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
        ;% Auto data (QD2_MissionCtrl_ManualPC_2021_P)
        ;%
            section.nData     = 12;
            section.data(12)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_ManualPC_2021_P.CompareToConstant_const
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.CompareToConstant_const_g
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.CompareToConstant_const_d
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.CompareToConstant_const_i
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.CompareToConstant1_const
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.StreamServer_default_value
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.Threshold_duration
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.Threshold_duration_l
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.Threshold_duration_b
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.Threshold_threshold
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.Threshold_threshold_p
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 10;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.Threshold_threshold_d
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 11;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_ManualPC_2021_P.VRPNClient_trackers_jpl
                    section.data(1).logicalSrcIdx = 12;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_ManualPC_2021_P.StopwithMessage_message_icon
                    section.data(1).logicalSrcIdx = 13;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_ManualPC_2021_P.StringDisplay_alignment
                    section.data(1).logicalSrcIdx = 14;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.StringDisplay_display_mode
                    section.data(2).logicalSrcIdx = 15;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 66;
            section.data(66)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_ManualPC_2021_P.HomePosemrad4_Y0
                    section.data(1).logicalSrcIdx = 16;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.Constant1_Value
                    section.data(2).logicalSrcIdx = 17;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.Constant_Value
                    section.data(3).logicalSrcIdx = 18;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.Yaw_Y0
                    section.data(4).logicalSrcIdx = 19;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.Throttle_Y0
                    section.data(5).logicalSrcIdx = 20;
                    section.data(5).dtTransOffset = 4;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.Roll_Y0
                    section.data(6).logicalSrcIdx = 21;
                    section.data(6).dtTransOffset = 5;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.Pitch_Y0
                    section.data(7).logicalSrcIdx = 22;
                    section.data(7).dtTransOffset = 6;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.DiscreteTimeIntegrator_gainval
                    section.data(8).logicalSrcIdx = 23;
                    section.data(8).dtTransOffset = 7;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.DiscreteTimeIntegrator_IC
                    section.data(9).logicalSrcIdx = 24;
                    section.data(9).dtTransOffset = 8;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.Gain_Gain
                    section.data(10).logicalSrcIdx = 25;
                    section.data(10).dtTransOffset = 9;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.Gain1_Gain
                    section.data(11).logicalSrcIdx = 26;
                    section.data(11).dtTransOffset = 10;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.Bias_Bias
                    section.data(12).logicalSrcIdx = 27;
                    section.data(12).dtTransOffset = 11;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.JoystickIssue01_Y0
                    section.data(13).logicalSrcIdx = 28;
                    section.data(13).dtTransOffset = 12;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.Triggers014_Y0
                    section.data(14).logicalSrcIdx = 29;
                    section.data(14).dtTransOffset = 13;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.Commands4_Y0
                    section.data(15).logicalSrcIdx = 30;
                    section.data(15).dtTransOffset = 14;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.DeadZone_Start
                    section.data(16).logicalSrcIdx = 31;
                    section.data(16).dtTransOffset = 15;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.DeadZone_End
                    section.data(17).logicalSrcIdx = 32;
                    section.data(17).dtTransOffset = 16;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.NumberofPulses_Y0
                    section.data(18).logicalSrcIdx = 33;
                    section.data(18).dtTransOffset = 17;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.Constant1_Value_p
                    section.data(19).logicalSrcIdx = 34;
                    section.data(19).dtTransOffset = 18;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.FixPtConstant_Value
                    section.data(20).logicalSrcIdx = 35;
                    section.data(20).dtTransOffset = 19;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.UnitDelay_InitialCondition
                    section.data(21).logicalSrcIdx = 36;
                    section.data(21).dtTransOffset = 20;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.PulseCheck_Value
                    section.data(22).logicalSrcIdx = 37;
                    section.data(22).dtTransOffset = 21;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.CustomMode_Value
                    section.data(23).logicalSrcIdx = 38;
                    section.data(23).dtTransOffset = 22;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.HomeMode_Value
                    section.data(24).logicalSrcIdx = 39;
                    section.data(24).dtTransOffset = 23;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.Constant_Value_i
                    section.data(25).logicalSrcIdx = 40;
                    section.data(25).dtTransOffset = 24;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.Memory_InitialCondition
                    section.data(26).logicalSrcIdx = 41;
                    section.data(26).dtTransOffset = 25;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.Constant_Value_k
                    section.data(27).logicalSrcIdx = 42;
                    section.data(27).dtTransOffset = 26;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.DiscreteTimeIntegrator_gainva_j
                    section.data(28).logicalSrcIdx = 43;
                    section.data(28).dtTransOffset = 32;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.DiscreteTimeIntegrator_IC_j
                    section.data(29).logicalSrcIdx = 44;
                    section.data(29).dtTransOffset = 33;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.RateTransition2_InitialConditio
                    section.data(30).logicalSrcIdx = 45;
                    section.data(30).dtTransOffset = 34;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.SubtractRigidBodyReferenceOffse
                    section.data(31).logicalSrcIdx = 46;
                    section.data(31).dtTransOffset = 35;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.Saturation_UpperSat
                    section.data(32).logicalSrcIdx = 47;
                    section.data(32).dtTransOffset = 38;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.Saturation_LowerSat
                    section.data(33).logicalSrcIdx = 48;
                    section.data(33).dtTransOffset = 41;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.Unwrapoptitrackmeasurement_Modu
                    section.data(34).logicalSrcIdx = 49;
                    section.data(34).dtTransOffset = 44;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.CubeLengthm_Value
                    section.data(35).logicalSrcIdx = 50;
                    section.data(35).dtTransOffset = 45;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.Integrator_IC
                    section.data(36).logicalSrcIdx = 51;
                    section.data(36).dtTransOffset = 46;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.Memory1_InitialCondition
                    section.data(37).logicalSrcIdx = 52;
                    section.data(37).dtTransOffset = 47;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.Constant_Value_iq
                    section.data(38).logicalSrcIdx = 53;
                    section.data(38).dtTransOffset = 48;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.XVelocityScaling_Gain
                    section.data(39).logicalSrcIdx = 54;
                    section.data(39).dtTransOffset = 49;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.YVelocityScaling_Gain
                    section.data(40).logicalSrcIdx = 55;
                    section.data(40).dtTransOffset = 50;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.HeightVelocityScaling_Gain
                    section.data(41).logicalSrcIdx = 56;
                    section.data(41).dtTransOffset = 51;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.Integrator2_IC
                    section.data(42).logicalSrcIdx = 57;
                    section.data(42).dtTransOffset = 52;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.width_Value
                    section.data(43).logicalSrcIdx = 58;
                    section.data(43).dtTransOffset = 53;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.one_shot_block_trigger_type
                    section.data(44).logicalSrcIdx = 59;
                    section.data(44).dtTransOffset = 54;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.one_shot_block_redun_pulse
                    section.data(45).logicalSrcIdx = 60;
                    section.data(45).dtTransOffset = 55;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.Switch_Threshold
                    section.data(46).logicalSrcIdx = 61;
                    section.data(46).dtTransOffset = 56;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.Homeheightm_Value
                    section.data(47).logicalSrcIdx = 62;
                    section.data(47).dtTransOffset = 57;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.Gain2_Gain
                    section.data(48).logicalSrcIdx = 63;
                    section.data(48).dtTransOffset = 58;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.Gain_Gain_f
                    section.data(49).logicalSrcIdx = 64;
                    section.data(49).dtTransOffset = 62;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.MinimumFlightHeight_Value
                    section.data(50).logicalSrcIdx = 65;
                    section.data(50).dtTransOffset = 63;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.Switch_Threshold_l
                    section.data(51).logicalSrcIdx = 66;
                    section.data(51).dtTransOffset = 64;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.Constant_Value_h
                    section.data(52).logicalSrcIdx = 67;
                    section.data(52).dtTransOffset = 65;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.DiscreteTimeIntegrator_gainva_n
                    section.data(53).logicalSrcIdx = 68;
                    section.data(53).dtTransOffset = 66;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.DiscreteTimeIntegrator_IC_c
                    section.data(54).logicalSrcIdx = 69;
                    section.data(54).dtTransOffset = 67;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.RateTransition6_InitialConditio
                    section.data(55).logicalSrcIdx = 70;
                    section.data(55).dtTransOffset = 68;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.RateTransition7_InitialConditio
                    section.data(56).logicalSrcIdx = 71;
                    section.data(56).dtTransOffset = 69;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.RateTransition8_InitialConditio
                    section.data(57).logicalSrcIdx = 72;
                    section.data(57).dtTransOffset = 70;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.DummyTranslation_Value
                    section.data(58).logicalSrcIdx = 73;
                    section.data(58).dtTransOffset = 71;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.Constant1_Value_a
                    section.data(59).logicalSrcIdx = 74;
                    section.data(59).dtTransOffset = 74;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.Constant2_Value
                    section.data(60).logicalSrcIdx = 75;
                    section.data(60).dtTransOffset = 76;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.Constant3_Value
                    section.data(61).logicalSrcIdx = 76;
                    section.data(61).dtTransOffset = 78;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.Gain3_Gain
                    section.data(62).logicalSrcIdx = 77;
                    section.data(62).dtTransOffset = 80;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.Switch_Threshold_k
                    section.data(63).logicalSrcIdx = 78;
                    section.data(63).dtTransOffset = 81;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.YawVelocityScaling_Gain
                    section.data(64).logicalSrcIdx = 79;
                    section.data(64).dtTransOffset = 82;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.Constant_Value_a
                    section.data(65).logicalSrcIdx = 80;
                    section.data(65).dtTransOffset = 83;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.Gain_Gain_b
                    section.data(66).logicalSrcIdx = 81;
                    section.data(66).dtTransOffset = 84;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section

            section.nData     = 9;
            section.data(9)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_ManualPC_2021_P.HostInitialize_SendBufferSize
                    section.data(1).logicalSrcIdx = 82;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.HostInitialize_ReceiveBufferSiz
                    section.data(2).logicalSrcIdx = 83;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.HostInitialize_ThreadPriority
                    section.data(3).logicalSrcIdx = 84;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.HostGameController_BufferSize
                    section.data(4).logicalSrcIdx = 85;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.StreamServer_SndPriority
                    section.data(5).logicalSrcIdx = 86;
                    section.data(5).dtTransOffset = 4;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.StreamServer_RcvPriority
                    section.data(6).logicalSrcIdx = 87;
                    section.data(6).dtTransOffset = 5;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.ToHostFile_Encoding
                    section.data(7).logicalSrcIdx = 88;
                    section.data(7).dtTransOffset = 6;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.VRPNClient_TraNumSensors
                    section.data(8).logicalSrcIdx = 89;
                    section.data(8).dtTransOffset = 7;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.VRPNClient_TraReadSensors
                    section.data(9).logicalSrcIdx = 90;
                    section.data(9).dtTransOffset = 8;

            nTotData = nTotData + section.nData;
            paramMap.sections(6) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_ManualPC_2021_P.StreamServer_SndSize
                    section.data(1).logicalSrcIdx = 91;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.StreamServer_RcvSize
                    section.data(2).logicalSrcIdx = 92;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.StreamServer_SndFIFO
                    section.data(3).logicalSrcIdx = 93;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.StreamServer_RcvFIFO
                    section.data(4).logicalSrcIdx = 94;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.ToHostFile_Decimation
                    section.data(5).logicalSrcIdx = 95;
                    section.data(5).dtTransOffset = 4;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.ToHostFile_BitRate
                    section.data(6).logicalSrcIdx = 96;
                    section.data(6).dtTransOffset = 5;

            nTotData = nTotData + section.nData;
            paramMap.sections(7) = section;
            clear section

            section.nData     = 16;
            section.data(16)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_ManualPC_2021_P.EmergencyAbortbool_Y0
                    section.data(1).logicalSrcIdx = 97;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.ArmDisarmbool_Y0
                    section.data(2).logicalSrcIdx = 98;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.TakeoffAutolandbool_Y0
                    section.data(3).logicalSrcIdx = 99;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.CommunicationIssue01_Y0
                    section.data(4).logicalSrcIdx = 100;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.Constant_Value_o
                    section.data(5).logicalSrcIdx = 101;
                    section.data(5).dtTransOffset = 4;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.HostInitialize_RunClient
                    section.data(6).logicalSrcIdx = 102;
                    section.data(6).dtTransOffset = 5;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.HostInitialize_UseWindow
                    section.data(7).logicalSrcIdx = 103;
                    section.data(7).dtTransOffset = 6;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.HostInitialize_Active
                    section.data(8).logicalSrcIdx = 104;
                    section.data(8).dtTransOffset = 7;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.HostGameController_AutoCenter
                    section.data(9).logicalSrcIdx = 105;
                    section.data(9).dtTransOffset = 8;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.HostGameController_Enabled
                    section.data(10).logicalSrcIdx = 106;
                    section.data(10).dtTransOffset = 9;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.HostGameController_DebugMode
                    section.data(11).logicalSrcIdx = 107;
                    section.data(11).dtTransOffset = 10;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.StreamServer_Active
                    section.data(12).logicalSrcIdx = 108;
                    section.data(12).dtTransOffset = 11;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.Delay_InitialCondition
                    section.data(13).logicalSrcIdx = 109;
                    section.data(13).dtTransOffset = 12;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.Delay1_InitialCondition
                    section.data(14).logicalSrcIdx = 110;
                    section.data(14).dtTransOffset = 13;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.Memory_InitialCondition_m
                    section.data(15).logicalSrcIdx = 111;
                    section.data(15).dtTransOffset = 14;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.VRPNClient_Active
                    section.data(16).logicalSrcIdx = 112;
                    section.data(16).dtTransOffset = 16;

            nTotData = nTotData + section.nData;
            paramMap.sections(8) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_ManualPC_2021_P.HostGameController_Controller
                    section.data(1).logicalSrcIdx = 113;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.StreamServer_Optimize
                    section.data(2).logicalSrcIdx = 114;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.StreamServer_Implementation
                    section.data(3).logicalSrcIdx = 115;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.ShowMessageonHost_MsgIcon
                    section.data(4).logicalSrcIdx = 116;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.ShowMessageonHost_MsgIcon_e
                    section.data(5).logicalSrcIdx = 117;
                    section.data(5).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            paramMap.sections(9) = section;
            clear section

            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_ManualPC_2021_P.HostInitialize_URI
                    section.data(1).logicalSrcIdx = 118;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.ManualSwitch1_CurrentSetting
                    section.data(2).logicalSrcIdx = 119;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.CommandEnable_CurrentSetting
                    section.data(3).logicalSrcIdx = 120;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.StreamServer_URI
                    section.data(4).logicalSrcIdx = 121;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.StreamServer_Endian
                    section.data(5).logicalSrcIdx = 122;
                    section.data(5).dtTransOffset = 4;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.ToHostFile_VarName
                    section.data(6).logicalSrcIdx = 123;
                    section.data(6).dtTransOffset = 5;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.ToHostFile_FileFormat
                    section.data(7).logicalSrcIdx = 124;
                    section.data(7).dtTransOffset = 25;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.ToHostFile_file_name
                    section.data(8).logicalSrcIdx = 125;
                    section.data(8).dtTransOffset = 26;

            nTotData = nTotData + section.nData;
            paramMap.sections(10) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys_p.one_shot_block_trigger_type
                    section.data(1).logicalSrcIdx = 126;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys_p.one_shot_block_redun_pulse
                    section.data(2).logicalSrcIdx = 127;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys_p.Switch_Threshold
                    section.data(3).logicalSrcIdx = 128;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            paramMap.sections(11) = section;
            clear section

            section.nData     = 21;
            section.data(21)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Constant_Value
                    section.data(1).logicalSrcIdx = 129;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Constant_Value_d
                    section.data(2).logicalSrcIdx = 130;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Constant_Value_p
                    section.data(3).logicalSrcIdx = 131;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.QualisysRotateMatrixR_VPRNcolum
                    section.data(4).logicalSrcIdx = 132;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.OptiTrackRotateMatrixR_Toolcolu
                    section.data(5).logicalSrcIdx = 133;
                    section.data(5).dtTransOffset = 12;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.PhaseSpaceRotateMatrixR_Toolcol
                    section.data(6).logicalSrcIdx = 134;
                    section.data(6).dtTransOffset = 21;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.GenericRotateMatrixR_VPRNcolumn
                    section.data(7).logicalSrcIdx = 135;
                    section.data(7).dtTransOffset = 30;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.GenericRotateMatrixR_Toolcolumn
                    section.data(8).logicalSrcIdx = 136;
                    section.data(8).dtTransOffset = 39;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Gain6_Gain
                    section.data(9).logicalSrcIdx = 137;
                    section.data(9).dtTransOffset = 48;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Gain1_Gain
                    section.data(10).logicalSrcIdx = 138;
                    section.data(10).dtTransOffset = 49;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Gain_Gain
                    section.data(11).logicalSrcIdx = 139;
                    section.data(11).dtTransOffset = 50;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Gain3_Gain
                    section.data(12).logicalSrcIdx = 140;
                    section.data(12).dtTransOffset = 51;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Gain5_Gain
                    section.data(13).logicalSrcIdx = 141;
                    section.data(13).dtTransOffset = 52;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Gain2_Gain
                    section.data(14).logicalSrcIdx = 142;
                    section.data(14).dtTransOffset = 53;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Constant_Value_i
                    section.data(15).logicalSrcIdx = 143;
                    section.data(15).dtTransOffset = 54;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Saturation_UpperSat
                    section.data(16).logicalSrcIdx = 144;
                    section.data(16).dtTransOffset = 55;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Saturation_LowerSat
                    section.data(17).logicalSrcIdx = 145;
                    section.data(17).dtTransOffset = 56;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Gain_Gain_c
                    section.data(18).logicalSrcIdx = 146;
                    section.data(18).dtTransOffset = 57;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Saturation1_UpperSat
                    section.data(19).logicalSrcIdx = 147;
                    section.data(19).dtTransOffset = 58;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Saturation1_LowerSat
                    section.data(20).logicalSrcIdx = 148;
                    section.data(20).dtTransOffset = 59;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Gain1_Gain_n
                    section.data(21).logicalSrcIdx = 149;
                    section.data(21).dtTransOffset = 60;

            nTotData = nTotData + section.nData;
            paramMap.sections(12) = section;
            clear section

            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Bias_Bias
                    section.data(1).logicalSrcIdx = 150;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Bias1_Bias
                    section.data(2).logicalSrcIdx = 151;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Bias2_Bias
                    section.data(3).logicalSrcIdx = 152;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Bias1_Bias_m
                    section.data(4).logicalSrcIdx = 153;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Bias_Bias_d
                    section.data(5).logicalSrcIdx = 154;
                    section.data(5).dtTransOffset = 4;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Constant_Value_iu
                    section.data(6).logicalSrcIdx = 155;
                    section.data(6).dtTransOffset = 5;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Bias_Bias_f
                    section.data(7).logicalSrcIdx = 156;
                    section.data(7).dtTransOffset = 6;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Constant_Value_i2
                    section.data(8).logicalSrcIdx = 157;
                    section.data(8).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            paramMap.sections(13) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Gain_Gain_i
                    section.data(1).logicalSrcIdx = 158;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Gain1_Gain_k
                    section.data(2).logicalSrcIdx = 159;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Gain2_Gain_n
                    section.data(3).logicalSrcIdx = 160;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Gain1_Gain_m
                    section.data(4).logicalSrcIdx = 161;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Gain_Gain_a
                    section.data(5).logicalSrcIdx = 162;
                    section.data(5).dtTransOffset = 4;

                    ;% QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Gain_Gain_i0
                    section.data(6).logicalSrcIdx = 163;
                    section.data(6).dtTransOffset = 5;

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
        nTotSects     = 5;
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
        ;% Auto data (QD2_MissionCtrl_ManualPC_2021_B)
        ;%
            section.nData     = 57;
            section.data(57)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_ManualPC_2021_B.DataTypeConversion
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.ManualSwitch1
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.RateTransition2
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 10;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.Reshape1
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 17;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.DataTypeConversion2
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 24;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.Saturation
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 25;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.DataTypeConversion1
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 28;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.Unwrapoptitrackmeasurement
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 31;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.MatrixMultiply
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 32;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.Integrator2
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 35;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.one_shot_block
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 36;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.Switch
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 37;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.Sum
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 38;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.Gain
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 42;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.Switch2
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 43;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.Switch2_h
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 45;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.CommandEnable
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 46;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.DesiredPosemrad
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 47;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.StreamServer_o4
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 51;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.DataTypeConversion_e
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 52;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.Product
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 53;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.Subtract
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 54;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.TmpSignalConversionAtToHostFile
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 55;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.RateTransition6
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 77;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.RateTransition7
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 86;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.Selector
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 95;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.RateTransition8
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 104;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.Selector1
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 113;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.Abs
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 122;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.Switch_g
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 124;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.YawVelocityScaling
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 126;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.VRPNClient_o1
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 127;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.VRPNClient_o2
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 130;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.VRPNClient_o3
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 134;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.VRPNClient_o4
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 137;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.VRPNClient_o5
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 141;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.VRPNClient_o6
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 142;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.VRPNClient_o7
                    section.data(38).logicalSrcIdx = 37;
                    section.data(38).dtTransOffset = 145;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.VRPNClient_o8
                    section.data(39).logicalSrcIdx = 38;
                    section.data(39).dtTransOffset = 149;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.Gain_i
                    section.data(40).logicalSrcIdx = 39;
                    section.data(40).dtTransOffset = 150;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.ImpAsg_InsertedFor_OutputSignal
                    section.data(41).logicalSrcIdx = 40;
                    section.data(41).dtTransOffset = 153;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.Flight_State
                    section.data(42).logicalSrcIdx = 41;
                    section.data(42).dtTransOffset = 155;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.FixPtSum1
                    section.data(43).logicalSrcIdx = 43;
                    section.data(43).dtTransOffset = 156;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.DataTypeConversion2_i
                    section.data(44).logicalSrcIdx = 44;
                    section.data(44).dtTransOffset = 157;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.DataTypeConversion4
                    section.data(45).logicalSrcIdx = 45;
                    section.data(45).dtTransOffset = 158;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.OutportBufferForJoystickIssue01
                    section.data(46).logicalSrcIdx = 46;
                    section.data(46).dtTransOffset = 159;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.Product_n
                    section.data(47).logicalSrcIdx = 47;
                    section.data(47).dtTransOffset = 160;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.Product1
                    section.data(48).logicalSrcIdx = 48;
                    section.data(48).dtTransOffset = 163;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.Product2
                    section.data(49).logicalSrcIdx = 49;
                    section.data(49).dtTransOffset = 164;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.Product3
                    section.data(50).logicalSrcIdx = 50;
                    section.data(50).dtTransOffset = 165;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.DataTypeConversion_g
                    section.data(51).logicalSrcIdx = 51;
                    section.data(51).dtTransOffset = 166;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.DiscreteTimeIntegrator
                    section.data(52).logicalSrcIdx = 52;
                    section.data(52).dtTransOffset = 167;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.Gain_h
                    section.data(53).logicalSrcIdx = 53;
                    section.data(53).dtTransOffset = 168;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.Bias
                    section.data(54).logicalSrcIdx = 54;
                    section.data(54).dtTransOffset = 169;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.y
                    section.data(55).logicalSrcIdx = 55;
                    section.data(55).dtTransOffset = 170;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.z
                    section.data(56).logicalSrcIdx = 56;
                    section.data(56).dtTransOffset = 171;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.Posemrad4
                    section.data(57).logicalSrcIdx = 57;
                    section.data(57).dtTransOffset = 172;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_ManualPC_2021_B.HostInitialize_o2
                    section.data(1).logicalSrcIdx = 60;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_ManualPC_2021_B.HostInitialize_o1
                    section.data(1).logicalSrcIdx = 61;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.ModelArgument
                    section.data(2).logicalSrcIdx = 62;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            sigMap.sections(3) = section;
            clear section

            section.nData     = 17;
            section.data(17)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_ManualPC_2021_B.HostGameController_o1
                    section.data(1).logicalSrcIdx = 63;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.LogicalOperator
                    section.data(2).logicalSrcIdx = 64;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.LogicalOperator_m
                    section.data(3).logicalSrcIdx = 66;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.HiddenBuf_InsertedFor_EnabledSu
                    section.data(4).logicalSrcIdx = 67;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.LogicalOperator_k
                    section.data(5).logicalSrcIdx = 68;
                    section.data(5).dtTransOffset = 4;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.Delay
                    section.data(6).logicalSrcIdx = 69;
                    section.data(6).dtTransOffset = 5;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.Compare
                    section.data(7).logicalSrcIdx = 70;
                    section.data(7).dtTransOffset = 6;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.OR
                    section.data(8).logicalSrcIdx = 71;
                    section.data(8).dtTransOffset = 7;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.Compare_d
                    section.data(9).logicalSrcIdx = 72;
                    section.data(9).dtTransOffset = 8;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.Memory
                    section.data(10).logicalSrcIdx = 73;
                    section.data(10).dtTransOffset = 10;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.VRPNClient_o9
                    section.data(11).logicalSrcIdx = 74;
                    section.data(11).dtTransOffset = 12;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.Compare_f
                    section.data(12).logicalSrcIdx = 75;
                    section.data(12).dtTransOffset = 13;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.Compare_g
                    section.data(13).logicalSrcIdx = 76;
                    section.data(13).dtTransOffset = 14;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.Buttons
                    section.data(14).logicalSrcIdx = 77;
                    section.data(14).dtTransOffset = 15;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.LogicalOperator_n
                    section.data(15).logicalSrcIdx = 78;
                    section.data(15).dtTransOffset = 47;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.RelationalOperator
                    section.data(16).logicalSrcIdx = 79;
                    section.data(16).dtTransOffset = 48;

                    ;% QD2_MissionCtrl_ManualPC_2021_B.Compare_n
                    section.data(17).logicalSrcIdx = 80;
                    section.data(17).dtTransOffset = 49;

            nTotData = nTotData + section.nData;
            sigMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_ManualPC_2021_B.CoreSubsys_p[1].one_shot_block
                    section.data(1).logicalSrcIdx = 81;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(5) = section;
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
        sectIdxOffset = 5;

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
        ;% Auto data (QD2_MissionCtrl_ManualPC_202_DW)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_ManualPC_202_DW.VRPNClient_TrackerData
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_ManualPC_202_DW.HostGameController_ControllerSt
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_ManualPC_202_DW.HostGameController_Lock
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_ManualPC_202_DW.Time_Timeout
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_ManualPC_202_DW.Time_Timeout_m
                    section.data(2).logicalSrcIdx = 4;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_ManualPC_202_DW.Time_Timeout_f
                    section.data(3).logicalSrcIdx = 5;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 14;
            section.data(14)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_ManualPC_202_DW.DiscreteTimeIntegrator_DSTATE
                    section.data(1).logicalSrcIdx = 6;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_ManualPC_202_DW.one_shot_block_DSTATE
                    section.data(2).logicalSrcIdx = 7;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_ManualPC_202_DW.DiscreteTimeIntegrator_DSTATE_j
                    section.data(3).logicalSrcIdx = 8;
                    section.data(3).dtTransOffset = 4;

                    ;% QD2_MissionCtrl_ManualPC_202_DW.UnitDelay_DSTATE
                    section.data(4).logicalSrcIdx = 9;
                    section.data(4).dtTransOffset = 5;

                    ;% QD2_MissionCtrl_ManualPC_202_DW.DiscreteTimeIntegrator_DSTATE_h
                    section.data(5).logicalSrcIdx = 10;
                    section.data(5).dtTransOffset = 6;

                    ;% QD2_MissionCtrl_ManualPC_202_DW.RateTransition2_Buffer0
                    section.data(6).logicalSrcIdx = 11;
                    section.data(6).dtTransOffset = 7;

                    ;% QD2_MissionCtrl_ManualPC_202_DW.Unwrapoptitrackmeasurement_Prev
                    section.data(7).logicalSrcIdx = 12;
                    section.data(7).dtTransOffset = 14;

                    ;% QD2_MissionCtrl_ManualPC_202_DW.Unwrapoptitrackmeasurement_Revo
                    section.data(8).logicalSrcIdx = 13;
                    section.data(8).dtTransOffset = 15;

                    ;% QD2_MissionCtrl_ManualPC_202_DW.Memory1_PreviousInput
                    section.data(9).logicalSrcIdx = 14;
                    section.data(9).dtTransOffset = 16;

                    ;% QD2_MissionCtrl_ManualPC_202_DW.RateTransition6_Buffer0
                    section.data(10).logicalSrcIdx = 15;
                    section.data(10).dtTransOffset = 17;

                    ;% QD2_MissionCtrl_ManualPC_202_DW.RateTransition7_Buffer0
                    section.data(11).logicalSrcIdx = 16;
                    section.data(11).dtTransOffset = 26;

                    ;% QD2_MissionCtrl_ManualPC_202_DW.RateTransition8_Buffer0
                    section.data(12).logicalSrcIdx = 17;
                    section.data(12).dtTransOffset = 35;

                    ;% QD2_MissionCtrl_ManualPC_202_DW.Memory_PreviousInput
                    section.data(13).logicalSrcIdx = 18;
                    section.data(13).dtTransOffset = 44;

                    ;% QD2_MissionCtrl_ManualPC_202_DW.State
                    section.data(14).logicalSrcIdx = 19;
                    section.data(14).dtTransOffset = 45;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_ManualPC_202_DW.StreamServer_Stream
                    section.data(1).logicalSrcIdx = 20;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_ManualPC_202_DW.HostInitialize_ConnectedHandle
                    section.data(1).logicalSrcIdx = 21;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_ManualPC_202_DW.VRPNClient_VRPNClient
                    section.data(1).logicalSrcIdx = 22;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(8) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_ManualPC_202_DW.ToHostFile_PointsWritten
                    section.data(1).logicalSrcIdx = 23;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(9) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_ManualPC_202_DW.ManualWaypointCommands_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 24;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_ManualPC_202_DW.Scope_PWORK.LoggedData
                    section.data(2).logicalSrcIdx = 25;
                    section.data(2).dtTransOffset = 4;

                    ;% QD2_MissionCtrl_ManualPC_202_DW.ToHostFile_PWORK
                    section.data(3).logicalSrcIdx = 26;
                    section.data(3).dtTransOffset = 5;

                    ;% QD2_MissionCtrl_ManualPC_202_DW.NewData_PWORK.LoggedData
                    section.data(4).logicalSrcIdx = 27;
                    section.data(4).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            dworkMap.sections(10) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_ManualPC_202_DW.sfEvent
                    section.data(1).logicalSrcIdx = 28;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_ManualPC_202_DW.sfEvent_n
                    section.data(2).logicalSrcIdx = 29;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(11) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_ManualPC_202_DW.ToHostFile_SamplesCount
                    section.data(1).logicalSrcIdx = 30;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_ManualPC_202_DW.ToHostFile_ArrayNameLength
                    section.data(2).logicalSrcIdx = 31;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(12) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_ManualPC_202_DW.StringDisplay_IWORK
                    section.data(1).logicalSrcIdx = 32;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(13) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_ManualPC_202_DW.Delay_DSTATE
                    section.data(1).logicalSrcIdx = 33;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_ManualPC_202_DW.Delay1_DSTATE
                    section.data(2).logicalSrcIdx = 34;
                    section.data(2).dtTransOffset = 6000;

            nTotData = nTotData + section.nData;
            dworkMap.sections(14) = section;
            clear section

            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_ManualPC_202_DW.DiscreteTimeIntegrator_PrevRese
                    section.data(1).logicalSrcIdx = 35;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_ManualPC_202_DW.DiscreteTimeIntegrator_PrevRe_b
                    section.data(2).logicalSrcIdx = 36;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_ManualPC_202_DW.TriggeredSubsystem_SubsysRanBC
                    section.data(3).logicalSrcIdx = 37;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_MissionCtrl_ManualPC_202_DW.pulsecount_SubsysRanBC
                    section.data(4).logicalSrcIdx = 38;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_MissionCtrl_ManualPC_202_DW.InitializationandConditioning_S
                    section.data(5).logicalSrcIdx = 39;
                    section.data(5).dtTransOffset = 4;

                    ;% QD2_MissionCtrl_ManualPC_202_DW.FrSKYMapping_SubsysRanBC
                    section.data(6).logicalSrcIdx = 40;
                    section.data(6).dtTransOffset = 5;

                    ;% QD2_MissionCtrl_ManualPC_202_DW.DiscreteTimeIntegrator_PrevRe_i
                    section.data(7).logicalSrcIdx = 41;
                    section.data(7).dtTransOffset = 6;

                    ;% QD2_MissionCtrl_ManualPC_202_DW.EnabledSubsystem_SubsysRanBC
                    section.data(8).logicalSrcIdx = 42;
                    section.data(8).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            dworkMap.sections(15) = section;
            clear section

            section.nData     = 12;
            section.data(12)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_ManualPC_202_DW.HostGameController_NewData
                    section.data(1).logicalSrcIdx = 43;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_ManualPC_202_DW.Time_Owner
                    section.data(2).logicalSrcIdx = 44;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_ManualPC_202_DW.Unwrapoptitrackmeasurement_Firs
                    section.data(3).logicalSrcIdx = 45;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_MissionCtrl_ManualPC_202_DW.Time_Owner_a
                    section.data(4).logicalSrcIdx = 46;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_MissionCtrl_ManualPC_202_DW.StreamServer_Listening
                    section.data(5).logicalSrcIdx = 47;
                    section.data(5).dtTransOffset = 4;

                    ;% QD2_MissionCtrl_ManualPC_202_DW.Time_Owner_p
                    section.data(6).logicalSrcIdx = 48;
                    section.data(6).dtTransOffset = 5;

                    ;% QD2_MissionCtrl_ManualPC_202_DW.Memory_PreviousInput_h
                    section.data(7).logicalSrcIdx = 49;
                    section.data(7).dtTransOffset = 6;

                    ;% QD2_MissionCtrl_ManualPC_202_DW.doneDoubleBufferReInit
                    section.data(8).logicalSrcIdx = 50;
                    section.data(8).dtTransOffset = 8;

                    ;% QD2_MissionCtrl_ManualPC_202_DW.State_not_empty
                    section.data(9).logicalSrcIdx = 51;
                    section.data(9).dtTransOffset = 9;

                    ;% QD2_MissionCtrl_ManualPC_202_DW.doneDoubleBufferReInit_k
                    section.data(10).logicalSrcIdx = 52;
                    section.data(10).dtTransOffset = 10;

                    ;% QD2_MissionCtrl_ManualPC_202_DW.FrSKYMapping_MODE
                    section.data(11).logicalSrcIdx = 53;
                    section.data(11).dtTransOffset = 11;

                    ;% QD2_MissionCtrl_ManualPC_202_DW.EnabledSubsystem_MODE
                    section.data(12).logicalSrcIdx = 54;
                    section.data(12).dtTransOffset = 12;

            nTotData = nTotData + section.nData;
            dworkMap.sections(16) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_ManualPC_202_DW.CoreSubsys_p[1].one_shot_block_DSTATE
                    section.data(1).logicalSrcIdx = 55;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(17) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% QD2_MissionCtrl_ManualPC_202_DW.CoreSubsys[0].q00_SubsysRanBC
                    section.data(1).logicalSrcIdx = 56;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_MissionCtrl_ManualPC_202_DW.CoreSubsys[0].q10_SubsysRanBC
                    section.data(2).logicalSrcIdx = 57;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_MissionCtrl_ManualPC_202_DW.CoreSubsys[0].q10_SubsysRanBC_h
                    section.data(3).logicalSrcIdx = 58;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_MissionCtrl_ManualPC_202_DW.CoreSubsys[0].q00_SubsysRanBC_f
                    section.data(4).logicalSrcIdx = 59;
                    section.data(4).dtTransOffset = 3;

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


    targMap.checksum0 = 4134201443;
    targMap.checksum1 = 566813720;
    targMap.checksum2 = 2096342655;
    targMap.checksum3 = 764929163;

