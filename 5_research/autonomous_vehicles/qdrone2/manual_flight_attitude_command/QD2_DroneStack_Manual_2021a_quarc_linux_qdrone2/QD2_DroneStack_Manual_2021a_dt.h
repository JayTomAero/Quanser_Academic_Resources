/*
 * QD2_DroneStack_Manual_2021a_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "QD2_DroneStack_Manual_2021a".
 *
 * Model version              : 3.0
 * Simulink Coder version : 26.1 (R2026a) 20-Nov-2025
 * C source code generated on : Fri Aug 14 17:12:33 2026
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
  sizeof(t_pstream),
  sizeof(t_ranging_sensor),
  sizeof(t_ranging_measurement),
  sizeof(t_timeout),
  sizeof(t_uint64),
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
  "t_pstream",
  "t_ranging_sensor",
  "t_ranging_measurement",
  "t_timeout",
  "t_uint64",
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
  { (char_T *)(&QD2_DroneStack_Manual_2021a_B.HILRead_o1[0]), 0, 0, 258 },

  { (char_T *)(&QD2_DroneStack_Manual_2021a_B.DataTypeConversion_ko), 7, 0, 1 },

  { (char_T *)(&QD2_DroneStack_Manual_2021a_B.RateTransition14), 6, 0, 1 },

  { (char_T *)(&QD2_DroneStack_Manual_2021a_B.IPAddressofSupervisoryModelMiss[0]),
    3, 0, 82 },

  { (char_T *)(&QD2_DroneStack_Manual_2021a_B.AND[0]), 8, 0, 15 },

  { (char_T *)(&QD2_DroneStack_Manual_2021a_B.CoreSubsys[1].Gain1[0]), 0, 0, 19
  }
  ,

  { (char_T *)(&QD2_DroneStack_Manual_2021a_DW.RangingSensor_Measurements), 19,
    0, 1 },

  { (char_T *)(&QD2_DroneStack_Manual_2021a_DW.Time_Timeout), 20, 0, 13 },

  { (char_T *)(&QD2_DroneStack_Manual_2021a_DW.Delay_DSTATE), 0, 0, 184 },

  { (char_T *)(&QD2_DroneStack_Manual_2021a_DW.StreamClient_Stream), 17, 0, 2 },

  { (char_T *)(&QD2_DroneStack_Manual_2021a_DW.RangingSensor_Sensor), 18, 0, 1 },

  { (char_T *)(&QD2_DroneStack_Manual_2021a_DW.ToHostFile_PointsWritten), 21, 0,
    2 },

  { (char_T *)(&QD2_DroneStack_Manual_2021a_DW.HILInitialize_Card), 22, 0, 1 },

  { (char_T *)(&QD2_DroneStack_Manual_2021a_DW.HILRead_PWORK), 11, 0, 33 },

  { (char_T *)(&QD2_DroneStack_Manual_2021a_DW.HILInitialize_DOStates[0]), 6, 0,
    33 },

  { (char_T *)(&QD2_DroneStack_Manual_2021a_DW.HILInitialize_POSortedChans[0]),
    7, 0, 10 },

  { (char_T *)(&QD2_DroneStack_Manual_2021a_DW.StringDisplay_IWORK[0]), 10, 0, 2
  },

  { (char_T *)(&QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_PrevRese),
    2, 0, 8 },

  { (char_T *)(&QD2_DroneStack_Manual_2021a_DW.HILInitialize_DOBits[0]), 8, 0,
    24 },

  { (char_T *)(&QD2_DroneStack_Manual_2021a_DW.HILWriteDigital_Buffer[0]), 23, 0,
    6 },

  { (char_T *)(&QD2_DroneStack_Manual_2021a_DW.CoreSubsys[1].sfEvent), 6, 0, 1 },

  { (char_T *)(&QD2_DroneStack_Manual_2021a_DW.CoreSubsys[1].Integrator1_DWORK1),
    8, 0, 3 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  22U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&QD2_DroneStack_Manual_2021a_P.KT[0]), 0, 0, 46 },

  { (char_T *)(&QD2_DroneStack_Manual_2021a_P.CompareToConstant1_const), 6, 0, 1
  },

  { (char_T *)(&QD2_DroneStack_Manual_2021a_P.HILRead_analog_channels[0]), 7, 0,
    36 },

  { (char_T *)(&QD2_DroneStack_Manual_2021a_P.StopwithMessage_message_icon), 2,
    0, 3 },

  { (char_T *)(&QD2_DroneStack_Manual_2021a_P.StringDisplay_alignment), 3, 0, 3
  },

  { (char_T *)(&QD2_DroneStack_Manual_2021a_P.RedRed_Value[0]), 0, 0, 267 },

  { (char_T *)(&QD2_DroneStack_Manual_2021a_P.HILInitialize_DOWatchdog[0]), 6, 0,
    21 },

  { (char_T *)(&QD2_DroneStack_Manual_2021a_P.HILInitialize_AIChannels[0]), 7, 0,
    38 },

  { (char_T *)(&QD2_DroneStack_Manual_2021a_P.HILWritePWM_Active), 8, 0, 47 },

  { (char_T *)(&QD2_DroneStack_Manual_2021a_P.StreamClient_Optimize), 2, 0, 4 },

  { (char_T *)(&QD2_DroneStack_Manual_2021a_P.StreamClient_URI), 3, 0, 216 },

  { (char_T *)
    (&QD2_DroneStack_Manual_2021a_P.CoreSubsys_p.CompareToConstant_const), 0, 0,
    1 },

  { (char_T *)
    (&QD2_DroneStack_Manual_2021a_P.CoreSubsys.AccelerometerFilterCutoffFreque),
    0, 0, 15 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  13U,
  rtPTransitions
};

/* [EOF] QD2_DroneStack_Manual_2021a_dt.h */
