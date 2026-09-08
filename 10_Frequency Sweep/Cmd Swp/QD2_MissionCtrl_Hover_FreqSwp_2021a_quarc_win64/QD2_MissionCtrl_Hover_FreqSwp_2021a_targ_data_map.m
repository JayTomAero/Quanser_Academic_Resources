    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 13;
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
        ;% Auto data (QD2_MissionCtrl_Hover_FreqSwp_P)
        ;%
            section.nData     = 13;
            section.data(13)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.CompareToConstant_const
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.CompareToConstant1_const
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.CompareToConstant_const_g
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.CompareToConstant_const_d
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.CompareToConstant_const_n
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.CompareToConstant1_const_i
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.StreamServer_default_value
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.Threshold_duration
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.Threshold_duration_l
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.Threshold_duration_b
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.Threshold_threshold
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 10;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.Threshold_threshold_p
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 11;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.Threshold_threshold_d
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 12;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.VRPNClient_trackers_jpl
                    section.data(1).logicalSrcIdx = 13;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.StopwithMessage_message_icon
                    section.data(1).logicalSrcIdx = 14;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.StringDisplay_alignment
                    section.data(1).logicalSrcIdx = 15;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.CompareToConstant_const_gq
                    section.data(2).logicalSrcIdx = 16;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.StringDisplay_display_mode
                    section.data(3).logicalSrcIdx = 17;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 50;
            section.data(50)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.HomePosemrad4_Y0
                    section.data(1).logicalSrcIdx = 18;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.Constant1_Value
                    section.data(2).logicalSrcIdx = 19;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.Constant_Value
                    section.data(3).logicalSrcIdx = 20;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.Yaw_Y0
                    section.data(4).logicalSrcIdx = 21;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.Throttle_Y0
                    section.data(5).logicalSrcIdx = 22;
                    section.data(5).dtTransOffset = 4;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.Roll_Y0
                    section.data(6).logicalSrcIdx = 23;
                    section.data(6).dtTransOffset = 5;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.Pitch_Y0
                    section.data(7).logicalSrcIdx = 24;
                    section.data(7).dtTransOffset = 6;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.DiscreteTimeIntegrator_gainval
                    section.data(8).logicalSrcIdx = 25;
                    section.data(8).dtTransOffset = 7;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.DiscreteTimeIntegrator_IC
                    section.data(9).logicalSrcIdx = 26;
                    section.data(9).dtTransOffset = 8;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.Gain_Gain
                    section.data(10).logicalSrcIdx = 27;
                    section.data(10).dtTransOffset = 9;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.Gain1_Gain
                    section.data(11).logicalSrcIdx = 28;
                    section.data(11).dtTransOffset = 10;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.Bias_Bias
                    section.data(12).logicalSrcIdx = 29;
                    section.data(12).dtTransOffset = 11;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.JoystickIssue01_Y0
                    section.data(13).logicalSrcIdx = 30;
                    section.data(13).dtTransOffset = 12;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.Triggers014_Y0
                    section.data(14).logicalSrcIdx = 31;
                    section.data(14).dtTransOffset = 13;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.Commands4_Y0
                    section.data(15).logicalSrcIdx = 32;
                    section.data(15).dtTransOffset = 14;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.DeadZone_Start
                    section.data(16).logicalSrcIdx = 33;
                    section.data(16).dtTransOffset = 15;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.DeadZone_End
                    section.data(17).logicalSrcIdx = 34;
                    section.data(17).dtTransOffset = 16;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.NumberofPulses_Y0
                    section.data(18).logicalSrcIdx = 35;
                    section.data(18).dtTransOffset = 17;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.Constant1_Value_p
                    section.data(19).logicalSrcIdx = 36;
                    section.data(19).dtTransOffset = 18;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.FixPtConstant_Value
                    section.data(20).logicalSrcIdx = 37;
                    section.data(20).dtTransOffset = 19;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.UnitDelay_InitialCondition
                    section.data(21).logicalSrcIdx = 38;
                    section.data(21).dtTransOffset = 20;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.PulseCheck_Value
                    section.data(22).logicalSrcIdx = 39;
                    section.data(22).dtTransOffset = 21;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.CustomMode_Value
                    section.data(23).logicalSrcIdx = 40;
                    section.data(23).dtTransOffset = 22;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.HomeMode_Value
                    section.data(24).logicalSrcIdx = 41;
                    section.data(24).dtTransOffset = 23;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.DefaultPosition_Value
                    section.data(25).logicalSrcIdx = 42;
                    section.data(25).dtTransOffset = 24;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.Homeheightm_Value
                    section.data(26).logicalSrcIdx = 43;
                    section.data(26).dtTransOffset = 28;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.Constant_Value_i
                    section.data(27).logicalSrcIdx = 44;
                    section.data(27).dtTransOffset = 29;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.Memory_InitialCondition
                    section.data(28).logicalSrcIdx = 45;
                    section.data(28).dtTransOffset = 30;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.Constant_Value_k
                    section.data(29).logicalSrcIdx = 46;
                    section.data(29).dtTransOffset = 31;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.DiscreteTimeIntegrator_gainva_j
                    section.data(30).logicalSrcIdx = 47;
                    section.data(30).dtTransOffset = 37;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.DiscreteTimeIntegrator_IC_j
                    section.data(31).logicalSrcIdx = 48;
                    section.data(31).dtTransOffset = 38;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.RateTransition2_InitialConditio
                    section.data(32).logicalSrcIdx = 49;
                    section.data(32).dtTransOffset = 39;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.SubtractRigidBodyReferenceOffse
                    section.data(33).logicalSrcIdx = 50;
                    section.data(33).dtTransOffset = 40;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.Saturation_UpperSat
                    section.data(34).logicalSrcIdx = 51;
                    section.data(34).dtTransOffset = 43;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.Saturation_LowerSat
                    section.data(35).logicalSrcIdx = 52;
                    section.data(35).dtTransOffset = 46;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.Unwrapoptitrackmeasurement_Modu
                    section.data(36).logicalSrcIdx = 53;
                    section.data(36).dtTransOffset = 49;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.width_Value
                    section.data(37).logicalSrcIdx = 54;
                    section.data(37).dtTransOffset = 50;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.one_shot_block_trigger_type
                    section.data(38).logicalSrcIdx = 55;
                    section.data(38).dtTransOffset = 51;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.one_shot_block_redun_pulse
                    section.data(39).logicalSrcIdx = 56;
                    section.data(39).dtTransOffset = 52;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.Switch_Threshold
                    section.data(40).logicalSrcIdx = 57;
                    section.data(40).dtTransOffset = 53;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.Switch_Threshold_l
                    section.data(41).logicalSrcIdx = 58;
                    section.data(41).dtTransOffset = 54;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.Constant_Value_h
                    section.data(42).logicalSrcIdx = 59;
                    section.data(42).dtTransOffset = 55;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.DiscreteTimeIntegrator_gainva_n
                    section.data(43).logicalSrcIdx = 60;
                    section.data(43).dtTransOffset = 56;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.DiscreteTimeIntegrator_IC_c
                    section.data(44).logicalSrcIdx = 61;
                    section.data(44).dtTransOffset = 57;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.RateTransition6_InitialConditio
                    section.data(45).logicalSrcIdx = 62;
                    section.data(45).dtTransOffset = 58;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.RateTransition7_InitialConditio
                    section.data(46).logicalSrcIdx = 63;
                    section.data(46).dtTransOffset = 59;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.RateTransition8_InitialConditio
                    section.data(47).logicalSrcIdx = 64;
                    section.data(47).dtTransOffset = 60;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.DummyTranslation_Value
                    section.data(48).logicalSrcIdx = 65;
                    section.data(48).dtTransOffset = 61;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.Constant_Value_j
                    section.data(49).logicalSrcIdx = 66;
                    section.data(49).dtTransOffset = 64;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.Gain_Gain_n
                    section.data(50).logicalSrcIdx = 67;
                    section.data(50).dtTransOffset = 65;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section

            section.nData     = 9;
            section.data(9)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.HostInitialize_SendBufferSize
                    section.data(1).logicalSrcIdx = 68;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.HostInitialize_ReceiveBufferSiz
                    section.data(2).logicalSrcIdx = 69;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.HostInitialize_ThreadPriority
                    section.data(3).logicalSrcIdx = 70;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.HostGameController_BufferSize
                    section.data(4).logicalSrcIdx = 71;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.StreamServer_SndPriority
                    section.data(5).logicalSrcIdx = 72;
                    section.data(5).dtTransOffset = 4;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.StreamServer_RcvPriority
                    section.data(6).logicalSrcIdx = 73;
                    section.data(6).dtTransOffset = 5;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.ToHostFile_Encoding
                    section.data(7).logicalSrcIdx = 74;
                    section.data(7).dtTransOffset = 6;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.VRPNClient_TraNumSensors
                    section.data(8).logicalSrcIdx = 75;
                    section.data(8).dtTransOffset = 7;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.VRPNClient_TraReadSensors
                    section.data(9).logicalSrcIdx = 76;
                    section.data(9).dtTransOffset = 8;

            nTotData = nTotData + section.nData;
            paramMap.sections(6) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.StreamServer_SndSize
                    section.data(1).logicalSrcIdx = 77;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.StreamServer_RcvSize
                    section.data(2).logicalSrcIdx = 78;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.StreamServer_SndFIFO
                    section.data(3).logicalSrcIdx = 79;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.StreamServer_RcvFIFO
                    section.data(4).logicalSrcIdx = 80;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.ToHostFile_Decimation
                    section.data(5).logicalSrcIdx = 81;
                    section.data(5).dtTransOffset = 4;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.ToHostFile_BitRate
                    section.data(6).logicalSrcIdx = 82;
                    section.data(6).dtTransOffset = 5;

            nTotData = nTotData + section.nData;
            paramMap.sections(7) = section;
            clear section

            section.nData     = 16;
            section.data(16)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.EmergencyAbortbool_Y0
                    section.data(1).logicalSrcIdx = 83;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.ArmDisarmbool_Y0
                    section.data(2).logicalSrcIdx = 84;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.TakeoffAutolandbool_Y0
                    section.data(3).logicalSrcIdx = 85;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.SysIDReq_Y0
                    section.data(4).logicalSrcIdx = 86;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.CommunicationIssue01_Y0
                    section.data(5).logicalSrcIdx = 87;
                    section.data(5).dtTransOffset = 4;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.Constant_Value_h0
                    section.data(6).logicalSrcIdx = 88;
                    section.data(6).dtTransOffset = 5;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.HostInitialize_RunClient
                    section.data(7).logicalSrcIdx = 89;
                    section.data(7).dtTransOffset = 6;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.HostInitialize_UseWindow
                    section.data(8).logicalSrcIdx = 90;
                    section.data(8).dtTransOffset = 7;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.HostInitialize_Active
                    section.data(9).logicalSrcIdx = 91;
                    section.data(9).dtTransOffset = 8;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.HostGameController_AutoCenter
                    section.data(10).logicalSrcIdx = 92;
                    section.data(10).dtTransOffset = 9;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.HostGameController_Enabled
                    section.data(11).logicalSrcIdx = 93;
                    section.data(11).dtTransOffset = 10;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.HostGameController_DebugMode
                    section.data(12).logicalSrcIdx = 94;
                    section.data(12).dtTransOffset = 11;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.StreamServer_Active
                    section.data(13).logicalSrcIdx = 95;
                    section.data(13).dtTransOffset = 12;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.Delay_InitialCondition
                    section.data(14).logicalSrcIdx = 96;
                    section.data(14).dtTransOffset = 13;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.Delay1_InitialCondition
                    section.data(15).logicalSrcIdx = 97;
                    section.data(15).dtTransOffset = 14;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.VRPNClient_Active
                    section.data(16).logicalSrcIdx = 98;
                    section.data(16).dtTransOffset = 15;

            nTotData = nTotData + section.nData;
            paramMap.sections(8) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.HostGameController_Controller
                    section.data(1).logicalSrcIdx = 99;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.StreamServer_Optimize
                    section.data(2).logicalSrcIdx = 100;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.StreamServer_Implementation
                    section.data(3).logicalSrcIdx = 101;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.ShowMessageonHost_MsgIcon
                    section.data(4).logicalSrcIdx = 102;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.ShowMessageonHost_MsgIcon_e
                    section.data(5).logicalSrcIdx = 103;
                    section.data(5).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            paramMap.sections(9) = section;
            clear section

            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.HostInitialize_URI
                    section.data(1).logicalSrcIdx = 104;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.ManualSwitch1_CurrentSetting
                    section.data(2).logicalSrcIdx = 105;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.CommandEnable_CurrentSetting
                    section.data(3).logicalSrcIdx = 106;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.StreamServer_URI
                    section.data(4).logicalSrcIdx = 107;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.StreamServer_Endian
                    section.data(5).logicalSrcIdx = 108;
                    section.data(5).dtTransOffset = 4;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.ToHostFile_VarName
                    section.data(6).logicalSrcIdx = 109;
                    section.data(6).dtTransOffset = 5;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.ToHostFile_FileFormat
                    section.data(7).logicalSrcIdx = 110;
                    section.data(7).dtTransOffset = 25;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.ToHostFile_file_name
                    section.data(8).logicalSrcIdx = 111;
                    section.data(8).dtTransOffset = 26;

            nTotData = nTotData + section.nData;
            paramMap.sections(10) = section;
            clear section

            section.nData     = 21;
            section.data(21)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.CoreSubsys.Constant_Value
                    section.data(1).logicalSrcIdx = 112;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.CoreSubsys.Constant_Value_e
                    section.data(2).logicalSrcIdx = 113;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.CoreSubsys.Constant_Value_b
                    section.data(3).logicalSrcIdx = 114;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.CoreSubsys.QualisysRotateMatrixR_VPRNcolum
                    section.data(4).logicalSrcIdx = 115;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.CoreSubsys.OptiTrackRotateMatrixR_Toolcolu
                    section.data(5).logicalSrcIdx = 116;
                    section.data(5).dtTransOffset = 12;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.CoreSubsys.PhaseSpaceRotateMatrixR_Toolcol
                    section.data(6).logicalSrcIdx = 117;
                    section.data(6).dtTransOffset = 21;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.CoreSubsys.GenericRotateMatrixR_VPRNcolumn
                    section.data(7).logicalSrcIdx = 118;
                    section.data(7).dtTransOffset = 30;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.CoreSubsys.GenericRotateMatrixR_Toolcolumn
                    section.data(8).logicalSrcIdx = 119;
                    section.data(8).dtTransOffset = 39;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.CoreSubsys.Gain6_Gain
                    section.data(9).logicalSrcIdx = 120;
                    section.data(9).dtTransOffset = 48;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.CoreSubsys.Gain1_Gain
                    section.data(10).logicalSrcIdx = 121;
                    section.data(10).dtTransOffset = 49;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.CoreSubsys.Gain_Gain
                    section.data(11).logicalSrcIdx = 122;
                    section.data(11).dtTransOffset = 50;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.CoreSubsys.Gain3_Gain
                    section.data(12).logicalSrcIdx = 123;
                    section.data(12).dtTransOffset = 51;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.CoreSubsys.Gain5_Gain
                    section.data(13).logicalSrcIdx = 124;
                    section.data(13).dtTransOffset = 52;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.CoreSubsys.Gain2_Gain
                    section.data(14).logicalSrcIdx = 125;
                    section.data(14).dtTransOffset = 53;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.CoreSubsys.Constant_Value_d
                    section.data(15).logicalSrcIdx = 126;
                    section.data(15).dtTransOffset = 54;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.CoreSubsys.Saturation_UpperSat
                    section.data(16).logicalSrcIdx = 127;
                    section.data(16).dtTransOffset = 55;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.CoreSubsys.Saturation_LowerSat
                    section.data(17).logicalSrcIdx = 128;
                    section.data(17).dtTransOffset = 56;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.CoreSubsys.Gain_Gain_b
                    section.data(18).logicalSrcIdx = 129;
                    section.data(18).dtTransOffset = 57;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.CoreSubsys.Saturation1_UpperSat
                    section.data(19).logicalSrcIdx = 130;
                    section.data(19).dtTransOffset = 58;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.CoreSubsys.Saturation1_LowerSat
                    section.data(20).logicalSrcIdx = 131;
                    section.data(20).dtTransOffset = 59;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.CoreSubsys.Gain1_Gain_a
                    section.data(21).logicalSrcIdx = 132;
                    section.data(21).dtTransOffset = 60;

            nTotData = nTotData + section.nData;
            paramMap.sections(11) = section;
            clear section

            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.CoreSubsys.Bias_Bias
                    section.data(1).logicalSrcIdx = 133;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.CoreSubsys.Bias1_Bias
                    section.data(2).logicalSrcIdx = 134;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.CoreSubsys.Bias2_Bias
                    section.data(3).logicalSrcIdx = 135;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.CoreSubsys.Bias1_Bias_i
                    section.data(4).logicalSrcIdx = 136;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.CoreSubsys.Bias_Bias_c
                    section.data(5).logicalSrcIdx = 137;
                    section.data(5).dtTransOffset = 4;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.CoreSubsys.Constant_Value_f
                    section.data(6).logicalSrcIdx = 138;
                    section.data(6).dtTransOffset = 5;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.CoreSubsys.Bias_Bias_a
                    section.data(7).logicalSrcIdx = 139;
                    section.data(7).dtTransOffset = 6;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.CoreSubsys.Constant_Value_n
                    section.data(8).logicalSrcIdx = 140;
                    section.data(8).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            paramMap.sections(12) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.CoreSubsys.Gain_Gain_c
                    section.data(1).logicalSrcIdx = 141;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.CoreSubsys.Gain1_Gain_f
                    section.data(2).logicalSrcIdx = 142;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.CoreSubsys.Gain2_Gain_h
                    section.data(3).logicalSrcIdx = 143;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.CoreSubsys.Gain1_Gain_k
                    section.data(4).logicalSrcIdx = 144;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.CoreSubsys.Gain_Gain_p
                    section.data(5).logicalSrcIdx = 145;
                    section.data(5).dtTransOffset = 4;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_P.CoreSubsys.Gain_Gain_co
                    section.data(6).logicalSrcIdx = 146;
                    section.data(6).dtTransOffset = 5;

            nTotData = nTotData + section.nData;
            paramMap.sections(13) = section;
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
        ;% Auto data (QD2_MissionCtrl_Hover_FreqSwp_B)
        ;%
            section.nData     = 46;
            section.data(46)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.DataTypeConversion
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.ManualSwitch1
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.RateTransition2
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 10;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.Reshape1
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 17;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.DataTypeConversion2
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 24;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.Saturation
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 25;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.DataTypeConversion1
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 28;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.Unwrapoptitrackmeasurement
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 31;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.one_shot_block
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 32;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.Switch
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 33;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.DesiredPosemrad
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 34;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.StreamServer_o4
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 38;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.DataTypeConversion_e
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 39;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.Product
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 40;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.Subtract
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 41;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.TmpSignalConversionAtToHostFile
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 42;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.RateTransition6
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 64;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.RateTransition7
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 73;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.Selector
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 82;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.RateTransition8
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 91;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.Selector1
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 100;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.VRPNClient_o1
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 109;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.VRPNClient_o2
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 112;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.VRPNClient_o3
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 116;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.VRPNClient_o4
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 119;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.VRPNClient_o5
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 123;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.VRPNClient_o6
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 124;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.VRPNClient_o7
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 127;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.VRPNClient_o8
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 131;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.Gain
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 132;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.Flight_State
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 135;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.FixPtSum1
                    section.data(32).logicalSrcIdx = 32;
                    section.data(32).dtTransOffset = 136;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.DataTypeConversion2_i
                    section.data(33).logicalSrcIdx = 33;
                    section.data(33).dtTransOffset = 137;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.DataTypeConversion4
                    section.data(34).logicalSrcIdx = 34;
                    section.data(34).dtTransOffset = 138;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.OutportBufferForJoystickIssue01
                    section.data(35).logicalSrcIdx = 35;
                    section.data(35).dtTransOffset = 139;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.Product_n
                    section.data(36).logicalSrcIdx = 36;
                    section.data(36).dtTransOffset = 140;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.Product1
                    section.data(37).logicalSrcIdx = 37;
                    section.data(37).dtTransOffset = 143;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.Product2
                    section.data(38).logicalSrcIdx = 38;
                    section.data(38).dtTransOffset = 144;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.Product3
                    section.data(39).logicalSrcIdx = 39;
                    section.data(39).dtTransOffset = 145;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.DataTypeConversion_g
                    section.data(40).logicalSrcIdx = 40;
                    section.data(40).dtTransOffset = 146;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.DiscreteTimeIntegrator
                    section.data(41).logicalSrcIdx = 41;
                    section.data(41).dtTransOffset = 147;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.Gain_h
                    section.data(42).logicalSrcIdx = 42;
                    section.data(42).dtTransOffset = 148;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.Bias
                    section.data(43).logicalSrcIdx = 43;
                    section.data(43).dtTransOffset = 149;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.y
                    section.data(44).logicalSrcIdx = 44;
                    section.data(44).dtTransOffset = 150;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.z
                    section.data(45).logicalSrcIdx = 45;
                    section.data(45).dtTransOffset = 151;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.Posemrad4
                    section.data(46).logicalSrcIdx = 46;
                    section.data(46).dtTransOffset = 152;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.HostInitialize_o2
                    section.data(1).logicalSrcIdx = 49;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.HostInitialize_o1
                    section.data(1).logicalSrcIdx = 50;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.ModelArgument
                    section.data(2).logicalSrcIdx = 51;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            sigMap.sections(3) = section;
            clear section

            section.nData     = 15;
            section.data(15)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.HostGameController_o1
                    section.data(1).logicalSrcIdx = 52;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.LogicalOperator
                    section.data(2).logicalSrcIdx = 53;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.LogicalOperator_l
                    section.data(3).logicalSrcIdx = 55;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.LogicalOperator_k
                    section.data(4).logicalSrcIdx = 56;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.Delay
                    section.data(5).logicalSrcIdx = 57;
                    section.data(5).dtTransOffset = 4;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.Compare
                    section.data(6).logicalSrcIdx = 58;
                    section.data(6).dtTransOffset = 5;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.OR
                    section.data(7).logicalSrcIdx = 59;
                    section.data(7).dtTransOffset = 6;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.VRPNClient_o9
                    section.data(8).logicalSrcIdx = 60;
                    section.data(8).dtTransOffset = 7;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.Compare_f
                    section.data(9).logicalSrcIdx = 61;
                    section.data(9).dtTransOffset = 8;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.Compare_g
                    section.data(10).logicalSrcIdx = 62;
                    section.data(10).dtTransOffset = 9;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.Buttons
                    section.data(11).logicalSrcIdx = 63;
                    section.data(11).dtTransOffset = 10;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.LogicalOperator_n
                    section.data(12).logicalSrcIdx = 64;
                    section.data(12).dtTransOffset = 42;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.RelationalOperator
                    section.data(13).logicalSrcIdx = 65;
                    section.data(13).dtTransOffset = 43;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.Compare_n
                    section.data(14).logicalSrcIdx = 66;
                    section.data(14).dtTransOffset = 44;

                    ;% QD2_MissionCtrl_Hover_FreqSwp_B.Compare_f2
                    section.data(15).logicalSrcIdx = 67;
                    section.data(15).dtTransOffset = 45;

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
        nTotSects     = 17;
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
        ;% Auto data (QD2_MissionCtrl_Hover_FreqSw_DW)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.VRPNClient_TrackerData
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.HostGameController_ControllerSt
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.HostGameController_Lock
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.Time_Timeout
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.Time_Timeout_m
                    section.data(2).logicalSrcIdx = 4;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.Time_Timeout_g
                    section.data(3).logicalSrcIdx = 5;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 13;
            section.data(13)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.DiscreteTimeIntegrator_DSTATE
                    section.data(1).logicalSrcIdx = 6;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.one_shot_block_DSTATE
                    section.data(2).logicalSrcIdx = 7;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.DiscreteTimeIntegrator_DSTATE_j
                    section.data(3).logicalSrcIdx = 8;
                    section.data(3).dtTransOffset = 4;

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.UnitDelay_DSTATE
                    section.data(4).logicalSrcIdx = 9;
                    section.data(4).dtTransOffset = 5;

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.DiscreteTimeIntegrator_DSTATE_h
                    section.data(5).logicalSrcIdx = 10;
                    section.data(5).dtTransOffset = 6;

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.RateTransition2_Buffer0
                    section.data(6).logicalSrcIdx = 11;
                    section.data(6).dtTransOffset = 7;

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.Unwrapoptitrackmeasurement_Prev
                    section.data(7).logicalSrcIdx = 12;
                    section.data(7).dtTransOffset = 14;

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.Unwrapoptitrackmeasurement_Revo
                    section.data(8).logicalSrcIdx = 13;
                    section.data(8).dtTransOffset = 15;

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.RateTransition6_Buffer0
                    section.data(9).logicalSrcIdx = 14;
                    section.data(9).dtTransOffset = 16;

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.RateTransition7_Buffer0
                    section.data(10).logicalSrcIdx = 15;
                    section.data(10).dtTransOffset = 25;

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.RateTransition8_Buffer0
                    section.data(11).logicalSrcIdx = 16;
                    section.data(11).dtTransOffset = 34;

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.Memory_PreviousInput
                    section.data(12).logicalSrcIdx = 17;
                    section.data(12).dtTransOffset = 43;

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.State
                    section.data(13).logicalSrcIdx = 18;
                    section.data(13).dtTransOffset = 44;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.StreamServer_Stream
                    section.data(1).logicalSrcIdx = 19;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.HostInitialize_ConnectedHandle
                    section.data(1).logicalSrcIdx = 20;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.VRPNClient_VRPNClient
                    section.data(1).logicalSrcIdx = 21;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(8) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.ToHostFile_PointsWritten
                    section.data(1).logicalSrcIdx = 22;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(9) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.Scope_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 23;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.ToHostFile_PWORK
                    section.data(2).logicalSrcIdx = 24;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.NewData_PWORK.LoggedData
                    section.data(3).logicalSrcIdx = 25;
                    section.data(3).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            dworkMap.sections(10) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.sfEvent
                    section.data(1).logicalSrcIdx = 26;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.sfEvent_m
                    section.data(2).logicalSrcIdx = 27;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(11) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.ToHostFile_SamplesCount
                    section.data(1).logicalSrcIdx = 28;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.ToHostFile_ArrayNameLength
                    section.data(2).logicalSrcIdx = 29;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(12) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.StringDisplay_IWORK
                    section.data(1).logicalSrcIdx = 30;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(13) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.Delay_DSTATE
                    section.data(1).logicalSrcIdx = 31;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.Delay1_DSTATE
                    section.data(2).logicalSrcIdx = 32;
                    section.data(2).dtTransOffset = 6000;

            nTotData = nTotData + section.nData;
            dworkMap.sections(14) = section;
            clear section

            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.DiscreteTimeIntegrator_PrevRese
                    section.data(1).logicalSrcIdx = 33;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.DiscreteTimeIntegrator_PrevRe_b
                    section.data(2).logicalSrcIdx = 34;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.TriggeredSubsystem_SubsysRanBC
                    section.data(3).logicalSrcIdx = 35;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.pulsecount_SubsysRanBC
                    section.data(4).logicalSrcIdx = 36;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.InitializationandConditioning_S
                    section.data(5).logicalSrcIdx = 37;
                    section.data(5).dtTransOffset = 4;

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.FrSKYMapping_SubsysRanBC
                    section.data(6).logicalSrcIdx = 38;
                    section.data(6).dtTransOffset = 5;

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.DiscreteTimeIntegrator_PrevRe_i
                    section.data(7).logicalSrcIdx = 39;
                    section.data(7).dtTransOffset = 6;

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.EnabledSubsystem_SubsysRanBC
                    section.data(8).logicalSrcIdx = 40;
                    section.data(8).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            dworkMap.sections(15) = section;
            clear section

            section.nData     = 11;
            section.data(11)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.HostGameController_NewData
                    section.data(1).logicalSrcIdx = 41;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.Time_Owner
                    section.data(2).logicalSrcIdx = 42;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.Unwrapoptitrackmeasurement_Firs
                    section.data(3).logicalSrcIdx = 43;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.Time_Owner_a
                    section.data(4).logicalSrcIdx = 44;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.StreamServer_Listening
                    section.data(5).logicalSrcIdx = 45;
                    section.data(5).dtTransOffset = 4;

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.Time_Owner_e
                    section.data(6).logicalSrcIdx = 46;
                    section.data(6).dtTransOffset = 5;

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.doneDoubleBufferReInit
                    section.data(7).logicalSrcIdx = 47;
                    section.data(7).dtTransOffset = 6;

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.State_not_empty
                    section.data(8).logicalSrcIdx = 48;
                    section.data(8).dtTransOffset = 7;

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.doneDoubleBufferReInit_c
                    section.data(9).logicalSrcIdx = 49;
                    section.data(9).dtTransOffset = 8;

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.FrSKYMapping_MODE
                    section.data(10).logicalSrcIdx = 50;
                    section.data(10).dtTransOffset = 9;

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.EnabledSubsystem_MODE
                    section.data(11).logicalSrcIdx = 51;
                    section.data(11).dtTransOffset = 10;

            nTotData = nTotData + section.nData;
            dworkMap.sections(16) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.CoreSubsys[0].q00_SubsysRanBC
                    section.data(1).logicalSrcIdx = 52;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.CoreSubsys[0].q10_SubsysRanBC
                    section.data(2).logicalSrcIdx = 53;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.CoreSubsys[0].q10_SubsysRanBC_a
                    section.data(3).logicalSrcIdx = 54;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_MissionCtrl_Hover_FreqSw_DW.CoreSubsys[0].q00_SubsysRanBC_b
                    section.data(4).logicalSrcIdx = 55;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            dworkMap.sections(17) = section;
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


    targMap.checksum0 = 4127139882;
    targMap.checksum1 = 2309731343;
    targMap.checksum2 = 1029588233;
    targMap.checksum3 = 3868340967;

