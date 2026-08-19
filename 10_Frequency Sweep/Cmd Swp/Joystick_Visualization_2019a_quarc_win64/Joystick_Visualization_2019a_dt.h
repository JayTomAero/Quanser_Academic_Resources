/*
 * Joystick_Visualization_2019a_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Joystick_Visualization_2019a".
 *
 * Model version              : 3.0
 * Simulink Coder version : 26.1 (R2026a) 20-Nov-2025
 * C source code generated on : Tue Aug  4 15:02:52 2026
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
  sizeof(qthread_section_t),
  sizeof(t_game_controller_states),
  sizeof(t_extmode_svr_connected_handle),
  sizeof(t_visualization),
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
  "qthread_section_t",
  "t_game_controller_states",
  "t_extmode_svr_connected_handle",
  "t_visualization",
  "uint_T",
  "char_T",
  "uchar_T",
  "time_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&Joystick_Visualization_2019a_B.ContinuousSigmoid_o1), 0, 0, 156
  },

  { (char_T *)(&Joystick_Visualization_2019a_B.HostInitialize_o2), 6, 0, 1 },

  { (char_T *)(&Joystick_Visualization_2019a_B.HostInitialize_o1), 3, 0, 1 },

  { (char_T *)(&Joystick_Visualization_2019a_B.HostGameController_o1), 8, 0, 38
  },

  { (char_T *)(&Joystick_Visualization_2019a_B.UsedesiredYwhenenabled.h_dm1), 0,
    0, 1 },

  { (char_T *)(&Joystick_Visualization_2019a_B.UsedesiredXwhenenabled.h_dm1), 0,
    0, 1 },

  { (char_T *)(&Joystick_Visualization_2019a_B.Usedesyawwhenenabled.h_dm1), 0, 0,
    1 },

  { (char_T *)(&Joystick_Visualization_2019a_B.Usedesheightwhenenabled.h_dm1), 0,
    0, 1 }
  ,

  { (char_T *)(&Joystick_Visualization_2019a_DW.HostGameController_ControllerSt),
    16, 0, 1 },

  { (char_T *)(&Joystick_Visualization_2019a_DW.HostGameController_Lock), 15, 0,
    1 },

  { (char_T *)(&Joystick_Visualization_2019a_DW.DiscreteTimeIntegrator_DSTATE),
    0, 0, 76 },

  { (char_T *)(&Joystick_Visualization_2019a_DW.HostInitialize_ConnectedHandle),
    17, 0, 1 },

  { (char_T *)(&Joystick_Visualization_2019a_DW.VisualizationInitialize_Visuali),
    18, 0, 1 },

  { (char_T *)(&Joystick_Visualization_2019a_DW.VisualizationInitialize_PWORK[0]),
    11, 0, 3 },

  { (char_T *)(&Joystick_Visualization_2019a_DW.sfEvent), 6, 0, 5 },

  { (char_T *)(&Joystick_Visualization_2019a_DW.DiscreteTimeIntegrator_PrevRese),
    2, 0, 5 },

  { (char_T *)(&Joystick_Visualization_2019a_DW.ContinuousSigmoid_Flag), 3, 0, 4
  },

  { (char_T *)(&Joystick_Visualization_2019a_DW.HostGameController_NewData), 8,
    0, 7 },

  { (char_T *)
    (&Joystick_Visualization_2019a_DW.UsedesiredYwhenenabled.Usedesheightwhenenabled_SubsysR),
    2, 0, 1 },

  { (char_T *)
    (&Joystick_Visualization_2019a_DW.UsedesiredYwhenenabled.Usedesheightwhenenabled_MODE),
    8, 0, 1 },

  { (char_T *)
    (&Joystick_Visualization_2019a_DW.UsedesiredXwhenenabled.Usedesheightwhenenabled_SubsysR),
    2, 0, 1 },

  { (char_T *)
    (&Joystick_Visualization_2019a_DW.UsedesiredXwhenenabled.Usedesheightwhenenabled_MODE),
    8, 0, 1 },

  { (char_T *)
    (&Joystick_Visualization_2019a_DW.Usedesyawwhenenabled.Usedesheightwhenenabled_SubsysR),
    2, 0, 1 },

  { (char_T *)
    (&Joystick_Visualization_2019a_DW.Usedesyawwhenenabled.Usedesheightwhenenabled_MODE),
    8, 0, 1 },

  { (char_T *)
    (&Joystick_Visualization_2019a_DW.Usedesheightwhenenabled.Usedesheightwhenenabled_SubsysR),
    2, 0, 1 },

  { (char_T *)
    (&Joystick_Visualization_2019a_DW.Usedesheightwhenenabled.Usedesheightwhenenabled_MODE),
    8, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  26U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Joystick_Visualization_2019a_P.CompareToConstant_const), 0, 0, 5
  },

  { (char_T *)(&Joystick_Visualization_2019a_P.VisualizationInitialize_client_),
    6, 0, 4 },

  { (char_T *)(&Joystick_Visualization_2019a_P.VisualizationInitialize_initial[0]),
    1, 0, 48 },

  { (char_T *)(&Joystick_Visualization_2019a_P.VisualizationInitialize_variabl[0]),
    7, 0, 3 },

  { (char_T *)(&Joystick_Visualization_2019a_P.VisualizationInitialize_close_o),
    8, 0, 1 },

  { (char_T *)(&Joystick_Visualization_2019a_P.Yaw_Y0), 0, 0, 164 },

  { (char_T *)(&Joystick_Visualization_2019a_P.HostGameController_BufferSize), 6,
    0, 4 },

  { (char_T *)(&Joystick_Visualization_2019a_P.EmergencyAbortbool_Y0), 8, 0, 10
  },

  { (char_T *)(&Joystick_Visualization_2019a_P.HostGameController_Controller), 2,
    0, 1 },

  { (char_T *)(&Joystick_Visualization_2019a_P.ManualSwitch1_CurrentSetting), 3,
    0, 2 },

  { (char_T *)(&Joystick_Visualization_2019a_P.UsedesiredYwhenenabled.Out1_Y0),
    0, 0, 1 },

  { (char_T *)(&Joystick_Visualization_2019a_P.UsedesiredXwhenenabled.Out1_Y0),
    0, 0, 1 },

  { (char_T *)(&Joystick_Visualization_2019a_P.Usedesyawwhenenabled.Out1_Y0), 0,
    0, 1 },

  { (char_T *)(&Joystick_Visualization_2019a_P.Usedesheightwhenenabled.Out1_Y0),
    0, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  14U,
  rtPTransitions
};

/* [EOF] Joystick_Visualization_2019a_dt.h */
