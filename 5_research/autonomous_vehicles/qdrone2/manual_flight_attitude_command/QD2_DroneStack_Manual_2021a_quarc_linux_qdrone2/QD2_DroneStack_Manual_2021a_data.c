/*
 * QD2_DroneStack_Manual_2021a_data.c
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

#include "QD2_DroneStack_Manual_2021a.h"

/* Block parameters (default storage) */
P_QD2_DroneStack_Manual_2021a_T QD2_DroneStack_Manual_2021a_P = {
  /* Variable: KT
   * Referenced by: '<S2>/Constant3'
   */
  { 0.03616, 0.117, -0.01215 },

  /* Variable: Motor_Matrix
   * Referenced by: '<S2>/Constant2'
   */
  { 0.25, 0.25, 0.25, 0.25, -1.9685039370078741, -1.9685039370078741,
    1.9685039370078741, 1.9685039370078741, 2.4606299212598426,
    -2.4606299212598426, 2.4606299212598426, -2.4606299212598426, 17.226375,
    -17.226375, -17.226375, 17.226375 },

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S36>/Constant'
   */
  20.0,

  /* Mask Parameter: Greaterthanminimumexpectedvolta
   * Referenced by: '<S40>/Constant'
   */
  0.5,

  /* Mask Parameter: Lessthanminimumthresholdvoltage
   * Referenced by: '<S41>/Constant'
   */
  14.0,

  /* Mask Parameter: StreamClient_default_value
   * Referenced by: '<S1>/Stream Client'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Mask Parameter: StreamServer_default_value
   * Referenced by: '<S2>/Stream Server'
   */
  0.0,

  /* Mask Parameter: Threshold_duration
   * Referenced by: '<S26>/duration'
   */
  0.6,

  /* Mask Parameter: Threshold_duration_d
   * Referenced by: '<S7>/duration'
   */
  0.1,

  /* Mask Parameter: Threshold1_duration
   * Referenced by: '<S8>/duration'
   */
  0.5,

  /* Mask Parameter: Stopmodel_duration
   * Referenced by: '<S60>/duration'
   */
  0.1,

  /* Mask Parameter: Communication_duration
   * Referenced by: '<S59>/duration'
   */
  1.0,

  /* Mask Parameter: DiscreteSecondOrderLowPassFilte
   * Referenced by: '<S18>/bandwidth'
   */
  1.0,

  /* Mask Parameter: DiscreteSecondOrderLowPassFil_p
   * Referenced by: '<S18>/zeta'
   */
  1.0,

  /* Mask Parameter: Threshold_threshold
   * Referenced by: '<S26>/threshold'
   */
  0.0,

  /* Mask Parameter: Threshold_threshold_h
   * Referenced by: '<S7>/threshold'
   */
  0.5,

  /* Mask Parameter: Threshold1_threshold
   * Referenced by: '<S8>/threshold'
   */
  0.5,

  /* Mask Parameter: Stopmodel_threshold
   * Referenced by: '<S60>/threshold'
   */
  0.5,

  /* Mask Parameter: Communication_threshold
   * Referenced by: '<S59>/threshold'
   */
  0.5,

  /* Mask Parameter: CompareToConstant1_const
   * Referenced by: '<S12>/Constant'
   */
  0,

  /* Mask Parameter: HILRead_analog_channels
   * Referenced by: '<S2>/HIL Read'
   */
  { 3U, 1U, 2U },

  /* Mask Parameter: HILWritePWM_channels
   * Referenced by: '<S19>/HIL Write PWM'
   */
  { 0U, 1U, 2U, 3U },

  /* Mask Parameter: HILWriteDigital_channels
   * Referenced by: '<S2>/HIL Write Digital'
   */
  { 6U, 7U, 8U, 9U, 10U, 11U },

  /* Mask Parameter: HILRead_other_channels
   * Referenced by: '<S2>/HIL Read'
   */
  { 3000U, 3001U, 3002U, 4000U, 4001U, 4002U, 3003U, 3004U, 3005U, 4003U, 4004U,
    4005U, 17000U, 17001U, 17002U, 17003U, 17004U, 17005U, 17006U, 17008U,
    17009U, 17007U, 17010U },

  /* Mask Parameter: StopwithMessage_message_icon
   * Referenced by: '<S61>/Show Message on Host'
   */
  3,

  /* Mask Parameter: StopwithMessage1_message_icon
   * Referenced by: '<S62>/Show Message on Host'
   */
  2,

  /* Mask Parameter: StopwithMessage3_message_icon
   * Referenced by: '<S63>/Show Message on Host'
   */
  3,

  /* Mask Parameter: StringDisplay_alignment
   * Referenced by: '<S1>/String Display'
   */
  2U,

  /* Mask Parameter: CompareToConstant_const_e
   * Referenced by: '<S11>/Constant'
   */
  2U,

  /* Mask Parameter: StringDisplay_display_mode
   * Referenced by: '<S1>/String Display'
   */
  1U,

  /* Expression: [ 1 0 0 1 0 0]
   * Referenced by: '<S21>/Red Red'
   */
  { 1.0, 0.0, 0.0, 1.0, 0.0, 0.0 },

  /* Expression: [ 0 0 0 0 0 0]
   * Referenced by: '<S21>/LED OFF'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: [ 1 1 0 1 1 0  ]
   * Referenced by: '<S21>/Yellow Yellow'
   */
  { 1.0, 1.0, 0.0, 1.0, 1.0, 0.0 },

  /* Expression: [ 1 1 0 0 1 0  ]
   * Referenced by: '<S21>/Yellow Green'
   */
  { 1.0, 1.0, 0.0, 0.0, 1.0, 0.0 },

  /* Expression: [0 0 1 0 0 1]
   * Referenced by: '<S21>/Blue Blue'
   */
  { 0.0, 0.0, 1.0, 0.0, 0.0, 1.0 },

  /* Expression: [ 1 1 0 1 0 0  ]
   * Referenced by: '<S21>/Yellow Red'
   */
  { 1.0, 1.0, 0.0, 1.0, 0.0, 0.0 },

  /* Expression: [ 1 0 0 1 1 0  ]
   * Referenced by: '<S21>/Red Yellow'
   */
  { 1.0, 0.0, 0.0, 1.0, 1.0, 0.0 },

  /* Expression: [0 1 0 0 1 0]
   * Referenced by: '<S21>/Green Green'
   */
  { 0.0, 1.0, 0.0, 0.0, 1.0, 0.0 },

  /* Expression: [ 1 1 0 0 0 1  ]
   * Referenced by: '<S21>/Yellow Blue'
   */
  { 1.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  /* Expression: [ 1 0 0 0 0 1   ]
   * Referenced by: '<S21>/Red Blue'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0 },

  /* Expression: 0
   * Referenced by: '<S43>/Out1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S43>/Constant'
   */
  1.0,

  /* Expression: [1 0 0 0]
   * Referenced by: '<S2>/Motor 0'
   */
  { 1.0, 0.0, 0.0, 0.0 },

  /* Expression: [0 1 0 0]
   * Referenced by: '<S2>/Motor 1'
   */
  { 0.0, 1.0, 0.0, 0.0 },

  /* Expression: [0 0 1 0]
   * Referenced by: '<S2>/Motor 2'
   */
  { 0.0, 0.0, 1.0, 0.0 },

  /* Expression: [0 0 0 1]
   * Referenced by: '<S2>/Motor 3'
   */
  { 0.0, 0.0, 0.0, 1.0 },

  /* Expression: [0 0 0 0]
   * Referenced by: '<S2>/No selection'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Expression: set_other_outputs_at_terminate
   * Referenced by: '<S2>/HIL Initialize'
   */
  1.0,

  /* Expression: set_other_outputs_at_switch_out
   * Referenced by: '<S2>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_start
   * Referenced by: '<S2>/HIL Initialize'
   */
  1.0,

  /* Expression: set_other_outputs_at_switch_in
   * Referenced by: '<S2>/HIL Initialize'
   */
  0.0,

  /* Expression: final_pwm_outputs
   * Referenced by: '<S2>/HIL Initialize'
   */
  0.0,

  /* Expression: analog_input_maximums
   * Referenced by: '<S2>/HIL Initialize'
   */
  3.3,

  /* Expression: analog_input_minimums
   * Referenced by: '<S2>/HIL Initialize'
   */
  0.0,

  /* Expression: encoder_filter_frequency
   * Referenced by: '<S2>/HIL Initialize'
   */
  1.0E+8,

  /* Expression: pwm_frequency
   * Referenced by: '<S2>/HIL Initialize'
   */
  600000.0,

  /* Expression: initial_pwm_outputs
   * Referenced by: '<S2>/HIL Initialize'
   */
  0.0,

  /* Expression: watchdog_pwm_outputs
   * Referenced by: '<S2>/HIL Initialize'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S1>/Delay'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S2>/Memory'
   */
  0.0,

  /* Expression: [0 0 0]
   * Referenced by: '<S4>/Zero Torque//Command'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: 0.5
   * Referenced by: '<S4>/Switch'
   */
  0.5,

  /* Expression: 0.5
   * Referenced by: '<S4>/Switch1'
   */
  0.5,

  /* Expression: [pi/4 pi/4 10*pi/18]
   * Referenced by: '<S4>/Saturate Stabilization Command'
   */
  { 0.78539816339744828, 0.78539816339744828, 1.7453292519943295 },

  /* Expression: [-pi/4 -pi/4 -10*pi/18]
   * Referenced by: '<S4>/Saturate Stabilization Command'
   */
  { -0.78539816339744828, -0.78539816339744828, -1.7453292519943295 },

  /* Expression: 2
   * Referenced by: '<S2>/Constant1'
   */
  2.0,

  /* Expression: [1 1 0]
   * Referenced by: '<S4>/Gain1'
   */
  { 1.0, 1.0, 0.0 },

  /* Expression: [12 12 1]
   * Referenced by: '<S4>/K_p_angle (rad//s // rad)'
   */
  { 12.0, 12.0, 1.0 },

  /* Expression: [1 1 2]
   * Referenced by: '<S4>/Scale'
   */
  { 1.0, 1.0, 2.0 },

  /* Expression: [0.1 0.1 0]
   * Referenced by: '<S4>/K_d_angle (rad//s // rad//s)'
   */
  { 0.1, 0.1, 0.0 },

  /* Expression: [1 1 2]
   * Referenced by: '<S4>/Scale1'
   */
  { 1.0, 1.0, 2.0 },

  /* Expression: 10*pi/3*[1 1 1]
   * Referenced by: '<S4>/Saturation Max Rate  (rad//s)'
   */
  { 10.471975511965978, 10.471975511965978, 10.471975511965978 },

  /* Expression: -10*pi/3*[1 1 1]
   * Referenced by: '<S4>/Saturation Max Rate  (rad//s)'
   */
  { -10.471975511965978, -10.471975511965978, -10.471975511965978 },

  /* Expression: [ 0.1876    0.1544    0.0395]
   * Referenced by: '<S4>/K_p_speed (Nm // rad//s)'
   */
  { 0.1876, 0.1544, 0.0395 },

  /* Expression: [1 1 2]
   * Referenced by: '<S4>/Scale5'
   */
  { 1.0, 1.0, 2.0 },

  /* Expression: [0.0032    0.0026     0.005]
   * Referenced by: '<S4>/K_d_speed (Nm // rad//s//s)1'
   */
  { 0.0032, 0.0026, 0.005 },

  /* Expression: [1 1 2]
   * Referenced by: '<S4>/Scale4'
   */
  { 1.0, 1.0, 2.0 },

  /* Expression: [1.0915 0.8984 0.0984]
   * Referenced by: '<S4>/Saturation Command  Authority (Nm)1'
   */
  { 1.0915, 0.8984, 0.0984 },

  /* Expression: -[1.0915 0.8984 0.0984]
   * Referenced by: '<S4>/Saturation Command  Authority (Nm)1'
   */
  { -1.0915, -0.8984, -0.0984 },

  /* Expression: 0.0
   * Referenced by: '<S4>/Delay'
   */
  0.0,

  /* Expression: [0 0 0 0]
   * Referenced by: '<Root>/Zero Reference Motor Commands'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Expression: [1 1 1 1]
   * Referenced by: '<S2>/Maximum  Command Authority '
   */
  { 1.0, 1.0, 1.0, 1.0 },

  /* Expression: [1 1 1 1]*0.025
   * Referenced by: '<S2>/Maximum  Command Authority '
   */
  { 0.025, 0.025, 0.025, 0.025 },

  /* Expression: [0 0 0 0; 1 0 0 0; 0 0 0 0; 0 1 0 0; 0 0 0 0; 0 0 1 0; 0 0 0 0;  0 0 0 1]
   * Referenced by: '<S10>/Constant1'
   */
  { 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0 },

  /* Expression: 8
   * Referenced by: '<S10>/Constant2'
   */
  8.0,

  /* Expression: 0
   * Referenced by: '<S2>/Rate Transition7'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Rate Transition2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Rate Transition1'
   */
  0.0,

  /* Expression: 2/14
   * Referenced by: '<S2>/Divide by half of the number of poles in motor'
   */
  0.14285714285714285,

  /* Expression: 1
   * Referenced by: '<S2>/Multiple by resolution (supposed to be 100 RPM)'
   */
  1.0,

  /* Expression: zeros(1,4)
   * Referenced by: '<S13>/Memory'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Expression: 1/1300
   * Referenced by: '<S2>/Convert to equivalent voltage (based on motor Kv rating)'
   */
  0.00076923076923076923,

  /* Expression: 17
   * Referenced by: '<S2>/Saturation'
   */
  17.0,

  /* Expression: 10
   * Referenced by: '<S2>/Saturation'
   */
  10.0,

  /* Expression: zeros(1,4)
   * Referenced by: '<S15>/Memory'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Expression: 1
   * Referenced by: '<S2>/Saturation1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S2>/Saturation1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S27>/Rate Transition'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S27>/Rate Transition1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S27>/Rate Transition2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S27>/Rate Transition3'
   */
  0.0,

  /* Expression: .7
   * Referenced by: '<S10>/Gain'
   */
  0.7,

  /* Expression: 0:3
   * Referenced by: '<S10>/Bias1'
   */
  { 0.0, 1.0, 2.0, 3.0 },

  /* Expression: zeros(1,4)
   * Referenced by: '<S14>/Memory'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Expression: 0.0
   * Referenced by: '<S16>/Delay3'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S16>/Delay2'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S16>/Delay1'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S16>/Delay'
   */
  0.0,

  /* Expression: 200
   * Referenced by: '<S16>/Constant'
   */
  200.0,

  /* Expression: 0
   * Referenced by: '<S2>/Zero Yaw'
   */
  0.0,

  /* Expression: 0.3
   * Referenced by: '<S23>/Battery Low Time Threshold (s)'
   */
  0.3,

  /* Expression: 0.5
   * Referenced by: '<S23>/Constant'
   */
  0.5,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S42>/Discrete-Time Integrator'
   */
  0.002,

  /* Expression: 0
   * Referenced by: '<S42>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S25>/Constant1'
   */
  1.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_b
   * Referenced by: '<S26>/Discrete-Time Integrator'
   */
  0.002,

  /* Expression: 0
   * Referenced by: '<S26>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_o
   * Referenced by: '<S7>/Discrete-Time Integrator'
   */
  0.002,

  /* Expression: 0
   * Referenced by: '<S7>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_j
   * Referenced by: '<S8>/Discrete-Time Integrator'
   */
  0.002,

  /* Expression: 0
   * Referenced by: '<S8>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<S57>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S58>/Gain'
   */
  57.295779513082323,

  /* Computed Parameter: DiscreteTimeIntegrator_gainv_bm
   * Referenced by: '<S60>/Discrete-Time Integrator'
   */
  0.002,

  /* Expression: 0
   * Referenced by: '<S60>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainv_b1
   * Referenced by: '<S59>/Discrete-Time Integrator'
   */
  0.002,

  /* Expression: 0
   * Referenced by: '<S59>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: timeout
   * Referenced by: '<S56>/HIL Watchdog'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S2>/Memory2'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S18>/Constant'
   */
  2.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_f
   * Referenced by: '<S18>/Discrete-Time Integrator'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<S18>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: input_init
   * Referenced by: '<S18>/x0'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator1_gainval
   * Referenced by: '<S18>/Discrete-Time Integrator1'
   */
  0.01,

  /* Expression: 2
   * Referenced by: '<S17>/Constant'
   */
  2.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainv_o5
   * Referenced by: '<S17>/Discrete-Time Integrator'
   */
  0.04,

  /* Expression: 0
   * Referenced by: '<S17>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/ToF Filter Initial Condition (m)'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator1_gainv_i
   * Referenced by: '<S17>/Discrete-Time Integrator1'
   */
  0.04,

  /* Expression: 40
   * Referenced by: '<S2>/ToF Filter Cutoff Frequency (rad)'
   */
  40.0,

  /* Expression: timing_budget
   * Referenced by: '<S2>/Ranging Sensor'
   */
  0.033,

  /* Expression: measurement_period
   * Referenced by: '<S2>/Ranging Sensor'
   */
  0.04,

  /* Expression: max_interpolated_distance
   * Referenced by: '<S2>/Ranging Sensor'
   */
  0.05,

  /* Expression: max_interpolated_angle
   * Referenced by: '<S2>/Ranging Sensor'
   */
  5.0,

  /* Expression: 1
   * Referenced by: '<S2>/ToF Filter Damping Ratio'
   */
  1.0,

  /* Expression: [0 0]
   * Referenced by: '<S2>/ToF Sensor XY Offsets (m)'
   */
  { 0.0, 0.0 },

  /* Computed Parameter: HILInitialize_DOWatchdog
   * Referenced by: '<S2>/HIL Initialize'
   */
  { 0, 0, 0, 0, 0, 0 },

  /* Computed Parameter: HILInitialize_EIInitial
   * Referenced by: '<S2>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POModes
   * Referenced by: '<S2>/HIL Initialize'
   */
  { 6, 6, 6, 6, 0 },

  /* Computed Parameter: HILInitialize_POConfiguration
   * Referenced by: '<S2>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POAlignment
   * Referenced by: '<S2>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POPolarity
   * Referenced by: '<S2>/HIL Initialize'
   */
  1,

  /* Computed Parameter: StreamClient_SndPriority
   * Referenced by: '<S1>/Stream Client'
   */
  0,

  /* Computed Parameter: StreamClient_RcvPriority
   * Referenced by: '<S1>/Stream Client'
   */
  0,

  /* Computed Parameter: ToHostFile_Encoding
   * Referenced by: '<S2>/To Host File'
   */
  1,

  /* Computed Parameter: ToHostFile_Encoding_b
   * Referenced by: '<S4>/To Host File'
   */
  1,

  /* Computed Parameter: StreamServer_SndPriority
   * Referenced by: '<S2>/Stream Server'
   */
  0,

  /* Computed Parameter: StreamServer_RcvPriority
   * Referenced by: '<S2>/Stream Server'
   */
  0,

  /* Computed Parameter: HILInitialize_AIChannels
   * Referenced by: '<S2>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U },

  /* Computed Parameter: HILInitialize_DIChannels
   * Referenced by: '<S2>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U },

  /* Computed Parameter: HILInitialize_DOChannels
   * Referenced by: '<S2>/HIL Initialize'
   */
  { 6U, 7U, 8U, 9U, 10U, 11U },

  /* Computed Parameter: HILInitialize_EIChannels
   * Referenced by: '<S2>/HIL Initialize'
   */
  { 0U, 1U },

  /* Computed Parameter: HILInitialize_EIQuadrature
   * Referenced by: '<S2>/HIL Initialize'
   */
  4U,

  /* Computed Parameter: HILInitialize_POChannels
   * Referenced by: '<S2>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U },

  /* Computed Parameter: StreamClient_SndSize
   * Referenced by: '<S1>/Stream Client'
   */
  1460U,

  /* Computed Parameter: StreamClient_RcvSize
   * Referenced by: '<S1>/Stream Client'
   */
  1460U,

  /* Computed Parameter: StreamClient_SndFIFO
   * Referenced by: '<S1>/Stream Client'
   */
  1U,

  /* Computed Parameter: StreamClient_RcvFIFO
   * Referenced by: '<S1>/Stream Client'
   */
  1U,

  /* Computed Parameter: ToHostFile_Decimation
   * Referenced by: '<S2>/To Host File'
   */
  1U,

  /* Computed Parameter: ToHostFile_BitRate
   * Referenced by: '<S2>/To Host File'
   */
  2000000U,

  /* Computed Parameter: ToHostFile_Decimation_m
   * Referenced by: '<S4>/To Host File'
   */
  1U,

  /* Computed Parameter: ToHostFile_BitRate_b
   * Referenced by: '<S4>/To Host File'
   */
  2000000U,

  /* Computed Parameter: StreamServer_SndSize
   * Referenced by: '<S2>/Stream Server'
   */
  1460U,

  /* Computed Parameter: StreamServer_RcvSize
   * Referenced by: '<S2>/Stream Server'
   */
  1460U,

  /* Computed Parameter: StreamServer_SndFIFO
   * Referenced by: '<S2>/Stream Server'
   */
  1000U,

  /* Computed Parameter: StreamServer_RcvFIFO
   * Referenced by: '<S2>/Stream Server'
   */
  1000U,

  /* Computed Parameter: RangingSensor_Range
   * Referenced by: '<S2>/Ranging Sensor'
   */
  3U,

  /* Computed Parameter: HILWritePWM_Active
   * Referenced by: '<S19>/HIL Write PWM'
   */
  false,

  /* Computed Parameter: Constant_Value_c
   * Referenced by: '<S64>/Constant'
   */
  false,

  /* Computed Parameter: Constant_Value_oc
   * Referenced by: '<S65>/Constant'
   */
  false,

  /* Computed Parameter: Constant_Value_a
   * Referenced by: '<S66>/Constant'
   */
  false,

  /* Computed Parameter: HILInitialize_Active
   * Referenced by: '<S2>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AOTerminate
   * Referenced by: '<S2>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOExit
   * Referenced by: '<S2>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOTerminate
   * Referenced by: '<S2>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOExit
   * Referenced by: '<S2>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POTerminate
   * Referenced by: '<S2>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_POExit
   * Referenced by: '<S2>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKPStart
   * Referenced by: '<S2>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKPEnter
   * Referenced by: '<S2>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKStart
   * Referenced by: '<S2>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKEnter
   * Referenced by: '<S2>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AIPStart
   * Referenced by: '<S2>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AIPEnter
   * Referenced by: '<S2>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOPStart
   * Referenced by: '<S2>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOPEnter
   * Referenced by: '<S2>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOStart
   * Referenced by: '<S2>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOEnter
   * Referenced by: '<S2>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOReset
   * Referenced by: '<S2>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOPStart
   * Referenced by: '<S2>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOPEnter
   * Referenced by: '<S2>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOStart
   * Referenced by: '<S2>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOEnter
   * Referenced by: '<S2>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOReset
   * Referenced by: '<S2>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_EIPStart
   * Referenced by: '<S2>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_EIPEnter
   * Referenced by: '<S2>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_EIStart
   * Referenced by: '<S2>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_EIEnter
   * Referenced by: '<S2>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POPStart
   * Referenced by: '<S2>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_POPEnter
   * Referenced by: '<S2>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POStart
   * Referenced by: '<S2>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_POEnter
   * Referenced by: '<S2>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POReset
   * Referenced by: '<S2>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_OOReset
   * Referenced by: '<S2>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOFinal
   * Referenced by: '<S2>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOInitial
   * Referenced by: '<S2>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILRead_Active
   * Referenced by: '<S2>/HIL Read'
   */
  true,

  /* Computed Parameter: StreamClient_Active
   * Referenced by: '<S1>/Stream Client'
   */
  false,

  /* Computed Parameter: Memory1_InitialCondition
   * Referenced by: '<S2>/Memory1'
   */
  false,

  /* Computed Parameter: HILWriteDigital_Active
   * Referenced by: '<S2>/HIL Write Digital'
   */
  false,

  /* Computed Parameter: HILWatchdog_Active
   * Referenced by: '<S56>/HIL Watchdog'
   */
  false,

  /* Computed Parameter: Memory3_InitialCondition
   * Referenced by: '<S2>/Memory3'
   */
  false,

  /* Computed Parameter: StreamServer_Active
   * Referenced by: '<S2>/Stream Server'
   */
  true,

  /* Computed Parameter: RangingSensor_Active
   * Referenced by: '<S2>/Ranging Sensor'
   */
  true,

  /* Computed Parameter: StreamClient_Optimize
   * Referenced by: '<S1>/Stream Client'
   */
  1,

  /* Computed Parameter: StreamClient_Implementation
   * Referenced by: '<S1>/Stream Client'
   */
  2,

  /* Computed Parameter: StreamServer_Optimize
   * Referenced by: '<S2>/Stream Server'
   */
  2,

  /* Computed Parameter: StreamServer_Implementation
   * Referenced by: '<S2>/Stream Server'
   */
  2,

  /* Expression: uri_argument
   * Referenced by: '<S1>/Stream Client'
   */
  0U,

  /* Computed Parameter: StreamClient_Endian
   * Referenced by: '<S1>/Stream Client'
   */
  1U,

  /* Computed Parameter: ManualSwitchSelectCommandInput_
   * Referenced by: '<S2>/Manual Switch -   Select Command Input'
   */
  1U,

  /* Expression: variable_name_argument
   * Referenced by: '<S2>/To Host File'
   */
  { 81U, 68U, 50U, 95U, 100U, 97U, 116U, 97U, 0U },

  /* Computed Parameter: ToHostFile_FileFormat
   * Referenced by: '<S2>/To Host File'
   */
  1U,

  /* Expression: file_name_argument
   * Referenced by: '<S2>/To Host File'
   */
  { 115U, 97U, 118U, 101U, 100U, 95U, 100U, 97U, 116U, 97U, 92U, 81U, 68U, 50U,
    95U, 68U, 114U, 111U, 110U, 101U, 83U, 116U, 97U, 99U, 107U, 95U, 77U, 97U,
    110U, 117U, 97U, 108U, 95U, 50U, 48U, 50U, 49U, 97U, 92U, 108U, 111U, 103U,
    95U, 81U, 68U, 50U, 95U, 50U, 48U, 50U, 54U, 45U, 48U, 56U, 45U, 49U, 52U,
    95U, 49U, 55U, 45U, 49U, 50U, 45U, 50U, 53U, 46U, 109U, 97U, 116U, 0U },

  /* Expression: variable_name_argument
   * Referenced by: '<S4>/To Host File'
   */
  { 115U, 116U, 97U, 98U, 105U, 108U, 105U, 122U, 101U, 114U, 95U, 100U, 97U,
    116U, 97U, 0U },

  /* Computed Parameter: ToHostFile_FileFormat_j
   * Referenced by: '<S4>/To Host File'
   */
  2U,

  /* Expression: file_name_argument
   * Referenced by: '<S4>/To Host File'
   */
  { 115U, 97U, 118U, 101U, 100U, 95U, 100U, 97U, 116U, 97U, 47U, 81U, 68U, 50U,
    95U, 68U, 114U, 111U, 110U, 101U, 83U, 116U, 97U, 99U, 107U, 95U, 77U, 97U,
    110U, 117U, 97U, 108U, 95U, 50U, 48U, 50U, 49U, 97U, 47U, 108U, 111U, 103U,
    95U, 50U, 48U, 50U, 54U, 45U, 48U, 56U, 45U, 49U, 52U, 95U, 49U, 55U, 45U,
    49U, 50U, 45U, 50U, 53U, 95U, 83U, 116U, 97U, 98U, 105U, 108U, 105U, 122U,
    101U, 114U, 46U, 109U, 97U, 116U, 0U },

  /* Expression: uri_argument
   * Referenced by: '<S2>/Stream Server'
   */
  { 116U, 99U, 112U, 105U, 112U, 58U, 47U, 47U, 108U, 111U, 99U, 97U, 108U, 104U,
    111U, 115U, 116U, 58U, 49U, 56U, 52U, 57U, 49U, 63U, 110U, 97U, 103U, 108U,
    101U, 61U, 39U, 111U, 102U, 102U, 39U, 0U },

  /* Computed Parameter: StreamServer_Endian
   * Referenced by: '<S2>/Stream Server'
   */
  1U,

  /* Start of '<S37>/CoreSubsys' */
  {
    /* Mask Parameter: CompareToConstant_const
     * Referenced by: '<S39>/Constant'
     */
    0.5
  }
  ,

  /* End of '<S37>/CoreSubsys' */

  /* Start of '<S28>/CoreSubsys' */
  {
    /* Expression: 120
     * Referenced by: '<S28>/Accelerometer Filter Cutoff Frequency (rad//s)'
     */
    120.0,

    /* Expression: 1
     * Referenced by: '<S28>/Accelerometer Filter Damping Ratio'
     */
    1.0,

    /* Expression: 0
     * Referenced by: '<S28>/Integrator1'
     */
    0.0,

    /* Expression: [0.25 0.25]
     * Referenced by: '<S28>/Gain'
     */
    { 0.25, 0.25 },

    /* Expression: [0.1 0.1]
     * Referenced by: '<S28>/Gain1'
     */
    { 0.1, 0.1 },

    /* Expression: 100
     * Referenced by: '<S28>/Gyro Filter Cutoff Frequency (rad//s)'
     */
    100.0,

    /* Expression: 0.7
     * Referenced by: '<S28>/Gyro Filter Damping Ratio'
     */
    0.7,

    /* Expression: 0
     * Referenced by: '<S28>/Integrator2'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S30>/Integrator2'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S28>/Integrator'
     */
    0.0,

    /* Expression: 2
     * Referenced by: '<S30>/Constant'
     */
    2.0,

    /* Expression: 2
     * Referenced by: '<S31>/Constant'
     */
    2.0,

    /* Expression: 0
     * Referenced by: '<S31>/Integrator2'
     */
    0.0
  }
  /* End of '<S28>/CoreSubsys' */
};
