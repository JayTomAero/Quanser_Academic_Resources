function data = parse_plot_qdrone_logs(logDir)
%PARSE_PLOT_QDRONE_LOGS Parse and plot QDrone 2 QUARC MAT-file logs.
%
%   data = parse_plot_qdrone_logs
%   data = parse_plot_qdrone_logs(logDir)
%
% Designed for the four logs recorded on 2026-09-02:
%   log_*_MissionCtrl*.mat       (mission_server_data)
%   log_*_Commander*.mat         (commander_data)
%   log_*_Stabilizer*.mat        (stabilizer_data)
%   log_QD2_*.mat                (QD2_data)
%
% The QUARC matrices store time in row 1, signals in the remaining rows,
% and samples in columns. This function transposes them into MATLAB tables,
% estimates the Mission-Control-to-DroneStack clock offset using the shared
% OptiTrack position signals, creates plots, and saves parsed data.
%
% IMPORTANT: Generic names (RowXX, StabilizerXX, QD2SensorXX) are deliberate.
% They should only be renamed after checking the exact Mux feeding each To
% Host File block in the matching Simulink model revision.

if nargin < 1 || isempty(logDir)
    logDir = locateDefaultLogDirectory();
end
logDir = char(logDir);

files.mission   = newestMatch(logDir, '*MissionCtrl*.mat');
files.commander = newestMatch(logDir, '*Commander*.mat');
files.stabilizer= newestMatch(logDir, '*Stabilizer*.mat');
files.qd2       = newestMatch(logDir, 'log_QD2_*.mat');

fprintf('Loading logs from:\n  %s\n', logDir);
M = loadNumericMatrix(files.mission,    'mission_server_data', 23);
C = loadNumericMatrix(files.commander,  'commander_data',      37);
S = loadNumericMatrix(files.stabilizer, 'stabilizer_data',     21);
Q = loadNumericMatrix(files.qd2,        'QD2_data',             61);

validateTime(M, 'Mission Control');
validateTime(C, 'Commander');
validateTime(S, 'Stabilizer');
validateTime(Q, 'QD2');

% Physical names here follow the Mission Control logging Mux used in this
% project. Command1..4 and Joystick1..4 retain neutral channel names because
% their axis order must be confirmed at the source Mux.
missionNames = { ...
    'Time_s', ...
    'DesiredX_m','DesiredY_m','DesiredZ_m','DesiredYaw_rad', ...
    'MeasuredX_m','MeasuredY_m','MeasuredZ_m', ...
    'MeasuredRoll_rad','MeasuredPitch_rad','MeasuredYaw_rad', ...
    'Loopback','StatusOrTimer', ...
    'Joystick1','Joystick2','Joystick3','Joystick4', ...
    'FlightPlan1','FlightPlanState', ...
    'Command1','Command2','Command3','Command4'};

commanderNames = [{'Time_s'}, makeNames('CommanderFlag', 1:20), ...
    {'MeasuredX_m','MeasuredY_m','MeasuredZ_m','MeasuredYaw_rad', ...
     'DesiredX_m','DesiredY_m','DesiredZ_m','DesiredYaw_rad'}, ...
    makeNames('CommanderTransform', 1:8)];

stabilizerNames = [{'Time_s','ExecutionTime_s','ComputationTime_s'}, ...
    makeNames('StabilizerState', 1:4), ...
    makeNames('StabilizerSignal', 8:21)];

qd2Names = [{'Time_s'}, makeNames('QD2Sensor', 2:19), ...
    {'MotorCommand1','MotorCommand2','MotorCommand3','MotorCommand4', ...
     'BatteryVoltage_V','QD2Signal25','BatteryCurrentCandidate_A'}, ...
    makeNames('QD2Signal', 27:61)];

data = struct();
data.mission    = matrixToTable(M, missionNames);
data.commander  = matrixToTable(C, commanderNames);
data.stabilizer = matrixToTable(S, stabilizerNames);
data.qd2        = matrixToTable(Q, qd2Names);
data.files      = files;

