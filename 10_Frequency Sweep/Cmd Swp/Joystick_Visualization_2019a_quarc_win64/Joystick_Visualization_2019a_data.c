/*
 * Joystick_Visualization_2019a_data.c
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

#include "Joystick_Visualization_2019a.h"

/* Block parameters (default storage) */
P_Joystick_Visualization_2019_T Joystick_Visualization_2019a_P = {
  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S8>/Constant'
   */
  -0.5,

  /* Mask Parameter: Threshold_duration
   * Referenced by: '<S9>/duration'
   */
  0.2,

  /* Mask Parameter: Threshold_duration_h
   * Referenced by: '<S7>/duration'
   */
  0.2,

  /* Mask Parameter: Threshold_threshold
   * Referenced by: '<S9>/threshold'
   */
  0.5,

  /* Mask Parameter: Threshold_threshold_d
   * Referenced by: '<S7>/threshold'
   */
  0.5,

  /* Mask Parameter: VisualizationInitialize_client_
   * Referenced by: '<S3>/Visualization Initialize'
   */
  1000000,

  /* Mask Parameter: VisualizationInitialize_clien_e
   * Referenced by: '<S3>/Visualization Initialize'
   */
  1000,

  /* Mask Parameter: VisualizationInitialize_server_
   * Referenced by: '<S3>/Visualization Initialize'
   */
  1000,

  /* Mask Parameter: VisualizationInitialize_serve_o
   * Referenced by: '<S3>/Visualization Initialize'
   */
  1000000,

  /* Mask Parameter: VisualizationInitialize_initial
   * Referenced by: '<S3>/Visualization Initialize'
   */
  { 1.0F, 0.0F, -0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 1.0F, 1.0F, 0.0F, -0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 1.0F, 0.0F, -0.0F, 0.0F,
    0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F },

  /* Mask Parameter: VisualizationInitialize_variabl
   * Referenced by: '<S3>/Visualization Initialize'
   */
  { 33U, 43U, 223U },

  /* Mask Parameter: VisualizationInitialize_close_o
   * Referenced by: '<S3>/Visualization Initialize'
   */
  true,

  /* Computed Parameter: Yaw_Y0
   * Referenced by: '<S4>/Yaw (%)'
   */
  0.0,

  /* Computed Parameter: Throttle_Y0
   * Referenced by: '<S4>/Throttle (%)'
   */
  0.0,

  /* Computed Parameter: Roll_Y0
   * Referenced by: '<S4>/Roll (%)'
   */
  0.0,

  /* Computed Parameter: Pitch_Y0
   * Referenced by: '<S4>/Pitch (%)'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S9>/Discrete-Time Integrator'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<S9>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S4>/Gain'
   */
  -1.0,

  /* Expression: 0.5
   * Referenced by: '<S4>/Gain1'
   */
  0.5,

  /* Expression: 0.5
   * Referenced by: '<S4>/Bias'
   */
  0.5,

  /* Expression: 0
   * Referenced by: '<S5>/Joystick Issue (0,1)'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S5>/Triggers (0,1) [4]'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S5>/Commands (%) [4]'
   */
  0.0,

  /* Expression: -0.01
   * Referenced by: '<S5>/Dead Zone'
   */
  -0.01,

  /* Expression: 0.01
   * Referenced by: '<S5>/Dead Zone'
   */
  0.01,

  /* Computed Parameter: NumberofPulses_Y0
   * Referenced by: '<S10>/Number of Pulses'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S10>/Constant1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S11>/FixPt Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S10>/Unit Delay'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S6>/Pulse Check'
   */
  1.0,

  /* Expression: [1 -1 1 1]
   * Referenced by: '<S14>/Gain'
   */
  { 1.0, -1.0, 1.0, 1.0 },

  /* Expression: [1 0 0 0; 0 1 0 0; 0 0 1 0; 0 0 0 1]
   * Referenced by: '<S19>/Constant'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    1.0 },

  /* Expression: [1 0 0; 0 1 0; 0 0 1; 0 0 0]
   * Referenced by: '<S20>/Constant1'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 },

  /* Expression: initial_position
   * Referenced by: '<S22>/Continuous Sigmoid'
   */
  0.0,

  /* Expression: initial_velocity
   * Referenced by: '<S22>/Continuous Sigmoid'
   */
  0.0,

  /* Expression: hold_off
   * Referenced by: '<S22>/Continuous Sigmoid'
   */
  0.5,

  /* Expression: initial_position
   * Referenced by: '<S22>/Continuous Sigmoid1'
   */
  0.0,

  /* Expression: initial_velocity
   * Referenced by: '<S22>/Continuous Sigmoid1'
   */
  0.0,

  /* Expression: hold_off
   * Referenced by: '<S22>/Continuous Sigmoid1'
   */
  0.5,

  /* Expression: initial_position
   * Referenced by: '<S22>/Continuous Sigmoid2'
   */
  0.0,

  /* Expression: initial_velocity
   * Referenced by: '<S22>/Continuous Sigmoid2'
   */
  0.0,

  /* Expression: hold_off
   * Referenced by: '<S22>/Continuous Sigmoid2'
   */
  0.5,

  /* Expression: initial_position
   * Referenced by: '<S22>/Continuous Sigmoid3'
   */
  0.0,

  /* Expression: initial_velocity
   * Referenced by: '<S22>/Continuous Sigmoid3'
   */
  0.0,

  /* Expression: hold_off
   * Referenced by: '<S22>/Continuous Sigmoid3'
   */
  0.5,

  /* Expression: -1*ones(1,6)
   * Referenced by: '<S1>/Constant'
   */
  { -1.0, -1.0, -1.0, -1.0, -1.0, -1.0 },

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_k
   * Referenced by: '<S7>/Discrete-Time Integrator'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<S7>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1>/  m//%  '
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S1>/ m//% '
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S1>/m//%'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Integrator'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S20>/Constant'
   */
  1.0,

  /* Expression: [1 0 0; 0 1 0; 0 0 1; 0 0 0]
   * Referenced by: '<S21>/Constant1'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<S13>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S21>/Constant'
   */
  1.0,

  /* Expression: [1 0 0 0; 0 1 0 0; 0 0 1 0; 0 0 0 1]
   * Referenced by: '<S15>/Constant'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    1.0 },

  /* Expression: 1
   * Referenced by: '<S18>/Constant6'
   */
  1.0,

  /* Expression: [0 0 1]
   * Referenced by: '<S12>/Constant'
   */
  { 0.0, 0.0, 1.0 },

  /* Expression: 0
   * Referenced by: '<S18>/Constant9'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S18>/Constant8'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S18>/Constant7'
   */
  0.0,

  /* Expression: [0 0 0 1]
   * Referenced by: '<S18>/Constant5'
   */
  { 0.0, 0.0, 0.0, 1.0 },

  /* Expression: 0
   * Referenced by: '<S3>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S16>/Constant6'
   */
  1.0,

  /* Expression: [0 1 0]
   * Referenced by: '<S12>/Constant1'
   */
  { 0.0, 1.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<S16>/Constant9'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S16>/Constant8'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S16>/Constant7'
   */
  0.0,

  /* Expression: [0 0 0 1]
   * Referenced by: '<S16>/Constant5'
   */
  { 0.0, 0.0, 0.0, 1.0 },

  /* Expression: 1
   * Referenced by: '<S17>/Constant6'
   */
  1.0,

  /* Expression: [1 0 0]
   * Referenced by: '<S12>/Constant2'
   */
  { 1.0, 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<S17>/Constant9'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S17>/Constant8'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S17>/Constant7'
   */
  0.0,

  /* Expression: [0 0 0 1]
   * Referenced by: '<S17>/Constant5'
   */
  { 0.0, 0.0, 0.0, 1.0 },

  /* Expression: 5
   * Referenced by: '<S22>/Constant'
   */
  5.0,

  /* Expression: [0.5 4.5]
   * Referenced by: '<S22>/Constant1'
   */
  { 0.5, 4.5 },

  /* Expression: [0.5 4.5]
   * Referenced by: '<S22>/Constant2'
   */
  { 0.5, 4.5 },

  /* Expression: [0.5 4.5]
   * Referenced by: '<S22>/Constant3'
   */
  { 0.5, 4.5 },

  /* Expression: [0.5 4.5]
   * Referenced by: '<S22>/Constant4'
   */
  { 0.5, 4.5 },

  /* Expression: [2 0.5]
   * Referenced by: '<S22>/Constant5'
   */
  { 2.0, 0.5 },

  /* Expression: [2 2]
   * Referenced by: '<S22>/Constant6'
   */
  { 2.0, 2.0 },

  /* Expression: [0.5 4.5]
   * Referenced by: '<S22>/Constant8'
   */
  { 0.5, 4.5 },

  /* Expression: [0.5 4.5]
   * Referenced by: '<S22>/Constant9'
   */
  { 0.5, 4.5 },

  /* Expression: [0 0 0 0]
   * Referenced by: '<S14>/Default input '
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<S14>/Switch'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S22>/Memory'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1>/ rad//s//%'
   */
  1.0,

  /* Computed Parameter: HostGameController_BufferSize
   * Referenced by: '<S1>/Host Game Controller'
   */
  20,

  /* Computed Parameter: HostInitialize_SendBufferSize
   * Referenced by: '<S1>/Host Initialize'
   */
  1000,

  /* Computed Parameter: HostInitialize_ReceiveBufferSiz
   * Referenced by: '<S1>/Host Initialize'
   */
  1000,

  /* Computed Parameter: HostInitialize_ThreadPriority
   * Referenced by: '<S1>/Host Initialize'
   */
  0,

  /* Computed Parameter: EmergencyAbortbool_Y0
   * Referenced by: '<S4>/Emergency Abort (bool)'
   */
  false,

  /* Computed Parameter: ArmDisarmbool_Y0
   * Referenced by: '<S4>/Arm//Disarm (bool) '
   */
  false,

  /* Computed Parameter: TakeoffAutolandbool_Y0
   * Referenced by: '<S4>/Takeoff//Autoland (bool)'
   */
  false,

  /* Computed Parameter: VisualizationInitialize_OpenVie
   * Referenced by: '<S3>/Visualization Initialize'
   */
  true,

  /* Computed Parameter: HostGameController_AutoCenter
   * Referenced by: '<S1>/Host Game Controller'
   */
  false,

  /* Computed Parameter: HostGameController_Enabled
   * Referenced by: '<S1>/Host Game Controller'
   */
  true,

  /* Computed Parameter: HostGameController_DebugMode
   * Referenced by: '<S1>/Host Game Controller'
   */
  false,

  /* Computed Parameter: HostInitialize_RunClient
   * Referenced by: '<S1>/Host Initialize'
   */
  true,

  /* Computed Parameter: HostInitialize_UseWindow
   * Referenced by: '<S1>/Host Initialize'
   */
  false,

  /* Computed Parameter: HostInitialize_Active
   * Referenced by: '<S1>/Host Initialize'
   */
  true,

  /* Computed Parameter: HostGameController_Controller
   * Referenced by: '<S1>/Host Game Controller'
   */
  1,

  /* Computed Parameter: ManualSwitch1_CurrentSetting
   * Referenced by: '<Root>/Manual Switch1'
   */
  1U,

  /* Expression: uri_argument
   * Referenced by: '<S1>/Host Initialize'
   */
  0U,

  /* Start of '<S22>/Use desired Y  when enabled' */
  {
    /* Expression: 0
     * Referenced by: '<S31>/Out1'
     */
    0.0
  }
  ,

  /* End of '<S22>/Use desired Y  when enabled' */

  /* Start of '<S22>/Use desired X  when enabled' */
  {
    /* Expression: 0
     * Referenced by: '<S30>/Out1'
     */
    0.0
  }
  ,

  /* End of '<S22>/Use desired X  when enabled' */

  /* Start of '<S22>/Use des yaw  when enabled' */
  {
    /* Expression: 0
     * Referenced by: '<S29>/Out1'
     */
    0.0
  }
  ,

  /* End of '<S22>/Use des yaw  when enabled' */

  /* Start of '<S22>/Use des height  when enabled' */
  {
    /* Expression: 0
     * Referenced by: '<S28>/Out1'
     */
    0.0
  }
  /* End of '<S22>/Use des height  when enabled' */
};
