    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 22;
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
        ;% Auto data (QD2_DroneStack_PID_2021a_P)
        ;%
            section.nData     = 38;
            section.data(38)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_P.KT
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_PID_2021a_P.Motor_Matrix
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 3;

                    ;% QD2_DroneStack_PID_2021a_P.Resetwhenstartingtotakeoff_cons
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 19;

                    ;% QD2_DroneStack_PID_2021a_P.IgnoreYawControllerunlessinFlig
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 20;

                    ;% QD2_DroneStack_PID_2021a_P.IgnoreYawControllerunlessinFl_h
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 21;

                    ;% QD2_DroneStack_PID_2021a_P.IgnoreControllerunlessinTakeoff
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 22;

                    ;% QD2_DroneStack_PID_2021a_P.CompareToConstant_const
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 23;

                    ;% QD2_DroneStack_PID_2021a_P.Greaterthanminimumexpectedvolta
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 24;

                    ;% QD2_DroneStack_PID_2021a_P.Lessthanminimumthresholdvoltage
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 25;

                    ;% QD2_DroneStack_PID_2021a_P.Waitatleast2secondstoallowforin
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 26;

                    ;% QD2_DroneStack_PID_2021a_P.CompareToConstant2_const
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 27;

                    ;% QD2_DroneStack_PID_2021a_P.Thresholdtodetectifthedroneiscl
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 28;

                    ;% QD2_DroneStack_PID_2021a_P.Thresholdtodetectifthecommanded
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 29;

                    ;% QD2_DroneStack_PID_2021a_P.Ifthemeasuredheightismorethan02
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 30;

                    ;% QD2_DroneStack_PID_2021a_P.themeasuredheightislessthan015m
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 31;

                    ;% QD2_DroneStack_PID_2021a_P.FlightState_const
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 32;

                    ;% QD2_DroneStack_PID_2021a_P.TakeoffThrottleHeightState_cons
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 33;

                    ;% QD2_DroneStack_PID_2021a_P.CompareToConstant1_const
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 34;

                    ;% QD2_DroneStack_PID_2021a_P.Ifthedroneisatorbelowthisheight
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 35;

                    ;% QD2_DroneStack_PID_2021a_P.StreamClient_default_value
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 36;

                    ;% QD2_DroneStack_PID_2021a_P.StreamServer_default_value
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 52;

                    ;% QD2_DroneStack_PID_2021a_P.Threshold_duration
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 53;

                    ;% QD2_DroneStack_PID_2021a_P.Threshold_duration_l
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 54;

                    ;% QD2_DroneStack_PID_2021a_P.Threshold1_duration
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 55;

                    ;% QD2_DroneStack_PID_2021a_P.Threshold2_duration
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 56;

                    ;% QD2_DroneStack_PID_2021a_P.Threshold_duration_o
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 57;

                    ;% QD2_DroneStack_PID_2021a_P.Stopmodel_duration
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 58;

                    ;% QD2_DroneStack_PID_2021a_P.Communication_duration
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 59;

                    ;% QD2_DroneStack_PID_2021a_P.DiscreteSecondOrderLowPassFilte
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 60;

                    ;% QD2_DroneStack_PID_2021a_P.DiscreteSecondOrderLowPassFil_p
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 61;

                    ;% QD2_DroneStack_PID_2021a_P.Threshold_threshold
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 62;

                    ;% QD2_DroneStack_PID_2021a_P.Threshold_threshold_p
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 63;

                    ;% QD2_DroneStack_PID_2021a_P.Threshold1_threshold
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 64;

                    ;% QD2_DroneStack_PID_2021a_P.Threshold2_threshold
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 65;

                    ;% QD2_DroneStack_PID_2021a_P.Threshold_threshold_pd
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 66;

                    ;% QD2_DroneStack_PID_2021a_P.Stopmodel_threshold
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 67;

                    ;% QD2_DroneStack_PID_2021a_P.Communication_threshold
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 68;

                    ;% QD2_DroneStack_PID_2021a_P.DetectChange_vinit
                    section.data(38).logicalSrcIdx = 37;
                    section.data(38).dtTransOffset = 69;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_P.CompareToConstant1_const_m
                    section.data(1).logicalSrcIdx = 38;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_P.HILRead_analog_channels
                    section.data(1).logicalSrcIdx = 39;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_PID_2021a_P.HILWritePWM_channels
                    section.data(2).logicalSrcIdx = 40;
                    section.data(2).dtTransOffset = 3;

                    ;% QD2_DroneStack_PID_2021a_P.HILWriteDigital_channels
                    section.data(3).logicalSrcIdx = 41;
                    section.data(3).dtTransOffset = 7;

                    ;% QD2_DroneStack_PID_2021a_P.HILRead_other_channels
                    section.data(4).logicalSrcIdx = 42;
                    section.data(4).dtTransOffset = 13;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_P.StopwithMessage_message_icon
                    section.data(1).logicalSrcIdx = 43;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_PID_2021a_P.StopwithMessage1_message_icon
                    section.data(2).logicalSrcIdx = 44;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_DroneStack_PID_2021a_P.StopwithMessage3_message_icon
                    section.data(3).logicalSrcIdx = 45;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_P.StringDisplay_alignment
                    section.data(1).logicalSrcIdx = 46;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_PID_2021a_P.CompareToConstant_const_n
                    section.data(2).logicalSrcIdx = 47;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_DroneStack_PID_2021a_P.StringDisplay_display_mode
                    section.data(3).logicalSrcIdx = 48;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section

            section.nData     = 226;
            section.data(226)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_P.Constant4_Value
                    section.data(1).logicalSrcIdx = 49;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_PID_2021a_P.Constant5_Value
                    section.data(2).logicalSrcIdx = 50;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_DroneStack_PID_2021a_P.RedRed_Value
                    section.data(3).logicalSrcIdx = 51;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_DroneStack_PID_2021a_P.LEDOFF_Value
                    section.data(4).logicalSrcIdx = 52;
                    section.data(4).dtTransOffset = 8;

                    ;% QD2_DroneStack_PID_2021a_P.YellowYellow_Value
                    section.data(5).logicalSrcIdx = 53;
                    section.data(5).dtTransOffset = 14;

                    ;% QD2_DroneStack_PID_2021a_P.YellowGreen_Value
                    section.data(6).logicalSrcIdx = 54;
                    section.data(6).dtTransOffset = 20;

                    ;% QD2_DroneStack_PID_2021a_P.BlueBlue_Value
                    section.data(7).logicalSrcIdx = 55;
                    section.data(7).dtTransOffset = 26;

                    ;% QD2_DroneStack_PID_2021a_P.YellowRed_Value
                    section.data(8).logicalSrcIdx = 56;
                    section.data(8).dtTransOffset = 32;

                    ;% QD2_DroneStack_PID_2021a_P.RedYellow_Value
                    section.data(9).logicalSrcIdx = 57;
                    section.data(9).dtTransOffset = 38;

                    ;% QD2_DroneStack_PID_2021a_P.GreenGreen_Value
                    section.data(10).logicalSrcIdx = 58;
                    section.data(10).dtTransOffset = 44;

                    ;% QD2_DroneStack_PID_2021a_P.YellowBlue_Value
                    section.data(11).logicalSrcIdx = 59;
                    section.data(11).dtTransOffset = 50;

                    ;% QD2_DroneStack_PID_2021a_P.RedBlue_Value
                    section.data(12).logicalSrcIdx = 60;
                    section.data(12).dtTransOffset = 56;

                    ;% QD2_DroneStack_PID_2021a_P.Out1_Y0
                    section.data(13).logicalSrcIdx = 61;
                    section.data(13).dtTransOffset = 62;

                    ;% QD2_DroneStack_PID_2021a_P.Constant_Value
                    section.data(14).logicalSrcIdx = 62;
                    section.data(14).dtTransOffset = 63;

                    ;% QD2_DroneStack_PID_2021a_P.Motor0_Value
                    section.data(15).logicalSrcIdx = 63;
                    section.data(15).dtTransOffset = 64;

                    ;% QD2_DroneStack_PID_2021a_P.Motor1_Value
                    section.data(16).logicalSrcIdx = 64;
                    section.data(16).dtTransOffset = 68;

                    ;% QD2_DroneStack_PID_2021a_P.Motor2_Value
                    section.data(17).logicalSrcIdx = 65;
                    section.data(17).dtTransOffset = 72;

                    ;% QD2_DroneStack_PID_2021a_P.Motor3_Value
                    section.data(18).logicalSrcIdx = 66;
                    section.data(18).dtTransOffset = 76;

                    ;% QD2_DroneStack_PID_2021a_P.Noselection_Value
                    section.data(19).logicalSrcIdx = 67;
                    section.data(19).dtTransOffset = 80;

                    ;% QD2_DroneStack_PID_2021a_P.Switch_Threshold
                    section.data(20).logicalSrcIdx = 68;
                    section.data(20).dtTransOffset = 84;

                    ;% QD2_DroneStack_PID_2021a_P.zeroreferencetorquecommands_Val
                    section.data(21).logicalSrcIdx = 69;
                    section.data(21).dtTransOffset = 85;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_OOTerminate
                    section.data(22).logicalSrcIdx = 70;
                    section.data(22).dtTransOffset = 88;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_OOExit
                    section.data(23).logicalSrcIdx = 71;
                    section.data(23).dtTransOffset = 89;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_OOStart
                    section.data(24).logicalSrcIdx = 72;
                    section.data(24).dtTransOffset = 90;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_OOEnter
                    section.data(25).logicalSrcIdx = 73;
                    section.data(25).dtTransOffset = 91;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_POFinal
                    section.data(26).logicalSrcIdx = 74;
                    section.data(26).dtTransOffset = 92;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_AIHigh
                    section.data(27).logicalSrcIdx = 75;
                    section.data(27).dtTransOffset = 93;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_AILow
                    section.data(28).logicalSrcIdx = 76;
                    section.data(28).dtTransOffset = 94;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_EIFrequency
                    section.data(29).logicalSrcIdx = 77;
                    section.data(29).dtTransOffset = 95;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_POFrequency
                    section.data(30).logicalSrcIdx = 78;
                    section.data(30).dtTransOffset = 96;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_POInitial
                    section.data(31).logicalSrcIdx = 79;
                    section.data(31).dtTransOffset = 97;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_POWatchdog
                    section.data(32).logicalSrcIdx = 80;
                    section.data(32).dtTransOffset = 98;

                    ;% QD2_DroneStack_PID_2021a_P.Memory_InitialCondition
                    section.data(33).logicalSrcIdx = 81;
                    section.data(33).dtTransOffset = 99;

                    ;% QD2_DroneStack_PID_2021a_P.Constant_Value_d
                    section.data(34).logicalSrcIdx = 82;
                    section.data(34).dtTransOffset = 100;

                    ;% QD2_DroneStack_PID_2021a_P.Memory_InitialCondition_c
                    section.data(35).logicalSrcIdx = 83;
                    section.data(35).dtTransOffset = 101;

                    ;% QD2_DroneStack_PID_2021a_P.gravityms2_Value
                    section.data(36).logicalSrcIdx = 84;
                    section.data(36).dtTransOffset = 102;

                    ;% QD2_DroneStack_PID_2021a_P.DroneWeightkg_Value
                    section.data(37).logicalSrcIdx = 85;
                    section.data(37).dtTransOffset = 103;

                    ;% QD2_DroneStack_PID_2021a_P.SaturationUpperLimitGain_Gain
                    section.data(38).logicalSrcIdx = 86;
                    section.data(38).dtTransOffset = 104;

                    ;% QD2_DroneStack_PID_2021a_P.ContinuousSigmoid_XI
                    section.data(39).logicalSrcIdx = 87;
                    section.data(39).dtTransOffset = 105;

                    ;% QD2_DroneStack_PID_2021a_P.ContinuousSigmoid_VI
                    section.data(40).logicalSrcIdx = 88;
                    section.data(40).dtTransOffset = 106;

                    ;% QD2_DroneStack_PID_2021a_P.ContinuousSigmoid_Hold
                    section.data(41).logicalSrcIdx = 89;
                    section.data(41).dtTransOffset = 107;

                    ;% QD2_DroneStack_PID_2021a_P.Memory_InitialCondition_b
                    section.data(42).logicalSrcIdx = 90;
                    section.data(42).dtTransOffset = 108;

                    ;% QD2_DroneStack_PID_2021a_P.Constant2_Value
                    section.data(43).logicalSrcIdx = 91;
                    section.data(43).dtTransOffset = 109;

                    ;% QD2_DroneStack_PID_2021a_P.Constant3_Value
                    section.data(44).logicalSrcIdx = 92;
                    section.data(44).dtTransOffset = 111;

                    ;% QD2_DroneStack_PID_2021a_P.Switch1_Threshold
                    section.data(45).logicalSrcIdx = 93;
                    section.data(45).dtTransOffset = 113;

                    ;% QD2_DroneStack_PID_2021a_P.Constant1_Value
                    section.data(46).logicalSrcIdx = 94;
                    section.data(46).dtTransOffset = 114;

                    ;% QD2_DroneStack_PID_2021a_P.Constant2_Value_a
                    section.data(47).logicalSrcIdx = 95;
                    section.data(47).dtTransOffset = 115;

                    ;% QD2_DroneStack_PID_2021a_P.Integrator1_IC
                    section.data(48).logicalSrcIdx = 96;
                    section.data(48).dtTransOffset = 131;

                    ;% QD2_DroneStack_PID_2021a_P.Constant_Value_l
                    section.data(49).logicalSrcIdx = 97;
                    section.data(49).dtTransOffset = 132;

                    ;% QD2_DroneStack_PID_2021a_P.PositionSafetyThresholdm3_Value
                    section.data(50).logicalSrcIdx = 98;
                    section.data(50).dtTransOffset = 133;

                    ;% QD2_DroneStack_PID_2021a_P.Constant1_Value_j
                    section.data(51).logicalSrcIdx = 99;
                    section.data(51).dtTransOffset = 136;

                    ;% QD2_DroneStack_PID_2021a_P.ContinuousSigmoid_XI_a
                    section.data(52).logicalSrcIdx = 100;
                    section.data(52).dtTransOffset = 137;

                    ;% QD2_DroneStack_PID_2021a_P.ContinuousSigmoid_VI_n
                    section.data(53).logicalSrcIdx = 101;
                    section.data(53).dtTransOffset = 138;

                    ;% QD2_DroneStack_PID_2021a_P.ContinuousSigmoid_Hold_d
                    section.data(54).logicalSrcIdx = 102;
                    section.data(54).dtTransOffset = 139;

                    ;% QD2_DroneStack_PID_2021a_P.ContinuousSigmoid1_XI
                    section.data(55).logicalSrcIdx = 103;
                    section.data(55).dtTransOffset = 140;

                    ;% QD2_DroneStack_PID_2021a_P.ContinuousSigmoid1_VI
                    section.data(56).logicalSrcIdx = 104;
                    section.data(56).dtTransOffset = 141;

                    ;% QD2_DroneStack_PID_2021a_P.ContinuousSigmoid1_Hold
                    section.data(57).logicalSrcIdx = 105;
                    section.data(57).dtTransOffset = 142;

                    ;% QD2_DroneStack_PID_2021a_P.ContinuousSigmoid2_XI
                    section.data(58).logicalSrcIdx = 106;
                    section.data(58).dtTransOffset = 143;

                    ;% QD2_DroneStack_PID_2021a_P.ContinuousSigmoid2_VI
                    section.data(59).logicalSrcIdx = 107;
                    section.data(59).dtTransOffset = 144;

                    ;% QD2_DroneStack_PID_2021a_P.ContinuousSigmoid2_Hold
                    section.data(60).logicalSrcIdx = 108;
                    section.data(60).dtTransOffset = 145;

                    ;% QD2_DroneStack_PID_2021a_P.ContinuousSigmoid3_XI
                    section.data(61).logicalSrcIdx = 109;
                    section.data(61).dtTransOffset = 146;

                    ;% QD2_DroneStack_PID_2021a_P.ContinuousSigmoid3_VI
                    section.data(62).logicalSrcIdx = 110;
                    section.data(62).dtTransOffset = 147;

                    ;% QD2_DroneStack_PID_2021a_P.ContinuousSigmoid3_Hold
                    section.data(63).logicalSrcIdx = 111;
                    section.data(63).dtTransOffset = 148;

                    ;% QD2_DroneStack_PID_2021a_P.Gain_Gain
                    section.data(64).logicalSrcIdx = 112;
                    section.data(64).dtTransOffset = 149;

                    ;% QD2_DroneStack_PID_2021a_P.KpradmradmNmradsrad_Gain
                    section.data(65).logicalSrcIdx = 113;
                    section.data(65).dtTransOffset = 153;

                    ;% QD2_DroneStack_PID_2021a_P.Gain_Gain_l
                    section.data(66).logicalSrcIdx = 114;
                    section.data(66).dtTransOffset = 157;

                    ;% QD2_DroneStack_PID_2021a_P.Integrator1_IC_i
                    section.data(67).logicalSrcIdx = 115;
                    section.data(67).dtTransOffset = 161;

                    ;% QD2_DroneStack_PID_2021a_P.Integrator1_UpperSat
                    section.data(68).logicalSrcIdx = 116;
                    section.data(68).dtTransOffset = 162;

                    ;% QD2_DroneStack_PID_2021a_P.Integrator1_LowerSat
                    section.data(69).logicalSrcIdx = 117;
                    section.data(69).dtTransOffset = 166;

                    ;% QD2_DroneStack_PID_2021a_P.Integrator6_IC
                    section.data(70).logicalSrcIdx = 118;
                    section.data(70).dtTransOffset = 170;

                    ;% QD2_DroneStack_PID_2021a_P.Constant1_Value_k
                    section.data(71).logicalSrcIdx = 119;
                    section.data(71).dtTransOffset = 171;

                    ;% QD2_DroneStack_PID_2021a_P.KdradmsradmsNmsradsrads_Gain
                    section.data(72).logicalSrcIdx = 120;
                    section.data(72).dtTransOffset = 172;

                    ;% QD2_DroneStack_PID_2021a_P.Gain2_Gain
                    section.data(73).logicalSrcIdx = 121;
                    section.data(73).dtTransOffset = 176;

                    ;% QD2_DroneStack_PID_2021a_P.SaturateStabilizationCommand_Up
                    section.data(74).logicalSrcIdx = 122;
                    section.data(74).dtTransOffset = 180;

                    ;% QD2_DroneStack_PID_2021a_P.SaturateStabilizationCommand_Lo
                    section.data(75).logicalSrcIdx = 123;
                    section.data(75).dtTransOffset = 184;

                    ;% QD2_DroneStack_PID_2021a_P.RateLimiterNs_RisingLim
                    section.data(76).logicalSrcIdx = 124;
                    section.data(76).dtTransOffset = 188;

                    ;% QD2_DroneStack_PID_2021a_P.RateLimiterNs_FallingLim
                    section.data(77).logicalSrcIdx = 125;
                    section.data(77).dtTransOffset = 189;

                    ;% QD2_DroneStack_PID_2021a_P.N_UpperSat
                    section.data(78).logicalSrcIdx = 126;
                    section.data(78).dtTransOffset = 190;

                    ;% QD2_DroneStack_PID_2021a_P.N_LowerSat
                    section.data(79).logicalSrcIdx = 127;
                    section.data(79).dtTransOffset = 191;

                    ;% QD2_DroneStack_PID_2021a_P.SpecifyAngleModeforStabilizerDO
                    section.data(80).logicalSrcIdx = 128;
                    section.data(80).dtTransOffset = 192;

                    ;% QD2_DroneStack_PID_2021a_P.ZeroTorqueCommand_Value
                    section.data(81).logicalSrcIdx = 129;
                    section.data(81).dtTransOffset = 193;

                    ;% QD2_DroneStack_PID_2021a_P.Switch_Threshold_l
                    section.data(82).logicalSrcIdx = 130;
                    section.data(82).dtTransOffset = 196;

                    ;% QD2_DroneStack_PID_2021a_P.NullAttitudeCommandradradrads_V
                    section.data(83).logicalSrcIdx = 131;
                    section.data(83).dtTransOffset = 197;

                    ;% QD2_DroneStack_PID_2021a_P.Switch1_Threshold_b
                    section.data(84).logicalSrcIdx = 132;
                    section.data(84).dtTransOffset = 200;

                    ;% QD2_DroneStack_PID_2021a_P.SaturateStabilizationCommand__o
                    section.data(85).logicalSrcIdx = 133;
                    section.data(85).dtTransOffset = 201;

                    ;% QD2_DroneStack_PID_2021a_P.SaturateStabilizationCommand__g
                    section.data(86).logicalSrcIdx = 134;
                    section.data(86).dtTransOffset = 204;

                    ;% QD2_DroneStack_PID_2021a_P.Gain1_Gain
                    section.data(87).logicalSrcIdx = 135;
                    section.data(87).dtTransOffset = 207;

                    ;% QD2_DroneStack_PID_2021a_P.K_p_angleradsrad_Gain
                    section.data(88).logicalSrcIdx = 136;
                    section.data(88).dtTransOffset = 210;

                    ;% QD2_DroneStack_PID_2021a_P.Scale_Gain
                    section.data(89).logicalSrcIdx = 137;
                    section.data(89).dtTransOffset = 213;

                    ;% QD2_DroneStack_PID_2021a_P.K_d_angleradsrads_Gain
                    section.data(90).logicalSrcIdx = 138;
                    section.data(90).dtTransOffset = 216;

                    ;% QD2_DroneStack_PID_2021a_P.Scale1_Gain
                    section.data(91).logicalSrcIdx = 139;
                    section.data(91).dtTransOffset = 219;

                    ;% QD2_DroneStack_PID_2021a_P.SaturationMaxRaterads_UpperSat
                    section.data(92).logicalSrcIdx = 140;
                    section.data(92).dtTransOffset = 222;

                    ;% QD2_DroneStack_PID_2021a_P.SaturationMaxRaterads_LowerSat
                    section.data(93).logicalSrcIdx = 141;
                    section.data(93).dtTransOffset = 225;

                    ;% QD2_DroneStack_PID_2021a_P.K_p_speedNmrads_Gain
                    section.data(94).logicalSrcIdx = 142;
                    section.data(94).dtTransOffset = 228;

                    ;% QD2_DroneStack_PID_2021a_P.Scale5_Gain
                    section.data(95).logicalSrcIdx = 143;
                    section.data(95).dtTransOffset = 231;

                    ;% QD2_DroneStack_PID_2021a_P.K_d_speedNmradss1_Gain
                    section.data(96).logicalSrcIdx = 144;
                    section.data(96).dtTransOffset = 234;

                    ;% QD2_DroneStack_PID_2021a_P.Scale4_Gain
                    section.data(97).logicalSrcIdx = 145;
                    section.data(97).dtTransOffset = 237;

                    ;% QD2_DroneStack_PID_2021a_P.SaturationCommandAuthorityNm1_U
                    section.data(98).logicalSrcIdx = 146;
                    section.data(98).dtTransOffset = 240;

                    ;% QD2_DroneStack_PID_2021a_P.SaturationCommandAuthorityNm1_L
                    section.data(99).logicalSrcIdx = 147;
                    section.data(99).dtTransOffset = 243;

                    ;% QD2_DroneStack_PID_2021a_P.Delay_InitialCondition
                    section.data(100).logicalSrcIdx = 148;
                    section.data(100).dtTransOffset = 246;

                    ;% QD2_DroneStack_PID_2021a_P.ZeroReferenceMotorCommands_Valu
                    section.data(101).logicalSrcIdx = 149;
                    section.data(101).dtTransOffset = 247;

                    ;% QD2_DroneStack_PID_2021a_P.MaximumCommandAuthority_UpperSa
                    section.data(102).logicalSrcIdx = 150;
                    section.data(102).dtTransOffset = 251;

                    ;% QD2_DroneStack_PID_2021a_P.MaximumCommandAuthority_LowerSa
                    section.data(103).logicalSrcIdx = 151;
                    section.data(103).dtTransOffset = 255;

                    ;% QD2_DroneStack_PID_2021a_P.Constant1_Value_c
                    section.data(104).logicalSrcIdx = 152;
                    section.data(104).dtTransOffset = 259;

                    ;% QD2_DroneStack_PID_2021a_P.Constant2_Value_e
                    section.data(105).logicalSrcIdx = 153;
                    section.data(105).dtTransOffset = 291;

                    ;% QD2_DroneStack_PID_2021a_P.RateTransition7_InitialConditio
                    section.data(106).logicalSrcIdx = 154;
                    section.data(106).dtTransOffset = 292;

                    ;% QD2_DroneStack_PID_2021a_P.RateTransition2_InitialConditio
                    section.data(107).logicalSrcIdx = 155;
                    section.data(107).dtTransOffset = 293;

                    ;% QD2_DroneStack_PID_2021a_P.RateTransition1_InitialConditio
                    section.data(108).logicalSrcIdx = 156;
                    section.data(108).dtTransOffset = 294;

                    ;% QD2_DroneStack_PID_2021a_P.Dividebyhalfofthenumberofpolesi
                    section.data(109).logicalSrcIdx = 157;
                    section.data(109).dtTransOffset = 295;

                    ;% QD2_DroneStack_PID_2021a_P.Multiplebyresolutionsupposedtob
                    section.data(110).logicalSrcIdx = 158;
                    section.data(110).dtTransOffset = 296;

                    ;% QD2_DroneStack_PID_2021a_P.Memory_InitialCondition_l
                    section.data(111).logicalSrcIdx = 159;
                    section.data(111).dtTransOffset = 297;

                    ;% QD2_DroneStack_PID_2021a_P.Converttoequivalentvoltagebased
                    section.data(112).logicalSrcIdx = 160;
                    section.data(112).dtTransOffset = 301;

                    ;% QD2_DroneStack_PID_2021a_P.Saturation_UpperSat
                    section.data(113).logicalSrcIdx = 161;
                    section.data(113).dtTransOffset = 302;

                    ;% QD2_DroneStack_PID_2021a_P.Saturation_LowerSat
                    section.data(114).logicalSrcIdx = 162;
                    section.data(114).dtTransOffset = 303;

                    ;% QD2_DroneStack_PID_2021a_P.Memory_InitialCondition_lk
                    section.data(115).logicalSrcIdx = 163;
                    section.data(115).dtTransOffset = 304;

                    ;% QD2_DroneStack_PID_2021a_P.Saturation1_UpperSat
                    section.data(116).logicalSrcIdx = 164;
                    section.data(116).dtTransOffset = 308;

                    ;% QD2_DroneStack_PID_2021a_P.Saturation1_LowerSat
                    section.data(117).logicalSrcIdx = 165;
                    section.data(117).dtTransOffset = 309;

                    ;% QD2_DroneStack_PID_2021a_P.RateTransition_InitialCondition
                    section.data(118).logicalSrcIdx = 166;
                    section.data(118).dtTransOffset = 310;

                    ;% QD2_DroneStack_PID_2021a_P.RateTransition1_InitialCondit_o
                    section.data(119).logicalSrcIdx = 167;
                    section.data(119).dtTransOffset = 311;

                    ;% QD2_DroneStack_PID_2021a_P.RateTransition2_InitialCondit_l
                    section.data(120).logicalSrcIdx = 168;
                    section.data(120).dtTransOffset = 312;

                    ;% QD2_DroneStack_PID_2021a_P.RateTransition3_InitialConditio
                    section.data(121).logicalSrcIdx = 169;
                    section.data(121).dtTransOffset = 313;

                    ;% QD2_DroneStack_PID_2021a_P.Gain_Gain_d
                    section.data(122).logicalSrcIdx = 170;
                    section.data(122).dtTransOffset = 314;

                    ;% QD2_DroneStack_PID_2021a_P.Bias1_Bias
                    section.data(123).logicalSrcIdx = 171;
                    section.data(123).dtTransOffset = 315;

                    ;% QD2_DroneStack_PID_2021a_P.Memory_InitialCondition_cr
                    section.data(124).logicalSrcIdx = 172;
                    section.data(124).dtTransOffset = 319;

                    ;% QD2_DroneStack_PID_2021a_P.Delay3_InitialCondition
                    section.data(125).logicalSrcIdx = 173;
                    section.data(125).dtTransOffset = 323;

                    ;% QD2_DroneStack_PID_2021a_P.Delay2_InitialCondition
                    section.data(126).logicalSrcIdx = 174;
                    section.data(126).dtTransOffset = 324;

                    ;% QD2_DroneStack_PID_2021a_P.Delay1_InitialCondition
                    section.data(127).logicalSrcIdx = 175;
                    section.data(127).dtTransOffset = 325;

                    ;% QD2_DroneStack_PID_2021a_P.Delay_InitialCondition_g
                    section.data(128).logicalSrcIdx = 176;
                    section.data(128).dtTransOffset = 326;

                    ;% QD2_DroneStack_PID_2021a_P.Constant_Value_k
                    section.data(129).logicalSrcIdx = 177;
                    section.data(129).dtTransOffset = 327;

                    ;% QD2_DroneStack_PID_2021a_P.ZeroYaw_Value
                    section.data(130).logicalSrcIdx = 178;
                    section.data(130).dtTransOffset = 328;

                    ;% QD2_DroneStack_PID_2021a_P.BatteryLowTimeThresholds_Value
                    section.data(131).logicalSrcIdx = 179;
                    section.data(131).dtTransOffset = 329;

                    ;% QD2_DroneStack_PID_2021a_P.Constant_Value_i
                    section.data(132).logicalSrcIdx = 180;
                    section.data(132).dtTransOffset = 330;

                    ;% QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_gainval
                    section.data(133).logicalSrcIdx = 181;
                    section.data(133).dtTransOffset = 331;

                    ;% QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC
                    section.data(134).logicalSrcIdx = 182;
                    section.data(134).dtTransOffset = 332;

                    ;% QD2_DroneStack_PID_2021a_P.Constant1_Value_p
                    section.data(135).logicalSrcIdx = 183;
                    section.data(135).dtTransOffset = 333;

                    ;% QD2_DroneStack_PID_2021a_P.Constant2_Value_d
                    section.data(136).logicalSrcIdx = 184;
                    section.data(136).dtTransOffset = 334;

                    ;% QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_gainva_f
                    section.data(137).logicalSrcIdx = 185;
                    section.data(137).dtTransOffset = 335;

                    ;% QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_b
                    section.data(138).logicalSrcIdx = 186;
                    section.data(138).dtTransOffset = 336;

                    ;% QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_gainva_p
                    section.data(139).logicalSrcIdx = 187;
                    section.data(139).dtTransOffset = 337;

                    ;% QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_g
                    section.data(140).logicalSrcIdx = 188;
                    section.data(140).dtTransOffset = 338;

                    ;% QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_gainva_g
                    section.data(141).logicalSrcIdx = 189;
                    section.data(141).dtTransOffset = 339;

                    ;% QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_e
                    section.data(142).logicalSrcIdx = 190;
                    section.data(142).dtTransOffset = 340;

                    ;% QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_gainva_e
                    section.data(143).logicalSrcIdx = 191;
                    section.data(143).dtTransOffset = 341;

                    ;% QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_n
                    section.data(144).logicalSrcIdx = 192;
                    section.data(144).dtTransOffset = 342;

                    ;% QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_gainva_o
                    section.data(145).logicalSrcIdx = 193;
                    section.data(145).dtTransOffset = 343;

                    ;% QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_m
                    section.data(146).logicalSrcIdx = 194;
                    section.data(146).dtTransOffset = 344;

                    ;% QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_gainva_d
                    section.data(147).logicalSrcIdx = 195;
                    section.data(147).dtTransOffset = 345;

                    ;% QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_f
                    section.data(148).logicalSrcIdx = 196;
                    section.data(148).dtTransOffset = 346;

                    ;% QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_gainv_el
                    section.data(149).logicalSrcIdx = 197;
                    section.data(149).dtTransOffset = 347;

                    ;% QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_h
                    section.data(150).logicalSrcIdx = 198;
                    section.data(150).dtTransOffset = 348;

                    ;% QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_gainv_f5
                    section.data(151).logicalSrcIdx = 199;
                    section.data(151).dtTransOffset = 349;

                    ;% QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_c
                    section.data(152).logicalSrcIdx = 200;
                    section.data(152).dtTransOffset = 350;

                    ;% QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_gainva_m
                    section.data(153).logicalSrcIdx = 201;
                    section.data(153).dtTransOffset = 351;

                    ;% QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_mg
                    section.data(154).logicalSrcIdx = 202;
                    section.data(154).dtTransOffset = 352;

                    ;% QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_gainva_b
                    section.data(155).logicalSrcIdx = 203;
                    section.data(155).dtTransOffset = 353;

                    ;% QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_hh
                    section.data(156).logicalSrcIdx = 204;
                    section.data(156).dtTransOffset = 354;

                    ;% QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_gainv_my
                    section.data(157).logicalSrcIdx = 205;
                    section.data(157).dtTransOffset = 355;

                    ;% QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_n2
                    section.data(158).logicalSrcIdx = 206;
                    section.data(158).dtTransOffset = 356;

                    ;% QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_gainva_a
                    section.data(159).logicalSrcIdx = 207;
                    section.data(159).dtTransOffset = 357;

                    ;% QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_m0
                    section.data(160).logicalSrcIdx = 208;
                    section.data(160).dtTransOffset = 358;

                    ;% QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_gainv_fp
                    section.data(161).logicalSrcIdx = 209;
                    section.data(161).dtTransOffset = 359;

                    ;% QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_k
                    section.data(162).logicalSrcIdx = 210;
                    section.data(162).dtTransOffset = 360;

                    ;% QD2_DroneStack_PID_2021a_P.UnitDelay_InitialCondition
                    section.data(163).logicalSrcIdx = 211;
                    section.data(163).dtTransOffset = 361;

                    ;% QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_gainv_e0
                    section.data(164).logicalSrcIdx = 212;
                    section.data(164).dtTransOffset = 362;

                    ;% QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_nh
                    section.data(165).logicalSrcIdx = 213;
                    section.data(165).dtTransOffset = 363;

                    ;% QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_gainva_i
                    section.data(166).logicalSrcIdx = 214;
                    section.data(166).dtTransOffset = 364;

                    ;% QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_fy
                    section.data(167).logicalSrcIdx = 215;
                    section.data(167).dtTransOffset = 365;

                    ;% QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_gainv_g3
                    section.data(168).logicalSrcIdx = 216;
                    section.data(168).dtTransOffset = 366;

                    ;% QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_gy
                    section.data(169).logicalSrcIdx = 217;
                    section.data(169).dtTransOffset = 367;

                    ;% QD2_DroneStack_PID_2021a_P.MAXthrottlepercentageForTrim_Va
                    section.data(170).logicalSrcIdx = 218;
                    section.data(170).dtTransOffset = 368;

                    ;% QD2_DroneStack_PID_2021a_P.MaxThrottleHQ7inch_Value
                    section.data(171).logicalSrcIdx = 219;
                    section.data(171).dtTransOffset = 369;

                    ;% QD2_DroneStack_PID_2021a_P.MAXthrottlepercentageForCMD_Val
                    section.data(172).logicalSrcIdx = 220;
                    section.data(172).dtTransOffset = 370;

                    ;% QD2_DroneStack_PID_2021a_P.MAXthrottlepercentageForCtrl_Va
                    section.data(173).logicalSrcIdx = 221;
                    section.data(173).dtTransOffset = 371;

                    ;% QD2_DroneStack_PID_2021a_P.u5ofCommandedHeight_Gain
                    section.data(174).logicalSrcIdx = 222;
                    section.data(174).dtTransOffset = 372;

                    ;% QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_gainv_e1
                    section.data(175).logicalSrcIdx = 223;
                    section.data(175).dtTransOffset = 373;

                    ;% QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_l
                    section.data(176).logicalSrcIdx = 224;
                    section.data(176).dtTransOffset = 374;

                    ;% QD2_DroneStack_PID_2021a_P.KiradsmradsmNsmradsrads_Gain
                    section.data(177).logicalSrcIdx = 225;
                    section.data(177).dtTransOffset = 375;

                    ;% QD2_DroneStack_PID_2021a_P.Gain1_Gain_h
                    section.data(178).logicalSrcIdx = 226;
                    section.data(178).dtTransOffset = 379;

                    ;% QD2_DroneStack_PID_2021a_P.Constant4_Value_m
                    section.data(179).logicalSrcIdx = 227;
                    section.data(179).dtTransOffset = 383;

                    ;% QD2_DroneStack_PID_2021a_P.Constant5_Value_h
                    section.data(180).logicalSrcIdx = 228;
                    section.data(180).dtTransOffset = 384;

                    ;% QD2_DroneStack_PID_2021a_P.Constant_Value_f
                    section.data(181).logicalSrcIdx = 229;
                    section.data(181).dtTransOffset = 385;

                    ;% QD2_DroneStack_PID_2021a_P.Integrator2_IC
                    section.data(182).logicalSrcIdx = 230;
                    section.data(182).dtTransOffset = 386;

                    ;% QD2_DroneStack_PID_2021a_P.Integrator2_IC_g
                    section.data(183).logicalSrcIdx = 231;
                    section.data(183).dtTransOffset = 387;

                    ;% QD2_DroneStack_PID_2021a_P.Integrator7_IC
                    section.data(184).logicalSrcIdx = 232;
                    section.data(184).dtTransOffset = 388;

                    ;% QD2_DroneStack_PID_2021a_P.Ki1_Gain
                    section.data(185).logicalSrcIdx = 233;
                    section.data(185).dtTransOffset = 389;

                    ;% QD2_DroneStack_PID_2021a_P.wn_Value
                    section.data(186).logicalSrcIdx = 234;
                    section.data(186).dtTransOffset = 390;

                    ;% QD2_DroneStack_PID_2021a_P.Integrator2_IC_gq
                    section.data(187).logicalSrcIdx = 235;
                    section.data(187).dtTransOffset = 391;

                    ;% QD2_DroneStack_PID_2021a_P.Ki3_Gain
                    section.data(188).logicalSrcIdx = 236;
                    section.data(188).dtTransOffset = 392;

                    ;% QD2_DroneStack_PID_2021a_P.Kp1_Gain
                    section.data(189).logicalSrcIdx = 237;
                    section.data(189).dtTransOffset = 393;

                    ;% QD2_DroneStack_PID_2021a_P.Kp3_Gain
                    section.data(190).logicalSrcIdx = 238;
                    section.data(190).dtTransOffset = 394;

                    ;% QD2_DroneStack_PID_2021a_P.Constant2_Value_f
                    section.data(191).logicalSrcIdx = 239;
                    section.data(191).dtTransOffset = 395;

                    ;% QD2_DroneStack_PID_2021a_P.Constant3_Value_c
                    section.data(192).logicalSrcIdx = 240;
                    section.data(192).dtTransOffset = 397;

                    ;% QD2_DroneStack_PID_2021a_P.Constant4_Value_c
                    section.data(193).logicalSrcIdx = 241;
                    section.data(193).dtTransOffset = 399;

                    ;% QD2_DroneStack_PID_2021a_P.Constant5_Value_j
                    section.data(194).logicalSrcIdx = 242;
                    section.data(194).dtTransOffset = 401;

                    ;% QD2_DroneStack_PID_2021a_P.Constant6_Value
                    section.data(195).logicalSrcIdx = 243;
                    section.data(195).dtTransOffset = 403;

                    ;% QD2_DroneStack_PID_2021a_P.Constant7_Value
                    section.data(196).logicalSrcIdx = 244;
                    section.data(196).dtTransOffset = 405;

                    ;% QD2_DroneStack_PID_2021a_P.Constant8_Value
                    section.data(197).logicalSrcIdx = 245;
                    section.data(197).dtTransOffset = 407;

                    ;% QD2_DroneStack_PID_2021a_P.Constant9_Value
                    section.data(198).logicalSrcIdx = 246;
                    section.data(198).dtTransOffset = 409;

                    ;% QD2_DroneStack_PID_2021a_P.Constant_Value_o
                    section.data(199).logicalSrcIdx = 247;
                    section.data(199).dtTransOffset = 411;

                    ;% QD2_DroneStack_PID_2021a_P.zt_Value
                    section.data(200).logicalSrcIdx = 248;
                    section.data(200).dtTransOffset = 412;

                    ;% QD2_DroneStack_PID_2021a_P.gravitycorrection_Bias
                    section.data(201).logicalSrcIdx = 249;
                    section.data(201).dtTransOffset = 413;

                    ;% QD2_DroneStack_PID_2021a_P.Gain_Gain_h
                    section.data(202).logicalSrcIdx = 250;
                    section.data(202).dtTransOffset = 416;

                    ;% QD2_DroneStack_PID_2021a_P.Gain_Gain_c
                    section.data(203).logicalSrcIdx = 251;
                    section.data(203).dtTransOffset = 417;

                    ;% QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_gainva_n
                    section.data(204).logicalSrcIdx = 252;
                    section.data(204).dtTransOffset = 418;

                    ;% QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_n2p
                    section.data(205).logicalSrcIdx = 253;
                    section.data(205).dtTransOffset = 419;

                    ;% QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_gainv_m3
                    section.data(206).logicalSrcIdx = 254;
                    section.data(206).dtTransOffset = 420;

                    ;% QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_j
                    section.data(207).logicalSrcIdx = 255;
                    section.data(207).dtTransOffset = 421;

                    ;% QD2_DroneStack_PID_2021a_P.HILWatchdog_Timeout
                    section.data(208).logicalSrcIdx = 256;
                    section.data(208).dtTransOffset = 422;

                    ;% QD2_DroneStack_PID_2021a_P.Memory2_InitialCondition
                    section.data(209).logicalSrcIdx = 257;
                    section.data(209).dtTransOffset = 423;

                    ;% QD2_DroneStack_PID_2021a_P.Constant_Value_b
                    section.data(210).logicalSrcIdx = 258;
                    section.data(210).dtTransOffset = 424;

                    ;% QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_gainva_c
                    section.data(211).logicalSrcIdx = 259;
                    section.data(211).dtTransOffset = 425;

                    ;% QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_e4
                    section.data(212).logicalSrcIdx = 260;
                    section.data(212).dtTransOffset = 426;

                    ;% QD2_DroneStack_PID_2021a_P.x0_Value
                    section.data(213).logicalSrcIdx = 261;
                    section.data(213).dtTransOffset = 427;

                    ;% QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator1_gainval
                    section.data(214).logicalSrcIdx = 262;
                    section.data(214).dtTransOffset = 428;

                    ;% QD2_DroneStack_PID_2021a_P.Constant_Value_j
                    section.data(215).logicalSrcIdx = 263;
                    section.data(215).dtTransOffset = 429;

                    ;% QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_gainva_j
                    section.data(216).logicalSrcIdx = 264;
                    section.data(216).dtTransOffset = 430;

                    ;% QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_gl
                    section.data(217).logicalSrcIdx = 265;
                    section.data(217).dtTransOffset = 431;

                    ;% QD2_DroneStack_PID_2021a_P.ToFFilterInitialConditionm_Valu
                    section.data(218).logicalSrcIdx = 266;
                    section.data(218).dtTransOffset = 432;

                    ;% QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator1_gainv_c
                    section.data(219).logicalSrcIdx = 267;
                    section.data(219).dtTransOffset = 433;

                    ;% QD2_DroneStack_PID_2021a_P.ToFFilterCutoffFrequencyrad_Val
                    section.data(220).logicalSrcIdx = 268;
                    section.data(220).dtTransOffset = 434;

                    ;% QD2_DroneStack_PID_2021a_P.RangingSensor_Budget
                    section.data(221).logicalSrcIdx = 269;
                    section.data(221).dtTransOffset = 435;

                    ;% QD2_DroneStack_PID_2021a_P.RangingSensor_Period
                    section.data(222).logicalSrcIdx = 270;
                    section.data(222).dtTransOffset = 436;

                    ;% QD2_DroneStack_PID_2021a_P.RangingSensor_MaxInterpolationD
                    section.data(223).logicalSrcIdx = 271;
                    section.data(223).dtTransOffset = 437;

                    ;% QD2_DroneStack_PID_2021a_P.RangingSensor_MaxInterpolationA
                    section.data(224).logicalSrcIdx = 272;
                    section.data(224).dtTransOffset = 438;

                    ;% QD2_DroneStack_PID_2021a_P.ToFFilterDampingRatio_Value
                    section.data(225).logicalSrcIdx = 273;
                    section.data(225).dtTransOffset = 439;

                    ;% QD2_DroneStack_PID_2021a_P.ToFSensorXYOffsetsm_Value
                    section.data(226).logicalSrcIdx = 274;
                    section.data(226).dtTransOffset = 440;

            nTotData = nTotData + section.nData;
            paramMap.sections(6) = section;
            clear section

            section.nData     = 13;
            section.data(13)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_DOWatchdog
                    section.data(1).logicalSrcIdx = 275;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_EIInitial
                    section.data(2).logicalSrcIdx = 276;
                    section.data(2).dtTransOffset = 6;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_POModes
                    section.data(3).logicalSrcIdx = 277;
                    section.data(3).dtTransOffset = 7;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_POConfiguration
                    section.data(4).logicalSrcIdx = 278;
                    section.data(4).dtTransOffset = 12;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_POAlignment
                    section.data(5).logicalSrcIdx = 279;
                    section.data(5).dtTransOffset = 13;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_POPolarity
                    section.data(6).logicalSrcIdx = 280;
                    section.data(6).dtTransOffset = 14;

                    ;% QD2_DroneStack_PID_2021a_P.StreamClient_SndPriority
                    section.data(7).logicalSrcIdx = 281;
                    section.data(7).dtTransOffset = 15;

                    ;% QD2_DroneStack_PID_2021a_P.StreamClient_RcvPriority
                    section.data(8).logicalSrcIdx = 282;
                    section.data(8).dtTransOffset = 16;

                    ;% QD2_DroneStack_PID_2021a_P.ToHostFile_Encoding
                    section.data(9).logicalSrcIdx = 283;
                    section.data(9).dtTransOffset = 17;

                    ;% QD2_DroneStack_PID_2021a_P.ToHostFile_Encoding_f
                    section.data(10).logicalSrcIdx = 284;
                    section.data(10).dtTransOffset = 18;

                    ;% QD2_DroneStack_PID_2021a_P.ToHostFile_Encoding_n
                    section.data(11).logicalSrcIdx = 285;
                    section.data(11).dtTransOffset = 19;

                    ;% QD2_DroneStack_PID_2021a_P.StreamServer_SndPriority
                    section.data(12).logicalSrcIdx = 286;
                    section.data(12).dtTransOffset = 20;

                    ;% QD2_DroneStack_PID_2021a_P.StreamServer_RcvPriority
                    section.data(13).logicalSrcIdx = 287;
                    section.data(13).dtTransOffset = 21;

            nTotData = nTotData + section.nData;
            paramMap.sections(7) = section;
            clear section

            section.nData     = 22;
            section.data(22)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_P.Print_MaxUnits
                    section.data(1).logicalSrcIdx = 288;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_AIChannels
                    section.data(2).logicalSrcIdx = 289;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_DIChannels
                    section.data(3).logicalSrcIdx = 290;
                    section.data(3).dtTransOffset = 5;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_DOChannels
                    section.data(4).logicalSrcIdx = 291;
                    section.data(4).dtTransOffset = 11;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_EIChannels
                    section.data(5).logicalSrcIdx = 292;
                    section.data(5).dtTransOffset = 17;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_EIQuadrature
                    section.data(6).logicalSrcIdx = 293;
                    section.data(6).dtTransOffset = 19;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_POChannels
                    section.data(7).logicalSrcIdx = 294;
                    section.data(7).dtTransOffset = 20;

                    ;% QD2_DroneStack_PID_2021a_P.StreamClient_SndSize
                    section.data(8).logicalSrcIdx = 295;
                    section.data(8).dtTransOffset = 26;

                    ;% QD2_DroneStack_PID_2021a_P.StreamClient_RcvSize
                    section.data(9).logicalSrcIdx = 296;
                    section.data(9).dtTransOffset = 27;

                    ;% QD2_DroneStack_PID_2021a_P.StreamClient_SndFIFO
                    section.data(10).logicalSrcIdx = 297;
                    section.data(10).dtTransOffset = 28;

                    ;% QD2_DroneStack_PID_2021a_P.StreamClient_RcvFIFO
                    section.data(11).logicalSrcIdx = 298;
                    section.data(11).dtTransOffset = 29;

                    ;% QD2_DroneStack_PID_2021a_P.ToHostFile_Decimation
                    section.data(12).logicalSrcIdx = 299;
                    section.data(12).dtTransOffset = 30;

                    ;% QD2_DroneStack_PID_2021a_P.ToHostFile_BitRate
                    section.data(13).logicalSrcIdx = 300;
                    section.data(13).dtTransOffset = 31;

                    ;% QD2_DroneStack_PID_2021a_P.ToHostFile_Decimation_j
                    section.data(14).logicalSrcIdx = 301;
                    section.data(14).dtTransOffset = 32;

                    ;% QD2_DroneStack_PID_2021a_P.ToHostFile_BitRate_p
                    section.data(15).logicalSrcIdx = 302;
                    section.data(15).dtTransOffset = 33;

                    ;% QD2_DroneStack_PID_2021a_P.ToHostFile_Decimation_m
                    section.data(16).logicalSrcIdx = 303;
                    section.data(16).dtTransOffset = 34;

                    ;% QD2_DroneStack_PID_2021a_P.ToHostFile_BitRate_h
                    section.data(17).logicalSrcIdx = 304;
                    section.data(17).dtTransOffset = 35;

                    ;% QD2_DroneStack_PID_2021a_P.StreamServer_SndSize
                    section.data(18).logicalSrcIdx = 305;
                    section.data(18).dtTransOffset = 36;

                    ;% QD2_DroneStack_PID_2021a_P.StreamServer_RcvSize
                    section.data(19).logicalSrcIdx = 306;
                    section.data(19).dtTransOffset = 37;

                    ;% QD2_DroneStack_PID_2021a_P.StreamServer_SndFIFO
                    section.data(20).logicalSrcIdx = 307;
                    section.data(20).dtTransOffset = 38;

                    ;% QD2_DroneStack_PID_2021a_P.StreamServer_RcvFIFO
                    section.data(21).logicalSrcIdx = 308;
                    section.data(21).dtTransOffset = 39;

                    ;% QD2_DroneStack_PID_2021a_P.RangingSensor_Range
                    section.data(22).logicalSrcIdx = 309;
                    section.data(22).dtTransOffset = 40;

            nTotData = nTotData + section.nData;
            paramMap.sections(8) = section;
            clear section

            section.nData     = 49;
            section.data(49)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_P.Print_Active
                    section.data(1).logicalSrcIdx = 310;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_PID_2021a_P.LatchedOutput_Y0
                    section.data(2).logicalSrcIdx = 311;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_DroneStack_PID_2021a_P.HILWritePWM_Active
                    section.data(3).logicalSrcIdx = 312;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_DroneStack_PID_2021a_P.Constant_Value_dj
                    section.data(4).logicalSrcIdx = 313;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_DroneStack_PID_2021a_P.Constant_Value_g
                    section.data(5).logicalSrcIdx = 314;
                    section.data(5).dtTransOffset = 4;

                    ;% QD2_DroneStack_PID_2021a_P.Constant_Value_p
                    section.data(6).logicalSrcIdx = 315;
                    section.data(6).dtTransOffset = 5;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_Active
                    section.data(7).logicalSrcIdx = 316;
                    section.data(7).dtTransOffset = 6;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_AOTerminate
                    section.data(8).logicalSrcIdx = 317;
                    section.data(8).dtTransOffset = 7;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_AOExit
                    section.data(9).logicalSrcIdx = 318;
                    section.data(9).dtTransOffset = 8;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_DOTerminate
                    section.data(10).logicalSrcIdx = 319;
                    section.data(10).dtTransOffset = 9;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_DOExit
                    section.data(11).logicalSrcIdx = 320;
                    section.data(11).dtTransOffset = 10;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_POTerminate
                    section.data(12).logicalSrcIdx = 321;
                    section.data(12).dtTransOffset = 11;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_POExit
                    section.data(13).logicalSrcIdx = 322;
                    section.data(13).dtTransOffset = 12;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_CKPStart
                    section.data(14).logicalSrcIdx = 323;
                    section.data(14).dtTransOffset = 13;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_CKPEnter
                    section.data(15).logicalSrcIdx = 324;
                    section.data(15).dtTransOffset = 14;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_CKStart
                    section.data(16).logicalSrcIdx = 325;
                    section.data(16).dtTransOffset = 15;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_CKEnter
                    section.data(17).logicalSrcIdx = 326;
                    section.data(17).dtTransOffset = 16;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_AIPStart
                    section.data(18).logicalSrcIdx = 327;
                    section.data(18).dtTransOffset = 17;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_AIPEnter
                    section.data(19).logicalSrcIdx = 328;
                    section.data(19).dtTransOffset = 18;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_AOPStart
                    section.data(20).logicalSrcIdx = 329;
                    section.data(20).dtTransOffset = 19;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_AOPEnter
                    section.data(21).logicalSrcIdx = 330;
                    section.data(21).dtTransOffset = 20;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_AOStart
                    section.data(22).logicalSrcIdx = 331;
                    section.data(22).dtTransOffset = 21;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_AOEnter
                    section.data(23).logicalSrcIdx = 332;
                    section.data(23).dtTransOffset = 22;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_AOReset
                    section.data(24).logicalSrcIdx = 333;
                    section.data(24).dtTransOffset = 23;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_DOPStart
                    section.data(25).logicalSrcIdx = 334;
                    section.data(25).dtTransOffset = 24;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_DOPEnter
                    section.data(26).logicalSrcIdx = 335;
                    section.data(26).dtTransOffset = 25;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_DOStart
                    section.data(27).logicalSrcIdx = 336;
                    section.data(27).dtTransOffset = 26;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_DOEnter
                    section.data(28).logicalSrcIdx = 337;
                    section.data(28).dtTransOffset = 27;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_DOReset
                    section.data(29).logicalSrcIdx = 338;
                    section.data(29).dtTransOffset = 28;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_EIPStart
                    section.data(30).logicalSrcIdx = 339;
                    section.data(30).dtTransOffset = 29;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_EIPEnter
                    section.data(31).logicalSrcIdx = 340;
                    section.data(31).dtTransOffset = 30;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_EIStart
                    section.data(32).logicalSrcIdx = 341;
                    section.data(32).dtTransOffset = 31;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_EIEnter
                    section.data(33).logicalSrcIdx = 342;
                    section.data(33).dtTransOffset = 32;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_POPStart
                    section.data(34).logicalSrcIdx = 343;
                    section.data(34).dtTransOffset = 33;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_POPEnter
                    section.data(35).logicalSrcIdx = 344;
                    section.data(35).dtTransOffset = 34;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_POStart
                    section.data(36).logicalSrcIdx = 345;
                    section.data(36).dtTransOffset = 35;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_POEnter
                    section.data(37).logicalSrcIdx = 346;
                    section.data(37).dtTransOffset = 36;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_POReset
                    section.data(38).logicalSrcIdx = 347;
                    section.data(38).dtTransOffset = 37;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_OOReset
                    section.data(39).logicalSrcIdx = 348;
                    section.data(39).dtTransOffset = 38;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_DOFinal
                    section.data(40).logicalSrcIdx = 349;
                    section.data(40).dtTransOffset = 39;

                    ;% QD2_DroneStack_PID_2021a_P.HILInitialize_DOInitial
                    section.data(41).logicalSrcIdx = 350;
                    section.data(41).dtTransOffset = 40;

                    ;% QD2_DroneStack_PID_2021a_P.HILRead_Active
                    section.data(42).logicalSrcIdx = 351;
                    section.data(42).dtTransOffset = 41;

                    ;% QD2_DroneStack_PID_2021a_P.StreamClient_Active
                    section.data(43).logicalSrcIdx = 352;
                    section.data(43).dtTransOffset = 42;

                    ;% QD2_DroneStack_PID_2021a_P.Memory1_InitialCondition
                    section.data(44).logicalSrcIdx = 353;
                    section.data(44).dtTransOffset = 43;

                    ;% QD2_DroneStack_PID_2021a_P.HILWriteDigital_Active
                    section.data(45).logicalSrcIdx = 354;
                    section.data(45).dtTransOffset = 44;

                    ;% QD2_DroneStack_PID_2021a_P.HILWatchdog_Active
                    section.data(46).logicalSrcIdx = 355;
                    section.data(46).dtTransOffset = 45;

                    ;% QD2_DroneStack_PID_2021a_P.Memory3_InitialCondition
                    section.data(47).logicalSrcIdx = 356;
                    section.data(47).dtTransOffset = 46;

                    ;% QD2_DroneStack_PID_2021a_P.StreamServer_Active
                    section.data(48).logicalSrcIdx = 357;
                    section.data(48).dtTransOffset = 47;

                    ;% QD2_DroneStack_PID_2021a_P.RangingSensor_Active
                    section.data(49).logicalSrcIdx = 358;
                    section.data(49).dtTransOffset = 48;

            nTotData = nTotData + section.nData;
            paramMap.sections(9) = section;
            clear section

            section.nData     = 13;
            section.data(13)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_P.StreamClient_Optimize
                    section.data(1).logicalSrcIdx = 359;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_PID_2021a_P.StreamClient_Implementation
                    section.data(2).logicalSrcIdx = 360;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_DroneStack_PID_2021a_P.ShowMessageonHost_MsgIcon
                    section.data(3).logicalSrcIdx = 361;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_DroneStack_PID_2021a_P.ShowMessageonHost1_MsgIcon
                    section.data(4).logicalSrcIdx = 362;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_DroneStack_PID_2021a_P.ShowMessageonHost2_MsgIcon
                    section.data(5).logicalSrcIdx = 363;
                    section.data(5).dtTransOffset = 4;

                    ;% QD2_DroneStack_PID_2021a_P.ShowMessageonHost3_MsgIcon
                    section.data(6).logicalSrcIdx = 364;
                    section.data(6).dtTransOffset = 5;

                    ;% QD2_DroneStack_PID_2021a_P.ShowMessageonHost4_MsgIcon
                    section.data(7).logicalSrcIdx = 365;
                    section.data(7).dtTransOffset = 6;

                    ;% QD2_DroneStack_PID_2021a_P.ShowMessageonHost5_MsgIcon
                    section.data(8).logicalSrcIdx = 366;
                    section.data(8).dtTransOffset = 7;

                    ;% QD2_DroneStack_PID_2021a_P.ShowMessageonHost6_MsgIcon
                    section.data(9).logicalSrcIdx = 367;
                    section.data(9).dtTransOffset = 8;

                    ;% QD2_DroneStack_PID_2021a_P.ShowMessageonHost7_MsgIcon
                    section.data(10).logicalSrcIdx = 368;
                    section.data(10).dtTransOffset = 9;

                    ;% QD2_DroneStack_PID_2021a_P.ShowMessageonHost8_MsgIcon
                    section.data(11).logicalSrcIdx = 369;
                    section.data(11).dtTransOffset = 10;

                    ;% QD2_DroneStack_PID_2021a_P.StreamServer_Optimize
                    section.data(12).logicalSrcIdx = 370;
                    section.data(12).dtTransOffset = 11;

                    ;% QD2_DroneStack_PID_2021a_P.StreamServer_Implementation
                    section.data(13).logicalSrcIdx = 371;
                    section.data(13).dtTransOffset = 12;

            nTotData = nTotData + section.nData;
            paramMap.sections(10) = section;
            clear section

            section.nData     = 35;
            section.data(35)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_P.StringConstant8_Value
                    section.data(1).logicalSrcIdx = 372;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_PID_2021a_P.StringConstant5_Value
                    section.data(2).logicalSrcIdx = 373;
                    section.data(2).dtTransOffset = 80;

                    ;% QD2_DroneStack_PID_2021a_P.StringConstant1_Value
                    section.data(3).logicalSrcIdx = 374;
                    section.data(3).dtTransOffset = 160;

                    ;% QD2_DroneStack_PID_2021a_P.StringConstant2_Value
                    section.data(4).logicalSrcIdx = 375;
                    section.data(4).dtTransOffset = 240;

                    ;% QD2_DroneStack_PID_2021a_P.StringConstant3_Value
                    section.data(5).logicalSrcIdx = 376;
                    section.data(5).dtTransOffset = 320;

                    ;% QD2_DroneStack_PID_2021a_P.StringConstant6_Value
                    section.data(6).logicalSrcIdx = 377;
                    section.data(6).dtTransOffset = 400;

                    ;% QD2_DroneStack_PID_2021a_P.StringConstant9_Value
                    section.data(7).logicalSrcIdx = 378;
                    section.data(7).dtTransOffset = 480;

                    ;% QD2_DroneStack_PID_2021a_P.StringConstant4_Value
                    section.data(8).logicalSrcIdx = 379;
                    section.data(8).dtTransOffset = 560;

                    ;% QD2_DroneStack_PID_2021a_P.StringConstant7_Value
                    section.data(9).logicalSrcIdx = 380;
                    section.data(9).dtTransOffset = 640;

                    ;% QD2_DroneStack_PID_2021a_P.StreamClient_URI
                    section.data(10).logicalSrcIdx = 381;
                    section.data(10).dtTransOffset = 720;

                    ;% QD2_DroneStack_PID_2021a_P.StreamClient_Endian
                    section.data(11).logicalSrcIdx = 382;
                    section.data(11).dtTransOffset = 721;

                    ;% QD2_DroneStack_PID_2021a_P.ManualSwitchSelectCommandInput_
                    section.data(12).logicalSrcIdx = 383;
                    section.data(12).dtTransOffset = 722;

                    ;% QD2_DroneStack_PID_2021a_P.ToHostFile_VarName
                    section.data(13).logicalSrcIdx = 384;
                    section.data(13).dtTransOffset = 723;

                    ;% QD2_DroneStack_PID_2021a_P.ToHostFile_FileFormat
                    section.data(14).logicalSrcIdx = 385;
                    section.data(14).dtTransOffset = 732;

                    ;% QD2_DroneStack_PID_2021a_P.ToHostFile_file_name
                    section.data(15).logicalSrcIdx = 386;
                    section.data(15).dtTransOffset = 733;

                    ;% QD2_DroneStack_PID_2021a_P.ToHostFile_VarName_l
                    section.data(16).logicalSrcIdx = 387;
                    section.data(16).dtTransOffset = 802;

                    ;% QD2_DroneStack_PID_2021a_P.ToHostFile_FileFormat_n
                    section.data(17).logicalSrcIdx = 388;
                    section.data(17).dtTransOffset = 817;

                    ;% QD2_DroneStack_PID_2021a_P.ToHostFile_file_name_h
                    section.data(18).logicalSrcIdx = 389;
                    section.data(18).dtTransOffset = 818;

                    ;% QD2_DroneStack_PID_2021a_P.StringConstant16_Value
                    section.data(19).logicalSrcIdx = 390;
                    section.data(19).dtTransOffset = 893;

                    ;% QD2_DroneStack_PID_2021a_P.StringConstant12_Value
                    section.data(20).logicalSrcIdx = 391;
                    section.data(20).dtTransOffset = 973;

                    ;% QD2_DroneStack_PID_2021a_P.StringConstant13_Value
                    section.data(21).logicalSrcIdx = 392;
                    section.data(21).dtTransOffset = 1053;

                    ;% QD2_DroneStack_PID_2021a_P.StringConstant_Value
                    section.data(22).logicalSrcIdx = 393;
                    section.data(22).dtTransOffset = 1133;

                    ;% QD2_DroneStack_PID_2021a_P.StringConstant1_Value_g
                    section.data(23).logicalSrcIdx = 394;
                    section.data(23).dtTransOffset = 1213;

                    ;% QD2_DroneStack_PID_2021a_P.StringConstant2_Value_k
                    section.data(24).logicalSrcIdx = 395;
                    section.data(24).dtTransOffset = 1293;

                    ;% QD2_DroneStack_PID_2021a_P.StringConstant3_Value_i
                    section.data(25).logicalSrcIdx = 396;
                    section.data(25).dtTransOffset = 1373;

                    ;% QD2_DroneStack_PID_2021a_P.StringConstant8_Value_b
                    section.data(26).logicalSrcIdx = 397;
                    section.data(26).dtTransOffset = 1453;

                    ;% QD2_DroneStack_PID_2021a_P.StringConstant4_Value_i
                    section.data(27).logicalSrcIdx = 398;
                    section.data(27).dtTransOffset = 1533;

                    ;% QD2_DroneStack_PID_2021a_P.StringConstant5_Value_n
                    section.data(28).logicalSrcIdx = 399;
                    section.data(28).dtTransOffset = 1613;

                    ;% QD2_DroneStack_PID_2021a_P.StringConstant6_Value_k
                    section.data(29).logicalSrcIdx = 400;
                    section.data(29).dtTransOffset = 1693;

                    ;% QD2_DroneStack_PID_2021a_P.StringConstant7_Value_d
                    section.data(30).logicalSrcIdx = 401;
                    section.data(30).dtTransOffset = 1773;

                    ;% QD2_DroneStack_PID_2021a_P.ToHostFile_VarName_g
                    section.data(31).logicalSrcIdx = 402;
                    section.data(31).dtTransOffset = 1853;

                    ;% QD2_DroneStack_PID_2021a_P.ToHostFile_FileFormat_a
                    section.data(32).logicalSrcIdx = 403;
                    section.data(32).dtTransOffset = 1869;

                    ;% QD2_DroneStack_PID_2021a_P.ToHostFile_file_name_j
                    section.data(33).logicalSrcIdx = 404;
                    section.data(33).dtTransOffset = 1870;

                    ;% QD2_DroneStack_PID_2021a_P.StreamServer_URI
                    section.data(34).logicalSrcIdx = 405;
                    section.data(34).dtTransOffset = 1946;

                    ;% QD2_DroneStack_PID_2021a_P.StreamServer_Endian
                    section.data(35).logicalSrcIdx = 406;
                    section.data(35).dtTransOffset = 1982;

            nTotData = nTotData + section.nData;
            paramMap.sections(11) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_P.CoreSubsys_pna.CompareToConstant_const
                    section.data(1).logicalSrcIdx = 407;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(12) = section;
            clear section

            section.nData     = 13;
            section.data(13)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.AccelerometerFilterCutoffFreque
                    section.data(1).logicalSrcIdx = 408;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.AccelerometerFilterDampingRatio
                    section.data(2).logicalSrcIdx = 409;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.Integrator1_IC
                    section.data(3).logicalSrcIdx = 410;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.Gain_Gain
                    section.data(4).logicalSrcIdx = 411;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.Gain1_Gain
                    section.data(5).logicalSrcIdx = 412;
                    section.data(5).dtTransOffset = 5;

                    ;% QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.GyroFilterCutoffFrequencyrads_V
                    section.data(6).logicalSrcIdx = 413;
                    section.data(6).dtTransOffset = 7;

                    ;% QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.GyroFilterDampingRatio_Value
                    section.data(7).logicalSrcIdx = 414;
                    section.data(7).dtTransOffset = 8;

                    ;% QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.Integrator2_IC
                    section.data(8).logicalSrcIdx = 415;
                    section.data(8).dtTransOffset = 9;

                    ;% QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.Integrator2_IC_n
                    section.data(9).logicalSrcIdx = 416;
                    section.data(9).dtTransOffset = 10;

                    ;% QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.Integrator_IC
                    section.data(10).logicalSrcIdx = 417;
                    section.data(10).dtTransOffset = 11;

                    ;% QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.Constant_Value
                    section.data(11).logicalSrcIdx = 418;
                    section.data(11).dtTransOffset = 12;

                    ;% QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.Constant_Value_p
                    section.data(12).logicalSrcIdx = 419;
                    section.data(12).dtTransOffset = 13;

                    ;% QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.Integrator2_IC_o
                    section.data(13).logicalSrcIdx = 420;
                    section.data(13).dtTransOffset = 14;

            nTotData = nTotData + section.nData;
            paramMap.sections(13) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_P.UsedesiredYwhenenabled.Out1_Y0
                    section.data(1).logicalSrcIdx = 421;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(14) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_P.UsedesiredXwhenenabled.Out1_Y0
                    section.data(1).logicalSrcIdx = 422;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(15) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_P.Usedesyawwhenenabled.Out1_Y0
                    section.data(1).logicalSrcIdx = 423;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(16) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_P.Usedesheightwhenenabled.Out1_Y0
                    section.data(1).logicalSrcIdx = 424;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(17) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_P.Usedesiredheightwhenenabled_c.Out1_Y0
                    section.data(1).logicalSrcIdx = 425;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(18) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_P.CoreSubsys_p.Print_MaxUnits
                    section.data(1).logicalSrcIdx = 426;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(19) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_P.CoreSubsys_p.Print_Active
                    section.data(1).logicalSrcIdx = 427;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(20) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_P.CoreSubsys.Print_MaxUnits
                    section.data(1).logicalSrcIdx = 428;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(21) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_P.CoreSubsys.Print_Active
                    section.data(1).logicalSrcIdx = 429;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(22) = section;
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
        nTotSects     = 12;
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
        ;% Auto data (QD2_DroneStack_PID_2021a_B)
        ;%
            section.nData     = 165;
            section.data(165)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_B.HILRead_o1
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_PID_2021a_B.HILRead_o2
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 3;

                    ;% QD2_DroneStack_PID_2021a_B.StreamClient_o4
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 26;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion1
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 42;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 43;

                    ;% QD2_DroneStack_PID_2021a_B.Product
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 44;

                    ;% QD2_DroneStack_PID_2021a_B.ContinuousSigmoid_o1
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 45;

                    ;% QD2_DroneStack_PID_2021a_B.ContinuousSigmoid_o2
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 46;

                    ;% QD2_DroneStack_PID_2021a_B.ContinuousSigmoid_o3
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 47;

                    ;% QD2_DroneStack_PID_2021a_B.ContinuousSigmoid_o4
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 48;

                    ;% QD2_DroneStack_PID_2021a_B.Memory
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 49;

                    ;% QD2_DroneStack_PID_2021a_B.Switch2
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 50;

                    ;% QD2_DroneStack_PID_2021a_B.Integrator1
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 51;

                    ;% QD2_DroneStack_PID_2021a_B.IFtoHRrotationmatrix
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 52;

                    ;% QD2_DroneStack_PID_2021a_B.ContinuousSigmoid_o1_a
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 61;

                    ;% QD2_DroneStack_PID_2021a_B.ContinuousSigmoid_o2_l
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 62;

                    ;% QD2_DroneStack_PID_2021a_B.ContinuousSigmoid_o3_b
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 63;

                    ;% QD2_DroneStack_PID_2021a_B.ContinuousSigmoid_o4_m
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 64;

                    ;% QD2_DroneStack_PID_2021a_B.ContinuousSigmoid1_o1
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 65;

                    ;% QD2_DroneStack_PID_2021a_B.ContinuousSigmoid1_o2
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 66;

                    ;% QD2_DroneStack_PID_2021a_B.ContinuousSigmoid1_o3
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 67;

                    ;% QD2_DroneStack_PID_2021a_B.ContinuousSigmoid1_o4
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 68;

                    ;% QD2_DroneStack_PID_2021a_B.ContinuousSigmoid2_o1
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 69;

                    ;% QD2_DroneStack_PID_2021a_B.ContinuousSigmoid2_o2
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 70;

                    ;% QD2_DroneStack_PID_2021a_B.ContinuousSigmoid2_o3
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 71;

                    ;% QD2_DroneStack_PID_2021a_B.ContinuousSigmoid2_o4
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 72;

                    ;% QD2_DroneStack_PID_2021a_B.ContinuousSigmoid3_o1
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 73;

                    ;% QD2_DroneStack_PID_2021a_B.ContinuousSigmoid3_o2
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 74;

                    ;% QD2_DroneStack_PID_2021a_B.ContinuousSigmoid3_o3
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 75;

                    ;% QD2_DroneStack_PID_2021a_B.ContinuousSigmoid3_o4
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 76;

                    ;% QD2_DroneStack_PID_2021a_B.Switch2_m
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 77;

                    ;% QD2_DroneStack_PID_2021a_B.Gain
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 81;

                    ;% QD2_DroneStack_PID_2021a_B.SelectDataforIMU1
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 85;

                    ;% QD2_DroneStack_PID_2021a_B.SelectDataforIMU0
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 94;

                    ;% QD2_DroneStack_PID_2021a_B.Product3
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 103;

                    ;% QD2_DroneStack_PID_2021a_B.Product4
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 112;

                    ;% QD2_DroneStack_PID_2021a_B.Product1
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 118;

                    ;% QD2_DroneStack_PID_2021a_B.UnsaturatedControllerCommandsNr
                    section.data(38).logicalSrcIdx = 37;
                    section.data(38).dtTransOffset = 121;

                    ;% QD2_DroneStack_PID_2021a_B.Integrator1_o
                    section.data(39).logicalSrcIdx = 38;
                    section.data(39).dtTransOffset = 125;

                    ;% QD2_DroneStack_PID_2021a_B.GeneralizedCommandNradradrads4
                    section.data(40).logicalSrcIdx = 39;
                    section.data(40).dtTransOffset = 127;

                    ;% QD2_DroneStack_PID_2021a_B.RateLimiterNs
                    section.data(41).logicalSrcIdx = 40;
                    section.data(41).dtTransOffset = 131;

                    ;% QD2_DroneStack_PID_2021a_B.NetThrottle
                    section.data(42).logicalSrcIdx = 41;
                    section.data(42).dtTransOffset = 132;

                    ;% QD2_DroneStack_PID_2021a_B.SpecifyAngleModeforStabilizerDO
                    section.data(43).logicalSrcIdx = 42;
                    section.data(43).dtTransOffset = 133;

                    ;% QD2_DroneStack_PID_2021a_B.AttitudeTorqueCommands
                    section.data(44).logicalSrcIdx = 43;
                    section.data(44).dtTransOffset = 134;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion_k
                    section.data(45).logicalSrcIdx = 44;
                    section.data(45).dtTransOffset = 137;

                    ;% QD2_DroneStack_PID_2021a_B.AttitudeAngleCommands
                    section.data(46).logicalSrcIdx = 45;
                    section.data(46).dtTransOffset = 138;

                    ;% QD2_DroneStack_PID_2021a_B.Sum6
                    section.data(47).logicalSrcIdx = 46;
                    section.data(47).dtTransOffset = 141;

                    ;% QD2_DroneStack_PID_2021a_B.SaturationCommandAuthorityNm1
                    section.data(48).logicalSrcIdx = 47;
                    section.data(48).dtTransOffset = 144;

                    ;% QD2_DroneStack_PID_2021a_B.Delay
                    section.data(49).logicalSrcIdx = 48;
                    section.data(49).dtTransOffset = 147;

                    ;% QD2_DroneStack_PID_2021a_B.MaximumCommandAuthority
                    section.data(50).logicalSrcIdx = 49;
                    section.data(50).dtTransOffset = 148;

                    ;% QD2_DroneStack_PID_2021a_B.Selector
                    section.data(51).logicalSrcIdx = 50;
                    section.data(51).dtTransOffset = 152;

                    ;% QD2_DroneStack_PID_2021a_B.RateTransition7
                    section.data(52).logicalSrcIdx = 51;
                    section.data(52).dtTransOffset = 156;

                    ;% QD2_DroneStack_PID_2021a_B.RateTransition2
                    section.data(53).logicalSrcIdx = 52;
                    section.data(53).dtTransOffset = 158;

                    ;% QD2_DroneStack_PID_2021a_B.RateTransition1
                    section.data(54).logicalSrcIdx = 53;
                    section.data(54).dtTransOffset = 159;

                    ;% QD2_DroneStack_PID_2021a_B.ExtractESCChannels
                    section.data(55).logicalSrcIdx = 54;
                    section.data(55).dtTransOffset = 160;

                    ;% QD2_DroneStack_PID_2021a_B.ComputationTime
                    section.data(56).logicalSrcIdx = 55;
                    section.data(56).dtTransOffset = 164;

                    ;% QD2_DroneStack_PID_2021a_B.SampleTime
                    section.data(57).logicalSrcIdx = 56;
                    section.data(57).dtTransOffset = 165;

                    ;% QD2_DroneStack_PID_2021a_B.RateTransition
                    section.data(58).logicalSrcIdx = 57;
                    section.data(58).dtTransOffset = 166;

                    ;% QD2_DroneStack_PID_2021a_B.RateTransition1_n
                    section.data(59).logicalSrcIdx = 58;
                    section.data(59).dtTransOffset = 167;

                    ;% QD2_DroneStack_PID_2021a_B.RateTransition2_m
                    section.data(60).logicalSrcIdx = 59;
                    section.data(60).dtTransOffset = 168;

                    ;% QD2_DroneStack_PID_2021a_B.RateTransition3
                    section.data(61).logicalSrcIdx = 60;
                    section.data(61).dtTransOffset = 169;

                    ;% QD2_DroneStack_PID_2021a_B.RateTransition6
                    section.data(62).logicalSrcIdx = 61;
                    section.data(62).dtTransOffset = 170;

                    ;% QD2_DroneStack_PID_2021a_B.Bias1
                    section.data(63).logicalSrcIdx = 62;
                    section.data(63).dtTransOffset = 230;

                    ;% QD2_DroneStack_PID_2021a_B.Delay3
                    section.data(64).logicalSrcIdx = 63;
                    section.data(64).dtTransOffset = 234;

                    ;% QD2_DroneStack_PID_2021a_B.Delay2
                    section.data(65).logicalSrcIdx = 64;
                    section.data(65).dtTransOffset = 235;

                    ;% QD2_DroneStack_PID_2021a_B.Delay1
                    section.data(66).logicalSrcIdx = 65;
                    section.data(66).dtTransOffset = 236;

                    ;% QD2_DroneStack_PID_2021a_B.Delay_n
                    section.data(67).logicalSrcIdx = 66;
                    section.data(67).dtTransOffset = 237;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion_n
                    section.data(68).logicalSrcIdx = 67;
                    section.data(68).dtTransOffset = 238;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion_o
                    section.data(69).logicalSrcIdx = 68;
                    section.data(69).dtTransOffset = 239;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion_a
                    section.data(70).logicalSrcIdx = 69;
                    section.data(70).dtTransOffset = 240;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion_ai
                    section.data(71).logicalSrcIdx = 70;
                    section.data(71).dtTransOffset = 241;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion_d
                    section.data(72).logicalSrcIdx = 71;
                    section.data(72).dtTransOffset = 242;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion_a2
                    section.data(73).logicalSrcIdx = 72;
                    section.data(73).dtTransOffset = 243;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion_p
                    section.data(74).logicalSrcIdx = 73;
                    section.data(74).dtTransOffset = 244;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion_b
                    section.data(75).logicalSrcIdx = 74;
                    section.data(75).dtTransOffset = 245;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion_nn
                    section.data(76).logicalSrcIdx = 75;
                    section.data(76).dtTransOffset = 246;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion_h
                    section.data(77).logicalSrcIdx = 76;
                    section.data(77).dtTransOffset = 247;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion_l
                    section.data(78).logicalSrcIdx = 77;
                    section.data(78).dtTransOffset = 248;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion_df
                    section.data(79).logicalSrcIdx = 78;
                    section.data(79).dtTransOffset = 249;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion_hb
                    section.data(80).logicalSrcIdx = 79;
                    section.data(80).dtTransOffset = 250;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion_e
                    section.data(81).logicalSrcIdx = 80;
                    section.data(81).dtTransOffset = 251;

                    ;% QD2_DroneStack_PID_2021a_B.UnitDelay
                    section.data(82).logicalSrcIdx = 81;
                    section.data(82).dtTransOffset = 252;

                    ;% QD2_DroneStack_PID_2021a_B.Clock1
                    section.data(83).logicalSrcIdx = 82;
                    section.data(83).dtTransOffset = 253;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion4
                    section.data(84).logicalSrcIdx = 83;
                    section.data(84).dtTransOffset = 254;

                    ;% QD2_DroneStack_PID_2021a_B.Abs
                    section.data(85).logicalSrcIdx = 84;
                    section.data(85).dtTransOffset = 255;

                    ;% QD2_DroneStack_PID_2021a_B.Abs1
                    section.data(86).logicalSrcIdx = 85;
                    section.data(86).dtTransOffset = 256;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion3
                    section.data(87).logicalSrcIdx = 86;
                    section.data(87).dtTransOffset = 257;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion12
                    section.data(88).logicalSrcIdx = 87;
                    section.data(88).dtTransOffset = 258;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion11
                    section.data(89).logicalSrcIdx = 88;
                    section.data(89).dtTransOffset = 259;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion10
                    section.data(90).logicalSrcIdx = 89;
                    section.data(90).dtTransOffset = 260;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion2
                    section.data(91).logicalSrcIdx = 90;
                    section.data(91).dtTransOffset = 261;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion6
                    section.data(92).logicalSrcIdx = 91;
                    section.data(92).dtTransOffset = 262;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion4_a
                    section.data(93).logicalSrcIdx = 92;
                    section.data(93).dtTransOffset = 279;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion2_l
                    section.data(94).logicalSrcIdx = 93;
                    section.data(94).dtTransOffset = 280;

                    ;% QD2_DroneStack_PID_2021a_B.TmpSignalConversionAtToHostFile
                    section.data(95).logicalSrcIdx = 94;
                    section.data(95).dtTransOffset = 281;

                    ;% QD2_DroneStack_PID_2021a_B.Gain1
                    section.data(96).logicalSrcIdx = 95;
                    section.data(96).dtTransOffset = 317;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion9
                    section.data(97).logicalSrcIdx = 96;
                    section.data(97).dtTransOffset = 321;

                    ;% QD2_DroneStack_PID_2021a_B.SensorIssue
                    section.data(98).logicalSrcIdx = 97;
                    section.data(98).dtTransOffset = 325;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion_e3
                    section.data(99).logicalSrcIdx = 98;
                    section.data(99).dtTransOffset = 326;

                    ;% QD2_DroneStack_PID_2021a_B.Product_i
                    section.data(100).logicalSrcIdx = 99;
                    section.data(100).dtTransOffset = 327;

                    ;% QD2_DroneStack_PID_2021a_B.Product1_m
                    section.data(101).logicalSrcIdx = 100;
                    section.data(101).dtTransOffset = 329;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion_i
                    section.data(102).logicalSrcIdx = 101;
                    section.data(102).dtTransOffset = 331;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion_ni
                    section.data(103).logicalSrcIdx = 102;
                    section.data(103).dtTransOffset = 332;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion_l2
                    section.data(104).logicalSrcIdx = 103;
                    section.data(104).dtTransOffset = 333;

                    ;% QD2_DroneStack_PID_2021a_B.Ki1
                    section.data(105).logicalSrcIdx = 104;
                    section.data(105).dtTransOffset = 334;

                    ;% QD2_DroneStack_PID_2021a_B.Product1_j
                    section.data(106).logicalSrcIdx = 105;
                    section.data(106).dtTransOffset = 335;

                    ;% QD2_DroneStack_PID_2021a_B.Ki3
                    section.data(107).logicalSrcIdx = 106;
                    section.data(107).dtTransOffset = 338;

                    ;% QD2_DroneStack_PID_2021a_B.Product_b
                    section.data(108).logicalSrcIdx = 107;
                    section.data(108).dtTransOffset = 341;

                    ;% QD2_DroneStack_PID_2021a_B.Sum2
                    section.data(109).logicalSrcIdx = 108;
                    section.data(109).dtTransOffset = 344;

                    ;% QD2_DroneStack_PID_2021a_B.IFAccelerometerdatamss3
                    section.data(110).logicalSrcIdx = 109;
                    section.data(110).dtTransOffset = 345;

                    ;% QD2_DroneStack_PID_2021a_B.Sum9
                    section.data(111).logicalSrcIdx = 110;
                    section.data(111).dtTransOffset = 348;

                    ;% QD2_DroneStack_PID_2021a_B.Gain_f
                    section.data(112).logicalSrcIdx = 111;
                    section.data(112).dtTransOffset = 351;

                    ;% QD2_DroneStack_PID_2021a_B.Gain_k
                    section.data(113).logicalSrcIdx = 112;
                    section.data(113).dtTransOffset = 357;

                    ;% QD2_DroneStack_PID_2021a_B.SampleTime_d
                    section.data(114).logicalSrcIdx = 113;
                    section.data(114).dtTransOffset = 363;

                    ;% QD2_DroneStack_PID_2021a_B.ComputationTime_l
                    section.data(115).logicalSrcIdx = 114;
                    section.data(115).dtTransOffset = 364;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion4_f
                    section.data(116).logicalSrcIdx = 115;
                    section.data(116).dtTransOffset = 365;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion1_i
                    section.data(117).logicalSrcIdx = 116;
                    section.data(117).dtTransOffset = 366;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion5
                    section.data(118).logicalSrcIdx = 117;
                    section.data(118).dtTransOffset = 367;

                    ;% QD2_DroneStack_PID_2021a_B.TmpSignalConversionAtToHostFi_a
                    section.data(119).logicalSrcIdx = 118;
                    section.data(119).dtTransOffset = 368;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion_m
                    section.data(120).logicalSrcIdx = 119;
                    section.data(120).dtTransOffset = 388;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion_ah
                    section.data(121).logicalSrcIdx = 120;
                    section.data(121).dtTransOffset = 389;

                    ;% QD2_DroneStack_PID_2021a_B.StreamServer_o4
                    section.data(122).logicalSrcIdx = 121;
                    section.data(122).dtTransOffset = 390;

                    ;% QD2_DroneStack_PID_2021a_B.RateTransition_p
                    section.data(123).logicalSrcIdx = 122;
                    section.data(123).dtTransOffset = 391;

                    ;% QD2_DroneStack_PID_2021a_B.x0
                    section.data(124).logicalSrcIdx = 123;
                    section.data(124).dtTransOffset = 398;

                    ;% QD2_DroneStack_PID_2021a_B.Product_j
                    section.data(125).logicalSrcIdx = 124;
                    section.data(125).dtTransOffset = 399;

                    ;% QD2_DroneStack_PID_2021a_B.Product1_d
                    section.data(126).logicalSrcIdx = 125;
                    section.data(126).dtTransOffset = 401;

                    ;% QD2_DroneStack_PID_2021a_B.ToFFilterInitialConditionm
                    section.data(127).logicalSrcIdx = 126;
                    section.data(127).dtTransOffset = 403;

                    ;% QD2_DroneStack_PID_2021a_B.RangingSensor_o1
                    section.data(128).logicalSrcIdx = 127;
                    section.data(128).dtTransOffset = 404;

                    ;% QD2_DroneStack_PID_2021a_B.RangingSensor_o2
                    section.data(129).logicalSrcIdx = 128;
                    section.data(129).dtTransOffset = 405;

                    ;% QD2_DroneStack_PID_2021a_B.RangingSensor_o3
                    section.data(130).logicalSrcIdx = 129;
                    section.data(130).dtTransOffset = 406;

                    ;% QD2_DroneStack_PID_2021a_B.RangingSensor_o4
                    section.data(131).logicalSrcIdx = 130;
                    section.data(131).dtTransOffset = 407;

                    ;% QD2_DroneStack_PID_2021a_B.Product_g
                    section.data(132).logicalSrcIdx = 131;
                    section.data(132).dtTransOffset = 408;

                    ;% QD2_DroneStack_PID_2021a_B.Product1_g
                    section.data(133).logicalSrcIdx = 132;
                    section.data(133).dtTransOffset = 409;

                    ;% QD2_DroneStack_PID_2021a_B.OutportBufferForOut1
                    section.data(134).logicalSrcIdx = 133;
                    section.data(134).dtTransOffset = 410;

                    ;% QD2_DroneStack_PID_2021a_B.cmd
                    section.data(135).logicalSrcIdx = 134;
                    section.data(135).dtTransOffset = 411;

                    ;% QD2_DroneStack_PID_2021a_B.cmd_enable
                    section.data(136).logicalSrcIdx = 135;
                    section.data(136).dtTransOffset = 415;

                    ;% QD2_DroneStack_PID_2021a_B.tele_enable
                    section.data(137).logicalSrcIdx = 136;
                    section.data(137).dtTransOffset = 416;

                    ;% QD2_DroneStack_PID_2021a_B.esc_ready
                    section.data(138).logicalSrcIdx = 137;
                    section.data(138).dtTransOffset = 417;

                    ;% QD2_DroneStack_PID_2021a_B.esc_timeout
                    section.data(139).logicalSrcIdx = 138;
                    section.data(139).dtTransOffset = 418;

                    ;% QD2_DroneStack_PID_2021a_B.state
                    section.data(140).logicalSrcIdx = 140;
                    section.data(140).dtTransOffset = 419;

                    ;% QD2_DroneStack_PID_2021a_B.n
                    section.data(141).logicalSrcIdx = 142;
                    section.data(141).dtTransOffset = 420;

                    ;% QD2_DroneStack_PID_2021a_B.ImpAsg_InsertedFor_ESCDataOut4_
                    section.data(142).logicalSrcIdx = 143;
                    section.data(142).dtTransOffset = 424;

                    ;% QD2_DroneStack_PID_2021a_B.ImpAsg_InsertedFor_ESCDataOut_k
                    section.data(143).logicalSrcIdx = 144;
                    section.data(143).dtTransOffset = 428;

                    ;% QD2_DroneStack_PID_2021a_B.ImpAsg_InsertedFor_ESCDataOu_kc
                    section.data(144).logicalSrcIdx = 145;
                    section.data(144).dtTransOffset = 432;

                    ;% QD2_DroneStack_PID_2021a_B.enable
                    section.data(145).logicalSrcIdx = 148;
                    section.data(145).dtTransOffset = 436;

                    ;% QD2_DroneStack_PID_2021a_B.yaw_ref
                    section.data(146).logicalSrcIdx = 149;
                    section.data(146).dtTransOffset = 437;

                    ;% QD2_DroneStack_PID_2021a_B.max_yaw_vel
                    section.data(147).logicalSrcIdx = 150;
                    section.data(147).dtTransOffset = 438;

                    ;% QD2_DroneStack_PID_2021a_B.max_yaw_accel
                    section.data(148).logicalSrcIdx = 151;
                    section.data(148).dtTransOffset = 439;

                    ;% QD2_DroneStack_PID_2021a_B.enable_c
                    section.data(149).logicalSrcIdx = 152;
                    section.data(149).dtTransOffset = 440;

                    ;% QD2_DroneStack_PID_2021a_B.height_ref
                    section.data(150).logicalSrcIdx = 153;
                    section.data(150).dtTransOffset = 441;

                    ;% QD2_DroneStack_PID_2021a_B.max_height_vel
                    section.data(151).logicalSrcIdx = 154;
                    section.data(151).dtTransOffset = 442;

                    ;% QD2_DroneStack_PID_2021a_B.max_height_accel
                    section.data(152).logicalSrcIdx = 155;
                    section.data(152).dtTransOffset = 443;

                    ;% QD2_DroneStack_PID_2021a_B.enable_n
                    section.data(153).logicalSrcIdx = 156;
                    section.data(153).dtTransOffset = 444;

                    ;% QD2_DroneStack_PID_2021a_B.y_ref
                    section.data(154).logicalSrcIdx = 157;
                    section.data(154).dtTransOffset = 445;

                    ;% QD2_DroneStack_PID_2021a_B.max_y_vel
                    section.data(155).logicalSrcIdx = 158;
                    section.data(155).dtTransOffset = 446;

                    ;% QD2_DroneStack_PID_2021a_B.max_y_accel
                    section.data(156).logicalSrcIdx = 159;
                    section.data(156).dtTransOffset = 447;

                    ;% QD2_DroneStack_PID_2021a_B.enable_k
                    section.data(157).logicalSrcIdx = 160;
                    section.data(157).dtTransOffset = 448;

                    ;% QD2_DroneStack_PID_2021a_B.x_ref
                    section.data(158).logicalSrcIdx = 161;
                    section.data(158).dtTransOffset = 449;

                    ;% QD2_DroneStack_PID_2021a_B.max_x_vel
                    section.data(159).logicalSrcIdx = 162;
                    section.data(159).dtTransOffset = 450;

                    ;% QD2_DroneStack_PID_2021a_B.max_x_accel
                    section.data(160).logicalSrcIdx = 163;
                    section.data(160).dtTransOffset = 451;

                    ;% QD2_DroneStack_PID_2021a_B.enable_d
                    section.data(161).logicalSrcIdx = 167;
                    section.data(161).dtTransOffset = 452;

                    ;% QD2_DroneStack_PID_2021a_B.throttle_ref
                    section.data(162).logicalSrcIdx = 168;
                    section.data(162).dtTransOffset = 453;

                    ;% QD2_DroneStack_PID_2021a_B.max_throttle_vel
                    section.data(163).logicalSrcIdx = 169;
                    section.data(163).dtTransOffset = 454;

                    ;% QD2_DroneStack_PID_2021a_B.max_throttle_accel
                    section.data(164).logicalSrcIdx = 170;
                    section.data(164).dtTransOffset = 455;

                    ;% QD2_DroneStack_PID_2021a_B.Next_state
                    section.data(165).logicalSrcIdx = 171;
                    section.data(165).dtTransOffset = 456;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_B.RateTransition14
                    section.data(1).logicalSrcIdx = 174;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_PID_2021a_B.Print_o2
                    section.data(2).logicalSrcIdx = 175;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_B.ModelArgument
                    section.data(1).logicalSrcIdx = 176;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_PID_2021a_B.MatrixConcatenate
                    section.data(2).logicalSrcIdx = 177;
                    section.data(2).dtTransOffset = 80;

                    ;% QD2_DroneStack_PID_2021a_B.RateTransition16
                    section.data(3).logicalSrcIdx = 178;
                    section.data(3).dtTransOffset = 320;

            nTotData = nTotData + section.nData;
            sigMap.sections(3) = section;
            clear section

            section.nData     = 55;
            section.data(55)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion_pb
                    section.data(1).logicalSrcIdx = 179;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion22
                    section.data(2).logicalSrcIdx = 180;
                    section.data(2).dtTransOffset = 4;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion24
                    section.data(3).logicalSrcIdx = 181;
                    section.data(3).dtTransOffset = 5;

                    ;% QD2_DroneStack_PID_2021a_B.Compare
                    section.data(4).logicalSrcIdx = 182;
                    section.data(4).dtTransOffset = 6;

                    ;% QD2_DroneStack_PID_2021a_B.AND
                    section.data(5).logicalSrcIdx = 183;
                    section.data(5).dtTransOffset = 7;

                    ;% QD2_DroneStack_PID_2021a_B.LogicalOperator
                    section.data(6).logicalSrcIdx = 184;
                    section.data(6).dtTransOffset = 11;

                    ;% QD2_DroneStack_PID_2021a_B.LogicalOperator_b
                    section.data(7).logicalSrcIdx = 185;
                    section.data(7).dtTransOffset = 12;

                    ;% QD2_DroneStack_PID_2021a_B.LogicalOperator_a
                    section.data(8).logicalSrcIdx = 186;
                    section.data(8).dtTransOffset = 13;

                    ;% QD2_DroneStack_PID_2021a_B.LogicalOperator_bu
                    section.data(9).logicalSrcIdx = 187;
                    section.data(9).dtTransOffset = 14;

                    ;% QD2_DroneStack_PID_2021a_B.LogicalOperator_m
                    section.data(10).logicalSrcIdx = 188;
                    section.data(10).dtTransOffset = 15;

                    ;% QD2_DroneStack_PID_2021a_B.LogicalOperator_l
                    section.data(11).logicalSrcIdx = 189;
                    section.data(11).dtTransOffset = 16;

                    ;% QD2_DroneStack_PID_2021a_B.LogicalOperator_l3
                    section.data(12).logicalSrcIdx = 190;
                    section.data(12).dtTransOffset = 17;

                    ;% QD2_DroneStack_PID_2021a_B.LogicalOperator_o
                    section.data(13).logicalSrcIdx = 191;
                    section.data(13).dtTransOffset = 18;

                    ;% QD2_DroneStack_PID_2021a_B.LogicalOperator_ms
                    section.data(14).logicalSrcIdx = 192;
                    section.data(14).dtTransOffset = 19;

                    ;% QD2_DroneStack_PID_2021a_B.LogicalOperator_og
                    section.data(15).logicalSrcIdx = 193;
                    section.data(15).dtTransOffset = 20;

                    ;% QD2_DroneStack_PID_2021a_B.LogicalOperator_on
                    section.data(16).logicalSrcIdx = 194;
                    section.data(16).dtTransOffset = 21;

                    ;% QD2_DroneStack_PID_2021a_B.LogicalOperator_lm
                    section.data(17).logicalSrcIdx = 195;
                    section.data(17).dtTransOffset = 22;

                    ;% QD2_DroneStack_PID_2021a_B.LogicalOperator_i
                    section.data(18).logicalSrcIdx = 196;
                    section.data(18).dtTransOffset = 23;

                    ;% QD2_DroneStack_PID_2021a_B.OR
                    section.data(19).logicalSrcIdx = 197;
                    section.data(19).dtTransOffset = 24;

                    ;% QD2_DroneStack_PID_2021a_B.LogicalOperator_p
                    section.data(20).logicalSrcIdx = 198;
                    section.data(20).dtTransOffset = 25;

                    ;% QD2_DroneStack_PID_2021a_B.RelationalOperator
                    section.data(21).logicalSrcIdx = 199;
                    section.data(21).dtTransOffset = 26;

                    ;% QD2_DroneStack_PID_2021a_B.LogicalOperator3
                    section.data(22).logicalSrcIdx = 200;
                    section.data(22).dtTransOffset = 27;

                    ;% QD2_DroneStack_PID_2021a_B.LogicalOperator_ab
                    section.data(23).logicalSrcIdx = 201;
                    section.data(23).dtTransOffset = 28;

                    ;% QD2_DroneStack_PID_2021a_B.RelationalOperator_g
                    section.data(24).logicalSrcIdx = 202;
                    section.data(24).dtTransOffset = 29;

                    ;% QD2_DroneStack_PID_2021a_B.LogicalOperator_f
                    section.data(25).logicalSrcIdx = 203;
                    section.data(25).dtTransOffset = 30;

                    ;% QD2_DroneStack_PID_2021a_B.RelationalOperator_i
                    section.data(26).logicalSrcIdx = 204;
                    section.data(26).dtTransOffset = 31;

                    ;% QD2_DroneStack_PID_2021a_B.LogicalOperator_ft
                    section.data(27).logicalSrcIdx = 205;
                    section.data(27).dtTransOffset = 32;

                    ;% QD2_DroneStack_PID_2021a_B.RelationalOperator_h
                    section.data(28).logicalSrcIdx = 206;
                    section.data(28).dtTransOffset = 33;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion4_fx
                    section.data(29).logicalSrcIdx = 207;
                    section.data(29).dtTransOffset = 34;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion23
                    section.data(30).logicalSrcIdx = 208;
                    section.data(30).dtTransOffset = 35;

                    ;% QD2_DroneStack_PID_2021a_B.Compare_c
                    section.data(31).logicalSrcIdx = 209;
                    section.data(31).dtTransOffset = 36;

                    ;% QD2_DroneStack_PID_2021a_B.Compare1
                    section.data(32).logicalSrcIdx = 210;
                    section.data(32).dtTransOffset = 37;

                    ;% QD2_DroneStack_PID_2021a_B.Compare2
                    section.data(33).logicalSrcIdx = 211;
                    section.data(33).dtTransOffset = 38;

                    ;% QD2_DroneStack_PID_2021a_B.LogicalOperator_mx
                    section.data(34).logicalSrcIdx = 212;
                    section.data(34).dtTransOffset = 39;

                    ;% QD2_DroneStack_PID_2021a_B.LogicalOperator2
                    section.data(35).logicalSrcIdx = 213;
                    section.data(35).dtTransOffset = 40;

                    ;% QD2_DroneStack_PID_2021a_B.checkifmeasuredheightexceedsmax
                    section.data(36).logicalSrcIdx = 214;
                    section.data(36).dtTransOffset = 41;

                    ;% QD2_DroneStack_PID_2021a_B.LogicalOperator3_e
                    section.data(37).logicalSrcIdx = 215;
                    section.data(37).dtTransOffset = 42;

                    ;% QD2_DroneStack_PID_2021a_B.LogicalOperator_bd
                    section.data(38).logicalSrcIdx = 216;
                    section.data(38).dtTransOffset = 43;

                    ;% QD2_DroneStack_PID_2021a_B.TmpSignalConversionAtBooleanEdg
                    section.data(39).logicalSrcIdx = 217;
                    section.data(39).dtTransOffset = 44;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion2_o
                    section.data(40).logicalSrcIdx = 218;
                    section.data(40).dtTransOffset = 47;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion5_c
                    section.data(41).logicalSrcIdx = 219;
                    section.data(41).dtTransOffset = 48;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion_f
                    section.data(42).logicalSrcIdx = 220;
                    section.data(42).dtTransOffset = 49;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion8
                    section.data(43).logicalSrcIdx = 221;
                    section.data(43).dtTransOffset = 50;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion14
                    section.data(44).logicalSrcIdx = 222;
                    section.data(44).dtTransOffset = 51;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion9_m
                    section.data(45).logicalSrcIdx = 223;
                    section.data(45).dtTransOffset = 52;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion10_a
                    section.data(46).logicalSrcIdx = 224;
                    section.data(46).dtTransOffset = 53;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion11_h
                    section.data(47).logicalSrcIdx = 225;
                    section.data(47).dtTransOffset = 54;

                    ;% QD2_DroneStack_PID_2021a_B.DataTypeConversion12_i
                    section.data(48).logicalSrcIdx = 226;
                    section.data(48).dtTransOffset = 55;

                    ;% QD2_DroneStack_PID_2021a_B.LogicalOperator_bx
                    section.data(49).logicalSrcIdx = 227;
                    section.data(49).dtTransOffset = 56;

                    ;% QD2_DroneStack_PID_2021a_B.RelationalOperator_e
                    section.data(50).logicalSrcIdx = 228;
                    section.data(50).dtTransOffset = 57;

                    ;% QD2_DroneStack_PID_2021a_B.LogicalOperator_c
                    section.data(51).logicalSrcIdx = 229;
                    section.data(51).dtTransOffset = 58;

                    ;% QD2_DroneStack_PID_2021a_B.RelationalOperator_gi
                    section.data(52).logicalSrcIdx = 230;
                    section.data(52).dtTransOffset = 59;

                    ;% QD2_DroneStack_PID_2021a_B.HILWatchdog
                    section.data(53).logicalSrcIdx = 231;
                    section.data(53).dtTransOffset = 60;

                    ;% QD2_DroneStack_PID_2021a_B.AND_f
                    section.data(54).logicalSrcIdx = 232;
                    section.data(54).dtTransOffset = 61;

                    ;% QD2_DroneStack_PID_2021a_B.Input
                    section.data(55).logicalSrcIdx = 233;
                    section.data(55).dtTransOffset = 62;

            nTotData = nTotData + section.nData;
            sigMap.sections(4) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[1].Gain1
                    section.data(1).logicalSrcIdx = 244;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[1].Integrator1
                    section.data(2).logicalSrcIdx = 245;
                    section.data(2).dtTransOffset = 2;

                    ;% QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[1].Product1
                    section.data(3).logicalSrcIdx = 246;
                    section.data(3).dtTransOffset = 5;

                    ;% QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[1].Product
                    section.data(4).logicalSrcIdx = 247;
                    section.data(4).dtTransOffset = 8;

                    ;% QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[1].Product_i
                    section.data(5).logicalSrcIdx = 248;
                    section.data(5).dtTransOffset = 11;

                    ;% QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[1].Product1_i
                    section.data(6).logicalSrcIdx = 249;
                    section.data(6).dtTransOffset = 14;

                    ;% QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[1].Sum1
                    section.data(7).logicalSrcIdx = 250;
                    section.data(7).dtTransOffset = 17;

            nTotData = nTotData + section.nData;
            sigMap.sections(5) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_B.UsedesiredYwhenenabled.h_dm1
                    section.data(1).logicalSrcIdx = 253;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_B.UsedesiredXwhenenabled.h_dm1
                    section.data(1).logicalSrcIdx = 254;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(7) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_B.Usedesyawwhenenabled.h_dm1
                    section.data(1).logicalSrcIdx = 255;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(8) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_B.Usedesheightwhenenabled.h_dm1
                    section.data(1).logicalSrcIdx = 256;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(9) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_B.Usedesiredheightwhenenabled_c.h_dm1
                    section.data(1).logicalSrcIdx = 257;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(10) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_B.CoreSubsys_p[8].Print_o2
                    section.data(1).logicalSrcIdx = 258;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(11) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_B.CoreSubsys[2].Print_o2
                    section.data(1).logicalSrcIdx = 259;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(12) = section;
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
        nTotSects     = 29;
        sectIdxOffset = 12;

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
        ;% Auto data (QD2_DroneStack_PID_2021a_DW)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_DW.RangingSensor_Measurements
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 14;
            section.data(14)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_DW.Time_Timeout
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_PID_2021a_DW.ComputationTime_BeginTime
                    section.data(2).logicalSrcIdx = 2;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_DroneStack_PID_2021a_DW.ComputationTime_ComputationTime
                    section.data(3).logicalSrcIdx = 3;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_DroneStack_PID_2021a_DW.SampleTime_PreviousTime
                    section.data(4).logicalSrcIdx = 4;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_DroneStack_PID_2021a_DW.Time_Timeout_d
                    section.data(5).logicalSrcIdx = 5;
                    section.data(5).dtTransOffset = 4;

                    ;% QD2_DroneStack_PID_2021a_DW.SampleTime_PreviousTime_d
                    section.data(6).logicalSrcIdx = 6;
                    section.data(6).dtTransOffset = 5;

                    ;% QD2_DroneStack_PID_2021a_DW.ComputationTime_BeginTime_g
                    section.data(7).logicalSrcIdx = 7;
                    section.data(7).dtTransOffset = 6;

                    ;% QD2_DroneStack_PID_2021a_DW.ComputationTime_ComputationTi_o
                    section.data(8).logicalSrcIdx = 8;
                    section.data(8).dtTransOffset = 7;

                    ;% QD2_DroneStack_PID_2021a_DW.ComputationTime1_BeginTime
                    section.data(9).logicalSrcIdx = 9;
                    section.data(9).dtTransOffset = 8;

                    ;% QD2_DroneStack_PID_2021a_DW.ComputationTime1_ComputationTim
                    section.data(10).logicalSrcIdx = 10;
                    section.data(10).dtTransOffset = 9;

                    ;% QD2_DroneStack_PID_2021a_DW.SampleTime1_PreviousTime
                    section.data(11).logicalSrcIdx = 11;
                    section.data(11).dtTransOffset = 10;

                    ;% QD2_DroneStack_PID_2021a_DW.ComputationTime2_BeginTime
                    section.data(12).logicalSrcIdx = 12;
                    section.data(12).dtTransOffset = 11;

                    ;% QD2_DroneStack_PID_2021a_DW.ComputationTime2_ComputationTim
                    section.data(13).logicalSrcIdx = 13;
                    section.data(13).dtTransOffset = 12;

                    ;% QD2_DroneStack_PID_2021a_DW.SampleTime2_PreviousTime
                    section.data(14).logicalSrcIdx = 14;
                    section.data(14).dtTransOffset = 13;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 104;
            section.data(104)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_DW.Delay_DSTATE
                    section.data(1).logicalSrcIdx = 15;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_PID_2021a_DW.Delay3_DSTATE
                    section.data(2).logicalSrcIdx = 16;
                    section.data(2).dtTransOffset = 100;

                    ;% QD2_DroneStack_PID_2021a_DW.Delay2_DSTATE
                    section.data(3).logicalSrcIdx = 17;
                    section.data(3).dtTransOffset = 102;

                    ;% QD2_DroneStack_PID_2021a_DW.Delay1_DSTATE
                    section.data(4).logicalSrcIdx = 18;
                    section.data(4).dtTransOffset = 104;

                    ;% QD2_DroneStack_PID_2021a_DW.Delay_DSTATE_e
                    section.data(5).logicalSrcIdx = 19;
                    section.data(5).dtTransOffset = 106;

                    ;% QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE
                    section.data(6).logicalSrcIdx = 20;
                    section.data(6).dtTransOffset = 108;

                    ;% QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_o
                    section.data(7).logicalSrcIdx = 21;
                    section.data(7).dtTransOffset = 109;

                    ;% QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_b
                    section.data(8).logicalSrcIdx = 22;
                    section.data(8).dtTransOffset = 110;

                    ;% QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_d
                    section.data(9).logicalSrcIdx = 23;
                    section.data(9).dtTransOffset = 111;

                    ;% QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_f
                    section.data(10).logicalSrcIdx = 24;
                    section.data(10).dtTransOffset = 112;

                    ;% QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_g
                    section.data(11).logicalSrcIdx = 25;
                    section.data(11).dtTransOffset = 113;

                    ;% QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_n
                    section.data(12).logicalSrcIdx = 26;
                    section.data(12).dtTransOffset = 114;

                    ;% QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_p
                    section.data(13).logicalSrcIdx = 27;
                    section.data(13).dtTransOffset = 115;

                    ;% QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_j
                    section.data(14).logicalSrcIdx = 28;
                    section.data(14).dtTransOffset = 116;

                    ;% QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_h
                    section.data(15).logicalSrcIdx = 29;
                    section.data(15).dtTransOffset = 117;

                    ;% QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTAT_n1
                    section.data(16).logicalSrcIdx = 30;
                    section.data(16).dtTransOffset = 118;

                    ;% QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_c
                    section.data(17).logicalSrcIdx = 31;
                    section.data(17).dtTransOffset = 119;

                    ;% QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_a
                    section.data(18).logicalSrcIdx = 32;
                    section.data(18).dtTransOffset = 120;

                    ;% QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTAT_bm
                    section.data(19).logicalSrcIdx = 33;
                    section.data(19).dtTransOffset = 121;

                    ;% QD2_DroneStack_PID_2021a_DW.UnitDelay_DSTATE
                    section.data(20).logicalSrcIdx = 34;
                    section.data(20).dtTransOffset = 122;

                    ;% QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTAT_jy
                    section.data(21).logicalSrcIdx = 35;
                    section.data(21).dtTransOffset = 123;

                    ;% QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_e
                    section.data(22).logicalSrcIdx = 36;
                    section.data(22).dtTransOffset = 124;

                    ;% QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_i
                    section.data(23).logicalSrcIdx = 37;
                    section.data(23).dtTransOffset = 125;

                    ;% QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTAT_ja
                    section.data(24).logicalSrcIdx = 38;
                    section.data(24).dtTransOffset = 126;

                    ;% QD2_DroneStack_PID_2021a_DW.DelayInput1_DSTATE
                    section.data(25).logicalSrcIdx = 39;
                    section.data(25).dtTransOffset = 127;

                    ;% QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_k
                    section.data(26).logicalSrcIdx = 40;
                    section.data(26).dtTransOffset = 128;

                    ;% QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTAT_fv
                    section.data(27).logicalSrcIdx = 41;
                    section.data(27).dtTransOffset = 129;

                    ;% QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTAT_a1
                    section.data(28).logicalSrcIdx = 42;
                    section.data(28).dtTransOffset = 130;

                    ;% QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator1_DSTATE
                    section.data(29).logicalSrcIdx = 43;
                    section.data(29).dtTransOffset = 132;

                    ;% QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTAT_ax
                    section.data(30).logicalSrcIdx = 44;
                    section.data(30).dtTransOffset = 134;

                    ;% QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator1_DSTAT_l
                    section.data(31).logicalSrcIdx = 45;
                    section.data(31).dtTransOffset = 135;

                    ;% QD2_DroneStack_PID_2021a_DW.HILInitialize_AIMinimums
                    section.data(32).logicalSrcIdx = 46;
                    section.data(32).dtTransOffset = 136;

                    ;% QD2_DroneStack_PID_2021a_DW.HILInitialize_AIMaximums
                    section.data(33).logicalSrcIdx = 47;
                    section.data(33).dtTransOffset = 140;

                    ;% QD2_DroneStack_PID_2021a_DW.HILInitialize_FilterFrequency
                    section.data(34).logicalSrcIdx = 48;
                    section.data(34).dtTransOffset = 144;

                    ;% QD2_DroneStack_PID_2021a_DW.HILInitialize_POSortedFreqs
                    section.data(35).logicalSrcIdx = 49;
                    section.data(35).dtTransOffset = 146;

                    ;% QD2_DroneStack_PID_2021a_DW.HILInitialize_POValues
                    section.data(36).logicalSrcIdx = 50;
                    section.data(36).dtTransOffset = 152;

                    ;% QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput
                    section.data(37).logicalSrcIdx = 51;
                    section.data(37).dtTransOffset = 158;

                    ;% QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_f
                    section.data(38).logicalSrcIdx = 52;
                    section.data(38).dtTransOffset = 159;

                    ;% QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Sigmoid
                    section.data(39).logicalSrcIdx = 53;
                    section.data(39).dtTransOffset = 160;

                    ;% QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Time
                    section.data(40).logicalSrcIdx = 54;
                    section.data(40).dtTransOffset = 171;

                    ;% QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Target
                    section.data(41).logicalSrcIdx = 55;
                    section.data(41).dtTransOffset = 172;

                    ;% QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_PPos
                    section.data(42).logicalSrcIdx = 56;
                    section.data(42).dtTransOffset = 173;

                    ;% QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_PVel
                    section.data(43).logicalSrcIdx = 57;
                    section.data(43).dtTransOffset = 174;

                    ;% QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_MVel
                    section.data(44).logicalSrcIdx = 58;
                    section.data(44).dtTransOffset = 175;

                    ;% QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_MAcc
                    section.data(45).logicalSrcIdx = 59;
                    section.data(45).dtTransOffset = 176;

                    ;% QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_e
                    section.data(46).logicalSrcIdx = 60;
                    section.data(46).dtTransOffset = 177;

                    ;% QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Sigmoid_l
                    section.data(47).logicalSrcIdx = 61;
                    section.data(47).dtTransOffset = 178;

                    ;% QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Time_c
                    section.data(48).logicalSrcIdx = 62;
                    section.data(48).dtTransOffset = 189;

                    ;% QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Target_d
                    section.data(49).logicalSrcIdx = 63;
                    section.data(49).dtTransOffset = 190;

                    ;% QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_PPos_a
                    section.data(50).logicalSrcIdx = 64;
                    section.data(50).dtTransOffset = 191;

                    ;% QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_PVel_p
                    section.data(51).logicalSrcIdx = 65;
                    section.data(51).dtTransOffset = 192;

                    ;% QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_MVel_l
                    section.data(52).logicalSrcIdx = 66;
                    section.data(52).dtTransOffset = 193;

                    ;% QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_MAcc_p
                    section.data(53).logicalSrcIdx = 67;
                    section.data(53).dtTransOffset = 194;

                    ;% QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_Sigmoid
                    section.data(54).logicalSrcIdx = 68;
                    section.data(54).dtTransOffset = 195;

                    ;% QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_Time
                    section.data(55).logicalSrcIdx = 69;
                    section.data(55).dtTransOffset = 206;

                    ;% QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_Target
                    section.data(56).logicalSrcIdx = 70;
                    section.data(56).dtTransOffset = 207;

                    ;% QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_PPos
                    section.data(57).logicalSrcIdx = 71;
                    section.data(57).dtTransOffset = 208;

                    ;% QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_PVel
                    section.data(58).logicalSrcIdx = 72;
                    section.data(58).dtTransOffset = 209;

                    ;% QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_MVel
                    section.data(59).logicalSrcIdx = 73;
                    section.data(59).dtTransOffset = 210;

                    ;% QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_MAcc
                    section.data(60).logicalSrcIdx = 74;
                    section.data(60).dtTransOffset = 211;

                    ;% QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_Sigmoid
                    section.data(61).logicalSrcIdx = 75;
                    section.data(61).dtTransOffset = 212;

                    ;% QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_Time
                    section.data(62).logicalSrcIdx = 76;
                    section.data(62).dtTransOffset = 223;

                    ;% QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_Target
                    section.data(63).logicalSrcIdx = 77;
                    section.data(63).dtTransOffset = 224;

                    ;% QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_PPos
                    section.data(64).logicalSrcIdx = 78;
                    section.data(64).dtTransOffset = 225;

                    ;% QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_PVel
                    section.data(65).logicalSrcIdx = 79;
                    section.data(65).dtTransOffset = 226;

                    ;% QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_MVel
                    section.data(66).logicalSrcIdx = 80;
                    section.data(66).dtTransOffset = 227;

                    ;% QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_MAcc
                    section.data(67).logicalSrcIdx = 81;
                    section.data(67).dtTransOffset = 228;

                    ;% QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_Sigmoid
                    section.data(68).logicalSrcIdx = 82;
                    section.data(68).dtTransOffset = 229;

                    ;% QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_Time
                    section.data(69).logicalSrcIdx = 83;
                    section.data(69).dtTransOffset = 240;

                    ;% QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_Target
                    section.data(70).logicalSrcIdx = 84;
                    section.data(70).dtTransOffset = 241;

                    ;% QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_PPos
                    section.data(71).logicalSrcIdx = 85;
                    section.data(71).dtTransOffset = 242;

                    ;% QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_PVel
                    section.data(72).logicalSrcIdx = 86;
                    section.data(72).dtTransOffset = 243;

                    ;% QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_MVel
                    section.data(73).logicalSrcIdx = 87;
                    section.data(73).dtTransOffset = 244;

                    ;% QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_MAcc
                    section.data(74).logicalSrcIdx = 88;
                    section.data(74).dtTransOffset = 245;

                    ;% QD2_DroneStack_PID_2021a_DW.PrevY
                    section.data(75).logicalSrcIdx = 89;
                    section.data(75).dtTransOffset = 246;

                    ;% QD2_DroneStack_PID_2021a_DW.LastMajorTime
                    section.data(76).logicalSrcIdx = 90;
                    section.data(76).dtTransOffset = 247;

                    ;% QD2_DroneStack_PID_2021a_DW.RateTransition7_Buffer0
                    section.data(77).logicalSrcIdx = 91;
                    section.data(77).dtTransOffset = 248;

                    ;% QD2_DroneStack_PID_2021a_DW.RateTransition2_Buffer0
                    section.data(78).logicalSrcIdx = 92;
                    section.data(78).dtTransOffset = 250;

                    ;% QD2_DroneStack_PID_2021a_DW.RateTransition1_Buffer0
                    section.data(79).logicalSrcIdx = 93;
                    section.data(79).dtTransOffset = 251;

                    ;% QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_a
                    section.data(80).logicalSrcIdx = 94;
                    section.data(80).dtTransOffset = 252;

                    ;% QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_as
                    section.data(81).logicalSrcIdx = 95;
                    section.data(81).dtTransOffset = 256;

                    ;% QD2_DroneStack_PID_2021a_DW.RateTransition_Buffer0
                    section.data(82).logicalSrcIdx = 96;
                    section.data(82).dtTransOffset = 260;

                    ;% QD2_DroneStack_PID_2021a_DW.RateTransition1_Buffer0_m
                    section.data(83).logicalSrcIdx = 97;
                    section.data(83).dtTransOffset = 261;

                    ;% QD2_DroneStack_PID_2021a_DW.RateTransition2_Buffer0_m
                    section.data(84).logicalSrcIdx = 98;
                    section.data(84).dtTransOffset = 262;

                    ;% QD2_DroneStack_PID_2021a_DW.RateTransition3_Buffer0
                    section.data(85).logicalSrcIdx = 99;
                    section.data(85).dtTransOffset = 263;

                    ;% QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_n
                    section.data(86).logicalSrcIdx = 100;
                    section.data(86).dtTransOffset = 264;

                    ;% QD2_DroneStack_PID_2021a_DW.RateTransition_Buffer
                    section.data(87).logicalSrcIdx = 101;
                    section.data(87).dtTransOffset = 268;

                    ;% QD2_DroneStack_PID_2021a_DW.RateTransition10_Buffer
                    section.data(88).logicalSrcIdx = 102;
                    section.data(88).dtTransOffset = 275;

                    ;% QD2_DroneStack_PID_2021a_DW.RateTransition11_Buffer
                    section.data(89).logicalSrcIdx = 103;
                    section.data(89).dtTransOffset = 279;

                    ;% QD2_DroneStack_PID_2021a_DW.RateTransition12_Buffer
                    section.data(90).logicalSrcIdx = 104;
                    section.data(90).dtTransOffset = 280;

                    ;% QD2_DroneStack_PID_2021a_DW.RateTransition15_Buffer
                    section.data(91).logicalSrcIdx = 105;
                    section.data(91).dtTransOffset = 281;

                    ;% QD2_DroneStack_PID_2021a_DW.RateTransition17_Buffer
                    section.data(92).logicalSrcIdx = 106;
                    section.data(92).dtTransOffset = 290;

                    ;% QD2_DroneStack_PID_2021a_DW.RateTransition19_Buffer
                    section.data(93).logicalSrcIdx = 107;
                    section.data(93).dtTransOffset = 299;

                    ;% QD2_DroneStack_PID_2021a_DW.RateTransition20_Buffer
                    section.data(94).logicalSrcIdx = 108;
                    section.data(94).dtTransOffset = 308;

                    ;% QD2_DroneStack_PID_2021a_DW.RateTransition3_Buffer
                    section.data(95).logicalSrcIdx = 109;
                    section.data(95).dtTransOffset = 309;

                    ;% QD2_DroneStack_PID_2021a_DW.RateTransition8_Buffer
                    section.data(96).logicalSrcIdx = 110;
                    section.data(96).dtTransOffset = 318;

                    ;% QD2_DroneStack_PID_2021a_DW.Memory2_PreviousInput
                    section.data(97).logicalSrcIdx = 111;
                    section.data(97).dtTransOffset = 330;

                    ;% QD2_DroneStack_PID_2021a_DW.next_state_after_pause
                    section.data(98).logicalSrcIdx = 112;
                    section.data(98).dtTransOffset = 331;

                    ;% QD2_DroneStack_PID_2021a_DW.state_counter
                    section.data(99).logicalSrcIdx = 113;
                    section.data(99).dtTransOffset = 332;

                    ;% QD2_DroneStack_PID_2021a_DW.state_counter_after_pause
                    section.data(100).logicalSrcIdx = 114;
                    section.data(100).dtTransOffset = 333;

                    ;% QD2_DroneStack_PID_2021a_DW.esc_timeout_state
                    section.data(101).logicalSrcIdx = 115;
                    section.data(101).dtTransOffset = 334;

                    ;% QD2_DroneStack_PID_2021a_DW.idx
                    section.data(102).logicalSrcIdx = 116;
                    section.data(102).dtTransOffset = 335;

                    ;% QD2_DroneStack_PID_2021a_DW.state
                    section.data(103).logicalSrcIdx = 117;
                    section.data(103).dtTransOffset = 336;

                    ;% QD2_DroneStack_PID_2021a_DW.ms_time_prev
                    section.data(104).logicalSrcIdx = 118;
                    section.data(104).dtTransOffset = 337;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_DW.ToHostFile_PointsWritten
                    section.data(1).logicalSrcIdx = 119;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_PID_2021a_DW.ToHostFile_PointsWritten_l
                    section.data(2).logicalSrcIdx = 120;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_DroneStack_PID_2021a_DW.ToHostFile_PointsWritten_p
                    section.data(3).logicalSrcIdx = 121;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_DW.StreamClient_Stream
                    section.data(1).logicalSrcIdx = 122;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_PID_2021a_DW.StreamServer_Stream
                    section.data(2).logicalSrcIdx = 123;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_DW.RangingSensor_Sensor
                    section.data(1).logicalSrcIdx = 124;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_DW.HILInitialize_Card
                    section.data(1).logicalSrcIdx = 125;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section

            section.nData     = 25;
            section.data(25)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_DW.HILRead_PWORK
                    section.data(1).logicalSrcIdx = 126;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_PID_2021a_DW.ESCSelectRaw_PWORK.LoggedData
                    section.data(2).logicalSrcIdx = 127;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_DroneStack_PID_2021a_DW.HILWriteDigital_PWORK
                    section.data(3).logicalSrcIdx = 128;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_DroneStack_PID_2021a_DW.ToHostFile_PWORK
                    section.data(4).logicalSrcIdx = 129;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_DroneStack_PID_2021a_DW.Telemetry_PWORK.LoggedData
                    section.data(5).logicalSrcIdx = 130;
                    section.data(5).dtTransOffset = 5;

                    ;% QD2_DroneStack_PID_2021a_DW.ESCChannelMismatrch_PWORK.LoggedData
                    section.data(6).logicalSrcIdx = 131;
                    section.data(6).dtTransOffset = 6;

                    ;% QD2_DroneStack_PID_2021a_DW.ESCChannelMismatrchCount_PWORK.LoggedData
                    section.data(7).logicalSrcIdx = 132;
                    section.data(7).dtTransOffset = 10;

                    ;% QD2_DroneStack_PID_2021a_DW.ESCChannelSelectionIndex_PWORK.LoggedData
                    section.data(8).logicalSrcIdx = 133;
                    section.data(8).dtTransOffset = 14;

                    ;% QD2_DroneStack_PID_2021a_DW.TimingCheck_PWORK.LoggedData
                    section.data(9).logicalSrcIdx = 134;
                    section.data(9).dtTransOffset = 18;

                    ;% QD2_DroneStack_PID_2021a_DW.Generalizedcommands_PWORK.LoggedData
                    section.data(10).logicalSrcIdx = 135;
                    section.data(10).dtTransOffset = 21;

                    ;% QD2_DroneStack_PID_2021a_DW.ToHostFile_PWORK_p
                    section.data(11).logicalSrcIdx = 136;
                    section.data(11).dtTransOffset = 22;

                    ;% QD2_DroneStack_PID_2021a_DW.FSM_PWORK.LoggedData
                    section.data(12).logicalSrcIdx = 137;
                    section.data(12).dtTransOffset = 24;

                    ;% QD2_DroneStack_PID_2021a_DW.HeightCheck_PWORK.LoggedData
                    section.data(13).logicalSrcIdx = 138;
                    section.data(13).dtTransOffset = 36;

                    ;% QD2_DroneStack_PID_2021a_DW.JoystickInfo_PWORK.LoggedData
                    section.data(14).logicalSrcIdx = 139;
                    section.data(14).dtTransOffset = 40;

                    ;% QD2_DroneStack_PID_2021a_DW.ThrottleCheck_PWORK.LoggedData
                    section.data(15).logicalSrcIdx = 140;
                    section.data(15).dtTransOffset = 44;

                    ;% QD2_DroneStack_PID_2021a_DW.CommunicationLoss_PWORK.LoggedData
                    section.data(16).logicalSrcIdx = 141;
                    section.data(16).dtTransOffset = 47;

                    ;% QD2_DroneStack_PID_2021a_DW.IFPoseTrackingPerformanceTracki.LoggedData
                    section.data(17).logicalSrcIdx = 142;
                    section.data(17).dtTransOffset = 49;

                    ;% QD2_DroneStack_PID_2021a_DW.RollandPitchAngleControldeg_PWO.LoggedData
                    section.data(18).logicalSrcIdx = 143;
                    section.data(18).dtTransOffset = 53;

                    ;% QD2_DroneStack_PID_2021a_DW.RollPitchandYawRateControldegs_.LoggedData
                    section.data(19).logicalSrcIdx = 144;
                    section.data(19).dtTransOffset = 55;

                    ;% QD2_DroneStack_PID_2021a_DW.HILWatchdog_PWORK
                    section.data(20).logicalSrcIdx = 145;
                    section.data(20).dtTransOffset = 58;

                    ;% QD2_DroneStack_PID_2021a_DW.ToHostFile_PWORK_k
                    section.data(21).logicalSrcIdx = 146;
                    section.data(21).dtTransOffset = 59;

                    ;% QD2_DroneStack_PID_2021a_DW.ComputationTimes_PWORK.LoggedData
                    section.data(22).logicalSrcIdx = 147;
                    section.data(22).dtTransOffset = 61;

                    ;% QD2_DroneStack_PID_2021a_DW.SampleTimes_PWORK.LoggedData
                    section.data(23).logicalSrcIdx = 148;
                    section.data(23).dtTransOffset = 62;

                    ;% QD2_DroneStack_PID_2021a_DW.HILWritePWM_PWORK
                    section.data(24).logicalSrcIdx = 149;
                    section.data(24).dtTransOffset = 63;

                    ;% QD2_DroneStack_PID_2021a_DW.buffer
                    section.data(25).logicalSrcIdx = 150;
                    section.data(25).dtTransOffset = 64;

            nTotData = nTotData + section.nData;
            dworkMap.sections(8) = section;
            clear section

            section.nData     = 20;
            section.data(20)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_DW.HILInitialize_DOStates
                    section.data(1).logicalSrcIdx = 151;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_PID_2021a_DW.HILInitialize_QuadratureModes
                    section.data(2).logicalSrcIdx = 152;
                    section.data(2).dtTransOffset = 6;

                    ;% QD2_DroneStack_PID_2021a_DW.HILInitialize_InitialEICounts
                    section.data(3).logicalSrcIdx = 153;
                    section.data(3).dtTransOffset = 8;

                    ;% QD2_DroneStack_PID_2021a_DW.HILInitialize_POModeValues
                    section.data(4).logicalSrcIdx = 154;
                    section.data(4).dtTransOffset = 10;

                    ;% QD2_DroneStack_PID_2021a_DW.HILInitialize_POAlignValues
                    section.data(5).logicalSrcIdx = 155;
                    section.data(5).dtTransOffset = 16;

                    ;% QD2_DroneStack_PID_2021a_DW.HILInitialize_POPolarityVals
                    section.data(6).logicalSrcIdx = 156;
                    section.data(6).dtTransOffset = 22;

                    ;% QD2_DroneStack_PID_2021a_DW.sfEvent
                    section.data(7).logicalSrcIdx = 157;
                    section.data(7).dtTransOffset = 28;

                    ;% QD2_DroneStack_PID_2021a_DW.sfEvent_n
                    section.data(8).logicalSrcIdx = 158;
                    section.data(8).dtTransOffset = 29;

                    ;% QD2_DroneStack_PID_2021a_DW.sfEvent_c
                    section.data(9).logicalSrcIdx = 159;
                    section.data(9).dtTransOffset = 30;

                    ;% QD2_DroneStack_PID_2021a_DW.sfEvent_nd
                    section.data(10).logicalSrcIdx = 160;
                    section.data(10).dtTransOffset = 31;

                    ;% QD2_DroneStack_PID_2021a_DW.sfEvent_b
                    section.data(11).logicalSrcIdx = 161;
                    section.data(11).dtTransOffset = 32;

                    ;% QD2_DroneStack_PID_2021a_DW.sfEvent_i
                    section.data(12).logicalSrcIdx = 162;
                    section.data(12).dtTransOffset = 33;

                    ;% QD2_DroneStack_PID_2021a_DW.sfEvent_id
                    section.data(13).logicalSrcIdx = 163;
                    section.data(13).dtTransOffset = 34;

                    ;% QD2_DroneStack_PID_2021a_DW.sfEvent_iv
                    section.data(14).logicalSrcIdx = 164;
                    section.data(14).dtTransOffset = 35;

                    ;% QD2_DroneStack_PID_2021a_DW.sfEvent_o
                    section.data(15).logicalSrcIdx = 165;
                    section.data(15).dtTransOffset = 36;

                    ;% QD2_DroneStack_PID_2021a_DW.sfEvent_l
                    section.data(16).logicalSrcIdx = 166;
                    section.data(16).dtTransOffset = 37;

                    ;% QD2_DroneStack_PID_2021a_DW.sfEvent_np
                    section.data(17).logicalSrcIdx = 167;
                    section.data(17).dtTransOffset = 38;

                    ;% QD2_DroneStack_PID_2021a_DW.sfEvent_m
                    section.data(18).logicalSrcIdx = 168;
                    section.data(18).dtTransOffset = 39;

                    ;% QD2_DroneStack_PID_2021a_DW.sfEvent_e
                    section.data(19).logicalSrcIdx = 169;
                    section.data(19).dtTransOffset = 40;

                    ;% QD2_DroneStack_PID_2021a_DW.sfEvent_cx
                    section.data(20).logicalSrcIdx = 170;
                    section.data(20).dtTransOffset = 41;

            nTotData = nTotData + section.nData;
            dworkMap.sections(9) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_DW.HILInitialize_POSortedChans
                    section.data(1).logicalSrcIdx = 171;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_PID_2021a_DW.ToHostFile_SamplesCount
                    section.data(2).logicalSrcIdx = 172;
                    section.data(2).dtTransOffset = 6;

                    ;% QD2_DroneStack_PID_2021a_DW.ToHostFile_ArrayNameLength
                    section.data(3).logicalSrcIdx = 173;
                    section.data(3).dtTransOffset = 7;

                    ;% QD2_DroneStack_PID_2021a_DW.ToHostFile_SamplesCount_h
                    section.data(4).logicalSrcIdx = 174;
                    section.data(4).dtTransOffset = 8;

                    ;% QD2_DroneStack_PID_2021a_DW.ToHostFile_ArrayNameLength_e
                    section.data(5).logicalSrcIdx = 175;
                    section.data(5).dtTransOffset = 9;

                    ;% QD2_DroneStack_PID_2021a_DW.ToHostFile_SamplesCount_n
                    section.data(6).logicalSrcIdx = 176;
                    section.data(6).dtTransOffset = 10;

                    ;% QD2_DroneStack_PID_2021a_DW.ToHostFile_ArrayNameLength_f
                    section.data(7).logicalSrcIdx = 177;
                    section.data(7).dtTransOffset = 11;

            nTotData = nTotData + section.nData;
            dworkMap.sections(10) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_DW.StringDisplay_IWORK
                    section.data(1).logicalSrcIdx = 178;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(11) = section;
            clear section

            section.nData     = 24;
            section.data(24)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevRese
                    section.data(1).logicalSrcIdx = 179;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevRe_p
                    section.data(2).logicalSrcIdx = 180;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevRe_g
                    section.data(3).logicalSrcIdx = 181;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevRe_o
                    section.data(4).logicalSrcIdx = 182;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevR_oi
                    section.data(5).logicalSrcIdx = 183;
                    section.data(5).dtTransOffset = 4;

                    ;% QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevRe_e
                    section.data(6).logicalSrcIdx = 184;
                    section.data(6).dtTransOffset = 5;

                    ;% QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevRe_n
                    section.data(7).logicalSrcIdx = 185;
                    section.data(7).dtTransOffset = 6;

                    ;% QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevR_p5
                    section.data(8).logicalSrcIdx = 186;
                    section.data(8).dtTransOffset = 7;

                    ;% QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevRe_d
                    section.data(9).logicalSrcIdx = 187;
                    section.data(9).dtTransOffset = 8;

                    ;% QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevR_nn
                    section.data(10).logicalSrcIdx = 188;
                    section.data(10).dtTransOffset = 9;

                    ;% QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevR_eu
                    section.data(11).logicalSrcIdx = 189;
                    section.data(11).dtTransOffset = 10;

                    ;% QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevR_gx
                    section.data(12).logicalSrcIdx = 190;
                    section.data(12).dtTransOffset = 11;

                    ;% QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevRe_f
                    section.data(13).logicalSrcIdx = 191;
                    section.data(13).dtTransOffset = 12;

                    ;% QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevR_oj
                    section.data(14).logicalSrcIdx = 192;
                    section.data(14).dtTransOffset = 13;

                    ;% QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevR_dp
                    section.data(15).logicalSrcIdx = 193;
                    section.data(15).dtTransOffset = 14;

                    ;% QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevRe_l
                    section.data(16).logicalSrcIdx = 194;
                    section.data(16).dtTransOffset = 15;

                    ;% QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevR_gh
                    section.data(17).logicalSrcIdx = 195;
                    section.data(17).dtTransOffset = 16;

                    ;% QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevRe_a
                    section.data(18).logicalSrcIdx = 196;
                    section.data(18).dtTransOffset = 17;

                    ;% QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevR_df
                    section.data(19).logicalSrcIdx = 197;
                    section.data(19).dtTransOffset = 18;

                    ;% QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevR_az
                    section.data(20).logicalSrcIdx = 198;
                    section.data(20).dtTransOffset = 19;

                    ;% QD2_DroneStack_PID_2021a_DW.TriggeredSubsystemLatchingFlag_
                    section.data(21).logicalSrcIdx = 199;
                    section.data(21).dtTransOffset = 20;

                    ;% QD2_DroneStack_PID_2021a_DW.EnabledSubsystemWriteESCCommand
                    section.data(22).logicalSrcIdx = 200;
                    section.data(22).dtTransOffset = 21;

                    ;% QD2_DroneStack_PID_2021a_DW.LatchEStop_SubsysRanBC
                    section.data(23).logicalSrcIdx = 201;
                    section.data(23).dtTransOffset = 22;

                    ;% QD2_DroneStack_PID_2021a_DW.TriggeredSubsystem_SubsysRanBC
                    section.data(24).logicalSrcIdx = 202;
                    section.data(24).dtTransOffset = 23;

            nTotData = nTotData + section.nData;
            dworkMap.sections(12) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Flag
                    section.data(1).logicalSrcIdx = 203;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Flag_h
                    section.data(2).logicalSrcIdx = 204;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_Flag
                    section.data(3).logicalSrcIdx = 205;
                    section.data(3).dtTransOffset = 2;

                    ;% QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_Flag
                    section.data(4).logicalSrcIdx = 206;
                    section.data(4).dtTransOffset = 3;

                    ;% QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_Flag
                    section.data(5).logicalSrcIdx = 207;
                    section.data(5).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            dworkMap.sections(13) = section;
            clear section

            section.nData     = 32;
            section.data(32)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_DW.HILInitialize_DOBits
                    section.data(1).logicalSrcIdx = 208;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_PID_2021a_DW.Time_Owner
                    section.data(2).logicalSrcIdx = 209;
                    section.data(2).dtTransOffset = 6;

                    ;% QD2_DroneStack_PID_2021a_DW.StreamClient_Connected
                    section.data(3).logicalSrcIdx = 210;
                    section.data(3).dtTransOffset = 7;

                    ;% QD2_DroneStack_PID_2021a_DW.Memory1_PreviousInput
                    section.data(4).logicalSrcIdx = 211;
                    section.data(4).dtTransOffset = 8;

                    ;% QD2_DroneStack_PID_2021a_DW.Integrator1_DWORK1
                    section.data(5).logicalSrcIdx = 212;
                    section.data(5).dtTransOffset = 9;

                    ;% QD2_DroneStack_PID_2021a_DW.PrevLimited
                    section.data(6).logicalSrcIdx = 213;
                    section.data(6).dtTransOffset = 10;

                    ;% QD2_DroneStack_PID_2021a_DW.Time_Owner_h
                    section.data(7).logicalSrcIdx = 214;
                    section.data(7).dtTransOffset = 11;

                    ;% QD2_DroneStack_PID_2021a_DW.Integrator1_DWORK1_p
                    section.data(8).logicalSrcIdx = 215;
                    section.data(8).dtTransOffset = 12;

                    ;% QD2_DroneStack_PID_2021a_DW.HILWatchdog_IsStarted
                    section.data(9).logicalSrcIdx = 216;
                    section.data(9).dtTransOffset = 13;

                    ;% QD2_DroneStack_PID_2021a_DW.Memory3_PreviousInput
                    section.data(10).logicalSrcIdx = 217;
                    section.data(10).dtTransOffset = 14;

                    ;% QD2_DroneStack_PID_2021a_DW.doneDoubleBufferReInit
                    section.data(11).logicalSrcIdx = 218;
                    section.data(11).dtTransOffset = 15;

                    ;% QD2_DroneStack_PID_2021a_DW.next_state_after_pause_not_empt
                    section.data(12).logicalSrcIdx = 219;
                    section.data(12).dtTransOffset = 16;

                    ;% QD2_DroneStack_PID_2021a_DW.state_counter_not_empty
                    section.data(13).logicalSrcIdx = 220;
                    section.data(13).dtTransOffset = 17;

                    ;% QD2_DroneStack_PID_2021a_DW.state_counter_after_pause_not_e
                    section.data(14).logicalSrcIdx = 221;
                    section.data(14).dtTransOffset = 18;

                    ;% QD2_DroneStack_PID_2021a_DW.esc_timeout_state_not_empty
                    section.data(15).logicalSrcIdx = 222;
                    section.data(15).dtTransOffset = 19;

                    ;% QD2_DroneStack_PID_2021a_DW.doneDoubleBufferReInit_g
                    section.data(16).logicalSrcIdx = 223;
                    section.data(16).dtTransOffset = 20;

                    ;% QD2_DroneStack_PID_2021a_DW.doneDoubleBufferReInit_a
                    section.data(17).logicalSrcIdx = 224;
                    section.data(17).dtTransOffset = 21;

                    ;% QD2_DroneStack_PID_2021a_DW.idx_not_empty
                    section.data(18).logicalSrcIdx = 225;
                    section.data(18).dtTransOffset = 22;

                    ;% QD2_DroneStack_PID_2021a_DW.buffer_not_empty
                    section.data(19).logicalSrcIdx = 226;
                    section.data(19).dtTransOffset = 23;

                    ;% QD2_DroneStack_PID_2021a_DW.doneDoubleBufferReInit_b
                    section.data(20).logicalSrcIdx = 227;
                    section.data(20).dtTransOffset = 24;

                    ;% QD2_DroneStack_PID_2021a_DW.state_not_empty
                    section.data(21).logicalSrcIdx = 228;
                    section.data(21).dtTransOffset = 25;

                    ;% QD2_DroneStack_PID_2021a_DW.doneDoubleBufferReInit_ai
                    section.data(22).logicalSrcIdx = 229;
                    section.data(22).dtTransOffset = 26;

                    ;% QD2_DroneStack_PID_2021a_DW.doneDoubleBufferReInit_h
                    section.data(23).logicalSrcIdx = 230;
                    section.data(23).dtTransOffset = 27;

                    ;% QD2_DroneStack_PID_2021a_DW.doneDoubleBufferReInit_i
                    section.data(24).logicalSrcIdx = 231;
                    section.data(24).dtTransOffset = 28;

                    ;% QD2_DroneStack_PID_2021a_DW.doneDoubleBufferReInit_l
                    section.data(25).logicalSrcIdx = 232;
                    section.data(25).dtTransOffset = 29;

                    ;% QD2_DroneStack_PID_2021a_DW.doneDoubleBufferReInit_hj
                    section.data(26).logicalSrcIdx = 233;
                    section.data(26).dtTransOffset = 30;

                    ;% QD2_DroneStack_PID_2021a_DW.doneDoubleBufferReInit_af
                    section.data(27).logicalSrcIdx = 234;
                    section.data(27).dtTransOffset = 31;

                    ;% QD2_DroneStack_PID_2021a_DW.ms_time_prev_not_empty
                    section.data(28).logicalSrcIdx = 235;
                    section.data(28).dtTransOffset = 32;

                    ;% QD2_DroneStack_PID_2021a_DW.doneDoubleBufferReInit_d
                    section.data(29).logicalSrcIdx = 236;
                    section.data(29).dtTransOffset = 33;

                    ;% QD2_DroneStack_PID_2021a_DW.doneDoubleBufferReInit_k
                    section.data(30).logicalSrcIdx = 237;
                    section.data(30).dtTransOffset = 34;

                    ;% QD2_DroneStack_PID_2021a_DW.doneDoubleBufferReInit_b3
                    section.data(31).logicalSrcIdx = 238;
                    section.data(31).dtTransOffset = 35;

                    ;% QD2_DroneStack_PID_2021a_DW.doneDoubleBufferReInit_o
                    section.data(32).logicalSrcIdx = 239;
                    section.data(32).dtTransOffset = 36;

            nTotData = nTotData + section.nData;
            dworkMap.sections(14) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_DW.HILWriteDigital_Buffer
                    section.data(1).logicalSrcIdx = 240;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(15) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_DW.CoreSubsys_pn[1].sfEvent
                    section.data(1).logicalSrcIdx = 241;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(16) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_DW.CoreSubsys_pn[1].Integrator1_DWORK1
                    section.data(1).logicalSrcIdx = 242;
                    section.data(1).dtTransOffset = 0;

                    ;% QD2_DroneStack_PID_2021a_DW.CoreSubsys_pn[1].Integrator1_DWORK1_n
                    section.data(2).logicalSrcIdx = 243;
                    section.data(2).dtTransOffset = 1;

                    ;% QD2_DroneStack_PID_2021a_DW.CoreSubsys_pn[1].doneDoubleBufferReInit
                    section.data(3).logicalSrcIdx = 244;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(17) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_DW.UsedesiredYwhenenabled.Usedesiredheightwhenenabled_Sub
                    section.data(1).logicalSrcIdx = 245;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(18) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_DW.UsedesiredYwhenenabled.Usedesiredheightwhenenabled_MOD
                    section.data(1).logicalSrcIdx = 246;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(19) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_DW.UsedesiredXwhenenabled.Usedesiredheightwhenenabled_Sub
                    section.data(1).logicalSrcIdx = 247;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(20) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_DW.UsedesiredXwhenenabled.Usedesiredheightwhenenabled_MOD
                    section.data(1).logicalSrcIdx = 248;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(21) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_DW.Usedesyawwhenenabled.Usedesiredheightwhenenabled_Sub
                    section.data(1).logicalSrcIdx = 249;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(22) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_DW.Usedesyawwhenenabled.Usedesiredheightwhenenabled_MOD
                    section.data(1).logicalSrcIdx = 250;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(23) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_DW.Usedesheightwhenenabled.Usedesiredheightwhenenabled_Sub
                    section.data(1).logicalSrcIdx = 251;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(24) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_DW.Usedesheightwhenenabled.Usedesiredheightwhenenabled_MOD
                    section.data(1).logicalSrcIdx = 252;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(25) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_DW.Usedesiredheightwhenenabled_c.Usedesiredheightwhenenabled_Sub
                    section.data(1).logicalSrcIdx = 253;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(26) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_DW.Usedesiredheightwhenenabled_c.Usedesiredheightwhenenabled_MOD
                    section.data(1).logicalSrcIdx = 254;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(27) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_DW.CoreSubsys_p[8].TriggeredSubsystem_SubsysRanBC
                    section.data(1).logicalSrcIdx = 255;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(28) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% QD2_DroneStack_PID_2021a_DW.CoreSubsys[2].TriggeredSubsystem1_SubsysRanBC
                    section.data(1).logicalSrcIdx = 256;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(29) = section;
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


    targMap.checksum0 = 819505525;
    targMap.checksum1 = 4166959094;
    targMap.checksum2 = 2689178127;
    targMap.checksum3 = 3169523502;

