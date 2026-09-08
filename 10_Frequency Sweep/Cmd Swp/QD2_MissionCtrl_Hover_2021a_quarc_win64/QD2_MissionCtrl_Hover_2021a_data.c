/*
 * QD2_MissionCtrl_Hover_2021a_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "QD2_MissionCtrl_Hover_2021a".
 *
 * Model version              : 13.19
 * Simulink Coder version : 26.1 (R2026a) 20-Nov-2025
 * C source code generated on : Tue Sep  8 14:14:05 2026
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "QD2_MissionCtrl_Hover_2021a.h"

/* Block parameters (default storage) */
P_QD2_MissionCtrl_Hover_2021a_T QD2_MissionCtrl_Hover_2021a_P = {
  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S22>/Constant'
   */
  -0.5,

  /* Mask Parameter: CompareToConstant_const_g
   * Referenced by: '<S43>/Constant'
   */
  1.0,

  /* Mask Parameter: CompareToConstant_const_d
   * Referenced by: '<S15>/Constant'
   */
  5.0,

  /* Mask Parameter: CompareToConstant_const_n
   * Referenced by: '<S38>/Constant'
   */
  1.0,

  /* Mask Parameter: CompareToConstant1_const
   * Referenced by: '<S39>/Constant'
   */
  3.0,

  /* Mask Parameter: StreamServer_default_value
   * Referenced by: '<S1>/Stream Server'
   */
  0.0,

  /* Mask Parameter: Threshold_duration
   * Referenced by: '<S23>/duration'
   */
  0.2,

  /* Mask Parameter: Threshold_duration_l
   * Referenced by: '<S21>/duration'
   */
  0.2,

  /* Mask Parameter: Threshold_duration_b
   * Referenced by: '<S8>/duration'
   */
  0.1,

  /* Mask Parameter: Threshold_threshold
   * Referenced by: '<S23>/threshold'
   */
  0.5,

  /* Mask Parameter: Threshold_threshold_p
   * Referenced by: '<S21>/threshold'
   */
  0.5,

  /* Mask Parameter: Threshold_threshold_d
   * Referenced by: '<S8>/threshold'
   */
  0.5,

  /* Mask Parameter: VRPNClient_trackers_jpl
   * Referenced by: '<S11>/VRPN Client'
   */
  false,

  /* Mask Parameter: StopwithMessage_message_icon
   * Referenced by: '<S41>/Show Message on Host'
   */
  3,

  /* Mask Parameter: StringDisplay_alignment
   * Referenced by: '<S1>/String Display '
   */
  2U,

  /* Mask Parameter: CompareToConstant_const_gq
   * Referenced by: '<S5>/Constant'
   */
  2U,

  /* Mask Parameter: StringDisplay_display_mode
   * Referenced by: '<S1>/String Display '
   */
  1U,

  /* Computed Parameter: HomePosemrad4_Y0
   * Referenced by: '<S16>/Home Pose (m, rad ) [4]'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S9>/Constant1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S9>/Constant'
   */
  0.0,

  /* Computed Parameter: Yaw_Y0
   * Referenced by: '<S18>/Yaw (%)'
   */
  0.0,

  /* Computed Parameter: Throttle_Y0
   * Referenced by: '<S18>/Throttle (%)'
   */
  0.0,

  /* Computed Parameter: Roll_Y0
   * Referenced by: '<S18>/Roll (%)'
   */
  0.0,

  /* Computed Parameter: Pitch_Y0
   * Referenced by: '<S18>/Pitch (%)'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S23>/Discrete-Time Integrator'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<S23>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S18>/Gain'
   */
  -1.0,

  /* Expression: 0.5
   * Referenced by: '<S18>/Gain1'
   */
  0.5,

  /* Expression: 0.5
   * Referenced by: '<S18>/Bias'
   */
  0.5,

  /* Expression: 0
   * Referenced by: '<S19>/Joystick Issue (0,1)'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S19>/Triggers (0,1) [4]'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S19>/Commands (%) [4]'
   */
  0.0,

  /* Expression: -0.01
   * Referenced by: '<S19>/Dead Zone'
   */
  -0.01,

  /* Expression: 0.01
   * Referenced by: '<S19>/Dead Zone'
   */
  0.01,

  /* Computed Parameter: NumberofPulses_Y0
   * Referenced by: '<S24>/Number of Pulses'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S24>/Constant1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S25>/FixPt Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S24>/Unit Delay'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S20>/Pulse Check'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S2>/Custom Mode'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S2>/Home Mode'
   */
  0.0,

  /* Expression: [0 0 1 0]
   * Referenced by: '<S2>/Default Position'
   */
  { 0.0, 0.0, 1.0, 0.0 },

  /* Expression: 1
   * Referenced by: '<S2>/Home height (m)'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S14>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S14>/Memory'
   */
  0.0,

  /* Expression: -1*ones(1,6)
   * Referenced by: '<S10>/Constant'
   */
  { -1.0, -1.0, -1.0, -1.0, -1.0, -1.0 },

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_j
   * Referenced by: '<S21>/Discrete-Time Integrator'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<S21>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S11>/Rate Transition2'
   */
  0.0,

  /* Expression: [0 0 -0.07]
   * Referenced by: '<S12>/Subtract Rigid Body Reference Offset  (Initial Height)  to get height above the ground'
   */
  { 0.0, 0.0, -0.07 },

  /* Expression: [2 2 5]
   * Referenced by: '<S12>/Saturation'
   */
  { 2.0, 2.0, 5.0 },

  /* Expression: [-2 -2 0]
   * Referenced by: '<S12>/Saturation'
   */
  { -2.0, -2.0, 0.0 },

  /* Expression: modulus
   * Referenced by: '<S12>/Unwrap optitrack measurement'
   */
  6.2831853071795862,

  /* Expression: i_pulse_width
   * Referenced by: '<S17>/width'
   */
  1000.0,

  /* Expression: i_trigger_type
   * Referenced by: '<S17>/one_shot_block'
   */
  1.0,

  /* Expression: i_redun_pulse
   * Referenced by: '<S17>/one_shot_block'
   */
  1.0,

  /* Expression: 0.5
   * Referenced by: '<S17>/Switch'
   */
  0.5,

  /* Expression: 0
   * Referenced by: '<S2>/Switch'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1>/Constant'
   */
  1.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_n
   * Referenced by: '<S8>/Discrete-Time Integrator'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<S8>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S11>/Rate Transition6'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S11>/Rate Transition7'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S11>/Rate Transition8'
   */
  0.0,

  /* Expression: [0 0 0]'
   * Referenced by: '<S11>/Dummy Translation'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: 1
   * Referenced by: '<S2>/Constant'
   */
  1.0,

  /* Expression: 180/pi
   * Referenced by: '<S27>/Gain'
   */
  57.295779513082323,

  /* Computed Parameter: HostInitialize_SendBufferSize
   * Referenced by: '<S10>/Host Initialize'
   */
  1000,

  /* Computed Parameter: HostInitialize_ReceiveBufferSiz
   * Referenced by: '<S10>/Host Initialize'
   */
  1000,

  /* Computed Parameter: HostInitialize_ThreadPriority
   * Referenced by: '<S10>/Host Initialize'
   */
  0,

  /* Computed Parameter: HostGameController_BufferSize
   * Referenced by: '<S10>/Host Game Controller'
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

  /* Computed Parameter: VRPNClient_TraNumSensors
   * Referenced by: '<S11>/VRPN Client'
   */
  1,

  /* Computed Parameter: VRPNClient_TraReadSensors
   * Referenced by: '<S11>/VRPN Client'
   */
  { 1, 0 },

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
   * Referenced by: '<S18>/Emergency Abort (bool)'
   */
  false,

  /* Computed Parameter: ArmDisarmbool_Y0
   * Referenced by: '<S18>/Arm//Disarm (bool) '
   */
  false,

  /* Computed Parameter: TakeoffAutolandbool_Y0
   * Referenced by: '<S18>/Takeoff//Autoland (bool)'
   */
  false,

  /* Computed Parameter: CommunicationIssue01_Y0
   * Referenced by: '<S14>/Communication Issue (0,1)'
   */
  false,

  /* Computed Parameter: Constant_Value_h0
   * Referenced by: '<S42>/Constant'
   */
  false,

  /* Computed Parameter: HostInitialize_RunClient
   * Referenced by: '<S10>/Host Initialize'
   */
  true,

  /* Computed Parameter: HostInitialize_UseWindow
   * Referenced by: '<S10>/Host Initialize'
   */
  false,

  /* Computed Parameter: HostInitialize_Active
   * Referenced by: '<S10>/Host Initialize'
   */
  true,

  /* Computed Parameter: HostGameController_AutoCenter
   * Referenced by: '<S10>/Host Game Controller'
   */
  false,

  /* Computed Parameter: HostGameController_Enabled
   * Referenced by: '<S10>/Host Game Controller'
   */
  true,

  /* Computed Parameter: HostGameController_DebugMode
   * Referenced by: '<S10>/Host Game Controller'
   */
  false,

  /* Computed Parameter: StreamServer_Active
   * Referenced by: '<S1>/Stream Server'
   */
  false,

  /* Computed Parameter: Delay_InitialCondition
   * Referenced by: '<S13>/Delay'
   */
  false,

  /* Computed Parameter: Delay1_InitialCondition
   * Referenced by: '<S13>/Delay1'
   */
  false,

  /* Computed Parameter: VRPNClient_Active
   * Referenced by: '<S11>/VRPN Client'
   */
  true,

  /* Computed Parameter: HostGameController_Controller
   * Referenced by: '<S10>/Host Game Controller'
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

  /* Computed Parameter: ShowMessageonHost_MsgIcon_e
   * Referenced by: '<S2>/Show Message on Host '
   */
  2,

  /* Expression: uri_argument
   * Referenced by: '<S10>/Host Initialize'
   */
  0U,

  /* Computed Parameter: ManualSwitch1_CurrentSetting
   * Referenced by: '<S2>/Manual Switch1'
   */
  1U,

  /* Computed Parameter: CommandEnable_CurrentSetting
   * Referenced by: '<S2>/Command Enable'
   */
  0U,

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
    72U, 111U, 118U, 101U, 114U, 95U, 50U, 48U, 50U, 49U, 97U, 47U, 108U, 111U,
    103U, 95U, 50U, 48U, 50U, 54U, 45U, 48U, 57U, 45U, 48U, 56U, 95U, 49U, 52U,
    45U, 49U, 52U, 45U, 48U, 51U, 95U, 77U, 105U, 115U, 115U, 105U, 111U, 110U,
    67U, 116U, 114U, 108U, 46U, 109U, 97U, 116U, 0U },

  /* Start of '<S26>/CoreSubsys' */
  {
    /* Expression: 0
     * Referenced by: '<S36>/Constant'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S35>/Constant'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S37>/Constant'
     */
    0.0,

    /* Expression: [0 1 0;0 0 1;1 0 0]'
     * Referenced by: '<S26>/ Qualisys Rotate Matrix R_VPRN (column vectors are basis vectors) of VF w.r.t. TNF'
     */
    { 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0 },

    /* Expression: [0 0 -1 ;-1 0 0 ;0 1 0 ]
     * Referenced by: '<S26>/OptiTrack Rotate Matrix R_Tool (column vectors are basis vectors) of TNF w.r.t. RSF'
     */
    { 0.0, -1.0, 0.0, 0.0, 0.0, 1.0, -1.0, 0.0, 0.0 },

    /* Expression: [0 0 1 ;1 0 0 ;0 1 0 ]
     * Referenced by: '<S26>/Phase Space Rotate Matrix R_Tool (column vectors are basis vectors) of TNF w.r.t. RSF'
     */
    { 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0 },

    /* Expression: [1 0 0 ;0 1 0;0 0 1]
     * Referenced by: '<S26>/ Generic Rotate Matrix R_VPRN (column vectors are basis vectors) of VF w.r.t. TNF1'
     */
    { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

    /* Expression: [1 0 0;0 1 0 ;0 0 1]
     * Referenced by: '<S26>/Generic Rotate Matrix R_Tool (column vectors are basis vectors) of TNF w.r.t. RSF'
     */
    { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

    /* Expression: 2
     * Referenced by: '<S29>/Gain6'
     */
    2.0,

    /* Expression: 2
     * Referenced by: '<S29>/Gain1'
     */
    2.0,

    /* Expression: 2
     * Referenced by: '<S29>/Gain'
     */
    2.0,

    /* Expression: 2
     * Referenced by: '<S29>/Gain3'
     */
    2.0,

    /* Expression: 2
     * Referenced by: '<S29>/Gain5'
     */
    2.0,

    /* Expression: 2
     * Referenced by: '<S29>/Gain2'
     */
    2.0,

    /* Expression: 1
     * Referenced by: '<S28>/Constant'
     */
    1.0,

    /* Expression: inf
     * Referenced by: '<S28>/Saturation'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S28>/Saturation'
     */
    0.0,

    /* Expression: 0.5
     * Referenced by: '<S28>/Gain'
     */
    0.5,

    /* Expression: inf
     * Referenced by: '<S28>/Saturation1'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S28>/Saturation1'
     */
    0.0,

    /* Expression: 0.5
     * Referenced by: '<S28>/Gain1'
     */
    0.5,

    /* Computed Parameter: Bias_Bias
     * Referenced by: '<S31>/Bias'
     */
    -1,

    /* Computed Parameter: Bias1_Bias
     * Referenced by: '<S31>/Bias1'
     */
    -1,

    /* Computed Parameter: Bias2_Bias
     * Referenced by: '<S31>/Bias2'
     */
    -1,

    /* Computed Parameter: Bias1_Bias_i
     * Referenced by: '<S33>/Bias1'
     */
    -1,

    /* Computed Parameter: Bias_Bias_c
     * Referenced by: '<S33>/Bias'
     */
    -1,

    /* Computed Parameter: Constant_Value_f
     * Referenced by: '<S34>/Constant'
     */
    1,

    /* Computed Parameter: Bias_Bias_a
     * Referenced by: '<S34>/Bias'
     */
    -1,

    /* Computed Parameter: Constant_Value_n
     * Referenced by: '<S32>/Constant'
     */
    1,

    /* Computed Parameter: Gain_Gain_c
     * Referenced by: '<S31>/Gain'
     */
    128U,

    /* Computed Parameter: Gain1_Gain_f
     * Referenced by: '<S31>/Gain1'
     */
    128U,

    /* Computed Parameter: Gain2_Gain_h
     * Referenced by: '<S31>/Gain2'
     */
    128U,

    /* Computed Parameter: Gain1_Gain_k
     * Referenced by: '<S33>/Gain1'
     */
    128U,

    /* Computed Parameter: Gain_Gain_p
     * Referenced by: '<S33>/Gain'
     */
    128U,

    /* Computed Parameter: Gain_Gain_co
     * Referenced by: '<S34>/Gain'
     */
    128U
  }
  /* End of '<S26>/CoreSubsys' */
};

/* Constant parameters (default storage) */
const ConstP_QD2_MissionCtrl_Hover__T QD2_MissionCtrl_Hover_20_ConstP = {
  /* Expression: trackers_list
   * Referenced by: '<S11>/VRPN Client'
   */
  { 81U, 68U, 114U, 111U, 110U, 101U, 50U, 95U, 48U, 50U, 0U }
};
