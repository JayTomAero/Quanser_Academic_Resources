    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
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
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (QD2_MissionCtrl_Manual_2021a_P)
        ;%
            section.nData     = 9;
            section.data(9)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Manual_2021a_P.CompareToConstant_const
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_Manual_2021a_P.CompareToConstant_const_f
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_Manual_2021a_P.StreamServer_default_value
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_MissionCtrl_Manual_2021a_P.Threshold_duration
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 4;

                    ;% QD2_MissionCtrl_Manual_2021a_P.Threshold_duration_d
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 5;

                    ;% QD2_MissionCtrl_Manual_2021a_P.Threshold_duration_b
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 6;

                    ;% QD2_MissionCtrl_Manual_2021a_P.Threshold_threshold
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 7;

                    ;% QD2_MissionCtrl_Manual_2021a_P.Threshold_threshold_h
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 8;

                    ;% QD2_MissionCtrl_Manual_2021a_P.Threshold_threshold_d
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 9;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Manual_2021a_P.StringDisplay_alignment
                    section.data(1).logicalSrcIdx = 9;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_Manual_2021a_P.StringDisplay_display_mode
                    section.data(2).logicalSrcIdx = 10;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 31;
            section.data(31)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Manual_2021a_P.Yaw_Y0
                    section.data(1).logicalSrcIdx = 11;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_Manual_2021a_P.Throttle_Y0
                    section.data(2).logicalSrcIdx = 12;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_Manual_2021a_P.Roll_Y0
                    section.data(3).logicalSrcIdx = 13;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_MissionCtrl_Manual_2021a_P.Pitch_Y0
                    section.data(4).logicalSrcIdx = 14;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_MissionCtrl_Manual_2021a_P.DiscreteTimeIntegrator_gainval
                    section.data(5).logicalSrcIdx = 15;
                    section.data(5).dtTransOffset = 4;

                    ;% QD2_MissionCtrl_Manual_2021a_P.DiscreteTimeIntegrator_IC
                    section.data(6).logicalSrcIdx = 16;
                    section.data(6).dtTransOffset = 5;

                    ;% QD2_MissionCtrl_Manual_2021a_P.Gain_Gain
                    section.data(7).logicalSrcIdx = 17;
                    section.data(7).dtTransOffset = 6;

                    ;% QD2_MissionCtrl_Manual_2021a_P.Gain1_Gain
                    section.data(8).logicalSrcIdx = 18;
                    section.data(8).dtTransOffset = 7;

                    ;% QD2_MissionCtrl_Manual_2021a_P.Bias_Bias
                    section.data(9).logicalSrcIdx = 19;
                    section.data(9).dtTransOffset = 8;

                    ;% QD2_MissionCtrl_Manual_2021a_P.JoystickIssue01_Y0
                    section.data(10).logicalSrcIdx = 20;
                    section.data(10).dtTransOffset = 9;

                    ;% QD2_MissionCtrl_Manual_2021a_P.Triggers014_Y0
                    section.data(11).logicalSrcIdx = 21;
                    section.data(11).dtTransOffset = 10;

                    ;% QD2_MissionCtrl_Manual_2021a_P.Commands4_Y0
                    section.data(12).logicalSrcIdx = 22;
                    section.data(12).dtTransOffset = 11;

                    ;% QD2_MissionCtrl_Manual_2021a_P.DeadZone_Start
                    section.data(13).logicalSrcIdx = 23;
                    section.data(13).dtTransOffset = 12;

                    ;% QD2_MissionCtrl_Manual_2021a_P.DeadZone_End
                    section.data(14).logicalSrcIdx = 24;
                    section.data(14).dtTransOffset = 13;

                    ;% QD2_MissionCtrl_Manual_2021a_P.NumberofPulses_Y0
                    section.data(15).logicalSrcIdx = 25;
                    section.data(15).dtTransOffset = 14;

                    ;% QD2_MissionCtrl_Manual_2021a_P.Constant1_Value
                    section.data(16).logicalSrcIdx = 26;
                    section.data(16).dtTransOffset = 15;

                    ;% QD2_MissionCtrl_Manual_2021a_P.FixPtConstant_Value
                    section.data(17).logicalSrcIdx = 27;
                    section.data(17).dtTransOffset = 16;

                    ;% QD2_MissionCtrl_Manual_2021a_P.UnitDelay_InitialCondition
                    section.data(18).logicalSrcIdx = 28;
                    section.data(18).dtTransOffset = 17;

                    ;% QD2_MissionCtrl_Manual_2021a_P.PulseCheck_Value
                    section.data(19).logicalSrcIdx = 29;
                    section.data(19).dtTransOffset = 18;

                    ;% QD2_MissionCtrl_Manual_2021a_P.Constant_Value
                    section.data(20).logicalSrcIdx = 30;
                    section.data(20).dtTransOffset = 19;

                    ;% QD2_MissionCtrl_Manual_2021a_P.Memory_InitialCondition
                    section.data(21).logicalSrcIdx = 31;
                    section.data(21).dtTransOffset = 20;

                    ;% QD2_MissionCtrl_Manual_2021a_P.Constant_Value_m
                    section.data(22).logicalSrcIdx = 32;
                    section.data(22).dtTransOffset = 21;

                    ;% QD2_MissionCtrl_Manual_2021a_P.DiscreteTimeIntegrator_gainva_b
                    section.data(23).logicalSrcIdx = 33;
                    section.data(23).dtTransOffset = 27;

                    ;% QD2_MissionCtrl_Manual_2021a_P.DiscreteTimeIntegrator_IC_m
                    section.data(24).logicalSrcIdx = 34;
                    section.data(24).dtTransOffset = 28;

                    ;% QD2_MissionCtrl_Manual_2021a_P.ManualFlightMode1TorqueMode0Ang
                    section.data(25).logicalSrcIdx = 35;
                    section.data(25).dtTransOffset = 29;

                    ;% QD2_MissionCtrl_Manual_2021a_P.MaxThrustis2044N_Gain
                    section.data(26).logicalSrcIdx = 36;
                    section.data(26).dtTransOffset = 30;

                    ;% QD2_MissionCtrl_Manual_2021a_P.u0915NmforRoll08984NmforPitch00
                    section.data(27).logicalSrcIdx = 37;
                    section.data(27).dtTransOffset = 31;

                    ;% QD2_MissionCtrl_Manual_2021a_P.pi4radforRollPitchpi2radsforYaw
                    section.data(28).logicalSrcIdx = 38;
                    section.data(28).dtTransOffset = 34;

                    ;% QD2_MissionCtrl_Manual_2021a_P.Constant_Value_h
                    section.data(29).logicalSrcIdx = 39;
                    section.data(29).dtTransOffset = 37;

                    ;% QD2_MissionCtrl_Manual_2021a_P.DiscreteTimeIntegrator_gainva_n
                    section.data(30).logicalSrcIdx = 40;
                    section.data(30).dtTransOffset = 38;

                    ;% QD2_MissionCtrl_Manual_2021a_P.DiscreteTimeIntegrator_IC_c
                    section.data(31).logicalSrcIdx = 41;
                    section.data(31).dtTransOffset = 39;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Manual_2021a_P.HostInitialize_SendBufferSize
                    section.data(1).logicalSrcIdx = 42;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_Manual_2021a_P.HostInitialize_ReceiveBufferSiz
                    section.data(2).logicalSrcIdx = 43;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_Manual_2021a_P.HostInitialize_ThreadPriority
                    section.data(3).logicalSrcIdx = 44;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_MissionCtrl_Manual_2021a_P.HostGameController_BufferSize
                    section.data(4).logicalSrcIdx = 45;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_MissionCtrl_Manual_2021a_P.StreamServer_SndPriority
                    section.data(5).logicalSrcIdx = 46;
                    section.data(5).dtTransOffset = 4;

                    ;% QD2_MissionCtrl_Manual_2021a_P.StreamServer_RcvPriority
                    section.data(6).logicalSrcIdx = 47;
                    section.data(6).dtTransOffset = 5;

                    ;% QD2_MissionCtrl_Manual_2021a_P.ToHostFile_Encoding
                    section.data(7).logicalSrcIdx = 48;
                    section.data(7).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Manual_2021a_P.StreamServer_SndSize
                    section.data(1).logicalSrcIdx = 49;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_Manual_2021a_P.StreamServer_RcvSize
                    section.data(2).logicalSrcIdx = 50;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_Manual_2021a_P.StreamServer_SndFIFO
                    section.data(3).logicalSrcIdx = 51;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_MissionCtrl_Manual_2021a_P.StreamServer_RcvFIFO
                    section.data(4).logicalSrcIdx = 52;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_MissionCtrl_Manual_2021a_P.ToHostFile_Decimation
                    section.data(5).logicalSrcIdx = 53;
                    section.data(5).dtTransOffset = 4;

                    ;% QD2_MissionCtrl_Manual_2021a_P.ToHostFile_BitRate
                    section.data(6).logicalSrcIdx = 54;
                    section.data(6).dtTransOffset = 5;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section

            section.nData     = 11;
            section.data(11)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Manual_2021a_P.EmergencyAbortbool_Y0
                    section.data(1).logicalSrcIdx = 55;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_Manual_2021a_P.ArmDisarmbool_Y0
                    section.data(2).logicalSrcIdx = 56;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_Manual_2021a_P.TakeoffAutolandbool_Y0
                    section.data(3).logicalSrcIdx = 57;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_MissionCtrl_Manual_2021a_P.CommunicationIssue01_Y0
                    section.data(4).logicalSrcIdx = 58;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_MissionCtrl_Manual_2021a_P.HostInitialize_RunClient
                    section.data(5).logicalSrcIdx = 59;
                    section.data(5).dtTransOffset = 4;

                    ;% QD2_MissionCtrl_Manual_2021a_P.HostInitialize_UseWindow
                    section.data(6).logicalSrcIdx = 60;
                    section.data(6).dtTransOffset = 5;

                    ;% QD2_MissionCtrl_Manual_2021a_P.HostInitialize_Active
                    section.data(7).logicalSrcIdx = 61;
                    section.data(7).dtTransOffset = 6;

                    ;% QD2_MissionCtrl_Manual_2021a_P.HostGameController_AutoCenter
                    section.data(8).logicalSrcIdx = 62;
                    section.data(8).dtTransOffset = 7;

                    ;% QD2_MissionCtrl_Manual_2021a_P.HostGameController_Enabled
                    section.data(9).logicalSrcIdx = 63;
                    section.data(9).dtTransOffset = 8;

                    ;% QD2_MissionCtrl_Manual_2021a_P.HostGameController_DebugMode
                    section.data(10).logicalSrcIdx = 64;
                    section.data(10).dtTransOffset = 9;

                    ;% QD2_MissionCtrl_Manual_2021a_P.StreamServer_Active
                    section.data(11).logicalSrcIdx = 65;
                    section.data(11).dtTransOffset = 10;

            nTotData = nTotData + section.nData;
            paramMap.sections(6) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Manual_2021a_P.HostGameController_Controller
                    section.data(1).logicalSrcIdx = 66;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_Manual_2021a_P.StreamServer_Optimize
                    section.data(2).logicalSrcIdx = 67;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_Manual_2021a_P.StreamServer_Implementation
                    section.data(3).logicalSrcIdx = 68;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_MissionCtrl_Manual_2021a_P.ShowMessageonHost_MsgIcon
                    section.data(4).logicalSrcIdx = 69;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_MissionCtrl_Manual_2021a_P.ShowMessageonHost_MsgIcon_p
                    section.data(5).logicalSrcIdx = 70;
                    section.data(5).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            paramMap.sections(7) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Manual_2021a_P.HostInitialize_URI
                    section.data(1).logicalSrcIdx = 71;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_Manual_2021a_P.ManualSwitch1_CurrentSetting
                    section.data(2).logicalSrcIdx = 72;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_Manual_2021a_P.StreamServer_URI
                    section.data(3).logicalSrcIdx = 73;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_MissionCtrl_Manual_2021a_P.StreamServer_Endian
                    section.data(4).logicalSrcIdx = 74;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_MissionCtrl_Manual_2021a_P.ToHostFile_VarName
                    section.data(5).logicalSrcIdx = 75;
                    section.data(5).dtTransOffset = 4;

                    ;% QD2_MissionCtrl_Manual_2021a_P.ToHostFile_FileFormat
                    section.data(6).logicalSrcIdx = 76;
                    section.data(6).dtTransOffset = 24;

                    ;% QD2_MissionCtrl_Manual_2021a_P.ToHostFile_file_name
                    section.data(7).logicalSrcIdx = 77;
                    section.data(7).dtTransOffset = 25;

            nTotData = nTotData + section.nData;
            paramMap.sections(8) = section;
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
        nTotSects     = 4;
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
        ;% Auto data (QD2_MissionCtrl_Manual_2021a_B)
        ;%
            section.nData     = 24;
            section.data(24)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Manual_2021a_B.DataTypeConversion
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_Manual_2021a_B.ManualSwitch1
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_Manual_2021a_B.MaxThrustis2044N
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 10;

                    ;% QD2_MissionCtrl_Manual_2021a_B.u0915NmforRoll08984NmforPitch00
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 11;

                    ;% QD2_MissionCtrl_Manual_2021a_B.pi4radforRollPitchpi2radsforYaw
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 14;

                    ;% QD2_MissionCtrl_Manual_2021a_B.StreamServer_o4
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 17;

                    ;% QD2_MissionCtrl_Manual_2021a_B.DataTypeConversion_e
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 19;

                    ;% QD2_MissionCtrl_Manual_2021a_B.Product
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 20;

                    ;% QD2_MissionCtrl_Manual_2021a_B.Subtract
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 21;

                    ;% QD2_MissionCtrl_Manual_2021a_B.TmpSignalConversionAtToHostFile
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 23;

                    ;% QD2_MissionCtrl_Manual_2021a_B.FixPtSum1
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 37;

                    ;% QD2_MissionCtrl_Manual_2021a_B.DataTypeConversion2
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 38;

                    ;% QD2_MissionCtrl_Manual_2021a_B.DataTypeConversion4
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 39;

                    ;% QD2_MissionCtrl_Manual_2021a_B.OutportBufferForJoystickIssue01
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 40;

                    ;% QD2_MissionCtrl_Manual_2021a_B.Product_b
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 41;

                    ;% QD2_MissionCtrl_Manual_2021a_B.Product1
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 44;

                    ;% QD2_MissionCtrl_Manual_2021a_B.Product2
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 45;

                    ;% QD2_MissionCtrl_Manual_2021a_B.Product3
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 46;

                    ;% QD2_MissionCtrl_Manual_2021a_B.DataTypeConversion_k
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 47;

                    ;% QD2_MissionCtrl_Manual_2021a_B.DiscreteTimeIntegrator
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 48;

                    ;% QD2_MissionCtrl_Manual_2021a_B.Gain
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 49;

                    ;% QD2_MissionCtrl_Manual_2021a_B.Bias
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 50;

                    ;% QD2_MissionCtrl_Manual_2021a_B.y
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 51;

                    ;% QD2_MissionCtrl_Manual_2021a_B.z
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 52;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Manual_2021a_B.HostInitialize_o2
                    section.data(1).logicalSrcIdx = 26;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Manual_2021a_B.HostInitialize_o1
                    section.data(1).logicalSrcIdx = 27;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_Manual_2021a_B.ModelArgument
                    section.data(2).logicalSrcIdx = 28;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            sigMap.sections(3) = section;
            clear section

            section.nData     = 9;
            section.data(9)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Manual_2021a_B.HostGameController_o1
                    section.data(1).logicalSrcIdx = 29;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_Manual_2021a_B.LogicalOperator
                    section.data(2).logicalSrcIdx = 30;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_Manual_2021a_B.LogicalOperator_k
                    section.data(3).logicalSrcIdx = 32;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_MissionCtrl_Manual_2021a_B.Compare
                    section.data(4).logicalSrcIdx = 33;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_MissionCtrl_Manual_2021a_B.Compare_n
                    section.data(5).logicalSrcIdx = 34;
                    section.data(5).dtTransOffset = 4;

                    ;% QD2_MissionCtrl_Manual_2021a_B.Buttons
                    section.data(6).logicalSrcIdx = 35;
                    section.data(6).dtTransOffset = 5;

                    ;% QD2_MissionCtrl_Manual_2021a_B.LogicalOperator_n
                    section.data(7).logicalSrcIdx = 36;
                    section.data(7).dtTransOffset = 37;

                    ;% QD2_MissionCtrl_Manual_2021a_B.RelationalOperator
                    section.data(8).logicalSrcIdx = 37;
                    section.data(8).dtTransOffset = 38;

                    ;% QD2_MissionCtrl_Manual_2021a_B.Compare_h
                    section.data(9).logicalSrcIdx = 38;
                    section.data(9).dtTransOffset = 39;

            nTotData = nTotData + section.nData;
            sigMap.sections(4) = section;
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
        nTotSects     = 13;
        sectIdxOffset = 4;

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
        ;% Auto data (QD2_MissionCtrl_Manual_2021a_DW)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Manual_2021a_DW.HostGameController_ControllerSt
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Manual_2021a_DW.HostGameController_Lock
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Manual_2021a_DW.Time_Timeout
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_Manual_2021a_DW.Time_Timeout_p
                    section.data(2).logicalSrcIdx = 3;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE
                    section.data(1).logicalSrcIdx = 4;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE_j
                    section.data(2).logicalSrcIdx = 5;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_Manual_2021a_DW.UnitDelay_DSTATE
                    section.data(3).logicalSrcIdx = 6;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_MissionCtrl_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE_a
                    section.data(4).logicalSrcIdx = 7;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_MissionCtrl_Manual_2021a_DW.Memory_PreviousInput
                    section.data(5).logicalSrcIdx = 8;
                    section.data(5).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Manual_2021a_DW.StreamServer_Stream
                    section.data(1).logicalSrcIdx = 9;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Manual_2021a_DW.HostInitialize_ConnectedHandle
                    section.data(1).logicalSrcIdx = 10;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Manual_2021a_DW.ToHostFile_PointsWritten
                    section.data(1).logicalSrcIdx = 11;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Manual_2021a_DW.Scope_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 12;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_Manual_2021a_DW.ToHostFile_PWORK
                    section.data(2).logicalSrcIdx = 13;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(8) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Manual_2021a_DW.sfEvent
                    section.data(1).logicalSrcIdx = 14;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(9) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Manual_2021a_DW.ToHostFile_SamplesCount
                    section.data(1).logicalSrcIdx = 15;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_Manual_2021a_DW.ToHostFile_ArrayNameLength
                    section.data(2).logicalSrcIdx = 16;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(10) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Manual_2021a_DW.StringDisplay_IWORK
                    section.data(1).logicalSrcIdx = 17;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(11) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Manual_2021a_DW.DiscreteTimeIntegrator_PrevRese
                    section.data(1).logicalSrcIdx = 18;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_Manual_2021a_DW.DiscreteTimeIntegrator_PrevRe_b
                    section.data(2).logicalSrcIdx = 19;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_Manual_2021a_DW.TriggeredSubsystem_SubsysRanBC
                    section.data(3).logicalSrcIdx = 20;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_MissionCtrl_Manual_2021a_DW.pulsecount_SubsysRanBC
                    section.data(4).logicalSrcIdx = 21;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_MissionCtrl_Manual_2021a_DW.InitializationandConditioning_S
                    section.data(5).logicalSrcIdx = 22;
                    section.data(5).dtTransOffset = 4;

                    ;% QD2_MissionCtrl_Manual_2021a_DW.FrSKYMapping_SubsysRanBC
                    section.data(6).logicalSrcIdx = 23;
                    section.data(6).dtTransOffset = 5;

                    ;% QD2_MissionCtrl_Manual_2021a_DW.DiscreteTimeIntegrator_PrevR_bf
                    section.data(7).logicalSrcIdx = 24;
                    section.data(7).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            dworkMap.sections(12) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Manual_2021a_DW.HostGameController_NewData
                    section.data(1).logicalSrcIdx = 25;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_Manual_2021a_DW.Time_Owner
                    section.data(2).logicalSrcIdx = 26;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_Manual_2021a_DW.Time_Owner_o
                    section.data(3).logicalSrcIdx = 27;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_MissionCtrl_Manual_2021a_DW.StreamServer_Listening
                    section.data(4).logicalSrcIdx = 28;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_MissionCtrl_Manual_2021a_DW.doneDoubleBufferReInit
                    section.data(5).logicalSrcIdx = 29;
                    section.data(5).dtTransOffset = 4;

                    ;% QD2_MissionCtrl_Manual_2021a_DW.FrSKYMapping_MODE
                    section.data(6).logicalSrcIdx = 30;
                    section.data(6).dtTransOffset = 5;

            nTotData = nTotData + section.nData;
            dworkMap.sections(13) = section;
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


    targMap.checksum0 = 909136845;
    targMap.checksum1 = 1981442374;
    targMap.checksum2 = 465213708;
    targMap.checksum3 = 3933833137;