% Estimate t_mission = t_drone + offset. The Commander rows 22:24 match
% Mission Control rows 6:8 (OptiTrack X/Y/Z) in this model revision.
[offset_s, alignInfo] = estimateClockOffset(M, C, files);
data.metadata.MissionMinusDroneOffset_s = offset_s;
data.metadata.Alignment = alignInfo;
data.metadata.DroneSampleRate_Hz = 1/median(diff(Q(1,:)));
data.metadata.MissionSampleRate_Hz = 1/median(diff(M(1,:)));
data.metadata.Notes = [ ...
    "Mission time equals DroneStack time plus the reported offset."; ...
    "Mission Command1..4 and Joystick1..4 require axis-order confirmation at the source Mux."; ...
    "Generic Stabilizer/QD2 channel names intentionally avoid unsupported physical labels."];

% Add synchronized time to the Mission Control table. Negative values are
% valid: Mission Control began before DroneStack logging.
data.mission.Time_Drone_s = data.mission.Time_s - offset_s;
data.mission = movevars(data.mission, 'Time_Drone_s', 'After', 'Time_s');

[activeStart_s, activeEnd_s] = estimateMotorActiveWindow(data.qd2);
data.metadata.MotorActiveStart_s = activeStart_s;
data.metadata.MotorActiveEnd_s = activeEnd_s;

% Check only the recorded Mission command channels; this does not claim
% that an unlogged downstream injection could not have occurred.
inOverlap = data.mission.Time_Drone_s >= 0 & ...
            data.mission.Time_Drone_s <= data.qd2.Time_s(end);
cmd = data.mission{inOverlap, {'Command1','Command2','Command3','Command4'}};
if isempty(cmd)
    commandPeak = NaN(1,4);
else
    commandPeak = max(abs(cmd), [], 1);
end
data.metadata.MissionCommandPeakDuringOverlap = commandPeak;
data.metadata.MissionCommandExcitationDetected = any(commandPeak > 1e-4);

outDir = fullfile(logDir, 'QDrone2_Parsed_Output');
figDir = fullfile(outDir, 'figures');
if ~exist(figDir, 'dir'), mkdir(figDir); end

makePlots(data, figDir);
writeRowMap(data, outDir);

save(fullfile(outDir, 'parsed_qdrone_logs.mat'), 'data', '-v7.3');

fprintf('\nClock alignment:\n');
fprintf('  Mission time = DroneStack time + %.3f s\n', offset_s);
fprintf('  Alignment normalized RMS error = %.4g\n', alignInfo.NormalizedRMSError);
fprintf('  DroneStack sample rate: %.1f Hz\n', data.metadata.DroneSampleRate_Hz);
fprintf('  Mission Control sample rate: %.1f Hz\n', data.metadata.MissionSampleRate_Hz);
fprintf('  Motor-active window (estimated): %.3f to %.3f s DroneStack time\n', ...
    activeStart_s, activeEnd_s);
fprintf('  Mission Command1..4 peak in overlap: [%s]\n', ...
    strtrim(sprintf('%.5g ', commandPeak)));
if data.metadata.MissionCommandExcitationDetected
    fprintf('  A nonzero Mission command-channel excitation was detected.\n');
else
    fprintf(['  No nonzero Mission Command1..4 excitation was detected during ' ...
             'the synchronized DroneStack interval.\n']);
end
fprintf('Saved parsed data and figures to:\n  %s\n', outDir);
end

function logDir = locateDefaultLogDirectory()
codeDir = fileparts(mfilename('fullpath'));
candidates = {codeDir, fullfile(codeDir,'upload'), pwd, fullfile(pwd,'upload')};
for k = 1:numel(candidates)
    if ~isempty(dir(fullfile(candidates{k}, '*MissionCtrl*.mat'))) && ...
       ~isempty(dir(fullfile(candidates{k}, 'log_QD2_*.mat')))
        logDir = candidates{k};
        return
    end
end
logDir = uigetdir(pwd, 'Select the folder containing all four QDrone MAT logs');
if isequal(logDir,0)
    error('No log directory selected.');
end
end

function pathOut = newestMatch(folder, pattern)
d = dir(fullfile(folder, pattern));
if isempty(d)
    error('No file matching "%s" was found in %s.', pattern, folder);
end
[~,i] = max([d.datenum]);
pathOut = fullfile(d(i).folder, d(i).name);
fprintf('  %-11s %s\n', pattern, d(i).name);
end

