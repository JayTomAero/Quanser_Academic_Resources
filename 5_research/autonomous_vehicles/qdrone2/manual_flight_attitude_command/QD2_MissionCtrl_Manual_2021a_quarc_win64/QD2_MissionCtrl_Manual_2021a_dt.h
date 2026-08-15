/*
 * QD2_MissionCtrl_Manual_2021a_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "QD2_MissionCtrl_Manual_2021a".
 *
 * Model version              : 2.0
 * Simulink Coder version : 26.1 (R2026a) 20-Nov-2025
 * C source code generated on : Fri Aug 14 17:12:13 2026
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
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
  sizeof(t_timeout),
  sizeof(t_pstream),
  sizeof(qthread_section_t),
  sizeof(t_game_controller_states),
  sizeof(t_extmode_svr_connected_handle),
  sizeof(t_uint64),
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
  "t_timeout",
  "t_pstream",
  "qthread_section_t",
  "t_game_controller_states",
  "t_extmode_svr_connected_handle",
  "t_uint64",
  "uint_T",
  "char_T",
  "uchar_T",
  "time_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&QD2_MissionCtrl_Manual_2021a_B.DataTypeConversion), 0, 0, 53 },

  { (char_T *)(&QD2_MissionCtrl_Manual_2021a_B.HostInitialize_o2), 6, 0, 1 },

  { (char_T *)(&QD2_MissionCtrl_Manual_2021a_B.HostInitialize_o1), 3, 0, 81 },

  { (char_T *)(&QD2_MissionCtrl_Manual_2021a_B.HostGameController_o1), 8, 0, 40
  }
  ,

  { (char_T *)(&QD2_MissionCtrl_Manual_2021a_DW.HostGameController_ControllerSt),
    18, 0, 1 },

  { (char_T *)(&QD2_MissionCtrl_Manual_2021a_DW.HostGameController_Lock), 17, 0,
    1 },

  { (char_T *)(&QD2_MissionCtrl_Manual_2021a_DW.Time_Timeout), 15, 0, 2 },

  { (char_T *)(&QD2_MissionCtrl_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE),
    0, 0, 5 },

  { (char_T *)(&QD2_MissionCtrl_Manual_2021a_DW.StreamServer_Stream), 16, 0, 1 },

  { (char_T *)(&QD2_MissionCtrl_Manual_2021a_DW.HostInitialize_ConnectedHandle),
    19, 0, 1 },

  { (char_T *)(&QD2_MissionCtrl_Manual_2021a_DW.ToHostFile_PointsWritten), 20, 0,
    1 },

  { (char_T *)(&QD2_MissionCtrl_Manual_2021a_DW.Scope_PWORK.LoggedData), 11, 0,
    3 },

  { (char_T *)(&QD2_MissionCtrl_Manual_2021a_DW.sfEvent), 6, 0, 1 },

  { (char_T *)(&QD2_MissionCtrl_Manual_2021a_DW.ToHostFile_SamplesCount), 7, 0,
    2 },

  { (char_T *)(&QD2_MissionCtrl_Manual_2021a_DW.StringDisplay_IWORK[0]), 10, 0,
    2 },

  { (char_T *)(&QD2_MissionCtrl_Manual_2021a_DW.DiscreteTimeIntegrator_PrevRese),
    2, 0, 7 },

  { (char_T *)(&QD2_MissionCtrl_Manual_2021a_DW.HostGameController_NewData), 8,
    0, 6 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  17U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&QD2_MissionCtrl_Manual_2021a_P.CompareToConstant_const), 0, 0,
    10 },

  { (char_T *)(&QD2_MissionCtrl_Manual_2021a_P.StringDisplay_alignment), 3, 0, 2
  },

  { (char_T *)(&QD2_MissionCtrl_Manual_2021a_P.Yaw_Y0), 0, 0, 40 },

  { (char_T *)(&QD2_MissionCtrl_Manual_2021a_P.HostInitialize_SendBufferSize), 6,
    0, 7 },

  { (char_T *)(&QD2_MissionCtrl_Manual_2021a_P.StreamServer_SndSize), 7, 0, 6 },

  { (char_T *)(&QD2_MissionCtrl_Manual_2021a_P.EmergencyAbortbool_Y0), 8, 0, 11
  },

  { (char_T *)(&QD2_MissionCtrl_Manual_2021a_P.HostGameController_Controller), 2,
    0, 5 },

  { (char_T *)(&QD2_MissionCtrl_Manual_2021a_P.HostInitialize_URI), 3, 0, 105 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  8U,
  rtPTransitions
};

/* [EOF] QD2_MissionCtrl_Manual_2021a_dt.h */
