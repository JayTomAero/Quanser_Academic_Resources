    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 14;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (Joystick_Visualization_2019a_P)
        ;%
            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% Joystick_Visualization_2019a_P.CompareToConstant_const
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Joystick_Visualization_2019a_P.Threshold_duration
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% Joystick_Visualization_2019a_P.Threshold_duration_h
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% Joystick_Visualization_2019a_P.Threshold_threshold
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% Joystick_Visualization_2019a_P.Threshold_threshold_d
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% Joystick_Visualization_2019a_P.VisualizationInitialize_client_
                    section.data(1).logicalSrcIdx = 5;
                    section.data(1).dtTransOffset = 0;

                    ;% Joystick_Visualization_2019a_P.VisualizationInitialize_clien_e
                    section.data(2).logicalSrcIdx = 6;
                    section.data(2).dtTransOffset = 1;

                    ;% Joystick_Visualization_2019a_P.VisualizationInitialize_server_
                    section.data(3).logicalSrcIdx = 7;
                    section.data(3).dtTransOffset = 2;

                    ;% Joystick_Visualization_2019a_P.VisualizationInitialize_serve_o
                    section.data(4).logicalSrcIdx = 8;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Joystick_Visualization_2019a_P.VisualizationInitialize_initial
                    section.data(1).logicalSrcIdx = 9;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Joystick_Visualization_2019a_P.VisualizationInitialize_variabl
                    section.data(1).logicalSrcIdx = 10;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Joystick_Visualization_2019a_P.VisualizationInitialize_close_o
                    section.data(1).logicalSrcIdx = 11;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section

            section.nData     = 78;
            section.data(78)  = dumData; %prealloc

                    ;% Joystick_Visualization_2019a_P.Yaw_Y0
                    section.data(1).logicalSrcIdx = 12;
                    section.data(1).dtTransOffset = 0;

                    ;% Joystick_Visualization_2019a_P.Throttle_Y0
                    section.data(2).logicalSrcIdx = 13;
                    section.data(2).dtTransOffset = 1;

                    ;% Joystick_Visualization_2019a_P.Roll_Y0
                    section.data(3).logicalSrcIdx = 14;
                    section.data(3).dtTransOffset = 2;

                    ;% Joystick_Visualization_2019a_P.Pitch_Y0
                    section.data(4).logicalSrcIdx = 15;
                    section.data(4).dtTransOffset = 3;

                    ;% Joystick_Visualization_2019a_P.DiscreteTimeIntegrator_gainval
                    section.data(5).logicalSrcIdx = 16;
                    section.data(5).dtTransOffset = 4;

                    ;% Joystick_Visualization_2019a_P.DiscreteTimeIntegrator_IC
                    section.data(6).logicalSrcIdx = 17;
                    section.data(6).dtTransOffset = 5;

                    ;% Joystick_Visualization_2019a_P.Gain_Gain
                    section.data(7).logicalSrcIdx = 18;
                    section.data(7).dtTransOffset = 6;

                    ;% Joystick_Visualization_2019a_P.Gain1_Gain
                    section.data(8).logicalSrcIdx = 19;
                    section.data(8).dtTransOffset = 7;

                    ;% Joystick_Visualization_2019a_P.Bias_Bias
                    section.data(9).logicalSrcIdx = 20;
                    section.data(9).dtTransOffset = 8;

                    ;% Joystick_Visualization_2019a_P.JoystickIssue01_Y0
                    section.data(10).logicalSrcIdx = 21;
                    section.data(10).dtTransOffset = 9;

                    ;% Joystick_Visualization_2019a_P.Triggers014_Y0
                    section.data(11).logicalSrcIdx = 22;
                    section.data(11).dtTransOffset = 10;

                    ;% Joystick_Visualization_2019a_P.Commands4_Y0
                    section.data(12).logicalSrcIdx = 23;
                    section.data(12).dtTransOffset = 11;

                    ;% Joystick_Visualization_2019a_P.DeadZone_Start
                    section.data(13).logicalSrcIdx = 24;
                    section.data(13).dtTransOffset = 12;

                    ;% Joystick_Visualization_2019a_P.DeadZone_End
                    section.data(14).logicalSrcIdx = 25;
                    section.data(14).dtTransOffset = 13;

                    ;% Joystick_Visualization_2019a_P.NumberofPulses_Y0
                    section.data(15).logicalSrcIdx = 26;
                    section.data(15).dtTransOffset = 14;

                    ;% Joystick_Visualization_2019a_P.Constant1_Value
                    section.data(16).logicalSrcIdx = 27;
                    section.data(16).dtTransOffset = 15;

                    ;% Joystick_Visualization_2019a_P.FixPtConstant_Value
                    section.data(17).logicalSrcIdx = 28;
                    section.data(17).dtTransOffset = 16;

                    ;% Joystick_Visualization_2019a_P.UnitDelay_InitialCondition
                    section.data(18).logicalSrcIdx = 29;
                    section.data(18).dtTransOffset = 17;

                    ;% Joystick_Visualization_2019a_P.PulseCheck_Value
                    section.data(19).logicalSrcIdx = 30;
                    section.data(19).dtTransOffset = 18;

                    ;% Joystick_Visualization_2019a_P.Gain_Gain_f
                    section.data(20).logicalSrcIdx = 31;
                    section.data(20).dtTransOffset = 19;

                    ;% Joystick_Visualization_2019a_P.Constant_Value
                    section.data(21).logicalSrcIdx = 32;
                    section.data(21).dtTransOffset = 23;

                    ;% Joystick_Visualization_2019a_P.Constant1_Value_l
                    section.data(22).logicalSrcIdx = 33;
                    section.data(22).dtTransOffset = 39;

                    ;% Joystick_Visualization_2019a_P.ContinuousSigmoid_XI
                    section.data(23).logicalSrcIdx = 34;
                    section.data(23).dtTransOffset = 51;

                    ;% Joystick_Visualization_2019a_P.ContinuousSigmoid_VI
                    section.data(24).logicalSrcIdx = 35;
                    section.data(24).dtTransOffset = 52;

                    ;% Joystick_Visualization_2019a_P.ContinuousSigmoid_Hold
                    section.data(25).logicalSrcIdx = 36;
                    section.data(25).dtTransOffset = 53;

                    ;% Joystick_Visualization_2019a_P.ContinuousSigmoid1_XI
                    section.data(26).logicalSrcIdx = 37;
                    section.data(26).dtTransOffset = 54;

                    ;% Joystick_Visualization_2019a_P.ContinuousSigmoid1_VI
                    section.data(27).logicalSrcIdx = 38;
                    section.data(27).dtTransOffset = 55;

                    ;% Joystick_Visualization_2019a_P.ContinuousSigmoid1_Hold
                    section.data(28).logicalSrcIdx = 39;
                    section.data(28).dtTransOffset = 56;

                    ;% Joystick_Visualization_2019a_P.ContinuousSigmoid2_XI
                    section.data(29).logicalSrcIdx = 40;
                    section.data(29).dtTransOffset = 57;

                    ;% Joystick_Visualization_2019a_P.ContinuousSigmoid2_VI
                    section.data(30).logicalSrcIdx = 41;
                    section.data(30).dtTransOffset = 58;

                    ;% Joystick_Visualization_2019a_P.ContinuousSigmoid2_Hold
                    section.data(31).logicalSrcIdx = 42;
                    section.data(31).dtTransOffset = 59;

                    ;% Joystick_Visualization_2019a_P.ContinuousSigmoid3_XI
                    section.data(32).logicalSrcIdx = 43;
                    section.data(32).dtTransOffset = 60;

                    ;% Joystick_Visualization_2019a_P.ContinuousSigmoid3_VI
                    section.data(33).logicalSrcIdx = 44;
                    section.data(33).dtTransOffset = 61;

                    ;% Joystick_Visualization_2019a_P.ContinuousSigmoid3_Hold
                    section.data(34).logicalSrcIdx = 45;
                    section.data(34).dtTransOffset = 62;

                    ;% Joystick_Visualization_2019a_P.Constant_Value_a
                    section.data(35).logicalSrcIdx = 46;
                    section.data(35).dtTransOffset = 63;

                    ;% Joystick_Visualization_2019a_P.DiscreteTimeIntegrator_gainva_k
                    section.data(36).logicalSrcIdx = 47;
                    section.data(36).dtTransOffset = 69;

                    ;% Joystick_Visualization_2019a_P.DiscreteTimeIntegrator_IC_e
                    section.data(37).logicalSrcIdx = 48;
                    section.data(37).dtTransOffset = 70;

                    ;% Joystick_Visualization_2019a_P.m_Gain
                    section.data(38).logicalSrcIdx = 49;
                    section.data(38).dtTransOffset = 71;

                    ;% Joystick_Visualization_2019a_P.m_Gain_o
                    section.data(39).logicalSrcIdx = 50;
                    section.data(39).dtTransOffset = 72;

                    ;% Joystick_Visualization_2019a_P.m_Gain_n
                    section.data(40).logicalSrcIdx = 51;
                    section.data(40).dtTransOffset = 73;

                    ;% Joystick_Visualization_2019a_P.Integrator_IC
                    section.data(41).logicalSrcIdx = 52;
                    section.data(41).dtTransOffset = 74;

                    ;% Joystick_Visualization_2019a_P.Constant_Value_f
                    section.data(42).logicalSrcIdx = 53;
                    section.data(42).dtTransOffset = 75;

                    ;% Joystick_Visualization_2019a_P.Constant1_Value_h
                    section.data(43).logicalSrcIdx = 54;
                    section.data(43).dtTransOffset = 76;

                    ;% Joystick_Visualization_2019a_P.Constant_Value_j
                    section.data(44).logicalSrcIdx = 55;
                    section.data(44).dtTransOffset = 88;

                    ;% Joystick_Visualization_2019a_P.Constant_Value_k
                    section.data(45).logicalSrcIdx = 56;
                    section.data(45).dtTransOffset = 89;

                    ;% Joystick_Visualization_2019a_P.Constant_Value_g
                    section.data(46).logicalSrcIdx = 57;
                    section.data(46).dtTransOffset = 90;

                    ;% Joystick_Visualization_2019a_P.Constant6_Value
                    section.data(47).logicalSrcIdx = 58;
                    section.data(47).dtTransOffset = 106;

                    ;% Joystick_Visualization_2019a_P.Constant_Value_m
                    section.data(48).logicalSrcIdx = 59;
                    section.data(48).dtTransOffset = 107;

                    ;% Joystick_Visualization_2019a_P.Constant9_Value
                    section.data(49).logicalSrcIdx = 60;
                    section.data(49).dtTransOffset = 110;

                    ;% Joystick_Visualization_2019a_P.Constant8_Value
                    section.data(50).logicalSrcIdx = 61;
                    section.data(50).dtTransOffset = 111;

                    ;% Joystick_Visualization_2019a_P.Constant7_Value
                    section.data(51).logicalSrcIdx = 62;
                    section.data(51).dtTransOffset = 112;

                    ;% Joystick_Visualization_2019a_P.Constant5_Value
                    section.data(52).logicalSrcIdx = 63;
                    section.data(52).dtTransOffset = 113;

                    ;% Joystick_Visualization_2019a_P.Constant_Value_fm
                    section.data(53).logicalSrcIdx = 64;
                    section.data(53).dtTransOffset = 117;

                    ;% Joystick_Visualization_2019a_P.Constant6_Value_l
                    section.data(54).logicalSrcIdx = 65;
                    section.data(54).dtTransOffset = 118;

                    ;% Joystick_Visualization_2019a_P.Constant1_Value_c
                    section.data(55).logicalSrcIdx = 66;
                    section.data(55).dtTransOffset = 119;

                    ;% Joystick_Visualization_2019a_P.Constant9_Value_f
                    section.data(56).logicalSrcIdx = 67;
                    section.data(56).dtTransOffset = 122;

                    ;% Joystick_Visualization_2019a_P.Constant8_Value_d
                    section.data(57).logicalSrcIdx = 68;
                    section.data(57).dtTransOffset = 123;

                    ;% Joystick_Visualization_2019a_P.Constant7_Value_e
                    section.data(58).logicalSrcIdx = 69;
                    section.data(58).dtTransOffset = 124;

                    ;% Joystick_Visualization_2019a_P.Constant5_Value_p
                    section.data(59).logicalSrcIdx = 70;
                    section.data(59).dtTransOffset = 125;

                    ;% Joystick_Visualization_2019a_P.Constant6_Value_j
                    section.data(60).logicalSrcIdx = 71;
                    section.data(60).dtTransOffset = 129;

                    ;% Joystick_Visualization_2019a_P.Constant2_Value
                    section.data(61).logicalSrcIdx = 72;
                    section.data(61).dtTransOffset = 130;

                    ;% Joystick_Visualization_2019a_P.Constant9_Value_j
                    section.data(62).logicalSrcIdx = 73;
                    section.data(62).dtTransOffset = 133;

                    ;% Joystick_Visualization_2019a_P.Constant8_Value_g
                    section.data(63).logicalSrcIdx = 74;
                    section.data(63).dtTransOffset = 134;

                    ;% Joystick_Visualization_2019a_P.Constant7_Value_g
                    section.data(64).logicalSrcIdx = 75;
                    section.data(64).dtTransOffset = 135;

                    ;% Joystick_Visualization_2019a_P.Constant5_Value_m
                    section.data(65).logicalSrcIdx = 76;
                    section.data(65).dtTransOffset = 136;

                    ;% Joystick_Visualization_2019a_P.Constant_Value_ab
                    section.data(66).logicalSrcIdx = 77;
                    section.data(66).dtTransOffset = 140;

                    ;% Joystick_Visualization_2019a_P.Constant1_Value_p
                    section.data(67).logicalSrcIdx = 78;
                    section.data(67).dtTransOffset = 141;

                    ;% Joystick_Visualization_2019a_P.Constant2_Value_d
                    section.data(68).logicalSrcIdx = 79;
                    section.data(68).dtTransOffset = 143;

                    ;% Joystick_Visualization_2019a_P.Constant3_Value
                    section.data(69).logicalSrcIdx = 80;
                    section.data(69).dtTransOffset = 145;

                    ;% Joystick_Visualization_2019a_P.Constant4_Value
                    section.data(70).logicalSrcIdx = 81;
                    section.data(70).dtTransOffset = 147;

                    ;% Joystick_Visualization_2019a_P.Constant5_Value_py
                    section.data(71).logicalSrcIdx = 82;
                    section.data(71).dtTransOffset = 149;

                    ;% Joystick_Visualization_2019a_P.Constant6_Value_b
                    section.data(72).logicalSrcIdx = 83;
                    section.data(72).dtTransOffset = 151;

                    ;% Joystick_Visualization_2019a_P.Constant8_Value_k
                    section.data(73).logicalSrcIdx = 84;
                    section.data(73).dtTransOffset = 153;

                    ;% Joystick_Visualization_2019a_P.Constant9_Value_b
                    section.data(74).logicalSrcIdx = 85;
                    section.data(74).dtTransOffset = 155;

                    ;% Joystick_Visualization_2019a_P.Defaultinput_Value
                    section.data(75).logicalSrcIdx = 86;
                    section.data(75).dtTransOffset = 157;

                    ;% Joystick_Visualization_2019a_P.Switch_Threshold
                    section.data(76).logicalSrcIdx = 87;
                    section.data(76).dtTransOffset = 161;

                    ;% Joystick_Visualization_2019a_P.Memory_InitialCondition
                    section.data(77).logicalSrcIdx = 88;
                    section.data(77).dtTransOffset = 162;

                    ;% Joystick_Visualization_2019a_P.rads_Gain
                    section.data(78).logicalSrcIdx = 89;
                    section.data(78).dtTransOffset = 163;

            nTotData = nTotData + section.nData;
            paramMap.sections(6) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% Joystick_Visualization_2019a_P.HostGameController_BufferSize
                    section.data(1).logicalSrcIdx = 90;
                    section.data(1).dtTransOffset = 0;

                    ;% Joystick_Visualization_2019a_P.HostInitialize_SendBufferSize
                    section.data(2).logicalSrcIdx = 91;
                    section.data(2).dtTransOffset = 1;

                    ;% Joystick_Visualization_2019a_P.HostInitialize_ReceiveBufferSiz
                    section.data(3).logicalSrcIdx = 92;
                    section.data(3).dtTransOffset = 2;

                    ;% Joystick_Visualization_2019a_P.HostInitialize_ThreadPriority
                    section.data(4).logicalSrcIdx = 93;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            paramMap.sections(7) = section;
            clear section

            section.nData     = 10;
            section.data(10)  = dumData; %prealloc

                    ;% Joystick_Visualization_2019a_P.EmergencyAbortbool_Y0
                    section.data(1).logicalSrcIdx = 94;
                    section.data(1).dtTransOffset = 0;

                    ;% Joystick_Visualization_2019a_P.ArmDisarmbool_Y0
                    section.data(2).logicalSrcIdx = 95;
                    section.data(2).dtTransOffset = 1;

                    ;% Joystick_Visualization_2019a_P.TakeoffAutolandbool_Y0
                    section.data(3).logicalSrcIdx = 96;
                    section.data(3).dtTransOffset = 2;

                    ;% Joystick_Visualization_2019a_P.VisualizationInitialize_OpenVie
                    section.data(4).logicalSrcIdx = 97;
                    section.data(4).dtTransOffset = 3;

                    ;% Joystick_Visualization_2019a_P.HostGameController_AutoCenter
                    section.data(5).logicalSrcIdx = 98;
                    section.data(5).dtTransOffset = 4;

                    ;% Joystick_Visualization_2019a_P.HostGameController_Enabled
                    section.data(6).logicalSrcIdx = 99;
                    section.data(6).dtTransOffset = 5;

                    ;% Joystick_Visualization_2019a_P.HostGameController_DebugMode
                    section.data(7).logicalSrcIdx = 100;
                    section.data(7).dtTransOffset = 6;

                    ;% Joystick_Visualization_2019a_P.HostInitialize_RunClient
                    section.data(8).logicalSrcIdx = 101;
                    section.data(8).dtTransOffset = 7;

                    ;% Joystick_Visualization_2019a_P.HostInitialize_UseWindow
                    section.data(9).logicalSrcIdx = 102;
                    section.data(9).dtTransOffset = 8;

                    ;% Joystick_Visualization_2019a_P.HostInitialize_Active
                    section.data(10).logicalSrcIdx = 103;
                    section.data(10).dtTransOffset = 9;

            nTotData = nTotData + section.nData;
            paramMap.sections(8) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Joystick_Visualization_2019a_P.HostGameController_Controller
                    section.data(1).logicalSrcIdx = 104;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(9) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Joystick_Visualization_2019a_P.ManualSwitch1_CurrentSetting
                    section.data(1).logicalSrcIdx = 105;
                    section.data(1).dtTransOffset = 0;

                    ;% Joystick_Visualization_2019a_P.HostInitialize_URI
                    section.data(2).logicalSrcIdx = 106;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            paramMap.sections(10) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Joystick_Visualization_2019a_P.UsedesiredYwhenenabled.Out1_Y0
                    section.data(1).logicalSrcIdx = 107;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(11) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Joystick_Visualization_2019a_P.UsedesiredXwhenenabled.Out1_Y0
                    section.data(1).logicalSrcIdx = 108;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(12) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Joystick_Visualization_2019a_P.Usedesyawwhenenabled.Out1_Y0
                    section.data(1).logicalSrcIdx = 109;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(13) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Joystick_Visualization_2019a_P.Usedesheightwhenenabled.Out1_Y0
                    section.data(1).logicalSrcIdx = 110;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(14) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 8;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (Joystick_Visualization_2019a_B)
        ;%
            section.nData     = 64;
            section.data(64)  = dumData; %prealloc

                    ;% Joystick_Visualization_2019a_B.ContinuousSigmoid_o1
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Joystick_Visualization_2019a_B.ContinuousSigmoid_o2
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% Joystick_Visualization_2019a_B.ContinuousSigmoid_o3
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% Joystick_Visualization_2019a_B.ContinuousSigmoid_o4
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% Joystick_Visualization_2019a_B.ContinuousSigmoid1_o1
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% Joystick_Visualization_2019a_B.ContinuousSigmoid1_o2
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% Joystick_Visualization_2019a_B.ContinuousSigmoid1_o3
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% Joystick_Visualization_2019a_B.ContinuousSigmoid1_o4
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% Joystick_Visualization_2019a_B.ContinuousSigmoid2_o1
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% Joystick_Visualization_2019a_B.ContinuousSigmoid2_o2
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

                    ;% Joystick_Visualization_2019a_B.ContinuousSigmoid2_o3
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 10;

                    ;% Joystick_Visualization_2019a_B.ContinuousSigmoid2_o4
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 11;

                    ;% Joystick_Visualization_2019a_B.ContinuousSigmoid3_o1
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 12;

                    ;% Joystick_Visualization_2019a_B.ContinuousSigmoid3_o2
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 13;

                    ;% Joystick_Visualization_2019a_B.ContinuousSigmoid3_o3
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 14;

                    ;% Joystick_Visualization_2019a_B.ContinuousSigmoid3_o4
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 15;

                    ;% Joystick_Visualization_2019a_B.m
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 16;

                    ;% Joystick_Visualization_2019a_B.m_h
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 17;

                    ;% Joystick_Visualization_2019a_B.m_m
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 18;

                    ;% Joystick_Visualization_2019a_B.ManualSwitch1
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 19;

                    ;% Joystick_Visualization_2019a_B.MatrixConcatenate
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 27;

                    ;% Joystick_Visualization_2019a_B.MatrixConcatenate_j
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 43;

                    ;% Joystick_Visualization_2019a_B.Product1
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 59;

                    ;% Joystick_Visualization_2019a_B.MatrixConcatenate_i
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 62;

                    ;% Joystick_Visualization_2019a_B.MatrixConcatenate_f
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 78;

                    ;% Joystick_Visualization_2019a_B.MatrixConcatenate_o
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 94;

                    ;% Joystick_Visualization_2019a_B.Switch
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 110;

                    ;% Joystick_Visualization_2019a_B.HiddenBuf_InsertedFor_Usedeshei
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 114;

                    ;% Joystick_Visualization_2019a_B.HiddenBuf_InsertedFor_Usedesyaw
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 115;

                    ;% Joystick_Visualization_2019a_B.Memory
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 116;

                    ;% Joystick_Visualization_2019a_B.HiddenBuf_InsertedFor_Usedesire
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 120;

                    ;% Joystick_Visualization_2019a_B.HiddenBuf_InsertedFor_Usedesi_i
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 121;

                    ;% Joystick_Visualization_2019a_B.rads
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 122;

                    ;% Joystick_Visualization_2019a_B.DataTypeConversion
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 123;

                    ;% Joystick_Visualization_2019a_B.sigmoid_type
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 124;

                    ;% Joystick_Visualization_2019a_B.enable
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 125;

                    ;% Joystick_Visualization_2019a_B.yaw_ref
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 126;

                    ;% Joystick_Visualization_2019a_B.max_yaw_vel
                    section.data(38).logicalSrcIdx = 37;
                    section.data(38).dtTransOffset = 127;

                    ;% Joystick_Visualization_2019a_B.max_yaw_accel
                    section.data(39).logicalSrcIdx = 38;
                    section.data(39).dtTransOffset = 128;

                    ;% Joystick_Visualization_2019a_B.enable_f
                    section.data(40).logicalSrcIdx = 39;
                    section.data(40).dtTransOffset = 129;

                    ;% Joystick_Visualization_2019a_B.height_ref
                    section.data(41).logicalSrcIdx = 40;
                    section.data(41).dtTransOffset = 130;

                    ;% Joystick_Visualization_2019a_B.max_height_vel
                    section.data(42).logicalSrcIdx = 41;
                    section.data(42).dtTransOffset = 131;

                    ;% Joystick_Visualization_2019a_B.max_height_accel
                    section.data(43).logicalSrcIdx = 42;
                    section.data(43).dtTransOffset = 132;

                    ;% Joystick_Visualization_2019a_B.enable_j
                    section.data(44).logicalSrcIdx = 43;
                    section.data(44).dtTransOffset = 133;

                    ;% Joystick_Visualization_2019a_B.y_ref
                    section.data(45).logicalSrcIdx = 44;
                    section.data(45).dtTransOffset = 134;

                    ;% Joystick_Visualization_2019a_B.max_y_vel
                    section.data(46).logicalSrcIdx = 45;
                    section.data(46).dtTransOffset = 135;

                    ;% Joystick_Visualization_2019a_B.max_y_accel
                    section.data(47).logicalSrcIdx = 46;
                    section.data(47).dtTransOffset = 136;

                    ;% Joystick_Visualization_2019a_B.enable_m
                    section.data(48).logicalSrcIdx = 47;
                    section.data(48).dtTransOffset = 137;

                    ;% Joystick_Visualization_2019a_B.x_ref
                    section.data(49).logicalSrcIdx = 48;
                    section.data(49).dtTransOffset = 138;

                    ;% Joystick_Visualization_2019a_B.max_x_vel
                    section.data(50).logicalSrcIdx = 49;
                    section.data(50).dtTransOffset = 139;

                    ;% Joystick_Visualization_2019a_B.max_x_accel
                    section.data(51).logicalSrcIdx = 50;
                    section.data(51).dtTransOffset = 140;

                    ;% Joystick_Visualization_2019a_B.FixPtSum1
                    section.data(52).logicalSrcIdx = 51;
                    section.data(52).dtTransOffset = 141;

                    ;% Joystick_Visualization_2019a_B.DataTypeConversion2
                    section.data(53).logicalSrcIdx = 52;
                    section.data(53).dtTransOffset = 142;

                    ;% Joystick_Visualization_2019a_B.DataTypeConversion4
                    section.data(54).logicalSrcIdx = 53;
                    section.data(54).dtTransOffset = 143;

                    ;% Joystick_Visualization_2019a_B.Product
                    section.data(55).logicalSrcIdx = 54;
                    section.data(55).dtTransOffset = 144;

                    ;% Joystick_Visualization_2019a_B.Product1_e
                    section.data(56).logicalSrcIdx = 55;
                    section.data(56).dtTransOffset = 147;

                    ;% Joystick_Visualization_2019a_B.Product2
                    section.data(57).logicalSrcIdx = 56;
                    section.data(57).dtTransOffset = 148;

                    ;% Joystick_Visualization_2019a_B.Product3
                    section.data(58).logicalSrcIdx = 57;
                    section.data(58).dtTransOffset = 149;

                    ;% Joystick_Visualization_2019a_B.DataTypeConversion_j
                    section.data(59).logicalSrcIdx = 58;
                    section.data(59).dtTransOffset = 150;

                    ;% Joystick_Visualization_2019a_B.DiscreteTimeIntegrator
                    section.data(60).logicalSrcIdx = 59;
                    section.data(60).dtTransOffset = 151;

                    ;% Joystick_Visualization_2019a_B.Gain
                    section.data(61).logicalSrcIdx = 60;
                    section.data(61).dtTransOffset = 152;

                    ;% Joystick_Visualization_2019a_B.Bias
                    section.data(62).logicalSrcIdx = 61;
                    section.data(62).dtTransOffset = 153;

                    ;% Joystick_Visualization_2019a_B.y
                    section.data(63).logicalSrcIdx = 62;
                    section.data(63).dtTransOffset = 154;

                    ;% Joystick_Visualization_2019a_B.z
                    section.data(64).logicalSrcIdx = 63;
                    section.data(64).dtTransOffset = 155;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Joystick_Visualization_2019a_B.HostInitialize_o2
                    section.data(1).logicalSrcIdx = 64;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Joystick_Visualization_2019a_B.HostInitialize_o1
                    section.data(1).logicalSrcIdx = 65;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(3) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% Joystick_Visualization_2019a_B.HostGameController_o1
                    section.data(1).logicalSrcIdx = 66;
                    section.data(1).dtTransOffset = 0;

                    ;% Joystick_Visualization_2019a_B.LogicalOperator
                    section.data(2).logicalSrcIdx = 67;
                    section.data(2).dtTransOffset = 1;

                    ;% Joystick_Visualization_2019a_B.Compare
                    section.data(3).logicalSrcIdx = 69;
                    section.data(3).dtTransOffset = 2;

                    ;% Joystick_Visualization_2019a_B.Buttons
                    section.data(4).logicalSrcIdx = 70;
                    section.data(4).dtTransOffset = 3;

                    ;% Joystick_Visualization_2019a_B.LogicalOperator_j
                    section.data(5).logicalSrcIdx = 71;
                    section.data(5).dtTransOffset = 35;

                    ;% Joystick_Visualization_2019a_B.RelationalOperator
                    section.data(6).logicalSrcIdx = 72;
                    section.data(6).dtTransOffset = 36;

                    ;% Joystick_Visualization_2019a_B.Compare_j
                    section.data(7).logicalSrcIdx = 73;
                    section.data(7).dtTransOffset = 37;

            nTotData = nTotData + section.nData;
            sigMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Joystick_Visualization_2019a_B.UsedesiredYwhenenabled.h_dm1
                    section.data(1).logicalSrcIdx = 74;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(5) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Joystick_Visualization_2019a_B.UsedesiredXwhenenabled.h_dm1
                    section.data(1).logicalSrcIdx = 75;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Joystick_Visualization_2019a_B.Usedesyawwhenenabled.h_dm1
                    section.data(1).logicalSrcIdx = 76;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(7) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Joystick_Visualization_2019a_B.Usedesheightwhenenabled.h_dm1
                    section.data(1).logicalSrcIdx = 77;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(8) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 18;
        sectIdxOffset = 8;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (Joystick_Visualization_2019a_DW)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Joystick_Visualization_2019a_DW.HostGameController_ControllerSt
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Joystick_Visualization_2019a_DW.HostGameController_Lock
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 33;
            section.data(33)  = dumData; %prealloc

                    ;% Joystick_Visualization_2019a_DW.DiscreteTimeIntegrator_DSTATE
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

                    ;% Joystick_Visualization_2019a_DW.UnitDelay_DSTATE
                    section.data(2).logicalSrcIdx = 3;
                    section.data(2).dtTransOffset = 1;

                    ;% Joystick_Visualization_2019a_DW.DiscreteTimeIntegrator_DSTATE_c
                    section.data(3).logicalSrcIdx = 4;
                    section.data(3).dtTransOffset = 2;

                    ;% Joystick_Visualization_2019a_DW.ContinuousSigmoid_Sigmoid
                    section.data(4).logicalSrcIdx = 5;
                    section.data(4).dtTransOffset = 3;

                    ;% Joystick_Visualization_2019a_DW.ContinuousSigmoid_Time
                    section.data(5).logicalSrcIdx = 6;
                    section.data(5).dtTransOffset = 14;

                    ;% Joystick_Visualization_2019a_DW.ContinuousSigmoid_Target
                    section.data(6).logicalSrcIdx = 7;
                    section.data(6).dtTransOffset = 15;

                    ;% Joystick_Visualization_2019a_DW.ContinuousSigmoid_PPos
                    section.data(7).logicalSrcIdx = 8;
                    section.data(7).dtTransOffset = 16;

                    ;% Joystick_Visualization_2019a_DW.ContinuousSigmoid_PVel
                    section.data(8).logicalSrcIdx = 9;
                    section.data(8).dtTransOffset = 17;

                    ;% Joystick_Visualization_2019a_DW.ContinuousSigmoid_MVel
                    section.data(9).logicalSrcIdx = 10;
                    section.data(9).dtTransOffset = 18;

                    ;% Joystick_Visualization_2019a_DW.ContinuousSigmoid_MAcc
                    section.data(10).logicalSrcIdx = 11;
                    section.data(10).dtTransOffset = 19;

                    ;% Joystick_Visualization_2019a_DW.ContinuousSigmoid1_Sigmoid
                    section.data(11).logicalSrcIdx = 12;
                    section.data(11).dtTransOffset = 20;

                    ;% Joystick_Visualization_2019a_DW.ContinuousSigmoid1_Time
                    section.data(12).logicalSrcIdx = 13;
                    section.data(12).dtTransOffset = 31;

                    ;% Joystick_Visualization_2019a_DW.ContinuousSigmoid1_Target
                    section.data(13).logicalSrcIdx = 14;
                    section.data(13).dtTransOffset = 32;

                    ;% Joystick_Visualization_2019a_DW.ContinuousSigmoid1_PPos
                    section.data(14).logicalSrcIdx = 15;
                    section.data(14).dtTransOffset = 33;

                    ;% Joystick_Visualization_2019a_DW.ContinuousSigmoid1_PVel
                    section.data(15).logicalSrcIdx = 16;
                    section.data(15).dtTransOffset = 34;

                    ;% Joystick_Visualization_2019a_DW.ContinuousSigmoid1_MVel
                    section.data(16).logicalSrcIdx = 17;
                    section.data(16).dtTransOffset = 35;

                    ;% Joystick_Visualization_2019a_DW.ContinuousSigmoid1_MAcc
                    section.data(17).logicalSrcIdx = 18;
                    section.data(17).dtTransOffset = 36;

                    ;% Joystick_Visualization_2019a_DW.ContinuousSigmoid2_Sigmoid
                    section.data(18).logicalSrcIdx = 19;
                    section.data(18).dtTransOffset = 37;

                    ;% Joystick_Visualization_2019a_DW.ContinuousSigmoid2_Time
                    section.data(19).logicalSrcIdx = 20;
                    section.data(19).dtTransOffset = 48;

                    ;% Joystick_Visualization_2019a_DW.ContinuousSigmoid2_Target
                    section.data(20).logicalSrcIdx = 21;
                    section.data(20).dtTransOffset = 49;

                    ;% Joystick_Visualization_2019a_DW.ContinuousSigmoid2_PPos
                    section.data(21).logicalSrcIdx = 22;
                    section.data(21).dtTransOffset = 50;

                    ;% Joystick_Visualization_2019a_DW.ContinuousSigmoid2_PVel
                    section.data(22).logicalSrcIdx = 23;
                    section.data(22).dtTransOffset = 51;

                    ;% Joystick_Visualization_2019a_DW.ContinuousSigmoid2_MVel
                    section.data(23).logicalSrcIdx = 24;
                    section.data(23).dtTransOffset = 52;

                    ;% Joystick_Visualization_2019a_DW.ContinuousSigmoid2_MAcc
                    section.data(24).logicalSrcIdx = 25;
                    section.data(24).dtTransOffset = 53;

                    ;% Joystick_Visualization_2019a_DW.ContinuousSigmoid3_Sigmoid
                    section.data(25).logicalSrcIdx = 26;
                    section.data(25).dtTransOffset = 54;

                    ;% Joystick_Visualization_2019a_DW.ContinuousSigmoid3_Time
                    section.data(26).logicalSrcIdx = 27;
                    section.data(26).dtTransOffset = 65;

                    ;% Joystick_Visualization_2019a_DW.ContinuousSigmoid3_Target
                    section.data(27).logicalSrcIdx = 28;
                    section.data(27).dtTransOffset = 66;

                    ;% Joystick_Visualization_2019a_DW.ContinuousSigmoid3_PPos
                    section.data(28).logicalSrcIdx = 29;
                    section.data(28).dtTransOffset = 67;

                    ;% Joystick_Visualization_2019a_DW.ContinuousSigmoid3_PVel
                    section.data(29).logicalSrcIdx = 30;
                    section.data(29).dtTransOffset = 68;

                    ;% Joystick_Visualization_2019a_DW.ContinuousSigmoid3_MVel
                    section.data(30).logicalSrcIdx = 31;
                    section.data(30).dtTransOffset = 69;

                    ;% Joystick_Visualization_2019a_DW.ContinuousSigmoid3_MAcc
                    section.data(31).logicalSrcIdx = 32;
                    section.data(31).dtTransOffset = 70;

                    ;% Joystick_Visualization_2019a_DW.VisualizationSetVariables_PrevT
                    section.data(32).logicalSrcIdx = 33;
                    section.data(32).dtTransOffset = 71;

                    ;% Joystick_Visualization_2019a_DW.Memory_PreviousInput
                    section.data(33).logicalSrcIdx = 34;
                    section.data(33).dtTransOffset = 72;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Joystick_Visualization_2019a_DW.HostInitialize_ConnectedHandle
                    section.data(1).logicalSrcIdx = 35;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Joystick_Visualization_2019a_DW.VisualizationInitialize_Visuali
                    section.data(1).logicalSrcIdx = 36;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Joystick_Visualization_2019a_DW.VisualizationInitialize_PWORK
                    section.data(1).logicalSrcIdx = 37;
                    section.data(1).dtTransOffset = 0;

                    ;% Joystick_Visualization_2019a_DW.VisualizationSetVariables_PWORK
                    section.data(2).logicalSrcIdx = 38;
                    section.data(2).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% Joystick_Visualization_2019a_DW.sfEvent
                    section.data(1).logicalSrcIdx = 39;
                    section.data(1).dtTransOffset = 0;

                    ;% Joystick_Visualization_2019a_DW.sfEvent_d
                    section.data(2).logicalSrcIdx = 40;
                    section.data(2).dtTransOffset = 1;

                    ;% Joystick_Visualization_2019a_DW.sfEvent_g
                    section.data(3).logicalSrcIdx = 41;
                    section.data(3).dtTransOffset = 2;

                    ;% Joystick_Visualization_2019a_DW.sfEvent_i
                    section.data(4).logicalSrcIdx = 42;
                    section.data(4).dtTransOffset = 3;

                    ;% Joystick_Visualization_2019a_DW.sfEvent_n
                    section.data(5).logicalSrcIdx = 43;
                    section.data(5).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% Joystick_Visualization_2019a_DW.DiscreteTimeIntegrator_PrevRese
                    section.data(1).logicalSrcIdx = 44;
                    section.data(1).dtTransOffset = 0;

                    ;% Joystick_Visualization_2019a_DW.pulsecount_SubsysRanBC
                    section.data(2).logicalSrcIdx = 45;
                    section.data(2).dtTransOffset = 1;

                    ;% Joystick_Visualization_2019a_DW.InitializationandConditioning_S
                    section.data(3).logicalSrcIdx = 46;
                    section.data(3).dtTransOffset = 2;

                    ;% Joystick_Visualization_2019a_DW.FrSKYMapping_SubsysRanBC
                    section.data(4).logicalSrcIdx = 47;
                    section.data(4).dtTransOffset = 3;

                    ;% Joystick_Visualization_2019a_DW.DiscreteTimeIntegrator_PrevRe_j
                    section.data(5).logicalSrcIdx = 48;
                    section.data(5).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            dworkMap.sections(8) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% Joystick_Visualization_2019a_DW.ContinuousSigmoid_Flag
                    section.data(1).logicalSrcIdx = 49;
                    section.data(1).dtTransOffset = 0;

                    ;% Joystick_Visualization_2019a_DW.ContinuousSigmoid1_Flag
                    section.data(2).logicalSrcIdx = 50;
                    section.data(2).dtTransOffset = 1;

                    ;% Joystick_Visualization_2019a_DW.ContinuousSigmoid2_Flag
                    section.data(3).logicalSrcIdx = 51;
                    section.data(3).dtTransOffset = 2;

                    ;% Joystick_Visualization_2019a_DW.ContinuousSigmoid3_Flag
                    section.data(4).logicalSrcIdx = 52;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            dworkMap.sections(9) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% Joystick_Visualization_2019a_DW.HostGameController_NewData
                    section.data(1).logicalSrcIdx = 53;
                    section.data(1).dtTransOffset = 0;

                    ;% Joystick_Visualization_2019a_DW.doneDoubleBufferReInit
                    section.data(2).logicalSrcIdx = 54;
                    section.data(2).dtTransOffset = 1;

                    ;% Joystick_Visualization_2019a_DW.doneDoubleBufferReInit_p
                    section.data(3).logicalSrcIdx = 55;
                    section.data(3).dtTransOffset = 2;

                    ;% Joystick_Visualization_2019a_DW.doneDoubleBufferReInit_d
                    section.data(4).logicalSrcIdx = 56;
                    section.data(4).dtTransOffset = 3;

                    ;% Joystick_Visualization_2019a_DW.doneDoubleBufferReInit_l
                    section.data(5).logicalSrcIdx = 57;
                    section.data(5).dtTransOffset = 4;

                    ;% Joystick_Visualization_2019a_DW.doneDoubleBufferReInit_f
                    section.data(6).logicalSrcIdx = 58;
                    section.data(6).dtTransOffset = 5;

                    ;% Joystick_Visualization_2019a_DW.FrSKYMapping_MODE
                    section.data(7).logicalSrcIdx = 59;
                    section.data(7).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            dworkMap.sections(10) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Joystick_Visualization_2019a_DW.UsedesiredYwhenenabled.Usedesheightwhenenabled_SubsysR
                    section.data(1).logicalSrcIdx = 60;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(11) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Joystick_Visualization_2019a_DW.UsedesiredYwhenenabled.Usedesheightwhenenabled_MODE
                    section.data(1).logicalSrcIdx = 61;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(12) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Joystick_Visualization_2019a_DW.UsedesiredXwhenenabled.Usedesheightwhenenabled_SubsysR
                    section.data(1).logicalSrcIdx = 62;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(13) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Joystick_Visualization_2019a_DW.UsedesiredXwhenenabled.Usedesheightwhenenabled_MODE
                    section.data(1).logicalSrcIdx = 63;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(14) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Joystick_Visualization_2019a_DW.Usedesyawwhenenabled.Usedesheightwhenenabled_SubsysR
                    section.data(1).logicalSrcIdx = 64;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(15) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Joystick_Visualization_2019a_DW.Usedesyawwhenenabled.Usedesheightwhenenabled_MODE
                    section.data(1).logicalSrcIdx = 65;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(16) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Joystick_Visualization_2019a_DW.Usedesheightwhenenabled.Usedesheightwhenenabled_SubsysR
                    section.data(1).logicalSrcIdx = 66;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(17) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Joystick_Visualization_2019a_DW.Usedesheightwhenenabled.Usedesheightwhenenabled_MODE
                    section.data(1).logicalSrcIdx = 67;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(18) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 1582488308;
    targMap.checksum1 = 609985076;
    targMap.checksum2 = 1662047858;
    targMap.checksum3 = 1640916765;

