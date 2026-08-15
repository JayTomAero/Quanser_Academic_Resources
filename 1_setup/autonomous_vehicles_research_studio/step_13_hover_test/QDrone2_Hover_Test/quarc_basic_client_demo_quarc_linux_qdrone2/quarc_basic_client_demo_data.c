/*
 * quarc_basic_client_demo_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "quarc_basic_client_demo".
 *
 * Model version              : 1.29
 * Simulink Coder version : 26.1 (R2026a) 20-Nov-2025
 * C source code generated on : Wed Aug 12 11:46:28 2026
 *
 * Target selection: quarc_linux_qdrone2.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "quarc_basic_client_demo.h"

/* Block parameters (default storage) */
P_quarc_basic_client_demo_T quarc_basic_client_demo_P = {
  /* Mask Parameter: StreamClient_default_value
   * Referenced by: '<Root>/Stream Client'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Signal Generator'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Signal Generator'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant'
   */
  1.0,

  /* Computed Parameter: StreamClient_SndPriority
   * Referenced by: '<Root>/Stream Client'
   */
  0,

  /* Computed Parameter: StreamClient_RcvPriority
   * Referenced by: '<Root>/Stream Client'
   */
  0,

  /* Computed Parameter: StreamClient_SndSize
   * Referenced by: '<Root>/Stream Client'
   */
  1460U,

  /* Computed Parameter: StreamClient_RcvSize
   * Referenced by: '<Root>/Stream Client'
   */
  1460U,

  /* Computed Parameter: StreamClient_SndFIFO
   * Referenced by: '<Root>/Stream Client'
   */
  1000U,

  /* Computed Parameter: StreamClient_RcvFIFO
   * Referenced by: '<Root>/Stream Client'
   */
  1000U,

  /* Computed Parameter: StreamClient_Active
   * Referenced by: '<Root>/Stream Client'
   */
  false,

  /* Computed Parameter: StreamClient_Optimize
   * Referenced by: '<Root>/Stream Client'
   */
  2,

  /* Computed Parameter: StreamClient_Implementation
   * Referenced by: '<Root>/Stream Client'
   */
  2,

  /* Expression: uri_argument
   * Referenced by: '<Root>/Stream Client'
   */
  { 116U, 99U, 112U, 105U, 112U, 58U, 47U, 47U, 49U, 57U, 50U, 46U, 49U, 54U,
    56U, 46U, 50U, 46U, 49U, 51U, 51U, 58U, 49U, 56U, 48U, 48U, 48U, 0U },

  /* Computed Parameter: StreamClient_Endian
   * Referenced by: '<Root>/Stream Client'
   */
  1U
};
