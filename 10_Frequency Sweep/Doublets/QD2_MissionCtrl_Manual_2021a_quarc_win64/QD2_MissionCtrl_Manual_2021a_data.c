/*
 * QD2_MissionCtrl_Manual_2021a_data.c
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

#include "QD2_MissionCtrl_Manual_2021a.h"

/* Block parameters (default storage) */
P_QD2_MissionCtrl_Manual_2021_T QD2_MissionCtrl_Manual_2021a_P = {
  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S15>/Constant'
   */
  -0.5,

  /* Mask Parameter: CompareToConstant_const_f
   * Referenced by: '<S19>/Constant'
   */
  1.0,

  /* Mask Parameter: StreamServer_default_value
   * Referenced by: '<S1>/Stream Server'
   */
  { 0.0, 0.0 },

  /* Mask Parameter: Threshold_duration
   * Referenced by: '<S16>/duration'
   */
  0.2,

  /* Mask Parameter: Threshold_duration_d
   * Referenced by: '<S14>/duration'
   */
  0.2,

  /* Mask Parameter: Threshold_duration_b
   * Referenced by: '<S7>/duration'
   */
  0.1,

  /* Mask Parameter: Threshold_threshold
   * Referenced by: '<S16>/threshold'
   */
  0.5,

  /* Mask Parameter: Threshold_threshold_h
   * Referenced by: '<S14>/threshold'
   */
  0.5,

  /* Mask Parameter: Threshold_threshold_d
   * Referenced by: '<S7>/threshold'
   */
  0.5,

  /* Mask Parameter: StringDisplay_alignment
   * Referenced by: '<S1>/String Display '
   */
  2U,

  /* Mask Parameter: StringDisplay_display_mode
   * Referenced by: '<S1>/String Display '
   */
  1U,

  /* Computed Parameter: Yaw_Y0
   * Referenced by: '<S11>/Yaw (%)'
   */
  0.0,

  /* Computed Parameter: Throttle_Y0
   * Referenced by: '<S11>/Throttle (%)'
   */
  0.0,

  /* Computed Parameter: Roll_Y0
   * Referenced by: '<S11>/Roll (%)'
   */
  0.0,

  /* Computed Parameter: Pitch_Y0
   * Referenced by: '<S11>/Pitch (%)'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S16>/Discrete-Time Integrator'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<S16>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S11>/Gain'
   */
  -1.0,

  /* Expression: 0.5
   * Referenced by: '<S11>/Gain1'
   */
  0.5,

  /* Expression: 0.5
   * Referenced by: '<S11>/Bias'
   */
  0.5,

  /* Expression: 0
   * Referenced by: '<S12>/Joystick Issue (0,1)'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S12>/Triggers (0,1) [4]'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S12>/Commands (%) [4]'
   */
  0.0,

  /* Expression: -0.01
   * Referenced by: '<S12>/Dead Zone'
   */
  -0.01,

  /* Expression: 0.01
   * Referenced by: '<S12>/Dead Zone'
   */
  0.01,

  /* Computed Parameter: NumberofPulses_Y0
   * Referenced by: '<S17>/Number of Pulses'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S17>/Constant1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S18>/FixPt Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S17>/Unit Delay'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S13>/Pulse Check'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S10>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S10>/Memory'
   */
  0.0,

  /* Expression: -1*ones(1,6)
   * Referenced by: '<S8>/Constant'
   */
  { -1.0, -1.0, -1.0, -1.0, -1.0, -1.0 },

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_b
   * Referenced by: '<S14>/Discrete-Time Integrator'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<S14>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S2>/Manual Flight Mode 1 - Torque Mode,   0 - Angle Mode'
   */
  1.0,

  /* Expression: 20.44
   * Referenced by: '<S9>/Max Thrust is 20.44 N'
   */
  20.44,

  /* Expression: [1.0915 0.8984 0.0984]
   * Referenced by: '<S9>/+//- 1.0915 Nm for Roll +//- 0.8984 Nm for Pitch +//- 0.0984 Nm for Yaw'
   */
  { 1.0915, 0.8984, 0.0984 },

  /* Expression: [pi/4 pi/4 pi/2]
   * Referenced by: '<S9>/+//- pi//4 rad for Roll//Pitch +//- pi//2 rad//s for Yaw Rate'
   */
  { 0.78539816339744828, 0.78539816339744828, 1.5707963267948966 },

  /* Expression: 1
   * Referenced by: '<S1>/Constant'
   */
  1.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_n
   * Referenced by: '<S7>/Discrete-Time Integrator'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<S7>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: HostInitialize_SendBufferSize
   * Referenced by: '<S8>/Host Initialize'
   */
  1000,

  /* Computed Parameter: HostInitialize_ReceiveBufferSiz
   * Referenced by: '<S8>/Host Initialize'
   */
  1000,

  /* Computed Parameter: HostInitialize_ThreadPriority
   * Referenced by: '<S8>/Host Initialize'
   */
  0,

  /* Computed Parameter: HostGameController_BufferSize
   * Referenced by: '<S8>/Host Game Controller'
   */
  20,

  /* Computed Parameter: StreamServer_SndPriority
   * Referenced by: '<S1>/Stream Server'
   */
  0,

  /* Computed Parameter: StreamServer_RcvPriority
   * Referenced by: '<S1>/Stream Server'
   */
  0,

  /* Computed Parameter: ToHostFile_Encoding
   * Referenced by: '<S2>/To Host File'
   */
  1,

  /* Computed Parameter: StreamServer_SndSize
   * Referenced by: '<S1>/Stream Server'
   */
  1460U,

  /* Computed Parameter: StreamServer_RcvSize
   * Referenced by: '<S1>/Stream Server'
   */
  1460U,

  /* Computed Parameter: StreamServer_SndFIFO
   * Referenced by: '<S1>/Stream Server'
   */
  1000U,

  /* Computed Parameter: StreamServer_RcvFIFO
   * Referenced by: '<S1>/Stream Server'
   */
  1000U,

  /* Computed Parameter: ToHostFile_Decimation
   * Referenced by: '<S2>/To Host File'
   */
  1U,

  /* Computed Parameter: ToHostFile_BitRate
   * Referenced by: '<S2>/To Host File'
   */
  2000000U,

  /* Computed Parameter: EmergencyAbortbool_Y0
   * Referenced by: '<S11>/Emergency Abort (bool)'
   */
  false,

  /* Computed Parameter: ArmDisarmbool_Y0
   * Referenced by: '<S11>/Arm//Disarm (bool) '
   */
  false,

  /* Computed Parameter: TakeoffAutolandbool_Y0
   * Referenced by: '<S11>/Takeoff//Autoland (bool)'
   */
  false,

  /* Computed Parameter: CommunicationIssue01_Y0
   * Referenced by: '<S10>/Communication Issue (0,1)'
   */
  false,

  /* Computed Parameter: HostInitialize_RunClient
   * Referenced by: '<S8>/Host Initialize'
   */
  true,

  /* Computed Parameter: HostInitialize_UseWindow
   * Referenced by: '<S8>/Host Initialize'
   */
  false,

  /* Computed Parameter: HostInitialize_Active
   * Referenced by: '<S8>/Host Initialize'
   */
  true,

  /* Computed Parameter: HostGameController_AutoCenter
   * Referenced by: '<S8>/Host Game Controller'
   */
  false,

  /* Computed Parameter: HostGameController_Enabled
   * Referenced by: '<S8>/Host Game Controller'
   */
  true,

  /* Computed Parameter: HostGameController_DebugMode
   * Referenced by: '<S8>/Host Game Controller'
   */
  false,

  /* Computed Parameter: StreamServer_Active
   * Referenced by: '<S1>/Stream Server'
   */
  false,

  /* Computed Parameter: HostGameController_Controller
   * Referenced by: '<S8>/Host Game Controller'
   */
  1,

  /* Computed Parameter: StreamServer_Optimize
   * Referenced by: '<S1>/Stream Server'
   */
  2,

  /* Computed Parameter: StreamServer_Implementation
   * Referenced by: '<S1>/Stream Server'
   */
  2,

  /* Computed Parameter: ShowMessageonHost_MsgIcon
   * Referenced by: '<S2>/Show Message on Host'
   */
  2,

  /* Computed Parameter: ShowMessageonHost_MsgIcon_p
   * Referenced by: '<S2>/Show Message on Host '
   */
  2,

  /* Expression: uri_argument
   * Referenced by: '<S8>/Host Initialize'
   */
  0U,

  /* Computed Parameter: ManualSwitch1_CurrentSetting
   * Referenced by: '<S2>/Manual Switch1'
   */
  1U,

  /* Expression: uri_argument
   * Referenced by: '<S1>/Stream Server'
   */
  0U,

  /* Computed Parameter: StreamServer_Endian
   * Referenced by: '<S1>/Stream Server'
   */
  1U,

  /* Expression: variable_name_argument
   * Referenced by: '<S2>/To Host File'
   */
  { 109U, 105U, 115U, 115U, 105U, 111U, 110U, 95U, 115U, 101U, 114U, 118U, 101U,
    114U, 95U, 100U, 97U, 116U, 97U, 0U },

  /* Computed Parameter: ToHostFile_FileFormat
   * Referenced by: '<S2>/To Host File'
   */
  2U,

  /* Expression: file_name_argument
   * Referenced by: '<S2>/To Host File'
   */
  { 115U, 97U, 118U, 101U, 100U, 95U, 100U, 97U, 116U, 97U, 47U, 81U, 68U, 50U,
    95U, 77U, 105U, 115U, 115U, 105U, 111U, 110U, 67U, 116U, 114U, 108U, 95U,
    77U, 97U, 110U, 117U, 97U, 108U, 95U, 50U, 48U, 50U, 49U, 97U, 47U, 108U,
    111U, 103U, 95U, 50U, 48U, 50U, 54U, 45U, 48U, 56U, 45U, 49U, 52U, 95U, 49U,
    55U, 45U, 49U, 50U, 45U, 49U, 50U, 95U, 77U, 105U, 115U, 115U, 105U, 111U,
    110U, 67U, 116U, 114U, 108U, 46U, 109U, 97U, 116U, 0U }
};
