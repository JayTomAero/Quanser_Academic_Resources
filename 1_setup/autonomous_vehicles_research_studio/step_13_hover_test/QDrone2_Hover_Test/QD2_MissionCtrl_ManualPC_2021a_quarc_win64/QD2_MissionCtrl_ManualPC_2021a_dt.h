/*
 * QD2_MissionCtrl_ManualPC_2021a_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "QD2_MissionCtrl_ManualPC_2021a".
 *
 * Model version              : 3.0
 * Simulink Coder version : 26.1 (R2026a) 20-Nov-2025
 * C source code generated on : Fri Aug 14 16:58:26 2026
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
  sizeof(t_vrpn_client_properties),
  sizeof(t_vrpn_client_tracker),
  sizeof(t_uint64),
  sizeof(uint8_T),
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
  "t_vrpn_client_properties",
  "t_vrpn_client_tracker",
  "t_uint64",
  "uint8_T",
  "uint_T",
  "char_T",
  "uchar_T",
  "time_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&QD2_MissionCtrl_ManualPC_2021_B.DataTypeConversion), 0, 0, 176 },

  { (char_T *)(&QD2_MissionCtrl_ManualPC_2021_B.HostInitialize_o2), 6, 0, 1 },

  { (char_T *)(&QD2_MissionCtrl_ManualPC_2021_B.HostInitialize_o1), 3, 0, 81 },

  { (char_T *)(&QD2_MissionCtrl_ManualPC_2021_B.HostGameController_o1), 8, 0, 50
  },

  { (char_T *)(&QD2_MissionCtrl_ManualPC_2021_B.CoreSubsys_p[1].one_shot_block),
    0, 0, 1 }
  ,

  { (char_T *)(&QD2_MissionCtrl_ManualPC_202_DW.VRPNClient_TrackerData), 21, 0,
    1 },

  { (char_T *)(&QD2_MissionCtrl_ManualPC_202_DW.HostGameController_ControllerSt),
    18, 0, 1 },

  { (char_T *)(&QD2_MissionCtrl_ManualPC_202_DW.HostGameController_Lock), 17, 0,
    1 },

  { (char_T *)(&QD2_MissionCtrl_ManualPC_202_DW.Time_Timeout), 15, 0, 3 },

  { (char_T *)(&QD2_MissionCtrl_ManualPC_202_DW.DiscreteTimeIntegrator_DSTATE),
    0, 0, 46 },

  { (char_T *)(&QD2_MissionCtrl_ManualPC_202_DW.StreamServer_Stream), 16, 0, 1 },

  { (char_T *)(&QD2_MissionCtrl_ManualPC_202_DW.HostInitialize_ConnectedHandle),
    19, 0, 1 },

  { (char_T *)(&QD2_MissionCtrl_ManualPC_202_DW.VRPNClient_VRPNClient), 20, 0, 1
  },

  { (char_T *)(&QD2_MissionCtrl_ManualPC_202_DW.ToHostFile_PointsWritten), 22, 0,
    1 },

  { (char_T *)
    (&QD2_MissionCtrl_ManualPC_202_DW.ManualWaypointCommands_PWORK.LoggedData[0]),
    11, 0, 8 },

  { (char_T *)(&QD2_MissionCtrl_ManualPC_202_DW.sfEvent), 6, 0, 2 },

  { (char_T *)(&QD2_MissionCtrl_ManualPC_202_DW.ToHostFile_SamplesCount), 7, 0,
    2 },

  { (char_T *)(&QD2_MissionCtrl_ManualPC_202_DW.StringDisplay_IWORK[0]), 10, 0,
    2 },

  { (char_T *)(&QD2_MissionCtrl_ManualPC_202_DW.Delay_DSTATE[0]), 8, 0, 8000 },

  { (char_T *)(&QD2_MissionCtrl_ManualPC_202_DW.DiscreteTimeIntegrator_PrevRese),
    2, 0, 8 },

  { (char_T *)(&QD2_MissionCtrl_ManualPC_202_DW.HostGameController_NewData), 8,
    0, 13 },

  { (char_T *)(&QD2_MissionCtrl_ManualPC_202_DW.CoreSubsys_p[1].
               one_shot_block_DSTATE[0]), 0, 0, 3 },

  { (char_T *)(&QD2_MissionCtrl_ManualPC_202_DW.CoreSubsys[0].q00_SubsysRanBC),
    2, 0, 4 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  23U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&QD2_MissionCtrl_ManualPC_2021_P.CompareToConstant_const), 0, 0,
    12 },

  { (char_T *)(&QD2_MissionCtrl_ManualPC_2021_P.VRPNClient_trackers_jpl), 8, 0,
    1 },

  { (char_T *)(&QD2_MissionCtrl_ManualPC_2021_P.StopwithMessage_message_icon), 2,
    0, 1 },

  { (char_T *)(&QD2_MissionCtrl_ManualPC_2021_P.StringDisplay_alignment), 3, 0,
    2 },

  { (char_T *)(&QD2_MissionCtrl_ManualPC_2021_P.HomePosemrad4_Y0), 0, 0, 85 },

  { (char_T *)(&QD2_MissionCtrl_ManualPC_2021_P.HostInitialize_SendBufferSize),
    6, 0, 10 },

  { (char_T *)(&QD2_MissionCtrl_ManualPC_2021_P.StreamServer_SndSize), 7, 0, 6 },

  { (char_T *)(&QD2_MissionCtrl_ManualPC_2021_P.EmergencyAbortbool_Y0), 8, 0, 17
  },

  { (char_T *)(&QD2_MissionCtrl_ManualPC_2021_P.HostGameController_Controller),
    2, 0, 5 },

  { (char_T *)(&QD2_MissionCtrl_ManualPC_2021_P.HostInitialize_URI), 3, 0, 108 },

  { (char_T *)
    (&QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys_p.one_shot_block_trigger_type),
    0, 0, 3 },

  { (char_T *)(&QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Constant_Value), 0, 0,
    61 },

  { (char_T *)(&QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Bias_Bias), 2, 0, 8 },

  { (char_T *)(&QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Gain_Gain_i), 23, 0,
    6 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  14U,
  rtPTransitions
};

/* [EOF] QD2_MissionCtrl_ManualPC_2021a_dt.h */
