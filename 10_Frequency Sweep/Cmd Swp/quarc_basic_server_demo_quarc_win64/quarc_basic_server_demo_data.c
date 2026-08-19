/*
 * quarc_basic_server_demo_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "quarc_basic_server_demo".
 *
 * Model version              : 1.28
 * Simulink Coder version : 26.1 (R2026a) 20-Nov-2025
 * C source code generated on : Mon Aug 10 15:24:04 2026
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "quarc_basic_server_demo.h"

/* Block parameters (default storage) */
P_quarc_basic_server_demo_T quarc_basic_server_demo_P = {
  /* Mask Parameter: StreamServer_default_value
   * Referenced by: '<Root>/Stream Server'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Sine Wave'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Sine Wave'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant'
   */
  1.0,

  /* Computed Parameter: StreamServer_SndPriority
   * Referenced by: '<Root>/Stream Server'
   */
  0,

  /* Computed Parameter: StreamServer_RcvPriority
   * Referenced by: '<Root>/Stream Server'
   */
  0,

  /* Computed Parameter: StreamServer_SndSize
   * Referenced by: '<Root>/Stream Server'
   */
  1460U,

  /* Computed Parameter: StreamServer_RcvSize
   * Referenced by: '<Root>/Stream Server'
   */
  1460U,

  /* Computed Parameter: StreamServer_SndFIFO
   * Referenced by: '<Root>/Stream Server'
   */
  1000U,

  /* Computed Parameter: StreamServer_RcvFIFO
   * Referenced by: '<Root>/Stream Server'
   */
  1000U,

  /* Computed Parameter: StreamServer_Active
   * Referenced by: '<Root>/Stream Server'
   */
  false,

  /* Computed Parameter: StreamServer_Optimize
   * Referenced by: '<Root>/Stream Server'
   */
  2,

  /* Computed Parameter: StreamServer_Implementation
   * Referenced by: '<Root>/Stream Server'
   */
  2,

  /* Expression: uri_argument
   * Referenced by: '<Root>/Stream Server'
   */
  { 116U, 99U, 112U, 105U, 112U, 58U, 47U, 47U, 108U, 111U, 99U, 97U, 108U, 104U,
    111U, 115U, 116U, 58U, 49U, 56U, 48U, 48U, 48U, 0U },

  /* Computed Parameter: StreamServer_Endian
   * Referenced by: '<Root>/Stream Server'
   */
  1U
};
