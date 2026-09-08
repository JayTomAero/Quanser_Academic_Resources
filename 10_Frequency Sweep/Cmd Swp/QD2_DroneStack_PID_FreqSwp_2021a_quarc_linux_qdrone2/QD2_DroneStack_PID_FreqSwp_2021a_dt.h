/*
 * QD2_DroneStack_PID_FreqSwp_2021a_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "QD2_DroneStack_PID_FreqSwp_2021a".
 *
 * Model version              : 11.17
 * Simulink Coder version : 26.1 (R2026a) 20-Nov-2025
 * C source code generated on : Tue Sep  8 15:03:35 2026
 *
 * Target selection: quarc_linux_qdrone2.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(int32_T),
  sizeof(int64_T),
  sizeof(uint64_T),
  sizeof(intmax_t),
  sizeof(ptrdiff_t),
  sizeof(size_t),
  sizeof(t_int64),
  sizeof(t_uint64),
  sizeof(t_wide_char),
  sizeof(t_timeout),
  sizeof(t_pstream),
  sizeof(t_ranging_sensor),
  sizeof(t_ranging_measurement),
  sizeof(t_card),
  sizeof(t_boolean),
  sizeof(uint64_T),
  sizeof(int64_T),
  sizeof(uint_T),
  sizeof(char_T),
  sizeof(uchar_T),
  sizeof(time_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "physical_connection",
  "int64_T",
  "uint64_T",
  "intmax_t",
  "ptrdiff_t",
  "size_t",
  "t_int64",
  "t_uint64",
  "t_wide_char",
  "t_timeout",
  "t_pstream",
  "t_ranging_sensor",
  "t_ranging_measurement",
  "t_card",
  "t_boolean",
  "uint64_T",
  "int64_T",
  "uint_T",
  "char_T",
  "uchar_T",
  "time_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_20_B.HILRead_o1[0]), 0, 0, 521 },

  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_20_B.StreamClient_o2), 6, 0, 3 },

  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_20_B.ModelArgument[0]), 3, 0, 322 },

  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_20_B.DataTypeConversion_pb[0]), 8, 0,
    69 },

  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_20_B.CoreSubsys_pn[1].Gain1[0]), 0, 0,
    19 },

  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_20_B.UsedesiredYwhenenabled.h_dm1), 0,
    0, 1 },

  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_20_B.UsedesiredXwhenenabled.h_dm1), 0,
    0, 1 },

  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_20_B.Usedesyawwhenenabled.h_dm1), 0,
    0, 1 },

  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_20_B.Usedesheightwhenenabled.h_dm1),
    0, 0, 1 },

  { (char_T *)
    (&QD2_DroneStack_PID_FreqSwp_20_B.Usedesiredheightwhenenabled_c.h_dm1), 0, 0,
    1 },

  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_20_B.CoreSubsys_p[8].Print_o2), 6, 0,
    1 },

  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_20_B.CoreSubsys[2].Print_o2), 6, 0, 1
  }
  ,

  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_2_DW.RangingSensor_Measurements), 26,
    0, 1 },

  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_2_DW.Time_Timeout), 23, 0, 14 },

  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_2_DW.DiscreteTimeIntegrator_DSTATE),
    0, 0, 339 },

  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_2_DW.ToHostFile_PointsWritten), 21, 0,
    4 },

  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_2_DW.StreamClient_Stream), 24, 0, 2 },

  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_2_DW.RangingSensor_Sensor), 25, 0, 1
  },

  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_2_DW.HILInitialize_Card), 27, 0, 1 },

  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_2_DW.HILRead_PWORK), 11, 0, 67 },

  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_2_DW.HILInitialize_DOStates[0]), 6, 0,
    44 },

  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_2_DW.HILInitialize_POSortedChans[0]),
    7, 0, 14 },

  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_2_DW.StringDisplay_IWORK[0]), 10, 0,
    2 },

  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_2_DW.DiscreteTimeIntegrator_PrevRese),
    2, 0, 24 },

  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_2_DW.ContinuousSigmoid_Flag), 3, 0, 5
  },

  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_2_DW.HILInitialize_DOBits[0]), 8, 0,
    44 },

  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_2_DW.HILWriteDigital_Buffer[0]), 28,
    0, 6 },

  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_2_DW.CoreSubsys_pn[1].sfEvent), 6, 0,
    1 },

  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_2_DW.CoreSubsys_pn[1].
               Integrator1_DWORK1), 8, 0, 3 },

  { (char_T *)
    (&QD2_DroneStack_PID_FreqSwp_2_DW.UsedesiredYwhenenabled.Usedesiredheightwhenenabled_Sub),
    2, 0, 1 },

  { (char_T *)
    (&QD2_DroneStack_PID_FreqSwp_2_DW.UsedesiredYwhenenabled.Usedesiredheightwhenenabled_MOD),
    8, 0, 1 },

  { (char_T *)
    (&QD2_DroneStack_PID_FreqSwp_2_DW.UsedesiredXwhenenabled.Usedesiredheightwhenenabled_Sub),
    2, 0, 1 },

  { (char_T *)
    (&QD2_DroneStack_PID_FreqSwp_2_DW.UsedesiredXwhenenabled.Usedesiredheightwhenenabled_MOD),
    8, 0, 1 },

  { (char_T *)
    (&QD2_DroneStack_PID_FreqSwp_2_DW.Usedesyawwhenenabled.Usedesiredheightwhenenabled_Sub),
    2, 0, 1 },

  { (char_T *)
    (&QD2_DroneStack_PID_FreqSwp_2_DW.Usedesyawwhenenabled.Usedesiredheightwhenenabled_MOD),
    8, 0, 1 },

  { (char_T *)
    (&QD2_DroneStack_PID_FreqSwp_2_DW.Usedesheightwhenenabled.Usedesiredheightwhenenabled_Sub),
    2, 0, 1 },

  { (char_T *)
    (&QD2_DroneStack_PID_FreqSwp_2_DW.Usedesheightwhenenabled.Usedesiredheightwhenenabled_MOD),
    8, 0, 1 },

  { (char_T *)
    (&QD2_DroneStack_PID_FreqSwp_2_DW.Usedesiredheightwhenenabled_c.Usedesiredheightwhenenabled_Sub),
    2, 0, 1 },

  { (char_T *)
    (&QD2_DroneStack_PID_FreqSwp_2_DW.Usedesiredheightwhenenabled_c.Usedesiredheightwhenenabled_MOD),
    8, 0, 1 },

  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_2_DW.CoreSubsys_p[8].
               TriggeredSubsystem_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_2_DW.CoreSubsys[2].
               TriggeredSubsystem1_SubsysRanBC), 2, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  41U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_20_P.KT[0]), 0, 0, 77 },

  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_20_P.CompareToConstant1_const_m), 6,
    0, 1 },

  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_20_P.HILRead_analog_channels[0]), 7,
    0, 36 },

  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_20_P.StopwithMessage_message_icon), 2,
    0, 3 },

  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_20_P.StringDisplay_alignment), 3, 0,
    3 },

  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_20_P.Constant4_Value), 0, 0, 458 },

  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_20_P.HILInitialize_DOWatchdog[0]), 6,
    0, 23 },

  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_20_P.Print_MaxUnits), 7, 0, 43 },

  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_20_P.Print_Active), 8, 0, 49 },

  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_20_P.StreamClient_Optimize), 2, 0, 13
  },

  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_20_P.StringConstant8_Value[0]), 3, 0,
    2094 },

  { (char_T *)
    (&QD2_DroneStack_PID_FreqSwp_20_P.CoreSubsys_pna.CompareToConstant_const), 0,
    0, 1 },

  { (char_T *)
    (&QD2_DroneStack_PID_FreqSwp_20_P.CoreSubsys_pn.AccelerometerFilterCutoffFreque),
    0, 0, 15 },

  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_20_P.UsedesiredYwhenenabled.Out1_Y0),
    0, 0, 1 },

  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_20_P.UsedesiredXwhenenabled.Out1_Y0),
    0, 0, 1 },

  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_20_P.Usedesyawwhenenabled.Out1_Y0), 0,
    0, 1 },

  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_20_P.Usedesheightwhenenabled.Out1_Y0),
    0, 0, 1 },

  { (char_T *)
    (&QD2_DroneStack_PID_FreqSwp_20_P.Usedesiredheightwhenenabled_c.Out1_Y0), 0,
    0, 1 },

  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_20_P.CoreSubsys_p.Print_MaxUnits), 7,
    0, 1 },

  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_20_P.CoreSubsys_p.Print_Active), 8, 0,
    1 },

  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_20_P.CoreSubsys.Print_MaxUnits), 7, 0,
    1 },

  { (char_T *)(&QD2_DroneStack_PID_FreqSwp_20_P.CoreSubsys.Print_Active), 8, 0,
    1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  22U,
  rtPTransitions
};

/* [EOF] QD2_DroneStack_PID_FreqSwp_2021a_dt.h */
