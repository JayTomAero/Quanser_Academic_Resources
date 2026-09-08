/*
 * QD2_DroneStack_PID_2021a_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "QD2_DroneStack_PID_2021a".
 *
 * Model version              : 11.8
 * Simulink Coder version : 26.1 (R2026a) 20-Nov-2025
 * C source code generated on : Fri Sep  4 17:04:36 2026
 *
 * Target selection: quarc_linux_qdrone2.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef QD2_DroneStack_PID_2021a_private_h_
#define QD2_DroneStack_PID_2021a_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "QD2_DroneStack_PID_2021a.h"
#include "QD2_DroneStack_PID_2021a_types.h"

/* A global buffer for storing error messages (defined in quanser_common library) */
EXTERN char _rt_error_message[512];
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern void Usedesiredheightwhenen_Init(B_Usedesiredheightwhenenabled_T *localB,
  P_Usedesiredheightwhenenabled_T *localP);
extern void Usedesiredheightwhene_Start(DW_Usedesiredheightwhenenable_T *localDW);
extern void Usedesiredheightwhe_Disable(B_Usedesiredheightwhenenabled_T *localB,
  DW_Usedesiredheightwhenenable_T *localDW, P_Usedesiredheightwhenenabled_T
  *localP);
extern void Usedesiredheightwhenenabled(RT_MODEL_QD2_DroneStack_PID_2_T * const
  QD2_DroneStack_PID_2021a_M, real_T rtu_Enable, real_T rtu_h_dm1,
  B_Usedesiredheightwhenenabled_T *localB, DW_Usedesiredheightwhenenable_T
  *localDW, P_Usedesiredheightwhenenabled_T *localP);
extern void ForEachSubsystemConstructES(int32_T NumIters, const real_T
  rtu_ESCDataIn4[4], real_T rtu_ESCChannel, const real_T rtu_ESCPreviousData4[4],
  real_T rty_ESCDataOut4[4]);

/* private model entry point functions */
extern void QD2_DroneStack_PID_2021a_derivatives(void);

#endif                                 /* QD2_DroneStack_PID_2021a_private_h_ */
