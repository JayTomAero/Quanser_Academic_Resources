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
        ;% Auto data (QD2_DroneStack_Manual_2021a_P)
        ;%
            section.nData     = 19;
            section.data(19)  = dumData; %prealloc

                    ;% QD2_DroneStack_Manual_2021a_P.KT
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_Manual_2021a_P.Motor_Matrix
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 3;

                    ;% QD2_DroneStack_Manual_2021a_P.CompareToConstant_const
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 19;

                    ;% QD2_DroneStack_Manual_2021a_P.Greaterthanminimumexpectedvolta
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 20;

                    ;% QD2_DroneStack_Manual_2021a_P.Lessthanminimumthresholdvoltage
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 21;

                    ;% QD2_DroneStack_Manual_2021a_P.StreamClient_default_value
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 22;

                    ;% QD2_DroneStack_Manual_2021a_P.StreamServer_default_value
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 33;

                    ;% QD2_DroneStack_Manual_2021a_P.Threshold_duration
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 34;

                    ;% QD2_DroneStack_Manual_2021a_P.Threshold_duration_d
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 35;

                    ;% QD2_DroneStack_Manual_2021a_P.Threshold1_duration
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 36;

                    ;% QD2_DroneStack_Manual_2021a_P.Stopmodel_duration
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 37;

                    ;% QD2_DroneStack_Manual_2021a_P.Communication_duration
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 38;

                    ;% QD2_DroneStack_Manual_2021a_P.DiscreteSecondOrderLowPassFilte
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 39;

                    ;% QD2_DroneStack_Manual_2021a_P.DiscreteSecondOrderLowPassFil_p
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 40;

                    ;% QD2_DroneStack_Manual_2021a_P.Threshold_threshold
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 41;

                    ;% QD2_DroneStack_Manual_2021a_P.Threshold_threshold_h
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 42;

                    ;% QD2_DroneStack_Manual_2021a_P.Threshold1_threshold
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 43;

                    ;% QD2_DroneStack_Manual_2021a_P.Stopmodel_threshold
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 44;

                    ;% QD2_DroneStack_Manual_2021a_P.Communication_threshold
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 45;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_DroneStack_Manual_2021a_P.CompareToConstant1_const
                    section.data(1).logicalSrcIdx = 19;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% QD2_DroneStack_Manual_2021a_P.HILRead_analog_channels
                    section.data(1).logicalSrcIdx = 20;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_Manual_2021a_P.HILWritePWM_channels
                    section.data(2).logicalSrcIdx = 21;
                    section.data(2).dtTransOffset = 3;

                    ;% QD2_DroneStack_Manual_2021a_P.HILWriteDigital_channels
                    section.data(3).logicalSrcIdx = 22;
                    section.data(3).dtTransOffset = 7;

                    ;% QD2_DroneStack_Manual_2021a_P.HILRead_other_channels
                    section.data(4).logicalSrcIdx = 23;
                    section.data(4).dtTransOffset = 13;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% QD2_DroneStack_Manual_2021a_P.StopwithMessage_message_icon
                    section.data(1).logicalSrcIdx = 24;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_Manual_2021a_P.StopwithMessage1_message_icon
                    section.data(2).logicalSrcIdx = 25;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_DroneStack_Manual_2021a_P.StopwithMessage3_message_icon
                    section.data(3).logicalSrcIdx = 26;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% QD2_DroneStack_Manual_2021a_P.StringDisplay_alignment
                    section.data(1).logicalSrcIdx = 27;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_Manual_2021a_P.CompareToConstant_const_e
                    section.data(2).logicalSrcIdx = 28;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_DroneStack_Manual_2021a_P.StringDisplay_display_mode
                    section.data(3).logicalSrcIdx = 29;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section

            section.nData     = 117;
            section.data(117)  = dumData; %prealloc

                    ;% QD2_DroneStack_Manual_2021a_P.RedRed_Value
                    section.data(1).logicalSrcIdx = 30;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_Manual_2021a_P.LEDOFF_Value
                    section.data(2).logicalSrcIdx = 31;
                    section.data(2).dtTransOffset = 6;

                    ;% QD2_DroneStack_Manual_2021a_P.YellowYellow_Value
                    section.data(3).logicalSrcIdx = 32;
                    section.data(3).dtTransOffset = 12;

                    ;% QD2_DroneStack_Manual_2021a_P.YellowGreen_Value
                    section.data(4).logicalSrcIdx = 33;
                    section.data(4).dtTransOffset = 18;

                    ;% QD2_DroneStack_Manual_2021a_P.BlueBlue_Value
                    section.data(5).logicalSrcIdx = 34;
                    section.data(5).dtTransOffset = 24;

                    ;% QD2_DroneStack_Manual_2021a_P.YellowRed_Value
                    section.data(6).logicalSrcIdx = 35;
                    section.data(6).dtTransOffset = 30;

                    ;% QD2_DroneStack_Manual_2021a_P.RedYellow_Value
                    section.data(7).logicalSrcIdx = 36;
                    section.data(7).dtTransOffset = 36;

                    ;% QD2_DroneStack_Manual_2021a_P.GreenGreen_Value
                    section.data(8).logicalSrcIdx = 37;
                    section.data(8).dtTransOffset = 42;

                    ;% QD2_DroneStack_Manual_2021a_P.YellowBlue_Value
                    section.data(9).logicalSrcIdx = 38;
                    section.data(9).dtTransOffset = 48;

                    ;% QD2_DroneStack_Manual_2021a_P.RedBlue_Value
                    section.data(10).logicalSrcIdx = 39;
                    section.data(10).dtTransOffset = 54;

                    ;% QD2_DroneStack_Manual_2021a_P.Out1_Y0
                    section.data(11).logicalSrcIdx = 40;
                    section.data(11).dtTransOffset = 60;

                    ;% QD2_DroneStack_Manual_2021a_P.Constant_Value
                    section.data(12).logicalSrcIdx = 41;
                    section.data(12).dtTransOffset = 61;

                    ;% QD2_DroneStack_Manual_2021a_P.Motor0_Value
                    section.data(13).logicalSrcIdx = 42;
                    section.data(13).dtTransOffset = 62;

                    ;% QD2_DroneStack_Manual_2021a_P.Motor1_Value
                    section.data(14).logicalSrcIdx = 43;
                    section.data(14).dtTransOffset = 66;

                    ;% QD2_DroneStack_Manual_2021a_P.Motor2_Value
                    section.data(15).logicalSrcIdx = 44;
                    section.data(15).dtTransOffset = 70;

                    ;% QD2_DroneStack_Manual_2021a_P.Motor3_Value
                    section.data(16).logicalSrcIdx = 45;
                    section.data(16).dtTransOffset = 74;

                    ;% QD2_DroneStack_Manual_2021a_P.Noselection_Value
                    section.data(17).logicalSrcIdx = 46;
                    section.data(17).dtTransOffset = 78;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_OOTerminate
                    section.data(18).logicalSrcIdx = 47;
                    section.data(18).dtTransOffset = 82;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_OOExit
                    section.data(19).logicalSrcIdx = 48;
                    section.data(19).dtTransOffset = 83;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_OOStart
                    section.data(20).logicalSrcIdx = 49;
                    section.data(20).dtTransOffset = 84;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_OOEnter
                    section.data(21).logicalSrcIdx = 50;
                    section.data(21).dtTransOffset = 85;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_POFinal
                    section.data(22).logicalSrcIdx = 51;
                    section.data(22).dtTransOffset = 86;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_AIHigh
                    section.data(23).logicalSrcIdx = 52;
                    section.data(23).dtTransOffset = 87;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_AILow
                    section.data(24).logicalSrcIdx = 53;
                    section.data(24).dtTransOffset = 88;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_EIFrequency
                    section.data(25).logicalSrcIdx = 54;
                    section.data(25).dtTransOffset = 89;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_POFrequency
                    section.data(26).logicalSrcIdx = 55;
                    section.data(26).dtTransOffset = 90;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_POInitial
                    section.data(27).logicalSrcIdx = 56;
                    section.data(27).dtTransOffset = 91;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_POWatchdog
                    section.data(28).logicalSrcIdx = 57;
                    section.data(28).dtTransOffset = 92;

                    ;% QD2_DroneStack_Manual_2021a_P.Delay_InitialCondition
                    section.data(29).logicalSrcIdx = 58;
                    section.data(29).dtTransOffset = 93;

                    ;% QD2_DroneStack_Manual_2021a_P.Constant_Value_e
                    section.data(30).logicalSrcIdx = 59;
                    section.data(30).dtTransOffset = 94;

                    ;% QD2_DroneStack_Manual_2021a_P.Memory_InitialCondition
                    section.data(31).logicalSrcIdx = 60;
                    section.data(31).dtTransOffset = 95;

                    ;% QD2_DroneStack_Manual_2021a_P.ZeroTorqueCommand_Value
                    section.data(32).logicalSrcIdx = 61;
                    section.data(32).dtTransOffset = 96;

                    ;% QD2_DroneStack_Manual_2021a_P.Switch_Threshold
                    section.data(33).logicalSrcIdx = 62;
                    section.data(33).dtTransOffset = 99;

                    ;% QD2_DroneStack_Manual_2021a_P.Switch1_Threshold
                    section.data(34).logicalSrcIdx = 63;
                    section.data(34).dtTransOffset = 100;

                    ;% QD2_DroneStack_Manual_2021a_P.SaturateStabilizationCommand_Up
                    section.data(35).logicalSrcIdx = 64;
                    section.data(35).dtTransOffset = 101;

                    ;% QD2_DroneStack_Manual_2021a_P.SaturateStabilizationCommand_Lo
                    section.data(36).logicalSrcIdx = 65;
                    section.data(36).dtTransOffset = 104;

                    ;% QD2_DroneStack_Manual_2021a_P.Constant1_Value
                    section.data(37).logicalSrcIdx = 66;
                    section.data(37).dtTransOffset = 107;

                    ;% QD2_DroneStack_Manual_2021a_P.Gain1_Gain
                    section.data(38).logicalSrcIdx = 67;
                    section.data(38).dtTransOffset = 108;

                    ;% QD2_DroneStack_Manual_2021a_P.K_p_angleradsrad_Gain
                    section.data(39).logicalSrcIdx = 68;
                    section.data(39).dtTransOffset = 111;

                    ;% QD2_DroneStack_Manual_2021a_P.Scale_Gain
                    section.data(40).logicalSrcIdx = 69;
                    section.data(40).dtTransOffset = 114;

                    ;% QD2_DroneStack_Manual_2021a_P.K_d_angleradsrads_Gain
                    section.data(41).logicalSrcIdx = 70;
                    section.data(41).dtTransOffset = 117;

                    ;% QD2_DroneStack_Manual_2021a_P.Scale1_Gain
                    section.data(42).logicalSrcIdx = 71;
                    section.data(42).dtTransOffset = 120;

                    ;% QD2_DroneStack_Manual_2021a_P.SaturationMaxRaterads_UpperSat
                    section.data(43).logicalSrcIdx = 72;
                    section.data(43).dtTransOffset = 123;

                    ;% QD2_DroneStack_Manual_2021a_P.SaturationMaxRaterads_LowerSat
                    section.data(44).logicalSrcIdx = 73;
                    section.data(44).dtTransOffset = 126;

                    ;% QD2_DroneStack_Manual_2021a_P.K_p_speedNmrads_Gain
                    section.data(45).logicalSrcIdx = 74;
                    section.data(45).dtTransOffset = 129;

                    ;% QD2_DroneStack_Manual_2021a_P.Scale5_Gain
                    section.data(46).logicalSrcIdx = 75;
                    section.data(46).dtTransOffset = 132;

                    ;% QD2_DroneStack_Manual_2021a_P.K_d_speedNmradss1_Gain
                    section.data(47).logicalSrcIdx = 76;
                    section.data(47).dtTransOffset = 135;

                    ;% QD2_DroneStack_Manual_2021a_P.Scale4_Gain
                    section.data(48).logicalSrcIdx = 77;
                    section.data(48).dtTransOffset = 138;

                    ;% QD2_DroneStack_Manual_2021a_P.SaturationCommandAuthorityNm1_U
                    section.data(49).logicalSrcIdx = 78;
                    section.data(49).dtTransOffset = 141;

                    ;% QD2_DroneStack_Manual_2021a_P.SaturationCommandAuthorityNm1_L
                    section.data(50).logicalSrcIdx = 79;
                    section.data(50).dtTransOffset = 144;

                    ;% QD2_DroneStack_Manual_2021a_P.Delay_InitialCondition_i
                    section.data(51).logicalSrcIdx = 80;
                    section.data(51).dtTransOffset = 147;

                    ;% QD2_DroneStack_Manual_2021a_P.ZeroReferenceMotorCommands_Valu
                    section.data(52).logicalSrcIdx = 81;
                    section.data(52).dtTransOffset = 148;

                    ;% QD2_DroneStack_Manual_2021a_P.MaximumCommandAuthority_UpperSa
                    section.data(53).logicalSrcIdx = 82;
                    section.data(53).dtTransOffset = 152;

                    ;% QD2_DroneStack_Manual_2021a_P.MaximumCommandAuthority_LowerSa
                    section.data(54).logicalSrcIdx = 83;
                    section.data(54).dtTransOffset = 156;

                    ;% QD2_DroneStack_Manual_2021a_P.Constant1_Value_f
                    section.data(55).logicalSrcIdx = 84;
                    section.data(55).dtTransOffset = 160;

                    ;% QD2_DroneStack_Manual_2021a_P.Constant2_Value
                    section.data(56).logicalSrcIdx = 85;
                    section.data(56).dtTransOffset = 192;

                    ;% QD2_DroneStack_Manual_2021a_P.RateTransition7_InitialConditio
                    section.data(57).logicalSrcIdx = 86;
                    section.data(57).dtTransOffset = 193;

                    ;% QD2_DroneStack_Manual_2021a_P.RateTransition2_InitialConditio
                    section.data(58).logicalSrcIdx = 87;
                    section.data(58).dtTransOffset = 194;

                    ;% QD2_DroneStack_Manual_2021a_P.RateTransition1_InitialConditio
                    section.data(59).logicalSrcIdx = 88;
                    section.data(59).dtTransOffset = 195;

                    ;% QD2_DroneStack_Manual_2021a_P.Dividebyhalfofthenumberofpolesi
                    section.data(60).logicalSrcIdx = 89;
                    section.data(60).dtTransOffset = 196;

                    ;% QD2_DroneStack_Manual_2021a_P.Multiplebyresolutionsupposedtob
                    section.data(61).logicalSrcIdx = 90;
                    section.data(61).dtTransOffset = 197;

                    ;% QD2_DroneStack_Manual_2021a_P.Memory_InitialCondition_k
                    section.data(62).logicalSrcIdx = 91;
                    section.data(62).dtTransOffset = 198;

                    ;% QD2_DroneStack_Manual_2021a_P.Converttoequivalentvoltagebased
                    section.data(63).logicalSrcIdx = 92;
                    section.data(63).dtTransOffset = 202;

                    ;% QD2_DroneStack_Manual_2021a_P.Saturation_UpperSat
                    section.data(64).logicalSrcIdx = 93;
                    section.data(64).dtTransOffset = 203;

                    ;% QD2_DroneStack_Manual_2021a_P.Saturation_LowerSat
                    section.data(65).logicalSrcIdx = 94;
                    section.data(65).dtTransOffset = 204;

                    ;% QD2_DroneStack_Manual_2021a_P.Memory_InitialCondition_b
                    section.data(66).logicalSrcIdx = 95;
                    section.data(66).dtTransOffset = 205;

                    ;% QD2_DroneStack_Manual_2021a_P.Saturation1_UpperSat
                    section.data(67).logicalSrcIdx = 96;
                    section.data(67).dtTransOffset = 209;

                    ;% QD2_DroneStack_Manual_2021a_P.Saturation1_LowerSat
                    section.data(68).logicalSrcIdx = 97;
                    section.data(68).dtTransOffset = 210;

                    ;% QD2_DroneStack_Manual_2021a_P.RateTransition_InitialCondition
                    section.data(69).logicalSrcIdx = 98;
                    section.data(69).dtTransOffset = 211;

                    ;% QD2_DroneStack_Manual_2021a_P.RateTransition1_InitialCondit_m
                    section.data(70).logicalSrcIdx = 99;
                    section.data(70).dtTransOffset = 212;

                    ;% QD2_DroneStack_Manual_2021a_P.RateTransition2_InitialCondit_o
                    section.data(71).logicalSrcIdx = 100;
                    section.data(71).dtTransOffset = 213;

                    ;% QD2_DroneStack_Manual_2021a_P.RateTransition3_InitialConditio
                    section.data(72).logicalSrcIdx = 101;
                    section.data(72).dtTransOffset = 214;

                    ;% QD2_DroneStack_Manual_2021a_P.Gain_Gain
                    section.data(73).logicalSrcIdx = 102;
                    section.data(73).dtTransOffset = 215;

                    ;% QD2_DroneStack_Manual_2021a_P.Bias1_Bias
                    section.data(74).logicalSrcIdx = 103;
                    section.data(74).dtTransOffset = 216;

                    ;% QD2_DroneStack_Manual_2021a_P.Memory_InitialCondition_bp
                    section.data(75).logicalSrcIdx = 104;
                    section.data(75).dtTransOffset = 220;

                    ;% QD2_DroneStack_Manual_2021a_P.Delay3_InitialCondition
                    section.data(76).logicalSrcIdx = 105;
                    section.data(76).dtTransOffset = 224;

                    ;% QD2_DroneStack_Manual_2021a_P.Delay2_InitialCondition
                    section.data(77).logicalSrcIdx = 106;
                    section.data(77).dtTransOffset = 225;

                    ;% QD2_DroneStack_Manual_2021a_P.Delay1_InitialCondition
                    section.data(78).logicalSrcIdx = 107;
                    section.data(78).dtTransOffset = 226;

                    ;% QD2_DroneStack_Manual_2021a_P.Delay_InitialCondition_m
                    section.data(79).logicalSrcIdx = 108;
                    section.data(79).dtTransOffset = 227;

                    ;% QD2_DroneStack_Manual_2021a_P.Constant_Value_o
                    section.data(80).logicalSrcIdx = 109;
                    section.data(80).dtTransOffset = 228;

                    ;% QD2_DroneStack_Manual_2021a_P.ZeroYaw_Value
                    section.data(81).logicalSrcIdx = 110;
                    section.data(81).dtTransOffset = 229;

                    ;% QD2_DroneStack_Manual_2021a_P.BatteryLowTimeThresholds_Value
                    section.data(82).logicalSrcIdx = 111;
                    section.data(82).dtTransOffset = 230;

                    ;% QD2_DroneStack_Manual_2021a_P.Constant_Value_j
                    section.data(83).logicalSrcIdx = 112;
                    section.data(83).dtTransOffset = 231;

                    ;% QD2_DroneStack_Manual_2021a_P.DiscreteTimeIntegrator_gainval
                    section.data(84).logicalSrcIdx = 113;
                    section.data(84).dtTransOffset = 232;

                    ;% QD2_DroneStack_Manual_2021a_P.DiscreteTimeIntegrator_IC
                    section.data(85).logicalSrcIdx = 114;
                    section.data(85).dtTransOffset = 233;

                    ;% QD2_DroneStack_Manual_2021a_P.Constant1_Value_o
                    section.data(86).logicalSrcIdx = 115;
                    section.data(86).dtTransOffset = 234;

                    ;% QD2_DroneStack_Manual_2021a_P.DiscreteTimeIntegrator_gainva_b
                    section.data(87).logicalSrcIdx = 116;
                    section.data(87).dtTransOffset = 235;

                    ;% QD2_DroneStack_Manual_2021a_P.DiscreteTimeIntegrator_IC_j
                    section.data(88).logicalSrcIdx = 117;
                    section.data(88).dtTransOffset = 236;

                    ;% QD2_DroneStack_Manual_2021a_P.DiscreteTimeIntegrator_gainva_o
                    section.data(89).logicalSrcIdx = 118;
                    section.data(89).dtTransOffset = 237;

                    ;% QD2_DroneStack_Manual_2021a_P.DiscreteTimeIntegrator_IC_c
                    section.data(90).logicalSrcIdx = 119;
                    section.data(90).dtTransOffset = 238;

                    ;% QD2_DroneStack_Manual_2021a_P.DiscreteTimeIntegrator_gainva_j
                    section.data(91).logicalSrcIdx = 120;
                    section.data(91).dtTransOffset = 239;

                    ;% QD2_DroneStack_Manual_2021a_P.DiscreteTimeIntegrator_IC_m
                    section.data(92).logicalSrcIdx = 121;
                    section.data(92).dtTransOffset = 240;

                    ;% QD2_DroneStack_Manual_2021a_P.Gain_Gain_b
                    section.data(93).logicalSrcIdx = 122;
                    section.data(93).dtTransOffset = 241;

                    ;% QD2_DroneStack_Manual_2021a_P.Gain_Gain_k
                    section.data(94).logicalSrcIdx = 123;
                    section.data(94).dtTransOffset = 242;

                    ;% QD2_DroneStack_Manual_2021a_P.DiscreteTimeIntegrator_gainv_bm
                    section.data(95).logicalSrcIdx = 124;
                    section.data(95).dtTransOffset = 243;

                    ;% QD2_DroneStack_Manual_2021a_P.DiscreteTimeIntegrator_IC_a
                    section.data(96).logicalSrcIdx = 125;
                    section.data(96).dtTransOffset = 244;

                    ;% QD2_DroneStack_Manual_2021a_P.DiscreteTimeIntegrator_gainv_b1
                    section.data(97).logicalSrcIdx = 126;
                    section.data(97).dtTransOffset = 245;

                    ;% QD2_DroneStack_Manual_2021a_P.DiscreteTimeIntegrator_IC_my
                    section.data(98).logicalSrcIdx = 127;
                    section.data(98).dtTransOffset = 246;

                    ;% QD2_DroneStack_Manual_2021a_P.HILWatchdog_Timeout
                    section.data(99).logicalSrcIdx = 128;
                    section.data(99).dtTransOffset = 247;

                    ;% QD2_DroneStack_Manual_2021a_P.Memory2_InitialCondition
                    section.data(100).logicalSrcIdx = 129;
                    section.data(100).dtTransOffset = 248;

                    ;% QD2_DroneStack_Manual_2021a_P.Constant_Value_l
                    section.data(101).logicalSrcIdx = 130;
                    section.data(101).dtTransOffset = 249;

                    ;% QD2_DroneStack_Manual_2021a_P.DiscreteTimeIntegrator_gainva_f
                    section.data(102).logicalSrcIdx = 131;
                    section.data(102).dtTransOffset = 250;

                    ;% QD2_DroneStack_Manual_2021a_P.DiscreteTimeIntegrator_IC_n
                    section.data(103).logicalSrcIdx = 132;
                    section.data(103).dtTransOffset = 251;

                    ;% QD2_DroneStack_Manual_2021a_P.x0_Value
                    section.data(104).logicalSrcIdx = 133;
                    section.data(104).dtTransOffset = 252;

                    ;% QD2_DroneStack_Manual_2021a_P.DiscreteTimeIntegrator1_gainval
                    section.data(105).logicalSrcIdx = 134;
                    section.data(105).dtTransOffset = 253;

                    ;% QD2_DroneStack_Manual_2021a_P.Constant_Value_n
                    section.data(106).logicalSrcIdx = 135;
                    section.data(106).dtTransOffset = 254;

                    ;% QD2_DroneStack_Manual_2021a_P.DiscreteTimeIntegrator_gainv_o5
                    section.data(107).logicalSrcIdx = 136;
                    section.data(107).dtTransOffset = 255;

                    ;% QD2_DroneStack_Manual_2021a_P.DiscreteTimeIntegrator_IC_ac
                    section.data(108).logicalSrcIdx = 137;
                    section.data(108).dtTransOffset = 256;

                    ;% QD2_DroneStack_Manual_2021a_P.ToFFilterInitialConditionm_Valu
                    section.data(109).logicalSrcIdx = 138;
                    section.data(109).dtTransOffset = 257;

                    ;% QD2_DroneStack_Manual_2021a_P.DiscreteTimeIntegrator1_gainv_i
                    section.data(110).logicalSrcIdx = 139;
                    section.data(110).dtTransOffset = 258;

                    ;% QD2_DroneStack_Manual_2021a_P.ToFFilterCutoffFrequencyrad_Val
                    section.data(111).logicalSrcIdx = 140;
                    section.data(111).dtTransOffset = 259;

                    ;% QD2_DroneStack_Manual_2021a_P.RangingSensor_Budget
                    section.data(112).logicalSrcIdx = 141;
                    section.data(112).dtTransOffset = 260;

                    ;% QD2_DroneStack_Manual_2021a_P.RangingSensor_Period
                    section.data(113).logicalSrcIdx = 142;
                    section.data(113).dtTransOffset = 261;

                    ;% QD2_DroneStack_Manual_2021a_P.RangingSensor_MaxInterpolationD
                    section.data(114).logicalSrcIdx = 143;
                    section.data(114).dtTransOffset = 262;

                    ;% QD2_DroneStack_Manual_2021a_P.RangingSensor_MaxInterpolationA
                    section.data(115).logicalSrcIdx = 144;
                    section.data(115).dtTransOffset = 263;

                    ;% QD2_DroneStack_Manual_2021a_P.ToFFilterDampingRatio_Value
                    section.data(116).logicalSrcIdx = 145;
                    section.data(116).dtTransOffset = 264;

                    ;% QD2_DroneStack_Manual_2021a_P.ToFSensorXYOffsetsm_Value
                    section.data(117).logicalSrcIdx = 146;
                    section.data(117).dtTransOffset = 265;

            nTotData = nTotData + section.nData;
            paramMap.sections(6) = section;
            clear section

            section.nData     = 12;
            section.data(12)  = dumData; %prealloc

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_DOWatchdog
                    section.data(1).logicalSrcIdx = 147;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_EIInitial
                    section.data(2).logicalSrcIdx = 148;
                    section.data(2).dtTransOffset = 6;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_POModes
                    section.data(3).logicalSrcIdx = 149;
                    section.data(3).dtTransOffset = 7;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_POConfiguration
                    section.data(4).logicalSrcIdx = 150;
                    section.data(4).dtTransOffset = 12;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_POAlignment
                    section.data(5).logicalSrcIdx = 151;
                    section.data(5).dtTransOffset = 13;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_POPolarity
                    section.data(6).logicalSrcIdx = 152;
                    section.data(6).dtTransOffset = 14;

                    ;% QD2_DroneStack_Manual_2021a_P.StreamClient_SndPriority
                    section.data(7).logicalSrcIdx = 153;
                    section.data(7).dtTransOffset = 15;

                    ;% QD2_DroneStack_Manual_2021a_P.StreamClient_RcvPriority
                    section.data(8).logicalSrcIdx = 154;
                    section.data(8).dtTransOffset = 16;

                    ;% QD2_DroneStack_Manual_2021a_P.ToHostFile_Encoding
                    section.data(9).logicalSrcIdx = 155;
                    section.data(9).dtTransOffset = 17;

                    ;% QD2_DroneStack_Manual_2021a_P.ToHostFile_Encoding_b
                    section.data(10).logicalSrcIdx = 156;
                    section.data(10).dtTransOffset = 18;

                    ;% QD2_DroneStack_Manual_2021a_P.StreamServer_SndPriority
                    section.data(11).logicalSrcIdx = 157;
                    section.data(11).dtTransOffset = 19;

                    ;% QD2_DroneStack_Manual_2021a_P.StreamServer_RcvPriority
                    section.data(12).logicalSrcIdx = 158;
                    section.data(12).dtTransOffset = 20;

            nTotData = nTotData + section.nData;
            paramMap.sections(7) = section;
            clear section

            section.nData     = 19;
            section.data(19)  = dumData; %prealloc

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_AIChannels
                    section.data(1).logicalSrcIdx = 159;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_DIChannels
                    section.data(2).logicalSrcIdx = 160;
                    section.data(2).dtTransOffset = 4;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_DOChannels
                    section.data(3).logicalSrcIdx = 161;
                    section.data(3).dtTransOffset = 10;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_EIChannels
                    section.data(4).logicalSrcIdx = 162;
                    section.data(4).dtTransOffset = 16;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_EIQuadrature
                    section.data(5).logicalSrcIdx = 163;
                    section.data(5).dtTransOffset = 18;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_POChannels
                    section.data(6).logicalSrcIdx = 164;
                    section.data(6).dtTransOffset = 19;

                    ;% QD2_DroneStack_Manual_2021a_P.StreamClient_SndSize
                    section.data(7).logicalSrcIdx = 165;
                    section.data(7).dtTransOffset = 25;

                    ;% QD2_DroneStack_Manual_2021a_P.StreamClient_RcvSize
                    section.data(8).logicalSrcIdx = 166;
                    section.data(8).dtTransOffset = 26;

                    ;% QD2_DroneStack_Manual_2021a_P.StreamClient_SndFIFO
                    section.data(9).logicalSrcIdx = 167;
                    section.data(9).dtTransOffset = 27;

                    ;% QD2_DroneStack_Manual_2021a_P.StreamClient_RcvFIFO
                    section.data(10).logicalSrcIdx = 168;
                    section.data(10).dtTransOffset = 28;

                    ;% QD2_DroneStack_Manual_2021a_P.ToHostFile_Decimation
                    section.data(11).logicalSrcIdx = 169;
                    section.data(11).dtTransOffset = 29;

                    ;% QD2_DroneStack_Manual_2021a_P.ToHostFile_BitRate
                    section.data(12).logicalSrcIdx = 170;
                    section.data(12).dtTransOffset = 30;

                    ;% QD2_DroneStack_Manual_2021a_P.ToHostFile_Decimation_m
                    section.data(13).logicalSrcIdx = 171;
                    section.data(13).dtTransOffset = 31;

                    ;% QD2_DroneStack_Manual_2021a_P.ToHostFile_BitRate_b
                    section.data(14).logicalSrcIdx = 172;
                    section.data(14).dtTransOffset = 32;

                    ;% QD2_DroneStack_Manual_2021a_P.StreamServer_SndSize
                    section.data(15).logicalSrcIdx = 173;
                    section.data(15).dtTransOffset = 33;

                    ;% QD2_DroneStack_Manual_2021a_P.StreamServer_RcvSize
                    section.data(16).logicalSrcIdx = 174;
                    section.data(16).dtTransOffset = 34;

                    ;% QD2_DroneStack_Manual_2021a_P.StreamServer_SndFIFO
                    section.data(17).logicalSrcIdx = 175;
                    section.data(17).dtTransOffset = 35;

                    ;% QD2_DroneStack_Manual_2021a_P.StreamServer_RcvFIFO
                    section.data(18).logicalSrcIdx = 176;
                    section.data(18).dtTransOffset = 36;

                    ;% QD2_DroneStack_Manual_2021a_P.RangingSensor_Range
                    section.data(19).logicalSrcIdx = 177;
                    section.data(19).dtTransOffset = 37;

            nTotData = nTotData + section.nData;
            paramMap.sections(8) = section;
            clear section

            section.nData     = 47;
            section.data(47)  = dumData; %prealloc

                    ;% QD2_DroneStack_Manual_2021a_P.HILWritePWM_Active
                    section.data(1).logicalSrcIdx = 178;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_Manual_2021a_P.Constant_Value_c
                    section.data(2).logicalSrcIdx = 179;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_DroneStack_Manual_2021a_P.Constant_Value_oc
                    section.data(3).logicalSrcIdx = 180;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_DroneStack_Manual_2021a_P.Constant_Value_a
                    section.data(4).logicalSrcIdx = 181;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_Active
                    section.data(5).logicalSrcIdx = 182;
                    section.data(5).dtTransOffset = 4;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_AOTerminate
                    section.data(6).logicalSrcIdx = 183;
                    section.data(6).dtTransOffset = 5;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_AOExit
                    section.data(7).logicalSrcIdx = 184;
                    section.data(7).dtTransOffset = 6;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_DOTerminate
                    section.data(8).logicalSrcIdx = 185;
                    section.data(8).dtTransOffset = 7;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_DOExit
                    section.data(9).logicalSrcIdx = 186;
                    section.data(9).dtTransOffset = 8;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_POTerminate
                    section.data(10).logicalSrcIdx = 187;
                    section.data(10).dtTransOffset = 9;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_POExit
                    section.data(11).logicalSrcIdx = 188;
                    section.data(11).dtTransOffset = 10;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_CKPStart
                    section.data(12).logicalSrcIdx = 189;
                    section.data(12).dtTransOffset = 11;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_CKPEnter
                    section.data(13).logicalSrcIdx = 190;
                    section.data(13).dtTransOffset = 12;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_CKStart
                    section.data(14).logicalSrcIdx = 191;
                    section.data(14).dtTransOffset = 13;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_CKEnter
                    section.data(15).logicalSrcIdx = 192;
                    section.data(15).dtTransOffset = 14;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_AIPStart
                    section.data(16).logicalSrcIdx = 193;
                    section.data(16).dtTransOffset = 15;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_AIPEnter
                    section.data(17).logicalSrcIdx = 194;
                    section.data(17).dtTransOffset = 16;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_AOPStart
                    section.data(18).logicalSrcIdx = 195;
                    section.data(18).dtTransOffset = 17;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_AOPEnter
                    section.data(19).logicalSrcIdx = 196;
                    section.data(19).dtTransOffset = 18;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_AOStart
                    section.data(20).logicalSrcIdx = 197;
                    section.data(20).dtTransOffset = 19;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_AOEnter
                    section.data(21).logicalSrcIdx = 198;
                    section.data(21).dtTransOffset = 20;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_AOReset
                    section.data(22).logicalSrcIdx = 199;
                    section.data(22).dtTransOffset = 21;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_DOPStart
                    section.data(23).logicalSrcIdx = 200;
                    section.data(23).dtTransOffset = 22;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_DOPEnter
                    section.data(24).logicalSrcIdx = 201;
                    section.data(24).dtTransOffset = 23;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_DOStart
                    section.data(25).logicalSrcIdx = 202;
                    section.data(25).dtTransOffset = 24;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_DOEnter
                    section.data(26).logicalSrcIdx = 203;
                    section.data(26).dtTransOffset = 25;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_DOReset
                    section.data(27).logicalSrcIdx = 204;
                    section.data(27).dtTransOffset = 26;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_EIPStart
                    section.data(28).logicalSrcIdx = 205;
                    section.data(28).dtTransOffset = 27;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_EIPEnter
                    section.data(29).logicalSrcIdx = 206;
                    section.data(29).dtTransOffset = 28;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_EIStart
                    section.data(30).logicalSrcIdx = 207;
                    section.data(30).dtTransOffset = 29;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_EIEnter
                    section.data(31).logicalSrcIdx = 208;
                    section.data(31).dtTransOffset = 30;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_POPStart
                    section.data(32).logicalSrcIdx = 209;
                    section.data(32).dtTransOffset = 31;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_POPEnter
                    section.data(33).logicalSrcIdx = 210;
                    section.data(33).dtTransOffset = 32;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_POStart
                    section.data(34).logicalSrcIdx = 211;
                    section.data(34).dtTransOffset = 33;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_POEnter
                    section.data(35).logicalSrcIdx = 212;
                    section.data(35).dtTransOffset = 34;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_POReset
                    section.data(36).logicalSrcIdx = 213;
                    section.data(36).dtTransOffset = 35;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_OOReset
                    section.data(37).logicalSrcIdx = 214;
                    section.data(37).dtTransOffset = 36;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_DOFinal
                    section.data(38).logicalSrcIdx = 215;
                    section.data(38).dtTransOffset = 37;

                    ;% QD2_DroneStack_Manual_2021a_P.HILInitialize_DOInitial
                    section.data(39).logicalSrcIdx = 216;
                    section.data(39).dtTransOffset = 38;

                    ;% QD2_DroneStack_Manual_2021a_P.HILRead_Active
                    section.data(40).logicalSrcIdx = 217;
                    section.data(40).dtTransOffset = 39;

                    ;% QD2_DroneStack_Manual_2021a_P.StreamClient_Active
                    section.data(41).logicalSrcIdx = 218;
                    section.data(41).dtTransOffset = 40;

                    ;% QD2_DroneStack_Manual_2021a_P.Memory1_InitialCondition
                    section.data(42).logicalSrcIdx = 219;
                    section.data(42).dtTransOffset = 41;

                    ;% QD2_DroneStack_Manual_2021a_P.HILWriteDigital_Active
                    section.data(43).logicalSrcIdx = 220;
                    section.data(43).dtTransOffset = 42;

                    ;% QD2_DroneStack_Manual_2021a_P.HILWatchdog_Active
                    section.data(44).logicalSrcIdx = 221;
                    section.data(44).dtTransOffset = 43;

                    ;% QD2_DroneStack_Manual_2021a_P.Memory3_InitialCondition
                    section.data(45).logicalSrcIdx = 222;
                    section.data(45).dtTransOffset = 44;

                    ;% QD2_DroneStack_Manual_2021a_P.StreamServer_Active
                    section.data(46).logicalSrcIdx = 223;
                    section.data(46).dtTransOffset = 45;

                    ;% QD2_DroneStack_Manual_2021a_P.RangingSensor_Active
                    section.data(47).logicalSrcIdx = 224;
                    section.data(47).dtTransOffset = 46;

            nTotData = nTotData + section.nData;
            paramMap.sections(9) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% QD2_DroneStack_Manual_2021a_P.StreamClient_Optimize
                    section.data(1).logicalSrcIdx = 225;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_Manual_2021a_P.StreamClient_Implementation
                    section.data(2).logicalSrcIdx = 226;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_DroneStack_Manual_2021a_P.StreamServer_Optimize
                    section.data(3).logicalSrcIdx = 227;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_DroneStack_Manual_2021a_P.StreamServer_Implementation
                    section.data(4).logicalSrcIdx = 228;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            paramMap.sections(10) = section;
            clear section

            section.nData     = 11;
            section.data(11)  = dumData; %prealloc

                    ;% QD2_DroneStack_Manual_2021a_P.StreamClient_URI
                    section.data(1).logicalSrcIdx = 229;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_Manual_2021a_P.StreamClient_Endian
                    section.data(2).logicalSrcIdx = 230;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_DroneStack_Manual_2021a_P.ManualSwitchSelectCommandInput_
                    section.data(3).logicalSrcIdx = 231;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_DroneStack_Manual_2021a_P.ToHostFile_VarName
                    section.data(4).logicalSrcIdx = 232;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_DroneStack_Manual_2021a_P.ToHostFile_FileFormat
                    section.data(5).logicalSrcIdx = 233;
                    section.data(5).dtTransOffset = 12;

                    ;% QD2_DroneStack_Manual_2021a_P.ToHostFile_file_name
                    section.data(6).logicalSrcIdx = 234;
                    section.data(6).dtTransOffset = 13;

                    ;% QD2_DroneStack_Manual_2021a_P.ToHostFile_VarName_m
                    section.data(7).logicalSrcIdx = 235;
                    section.data(7).dtTransOffset = 84;

                    ;% QD2_DroneStack_Manual_2021a_P.ToHostFile_FileFormat_j
                    section.data(8).logicalSrcIdx = 236;
                    section.data(8).dtTransOffset = 100;

                    ;% QD2_DroneStack_Manual_2021a_P.ToHostFile_file_name_p
                    section.data(9).logicalSrcIdx = 237;
                    section.data(9).dtTransOffset = 101;

                    ;% QD2_DroneStack_Manual_2021a_P.StreamServer_URI
                    section.data(10).logicalSrcIdx = 238;
                    section.data(10).dtTransOffset = 179;

                    ;% QD2_DroneStack_Manual_2021a_P.StreamServer_Endian
                    section.data(11).logicalSrcIdx = 239;
                    section.data(11).dtTransOffset = 215;

            nTotData = nTotData + section.nData;
            paramMap.sections(11) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_DroneStack_Manual_2021a_P.CoreSubsys_p.CompareToConstant_const
                    section.data(1).logicalSrcIdx = 240;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(12) = section;
            clear section

            section.nData     = 13;
            section.data(13)  = dumData; %prealloc

                    ;% QD2_DroneStack_Manual_2021a_P.CoreSubsys.AccelerometerFilterCutoffFreque
                    section.data(1).logicalSrcIdx = 241;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_Manual_2021a_P.CoreSubsys.AccelerometerFilterDampingRatio
                    section.data(2).logicalSrcIdx = 242;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_DroneStack_Manual_2021a_P.CoreSubsys.Integrator1_IC
                    section.data(3).logicalSrcIdx = 243;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_DroneStack_Manual_2021a_P.CoreSubsys.Gain_Gain
                    section.data(4).logicalSrcIdx = 244;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_DroneStack_Manual_2021a_P.CoreSubsys.Gain1_Gain
                    section.data(5).logicalSrcIdx = 245;
                    section.data(5).dtTransOffset = 5;

                    ;% QD2_DroneStack_Manual_2021a_P.CoreSubsys.GyroFilterCutoffFrequencyrads_V
                    section.data(6).logicalSrcIdx = 246;
                    section.data(6).dtTransOffset = 7;

                    ;% QD2_DroneStack_Manual_2021a_P.CoreSubsys.GyroFilterDampingRatio_Value
                    section.data(7).logicalSrcIdx = 247;
                    section.data(7).dtTransOffset = 8;

                    ;% QD2_DroneStack_Manual_2021a_P.CoreSubsys.Integrator2_IC
                    section.data(8).logicalSrcIdx = 248;
                    section.data(8).dtTransOffset = 9;

                    ;% QD2_DroneStack_Manual_2021a_P.CoreSubsys.Integrator2_IC_j
                    section.data(9).logicalSrcIdx = 249;
                    section.data(9).dtTransOffset = 10;

                    ;% QD2_DroneStack_Manual_2021a_P.CoreSubsys.Integrator_IC
                    section.data(10).logicalSrcIdx = 250;
                    section.data(10).dtTransOffset = 11;

                    ;% QD2_DroneStack_Manual_2021a_P.CoreSubsys.Constant_Value
                    section.data(11).logicalSrcIdx = 251;
                    section.data(11).dtTransOffset = 12;

                    ;% QD2_DroneStack_Manual_2021a_P.CoreSubsys.Constant_Value_m
                    section.data(12).logicalSrcIdx = 252;
                    section.data(12).dtTransOffset = 13;

                    ;% QD2_DroneStack_Manual_2021a_P.CoreSubsys.Integrator2_IC_g
                    section.data(13).logicalSrcIdx = 253;
                    section.data(13).dtTransOffset = 14;

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
        nTotSects     = 6;
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
        ;% Auto data (QD2_DroneStack_Manual_2021a_B)
        ;%
            section.nData     = 68;
            section.data(68)  = dumData; %prealloc

                    ;% QD2_DroneStack_Manual_2021a_B.HILRead_o1
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_Manual_2021a_B.HILRead_o2
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 3;

                    ;% QD2_DroneStack_Manual_2021a_B.StreamClient_o4
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 26;

                    ;% QD2_DroneStack_Manual_2021a_B.AttitudeTorqueCommands
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 37;

                    ;% QD2_DroneStack_Manual_2021a_B.AttitudeAngleCommands
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 40;

                    ;% QD2_DroneStack_Manual_2021a_B.SelectDataforIMU1
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 43;

                    ;% QD2_DroneStack_Manual_2021a_B.SelectDataforIMU0
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 52;

                    ;% QD2_DroneStack_Manual_2021a_B.Product3
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 61;

                    ;% QD2_DroneStack_Manual_2021a_B.Sum6
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 70;

                    ;% QD2_DroneStack_Manual_2021a_B.SaturationCommandAuthorityNm1
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 73;

                    ;% QD2_DroneStack_Manual_2021a_B.Delay
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 76;

                    ;% QD2_DroneStack_Manual_2021a_B.MaximumCommandAuthority
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 77;

                    ;% QD2_DroneStack_Manual_2021a_B.Selector
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 81;

                    ;% QD2_DroneStack_Manual_2021a_B.RateTransition7
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 85;

                    ;% QD2_DroneStack_Manual_2021a_B.RateTransition2
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 87;

                    ;% QD2_DroneStack_Manual_2021a_B.RateTransition1
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 88;

                    ;% QD2_DroneStack_Manual_2021a_B.ExtractESCChannels
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 89;

                    ;% QD2_DroneStack_Manual_2021a_B.ComputationTime
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 93;

                    ;% QD2_DroneStack_Manual_2021a_B.SampleTime
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 94;

                    ;% QD2_DroneStack_Manual_2021a_B.RateTransition
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 95;

                    ;% QD2_DroneStack_Manual_2021a_B.RateTransition1_d
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 96;

                    ;% QD2_DroneStack_Manual_2021a_B.RateTransition2_f
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 97;

                    ;% QD2_DroneStack_Manual_2021a_B.RateTransition3
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 98;

                    ;% QD2_DroneStack_Manual_2021a_B.RateTransition6
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 99;

                    ;% QD2_DroneStack_Manual_2021a_B.Bias1
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 159;

                    ;% QD2_DroneStack_Manual_2021a_B.Delay3
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 163;

                    ;% QD2_DroneStack_Manual_2021a_B.Delay2
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 164;

                    ;% QD2_DroneStack_Manual_2021a_B.Delay1
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 165;

                    ;% QD2_DroneStack_Manual_2021a_B.Delay_i
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 166;

                    ;% QD2_DroneStack_Manual_2021a_B.DataTypeConversion
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 167;

                    ;% QD2_DroneStack_Manual_2021a_B.DataTypeConversion_h
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 168;

                    ;% QD2_DroneStack_Manual_2021a_B.Clock
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 169;

                    ;% QD2_DroneStack_Manual_2021a_B.DataTypeConversion_c
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 170;

                    ;% QD2_DroneStack_Manual_2021a_B.DataTypeConversion_k
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 171;

                    ;% QD2_DroneStack_Manual_2021a_B.DataTypeConversion_cz
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 172;

                    ;% QD2_DroneStack_Manual_2021a_B.Gain
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 173;

                    ;% QD2_DroneStack_Manual_2021a_B.Gain_l
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 179;

                    ;% QD2_DroneStack_Manual_2021a_B.SampleTime_h
                    section.data(38).logicalSrcIdx = 37;
                    section.data(38).dtTransOffset = 185;

                    ;% QD2_DroneStack_Manual_2021a_B.ComputationTime_a
                    section.data(39).logicalSrcIdx = 38;
                    section.data(39).dtTransOffset = 186;

                    ;% QD2_DroneStack_Manual_2021a_B.DataTypeConversion4
                    section.data(40).logicalSrcIdx = 39;
                    section.data(40).dtTransOffset = 187;

                    ;% QD2_DroneStack_Manual_2021a_B.DataTypeConversion1
                    section.data(41).logicalSrcIdx = 40;
                    section.data(41).dtTransOffset = 188;

                    ;% QD2_DroneStack_Manual_2021a_B.DataTypeConversion5
                    section.data(42).logicalSrcIdx = 41;
                    section.data(42).dtTransOffset = 189;

                    ;% QD2_DroneStack_Manual_2021a_B.TmpSignalConversionAtToHostFile
                    section.data(43).logicalSrcIdx = 42;
                    section.data(43).dtTransOffset = 190;

                    ;% QD2_DroneStack_Manual_2021a_B.DataTypeConversion_p
                    section.data(44).logicalSrcIdx = 43;
                    section.data(44).dtTransOffset = 210;

                    ;% QD2_DroneStack_Manual_2021a_B.DataTypeConversion_a
                    section.data(45).logicalSrcIdx = 44;
                    section.data(45).dtTransOffset = 211;

                    ;% QD2_DroneStack_Manual_2021a_B.StreamServer_o4
                    section.data(46).logicalSrcIdx = 45;
                    section.data(46).dtTransOffset = 212;

                    ;% QD2_DroneStack_Manual_2021a_B.RateTransition_g
                    section.data(47).logicalSrcIdx = 46;
                    section.data(47).dtTransOffset = 213;

                    ;% QD2_DroneStack_Manual_2021a_B.x0
                    section.data(48).logicalSrcIdx = 47;
                    section.data(48).dtTransOffset = 220;

                    ;% QD2_DroneStack_Manual_2021a_B.Product
                    section.data(49).logicalSrcIdx = 48;
                    section.data(49).dtTransOffset = 221;

                    ;% QD2_DroneStack_Manual_2021a_B.Product1
                    section.data(50).logicalSrcIdx = 49;
                    section.data(50).dtTransOffset = 223;

                    ;% QD2_DroneStack_Manual_2021a_B.ToFFilterInitialConditionm
                    section.data(51).logicalSrcIdx = 50;
                    section.data(51).dtTransOffset = 225;

                    ;% QD2_DroneStack_Manual_2021a_B.RangingSensor_o1
                    section.data(52).logicalSrcIdx = 51;
                    section.data(52).dtTransOffset = 226;

                    ;% QD2_DroneStack_Manual_2021a_B.RangingSensor_o2
                    section.data(53).logicalSrcIdx = 52;
                    section.data(53).dtTransOffset = 227;

                    ;% QD2_DroneStack_Manual_2021a_B.RangingSensor_o3
                    section.data(54).logicalSrcIdx = 53;
                    section.data(54).dtTransOffset = 228;

                    ;% QD2_DroneStack_Manual_2021a_B.RangingSensor_o4
                    section.data(55).logicalSrcIdx = 54;
                    section.data(55).dtTransOffset = 229;

                    ;% QD2_DroneStack_Manual_2021a_B.Product_k
                    section.data(56).logicalSrcIdx = 55;
                    section.data(56).dtTransOffset = 230;

                    ;% QD2_DroneStack_Manual_2021a_B.Product1_p
                    section.data(57).logicalSrcIdx = 56;
                    section.data(57).dtTransOffset = 231;

                    ;% QD2_DroneStack_Manual_2021a_B.OutportBufferForOut1
                    section.data(58).logicalSrcIdx = 57;
                    section.data(58).dtTransOffset = 232;

                    ;% QD2_DroneStack_Manual_2021a_B.cmd
                    section.data(59).logicalSrcIdx = 58;
                    section.data(59).dtTransOffset = 233;

                    ;% QD2_DroneStack_Manual_2021a_B.cmd_enable
                    section.data(60).logicalSrcIdx = 59;
                    section.data(60).dtTransOffset = 237;

                    ;% QD2_DroneStack_Manual_2021a_B.tele_enable
                    section.data(61).logicalSrcIdx = 60;
                    section.data(61).dtTransOffset = 238;

                    ;% QD2_DroneStack_Manual_2021a_B.esc_ready
                    section.data(62).logicalSrcIdx = 61;
                    section.data(62).dtTransOffset = 239;

                    ;% QD2_DroneStack_Manual_2021a_B.esc_timeout
                    section.data(63).logicalSrcIdx = 62;
                    section.data(63).dtTransOffset = 240;

                    ;% QD2_DroneStack_Manual_2021a_B.state
                    section.data(64).logicalSrcIdx = 64;
                    section.data(64).dtTransOffset = 241;

                    ;% QD2_DroneStack_Manual_2021a_B.n
                    section.data(65).logicalSrcIdx = 66;
                    section.data(65).dtTransOffset = 242;

                    ;% QD2_DroneStack_Manual_2021a_B.ImpAsg_InsertedFor_ESCDataOut4_
                    section.data(66).logicalSrcIdx = 67;
                    section.data(66).dtTransOffset = 246;

                    ;% QD2_DroneStack_Manual_2021a_B.ImpAsg_InsertedFor_ESCDataOut_k
                    section.data(67).logicalSrcIdx = 68;
                    section.data(67).dtTransOffset = 250;

                    ;% QD2_DroneStack_Manual_2021a_B.ImpAsg_InsertedFor_ESCDataOu_kc
                    section.data(68).logicalSrcIdx = 69;
                    section.data(68).dtTransOffset = 254;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_DroneStack_Manual_2021a_B.DataTypeConversion_ko
                    section.data(1).logicalSrcIdx = 73;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_DroneStack_Manual_2021a_B.RateTransition14
                    section.data(1).logicalSrcIdx = 74;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(3) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% QD2_DroneStack_Manual_2021a_B.IPAddressofSupervisoryModelMiss
                    section.data(1).logicalSrcIdx = 75;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_Manual_2021a_B.StreamClient_o1
                    section.data(2).logicalSrcIdx = 76;
                    section.data(2).dtTransOffset = 80;

                    ;% QD2_DroneStack_Manual_2021a_B.RateTransition16
                    section.data(3).logicalSrcIdx = 77;
                    section.data(3).dtTransOffset = 81;

            nTotData = nTotData + section.nData;
            sigMap.sections(4) = section;
            clear section

            section.nData     = 12;
            section.data(12)  = dumData; %prealloc

                    ;% QD2_DroneStack_Manual_2021a_B.AND
                    section.data(1).logicalSrcIdx = 78;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_Manual_2021a_B.LogicalOperator
                    section.data(2).logicalSrcIdx = 79;
                    section.data(2).dtTransOffset = 4;

                    ;% QD2_DroneStack_Manual_2021a_B.LogicalOperator_f
                    section.data(3).logicalSrcIdx = 80;
                    section.data(3).dtTransOffset = 5;

                    ;% QD2_DroneStack_Manual_2021a_B.RelationalOperator
                    section.data(4).logicalSrcIdx = 81;
                    section.data(4).dtTransOffset = 6;

                    ;% QD2_DroneStack_Manual_2021a_B.LogicalOperator_p
                    section.data(5).logicalSrcIdx = 82;
                    section.data(5).dtTransOffset = 7;

                    ;% QD2_DroneStack_Manual_2021a_B.LogicalOperator_m
                    section.data(6).logicalSrcIdx = 83;
                    section.data(6).dtTransOffset = 8;

                    ;% QD2_DroneStack_Manual_2021a_B.LogicalOperator_a
                    section.data(7).logicalSrcIdx = 84;
                    section.data(7).dtTransOffset = 9;

                    ;% QD2_DroneStack_Manual_2021a_B.RelationalOperator_g
                    section.data(8).logicalSrcIdx = 85;
                    section.data(8).dtTransOffset = 10;

                    ;% QD2_DroneStack_Manual_2021a_B.LogicalOperator_k
                    section.data(9).logicalSrcIdx = 86;
                    section.data(9).dtTransOffset = 11;

                    ;% QD2_DroneStack_Manual_2021a_B.RelationalOperator_p
                    section.data(10).logicalSrcIdx = 87;
                    section.data(10).dtTransOffset = 12;

                    ;% QD2_DroneStack_Manual_2021a_B.HILWatchdog
                    section.data(11).logicalSrcIdx = 88;
                    section.data(11).dtTransOffset = 13;

                    ;% QD2_DroneStack_Manual_2021a_B.AND_g
                    section.data(12).logicalSrcIdx = 89;
                    section.data(12).dtTransOffset = 14;

            nTotData = nTotData + section.nData;
            sigMap.sections(5) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% QD2_DroneStack_Manual_2021a_B.CoreSubsys[1].Gain1
                    section.data(1).logicalSrcIdx = 90;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_Manual_2021a_B.CoreSubsys[1].Integrator1
                    section.data(2).logicalSrcIdx = 91;
                    section.data(2).dtTransOffset = 2;

                    ;% QD2_DroneStack_Manual_2021a_B.CoreSubsys[1].Product1
                    section.data(3).logicalSrcIdx = 92;
                    section.data(3).dtTransOffset = 5;

                    ;% QD2_DroneStack_Manual_2021a_B.CoreSubsys[1].Product
                    section.data(4).logicalSrcIdx = 93;
                    section.data(4).dtTransOffset = 8;

                    ;% QD2_DroneStack_Manual_2021a_B.CoreSubsys[1].Product_j
                    section.data(5).logicalSrcIdx = 94;
                    section.data(5).dtTransOffset = 11;

                    ;% QD2_DroneStack_Manual_2021a_B.CoreSubsys[1].Product1_e
                    section.data(6).logicalSrcIdx = 95;
                    section.data(6).dtTransOffset = 14;

                    ;% QD2_DroneStack_Manual_2021a_B.CoreSubsys[1].Sum1
                    section.data(7).logicalSrcIdx = 96;
                    section.data(7).dtTransOffset = 17;

            nTotData = nTotData + section.nData;
            sigMap.sections(6) = section;
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
        nTotSects     = 16;
        sectIdxOffset = 6;

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
        ;% Auto data (QD2_DroneStack_Manual_2021a_DW)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_DroneStack_Manual_2021a_DW.RangingSensor_Measurements
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 13;
            section.data(13)  = dumData; %prealloc

                    ;% QD2_DroneStack_Manual_2021a_DW.Time_Timeout
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_Manual_2021a_DW.ComputationTime_BeginTime
                    section.data(2).logicalSrcIdx = 2;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_DroneStack_Manual_2021a_DW.ComputationTime_ComputationTime
                    section.data(3).logicalSrcIdx = 3;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_DroneStack_Manual_2021a_DW.SampleTime_PreviousTime
                    section.data(4).logicalSrcIdx = 4;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_DroneStack_Manual_2021a_DW.SampleTime_PreviousTime_j
                    section.data(5).logicalSrcIdx = 5;
                    section.data(5).dtTransOffset = 4;

                    ;% QD2_DroneStack_Manual_2021a_DW.ComputationTime_BeginTime_b
                    section.data(6).logicalSrcIdx = 6;
                    section.data(6).dtTransOffset = 5;

                    ;% QD2_DroneStack_Manual_2021a_DW.ComputationTime_ComputationTi_j
                    section.data(7).logicalSrcIdx = 7;
                    section.data(7).dtTransOffset = 6;

                    ;% QD2_DroneStack_Manual_2021a_DW.ComputationTime1_BeginTime
                    section.data(8).logicalSrcIdx = 8;
                    section.data(8).dtTransOffset = 7;

                    ;% QD2_DroneStack_Manual_2021a_DW.ComputationTime1_ComputationTim
                    section.data(9).logicalSrcIdx = 9;
                    section.data(9).dtTransOffset = 8;

                    ;% QD2_DroneStack_Manual_2021a_DW.SampleTime1_PreviousTime
                    section.data(10).logicalSrcIdx = 10;
                    section.data(10).dtTransOffset = 9;

                    ;% QD2_DroneStack_Manual_2021a_DW.ComputationTime2_BeginTime
                    section.data(11).logicalSrcIdx = 11;
                    section.data(11).dtTransOffset = 10;

                    ;% QD2_DroneStack_Manual_2021a_DW.ComputationTime2_ComputationTim
                    section.data(12).logicalSrcIdx = 12;
                    section.data(12).dtTransOffset = 11;

                    ;% QD2_DroneStack_Manual_2021a_DW.SampleTime2_PreviousTime
                    section.data(13).logicalSrcIdx = 13;
                    section.data(13).dtTransOffset = 12;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 50;
            section.data(50)  = dumData; %prealloc

                    ;% QD2_DroneStack_Manual_2021a_DW.Delay_DSTATE
                    section.data(1).logicalSrcIdx = 14;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_Manual_2021a_DW.Delay_DSTATE_l
                    section.data(2).logicalSrcIdx = 15;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_DroneStack_Manual_2021a_DW.Delay3_DSTATE
                    section.data(3).logicalSrcIdx = 16;
                    section.data(3).dtTransOffset = 51;

                    ;% QD2_DroneStack_Manual_2021a_DW.Delay2_DSTATE
                    section.data(4).logicalSrcIdx = 17;
                    section.data(4).dtTransOffset = 53;

                    ;% QD2_DroneStack_Manual_2021a_DW.Delay1_DSTATE
                    section.data(5).logicalSrcIdx = 18;
                    section.data(5).dtTransOffset = 55;

                    ;% QD2_DroneStack_Manual_2021a_DW.Delay_DSTATE_ln
                    section.data(6).logicalSrcIdx = 19;
                    section.data(6).dtTransOffset = 57;

                    ;% QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE
                    section.data(7).logicalSrcIdx = 20;
                    section.data(7).dtTransOffset = 59;

                    ;% QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE_j
                    section.data(8).logicalSrcIdx = 21;
                    section.data(8).dtTransOffset = 60;

                    ;% QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE_k
                    section.data(9).logicalSrcIdx = 22;
                    section.data(9).dtTransOffset = 61;

                    ;% QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE_e
                    section.data(10).logicalSrcIdx = 23;
                    section.data(10).dtTransOffset = 62;

                    ;% QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE_l
                    section.data(11).logicalSrcIdx = 24;
                    section.data(11).dtTransOffset = 63;

                    ;% QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_DSTAT_lx
                    section.data(12).logicalSrcIdx = 25;
                    section.data(12).dtTransOffset = 64;

                    ;% QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE_o
                    section.data(13).logicalSrcIdx = 26;
                    section.data(13).dtTransOffset = 65;

                    ;% QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator1_DSTATE
                    section.data(14).logicalSrcIdx = 27;
                    section.data(14).dtTransOffset = 67;

                    ;% QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE_a
                    section.data(15).logicalSrcIdx = 28;
                    section.data(15).dtTransOffset = 69;

                    ;% QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator1_DSTAT_d
                    section.data(16).logicalSrcIdx = 29;
                    section.data(16).dtTransOffset = 70;

                    ;% QD2_DroneStack_Manual_2021a_DW.HILInitialize_AIMinimums
                    section.data(17).logicalSrcIdx = 30;
                    section.data(17).dtTransOffset = 71;

                    ;% QD2_DroneStack_Manual_2021a_DW.HILInitialize_AIMaximums
                    section.data(18).logicalSrcIdx = 31;
                    section.data(18).dtTransOffset = 75;

                    ;% QD2_DroneStack_Manual_2021a_DW.HILInitialize_FilterFrequency
                    section.data(19).logicalSrcIdx = 32;
                    section.data(19).dtTransOffset = 79;

                    ;% QD2_DroneStack_Manual_2021a_DW.HILInitialize_POSortedFreqs
                    section.data(20).logicalSrcIdx = 33;
                    section.data(20).dtTransOffset = 81;

                    ;% QD2_DroneStack_Manual_2021a_DW.HILInitialize_POValues
                    section.data(21).logicalSrcIdx = 34;
                    section.data(21).dtTransOffset = 87;

                    ;% QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput
                    section.data(22).logicalSrcIdx = 35;
                    section.data(22).dtTransOffset = 93;

                    ;% QD2_DroneStack_Manual_2021a_DW.RateTransition7_Buffer0
                    section.data(23).logicalSrcIdx = 36;
                    section.data(23).dtTransOffset = 94;

                    ;% QD2_DroneStack_Manual_2021a_DW.RateTransition2_Buffer0
                    section.data(24).logicalSrcIdx = 37;
                    section.data(24).dtTransOffset = 96;

                    ;% QD2_DroneStack_Manual_2021a_DW.RateTransition1_Buffer0
                    section.data(25).logicalSrcIdx = 38;
                    section.data(25).dtTransOffset = 97;

                    ;% QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput_h
                    section.data(26).logicalSrcIdx = 39;
                    section.data(26).dtTransOffset = 98;

                    ;% QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput_k
                    section.data(27).logicalSrcIdx = 40;
                    section.data(27).dtTransOffset = 102;

                    ;% QD2_DroneStack_Manual_2021a_DW.RateTransition_Buffer0
                    section.data(28).logicalSrcIdx = 41;
                    section.data(28).dtTransOffset = 106;

                    ;% QD2_DroneStack_Manual_2021a_DW.RateTransition1_Buffer0_l
                    section.data(29).logicalSrcIdx = 42;
                    section.data(29).dtTransOffset = 107;

                    ;% QD2_DroneStack_Manual_2021a_DW.RateTransition2_Buffer0_l
                    section.data(30).logicalSrcIdx = 43;
                    section.data(30).dtTransOffset = 108;

                    ;% QD2_DroneStack_Manual_2021a_DW.RateTransition3_Buffer0
                    section.data(31).logicalSrcIdx = 44;
                    section.data(31).dtTransOffset = 109;

                    ;% QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput_a
                    section.data(32).logicalSrcIdx = 45;
                    section.data(32).dtTransOffset = 110;

                    ;% QD2_DroneStack_Manual_2021a_DW.RateTransition_Buffer
                    section.data(33).logicalSrcIdx = 46;
                    section.data(33).dtTransOffset = 114;

                    ;% QD2_DroneStack_Manual_2021a_DW.RateTransition10_Buffer
                    section.data(34).logicalSrcIdx = 47;
                    section.data(34).dtTransOffset = 121;

                    ;% QD2_DroneStack_Manual_2021a_DW.RateTransition11_Buffer
                    section.data(35).logicalSrcIdx = 48;
                    section.data(35).dtTransOffset = 125;

                    ;% QD2_DroneStack_Manual_2021a_DW.RateTransition12_Buffer
                    section.data(36).logicalSrcIdx = 49;
                    section.data(36).dtTransOffset = 126;

                    ;% QD2_DroneStack_Manual_2021a_DW.RateTransition15_Buffer
                    section.data(37).logicalSrcIdx = 50;
                    section.data(37).dtTransOffset = 127;

                    ;% QD2_DroneStack_Manual_2021a_DW.RateTransition17_Buffer
                    section.data(38).logicalSrcIdx = 51;
                    section.data(38).dtTransOffset = 136;

                    ;% QD2_DroneStack_Manual_2021a_DW.RateTransition19_Buffer
                    section.data(39).logicalSrcIdx = 52;
                    section.data(39).dtTransOffset = 145;

                    ;% QD2_DroneStack_Manual_2021a_DW.RateTransition20_Buffer
                    section.data(40).logicalSrcIdx = 53;
                    section.data(40).dtTransOffset = 154;

                    ;% QD2_DroneStack_Manual_2021a_DW.RateTransition3_Buffer
                    section.data(41).logicalSrcIdx = 54;
                    section.data(41).dtTransOffset = 155;

                    ;% QD2_DroneStack_Manual_2021a_DW.RateTransition8_Buffer
                    section.data(42).logicalSrcIdx = 55;
                    section.data(42).dtTransOffset = 164;

                    ;% QD2_DroneStack_Manual_2021a_DW.Memory2_PreviousInput
                    section.data(43).logicalSrcIdx = 56;
                    section.data(43).dtTransOffset = 176;

                    ;% QD2_DroneStack_Manual_2021a_DW.next_state_after_pause
                    section.data(44).logicalSrcIdx = 57;
                    section.data(44).dtTransOffset = 177;

                    ;% QD2_DroneStack_Manual_2021a_DW.state_counter
                    section.data(45).logicalSrcIdx = 58;
                    section.data(45).dtTransOffset = 178;

                    ;% QD2_DroneStack_Manual_2021a_DW.state_counter_after_pause
                    section.data(46).logicalSrcIdx = 59;
                    section.data(46).dtTransOffset = 179;

                    ;% QD2_DroneStack_Manual_2021a_DW.esc_timeout_state
                    section.data(47).logicalSrcIdx = 60;
                    section.data(47).dtTransOffset = 180;

                    ;% QD2_DroneStack_Manual_2021a_DW.idx
                    section.data(48).logicalSrcIdx = 61;
                    section.data(48).dtTransOffset = 181;

                    ;% QD2_DroneStack_Manual_2021a_DW.state
                    section.data(49).logicalSrcIdx = 62;
                    section.data(49).dtTransOffset = 182;

                    ;% QD2_DroneStack_Manual_2021a_DW.ms_time_prev
                    section.data(50).logicalSrcIdx = 63;
                    section.data(50).dtTransOffset = 183;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% QD2_DroneStack_Manual_2021a_DW.StreamClient_Stream
                    section.data(1).logicalSrcIdx = 64;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_Manual_2021a_DW.StreamServer_Stream
                    section.data(2).logicalSrcIdx = 65;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_DroneStack_Manual_2021a_DW.RangingSensor_Sensor
                    section.data(1).logicalSrcIdx = 66;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% QD2_DroneStack_Manual_2021a_DW.ToHostFile_PointsWritten
                    section.data(1).logicalSrcIdx = 67;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_Manual_2021a_DW.ToHostFile_PointsWritten_m
                    section.data(2).logicalSrcIdx = 68;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_DroneStack_Manual_2021a_DW.HILInitialize_Card
                    section.data(1).logicalSrcIdx = 69;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section

            section.nData     = 17;
            section.data(17)  = dumData; %prealloc

                    ;% QD2_DroneStack_Manual_2021a_DW.HILRead_PWORK
                    section.data(1).logicalSrcIdx = 70;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_Manual_2021a_DW.ESCSelectRaw_PWORK.LoggedData
                    section.data(2).logicalSrcIdx = 71;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_DroneStack_Manual_2021a_DW.HILWriteDigital_PWORK
                    section.data(3).logicalSrcIdx = 72;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_DroneStack_Manual_2021a_DW.ToHostFile_PWORK
                    section.data(4).logicalSrcIdx = 73;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_DroneStack_Manual_2021a_DW.Telemetry_PWORK.LoggedData
                    section.data(5).logicalSrcIdx = 74;
                    section.data(5).dtTransOffset = 5;

                    ;% QD2_DroneStack_Manual_2021a_DW.ESCChannelMismatrch_PWORK.LoggedData
                    section.data(6).logicalSrcIdx = 75;
                    section.data(6).dtTransOffset = 6;

                    ;% QD2_DroneStack_Manual_2021a_DW.ESCChannelMismatrchCount_PWORK.LoggedData
                    section.data(7).logicalSrcIdx = 76;
                    section.data(7).dtTransOffset = 10;

                    ;% QD2_DroneStack_Manual_2021a_DW.ESCChannelSelectionIndex_PWORK.LoggedData
                    section.data(8).logicalSrcIdx = 77;
                    section.data(8).dtTransOffset = 14;

                    ;% QD2_DroneStack_Manual_2021a_DW.TimingCheck_PWORK.LoggedData
                    section.data(9).logicalSrcIdx = 78;
                    section.data(9).dtTransOffset = 18;

                    ;% QD2_DroneStack_Manual_2021a_DW.RollandPitchAngleControldeg_PWO.LoggedData
                    section.data(10).logicalSrcIdx = 79;
                    section.data(10).dtTransOffset = 21;

                    ;% QD2_DroneStack_Manual_2021a_DW.RollPitchandYawRateControldegs_.LoggedData
                    section.data(11).logicalSrcIdx = 80;
                    section.data(11).dtTransOffset = 23;

                    ;% QD2_DroneStack_Manual_2021a_DW.HILWatchdog_PWORK
                    section.data(12).logicalSrcIdx = 81;
                    section.data(12).dtTransOffset = 26;

                    ;% QD2_DroneStack_Manual_2021a_DW.ToHostFile_PWORK_f
                    section.data(13).logicalSrcIdx = 82;
                    section.data(13).dtTransOffset = 27;

                    ;% QD2_DroneStack_Manual_2021a_DW.ComputationTimes_PWORK.LoggedData
                    section.data(14).logicalSrcIdx = 83;
                    section.data(14).dtTransOffset = 29;

                    ;% QD2_DroneStack_Manual_2021a_DW.SampleTimes_PWORK.LoggedData
                    section.data(15).logicalSrcIdx = 84;
                    section.data(15).dtTransOffset = 30;

                    ;% QD2_DroneStack_Manual_2021a_DW.HILWritePWM_PWORK
                    section.data(16).logicalSrcIdx = 85;
                    section.data(16).dtTransOffset = 31;

                    ;% QD2_DroneStack_Manual_2021a_DW.buffer
                    section.data(17).logicalSrcIdx = 86;
                    section.data(17).dtTransOffset = 32;

            nTotData = nTotData + section.nData;
            dworkMap.sections(8) = section;
            clear section

            section.nData     = 11;
            section.data(11)  = dumData; %prealloc

                    ;% QD2_DroneStack_Manual_2021a_DW.HILInitialize_DOStates
                    section.data(1).logicalSrcIdx = 87;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_Manual_2021a_DW.HILInitialize_QuadratureModes
                    section.data(2).logicalSrcIdx = 88;
                    section.data(2).dtTransOffset = 6;

                    ;% QD2_DroneStack_Manual_2021a_DW.HILInitialize_InitialEICounts
                    section.data(3).logicalSrcIdx = 89;
                    section.data(3).dtTransOffset = 8;

                    ;% QD2_DroneStack_Manual_2021a_DW.HILInitialize_POModeValues
                    section.data(4).logicalSrcIdx = 90;
                    section.data(4).dtTransOffset = 10;

                    ;% QD2_DroneStack_Manual_2021a_DW.HILInitialize_POAlignValues
                    section.data(5).logicalSrcIdx = 91;
                    section.data(5).dtTransOffset = 16;

                    ;% QD2_DroneStack_Manual_2021a_DW.HILInitialize_POPolarityVals
                    section.data(6).logicalSrcIdx = 92;
                    section.data(6).dtTransOffset = 22;

                    ;% QD2_DroneStack_Manual_2021a_DW.sfEvent
                    section.data(7).logicalSrcIdx = 93;
                    section.data(7).dtTransOffset = 28;

                    ;% QD2_DroneStack_Manual_2021a_DW.sfEvent_e
                    section.data(8).logicalSrcIdx = 94;
                    section.data(8).dtTransOffset = 29;

                    ;% QD2_DroneStack_Manual_2021a_DW.sfEvent_d
                    section.data(9).logicalSrcIdx = 95;
                    section.data(9).dtTransOffset = 30;

                    ;% QD2_DroneStack_Manual_2021a_DW.sfEvent_b
                    section.data(10).logicalSrcIdx = 96;
                    section.data(10).dtTransOffset = 31;

                    ;% QD2_DroneStack_Manual_2021a_DW.sfEvent_a
                    section.data(11).logicalSrcIdx = 97;
                    section.data(11).dtTransOffset = 32;

            nTotData = nTotData + section.nData;
            dworkMap.sections(9) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% QD2_DroneStack_Manual_2021a_DW.HILInitialize_POSortedChans
                    section.data(1).logicalSrcIdx = 98;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_Manual_2021a_DW.ToHostFile_SamplesCount
                    section.data(2).logicalSrcIdx = 99;
                    section.data(2).dtTransOffset = 6;

                    ;% QD2_DroneStack_Manual_2021a_DW.ToHostFile_ArrayNameLength
                    section.data(3).logicalSrcIdx = 100;
                    section.data(3).dtTransOffset = 7;

                    ;% QD2_DroneStack_Manual_2021a_DW.ToHostFile_SamplesCount_k
                    section.data(4).logicalSrcIdx = 101;
                    section.data(4).dtTransOffset = 8;

                    ;% QD2_DroneStack_Manual_2021a_DW.ToHostFile_ArrayNameLength_l
                    section.data(5).logicalSrcIdx = 102;
                    section.data(5).dtTransOffset = 9;

            nTotData = nTotData + section.nData;
            dworkMap.sections(10) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_DroneStack_Manual_2021a_DW.StringDisplay_IWORK
                    section.data(1).logicalSrcIdx = 103;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(11) = section;
            clear section

            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_PrevRese
                    section.data(1).logicalSrcIdx = 104;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_PrevRe_h
                    section.data(2).logicalSrcIdx = 105;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_PrevR_hs
                    section.data(3).logicalSrcIdx = 106;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_PrevRe_b
                    section.data(4).logicalSrcIdx = 107;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_PrevRe_j
                    section.data(5).logicalSrcIdx = 108;
                    section.data(5).dtTransOffset = 4;

                    ;% QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_PrevRe_k
                    section.data(6).logicalSrcIdx = 109;
                    section.data(6).dtTransOffset = 5;

                    ;% QD2_DroneStack_Manual_2021a_DW.TriggeredSubsystemLatchingFlag_
                    section.data(7).logicalSrcIdx = 110;
                    section.data(7).dtTransOffset = 6;

                    ;% QD2_DroneStack_Manual_2021a_DW.EnabledSubsystemWriteESCCommand
                    section.data(8).logicalSrcIdx = 111;
                    section.data(8).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            dworkMap.sections(12) = section;
            clear section

            section.nData     = 19;
            section.data(19)  = dumData; %prealloc

                    ;% QD2_DroneStack_Manual_2021a_DW.HILInitialize_DOBits
                    section.data(1).logicalSrcIdx = 112;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_Manual_2021a_DW.Time_Owner
                    section.data(2).logicalSrcIdx = 113;
                    section.data(2).dtTransOffset = 6;

                    ;% QD2_DroneStack_Manual_2021a_DW.StreamClient_Connected
                    section.data(3).logicalSrcIdx = 114;
                    section.data(3).dtTransOffset = 7;

                    ;% QD2_DroneStack_Manual_2021a_DW.Memory1_PreviousInput
                    section.data(4).logicalSrcIdx = 115;
                    section.data(4).dtTransOffset = 8;

                    ;% QD2_DroneStack_Manual_2021a_DW.HILWatchdog_IsStarted
                    section.data(5).logicalSrcIdx = 116;
                    section.data(5).dtTransOffset = 9;

                    ;% QD2_DroneStack_Manual_2021a_DW.Memory3_PreviousInput
                    section.data(6).logicalSrcIdx = 117;
                    section.data(6).dtTransOffset = 10;

                    ;% QD2_DroneStack_Manual_2021a_DW.doneDoubleBufferReInit
                    section.data(7).logicalSrcIdx = 118;
                    section.data(7).dtTransOffset = 11;

                    ;% QD2_DroneStack_Manual_2021a_DW.next_state_after_pause_not_empt
                    section.data(8).logicalSrcIdx = 119;
                    section.data(8).dtTransOffset = 12;

                    ;% QD2_DroneStack_Manual_2021a_DW.state_counter_not_empty
                    section.data(9).logicalSrcIdx = 120;
                    section.data(9).dtTransOffset = 13;

                    ;% QD2_DroneStack_Manual_2021a_DW.state_counter_after_pause_not_e
                    section.data(10).logicalSrcIdx = 121;
                    section.data(10).dtTransOffset = 14;

                    ;% QD2_DroneStack_Manual_2021a_DW.esc_timeout_state_not_empty
                    section.data(11).logicalSrcIdx = 122;
                    section.data(11).dtTransOffset = 15;

                    ;% QD2_DroneStack_Manual_2021a_DW.doneDoubleBufferReInit_c
                    section.data(12).logicalSrcIdx = 123;
                    section.data(12).dtTransOffset = 16;

                    ;% QD2_DroneStack_Manual_2021a_DW.doneDoubleBufferReInit_d
                    section.data(13).logicalSrcIdx = 124;
                    section.data(13).dtTransOffset = 17;

                    ;% QD2_DroneStack_Manual_2021a_DW.idx_not_empty
                    section.data(14).logicalSrcIdx = 125;
                    section.data(14).dtTransOffset = 18;

                    ;% QD2_DroneStack_Manual_2021a_DW.buffer_not_empty
                    section.data(15).logicalSrcIdx = 126;
                    section.data(15).dtTransOffset = 19;

                    ;% QD2_DroneStack_Manual_2021a_DW.doneDoubleBufferReInit_o
                    section.data(16).logicalSrcIdx = 127;
                    section.data(16).dtTransOffset = 20;

                    ;% QD2_DroneStack_Manual_2021a_DW.state_not_empty
                    section.data(17).logicalSrcIdx = 128;
                    section.data(17).dtTransOffset = 21;

                    ;% QD2_DroneStack_Manual_2021a_DW.doneDoubleBufferReInit_b
                    section.data(18).logicalSrcIdx = 129;
                    section.data(18).dtTransOffset = 22;

                    ;% QD2_DroneStack_Manual_2021a_DW.ms_time_prev_not_empty
                    section.data(19).logicalSrcIdx = 130;
                    section.data(19).dtTransOffset = 23;

            nTotData = nTotData + section.nData;
            dworkMap.sections(13) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_DroneStack_Manual_2021a_DW.HILWriteDigital_Buffer
                    section.data(1).logicalSrcIdx = 131;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(14) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_DroneStack_Manual_2021a_DW.CoreSubsys[1].sfEvent
                    section.data(1).logicalSrcIdx = 132;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(15) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% QD2_DroneStack_Manual_2021a_DW.CoreSubsys[1].Integrator1_DWORK1
                    section.data(1).logicalSrcIdx = 133;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_Manual_2021a_DW.CoreSubsys[1].Integrator1_DWORK1_b
                    section.data(2).logicalSrcIdx = 134;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_DroneStack_Manual_2021a_DW.CoreSubsys[1].doneDoubleBufferReInit
                    section.data(3).logicalSrcIdx = 135;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(16) = section;
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


    targMap.checksum0 = 1429712378;
    targMap.checksum1 = 3322906005;
    targMap.checksum2 = 3877968020;
    targMap.checksum3 = 2383775020;

