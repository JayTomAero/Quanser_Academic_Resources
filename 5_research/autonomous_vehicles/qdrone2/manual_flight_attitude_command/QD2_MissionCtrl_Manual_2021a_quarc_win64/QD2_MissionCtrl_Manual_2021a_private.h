/*
 * QD2_MissionCtrl_Manual_2021a_private.h
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

#ifndef QD2_MissionCtrl_Manual_2021a_private_h_
#define QD2_MissionCtrl_Manual_2021a_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "QD2_MissionCtrl_Manual_2021a_types.h"
#include "QD2_MissionCtrl_Manual_2021a.h"

/* A global buffer for storing error messages (defined in quanser_common library) */
EXTERN char _rt_error_message[512];
extern t_error host_send_extmode_packet(void * context, const void * data,
  t_uint data_length);

#endif                             /* QD2_MissionCtrl_Manual_2021a_private_h_ */
