/*
 * Joystick_Visualization_2019a_private.h
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

#ifndef Joystick_Visualization_2019a_private_h_
#define Joystick_Visualization_2019a_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "Joystick_Visualization_2019a.h"
#include "Joystick_Visualization_2019a_types.h"

/* A global buffer for storing error messages (defined in quanser_common library) */
EXTERN char _rt_error_message[512];
extern real_T rt_powd_snf(real_T u0, real_T u1);
extern t_error host_send_extmode_packet(void * context, const void * data,
  t_uint data_length);
extern void Jo_Usedesheightwhenenabled_Init(B_Usedesheightwhenenabled_Joy_T
  *localB, P_Usedesheightwhenenabled_Joy_T *localP);
extern void J_Usedesheightwhenenabled_Start(DW_Usedesheightwhenenabled_Jo_T
  *localDW);
extern void Usedesheightwhenenabled_Disable(B_Usedesheightwhenenabled_Joy_T
  *localB, DW_Usedesheightwhenenabled_Jo_T *localDW,
  P_Usedesheightwhenenabled_Joy_T *localP);
extern void Joystic_Usedesheightwhenenabled(RT_MODEL_Joystick_Visualizati_T *
  const Joystick_Visualization_2019a_M, real_T rtu_Enable, real_T rtu_h_dm1,
  B_Usedesheightwhenenabled_Joy_T *localB, DW_Usedesheightwhenenabled_Jo_T
  *localDW, P_Usedesheightwhenenabled_Joy_T *localP);

/* private model entry point functions */
extern void Joystick_Visualization_2019a_derivatives(void);

#endif                             /* Joystick_Visualization_2019a_private_h_ */
