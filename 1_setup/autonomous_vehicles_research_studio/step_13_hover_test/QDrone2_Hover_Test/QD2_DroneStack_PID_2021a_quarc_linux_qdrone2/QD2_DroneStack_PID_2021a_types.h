/*
 * QD2_DroneStack_PID_2021a_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "QD2_DroneStack_PID_2021a".
 *
 * Model version              : 11.3
 * Simulink Coder version : 26.1 (R2026a) 20-Nov-2025
 * C source code generated on : Tue Aug  4 16:12:14 2026
 *
 * Target selection: quarc_linux_qdrone2.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef QD2_DroneStack_PID_2021a_types_h_
#define QD2_DroneStack_PID_2021a_types_h_
#include "rtwtypes.h"
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /* struct_emxArray_real_T */

#ifndef typedef_emxArray_real_T_QD2_DroneStac_T
#define typedef_emxArray_real_T_QD2_DroneStac_T

typedef struct emxArray_real_T emxArray_real_T_QD2_DroneStac_T;

#endif                             /* typedef_emxArray_real_T_QD2_DroneStac_T */

/* Parameters for system: '<S16>/Boolean Edge-Based Triggered Print' */
typedef struct P_CoreSubsys_QD2_DroneStack_P_T_ P_CoreSubsys_QD2_DroneStack_P_T;

/* Parameters for system: '<S18>/Boolean Value-Based Triggered Print' */
typedef struct P_CoreSubsys_QD2_DroneStack_g_T_ P_CoreSubsys_QD2_DroneStack_g_T;

/* Parameters for system: '<S13>/Use desired height when enabled' */
typedef struct P_Usedesiredheightwhenenabled_T_ P_Usedesiredheightwhenenabled_T;

/* Parameters for system: '<S63>/For Each Subsystem - Iterate over IMU0 and IMU1' */
typedef struct P_CoreSubsys_QD2_DroneStac_gm_T_ P_CoreSubsys_QD2_DroneStac_gm_T;

/* Parameters for system: '<S70>/For Each Subsystem' */
typedef struct P_CoreSubsys_QD2_DroneSt_gmy0_T_ P_CoreSubsys_QD2_DroneSt_gmy0_T;

/* Parameters (default storage) */
typedef struct P_QD2_DroneStack_PID_2021a_T_ P_QD2_DroneStack_PID_2021a_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_QD2_DroneStack_PID_20_T RT_MODEL_QD2_DroneStack_PID_2_T;

#endif                                 /* QD2_DroneStack_PID_2021a_types_h_ */