function A = loadNumericMatrix(filePath, variableName, expectedRows)
x = load(filePath, variableName);
if ~isfield(x, variableName)
    error('%s does not contain variable %s.', filePath, variableName);
end
A = x.(variableName);
if ~isnumeric(A) || ndims(A) ~= 2 || size(A,1) ~= expectedRows
    error('%s must be a numeric %d-by-N matrix; found %s.', ...
        variableName, expectedRows, mat2str(size(A)));
end
end

function validateTime(A, label)
t = A(1,:);
if any(~isfinite(t)) || any(diff(t) <= 0)
    error('%s row 1 is not a finite, strictly increasing time vector.', label);
end
end

function names = makeNames(prefix, indices)
names = arrayfun(@(n)sprintf('%s%02d',prefix,n), indices, 'UniformOutput',false);
end

function T = matrixToTable(A, names)
if numel(names) ~= size(A,1)
    error('Internal name count (%d) does not match matrix row count (%d).', ...
        numel(names), size(A,1));
end
T = array2table(A.', 'VariableNames', names);
end

function [bestOffset, info] = estimateClockOffset(M, C, files)
tm = M(1,:);
tc = C(1,:);

% Use the timestamps in the filenames as the coarse clock-start estimate.
stampM = timestampFromName(files.mission);
stampC = timestampFromName(files.commander);
if isnat(stampM) || isnat(stampC)
    initial = max(0, 0.5*(tm(end)-tc(end)));
else
    initial = seconds(stampC-stampM);
end

stride = max(1, floor(numel(tc)/4000));
tq = tc(1:stride:end);
x = C(22:24,1:stride:end); % verified shared measured X/Y/Z
scale = std(x,0,2);
scale(scale < 1e-6) = 1;

coarse = (initial-3):0.01:(initial+3);
cost = alignmentCost(coarse, tm, M(6:8,:), tq, x, scale);
[~,i] = min(cost);
coarseBest = coarse(i);

fine = (coarseBest-0.02):0.001:(coarseBest+0.02);
fineCost = alignmentCost(fine, tm, M(6:8,:), tq, x, scale);
[bestCost,i] = min(fineCost);
bestOffset = fine(i);

info = struct('FilenameEstimate_s',initial, ...
              'EstimatedOffset_s',bestOffset, ...
              'NormalizedRMSError',sqrt(bestCost), ...
              'SharedSignals','Commander rows 22:24 versus Mission rows 6:8');
end

function cost = alignmentCost(offsets, tm, ym, tq, xq, scale)
cost = inf(size(offsets));
for k = 1:numel(offsets)
    y = interp1(tm.', ym.', tq.' + offsets(k), 'previous', NaN).';
    e = (y-xq)./scale;
    good = isfinite(e);
    if nnz(good) > 100
        cost(k) = mean(e(good).^2);
    end
end
end

function stamp = timestampFromName(pathIn)
[~,name] = fileparts(pathIn);
token = regexp(name, '\d{4}-\d{2}-\d{2}_\d{2}-\d{2}-\d{2}', 'match', 'once');
if isempty(token)
    stamp = NaT;
else
    stamp = datetime(token, 'InputFormat','yyyy-MM-dd_HH-mm-ss');
end
end

function [t0,t1] = estimateMotorActiveWindow(Q)
motor = Q{:, {'MotorCommand1','MotorCommand2','MotorCommand3','MotorCommand4'}};
dt = median(diff(Q.Time_s));
n = max(1, round(0.25/dt));
active = movmean(mean(motor,2), n) > 0.10;
idx = find(active);
if isempty(idx)
    t0 = NaN; t1 = NaN;
else
    t0 = Q.Time_s(idx(1));
    t1 = Q.Time_s(idx(end));
end
end

function makePlots(data, figDir)
M = data.mission;
Q = data.qd2;
S = data.stabilizer;
tM = M.Time_Drone_s;
tQ = Q.Time_s;
tS = S.Time_s;

colors = lines(7);

% 1. Desired and measured OptiTrack position.
f = newFigure('Position Tracking');
tl = tiledlayout(3,1,'TileSpacing','compact','Padding','compact');
labs = {'X (m)','Y (m)','Z (m)'};
desired = {'DesiredX_m','DesiredY_m','DesiredZ_m'};
measured = {'MeasuredX_m','MeasuredY_m','MeasuredZ_m'};
for k = 1:3
    ax = nexttile; hold(ax,'on');
    plot(ax,tM,M.(desired{k}),'--','LineWidth',1.3,'Color',colors(1,:));
    plot(ax,tM,M.(measured{k}),'LineWidth',1.2,'Color',colors(2,:));
    ylabel(ax,labs{k}); grid(ax,'on');
    if k==1, legend(ax,{'Desired','Measured'},'Location','best'); end
end
xlabel(tl,'DroneStack time (s)'); title(tl,'Mission Control: Desired vs. OptiTrack Position');
linkaxes(findall(f,'Type','axes'),'x'); xlim([max(0,min(tQ)) max(tQ)]);
saveNice(f,figDir,'01_position_tracking');

% 2. Measured attitude and desired yaw.
f = newFigure('Attitude');
tl = tiledlayout(3,1,'TileSpacing','compact','Padding','compact');
att = {'MeasuredRoll_rad','MeasuredPitch_rad','MeasuredYaw_rad'};
labs = {'Roll (deg)','Pitch (deg)','Yaw (deg)'};
for k=1:3
    ax=nexttile; hold(ax,'on');
    plot(ax,tM,rad2deg(M.(att{k})),'LineWidth',1.1,'Color',colors(k,:));
    if k==3
        plot(ax,tM,rad2deg(M.DesiredYaw_rad),'--','LineWidth',1.3,'Color',[0.2 0.2 0.2]);
        legend(ax,{'Measured','Desired'},'Location','best');
    end
    ylabel(ax,labs{k}); grid(ax,'on');
end
xlabel(tl,'DroneStack time (s)'); title(tl,'OptiTrack Attitude');
linkaxes(findall(f,'Type','axes'),'x'); xlim([max(0,min(tQ)) max(tQ)]);
saveNice(f,figDir,'02_attitude');

% 3. Three-dimensional trajectory.
f = newFigure('3-D Trajectory');
plot3(M.MeasuredX_m,M.MeasuredY_m,M.MeasuredZ_m,'LineWidth',1.4,'Color',colors(2,:));
grid on; axis equal; view(35,25);
xlabel('X (m)'); ylabel('Y (m)'); zlabel('Z (m)');
title('OptiTrack Flight Trajectory');
saveNice(f,figDir,'03_trajectory_3d');

% 4. Motor mixer outputs and battery data from the QD2 log.
f = newFigure('Motors and Battery');
tl=tiledlayout(2,1,'TileSpacing','compact','Padding','compact');
ax=nexttile;
plot(ax,tQ,Q{:,{'MotorCommand1','MotorCommand2','MotorCommand3','MotorCommand4'}},'LineWidth',1.0);
ylabel(ax,'Motor command'); legend(ax,{'M1','M2','M3','M4'},'Location','best','NumColumns',4); grid(ax,'on');
ax=nexttile; yyaxis(ax,'left'); plot(ax,tQ,Q.BatteryVoltage_V,'LineWidth',1.2); ylabel(ax,'Voltage (V)');
yyaxis(ax,'right'); plot(ax,tQ,Q.BatteryCurrentCandidate_A,'LineWidth',1.0); ylabel(ax,'Current candidate (A)'); grid(ax,'on');
xlabel(tl,'DroneStack time (s)'); title(tl,'QD2 Motor Outputs and Battery');
linkaxes(findall(f,'Type','axes'),'x');
saveNice(f,figDir,'04_motors_battery');

% 5. Discrete flight timeline, synchronized to DroneStack time.
f = newFigure('Flight Timeline');
tl=tiledlayout(3,1,'TileSpacing','compact','Padding','compact');
ax=nexttile;
stairs(ax,tM,M{:,{'Joystick1','Joystick2','Joystick3','Joystick4'}},'LineWidth',1.0);
ylabel(ax,'Joystick/switch'); legend(ax,{'J1','J2','J3','J4'},'Location','best','NumColumns',4); grid(ax,'on');
ax=nexttile; stairs(ax,tM,M.FlightPlanState,'LineWidth',1.2); ylabel(ax,'Flight-plan state'); grid(ax,'on');
ax=nexttile; plot(ax,tQ,mean(Q{:,{'MotorCommand1','MotorCommand2','MotorCommand3','MotorCommand4'}},2),'LineWidth',1.2);
ylabel(ax,'Mean motor command'); grid(ax,'on');
xlabel(tl,'DroneStack time (s)'); title(tl,'Synchronized Arming / Mode / Motor Timeline');
linkaxes(findall(f,'Type','axes'),'x'); xlim([max(0,min(tQ)) max(tQ)]);
saveNice(f,figDir,'05_flight_timeline');

% 6. Mission command channels. Axis order remains intentionally neutral.
f = newFigure('Mission Commands');
plot(tM,M{:,{'Command1','Command2','Command3','Command4'}},'LineWidth',1.1);
grid on; xlabel('DroneStack time (s)'); ylabel('Logged command');
legend({'Command1','Command2','Command3','Command4'},'Location','best','NumColumns',2);
title('Mission Control Logged Command Channels (Confirm Axis Order at Mux)');
xlim([max(0,min(tQ)) max(tQ)]);
saveNice(f,figDir,'06_mission_commands');

% 7. Stabilizer channels useful for diagnosing the controller/injection
% path, kept neutral until the Stabilizer To Host File Mux is verified.
f = newFigure('Stabilizer Channels');
tl=tiledlayout(2,1,'TileSpacing','compact','Padding','compact');
ax=nexttile;
plot(ax,tS,S{:,{'StabilizerSignal09','StabilizerSignal10','StabilizerSignal11'}},'LineWidth',1.0);
ylabel(ax,'Signal value'); legend(ax,{'Row 9','Row 10','Row 11'},'Location','best','NumColumns',3); grid(ax,'on');
ax=nexttile;
plot(ax,tS,S{:,{'StabilizerSignal15','StabilizerSignal16','StabilizerSignal17'}},'LineWidth',1.0);
ylabel(ax,'Signal value'); legend(ax,{'Row 15','Row 16','Row 17'},'Location','best','NumColumns',3); grid(ax,'on');
xlabel(tl,'DroneStack time (s)'); title(tl,'Stabilizer Candidate Input / Output Channels');
linkaxes(findall(f,'Type','axes'),'x');
saveNice(f,figDir,'07_stabilizer_channels');
end

function f = newFigure(name)
f = figure('Name',name,'Color','w','Position',[100 100 1100 720]);
set(f,'DefaultAxesFontName','Arial','DefaultAxesFontSize',11, ...
      'DefaultLineLineWidth',1.1);
end

function saveNice(f,figDir,baseName)
drawnow;
exportgraphics(f,fullfile(figDir,[baseName '.png']),'Resolution',220);
savefig(f,fullfile(figDir,[baseName '.fig']));
end

function writeRowMap(data, outDir)
sources = {'MissionControl','Commander','Stabilizer','QD2'};
tables = {data.mission,data.commander,data.stabilizer,data.qd2};
sourceCol = {}; rowCol = []; nameCol = {}; confidenceCol = {};
for k=1:numel(tables)
    names=tables{k}.Properties.VariableNames;
    % Time_Drone_s is derived and has no source row.
    names(strcmp(names,'Time_Drone_s'))=[];
    for r=1:numel(names)
        sourceCol{end+1,1}=sources{k}; %#ok<AGROW>
        rowCol(end+1,1)=r; %#ok<AGROW>
        nameCol{end+1,1}=names{r}; %#ok<AGROW>
        if any(contains(names{r},{'Row','Signal','Flag','State','Transform','Command','Joystick','Candidate','Or'}))
            confidenceCol{end+1,1}='Requires Mux confirmation'; %#ok<AGROW>
        else
            confidenceCol{end+1,1}='Mapped/strong evidence'; %#ok<AGROW>
        end
    end
end
map=table(sourceCol,rowCol,nameCol,confidenceCol, ...
    'VariableNames',{'Source','SourceRow','MATLABName','MappingConfidence'});
writetable(map,fullfile(outDir,'signal_row_mapping.csv'));
end
