/*
 * QD2_DroneStack_PID_2021a.c
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

#include "QD2_DroneStack_PID_2021a.h"
#include "rtwtypes.h"
#include "QD2_DroneStack_PID_2021a_types.h"
#include "QD2_DroneStack_PID_2021a_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "zero_crossing_types.h"
#include "rt_defines.h"
#include "QD2_DroneStack_PID_2021a_dt.h"

/* Named constants for MATLAB Function: '<S1>/STATE MACHINE LOGIC' */
#define QD2_DroneStack_PID_2_CALL_EVENT (-1)

/* Block signals (default storage) */
B_QD2_DroneStack_PID_2021a_T QD2_DroneStack_PID_2021a_B;

/* Continuous states */
X_QD2_DroneStack_PID_2021a_T QD2_DroneStack_PID_2021a_X;

/* Disabled State Vector */
XDis_QD2_DroneStack_PID_2021a_T QD2_DroneStack_PID_2021a_XDis;

/* Block states (default storage) */
DW_QD2_DroneStack_PID_2021a_T QD2_DroneStack_PID_2021a_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_QD2_DroneStack_PID_20_T QD2_DroneStack_PID_2021_PrevZCX;

/* Real-time model */
static RT_MODEL_QD2_DroneStack_PID_2_T QD2_DroneStack_PID_2021a_M_;
RT_MODEL_QD2_DroneStack_PID_2_T *const QD2_DroneStack_PID_2021a_M =
  &QD2_DroneStack_PID_2021a_M_;

/* Forward declaration for local functions */
static void QD2_DroneStack_P_emxInit_real_T(emxArray_real_T_QD2_DroneStac_T
  **pEmxArray, int32_T numDimensions);
static void QD2_Dr_emxEnsureCapacity_real_T(emxArray_real_T_QD2_DroneStac_T
  *emxArray, int32_T oldNumel);
static void QD2_DroneStack_P_emxFree_real_T(emxArray_real_T_QD2_DroneStac_T
  **pEmxArray);
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(QD2_DroneStack_PID_2021a_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(QD2_DroneStack_PID_2021a_M, 2);
  rtmSampleHitPtr[3] = rtmStepTask(QD2_DroneStack_PID_2021a_M, 3);
  rtmSampleHitPtr[4] = rtmStepTask(QD2_DroneStack_PID_2021a_M, 4);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rates: 2, 3, 4 */
  if (QD2_DroneStack_PID_2021a_M->Timing.TaskCounters.TID[1] == 0) {
    QD2_DroneStack_PID_2021a_M->Timing.RateInteraction.TID1_2 =
      (QD2_DroneStack_PID_2021a_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    QD2_DroneStack_PID_2021a_M->Timing.perTaskSampleHits[7] =
      QD2_DroneStack_PID_2021a_M->Timing.RateInteraction.TID1_2;
    QD2_DroneStack_PID_2021a_M->Timing.RateInteraction.TID1_3 =
      (QD2_DroneStack_PID_2021a_M->Timing.TaskCounters.TID[3] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    QD2_DroneStack_PID_2021a_M->Timing.perTaskSampleHits[8] =
      QD2_DroneStack_PID_2021a_M->Timing.RateInteraction.TID1_3;
    QD2_DroneStack_PID_2021a_M->Timing.RateInteraction.TID1_4 =
      (QD2_DroneStack_PID_2021a_M->Timing.TaskCounters.TID[4] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    QD2_DroneStack_PID_2021a_M->Timing.perTaskSampleHits[9] =
      QD2_DroneStack_PID_2021a_M->Timing.RateInteraction.TID1_4;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (QD2_DroneStack_PID_2021a_M->Timing.TaskCounters.TID[2])++;
  if ((QD2_DroneStack_PID_2021a_M->Timing.TaskCounters.TID[2]) > 1) {/* Sample time: [0.002s, 0.0s] */
    QD2_DroneStack_PID_2021a_M->Timing.TaskCounters.TID[2] = 0;
  }

  (QD2_DroneStack_PID_2021a_M->Timing.TaskCounters.TID[3])++;
  if ((QD2_DroneStack_PID_2021a_M->Timing.TaskCounters.TID[3]) > 9) {/* Sample time: [0.01s, 0.0s] */
    QD2_DroneStack_PID_2021a_M->Timing.TaskCounters.TID[3] = 0;
  }

  (QD2_DroneStack_PID_2021a_M->Timing.TaskCounters.TID[4])++;
  if ((QD2_DroneStack_PID_2021a_M->Timing.TaskCounters.TID[4]) > 39) {/* Sample time: [0.04s, 0.0s] */
    QD2_DroneStack_PID_2021a_M->Timing.TaskCounters.TID[4] = 0;
  }
}

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 56;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  QD2_DroneStack_PID_2021a_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * System initialize for enable system:
 *    '<S13>/Use desired height when enabled'
 *    '<S51>/Use des height  when enabled'
 *    '<S51>/Use des yaw  when enabled'
 *    '<S51>/Use desired X  when enabled'
 *    '<S51>/Use desired Y  when enabled'
 */
void Usedesiredheightwhenen_Init(B_Usedesiredheightwhenenabled_T *localB,
  P_Usedesiredheightwhenenabled_T *localP)
{
  /* SystemInitialize for SignalConversion generated from: '<S46>/h_d (m) [1]' incorporates:
   *  Outport: '<S46>/Out1'
   */
  localB->h_dm1 = localP->Out1_Y0;
}

/*
 * Disable for enable system:
 *    '<S13>/Use desired height when enabled'
 *    '<S51>/Use des height  when enabled'
 *    '<S51>/Use des yaw  when enabled'
 *    '<S51>/Use desired X  when enabled'
 *    '<S51>/Use desired Y  when enabled'
 */
void Usedesiredheightwhe_Disable(B_Usedesiredheightwhenenabled_T *localB,
  DW_Usedesiredheightwhenenable_T *localDW, P_Usedesiredheightwhenenabled_T
  *localP)
{
  /* Disable for SignalConversion generated from: '<S46>/h_d (m) [1]' incorporates:
   *  Outport: '<S46>/Out1'
   */
  localB->h_dm1 = localP->Out1_Y0;
  localDW->Usedesiredheightwhenenabled_MOD = false;
}

/*
 * Start for enable system:
 *    '<S13>/Use desired height when enabled'
 *    '<S51>/Use des height  when enabled'
 *    '<S51>/Use des yaw  when enabled'
 *    '<S51>/Use desired X  when enabled'
 *    '<S51>/Use desired Y  when enabled'
 */
void Usedesiredheightwhene_Start(DW_Usedesiredheightwhenenable_T *localDW)
{
  localDW->Usedesiredheightwhenenabled_MOD = false;
}

/*
 * Output and update for enable system:
 *    '<S13>/Use desired height when enabled'
 *    '<S51>/Use des height  when enabled'
 *    '<S51>/Use des yaw  when enabled'
 *    '<S51>/Use desired X  when enabled'
 *    '<S51>/Use desired Y  when enabled'
 */
void Usedesiredheightwhenenabled(RT_MODEL_QD2_DroneStack_PID_2_T * const
  QD2_DroneStack_PID_2021a_M, real_T rtu_Enable, real_T rtu_h_dm1,
  B_Usedesiredheightwhenenabled_T *localB, DW_Usedesiredheightwhenenable_T
  *localDW, P_Usedesiredheightwhenenabled_T *localP)
{
  /* Outputs for Enabled SubSystem: '<S13>/Use desired height when enabled' incorporates:
   *  EnablePort: '<S46>/Enable'
   */
  if (rtsiIsModeUpdateTimeStep(&QD2_DroneStack_PID_2021a_M->solverInfo)) {
    if (rtu_Enable > 0.0) {
      localDW->Usedesiredheightwhenenabled_MOD = true;
    } else if (localDW->Usedesiredheightwhenenabled_MOD) {
      Usedesiredheightwhe_Disable(localB, localDW, localP);
    }
  }

  if (localDW->Usedesiredheightwhenenabled_MOD) {
    /* SignalConversion generated from: '<S46>/h_d (m) [1]' */
    localB->h_dm1 = rtu_h_dm1;
    if (rtsiIsModeUpdateTimeStep(&QD2_DroneStack_PID_2021a_M->solverInfo)) {
      srUpdateBC(localDW->Usedesiredheightwhenenabled_Sub);
    }
  }

  /* End of Outputs for SubSystem: '<S13>/Use desired height when enabled' */
}

/*
 * Output and update for iterator system:
 *    '<S67>/For Each Subsystem -  Construct ESC Signal'
 *    '<S68>/For Each Subsystem -  Construct ESC Signal'
 *    '<S69>/For Each Subsystem -  Construct ESC Signal'
 */
void ForEachSubsystemConstructES(int32_T NumIters, const real_T rtu_ESCDataIn4[4],
  real_T rtu_ESCChannel, const real_T rtu_ESCPreviousData4[4], real_T
  rty_ESCDataOut4[4])
{
  /* local block i/o variables */
  int32_T rtb_ForEach;

  /* local scratch DWork variables */
  int32_T ForEach_itr;

  /* Outputs for Iterator SubSystem: '<S67>/For Each Subsystem -  Construct ESC Signal' incorporates:
   *  ForEach: '<S87>/For Each'
   */
  for (ForEach_itr = 0; ForEach_itr < NumIters; ForEach_itr++) {
    /* Outputs for Iterator SubSystem: '<S67>/For Each Subsystem -  Construct ESC Signal' incorporates:
     *  ForEach: '<S87>/For Each'
     */
    rtb_ForEach = ForEach_itr;

    /* Switch: '<S87>/Switch' incorporates:
     *  S-Function (compare_block): '<S87>/Compare'
     */
    if ((rtb_ForEach == rtu_ESCChannel)) {
      /* ForEachSliceAssignment generated from: '<S87>/ESC Data Out [4]' incorporates:
       *  ForEachSliceSelector generated from: '<S87>/ESC Data In [4]'
       */
      rty_ESCDataOut4[ForEach_itr] = rtu_ESCDataIn4[ForEach_itr];
    } else {
      /* ForEachSliceAssignment generated from: '<S87>/ESC Data Out [4]' incorporates:
       *  ForEachSliceSelector generated from: '<S87>/ESC Previous Data [4]'
       */
      rty_ESCDataOut4[ForEach_itr] = rtu_ESCPreviousData4[ForEach_itr];
    }

    /* End of Switch: '<S87>/Switch' */
  }

  /* End of Outputs for SubSystem: '<S67>/For Each Subsystem -  Construct ESC Signal' */
}

static void QD2_DroneStack_P_emxInit_real_T(emxArray_real_T_QD2_DroneStac_T
  **pEmxArray, int32_T numDimensions)
{
  emxArray_real_T_QD2_DroneStac_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T_QD2_DroneStac_T *)malloc(sizeof
    (emxArray_real_T_QD2_DroneStac_T));
  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc(sizeof(int32_T) * (uint32_T)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void QD2_Dr_emxEnsureCapacity_real_T(emxArray_real_T_QD2_DroneStac_T
  *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = malloc((uint32_T)i * sizeof(real_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(real_T) * (uint32_T)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (real_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T tmp;
  int32_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u1 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = atan2(tmp, tmp_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

static void QD2_DroneStack_P_emxFree_real_T(emxArray_real_T_QD2_DroneStac_T
  **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T_QD2_DroneStac_T *)NULL) {
    if (((*pEmxArray)->data != (real_T *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_real_T_QD2_DroneStac_T *)NULL;
  }
}

/* Model output function for TID0 */
void QD2_DroneStack_PID_2021a_output0(void) /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_Time;
  real_T rtb_ESCOutput[4];
  real_T rtb_Product[4];
  real_T rtb_Memory_e[4];
  real_T rtb_Product1[4];
  real_T rtb_Memory_i[4];
  real_T rtb_Product2[4];
  real_T rtb_Memory_ic[4];
  real_T rtb_Product1_j;
  real_T rtb_Product_j;
  real_T rtb_Product2_p;
  real_T rtb_Subtract2;
  real_T rtb_u5ofCommandedHeight;
  real_T rtb_Time_d;
  real_T rtb_ImpSel_InsertedFor_ChannelR;
  real_T rtb_ImpSel_InsertedFor_Channe_e;
  int32_T rtb_Print_o1;
  int32_T rtb_Print_o1_h;
  int32_T rtb_Print_o1_l;

  /* local scratch DWork variables */
  int32_T ForEach_itr;
  int32_T ForEach_itr_a;
  int32_T ForEach_itr_h;
  int32_T ForEach_itr_b;
  real_T rtb_ImpAsg_InsertedFor_BFEstima[18];
  real_T rtb_BFToIFrotationmatrix[9];
  real_T rtb_EulerAnglestoRotationMatrix[9];
  real_T rtb_MultiportSwitch[6];
  real_T Duty_Cycle[4];
  real_T rtb_KiradsmradsmNsmradsrads[4];
  real_T Duty_Cycle_0;
  real_T data_loss;
  real_T rtb_DataTypeConversion3;
  real_T rtb_Integrator2_idx_0;
  real_T rtb_Product_h_idx_0;
  real_T rtb_Product_h_idx_1;
  real_T rtb_Product_h_idx_2;
  real_T rtb_Sum1_c_idx_0;
  real_T rtb_Sum1_c_idx_1;
  real_T rtb_Sum1_c_idx_2;
  real_T rtb_Sum1_j_idx_1;
  real_T sigmoid;
  real_T tmp;
  real_T tmp_0;
  real_T tmp_1;
  int32_T b_k;
  int32_T exitg1;
  int32_T firstBlockLength;
  int32_T hi;
  int32_T i;
  int32_T lastBlockLength;
  int32_T xblockoffset;
  int32_T xoffset;
  uint16_T rtb_DataTypeConversion1[4];
  uint8_T rtb_MatrixConcatenate[720];
  uint8_T rtb_MultiportSwitch_o[80];
  boolean_T rtb_TmpSignalConversionAtBoolea[9];
  boolean_T tmpForInput_0[7];
  boolean_T tmpForInput[6];
  boolean_T rtb_ImpAsg_InsertedFor_mismatch[4];
  boolean_T pt_EMERGENCY_ABORT_TO_DISABLE;
  boolean_T rtb_AND2;
  boolean_T rtb_AND3;
  boolean_T rtb_Compare_f;
  boolean_T rtb_DataTypeConversion3_k;
  boolean_T rtb_Relation;
  boolean_T rtb_Relation_a;
  boolean_T rtb_Relation_bl;
  boolean_T rtb_Relation_en;
  boolean_T rtb_Relation_f;
  boolean_T rtb_Relation_j;
  boolean_T rtb_Relation_k;
  boolean_T rtb_Relation_l;
  boolean_T rtb_Relation_m;
  boolean_T rtb_RelationalOperator;
  ZCEventType zcEvent;
  if (rtmIsMajorTimeStep(QD2_DroneStack_PID_2021a_M)) {
    /* set solver stop time */
    if (!(QD2_DroneStack_PID_2021a_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&QD2_DroneStack_PID_2021a_M->solverInfo,
                            ((QD2_DroneStack_PID_2021a_M->Timing.clockTickH0 + 1)
        * QD2_DroneStack_PID_2021a_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&QD2_DroneStack_PID_2021a_M->solverInfo,
                            ((QD2_DroneStack_PID_2021a_M->Timing.clockTick0 + 1)
        * QD2_DroneStack_PID_2021a_M->Timing.stepSize0 +
        QD2_DroneStack_PID_2021a_M->Timing.clockTickH0 *
        QD2_DroneStack_PID_2021a_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(QD2_DroneStack_PID_2021a_M)) {
    QD2_DroneStack_PID_2021a_M->Timing.t[0] = rtsiGetT
      (&QD2_DroneStack_PID_2021a_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(QD2_DroneStack_PID_2021a_DW.TriggeredSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(QD2_DroneStack_PID_2021a_DW.LatchEStop_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC
    (QD2_DroneStack_PID_2021a_DW.Usedesiredheightwhenenabled_c.Usedesiredheightwhenenabled_Sub);

  /* Reset subsysRan breadcrumbs */
  srClearBC(QD2_DroneStack_PID_2021a_DW.EnabledSubsystemWriteESCCommand);

  /* Reset subsysRan breadcrumbs */
  srClearBC(QD2_DroneStack_PID_2021a_DW.TriggeredSubsystemLatchingFlag_);

  /* RateTransition: '<S5>/Rate Transition6' */
  rtb_Compare_f = rtmIsMajorTimeStep(QD2_DroneStack_PID_2021a_M);
  if (rtb_Compare_f) {
    /* S-Function (hil_read_block): '<S5>/HIL Read' */

    /* S-Function Block: QD2_DroneStack_PID_2021a/QDrone 2 DAQ/HIL Read (hil_read_block) */
    {
      t_error result = hil_read(QD2_DroneStack_PID_2021a_DW.HILInitialize_Card,
        QD2_DroneStack_PID_2021a_P.HILRead_analog_channels, 3U,
        NULL, 0U,
        NULL, 0U,
        QD2_DroneStack_PID_2021a_P.HILRead_other_channels, 23U,
        &QD2_DroneStack_PID_2021a_B.HILRead_o1[0],
        NULL,
        NULL,
        &QD2_DroneStack_PID_2021a_B.HILRead_o2[0]
        );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M, _rt_error_message);
      }
    }

    /* S-Function (time_block): '<S5>/Time' */

    /* S-Function Block: QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Time (time_block) */
    {
      t_error result;
      t_timeout current_time;
      t_timeout time_difference;
      result = timeout_get_high_resolution_time(&current_time);
      if (result == 0) {
        result = timeout_subtract(&time_difference, &current_time,
          &_high_resolution_start_time);
        rtb_Time = time_difference.seconds + time_difference.nanoseconds * 1e-9;
      }

      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M, _rt_error_message);
        return;
      }
    }

    /* Memory: '<S2>/Memory' */
    rtb_DataTypeConversion3 = QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput;

    /* S-Function (stream_client_block): '<S2>/Stream Client' incorporates:
     *  Constant: '<S2>/Constant'
     */

    /* S-Function Block: QD2_DroneStack_PID_2021a/Communication/Stream Client (stream_client_block) */
    {
      t_pstream_state state;
      t_error send_result;
      t_error receive_result;
      if (!QD2_DroneStack_PID_2021a_DW.StreamClient_Connected) {
        qthread_attr_t send_thread_attributes;
        qthread_attr_t receive_thread_attributes;
        struct qsched_param scheduling_parameters;
        int min_priority = qsched_get_priority_min(QSCHED_FIFO);
        int max_priority = qsched_get_priority_max(QSCHED_FIFO);
        t_pstream_options options;
        t_error result;
        result = 0;
        options.size = sizeof(options);
        options.flags = QD2_DroneStack_PID_2021a_P.StreamClient_Endian &
          PSTREAM_FLAG_ENDIAN_MASK;
        if (QD2_DroneStack_PID_2021a_P.StreamClient_Implementation ==
            STREAM_CLIENT_IMPLEMENTATION_THREAD) {
          options.flags |= PSTREAM_FLAG_MULTITHREADED;
        }

        if (QD2_DroneStack_PID_2021a_P.StreamClient_Optimize ==
            STREAM_CLIENT_OPTIMIZE_LATENCY) {
          options.flags |= PSTREAM_FLAG_MINIMIZE_LATENCY;
        }

        options.flags |= PSTREAM_FLAG_SEND_MOST_RECENT;
        options.flags |= PSTREAM_FLAG_RECEIVE_MOST_RECENT;
        options.send_unit_size = 8;
        options.num_send_units = 1;
        options.send_buffer_size =
          QD2_DroneStack_PID_2021a_P.StreamClient_SndSize;
        options.send_fifo_size = QD2_DroneStack_PID_2021a_P.StreamClient_SndFIFO;
        options.num_send_dimensions = 0;
        options.max_send_dimensions = NULL;
        if (QD2_DroneStack_PID_2021a_P.StreamClient_SndPriority < min_priority)
        {
          scheduling_parameters.sched_priority = min_priority;
        } else if (QD2_DroneStack_PID_2021a_P.StreamClient_SndPriority >
                   max_priority) {
          scheduling_parameters.sched_priority = max_priority;
        } else {
          scheduling_parameters.sched_priority =
            QD2_DroneStack_PID_2021a_P.StreamClient_SndPriority;
        }

        qthread_attr_init(&send_thread_attributes);
        result = qthread_attr_setschedpolicy(&send_thread_attributes,
          QSCHED_FIFO);
        if (result == 0) {
          result = qthread_attr_setschedparam(&send_thread_attributes,
            &scheduling_parameters);
          if (result == 0) {
            result = qthread_attr_setinheritsched(&send_thread_attributes,
              QTHREAD_EXPLICIT_SCHED);
            if (result < 0) {
              rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M,
                                "Unable to set scheduling inheritance for Stream Client sending thread");
            }
          } else {
            rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M,
                              "The specified thread priority for the Stream Client sending thread is not valid for this target");
          }
        } else {
          rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M,
                            "Unable to set scheduling policy for Stream Client sending thread");
        }

        options.send_thread_attributes = &send_thread_attributes;
        options.receive_unit_size = 8;
        options.num_receive_units = 16;
        options.receive_buffer_size =
          QD2_DroneStack_PID_2021a_P.StreamClient_RcvSize;
        options.receive_fifo_size =
          QD2_DroneStack_PID_2021a_P.StreamClient_RcvFIFO;
        options.num_receive_dimensions = 0;
        options.max_receive_dimensions = NULL;
        if (QD2_DroneStack_PID_2021a_P.StreamClient_RcvPriority < min_priority)
        {
          scheduling_parameters.sched_priority = min_priority;
        } else if (QD2_DroneStack_PID_2021a_P.StreamClient_RcvPriority >
                   max_priority) {
          scheduling_parameters.sched_priority = max_priority;
        } else {
          scheduling_parameters.sched_priority =
            QD2_DroneStack_PID_2021a_P.StreamClient_RcvPriority;
        }

        qthread_attr_init(&receive_thread_attributes);
        if (result == 0) {
          result = qthread_attr_setschedpolicy(&receive_thread_attributes,
            QSCHED_FIFO);
          if (result == 0) {
            result = qthread_attr_setschedparam(&receive_thread_attributes,
              &scheduling_parameters);
            if (result == 0) {
              result = qthread_attr_setinheritsched(&receive_thread_attributes,
                QTHREAD_EXPLICIT_SCHED);
              if (result < 0) {
                rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M,
                                  "Unable to set scheduling inheritance for Stream Client receiving thread");
              }
            } else {
              rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M,
                                "The specified thread priority for the Stream Client receiving thread is not valid for this target");
            }
          } else {
            rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M,
                              "Unable to set scheduling policy for Stream Client receiving thread");
          }
        }

        options.receive_thread_attributes = &receive_thread_attributes;
        if (result == 0) {
          /* Make sure URI is null-terminated */
          if (string_length((char *) &QD2_DroneStack_PID_2021a_B.ModelArgument[0],
                            80) == 80) {
            rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M,
                              "URI passed to Stream Client block is not null-terminated!");
            result = -QERR_STRING_NOT_TERMINATED;
          } else {
            result = pstream_connect((char *)
              &QD2_DroneStack_PID_2021a_B.ModelArgument[0], &options,
              &QD2_DroneStack_PID_2021a_DW.StreamClient_Stream);
            if (result < 0 && result != -QERR_WOULD_BLOCK) {
              msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
                (_rt_error_message));
              rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M, _rt_error_message);
            }
          }
        }

        qthread_attr_destroy(&send_thread_attributes);
        qthread_attr_destroy(&receive_thread_attributes);
        QD2_DroneStack_PID_2021a_DW.StreamClient_Connected = true;
      }

      if (QD2_DroneStack_PID_2021a_P.Constant_Value_d) {
        send_result = pstream_send
          (QD2_DroneStack_PID_2021a_DW.StreamClient_Stream,
           &rtb_DataTypeConversion3);
      } else {
        send_result = 0;
      }

      receive_result = pstream_receive
        (QD2_DroneStack_PID_2021a_DW.StreamClient_Stream,
         &QD2_DroneStack_PID_2021a_B.StreamClient_o4[0]);
      QD2_DroneStack_PID_2021a_B.StreamClient_o2 = 0;
      if (send_result < 0 && send_result != -QERR_WOULD_BLOCK) {
        QD2_DroneStack_PID_2021a_B.StreamClient_o2 = send_result;
      } else if (receive_result < 0 && receive_result != -QERR_WOULD_BLOCK) {
        QD2_DroneStack_PID_2021a_B.StreamClient_o2 = receive_result;
      }

      pstream_get_state(QD2_DroneStack_PID_2021a_DW.StreamClient_Stream, &state);
      QD2_DroneStack_PID_2021a_B.StreamClient_o1 = state;
    }

    /* DataTypeConversion: '<S10>/Data Type Conversion' */
    QD2_DroneStack_PID_2021a_B.DataTypeConversion_pb[0] =
      (QD2_DroneStack_PID_2021a_B.StreamClient_o4[0] != 0.0);
    QD2_DroneStack_PID_2021a_B.DataTypeConversion_pb[1] =
      (QD2_DroneStack_PID_2021a_B.StreamClient_o4[1] != 0.0);
    QD2_DroneStack_PID_2021a_B.DataTypeConversion_pb[2] =
      (QD2_DroneStack_PID_2021a_B.StreamClient_o4[2] != 0.0);
    QD2_DroneStack_PID_2021a_B.DataTypeConversion_pb[3] =
      (QD2_DroneStack_PID_2021a_B.StreamClient_o4[3] != 0.0);

    /* DataTypeConversion: '<S10>/Data Type Conversion22' */
    QD2_DroneStack_PID_2021a_B.DataTypeConversion22 =
      QD2_DroneStack_PID_2021a_B.DataTypeConversion_pb[0];

    /* Outputs for Triggered SubSystem: '<S10>/Latch E-Stop' incorporates:
     *  TriggerPort: '<S20>/Trigger'
     */
    if (rtsiIsModeUpdateTimeStep(&QD2_DroneStack_PID_2021a_M->solverInfo)) {
      if (QD2_DroneStack_PID_2021a_B.DataTypeConversion_pb[2] &&
          (QD2_DroneStack_PID_2021_PrevZCX.LatchEStop_Trig_ZCE != POS_ZCSIG)) {
        /* SignalConversion generated from: '<S20>/Input' */
        QD2_DroneStack_PID_2021a_B.Input =
          QD2_DroneStack_PID_2021a_B.DataTypeConversion_pb[2];
        QD2_DroneStack_PID_2021a_DW.LatchEStop_SubsysRanBC = 4;
      }

      QD2_DroneStack_PID_2021_PrevZCX.LatchEStop_Trig_ZCE =
        QD2_DroneStack_PID_2021a_B.DataTypeConversion_pb[2];
    }

    /* End of Outputs for SubSystem: '<S10>/Latch E-Stop' */

    /* DataTypeConversion: '<S10>/Data Type Conversion24' */
    QD2_DroneStack_PID_2021a_B.DataTypeConversion24 =
      QD2_DroneStack_PID_2021a_B.Input;

    /* DataTypeConversion: '<S1>/Data Type Conversion1' incorporates:
     *  Logic: '<S1>/Logical Operator1'
     *  Logic: '<S1>/Logical Operator2'
     */
    QD2_DroneStack_PID_2021a_B.DataTypeConversion1 =
      (QD2_DroneStack_PID_2021a_B.DataTypeConversion22 &&
       !QD2_DroneStack_PID_2021a_B.DataTypeConversion24);

    /* MATLAB Function: '<S5>/MATLAB Function' incorporates:
     *  Memory: '<S5>/Memory'
     *  Memory: '<S5>/Memory1'
     */
    QD2_DroneStack_PID_2021a_DW.sfEvent = QD2_DroneStack_PID_2_CALL_EVENT;

    /* MATLAB Function 'QDrone 2 DAQ/MATLAB Function': '<S76>:1' */
    /* '<S76>:1:49' */
    /* '<S76>:1:241' */
    /* '<S76>:1:218' */
    /* '<S76>:1:206' */
    /* '<S76>:1:9' */
    sigmoid = 0.0;

    /* '<S76>:1:10' */
    /* '<S76>:1:11' */
    /* '<S76>:1:12' */
    /* '<S76>:1:13' */
    /* '<S76>:1:14' */
    /* '<S76>:1:15' */
    /* '<S76>:1:16' */
    /* '<S76>:1:17' */
    /* '<S76>:1:21' */
    /* '<S76>:1:22' */
    /* '<S76>:1:23' */
    /* '<S76>:1:25' */
    /* '<S76>:1:27' */
    /* '<S76>:1:28' */
    /* '<S76>:1:29' */
    /* '<S76>:1:48' */
    /* '<S76>:1:49' */
    QD2_DroneStack_PID_2021a_B.cmd[0] = 0.0;
    QD2_DroneStack_PID_2021a_B.cmd[1] = 0.0;
    QD2_DroneStack_PID_2021a_B.cmd[2] = 0.0;
    QD2_DroneStack_PID_2021a_B.cmd[3] = 0.0;

    /* '<S76>:1:50' */
    QD2_DroneStack_PID_2021a_B.tele_enable = 0.0;

    /* '<S76>:1:51' */
    QD2_DroneStack_PID_2021a_B.cmd_enable = 0.0;

    /* '<S76>:1:52' */
    /* '<S76>:1:53' */
    QD2_DroneStack_PID_2021a_B.esc_ready = 0.0;
    if (QD2_DroneStack_PID_2021a_B.StreamClient_o4[2] != 0.0) {
      /* '<S76>:1:58' */
      sigmoid = 99.0;
    } else {
      switch ((int32_T)QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_f) {
       case 0:
        /* '<S76>:1:63' */
        QD2_DroneStack_PID_2021a_DW.state_counter--;
        if (QD2_DroneStack_PID_2021a_DW.state_counter <= 0.0) {
          /* '<S76>:1:64' */
          /* '<S76>:1:66' */
          sigmoid = 1.0;

          /* '<S76>:1:67' */
          QD2_DroneStack_PID_2021a_DW.state_counter = 10000.0;
        } else {
          /* '<S76>:1:70' */
          sigmoid = QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_f;
        }
        break;

       case 1:
        /* '<S76>:1:76' */
        QD2_DroneStack_PID_2021a_DW.state_counter--;
        if (QD2_DroneStack_PID_2021a_DW.state_counter <= 0.0) {
          /* '<S76>:1:77' */
          /* '<S76>:1:80' */
          sigmoid = 99.0;

          /* '<S76>:1:81' */
          QD2_DroneStack_PID_2021a_DW.esc_timeout_state = 1.0;
        } else if (QD2_DroneStack_PID_2021a_DW.Memory1_PreviousInput) {
          /* '<S76>:1:85' */
          /* '<S76>:1:87' */
          sigmoid = QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_f;
        } else {
          /* '<S76>:1:90' */
          sigmoid = 77.0;

          /* '<S76>:1:91' */
          QD2_DroneStack_PID_2021a_DW.state_counter = 1000.0;

          /* '<S76>:1:92' */
          QD2_DroneStack_PID_2021a_DW.next_state_after_pause = 3.0;

          /* '<S76>:1:93' */
          QD2_DroneStack_PID_2021a_DW.state_counter_after_pause = 60.0;
        }
        break;

       case 3:
        /* '<S76>:1:99' */
        QD2_DroneStack_PID_2021a_DW.state_counter--;
        if (QD2_DroneStack_PID_2021a_DW.state_counter <= 0.0) {
          /* '<S76>:1:100' */
          /* '<S76>:1:102' */
          sigmoid = 88.0;

          /* '<S76>:1:103' */
          QD2_DroneStack_PID_2021a_DW.state_counter = 1000.0;

          /* '<S76>:1:104' */
          QD2_DroneStack_PID_2021a_DW.next_state_after_pause = 4.0;

          /* '<S76>:1:105' */
          QD2_DroneStack_PID_2021a_DW.state_counter_after_pause = 120.0;
        } else {
          /* '<S76>:1:111' */
          sigmoid = QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_f;
        }
        break;

       case 4:
        /* '<S76>:1:116' */
        QD2_DroneStack_PID_2021a_DW.state_counter--;
        if (QD2_DroneStack_PID_2021a_DW.state_counter <= 0.0) {
          /* '<S76>:1:117' */
          /* '<S76>:1:119' */
          sigmoid = 88.0;

          /* '<S76>:1:120' */
          QD2_DroneStack_PID_2021a_DW.state_counter = 500.0;

          /* '<S76>:1:121' */
          QD2_DroneStack_PID_2021a_DW.next_state_after_pause = 2.0;

          /* '<S76>:1:122' */
          QD2_DroneStack_PID_2021a_DW.state_counter_after_pause = 1000.0;
        } else {
          /* '<S76>:1:125' */
          sigmoid = QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_f;
        }
        break;

       case 2:
        if (QD2_DroneStack_PID_2021a_B.DataTypeConversion1 != 0.0) {
          /* '<S76>:1:132' */
          sigmoid = 5.0;
        } else {
          /* '<S76>:1:135' */
          sigmoid = QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_f;
        }
        break;

       case 5:
        if (!(QD2_DroneStack_PID_2021a_B.DataTypeConversion1 != 0.0)) {
          /* '<S76>:1:142' */
          /* '<S76>:1:144' */
          sigmoid = 2.0;
        } else {
          /* '<S76>:1:147' */
          sigmoid = QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_f;
        }
        break;

       case 88:
        /* '<S76>:1:157' */
        QD2_DroneStack_PID_2021a_DW.state_counter--;
        if (QD2_DroneStack_PID_2021a_DW.state_counter <= 0.0) {
          /* '<S76>:1:158' */
          /* '<S76>:1:160' */
          sigmoid = QD2_DroneStack_PID_2021a_DW.next_state_after_pause;

          /* '<S76>:1:161' */
          QD2_DroneStack_PID_2021a_DW.state_counter =
            QD2_DroneStack_PID_2021a_DW.state_counter_after_pause;
        } else {
          /* '<S76>:1:164' */
          sigmoid = QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_f;
        }
        break;

       case 77:
        /* '<S76>:1:169' */
        QD2_DroneStack_PID_2021a_DW.state_counter--;
        if (QD2_DroneStack_PID_2021a_DW.state_counter <= 0.0) {
          /* '<S76>:1:170' */
          /* '<S76>:1:172' */
          sigmoid = QD2_DroneStack_PID_2021a_DW.next_state_after_pause;

          /* '<S76>:1:173' */
          QD2_DroneStack_PID_2021a_DW.state_counter =
            QD2_DroneStack_PID_2021a_DW.state_counter_after_pause;
        } else {
          /* '<S76>:1:176' */
          sigmoid = QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_f;
        }
        break;

       case 99:
        /* '<S76>:1:182' */
        sigmoid = QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_f;
        break;
      }
    }

    switch ((int32_T)sigmoid) {
     case 0:
      /* '<S76>:1:190' */
      QD2_DroneStack_PID_2021a_B.cmd[0] = 0.0;
      QD2_DroneStack_PID_2021a_B.cmd[1] = 0.0;
      QD2_DroneStack_PID_2021a_B.cmd[2] = 0.0;
      QD2_DroneStack_PID_2021a_B.cmd[3] = 0.0;

      /* '<S76>:1:191' */
      QD2_DroneStack_PID_2021a_B.tele_enable = 1.0;

      /* '<S76>:1:192' */
      QD2_DroneStack_PID_2021a_B.cmd_enable = 1.0;

      /* '<S76>:1:193' */
      /* '<S76>:1:194' */
      break;

     case 1:
      /* '<S76>:1:198' */
      QD2_DroneStack_PID_2021a_B.cmd[0] = 0.0;
      QD2_DroneStack_PID_2021a_B.cmd[1] = 0.0;
      QD2_DroneStack_PID_2021a_B.cmd[2] = 0.0;
      QD2_DroneStack_PID_2021a_B.cmd[3] = 0.0;

      /* '<S76>:1:199' */
      QD2_DroneStack_PID_2021a_B.tele_enable = 1.0;

      /* '<S76>:1:200' */
      QD2_DroneStack_PID_2021a_B.cmd_enable = 1.0;

      /* '<S76>:1:201' */
      /* '<S76>:1:202' */
      break;

     case 3:
      /* '<S76>:1:206' */
      QD2_DroneStack_PID_2021a_B.cmd[0] = 3.0;
      QD2_DroneStack_PID_2021a_B.cmd[1] = 3.0;
      QD2_DroneStack_PID_2021a_B.cmd[2] = 3.0;
      QD2_DroneStack_PID_2021a_B.cmd[3] = 3.0;

      /* '<S76>:1:210' */
      QD2_DroneStack_PID_2021a_B.tele_enable = 1.0;

      /* '<S76>:1:211' */
      QD2_DroneStack_PID_2021a_B.cmd_enable = 1.0;

      /* '<S76>:1:212' */
      /* '<S76>:1:213' */
      break;

     case 4:
      /* '<S76>:1:218' */
      QD2_DroneStack_PID_2021a_B.cmd[0] = 20.0;
      QD2_DroneStack_PID_2021a_B.cmd[1] = 21.0;
      QD2_DroneStack_PID_2021a_B.cmd[2] = 21.0;
      QD2_DroneStack_PID_2021a_B.cmd[3] = 20.0;

      /* '<S76>:1:226' */
      QD2_DroneStack_PID_2021a_B.tele_enable = 1.0;

      /* '<S76>:1:227' */
      QD2_DroneStack_PID_2021a_B.cmd_enable = 1.0;

      /* '<S76>:1:228' */
      /* '<S76>:1:229' */
      break;

     case 2:
      /* '<S76>:1:233' */
      QD2_DroneStack_PID_2021a_B.cmd[0] = 0.0;
      QD2_DroneStack_PID_2021a_B.cmd[1] = 0.0;
      QD2_DroneStack_PID_2021a_B.cmd[2] = 0.0;
      QD2_DroneStack_PID_2021a_B.cmd[3] = 0.0;

      /* '<S76>:1:234' */
      /* '<S76>:1:235' */
      QD2_DroneStack_PID_2021a_B.cmd_enable = 1.0;

      /* '<S76>:1:236' */
      /* '<S76>:1:237' */
      QD2_DroneStack_PID_2021a_B.esc_ready = 1.0;
      break;

     case 5:
      /* '<S76>:1:241' */
      QD2_DroneStack_PID_2021a_B.cmd[0] = 48.0;
      QD2_DroneStack_PID_2021a_B.cmd[1] = 48.0;
      QD2_DroneStack_PID_2021a_B.cmd[2] = 48.0;
      QD2_DroneStack_PID_2021a_B.cmd[3] = 48.0;

      /* '<S76>:1:242' */
      QD2_DroneStack_PID_2021a_B.tele_enable = 1.0;

      /* '<S76>:1:243' */
      QD2_DroneStack_PID_2021a_B.cmd_enable = 1.0;

      /* '<S76>:1:244' */
      /* '<S76>:1:245' */
      QD2_DroneStack_PID_2021a_B.esc_ready = 1.0;
      break;

     case 88:
      /* '<S76>:1:249' */
      QD2_DroneStack_PID_2021a_B.cmd[0] = 0.0;
      QD2_DroneStack_PID_2021a_B.cmd[1] = 0.0;
      QD2_DroneStack_PID_2021a_B.cmd[2] = 0.0;
      QD2_DroneStack_PID_2021a_B.cmd[3] = 0.0;

      /* '<S76>:1:250' */
      /* '<S76>:1:251' */
      /* '<S76>:1:252' */
      /* '<S76>:1:253' */
      break;

     case 77:
      /* '<S76>:1:257' */
      QD2_DroneStack_PID_2021a_B.cmd[0] = 0.0;
      QD2_DroneStack_PID_2021a_B.cmd[1] = 0.0;
      QD2_DroneStack_PID_2021a_B.cmd[2] = 0.0;
      QD2_DroneStack_PID_2021a_B.cmd[3] = 0.0;

      /* '<S76>:1:258' */
      QD2_DroneStack_PID_2021a_B.tele_enable = 1.0;

      /* '<S76>:1:259' */
      QD2_DroneStack_PID_2021a_B.cmd_enable = 1.0;

      /* '<S76>:1:260' */
      /* '<S76>:1:261' */
      break;

     case 99:
      /* '<S76>:1:265' */
      QD2_DroneStack_PID_2021a_B.cmd[0] = 0.0;
      QD2_DroneStack_PID_2021a_B.cmd[1] = 0.0;
      QD2_DroneStack_PID_2021a_B.cmd[2] = 0.0;
      QD2_DroneStack_PID_2021a_B.cmd[3] = 0.0;

      /* '<S76>:1:266' */
      /* '<S76>:1:267' */
      QD2_DroneStack_PID_2021a_B.cmd_enable = 1.0;

      /* '<S76>:1:268' */
      /* '<S76>:1:269' */
      break;
    }

    /* '<S76>:1:273' */
    QD2_DroneStack_PID_2021a_B.esc_timeout =
      QD2_DroneStack_PID_2021a_DW.esc_timeout_state;
    QD2_DroneStack_PID_2021a_B.state = sigmoid;

    /* End of MATLAB Function: '<S5>/MATLAB Function' */

    /* DataTypeConversion: '<S5>/Data Type Conversion' */
    QD2_DroneStack_PID_2021a_B.DataTypeConversion =
      QD2_DroneStack_PID_2021a_B.state;

    /* Product: '<S1>/Product' incorporates:
     *  Constant: '<Root>/Drone  Weight (kg)'
     *  Constant: '<S1>/gravity (m//s^2)'
     */
    QD2_DroneStack_PID_2021a_B.Product =
      QD2_DroneStack_PID_2021a_P.gravityms2_Value *
      QD2_DroneStack_PID_2021a_P.DroneWeightkg_Value;

    /* Gain: '<S13>/Saturation Upper Limit Gain' */
    rtb_DataTypeConversion3 =
      QD2_DroneStack_PID_2021a_P.SaturationUpperLimitGain_Gain *
      QD2_DroneStack_PID_2021a_B.Product;

    /* S-Function (continuous_sigmoid_block): '<S13>/Continuous Sigmoid' */
    /* S-Function Block: QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/THROTTLE SWITCHBOX /Continuous Sigmoid (continuous_sigmoid_block) */
    {
      if (rtmIsMajorTimeStep(QD2_DroneStack_PID_2021a_M)) {
        {
          real_T* params;

          /* Determine the correct step size for the output ports */
          params = &QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Sigmoid[0 *
            NUMBER_OF_SIGMOID_PARAMETERS];

          /*  Check if the target position has changed or if it is the first
             simulation step, in which case we need to compute the initial
             trajectory. */
          if (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Flag == 1 ||
              QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Time == 0) {
            /*  Read the new position and reset the flag */
            params[SIGMOID_PARAMETER_XD] =
              QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Target;
            QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Flag = 0;

            /*  Calculate a single step using the new trajectory to account for the target
               change that occured at the previous sample (i.e., there is a one sample delay
               between the point where the target position changes and the trajectory changes
               based on the new target)    */
            if (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Time == 0) {
              /*  Do not update the trajectory since we are at time 0 in simulation
                 (leave t = 0)   */
            } else {
              /*  Set the relative time to one step size so that a single step
                 is computed for the new trajectory  */

              /*  Set the default values in sigmoid_parameters to the trajectory
                 state at the last time step.    */
              params[SIGMOID_PARAMETER_X0] =
                QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_PPos;
              params[SIGMOID_PARAMETER_V0] =
                QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_PVel;
              QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Time = 0.001;
            }

            /*  Calculate the new trajectory    */
            sigmoid_calculate_trajectory(params, 0, params[SIGMOID_PARAMETER_X0],
              params[SIGMOID_PARAMETER_V0],
              QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_MAcc,
              QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_MVel);
          }

          /* Mark the target as not reached */
          QD2_DroneStack_PID_2021a_B.ContinuousSigmoid_o4 = 0;
          if (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Time <
              params[SIGMOID_PARAMETER_T1]) {
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid_o3 =
              params[SIGMOID_PARAMETER_AP];
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid_o2 =
              params[SIGMOID_PARAMETER_V0] + params[SIGMOID_PARAMETER_AP] *
              QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Time;
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid_o1 =
              params[SIGMOID_PARAMETER_X0] + (params[SIGMOID_PARAMETER_V0] + 0.5
              * params[SIGMOID_PARAMETER_AP] *
              QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Time) *
              QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Time;
          } else if (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Time <
                     params[SIGMOID_PARAMETER_T2]) {
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid_o3 = 0;
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid_o2 =
              params[SIGMOID_PARAMETER_VP];
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid_o1 =
              params[SIGMOID_PARAMETER_X1] + params[SIGMOID_PARAMETER_VP] *
              (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Time -
               params[SIGMOID_PARAMETER_T1]);
          } else if (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Time <
                     params[SIGMOID_PARAMETER_T3]) {
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid_o3 =
              -params[SIGMOID_PARAMETER_AP];
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid_o2 =
              params[SIGMOID_PARAMETER_VP] - params[SIGMOID_PARAMETER_AP] *
              (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Time -
               params[SIGMOID_PARAMETER_T2]);
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid_o1 =
              params[SIGMOID_PARAMETER_X2] + (params[SIGMOID_PARAMETER_VP] - 0.5
              * params[SIGMOID_PARAMETER_AP] *
              (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Time -
               params[SIGMOID_PARAMETER_T2])) *
              (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Time -
               params[SIGMOID_PARAMETER_T2]);
          } else {
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid_o3 = 0;
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid_o2 = 0;
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid_o1 =
              params[SIGMOID_PARAMETER_XD];/* always attainable */

            /* Mark the target as reached after the hold-off period */
            if ((QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Time -
                 params[SIGMOID_PARAMETER_T3]) >=
                params[SIGMOID_PARAMETER_HOLD_OFF])
              QD2_DroneStack_PID_2021a_B.ContinuousSigmoid_o4 = 1;/* Assert Done signal */
          }

          /*  Save the current position/velocity to be used next time step (possibly) */
          QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_PPos =
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid_o1;
          QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_PVel =
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid_o2;

          /*  Increment the relative time RWork to the NEXT time step */
          QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Time += 0.001;
        }
      }
    }

    /* Memory: '<S1>/Memory' */
    QD2_DroneStack_PID_2021a_B.Memory =
      QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_e;

    /* MATLAB Function: '<S13>/Throttle Switchbox' */
    QD2_DroneStack_PID_2021a_DW.sfEvent_np = QD2_DroneStack_PID_2_CALL_EVENT;

    /* MATLAB Function 'COMMANDER (ANGLE MODE)/THROTTLE SWITCHBOX /Throttle Switchbox': '<S45>:1' */
    /* '<S45>:1:23' */
    sigmoid = 0.0;
    switch ((int32_T)QD2_DroneStack_PID_2021a_B.Memory) {
     case 1:
      /* '<S45>:1:26' */
      sigmoid = 1.0;
      break;

     case 2:
      /* '<S45>:1:28' */
      sigmoid = 1.0;
      break;

     case 3:
      /* '<S45>:1:30' */
      sigmoid = 2.0;
      break;

     case 4:
      /* '<S45>:1:32' */
      sigmoid = 3.0;
      break;

     case 5:
      /* '<S45>:1:34' */
      sigmoid = 3.0;
      break;

     case 6:
      /* '<S45>:1:36' */
      sigmoid = 5.0;
      break;

     case 7:
      /* '<S45>:1:38' */
      sigmoid = 4.0;
      break;

     case 8:
      /* '<S45>:1:40' */
      sigmoid = 1.0;
      break;

     case 9:
      /* '<S45>:1:42' */
      sigmoid = 1.0;
      break;
    }

    /* End of MATLAB Function: '<S13>/Throttle Switchbox' */

    /* MATLAB Function: '<S13>/Hover Throttle Sigmoid Parameters' incorporates:
     *  Constant: '<S13>/Constant2'
     *  Constant: '<S13>/Constant3'
     */
    QD2_DroneStack_PID_2021a_DW.sfEvent_m = QD2_DroneStack_PID_2_CALL_EVENT;

    /* MATLAB Function 'COMMANDER (ANGLE MODE)/THROTTLE SWITCHBOX /Hover Throttle Sigmoid Parameters': '<S40>:1' */
    /* '<S40>:1:8' */
    QD2_DroneStack_PID_2021a_B.enable_d = 0.0;

    /* '<S40>:1:9' */
    QD2_DroneStack_PID_2021a_B.throttle_ref = 0.0;

    /* '<S40>:1:10' */
    QD2_DroneStack_PID_2021a_B.max_throttle_vel = 0.0;

    /* '<S40>:1:11' */
    QD2_DroneStack_PID_2021a_B.max_throttle_accel = 0.0;
    switch ((int32_T)sigmoid) {
     case 1:
      /* '<S40>:1:16' */
      /* '<S40>:1:17' */
      /* '<S40>:1:18' */
      QD2_DroneStack_PID_2021a_B.max_throttle_vel = 0.0;

      /* '<S40>:1:19' */
      QD2_DroneStack_PID_2021a_B.max_throttle_accel = 0.0;
      break;

     case 2:
      /* '<S40>:1:23' */
      QD2_DroneStack_PID_2021a_B.enable_d = 1.0;

      /* '<S40>:1:24' */
      QD2_DroneStack_PID_2021a_B.throttle_ref =
        QD2_DroneStack_PID_2021a_B.Product;

      /* '<S40>:1:25' */
      QD2_DroneStack_PID_2021a_B.max_throttle_vel =
        QD2_DroneStack_PID_2021a_P.Constant2_Value[0];

      /* '<S40>:1:26' */
      QD2_DroneStack_PID_2021a_B.max_throttle_accel =
        QD2_DroneStack_PID_2021a_P.Constant2_Value[1];
      break;

     case 3:
      /* '<S40>:1:30' */
      QD2_DroneStack_PID_2021a_B.enable_d = 1.0;

      /* '<S40>:1:31' */
      QD2_DroneStack_PID_2021a_B.throttle_ref =
        QD2_DroneStack_PID_2021a_B.Product;

      /* '<S40>:1:32' */
      QD2_DroneStack_PID_2021a_B.max_throttle_vel =
        QD2_DroneStack_PID_2021a_P.Constant2_Value[0];

      /* '<S40>:1:33' */
      QD2_DroneStack_PID_2021a_B.max_throttle_accel =
        QD2_DroneStack_PID_2021a_P.Constant2_Value[1];
      break;

     case 4:
      /* '<S40>:1:37' */
      QD2_DroneStack_PID_2021a_B.enable_d = 1.0;

      /* '<S40>:1:38' */
      if (QD2_DroneStack_PID_2021a_B.ContinuousSigmoid_o2 > 0.0) {
        /* '<S40>:1:39' */
        /* '<S40>:1:40' */
        QD2_DroneStack_PID_2021a_B.max_throttle_vel =
          QD2_DroneStack_PID_2021a_P.Constant2_Value[0];

        /* '<S40>:1:41' */
        QD2_DroneStack_PID_2021a_B.max_throttle_accel =
          QD2_DroneStack_PID_2021a_P.Constant2_Value[1];
      } else {
        /* '<S40>:1:43' */
        QD2_DroneStack_PID_2021a_B.max_throttle_vel =
          QD2_DroneStack_PID_2021a_P.Constant3_Value[0];

        /* '<S40>:1:44' */
        QD2_DroneStack_PID_2021a_B.max_throttle_accel =
          QD2_DroneStack_PID_2021a_P.Constant3_Value[1];
      }
      break;

     case 5:
      /* '<S40>:1:49' */
      QD2_DroneStack_PID_2021a_B.enable_d = 1.0;

      /* '<S40>:1:50' */
      QD2_DroneStack_PID_2021a_B.throttle_ref =
        QD2_DroneStack_PID_2021a_B.Product;

      /* '<S40>:1:51' */
      QD2_DroneStack_PID_2021a_B.max_throttle_vel =
        QD2_DroneStack_PID_2021a_P.Constant2_Value[0];

      /* '<S40>:1:52' */
      QD2_DroneStack_PID_2021a_B.max_throttle_accel =
        QD2_DroneStack_PID_2021a_P.Constant2_Value[1];
      break;
    }

    /* End of MATLAB Function: '<S13>/Hover Throttle Sigmoid Parameters' */

    /* Switch: '<S13>/Switch1' incorporates:
     *  Constant: '<S13>/Constant5'
     */
    if (QD2_DroneStack_PID_2021a_B.enable_d >
        QD2_DroneStack_PID_2021a_P.Switch1_Threshold) {
      sigmoid = QD2_DroneStack_PID_2021a_B.ContinuousSigmoid_o1;
    } else {
      sigmoid = QD2_DroneStack_PID_2021a_P.Constant5_Value;
    }

    /* End of Switch: '<S13>/Switch1' */

    /* Switch: '<S44>/Switch2' incorporates:
     *  Constant: '<S13>/Constant4'
     *  RelationalOperator: '<S44>/LowerRelop1'
     *  RelationalOperator: '<S44>/UpperRelop'
     *  Switch: '<S44>/Switch'
     */
    if (sigmoid > rtb_DataTypeConversion3) {
      /* Switch: '<S44>/Switch2' */
      QD2_DroneStack_PID_2021a_B.Switch2 = rtb_DataTypeConversion3;
    } else if (sigmoid < QD2_DroneStack_PID_2021a_P.Constant4_Value) {
      /* Switch: '<S44>/Switch' incorporates:
       *  Constant: '<S13>/Constant4'
       *  Switch: '<S44>/Switch2'
       */
      QD2_DroneStack_PID_2021a_B.Switch2 =
        QD2_DroneStack_PID_2021a_P.Constant4_Value;
    } else {
      /* Switch: '<S44>/Switch2' incorporates:
       *  Switch: '<S44>/Switch'
       */
      QD2_DroneStack_PID_2021a_B.Switch2 = sigmoid;
    }

    /* End of Switch: '<S44>/Switch2' */
  }

  /* Integrator: '<S3>/Integrator1' */
  QD2_DroneStack_PID_2021a_B.Integrator1 =
    QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE;
  if (rtb_Compare_f) {
    /* S-Function (euler_angles_to_rotation_matrix_block): '<S3>/Euler Angles to Rotation Matrix1' incorporates:
     *  Constant: '<S3>/Constant'
     */
    {
      t_double sin_phi = sin(QD2_DroneStack_PID_2021a_B.Integrator1);
      t_double cos_phi = cos(QD2_DroneStack_PID_2021a_B.Integrator1);
      t_double sin_theta = sin(QD2_DroneStack_PID_2021a_P.Constant_Value_l);
      t_double cos_theta = cos(QD2_DroneStack_PID_2021a_P.Constant_Value_l);
      t_double sin_psi = sin(QD2_DroneStack_PID_2021a_P.Constant_Value_l);
      t_double cos_psi = cos(QD2_DroneStack_PID_2021a_P.Constant_Value_l);
      rtb_BFToIFrotationmatrix[0] = cos_phi * cos_theta;
      rtb_BFToIFrotationmatrix[1] = sin_phi * cos_theta;
      rtb_BFToIFrotationmatrix[2] = -sin_theta;
      rtb_BFToIFrotationmatrix[3] = -sin_phi * cos_psi + cos_phi * sin_theta *
        sin_psi;
      rtb_BFToIFrotationmatrix[4] = cos_phi * cos_psi + sin_phi * sin_theta *
        sin_psi;
      rtb_BFToIFrotationmatrix[5] = cos_theta * sin_psi;
      rtb_BFToIFrotationmatrix[6] = sin_phi * sin_psi + cos_phi * sin_theta *
        cos_psi;
      rtb_BFToIFrotationmatrix[7] = -cos_phi * sin_psi + sin_phi * sin_theta *
        cos_psi;
      rtb_BFToIFrotationmatrix[8] = cos_theta * cos_psi;
    }

    for (i = 0; i < 3; i++) {
      /* Math: '<S3>/Transpose' incorporates:
       *  S-Function (euler_angles_to_rotation_matrix_block): '<S3>/Euler Angles to Rotation Matrix2'
       */
      QD2_DroneStack_PID_2021a_B.IFtoHRrotationmatrix[3 * i] =
        rtb_BFToIFrotationmatrix[i];
      QD2_DroneStack_PID_2021a_B.IFtoHRrotationmatrix[3 * i + 1] =
        rtb_BFToIFrotationmatrix[i + 3];
      QD2_DroneStack_PID_2021a_B.IFtoHRrotationmatrix[3 * i + 2] =
        rtb_BFToIFrotationmatrix[i + 6];
    }

    /* S-Function (continuous_sigmoid_block): '<S51>/Continuous Sigmoid' */
    /* S-Function Block: QD2_DroneStack_PID_2021a/HORIZON FRAME CONVERSION AND ESTIMATION/Pose Switchbox/Continuous Sigmoid (continuous_sigmoid_block) */
    {
      if (rtmIsMajorTimeStep(QD2_DroneStack_PID_2021a_M)) {
        {
          real_T* params;

          /* Determine the correct step size for the output ports */
          params = &QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Sigmoid_l[0 *
            NUMBER_OF_SIGMOID_PARAMETERS];

          /*  Check if the target position has changed or if it is the first
             simulation step, in which case we need to compute the initial
             trajectory. */
          if (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Flag_h == 1 ||
              QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Time_c == 0) {
            /*  Read the new position and reset the flag */
            params[SIGMOID_PARAMETER_XD] =
              QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Target_d;
            QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Flag_h = 0;

            /*  Calculate a single step using the new trajectory to account for the target
               change that occured at the previous sample (i.e., there is a one sample delay
               between the point where the target position changes and the trajectory changes
               based on the new target)    */
            if (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Time_c == 0) {
              /*  Do not update the trajectory since we are at time 0 in simulation
                 (leave t = 0)   */
            } else {
              /*  Set the relative time to one step size so that a single step
                 is computed for the new trajectory  */

              /*  Set the default values in sigmoid_parameters to the trajectory
                 state at the last time step.    */
              params[SIGMOID_PARAMETER_X0] =
                QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_PPos_a;
              params[SIGMOID_PARAMETER_V0] =
                QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_PVel_p;
              QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Time_c = 0.001;
            }

            /*  Calculate the new trajectory    */
            sigmoid_calculate_trajectory(params, 0, params[SIGMOID_PARAMETER_X0],
              params[SIGMOID_PARAMETER_V0],
              QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_MAcc_p,
              QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_MVel_l);
          }

          /* Mark the target as not reached */
          QD2_DroneStack_PID_2021a_B.ContinuousSigmoid_o4_m = 0;
          if (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Time_c <
              params[SIGMOID_PARAMETER_T1]) {
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid_o3_b =
              params[SIGMOID_PARAMETER_AP];
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid_o2_l =
              params[SIGMOID_PARAMETER_V0] + params[SIGMOID_PARAMETER_AP] *
              QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Time_c;
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid_o1_a =
              params[SIGMOID_PARAMETER_X0] + (params[SIGMOID_PARAMETER_V0] + 0.5
              * params[SIGMOID_PARAMETER_AP] *
              QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Time_c) *
              QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Time_c;
          } else if (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Time_c <
                     params[SIGMOID_PARAMETER_T2]) {
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid_o3_b = 0;
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid_o2_l =
              params[SIGMOID_PARAMETER_VP];
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid_o1_a =
              params[SIGMOID_PARAMETER_X1] + params[SIGMOID_PARAMETER_VP] *
              (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Time_c -
               params[SIGMOID_PARAMETER_T1]);
          } else if (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Time_c <
                     params[SIGMOID_PARAMETER_T3]) {
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid_o3_b =
              -params[SIGMOID_PARAMETER_AP];
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid_o2_l =
              params[SIGMOID_PARAMETER_VP] - params[SIGMOID_PARAMETER_AP] *
              (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Time_c -
               params[SIGMOID_PARAMETER_T2]);
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid_o1_a =
              params[SIGMOID_PARAMETER_X2] + (params[SIGMOID_PARAMETER_VP] - 0.5
              * params[SIGMOID_PARAMETER_AP] *
              (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Time_c -
               params[SIGMOID_PARAMETER_T2])) *
              (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Time_c -
               params[SIGMOID_PARAMETER_T2]);
          } else {
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid_o3_b = 0;
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid_o2_l = 0;
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid_o1_a =
              params[SIGMOID_PARAMETER_XD];/* always attainable */

            /* Mark the target as reached after the hold-off period */
            if ((QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Time_c -
                 params[SIGMOID_PARAMETER_T3]) >=
                params[SIGMOID_PARAMETER_HOLD_OFF])
              QD2_DroneStack_PID_2021a_B.ContinuousSigmoid_o4_m = 1;/* Assert Done signal */
          }

          /*  Save the current position/velocity to be used next time step (possibly) */
          QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_PPos_a =
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid_o1_a;
          QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_PVel_p =
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid_o2_l;

          /*  Increment the relative time RWork to the NEXT time step */
          QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Time_c += 0.001;
        }
      }
    }

    /* S-Function (continuous_sigmoid_block): '<S51>/Continuous Sigmoid1' */
    /* S-Function Block: QD2_DroneStack_PID_2021a/HORIZON FRAME CONVERSION AND ESTIMATION/Pose Switchbox/Continuous Sigmoid1 (continuous_sigmoid_block) */
    {
      if (rtmIsMajorTimeStep(QD2_DroneStack_PID_2021a_M)) {
        {
          real_T* params;

          /* Determine the correct step size for the output ports */
          params = &QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_Sigmoid[0 *
            NUMBER_OF_SIGMOID_PARAMETERS];

          /*  Check if the target position has changed or if it is the first
             simulation step, in which case we need to compute the initial
             trajectory. */
          if (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_Flag == 1 ||
              QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_Time == 0) {
            /*  Read the new position and reset the flag */
            params[SIGMOID_PARAMETER_XD] =
              QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_Target;
            QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_Flag = 0;

            /*  Calculate a single step using the new trajectory to account for the target
               change that occured at the previous sample (i.e., there is a one sample delay
               between the point where the target position changes and the trajectory changes
               based on the new target)    */
            if (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_Time == 0) {
              /*  Do not update the trajectory since we are at time 0 in simulation
                 (leave t = 0)   */
            } else {
              /*  Set the relative time to one step size so that a single step
                 is computed for the new trajectory  */

              /*  Set the default values in sigmoid_parameters to the trajectory
                 state at the last time step.    */
              params[SIGMOID_PARAMETER_X0] =
                QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_PPos;
              params[SIGMOID_PARAMETER_V0] =
                QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_PVel;
              QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_Time = 0.001;
            }

            /*  Calculate the new trajectory    */
            sigmoid_calculate_trajectory(params, 0, params[SIGMOID_PARAMETER_X0],
              params[SIGMOID_PARAMETER_V0],
              QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_MAcc,
              QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_MVel);
          }

          /* Mark the target as not reached */
          QD2_DroneStack_PID_2021a_B.ContinuousSigmoid1_o4 = 0;
          if (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_Time <
              params[SIGMOID_PARAMETER_T1]) {
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid1_o3 =
              params[SIGMOID_PARAMETER_AP];
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid1_o2 =
              params[SIGMOID_PARAMETER_V0] + params[SIGMOID_PARAMETER_AP] *
              QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_Time;
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid1_o1 =
              params[SIGMOID_PARAMETER_X0] + (params[SIGMOID_PARAMETER_V0] + 0.5
              * params[SIGMOID_PARAMETER_AP] *
              QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_Time) *
              QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_Time;
          } else if (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_Time <
                     params[SIGMOID_PARAMETER_T2]) {
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid1_o3 = 0;
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid1_o2 =
              params[SIGMOID_PARAMETER_VP];
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid1_o1 =
              params[SIGMOID_PARAMETER_X1] + params[SIGMOID_PARAMETER_VP] *
              (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_Time -
               params[SIGMOID_PARAMETER_T1]);
          } else if (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_Time <
                     params[SIGMOID_PARAMETER_T3]) {
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid1_o3 =
              -params[SIGMOID_PARAMETER_AP];
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid1_o2 =
              params[SIGMOID_PARAMETER_VP] - params[SIGMOID_PARAMETER_AP] *
              (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_Time -
               params[SIGMOID_PARAMETER_T2]);
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid1_o1 =
              params[SIGMOID_PARAMETER_X2] + (params[SIGMOID_PARAMETER_VP] - 0.5
              * params[SIGMOID_PARAMETER_AP] *
              (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_Time -
               params[SIGMOID_PARAMETER_T2])) *
              (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_Time -
               params[SIGMOID_PARAMETER_T2]);
          } else {
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid1_o3 = 0;
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid1_o2 = 0;
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid1_o1 =
              params[SIGMOID_PARAMETER_XD];/* always attainable */

            /* Mark the target as reached after the hold-off period */
            if ((QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_Time -
                 params[SIGMOID_PARAMETER_T3]) >=
                params[SIGMOID_PARAMETER_HOLD_OFF])
              QD2_DroneStack_PID_2021a_B.ContinuousSigmoid1_o4 = 1;/* Assert Done signal */
          }

          /*  Save the current position/velocity to be used next time step (possibly) */
          QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_PPos =
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid1_o1;
          QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_PVel =
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid1_o2;

          /*  Increment the relative time RWork to the NEXT time step */
          QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_Time += 0.001;
        }
      }
    }

    /* S-Function (continuous_sigmoid_block): '<S51>/Continuous Sigmoid2' */
    /* S-Function Block: QD2_DroneStack_PID_2021a/HORIZON FRAME CONVERSION AND ESTIMATION/Pose Switchbox/Continuous Sigmoid2 (continuous_sigmoid_block) */
    {
      if (rtmIsMajorTimeStep(QD2_DroneStack_PID_2021a_M)) {
        {
          real_T* params;

          /* Determine the correct step size for the output ports */
          params = &QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_Sigmoid[0 *
            NUMBER_OF_SIGMOID_PARAMETERS];

          /*  Check if the target position has changed or if it is the first
             simulation step, in which case we need to compute the initial
             trajectory. */
          if (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_Flag == 1 ||
              QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_Time == 0) {
            /*  Read the new position and reset the flag */
            params[SIGMOID_PARAMETER_XD] =
              QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_Target;
            QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_Flag = 0;

            /*  Calculate a single step using the new trajectory to account for the target
               change that occured at the previous sample (i.e., there is a one sample delay
               between the point where the target position changes and the trajectory changes
               based on the new target)    */
            if (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_Time == 0) {
              /*  Do not update the trajectory since we are at time 0 in simulation
                 (leave t = 0)   */
            } else {
              /*  Set the relative time to one step size so that a single step
                 is computed for the new trajectory  */

              /*  Set the default values in sigmoid_parameters to the trajectory
                 state at the last time step.    */
              params[SIGMOID_PARAMETER_X0] =
                QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_PPos;
              params[SIGMOID_PARAMETER_V0] =
                QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_PVel;
              QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_Time = 0.001;
            }

            /*  Calculate the new trajectory    */
            sigmoid_calculate_trajectory(params, 0, params[SIGMOID_PARAMETER_X0],
              params[SIGMOID_PARAMETER_V0],
              QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_MAcc,
              QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_MVel);
          }

          /* Mark the target as not reached */
          QD2_DroneStack_PID_2021a_B.ContinuousSigmoid2_o4 = 0;
          if (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_Time <
              params[SIGMOID_PARAMETER_T1]) {
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid2_o3 =
              params[SIGMOID_PARAMETER_AP];
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid2_o2 =
              params[SIGMOID_PARAMETER_V0] + params[SIGMOID_PARAMETER_AP] *
              QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_Time;
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid2_o1 =
              params[SIGMOID_PARAMETER_X0] + (params[SIGMOID_PARAMETER_V0] + 0.5
              * params[SIGMOID_PARAMETER_AP] *
              QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_Time) *
              QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_Time;
          } else if (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_Time <
                     params[SIGMOID_PARAMETER_T2]) {
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid2_o3 = 0;
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid2_o2 =
              params[SIGMOID_PARAMETER_VP];
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid2_o1 =
              params[SIGMOID_PARAMETER_X1] + params[SIGMOID_PARAMETER_VP] *
              (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_Time -
               params[SIGMOID_PARAMETER_T1]);
          } else if (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_Time <
                     params[SIGMOID_PARAMETER_T3]) {
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid2_o3 =
              -params[SIGMOID_PARAMETER_AP];
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid2_o2 =
              params[SIGMOID_PARAMETER_VP] - params[SIGMOID_PARAMETER_AP] *
              (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_Time -
               params[SIGMOID_PARAMETER_T2]);
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid2_o1 =
              params[SIGMOID_PARAMETER_X2] + (params[SIGMOID_PARAMETER_VP] - 0.5
              * params[SIGMOID_PARAMETER_AP] *
              (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_Time -
               params[SIGMOID_PARAMETER_T2])) *
              (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_Time -
               params[SIGMOID_PARAMETER_T2]);
          } else {
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid2_o3 = 0;
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid2_o2 = 0;
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid2_o1 =
              params[SIGMOID_PARAMETER_XD];/* always attainable */

            /* Mark the target as reached after the hold-off period */
            if ((QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_Time -
                 params[SIGMOID_PARAMETER_T3]) >=
                params[SIGMOID_PARAMETER_HOLD_OFF])
              QD2_DroneStack_PID_2021a_B.ContinuousSigmoid2_o4 = 1;/* Assert Done signal */
          }

          /*  Save the current position/velocity to be used next time step (possibly) */
          QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_PPos =
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid2_o1;
          QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_PVel =
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid2_o2;

          /*  Increment the relative time RWork to the NEXT time step */
          QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_Time += 0.001;
        }
      }
    }

    /* S-Function (continuous_sigmoid_block): '<S51>/Continuous Sigmoid3' */
    /* S-Function Block: QD2_DroneStack_PID_2021a/HORIZON FRAME CONVERSION AND ESTIMATION/Pose Switchbox/Continuous Sigmoid3 (continuous_sigmoid_block) */
    {
      if (rtmIsMajorTimeStep(QD2_DroneStack_PID_2021a_M)) {
        {
          real_T* params;

          /* Determine the correct step size for the output ports */
          params = &QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_Sigmoid[0 *
            NUMBER_OF_SIGMOID_PARAMETERS];

          /*  Check if the target position has changed or if it is the first
             simulation step, in which case we need to compute the initial
             trajectory. */
          if (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_Flag == 1 ||
              QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_Time == 0) {
            /*  Read the new position and reset the flag */
            params[SIGMOID_PARAMETER_XD] =
              QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_Target;
            QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_Flag = 0;

            /*  Calculate a single step using the new trajectory to account for the target
               change that occured at the previous sample (i.e., there is a one sample delay
               between the point where the target position changes and the trajectory changes
               based on the new target)    */
            if (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_Time == 0) {
              /*  Do not update the trajectory since we are at time 0 in simulation
                 (leave t = 0)   */
            } else {
              /*  Set the relative time to one step size so that a single step
                 is computed for the new trajectory  */

              /*  Set the default values in sigmoid_parameters to the trajectory
                 state at the last time step.    */
              params[SIGMOID_PARAMETER_X0] =
                QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_PPos;
              params[SIGMOID_PARAMETER_V0] =
                QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_PVel;
              QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_Time = 0.001;
            }

            /*  Calculate the new trajectory    */
            sigmoid_calculate_trajectory(params, 0, params[SIGMOID_PARAMETER_X0],
              params[SIGMOID_PARAMETER_V0],
              QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_MAcc,
              QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_MVel);
          }

          /* Mark the target as not reached */
          QD2_DroneStack_PID_2021a_B.ContinuousSigmoid3_o4 = 0;
          if (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_Time <
              params[SIGMOID_PARAMETER_T1]) {
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid3_o3 =
              params[SIGMOID_PARAMETER_AP];
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid3_o2 =
              params[SIGMOID_PARAMETER_V0] + params[SIGMOID_PARAMETER_AP] *
              QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_Time;
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid3_o1 =
              params[SIGMOID_PARAMETER_X0] + (params[SIGMOID_PARAMETER_V0] + 0.5
              * params[SIGMOID_PARAMETER_AP] *
              QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_Time) *
              QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_Time;
          } else if (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_Time <
                     params[SIGMOID_PARAMETER_T2]) {
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid3_o3 = 0;
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid3_o2 =
              params[SIGMOID_PARAMETER_VP];
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid3_o1 =
              params[SIGMOID_PARAMETER_X1] + params[SIGMOID_PARAMETER_VP] *
              (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_Time -
               params[SIGMOID_PARAMETER_T1]);
          } else if (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_Time <
                     params[SIGMOID_PARAMETER_T3]) {
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid3_o3 =
              -params[SIGMOID_PARAMETER_AP];
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid3_o2 =
              params[SIGMOID_PARAMETER_VP] - params[SIGMOID_PARAMETER_AP] *
              (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_Time -
               params[SIGMOID_PARAMETER_T2]);
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid3_o1 =
              params[SIGMOID_PARAMETER_X2] + (params[SIGMOID_PARAMETER_VP] - 0.5
              * params[SIGMOID_PARAMETER_AP] *
              (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_Time -
               params[SIGMOID_PARAMETER_T2])) *
              (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_Time -
               params[SIGMOID_PARAMETER_T2]);
          } else {
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid3_o3 = 0;
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid3_o2 = 0;
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid3_o1 =
              params[SIGMOID_PARAMETER_XD];/* always attainable */

            /* Mark the target as reached after the hold-off period */
            if ((QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_Time -
                 params[SIGMOID_PARAMETER_T3]) >=
                params[SIGMOID_PARAMETER_HOLD_OFF])
              QD2_DroneStack_PID_2021a_B.ContinuousSigmoid3_o4 = 1;/* Assert Done signal */
          }

          /*  Save the current position/velocity to be used next time step (possibly) */
          QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_PPos =
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid3_o1;
          QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_PVel =
            QD2_DroneStack_PID_2021a_B.ContinuousSigmoid3_o2;

          /*  Increment the relative time RWork to the NEXT time step */
          QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_Time += 0.001;
        }
      }
    }

    /* Gain: '<S51>/Gain' incorporates:
     *  Constant: '<S3>/Position Safety Threshold (m) [3]'
     *  Constant: '<S51>/Constant1'
     */
    rtb_KiradsmradsmNsmradsrads[0] = QD2_DroneStack_PID_2021a_P.Gain_Gain[0] *
      QD2_DroneStack_PID_2021a_P.PositionSafetyThresholdm3_Value[0];
    rtb_KiradsmradsmNsmradsrads[1] = QD2_DroneStack_PID_2021a_P.Gain_Gain[1] *
      QD2_DroneStack_PID_2021a_P.PositionSafetyThresholdm3_Value[1];
    rtb_KiradsmradsmNsmradsrads[2] = QD2_DroneStack_PID_2021a_P.Gain_Gain[2] *
      QD2_DroneStack_PID_2021a_P.PositionSafetyThresholdm3_Value[2];
    rtb_KiradsmradsmNsmradsrads[3] = QD2_DroneStack_PID_2021a_P.Gain_Gain[3] *
      QD2_DroneStack_PID_2021a_P.Constant1_Value_j;

    /* Switch: '<S57>/Switch2' incorporates:
     *  Constant: '<S3>/Position Safety Threshold (m) [3]'
     *  Constant: '<S51>/Constant1'
     *  RelationalOperator: '<S57>/LowerRelop1'
     *  RelationalOperator: '<S57>/UpperRelop'
     *  Switch: '<S57>/Switch'
     */
    if (QD2_DroneStack_PID_2021a_B.ContinuousSigmoid_o1_a >
        QD2_DroneStack_PID_2021a_P.PositionSafetyThresholdm3_Value[0]) {
      /* Switch: '<S57>/Switch2' */
      QD2_DroneStack_PID_2021a_B.Switch2_m[0] =
        QD2_DroneStack_PID_2021a_P.PositionSafetyThresholdm3_Value[0];
    } else if (QD2_DroneStack_PID_2021a_B.ContinuousSigmoid_o1_a <
               rtb_KiradsmradsmNsmradsrads[0]) {
      /* Switch: '<S57>/Switch' incorporates:
       *  Switch: '<S57>/Switch2'
       */
      QD2_DroneStack_PID_2021a_B.Switch2_m[0] = rtb_KiradsmradsmNsmradsrads[0];
    } else {
      /* Switch: '<S57>/Switch2' incorporates:
       *  Switch: '<S57>/Switch'
       */
      QD2_DroneStack_PID_2021a_B.Switch2_m[0] =
        QD2_DroneStack_PID_2021a_B.ContinuousSigmoid_o1_a;
    }

    if (QD2_DroneStack_PID_2021a_B.ContinuousSigmoid1_o1 >
        QD2_DroneStack_PID_2021a_P.PositionSafetyThresholdm3_Value[1]) {
      /* Switch: '<S57>/Switch2' */
      QD2_DroneStack_PID_2021a_B.Switch2_m[1] =
        QD2_DroneStack_PID_2021a_P.PositionSafetyThresholdm3_Value[1];
    } else if (QD2_DroneStack_PID_2021a_B.ContinuousSigmoid1_o1 <
               rtb_KiradsmradsmNsmradsrads[1]) {
      /* Switch: '<S57>/Switch' incorporates:
       *  Switch: '<S57>/Switch2'
       */
      QD2_DroneStack_PID_2021a_B.Switch2_m[1] = rtb_KiradsmradsmNsmradsrads[1];
    } else {
      /* Switch: '<S57>/Switch2' incorporates:
       *  Switch: '<S57>/Switch'
       */
      QD2_DroneStack_PID_2021a_B.Switch2_m[1] =
        QD2_DroneStack_PID_2021a_B.ContinuousSigmoid1_o1;
    }

    if (QD2_DroneStack_PID_2021a_B.ContinuousSigmoid2_o1 >
        QD2_DroneStack_PID_2021a_P.PositionSafetyThresholdm3_Value[2]) {
      /* Switch: '<S57>/Switch2' */
      QD2_DroneStack_PID_2021a_B.Switch2_m[2] =
        QD2_DroneStack_PID_2021a_P.PositionSafetyThresholdm3_Value[2];
    } else if (QD2_DroneStack_PID_2021a_B.ContinuousSigmoid2_o1 <
               rtb_KiradsmradsmNsmradsrads[2]) {
      /* Switch: '<S57>/Switch' incorporates:
       *  Switch: '<S57>/Switch2'
       */
      QD2_DroneStack_PID_2021a_B.Switch2_m[2] = rtb_KiradsmradsmNsmradsrads[2];
    } else {
      /* Switch: '<S57>/Switch2' incorporates:
       *  Switch: '<S57>/Switch'
       */
      QD2_DroneStack_PID_2021a_B.Switch2_m[2] =
        QD2_DroneStack_PID_2021a_B.ContinuousSigmoid2_o1;
    }

    if (QD2_DroneStack_PID_2021a_B.ContinuousSigmoid3_o1 >
        QD2_DroneStack_PID_2021a_P.Constant1_Value_j) {
      /* Switch: '<S57>/Switch2' */
      QD2_DroneStack_PID_2021a_B.Switch2_m[3] =
        QD2_DroneStack_PID_2021a_P.Constant1_Value_j;
    } else if (QD2_DroneStack_PID_2021a_B.ContinuousSigmoid3_o1 <
               rtb_KiradsmradsmNsmradsrads[3]) {
      /* Switch: '<S57>/Switch' incorporates:
       *  Switch: '<S57>/Switch2'
       */
      QD2_DroneStack_PID_2021a_B.Switch2_m[3] = rtb_KiradsmradsmNsmradsrads[3];
    } else {
      /* Switch: '<S57>/Switch2' incorporates:
       *  Switch: '<S57>/Switch'
       */
      QD2_DroneStack_PID_2021a_B.Switch2_m[3] =
        QD2_DroneStack_PID_2021a_B.ContinuousSigmoid3_o1;
    }

    /* End of Switch: '<S57>/Switch2' */

    /* Sum: '<S3>/Sum' */
    rtb_KiradsmradsmNsmradsrads[3] = QD2_DroneStack_PID_2021a_B.Switch2_m[3] -
      QD2_DroneStack_PID_2021a_B.StreamClient_o4[10];
    rtb_KiradsmradsmNsmradsrads[0] = QD2_DroneStack_PID_2021a_B.Switch2_m[0] -
      QD2_DroneStack_PID_2021a_B.StreamClient_o4[5];

    /* Product: '<S3>/Matrix Multiply' */
    rtb_Product_h_idx_0 = 0.0;

    /* Sum: '<S3>/Sum' */
    rtb_KiradsmradsmNsmradsrads[1] = QD2_DroneStack_PID_2021a_B.Switch2_m[1] -
      QD2_DroneStack_PID_2021a_B.StreamClient_o4[6];

    /* Product: '<S3>/Matrix Multiply' */
    rtb_Product_h_idx_1 = 0.0;

    /* Sum: '<S3>/Sum' */
    rtb_KiradsmradsmNsmradsrads[2] = QD2_DroneStack_PID_2021a_B.Switch2_m[2] -
      QD2_DroneStack_PID_2021a_B.StreamClient_o4[7];

    /* Product: '<S3>/Matrix Multiply' incorporates:
     *  Math: '<S3>/Transpose'
     */
    rtb_Product_h_idx_2 = 0.0;
    for (i = 0; i < 3; i++) {
      rtb_Sum1_c_idx_2 = rtb_KiradsmradsmNsmradsrads[i];
      rtb_Product_h_idx_0 += QD2_DroneStack_PID_2021a_B.IFtoHRrotationmatrix[3 *
        i] * rtb_Sum1_c_idx_2;
      rtb_Product_h_idx_1 += QD2_DroneStack_PID_2021a_B.IFtoHRrotationmatrix[3 *
        i + 1] * rtb_Sum1_c_idx_2;
      rtb_Product_h_idx_2 += QD2_DroneStack_PID_2021a_B.IFtoHRrotationmatrix[3 *
        i + 2] * rtb_Sum1_c_idx_2;
    }

    /* Gain: '<S1>/Gain' incorporates:
     *  Gain: '<S1>/Kp (rad // m, rad // m, N // m, rad//s // rad)'
     */
    QD2_DroneStack_PID_2021a_B.Gain[0] =
      QD2_DroneStack_PID_2021a_P.KpradmradmNmradsrad_Gain[0] *
      rtb_Product_h_idx_0 * QD2_DroneStack_PID_2021a_P.Gain_Gain_l[0];
    QD2_DroneStack_PID_2021a_B.Gain[1] =
      QD2_DroneStack_PID_2021a_P.KpradmradmNmradsrad_Gain[1] *
      rtb_Product_h_idx_1 * QD2_DroneStack_PID_2021a_P.Gain_Gain_l[1];
    QD2_DroneStack_PID_2021a_B.Gain[2] =
      QD2_DroneStack_PID_2021a_P.KpradmradmNmradsrad_Gain[2] *
      rtb_Product_h_idx_2 * QD2_DroneStack_PID_2021a_P.Gain_Gain_l[2];
    QD2_DroneStack_PID_2021a_B.Gain[3] =
      QD2_DroneStack_PID_2021a_P.KpradmradmNmradsrad_Gain[3] *
      rtb_KiradsmradsmNsmradsrads[3] * QD2_DroneStack_PID_2021a_P.Gain_Gain_l[3];

    /* RelationalOperator: '<S8>/Compare' incorporates:
     *  Constant: '<S8>/Constant'
     */
    QD2_DroneStack_PID_2021a_B.Compare = (QD2_DroneStack_PID_2021a_B.Memory ==
      QD2_DroneStack_PID_2021a_P.Resetwhenstartingtotakeoff_cons);
  }

  /* Integrator: '<S1>/Integrator1' */
  /* Limited  Integrator  */
  if (rtsiIsModeUpdateTimeStep(&QD2_DroneStack_PID_2021a_M->solverInfo)) {
    rtb_Relation_j = (QD2_DroneStack_PID_2021a_B.Compare &&
                      (QD2_DroneStack_PID_2021_PrevZCX.Integrator1_Reset_ZCE !=
                       POS_ZCSIG));
    QD2_DroneStack_PID_2021_PrevZCX.Integrator1_Reset_ZCE =
      QD2_DroneStack_PID_2021a_B.Compare;

    /* evaluate zero-crossings */
    if (rtb_Relation_j) {
      QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_f[0] =
        QD2_DroneStack_PID_2021a_P.Integrator1_IC_i;
      QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_f[1] =
        QD2_DroneStack_PID_2021a_P.Integrator1_IC_i;
      QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_f[2] =
        QD2_DroneStack_PID_2021a_P.Integrator1_IC_i;
      QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_f[3] =
        QD2_DroneStack_PID_2021a_P.Integrator1_IC_i;
    }
  }

  if (QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_f[0] >=
      QD2_DroneStack_PID_2021a_P.Integrator1_UpperSat[0]) {
    QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_f[0] =
      QD2_DroneStack_PID_2021a_P.Integrator1_UpperSat[0];
  } else if (QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_f[0] <=
             QD2_DroneStack_PID_2021a_P.Integrator1_LowerSat[0]) {
    QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_f[0] =
      QD2_DroneStack_PID_2021a_P.Integrator1_LowerSat[0];
  }

  if (QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_f[1] >=
      QD2_DroneStack_PID_2021a_P.Integrator1_UpperSat[1]) {
    QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_f[1] =
      QD2_DroneStack_PID_2021a_P.Integrator1_UpperSat[1];
  } else if (QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_f[1] <=
             QD2_DroneStack_PID_2021a_P.Integrator1_LowerSat[1]) {
    QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_f[1] =
      QD2_DroneStack_PID_2021a_P.Integrator1_LowerSat[1];
  }

  if (QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_f[2] >=
      QD2_DroneStack_PID_2021a_P.Integrator1_UpperSat[2]) {
    QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_f[2] =
      QD2_DroneStack_PID_2021a_P.Integrator1_UpperSat[2];
  } else if (QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_f[2] <=
             QD2_DroneStack_PID_2021a_P.Integrator1_LowerSat[2]) {
    QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_f[2] =
      QD2_DroneStack_PID_2021a_P.Integrator1_LowerSat[2];
  }

  if (QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_f[3] >=
      QD2_DroneStack_PID_2021a_P.Integrator1_UpperSat[3]) {
    QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_f[3] =
      QD2_DroneStack_PID_2021a_P.Integrator1_UpperSat[3];
  } else if (QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_f[3] <=
             QD2_DroneStack_PID_2021a_P.Integrator1_LowerSat[3]) {
    QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_f[3] =
      QD2_DroneStack_PID_2021a_P.Integrator1_LowerSat[3];
  }

  /* Outputs for Iterator SubSystem: '<S63>/For Each Subsystem - Iterate over IMU0 and IMU1' incorporates:
   *  ForEach: '<S82>/For Each'
   */
  for (ForEach_itr_a = 0; ForEach_itr_a < 2; ForEach_itr_a++) {
    /* ForEachSliceSelector generated from: '<S82>/IMU Data [6xn]' */
    for (i = 0; i < 6; i++) {
      rtb_MultiportSwitch[i] = (&QD2_DroneStack_PID_2021a_B.HILRead_o2[0])[6 *
        ForEach_itr_a + i];
    }

    /* End of ForEachSliceSelector generated from: '<S82>/IMU Data [6xn]' */

    /* Integrator: '<S85>/Integrator1' */
    if (QD2_DroneStack_PID_2021a_DW.CoreSubsys_pn[ForEach_itr_a].
        Integrator1_DWORK1) {
      QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
        Integrator1_CSTATE_b[0] = rtb_MultiportSwitch[3];
      QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
        Integrator1_CSTATE_b[1] = rtb_MultiportSwitch[4];
      QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
        Integrator1_CSTATE_b[2] = rtb_MultiportSwitch[5];
    }

    /* MATLAB Function: '<S82>/Roll and Pitch Approximation from Accelerometer data' incorporates:
     *  Integrator: '<S85>/Integrator1'
     */
    QD2_DroneStack_PID_2021a_DW.CoreSubsys_pn[ForEach_itr_a].sfEvent =
      QD2_DroneStack_PID_2_CALL_EVENT;

    /* MATLAB Function 'QDrone 2 DAQ/Attitude Estimate from IMU Data/For Each Subsystem - Iterate over IMU0 and IMU1/Roll and Pitch Approximation from Accelerometer data': '<S83>:1' */
    /* '<S83>:1:7' */
    /* '<S83>:1:3' */
    rtb_DataTypeConversion3 = 3.312168642111238E-170;
    data_loss = fabs(QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
                     Integrator1_CSTATE_b[0]);
    if (data_loss > 3.312168642111238E-170) {
      sigmoid = 1.0;
      rtb_DataTypeConversion3 = data_loss;
    } else {
      rtb_Sum1_c_idx_2 = data_loss / 3.312168642111238E-170;
      sigmoid = rtb_Sum1_c_idx_2 * rtb_Sum1_c_idx_2;
    }

    data_loss = fabs(QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
                     Integrator1_CSTATE_b[1]);
    if (data_loss > rtb_DataTypeConversion3) {
      rtb_Sum1_c_idx_2 = rtb_DataTypeConversion3 / data_loss;
      sigmoid = sigmoid * rtb_Sum1_c_idx_2 * rtb_Sum1_c_idx_2 + 1.0;
      rtb_DataTypeConversion3 = data_loss;
    } else {
      rtb_Sum1_c_idx_2 = data_loss / rtb_DataTypeConversion3;
      sigmoid += rtb_Sum1_c_idx_2 * rtb_Sum1_c_idx_2;
    }

    data_loss = fabs(QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
                     Integrator1_CSTATE_b[2]);
    if (data_loss > rtb_DataTypeConversion3) {
      rtb_Sum1_c_idx_2 = rtb_DataTypeConversion3 / data_loss;
      sigmoid = sigmoid * rtb_Sum1_c_idx_2 * rtb_Sum1_c_idx_2 + 1.0;
      rtb_DataTypeConversion3 = data_loss;
    } else {
      rtb_Sum1_c_idx_2 = data_loss / rtb_DataTypeConversion3;
      sigmoid += rtb_Sum1_c_idx_2 * rtb_Sum1_c_idx_2;
    }

    sigmoid = rtb_DataTypeConversion3 * sqrt(sigmoid);
    if (rtIsNaN(sigmoid)) {
      b_k = 0;
      do {
        exitg1 = 0;
        if (b_k < 3) {
          if (rtIsNaN(QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
                      Integrator1_CSTATE_b[b_k])) {
            exitg1 = 1;
          } else {
            b_k++;
          }
        } else {
          sigmoid = (rtInf);
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }

    if (sigmoid > 2.220446049250313E-16) {
      /* '<S83>:1:4' */
      /* '<S83>:1:5' */
      rtb_Sum1_c_idx_0 = QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a]
        .Integrator1_CSTATE_b[0] / sigmoid;
      rtb_Sum1_c_idx_1 = QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a]
        .Integrator1_CSTATE_b[1] / sigmoid;
      rtb_Sum1_c_idx_2 = QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a]
        .Integrator1_CSTATE_b[2] / sigmoid;
    } else {
      /* '<S83>:1:7' */
      rtb_Sum1_c_idx_0 = 0.0;
      rtb_Sum1_c_idx_1 = 0.0;
      rtb_Sum1_c_idx_2 = 1.0;
    }

    /* '<S83>:1:10' */
    sigmoid = rt_atan2d_snf(rtb_Sum1_c_idx_1, rtb_Sum1_c_idx_2);

    /* Sum: '<S82>/Sum' incorporates:
     *  Integrator: '<S82>/Integrator1'
     *  MATLAB Function: '<S82>/Roll and Pitch Approximation from Accelerometer data'
     */
    /* '<S83>:1:11' */
    rtb_Integrator2_idx_0 =
      QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
      Integrator1_CSTATE_n[0] - sigmoid;
    rtb_Sum1_c_idx_2 = QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
      Integrator1_CSTATE_n[1] - rt_atan2d_snf(-rtb_Sum1_c_idx_0,
      rtb_Sum1_c_idx_1 * sin(sigmoid) + rtb_Sum1_c_idx_2 * cos(sigmoid));

    /* Gain: '<S82>/Gain1' */
    QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Gain1[0] =
      QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.Gain1_Gain[0] *
      rtb_Integrator2_idx_0;
    QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Gain1[1] =
      QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.Gain1_Gain[1] * rtb_Sum1_c_idx_2;

    /* Integrator: '<S84>/Integrator1' */
    if (QD2_DroneStack_PID_2021a_DW.CoreSubsys_pn[ForEach_itr_a].
        Integrator1_DWORK1_n) {
      QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
        Integrator1_CSTATE_o[0] = rtb_MultiportSwitch[0];
      QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
        Integrator1_CSTATE_o[1] = rtb_MultiportSwitch[1];
      QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
        Integrator1_CSTATE_o[2] = rtb_MultiportSwitch[2];
    }

    /* Integrator: '<S84>/Integrator1' */
    QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Integrator1[0] =
      QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
      Integrator1_CSTATE_o[0];

    /* Product: '<S84>/Product1' incorporates:
     *  Constant: '<S82>/Gyro Filter Cutoff Frequency (rad//s)'
     *  Integrator: '<S84>/Integrator2'
     */
    QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Product1[0] =
      QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.GyroFilterCutoffFrequencyrads_V *
      QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
      Integrator2_CSTATE_i[0];

    /* Product: '<S84>/Product' incorporates:
     *  Constant: '<S82>/Gyro Filter Cutoff Frequency (rad//s)'
     *  Constant: '<S82>/Gyro Filter Damping Ratio'
     *  Constant: '<S84>/Constant'
     *  Integrator: '<S84>/Integrator1'
     *  Integrator: '<S84>/Integrator2'
     *  Product: '<S84>/Product2'
     *  Sum: '<S84>/Sum'
     *  Sum: '<S84>/Sum1'
     */
    QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Product[0] =
      ((rtb_MultiportSwitch[0] -
        QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
        Integrator1_CSTATE_o[0]) -
       QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
       Integrator2_CSTATE_i[0] *
       QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.Constant_Value *
       QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.GyroFilterDampingRatio_Value) *
      QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.GyroFilterCutoffFrequencyrads_V;

    /* Product: '<S85>/Product' incorporates:
     *  Constant: '<S82>/Accelerometer Filter Cutoff Frequency (rad//s)'
     *  Constant: '<S82>/Accelerometer Filter Damping Ratio'
     *  Constant: '<S85>/Constant'
     *  Integrator: '<S85>/Integrator1'
     *  Integrator: '<S85>/Integrator2'
     *  Product: '<S85>/Product2'
     *  Sum: '<S85>/Sum'
     *  Sum: '<S85>/Sum1'
     */
    QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Product_i[0] =
      ((rtb_MultiportSwitch[3] -
        QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
        Integrator1_CSTATE_b[0]) -
       QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
       Integrator2_CSTATE_k[0] *
       QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.Constant_Value_p *
       QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.AccelerometerFilterDampingRatio)
      * QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.AccelerometerFilterCutoffFreque;

    /* Product: '<S85>/Product1' incorporates:
     *  Constant: '<S82>/Accelerometer Filter Cutoff Frequency (rad//s)'
     *  Integrator: '<S85>/Integrator2'
     */
    QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Product1_i[0] =
      QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.AccelerometerFilterCutoffFreque *
      QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
      Integrator2_CSTATE_k[0];

    /* Integrator: '<S84>/Integrator1' */
    QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Integrator1[1] =
      QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
      Integrator1_CSTATE_o[1];

    /* Product: '<S84>/Product1' incorporates:
     *  Constant: '<S82>/Gyro Filter Cutoff Frequency (rad//s)'
     *  Integrator: '<S84>/Integrator2'
     */
    QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Product1[1] =
      QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.GyroFilterCutoffFrequencyrads_V *
      QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
      Integrator2_CSTATE_i[1];

    /* Product: '<S84>/Product' incorporates:
     *  Constant: '<S82>/Gyro Filter Cutoff Frequency (rad//s)'
     *  Constant: '<S82>/Gyro Filter Damping Ratio'
     *  Constant: '<S84>/Constant'
     *  Integrator: '<S84>/Integrator1'
     *  Integrator: '<S84>/Integrator2'
     *  Product: '<S84>/Product2'
     *  Sum: '<S84>/Sum'
     *  Sum: '<S84>/Sum1'
     */
    QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Product[1] =
      ((rtb_MultiportSwitch[1] -
        QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
        Integrator1_CSTATE_o[1]) -
       QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
       Integrator2_CSTATE_i[1] *
       QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.Constant_Value *
       QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.GyroFilterDampingRatio_Value) *
      QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.GyroFilterCutoffFrequencyrads_V;

    /* Product: '<S85>/Product' incorporates:
     *  Constant: '<S82>/Accelerometer Filter Cutoff Frequency (rad//s)'
     *  Constant: '<S82>/Accelerometer Filter Damping Ratio'
     *  Constant: '<S85>/Constant'
     *  Integrator: '<S85>/Integrator1'
     *  Integrator: '<S85>/Integrator2'
     *  Product: '<S85>/Product2'
     *  Sum: '<S85>/Sum'
     *  Sum: '<S85>/Sum1'
     */
    QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Product_i[1] =
      ((rtb_MultiportSwitch[4] -
        QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
        Integrator1_CSTATE_b[1]) -
       QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
       Integrator2_CSTATE_k[1] *
       QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.Constant_Value_p *
       QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.AccelerometerFilterDampingRatio)
      * QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.AccelerometerFilterCutoffFreque;

    /* Product: '<S85>/Product1' incorporates:
     *  Constant: '<S82>/Accelerometer Filter Cutoff Frequency (rad//s)'
     *  Integrator: '<S85>/Integrator2'
     */
    QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Product1_i[1] =
      QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.AccelerometerFilterCutoffFreque *
      QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
      Integrator2_CSTATE_k[1];

    /* Integrator: '<S84>/Integrator1' */
    QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Integrator1[2] =
      QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
      Integrator1_CSTATE_o[2];

    /* Product: '<S84>/Product1' incorporates:
     *  Constant: '<S82>/Gyro Filter Cutoff Frequency (rad//s)'
     *  Integrator: '<S84>/Integrator2'
     */
    QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Product1[2] =
      QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.GyroFilterCutoffFrequencyrads_V *
      QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
      Integrator2_CSTATE_i[2];

    /* Product: '<S84>/Product' incorporates:
     *  Constant: '<S82>/Gyro Filter Cutoff Frequency (rad//s)'
     *  Constant: '<S82>/Gyro Filter Damping Ratio'
     *  Constant: '<S84>/Constant'
     *  Integrator: '<S84>/Integrator1'
     *  Integrator: '<S84>/Integrator2'
     *  Product: '<S84>/Product2'
     *  Sum: '<S84>/Sum'
     *  Sum: '<S84>/Sum1'
     */
    QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Product[2] =
      ((rtb_MultiportSwitch[2] -
        QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
        Integrator1_CSTATE_o[2]) -
       QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
       Integrator2_CSTATE_i[2] *
       QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.Constant_Value *
       QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.GyroFilterDampingRatio_Value) *
      QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.GyroFilterCutoffFrequencyrads_V;

    /* Product: '<S85>/Product' incorporates:
     *  Constant: '<S82>/Accelerometer Filter Cutoff Frequency (rad//s)'
     *  Constant: '<S82>/Accelerometer Filter Damping Ratio'
     *  Constant: '<S85>/Constant'
     *  Integrator: '<S85>/Integrator1'
     *  Integrator: '<S85>/Integrator2'
     *  Product: '<S85>/Product2'
     *  Sum: '<S85>/Sum'
     *  Sum: '<S85>/Sum1'
     */
    QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Product_i[2] =
      ((rtb_MultiportSwitch[5] -
        QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
        Integrator1_CSTATE_b[2]) -
       QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
       Integrator2_CSTATE_k[2] *
       QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.Constant_Value_p *
       QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.AccelerometerFilterDampingRatio)
      * QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.AccelerometerFilterCutoffFreque;

    /* Product: '<S85>/Product1' incorporates:
     *  Constant: '<S82>/Accelerometer Filter Cutoff Frequency (rad//s)'
     *  Integrator: '<S85>/Integrator2'
     */
    QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Product1_i[2] =
      QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.AccelerometerFilterCutoffFreque *
      QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
      Integrator2_CSTATE_k[2];

    /* Sum: '<S82>/Sum1' incorporates:
     *  Gain: '<S82>/Gain'
     *  Integrator: '<S82>/Integrator'
     */
    QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Sum1[0] =
      (QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Integrator1[0] -
       QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.Gain_Gain[0] *
       rtb_Integrator2_idx_0) -
      QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].Integrator_CSTATE
      [0];

    /* ForEachSliceAssignment generated from: '<S82>/BF Estimated Attitude (rad, rad//s, rad//2^2) [9xn]' incorporates:
     *  Integrator: '<S82>/Integrator1'
     */
    rtb_ImpAsg_InsertedFor_BFEstima[9 * ForEach_itr_a] =
      QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
      Integrator1_CSTATE_n[0];

    /* Sum: '<S82>/Sum1' incorporates:
     *  Gain: '<S82>/Gain'
     *  Integrator: '<S82>/Integrator'
     */
    QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Sum1[1] =
      (QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Integrator1[1] -
       QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.Gain_Gain[1] * rtb_Sum1_c_idx_2)
      - QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
      Integrator_CSTATE[1];

    /* ForEachSliceAssignment generated from: '<S82>/BF Estimated Attitude (rad, rad//s, rad//2^2) [9xn]' incorporates:
     *  Integrator: '<S82>/Integrator1'
     *  Integrator: '<S82>/Integrator2'
     *  SignalConversion generated from: '<S82>/BF Estimated Attitude (rad, rad//s, rad//2^2) [9xn]'
     */
    rtb_ImpAsg_InsertedFor_BFEstima[9 * ForEach_itr_a + 1] =
      QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
      Integrator1_CSTATE_n[1];
    rtb_ImpAsg_InsertedFor_BFEstima[9 * ForEach_itr_a + 2] =
      QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
      Integrator2_CSTATE_od;
    rtb_ImpAsg_InsertedFor_BFEstima[9 * ForEach_itr_a + 3] =
      QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Integrator1[0];
    rtb_ImpAsg_InsertedFor_BFEstima[9 * ForEach_itr_a + 6] =
      QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Product1[0];
    rtb_ImpAsg_InsertedFor_BFEstima[9 * ForEach_itr_a + 4] =
      QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Integrator1[1];
    rtb_ImpAsg_InsertedFor_BFEstima[9 * ForEach_itr_a + 7] =
      QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Product1[1];
    rtb_ImpAsg_InsertedFor_BFEstima[9 * ForEach_itr_a + 5] =
      QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Integrator1[2];
    rtb_ImpAsg_InsertedFor_BFEstima[9 * ForEach_itr_a + 8] =
      QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Product1[2];
  }

  /* End of Outputs for SubSystem: '<S63>/For Each Subsystem - Iterate over IMU0 and IMU1' */
  for (i = 0; i < 9; i++) {
    /* Selector: '<S63>/Select Data for IMU1' incorporates:
     *  ForEachSliceAssignment generated from: '<S82>/BF Estimated Attitude (rad, rad//s, rad//2^2) [9xn]'
     */
    rtb_Sum1_c_idx_2 = rtb_ImpAsg_InsertedFor_BFEstima[i + 9];
    QD2_DroneStack_PID_2021a_B.SelectDataforIMU1[i] = rtb_Sum1_c_idx_2;

    /* Selector: '<S63>/Select Data for IMU0' incorporates:
     *  ForEachSliceAssignment generated from: '<S82>/BF Estimated Attitude (rad, rad//s, rad//2^2) [9xn]'
     */
    sigmoid = rtb_ImpAsg_InsertedFor_BFEstima[i];
    QD2_DroneStack_PID_2021a_B.SelectDataforIMU0[i] = sigmoid;

    /* Product: '<S5>/Product3' incorporates:
     *  Constant: '<S5>/Constant1'
     *  Selector: '<S63>/Select Data for IMU0'
     *  Selector: '<S63>/Select Data for IMU1'
     *  Sum: '<S5>/Sum'
     */
    QD2_DroneStack_PID_2021a_B.Product3[i] = (rtb_Sum1_c_idx_2 + sigmoid) /
      QD2_DroneStack_PID_2021a_P.Constant1_Value_k;
  }

  if (rtb_Compare_f) {
    /* S-Function (euler_angles_to_rotation_matrix_block): '<S3>/Euler Angles to Rotation Matrix2' */
    {
      t_double sin_phi = sin(QD2_DroneStack_PID_2021a_B.Integrator1);
      t_double cos_phi = cos(QD2_DroneStack_PID_2021a_B.Integrator1);
      t_double sin_theta = sin(QD2_DroneStack_PID_2021a_B.Product3[1]);
      t_double cos_theta = cos(QD2_DroneStack_PID_2021a_B.Product3[1]);
      t_double sin_psi = sin(QD2_DroneStack_PID_2021a_B.Product3[0]);
      t_double cos_psi = cos(QD2_DroneStack_PID_2021a_B.Product3[0]);
      rtb_BFToIFrotationmatrix[0] = cos_phi * cos_theta;
      rtb_BFToIFrotationmatrix[1] = sin_phi * cos_theta;
      rtb_BFToIFrotationmatrix[2] = -sin_theta;
      rtb_BFToIFrotationmatrix[3] = -sin_phi * cos_psi + cos_phi * sin_theta *
        sin_psi;
      rtb_BFToIFrotationmatrix[4] = cos_phi * cos_psi + sin_phi * sin_theta *
        sin_psi;
      rtb_BFToIFrotationmatrix[5] = cos_theta * sin_psi;
      rtb_BFToIFrotationmatrix[6] = sin_phi * sin_psi + cos_phi * sin_theta *
        cos_psi;
      rtb_BFToIFrotationmatrix[7] = -cos_phi * sin_psi + sin_phi * sin_theta *
        cos_psi;
      rtb_BFToIFrotationmatrix[8] = cos_theta * cos_psi;
    }

    for (i = 0; i < 6; i++) {
      /* Product: '<S5>/Product4' incorporates:
       *  Constant: '<S5>/Constant1'
       *  Sum: '<S5>/Sum1'
       */
      QD2_DroneStack_PID_2021a_B.Product4[i] =
        (QD2_DroneStack_PID_2021a_B.HILRead_o2[i + 6] +
         QD2_DroneStack_PID_2021a_B.HILRead_o2[i]) /
        QD2_DroneStack_PID_2021a_P.Constant1_Value_k;
    }

    /* Product: '<S3>/Product1' incorporates:
     *  S-Function (euler_angles_to_rotation_matrix_block): '<S3>/Euler Angles to Rotation Matrix2'
     */
    sigmoid = 0.0;
    rtb_Sum1_c_idx_0 = 0.0;
    rtb_Sum1_c_idx_1 = 0.0;
    for (i = 0; i < 3; i++) {
      rtb_Sum1_c_idx_2 = QD2_DroneStack_PID_2021a_B.Product4[i];
      sigmoid += rtb_BFToIFrotationmatrix[3 * i] * rtb_Sum1_c_idx_2;
      rtb_Sum1_c_idx_0 += rtb_BFToIFrotationmatrix[3 * i + 1] * rtb_Sum1_c_idx_2;
      rtb_Sum1_c_idx_1 += rtb_BFToIFrotationmatrix[3 * i + 2] * rtb_Sum1_c_idx_2;
    }

    QD2_DroneStack_PID_2021a_B.Product1[2] = rtb_Sum1_c_idx_1;
    QD2_DroneStack_PID_2021a_B.Product1[1] = rtb_Sum1_c_idx_0;
    QD2_DroneStack_PID_2021a_B.Product1[0] = sigmoid;

    /* End of Product: '<S3>/Product1' */
  }

  /* Product: '<S3>/Matrix Multiply1' incorporates:
   *  Integrator: '<S3>/Integrator6'
   *  Math: '<S3>/Transpose'
   */
  rtb_Sum1_j_idx_1 = 0.0;
  tmp_0 = 0.0;
  tmp_1 = 0.0;
  for (i = 0; i < 3; i++) {
    rtb_Sum1_c_idx_2 = QD2_DroneStack_PID_2021a_X.Integrator6_CSTATE[i];
    rtb_Sum1_j_idx_1 += QD2_DroneStack_PID_2021a_B.IFtoHRrotationmatrix[3 * i] *
      rtb_Sum1_c_idx_2;
    tmp_0 += QD2_DroneStack_PID_2021a_B.IFtoHRrotationmatrix[3 * i + 1] *
      rtb_Sum1_c_idx_2;
    tmp_1 += QD2_DroneStack_PID_2021a_B.IFtoHRrotationmatrix[3 * i + 2] *
      rtb_Sum1_c_idx_2;
  }

  /* End of Product: '<S3>/Matrix Multiply1' */

  /* Sum: '<S1>/Sum2' incorporates:
   *  Gain: '<S1>/Gain2'
   *  Gain: '<S1>/Kd (rad // m//s, rad // m//s, N // m//s, rad//s // rad//s)'
   *  Integrator: '<S1>/Integrator1'
   */
  QD2_DroneStack_PID_2021a_B.UnsaturatedControllerCommandsNr[0] =
    (QD2_DroneStack_PID_2021a_B.Gain[0] +
     QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_f[0]) -
    QD2_DroneStack_PID_2021a_P.KdradmsradmsNmsradsrads_Gain[0] *
    rtb_Sum1_j_idx_1 * QD2_DroneStack_PID_2021a_P.Gain2_Gain[0];
  QD2_DroneStack_PID_2021a_B.UnsaturatedControllerCommandsNr[1] =
    (QD2_DroneStack_PID_2021a_B.Gain[1] +
     QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_f[1]) -
    QD2_DroneStack_PID_2021a_P.KdradmsradmsNmsradsrads_Gain[1] * tmp_0 *
    QD2_DroneStack_PID_2021a_P.Gain2_Gain[1];
  QD2_DroneStack_PID_2021a_B.UnsaturatedControllerCommandsNr[2] =
    (QD2_DroneStack_PID_2021a_B.Gain[2] +
     QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_f[2]) -
    QD2_DroneStack_PID_2021a_P.KdradmsradmsNmsradsrads_Gain[2] * tmp_1 *
    QD2_DroneStack_PID_2021a_P.Gain2_Gain[2];
  QD2_DroneStack_PID_2021a_B.UnsaturatedControllerCommandsNr[3] =
    (QD2_DroneStack_PID_2021a_B.Gain[3] +
     QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_f[3]) -
    QD2_DroneStack_PID_2021a_B.Product1[2] *
    QD2_DroneStack_PID_2021a_P.KdradmsradmsNmsradsrads_Gain[3] *
    QD2_DroneStack_PID_2021a_P.Gain2_Gain[3];

  /* Integrator: '<S39>/Integrator1' */
  if (QD2_DroneStack_PID_2021a_DW.Integrator1_DWORK1) {
    QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_h[0] =
      QD2_DroneStack_PID_2021a_B.UnsaturatedControllerCommandsNr[0];
    QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_h[1] =
      QD2_DroneStack_PID_2021a_B.UnsaturatedControllerCommandsNr[1];
  }

  /* Integrator: '<S39>/Integrator1' */
  QD2_DroneStack_PID_2021a_B.Integrator1_o[0] =
    QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_h[0];
  QD2_DroneStack_PID_2021a_B.Integrator1_o[1] =
    QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_h[1];

  /* Saturate: '<S1>/Saturate Stabilization Command' incorporates:
   *  Integrator: '<S39>/Integrator1'
   */
  if (QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_h[0] >
      QD2_DroneStack_PID_2021a_P.SaturateStabilizationCommand_Up[0]) {
    Duty_Cycle[0] = QD2_DroneStack_PID_2021a_P.SaturateStabilizationCommand_Up[0];
  } else if (QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_h[0] <
             QD2_DroneStack_PID_2021a_P.SaturateStabilizationCommand_Lo[0]) {
    Duty_Cycle[0] = QD2_DroneStack_PID_2021a_P.SaturateStabilizationCommand_Lo[0];
  } else {
    Duty_Cycle[0] = QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_h[0];
  }

  /* Product: '<S1>/ ' */
  QD2_DroneStack_PID_2021a_B.GeneralizedCommandNradradrads4[0] = 0.0;

  /* Saturate: '<S1>/Saturate Stabilization Command' incorporates:
   *  Integrator: '<S39>/Integrator1'
   */
  if (QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_h[1] >
      QD2_DroneStack_PID_2021a_P.SaturateStabilizationCommand_Up[1]) {
    Duty_Cycle[1] = QD2_DroneStack_PID_2021a_P.SaturateStabilizationCommand_Up[1];
  } else if (QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_h[1] <
             QD2_DroneStack_PID_2021a_P.SaturateStabilizationCommand_Lo[1]) {
    Duty_Cycle[1] = QD2_DroneStack_PID_2021a_P.SaturateStabilizationCommand_Lo[1];
  } else {
    Duty_Cycle[1] = QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_h[1];
  }

  /* Product: '<S1>/ ' */
  QD2_DroneStack_PID_2021a_B.GeneralizedCommandNradradrads4[1] = 0.0;

  /* Saturate: '<S1>/Saturate Stabilization Command' */
  if (QD2_DroneStack_PID_2021a_B.UnsaturatedControllerCommandsNr[2] >
      QD2_DroneStack_PID_2021a_P.SaturateStabilizationCommand_Up[2]) {
    Duty_Cycle[2] = QD2_DroneStack_PID_2021a_P.SaturateStabilizationCommand_Up[2];
  } else if (QD2_DroneStack_PID_2021a_B.UnsaturatedControllerCommandsNr[2] <
             QD2_DroneStack_PID_2021a_P.SaturateStabilizationCommand_Lo[2]) {
    Duty_Cycle[2] = QD2_DroneStack_PID_2021a_P.SaturateStabilizationCommand_Lo[2];
  } else {
    Duty_Cycle[2] = QD2_DroneStack_PID_2021a_B.UnsaturatedControllerCommandsNr[2];
  }

  /* Product: '<S1>/ ' */
  QD2_DroneStack_PID_2021a_B.GeneralizedCommandNradradrads4[2] = 0.0;

  /* Saturate: '<S1>/Saturate Stabilization Command' */
  if (QD2_DroneStack_PID_2021a_B.UnsaturatedControllerCommandsNr[3] >
      QD2_DroneStack_PID_2021a_P.SaturateStabilizationCommand_Up[3]) {
    Duty_Cycle[3] = QD2_DroneStack_PID_2021a_P.SaturateStabilizationCommand_Up[3];
  } else if (QD2_DroneStack_PID_2021a_B.UnsaturatedControllerCommandsNr[3] <
             QD2_DroneStack_PID_2021a_P.SaturateStabilizationCommand_Lo[3]) {
    Duty_Cycle[3] = QD2_DroneStack_PID_2021a_P.SaturateStabilizationCommand_Lo[3];
  } else {
    Duty_Cycle[3] = QD2_DroneStack_PID_2021a_B.UnsaturatedControllerCommandsNr[3];
  }

  /* Product: '<S1>/ ' incorporates:
   *  Constant: '<S1>/Constant2'
   */
  QD2_DroneStack_PID_2021a_B.GeneralizedCommandNradradrads4[3] = 0.0;
  sigmoid = QD2_DroneStack_PID_2021a_B.GeneralizedCommandNradradrads4[0];
  rtb_Sum1_c_idx_0 = QD2_DroneStack_PID_2021a_B.GeneralizedCommandNradradrads4[1];
  rtb_Sum1_c_idx_1 = QD2_DroneStack_PID_2021a_B.GeneralizedCommandNradradrads4[2];
  rtb_Integrator2_idx_0 =
    QD2_DroneStack_PID_2021a_B.GeneralizedCommandNradradrads4[3];
  for (i = 0; i < 4; i++) {
    rtb_Sum1_c_idx_2 = Duty_Cycle[i];
    firstBlockLength = i << 2;
    sigmoid += QD2_DroneStack_PID_2021a_P.Constant2_Value_a[firstBlockLength] *
      rtb_Sum1_c_idx_2;
    rtb_Sum1_c_idx_0 +=
      QD2_DroneStack_PID_2021a_P.Constant2_Value_a[firstBlockLength + 1] *
      rtb_Sum1_c_idx_2;
    rtb_Sum1_c_idx_1 +=
      QD2_DroneStack_PID_2021a_P.Constant2_Value_a[firstBlockLength + 2] *
      rtb_Sum1_c_idx_2;
    rtb_Integrator2_idx_0 +=
      QD2_DroneStack_PID_2021a_P.Constant2_Value_a[firstBlockLength + 3] *
      rtb_Sum1_c_idx_2;
  }

  QD2_DroneStack_PID_2021a_B.GeneralizedCommandNradradrads4[3] =
    rtb_Integrator2_idx_0;
  QD2_DroneStack_PID_2021a_B.GeneralizedCommandNradradrads4[2] =
    rtb_Sum1_c_idx_1;
  QD2_DroneStack_PID_2021a_B.GeneralizedCommandNradradrads4[1] =
    rtb_Sum1_c_idx_0;
  QD2_DroneStack_PID_2021a_B.GeneralizedCommandNradradrads4[0] = sigmoid;

  /* RateLimiter: '<S13>/Rate Limiter (N//s)' */
  if (QD2_DroneStack_PID_2021a_DW.LastMajorTime == (rtInf)) {
    /* RateLimiter: '<S13>/Rate Limiter (N//s)' */
    QD2_DroneStack_PID_2021a_B.RateLimiterNs =
      QD2_DroneStack_PID_2021a_B.GeneralizedCommandNradradrads4[0];
  } else {
    rtb_DataTypeConversion3 = QD2_DroneStack_PID_2021a_M->Timing.t[0];
    sigmoid = rtb_DataTypeConversion3 -
      QD2_DroneStack_PID_2021a_DW.LastMajorTime;
    if (QD2_DroneStack_PID_2021a_DW.LastMajorTime == rtb_DataTypeConversion3) {
      if (QD2_DroneStack_PID_2021a_DW.PrevLimited) {
        /* RateLimiter: '<S13>/Rate Limiter (N//s)' */
        QD2_DroneStack_PID_2021a_B.RateLimiterNs =
          QD2_DroneStack_PID_2021a_DW.PrevY;
      } else {
        /* RateLimiter: '<S13>/Rate Limiter (N//s)' */
        QD2_DroneStack_PID_2021a_B.RateLimiterNs =
          QD2_DroneStack_PID_2021a_B.GeneralizedCommandNradradrads4[0];
      }
    } else {
      data_loss = sigmoid * QD2_DroneStack_PID_2021a_P.RateLimiterNs_RisingLim;
      rtb_DataTypeConversion3 =
        QD2_DroneStack_PID_2021a_B.GeneralizedCommandNradradrads4[0] -
        QD2_DroneStack_PID_2021a_DW.PrevY;
      if (rtb_DataTypeConversion3 > data_loss) {
        /* RateLimiter: '<S13>/Rate Limiter (N//s)' */
        QD2_DroneStack_PID_2021a_B.RateLimiterNs =
          QD2_DroneStack_PID_2021a_DW.PrevY + data_loss;
        rtb_Relation_j = true;
      } else {
        sigmoid *= QD2_DroneStack_PID_2021a_P.RateLimiterNs_FallingLim;
        if (rtb_DataTypeConversion3 < sigmoid) {
          /* RateLimiter: '<S13>/Rate Limiter (N//s)' */
          QD2_DroneStack_PID_2021a_B.RateLimiterNs =
            QD2_DroneStack_PID_2021a_DW.PrevY + sigmoid;
          rtb_Relation_j = true;
        } else {
          /* RateLimiter: '<S13>/Rate Limiter (N//s)' */
          QD2_DroneStack_PID_2021a_B.RateLimiterNs =
            QD2_DroneStack_PID_2021a_B.GeneralizedCommandNradradrads4[0];
          rtb_Relation_j = false;
        }
      }

      if (rtsiIsModeUpdateTimeStep(&QD2_DroneStack_PID_2021a_M->solverInfo)) {
        QD2_DroneStack_PID_2021a_DW.PrevLimited = rtb_Relation_j;
      }
    }
  }

  /* End of RateLimiter: '<S13>/Rate Limiter (N//s)' */

  /* MultiPortSwitch: '<S13>/Actual height' incorporates:
   *  Constant: '<S13>/Constant1'
   */
  switch ((int32_T)QD2_DroneStack_PID_2021a_B.Memory) {
   case 1:
    sigmoid = QD2_DroneStack_PID_2021a_P.Constant1_Value;
    break;

   case 2:
    sigmoid = QD2_DroneStack_PID_2021a_P.Constant1_Value;
    break;

   case 3:
    sigmoid = QD2_DroneStack_PID_2021a_P.Constant1_Value;
    break;

   case 4:
    sigmoid = QD2_DroneStack_PID_2021a_B.GeneralizedCommandNradradrads4[0];
    break;

   case 5:
    sigmoid = QD2_DroneStack_PID_2021a_B.GeneralizedCommandNradradrads4[0];
    break;

   case 6:
    sigmoid = QD2_DroneStack_PID_2021a_B.RateLimiterNs;
    break;

   case 7:
    sigmoid = QD2_DroneStack_PID_2021a_P.Constant1_Value;
    break;

   case 8:
    sigmoid = QD2_DroneStack_PID_2021a_P.Constant1_Value;
    break;

   default:
    sigmoid = QD2_DroneStack_PID_2021a_P.Constant1_Value;
    break;
  }

  /* End of MultiPortSwitch: '<S13>/Actual height' */

  /* Sum: '<S13>/Add' */
  rtb_Sum1_c_idx_2 = QD2_DroneStack_PID_2021a_B.Switch2 + sigmoid;

  /* Saturate: '<S13>/(N)' */
  if (rtb_Sum1_c_idx_2 > QD2_DroneStack_PID_2021a_P.N_UpperSat) {
    /* Saturate: '<S13>/(N)' */
    QD2_DroneStack_PID_2021a_B.NetThrottle =
      QD2_DroneStack_PID_2021a_P.N_UpperSat;
  } else if (rtb_Sum1_c_idx_2 < QD2_DroneStack_PID_2021a_P.N_LowerSat) {
    /* Saturate: '<S13>/(N)' */
    QD2_DroneStack_PID_2021a_B.NetThrottle =
      QD2_DroneStack_PID_2021a_P.N_LowerSat;
  } else {
    /* Saturate: '<S13>/(N)' */
    QD2_DroneStack_PID_2021a_B.NetThrottle = rtb_Sum1_c_idx_2;
  }

  /* End of Saturate: '<S13>/(N)' */
  if (rtb_Compare_f) {
    /* Constant: '<S1>/Specify Angle Mode for Stabilizer (DO NOT CHANGE)' */
    QD2_DroneStack_PID_2021a_B.SpecifyAngleModeforStabilizerDO =
      QD2_DroneStack_PID_2021a_P.SpecifyAngleModeforStabilizerDO;

    /* Switch: '<S7>/Switch' */
    if (QD2_DroneStack_PID_2021a_B.SpecifyAngleModeforStabilizerDO >
        QD2_DroneStack_PID_2021a_P.Switch_Threshold_l) {
      /* Switch: '<S7>/Switch' incorporates:
       *  Constant: '<Root>/zero reference torque commands'
       */
      QD2_DroneStack_PID_2021a_B.AttitudeTorqueCommands[0] =
        QD2_DroneStack_PID_2021a_P.zeroreferencetorquecommands_Val[0];
      QD2_DroneStack_PID_2021a_B.AttitudeTorqueCommands[1] =
        QD2_DroneStack_PID_2021a_P.zeroreferencetorquecommands_Val[1];
      QD2_DroneStack_PID_2021a_B.AttitudeTorqueCommands[2] =
        QD2_DroneStack_PID_2021a_P.zeroreferencetorquecommands_Val[2];
    } else {
      /* Switch: '<S7>/Switch' incorporates:
       *  Constant: '<S7>/Zero Torque//Command'
       */
      QD2_DroneStack_PID_2021a_B.AttitudeTorqueCommands[0] =
        QD2_DroneStack_PID_2021a_P.ZeroTorqueCommand_Value[0];
      QD2_DroneStack_PID_2021a_B.AttitudeTorqueCommands[1] =
        QD2_DroneStack_PID_2021a_P.ZeroTorqueCommand_Value[1];
      QD2_DroneStack_PID_2021a_B.AttitudeTorqueCommands[2] =
        QD2_DroneStack_PID_2021a_P.ZeroTorqueCommand_Value[2];
    }

    /* End of Switch: '<S7>/Switch' */

    /* DataTypeConversion: '<S13>/Data Type Conversion' incorporates:
     *  Constant: '<S41>/Constant'
     *  Constant: '<S42>/Constant'
     *  Constant: '<S43>/Constant'
     *  Logic: '<S13>/Logical Operator'
     *  RelationalOperator: '<S41>/Compare'
     *  RelationalOperator: '<S42>/Compare'
     *  RelationalOperator: '<S43>/Compare'
     */
    QD2_DroneStack_PID_2021a_B.DataTypeConversion_k =
      ((QD2_DroneStack_PID_2021a_B.Memory ==
        QD2_DroneStack_PID_2021a_P.IgnoreYawControllerunlessinFlig) ||
       (QD2_DroneStack_PID_2021a_B.Memory ==
        QD2_DroneStack_PID_2021a_P.IgnoreYawControllerunlessinFl_h) ||
       (QD2_DroneStack_PID_2021a_B.Memory ==
        QD2_DroneStack_PID_2021a_P.IgnoreControllerunlessinTakeoff));
  }

  /* Switch: '<S7>/Switch1' incorporates:
   *  Constant: '<S13>/Null Attitude Command (rad, rad, rad//s)'
   *  Constant: '<S7>/Zero Torque//Command'
   *  Switch: '<S13>/Switch'
   */
  if (QD2_DroneStack_PID_2021a_B.SpecifyAngleModeforStabilizerDO >
      QD2_DroneStack_PID_2021a_P.Switch1_Threshold_b) {
    rtb_Sum1_c_idx_0 = QD2_DroneStack_PID_2021a_P.ZeroTorqueCommand_Value[0];
    rtb_Sum1_c_idx_1 = QD2_DroneStack_PID_2021a_P.ZeroTorqueCommand_Value[1];
    rtb_Sum1_c_idx_2 = QD2_DroneStack_PID_2021a_P.ZeroTorqueCommand_Value[2];
  } else if (QD2_DroneStack_PID_2021a_B.DataTypeConversion_k >
             QD2_DroneStack_PID_2021a_P.Switch_Threshold) {
    /* Switch: '<S13>/Switch' */
    rtb_Sum1_c_idx_0 =
      QD2_DroneStack_PID_2021a_B.GeneralizedCommandNradradrads4[1];
    rtb_Sum1_c_idx_1 =
      QD2_DroneStack_PID_2021a_B.GeneralizedCommandNradradrads4[2];
    rtb_Sum1_c_idx_2 =
      QD2_DroneStack_PID_2021a_B.GeneralizedCommandNradradrads4[3];
  } else {
    rtb_Sum1_c_idx_0 =
      QD2_DroneStack_PID_2021a_P.NullAttitudeCommandradradrads_V[0];
    rtb_Sum1_c_idx_1 =
      QD2_DroneStack_PID_2021a_P.NullAttitudeCommandradradrads_V[1];
    rtb_Sum1_c_idx_2 =
      QD2_DroneStack_PID_2021a_P.NullAttitudeCommandradradrads_V[2];
  }

  /* End of Switch: '<S7>/Switch1' */

  /* Saturate: '<S7>/Saturate Stabilization Command' */
  if (rtb_Sum1_c_idx_0 >
      QD2_DroneStack_PID_2021a_P.SaturateStabilizationCommand__o[0]) {
    /* Saturate: '<S7>/Saturate Stabilization Command' */
    rtb_Integrator2_idx_0 =
      QD2_DroneStack_PID_2021a_P.SaturateStabilizationCommand__o[0];
  } else if (rtb_Sum1_c_idx_0 <
             QD2_DroneStack_PID_2021a_P.SaturateStabilizationCommand__g[0]) {
    /* Saturate: '<S7>/Saturate Stabilization Command' */
    rtb_Integrator2_idx_0 =
      QD2_DroneStack_PID_2021a_P.SaturateStabilizationCommand__g[0];
  } else {
    /* Saturate: '<S7>/Saturate Stabilization Command' */
    rtb_Integrator2_idx_0 = rtb_Sum1_c_idx_0;
  }

  /* Saturate: '<S7>/Saturate Stabilization Command' */
  QD2_DroneStack_PID_2021a_B.AttitudeAngleCommands[0] = rtb_Integrator2_idx_0;

  /* Sum: '<S7>/Sum1' incorporates:
   *  Gain: '<S7>/Gain1'
   *  Gain: '<S7>/K_d_angle (rad//s // rad//s)'
   *  Gain: '<S7>/K_p_angle (rad//s // rad)'
   *  Gain: '<S7>/Scale'
   *  Gain: '<S7>/Scale1'
   *  Sum: '<S7>/Sum'
   */
  rtb_Integrator2_idx_0 = (rtb_Integrator2_idx_0 -
    QD2_DroneStack_PID_2021a_P.Gain1_Gain[0] *
    QD2_DroneStack_PID_2021a_B.Product3[0]) *
    QD2_DroneStack_PID_2021a_P.K_p_angleradsrad_Gain[0] *
    QD2_DroneStack_PID_2021a_P.Scale_Gain[0] -
    QD2_DroneStack_PID_2021a_P.K_d_angleradsrads_Gain[0] *
    QD2_DroneStack_PID_2021a_B.Product3[3] *
    QD2_DroneStack_PID_2021a_P.Scale1_Gain[0];
  rtb_Sum1_c_idx_0 = rtb_Integrator2_idx_0;

  /* Saturate: '<S7>/Saturation Max Rate  (rad//s)' */
  if (rtb_Integrator2_idx_0 >
      QD2_DroneStack_PID_2021a_P.SaturationMaxRaterads_UpperSat[0]) {
    rtb_Integrator2_idx_0 =
      QD2_DroneStack_PID_2021a_P.SaturationMaxRaterads_UpperSat[0];
  } else if (rtb_Integrator2_idx_0 <
             QD2_DroneStack_PID_2021a_P.SaturationMaxRaterads_LowerSat[0]) {
    rtb_Integrator2_idx_0 =
      QD2_DroneStack_PID_2021a_P.SaturationMaxRaterads_LowerSat[0];
  }

  /* Sum: '<S7>/Sum6' incorporates:
   *  Gain: '<S7>/K_d_angle (rad//s // rad//s)'
   *  Gain: '<S7>/K_d_speed (Nm // rad//s//s)1'
   *  Gain: '<S7>/K_p_speed (Nm // rad//s)'
   *  Gain: '<S7>/Scale4'
   *  Gain: '<S7>/Scale5'
   *  Saturate: '<S7>/Saturation Max Rate  (rad//s)'
   *  Sum: '<S7>/Sum5'
   */
  QD2_DroneStack_PID_2021a_B.Sum6[0] = ((rtb_Integrator2_idx_0 -
    QD2_DroneStack_PID_2021a_B.Product3[3]) *
    QD2_DroneStack_PID_2021a_P.K_p_speedNmrads_Gain[0] *
    QD2_DroneStack_PID_2021a_P.Scale5_Gain[0] +
    QD2_DroneStack_PID_2021a_B.AttitudeTorqueCommands[0]) -
    QD2_DroneStack_PID_2021a_P.K_d_speedNmradss1_Gain[0] *
    QD2_DroneStack_PID_2021a_B.Product3[6] *
    QD2_DroneStack_PID_2021a_P.Scale4_Gain[0];

  /* Saturate: '<S7>/Saturation Command  Authority (Nm)1' */
  if (QD2_DroneStack_PID_2021a_B.Sum6[0] >
      QD2_DroneStack_PID_2021a_P.SaturationCommandAuthorityNm1_U[0]) {
    /* Saturate: '<S7>/Saturation Command  Authority (Nm)1' */
    QD2_DroneStack_PID_2021a_B.SaturationCommandAuthorityNm1[0] =
      QD2_DroneStack_PID_2021a_P.SaturationCommandAuthorityNm1_U[0];
  } else if (QD2_DroneStack_PID_2021a_B.Sum6[0] <
             QD2_DroneStack_PID_2021a_P.SaturationCommandAuthorityNm1_L[0]) {
    /* Saturate: '<S7>/Saturation Command  Authority (Nm)1' */
    QD2_DroneStack_PID_2021a_B.SaturationCommandAuthorityNm1[0] =
      QD2_DroneStack_PID_2021a_P.SaturationCommandAuthorityNm1_L[0];
  } else {
    /* Saturate: '<S7>/Saturation Command  Authority (Nm)1' */
    QD2_DroneStack_PID_2021a_B.SaturationCommandAuthorityNm1[0] =
      QD2_DroneStack_PID_2021a_B.Sum6[0];
  }

  /* Saturate: '<S7>/Saturate Stabilization Command' */
  if (rtb_Sum1_c_idx_1 >
      QD2_DroneStack_PID_2021a_P.SaturateStabilizationCommand__o[1]) {
    /* Saturate: '<S7>/Saturate Stabilization Command' */
    rtb_Integrator2_idx_0 =
      QD2_DroneStack_PID_2021a_P.SaturateStabilizationCommand__o[1];
  } else if (rtb_Sum1_c_idx_1 <
             QD2_DroneStack_PID_2021a_P.SaturateStabilizationCommand__g[1]) {
    /* Saturate: '<S7>/Saturate Stabilization Command' */
    rtb_Integrator2_idx_0 =
      QD2_DroneStack_PID_2021a_P.SaturateStabilizationCommand__g[1];
  } else {
    /* Saturate: '<S7>/Saturate Stabilization Command' */
    rtb_Integrator2_idx_0 = rtb_Sum1_c_idx_1;
  }

  /* Saturate: '<S7>/Saturate Stabilization Command' */
  QD2_DroneStack_PID_2021a_B.AttitudeAngleCommands[1] = rtb_Integrator2_idx_0;

  /* Sum: '<S7>/Sum1' incorporates:
   *  Gain: '<S7>/Gain1'
   *  Gain: '<S7>/K_d_angle (rad//s // rad//s)'
   *  Gain: '<S7>/K_p_angle (rad//s // rad)'
   *  Gain: '<S7>/Scale'
   *  Gain: '<S7>/Scale1'
   *  Sum: '<S7>/Sum'
   */
  rtb_Integrator2_idx_0 = (rtb_Integrator2_idx_0 -
    QD2_DroneStack_PID_2021a_P.Gain1_Gain[1] *
    QD2_DroneStack_PID_2021a_B.Product3[1]) *
    QD2_DroneStack_PID_2021a_P.K_p_angleradsrad_Gain[1] *
    QD2_DroneStack_PID_2021a_P.Scale_Gain[1] -
    QD2_DroneStack_PID_2021a_P.K_d_angleradsrads_Gain[1] *
    QD2_DroneStack_PID_2021a_B.Product3[4] *
    QD2_DroneStack_PID_2021a_P.Scale1_Gain[1];
  rtb_Sum1_c_idx_1 = rtb_Integrator2_idx_0;

  /* Saturate: '<S7>/Saturation Max Rate  (rad//s)' */
  if (rtb_Integrator2_idx_0 >
      QD2_DroneStack_PID_2021a_P.SaturationMaxRaterads_UpperSat[1]) {
    rtb_Integrator2_idx_0 =
      QD2_DroneStack_PID_2021a_P.SaturationMaxRaterads_UpperSat[1];
  } else if (rtb_Integrator2_idx_0 <
             QD2_DroneStack_PID_2021a_P.SaturationMaxRaterads_LowerSat[1]) {
    rtb_Integrator2_idx_0 =
      QD2_DroneStack_PID_2021a_P.SaturationMaxRaterads_LowerSat[1];
  }

  /* Sum: '<S7>/Sum6' incorporates:
   *  Gain: '<S7>/K_d_angle (rad//s // rad//s)'
   *  Gain: '<S7>/K_d_speed (Nm // rad//s//s)1'
   *  Gain: '<S7>/K_p_speed (Nm // rad//s)'
   *  Gain: '<S7>/Scale4'
   *  Gain: '<S7>/Scale5'
   *  Saturate: '<S7>/Saturation Max Rate  (rad//s)'
   *  Sum: '<S7>/Sum5'
   */
  QD2_DroneStack_PID_2021a_B.Sum6[1] = ((rtb_Integrator2_idx_0 -
    QD2_DroneStack_PID_2021a_B.Product3[4]) *
    QD2_DroneStack_PID_2021a_P.K_p_speedNmrads_Gain[1] *
    QD2_DroneStack_PID_2021a_P.Scale5_Gain[1] +
    QD2_DroneStack_PID_2021a_B.AttitudeTorqueCommands[1]) -
    QD2_DroneStack_PID_2021a_P.K_d_speedNmradss1_Gain[1] *
    QD2_DroneStack_PID_2021a_B.Product3[7] *
    QD2_DroneStack_PID_2021a_P.Scale4_Gain[1];

  /* Saturate: '<S7>/Saturation Command  Authority (Nm)1' */
  if (QD2_DroneStack_PID_2021a_B.Sum6[1] >
      QD2_DroneStack_PID_2021a_P.SaturationCommandAuthorityNm1_U[1]) {
    /* Saturate: '<S7>/Saturation Command  Authority (Nm)1' */
    QD2_DroneStack_PID_2021a_B.SaturationCommandAuthorityNm1[1] =
      QD2_DroneStack_PID_2021a_P.SaturationCommandAuthorityNm1_U[1];
  } else if (QD2_DroneStack_PID_2021a_B.Sum6[1] <
             QD2_DroneStack_PID_2021a_P.SaturationCommandAuthorityNm1_L[1]) {
    /* Saturate: '<S7>/Saturation Command  Authority (Nm)1' */
    QD2_DroneStack_PID_2021a_B.SaturationCommandAuthorityNm1[1] =
      QD2_DroneStack_PID_2021a_P.SaturationCommandAuthorityNm1_L[1];
  } else {
    /* Saturate: '<S7>/Saturation Command  Authority (Nm)1' */
    QD2_DroneStack_PID_2021a_B.SaturationCommandAuthorityNm1[1] =
      QD2_DroneStack_PID_2021a_B.Sum6[1];
  }

  /* Saturate: '<S7>/Saturate Stabilization Command' */
  if (rtb_Sum1_c_idx_2 >
      QD2_DroneStack_PID_2021a_P.SaturateStabilizationCommand__o[2]) {
    /* Saturate: '<S7>/Saturate Stabilization Command' */
    rtb_Integrator2_idx_0 =
      QD2_DroneStack_PID_2021a_P.SaturateStabilizationCommand__o[2];
  } else if (rtb_Sum1_c_idx_2 <
             QD2_DroneStack_PID_2021a_P.SaturateStabilizationCommand__g[2]) {
    /* Saturate: '<S7>/Saturate Stabilization Command' */
    rtb_Integrator2_idx_0 =
      QD2_DroneStack_PID_2021a_P.SaturateStabilizationCommand__g[2];
  } else {
    /* Saturate: '<S7>/Saturate Stabilization Command' */
    rtb_Integrator2_idx_0 = rtb_Sum1_c_idx_2;
  }

  /* Saturate: '<S7>/Saturate Stabilization Command' */
  QD2_DroneStack_PID_2021a_B.AttitudeAngleCommands[2] = rtb_Integrator2_idx_0;

  /* Sum: '<S7>/Sum1' incorporates:
   *  Gain: '<S7>/Gain1'
   *  Gain: '<S7>/K_d_angle (rad//s // rad//s)'
   *  Gain: '<S7>/K_p_angle (rad//s // rad)'
   *  Gain: '<S7>/Scale'
   *  Gain: '<S7>/Scale1'
   *  Sum: '<S7>/Sum'
   */
  rtb_Integrator2_idx_0 = (rtb_Integrator2_idx_0 -
    QD2_DroneStack_PID_2021a_P.Gain1_Gain[2] *
    QD2_DroneStack_PID_2021a_B.Product3[2]) *
    QD2_DroneStack_PID_2021a_P.K_p_angleradsrad_Gain[2] *
    QD2_DroneStack_PID_2021a_P.Scale_Gain[2] -
    QD2_DroneStack_PID_2021a_P.K_d_angleradsrads_Gain[2] *
    QD2_DroneStack_PID_2021a_B.Product3[5] *
    QD2_DroneStack_PID_2021a_P.Scale1_Gain[2];

  /* Saturate: '<S7>/Saturation Max Rate  (rad//s)' */
  if (rtb_Integrator2_idx_0 >
      QD2_DroneStack_PID_2021a_P.SaturationMaxRaterads_UpperSat[2]) {
    rtb_Sum1_c_idx_2 =
      QD2_DroneStack_PID_2021a_P.SaturationMaxRaterads_UpperSat[2];
  } else if (rtb_Integrator2_idx_0 <
             QD2_DroneStack_PID_2021a_P.SaturationMaxRaterads_LowerSat[2]) {
    rtb_Sum1_c_idx_2 =
      QD2_DroneStack_PID_2021a_P.SaturationMaxRaterads_LowerSat[2];
  } else {
    rtb_Sum1_c_idx_2 = rtb_Integrator2_idx_0;
  }

  /* Sum: '<S7>/Sum6' incorporates:
   *  Gain: '<S7>/K_d_angle (rad//s // rad//s)'
   *  Gain: '<S7>/K_d_speed (Nm // rad//s//s)1'
   *  Gain: '<S7>/K_p_speed (Nm // rad//s)'
   *  Gain: '<S7>/Scale4'
   *  Gain: '<S7>/Scale5'
   *  Saturate: '<S7>/Saturation Max Rate  (rad//s)'
   *  Sum: '<S7>/Sum5'
   */
  QD2_DroneStack_PID_2021a_B.Sum6[2] = ((rtb_Sum1_c_idx_2 -
    QD2_DroneStack_PID_2021a_B.Product3[5]) *
    QD2_DroneStack_PID_2021a_P.K_p_speedNmrads_Gain[2] *
    QD2_DroneStack_PID_2021a_P.Scale5_Gain[2] +
    QD2_DroneStack_PID_2021a_B.AttitudeTorqueCommands[2]) -
    QD2_DroneStack_PID_2021a_P.K_d_speedNmradss1_Gain[2] *
    QD2_DroneStack_PID_2021a_B.Product3[8] *
    QD2_DroneStack_PID_2021a_P.Scale4_Gain[2];

  /* Saturate: '<S7>/Saturation Command  Authority (Nm)1' */
  if (QD2_DroneStack_PID_2021a_B.Sum6[2] >
      QD2_DroneStack_PID_2021a_P.SaturationCommandAuthorityNm1_U[2]) {
    /* Saturate: '<S7>/Saturation Command  Authority (Nm)1' */
    QD2_DroneStack_PID_2021a_B.SaturationCommandAuthorityNm1[2] =
      QD2_DroneStack_PID_2021a_P.SaturationCommandAuthorityNm1_U[2];
  } else if (QD2_DroneStack_PID_2021a_B.Sum6[2] <
             QD2_DroneStack_PID_2021a_P.SaturationCommandAuthorityNm1_L[2]) {
    /* Saturate: '<S7>/Saturation Command  Authority (Nm)1' */
    QD2_DroneStack_PID_2021a_B.SaturationCommandAuthorityNm1[2] =
      QD2_DroneStack_PID_2021a_P.SaturationCommandAuthorityNm1_L[2];
  } else {
    /* Saturate: '<S7>/Saturation Command  Authority (Nm)1' */
    QD2_DroneStack_PID_2021a_B.SaturationCommandAuthorityNm1[2] =
      QD2_DroneStack_PID_2021a_B.Sum6[2];
  }

  if (rtb_Compare_f) {
    /* Delay: '<S7>/Delay' */
    QD2_DroneStack_PID_2021a_B.Delay = QD2_DroneStack_PID_2021a_DW.Delay_DSTATE
      [0];
  }

  /* MATLAB Function: '<S5>/Force to percentage Mapping' incorporates:
   *  Constant: '<S5>/Constant3'
   */
  QD2_DroneStack_PID_2021a_DW.sfEvent_n = QD2_DroneStack_PID_2_CALL_EVENT;

  /* MATLAB Function 'QDrone 2 DAQ/Force to percentage Mapping': '<S74>:1' */
  /* '<S74>:1:3' */
  rtb_DataTypeConversion3 = QD2_DroneStack_PID_2021a_P.KT[1] *
    QD2_DroneStack_PID_2021a_P.KT[1];
  data_loss = 4.0 * QD2_DroneStack_PID_2021a_P.KT[0];
  rtb_Sum1_c_idx_2 = QD2_DroneStack_PID_2021a_P.KT[2];

  /* Product: '<S7>/Product' */
  rtb_Sum1_j_idx_1 = QD2_DroneStack_PID_2021a_B.NetThrottle *
    QD2_DroneStack_PID_2021a_B.Delay;
  tmp_0 = QD2_DroneStack_PID_2021a_B.SaturationCommandAuthorityNm1[0] *
    QD2_DroneStack_PID_2021a_B.Delay;
  tmp_1 = QD2_DroneStack_PID_2021a_B.SaturationCommandAuthorityNm1[1] *
    QD2_DroneStack_PID_2021a_B.Delay;
  tmp = QD2_DroneStack_PID_2021a_B.SaturationCommandAuthorityNm1[2] *
    QD2_DroneStack_PID_2021a_B.Delay;

  /* MATLAB Function: '<S5>/Force to percentage Mapping' incorporates:
   *  Constant: '<S5>/Constant2'
   *  Product: '<S5>/Product5'
   */
  /* '<S74>:1:5' */
  /* '<S74>:1:6' */
  for (i = 0; i < 4; i++) {
    Duty_Cycle_0 = rtb_DataTypeConversion3 - (rtb_Sum1_c_idx_2 -
      (((QD2_DroneStack_PID_2021a_P.Motor_Matrix[i + 4] * tmp_0 +
         QD2_DroneStack_PID_2021a_P.Motor_Matrix[i] * rtb_Sum1_j_idx_1) +
        QD2_DroneStack_PID_2021a_P.Motor_Matrix[i + 8] * tmp_1) +
       QD2_DroneStack_PID_2021a_P.Motor_Matrix[i + 12] * tmp)) * data_loss;
    Duty_Cycle[i] = Duty_Cycle_0;
    if (Duty_Cycle_0 < 0.0) {
      Duty_Cycle[i] = 0.0;
    }
  }

  /* ManualSwitch: '<S5>/Manual Switch -   Select Command Input' incorporates:
   *  Constant: '<Root>/Zero Reference Motor Commands'
   *  Constant: '<S5>/Constant3'
   *  MATLAB Function: '<S5>/Force to percentage Mapping'
   */
  /* '<S74>:1:9' */
  /* '<S74>:1:11' */
  if (QD2_DroneStack_PID_2021a_P.ManualSwitchSelectCommandInput_ == 1) {
    rtb_Sum1_c_idx_2 = (-0.5 * QD2_DroneStack_PID_2021a_P.KT[1] /
                        QD2_DroneStack_PID_2021a_P.KT[0] + sqrt(Duty_Cycle[0]) /
                        (2.0 * QD2_DroneStack_PID_2021a_P.KT[0])) /
      QD2_DroneStack_PID_2021a_B.HILRead_o1[0];
  } else {
    rtb_Sum1_c_idx_2 =
      QD2_DroneStack_PID_2021a_P.ZeroReferenceMotorCommands_Valu[0];
  }

  /* Saturate: '<S5>/Maximum  Command Authority ' incorporates:
   *  ManualSwitch: '<S5>/Manual Switch -   Select Command Input'
   */
  if (rtb_Sum1_c_idx_2 >
      QD2_DroneStack_PID_2021a_P.MaximumCommandAuthority_UpperSa[0]) {
    /* Saturate: '<S5>/Maximum  Command Authority ' */
    QD2_DroneStack_PID_2021a_B.MaximumCommandAuthority[0] =
      QD2_DroneStack_PID_2021a_P.MaximumCommandAuthority_UpperSa[0];
  } else if (rtb_Sum1_c_idx_2 <
             QD2_DroneStack_PID_2021a_P.MaximumCommandAuthority_LowerSa[0]) {
    /* Saturate: '<S5>/Maximum  Command Authority ' */
    QD2_DroneStack_PID_2021a_B.MaximumCommandAuthority[0] =
      QD2_DroneStack_PID_2021a_P.MaximumCommandAuthority_LowerSa[0];
  } else {
    /* Saturate: '<S5>/Maximum  Command Authority ' */
    QD2_DroneStack_PID_2021a_B.MaximumCommandAuthority[0] = rtb_Sum1_c_idx_2;
  }

  /* ManualSwitch: '<S5>/Manual Switch -   Select Command Input' incorporates:
   *  Constant: '<Root>/Zero Reference Motor Commands'
   *  Constant: '<S5>/Constant3'
   *  MATLAB Function: '<S5>/Force to percentage Mapping'
   */
  if (QD2_DroneStack_PID_2021a_P.ManualSwitchSelectCommandInput_ == 1) {
    rtb_Sum1_c_idx_2 = (-0.5 * QD2_DroneStack_PID_2021a_P.KT[1] /
                        QD2_DroneStack_PID_2021a_P.KT[0] + sqrt(Duty_Cycle[1]) /
                        (2.0 * QD2_DroneStack_PID_2021a_P.KT[0])) /
      QD2_DroneStack_PID_2021a_B.HILRead_o1[0];
  } else {
    rtb_Sum1_c_idx_2 =
      QD2_DroneStack_PID_2021a_P.ZeroReferenceMotorCommands_Valu[1];
  }

  /* Saturate: '<S5>/Maximum  Command Authority ' incorporates:
   *  ManualSwitch: '<S5>/Manual Switch -   Select Command Input'
   */
  if (rtb_Sum1_c_idx_2 >
      QD2_DroneStack_PID_2021a_P.MaximumCommandAuthority_UpperSa[1]) {
    /* Saturate: '<S5>/Maximum  Command Authority ' */
    QD2_DroneStack_PID_2021a_B.MaximumCommandAuthority[1] =
      QD2_DroneStack_PID_2021a_P.MaximumCommandAuthority_UpperSa[1];
  } else if (rtb_Sum1_c_idx_2 <
             QD2_DroneStack_PID_2021a_P.MaximumCommandAuthority_LowerSa[1]) {
    /* Saturate: '<S5>/Maximum  Command Authority ' */
    QD2_DroneStack_PID_2021a_B.MaximumCommandAuthority[1] =
      QD2_DroneStack_PID_2021a_P.MaximumCommandAuthority_LowerSa[1];
  } else {
    /* Saturate: '<S5>/Maximum  Command Authority ' */
    QD2_DroneStack_PID_2021a_B.MaximumCommandAuthority[1] = rtb_Sum1_c_idx_2;
  }

  /* ManualSwitch: '<S5>/Manual Switch -   Select Command Input' incorporates:
   *  Constant: '<Root>/Zero Reference Motor Commands'
   *  Constant: '<S5>/Constant3'
   *  MATLAB Function: '<S5>/Force to percentage Mapping'
   */
  if (QD2_DroneStack_PID_2021a_P.ManualSwitchSelectCommandInput_ == 1) {
    rtb_Sum1_c_idx_2 = (-0.5 * QD2_DroneStack_PID_2021a_P.KT[1] /
                        QD2_DroneStack_PID_2021a_P.KT[0] + sqrt(Duty_Cycle[2]) /
                        (2.0 * QD2_DroneStack_PID_2021a_P.KT[0])) /
      QD2_DroneStack_PID_2021a_B.HILRead_o1[0];
  } else {
    rtb_Sum1_c_idx_2 =
      QD2_DroneStack_PID_2021a_P.ZeroReferenceMotorCommands_Valu[2];
  }

  /* Saturate: '<S5>/Maximum  Command Authority ' incorporates:
   *  ManualSwitch: '<S5>/Manual Switch -   Select Command Input'
   */
  if (rtb_Sum1_c_idx_2 >
      QD2_DroneStack_PID_2021a_P.MaximumCommandAuthority_UpperSa[2]) {
    /* Saturate: '<S5>/Maximum  Command Authority ' */
    QD2_DroneStack_PID_2021a_B.MaximumCommandAuthority[2] =
      QD2_DroneStack_PID_2021a_P.MaximumCommandAuthority_UpperSa[2];
  } else if (rtb_Sum1_c_idx_2 <
             QD2_DroneStack_PID_2021a_P.MaximumCommandAuthority_LowerSa[2]) {
    /* Saturate: '<S5>/Maximum  Command Authority ' */
    QD2_DroneStack_PID_2021a_B.MaximumCommandAuthority[2] =
      QD2_DroneStack_PID_2021a_P.MaximumCommandAuthority_LowerSa[2];
  } else {
    /* Saturate: '<S5>/Maximum  Command Authority ' */
    QD2_DroneStack_PID_2021a_B.MaximumCommandAuthority[2] = rtb_Sum1_c_idx_2;
  }

  /* ManualSwitch: '<S5>/Manual Switch -   Select Command Input' incorporates:
   *  Constant: '<Root>/Zero Reference Motor Commands'
   *  Constant: '<S5>/Constant3'
   *  MATLAB Function: '<S5>/Force to percentage Mapping'
   */
  if (QD2_DroneStack_PID_2021a_P.ManualSwitchSelectCommandInput_ == 1) {
    rtb_Sum1_c_idx_2 = (-0.5 * QD2_DroneStack_PID_2021a_P.KT[1] /
                        QD2_DroneStack_PID_2021a_P.KT[0] + sqrt(Duty_Cycle[3]) /
                        (2.0 * QD2_DroneStack_PID_2021a_P.KT[0])) /
      QD2_DroneStack_PID_2021a_B.HILRead_o1[0];
  } else {
    rtb_Sum1_c_idx_2 =
      QD2_DroneStack_PID_2021a_P.ZeroReferenceMotorCommands_Valu[3];
  }

  /* Saturate: '<S5>/Maximum  Command Authority ' incorporates:
   *  ManualSwitch: '<S5>/Manual Switch -   Select Command Input'
   */
  if (rtb_Sum1_c_idx_2 >
      QD2_DroneStack_PID_2021a_P.MaximumCommandAuthority_UpperSa[3]) {
    /* Saturate: '<S5>/Maximum  Command Authority ' */
    QD2_DroneStack_PID_2021a_B.MaximumCommandAuthority[3] =
      QD2_DroneStack_PID_2021a_P.MaximumCommandAuthority_UpperSa[3];
  } else if (rtb_Sum1_c_idx_2 <
             QD2_DroneStack_PID_2021a_P.MaximumCommandAuthority_LowerSa[3]) {
    /* Saturate: '<S5>/Maximum  Command Authority ' */
    QD2_DroneStack_PID_2021a_B.MaximumCommandAuthority[3] =
      QD2_DroneStack_PID_2021a_P.MaximumCommandAuthority_LowerSa[3];
  } else {
    /* Saturate: '<S5>/Maximum  Command Authority ' */
    QD2_DroneStack_PID_2021a_B.MaximumCommandAuthority[3] = rtb_Sum1_c_idx_2;
  }

  if (rtb_Compare_f) {
    /* MATLAB Function: '<S64>/MATLAB Function' incorporates:
     *  Constant: '<S64>/Constant2'
     */
    QD2_DroneStack_PID_2021a_DW.sfEvent_nd = QD2_DroneStack_PID_2_CALL_EVENT;

    /* MATLAB Function 'QDrone 2 DAQ/Choose Motor Telemetry/MATLAB Function': '<S86>:1' */
    /* '<S86>:1:11' */
    rtb_DataTypeConversion3 = QD2_DroneStack_PID_2021a_DW.state;
    if (QD2_DroneStack_PID_2021a_B.tele_enable != 0.0) {
      /* '<S86>:1:15' */
      QD2_DroneStack_PID_2021a_DW.state++;
      if (QD2_DroneStack_PID_2021a_DW.state >=
          QD2_DroneStack_PID_2021a_P.Constant2_Value_e) {
        /* '<S86>:1:17' */
        /* '<S86>:1:18' */
        QD2_DroneStack_PID_2021a_DW.state = 0.0;
      }
    } else {
      /* '<S86>:1:22' */
      QD2_DroneStack_PID_2021a_DW.state = 0.0;

      /* '<S86>:1:23' */
      rtb_DataTypeConversion3 = 0.0;
    }

    /* End of MATLAB Function: '<S64>/MATLAB Function' */

    /* Selector: '<S64>/Selector' incorporates:
     *  Constant: '<S64>/Constant1'
     */
    QD2_DroneStack_PID_2021a_B.Selector[0] =
      QD2_DroneStack_PID_2021a_P.Constant1_Value_c[(int32_T)
      rtb_DataTypeConversion3];

    /* DataTypeConversion: '<S5>/Data Type Conversion1' */
    rtb_Sum1_c_idx_2 = floor(QD2_DroneStack_PID_2021a_B.cmd[0]);
    if (rtIsNaN(rtb_Sum1_c_idx_2) || rtIsInf(rtb_Sum1_c_idx_2)) {
      rtb_Sum1_c_idx_2 = 0.0;
    } else {
      rtb_Sum1_c_idx_2 = fmod(rtb_Sum1_c_idx_2, 65536.0);
    }

    rtb_DataTypeConversion1[0] = (uint16_T)(rtb_Sum1_c_idx_2 < 0.0 ? (int32_T)
      (uint16_T)-(int16_T)(uint16_T)-rtb_Sum1_c_idx_2 : (int32_T)(uint16_T)
      rtb_Sum1_c_idx_2);

    /* Selector: '<S64>/Selector' incorporates:
     *  Constant: '<S64>/Constant1'
     */
    QD2_DroneStack_PID_2021a_B.Selector[1] =
      QD2_DroneStack_PID_2021a_P.Constant1_Value_c[(int32_T)
      rtb_DataTypeConversion3 + 8];

    /* DataTypeConversion: '<S5>/Data Type Conversion1' */
    rtb_Sum1_c_idx_2 = floor(QD2_DroneStack_PID_2021a_B.cmd[1]);
    if (rtIsNaN(rtb_Sum1_c_idx_2) || rtIsInf(rtb_Sum1_c_idx_2)) {
      rtb_Sum1_c_idx_2 = 0.0;
    } else {
      rtb_Sum1_c_idx_2 = fmod(rtb_Sum1_c_idx_2, 65536.0);
    }

    rtb_DataTypeConversion1[1] = (uint16_T)(rtb_Sum1_c_idx_2 < 0.0 ? (int32_T)
      (uint16_T)-(int16_T)(uint16_T)-rtb_Sum1_c_idx_2 : (int32_T)(uint16_T)
      rtb_Sum1_c_idx_2);

    /* Selector: '<S64>/Selector' incorporates:
     *  Constant: '<S64>/Constant1'
     */
    QD2_DroneStack_PID_2021a_B.Selector[2] =
      QD2_DroneStack_PID_2021a_P.Constant1_Value_c[(int32_T)
      rtb_DataTypeConversion3 + 16];

    /* DataTypeConversion: '<S5>/Data Type Conversion1' */
    rtb_Sum1_c_idx_2 = floor(QD2_DroneStack_PID_2021a_B.cmd[2]);
    if (rtIsNaN(rtb_Sum1_c_idx_2) || rtIsInf(rtb_Sum1_c_idx_2)) {
      rtb_Sum1_c_idx_2 = 0.0;
    } else {
      rtb_Sum1_c_idx_2 = fmod(rtb_Sum1_c_idx_2, 65536.0);
    }

    rtb_DataTypeConversion1[2] = (uint16_T)(rtb_Sum1_c_idx_2 < 0.0 ? (int32_T)
      (uint16_T)-(int16_T)(uint16_T)-rtb_Sum1_c_idx_2 : (int32_T)(uint16_T)
      rtb_Sum1_c_idx_2);

    /* Selector: '<S64>/Selector' incorporates:
     *  Constant: '<S64>/Constant1'
     */
    QD2_DroneStack_PID_2021a_B.Selector[3] =
      QD2_DroneStack_PID_2021a_P.Constant1_Value_c[(int32_T)
      rtb_DataTypeConversion3 + 24];

    /* DataTypeConversion: '<S5>/Data Type Conversion1' */
    rtb_Sum1_c_idx_2 = floor(QD2_DroneStack_PID_2021a_B.cmd[3]);
    if (rtIsNaN(rtb_Sum1_c_idx_2) || rtIsInf(rtb_Sum1_c_idx_2)) {
      rtb_Sum1_c_idx_2 = 0.0;
    } else {
      rtb_Sum1_c_idx_2 = fmod(rtb_Sum1_c_idx_2, 65536.0);
    }

    rtb_DataTypeConversion1[3] = (uint16_T)(rtb_Sum1_c_idx_2 < 0.0 ? (int32_T)
      (uint16_T)-(int16_T)(uint16_T)-rtb_Sum1_c_idx_2 : (int32_T)(uint16_T)
      rtb_Sum1_c_idx_2);

    /* S-Function (esc_output_block): '<S5>/ESC Output' */

    /* S-Function Block: QD2_DroneStack_PID_2021a/QDrone 2 DAQ/ESC Output (esc_output_block) */
    {
      t_double saturated_input;
      t_uint16 throttle;
      t_uint16 checksum;
      saturated_input = QD2_DroneStack_PID_2021a_B.MaximumCommandAuthority[0];
      if (saturated_input < 0) {
        saturated_input = 0;
      } else if (saturated_input > 1) {
        saturated_input = 1;
      }

      if (rtb_DataTypeConversion1[0] < 0 || rtb_DataTypeConversion1[0] > 47) {
        throttle = (t_uint16)(48 + saturated_input * 1999);
      } else {
        throttle = (t_uint16) rtb_DataTypeConversion1[0];
      }

      throttle = (throttle << 1) | (QD2_DroneStack_PID_2021a_B.Selector[0] != 0);
      checksum = throttle ^ (throttle >> 4) ^ (throttle >> 8);
      rtb_ESCOutput[0] = (throttle << 4) | (checksum & 0x0f);
      saturated_input = QD2_DroneStack_PID_2021a_B.MaximumCommandAuthority[1];
      if (saturated_input < 0) {
        saturated_input = 0;
      } else if (saturated_input > 1) {
        saturated_input = 1;
      }

      if (rtb_DataTypeConversion1[1] < 0 || rtb_DataTypeConversion1[1] > 47) {
        throttle = (t_uint16)(48 + saturated_input * 1999);
      } else {
        throttle = (t_uint16) rtb_DataTypeConversion1[1];
      }

      throttle = (throttle << 1) | (QD2_DroneStack_PID_2021a_B.Selector[1] != 0);
      checksum = throttle ^ (throttle >> 4) ^ (throttle >> 8);
      rtb_ESCOutput[1] = (throttle << 4) | (checksum & 0x0f);
      saturated_input = QD2_DroneStack_PID_2021a_B.MaximumCommandAuthority[2];
      if (saturated_input < 0) {
        saturated_input = 0;
      } else if (saturated_input > 1) {
        saturated_input = 1;
      }

      if (rtb_DataTypeConversion1[2] < 0 || rtb_DataTypeConversion1[2] > 47) {
        throttle = (t_uint16)(48 + saturated_input * 1999);
      } else {
        throttle = (t_uint16) rtb_DataTypeConversion1[2];
      }

      throttle = (throttle << 1) | (QD2_DroneStack_PID_2021a_B.Selector[2] != 0);
      checksum = throttle ^ (throttle >> 4) ^ (throttle >> 8);
      rtb_ESCOutput[2] = (throttle << 4) | (checksum & 0x0f);
      saturated_input = QD2_DroneStack_PID_2021a_B.MaximumCommandAuthority[3];
      if (saturated_input < 0) {
        saturated_input = 0;
      } else if (saturated_input > 1) {
        saturated_input = 1;
      }

      if (rtb_DataTypeConversion1[3] < 0 || rtb_DataTypeConversion1[3] > 47) {
        throttle = (t_uint16)(48 + saturated_input * 1999);
      } else {
        throttle = (t_uint16) rtb_DataTypeConversion1[3];
      }

      throttle = (throttle << 1) | (QD2_DroneStack_PID_2021a_B.Selector[3] != 0);
      checksum = throttle ^ (throttle >> 4) ^ (throttle >> 8);
      rtb_ESCOutput[3] = (throttle << 4) | (checksum & 0x0f);
    }

    /* Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem -  Write ESC Commands' incorporates:
     *  EnablePort: '<S73>/Enable'
     */
    if (QD2_DroneStack_PID_2021a_B.cmd_enable > 0.0) {
      /* S-Function (hil_write_pwm_block): '<S73>/HIL Write PWM' */

      /* S-Function Block: QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Enabled Subsystem -  Write ESC Commands/HIL Write PWM (hil_write_pwm_block) */
      {
        t_error result;
        result = hil_write_pwm(QD2_DroneStack_PID_2021a_DW.HILInitialize_Card,
          QD2_DroneStack_PID_2021a_P.HILWritePWM_channels, 4, &rtb_ESCOutput[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M, _rt_error_message);
        }
      }

      if (rtsiIsModeUpdateTimeStep(&QD2_DroneStack_PID_2021a_M->solverInfo)) {
        srUpdateBC(QD2_DroneStack_PID_2021a_DW.EnabledSubsystemWriteESCCommand);
      }
    }

    /* End of Outputs for SubSystem: '<S5>/Enabled Subsystem -  Write ESC Commands' */

    /* MultiPortSwitch: '<S75>/Multiport Switch' incorporates:
     *  Constant: '<S75>/Blue Blue'
     *  Constant: '<S75>/Green Green'
     *  Constant: '<S75>/LED OFF'
     *  Constant: '<S75>/Red Blue'
     *  Constant: '<S75>/Red Red'
     *  Constant: '<S75>/Red Yellow'
     *  Constant: '<S75>/Yellow Blue'
     *  Constant: '<S75>/Yellow Green'
     *  Constant: '<S75>/Yellow Red'
     *  Constant: '<S75>/Yellow Yellow'
     */
    switch ((int32_T)QD2_DroneStack_PID_2021a_B.DataTypeConversion) {
     case 0:
      for (i = 0; i < 6; i++) {
        rtb_MultiportSwitch[i] = QD2_DroneStack_PID_2021a_P.YellowYellow_Value[i];
      }
      break;

     case 1:
      for (i = 0; i < 6; i++) {
        rtb_MultiportSwitch[i] = QD2_DroneStack_PID_2021a_P.YellowGreen_Value[i];
      }
      break;

     case 2:
      for (i = 0; i < 6; i++) {
        rtb_MultiportSwitch[i] = QD2_DroneStack_PID_2021a_P.BlueBlue_Value[i];
      }
      break;

     case 3:
      for (i = 0; i < 6; i++) {
        rtb_MultiportSwitch[i] = QD2_DroneStack_PID_2021a_P.YellowRed_Value[i];
      }
      break;

     case 4:
      for (i = 0; i < 6; i++) {
        rtb_MultiportSwitch[i] = QD2_DroneStack_PID_2021a_P.RedYellow_Value[i];
      }
      break;

     case 5:
      for (i = 0; i < 6; i++) {
        rtb_MultiportSwitch[i] = QD2_DroneStack_PID_2021a_P.GreenGreen_Value[i];
      }
      break;

     case 77:
      for (i = 0; i < 6; i++) {
        rtb_MultiportSwitch[i] = QD2_DroneStack_PID_2021a_P.YellowBlue_Value[i];
      }
      break;

     case 88:
      for (i = 0; i < 6; i++) {
        rtb_MultiportSwitch[i] = QD2_DroneStack_PID_2021a_P.RedBlue_Value[i];
      }
      break;

     case 99:
      for (i = 0; i < 6; i++) {
        rtb_MultiportSwitch[i] = QD2_DroneStack_PID_2021a_P.RedRed_Value[i];
      }
      break;

     default:
      for (i = 0; i < 6; i++) {
        rtb_MultiportSwitch[i] = QD2_DroneStack_PID_2021a_P.LEDOFF_Value[i];
      }
      break;
    }

    /* End of MultiPortSwitch: '<S75>/Multiport Switch' */

    /* S-Function (hil_write_digital_block): '<S5>/HIL Write Digital' */

    /* S-Function Block: QD2_DroneStack_PID_2021a/QDrone 2 DAQ/HIL Write Digital (hil_write_digital_block) */
    {
      t_error result;

      {
        int_T i1;
        const real_T *u0 = &rtb_MultiportSwitch[0];
        t_boolean *dw_Buffer =
          &QD2_DroneStack_PID_2021a_DW.HILWriteDigital_Buffer[0];
        for (i1=0; i1 < 6; i1++) {
          dw_Buffer[i1] = (u0[i1] != 0);
        }
      }

      result = hil_write_digital(QD2_DroneStack_PID_2021a_DW.HILInitialize_Card,
        QD2_DroneStack_PID_2021a_P.HILWriteDigital_channels, 6,
        &QD2_DroneStack_PID_2021a_DW.HILWriteDigital_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M, _rt_error_message);
      }
    }

    /* RateTransition: '<S5>/Rate Transition7' */
    if (QD2_DroneStack_PID_2021a_M->Timing.RateInteraction.TID1_3) {
      /* RateTransition: '<S5>/Rate Transition7' */
      QD2_DroneStack_PID_2021a_B.RateTransition7[0] =
        QD2_DroneStack_PID_2021a_DW.RateTransition7_Buffer0[0];
      QD2_DroneStack_PID_2021a_B.RateTransition7[1] =
        QD2_DroneStack_PID_2021a_DW.RateTransition7_Buffer0[1];
    }

    /* End of RateTransition: '<S5>/Rate Transition7' */

    /* RateTransition: '<S5>/Rate Transition2' incorporates:
     *  RateTransition: '<S5>/Rate Transition1'
     */
    if (QD2_DroneStack_PID_2021a_M->Timing.RateInteraction.TID1_4) {
      /* RateTransition: '<S5>/Rate Transition2' */
      QD2_DroneStack_PID_2021a_B.RateTransition2 =
        QD2_DroneStack_PID_2021a_DW.RateTransition2_Buffer0;

      /* RateTransition: '<S5>/Rate Transition1' */
      QD2_DroneStack_PID_2021a_B.RateTransition1 =
        QD2_DroneStack_PID_2021a_DW.RateTransition1_Buffer0;
    }

    /* End of RateTransition: '<S5>/Rate Transition2' */

    /* Gain: '<S5>/Divide by half of the number of poles in motor' */
    rtb_DataTypeConversion3 =
      QD2_DroneStack_PID_2021a_P.Dividebyhalfofthenumberofpolesi *
      QD2_DroneStack_PID_2021a_B.HILRead_o2[19];

    /* Gain: '<S5>/Multiple by resolution (supposed to be 100 RPM)' */
    rtb_DataTypeConversion3 *=
      QD2_DroneStack_PID_2021a_P.Multiplebyresolutionsupposedtob;

    /* MultiPortSwitch: '<S5>/Extract ESC Channels' */
    switch ((int32_T)QD2_DroneStack_PID_2021a_B.HILRead_o2[21]) {
     case 0:
      /* MultiPortSwitch: '<S5>/Extract ESC Channels' incorporates:
       *  Constant: '<S5>/Motor 0'
       */
      QD2_DroneStack_PID_2021a_B.ExtractESCChannels[0] =
        QD2_DroneStack_PID_2021a_P.Motor0_Value[0];
      QD2_DroneStack_PID_2021a_B.ExtractESCChannels[1] =
        QD2_DroneStack_PID_2021a_P.Motor0_Value[1];
      QD2_DroneStack_PID_2021a_B.ExtractESCChannels[2] =
        QD2_DroneStack_PID_2021a_P.Motor0_Value[2];
      QD2_DroneStack_PID_2021a_B.ExtractESCChannels[3] =
        QD2_DroneStack_PID_2021a_P.Motor0_Value[3];
      break;

     case 1:
      /* MultiPortSwitch: '<S5>/Extract ESC Channels' incorporates:
       *  Constant: '<S5>/Motor 1'
       */
      QD2_DroneStack_PID_2021a_B.ExtractESCChannels[0] =
        QD2_DroneStack_PID_2021a_P.Motor1_Value[0];
      QD2_DroneStack_PID_2021a_B.ExtractESCChannels[1] =
        QD2_DroneStack_PID_2021a_P.Motor1_Value[1];
      QD2_DroneStack_PID_2021a_B.ExtractESCChannels[2] =
        QD2_DroneStack_PID_2021a_P.Motor1_Value[2];
      QD2_DroneStack_PID_2021a_B.ExtractESCChannels[3] =
        QD2_DroneStack_PID_2021a_P.Motor1_Value[3];
      break;

     case 2:
      /* MultiPortSwitch: '<S5>/Extract ESC Channels' incorporates:
       *  Constant: '<S5>/Motor 2'
       */
      QD2_DroneStack_PID_2021a_B.ExtractESCChannels[0] =
        QD2_DroneStack_PID_2021a_P.Motor2_Value[0];
      QD2_DroneStack_PID_2021a_B.ExtractESCChannels[1] =
        QD2_DroneStack_PID_2021a_P.Motor2_Value[1];
      QD2_DroneStack_PID_2021a_B.ExtractESCChannels[2] =
        QD2_DroneStack_PID_2021a_P.Motor2_Value[2];
      QD2_DroneStack_PID_2021a_B.ExtractESCChannels[3] =
        QD2_DroneStack_PID_2021a_P.Motor2_Value[3];
      break;

     case 3:
      /* MultiPortSwitch: '<S5>/Extract ESC Channels' incorporates:
       *  Constant: '<S5>/Motor 3'
       */
      QD2_DroneStack_PID_2021a_B.ExtractESCChannels[0] =
        QD2_DroneStack_PID_2021a_P.Motor3_Value[0];
      QD2_DroneStack_PID_2021a_B.ExtractESCChannels[1] =
        QD2_DroneStack_PID_2021a_P.Motor3_Value[1];
      QD2_DroneStack_PID_2021a_B.ExtractESCChannels[2] =
        QD2_DroneStack_PID_2021a_P.Motor3_Value[2];
      QD2_DroneStack_PID_2021a_B.ExtractESCChannels[3] =
        QD2_DroneStack_PID_2021a_P.Motor3_Value[3];
      break;

     default:
      /* MultiPortSwitch: '<S5>/Extract ESC Channels' incorporates:
       *  Constant: '<S5>/No selection'
       */
      QD2_DroneStack_PID_2021a_B.ExtractESCChannels[0] =
        QD2_DroneStack_PID_2021a_P.Noselection_Value[0];
      QD2_DroneStack_PID_2021a_B.ExtractESCChannels[1] =
        QD2_DroneStack_PID_2021a_P.Noselection_Value[1];
      QD2_DroneStack_PID_2021a_B.ExtractESCChannels[2] =
        QD2_DroneStack_PID_2021a_P.Noselection_Value[2];
      QD2_DroneStack_PID_2021a_B.ExtractESCChannels[3] =
        QD2_DroneStack_PID_2021a_P.Noselection_Value[3];
      break;
    }

    /* End of MultiPortSwitch: '<S5>/Extract ESC Channels' */

    /* Product: '<S5>/Product' */
    rtb_Product[0] = rtb_DataTypeConversion3 *
      QD2_DroneStack_PID_2021a_B.ExtractESCChannels[0];

    /* Memory: '<S67>/Memory' */
    rtb_Memory_e[0] = QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_a[0];

    /* Product: '<S5>/Product' */
    rtb_Product[1] = rtb_DataTypeConversion3 *
      QD2_DroneStack_PID_2021a_B.ExtractESCChannels[1];

    /* Memory: '<S67>/Memory' */
    rtb_Memory_e[1] = QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_a[1];

    /* Product: '<S5>/Product' */
    rtb_Product[2] = rtb_DataTypeConversion3 *
      QD2_DroneStack_PID_2021a_B.ExtractESCChannels[2];

    /* Memory: '<S67>/Memory' */
    rtb_Memory_e[2] = QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_a[2];

    /* Product: '<S5>/Product' */
    rtb_Product[3] = rtb_DataTypeConversion3 *
      QD2_DroneStack_PID_2021a_B.ExtractESCChannels[3];

    /* Memory: '<S67>/Memory' */
    rtb_Memory_e[3] = QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_a[3];

    /* Outputs for Iterator SubSystem: '<S67>/For Each Subsystem -  Construct ESC Signal' */
    ForEachSubsystemConstructES(4, rtb_Product,
      QD2_DroneStack_PID_2021a_B.HILRead_o2[21], rtb_Memory_e,
      QD2_DroneStack_PID_2021a_B.ImpAsg_InsertedFor_ESCDataOu_kc);

    /* End of Outputs for SubSystem: '<S67>/For Each Subsystem -  Construct ESC Signal' */

    /* Saturate: '<S5>/Saturation' */
    if (QD2_DroneStack_PID_2021a_B.HILRead_o2[20] >
        QD2_DroneStack_PID_2021a_P.Saturation_UpperSat) {
      rtb_DataTypeConversion3 = QD2_DroneStack_PID_2021a_P.Saturation_UpperSat;
    } else if (QD2_DroneStack_PID_2021a_B.HILRead_o2[20] <
               QD2_DroneStack_PID_2021a_P.Saturation_LowerSat) {
      rtb_DataTypeConversion3 = QD2_DroneStack_PID_2021a_P.Saturation_LowerSat;
    } else {
      rtb_DataTypeConversion3 = QD2_DroneStack_PID_2021a_B.HILRead_o2[20];
    }

    /* End of Saturate: '<S5>/Saturation' */

    /* Product: '<S5>/Product1' */
    rtb_Product1[0] = rtb_DataTypeConversion3 *
      QD2_DroneStack_PID_2021a_B.ExtractESCChannels[0];

    /* Memory: '<S69>/Memory' */
    rtb_Memory_i[0] = QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_as[0];

    /* Product: '<S5>/Product1' */
    rtb_Product1[1] = rtb_DataTypeConversion3 *
      QD2_DroneStack_PID_2021a_B.ExtractESCChannels[1];

    /* Memory: '<S69>/Memory' */
    rtb_Memory_i[1] = QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_as[1];

    /* Product: '<S5>/Product1' */
    rtb_Product1[2] = rtb_DataTypeConversion3 *
      QD2_DroneStack_PID_2021a_B.ExtractESCChannels[2];

    /* Memory: '<S69>/Memory' */
    rtb_Memory_i[2] = QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_as[2];

    /* Product: '<S5>/Product1' */
    rtb_Product1[3] = rtb_DataTypeConversion3 *
      QD2_DroneStack_PID_2021a_B.ExtractESCChannels[3];

    /* Memory: '<S69>/Memory' */
    rtb_Memory_i[3] = QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_as[3];

    /* Outputs for Iterator SubSystem: '<S69>/For Each Subsystem -  Construct ESC Signal' */
    ForEachSubsystemConstructES(4, rtb_Product1,
      QD2_DroneStack_PID_2021a_B.HILRead_o2[21], rtb_Memory_i,
      QD2_DroneStack_PID_2021a_B.ImpAsg_InsertedFor_ESCDataOut4_);

    /* End of Outputs for SubSystem: '<S69>/For Each Subsystem -  Construct ESC Signal' */

    /* S-Function (computation_time_block): '<S81>/Computation Time' */

    /* S-Function Block: QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Timing Monitors/Computation Time (computation_time_block) */
    {
      QD2_DroneStack_PID_2021a_B.ComputationTime =
        QD2_DroneStack_PID_2021a_DW.ComputationTime_ComputationTime.seconds +
        QD2_DroneStack_PID_2021a_DW.ComputationTime_ComputationTime.nanoseconds *
        1e-9;
    }

    /* S-Function (sample_time_block): '<S81>/Sample Time' */

    /* S-Function Block: QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Timing Monitors/Sample Time (sample_time_block) */
    {
      t_error result;
      t_timeout current_time;
      t_timeout time_difference;
      result = timeout_get_high_resolution_time(&current_time);
      if (result >= 0) {
        result = timeout_subtract(&time_difference, &current_time,
          &QD2_DroneStack_PID_2021a_DW.SampleTime_PreviousTime);
        QD2_DroneStack_PID_2021a_B.SampleTime = time_difference.seconds +
          time_difference.nanoseconds * 1e-9;
        memcpy(&QD2_DroneStack_PID_2021a_DW.SampleTime_PreviousTime,
               &current_time, sizeof(t_timeout));
      }

      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M, _rt_error_message);
        return;
      }
    }

    /* RateTransition: '<S81>/Rate Transition' incorporates:
     *  RateTransition: '<S81>/Rate Transition1'
     */
    if (QD2_DroneStack_PID_2021a_M->Timing.RateInteraction.TID1_3) {
      /* RateTransition: '<S81>/Rate Transition' */
      QD2_DroneStack_PID_2021a_B.RateTransition =
        QD2_DroneStack_PID_2021a_DW.RateTransition_Buffer0;

      /* RateTransition: '<S81>/Rate Transition1' */
      QD2_DroneStack_PID_2021a_B.RateTransition1_n =
        QD2_DroneStack_PID_2021a_DW.RateTransition1_Buffer0_m;
    }

    /* End of RateTransition: '<S81>/Rate Transition' */

    /* RateTransition: '<S81>/Rate Transition2' incorporates:
     *  RateTransition: '<S81>/Rate Transition3'
     */
    if (QD2_DroneStack_PID_2021a_M->Timing.RateInteraction.TID1_4) {
      /* RateTransition: '<S81>/Rate Transition2' */
      QD2_DroneStack_PID_2021a_B.RateTransition2_m =
        QD2_DroneStack_PID_2021a_DW.RateTransition2_Buffer0_m;

      /* RateTransition: '<S81>/Rate Transition3' */
      QD2_DroneStack_PID_2021a_B.RateTransition3 =
        QD2_DroneStack_PID_2021a_DW.RateTransition3_Buffer0;
    }

    /* End of RateTransition: '<S81>/Rate Transition2' */

    /* RateTransition: '<S5>/Rate Transition6' */
    memcpy(&QD2_DroneStack_PID_2021a_B.RateTransition6[0],
           &QD2_DroneStack_PID_2021a_B.SelectDataforIMU0[0], 9U * sizeof(real_T));
    memcpy(&QD2_DroneStack_PID_2021a_B.RateTransition6[9],
           &QD2_DroneStack_PID_2021a_B.SelectDataforIMU1[0], 9U * sizeof(real_T));
    QD2_DroneStack_PID_2021a_B.RateTransition6[18] =
      QD2_DroneStack_PID_2021a_B.MaximumCommandAuthority[0];
    QD2_DroneStack_PID_2021a_B.RateTransition6[19] =
      QD2_DroneStack_PID_2021a_B.MaximumCommandAuthority[1];
    QD2_DroneStack_PID_2021a_B.RateTransition6[20] =
      QD2_DroneStack_PID_2021a_B.MaximumCommandAuthority[2];
    QD2_DroneStack_PID_2021a_B.RateTransition6[21] =
      QD2_DroneStack_PID_2021a_B.MaximumCommandAuthority[3];
    QD2_DroneStack_PID_2021a_B.RateTransition6[22] =
      QD2_DroneStack_PID_2021a_B.HILRead_o1[0];
    QD2_DroneStack_PID_2021a_B.RateTransition6[23] =
      QD2_DroneStack_PID_2021a_B.HILRead_o1[1];
    QD2_DroneStack_PID_2021a_B.RateTransition6[24] =
      QD2_DroneStack_PID_2021a_B.HILRead_o1[2];
    memcpy(&QD2_DroneStack_PID_2021a_B.RateTransition6[25],
           &QD2_DroneStack_PID_2021a_B.HILRead_o2[0], 12U * sizeof(real_T));
    QD2_DroneStack_PID_2021a_B.RateTransition6[37] =
      QD2_DroneStack_PID_2021a_B.RateTransition7[0];
    QD2_DroneStack_PID_2021a_B.RateTransition6[38] =
      QD2_DroneStack_PID_2021a_B.RateTransition7[1];
    for (i = 0; i < 7; i++) {
      QD2_DroneStack_PID_2021a_B.RateTransition6[i + 39] =
        QD2_DroneStack_PID_2021a_B.HILRead_o2[i + 12];
    }

    QD2_DroneStack_PID_2021a_B.RateTransition6[46] =
      QD2_DroneStack_PID_2021a_B.RateTransition2;
    QD2_DroneStack_PID_2021a_B.RateTransition6[47] =
      QD2_DroneStack_PID_2021a_B.RateTransition1;

    /* Product: '<S5>/Divide' incorporates:
     *  Gain: '<S5>/Convert to equivalent voltage (based on motor Kv rating)'
     */
    rtb_Sum1_c_idx_2 =
      QD2_DroneStack_PID_2021a_P.Converttoequivalentvoltagebased *
      QD2_DroneStack_PID_2021a_B.ImpAsg_InsertedFor_ESCDataOu_kc[0] /
      QD2_DroneStack_PID_2021a_B.ImpAsg_InsertedFor_ESCDataOut4_[0];

    /* Saturate: '<S5>/Saturation1' */
    if (rtb_Sum1_c_idx_2 > QD2_DroneStack_PID_2021a_P.Saturation1_UpperSat) {
      /* RateTransition: '<S5>/Rate Transition6' */
      QD2_DroneStack_PID_2021a_B.RateTransition6[48] =
        QD2_DroneStack_PID_2021a_P.Saturation1_UpperSat;
    } else if (rtb_Sum1_c_idx_2 <
               QD2_DroneStack_PID_2021a_P.Saturation1_LowerSat) {
      /* RateTransition: '<S5>/Rate Transition6' */
      QD2_DroneStack_PID_2021a_B.RateTransition6[48] =
        QD2_DroneStack_PID_2021a_P.Saturation1_LowerSat;
    } else {
      /* RateTransition: '<S5>/Rate Transition6' */
      QD2_DroneStack_PID_2021a_B.RateTransition6[48] = rtb_Sum1_c_idx_2;
    }

    /* Product: '<S5>/Divide' incorporates:
     *  Gain: '<S5>/Convert to equivalent voltage (based on motor Kv rating)'
     */
    rtb_Sum1_c_idx_2 =
      QD2_DroneStack_PID_2021a_P.Converttoequivalentvoltagebased *
      QD2_DroneStack_PID_2021a_B.ImpAsg_InsertedFor_ESCDataOu_kc[1] /
      QD2_DroneStack_PID_2021a_B.ImpAsg_InsertedFor_ESCDataOut4_[1];

    /* Saturate: '<S5>/Saturation1' */
    if (rtb_Sum1_c_idx_2 > QD2_DroneStack_PID_2021a_P.Saturation1_UpperSat) {
      /* RateTransition: '<S5>/Rate Transition6' */
      QD2_DroneStack_PID_2021a_B.RateTransition6[49] =
        QD2_DroneStack_PID_2021a_P.Saturation1_UpperSat;
    } else if (rtb_Sum1_c_idx_2 <
               QD2_DroneStack_PID_2021a_P.Saturation1_LowerSat) {
      /* RateTransition: '<S5>/Rate Transition6' */
      QD2_DroneStack_PID_2021a_B.RateTransition6[49] =
        QD2_DroneStack_PID_2021a_P.Saturation1_LowerSat;
    } else {
      /* RateTransition: '<S5>/Rate Transition6' */
      QD2_DroneStack_PID_2021a_B.RateTransition6[49] = rtb_Sum1_c_idx_2;
    }

    /* Product: '<S5>/Divide' incorporates:
     *  Gain: '<S5>/Convert to equivalent voltage (based on motor Kv rating)'
     */
    rtb_Sum1_c_idx_2 =
      QD2_DroneStack_PID_2021a_P.Converttoequivalentvoltagebased *
      QD2_DroneStack_PID_2021a_B.ImpAsg_InsertedFor_ESCDataOu_kc[2] /
      QD2_DroneStack_PID_2021a_B.ImpAsg_InsertedFor_ESCDataOut4_[2];

    /* Saturate: '<S5>/Saturation1' */
    if (rtb_Sum1_c_idx_2 > QD2_DroneStack_PID_2021a_P.Saturation1_UpperSat) {
      /* RateTransition: '<S5>/Rate Transition6' */
      QD2_DroneStack_PID_2021a_B.RateTransition6[50] =
        QD2_DroneStack_PID_2021a_P.Saturation1_UpperSat;
    } else if (rtb_Sum1_c_idx_2 <
               QD2_DroneStack_PID_2021a_P.Saturation1_LowerSat) {
      /* RateTransition: '<S5>/Rate Transition6' */
      QD2_DroneStack_PID_2021a_B.RateTransition6[50] =
        QD2_DroneStack_PID_2021a_P.Saturation1_LowerSat;
    } else {
      /* RateTransition: '<S5>/Rate Transition6' */
      QD2_DroneStack_PID_2021a_B.RateTransition6[50] = rtb_Sum1_c_idx_2;
    }

    /* Product: '<S5>/Divide' incorporates:
     *  Gain: '<S5>/Convert to equivalent voltage (based on motor Kv rating)'
     */
    rtb_Sum1_c_idx_2 =
      QD2_DroneStack_PID_2021a_P.Converttoequivalentvoltagebased *
      QD2_DroneStack_PID_2021a_B.ImpAsg_InsertedFor_ESCDataOu_kc[3] /
      QD2_DroneStack_PID_2021a_B.ImpAsg_InsertedFor_ESCDataOut4_[3];

    /* Saturate: '<S5>/Saturation1' */
    if (rtb_Sum1_c_idx_2 > QD2_DroneStack_PID_2021a_P.Saturation1_UpperSat) {
      /* RateTransition: '<S5>/Rate Transition6' */
      QD2_DroneStack_PID_2021a_B.RateTransition6[51] =
        QD2_DroneStack_PID_2021a_P.Saturation1_UpperSat;
    } else if (rtb_Sum1_c_idx_2 <
               QD2_DroneStack_PID_2021a_P.Saturation1_LowerSat) {
      /* RateTransition: '<S5>/Rate Transition6' */
      QD2_DroneStack_PID_2021a_B.RateTransition6[51] =
        QD2_DroneStack_PID_2021a_P.Saturation1_LowerSat;
    } else {
      /* RateTransition: '<S5>/Rate Transition6' */
      QD2_DroneStack_PID_2021a_B.RateTransition6[51] = rtb_Sum1_c_idx_2;
    }

    /* RateTransition: '<S5>/Rate Transition6' */
    QD2_DroneStack_PID_2021a_B.RateTransition6[52] =
      QD2_DroneStack_PID_2021a_B.ComputationTime;
    QD2_DroneStack_PID_2021a_B.RateTransition6[53] =
      QD2_DroneStack_PID_2021a_B.SampleTime;
    QD2_DroneStack_PID_2021a_B.RateTransition6[54] =
      QD2_DroneStack_PID_2021a_B.RateTransition;
    QD2_DroneStack_PID_2021a_B.RateTransition6[55] =
      QD2_DroneStack_PID_2021a_B.RateTransition1_n;
    QD2_DroneStack_PID_2021a_B.RateTransition6[56] =
      QD2_DroneStack_PID_2021a_B.RateTransition2_m;
    QD2_DroneStack_PID_2021a_B.RateTransition6[57] =
      QD2_DroneStack_PID_2021a_B.RateTransition3;
    QD2_DroneStack_PID_2021a_B.RateTransition6[58] =
      QD2_DroneStack_PID_2021a_B.esc_ready;
    QD2_DroneStack_PID_2021a_B.RateTransition6[59] =
      QD2_DroneStack_PID_2021a_B.esc_timeout;

    /* Bias: '<S64>/Bias1' incorporates:
     *  Gain: '<S64>/Gain'
     *  Selector: '<S64>/Selector'
     */
    QD2_DroneStack_PID_2021a_B.Bias1[0] = QD2_DroneStack_PID_2021a_P.Gain_Gain_d
      * QD2_DroneStack_PID_2021a_B.Selector[0] +
      QD2_DroneStack_PID_2021a_P.Bias1_Bias[0];
    QD2_DroneStack_PID_2021a_B.Bias1[1] = QD2_DroneStack_PID_2021a_P.Gain_Gain_d
      * QD2_DroneStack_PID_2021a_B.Selector[1] +
      QD2_DroneStack_PID_2021a_P.Bias1_Bias[1];
    QD2_DroneStack_PID_2021a_B.Bias1[2] = QD2_DroneStack_PID_2021a_P.Gain_Gain_d
      * QD2_DroneStack_PID_2021a_B.Selector[2] +
      QD2_DroneStack_PID_2021a_P.Bias1_Bias[2];
    QD2_DroneStack_PID_2021a_B.Bias1[3] = QD2_DroneStack_PID_2021a_P.Gain_Gain_d
      * QD2_DroneStack_PID_2021a_B.Selector[3] +
      QD2_DroneStack_PID_2021a_P.Bias1_Bias[3];

    /* Product: '<S5>/Product2' */
    rtb_Product2[0] = QD2_DroneStack_PID_2021a_B.ExtractESCChannels[0] *
      QD2_DroneStack_PID_2021a_B.HILRead_o2[22];

    /* Memory: '<S68>/Memory' */
    rtb_Memory_ic[0] = QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_n[0];

    /* Product: '<S5>/Product2' */
    rtb_Product2[1] = QD2_DroneStack_PID_2021a_B.ExtractESCChannels[1] *
      QD2_DroneStack_PID_2021a_B.HILRead_o2[22];

    /* Memory: '<S68>/Memory' */
    rtb_Memory_ic[1] = QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_n[1];

    /* Product: '<S5>/Product2' */
    rtb_Product2[2] = QD2_DroneStack_PID_2021a_B.ExtractESCChannels[2] *
      QD2_DroneStack_PID_2021a_B.HILRead_o2[22];

    /* Memory: '<S68>/Memory' */
    rtb_Memory_ic[2] = QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_n[2];

    /* Product: '<S5>/Product2' */
    rtb_Product2[3] = QD2_DroneStack_PID_2021a_B.ExtractESCChannels[3] *
      QD2_DroneStack_PID_2021a_B.HILRead_o2[22];

    /* Memory: '<S68>/Memory' */
    rtb_Memory_ic[3] = QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_n[3];

    /* Outputs for Iterator SubSystem: '<S68>/For Each Subsystem -  Construct ESC Signal' */
    ForEachSubsystemConstructES(4, rtb_Product2,
      QD2_DroneStack_PID_2021a_B.HILRead_o2[21], rtb_Memory_ic,
      QD2_DroneStack_PID_2021a_B.ImpAsg_InsertedFor_ESCDataOut_k);

    /* End of Outputs for SubSystem: '<S68>/For Each Subsystem -  Construct ESC Signal' */

    /* Delay: '<S70>/Delay3' */
    QD2_DroneStack_PID_2021a_B.Delay3 =
      QD2_DroneStack_PID_2021a_DW.Delay3_DSTATE[0];

    /* Delay: '<S70>/Delay2' */
    QD2_DroneStack_PID_2021a_B.Delay2 =
      QD2_DroneStack_PID_2021a_DW.Delay2_DSTATE[0];

    /* Delay: '<S70>/Delay1' */
    QD2_DroneStack_PID_2021a_B.Delay1 =
      QD2_DroneStack_PID_2021a_DW.Delay1_DSTATE[0];

    /* Delay: '<S70>/Delay' */
    QD2_DroneStack_PID_2021a_B.Delay_n =
      QD2_DroneStack_PID_2021a_DW.Delay_DSTATE_e[0];

    /* SignalConversion generated from: '<S70>/For Each Subsystem' */
    Duty_Cycle[0] = QD2_DroneStack_PID_2021a_B.Delay3;
    Duty_Cycle[1] = QD2_DroneStack_PID_2021a_B.Delay2;
    Duty_Cycle[2] = QD2_DroneStack_PID_2021a_B.Delay1;
    Duty_Cycle[3] = QD2_DroneStack_PID_2021a_B.Delay_n;

    /* Outputs for Iterator SubSystem: '<S70>/For Each Subsystem' incorporates:
     *  ForEach: '<S91>/For Each'
     */
    for (ForEach_itr = 0; ForEach_itr < 4; ForEach_itr++) {
      /* ForEachSliceSelector generated from: '<S91>/Channel Requested [4]' */
      rtb_ImpSel_InsertedFor_ChannelR = Duty_Cycle[ForEach_itr];

      /* ForEachSliceSelector generated from: '<S91>/Channel Reported [4]' */
      rtb_ImpSel_InsertedFor_Channe_e =
        QD2_DroneStack_PID_2021a_B.ExtractESCChannels[ForEach_itr];

      /* ForEachSliceAssignment generated from: '<S91>/mismatched [4]' incorporates:
       *  Constant: '<S93>/Constant'
       *  ForEachSliceSelector generated from: '<S91>/Channel Reported [4]'
       *  ForEachSliceSelector generated from: '<S91>/Channel Requested [4]'
       *  Logic: '<S91>/AND'
       *  RelationalOperator: '<S93>/Compare'
       *  S-Function (compare_block): '<S91>/Compare'
       */
      rtb_ImpAsg_InsertedFor_mismatch[ForEach_itr] =
        ((rtb_ImpSel_InsertedFor_ChannelR >=
          QD2_DroneStack_PID_2021a_P.CoreSubsys_pna.CompareToConstant_const) &&
         (rtb_ImpSel_InsertedFor_ChannelR != rtb_ImpSel_InsertedFor_Channe_e));
    }

    /* End of Outputs for SubSystem: '<S70>/For Each Subsystem' */

    /* Logic: '<S70>/AND' */
    QD2_DroneStack_PID_2021a_B.AND[0] = (rtb_ImpAsg_InsertedFor_mismatch[0] &&
      (QD2_DroneStack_PID_2021a_B.tele_enable != 0.0));
    QD2_DroneStack_PID_2021a_B.AND[1] = (rtb_ImpAsg_InsertedFor_mismatch[1] &&
      (QD2_DroneStack_PID_2021a_B.tele_enable != 0.0));
    QD2_DroneStack_PID_2021a_B.AND[2] = (rtb_ImpAsg_InsertedFor_mismatch[2] &&
      (QD2_DroneStack_PID_2021a_B.tele_enable != 0.0));
    QD2_DroneStack_PID_2021a_B.AND[3] = (rtb_ImpAsg_InsertedFor_mismatch[3] &&
      (QD2_DroneStack_PID_2021a_B.tele_enable != 0.0));

    /* MATLAB Function: '<S70>/MATLAB Function' incorporates:
     *  Constant: '<S70>/Constant'
     */
    QD2_DroneStack_PID_2021a_DW.sfEvent_c = QD2_DroneStack_PID_2_CALL_EVENT;

    /* MATLAB Function 'QDrone 2 DAQ/Detect ESC Problems/MATLAB Function': '<S92>:1' */
    if (!QD2_DroneStack_PID_2021a_DW.buffer_not_empty) {
      /* '<S92>:1:9' */
      /* '<S92>:1:10' */
      i = QD2_DroneStack_PID_2021a_DW.buffer->size[0] *
        QD2_DroneStack_PID_2021a_DW.buffer->size[1];
      QD2_DroneStack_PID_2021a_DW.buffer->size[0] = 4;
      QD2_DroneStack_PID_2021a_DW.buffer->size[1] = (int32_T)
        QD2_DroneStack_PID_2021a_P.Constant_Value_k;
      QD2_Dr_emxEnsureCapacity_real_T(QD2_DroneStack_PID_2021a_DW.buffer, i);
      firstBlockLength = (int32_T)QD2_DroneStack_PID_2021a_P.Constant_Value_k <<
        2;
      if (firstBlockLength - 1 >= 0) {
        memset(&QD2_DroneStack_PID_2021a_DW.buffer->data[0], 0, (uint32_T)
               firstBlockLength * sizeof(real_T));
      }

      QD2_DroneStack_PID_2021a_DW.buffer_not_empty =
        (QD2_DroneStack_PID_2021a_DW.buffer->size[1] != 0);
    }

    /* '<S92>:1:17' */
    QD2_DroneStack_PID_2021a_DW.buffer->data[((int32_T)
      QD2_DroneStack_PID_2021a_DW.idx - 1) << 2] =
      QD2_DroneStack_PID_2021a_B.AND[0];
    QD2_DroneStack_PID_2021a_DW.buffer->data[(((int32_T)
      QD2_DroneStack_PID_2021a_DW.idx - 1) << 2) + 1] =
      QD2_DroneStack_PID_2021a_B.AND[1];
    QD2_DroneStack_PID_2021a_DW.buffer->data[(((int32_T)
      QD2_DroneStack_PID_2021a_DW.idx - 1) << 2) + 2] =
      QD2_DroneStack_PID_2021a_B.AND[2];
    QD2_DroneStack_PID_2021a_DW.buffer->data[(((int32_T)
      QD2_DroneStack_PID_2021a_DW.idx - 1) << 2) + 3] =
      QD2_DroneStack_PID_2021a_B.AND[3];

    /* '<S92>:1:19' */
    QD2_DroneStack_PID_2021a_DW.idx++;
    if (QD2_DroneStack_PID_2021a_DW.idx >
        QD2_DroneStack_PID_2021a_P.Constant_Value_k) {
      /* '<S92>:1:20' */
      /* '<S92>:1:22' */
      QD2_DroneStack_PID_2021a_DW.idx = 1.0;
    }

    /* '<S92>:1:26' */
    if (QD2_DroneStack_PID_2021a_DW.buffer->size[1] == 0) {
      QD2_DroneStack_PID_2021a_B.n[0] = 0.0;
      QD2_DroneStack_PID_2021a_B.n[1] = 0.0;
      QD2_DroneStack_PID_2021a_B.n[2] = 0.0;
      QD2_DroneStack_PID_2021a_B.n[3] = 0.0;
    } else {
      if (QD2_DroneStack_PID_2021a_DW.buffer->size[1] <= 1024) {
        firstBlockLength = QD2_DroneStack_PID_2021a_DW.buffer->size[1];
        lastBlockLength = 0;
        i = 1;
      } else {
        firstBlockLength = 1024;
        i = (int32_T)((uint32_T)QD2_DroneStack_PID_2021a_DW.buffer->size[1] >>
                      10);
        lastBlockLength = QD2_DroneStack_PID_2021a_DW.buffer->size[1] - (i << 10);
        if (lastBlockLength > 0) {
          i++;
        } else {
          lastBlockLength = 1024;
        }
      }

      QD2_DroneStack_PID_2021a_B.n[0] = QD2_DroneStack_PID_2021a_DW.buffer->
        data[0];
      QD2_DroneStack_PID_2021a_B.n[1] = QD2_DroneStack_PID_2021a_DW.buffer->
        data[1];
      QD2_DroneStack_PID_2021a_B.n[2] = QD2_DroneStack_PID_2021a_DW.buffer->
        data[2];
      QD2_DroneStack_PID_2021a_B.n[3] = QD2_DroneStack_PID_2021a_DW.buffer->
        data[3];
      for (xblockoffset = 2; xblockoffset <= firstBlockLength; xblockoffset++) {
        xoffset = (xblockoffset - 1) << 2;
        QD2_DroneStack_PID_2021a_B.n[0] +=
          QD2_DroneStack_PID_2021a_DW.buffer->data[xoffset];
        QD2_DroneStack_PID_2021a_B.n[1] +=
          QD2_DroneStack_PID_2021a_DW.buffer->data[xoffset + 1];
        QD2_DroneStack_PID_2021a_B.n[2] +=
          QD2_DroneStack_PID_2021a_DW.buffer->data[xoffset + 2];
        QD2_DroneStack_PID_2021a_B.n[3] +=
          QD2_DroneStack_PID_2021a_DW.buffer->data[xoffset + 3];
      }

      for (firstBlockLength = 2; firstBlockLength <= i; firstBlockLength++) {
        xblockoffset = (firstBlockLength - 1) << 12;
        Duty_Cycle[0] = QD2_DroneStack_PID_2021a_DW.buffer->data[xblockoffset];
        Duty_Cycle[1] = QD2_DroneStack_PID_2021a_DW.buffer->data[xblockoffset +
          1];
        Duty_Cycle[2] = QD2_DroneStack_PID_2021a_DW.buffer->data[xblockoffset +
          2];
        Duty_Cycle[3] = QD2_DroneStack_PID_2021a_DW.buffer->data[xblockoffset +
          3];
        if (firstBlockLength == i) {
          hi = lastBlockLength;
        } else {
          hi = 1024;
        }

        for (b_k = 2; b_k <= hi; b_k++) {
          xoffset = ((b_k - 1) << 2) + xblockoffset;
          Duty_Cycle[0] += QD2_DroneStack_PID_2021a_DW.buffer->data[xoffset];
          Duty_Cycle[1] += QD2_DroneStack_PID_2021a_DW.buffer->data[xoffset + 1];
          Duty_Cycle[2] += QD2_DroneStack_PID_2021a_DW.buffer->data[xoffset + 2];
          Duty_Cycle[3] += QD2_DroneStack_PID_2021a_DW.buffer->data[xoffset + 3];
        }

        QD2_DroneStack_PID_2021a_B.n[0] += Duty_Cycle[0];
        QD2_DroneStack_PID_2021a_B.n[1] += Duty_Cycle[1];
        QD2_DroneStack_PID_2021a_B.n[2] += Duty_Cycle[2];
        QD2_DroneStack_PID_2021a_B.n[3] += Duty_Cycle[3];
      }
    }

    /* End of MATLAB Function: '<S70>/MATLAB Function' */
    /* S-Function (euler_angles_to_rotation_matrix_block): '<S5>/Euler Angles to Rotation Matrix' incorporates:
     *  Constant: '<S5>/Zero Yaw'
     */
    {
      t_double sin_phi = sin(QD2_DroneStack_PID_2021a_P.ZeroYaw_Value);
      t_double cos_phi = cos(QD2_DroneStack_PID_2021a_P.ZeroYaw_Value);
      t_double sin_theta = sin(QD2_DroneStack_PID_2021a_B.Product3[1]);
      t_double cos_theta = cos(QD2_DroneStack_PID_2021a_B.Product3[1]);
      t_double sin_psi = sin(QD2_DroneStack_PID_2021a_B.Product3[0]);
      t_double cos_psi = cos(QD2_DroneStack_PID_2021a_B.Product3[0]);
      rtb_EulerAnglestoRotationMatrix[0] = cos_phi * cos_theta;
      rtb_EulerAnglestoRotationMatrix[1] = sin_phi * cos_theta;
      rtb_EulerAnglestoRotationMatrix[2] = -sin_theta;
      rtb_EulerAnglestoRotationMatrix[3] = -sin_phi * cos_psi + cos_phi *
        sin_theta * sin_psi;
      rtb_EulerAnglestoRotationMatrix[4] = cos_phi * cos_psi + sin_phi *
        sin_theta * sin_psi;
      rtb_EulerAnglestoRotationMatrix[5] = cos_theta * sin_psi;
      rtb_EulerAnglestoRotationMatrix[6] = sin_phi * sin_psi + cos_phi *
        sin_theta * cos_psi;
      rtb_EulerAnglestoRotationMatrix[7] = -cos_phi * sin_psi + sin_phi *
        sin_theta * cos_psi;
      rtb_EulerAnglestoRotationMatrix[8] = cos_theta * cos_psi;
    }

    /* DataTypeConversion: '<S77>/Data Type Conversion' incorporates:
     *  Constant: '<S94>/Constant'
     *  Constant: '<S95>/Constant'
     *  Logic: '<S77>/AND'
     *  RelationalOperator: '<S94>/Compare'
     *  RelationalOperator: '<S95>/Compare'
     */
    rtb_DataTypeConversion3 = ((QD2_DroneStack_PID_2021a_B.HILRead_o1[0] >
      QD2_DroneStack_PID_2021a_P.Greaterthanminimumexpectedvolta) &&
      (QD2_DroneStack_PID_2021a_B.HILRead_o1[0] <=
       QD2_DroneStack_PID_2021a_P.Lessthanminimumthresholdvoltage));

    /* RelationalOperator: '<S96>/Relation' incorporates:
     *  Constant: '<S77>/Constant'
     */
    rtb_Relation_j = (rtb_DataTypeConversion3 >=
                      QD2_DroneStack_PID_2021a_P.Constant_Value_i);

    /* DataTypeConversion: '<S96>/Data Type Conversion' */
    QD2_DroneStack_PID_2021a_B.DataTypeConversion_n = rtb_Relation_j;

    /* Logic: '<S96>/Logical Operator' */
    QD2_DroneStack_PID_2021a_B.LogicalOperator = !rtb_Relation_j;

    /* DiscreteIntegrator: '<S96>/Discrete-Time Integrator' */
    if (QD2_DroneStack_PID_2021a_B.LogicalOperator ||
        (QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevRese != 0)) {
      QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE =
        QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC;
    }

    /* RelationalOperator: '<S96>/Relational Operator' incorporates:
     *  Constant: '<S77>/Battery Low Time Threshold (s)'
     *  DiscreteIntegrator: '<S96>/Discrete-Time Integrator'
     */
    rtb_RelationalOperator =
      (QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE >=
       QD2_DroneStack_PID_2021a_P.BatteryLowTimeThresholds_Value);

    /* Outputs for Triggered SubSystem: '<S77>/Triggered Subsystem - Latching Flag' incorporates:
     *  TriggerPort: '<S97>/Trigger'
     */
    if (rtsiIsModeUpdateTimeStep(&QD2_DroneStack_PID_2021a_M->solverInfo)) {
      if (rtb_RelationalOperator &&
          (QD2_DroneStack_PID_2021_PrevZCX.TriggeredSubsystemLatchingFlag_ !=
           POS_ZCSIG)) {
        /* SignalConversion generated from: '<S97>/Out1' incorporates:
         *  Constant: '<S97>/Constant'
         */
        QD2_DroneStack_PID_2021a_B.OutportBufferForOut1 =
          QD2_DroneStack_PID_2021a_P.Constant_Value;
        QD2_DroneStack_PID_2021a_DW.TriggeredSubsystemLatchingFlag_ = 4;
      }

      QD2_DroneStack_PID_2021_PrevZCX.TriggeredSubsystemLatchingFlag_ =
        rtb_RelationalOperator;
    }

    /* End of Outputs for SubSystem: '<S77>/Triggered Subsystem - Latching Flag' */
    /* RelationalOperator: '<S98>/Relation' incorporates:
     *  Constant: '<S79>/Constant2'
     */
    rtb_Relation_j = (QD2_DroneStack_PID_2021a_B.HILRead_o2[0] ==
                      QD2_DroneStack_PID_2021a_P.Constant2_Value_d);

    /* Logic: '<S98>/Logical Operator' */
    QD2_DroneStack_PID_2021a_B.LogicalOperator_b = !rtb_Relation_j;

    /* DiscreteIntegrator: '<S98>/Discrete-Time Integrator' */
    if (QD2_DroneStack_PID_2021a_B.LogicalOperator_b ||
        (QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevRe_p != 0)) {
      QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_o =
        QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_b;
    }

    /* RelationalOperator: '<S99>/Relation' incorporates:
     *  Constant: '<S79>/Constant2'
     */
    rtb_Relation_k = (QD2_DroneStack_PID_2021a_B.HILRead_o2[1] ==
                      QD2_DroneStack_PID_2021a_P.Constant2_Value_d);

    /* Logic: '<S99>/Logical Operator' */
    QD2_DroneStack_PID_2021a_B.LogicalOperator_a = !rtb_Relation_k;

    /* DiscreteIntegrator: '<S99>/Discrete-Time Integrator' */
    if (QD2_DroneStack_PID_2021a_B.LogicalOperator_a ||
        (QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevRe_g != 0)) {
      QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_b =
        QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_g;
    }

    /* RelationalOperator: '<S102>/Relation' incorporates:
     *  Constant: '<S79>/Constant2'
     */
    rtb_Relation = (QD2_DroneStack_PID_2021a_B.HILRead_o2[2] ==
                    QD2_DroneStack_PID_2021a_P.Constant2_Value_d);

    /* Logic: '<S102>/Logical Operator' */
    QD2_DroneStack_PID_2021a_B.LogicalOperator_bu = !rtb_Relation;

    /* DiscreteIntegrator: '<S102>/Discrete-Time Integrator' */
    if (QD2_DroneStack_PID_2021a_B.LogicalOperator_bu ||
        (QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevRe_o != 0)) {
      QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_d =
        QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_e;
    }

    /* RelationalOperator: '<S103>/Relation' incorporates:
     *  Constant: '<S79>/Constant2'
     */
    rtb_Relation_en = (QD2_DroneStack_PID_2021a_B.HILRead_o2[3] ==
                       QD2_DroneStack_PID_2021a_P.Constant2_Value_d);

    /* Logic: '<S103>/Logical Operator' */
    QD2_DroneStack_PID_2021a_B.LogicalOperator_m = !rtb_Relation_en;

    /* DiscreteIntegrator: '<S103>/Discrete-Time Integrator' */
    if (QD2_DroneStack_PID_2021a_B.LogicalOperator_m ||
        (QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevR_oi != 0)) {
      QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_f =
        QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_n;
    }

    /* RelationalOperator: '<S104>/Relation' incorporates:
     *  Constant: '<S79>/Constant2'
     */
    rtb_Relation_f = (QD2_DroneStack_PID_2021a_B.HILRead_o2[4] ==
                      QD2_DroneStack_PID_2021a_P.Constant2_Value_d);

    /* Logic: '<S104>/Logical Operator' */
    QD2_DroneStack_PID_2021a_B.LogicalOperator_l = !rtb_Relation_f;

    /* DiscreteIntegrator: '<S104>/Discrete-Time Integrator' */
    if (QD2_DroneStack_PID_2021a_B.LogicalOperator_l ||
        (QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevRe_e != 0)) {
      QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_g =
        QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_m;
    }

    /* RelationalOperator: '<S105>/Relation' incorporates:
     *  Constant: '<S79>/Constant2'
     */
    rtb_Relation_bl = (QD2_DroneStack_PID_2021a_B.HILRead_o2[5] ==
                       QD2_DroneStack_PID_2021a_P.Constant2_Value_d);

    /* Logic: '<S105>/Logical Operator' */
    QD2_DroneStack_PID_2021a_B.LogicalOperator_l3 = !rtb_Relation_bl;

    /* DiscreteIntegrator: '<S105>/Discrete-Time Integrator' */
    if (QD2_DroneStack_PID_2021a_B.LogicalOperator_l3 ||
        (QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevRe_n != 0)) {
      QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_n =
        QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_f;
    }

    /* RelationalOperator: '<S106>/Relation' incorporates:
     *  Constant: '<S79>/Constant2'
     */
    rtb_Relation_l = (QD2_DroneStack_PID_2021a_B.HILRead_o2[6] ==
                      QD2_DroneStack_PID_2021a_P.Constant2_Value_d);

    /* Logic: '<S106>/Logical Operator' */
    QD2_DroneStack_PID_2021a_B.LogicalOperator_o = !rtb_Relation_l;

    /* DiscreteIntegrator: '<S106>/Discrete-Time Integrator' */
    if (QD2_DroneStack_PID_2021a_B.LogicalOperator_o ||
        (QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevR_p5 != 0)) {
      QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_p =
        QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_h;
    }

    /* RelationalOperator: '<S107>/Relation' incorporates:
     *  Constant: '<S79>/Constant2'
     */
    rtb_Relation_a = (QD2_DroneStack_PID_2021a_B.HILRead_o2[7] ==
                      QD2_DroneStack_PID_2021a_P.Constant2_Value_d);

    /* Logic: '<S107>/Logical Operator' */
    QD2_DroneStack_PID_2021a_B.LogicalOperator_ms = !rtb_Relation_a;

    /* DiscreteIntegrator: '<S107>/Discrete-Time Integrator' */
    if (QD2_DroneStack_PID_2021a_B.LogicalOperator_ms ||
        (QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevRe_d != 0)) {
      QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_j =
        QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_c;
    }

    /* RelationalOperator: '<S108>/Relation' incorporates:
     *  Constant: '<S79>/Constant2'
     */
    rtb_AND3 = (QD2_DroneStack_PID_2021a_B.HILRead_o2[8] ==
                QD2_DroneStack_PID_2021a_P.Constant2_Value_d);

    /* Logic: '<S108>/Logical Operator' */
    QD2_DroneStack_PID_2021a_B.LogicalOperator_og = !rtb_AND3;

    /* DiscreteIntegrator: '<S108>/Discrete-Time Integrator' */
    if (QD2_DroneStack_PID_2021a_B.LogicalOperator_og ||
        (QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevR_nn != 0)) {
      QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_h =
        QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_mg;
    }

    /* RelationalOperator: '<S109>/Relation' incorporates:
     *  Constant: '<S79>/Constant2'
     */
    rtb_DataTypeConversion3_k = (QD2_DroneStack_PID_2021a_B.HILRead_o2[9] ==
      QD2_DroneStack_PID_2021a_P.Constant2_Value_d);

    /* Logic: '<S109>/Logical Operator' */
    QD2_DroneStack_PID_2021a_B.LogicalOperator_on = !rtb_DataTypeConversion3_k;

    /* DiscreteIntegrator: '<S109>/Discrete-Time Integrator' */
    if (QD2_DroneStack_PID_2021a_B.LogicalOperator_on ||
        (QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevR_eu != 0)) {
      QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTAT_n1 =
        QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_hh;
    }

    /* RelationalOperator: '<S100>/Relation' incorporates:
     *  Constant: '<S79>/Constant2'
     */
    rtb_AND2 = (QD2_DroneStack_PID_2021a_B.HILRead_o2[10] ==
                QD2_DroneStack_PID_2021a_P.Constant2_Value_d);

    /* Logic: '<S100>/Logical Operator' */
    QD2_DroneStack_PID_2021a_B.LogicalOperator_lm = !rtb_AND2;

    /* DiscreteIntegrator: '<S100>/Discrete-Time Integrator' */
    if (QD2_DroneStack_PID_2021a_B.LogicalOperator_lm ||
        (QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevR_gx != 0)) {
      QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_c =
        QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_n2;
    }

    /* RelationalOperator: '<S101>/Relation' incorporates:
     *  Constant: '<S79>/Constant2'
     */
    rtb_Relation_m = (QD2_DroneStack_PID_2021a_B.HILRead_o2[11] ==
                      QD2_DroneStack_PID_2021a_P.Constant2_Value_d);

    /* Logic: '<S101>/Logical Operator' */
    QD2_DroneStack_PID_2021a_B.LogicalOperator_i = !rtb_Relation_m;

    /* DiscreteIntegrator: '<S101>/Discrete-Time Integrator' */
    if (QD2_DroneStack_PID_2021a_B.LogicalOperator_i ||
        (QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevRe_f != 0)) {
      QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_a =
        QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_m0;
    }

    /* Logic: '<S5>/OR' incorporates:
     *  Constant: '<S79>/Constant1'
     *  DiscreteIntegrator: '<S100>/Discrete-Time Integrator'
     *  DiscreteIntegrator: '<S101>/Discrete-Time Integrator'
     *  DiscreteIntegrator: '<S102>/Discrete-Time Integrator'
     *  DiscreteIntegrator: '<S103>/Discrete-Time Integrator'
     *  DiscreteIntegrator: '<S104>/Discrete-Time Integrator'
     *  DiscreteIntegrator: '<S105>/Discrete-Time Integrator'
     *  DiscreteIntegrator: '<S106>/Discrete-Time Integrator'
     *  DiscreteIntegrator: '<S107>/Discrete-Time Integrator'
     *  DiscreteIntegrator: '<S108>/Discrete-Time Integrator'
     *  DiscreteIntegrator: '<S109>/Discrete-Time Integrator'
     *  DiscreteIntegrator: '<S98>/Discrete-Time Integrator'
     *  DiscreteIntegrator: '<S99>/Discrete-Time Integrator'
     *  Logic: '<S79>/AND'
     *  Logic: '<S79>/OR'
     *  RelationalOperator: '<S100>/Relational Operator'
     *  RelationalOperator: '<S101>/Relational Operator'
     *  RelationalOperator: '<S102>/Relational Operator'
     *  RelationalOperator: '<S103>/Relational Operator'
     *  RelationalOperator: '<S104>/Relational Operator'
     *  RelationalOperator: '<S105>/Relational Operator'
     *  RelationalOperator: '<S106>/Relational Operator'
     *  RelationalOperator: '<S107>/Relational Operator'
     *  RelationalOperator: '<S108>/Relational Operator'
     *  RelationalOperator: '<S109>/Relational Operator'
     *  RelationalOperator: '<S98>/Relational Operator'
     *  RelationalOperator: '<S99>/Relational Operator'
     *  S-Function (compare_block): '<S79>/Compare'
     *  S-Function (time_block): '<S5>/Time'
     */
    QD2_DroneStack_PID_2021a_B.OR = (((rtb_Time >=
      QD2_DroneStack_PID_2021a_P.Constant1_Value_p) &&
      ((QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_o >=
        QD2_DroneStack_PID_2021a_P.Constant1_Value_p) ||
       (QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_b >=
        QD2_DroneStack_PID_2021a_P.Constant1_Value_p) ||
       (QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_d >=
        QD2_DroneStack_PID_2021a_P.Constant1_Value_p) ||
       (QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_f >=
        QD2_DroneStack_PID_2021a_P.Constant1_Value_p) ||
       (QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_g >=
        QD2_DroneStack_PID_2021a_P.Constant1_Value_p) ||
       (QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_n >=
        QD2_DroneStack_PID_2021a_P.Constant1_Value_p) ||
       (QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_p >=
        QD2_DroneStack_PID_2021a_P.Constant1_Value_p) ||
       (QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_j >=
        QD2_DroneStack_PID_2021a_P.Constant1_Value_p) ||
       (QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_h >=
        QD2_DroneStack_PID_2021a_P.Constant1_Value_p) ||
       (QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTAT_n1 >=
        QD2_DroneStack_PID_2021a_P.Constant1_Value_p) ||
       (QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_c >=
        QD2_DroneStack_PID_2021a_P.Constant1_Value_p) ||
       (QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_a >=
        QD2_DroneStack_PID_2021a_P.Constant1_Value_p))) ||
      (QD2_DroneStack_PID_2021a_B.esc_timeout != 0.0));

    /* RateTransition: '<S5>/Rate Transition' */
    if (QD2_DroneStack_PID_2021a_M->Timing.RateInteraction.TID1_3) {
      for (i = 0; i < 7; i++) {
        QD2_DroneStack_PID_2021a_DW.RateTransition_Buffer[i] =
          QD2_DroneStack_PID_2021a_B.HILRead_o2[i + 12];
      }
    }

    /* End of RateTransition: '<S5>/Rate Transition' */

    /* RateTransition: '<S5>/Rate Transition10' incorporates:
     *  Product: '<S5>/Product3'
     *  RateTransition: '<S5>/Rate Transition11'
     *  RateTransition: '<S5>/Rate Transition12'
     *  RateTransition: '<S5>/Rate Transition15'
     *  RateTransition: '<S5>/Rate Transition17'
     *  RateTransition: '<S5>/Rate Transition19'
     *  RateTransition: '<S5>/Rate Transition20'
     *  Selector: '<S63>/Select Data for IMU0'
     *  Selector: '<S63>/Select Data for IMU1'
     */
    if (QD2_DroneStack_PID_2021a_M->Timing.RateInteraction.TID1_2) {
      QD2_DroneStack_PID_2021a_DW.RateTransition10_Buffer[0] =
        QD2_DroneStack_PID_2021a_B.MaximumCommandAuthority[0];
      QD2_DroneStack_PID_2021a_DW.RateTransition10_Buffer[1] =
        QD2_DroneStack_PID_2021a_B.MaximumCommandAuthority[1];
      QD2_DroneStack_PID_2021a_DW.RateTransition10_Buffer[2] =
        QD2_DroneStack_PID_2021a_B.MaximumCommandAuthority[2];
      QD2_DroneStack_PID_2021a_DW.RateTransition10_Buffer[3] =
        QD2_DroneStack_PID_2021a_B.MaximumCommandAuthority[3];
      QD2_DroneStack_PID_2021a_DW.RateTransition11_Buffer =
        QD2_DroneStack_PID_2021a_B.OutportBufferForOut1;
      QD2_DroneStack_PID_2021a_DW.RateTransition12_Buffer =
        QD2_DroneStack_PID_2021a_B.HILRead_o1[0];
      memcpy(&QD2_DroneStack_PID_2021a_DW.RateTransition15_Buffer[0],
             &QD2_DroneStack_PID_2021a_B.SelectDataforIMU0[0], 9U * sizeof
             (real_T));
      memcpy(&QD2_DroneStack_PID_2021a_DW.RateTransition17_Buffer[0],
             &QD2_DroneStack_PID_2021a_B.SelectDataforIMU1[0], 9U * sizeof
             (real_T));
      memcpy(&QD2_DroneStack_PID_2021a_DW.RateTransition19_Buffer[0],
             &QD2_DroneStack_PID_2021a_B.Product3[0], 9U * sizeof(real_T));
      QD2_DroneStack_PID_2021a_DW.RateTransition20_Buffer =
        QD2_DroneStack_PID_2021a_B.HILRead_o1[2];
    }

    /* End of RateTransition: '<S5>/Rate Transition10' */

    /* RateTransition: '<S5>/Rate Transition3' incorporates:
     *  S-Function (euler_angles_to_rotation_matrix_block): '<S5>/Euler Angles to Rotation Matrix'
     */
    if (QD2_DroneStack_PID_2021a_M->Timing.RateInteraction.TID1_4) {
      memcpy(&QD2_DroneStack_PID_2021a_DW.RateTransition3_Buffer[0],
             &rtb_EulerAnglestoRotationMatrix[0], 9U * sizeof(real_T));
    }

    /* End of RateTransition: '<S5>/Rate Transition3' */

    /* RateTransition: '<S5>/Rate Transition8' */
    if (QD2_DroneStack_PID_2021a_M->Timing.RateInteraction.TID1_2) {
      memcpy(&QD2_DroneStack_PID_2021a_DW.RateTransition8_Buffer[0],
             &QD2_DroneStack_PID_2021a_B.HILRead_o2[0], 12U * sizeof(real_T));
    }

    /* End of RateTransition: '<S5>/Rate Transition8' */

    /* DataTypeConversion: '<S98>/Data Type Conversion' */
    QD2_DroneStack_PID_2021a_B.DataTypeConversion_o = rtb_Relation_j;

    /* DataTypeConversion: '<S99>/Data Type Conversion' */
    QD2_DroneStack_PID_2021a_B.DataTypeConversion_a = rtb_Relation_k;

    /* DataTypeConversion: '<S100>/Data Type Conversion' */
    QD2_DroneStack_PID_2021a_B.DataTypeConversion_ai = rtb_AND2;

    /* DataTypeConversion: '<S101>/Data Type Conversion' */
    QD2_DroneStack_PID_2021a_B.DataTypeConversion_d = rtb_Relation_m;

    /* DataTypeConversion: '<S102>/Data Type Conversion' */
    QD2_DroneStack_PID_2021a_B.DataTypeConversion_a2 = rtb_Relation;

    /* DataTypeConversion: '<S103>/Data Type Conversion' */
    QD2_DroneStack_PID_2021a_B.DataTypeConversion_p = rtb_Relation_en;

    /* DataTypeConversion: '<S104>/Data Type Conversion' */
    QD2_DroneStack_PID_2021a_B.DataTypeConversion_b = rtb_Relation_f;

    /* DataTypeConversion: '<S105>/Data Type Conversion' */
    QD2_DroneStack_PID_2021a_B.DataTypeConversion_nn = rtb_Relation_bl;

    /* DataTypeConversion: '<S106>/Data Type Conversion' */
    QD2_DroneStack_PID_2021a_B.DataTypeConversion_h = rtb_Relation_l;

    /* DataTypeConversion: '<S107>/Data Type Conversion' */
    QD2_DroneStack_PID_2021a_B.DataTypeConversion_l = rtb_Relation_a;

    /* DataTypeConversion: '<S108>/Data Type Conversion' */
    QD2_DroneStack_PID_2021a_B.DataTypeConversion_df = rtb_AND3;

    /* DataTypeConversion: '<S109>/Data Type Conversion' */
    QD2_DroneStack_PID_2021a_B.DataTypeConversion_hb = rtb_DataTypeConversion3_k;

    /* RelationalOperator: '<S80>/Relation' incorporates:
     *  Constant: '<S80>/threshold'
     *  Constant: '<S90>/Constant'
     *  Logic: '<S5>/OR1'
     *  RelationalOperator: '<S90>/Compare'
     */
    rtb_Relation_m = (((QD2_DroneStack_PID_2021a_B.n[0] >=
                        QD2_DroneStack_PID_2021a_P.CompareToConstant_const) ||
                       (QD2_DroneStack_PID_2021a_B.n[1] >=
                        QD2_DroneStack_PID_2021a_P.CompareToConstant_const) ||
                       (QD2_DroneStack_PID_2021a_B.n[2] >=
                        QD2_DroneStack_PID_2021a_P.CompareToConstant_const) ||
                       (QD2_DroneStack_PID_2021a_B.n[3] >=
                        QD2_DroneStack_PID_2021a_P.CompareToConstant_const)) !=
                      QD2_DroneStack_PID_2021a_P.Threshold_threshold);

    /* DataTypeConversion: '<S80>/Data Type Conversion' */
    QD2_DroneStack_PID_2021a_B.DataTypeConversion_e = rtb_Relation_m;

    /* Logic: '<S80>/Logical Operator' */
    QD2_DroneStack_PID_2021a_B.LogicalOperator_p = !rtb_Relation_m;

    /* DiscreteIntegrator: '<S80>/Discrete-Time Integrator' */
    if (QD2_DroneStack_PID_2021a_B.LogicalOperator_p ||
        (QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevR_oj != 0)) {
      QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTAT_bm =
        QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_k;
    }

    /* RelationalOperator: '<S80>/Relational Operator' incorporates:
     *  Constant: '<S80>/duration'
     *  DiscreteIntegrator: '<S80>/Discrete-Time Integrator'
     */
    QD2_DroneStack_PID_2021a_B.RelationalOperator =
      (QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTAT_bm >=
       QD2_DroneStack_PID_2021a_P.Threshold_duration);

    /* DataTypeConversion: '<S10>/Data Type Conversion1' */
    rtb_RelationalOperator = (QD2_DroneStack_PID_2021a_B.StreamClient_o4[4] !=
      0.0);

    /* Logic: '<S10>/Logical Operator3' incorporates:
     *  DataTypeConversion: '<S10>/Data Type Conversion1'
     */
    QD2_DroneStack_PID_2021a_B.LogicalOperator3 =
      !(QD2_DroneStack_PID_2021a_B.StreamClient_o4[4] != 0.0);

    /* UnitDelay: '<Root>/Unit Delay' */
    QD2_DroneStack_PID_2021a_B.UnitDelay =
      QD2_DroneStack_PID_2021a_DW.UnitDelay_DSTATE;
  }

  /* Clock: '<S10>/Clock' incorporates:
   *  Clock: '<S47>/Clock1'
   */
  rtb_DataTypeConversion3 = QD2_DroneStack_PID_2021a_M->Timing.t[0];

  /* RelationalOperator: '<S23>/Compare' incorporates:
   *  Constant: '<S23>/Constant'
   */
  rtb_Relation = (rtb_DataTypeConversion3 <=
                  QD2_DroneStack_PID_2021a_P.Waitatleast2secondstoallowforin);

  /* RelationalOperator: '<S21>/Relation' incorporates:
   *  Constant: '<S15>/Constant'
   *  Constant: '<S21>/threshold'
   *  DataTypeConversion: '<S10>/Data Type Conversion3'
   *  Logic: '<S10>/Logical Operator4'
   *  RelationalOperator: '<S15>/Compare'
   */
  rtb_Relation_k = ((QD2_DroneStack_PID_2021a_B.LogicalOperator3 &&
                     (rtb_DataTypeConversion3 >
                      QD2_DroneStack_PID_2021a_P.CompareToConstant2_const) &&
                     (QD2_DroneStack_PID_2021a_B.UnitDelay != 0.0)) >=
                    QD2_DroneStack_PID_2021a_P.Threshold_threshold_p);

  /* Logic: '<S21>/Logical Operator' */
  QD2_DroneStack_PID_2021a_B.LogicalOperator_ab = !rtb_Relation_k;

  /* Clock: '<S47>/Clock1' */
  QD2_DroneStack_PID_2021a_B.Clock1 = rtb_DataTypeConversion3;

  /* Abs: '<S22>/Abs' incorporates:
   *  Sum: '<S22>/Subtract'
   */
  QD2_DroneStack_PID_2021a_B.Abs = fabs(QD2_DroneStack_PID_2021a_B.NetThrottle -
    QD2_DroneStack_PID_2021a_B.Product);
  if (rtb_Compare_f) {
    /* DiscreteIntegrator: '<S21>/Discrete-Time Integrator' */
    if (QD2_DroneStack_PID_2021a_B.LogicalOperator_ab ||
        (QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevR_dp != 0)) {
      QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTAT_jy =
        QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_nh;
    }

    /* RelationalOperator: '<S21>/Relational Operator' incorporates:
     *  Constant: '<S21>/duration'
     *  DiscreteIntegrator: '<S21>/Discrete-Time Integrator'
     */
    QD2_DroneStack_PID_2021a_B.RelationalOperator_g =
      (QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTAT_jy >=
       QD2_DroneStack_PID_2021a_P.Threshold_duration_l);

    /* MATLAB Function: '<S47>/MATLAB Function' */
    QD2_DroneStack_PID_2021a_DW.sfEvent_l = QD2_DroneStack_PID_2_CALL_EVENT;

    /* MATLAB Function 'Communication/Detect Communication Loss/MATLAB Function': '<S48>:1' */
    /* '<S48>:1:8' */
    rtb_DataTypeConversion3 = 0.0;

    /* '<S48>:1:9' */
    data_loss = 0.0;
    if (QD2_DroneStack_PID_2021a_B.Clock1 > 3.0) {
      /* '<S48>:1:10' */
      if ((QD2_DroneStack_PID_2021a_B.StreamClient_o1 != 2) &&
          (QD2_DroneStack_PID_2021a_B.StreamClient_o2 < 0)) {
        /* '<S48>:1:11' */
        /* '<S48>:1:13' */
        rtb_DataTypeConversion3 = 1.0;
      }

      if ((QD2_DroneStack_PID_2021a_B.StreamClient_o4[15] ==
           QD2_DroneStack_PID_2021a_DW.ms_time_prev) &&
          (QD2_DroneStack_PID_2021a_B.StreamClient_o4[15] > 0.0)) {
        /* '<S48>:1:16' */
        /* '<S48>:1:18' */
        data_loss = 1.0;
      }
    }

    /* '<S48>:1:22' */
    QD2_DroneStack_PID_2021a_DW.ms_time_prev =
      QD2_DroneStack_PID_2021a_B.StreamClient_o4[15];

    /* End of MATLAB Function: '<S47>/MATLAB Function' */

    /* RelationalOperator: '<S49>/Relation' incorporates:
     *  Constant: '<S49>/threshold'
     */
    rtb_RelationalOperator = (rtb_DataTypeConversion3 >=
      QD2_DroneStack_PID_2021a_P.Threshold1_threshold);

    /* Logic: '<S49>/Logical Operator' */
    QD2_DroneStack_PID_2021a_B.LogicalOperator_f = !rtb_RelationalOperator;

    /* DiscreteIntegrator: '<S49>/Discrete-Time Integrator' */
    if (QD2_DroneStack_PID_2021a_B.LogicalOperator_f ||
        (QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevRe_l != 0)) {
      QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_e =
        QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_fy;
    }

    /* RelationalOperator: '<S49>/Relational Operator' incorporates:
     *  Constant: '<S49>/duration'
     *  DiscreteIntegrator: '<S49>/Discrete-Time Integrator'
     */
    QD2_DroneStack_PID_2021a_B.RelationalOperator_i =
      (QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_e >=
       QD2_DroneStack_PID_2021a_P.Threshold1_duration);

    /* RelationalOperator: '<S50>/Relation' incorporates:
     *  Constant: '<S50>/threshold'
     */
    rtb_Relation_m = (data_loss >=
                      QD2_DroneStack_PID_2021a_P.Threshold2_threshold);

    /* Logic: '<S50>/Logical Operator' */
    QD2_DroneStack_PID_2021a_B.LogicalOperator_ft = !rtb_Relation_m;

    /* DiscreteIntegrator: '<S50>/Discrete-Time Integrator' */
    if (QD2_DroneStack_PID_2021a_B.LogicalOperator_ft ||
        (QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevR_gh != 0)) {
      QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_i =
        QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_gy;
    }

    /* RelationalOperator: '<S50>/Relational Operator' incorporates:
     *  Constant: '<S50>/duration'
     *  DiscreteIntegrator: '<S50>/Discrete-Time Integrator'
     */
    QD2_DroneStack_PID_2021a_B.RelationalOperator_h =
      (QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_i >=
       QD2_DroneStack_PID_2021a_P.Threshold2_duration);

    /* DataTypeConversion: '<S47>/Data Type Conversion4' incorporates:
     *  Logic: '<S47>/Logical Operator4'
     */
    QD2_DroneStack_PID_2021a_B.DataTypeConversion4 =
      (QD2_DroneStack_PID_2021a_B.RelationalOperator_i ||
       QD2_DroneStack_PID_2021a_B.RelationalOperator_h);

    /* DataTypeConversion: '<S10>/Data Type Conversion4' */
    QD2_DroneStack_PID_2021a_B.DataTypeConversion4_fx =
      (QD2_DroneStack_PID_2021a_B.OutportBufferForOut1 != 0.0);

    /* DataTypeConversion: '<S10>/Data Type Conversion23' */
    QD2_DroneStack_PID_2021a_B.DataTypeConversion23 =
      QD2_DroneStack_PID_2021a_B.DataTypeConversion_pb[1];

    /* Product: '<S22>/Product1' incorporates:
     *  Constant: '<Root>/Max Throttle HQ 7 inch'
     *  Constant: '<S22>/MAX throttle   percentage (%)  For Trim  '
     */
    rtb_Product1_j = QD2_DroneStack_PID_2021a_P.MAXthrottlepercentageForTrim_Va *
      QD2_DroneStack_PID_2021a_P.MaxThrottleHQ7inch_Value;

    /* S-Function (compare_block): '<S22>/Compare' */
    {
      QD2_DroneStack_PID_2021a_B.Compare_c = (QD2_DroneStack_PID_2021a_B.Abs <=
        rtb_Product1_j);
    }

    /* Product: '<S22>/Product' incorporates:
     *  Constant: '<Root>/Max Throttle HQ 7 inch'
     *  Constant: '<S22>/MAX throttle percentage (%) For CMD '
     */
    rtb_Product_j = QD2_DroneStack_PID_2021a_P.MAXthrottlepercentageForCMD_Val *
      QD2_DroneStack_PID_2021a_P.MaxThrottleHQ7inch_Value;

    /* S-Function (compare_block): '<S22>/Compare1' */
    {
      QD2_DroneStack_PID_2021a_B.Compare1 =
        (QD2_DroneStack_PID_2021a_B.NetThrottle <= rtb_Product_j);
    }
  }

  /* Abs: '<S22>/Abs1' */
  QD2_DroneStack_PID_2021a_B.Abs1 = fabs(sigmoid);
  if (rtb_Compare_f) {
    /* Product: '<S22>/Product2' incorporates:
     *  Constant: '<Root>/Max Throttle HQ 7 inch'
     *  Constant: '<S22>/MAX throttle percentage (%) For Ctrl '
     */
    rtb_Product2_p = QD2_DroneStack_PID_2021a_P.MAXthrottlepercentageForCtrl_Va *
      QD2_DroneStack_PID_2021a_P.MaxThrottleHQ7inch_Value;

    /* S-Function (compare_block): '<S22>/Compare2' */
    {
      QD2_DroneStack_PID_2021a_B.Compare2 = (QD2_DroneStack_PID_2021a_B.Abs1 <=
        rtb_Product2_p);
    }

    /* Sum: '<S19>/Subtract' */
    rtb_DataTypeConversion3 = QD2_DroneStack_PID_2021a_B.Switch2_m[2] -
      QD2_DroneStack_PID_2021a_B.StreamClient_o4[7];

    /* Abs: '<S19>/Abs' */
    rtb_DataTypeConversion3 = fabs(rtb_DataTypeConversion3);

    /* RelationalOperator: '<S38>/Compare' incorporates:
     *  Constant: '<S38>/Constant'
     */
    rtb_AND2 = (rtb_DataTypeConversion3 <=
                QD2_DroneStack_PID_2021a_P.Thresholdtodetectifthedroneiscl);

    /* Sum: '<S19>/Subtract1' */
    rtb_DataTypeConversion3 = QD2_DroneStack_PID_2021a_B.Switch2_m[2] -
      QD2_DroneStack_PID_2021a_B.StreamClient_o4[13];

    /* Abs: '<S19>/Abs1' */
    rtb_DataTypeConversion3 = fabs(rtb_DataTypeConversion3);

    /* Logic: '<S19>/Logical Operator' incorporates:
     *  Constant: '<S37>/Constant'
     *  RelationalOperator: '<S37>/Compare'
     */
    QD2_DroneStack_PID_2021a_B.LogicalOperator_mx =
      (QD2_DroneStack_PID_2021a_B.DataTypeConversion_pb[1] && rtb_AND2 &&
       (rtb_DataTypeConversion3 <=
        QD2_DroneStack_PID_2021a_P.Thresholdtodetectifthecommanded));

    /* Sum: '<S19>/Subtract2' */
    rtb_Subtract2 = QD2_DroneStack_PID_2021a_B.Switch2_m[2] -
      QD2_DroneStack_PID_2021a_B.StreamClient_o4[7];

    /* RelationalOperator: '<S31>/Compare' incorporates:
     *  Constant: '<S31>/Constant'
     */
    rtb_AND2 = (QD2_DroneStack_PID_2021a_B.StreamClient_o4[7] <=
                QD2_DroneStack_PID_2021a_P.themeasuredheightislessthan015m);

    /* Gain: '<S19>/75% of  Commanded Height' */
    rtb_u5ofCommandedHeight =
      QD2_DroneStack_PID_2021a_P.u5ofCommandedHeight_Gain *
      QD2_DroneStack_PID_2021a_B.StreamClient_o4[13];

    /* Logic: '<S19>/Logical Operator2' incorporates:
     *  Constant: '<S33>/Constant'
     *  Constant: '<S35>/Constant'
     *  Constant: '<S36>/Constant'
     *  Gain: '<S19>/75% of  Commanded Height'
     *  Logic: '<S19>/Logical Operator1'
     *  Logic: '<S19>/Logical Operator4'
     *  RelationalOperator: '<S33>/Compare'
     *  RelationalOperator: '<S35>/Compare'
     *  RelationalOperator: '<S36>/Compare'
     *  S-Function (compare_block): '<S19>/If the difference between the measured  and commanded height is greater than  75% of the commanded height during...'
     *  Sum: '<S19>/Subtract2'
     */
    QD2_DroneStack_PID_2021a_B.LogicalOperator2 = (((rtb_Subtract2 >=
      QD2_DroneStack_PID_2021a_P.Ifthemeasuredheightismorethan02) && rtb_AND2 &&
      (QD2_DroneStack_PID_2021a_B.Memory ==
       QD2_DroneStack_PID_2021a_P.FlightState_const)) || (rtb_AND2 &&
      (rtb_Subtract2 >= rtb_u5ofCommandedHeight) &&
      (QD2_DroneStack_PID_2021a_B.Memory ==
       QD2_DroneStack_PID_2021a_P.TakeoffThrottleHeightState_cons)));

    /* S-Function (compare_block): '<S19>/check if measured height exceeds maximum height safety threshold' incorporates:
     *  Constant: '<S3>/Position Safety Threshold (m) [3]'
     */
    {
      QD2_DroneStack_PID_2021a_B.checkifmeasuredheightexceedsmax =
        (QD2_DroneStack_PID_2021a_B.StreamClient_o4[7] >=
         QD2_DroneStack_PID_2021a_P.PositionSafetyThresholdm3_Value[2]);
    }

    /* Logic: '<S19>/Logical Operator3' incorporates:
     *  Constant: '<S32>/Constant'
     *  Constant: '<S34>/Constant'
     *  RelationalOperator: '<S32>/Compare'
     *  RelationalOperator: '<S34>/Compare'
     */
    QD2_DroneStack_PID_2021a_B.LogicalOperator3_e =
      ((QD2_DroneStack_PID_2021a_B.Memory >=
        QD2_DroneStack_PID_2021a_P.CompareToConstant1_const) &&
       (QD2_DroneStack_PID_2021a_B.StreamClient_o4[7] <=
        QD2_DroneStack_PID_2021a_P.Ifthedroneisatorbelowthisheight));
  }

  /* MATLAB Function: '<S1>/STATE MACHINE LOGIC' */
  QD2_DroneStack_PID_2021a_DW.sfEvent_cx = QD2_DroneStack_PID_2_CALL_EVENT;

  /* MATLAB Function 'COMMANDER (ANGLE MODE)/STATE MACHINE LOGIC': '<S9>:1' */
  /* '<S9>:1:47' */
  sigmoid = 0.0;

  /* '<S9>:1:48' */
  /* '<S9>:1:49' */
  rtb_AND2 = false;

  /* '<S9>:1:50' */
  rtb_Relation_en = false;

  /* '<S9>:1:51' */
  rtb_Relation_f = false;

  /* '<S9>:1:52' */
  rtb_Relation_bl = false;

  /* '<S9>:1:53' */
  rtb_Relation_l = false;

  /* '<S9>:1:54' */
  rtb_Relation_a = false;

  /* '<S9>:1:55' */
  rtb_AND3 = false;

  /* '<S9>:1:56' */
  rtb_DataTypeConversion3_k = false;

  /* '<S9>:1:57' */
  pt_EMERGENCY_ABORT_TO_DISABLE = false;

  /* DataTypeConversion: '<S1>/Data Type Conversion3' incorporates:
   *  MATLAB Function: '<S1>/STATE MACHINE LOGIC'
   */
  /* '<S9>:1:58' */
  QD2_DroneStack_PID_2021a_B.DataTypeConversion3 = 0.0;

  /* MATLAB Function: '<S1>/STATE MACHINE LOGIC' */
  switch ((int32_T)QD2_DroneStack_PID_2021a_B.Memory) {
   case 1:
    if ((QD2_DroneStack_PID_2021a_B.DataTypeConversion4 != 0.0) ||
        QD2_DroneStack_PID_2021a_B.DataTypeConversion_pb[3] ||
        QD2_DroneStack_PID_2021a_B.RelationalOperator_g ||
        QD2_DroneStack_PID_2021a_B.DataTypeConversion4_fx ||
        QD2_DroneStack_PID_2021a_B.OR ||
        (QD2_DroneStack_PID_2021a_B.DataTypeConversion22 && rtb_Relation) ||
        QD2_DroneStack_PID_2021a_B.DataTypeConversion23 ||
        !QD2_DroneStack_PID_2021a_B.Compare2) {
      /* '<S9>:1:64' */
      /* '<S9>:1:65' */
      /* '<S9>:1:66' */
      /* '<S9>:1:67' */
      /* '<S9>:1:68' */
      /* '<S9>:1:69' */
      /* '<S9>:1:70' */
      /* '<S9>:1:72' */
      sigmoid = 1.0;
    } else if (QD2_DroneStack_PID_2021a_B.DataTypeConversion22) {
      /* '<S9>:1:73' */
      /* '<S9>:1:74' */
      rtb_AND2 = true;
    }
    break;

   case 2:
    /* '<S9>:1:78' */
    rtb_AND2 = QD2_DroneStack_PID_2021a_B.DataTypeConversion22;
    if ((QD2_DroneStack_PID_2021a_B.DataTypeConversion4 != 0.0) ||
        QD2_DroneStack_PID_2021a_B.DataTypeConversion_pb[3] ||
        QD2_DroneStack_PID_2021a_B.RelationalOperator_g ||
        QD2_DroneStack_PID_2021a_B.DataTypeConversion4_fx ||
        QD2_DroneStack_PID_2021a_B.OR || !QD2_DroneStack_PID_2021a_B.Compare2) {
      /* '<S9>:1:80' */
      /* '<S9>:1:81' */
      /* '<S9>:1:82' */
      /* '<S9>:1:83' */
      /* '<S9>:1:84' */
      /* '<S9>:1:86' */
      sigmoid = 1.0;
    } else if (QD2_DroneStack_PID_2021a_B.DataTypeConversion22 &&
               QD2_DroneStack_PID_2021a_B.DataTypeConversion23) {
      /* '<S9>:1:87' */
      /* '<S9>:1:88' */
      rtb_Relation_en = true;
    }
    break;

   case 3:
    if ((QD2_DroneStack_PID_2021a_B.DataTypeConversion4 != 0.0) ||
        QD2_DroneStack_PID_2021a_B.DataTypeConversion_pb[3] ||
        QD2_DroneStack_PID_2021a_B.RelationalOperator_g ||
        QD2_DroneStack_PID_2021a_B.DataTypeConversion4_fx ||
        QD2_DroneStack_PID_2021a_B.OR ||
        !QD2_DroneStack_PID_2021a_B.DataTypeConversion22 ||
        !QD2_DroneStack_PID_2021a_B.DataTypeConversion23 ||
        !QD2_DroneStack_PID_2021a_B.Compare2) {
      /* '<S9>:1:93' */
      /* '<S9>:1:94' */
      /* '<S9>:1:95' */
      /* '<S9>:1:96' */
      /* '<S9>:1:97' */
      /* '<S9>:1:98' */
      /* '<S9>:1:99' */
      /* '<S9>:1:101' */
      sigmoid = 1.0;
    } else if (QD2_DroneStack_PID_2021a_B.Compare_c) {
      /* '<S9>:1:102' */
      /* '<S9>:1:103' */
      rtb_Relation_f = true;
    }
    break;

   case 4:
    if ((QD2_DroneStack_PID_2021a_B.DataTypeConversion4 != 0.0) ||
        QD2_DroneStack_PID_2021a_B.DataTypeConversion_pb[3] ||
        QD2_DroneStack_PID_2021a_B.RelationalOperator_g ||
        QD2_DroneStack_PID_2021a_B.OR ||
        QD2_DroneStack_PID_2021a_B.LogicalOperator2 ||
        QD2_DroneStack_PID_2021a_B.checkifmeasuredheightexceedsmax ||
        !QD2_DroneStack_PID_2021a_B.DataTypeConversion22) {
      /* '<S9>:1:108' */
      /* '<S9>:1:109' */
      /* '<S9>:1:110' */
      /* '<S9>:1:111' */
      /* '<S9>:1:112' */
      /* '<S9>:1:113' */
      /* '<S9>:1:115' */
      sigmoid = 1.0;
    } else if (!QD2_DroneStack_PID_2021a_B.DataTypeConversion23 ||
               QD2_DroneStack_PID_2021a_B.DataTypeConversion4_fx) {
      /* '<S9>:1:116' */
      /* '<S9>:1:117' */
      rtb_Relation_bl = true;
    } else if (QD2_DroneStack_PID_2021a_B.LogicalOperator_mx) {
      /* '<S9>:1:118' */
      /* '<S9>:1:119' */
      rtb_Relation_l = true;
    }
    break;

   case 5:
    if ((QD2_DroneStack_PID_2021a_B.DataTypeConversion4 != 0.0) ||
        QD2_DroneStack_PID_2021a_B.DataTypeConversion_pb[3] ||
        QD2_DroneStack_PID_2021a_B.RelationalOperator_g ||
        QD2_DroneStack_PID_2021a_B.OR ||
        QD2_DroneStack_PID_2021a_B.LogicalOperator2 ||
        QD2_DroneStack_PID_2021a_B.checkifmeasuredheightexceedsmax ||
        !QD2_DroneStack_PID_2021a_B.DataTypeConversion22) {
      /* '<S9>:1:124' */
      /* '<S9>:1:125' */
      /* '<S9>:1:126' */
      /* '<S9>:1:127' */
      /* '<S9>:1:128' */
      /* '<S9>:1:129' */
      /* '<S9>:1:131' */
      sigmoid = 1.0;
    } else if (!QD2_DroneStack_PID_2021a_B.DataTypeConversion23 ||
               QD2_DroneStack_PID_2021a_B.DataTypeConversion4_fx) {
      /* '<S9>:1:132' */
      /* '<S9>:1:133' */
      rtb_Relation_a = true;
    }
    break;

   case 6:
    if ((QD2_DroneStack_PID_2021a_B.DataTypeConversion4 != 0.0) ||
        QD2_DroneStack_PID_2021a_B.DataTypeConversion_pb[3] ||
        QD2_DroneStack_PID_2021a_B.RelationalOperator_g ||
        QD2_DroneStack_PID_2021a_B.OR ||
        QD2_DroneStack_PID_2021a_B.checkifmeasuredheightexceedsmax ||
        !QD2_DroneStack_PID_2021a_B.DataTypeConversion22) {
      /* '<S9>:1:138' */
      /* '<S9>:1:139' */
      /* '<S9>:1:140' */
      /* '<S9>:1:141' */
      /* '<S9>:1:142' */
      /* '<S9>:1:144' */
      sigmoid = 1.0;
    } else if (QD2_DroneStack_PID_2021a_B.LogicalOperator3_e) {
      /* '<S9>:1:145' */
      /* '<S9>:1:146' */
      rtb_AND3 = true;
    }
    break;

   case 7:
    if (QD2_DroneStack_PID_2021a_B.Compare1) {
      /* '<S9>:1:150' */
      /* '<S9>:1:151' */
      rtb_DataTypeConversion3_k = true;
    }
    break;

   case 8:
    /* '<S9>:1:155' */
    pt_EMERGENCY_ABORT_TO_DISABLE = true;
    break;

   case 9:
    /* DataTypeConversion: '<S1>/Data Type Conversion3' */
    /* '<S9>:1:159' */
    QD2_DroneStack_PID_2021a_B.DataTypeConversion3 = 1.0;
    break;
  }

  /* RelationalOperator: '<S14>/Relation' incorporates:
   *  Constant: '<S14>/threshold'
   */
  rtb_Relation_j = (QD2_DroneStack_PID_2021a_B.DataTypeConversion3 >=
                    QD2_DroneStack_PID_2021a_P.Threshold_threshold_pd);

  /* Logic: '<S14>/Logical Operator' */
  QD2_DroneStack_PID_2021a_B.LogicalOperator_bd = !rtb_Relation_j;
  if (rtb_Compare_f) {
    /* DiscreteIntegrator: '<S14>/Discrete-Time Integrator' */
    if (QD2_DroneStack_PID_2021a_B.LogicalOperator_bd ||
        (QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevRe_a != 0)) {
      QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTAT_ja =
        QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_l;
    }

    /* Stop: '<S1>/Stop Simulation' incorporates:
     *  Constant: '<S14>/duration'
     *  DiscreteIntegrator: '<S14>/Discrete-Time Integrator'
     *  RelationalOperator: '<S14>/Relational Operator'
     */
    if (QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTAT_ja >=
        QD2_DroneStack_PID_2021a_P.Threshold_duration_o) {
      rtmSetStopRequested(QD2_DroneStack_PID_2021a_M, true);
    }

    /* End of Stop: '<S1>/Stop Simulation' */

    /* DataTypeConversion: '<S10>/Data Type Conversion11' */
    QD2_DroneStack_PID_2021a_B.DataTypeConversion11 =
      QD2_DroneStack_PID_2021a_B.RelationalOperator_g;

    /* DataTypeConversion: '<S10>/Data Type Conversion10' */
    QD2_DroneStack_PID_2021a_B.DataTypeConversion10 =
      QD2_DroneStack_PID_2021a_B.DataTypeConversion4;

    /* DataTypeConversion: '<S10>/Data Type Conversion2' */
    QD2_DroneStack_PID_2021a_B.DataTypeConversion2 =
      QD2_DroneStack_PID_2021a_B.DataTypeConversion4_fx;
  }

  /* DataTypeConversion: '<S10>/Data Type Conversion12' */
  QD2_DroneStack_PID_2021a_B.DataTypeConversion12 = rtb_Relation;

  /* DataTypeConversion: '<S1>/Data Type Conversion6' incorporates:
   *  DataTypeConversion: '<S10>/Data Type Conversion14'
   */
  QD2_DroneStack_PID_2021a_B.DataTypeConversion6[0] =
    (QD2_DroneStack_PID_2021a_B.Memory != 0.0);
  QD2_DroneStack_PID_2021a_B.DataTypeConversion6[1] =
    (QD2_DroneStack_PID_2021a_B.DataTypeConversion12 != 0.0);
  QD2_DroneStack_PID_2021a_B.DataTypeConversion6[2] =
    (QD2_DroneStack_PID_2021a_B.DataTypeConversion11 != 0.0);
  QD2_DroneStack_PID_2021a_B.DataTypeConversion6[3] =
    (QD2_DroneStack_PID_2021a_B.DataTypeConversion10 != 0.0);
  QD2_DroneStack_PID_2021a_B.DataTypeConversion6[4] =
    (QD2_DroneStack_PID_2021a_B.DataTypeConversion2 != 0.0);
  QD2_DroneStack_PID_2021a_B.DataTypeConversion6[5] =
    QD2_DroneStack_PID_2021a_B.DataTypeConversion22;
  QD2_DroneStack_PID_2021a_B.DataTypeConversion6[6] =
    QD2_DroneStack_PID_2021a_B.DataTypeConversion23;
  QD2_DroneStack_PID_2021a_B.DataTypeConversion6[7] =
    QD2_DroneStack_PID_2021a_B.DataTypeConversion24;
  QD2_DroneStack_PID_2021a_B.DataTypeConversion6[8] =
    QD2_DroneStack_PID_2021a_B.DataTypeConversion_pb[3];
  QD2_DroneStack_PID_2021a_B.DataTypeConversion6[9] =
    QD2_DroneStack_PID_2021a_B.Compare_c;
  QD2_DroneStack_PID_2021a_B.DataTypeConversion6[10] =
    QD2_DroneStack_PID_2021a_B.Compare1;
  QD2_DroneStack_PID_2021a_B.DataTypeConversion6[11] =
    QD2_DroneStack_PID_2021a_B.Compare2;
  QD2_DroneStack_PID_2021a_B.DataTypeConversion6[12] =
    QD2_DroneStack_PID_2021a_B.LogicalOperator_mx;
  QD2_DroneStack_PID_2021a_B.DataTypeConversion6[13] =
    QD2_DroneStack_PID_2021a_B.LogicalOperator2;
  QD2_DroneStack_PID_2021a_B.DataTypeConversion6[14] =
    QD2_DroneStack_PID_2021a_B.checkifmeasuredheightexceedsmax;
  QD2_DroneStack_PID_2021a_B.DataTypeConversion6[15] =
    QD2_DroneStack_PID_2021a_B.LogicalOperator3_e;
  QD2_DroneStack_PID_2021a_B.DataTypeConversion6[16] =
    QD2_DroneStack_PID_2021a_B.OR;

  /* MATLAB Function: '<S1>/STATE MACHINE TRANSITION' incorporates:
   *  MATLAB Function: '<S1>/STATE MACHINE LOGIC'
   */
  QD2_DroneStack_PID_2021a_DW.sfEvent_e = QD2_DroneStack_PID_2_CALL_EVENT;

  /* MATLAB Function 'COMMANDER (ANGLE MODE)/STATE MACHINE TRANSITION': '<S11>:1' */
  /* '<S11>:1:29' */
  QD2_DroneStack_PID_2021a_B.Next_state = 0.0;
  switch ((int32_T)QD2_DroneStack_PID_2021a_B.Memory) {
   case 1:
    if (QD2_DroneStack_PID_2021a_B.DataTypeConversion24) {
      /* '<S11>:1:33' */
      /* '<S11>:1:34' */
      QD2_DroneStack_PID_2021a_B.Next_state = 8.0;
    } else if (sigmoid != 0.0) {
      /* '<S11>:1:36' */
      QD2_DroneStack_PID_2021a_B.Next_state = 7.0;
    } else if (rtb_AND2) {
      /* '<S11>:1:37' */
      /* '<S11>:1:38' */
      QD2_DroneStack_PID_2021a_B.Next_state = 2.0;
    } else {
      /* '<S11>:1:40' */
      QD2_DroneStack_PID_2021a_B.Next_state = 1.0;
    }
    break;

   case 2:
    if (QD2_DroneStack_PID_2021a_B.DataTypeConversion24) {
      /* '<S11>:1:44' */
      /* '<S11>:1:45' */
      QD2_DroneStack_PID_2021a_B.Next_state = 8.0;
    } else if (sigmoid != 0.0) {
      /* '<S11>:1:47' */
      QD2_DroneStack_PID_2021a_B.Next_state = 7.0;
    } else if (!rtb_AND2) {
      /* '<S11>:1:48' */
      /* '<S11>:1:49' */
      QD2_DroneStack_PID_2021a_B.Next_state = 1.0;
    } else if (rtb_Relation_en) {
      /* '<S11>:1:50' */
      /* '<S11>:1:51' */
      QD2_DroneStack_PID_2021a_B.Next_state = 3.0;
    } else {
      /* '<S11>:1:53' */
      QD2_DroneStack_PID_2021a_B.Next_state = 2.0;
    }
    break;

   case 3:
    if (QD2_DroneStack_PID_2021a_B.DataTypeConversion24) {
      /* '<S11>:1:57' */
      /* '<S11>:1:58' */
      QD2_DroneStack_PID_2021a_B.Next_state = 8.0;
    } else if (sigmoid != 0.0) {
      /* '<S11>:1:60' */
      QD2_DroneStack_PID_2021a_B.Next_state = 7.0;
    } else if (rtb_Relation_f) {
      /* '<S11>:1:61' */
      /* '<S11>:1:62' */
      QD2_DroneStack_PID_2021a_B.Next_state = 4.0;
    } else {
      /* '<S11>:1:64' */
      QD2_DroneStack_PID_2021a_B.Next_state = 3.0;
    }
    break;

   case 4:
    if (QD2_DroneStack_PID_2021a_B.DataTypeConversion24) {
      /* '<S11>:1:68' */
      /* '<S11>:1:69' */
      QD2_DroneStack_PID_2021a_B.Next_state = 8.0;
    } else if (sigmoid != 0.0) {
      /* '<S11>:1:71' */
      QD2_DroneStack_PID_2021a_B.Next_state = 7.0;
    } else if (rtb_Relation_bl) {
      /* '<S11>:1:72' */
      /* '<S11>:1:73' */
      QD2_DroneStack_PID_2021a_B.Next_state = 6.0;
    } else if (rtb_Relation_l) {
      /* '<S11>:1:74' */
      /* '<S11>:1:75' */
      QD2_DroneStack_PID_2021a_B.Next_state = 5.0;
    } else {
      /* '<S11>:1:77' */
      QD2_DroneStack_PID_2021a_B.Next_state = 4.0;
    }
    break;

   case 5:
    if (QD2_DroneStack_PID_2021a_B.DataTypeConversion24) {
      /* '<S11>:1:81' */
      /* '<S11>:1:82' */
      QD2_DroneStack_PID_2021a_B.Next_state = 8.0;
    } else if (sigmoid != 0.0) {
      /* '<S11>:1:84' */
      QD2_DroneStack_PID_2021a_B.Next_state = 7.0;
    } else if (rtb_Relation_a) {
      /* '<S11>:1:85' */
      /* '<S11>:1:86' */
      QD2_DroneStack_PID_2021a_B.Next_state = 6.0;
    } else {
      /* '<S11>:1:88' */
      QD2_DroneStack_PID_2021a_B.Next_state = 5.0;
    }
    break;

   case 6:
    if (QD2_DroneStack_PID_2021a_B.DataTypeConversion24) {
      /* '<S11>:1:92' */
      /* '<S11>:1:93' */
      QD2_DroneStack_PID_2021a_B.Next_state = 8.0;
    } else if (sigmoid != 0.0) {
      /* '<S11>:1:95' */
      QD2_DroneStack_PID_2021a_B.Next_state = 7.0;
    } else if (rtb_AND3) {
      /* '<S11>:1:96' */
      /* '<S11>:1:97' */
      QD2_DroneStack_PID_2021a_B.Next_state = 9.0;
    } else {
      /* '<S11>:1:99' */
      QD2_DroneStack_PID_2021a_B.Next_state = 6.0;
    }
    break;

   case 7:
    if (QD2_DroneStack_PID_2021a_B.DataTypeConversion24) {
      /* '<S11>:1:103' */
      /* '<S11>:1:104' */
      QD2_DroneStack_PID_2021a_B.Next_state = 8.0;
    } else if (rtb_DataTypeConversion3_k) {
      /* '<S11>:1:105' */
      /* '<S11>:1:106' */
      QD2_DroneStack_PID_2021a_B.Next_state = 9.0;
    } else {
      /* '<S11>:1:108' */
      QD2_DroneStack_PID_2021a_B.Next_state = 7.0;
    }
    break;

   case 8:
    if (pt_EMERGENCY_ABORT_TO_DISABLE) {
      /* '<S11>:1:112' */
      /* '<S11>:1:113' */
      QD2_DroneStack_PID_2021a_B.Next_state = 9.0;
    } else {
      /* '<S11>:1:115' */
      QD2_DroneStack_PID_2021a_B.Next_state = 8.0;
    }
    break;

   case 9:
    /* '<S11>:1:119' */
    QD2_DroneStack_PID_2021a_B.Next_state = 9.0;
    break;
  }

  /* End of MATLAB Function: '<S1>/STATE MACHINE TRANSITION' */

  /* DataTypeConversion: '<S1>/Data Type Conversion4' */
  QD2_DroneStack_PID_2021a_B.DataTypeConversion4_a =
    QD2_DroneStack_PID_2021a_B.Next_state;

  /* DataTypeConversion: '<S1>/Data Type Conversion2' */
  QD2_DroneStack_PID_2021a_B.DataTypeConversion2_l = sigmoid;
  if (rtb_Compare_f) {
    /* SignalConversion generated from: '<S1>/To Host File' */
    memcpy(&QD2_DroneStack_PID_2021a_B.TmpSignalConversionAtToHostFile[0],
           &QD2_DroneStack_PID_2021a_B.DataTypeConversion6[0], 17U * sizeof
           (real_T));
    QD2_DroneStack_PID_2021a_B.TmpSignalConversionAtToHostFile[17] =
      QD2_DroneStack_PID_2021a_B.DataTypeConversion4_a;
    QD2_DroneStack_PID_2021a_B.TmpSignalConversionAtToHostFile[18] =
      QD2_DroneStack_PID_2021a_B.DataTypeConversion2_l;
    QD2_DroneStack_PID_2021a_B.TmpSignalConversionAtToHostFile[19] =
      QD2_DroneStack_PID_2021a_B.DataTypeConversion3;
    QD2_DroneStack_PID_2021a_B.TmpSignalConversionAtToHostFile[20] =
      QD2_DroneStack_PID_2021a_B.StreamClient_o4[5];
    QD2_DroneStack_PID_2021a_B.TmpSignalConversionAtToHostFile[21] =
      QD2_DroneStack_PID_2021a_B.StreamClient_o4[6];
    QD2_DroneStack_PID_2021a_B.TmpSignalConversionAtToHostFile[22] =
      QD2_DroneStack_PID_2021a_B.StreamClient_o4[7];
    QD2_DroneStack_PID_2021a_B.TmpSignalConversionAtToHostFile[23] =
      QD2_DroneStack_PID_2021a_B.StreamClient_o4[10];
    QD2_DroneStack_PID_2021a_B.TmpSignalConversionAtToHostFile[24] =
      QD2_DroneStack_PID_2021a_B.Switch2_m[0];
    QD2_DroneStack_PID_2021a_B.TmpSignalConversionAtToHostFile[25] =
      QD2_DroneStack_PID_2021a_B.Switch2_m[1];
    QD2_DroneStack_PID_2021a_B.TmpSignalConversionAtToHostFile[26] =
      QD2_DroneStack_PID_2021a_B.Switch2_m[2];
    QD2_DroneStack_PID_2021a_B.TmpSignalConversionAtToHostFile[27] =
      QD2_DroneStack_PID_2021a_B.Switch2_m[3];
    QD2_DroneStack_PID_2021a_B.TmpSignalConversionAtToHostFile[28] =
      QD2_DroneStack_PID_2021a_B.Integrator1_o[0];
    QD2_DroneStack_PID_2021a_B.TmpSignalConversionAtToHostFile[30] =
      QD2_DroneStack_PID_2021a_B.UnsaturatedControllerCommandsNr[2];
    QD2_DroneStack_PID_2021a_B.TmpSignalConversionAtToHostFile[29] =
      QD2_DroneStack_PID_2021a_B.Integrator1_o[1];
    QD2_DroneStack_PID_2021a_B.TmpSignalConversionAtToHostFile[31] =
      QD2_DroneStack_PID_2021a_B.UnsaturatedControllerCommandsNr[3];
    QD2_DroneStack_PID_2021a_B.TmpSignalConversionAtToHostFile[32] =
      QD2_DroneStack_PID_2021a_B.GeneralizedCommandNradradrads4[0];
    QD2_DroneStack_PID_2021a_B.TmpSignalConversionAtToHostFile[33] =
      QD2_DroneStack_PID_2021a_B.GeneralizedCommandNradradrads4[1];
    QD2_DroneStack_PID_2021a_B.TmpSignalConversionAtToHostFile[34] =
      QD2_DroneStack_PID_2021a_B.GeneralizedCommandNradradrads4[2];
    QD2_DroneStack_PID_2021a_B.TmpSignalConversionAtToHostFile[35] =
      QD2_DroneStack_PID_2021a_B.GeneralizedCommandNradradrads4[3];

    /* Gain: '<S1>/Gain1' incorporates:
     *  Gain: '<S1>/Ki (rad s // m, rad s // m, N s//m, rad//s // rad//s)'
     */
    QD2_DroneStack_PID_2021a_B.Gain1[0] =
      QD2_DroneStack_PID_2021a_P.KiradsmradsmNsmradsrads_Gain[0] *
      rtb_Product_h_idx_0 * QD2_DroneStack_PID_2021a_P.Gain1_Gain_h[0];
    QD2_DroneStack_PID_2021a_B.Gain1[1] =
      QD2_DroneStack_PID_2021a_P.KiradsmradsmNsmradsrads_Gain[1] *
      rtb_Product_h_idx_1 * QD2_DroneStack_PID_2021a_P.Gain1_Gain_h[1];
    QD2_DroneStack_PID_2021a_B.Gain1[2] =
      QD2_DroneStack_PID_2021a_P.KiradsmradsmNsmradsrads_Gain[2] *
      rtb_Product_h_idx_2 * QD2_DroneStack_PID_2021a_P.Gain1_Gain_h[2];
    QD2_DroneStack_PID_2021a_B.Gain1[3] =
      QD2_DroneStack_PID_2021a_P.KiradsmradsmNsmradsrads_Gain[3] *
      rtb_KiradsmradsmNsmradsrads[3] * QD2_DroneStack_PID_2021a_P.Gain1_Gain_h[3];

    /* DataTypeConversion: '<S10>/Data Type Conversion9' */
    QD2_DroneStack_PID_2021a_B.DataTypeConversion9[0] =
      QD2_DroneStack_PID_2021a_B.DataTypeConversion22;
    QD2_DroneStack_PID_2021a_B.DataTypeConversion9[1] =
      QD2_DroneStack_PID_2021a_B.DataTypeConversion23;
    QD2_DroneStack_PID_2021a_B.DataTypeConversion9[2] =
      QD2_DroneStack_PID_2021a_B.DataTypeConversion24;
    QD2_DroneStack_PID_2021a_B.DataTypeConversion9[3] =
      QD2_DroneStack_PID_2021a_B.DataTypeConversion_pb[3];

    /* DataTypeConversion: '<S10>/Data Type Conversion5' */
    QD2_DroneStack_PID_2021a_B.SensorIssue = QD2_DroneStack_PID_2021a_B.OR;
  }

  /* SignalConversion generated from: '<S16>/Boolean Edge-Based Triggered Print' */
  QD2_DroneStack_PID_2021a_B.TmpSignalConversionAtBooleanEdg[0] = rtb_Relation;
  QD2_DroneStack_PID_2021a_B.TmpSignalConversionAtBooleanEdg[1] =
    QD2_DroneStack_PID_2021a_B.DataTypeConversion22;
  QD2_DroneStack_PID_2021a_B.TmpSignalConversionAtBooleanEdg[2] =
    QD2_DroneStack_PID_2021a_B.DataTypeConversion23;
  if (rtb_Compare_f) {
    /* S-Function (string_constant_block): '<S16>/String Constant16' */

    /* S-Function Block: QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/STATE MACHINE SIGNALS/Generate Extra Messages for Console/String Constant16 (string_constant_block) */
    {
      size_t length;
      length = 80;
      utf8_string_copy_characters((t_utf8_char*)
        &QD2_DroneStack_PID_2021a_B.MatrixConcatenate[0], length, (const
        t_utf8_char*) QD2_DroneStack_PID_2021a_P.StringConstant16_Value);
    }

    /* S-Function (string_constant_block): '<S16>/String Constant12' */

    /* S-Function Block: QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/STATE MACHINE SIGNALS/Generate Extra Messages for Console/String Constant12 (string_constant_block) */
    {
      size_t length;
      length = 80;
      utf8_string_copy_characters((t_utf8_char*)
        &QD2_DroneStack_PID_2021a_B.MatrixConcatenate[80], length, (const
        t_utf8_char*) QD2_DroneStack_PID_2021a_P.StringConstant12_Value);
    }

    /* S-Function (string_constant_block): '<S16>/String Constant13' */

    /* S-Function Block: QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/STATE MACHINE SIGNALS/Generate Extra Messages for Console/String Constant13 (string_constant_block) */
    {
      size_t length;
      length = 80;
      utf8_string_copy_characters((t_utf8_char*)
        &QD2_DroneStack_PID_2021a_B.MatrixConcatenate[160], length, (const
        t_utf8_char*) QD2_DroneStack_PID_2021a_P.StringConstant13_Value);
    }

    /* S-Function (time_block): '<S10>/Time' */

    /* S-Function Block: QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/STATE MACHINE SIGNALS/Time (time_block) */
    {
      t_error result;
      t_timeout current_time;
      t_timeout time_difference;
      result = timeout_get_high_resolution_time(&current_time);
      if (result == 0) {
        result = timeout_subtract(&time_difference, &current_time,
          &_high_resolution_start_time);
        rtb_Time_d = time_difference.seconds + time_difference.nanoseconds *
          1e-9;
      }

      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M, _rt_error_message);
        return;
      }
    }
  }

  /* Outputs for Iterator SubSystem: '<S16>/Boolean Edge-Based Triggered Print' incorporates:
   *  ForEach: '<S25>/For Each'
   */
  for (ForEach_itr_b = 0; ForEach_itr_b < 3; ForEach_itr_b++) {
    /* ForEachSliceSelector generated from: '<S25>/Message' incorporates:
     *  Concatenate: '<S16>/Matrix Concatenate'
     */
    for (i = 0; i < 80; i++) {
      rtb_MultiportSwitch_o[i] = QD2_DroneStack_PID_2021a_B.MatrixConcatenate[80
        * ForEach_itr_b + i];
    }

    /* End of ForEachSliceSelector generated from: '<S25>/Message' */
    if (rtmIsMajorTimeStep(QD2_DroneStack_PID_2021a_M)) {
      /* Outputs for Triggered SubSystem: '<S25>/Triggered Subsystem1' incorporates:
       *  TriggerPort: '<S26>/Trigger'
       */
      if (rtsiIsModeUpdateTimeStep(&QD2_DroneStack_PID_2021a_M->solverInfo)) {
        /* ForEachSliceSelector generated from: '<S25>/Signal Enable' */
        if (!QD2_DroneStack_PID_2021a_B.TmpSignalConversionAtBooleanEdg[ForEach_itr_b]
            && (QD2_DroneStack_PID_2021_PrevZCX.CoreSubsys[ForEach_itr_b].
                TriggeredSubsystem1_Trig_ZCE != ZERO_ZCSIG)) {
          /* S-Function (print_block): '<S26>/Print' */

          /* S-Function Block: QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/STATE MACHINE SIGNALS/Generate Extra Messages for Console/Boolean Edge-Based Triggered Print/Triggered Subsystem1/Print (print_block) */
          {
            t_error result;
            size_t length;
            t_error string_result = 0;
            length = string_length((const char *) &rtb_MultiportSwitch_o[0], 80);
            if (length == 80) {
              string_result = -QERR_STRING_NOT_TERMINATED;
            }

            if (string_result >= 0) {
              result = console_print
                (QD2_DroneStack_PID_2021a_P.CoreSubsys.Print_MaxUnits,
                 &rtb_Print_o1_l, "[ %lf ] (s): %s !\n"
                 , (double) rtb_Time_d
                 , &rtb_MultiportSwitch_o[0]
                 );
              if (result >= 0) {
                console_flush();
              }
            }
          }

          QD2_DroneStack_PID_2021a_DW.CoreSubsys[ForEach_itr_b].
            TriggeredSubsystem1_SubsysRanBC = 4;
        }

        QD2_DroneStack_PID_2021_PrevZCX.CoreSubsys[ForEach_itr_b].
          TriggeredSubsystem1_Trig_ZCE =
          QD2_DroneStack_PID_2021a_B.TmpSignalConversionAtBooleanEdg[ForEach_itr_b];

        /* End of ForEachSliceSelector generated from: '<S25>/Signal Enable' */
      }

      /* End of Outputs for SubSystem: '<S25>/Triggered Subsystem1' */
    }
  }

  /* End of Outputs for SubSystem: '<S16>/Boolean Edge-Based Triggered Print' */
  if (rtb_Compare_f) {
    /* MultiPortSwitch: '<S17>/Multiport Switch' incorporates:
     *  S-Function (string_constant_block): '<S17>/String Constant1'
     *  S-Function (string_constant_block): '<S17>/String Constant2'
     *  S-Function (string_constant_block): '<S17>/String Constant3'
     *  S-Function (string_constant_block): '<S17>/String Constant4'
     *  S-Function (string_constant_block): '<S17>/String Constant5'
     *  S-Function (string_constant_block): '<S17>/String Constant6'
     *  S-Function (string_constant_block): '<S17>/String Constant7'
     *  S-Function (string_constant_block): '<S17>/String Constant8'
     *  S-Function (string_constant_block): '<S17>/String Constant9'
     */
    switch ((int32_T)QD2_DroneStack_PID_2021a_B.Memory) {
     case 1:
      for (i = 0; i < 80; i++) {
        rtb_MultiportSwitch_o[i] =
          (QD2_DroneStack_PID_2021a_P.StringConstant5_Value[i]);
      }
      break;

     case 2:
      for (i = 0; i < 80; i++) {
        rtb_MultiportSwitch_o[i] =
          (QD2_DroneStack_PID_2021a_P.StringConstant1_Value[i]);
      }
      break;

     case 3:
      for (i = 0; i < 80; i++) {
        rtb_MultiportSwitch_o[i] =
          (QD2_DroneStack_PID_2021a_P.StringConstant2_Value[i]);
      }
      break;

     case 4:
      for (i = 0; i < 80; i++) {
        rtb_MultiportSwitch_o[i] =
          (QD2_DroneStack_PID_2021a_P.StringConstant3_Value[i]);
      }
      break;

     case 5:
      for (i = 0; i < 80; i++) {
        rtb_MultiportSwitch_o[i] =
          (QD2_DroneStack_PID_2021a_P.StringConstant6_Value[i]);
      }
      break;

     case 6:
      for (i = 0; i < 80; i++) {
        rtb_MultiportSwitch_o[i] =
          (QD2_DroneStack_PID_2021a_P.StringConstant9_Value[i]);
      }
      break;

     case 7:
      for (i = 0; i < 80; i++) {
        rtb_MultiportSwitch_o[i] =
          (QD2_DroneStack_PID_2021a_P.StringConstant4_Value[i]);
      }
      break;

     case 8:
      for (i = 0; i < 80; i++) {
        rtb_MultiportSwitch_o[i] =
          (QD2_DroneStack_PID_2021a_P.StringConstant7_Value[i]);
      }
      break;

     default:
      for (i = 0; i < 80; i++) {
        rtb_MultiportSwitch_o[i] =
          (QD2_DroneStack_PID_2021a_P.StringConstant8_Value[i]);
      }
      break;
    }

    /* End of MultiPortSwitch: '<S17>/Multiport Switch' */

    /* RelationalOperator: '<S27>/FixPt Relational Operator' incorporates:
     *  UnitDelay: '<S27>/Delay Input1'
     */
    rtb_AND2 = (QD2_DroneStack_PID_2021a_B.Memory !=
                QD2_DroneStack_PID_2021a_DW.DelayInput1_DSTATE);

    /* Outputs for Triggered SubSystem: '<S17>/Triggered Subsystem' incorporates:
     *  TriggerPort: '<S28>/Trigger'
     */
    if (rtsiIsModeUpdateTimeStep(&QD2_DroneStack_PID_2021a_M->solverInfo)) {
      if (rtb_AND2 &&
          (QD2_DroneStack_PID_2021_PrevZCX.TriggeredSubsystem_Trig_ZCE_g !=
           POS_ZCSIG)) {
        /* S-Function (print_block): '<S28>/Print' */

        /* S-Function Block: QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/STATE MACHINE SIGNALS/Generate State Messages for Console/Triggered Subsystem/Print (print_block) */
        {
          t_error result;
          size_t length;
          t_error string_result = 0;
          length = string_length((const char *) &rtb_MultiportSwitch_o[0], 80);
          if (length == 80) {
            string_result = -QERR_STRING_NOT_TERMINATED;
          }

          if (string_result >= 0) {
            result = console_print(QD2_DroneStack_PID_2021a_P.Print_MaxUnits,
              &rtb_Print_o1_h, "[ %lf ] (s): State %u  => %s \n"
              , (double) rtb_Time_d
              , (unsigned int) QD2_DroneStack_PID_2021a_B.Memory
              , &rtb_MultiportSwitch_o[0]
              );
            if (result >= 0) {
              console_flush();
            }
          }
        }

        QD2_DroneStack_PID_2021a_DW.TriggeredSubsystem_SubsysRanBC = 4;
      }

      QD2_DroneStack_PID_2021_PrevZCX.TriggeredSubsystem_Trig_ZCE_g = rtb_AND2;
    }

    /* End of Outputs for SubSystem: '<S17>/Triggered Subsystem' */

    /* DataTypeConversion: '<S24>/Data Type Conversion2' */
    QD2_DroneStack_PID_2021a_B.DataTypeConversion2_o =
      (QD2_DroneStack_PID_2021a_B.DataTypeConversion2 != 0.0);

    /* DataTypeConversion: '<S24>/Data Type Conversion5' */
    QD2_DroneStack_PID_2021a_B.DataTypeConversion5_c =
      QD2_DroneStack_PID_2021a_B.OR;

    /* DataTypeConversion: '<S24>/Data Type Conversion' */
    QD2_DroneStack_PID_2021a_B.DataTypeConversion_f =
      (QD2_DroneStack_PID_2021a_B.DataTypeConversion10 != 0.0);

    /* DataTypeConversion: '<S24>/Data Type Conversion8' incorporates:
     *  Logic: '<S24>/AND6'
     *  Logic: '<S24>/NOT6'
     */
    QD2_DroneStack_PID_2021a_B.DataTypeConversion8 =
      (!QD2_DroneStack_PID_2021a_B.DataTypeConversion_f &&
       QD2_DroneStack_PID_2021a_B.DataTypeConversion_pb[3]);

    /* Logic: '<S24>/AND' incorporates:
     *  Logic: '<S24>/NOT1'
     */
    rtb_AND2 = (!QD2_DroneStack_PID_2021a_B.DataTypeConversion22 &&
                QD2_DroneStack_PID_2021a_B.DataTypeConversion23);

    /* DataTypeConversion: '<S24>/Data Type Conversion14' incorporates:
     *  Logic: '<S24>/AND1'
     *  Logic: '<S24>/NOT7'
     */
    QD2_DroneStack_PID_2021a_B.DataTypeConversion14 =
      (!QD2_DroneStack_PID_2021a_B.DataTypeConversion_f &&
       !QD2_DroneStack_PID_2021a_B.DataTypeConversion_pb[3] && rtb_AND2);

    /* Logic: '<S24>/NOT5' incorporates:
     *  Logic: '<S24>/NOT2'
     *  Logic: '<S24>/NOT3'
     *  Logic: '<S24>/NOT4'
     */
    rtb_Relation_en = !rtb_AND2;

    /* DataTypeConversion: '<S24>/Data Type Conversion9' incorporates:
     *  DataTypeConversion: '<S24>/Data Type Conversion3'
     *  Logic: '<S24>/AND5'
     *  Logic: '<S24>/NOT5'
     */
    QD2_DroneStack_PID_2021a_B.DataTypeConversion9_m =
      (!QD2_DroneStack_PID_2021a_B.DataTypeConversion_f &&
       !QD2_DroneStack_PID_2021a_B.DataTypeConversion_pb[3] && rtb_Relation_en &&
       (QD2_DroneStack_PID_2021a_B.DataTypeConversion11 != 0.0));

    /* DataTypeConversion: '<S24>/Data Type Conversion10' incorporates:
     *  DataTypeConversion: '<S24>/Data Type Conversion3'
     *  Logic: '<S24>/AND4'
     *  Logic: '<S24>/NOT4'
     */
    QD2_DroneStack_PID_2021a_B.DataTypeConversion10_a =
      (!QD2_DroneStack_PID_2021a_B.DataTypeConversion_f &&
       !QD2_DroneStack_PID_2021a_B.DataTypeConversion_pb[3] && rtb_Relation_en &&
       !(QD2_DroneStack_PID_2021a_B.DataTypeConversion11 != 0.0) &&
       QD2_DroneStack_PID_2021a_B.LogicalOperator2);

    /* Logic: '<S24>/AND3' incorporates:
     *  DataTypeConversion: '<S24>/Data Type Conversion3'
     *  Logic: '<S24>/NOT3'
     */
    tmpForInput[0] = !QD2_DroneStack_PID_2021a_B.DataTypeConversion_f;
    tmpForInput[1] = !QD2_DroneStack_PID_2021a_B.DataTypeConversion_pb[3];
    tmpForInput[2] = rtb_Relation_en;
    tmpForInput[3] = !(QD2_DroneStack_PID_2021a_B.DataTypeConversion11 != 0.0);
    tmpForInput[4] = !QD2_DroneStack_PID_2021a_B.LogicalOperator2;
    tmpForInput[5] = QD2_DroneStack_PID_2021a_B.checkifmeasuredheightexceedsmax;
    rtb_Relation = tmpForInput[0];
    for (i = 0; i < 5; i++) {
      rtb_Relation = (rtb_Relation && tmpForInput[i + 1]);
    }

    /* DataTypeConversion: '<S24>/Data Type Conversion11' incorporates:
     *  Logic: '<S24>/AND3'
     */
    QD2_DroneStack_PID_2021a_B.DataTypeConversion11_h = rtb_Relation;

    /* Logic: '<S24>/AND2' incorporates:
     *  DataTypeConversion: '<S24>/Data Type Conversion3'
     *  Logic: '<S24>/NOT2'
     */
    tmpForInput_0[0] = !QD2_DroneStack_PID_2021a_B.DataTypeConversion_f;
    tmpForInput_0[1] = !QD2_DroneStack_PID_2021a_B.DataTypeConversion_pb[3];
    tmpForInput_0[2] = rtb_Relation_en;
    tmpForInput_0[3] = !(QD2_DroneStack_PID_2021a_B.DataTypeConversion11 != 0.0);
    tmpForInput_0[4] = !QD2_DroneStack_PID_2021a_B.LogicalOperator2;
    tmpForInput_0[5] =
      !QD2_DroneStack_PID_2021a_B.checkifmeasuredheightexceedsmax;
    tmpForInput_0[6] = QD2_DroneStack_PID_2021a_B.DataTypeConversion24;
    rtb_Relation = tmpForInput_0[0];
    for (i = 0; i < 6; i++) {
      rtb_Relation = (rtb_Relation && tmpForInput_0[i + 1]);
    }

    /* DataTypeConversion: '<S24>/Data Type Conversion12' incorporates:
     *  Logic: '<S24>/AND2'
     */
    QD2_DroneStack_PID_2021a_B.DataTypeConversion12_i = rtb_Relation;

    /* SignalConversion generated from: '<S18>/Boolean Value-Based Triggered Print' */
    rtb_TmpSignalConversionAtBoolea[0] =
      QD2_DroneStack_PID_2021a_B.DataTypeConversion2_o;
    rtb_TmpSignalConversionAtBoolea[1] =
      QD2_DroneStack_PID_2021a_B.DataTypeConversion5_c;
    rtb_TmpSignalConversionAtBoolea[2] =
      QD2_DroneStack_PID_2021a_B.DataTypeConversion_f;
    rtb_TmpSignalConversionAtBoolea[3] =
      QD2_DroneStack_PID_2021a_B.DataTypeConversion8;
    rtb_TmpSignalConversionAtBoolea[4] =
      QD2_DroneStack_PID_2021a_B.DataTypeConversion14;
    rtb_TmpSignalConversionAtBoolea[5] =
      QD2_DroneStack_PID_2021a_B.DataTypeConversion9_m;
    rtb_TmpSignalConversionAtBoolea[6] =
      QD2_DroneStack_PID_2021a_B.DataTypeConversion10_a;
    rtb_TmpSignalConversionAtBoolea[7] =
      QD2_DroneStack_PID_2021a_B.DataTypeConversion11_h;
    rtb_TmpSignalConversionAtBoolea[8] =
      QD2_DroneStack_PID_2021a_B.DataTypeConversion12_i;

    /* S-Function (string_constant_block): '<S18>/String Constant' */

    /* S-Function Block: QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/STATE MACHINE SIGNALS/Generate Warning Messages for Console/String Constant (string_constant_block) */
    {
      size_t length;
      length = 80;
      utf8_string_copy_characters((t_utf8_char*) &rtb_MatrixConcatenate[0],
        length, (const t_utf8_char*)
        QD2_DroneStack_PID_2021a_P.StringConstant_Value);
    }

    /* S-Function (string_constant_block): '<S18>/String Constant1' */

    /* S-Function Block: QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/STATE MACHINE SIGNALS/Generate Warning Messages for Console/String Constant1 (string_constant_block) */
    {
      size_t length;
      length = 80;
      utf8_string_copy_characters((t_utf8_char*) &rtb_MatrixConcatenate[80],
        length, (const t_utf8_char*)
        QD2_DroneStack_PID_2021a_P.StringConstant1_Value_g);
    }

    /* S-Function (string_constant_block): '<S18>/String Constant2' */

    /* S-Function Block: QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/STATE MACHINE SIGNALS/Generate Warning Messages for Console/String Constant2 (string_constant_block) */
    {
      size_t length;
      length = 80;
      utf8_string_copy_characters((t_utf8_char*) &rtb_MatrixConcatenate[160],
        length, (const t_utf8_char*)
        QD2_DroneStack_PID_2021a_P.StringConstant2_Value_k);
    }

    /* S-Function (string_constant_block): '<S18>/String Constant3' */

    /* S-Function Block: QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/STATE MACHINE SIGNALS/Generate Warning Messages for Console/String Constant3 (string_constant_block) */
    {
      size_t length;
      length = 80;
      utf8_string_copy_characters((t_utf8_char*) &rtb_MatrixConcatenate[240],
        length, (const t_utf8_char*)
        QD2_DroneStack_PID_2021a_P.StringConstant3_Value_i);
    }

    /* S-Function (string_constant_block): '<S18>/String Constant8' */

    /* S-Function Block: QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/STATE MACHINE SIGNALS/Generate Warning Messages for Console/String Constant8 (string_constant_block) */
    {
      size_t length;
      length = 80;
      utf8_string_copy_characters((t_utf8_char*) &rtb_MatrixConcatenate[320],
        length, (const t_utf8_char*)
        QD2_DroneStack_PID_2021a_P.StringConstant8_Value_b);
    }

    /* S-Function (string_constant_block): '<S18>/String Constant4' */

    /* S-Function Block: QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/STATE MACHINE SIGNALS/Generate Warning Messages for Console/String Constant4 (string_constant_block) */
    {
      size_t length;
      length = 80;
      utf8_string_copy_characters((t_utf8_char*) &rtb_MatrixConcatenate[400],
        length, (const t_utf8_char*)
        QD2_DroneStack_PID_2021a_P.StringConstant4_Value_i);
    }

    /* S-Function (string_constant_block): '<S18>/String Constant5' */

    /* S-Function Block: QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/STATE MACHINE SIGNALS/Generate Warning Messages for Console/String Constant5 (string_constant_block) */
    {
      size_t length;
      length = 80;
      utf8_string_copy_characters((t_utf8_char*) &rtb_MatrixConcatenate[480],
        length, (const t_utf8_char*)
        QD2_DroneStack_PID_2021a_P.StringConstant5_Value_n);
    }

    /* S-Function (string_constant_block): '<S18>/String Constant6' */

    /* S-Function Block: QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/STATE MACHINE SIGNALS/Generate Warning Messages for Console/String Constant6 (string_constant_block) */
    {
      size_t length;
      length = 80;
      utf8_string_copy_characters((t_utf8_char*) &rtb_MatrixConcatenate[560],
        length, (const t_utf8_char*)
        QD2_DroneStack_PID_2021a_P.StringConstant6_Value_k);
    }

    /* S-Function (string_constant_block): '<S18>/String Constant7' */

    /* S-Function Block: QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/STATE MACHINE SIGNALS/Generate Warning Messages for Console/String Constant7 (string_constant_block) */
    {
      size_t length;
      length = 80;
      utf8_string_copy_characters((t_utf8_char*) &rtb_MatrixConcatenate[640],
        length, (const t_utf8_char*)
        QD2_DroneStack_PID_2021a_P.StringConstant7_Value_d);
    }

    /* Outputs for Iterator SubSystem: '<S18>/Boolean Value-Based Triggered Print' incorporates:
     *  ForEach: '<S29>/For Each'
     */
    for (ForEach_itr_h = 0; ForEach_itr_h < 9; ForEach_itr_h++) {
      /* ForEachSliceSelector generated from: '<S29>/Message' incorporates:
       *  Concatenate: '<S18>/Matrix Concatenate'
       */
      for (i = 0; i < 80; i++) {
        rtb_MultiportSwitch_o[i] = rtb_MatrixConcatenate[80 * ForEach_itr_h + i];
      }

      /* End of ForEachSliceSelector generated from: '<S29>/Message' */

      /* Outputs for Triggered SubSystem: '<S29>/Triggered Subsystem' incorporates:
       *  TriggerPort: '<S30>/Trigger'
       */
      /* ForEachSliceSelector generated from: '<S29>/Signal Enable' */
      if (rtb_TmpSignalConversionAtBoolea[ForEach_itr_h] &&
          (QD2_DroneStack_PID_2021_PrevZCX.CoreSubsys_p[ForEach_itr_h].
           TriggeredSubsystem_Trig_ZCE != POS_ZCSIG)) {
        /* S-Function (print_block): '<S30>/Print' */

        /* S-Function Block: QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/STATE MACHINE SIGNALS/Generate Warning Messages for Console/Boolean Value-Based Triggered Print/Triggered Subsystem/Print (print_block) */
        {
          t_error result;
          size_t length;
          t_error string_result = 0;
          length = string_length((const char *) &rtb_MultiportSwitch_o[0], 80);
          if (length == 80) {
            string_result = -QERR_STRING_NOT_TERMINATED;
          }

          if (string_result >= 0) {
            result = console_print
              (QD2_DroneStack_PID_2021a_P.CoreSubsys_p.Print_MaxUnits,
               &rtb_Print_o1, "[ %lf ] (s): %s\n"
               , (double) rtb_Time_d
               , &rtb_MultiportSwitch_o[0]
               );
            if (result >= 0) {
              console_flush();
            }
          }
        }

        QD2_DroneStack_PID_2021a_DW.CoreSubsys_p[ForEach_itr_h].
          TriggeredSubsystem_SubsysRanBC = 4;
      }

      QD2_DroneStack_PID_2021_PrevZCX.CoreSubsys_p[ForEach_itr_h].
        TriggeredSubsystem_Trig_ZCE =
        rtb_TmpSignalConversionAtBoolea[ForEach_itr_h];

      /* End of ForEachSliceSelector generated from: '<S29>/Signal Enable' */
      /* End of Outputs for SubSystem: '<S29>/Triggered Subsystem' */
    }

    /* End of Outputs for SubSystem: '<S18>/Boolean Value-Based Triggered Print' */
  }

  /* DataTypeConversion: '<S21>/Data Type Conversion' */
  QD2_DroneStack_PID_2021a_B.DataTypeConversion_e3 = rtb_Relation_k;
  if (rtb_Compare_f) {
  }

  /* Product: '<S39>/Product' incorporates:
   *  Constant: '<S12>/Constant4'
   *  Constant: '<S12>/Constant5'
   *  Constant: '<S39>/Constant'
   *  Integrator: '<S39>/Integrator2'
   *  Product: '<S39>/Product2'
   *  Sum: '<S39>/Sum'
   *  Sum: '<S39>/Sum1'
   */
  QD2_DroneStack_PID_2021a_B.Product_i[0] =
    ((QD2_DroneStack_PID_2021a_B.UnsaturatedControllerCommandsNr[0] -
      QD2_DroneStack_PID_2021a_B.Integrator1_o[0]) -
     QD2_DroneStack_PID_2021a_X.Integrator2_CSTATE[0] *
     QD2_DroneStack_PID_2021a_P.Constant_Value_f *
     QD2_DroneStack_PID_2021a_P.Constant4_Value_m) *
    QD2_DroneStack_PID_2021a_P.Constant5_Value_h;

  /* Product: '<S39>/Product1' incorporates:
   *  Constant: '<S12>/Constant5'
   *  Integrator: '<S39>/Integrator2'
   */
  QD2_DroneStack_PID_2021a_B.Product1_m[0] =
    QD2_DroneStack_PID_2021a_P.Constant5_Value_h *
    QD2_DroneStack_PID_2021a_X.Integrator2_CSTATE[0];

  /* Product: '<S39>/Product' incorporates:
   *  Constant: '<S12>/Constant4'
   *  Constant: '<S12>/Constant5'
   *  Constant: '<S39>/Constant'
   *  Integrator: '<S39>/Integrator2'
   *  Product: '<S39>/Product2'
   *  Sum: '<S39>/Sum'
   *  Sum: '<S39>/Sum1'
   */
  QD2_DroneStack_PID_2021a_B.Product_i[1] =
    ((QD2_DroneStack_PID_2021a_B.UnsaturatedControllerCommandsNr[1] -
      QD2_DroneStack_PID_2021a_B.Integrator1_o[1]) -
     QD2_DroneStack_PID_2021a_X.Integrator2_CSTATE[1] *
     QD2_DroneStack_PID_2021a_P.Constant_Value_f *
     QD2_DroneStack_PID_2021a_P.Constant4_Value_m) *
    QD2_DroneStack_PID_2021a_P.Constant5_Value_h;

  /* Product: '<S39>/Product1' incorporates:
   *  Constant: '<S12>/Constant5'
   *  Integrator: '<S39>/Integrator2'
   */
  QD2_DroneStack_PID_2021a_B.Product1_m[1] =
    QD2_DroneStack_PID_2021a_P.Constant5_Value_h *
    QD2_DroneStack_PID_2021a_X.Integrator2_CSTATE[1];
  if (rtb_Compare_f) {
    /* Outputs for Enabled SubSystem: '<S13>/Use desired height when enabled' */
    Usedesiredheightwhenenabled(QD2_DroneStack_PID_2021a_M,
      QD2_DroneStack_PID_2021a_B.enable_d,
      QD2_DroneStack_PID_2021a_B.throttle_ref,
      &QD2_DroneStack_PID_2021a_B.Usedesiredheightwhenenabled_c,
      &QD2_DroneStack_PID_2021a_DW.Usedesiredheightwhenenabled_c,
      &QD2_DroneStack_PID_2021a_P.Usedesiredheightwhenenabled_c);

    /* End of Outputs for SubSystem: '<S13>/Use desired height when enabled' */
  }

  /* DataTypeConversion: '<S14>/Data Type Conversion' */
  QD2_DroneStack_PID_2021a_B.DataTypeConversion_i = rtb_Relation_j;
  if (rtb_Compare_f) {
    /* DataTypeConversion: '<S49>/Data Type Conversion' */
    QD2_DroneStack_PID_2021a_B.DataTypeConversion_ni = rtb_RelationalOperator;

    /* DataTypeConversion: '<S50>/Data Type Conversion' */
    QD2_DroneStack_PID_2021a_B.DataTypeConversion_l2 = rtb_Relation_m;
  }

  /* Integrator: '<S3>/Integrator2' incorporates:
   *  Integrator: '<S3>/Integrator7'
   */
  if (rtsiIsModeUpdateTimeStep(&QD2_DroneStack_PID_2021a_M->solverInfo)) {
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &QD2_DroneStack_PID_2021_PrevZCX.Integrator2_Reset_ZCE,
                       (QD2_DroneStack_PID_2021a_B.StreamClient_o4[1]));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      QD2_DroneStack_PID_2021a_X.Integrator2_CSTATE_o =
        QD2_DroneStack_PID_2021a_P.Integrator2_IC_g;
    }

    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &QD2_DroneStack_PID_2021_PrevZCX.Integrator7_Reset_ZCE,
                       (QD2_DroneStack_PID_2021a_B.StreamClient_o4[1]));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      QD2_DroneStack_PID_2021a_X.Integrator7_CSTATE[0] =
        QD2_DroneStack_PID_2021a_P.Integrator7_IC;
      QD2_DroneStack_PID_2021a_X.Integrator7_CSTATE[1] =
        QD2_DroneStack_PID_2021a_P.Integrator7_IC;
      QD2_DroneStack_PID_2021a_X.Integrator7_CSTATE[2] =
        QD2_DroneStack_PID_2021a_P.Integrator7_IC;
    }
  }

  /* Sum: '<S3>/Sum1' */
  sigmoid = QD2_DroneStack_PID_2021a_B.Integrator1 -
    QD2_DroneStack_PID_2021a_B.StreamClient_o4[10];

  /* Gain: '<S3>/Ki1' */
  QD2_DroneStack_PID_2021a_B.Ki1 = QD2_DroneStack_PID_2021a_P.Ki1_Gain * sigmoid;

  /* Product: '<S52>/Product1' incorporates:
   *  Constant: '<S3>/wn'
   *  Integrator: '<S52>/Integrator2'
   */
  rtb_Sum1_c_idx_2 = QD2_DroneStack_PID_2021a_P.wn_Value *
    QD2_DroneStack_PID_2021a_X.Integrator2_CSTATE_c[0];
  QD2_DroneStack_PID_2021a_B.Product1_j[0] = rtb_Sum1_c_idx_2;

  /* Sum: '<S3>/Sum8' incorporates:
   *  Integrator: '<S3>/Integrator6'
   */
  tmp_0 = QD2_DroneStack_PID_2021a_X.Integrator6_CSTATE[0] - rtb_Sum1_c_idx_2;
  data_loss = tmp_0;

  /* Gain: '<S3>/Ki3' */
  QD2_DroneStack_PID_2021a_B.Ki3[0] = QD2_DroneStack_PID_2021a_P.Ki3_Gain *
    tmp_0;

  /* Product: '<S52>/Product1' incorporates:
   *  Constant: '<S3>/wn'
   *  Integrator: '<S52>/Integrator2'
   */
  rtb_Sum1_c_idx_2 = QD2_DroneStack_PID_2021a_P.wn_Value *
    QD2_DroneStack_PID_2021a_X.Integrator2_CSTATE_c[1];
  QD2_DroneStack_PID_2021a_B.Product1_j[1] = rtb_Sum1_c_idx_2;

  /* Sum: '<S3>/Sum8' incorporates:
   *  Integrator: '<S3>/Integrator6'
   */
  tmp_0 = QD2_DroneStack_PID_2021a_X.Integrator6_CSTATE[1] - rtb_Sum1_c_idx_2;
  rtb_Sum1_j_idx_1 = tmp_0;

  /* Gain: '<S3>/Ki3' */
  QD2_DroneStack_PID_2021a_B.Ki3[1] = QD2_DroneStack_PID_2021a_P.Ki3_Gain *
    tmp_0;

  /* Product: '<S52>/Product1' incorporates:
   *  Constant: '<S3>/wn'
   *  Integrator: '<S52>/Integrator2'
   */
  rtb_Sum1_c_idx_2 = QD2_DroneStack_PID_2021a_P.wn_Value *
    QD2_DroneStack_PID_2021a_X.Integrator2_CSTATE_c[2];
  QD2_DroneStack_PID_2021a_B.Product1_j[2] = rtb_Sum1_c_idx_2;

  /* Sum: '<S3>/Sum8' incorporates:
   *  Integrator: '<S3>/Integrator6'
   */
  tmp_0 = QD2_DroneStack_PID_2021a_X.Integrator6_CSTATE[2] - rtb_Sum1_c_idx_2;

  /* Gain: '<S3>/Ki3' */
  QD2_DroneStack_PID_2021a_B.Ki3[2] = QD2_DroneStack_PID_2021a_P.Ki3_Gain *
    tmp_0;
  if (rtb_Compare_f) {
    /* MATLAB Function: '<S51>/Signmoid Type' */
    QD2_DroneStack_PID_2021a_DW.sfEvent_b = QD2_DroneStack_PID_2_CALL_EVENT;

    /* MATLAB Function 'HORIZON FRAME CONVERSION AND ESTIMATION/Pose Switchbox/Signmoid Type': '<S58>:1' */
    /* '<S58>:1:24' */
    rtb_DataTypeConversion3 = 0.0;
    switch ((int32_T)QD2_DroneStack_PID_2021a_B.Memory) {
     case 1:
      /* '<S58>:1:28' */
      rtb_DataTypeConversion3 = 1.0;
      break;

     case 2:
      /* '<S58>:1:30' */
      rtb_DataTypeConversion3 = 1.0;
      break;

     case 3:
      /* '<S58>:1:32' */
      rtb_DataTypeConversion3 = 2.0;
      break;

     case 4:
      /* '<S58>:1:34' */
      rtb_DataTypeConversion3 = 4.0;
      break;

     case 5:
      /* '<S58>:1:36' */
      rtb_DataTypeConversion3 = 3.0;
      break;

     case 6:
      /* '<S58>:1:38' */
      rtb_DataTypeConversion3 = 5.0;
      break;

     case 7:
      /* '<S58>:1:40' */
      rtb_DataTypeConversion3 = 1.0;
      break;

     case 8:
      /* '<S58>:1:42' */
      rtb_DataTypeConversion3 = 1.0;
      break;

     case 9:
      /* '<S58>:1:44' */
      rtb_DataTypeConversion3 = 1.0;
      break;
    }

    /* End of MATLAB Function: '<S51>/Signmoid Type' */

    /* MATLAB Function: '<S51>/MATLAB Function' incorporates:
     *  Constant: '<S51>/Constant8'
     *  Constant: '<S51>/Constant9'
     */
    QD2_DroneStack_PID_2021a_DW.sfEvent_o = QD2_DroneStack_PID_2_CALL_EVENT;

    /* MATLAB Function 'HORIZON FRAME CONVERSION AND ESTIMATION/Pose Switchbox/MATLAB Function': '<S53>:1' */
    /* '<S53>:1:8' */
    QD2_DroneStack_PID_2021a_B.enable_k = 0.0;

    /* '<S53>:1:9' */
    QD2_DroneStack_PID_2021a_B.x_ref = 0.0;

    /* '<S53>:1:10' */
    QD2_DroneStack_PID_2021a_B.max_x_vel = 0.0;

    /* '<S53>:1:11' */
    QD2_DroneStack_PID_2021a_B.max_x_accel = 0.0;
    switch ((int32_T)rtb_DataTypeConversion3) {
     case 1:
      /* '<S53>:1:15' */
      QD2_DroneStack_PID_2021a_B.enable_k = 1.0;

      /* '<S53>:1:16' */
      QD2_DroneStack_PID_2021a_B.x_ref =
        QD2_DroneStack_PID_2021a_B.StreamClient_o4[5];

      /* '<S53>:1:17' */
      QD2_DroneStack_PID_2021a_B.max_x_vel =
        QD2_DroneStack_PID_2021a_P.Constant9_Value[0];

      /* '<S53>:1:18' */
      QD2_DroneStack_PID_2021a_B.max_x_accel =
        QD2_DroneStack_PID_2021a_P.Constant9_Value[1];
      break;

     case 2:
      /* '<S53>:1:21' */
      QD2_DroneStack_PID_2021a_B.enable_k = 1.0;

      /* '<S53>:1:22' */
      QD2_DroneStack_PID_2021a_B.x_ref =
        QD2_DroneStack_PID_2021a_B.StreamClient_o4[5];

      /* '<S53>:1:23' */
      QD2_DroneStack_PID_2021a_B.max_x_vel =
        QD2_DroneStack_PID_2021a_P.Constant9_Value[0];

      /* '<S53>:1:24' */
      QD2_DroneStack_PID_2021a_B.max_x_accel =
        QD2_DroneStack_PID_2021a_P.Constant9_Value[1];
      break;

     case 3:
      /* '<S53>:1:27' */
      QD2_DroneStack_PID_2021a_B.enable_k = 1.0;

      /* '<S53>:1:28' */
      QD2_DroneStack_PID_2021a_B.x_ref =
        QD2_DroneStack_PID_2021a_B.StreamClient_o4[11];

      /* '<S53>:1:29' */
      QD2_DroneStack_PID_2021a_B.max_x_vel =
        QD2_DroneStack_PID_2021a_P.Constant8_Value[0];

      /* '<S53>:1:30' */
      QD2_DroneStack_PID_2021a_B.max_x_accel =
        QD2_DroneStack_PID_2021a_P.Constant8_Value[1];
      break;

     case 4:
      /* '<S53>:1:33' */
      QD2_DroneStack_PID_2021a_B.enable_k = 1.0;

      /* '<S53>:1:34' */
      QD2_DroneStack_PID_2021a_B.x_ref =
        QD2_DroneStack_PID_2021a_B.StreamClient_o4[11];
      if (fabs(QD2_DroneStack_PID_2021a_B.ContinuousSigmoid_o1_a -
               QD2_DroneStack_PID_2021a_B.StreamClient_o4[11]) <= 0.02) {
        /* '<S53>:1:35' */
        /* '<S53>:1:36' */
        QD2_DroneStack_PID_2021a_B.max_x_vel =
          QD2_DroneStack_PID_2021a_P.Constant8_Value[0];

        /* '<S53>:1:37' */
        QD2_DroneStack_PID_2021a_B.max_x_accel =
          QD2_DroneStack_PID_2021a_P.Constant8_Value[1];
      } else {
        /* '<S53>:1:39' */
        QD2_DroneStack_PID_2021a_B.max_x_vel =
          QD2_DroneStack_PID_2021a_P.Constant9_Value[0];

        /* '<S53>:1:40' */
        QD2_DroneStack_PID_2021a_B.max_x_accel =
          QD2_DroneStack_PID_2021a_P.Constant9_Value[1];
      }
      break;

     case 5:
      /* '<S53>:1:43' */
      QD2_DroneStack_PID_2021a_B.enable_k = 1.0;

      /* '<S53>:1:44' */
      QD2_DroneStack_PID_2021a_B.x_ref =
        QD2_DroneStack_PID_2021a_B.StreamClient_o4[11];
      if (fabs(QD2_DroneStack_PID_2021a_B.ContinuousSigmoid_o1_a -
               QD2_DroneStack_PID_2021a_B.StreamClient_o4[11]) <= 0.02) {
        /* '<S53>:1:45' */
        /* '<S53>:1:46' */
        QD2_DroneStack_PID_2021a_B.max_x_vel =
          QD2_DroneStack_PID_2021a_P.Constant8_Value[0];

        /* '<S53>:1:47' */
        QD2_DroneStack_PID_2021a_B.max_x_accel =
          QD2_DroneStack_PID_2021a_P.Constant8_Value[1];
      } else {
        /* '<S53>:1:49' */
        QD2_DroneStack_PID_2021a_B.max_x_vel =
          QD2_DroneStack_PID_2021a_P.Constant9_Value[0];

        /* '<S53>:1:50' */
        QD2_DroneStack_PID_2021a_B.max_x_accel =
          QD2_DroneStack_PID_2021a_P.Constant9_Value[1];
      }
      break;
    }

    /* End of MATLAB Function: '<S51>/MATLAB Function' */

    /* MATLAB Function: '<S51>/MATLAB Function1' incorporates:
     *  Constant: '<S51>/Constant2'
     *  Constant: '<S51>/Constant5'
     */
    QD2_DroneStack_PID_2021a_DW.sfEvent_iv = QD2_DroneStack_PID_2_CALL_EVENT;

    /* MATLAB Function 'HORIZON FRAME CONVERSION AND ESTIMATION/Pose Switchbox/MATLAB Function1': '<S54>:1' */
    /* '<S54>:1:8' */
    QD2_DroneStack_PID_2021a_B.enable_n = 0.0;

    /* '<S54>:1:9' */
    QD2_DroneStack_PID_2021a_B.y_ref = 0.0;

    /* '<S54>:1:10' */
    QD2_DroneStack_PID_2021a_B.max_y_vel = 0.0;

    /* '<S54>:1:11' */
    QD2_DroneStack_PID_2021a_B.max_y_accel = 0.0;
    switch ((int32_T)rtb_DataTypeConversion3) {
     case 1:
      /* '<S54>:1:15' */
      QD2_DroneStack_PID_2021a_B.enable_n = 1.0;

      /* '<S54>:1:16' */
      QD2_DroneStack_PID_2021a_B.y_ref =
        QD2_DroneStack_PID_2021a_B.StreamClient_o4[6];

      /* '<S54>:1:17' */
      QD2_DroneStack_PID_2021a_B.max_y_vel =
        QD2_DroneStack_PID_2021a_P.Constant2_Value_f[0];

      /* '<S54>:1:18' */
      QD2_DroneStack_PID_2021a_B.max_y_accel =
        QD2_DroneStack_PID_2021a_P.Constant2_Value_f[1];
      break;

     case 2:
      /* '<S54>:1:21' */
      QD2_DroneStack_PID_2021a_B.enable_n = 1.0;

      /* '<S54>:1:22' */
      QD2_DroneStack_PID_2021a_B.y_ref =
        QD2_DroneStack_PID_2021a_B.StreamClient_o4[6];

      /* '<S54>:1:23' */
      QD2_DroneStack_PID_2021a_B.max_y_vel =
        QD2_DroneStack_PID_2021a_P.Constant2_Value_f[0];

      /* '<S54>:1:24' */
      QD2_DroneStack_PID_2021a_B.max_y_accel =
        QD2_DroneStack_PID_2021a_P.Constant2_Value_f[1];
      break;

     case 3:
      /* '<S54>:1:27' */
      QD2_DroneStack_PID_2021a_B.enable_n = 1.0;

      /* '<S54>:1:28' */
      QD2_DroneStack_PID_2021a_B.y_ref =
        QD2_DroneStack_PID_2021a_B.StreamClient_o4[12];

      /* '<S54>:1:29' */
      QD2_DroneStack_PID_2021a_B.max_y_vel =
        QD2_DroneStack_PID_2021a_P.Constant5_Value_j[0];

      /* '<S54>:1:30' */
      QD2_DroneStack_PID_2021a_B.max_y_accel =
        QD2_DroneStack_PID_2021a_P.Constant5_Value_j[1];
      break;

     case 4:
      /* '<S54>:1:33' */
      QD2_DroneStack_PID_2021a_B.enable_n = 1.0;

      /* '<S54>:1:34' */
      QD2_DroneStack_PID_2021a_B.y_ref =
        QD2_DroneStack_PID_2021a_B.StreamClient_o4[12];
      if (fabs(QD2_DroneStack_PID_2021a_B.ContinuousSigmoid1_o1 -
               QD2_DroneStack_PID_2021a_B.StreamClient_o4[12]) <= 0.02) {
        /* '<S54>:1:35' */
        /* '<S54>:1:36' */
        QD2_DroneStack_PID_2021a_B.max_y_vel =
          QD2_DroneStack_PID_2021a_P.Constant5_Value_j[0];

        /* '<S54>:1:37' */
        QD2_DroneStack_PID_2021a_B.max_y_accel =
          QD2_DroneStack_PID_2021a_P.Constant5_Value_j[1];
      } else {
        /* '<S54>:1:39' */
        QD2_DroneStack_PID_2021a_B.max_y_vel =
          QD2_DroneStack_PID_2021a_P.Constant2_Value_f[0];

        /* '<S54>:1:40' */
        QD2_DroneStack_PID_2021a_B.max_y_accel =
          QD2_DroneStack_PID_2021a_P.Constant2_Value_f[1];
      }
      break;

     case 5:
      /* '<S54>:1:43' */
      QD2_DroneStack_PID_2021a_B.enable_n = 1.0;

      /* '<S54>:1:44' */
      QD2_DroneStack_PID_2021a_B.y_ref =
        QD2_DroneStack_PID_2021a_B.StreamClient_o4[12];
      if (fabs(QD2_DroneStack_PID_2021a_B.ContinuousSigmoid1_o1 -
               QD2_DroneStack_PID_2021a_B.StreamClient_o4[12]) <= 0.02) {
        /* '<S54>:1:45' */
        /* '<S54>:1:46' */
        QD2_DroneStack_PID_2021a_B.max_y_vel =
          QD2_DroneStack_PID_2021a_P.Constant5_Value_j[0];

        /* '<S54>:1:47' */
        QD2_DroneStack_PID_2021a_B.max_y_accel =
          QD2_DroneStack_PID_2021a_P.Constant5_Value_j[1];
      } else {
        /* '<S54>:1:49' */
        QD2_DroneStack_PID_2021a_B.max_y_vel =
          QD2_DroneStack_PID_2021a_P.Constant2_Value_f[0];

        /* '<S54>:1:50' */
        QD2_DroneStack_PID_2021a_B.max_y_accel =
          QD2_DroneStack_PID_2021a_P.Constant2_Value_f[1];
      }
      break;
    }

    /* End of MATLAB Function: '<S51>/MATLAB Function1' */

    /* MATLAB Function: '<S51>/MATLAB Function2' incorporates:
     *  Constant: '<S51>/Constant3'
     *  Constant: '<S51>/Constant4'
     */
    QD2_DroneStack_PID_2021a_DW.sfEvent_id = QD2_DroneStack_PID_2_CALL_EVENT;

    /* MATLAB Function 'HORIZON FRAME CONVERSION AND ESTIMATION/Pose Switchbox/MATLAB Function2': '<S55>:1' */
    /* '<S55>:1:8' */
    QD2_DroneStack_PID_2021a_B.enable_c = 0.0;

    /* '<S55>:1:9' */
    QD2_DroneStack_PID_2021a_B.height_ref = 0.0;

    /* '<S55>:1:10' */
    QD2_DroneStack_PID_2021a_B.max_height_vel = 0.0;

    /* '<S55>:1:11' */
    QD2_DroneStack_PID_2021a_B.max_height_accel = 0.0;
    switch ((int32_T)rtb_DataTypeConversion3) {
     case 1:
      /* '<S55>:1:15' */
      /* '<S55>:1:16' */
      /* '<S55>:1:17' */
      QD2_DroneStack_PID_2021a_B.max_height_vel = 0.0;

      /* '<S55>:1:18' */
      QD2_DroneStack_PID_2021a_B.max_height_accel = 0.0;
      break;

     case 2:
      /* '<S55>:1:21' */
      /* '<S55>:1:22' */
      /* '<S55>:1:23' */
      QD2_DroneStack_PID_2021a_B.max_height_vel = 0.0;

      /* '<S55>:1:24' */
      QD2_DroneStack_PID_2021a_B.max_height_accel = 0.0;
      break;

     case 3:
      /* '<S55>:1:27' */
      QD2_DroneStack_PID_2021a_B.enable_c = 1.0;

      /* '<S55>:1:28' */
      QD2_DroneStack_PID_2021a_B.height_ref =
        QD2_DroneStack_PID_2021a_B.StreamClient_o4[13];

      /* '<S55>:1:29' */
      QD2_DroneStack_PID_2021a_B.max_height_vel =
        QD2_DroneStack_PID_2021a_P.Constant3_Value_c[0];

      /* '<S55>:1:30' */
      QD2_DroneStack_PID_2021a_B.max_height_accel =
        QD2_DroneStack_PID_2021a_P.Constant3_Value_c[1];
      break;

     case 4:
      /* '<S55>:1:33' */
      QD2_DroneStack_PID_2021a_B.enable_c = 1.0;

      /* '<S55>:1:34' */
      QD2_DroneStack_PID_2021a_B.height_ref =
        QD2_DroneStack_PID_2021a_B.StreamClient_o4[13];
      if ((QD2_DroneStack_PID_2021a_B.ContinuousSigmoid2_o2 < 0.0) || (fabs
           (QD2_DroneStack_PID_2021a_B.ContinuousSigmoid2_o1 -
            QD2_DroneStack_PID_2021a_B.StreamClient_o4[13]) <= 0.1) ||
          (QD2_DroneStack_PID_2021a_B.StreamClient_o4[13] <=
           QD2_DroneStack_PID_2021a_B.ContinuousSigmoid2_o1)) {
        /* '<S55>:1:35' */
        /* '<S55>:1:36' */
        QD2_DroneStack_PID_2021a_B.max_height_vel =
          QD2_DroneStack_PID_2021a_P.Constant3_Value_c[0];

        /* '<S55>:1:37' */
        QD2_DroneStack_PID_2021a_B.max_height_accel =
          QD2_DroneStack_PID_2021a_P.Constant3_Value_c[1];
      } else {
        /* '<S55>:1:39' */
        QD2_DroneStack_PID_2021a_B.max_height_vel =
          QD2_DroneStack_PID_2021a_P.Constant4_Value_c[0];

        /* '<S55>:1:40' */
        QD2_DroneStack_PID_2021a_B.max_height_accel =
          QD2_DroneStack_PID_2021a_P.Constant4_Value_c[1];
      }
      break;

     case 5:
      /* '<S55>:1:43' */
      QD2_DroneStack_PID_2021a_B.enable_c = 1.0;

      /* '<S55>:1:44' */
      if (QD2_DroneStack_PID_2021a_B.ContinuousSigmoid2_o2 >= 0.0) {
        /* '<S55>:1:45' */
        /* '<S55>:1:46' */
        QD2_DroneStack_PID_2021a_B.max_height_vel =
          QD2_DroneStack_PID_2021a_P.Constant3_Value_c[0];

        /* '<S55>:1:47' */
        QD2_DroneStack_PID_2021a_B.max_height_accel =
          QD2_DroneStack_PID_2021a_P.Constant3_Value_c[1];
      } else {
        /* '<S55>:1:49' */
        QD2_DroneStack_PID_2021a_B.max_height_vel =
          QD2_DroneStack_PID_2021a_P.Constant4_Value_c[0];

        /* '<S55>:1:50' */
        QD2_DroneStack_PID_2021a_B.max_height_accel =
          QD2_DroneStack_PID_2021a_P.Constant4_Value_c[1];
      }
      break;
    }

    /* End of MATLAB Function: '<S51>/MATLAB Function2' */

    /* MATLAB Function: '<S51>/MATLAB Function4' incorporates:
     *  Constant: '<S51>/Constant6'
     *  Constant: '<S51>/Constant7'
     */
    QD2_DroneStack_PID_2021a_DW.sfEvent_i = QD2_DroneStack_PID_2_CALL_EVENT;

    /* MATLAB Function 'HORIZON FRAME CONVERSION AND ESTIMATION/Pose Switchbox/MATLAB Function4': '<S56>:1' */
    /* '<S56>:1:8' */
    QD2_DroneStack_PID_2021a_B.enable = 0.0;

    /* '<S56>:1:9' */
    QD2_DroneStack_PID_2021a_B.yaw_ref = 0.0;

    /* '<S56>:1:10' */
    QD2_DroneStack_PID_2021a_B.max_yaw_vel = 0.0;

    /* '<S56>:1:11' */
    QD2_DroneStack_PID_2021a_B.max_yaw_accel = 0.0;
    switch ((int32_T)rtb_DataTypeConversion3) {
     case 1:
      /* '<S56>:1:15' */
      /* '<S56>:1:16' */
      /* '<S56>:1:17' */
      QD2_DroneStack_PID_2021a_B.max_yaw_vel = 0.0;

      /* '<S56>:1:18' */
      QD2_DroneStack_PID_2021a_B.max_yaw_accel = 0.0;
      break;

     case 2:
      /* '<S56>:1:20' */
      QD2_DroneStack_PID_2021a_B.enable = 1.0;

      /* '<S56>:1:21' */
      QD2_DroneStack_PID_2021a_B.yaw_ref =
        QD2_DroneStack_PID_2021a_B.StreamClient_o4[14];

      /* '<S56>:1:22' */
      QD2_DroneStack_PID_2021a_B.max_yaw_vel =
        QD2_DroneStack_PID_2021a_P.Constant6_Value[0];

      /* '<S56>:1:23' */
      QD2_DroneStack_PID_2021a_B.max_yaw_accel =
        QD2_DroneStack_PID_2021a_P.Constant6_Value[1];
      break;

     case 3:
      /* '<S56>:1:25' */
      QD2_DroneStack_PID_2021a_B.enable = 1.0;

      /* '<S56>:1:26' */
      QD2_DroneStack_PID_2021a_B.yaw_ref =
        QD2_DroneStack_PID_2021a_B.StreamClient_o4[14];

      /* '<S56>:1:27' */
      QD2_DroneStack_PID_2021a_B.max_yaw_vel =
        QD2_DroneStack_PID_2021a_P.Constant7_Value[0];

      /* '<S56>:1:28' */
      QD2_DroneStack_PID_2021a_B.max_yaw_accel =
        QD2_DroneStack_PID_2021a_P.Constant7_Value[1];
      break;

     case 4:
      /* '<S56>:1:30' */
      QD2_DroneStack_PID_2021a_B.enable = 1.0;

      /* '<S56>:1:31' */
      QD2_DroneStack_PID_2021a_B.yaw_ref =
        QD2_DroneStack_PID_2021a_B.StreamClient_o4[14];
      if ((QD2_DroneStack_PID_2021a_B.ContinuousSigmoid3_o2 < 0.0) ||
          (QD2_DroneStack_PID_2021a_B.StreamClient_o4[14] <
           QD2_DroneStack_PID_2021a_B.ContinuousSigmoid3_o1) || (fabs
           (QD2_DroneStack_PID_2021a_B.ContinuousSigmoid3_o1 -
            QD2_DroneStack_PID_2021a_B.StreamClient_o4[14]) <= 0.2)) {
        /* '<S56>:1:32' */
        /* '<S56>:1:33' */
        QD2_DroneStack_PID_2021a_B.max_yaw_vel =
          QD2_DroneStack_PID_2021a_P.Constant7_Value[0];

        /* '<S56>:1:34' */
        QD2_DroneStack_PID_2021a_B.max_yaw_accel =
          QD2_DroneStack_PID_2021a_P.Constant7_Value[1];
      } else {
        /* '<S56>:1:36' */
        QD2_DroneStack_PID_2021a_B.max_yaw_vel =
          QD2_DroneStack_PID_2021a_P.Constant6_Value[0];

        /* '<S56>:1:37' */
        QD2_DroneStack_PID_2021a_B.max_yaw_accel =
          QD2_DroneStack_PID_2021a_P.Constant6_Value[1];
      }
      break;

     case 5:
      /* '<S56>:1:40' */
      QD2_DroneStack_PID_2021a_B.enable = 1.0;

      /* '<S56>:1:41' */
      QD2_DroneStack_PID_2021a_B.yaw_ref =
        QD2_DroneStack_PID_2021a_B.StreamClient_o4[14];
      if (QD2_DroneStack_PID_2021a_B.ContinuousSigmoid3_o2 >= 0.0) {
        /* '<S56>:1:42' */
        /* '<S56>:1:43' */
        QD2_DroneStack_PID_2021a_B.max_yaw_vel =
          QD2_DroneStack_PID_2021a_P.Constant7_Value[0];

        /* '<S56>:1:44' */
        QD2_DroneStack_PID_2021a_B.max_yaw_accel =
          QD2_DroneStack_PID_2021a_P.Constant7_Value[1];
      } else {
        /* '<S56>:1:46' */
        QD2_DroneStack_PID_2021a_B.max_yaw_vel =
          QD2_DroneStack_PID_2021a_P.Constant6_Value[0];

        /* '<S56>:1:47' */
        QD2_DroneStack_PID_2021a_B.max_yaw_accel =
          QD2_DroneStack_PID_2021a_P.Constant6_Value[1];
      }
      break;
    }

    /* End of MATLAB Function: '<S51>/MATLAB Function4' */

    /* Outputs for Enabled SubSystem: '<S51>/Use des height  when enabled' */
    Usedesiredheightwhenenabled(QD2_DroneStack_PID_2021a_M,
      QD2_DroneStack_PID_2021a_B.enable_c, QD2_DroneStack_PID_2021a_B.height_ref,
      &QD2_DroneStack_PID_2021a_B.Usedesheightwhenenabled,
      &QD2_DroneStack_PID_2021a_DW.Usedesheightwhenenabled,
      &QD2_DroneStack_PID_2021a_P.Usedesheightwhenenabled);

    /* End of Outputs for SubSystem: '<S51>/Use des height  when enabled' */

    /* Outputs for Enabled SubSystem: '<S51>/Use des yaw  when enabled' */
    Usedesiredheightwhenenabled(QD2_DroneStack_PID_2021a_M,
      QD2_DroneStack_PID_2021a_B.enable, QD2_DroneStack_PID_2021a_B.yaw_ref,
      &QD2_DroneStack_PID_2021a_B.Usedesyawwhenenabled,
      &QD2_DroneStack_PID_2021a_DW.Usedesyawwhenenabled,
      &QD2_DroneStack_PID_2021a_P.Usedesyawwhenenabled);

    /* End of Outputs for SubSystem: '<S51>/Use des yaw  when enabled' */

    /* Outputs for Enabled SubSystem: '<S51>/Use desired X  when enabled' */
    Usedesiredheightwhenenabled(QD2_DroneStack_PID_2021a_M,
      QD2_DroneStack_PID_2021a_B.enable_k, QD2_DroneStack_PID_2021a_B.x_ref,
      &QD2_DroneStack_PID_2021a_B.UsedesiredXwhenenabled,
      &QD2_DroneStack_PID_2021a_DW.UsedesiredXwhenenabled,
      &QD2_DroneStack_PID_2021a_P.UsedesiredXwhenenabled);

    /* End of Outputs for SubSystem: '<S51>/Use desired X  when enabled' */

    /* Outputs for Enabled SubSystem: '<S51>/Use desired Y  when enabled' */
    Usedesiredheightwhenenabled(QD2_DroneStack_PID_2021a_M,
      QD2_DroneStack_PID_2021a_B.enable_n, QD2_DroneStack_PID_2021a_B.y_ref,
      &QD2_DroneStack_PID_2021a_B.UsedesiredYwhenenabled,
      &QD2_DroneStack_PID_2021a_DW.UsedesiredYwhenenabled,
      &QD2_DroneStack_PID_2021a_P.UsedesiredYwhenenabled);

    /* End of Outputs for SubSystem: '<S51>/Use desired Y  when enabled' */

    /* Product: '<S3>/Product' incorporates:
     *  S-Function (euler_angles_to_rotation_matrix_block): '<S3>/Euler Angles to Rotation Matrix2'
     */
    rtb_Product_h_idx_0 = 0.0;
    rtb_Product_h_idx_1 = 0.0;
    rtb_Product_h_idx_2 = 0.0;
    for (i = 0; i < 3; i++) {
      rtb_Sum1_c_idx_2 = QD2_DroneStack_PID_2021a_B.Product4[i + 3];
      rtb_Product_h_idx_0 += rtb_BFToIFrotationmatrix[3 * i] * rtb_Sum1_c_idx_2;
      rtb_Product_h_idx_1 += rtb_BFToIFrotationmatrix[3 * i + 1] *
        rtb_Sum1_c_idx_2;
      rtb_Product_h_idx_2 += rtb_BFToIFrotationmatrix[3 * i + 2] *
        rtb_Sum1_c_idx_2;
    }

    /* End of Product: '<S3>/Product' */
  }

  /* Integrator: '<S52>/Integrator1' */
  if (QD2_DroneStack_PID_2021a_DW.Integrator1_DWORK1_p) {
    QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_j[0] =
      QD2_DroneStack_PID_2021a_B.StreamClient_o4[5];
    QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_j[1] =
      QD2_DroneStack_PID_2021a_B.StreamClient_o4[6];
    QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_j[2] =
      QD2_DroneStack_PID_2021a_B.StreamClient_o4[7];
  }

  /* Product: '<S52>/Product' incorporates:
   *  Constant: '<S3>/wn'
   *  Constant: '<S3>/zt'
   *  Constant: '<S52>/Constant'
   *  Integrator: '<S52>/Integrator1'
   *  Integrator: '<S52>/Integrator2'
   *  Product: '<S52>/Product2'
   *  Sum: '<S52>/Sum'
   *  Sum: '<S52>/Sum1'
   */
  QD2_DroneStack_PID_2021a_B.Product_b[0] =
    ((QD2_DroneStack_PID_2021a_B.StreamClient_o4[5] -
      QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_j[0]) -
     QD2_DroneStack_PID_2021a_X.Integrator2_CSTATE_c[0] *
     QD2_DroneStack_PID_2021a_P.Constant_Value_o *
     QD2_DroneStack_PID_2021a_P.zt_Value) * QD2_DroneStack_PID_2021a_P.wn_Value;
  QD2_DroneStack_PID_2021a_B.Product_b[1] =
    ((QD2_DroneStack_PID_2021a_B.StreamClient_o4[6] -
      QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_j[1]) -
     QD2_DroneStack_PID_2021a_X.Integrator2_CSTATE_c[1] *
     QD2_DroneStack_PID_2021a_P.Constant_Value_o *
     QD2_DroneStack_PID_2021a_P.zt_Value) * QD2_DroneStack_PID_2021a_P.wn_Value;
  QD2_DroneStack_PID_2021a_B.Product_b[2] =
    ((QD2_DroneStack_PID_2021a_B.StreamClient_o4[7] -
      QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_j[2]) -
     QD2_DroneStack_PID_2021a_X.Integrator2_CSTATE_c[2] *
     QD2_DroneStack_PID_2021a_P.Constant_Value_o *
     QD2_DroneStack_PID_2021a_P.zt_Value) * QD2_DroneStack_PID_2021a_P.wn_Value;

  /* Sum: '<S3>/Sum2' incorporates:
   *  Gain: '<S3>/Kp1'
   *  Integrator: '<S3>/Integrator2'
   */
  QD2_DroneStack_PID_2021a_B.Sum2 = (QD2_DroneStack_PID_2021a_B.Product4[2] -
    QD2_DroneStack_PID_2021a_P.Kp1_Gain * sigmoid) -
    QD2_DroneStack_PID_2021a_X.Integrator2_CSTATE_o;
  if (rtb_Compare_f) {
    /* Bias: '<S3>/gravity correction' */
    QD2_DroneStack_PID_2021a_B.IFAccelerometerdatamss3[0] = rtb_Product_h_idx_0
      + QD2_DroneStack_PID_2021a_P.gravitycorrection_Bias[0];
    QD2_DroneStack_PID_2021a_B.IFAccelerometerdatamss3[1] = rtb_Product_h_idx_1
      + QD2_DroneStack_PID_2021a_P.gravitycorrection_Bias[1];
    QD2_DroneStack_PID_2021a_B.IFAccelerometerdatamss3[2] = rtb_Product_h_idx_2
      + QD2_DroneStack_PID_2021a_P.gravitycorrection_Bias[2];
  }

  /* Sum: '<S3>/Sum9' incorporates:
   *  Gain: '<S3>/Kp3'
   *  Integrator: '<S3>/Integrator7'
   */
  QD2_DroneStack_PID_2021a_B.Sum9[0] =
    (QD2_DroneStack_PID_2021a_B.IFAccelerometerdatamss3[0] -
     QD2_DroneStack_PID_2021a_P.Kp3_Gain * data_loss) -
    QD2_DroneStack_PID_2021a_X.Integrator7_CSTATE[0];

  /* Gain: '<S111>/Gain' */
  QD2_DroneStack_PID_2021a_B.Gain_f[0] = QD2_DroneStack_PID_2021a_P.Gain_Gain_h *
    QD2_DroneStack_PID_2021a_B.AttitudeAngleCommands[0];
  QD2_DroneStack_PID_2021a_B.Gain_f[3] = QD2_DroneStack_PID_2021a_P.Gain_Gain_h *
    QD2_DroneStack_PID_2021a_B.Product3[0];

  /* Sum: '<S3>/Sum9' incorporates:
   *  Gain: '<S3>/Kp3'
   *  Integrator: '<S3>/Integrator7'
   */
  QD2_DroneStack_PID_2021a_B.Sum9[1] =
    (QD2_DroneStack_PID_2021a_B.IFAccelerometerdatamss3[1] -
     QD2_DroneStack_PID_2021a_P.Kp3_Gain * rtb_Sum1_j_idx_1) -
    QD2_DroneStack_PID_2021a_X.Integrator7_CSTATE[1];

  /* Gain: '<S111>/Gain' */
  QD2_DroneStack_PID_2021a_B.Gain_f[1] = QD2_DroneStack_PID_2021a_P.Gain_Gain_h *
    QD2_DroneStack_PID_2021a_B.AttitudeAngleCommands[1];
  QD2_DroneStack_PID_2021a_B.Gain_f[4] = QD2_DroneStack_PID_2021a_P.Gain_Gain_h *
    QD2_DroneStack_PID_2021a_B.Product3[1];

  /* Sum: '<S3>/Sum9' incorporates:
   *  Gain: '<S3>/Kp3'
   *  Integrator: '<S3>/Integrator7'
   *  Sum: '<S3>/Sum8'
   */
  QD2_DroneStack_PID_2021a_B.Sum9[2] =
    (QD2_DroneStack_PID_2021a_B.IFAccelerometerdatamss3[2] -
     QD2_DroneStack_PID_2021a_P.Kp3_Gain * tmp_0) -
    QD2_DroneStack_PID_2021a_X.Integrator7_CSTATE[2];

  /* Gain: '<S111>/Gain' */
  QD2_DroneStack_PID_2021a_B.Gain_f[2] = QD2_DroneStack_PID_2021a_P.Gain_Gain_h *
    QD2_DroneStack_PID_2021a_B.AttitudeAngleCommands[2];
  QD2_DroneStack_PID_2021a_B.Gain_f[5] = QD2_DroneStack_PID_2021a_P.Gain_Gain_h *
    QD2_DroneStack_PID_2021a_B.Product3[2];
  if (rtb_Compare_f) {
  }

  /* Gain: '<S112>/Gain' incorporates:
   *  Sum: '<S7>/Sum1'
   */
  QD2_DroneStack_PID_2021a_B.Gain_k[0] = QD2_DroneStack_PID_2021a_P.Gain_Gain_c *
    rtb_Sum1_c_idx_0;
  QD2_DroneStack_PID_2021a_B.Gain_k[3] = QD2_DroneStack_PID_2021a_P.Gain_Gain_c *
    QD2_DroneStack_PID_2021a_B.Product3[3];
  QD2_DroneStack_PID_2021a_B.Gain_k[1] = QD2_DroneStack_PID_2021a_P.Gain_Gain_c *
    rtb_Sum1_c_idx_1;
  QD2_DroneStack_PID_2021a_B.Gain_k[4] = QD2_DroneStack_PID_2021a_P.Gain_Gain_c *
    QD2_DroneStack_PID_2021a_B.Product3[4];
  QD2_DroneStack_PID_2021a_B.Gain_k[2] = QD2_DroneStack_PID_2021a_P.Gain_Gain_c *
    rtb_Integrator2_idx_0;
  QD2_DroneStack_PID_2021a_B.Gain_k[5] = QD2_DroneStack_PID_2021a_P.Gain_Gain_c *
    QD2_DroneStack_PID_2021a_B.Product3[5];
  if (rtb_Compare_f) {
    /* S-Function (sample_time_block): '<S110>/Sample Time' */

    /* S-Function Block: QD2_DroneStack_PID_2021a/STABILIZER - QDRONE 2/FLIGHT SAFETY/Sample Time (sample_time_block) */
    {
      t_error result;
      t_timeout current_time;
      t_timeout time_difference;
      result = timeout_get_high_resolution_time(&current_time);
      if (result >= 0) {
        result = timeout_subtract(&time_difference, &current_time,
          &QD2_DroneStack_PID_2021a_DW.SampleTime_PreviousTime_d);
        QD2_DroneStack_PID_2021a_B.SampleTime_d = time_difference.seconds +
          time_difference.nanoseconds * 1e-9;
        memcpy(&QD2_DroneStack_PID_2021a_DW.SampleTime_PreviousTime_d,
               &current_time, sizeof(t_timeout));
      }

      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M, _rt_error_message);
        return;
      }
    }

    /* S-Function (computation_time_block): '<S110>/Computation Time' */

    /* S-Function Block: QD2_DroneStack_PID_2021a/STABILIZER - QDRONE 2/FLIGHT SAFETY/Computation Time (computation_time_block) */
    {
      QD2_DroneStack_PID_2021a_B.ComputationTime_l =
        QD2_DroneStack_PID_2021a_DW.ComputationTime_ComputationTi_o.seconds +
        QD2_DroneStack_PID_2021a_DW.ComputationTime_ComputationTi_o.nanoseconds *
        1e-9;
    }
  }

  /* RelationalOperator: '<S114>/Relation' incorporates:
   *  Constant: '<S114>/threshold'
   */
  rtb_Relation_j = (QD2_DroneStack_PID_2021a_B.DataTypeConversion3 >=
                    QD2_DroneStack_PID_2021a_P.Stopmodel_threshold);

  /* Logic: '<S114>/Logical Operator' */
  QD2_DroneStack_PID_2021a_B.LogicalOperator_bx = !rtb_Relation_j;
  if (rtb_Compare_f) {
    /* DiscreteIntegrator: '<S114>/Discrete-Time Integrator' */
    if (QD2_DroneStack_PID_2021a_B.LogicalOperator_bx ||
        (QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevR_df != 0)) {
      QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_k =
        QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_n2p;
    }

    /* RelationalOperator: '<S114>/Relational Operator' incorporates:
     *  Constant: '<S114>/duration'
     *  DiscreteIntegrator: '<S114>/Discrete-Time Integrator'
     */
    QD2_DroneStack_PID_2021a_B.RelationalOperator_e =
      (QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_k >=
       QD2_DroneStack_PID_2021a_P.Stopmodel_duration);

    /* DataTypeConversion: '<S110>/Data Type Conversion4' */
    QD2_DroneStack_PID_2021a_B.DataTypeConversion4_f =
      QD2_DroneStack_PID_2021a_B.RelationalOperator_e;

    /* DataTypeConversion: '<S110>/Data Type Conversion3' incorporates:
     *  Logic: '<S110>/Logical Operator1'
     */
    rtb_DataTypeConversion3 = ((QD2_DroneStack_PID_2021a_B.DataTypeConversion4
      != 0.0) && (QD2_DroneStack_PID_2021a_B.DataTypeConversion1 != 0.0));

    /* RelationalOperator: '<S113>/Relation' incorporates:
     *  Constant: '<S113>/threshold'
     */
    rtb_RelationalOperator = (rtb_DataTypeConversion3 >=
      QD2_DroneStack_PID_2021a_P.Communication_threshold);

    /* Logic: '<S113>/Logical Operator' */
    QD2_DroneStack_PID_2021a_B.LogicalOperator_c = !rtb_RelationalOperator;

    /* DiscreteIntegrator: '<S113>/Discrete-Time Integrator' */
    if (QD2_DroneStack_PID_2021a_B.LogicalOperator_c ||
        (QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevR_az != 0)) {
      QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTAT_fv =
        QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_j;
    }

    /* RelationalOperator: '<S113>/Relational Operator' incorporates:
     *  Constant: '<S113>/duration'
     *  DiscreteIntegrator: '<S113>/Discrete-Time Integrator'
     */
    QD2_DroneStack_PID_2021a_B.RelationalOperator_gi =
      (QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTAT_fv >=
       QD2_DroneStack_PID_2021a_P.Communication_duration);

    /* DataTypeConversion: '<S110>/Data Type Conversion1' */
    QD2_DroneStack_PID_2021a_B.DataTypeConversion1_i =
      QD2_DroneStack_PID_2021a_B.RelationalOperator_gi;

    /* S-Function (hil_watchdog_block): '<S110>/HIL Watchdog' */

    /* S-Function Block: QD2_DroneStack_PID_2021a/STABILIZER - QDRONE 2/FLIGHT SAFETY/HIL Watchdog (hil_watchdog_block) */
    {
      t_error result;
      if (QD2_DroneStack_PID_2021a_DW.HILWatchdog_IsStarted) {
        result = hil_watchdog_reload
          (QD2_DroneStack_PID_2021a_DW.HILInitialize_Card);
      } else {
        result = hil_watchdog_start
          (QD2_DroneStack_PID_2021a_DW.HILInitialize_Card,
           QD2_DroneStack_PID_2021a_P.HILWatchdog_Timeout);
        if (result == 0) {
          QD2_DroneStack_PID_2021a_DW.HILWatchdog_IsStarted = true;
          result = 1;                  /* indicate watchdog has not expired */
        }
      }

      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M, _rt_error_message);
      }

      QD2_DroneStack_PID_2021a_B.HILWatchdog = (result == 0);
    }

    /* DataTypeConversion: '<S110>/Data Type Conversion5' */
    QD2_DroneStack_PID_2021a_B.DataTypeConversion5 =
      QD2_DroneStack_PID_2021a_B.HILWatchdog;

    /* SignalConversion generated from: '<S7>/To Host File' */
    QD2_DroneStack_PID_2021a_B.TmpSignalConversionAtToHostFi_a[0] =
      QD2_DroneStack_PID_2021a_B.SampleTime_d;
    QD2_DroneStack_PID_2021a_B.TmpSignalConversionAtToHostFi_a[1] =
      QD2_DroneStack_PID_2021a_B.ComputationTime_l;
    QD2_DroneStack_PID_2021a_B.TmpSignalConversionAtToHostFi_a[2] =
      QD2_DroneStack_PID_2021a_B.DataTypeConversion4_f;
    QD2_DroneStack_PID_2021a_B.TmpSignalConversionAtToHostFi_a[3] =
      QD2_DroneStack_PID_2021a_B.DataTypeConversion1_i;
    QD2_DroneStack_PID_2021a_B.TmpSignalConversionAtToHostFi_a[4] =
      QD2_DroneStack_PID_2021a_B.DataTypeConversion5;
    QD2_DroneStack_PID_2021a_B.TmpSignalConversionAtToHostFi_a[5] =
      QD2_DroneStack_PID_2021a_B.SpecifyAngleModeforStabilizerDO;
    QD2_DroneStack_PID_2021a_B.TmpSignalConversionAtToHostFi_a[6] =
      QD2_DroneStack_PID_2021a_B.NetThrottle;
    QD2_DroneStack_PID_2021a_B.TmpSignalConversionAtToHostFi_a[16] =
      QD2_DroneStack_PID_2021a_B.NetThrottle;
    QD2_DroneStack_PID_2021a_B.TmpSignalConversionAtToHostFi_a[7] =
      QD2_DroneStack_PID_2021a_B.AttitudeAngleCommands[0];
    QD2_DroneStack_PID_2021a_B.TmpSignalConversionAtToHostFi_a[10] =
      QD2_DroneStack_PID_2021a_B.AttitudeTorqueCommands[0];
    QD2_DroneStack_PID_2021a_B.TmpSignalConversionAtToHostFi_a[13] =
      QD2_DroneStack_PID_2021a_B.Sum6[0];
    QD2_DroneStack_PID_2021a_B.TmpSignalConversionAtToHostFi_a[17] =
      QD2_DroneStack_PID_2021a_B.SaturationCommandAuthorityNm1[0];
    QD2_DroneStack_PID_2021a_B.TmpSignalConversionAtToHostFi_a[8] =
      QD2_DroneStack_PID_2021a_B.AttitudeAngleCommands[1];
    QD2_DroneStack_PID_2021a_B.TmpSignalConversionAtToHostFi_a[11] =
      QD2_DroneStack_PID_2021a_B.AttitudeTorqueCommands[1];
    QD2_DroneStack_PID_2021a_B.TmpSignalConversionAtToHostFi_a[14] =
      QD2_DroneStack_PID_2021a_B.Sum6[1];
    QD2_DroneStack_PID_2021a_B.TmpSignalConversionAtToHostFi_a[18] =
      QD2_DroneStack_PID_2021a_B.SaturationCommandAuthorityNm1[1];
    QD2_DroneStack_PID_2021a_B.TmpSignalConversionAtToHostFi_a[9] =
      QD2_DroneStack_PID_2021a_B.AttitudeAngleCommands[2];
    QD2_DroneStack_PID_2021a_B.TmpSignalConversionAtToHostFi_a[12] =
      QD2_DroneStack_PID_2021a_B.AttitudeTorqueCommands[2];
    QD2_DroneStack_PID_2021a_B.TmpSignalConversionAtToHostFi_a[15] =
      QD2_DroneStack_PID_2021a_B.Sum6[2];
    QD2_DroneStack_PID_2021a_B.TmpSignalConversionAtToHostFi_a[19] =
      QD2_DroneStack_PID_2021a_B.SaturationCommandAuthorityNm1[2];

    /* Stop: '<S115>/Stop Simulation' incorporates:
     *  Constant: '<S118>/Constant'
     *  RelationalOperator: '<S118>/Compare'
     */
    if (QD2_DroneStack_PID_2021a_B.RelationalOperator_e !=
        QD2_DroneStack_PID_2021a_P.Constant_Value_dj) {
      rtmSetStopRequested(QD2_DroneStack_PID_2021a_M, true);
    }

    /* End of Stop: '<S115>/Stop Simulation' */
    /* Stop: '<S116>/Stop Simulation' incorporates:
     *  Constant: '<S119>/Constant'
     *  RelationalOperator: '<S119>/Compare'
     */
    if (QD2_DroneStack_PID_2021a_B.RelationalOperator_gi !=
        QD2_DroneStack_PID_2021a_P.Constant_Value_g) {
      rtmSetStopRequested(QD2_DroneStack_PID_2021a_M, true);
    }

    /* End of Stop: '<S116>/Stop Simulation' */
    /* Stop: '<S117>/Stop Simulation' incorporates:
     *  Constant: '<S120>/Constant'
     *  RelationalOperator: '<S120>/Compare'
     */
    if (QD2_DroneStack_PID_2021a_B.HILWatchdog !=
        QD2_DroneStack_PID_2021a_P.Constant_Value_p) {
      rtmSetStopRequested(QD2_DroneStack_PID_2021a_M, true);
    }

    /* End of Stop: '<S117>/Stop Simulation' */

    /* DataTypeConversion: '<S113>/Data Type Conversion' */
    QD2_DroneStack_PID_2021a_B.DataTypeConversion_m = rtb_RelationalOperator;
  }

  /* DataTypeConversion: '<S114>/Data Type Conversion' */
  QD2_DroneStack_PID_2021a_B.DataTypeConversion_ah = rtb_Relation_j;
}

/* Model update function for TID0 */
void QD2_DroneStack_PID_2021a_update0(void) /* Sample time: [0.0s, 0.0s] */
{
  /* local scratch DWork variables */
  int32_T ForEach_itr_a;
  int32_T idxDelay;
  boolean_T tmp;
  tmp = rtmIsMajorTimeStep(QD2_DroneStack_PID_2021a_M);
  if (tmp) {
    /* Update for Memory: '<S2>/Memory' */
    QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput =
      QD2_DroneStack_PID_2021a_B.StreamClient_o4[15];

    /* Update for Memory: '<S5>/Memory1' */
    QD2_DroneStack_PID_2021a_DW.Memory1_PreviousInput =
      QD2_DroneStack_PID_2021a_B.RelationalOperator;

    /* Update for Memory: '<S5>/Memory' */
    QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_f =
      QD2_DroneStack_PID_2021a_B.state;

    /* Update for S-Function (continuous_sigmoid_block): '<S13>/Continuous Sigmoid' */
    if (rtmIsMajorTimeStep(QD2_DroneStack_PID_2021a_M)) {
      {
        if (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Target !=
            QD2_DroneStack_PID_2021a_B.Usedesiredheightwhenenabled_c.h_dm1) {
          QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Target =
            QD2_DroneStack_PID_2021a_B.Usedesiredheightwhenenabled_c.h_dm1;
          QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Flag = 1;
        }

        if (QD2_DroneStack_PID_2021a_B.max_throttle_vel !=
            QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_MVel) {
          QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_MVel =
            QD2_DroneStack_PID_2021a_B.max_throttle_vel;
          QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Flag = 1;
        }

        if (QD2_DroneStack_PID_2021a_B.max_throttle_accel !=
            QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_MAcc) {
          QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_MAcc =
            QD2_DroneStack_PID_2021a_B.max_throttle_accel;
          QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Flag = 1;
        }
      }
    }

    /* Update for Memory: '<S1>/Memory' */
    QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_e =
      QD2_DroneStack_PID_2021a_B.Next_state;

    /* Update for S-Function (continuous_sigmoid_block): '<S51>/Continuous Sigmoid' */
    if (rtmIsMajorTimeStep(QD2_DroneStack_PID_2021a_M)) {
      {
        if (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Target_d !=
            QD2_DroneStack_PID_2021a_B.UsedesiredXwhenenabled.h_dm1) {
          QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Target_d =
            QD2_DroneStack_PID_2021a_B.UsedesiredXwhenenabled.h_dm1;
          QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Flag_h = 1;
        }

        if (QD2_DroneStack_PID_2021a_B.max_x_vel !=
            QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_MVel_l) {
          QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_MVel_l =
            QD2_DroneStack_PID_2021a_B.max_x_vel;
          QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Flag_h = 1;
        }

        if (QD2_DroneStack_PID_2021a_B.max_x_accel !=
            QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_MAcc_p) {
          QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_MAcc_p =
            QD2_DroneStack_PID_2021a_B.max_x_accel;
          QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Flag_h = 1;
        }
      }
    }

    /* Update for S-Function (continuous_sigmoid_block): '<S51>/Continuous Sigmoid1' */
    if (rtmIsMajorTimeStep(QD2_DroneStack_PID_2021a_M)) {
      {
        if (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_Target !=
            QD2_DroneStack_PID_2021a_B.UsedesiredYwhenenabled.h_dm1) {
          QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_Target =
            QD2_DroneStack_PID_2021a_B.UsedesiredYwhenenabled.h_dm1;
          QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_Flag = 1;
        }

        if (QD2_DroneStack_PID_2021a_B.max_y_vel !=
            QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_MVel) {
          QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_MVel =
            QD2_DroneStack_PID_2021a_B.max_y_vel;
          QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_Flag = 1;
        }

        if (QD2_DroneStack_PID_2021a_B.max_y_accel !=
            QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_MAcc) {
          QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_MAcc =
            QD2_DroneStack_PID_2021a_B.max_y_accel;
          QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_Flag = 1;
        }
      }
    }

    /* Update for S-Function (continuous_sigmoid_block): '<S51>/Continuous Sigmoid2' */
    if (rtmIsMajorTimeStep(QD2_DroneStack_PID_2021a_M)) {
      {
        if (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_Target !=
            QD2_DroneStack_PID_2021a_B.Usedesheightwhenenabled.h_dm1) {
          QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_Target =
            QD2_DroneStack_PID_2021a_B.Usedesheightwhenenabled.h_dm1;
          QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_Flag = 1;
        }

        if (QD2_DroneStack_PID_2021a_B.max_height_vel !=
            QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_MVel) {
          QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_MVel =
            QD2_DroneStack_PID_2021a_B.max_height_vel;
          QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_Flag = 1;
        }

        if (QD2_DroneStack_PID_2021a_B.max_height_accel !=
            QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_MAcc) {
          QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_MAcc =
            QD2_DroneStack_PID_2021a_B.max_height_accel;
          QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_Flag = 1;
        }
      }
    }

    /* Update for S-Function (continuous_sigmoid_block): '<S51>/Continuous Sigmoid3' */
    if (rtmIsMajorTimeStep(QD2_DroneStack_PID_2021a_M)) {
      {
        if (QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_Target !=
            QD2_DroneStack_PID_2021a_B.Usedesyawwhenenabled.h_dm1) {
          QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_Target =
            QD2_DroneStack_PID_2021a_B.Usedesyawwhenenabled.h_dm1;
          QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_Flag = 1;
        }

        if (QD2_DroneStack_PID_2021a_B.max_yaw_vel !=
            QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_MVel) {
          QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_MVel =
            QD2_DroneStack_PID_2021a_B.max_yaw_vel;
          QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_Flag = 1;
        }

        if (QD2_DroneStack_PID_2021a_B.max_yaw_accel !=
            QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_MAcc) {
          QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_MAcc =
            QD2_DroneStack_PID_2021a_B.max_yaw_accel;
          QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_Flag = 1;
        }
      }
    }
  }

  /* Update for Iterator SubSystem: '<S63>/For Each Subsystem - Iterate over IMU0 and IMU1' */
  for (ForEach_itr_a = 0; ForEach_itr_a < 2; ForEach_itr_a++) {
    /* Update for Integrator: '<S85>/Integrator1' */
    QD2_DroneStack_PID_2021a_DW.CoreSubsys_pn[ForEach_itr_a].Integrator1_DWORK1 =
      false;

    /* Update for Integrator: '<S84>/Integrator1' */
    QD2_DroneStack_PID_2021a_DW.CoreSubsys_pn[ForEach_itr_a].
      Integrator1_DWORK1_n = false;
  }

  /* End of Update for SubSystem: '<S63>/For Each Subsystem - Iterate over IMU0 and IMU1' */

  /* Update for Integrator: '<S39>/Integrator1' */
  QD2_DroneStack_PID_2021a_DW.Integrator1_DWORK1 = false;

  /* Update for RateLimiter: '<S13>/Rate Limiter (N//s)' */
  QD2_DroneStack_PID_2021a_DW.PrevY = QD2_DroneStack_PID_2021a_B.RateLimiterNs;
  QD2_DroneStack_PID_2021a_DW.LastMajorTime =
    QD2_DroneStack_PID_2021a_M->Timing.t[0];
  if (tmp) {
    /* Update for Delay: '<S7>/Delay' */
    for (idxDelay = 0; idxDelay < 99; idxDelay++) {
      QD2_DroneStack_PID_2021a_DW.Delay_DSTATE[idxDelay] =
        QD2_DroneStack_PID_2021a_DW.Delay_DSTATE[idxDelay + 1];
    }

    QD2_DroneStack_PID_2021a_DW.Delay_DSTATE[99] =
      QD2_DroneStack_PID_2021a_B.DataTypeConversion1;

    /* End of Update for Delay: '<S7>/Delay' */

    /* Update for Memory: '<S67>/Memory' */
    QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_a[0] =
      QD2_DroneStack_PID_2021a_B.ImpAsg_InsertedFor_ESCDataOu_kc[0];

    /* Update for Memory: '<S69>/Memory' */
    QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_as[0] =
      QD2_DroneStack_PID_2021a_B.ImpAsg_InsertedFor_ESCDataOut4_[0];

    /* Update for Memory: '<S68>/Memory' */
    QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_n[0] =
      QD2_DroneStack_PID_2021a_B.ImpAsg_InsertedFor_ESCDataOut_k[0];

    /* Update for Memory: '<S67>/Memory' */
    QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_a[1] =
      QD2_DroneStack_PID_2021a_B.ImpAsg_InsertedFor_ESCDataOu_kc[1];

    /* Update for Memory: '<S69>/Memory' */
    QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_as[1] =
      QD2_DroneStack_PID_2021a_B.ImpAsg_InsertedFor_ESCDataOut4_[1];

    /* Update for Memory: '<S68>/Memory' */
    QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_n[1] =
      QD2_DroneStack_PID_2021a_B.ImpAsg_InsertedFor_ESCDataOut_k[1];

    /* Update for Memory: '<S67>/Memory' */
    QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_a[2] =
      QD2_DroneStack_PID_2021a_B.ImpAsg_InsertedFor_ESCDataOu_kc[2];

    /* Update for Memory: '<S69>/Memory' */
    QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_as[2] =
      QD2_DroneStack_PID_2021a_B.ImpAsg_InsertedFor_ESCDataOut4_[2];

    /* Update for Memory: '<S68>/Memory' */
    QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_n[2] =
      QD2_DroneStack_PID_2021a_B.ImpAsg_InsertedFor_ESCDataOut_k[2];

    /* Update for Memory: '<S67>/Memory' */
    QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_a[3] =
      QD2_DroneStack_PID_2021a_B.ImpAsg_InsertedFor_ESCDataOu_kc[3];

    /* Update for Memory: '<S69>/Memory' */
    QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_as[3] =
      QD2_DroneStack_PID_2021a_B.ImpAsg_InsertedFor_ESCDataOut4_[3];

    /* Update for Memory: '<S68>/Memory' */
    QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_n[3] =
      QD2_DroneStack_PID_2021a_B.ImpAsg_InsertedFor_ESCDataOut_k[3];

    /* Update for Delay: '<S70>/Delay3' */
    QD2_DroneStack_PID_2021a_DW.Delay3_DSTATE[0] =
      QD2_DroneStack_PID_2021a_DW.Delay3_DSTATE[1];
    QD2_DroneStack_PID_2021a_DW.Delay3_DSTATE[1] =
      QD2_DroneStack_PID_2021a_B.Selector[0];

    /* Update for Delay: '<S70>/Delay2' */
    QD2_DroneStack_PID_2021a_DW.Delay2_DSTATE[0] =
      QD2_DroneStack_PID_2021a_DW.Delay2_DSTATE[1];
    QD2_DroneStack_PID_2021a_DW.Delay2_DSTATE[1] =
      QD2_DroneStack_PID_2021a_B.Selector[1];

    /* Update for Delay: '<S70>/Delay1' */
    QD2_DroneStack_PID_2021a_DW.Delay1_DSTATE[0] =
      QD2_DroneStack_PID_2021a_DW.Delay1_DSTATE[1];
    QD2_DroneStack_PID_2021a_DW.Delay1_DSTATE[1] =
      QD2_DroneStack_PID_2021a_B.Selector[2];

    /* Update for Delay: '<S70>/Delay' */
    QD2_DroneStack_PID_2021a_DW.Delay_DSTATE_e[0] =
      QD2_DroneStack_PID_2021a_DW.Delay_DSTATE_e[1];
    QD2_DroneStack_PID_2021a_DW.Delay_DSTATE_e[1] =
      QD2_DroneStack_PID_2021a_B.Selector[3];

    /* Update for DiscreteIntegrator: '<S96>/Discrete-Time Integrator' */
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE +=
      QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_gainval *
      QD2_DroneStack_PID_2021a_B.DataTypeConversion_n;
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
      QD2_DroneStack_PID_2021a_B.LogicalOperator;

    /* Update for DiscreteIntegrator: '<S98>/Discrete-Time Integrator' */
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_o +=
      QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_gainva_f *
      QD2_DroneStack_PID_2021a_B.DataTypeConversion_o;
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevRe_p = (int8_T)
      QD2_DroneStack_PID_2021a_B.LogicalOperator_b;

    /* Update for DiscreteIntegrator: '<S99>/Discrete-Time Integrator' */
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_b +=
      QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_gainva_p *
      QD2_DroneStack_PID_2021a_B.DataTypeConversion_a;
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevRe_g = (int8_T)
      QD2_DroneStack_PID_2021a_B.LogicalOperator_a;

    /* Update for DiscreteIntegrator: '<S102>/Discrete-Time Integrator' */
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_d +=
      QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_gainva_g *
      QD2_DroneStack_PID_2021a_B.DataTypeConversion_a2;
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevRe_o = (int8_T)
      QD2_DroneStack_PID_2021a_B.LogicalOperator_bu;

    /* Update for DiscreteIntegrator: '<S103>/Discrete-Time Integrator' */
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_f +=
      QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_gainva_e *
      QD2_DroneStack_PID_2021a_B.DataTypeConversion_p;
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevR_oi = (int8_T)
      QD2_DroneStack_PID_2021a_B.LogicalOperator_m;

    /* Update for DiscreteIntegrator: '<S104>/Discrete-Time Integrator' */
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_g +=
      QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_gainva_o *
      QD2_DroneStack_PID_2021a_B.DataTypeConversion_b;
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevRe_e = (int8_T)
      QD2_DroneStack_PID_2021a_B.LogicalOperator_l;

    /* Update for DiscreteIntegrator: '<S105>/Discrete-Time Integrator' */
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_n +=
      QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_gainva_d *
      QD2_DroneStack_PID_2021a_B.DataTypeConversion_nn;
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevRe_n = (int8_T)
      QD2_DroneStack_PID_2021a_B.LogicalOperator_l3;

    /* Update for DiscreteIntegrator: '<S106>/Discrete-Time Integrator' */
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_p +=
      QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_gainv_el *
      QD2_DroneStack_PID_2021a_B.DataTypeConversion_h;
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevR_p5 = (int8_T)
      QD2_DroneStack_PID_2021a_B.LogicalOperator_o;

    /* Update for DiscreteIntegrator: '<S107>/Discrete-Time Integrator' */
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_j +=
      QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_gainv_f5 *
      QD2_DroneStack_PID_2021a_B.DataTypeConversion_l;
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevRe_d = (int8_T)
      QD2_DroneStack_PID_2021a_B.LogicalOperator_ms;

    /* Update for DiscreteIntegrator: '<S108>/Discrete-Time Integrator' */
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_h +=
      QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_gainva_m *
      QD2_DroneStack_PID_2021a_B.DataTypeConversion_df;
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevR_nn = (int8_T)
      QD2_DroneStack_PID_2021a_B.LogicalOperator_og;

    /* Update for DiscreteIntegrator: '<S109>/Discrete-Time Integrator' */
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTAT_n1 +=
      QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_gainva_b *
      QD2_DroneStack_PID_2021a_B.DataTypeConversion_hb;
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevR_eu = (int8_T)
      QD2_DroneStack_PID_2021a_B.LogicalOperator_on;

    /* Update for DiscreteIntegrator: '<S100>/Discrete-Time Integrator' */
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_c +=
      QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_gainv_my *
      QD2_DroneStack_PID_2021a_B.DataTypeConversion_ai;
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevR_gx = (int8_T)
      QD2_DroneStack_PID_2021a_B.LogicalOperator_lm;

    /* Update for DiscreteIntegrator: '<S101>/Discrete-Time Integrator' */
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_a +=
      QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_gainva_a *
      QD2_DroneStack_PID_2021a_B.DataTypeConversion_d;
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevRe_f = (int8_T)
      QD2_DroneStack_PID_2021a_B.LogicalOperator_i;

    /* Update for DiscreteIntegrator: '<S80>/Discrete-Time Integrator' */
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTAT_bm +=
      QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_gainv_fp *
      QD2_DroneStack_PID_2021a_B.DataTypeConversion_e;
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevR_oj = (int8_T)
      QD2_DroneStack_PID_2021a_B.LogicalOperator_p;

    /* Update for UnitDelay: '<Root>/Unit Delay' */
    QD2_DroneStack_PID_2021a_DW.UnitDelay_DSTATE =
      QD2_DroneStack_PID_2021a_B.esc_ready;

    /* Update for DiscreteIntegrator: '<S21>/Discrete-Time Integrator' */
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTAT_jy +=
      QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_gainv_e0 *
      QD2_DroneStack_PID_2021a_B.DataTypeConversion_e3;
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevR_dp = (int8_T)
      QD2_DroneStack_PID_2021a_B.LogicalOperator_ab;

    /* Update for DiscreteIntegrator: '<S49>/Discrete-Time Integrator' */
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_e +=
      QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_gainva_i *
      QD2_DroneStack_PID_2021a_B.DataTypeConversion_ni;
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevRe_l = (int8_T)
      QD2_DroneStack_PID_2021a_B.LogicalOperator_f;

    /* Update for DiscreteIntegrator: '<S50>/Discrete-Time Integrator' */
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_i +=
      QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_gainv_g3 *
      QD2_DroneStack_PID_2021a_B.DataTypeConversion_l2;
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevR_gh = (int8_T)
      QD2_DroneStack_PID_2021a_B.LogicalOperator_ft;

    /* Update for DiscreteIntegrator: '<S14>/Discrete-Time Integrator' */
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTAT_ja +=
      QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_gainv_e1 *
      QD2_DroneStack_PID_2021a_B.DataTypeConversion_i;
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevRe_a = (int8_T)
      QD2_DroneStack_PID_2021a_B.LogicalOperator_bd;

    /* Update for UnitDelay: '<S27>/Delay Input1' */
    QD2_DroneStack_PID_2021a_DW.DelayInput1_DSTATE =
      QD2_DroneStack_PID_2021a_B.Memory;

    /* Update for DiscreteIntegrator: '<S114>/Discrete-Time Integrator' */
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_k +=
      QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_gainva_n *
      QD2_DroneStack_PID_2021a_B.DataTypeConversion_ah;
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevR_df = (int8_T)
      QD2_DroneStack_PID_2021a_B.LogicalOperator_bx;

    /* Update for DiscreteIntegrator: '<S113>/Discrete-Time Integrator' */
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTAT_fv +=
      QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_gainv_m3 *
      QD2_DroneStack_PID_2021a_B.DataTypeConversion_m;
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevR_az = (int8_T)
      QD2_DroneStack_PID_2021a_B.LogicalOperator_c;
  }

  /* Update for Integrator: '<S52>/Integrator1' */
  QD2_DroneStack_PID_2021a_DW.Integrator1_DWORK1_p = false;
  if (rtmIsMajorTimeStep(QD2_DroneStack_PID_2021a_M)) {
    rt_ertODEUpdateContinuousStates(&QD2_DroneStack_PID_2021a_M->solverInfo);
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++QD2_DroneStack_PID_2021a_M->Timing.clockTick0)) {
    ++QD2_DroneStack_PID_2021a_M->Timing.clockTickH0;
  }

  QD2_DroneStack_PID_2021a_M->Timing.t[0] = rtsiGetSolverStopTime
    (&QD2_DroneStack_PID_2021a_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++QD2_DroneStack_PID_2021a_M->Timing.clockTick1)) {
    ++QD2_DroneStack_PID_2021a_M->Timing.clockTickH1;
  }

  QD2_DroneStack_PID_2021a_M->Timing.t[1] =
    QD2_DroneStack_PID_2021a_M->Timing.clockTick1 *
    QD2_DroneStack_PID_2021a_M->Timing.stepSize1 +
    QD2_DroneStack_PID_2021a_M->Timing.clockTickH1 *
    QD2_DroneStack_PID_2021a_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void QD2_DroneStack_PID_2021a_derivatives(void)
{
  /* local scratch DWork variables */
  int32_T ForEach_itr_a;
  XDot_QD2_DroneStack_PID_2021a_T *_rtXdot;
  boolean_T lsat;
  boolean_T usat;
  _rtXdot = ((XDot_QD2_DroneStack_PID_2021a_T *)
             QD2_DroneStack_PID_2021a_M->derivs);

  /* Derivatives for Integrator: '<S3>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = QD2_DroneStack_PID_2021a_B.Sum2;

  /* Derivatives for Integrator: '<S1>/Integrator1' */
  lsat = (QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_f[0] <=
          QD2_DroneStack_PID_2021a_P.Integrator1_LowerSat[0]);
  usat = (QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_f[0] >=
          QD2_DroneStack_PID_2021a_P.Integrator1_UpperSat[0]);
  if ((!lsat && !usat) || (lsat && (QD2_DroneStack_PID_2021a_B.Gain1[0] > 0.0)) ||
      (usat && (QD2_DroneStack_PID_2021a_B.Gain1[0] < 0.0))) {
    _rtXdot->Integrator1_CSTATE_f[0] = QD2_DroneStack_PID_2021a_B.Gain1[0];
  } else {
    /* in saturation */
    _rtXdot->Integrator1_CSTATE_f[0] = 0.0;
  }

  lsat = (QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_f[1] <=
          QD2_DroneStack_PID_2021a_P.Integrator1_LowerSat[1]);
  usat = (QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_f[1] >=
          QD2_DroneStack_PID_2021a_P.Integrator1_UpperSat[1]);
  if ((!lsat && !usat) || (lsat && (QD2_DroneStack_PID_2021a_B.Gain1[1] > 0.0)) ||
      (usat && (QD2_DroneStack_PID_2021a_B.Gain1[1] < 0.0))) {
    _rtXdot->Integrator1_CSTATE_f[1] = QD2_DroneStack_PID_2021a_B.Gain1[1];
  } else {
    /* in saturation */
    _rtXdot->Integrator1_CSTATE_f[1] = 0.0;
  }

  lsat = (QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_f[2] <=
          QD2_DroneStack_PID_2021a_P.Integrator1_LowerSat[2]);
  usat = (QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_f[2] >=
          QD2_DroneStack_PID_2021a_P.Integrator1_UpperSat[2]);
  if ((!lsat && !usat) || (lsat && (QD2_DroneStack_PID_2021a_B.Gain1[2] > 0.0)) ||
      (usat && (QD2_DroneStack_PID_2021a_B.Gain1[2] < 0.0))) {
    _rtXdot->Integrator1_CSTATE_f[2] = QD2_DroneStack_PID_2021a_B.Gain1[2];
  } else {
    /* in saturation */
    _rtXdot->Integrator1_CSTATE_f[2] = 0.0;
  }

  lsat = (QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_f[3] <=
          QD2_DroneStack_PID_2021a_P.Integrator1_LowerSat[3]);
  usat = (QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_f[3] >=
          QD2_DroneStack_PID_2021a_P.Integrator1_UpperSat[3]);
  if ((!lsat && !usat) || (lsat && (QD2_DroneStack_PID_2021a_B.Gain1[3] > 0.0)) ||
      (usat && (QD2_DroneStack_PID_2021a_B.Gain1[3] < 0.0))) {
    _rtXdot->Integrator1_CSTATE_f[3] = QD2_DroneStack_PID_2021a_B.Gain1[3];
  } else {
    /* in saturation */
    _rtXdot->Integrator1_CSTATE_f[3] = 0.0;
  }

  /* End of Derivatives for Integrator: '<S1>/Integrator1' */

  /* Derivatives for Integrator: '<S3>/Integrator6' */
  _rtXdot->Integrator6_CSTATE[0] = QD2_DroneStack_PID_2021a_B.Sum9[0];
  _rtXdot->Integrator6_CSTATE[1] = QD2_DroneStack_PID_2021a_B.Sum9[1];
  _rtXdot->Integrator6_CSTATE[2] = QD2_DroneStack_PID_2021a_B.Sum9[2];

  /* Derivatives for Iterator SubSystem: '<S63>/For Each Subsystem - Iterate over IMU0 and IMU1' */
  for (ForEach_itr_a = 0; ForEach_itr_a < 2; ForEach_itr_a++) {
    /* Derivatives for Integrator: '<S85>/Integrator1' incorporates:
     *  Product: '<S85>/Product1'
     */
    _rtXdot->CoreSubsys_pn[ForEach_itr_a].Integrator1_CSTATE_b[0] =
      QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Product1_i[0];
    _rtXdot->CoreSubsys_pn[ForEach_itr_a].Integrator1_CSTATE_b[1] =
      QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Product1_i[1];
    _rtXdot->CoreSubsys_pn[ForEach_itr_a].Integrator1_CSTATE_b[2] =
      QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Product1_i[2];

    /* Derivatives for Integrator: '<S82>/Integrator1' */
    _rtXdot->CoreSubsys_pn[ForEach_itr_a].Integrator1_CSTATE_n[0] =
      QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Sum1[0];
    _rtXdot->CoreSubsys_pn[ForEach_itr_a].Integrator1_CSTATE_n[1] =
      QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Sum1[1];

    /* Derivatives for Integrator: '<S82>/Integrator2' */
    _rtXdot->CoreSubsys_pn[ForEach_itr_a].Integrator2_CSTATE_od =
      QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Integrator1[2];

    /* Derivatives for Integrator: '<S84>/Integrator1' incorporates:
     *  Product: '<S84>/Product1'
     */
    _rtXdot->CoreSubsys_pn[ForEach_itr_a].Integrator1_CSTATE_o[0] =
      QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Product1[0];

    /* Derivatives for Integrator: '<S84>/Integrator2' incorporates:
     *  Product: '<S84>/Product'
     */
    _rtXdot->CoreSubsys_pn[ForEach_itr_a].Integrator2_CSTATE_i[0] =
      QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Product[0];

    /* Derivatives for Integrator: '<S84>/Integrator1' incorporates:
     *  Product: '<S84>/Product1'
     */
    _rtXdot->CoreSubsys_pn[ForEach_itr_a].Integrator1_CSTATE_o[1] =
      QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Product1[1];

    /* Derivatives for Integrator: '<S84>/Integrator2' incorporates:
     *  Product: '<S84>/Product'
     */
    _rtXdot->CoreSubsys_pn[ForEach_itr_a].Integrator2_CSTATE_i[1] =
      QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Product[1];

    /* Derivatives for Integrator: '<S84>/Integrator1' incorporates:
     *  Product: '<S84>/Product1'
     */
    _rtXdot->CoreSubsys_pn[ForEach_itr_a].Integrator1_CSTATE_o[2] =
      QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Product1[2];

    /* Derivatives for Integrator: '<S84>/Integrator2' incorporates:
     *  Product: '<S84>/Product'
     */
    _rtXdot->CoreSubsys_pn[ForEach_itr_a].Integrator2_CSTATE_i[2] =
      QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Product[2];

    /* Derivatives for Integrator: '<S82>/Integrator' */
    _rtXdot->CoreSubsys_pn[ForEach_itr_a].Integrator_CSTATE[0] =
      QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Gain1[0];
    _rtXdot->CoreSubsys_pn[ForEach_itr_a].Integrator_CSTATE[1] =
      QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Gain1[1];

    /* Derivatives for Integrator: '<S85>/Integrator2' incorporates:
     *  Product: '<S85>/Product'
     */
    _rtXdot->CoreSubsys_pn[ForEach_itr_a].Integrator2_CSTATE_k[0] =
      QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Product_i[0];
    _rtXdot->CoreSubsys_pn[ForEach_itr_a].Integrator2_CSTATE_k[1] =
      QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Product_i[1];
    _rtXdot->CoreSubsys_pn[ForEach_itr_a].Integrator2_CSTATE_k[2] =
      QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Product_i[2];
  }

  /* End of Derivatives for SubSystem: '<S63>/For Each Subsystem - Iterate over IMU0 and IMU1' */

  /* Derivatives for Integrator: '<S39>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_h[0] = QD2_DroneStack_PID_2021a_B.Product1_m[0];

  /* Derivatives for Integrator: '<S39>/Integrator2' */
  _rtXdot->Integrator2_CSTATE[0] = QD2_DroneStack_PID_2021a_B.Product_i[0];

  /* Derivatives for Integrator: '<S39>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_h[1] = QD2_DroneStack_PID_2021a_B.Product1_m[1];

  /* Derivatives for Integrator: '<S39>/Integrator2' */
  _rtXdot->Integrator2_CSTATE[1] = QD2_DroneStack_PID_2021a_B.Product_i[1];

  /* Derivatives for Integrator: '<S3>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_o = QD2_DroneStack_PID_2021a_B.Ki1;

  /* Derivatives for Integrator: '<S3>/Integrator7' */
  _rtXdot->Integrator7_CSTATE[0] = QD2_DroneStack_PID_2021a_B.Ki3[0];

  /* Derivatives for Integrator: '<S52>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_c[0] = QD2_DroneStack_PID_2021a_B.Product_b[0];

  /* Derivatives for Integrator: '<S52>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_j[0] = QD2_DroneStack_PID_2021a_B.Product1_j[0];

  /* Derivatives for Integrator: '<S3>/Integrator7' */
  _rtXdot->Integrator7_CSTATE[1] = QD2_DroneStack_PID_2021a_B.Ki3[1];

  /* Derivatives for Integrator: '<S52>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_c[1] = QD2_DroneStack_PID_2021a_B.Product_b[1];

  /* Derivatives for Integrator: '<S52>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_j[1] = QD2_DroneStack_PID_2021a_B.Product1_j[1];

  /* Derivatives for Integrator: '<S3>/Integrator7' */
  _rtXdot->Integrator7_CSTATE[2] = QD2_DroneStack_PID_2021a_B.Ki3[2];

  /* Derivatives for Integrator: '<S52>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_c[2] = QD2_DroneStack_PID_2021a_B.Product_b[2];

  /* Derivatives for Integrator: '<S52>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_j[2] = QD2_DroneStack_PID_2021a_B.Product1_j[2];
}

/* Model output function for TID2 */
void QD2_DroneStack_PID_2021a_output2(void) /* Sample time: [0.002s, 0.0s] */
{
  /* local block i/o variables */
  boolean_T rtb_StreamServer_o3;
  boolean_T rtb_StreamServer_o5;
  real_T rtb_TmpSignalConversionAtStream[47];
  boolean_T rtb_Memory3;

  /* SignalConversion generated from: '<S5>/Stream Server' incorporates:
   *  Memory: '<S5>/Memory2'
   *  RateTransition: '<S5>/Rate Transition10'
   *  RateTransition: '<S5>/Rate Transition11'
   *  RateTransition: '<S5>/Rate Transition12'
   *  RateTransition: '<S5>/Rate Transition15'
   *  RateTransition: '<S5>/Rate Transition17'
   *  RateTransition: '<S5>/Rate Transition19'
   *  RateTransition: '<S5>/Rate Transition20'
   *  RateTransition: '<S5>/Rate Transition8'
   */
  memcpy(&rtb_TmpSignalConversionAtStream[0],
         &QD2_DroneStack_PID_2021a_DW.RateTransition8_Buffer[0], 12U * sizeof
         (real_T));
  memcpy(&rtb_TmpSignalConversionAtStream[12],
         &QD2_DroneStack_PID_2021a_DW.RateTransition15_Buffer[0], 9U * sizeof
         (real_T));
  memcpy(&rtb_TmpSignalConversionAtStream[21],
         &QD2_DroneStack_PID_2021a_DW.RateTransition17_Buffer[0], 9U * sizeof
         (real_T));
  memcpy(&rtb_TmpSignalConversionAtStream[30],
         &QD2_DroneStack_PID_2021a_DW.RateTransition19_Buffer[0], 9U * sizeof
         (real_T));
  rtb_TmpSignalConversionAtStream[39] =
    QD2_DroneStack_PID_2021a_DW.RateTransition20_Buffer;
  rtb_TmpSignalConversionAtStream[40] =
    QD2_DroneStack_PID_2021a_DW.RateTransition10_Buffer[0];
  rtb_TmpSignalConversionAtStream[41] =
    QD2_DroneStack_PID_2021a_DW.RateTransition10_Buffer[1];
  rtb_TmpSignalConversionAtStream[42] =
    QD2_DroneStack_PID_2021a_DW.RateTransition10_Buffer[2];
  rtb_TmpSignalConversionAtStream[43] =
    QD2_DroneStack_PID_2021a_DW.RateTransition10_Buffer[3];
  rtb_TmpSignalConversionAtStream[44] =
    QD2_DroneStack_PID_2021a_DW.RateTransition12_Buffer;
  rtb_TmpSignalConversionAtStream[45] =
    QD2_DroneStack_PID_2021a_DW.RateTransition11_Buffer;
  rtb_TmpSignalConversionAtStream[46] =
    QD2_DroneStack_PID_2021a_DW.Memory2_PreviousInput;

  /* Memory: '<S5>/Memory3' */
  rtb_Memory3 = QD2_DroneStack_PID_2021a_DW.Memory3_PreviousInput;

  /* RateTransition: '<S5>/Rate Transition14' incorporates:
   *  RateTransition: '<S5>/Rate Transition16'
   *  S-Function (stream_server_block): '<S5>/Stream Server'
   */

  /* S-Function Block: QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Stream Server (stream_server_block) */
  {
    t_pstream_state state;
    t_error send_result;
    t_error receive_result;
    if (rtb_Memory3) {
      send_result = pstream_send(QD2_DroneStack_PID_2021a_DW.StreamServer_Stream,
        &rtb_TmpSignalConversionAtStream[0]);
    } else {
      send_result = 0;
    }

    rtb_StreamServer_o3 = (send_result > 0);
    receive_result = pstream_receive
      (QD2_DroneStack_PID_2021a_DW.StreamServer_Stream,
       &QD2_DroneStack_PID_2021a_B.StreamServer_o4);
    rtb_StreamServer_o5 = (receive_result > 0);
    QD2_DroneStack_PID_2021a_B.RateTransition14 = 0;
    if (send_result < 0 && send_result != -QERR_WOULD_BLOCK) {
      QD2_DroneStack_PID_2021a_B.RateTransition14 = send_result;
    } else if (receive_result < 0 && receive_result != -QERR_WOULD_BLOCK) {
      QD2_DroneStack_PID_2021a_B.RateTransition14 = receive_result;
    }

    pstream_get_state(QD2_DroneStack_PID_2021a_DW.StreamServer_Stream, &state);
    QD2_DroneStack_PID_2021a_B.RateTransition16 = state;
  }

  /* Logic: '<S5>/AND' incorporates:
   *  Constant: '<S65>/Constant'
   *  Constant: '<S66>/Constant'
   *  RelationalOperator: '<S65>/Compare'
   *  RelationalOperator: '<S66>/Compare'
   */
  QD2_DroneStack_PID_2021a_B.AND_f =
    ((QD2_DroneStack_PID_2021a_B.RateTransition16 ==
      QD2_DroneStack_PID_2021a_P.CompareToConstant_const_n) &&
     (QD2_DroneStack_PID_2021a_B.RateTransition14 >=
      QD2_DroneStack_PID_2021a_P.CompareToConstant1_const_m));
}

/* Model update function for TID2 */
void QD2_DroneStack_PID_2021a_update2(void) /* Sample time: [0.002s, 0.0s] */
{
  /* Update for Memory: '<S5>/Memory2' */
  QD2_DroneStack_PID_2021a_DW.Memory2_PreviousInput =
    QD2_DroneStack_PID_2021a_B.StreamServer_o4;

  /* Update for Memory: '<S5>/Memory3' */
  QD2_DroneStack_PID_2021a_DW.Memory3_PreviousInput =
    QD2_DroneStack_PID_2021a_B.AND_f;

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++QD2_DroneStack_PID_2021a_M->Timing.clockTick2)) {
    ++QD2_DroneStack_PID_2021a_M->Timing.clockTickH2;
  }

  QD2_DroneStack_PID_2021a_M->Timing.t[2] =
    QD2_DroneStack_PID_2021a_M->Timing.clockTick2 *
    QD2_DroneStack_PID_2021a_M->Timing.stepSize2 +
    QD2_DroneStack_PID_2021a_M->Timing.clockTickH2 *
    QD2_DroneStack_PID_2021a_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output function for TID3 */
void QD2_DroneStack_PID_2021a_output3(void) /* Sample time: [0.01s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_ComputationTime1;
  real_T rtb_SampleTime1;
  int32_T i;
  for (i = 0; i < 7; i++) {
    /* RateTransition: '<S5>/Rate Transition' */
    QD2_DroneStack_PID_2021a_B.RateTransition_p[i] =
      QD2_DroneStack_PID_2021a_DW.RateTransition_Buffer[i];
  }

  /* Constant: '<S72>/x0' */
  QD2_DroneStack_PID_2021a_B.x0 = QD2_DroneStack_PID_2021a_P.x0_Value;

  /* Product: '<S72>/Product' incorporates:
   *  Constant: '<S72>/Constant'
   *  Constant: '<S72>/bandwidth'
   *  Constant: '<S72>/zeta'
   *  DiscreteIntegrator: '<S72>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S72>/Discrete-Time Integrator1'
   *  Product: '<S72>/Product2'
   *  Sum: '<S72>/Sum'
   *  Sum: '<S72>/Sum1'
   */
  QD2_DroneStack_PID_2021a_B.Product_j[0] =
    ((QD2_DroneStack_PID_2021a_B.RateTransition_p[0] -
      QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator1_DSTATE[0]) -
     QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTAT_a1[0] *
     QD2_DroneStack_PID_2021a_P.Constant_Value_b *
     QD2_DroneStack_PID_2021a_P.DiscreteSecondOrderLowPassFil_p) *
    QD2_DroneStack_PID_2021a_P.DiscreteSecondOrderLowPassFilte;

  /* Product: '<S72>/Product1' incorporates:
   *  Constant: '<S72>/bandwidth'
   *  DiscreteIntegrator: '<S72>/Discrete-Time Integrator'
   */
  QD2_DroneStack_PID_2021a_B.Product1_d[0] =
    QD2_DroneStack_PID_2021a_P.DiscreteSecondOrderLowPassFilte *
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTAT_a1[0];

  /* RateTransition: '<S5>/Rate Transition7' incorporates:
   *  DiscreteIntegrator: '<S72>/Discrete-Time Integrator1'
   */
  QD2_DroneStack_PID_2021a_DW.RateTransition7_Buffer0[0] =
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator1_DSTATE[0];

  /* Product: '<S72>/Product' incorporates:
   *  Constant: '<S72>/Constant'
   *  Constant: '<S72>/bandwidth'
   *  Constant: '<S72>/zeta'
   *  DiscreteIntegrator: '<S72>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S72>/Discrete-Time Integrator1'
   *  Product: '<S72>/Product2'
   *  Sum: '<S72>/Sum'
   *  Sum: '<S72>/Sum1'
   */
  QD2_DroneStack_PID_2021a_B.Product_j[1] =
    ((QD2_DroneStack_PID_2021a_B.RateTransition_p[1] -
      QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator1_DSTATE[1]) -
     QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTAT_a1[1] *
     QD2_DroneStack_PID_2021a_P.Constant_Value_b *
     QD2_DroneStack_PID_2021a_P.DiscreteSecondOrderLowPassFil_p) *
    QD2_DroneStack_PID_2021a_P.DiscreteSecondOrderLowPassFilte;

  /* Product: '<S72>/Product1' incorporates:
   *  Constant: '<S72>/bandwidth'
   *  DiscreteIntegrator: '<S72>/Discrete-Time Integrator'
   */
  QD2_DroneStack_PID_2021a_B.Product1_d[1] =
    QD2_DroneStack_PID_2021a_P.DiscreteSecondOrderLowPassFilte *
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTAT_a1[1];

  /* RateTransition: '<S5>/Rate Transition7' incorporates:
   *  DiscreteIntegrator: '<S72>/Discrete-Time Integrator1'
   */
  QD2_DroneStack_PID_2021a_DW.RateTransition7_Buffer0[1] =
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator1_DSTATE[1];

  /* S-Function (computation_time_block): '<S81>/Computation Time1' */

  /* S-Function Block: QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Timing Monitors/Computation Time1 (computation_time_block) */
  {
    rtb_ComputationTime1 =
      QD2_DroneStack_PID_2021a_DW.ComputationTime1_ComputationTim.seconds +
      QD2_DroneStack_PID_2021a_DW.ComputationTime1_ComputationTim.nanoseconds *
      1e-9;
  }

  /* RateTransition: '<S81>/Rate Transition' */
  QD2_DroneStack_PID_2021a_DW.RateTransition_Buffer0 = rtb_ComputationTime1;

  /* S-Function (sample_time_block): '<S81>/Sample Time1' */

  /* S-Function Block: QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Timing Monitors/Sample Time1 (sample_time_block) */
  {
    t_error result;
    t_timeout current_time;
    t_timeout time_difference;
    result = timeout_get_high_resolution_time(&current_time);
    if (result >= 0) {
      result = timeout_subtract(&time_difference, &current_time,
        &QD2_DroneStack_PID_2021a_DW.SampleTime1_PreviousTime);
      rtb_SampleTime1 = time_difference.seconds + time_difference.nanoseconds *
        1e-9;
      memcpy(&QD2_DroneStack_PID_2021a_DW.SampleTime1_PreviousTime,
             &current_time, sizeof(t_timeout));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M, _rt_error_message);
      return;
    }
  }

  /* RateTransition: '<S81>/Rate Transition1' */
  QD2_DroneStack_PID_2021a_DW.RateTransition1_Buffer0_m = rtb_SampleTime1;
}

/* Model update function for TID3 */
void QD2_DroneStack_PID_2021a_update3(void) /* Sample time: [0.01s, 0.0s] */
{
  /* Update for DiscreteIntegrator: '<S72>/Discrete-Time Integrator' */
  QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTAT_a1[0] +=
    QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_gainva_c *
    QD2_DroneStack_PID_2021a_B.Product_j[0];

  /* Update for DiscreteIntegrator: '<S72>/Discrete-Time Integrator1' */
  QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator1_DSTATE[0] +=
    QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator1_gainval *
    QD2_DroneStack_PID_2021a_B.Product1_d[0];

  /* Update for DiscreteIntegrator: '<S72>/Discrete-Time Integrator' */
  QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTAT_a1[1] +=
    QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_gainva_c *
    QD2_DroneStack_PID_2021a_B.Product_j[1];

  /* Update for DiscreteIntegrator: '<S72>/Discrete-Time Integrator1' */
  QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator1_DSTATE[1] +=
    QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator1_gainval *
    QD2_DroneStack_PID_2021a_B.Product1_d[1];

  /* Update absolute time */
  /* The "clockTick3" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick3"
   * and "Timing.stepSize3". Size of "clockTick3" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick3 and the high bits
   * Timing.clockTickH3. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++QD2_DroneStack_PID_2021a_M->Timing.clockTick3)) {
    ++QD2_DroneStack_PID_2021a_M->Timing.clockTickH3;
  }

  QD2_DroneStack_PID_2021a_M->Timing.t[3] =
    QD2_DroneStack_PID_2021a_M->Timing.clockTick3 *
    QD2_DroneStack_PID_2021a_M->Timing.stepSize3 +
    QD2_DroneStack_PID_2021a_M->Timing.clockTickH3 *
    QD2_DroneStack_PID_2021a_M->Timing.stepSize3 * 4294967296.0;
}

/* Model output function for TID4 */
void QD2_DroneStack_PID_2021a_output4(void) /* Sample time: [0.04s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_ComputationTime2;
  real_T rtb_SampleTime2;
  real_T rtb_MatrixMultiply[3];
  real_T rtb_DiscreteTimeIntegrator1_k;
  real_T rtb_MatrixMultiply_0;
  int32_T i;

  /* Constant: '<S5>/ToF Filter Initial Condition (m)' */
  QD2_DroneStack_PID_2021a_B.ToFFilterInitialConditionm =
    QD2_DroneStack_PID_2021a_P.ToFFilterInitialConditionm_Valu;

  /* DiscreteIntegrator: '<S71>/Discrete-Time Integrator1' */
  rtb_DiscreteTimeIntegrator1_k =
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator1_DSTAT_l;

  /* S-Function (ranging_sensor_block): '<S5>/Ranging Sensor' */

  /* S-Function Block: QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Ranging Sensor (ranging_sensor_block) */
  {
    t_error result;
    result = vl53l1x_read(QD2_DroneStack_PID_2021a_DW.RangingSensor_Sensor,
                          &QD2_DroneStack_PID_2021a_DW.RangingSensor_Measurements);
    if (result >= 0) {
      QD2_DroneStack_PID_2021a_B.RangingSensor_o1 =
        QD2_DroneStack_PID_2021a_DW.RangingSensor_Measurements.distance;
    } else {
      if (result != -QERR_WOULD_BLOCK) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M, _rt_error_message);
      }
    }
  }

  /* Product: '<S71>/Product' incorporates:
   *  Constant: '<S5>/ToF Filter Cutoff Frequency (rad)'
   *  Constant: '<S5>/ToF Filter Damping Ratio'
   *  Constant: '<S71>/Constant'
   *  DiscreteIntegrator: '<S71>/Discrete-Time Integrator'
   *  Product: '<S71>/Product2'
   *  Sum: '<S71>/Sum'
   *  Sum: '<S71>/Sum1'
   */
  QD2_DroneStack_PID_2021a_B.Product_g =
    ((QD2_DroneStack_PID_2021a_B.RangingSensor_o1 -
      rtb_DiscreteTimeIntegrator1_k) -
     QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTAT_ax *
     QD2_DroneStack_PID_2021a_P.Constant_Value_j *
     QD2_DroneStack_PID_2021a_P.ToFFilterDampingRatio_Value) *
    QD2_DroneStack_PID_2021a_P.ToFFilterCutoffFrequencyrad_Val;

  /* Product: '<S71>/Product1' incorporates:
   *  Constant: '<S5>/ToF Filter Cutoff Frequency (rad)'
   *  DiscreteIntegrator: '<S71>/Discrete-Time Integrator'
   */
  QD2_DroneStack_PID_2021a_B.Product1_g =
    QD2_DroneStack_PID_2021a_P.ToFFilterCutoffFrequencyrad_Val *
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTAT_ax;

  /* SignalConversion generated from: '<S5>/Matrix Multiply' incorporates:
   *  Constant: '<S5>/ToF Sensor XY Offsets (m)'
   */
  rtb_MatrixMultiply[0] = QD2_DroneStack_PID_2021a_P.ToFSensorXYOffsetsm_Value[0];
  rtb_MatrixMultiply[1] = QD2_DroneStack_PID_2021a_P.ToFSensorXYOffsetsm_Value[1];
  rtb_MatrixMultiply[2] = rtb_DiscreteTimeIntegrator1_k;

  /* Product: '<S5>/Matrix Multiply' incorporates:
   *  RateTransition: '<S5>/Rate Transition3'
   */
  rtb_MatrixMultiply_0 = 0.0;
  for (i = 0; i < 3; i++) {
    rtb_MatrixMultiply_0 += QD2_DroneStack_PID_2021a_DW.RateTransition3_Buffer[3
      * i + 2] * rtb_MatrixMultiply[i];
  }

  rtb_MatrixMultiply[2] = rtb_MatrixMultiply_0;

  /* End of Product: '<S5>/Matrix Multiply' */

  /* RateTransition: '<S5>/Rate Transition1' */
  QD2_DroneStack_PID_2021a_DW.RateTransition1_Buffer0 = rtb_MatrixMultiply[2];

  /* RateTransition: '<S5>/Rate Transition2' */
  QD2_DroneStack_PID_2021a_DW.RateTransition2_Buffer0 =
    rtb_DiscreteTimeIntegrator1_k;

  /* S-Function (computation_time_block): '<S81>/Computation Time2' */

  /* S-Function Block: QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Timing Monitors/Computation Time2 (computation_time_block) */
  {
    rtb_ComputationTime2 =
      QD2_DroneStack_PID_2021a_DW.ComputationTime2_ComputationTim.seconds +
      QD2_DroneStack_PID_2021a_DW.ComputationTime2_ComputationTim.nanoseconds *
      1e-9;
  }

  /* RateTransition: '<S81>/Rate Transition2' */
  QD2_DroneStack_PID_2021a_DW.RateTransition2_Buffer0_m = rtb_ComputationTime2;

  /* S-Function (sample_time_block): '<S81>/Sample Time2' */

  /* S-Function Block: QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Timing Monitors/Sample Time2 (sample_time_block) */
  {
    t_error result;
    t_timeout current_time;
    t_timeout time_difference;
    result = timeout_get_high_resolution_time(&current_time);
    if (result >= 0) {
      result = timeout_subtract(&time_difference, &current_time,
        &QD2_DroneStack_PID_2021a_DW.SampleTime2_PreviousTime);
      rtb_SampleTime2 = time_difference.seconds + time_difference.nanoseconds *
        1e-9;
      memcpy(&QD2_DroneStack_PID_2021a_DW.SampleTime2_PreviousTime,
             &current_time, sizeof(t_timeout));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M, _rt_error_message);
      return;
    }
  }

  /* RateTransition: '<S81>/Rate Transition3' */
  QD2_DroneStack_PID_2021a_DW.RateTransition3_Buffer0 = rtb_SampleTime2;
}

/* Model update function for TID4 */
void QD2_DroneStack_PID_2021a_update4(void) /* Sample time: [0.04s, 0.0s] */
{
  /* Update for DiscreteIntegrator: '<S71>/Discrete-Time Integrator' */
  QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTAT_ax +=
    QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_gainva_j *
    QD2_DroneStack_PID_2021a_B.Product_g;

  /* Update for DiscreteIntegrator: '<S71>/Discrete-Time Integrator1' */
  QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator1_DSTAT_l +=
    QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator1_gainv_c *
    QD2_DroneStack_PID_2021a_B.Product1_g;

  /* Update absolute time */
  /* The "clockTick4" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick4"
   * and "Timing.stepSize4". Size of "clockTick4" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick4 and the high bits
   * Timing.clockTickH4. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++QD2_DroneStack_PID_2021a_M->Timing.clockTick4)) {
    ++QD2_DroneStack_PID_2021a_M->Timing.clockTickH4;
  }

  QD2_DroneStack_PID_2021a_M->Timing.t[4] =
    QD2_DroneStack_PID_2021a_M->Timing.clockTick4 *
    QD2_DroneStack_PID_2021a_M->Timing.stepSize4 +
    QD2_DroneStack_PID_2021a_M->Timing.clockTickH4 *
    QD2_DroneStack_PID_2021a_M->Timing.stepSize4 * 4294967296.0;
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void QD2_DroneStack_PID_2021a_output(int_T tid)
{
  switch (tid) {
   case 0 :
    QD2_DroneStack_PID_2021a_output0();
    break;

   case 2 :
    QD2_DroneStack_PID_2021a_output2();
    break;

   case 3 :
    QD2_DroneStack_PID_2021a_output3();
    break;

   case 4 :
    QD2_DroneStack_PID_2021a_output4();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void QD2_DroneStack_PID_2021a_update(int_T tid)
{
  switch (tid) {
   case 0 :
    QD2_DroneStack_PID_2021a_update0();
    break;

   case 2 :
    QD2_DroneStack_PID_2021a_update2();
    break;

   case 3 :
    QD2_DroneStack_PID_2021a_update3();
    break;

   case 4 :
    QD2_DroneStack_PID_2021a_update4();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void QD2_DroneStack_PID_2021a_initialize(void)
{
  {
    /* local scratch DWork variables */
    int32_T ForEach_itr_a;
    int32_T ForEach_itr_h;
    int32_T ForEach_itr_b;

    /* Start for S-Function (hil_initialize_block): '<S5>/HIL Initialize' */

    /* S-Function Block: QD2_DroneStack_PID_2021a/QDrone 2 DAQ/HIL Initialize (hil_initialize_block) */
    {
      t_int result;
      t_boolean is_switching;
      result = hil_open("qdrone2", "0",
                        &QD2_DroneStack_PID_2021a_DW.HILInitialize_Card);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M, _rt_error_message);
        return;
      }

      is_switching = false;
      result = hil_set_card_specific_options
        (QD2_DroneStack_PID_2021a_DW.HILInitialize_Card,
         "gyro0_fs=250;gyro0_rate=500;gyro0_bw=125;gyro0_ord=3;accel0_fs=16;accel0_rate=1000;accel0_bw=250;accel0_ord=3;temp0_bw=4000;gyro1_fs=250;gyro1_rate=500;gyro1_bw=125;gyro1_ord=3;accel1_fs=16;accel1_rate=1000;accel1_bw=400;accel1_ord=3;temp1_bw=4000;enc0_dir=0;enc1_dir=0;pwm03_dshot=1;opt_rate=121;",
         298);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M, _rt_error_message);
        return;
      }

      result = hil_watchdog_clear(QD2_DroneStack_PID_2021a_DW.HILInitialize_Card);
      if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M, _rt_error_message);
        return;
      }

      if ((QD2_DroneStack_PID_2021a_P.HILInitialize_AIPStart && !is_switching) ||
          (QD2_DroneStack_PID_2021a_P.HILInitialize_AIPEnter && is_switching)) {
        QD2_DroneStack_PID_2021a_DW.HILInitialize_AIMinimums[0] =
          QD2_DroneStack_PID_2021a_P.HILInitialize_AILow;
        QD2_DroneStack_PID_2021a_DW.HILInitialize_AIMinimums[1] =
          QD2_DroneStack_PID_2021a_P.HILInitialize_AILow;
        QD2_DroneStack_PID_2021a_DW.HILInitialize_AIMinimums[2] =
          QD2_DroneStack_PID_2021a_P.HILInitialize_AILow;
        QD2_DroneStack_PID_2021a_DW.HILInitialize_AIMinimums[3] =
          QD2_DroneStack_PID_2021a_P.HILInitialize_AILow;
        QD2_DroneStack_PID_2021a_DW.HILInitialize_AIMaximums[0] =
          QD2_DroneStack_PID_2021a_P.HILInitialize_AIHigh;
        QD2_DroneStack_PID_2021a_DW.HILInitialize_AIMaximums[1] =
          QD2_DroneStack_PID_2021a_P.HILInitialize_AIHigh;
        QD2_DroneStack_PID_2021a_DW.HILInitialize_AIMaximums[2] =
          QD2_DroneStack_PID_2021a_P.HILInitialize_AIHigh;
        QD2_DroneStack_PID_2021a_DW.HILInitialize_AIMaximums[3] =
          QD2_DroneStack_PID_2021a_P.HILInitialize_AIHigh;
        result = hil_set_analog_input_ranges
          (QD2_DroneStack_PID_2021a_DW.HILInitialize_Card,
           QD2_DroneStack_PID_2021a_P.HILInitialize_AIChannels, 4U,
           &QD2_DroneStack_PID_2021a_DW.HILInitialize_AIMinimums[0],
           &QD2_DroneStack_PID_2021a_DW.HILInitialize_AIMaximums[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M, _rt_error_message);
          return;
        }
      }

      result = hil_set_digital_directions
        (QD2_DroneStack_PID_2021a_DW.HILInitialize_Card,
         QD2_DroneStack_PID_2021a_P.HILInitialize_DIChannels, 6U,
         QD2_DroneStack_PID_2021a_P.HILInitialize_DOChannels, 6U);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M, _rt_error_message);
        return;
      }

      if ((QD2_DroneStack_PID_2021a_P.HILInitialize_DOStart && !is_switching) ||
          (QD2_DroneStack_PID_2021a_P.HILInitialize_DOEnter && is_switching)) {
        {
          int_T i1;
          boolean_T *dw_DOBits =
            &QD2_DroneStack_PID_2021a_DW.HILInitialize_DOBits[0];
          for (i1=0; i1 < 6; i1++) {
            dw_DOBits[i1] = QD2_DroneStack_PID_2021a_P.HILInitialize_DOInitial;
          }
        }

        result = hil_write_digital
          (QD2_DroneStack_PID_2021a_DW.HILInitialize_Card,
           QD2_DroneStack_PID_2021a_P.HILInitialize_DOChannels, 6U, (t_boolean *)
           &QD2_DroneStack_PID_2021a_DW.HILInitialize_DOBits[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M, _rt_error_message);
          return;
        }
      }

      if (QD2_DroneStack_PID_2021a_P.HILInitialize_DOReset) {
        result = hil_watchdog_set_digital_expiration_state
          (QD2_DroneStack_PID_2021a_DW.HILInitialize_Card,
           QD2_DroneStack_PID_2021a_P.HILInitialize_DOChannels, 6U, (const
            t_digital_state *)
           QD2_DroneStack_PID_2021a_P.HILInitialize_DOWatchdog);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M, _rt_error_message);
          return;
        }
      }

      if ((QD2_DroneStack_PID_2021a_P.HILInitialize_EIPStart && !is_switching) ||
          (QD2_DroneStack_PID_2021a_P.HILInitialize_EIPEnter && is_switching)) {
        QD2_DroneStack_PID_2021a_DW.HILInitialize_QuadratureModes[0] =
          QD2_DroneStack_PID_2021a_P.HILInitialize_EIQuadrature;
        QD2_DroneStack_PID_2021a_DW.HILInitialize_QuadratureModes[1] =
          QD2_DroneStack_PID_2021a_P.HILInitialize_EIQuadrature;
        result = hil_set_encoder_quadrature_mode
          (QD2_DroneStack_PID_2021a_DW.HILInitialize_Card,
           QD2_DroneStack_PID_2021a_P.HILInitialize_EIChannels, 2U,
           (t_encoder_quadrature_mode *)
           &QD2_DroneStack_PID_2021a_DW.HILInitialize_QuadratureModes[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M, _rt_error_message);
          return;
        }

        QD2_DroneStack_PID_2021a_DW.HILInitialize_FilterFrequency[0] =
          QD2_DroneStack_PID_2021a_P.HILInitialize_EIFrequency;
        QD2_DroneStack_PID_2021a_DW.HILInitialize_FilterFrequency[1] =
          QD2_DroneStack_PID_2021a_P.HILInitialize_EIFrequency;
        result = hil_set_encoder_filter_frequency
          (QD2_DroneStack_PID_2021a_DW.HILInitialize_Card,
           QD2_DroneStack_PID_2021a_P.HILInitialize_EIChannels, 2U,
           &QD2_DroneStack_PID_2021a_DW.HILInitialize_FilterFrequency[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M, _rt_error_message);
          return;
        }
      }

      if ((QD2_DroneStack_PID_2021a_P.HILInitialize_EIStart && !is_switching) ||
          (QD2_DroneStack_PID_2021a_P.HILInitialize_EIEnter && is_switching)) {
        QD2_DroneStack_PID_2021a_DW.HILInitialize_InitialEICounts[0] =
          QD2_DroneStack_PID_2021a_P.HILInitialize_EIInitial;
        QD2_DroneStack_PID_2021a_DW.HILInitialize_InitialEICounts[1] =
          QD2_DroneStack_PID_2021a_P.HILInitialize_EIInitial;
        result = hil_set_encoder_counts
          (QD2_DroneStack_PID_2021a_DW.HILInitialize_Card,
           QD2_DroneStack_PID_2021a_P.HILInitialize_EIChannels, 2U,
           &QD2_DroneStack_PID_2021a_DW.HILInitialize_InitialEICounts[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M, _rt_error_message);
          return;
        }
      }

      if ((QD2_DroneStack_PID_2021a_P.HILInitialize_POPStart && !is_switching) ||
          (QD2_DroneStack_PID_2021a_P.HILInitialize_POPEnter && is_switching)) {
        uint32_T num_duty_cycle_modes = 0;
        uint32_T num_frequency_modes = 0;
        QD2_DroneStack_PID_2021a_DW.HILInitialize_POModeValues[0] =
          (QD2_DroneStack_PID_2021a_P.HILInitialize_POModes[0]);
        QD2_DroneStack_PID_2021a_DW.HILInitialize_POModeValues[1] =
          (QD2_DroneStack_PID_2021a_P.HILInitialize_POModes[1]);
        QD2_DroneStack_PID_2021a_DW.HILInitialize_POModeValues[2] =
          (QD2_DroneStack_PID_2021a_P.HILInitialize_POModes[2]);
        QD2_DroneStack_PID_2021a_DW.HILInitialize_POModeValues[3] =
          (QD2_DroneStack_PID_2021a_P.HILInitialize_POModes[3]);
        QD2_DroneStack_PID_2021a_DW.HILInitialize_POModeValues[4] =
          (QD2_DroneStack_PID_2021a_P.HILInitialize_POModes[4]);
        QD2_DroneStack_PID_2021a_DW.HILInitialize_POModeValues[5] =
          (QD2_DroneStack_PID_2021a_P.HILInitialize_POModes[4]);
        result = hil_set_pwm_mode(QD2_DroneStack_PID_2021a_DW.HILInitialize_Card,
          QD2_DroneStack_PID_2021a_P.HILInitialize_POChannels, 6U, (t_pwm_mode *)
          &QD2_DroneStack_PID_2021a_DW.HILInitialize_POModeValues[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M, _rt_error_message);
          return;
        }

        {
          int_T i1;
          const uint32_T *p_HILInitialize_POChannels =
            QD2_DroneStack_PID_2021a_P.HILInitialize_POChannels;
          int32_T *dw_POModeValues =
            &QD2_DroneStack_PID_2021a_DW.HILInitialize_POModeValues[0];
          for (i1=0; i1 < 6; i1++) {
            if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1]
                == PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE ||
                dw_POModeValues[i1] == PWM_RAW_MODE) {
              QD2_DroneStack_PID_2021a_DW.HILInitialize_POSortedChans[num_duty_cycle_modes]
                = (p_HILInitialize_POChannels[i1]);
              QD2_DroneStack_PID_2021a_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]
                = QD2_DroneStack_PID_2021a_P.HILInitialize_POFrequency;
              num_duty_cycle_modes++;
            } else {
              QD2_DroneStack_PID_2021a_DW.HILInitialize_POSortedChans[5U -
                num_frequency_modes] = (p_HILInitialize_POChannels[i1]);
              QD2_DroneStack_PID_2021a_DW.HILInitialize_POSortedFreqs[5U -
                num_frequency_modes] =
                QD2_DroneStack_PID_2021a_P.HILInitialize_POFrequency;
              num_frequency_modes++;
            }
          }
        }

        if (num_duty_cycle_modes > 0) {
          result = hil_set_pwm_frequency
            (QD2_DroneStack_PID_2021a_DW.HILInitialize_Card,
             &QD2_DroneStack_PID_2021a_DW.HILInitialize_POSortedChans[0],
             num_duty_cycle_modes,
             &QD2_DroneStack_PID_2021a_DW.HILInitialize_POSortedFreqs[0]);
          if (result < 0) {
            msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
              (_rt_error_message));
            rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M, _rt_error_message);
            return;
          }
        }

        if (num_frequency_modes > 0) {
          result = hil_set_pwm_duty_cycle
            (QD2_DroneStack_PID_2021a_DW.HILInitialize_Card,
             &QD2_DroneStack_PID_2021a_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
             num_frequency_modes,
             &QD2_DroneStack_PID_2021a_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
          if (result < 0) {
            msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
              (_rt_error_message));
            rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M, _rt_error_message);
            return;
          }
        }

        {
          int_T i1;
          int32_T *dw_POModeValues =
            &QD2_DroneStack_PID_2021a_DW.HILInitialize_POModeValues[0];
          for (i1=0; i1 < 6; i1++) {
            dw_POModeValues[i1] =
              QD2_DroneStack_PID_2021a_P.HILInitialize_POConfiguration;
          }
        }

        {
          int_T i1;
          int32_T *dw_POAlignValues =
            &QD2_DroneStack_PID_2021a_DW.HILInitialize_POAlignValues[0];
          for (i1=0; i1 < 6; i1++) {
            dw_POAlignValues[i1] =
              QD2_DroneStack_PID_2021a_P.HILInitialize_POAlignment;
          }
        }

        {
          int_T i1;
          int32_T *dw_POPolarityVals =
            &QD2_DroneStack_PID_2021a_DW.HILInitialize_POPolarityVals[0];
          for (i1=0; i1 < 6; i1++) {
            dw_POPolarityVals[i1] =
              QD2_DroneStack_PID_2021a_P.HILInitialize_POPolarity;
          }
        }

        result = hil_set_pwm_configuration
          (QD2_DroneStack_PID_2021a_DW.HILInitialize_Card,
           QD2_DroneStack_PID_2021a_P.HILInitialize_POChannels, 6U,
           (t_pwm_configuration *)
           &QD2_DroneStack_PID_2021a_DW.HILInitialize_POModeValues[0],
           (t_pwm_alignment *)
           &QD2_DroneStack_PID_2021a_DW.HILInitialize_POAlignValues[0],
           (t_pwm_polarity *)
           &QD2_DroneStack_PID_2021a_DW.HILInitialize_POPolarityVals[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M, _rt_error_message);
          return;
        }
      }

      if ((QD2_DroneStack_PID_2021a_P.HILInitialize_POStart && !is_switching) ||
          (QD2_DroneStack_PID_2021a_P.HILInitialize_POEnter && is_switching)) {
        {
          int_T i1;
          real_T *dw_POValues =
            &QD2_DroneStack_PID_2021a_DW.HILInitialize_POValues[0];
          for (i1=0; i1 < 6; i1++) {
            dw_POValues[i1] = QD2_DroneStack_PID_2021a_P.HILInitialize_POInitial;
          }
        }

        result = hil_write_pwm(QD2_DroneStack_PID_2021a_DW.HILInitialize_Card,
          QD2_DroneStack_PID_2021a_P.HILInitialize_POChannels, 6U,
          &QD2_DroneStack_PID_2021a_DW.HILInitialize_POValues[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M, _rt_error_message);
          return;
        }
      }

      if (QD2_DroneStack_PID_2021a_P.HILInitialize_POReset) {
        {
          int_T i1;
          real_T *dw_POValues =
            &QD2_DroneStack_PID_2021a_DW.HILInitialize_POValues[0];
          for (i1=0; i1 < 6; i1++) {
            dw_POValues[i1] =
              QD2_DroneStack_PID_2021a_P.HILInitialize_POWatchdog;
          }
        }

        result = hil_watchdog_set_pwm_expiration_state
          (QD2_DroneStack_PID_2021a_DW.HILInitialize_Card,
           QD2_DroneStack_PID_2021a_P.HILInitialize_POChannels, 6U,
           &QD2_DroneStack_PID_2021a_DW.HILInitialize_POValues[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M, _rt_error_message);
          return;
        }
      }
    }

    /* Start for S-Function (stream_client_block): '<S2>/Stream Client' incorporates:
     *  Constant: '<S2>/Constant'
     */

    /* S-Function Block: QD2_DroneStack_PID_2021a/Communication/Stream Client (stream_client_block) */
    {
      QD2_DroneStack_PID_2021a_DW.StreamClient_Stream = NULL;

      {
        int_T i1;
        real_T *y3 = &QD2_DroneStack_PID_2021a_B.StreamClient_o4[0];
        const real_T *p_StreamClient_default_value =
          QD2_DroneStack_PID_2021a_P.StreamClient_default_value;
        for (i1=0; i1 < 16; i1++) {
          y3[i1] = p_StreamClient_default_value[i1];
        }
      }

      QD2_DroneStack_PID_2021a_DW.StreamClient_Connected = false;
    }

    /* Start for S-Function (continuous_sigmoid_block): '<S13>/Continuous Sigmoid' */

    /* S-Function Block: QD2_DroneStack_PID_2021a/COMMANDER (ANGLE MODE)/THROTTLE SWITCHBOX /Continuous Sigmoid (continuous_sigmoid_block) */
    {
      real_T* params;
      params = &QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Sigmoid[0 *
        NUMBER_OF_SIGMOID_PARAMETERS];
      params[SIGMOID_PARAMETER_T1] = 0;
      params[SIGMOID_PARAMETER_T2] = 0;
      params[SIGMOID_PARAMETER_T3] = 0;
      params[SIGMOID_PARAMETER_X0] =
        QD2_DroneStack_PID_2021a_P.ContinuousSigmoid_XI;
      params[SIGMOID_PARAMETER_X1] =
        QD2_DroneStack_PID_2021a_P.ContinuousSigmoid_XI;
      params[SIGMOID_PARAMETER_X2] =
        QD2_DroneStack_PID_2021a_P.ContinuousSigmoid_XI;
      params[SIGMOID_PARAMETER_XD] =
        QD2_DroneStack_PID_2021a_P.ContinuousSigmoid_XI;
      params[SIGMOID_PARAMETER_V0] =
        QD2_DroneStack_PID_2021a_P.ContinuousSigmoid_VI;
      params[SIGMOID_PARAMETER_VP] = 0;
      params[SIGMOID_PARAMETER_AP] = 0;
      params[SIGMOID_PARAMETER_HOLD_OFF] =
        QD2_DroneStack_PID_2021a_P.ContinuousSigmoid_Hold;
      QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Time = 0;
      QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Target =
        QD2_DroneStack_PID_2021a_P.ContinuousSigmoid_XI;
      QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_PPos =
        QD2_DroneStack_PID_2021a_P.ContinuousSigmoid_XI;
      QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_PVel =
        QD2_DroneStack_PID_2021a_P.ContinuousSigmoid_VI;
      QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Flag = 0;
      QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_MVel = 0;
      QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_MAcc = 0;
    }

    /* Start for S-Function (continuous_sigmoid_block): '<S51>/Continuous Sigmoid' */

    /* S-Function Block: QD2_DroneStack_PID_2021a/HORIZON FRAME CONVERSION AND ESTIMATION/Pose Switchbox/Continuous Sigmoid (continuous_sigmoid_block) */
    {
      real_T* params;
      params = &QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Sigmoid_l[0 *
        NUMBER_OF_SIGMOID_PARAMETERS];
      params[SIGMOID_PARAMETER_T1] = 0;
      params[SIGMOID_PARAMETER_T2] = 0;
      params[SIGMOID_PARAMETER_T3] = 0;
      params[SIGMOID_PARAMETER_X0] =
        QD2_DroneStack_PID_2021a_P.ContinuousSigmoid_XI_a;
      params[SIGMOID_PARAMETER_X1] =
        QD2_DroneStack_PID_2021a_P.ContinuousSigmoid_XI_a;
      params[SIGMOID_PARAMETER_X2] =
        QD2_DroneStack_PID_2021a_P.ContinuousSigmoid_XI_a;
      params[SIGMOID_PARAMETER_XD] =
        QD2_DroneStack_PID_2021a_P.ContinuousSigmoid_XI_a;
      params[SIGMOID_PARAMETER_V0] =
        QD2_DroneStack_PID_2021a_P.ContinuousSigmoid_VI_n;
      params[SIGMOID_PARAMETER_VP] = 0;
      params[SIGMOID_PARAMETER_AP] = 0;
      params[SIGMOID_PARAMETER_HOLD_OFF] =
        QD2_DroneStack_PID_2021a_P.ContinuousSigmoid_Hold_d;
      QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Time_c = 0;
      QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Target_d =
        QD2_DroneStack_PID_2021a_P.ContinuousSigmoid_XI_a;
      QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_PPos_a =
        QD2_DroneStack_PID_2021a_P.ContinuousSigmoid_XI_a;
      QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_PVel_p =
        QD2_DroneStack_PID_2021a_P.ContinuousSigmoid_VI_n;
      QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_Flag_h = 0;
      QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_MVel_l = 0;
      QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid_MAcc_p = 0;
    }

    /* Start for S-Function (continuous_sigmoid_block): '<S51>/Continuous Sigmoid1' */

    /* S-Function Block: QD2_DroneStack_PID_2021a/HORIZON FRAME CONVERSION AND ESTIMATION/Pose Switchbox/Continuous Sigmoid1 (continuous_sigmoid_block) */
    {
      real_T* params;
      params = &QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_Sigmoid[0 *
        NUMBER_OF_SIGMOID_PARAMETERS];
      params[SIGMOID_PARAMETER_T1] = 0;
      params[SIGMOID_PARAMETER_T2] = 0;
      params[SIGMOID_PARAMETER_T3] = 0;
      params[SIGMOID_PARAMETER_X0] =
        QD2_DroneStack_PID_2021a_P.ContinuousSigmoid1_XI;
      params[SIGMOID_PARAMETER_X1] =
        QD2_DroneStack_PID_2021a_P.ContinuousSigmoid1_XI;
      params[SIGMOID_PARAMETER_X2] =
        QD2_DroneStack_PID_2021a_P.ContinuousSigmoid1_XI;
      params[SIGMOID_PARAMETER_XD] =
        QD2_DroneStack_PID_2021a_P.ContinuousSigmoid1_XI;
      params[SIGMOID_PARAMETER_V0] =
        QD2_DroneStack_PID_2021a_P.ContinuousSigmoid1_VI;
      params[SIGMOID_PARAMETER_VP] = 0;
      params[SIGMOID_PARAMETER_AP] = 0;
      params[SIGMOID_PARAMETER_HOLD_OFF] =
        QD2_DroneStack_PID_2021a_P.ContinuousSigmoid1_Hold;
      QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_Time = 0;
      QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_Target =
        QD2_DroneStack_PID_2021a_P.ContinuousSigmoid1_XI;
      QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_PPos =
        QD2_DroneStack_PID_2021a_P.ContinuousSigmoid1_XI;
      QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_PVel =
        QD2_DroneStack_PID_2021a_P.ContinuousSigmoid1_VI;
      QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_Flag = 0;
      QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_MVel = 0;
      QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid1_MAcc = 0;
    }

    /* Start for S-Function (continuous_sigmoid_block): '<S51>/Continuous Sigmoid2' */

    /* S-Function Block: QD2_DroneStack_PID_2021a/HORIZON FRAME CONVERSION AND ESTIMATION/Pose Switchbox/Continuous Sigmoid2 (continuous_sigmoid_block) */
    {
      real_T* params;
      params = &QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_Sigmoid[0 *
        NUMBER_OF_SIGMOID_PARAMETERS];
      params[SIGMOID_PARAMETER_T1] = 0;
      params[SIGMOID_PARAMETER_T2] = 0;
      params[SIGMOID_PARAMETER_T3] = 0;
      params[SIGMOID_PARAMETER_X0] =
        QD2_DroneStack_PID_2021a_P.ContinuousSigmoid2_XI;
      params[SIGMOID_PARAMETER_X1] =
        QD2_DroneStack_PID_2021a_P.ContinuousSigmoid2_XI;
      params[SIGMOID_PARAMETER_X2] =
        QD2_DroneStack_PID_2021a_P.ContinuousSigmoid2_XI;
      params[SIGMOID_PARAMETER_XD] =
        QD2_DroneStack_PID_2021a_P.ContinuousSigmoid2_XI;
      params[SIGMOID_PARAMETER_V0] =
        QD2_DroneStack_PID_2021a_P.ContinuousSigmoid2_VI;
      params[SIGMOID_PARAMETER_VP] = 0;
      params[SIGMOID_PARAMETER_AP] = 0;
      params[SIGMOID_PARAMETER_HOLD_OFF] =
        QD2_DroneStack_PID_2021a_P.ContinuousSigmoid2_Hold;
      QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_Time = 0;
      QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_Target =
        QD2_DroneStack_PID_2021a_P.ContinuousSigmoid2_XI;
      QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_PPos =
        QD2_DroneStack_PID_2021a_P.ContinuousSigmoid2_XI;
      QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_PVel =
        QD2_DroneStack_PID_2021a_P.ContinuousSigmoid2_VI;
      QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_Flag = 0;
      QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_MVel = 0;
      QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid2_MAcc = 0;
    }

    /* Start for S-Function (continuous_sigmoid_block): '<S51>/Continuous Sigmoid3' */

    /* S-Function Block: QD2_DroneStack_PID_2021a/HORIZON FRAME CONVERSION AND ESTIMATION/Pose Switchbox/Continuous Sigmoid3 (continuous_sigmoid_block) */
    {
      real_T* params;
      params = &QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_Sigmoid[0 *
        NUMBER_OF_SIGMOID_PARAMETERS];
      params[SIGMOID_PARAMETER_T1] = 0;
      params[SIGMOID_PARAMETER_T2] = 0;
      params[SIGMOID_PARAMETER_T3] = 0;
      params[SIGMOID_PARAMETER_X0] =
        QD2_DroneStack_PID_2021a_P.ContinuousSigmoid3_XI;
      params[SIGMOID_PARAMETER_X1] =
        QD2_DroneStack_PID_2021a_P.ContinuousSigmoid3_XI;
      params[SIGMOID_PARAMETER_X2] =
        QD2_DroneStack_PID_2021a_P.ContinuousSigmoid3_XI;
      params[SIGMOID_PARAMETER_XD] =
        QD2_DroneStack_PID_2021a_P.ContinuousSigmoid3_XI;
      params[SIGMOID_PARAMETER_V0] =
        QD2_DroneStack_PID_2021a_P.ContinuousSigmoid3_VI;
      params[SIGMOID_PARAMETER_VP] = 0;
      params[SIGMOID_PARAMETER_AP] = 0;
      params[SIGMOID_PARAMETER_HOLD_OFF] =
        QD2_DroneStack_PID_2021a_P.ContinuousSigmoid3_Hold;
      QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_Time = 0;
      QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_Target =
        QD2_DroneStack_PID_2021a_P.ContinuousSigmoid3_XI;
      QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_PPos =
        QD2_DroneStack_PID_2021a_P.ContinuousSigmoid3_XI;
      QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_PVel =
        QD2_DroneStack_PID_2021a_P.ContinuousSigmoid3_VI;
      QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_Flag = 0;
      QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_MVel = 0;
      QD2_DroneStack_PID_2021a_DW.ContinuousSigmoid3_MAcc = 0;
    }

    /* Start for Iterator SubSystem: '<S63>/For Each Subsystem - Iterate over IMU0 and IMU1' */
    for (ForEach_itr_a = 0; ForEach_itr_a < 2; ForEach_itr_a++) {
      /* Start for Gain: '<S82>/Gain1' */
      QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Gain1[0] = 0.0;
      QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Gain1[1] = 0.0;

      /* Start for Integrator: '<S84>/Integrator1' */
      QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Integrator1[0] =
        0.0;

      /* Start for Product: '<S84>/Product1' */
      QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Product1[0] = 0.0;

      /* Start for Product: '<S84>/Product' */
      QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Product[0] = 0.0;

      /* Start for Product: '<S85>/Product' */
      QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Product_i[0] = 0.0;

      /* Start for Product: '<S85>/Product1' */
      QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Product1_i[0] =
        0.0;

      /* Start for Integrator: '<S84>/Integrator1' */
      QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Integrator1[1] =
        0.0;

      /* Start for Product: '<S84>/Product1' */
      QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Product1[1] = 0.0;

      /* Start for Product: '<S84>/Product' */
      QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Product[1] = 0.0;

      /* Start for Product: '<S85>/Product' */
      QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Product_i[1] = 0.0;

      /* Start for Product: '<S85>/Product1' */
      QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Product1_i[1] =
        0.0;

      /* Start for Integrator: '<S84>/Integrator1' */
      QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Integrator1[2] =
        0.0;

      /* Start for Product: '<S84>/Product1' */
      QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Product1[2] = 0.0;

      /* Start for Product: '<S84>/Product' */
      QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Product[2] = 0.0;

      /* Start for Product: '<S85>/Product' */
      QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Product_i[2] = 0.0;

      /* Start for Product: '<S85>/Product1' */
      QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Product1_i[2] =
        0.0;

      /* Start for Sum: '<S82>/Sum1' */
      QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Sum1[0] = 0.0;
      QD2_DroneStack_PID_2021a_B.CoreSubsys_pn[ForEach_itr_a].Sum1[1] = 0.0;
    }

    /* End of Start for SubSystem: '<S63>/For Each Subsystem - Iterate over IMU0 and IMU1' */

    /* Start for RateTransition: '<S5>/Rate Transition7' */
    QD2_DroneStack_PID_2021a_B.RateTransition7[0] =
      QD2_DroneStack_PID_2021a_P.RateTransition7_InitialConditio;
    QD2_DroneStack_PID_2021a_B.RateTransition7[1] =
      QD2_DroneStack_PID_2021a_P.RateTransition7_InitialConditio;

    /* Start for RateTransition: '<S5>/Rate Transition2' */
    QD2_DroneStack_PID_2021a_B.RateTransition2 =
      QD2_DroneStack_PID_2021a_P.RateTransition2_InitialConditio;

    /* Start for RateTransition: '<S5>/Rate Transition1' */
    QD2_DroneStack_PID_2021a_B.RateTransition1 =
      QD2_DroneStack_PID_2021a_P.RateTransition1_InitialConditio;

    /* Start for S-Function (sample_time_block): '<S81>/Sample Time' */

    /* S-Function Block: QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Timing Monitors/Sample Time (sample_time_block) */
    {
      t_error result;
      result = timeout_get_high_resolution_time
        (&QD2_DroneStack_PID_2021a_DW.SampleTime_PreviousTime);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M, _rt_error_message);
        return;
      }
    }

    /* Start for RateTransition: '<S81>/Rate Transition' */
    QD2_DroneStack_PID_2021a_B.RateTransition =
      QD2_DroneStack_PID_2021a_P.RateTransition_InitialCondition;

    /* Start for RateTransition: '<S81>/Rate Transition1' */
    QD2_DroneStack_PID_2021a_B.RateTransition1_n =
      QD2_DroneStack_PID_2021a_P.RateTransition1_InitialCondit_o;

    /* Start for RateTransition: '<S81>/Rate Transition2' */
    QD2_DroneStack_PID_2021a_B.RateTransition2_m =
      QD2_DroneStack_PID_2021a_P.RateTransition2_InitialCondit_l;

    /* Start for RateTransition: '<S81>/Rate Transition3' */
    QD2_DroneStack_PID_2021a_B.RateTransition3 =
      QD2_DroneStack_PID_2021a_P.RateTransition3_InitialConditio;
    QD2_DroneStack_P_emxInit_real_T(&QD2_DroneStack_PID_2021a_DW.buffer, 2);

    /* Start for Iterator SubSystem: '<S16>/Boolean Edge-Based Triggered Print' */
    for (ForEach_itr_b = 0; ForEach_itr_b < 3; ForEach_itr_b++) {
      /* Start for Triggered SubSystem: '<S25>/Triggered Subsystem1' */
      QD2_DroneStack_PID_2021_PrevZCX.CoreSubsys[ForEach_itr_b].
        TriggeredSubsystem1_Trig_ZCE = ZERO_ZCSIG;

      /* End of Start for SubSystem: '<S25>/Triggered Subsystem1' */
      QD2_DroneStack_PID_2021_PrevZCX.CoreSubsys[ForEach_itr_b].
        TriggeredSubsystem1_Trig_ZCE = ZERO_ZCSIG;
    }

    /* End of Start for SubSystem: '<S16>/Boolean Edge-Based Triggered Print' */

    /* Start for Iterator SubSystem: '<S18>/Boolean Value-Based Triggered Print' */
    for (ForEach_itr_h = 0; ForEach_itr_h < 9; ForEach_itr_h++) {
      /* Start for Triggered SubSystem: '<S29>/Triggered Subsystem' */
      QD2_DroneStack_PID_2021_PrevZCX.CoreSubsys_p[ForEach_itr_h].
        TriggeredSubsystem_Trig_ZCE = POS_ZCSIG;

      /* End of Start for SubSystem: '<S29>/Triggered Subsystem' */
      QD2_DroneStack_PID_2021_PrevZCX.CoreSubsys_p[ForEach_itr_h].
        TriggeredSubsystem_Trig_ZCE = POS_ZCSIG;
    }

    /* End of Start for SubSystem: '<S18>/Boolean Value-Based Triggered Print' */

    /* Start for Enabled SubSystem: '<S13>/Use desired height when enabled' */
    Usedesiredheightwhene_Start
      (&QD2_DroneStack_PID_2021a_DW.Usedesiredheightwhenenabled_c);

    /* End of Start for SubSystem: '<S13>/Use desired height when enabled' */

    /* Start for Enabled SubSystem: '<S51>/Use des height  when enabled' */
    Usedesiredheightwhene_Start
      (&QD2_DroneStack_PID_2021a_DW.Usedesheightwhenenabled);

    /* End of Start for SubSystem: '<S51>/Use des height  when enabled' */

    /* Start for Enabled SubSystem: '<S51>/Use des yaw  when enabled' */
    Usedesiredheightwhene_Start
      (&QD2_DroneStack_PID_2021a_DW.Usedesyawwhenenabled);

    /* End of Start for SubSystem: '<S51>/Use des yaw  when enabled' */

    /* Start for Enabled SubSystem: '<S51>/Use desired X  when enabled' */
    Usedesiredheightwhene_Start
      (&QD2_DroneStack_PID_2021a_DW.UsedesiredXwhenenabled);

    /* End of Start for SubSystem: '<S51>/Use desired X  when enabled' */

    /* Start for Enabled SubSystem: '<S51>/Use desired Y  when enabled' */
    Usedesiredheightwhene_Start
      (&QD2_DroneStack_PID_2021a_DW.UsedesiredYwhenenabled);

    /* End of Start for SubSystem: '<S51>/Use desired Y  when enabled' */

    /* Start for S-Function (sample_time_block): '<S110>/Sample Time' */

    /* S-Function Block: QD2_DroneStack_PID_2021a/STABILIZER - QDRONE 2/FLIGHT SAFETY/Sample Time (sample_time_block) */
    {
      t_error result;
      result = timeout_get_high_resolution_time
        (&QD2_DroneStack_PID_2021a_DW.SampleTime_PreviousTime_d);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M, _rt_error_message);
        return;
      }
    }

    /* Start for S-Function (hil_watchdog_block): '<S110>/HIL Watchdog' */

    /* S-Function Block: QD2_DroneStack_PID_2021a/STABILIZER - QDRONE 2/FLIGHT SAFETY/HIL Watchdog (hil_watchdog_block) */
    {
      QD2_DroneStack_PID_2021a_DW.HILWatchdog_IsStarted = false;
    }

    /* Start for S-Function (stream_server_block): '<S5>/Stream Server' */

    /* S-Function Block: QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Stream Server (stream_server_block) */
    {
      qthread_attr_t send_thread_attributes;
      qthread_attr_t receive_thread_attributes;
      struct qsched_param scheduling_parameters;
      int min_priority = qsched_get_priority_min(QSCHED_FIFO);
      int max_priority = qsched_get_priority_max(QSCHED_FIFO);
      t_pstream_options options;
      t_error result;
      QD2_DroneStack_PID_2021a_DW.StreamServer_Stream = NULL;
      QD2_DroneStack_PID_2021a_B.StreamServer_o4 =
        QD2_DroneStack_PID_2021a_P.StreamServer_default_value;
      result = 0;
      options.size = sizeof(options);
      options.flags = QD2_DroneStack_PID_2021a_P.StreamServer_Endian &
        PSTREAM_FLAG_ENDIAN_MASK;
      if (QD2_DroneStack_PID_2021a_P.StreamServer_Implementation ==
          STREAM_SERVER_IMPLEMENTATION_THREAD) {
        options.flags |= PSTREAM_FLAG_MULTITHREADED;
      }

      if (QD2_DroneStack_PID_2021a_P.StreamServer_Optimize ==
          STREAM_SERVER_OPTIMIZE_LATENCY) {
        options.flags |= PSTREAM_FLAG_MINIMIZE_LATENCY;
      }

      options.flags |= PSTREAM_FLAG_SEND_MOST_RECENT;
      options.flags |= PSTREAM_FLAG_RECEIVE_MOST_RECENT;
      options.send_unit_size = 8;
      options.num_send_units = 47;
      options.send_buffer_size = QD2_DroneStack_PID_2021a_P.StreamServer_SndSize;
      options.send_fifo_size = QD2_DroneStack_PID_2021a_P.StreamServer_SndFIFO;
      options.num_send_dimensions = 0;
      options.max_send_dimensions = NULL;
      if (QD2_DroneStack_PID_2021a_P.StreamServer_SndPriority < min_priority) {
        scheduling_parameters.sched_priority = min_priority;
      } else if (QD2_DroneStack_PID_2021a_P.StreamServer_SndPriority >
                 max_priority) {
        scheduling_parameters.sched_priority = max_priority;
      } else {
        scheduling_parameters.sched_priority =
          QD2_DroneStack_PID_2021a_P.StreamServer_SndPriority;
      }

      qthread_attr_init(&send_thread_attributes);
      result = qthread_attr_setschedpolicy(&send_thread_attributes, QSCHED_FIFO);
      if (result == 0) {
        result = qthread_attr_setschedparam(&send_thread_attributes,
          &scheduling_parameters);
        if (result == 0) {
          result = qthread_attr_setinheritsched(&send_thread_attributes,
            QTHREAD_EXPLICIT_SCHED);
          if (result < 0) {
            rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M,
                              "Unable to set scheduling inheritance for Stream Client sending thread");
          }
        } else {
          rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M,
                            "The specified thread priority for the Stream Client sending thread is not valid for this target");
        }
      } else {
        rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M,
                          "Unable to set scheduling policy for Stream Client sending thread");
      }

      options.send_thread_attributes = &send_thread_attributes;
      options.receive_unit_size = 8;
      options.num_receive_units = 1;
      options.receive_buffer_size =
        QD2_DroneStack_PID_2021a_P.StreamServer_RcvSize;
      options.receive_fifo_size =
        QD2_DroneStack_PID_2021a_P.StreamServer_RcvFIFO;
      options.num_receive_dimensions = 0;
      options.max_receive_dimensions = NULL;
      if (QD2_DroneStack_PID_2021a_P.StreamServer_RcvPriority < min_priority) {
        scheduling_parameters.sched_priority = min_priority;
      } else if (QD2_DroneStack_PID_2021a_P.StreamServer_RcvPriority >
                 max_priority) {
        scheduling_parameters.sched_priority = max_priority;
      } else {
        scheduling_parameters.sched_priority =
          QD2_DroneStack_PID_2021a_P.StreamServer_RcvPriority;
      }

      qthread_attr_init(&receive_thread_attributes);
      if (result == 0) {
        result = qthread_attr_setschedpolicy(&receive_thread_attributes,
          QSCHED_FIFO);
        if (result == 0) {
          result = qthread_attr_setschedparam(&receive_thread_attributes,
            &scheduling_parameters);
          if (result == 0) {
            result = qthread_attr_setinheritsched(&receive_thread_attributes,
              QTHREAD_EXPLICIT_SCHED);
            if (result < 0) {
              rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M,
                                "Unable to set scheduling inheritance for Stream Client receiving thread");
            }
          } else {
            rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M,
                              "The specified thread priority for the Stream Client receiving thread is not valid for this target");
          }
        } else {
          rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M,
                            "Unable to set scheduling policy for Stream Client receiving thread");
        }
      }

      options.receive_thread_attributes = &receive_thread_attributes;
      if (result == 0) {
        result = pstream_listen((const char *)
          QD2_DroneStack_PID_2021a_P.StreamServer_URI, &options,
          &QD2_DroneStack_PID_2021a_DW.StreamServer_Stream);
        if (result < 0 && result != -QERR_WOULD_BLOCK) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M, _rt_error_message);
        }
      }

      qthread_attr_destroy(&send_thread_attributes);
      qthread_attr_destroy(&receive_thread_attributes);
    }

    /* Start for Constant: '<S72>/x0' */
    QD2_DroneStack_PID_2021a_B.x0 = QD2_DroneStack_PID_2021a_P.x0_Value;

    /* Start for S-Function (sample_time_block): '<S81>/Sample Time1' */

    /* S-Function Block: QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Timing Monitors/Sample Time1 (sample_time_block) */
    {
      t_error result;
      result = timeout_get_high_resolution_time
        (&QD2_DroneStack_PID_2021a_DW.SampleTime1_PreviousTime);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M, _rt_error_message);
        return;
      }
    }

    /* Start for Constant: '<S5>/ToF Filter Initial Condition (m)' */
    QD2_DroneStack_PID_2021a_B.ToFFilterInitialConditionm =
      QD2_DroneStack_PID_2021a_P.ToFFilterInitialConditionm_Valu;

    /* Start for S-Function (ranging_sensor_block): '<S5>/Ranging Sensor' */

    /* S-Function Block: QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Ranging Sensor (ranging_sensor_block) */
    {
      t_error result;
      result = vl53l1x_open("i2c-cpu://localhost:0?address='0x29',baud='400000',memsize='512'",
                            (t_ranging_distance)
                            (QD2_DroneStack_PID_2021a_P.RangingSensor_Range - 1),
                            QD2_DroneStack_PID_2021a_P.RangingSensor_Budget,
                            QD2_DroneStack_PID_2021a_P.RangingSensor_Period,
                            &QD2_DroneStack_PID_2021a_DW.RangingSensor_Sensor);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M, _rt_error_message);
      }
    }

    /* Start for S-Function (sample_time_block): '<S81>/Sample Time2' */

    /* S-Function Block: QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Timing Monitors/Sample Time2 (sample_time_block) */
    {
      t_error result;
      result = timeout_get_high_resolution_time
        (&QD2_DroneStack_PID_2021a_DW.SampleTime2_PreviousTime);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M, _rt_error_message);
        return;
      }
    }

    /* user code (Start function Trailer) */

    /* S-Function Block: QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Time (time_block) */
    {
      t_error result;
      result = timeout_get_high_resolution_time(&_high_resolution_start_time);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M, _rt_error_message);
        return;
      }
    }
  }

  QD2_DroneStack_PID_2021_PrevZCX.Integrator1_Reset_ZCE = UNINITIALIZED_ZCSIG;
  QD2_DroneStack_PID_2021_PrevZCX.Integrator2_Reset_ZCE = UNINITIALIZED_ZCSIG;
  QD2_DroneStack_PID_2021_PrevZCX.Integrator7_Reset_ZCE = UNINITIALIZED_ZCSIG;
  QD2_DroneStack_PID_2021_PrevZCX.TriggeredSubsystem_Trig_ZCE_g = POS_ZCSIG;
  QD2_DroneStack_PID_2021_PrevZCX.LatchEStop_Trig_ZCE = POS_ZCSIG;
  QD2_DroneStack_PID_2021_PrevZCX.TriggeredSubsystemLatchingFlag_ = POS_ZCSIG;

  {
    /* local scratch DWork variables */
    int32_T ForEach_itr_a;
    int32_T i;

    /* InitializeConditions for Memory: '<S2>/Memory' */
    QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput =
      QD2_DroneStack_PID_2021a_P.Memory_InitialCondition;

    /* InitializeConditions for Memory: '<S5>/Memory1' */
    QD2_DroneStack_PID_2021a_DW.Memory1_PreviousInput =
      QD2_DroneStack_PID_2021a_P.Memory1_InitialCondition;

    /* InitializeConditions for Memory: '<S5>/Memory' */
    QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_f =
      QD2_DroneStack_PID_2021a_P.Memory_InitialCondition_c;

    /* InitializeConditions for Memory: '<S1>/Memory' */
    QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_e =
      QD2_DroneStack_PID_2021a_P.Memory_InitialCondition_b;

    /* InitializeConditions for Integrator: '<S3>/Integrator1' */
    QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE =
      QD2_DroneStack_PID_2021a_P.Integrator1_IC;

    /* InitializeConditions for Integrator: '<S1>/Integrator1' */
    QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_f[0] =
      QD2_DroneStack_PID_2021a_P.Integrator1_IC_i;
    QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_f[1] =
      QD2_DroneStack_PID_2021a_P.Integrator1_IC_i;
    QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_f[2] =
      QD2_DroneStack_PID_2021a_P.Integrator1_IC_i;
    QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_f[3] =
      QD2_DroneStack_PID_2021a_P.Integrator1_IC_i;

    /* InitializeConditions for Integrator: '<S3>/Integrator6' */
    QD2_DroneStack_PID_2021a_X.Integrator6_CSTATE[0] =
      QD2_DroneStack_PID_2021a_P.Integrator6_IC;
    QD2_DroneStack_PID_2021a_X.Integrator6_CSTATE[1] =
      QD2_DroneStack_PID_2021a_P.Integrator6_IC;
    QD2_DroneStack_PID_2021a_X.Integrator6_CSTATE[2] =
      QD2_DroneStack_PID_2021a_P.Integrator6_IC;

    /* InitializeConditions for Integrator: '<S39>/Integrator1' */
    if (rtmIsFirstInitCond(QD2_DroneStack_PID_2021a_M)) {
      QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_h[0] = 0.0;
      QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_h[1] = 0.0;
    }

    QD2_DroneStack_PID_2021a_DW.Integrator1_DWORK1 = true;

    /* End of InitializeConditions for Integrator: '<S39>/Integrator1' */

    /* InitializeConditions for RateLimiter: '<S13>/Rate Limiter (N//s)' */
    QD2_DroneStack_PID_2021a_DW.LastMajorTime = (rtInf);

    /* InitializeConditions for Delay: '<S7>/Delay' */
    for (i = 0; i < 100; i++) {
      QD2_DroneStack_PID_2021a_DW.Delay_DSTATE[i] =
        QD2_DroneStack_PID_2021a_P.Delay_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<S7>/Delay' */

    /* InitializeConditions for RateTransition: '<S5>/Rate Transition7' */
    QD2_DroneStack_PID_2021a_DW.RateTransition7_Buffer0[0] =
      QD2_DroneStack_PID_2021a_P.RateTransition7_InitialConditio;
    QD2_DroneStack_PID_2021a_DW.RateTransition7_Buffer0[1] =
      QD2_DroneStack_PID_2021a_P.RateTransition7_InitialConditio;

    /* InitializeConditions for RateTransition: '<S5>/Rate Transition2' */
    QD2_DroneStack_PID_2021a_DW.RateTransition2_Buffer0 =
      QD2_DroneStack_PID_2021a_P.RateTransition2_InitialConditio;

    /* InitializeConditions for RateTransition: '<S5>/Rate Transition1' */
    QD2_DroneStack_PID_2021a_DW.RateTransition1_Buffer0 =
      QD2_DroneStack_PID_2021a_P.RateTransition1_InitialConditio;

    /* InitializeConditions for RateTransition: '<S81>/Rate Transition' */
    QD2_DroneStack_PID_2021a_DW.RateTransition_Buffer0 =
      QD2_DroneStack_PID_2021a_P.RateTransition_InitialCondition;

    /* InitializeConditions for RateTransition: '<S81>/Rate Transition1' */
    QD2_DroneStack_PID_2021a_DW.RateTransition1_Buffer0_m =
      QD2_DroneStack_PID_2021a_P.RateTransition1_InitialCondit_o;

    /* InitializeConditions for RateTransition: '<S81>/Rate Transition2' */
    QD2_DroneStack_PID_2021a_DW.RateTransition2_Buffer0_m =
      QD2_DroneStack_PID_2021a_P.RateTransition2_InitialCondit_l;

    /* InitializeConditions for RateTransition: '<S81>/Rate Transition3' */
    QD2_DroneStack_PID_2021a_DW.RateTransition3_Buffer0 =
      QD2_DroneStack_PID_2021a_P.RateTransition3_InitialConditio;

    /* InitializeConditions for Memory: '<S67>/Memory' */
    QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_a[0] =
      QD2_DroneStack_PID_2021a_P.Memory_InitialCondition_l[0];

    /* InitializeConditions for Memory: '<S69>/Memory' */
    QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_as[0] =
      QD2_DroneStack_PID_2021a_P.Memory_InitialCondition_lk[0];

    /* InitializeConditions for Memory: '<S68>/Memory' */
    QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_n[0] =
      QD2_DroneStack_PID_2021a_P.Memory_InitialCondition_cr[0];

    /* InitializeConditions for Memory: '<S67>/Memory' */
    QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_a[1] =
      QD2_DroneStack_PID_2021a_P.Memory_InitialCondition_l[1];

    /* InitializeConditions for Memory: '<S69>/Memory' */
    QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_as[1] =
      QD2_DroneStack_PID_2021a_P.Memory_InitialCondition_lk[1];

    /* InitializeConditions for Memory: '<S68>/Memory' */
    QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_n[1] =
      QD2_DroneStack_PID_2021a_P.Memory_InitialCondition_cr[1];

    /* InitializeConditions for Memory: '<S67>/Memory' */
    QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_a[2] =
      QD2_DroneStack_PID_2021a_P.Memory_InitialCondition_l[2];

    /* InitializeConditions for Memory: '<S69>/Memory' */
    QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_as[2] =
      QD2_DroneStack_PID_2021a_P.Memory_InitialCondition_lk[2];

    /* InitializeConditions for Memory: '<S68>/Memory' */
    QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_n[2] =
      QD2_DroneStack_PID_2021a_P.Memory_InitialCondition_cr[2];

    /* InitializeConditions for Memory: '<S67>/Memory' */
    QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_a[3] =
      QD2_DroneStack_PID_2021a_P.Memory_InitialCondition_l[3];

    /* InitializeConditions for Memory: '<S69>/Memory' */
    QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_as[3] =
      QD2_DroneStack_PID_2021a_P.Memory_InitialCondition_lk[3];

    /* InitializeConditions for Memory: '<S68>/Memory' */
    QD2_DroneStack_PID_2021a_DW.Memory_PreviousInput_n[3] =
      QD2_DroneStack_PID_2021a_P.Memory_InitialCondition_cr[3];

    /* InitializeConditions for DiscreteIntegrator: '<S96>/Discrete-Time Integrator' */
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE =
      QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC;
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevRese = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S98>/Discrete-Time Integrator' */
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_o =
      QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_b;
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevRe_p = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S99>/Discrete-Time Integrator' */
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_b =
      QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_g;
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevRe_g = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S102>/Discrete-Time Integrator' */
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_d =
      QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_e;
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevRe_o = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S103>/Discrete-Time Integrator' */
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_f =
      QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_n;
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevR_oi = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S104>/Discrete-Time Integrator' */
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_g =
      QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_m;
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevRe_e = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S105>/Discrete-Time Integrator' */
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_n =
      QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_f;
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevRe_n = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S106>/Discrete-Time Integrator' */
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_p =
      QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_h;
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevR_p5 = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S107>/Discrete-Time Integrator' */
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_j =
      QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_c;
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevRe_d = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S108>/Discrete-Time Integrator' */
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_h =
      QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_mg;
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevR_nn = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S109>/Discrete-Time Integrator' */
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTAT_n1 =
      QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_hh;
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevR_eu = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S100>/Discrete-Time Integrator' */
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_c =
      QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_n2;
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevR_gx = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S101>/Discrete-Time Integrator' */
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_a =
      QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_m0;
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevRe_f = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S80>/Discrete-Time Integrator' */
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTAT_bm =
      QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_k;
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevR_oj = 0;

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
    QD2_DroneStack_PID_2021a_DW.UnitDelay_DSTATE =
      QD2_DroneStack_PID_2021a_P.UnitDelay_InitialCondition;

    /* InitializeConditions for DiscreteIntegrator: '<S21>/Discrete-Time Integrator' */
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTAT_jy =
      QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_nh;
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevR_dp = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S49>/Discrete-Time Integrator' */
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_e =
      QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_fy;
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevRe_l = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S50>/Discrete-Time Integrator' */
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_i =
      QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_gy;
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevR_gh = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S14>/Discrete-Time Integrator' */
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTAT_ja =
      QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_l;
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevRe_a = 0;

    /* InitializeConditions for UnitDelay: '<S27>/Delay Input1' */
    QD2_DroneStack_PID_2021a_DW.DelayInput1_DSTATE =
      QD2_DroneStack_PID_2021a_P.DetectChange_vinit;

    /* InitializeConditions for Delay: '<S70>/Delay3' */
    QD2_DroneStack_PID_2021a_DW.Delay3_DSTATE[0] =
      QD2_DroneStack_PID_2021a_P.Delay3_InitialCondition;

    /* InitializeConditions for Delay: '<S70>/Delay2' */
    QD2_DroneStack_PID_2021a_DW.Delay2_DSTATE[0] =
      QD2_DroneStack_PID_2021a_P.Delay2_InitialCondition;

    /* InitializeConditions for Delay: '<S70>/Delay1' */
    QD2_DroneStack_PID_2021a_DW.Delay1_DSTATE[0] =
      QD2_DroneStack_PID_2021a_P.Delay1_InitialCondition;

    /* InitializeConditions for Delay: '<S70>/Delay' */
    QD2_DroneStack_PID_2021a_DW.Delay_DSTATE_e[0] =
      QD2_DroneStack_PID_2021a_P.Delay_InitialCondition_g;

    /* InitializeConditions for Integrator: '<S39>/Integrator2' */
    QD2_DroneStack_PID_2021a_X.Integrator2_CSTATE[0] =
      QD2_DroneStack_PID_2021a_P.Integrator2_IC;

    /* InitializeConditions for Delay: '<S70>/Delay3' */
    QD2_DroneStack_PID_2021a_DW.Delay3_DSTATE[1] =
      QD2_DroneStack_PID_2021a_P.Delay3_InitialCondition;

    /* InitializeConditions for Delay: '<S70>/Delay2' */
    QD2_DroneStack_PID_2021a_DW.Delay2_DSTATE[1] =
      QD2_DroneStack_PID_2021a_P.Delay2_InitialCondition;

    /* InitializeConditions for Delay: '<S70>/Delay1' */
    QD2_DroneStack_PID_2021a_DW.Delay1_DSTATE[1] =
      QD2_DroneStack_PID_2021a_P.Delay1_InitialCondition;

    /* InitializeConditions for Delay: '<S70>/Delay' */
    QD2_DroneStack_PID_2021a_DW.Delay_DSTATE_e[1] =
      QD2_DroneStack_PID_2021a_P.Delay_InitialCondition_g;

    /* InitializeConditions for Integrator: '<S39>/Integrator2' */
    QD2_DroneStack_PID_2021a_X.Integrator2_CSTATE[1] =
      QD2_DroneStack_PID_2021a_P.Integrator2_IC;

    /* InitializeConditions for Integrator: '<S3>/Integrator2' */
    QD2_DroneStack_PID_2021a_X.Integrator2_CSTATE_o =
      QD2_DroneStack_PID_2021a_P.Integrator2_IC_g;

    /* InitializeConditions for Integrator: '<S3>/Integrator7' */
    QD2_DroneStack_PID_2021a_X.Integrator7_CSTATE[0] =
      QD2_DroneStack_PID_2021a_P.Integrator7_IC;

    /* InitializeConditions for Integrator: '<S52>/Integrator2' */
    QD2_DroneStack_PID_2021a_X.Integrator2_CSTATE_c[0] =
      QD2_DroneStack_PID_2021a_P.Integrator2_IC_gq;

    /* InitializeConditions for Integrator: '<S3>/Integrator7' */
    QD2_DroneStack_PID_2021a_X.Integrator7_CSTATE[1] =
      QD2_DroneStack_PID_2021a_P.Integrator7_IC;

    /* InitializeConditions for Integrator: '<S52>/Integrator2' */
    QD2_DroneStack_PID_2021a_X.Integrator2_CSTATE_c[1] =
      QD2_DroneStack_PID_2021a_P.Integrator2_IC_gq;

    /* InitializeConditions for Integrator: '<S3>/Integrator7' */
    QD2_DroneStack_PID_2021a_X.Integrator7_CSTATE[2] =
      QD2_DroneStack_PID_2021a_P.Integrator7_IC;

    /* InitializeConditions for Integrator: '<S52>/Integrator2' */
    QD2_DroneStack_PID_2021a_X.Integrator2_CSTATE_c[2] =
      QD2_DroneStack_PID_2021a_P.Integrator2_IC_gq;

    /* InitializeConditions for Integrator: '<S52>/Integrator1' */
    if (rtmIsFirstInitCond(QD2_DroneStack_PID_2021a_M)) {
      QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_j[0] = 0.0;
      QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_j[1] = 0.0;
      QD2_DroneStack_PID_2021a_X.Integrator1_CSTATE_j[2] = 0.0;
    }

    QD2_DroneStack_PID_2021a_DW.Integrator1_DWORK1_p = true;

    /* End of InitializeConditions for Integrator: '<S52>/Integrator1' */

    /* InitializeConditions for DiscreteIntegrator: '<S114>/Discrete-Time Integrator' */
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTATE_k =
      QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_n2p;
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevR_df = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S113>/Discrete-Time Integrator' */
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTAT_fv =
      QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_j;
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_PrevR_az = 0;

    /* InitializeConditions for Memory: '<S5>/Memory2' */
    QD2_DroneStack_PID_2021a_DW.Memory2_PreviousInput =
      QD2_DroneStack_PID_2021a_P.Memory2_InitialCondition;

    /* InitializeConditions for Memory: '<S5>/Memory3' */
    QD2_DroneStack_PID_2021a_DW.Memory3_PreviousInput =
      QD2_DroneStack_PID_2021a_P.Memory3_InitialCondition;

    /* InitializeConditions for DiscreteIntegrator: '<S72>/Discrete-Time Integrator' */
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTAT_a1[0] =
      QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_e4;

    /* InitializeConditions for DiscreteIntegrator: '<S72>/Discrete-Time Integrator1' */
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator1_DSTATE[0] =
      QD2_DroneStack_PID_2021a_B.x0;

    /* InitializeConditions for DiscreteIntegrator: '<S72>/Discrete-Time Integrator' */
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTAT_a1[1] =
      QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_e4;

    /* InitializeConditions for DiscreteIntegrator: '<S72>/Discrete-Time Integrator1' */
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator1_DSTATE[1] =
      QD2_DroneStack_PID_2021a_B.x0;

    /* InitializeConditions for DiscreteIntegrator: '<S71>/Discrete-Time Integrator' */
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator_DSTAT_ax =
      QD2_DroneStack_PID_2021a_P.DiscreteTimeIntegrator_IC_gl;

    /* InitializeConditions for DiscreteIntegrator: '<S71>/Discrete-Time Integrator1' */
    QD2_DroneStack_PID_2021a_DW.DiscreteTimeIntegrator1_DSTAT_l =
      QD2_DroneStack_PID_2021a_B.ToFFilterInitialConditionm;

    /* SystemInitialize for Iterator SubSystem: '<S63>/For Each Subsystem - Iterate over IMU0 and IMU1' */
    for (ForEach_itr_a = 0; ForEach_itr_a < 2; ForEach_itr_a++) {
      /* InitializeConditions for Integrator: '<S85>/Integrator1' incorporates:
       *  Integrator: '<S84>/Integrator1'
       */
      if (rtmIsFirstInitCond(QD2_DroneStack_PID_2021a_M)) {
        QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
          Integrator1_CSTATE_b[0] = 0.0;
        QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
          Integrator1_CSTATE_b[1] = 0.0;
        QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
          Integrator1_CSTATE_b[2] = 0.0;
        QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
          Integrator1_CSTATE_o[0] = 0.0;
        QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
          Integrator1_CSTATE_o[1] = 0.0;
        QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
          Integrator1_CSTATE_o[2] = 0.0;
      }

      QD2_DroneStack_PID_2021a_DW.CoreSubsys_pn[ForEach_itr_a].
        Integrator1_DWORK1 = true;

      /* End of InitializeConditions for Integrator: '<S85>/Integrator1' */

      /* InitializeConditions for Integrator: '<S82>/Integrator1' */
      QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
        Integrator1_CSTATE_n[0] =
        QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.Integrator1_IC;
      QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
        Integrator1_CSTATE_n[1] =
        QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.Integrator1_IC;

      /* InitializeConditions for Integrator: '<S82>/Integrator2' */
      QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
        Integrator2_CSTATE_od =
        QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.Integrator2_IC;

      /* InitializeConditions for Integrator: '<S84>/Integrator1' */
      QD2_DroneStack_PID_2021a_DW.CoreSubsys_pn[ForEach_itr_a].
        Integrator1_DWORK1_n = true;

      /* InitializeConditions for Integrator: '<S84>/Integrator2' */
      QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
        Integrator2_CSTATE_i[0] =
        QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.Integrator2_IC_n;
      QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
        Integrator2_CSTATE_i[1] =
        QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.Integrator2_IC_n;
      QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
        Integrator2_CSTATE_i[2] =
        QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.Integrator2_IC_n;

      /* InitializeConditions for Integrator: '<S82>/Integrator' */
      QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].Integrator_CSTATE
        [0] = QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.Integrator_IC;
      QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].Integrator_CSTATE
        [1] = QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.Integrator_IC;

      /* InitializeConditions for Integrator: '<S85>/Integrator2' */
      QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
        Integrator2_CSTATE_k[0] =
        QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.Integrator2_IC_o;
      QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
        Integrator2_CSTATE_k[1] =
        QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.Integrator2_IC_o;
      QD2_DroneStack_PID_2021a_X.CoreSubsys_pn[ForEach_itr_a].
        Integrator2_CSTATE_k[2] =
        QD2_DroneStack_PID_2021a_P.CoreSubsys_pn.Integrator2_IC_o;

      /* SystemInitialize for MATLAB Function: '<S82>/Roll and Pitch Approximation from Accelerometer data' */
      QD2_DroneStack_PID_2021a_DW.CoreSubsys_pn[ForEach_itr_a].sfEvent =
        QD2_DroneStack_PID_2_CALL_EVENT;
    }

    /* End of SystemInitialize for SubSystem: '<S63>/For Each Subsystem - Iterate over IMU0 and IMU1' */

    /* SystemInitialize for MATLAB Function: '<S64>/MATLAB Function' */
    QD2_DroneStack_PID_2021a_DW.state = 0.0;
    QD2_DroneStack_PID_2021a_DW.state_not_empty = true;
    QD2_DroneStack_PID_2021a_DW.sfEvent_nd = QD2_DroneStack_PID_2_CALL_EVENT;

    /* SystemInitialize for MATLAB Function: '<S70>/MATLAB Function' */
    QD2_DroneStack_PID_2021a_DW.buffer_not_empty = false;
    QD2_DroneStack_PID_2021a_DW.idx = 1.0;
    QD2_DroneStack_PID_2021a_DW.idx_not_empty = true;
    QD2_DroneStack_PID_2021a_DW.sfEvent_c = QD2_DroneStack_PID_2_CALL_EVENT;

    /* SystemInitialize for MATLAB Function: '<S5>/Force to percentage Mapping' */
    QD2_DroneStack_PID_2021a_DW.sfEvent_n = QD2_DroneStack_PID_2_CALL_EVENT;

    /* SystemInitialize for MATLAB Function: '<S5>/MATLAB Function' */
    QD2_DroneStack_PID_2021a_DW.next_state_after_pause = 99.0;
    QD2_DroneStack_PID_2021a_DW.next_state_after_pause_not_empt = true;
    QD2_DroneStack_PID_2021a_DW.state_counter = 1000.0;
    QD2_DroneStack_PID_2021a_DW.state_counter_not_empty = true;
    QD2_DroneStack_PID_2021a_DW.state_counter_after_pause = 1000.0;
    QD2_DroneStack_PID_2021a_DW.state_counter_after_pause_not_e = true;
    QD2_DroneStack_PID_2021a_DW.esc_timeout_state = 0.0;
    QD2_DroneStack_PID_2021a_DW.esc_timeout_state_not_empty = true;
    QD2_DroneStack_PID_2021a_DW.sfEvent = QD2_DroneStack_PID_2_CALL_EVENT;

    /* SystemInitialize for Triggered SubSystem: '<S77>/Triggered Subsystem - Latching Flag' */
    /* SystemInitialize for SignalConversion generated from: '<S97>/Out1' incorporates:
     *  Outport: '<S97>/Out1'
     */
    QD2_DroneStack_PID_2021a_B.OutportBufferForOut1 =
      QD2_DroneStack_PID_2021a_P.Out1_Y0;

    /* End of SystemInitialize for SubSystem: '<S77>/Triggered Subsystem - Latching Flag' */

    /* SystemInitialize for MATLAB Function: '<S1>/STATE MACHINE LOGIC' */
    QD2_DroneStack_PID_2021a_DW.sfEvent_cx = QD2_DroneStack_PID_2_CALL_EVENT;

    /* SystemInitialize for Triggered SubSystem: '<S10>/Latch E-Stop' */
    /* SystemInitialize for SignalConversion generated from: '<S20>/Input' incorporates:
     *  Outport: '<S20>/Latched Output'
     */
    QD2_DroneStack_PID_2021a_B.Input =
      QD2_DroneStack_PID_2021a_P.LatchedOutput_Y0;

    /* End of SystemInitialize for SubSystem: '<S10>/Latch E-Stop' */

    /* SystemInitialize for MATLAB Function: '<S1>/STATE MACHINE TRANSITION' */
    QD2_DroneStack_PID_2021a_DW.sfEvent_e = QD2_DroneStack_PID_2_CALL_EVENT;

    /* SystemInitialize for MATLAB Function: '<S13>/Hover Throttle Sigmoid Parameters' */
    QD2_DroneStack_PID_2021a_DW.sfEvent_m = QD2_DroneStack_PID_2_CALL_EVENT;

    /* SystemInitialize for MATLAB Function: '<S13>/Throttle Switchbox' */
    QD2_DroneStack_PID_2021a_DW.sfEvent_np = QD2_DroneStack_PID_2_CALL_EVENT;

    /* SystemInitialize for Enabled SubSystem: '<S13>/Use desired height when enabled' */
    Usedesiredheightwhenen_Init
      (&QD2_DroneStack_PID_2021a_B.Usedesiredheightwhenenabled_c,
       &QD2_DroneStack_PID_2021a_P.Usedesiredheightwhenenabled_c);

    /* End of SystemInitialize for SubSystem: '<S13>/Use desired height when enabled' */

    /* SystemInitialize for MATLAB Function: '<S47>/MATLAB Function' */
    QD2_DroneStack_PID_2021a_DW.ms_time_prev = 0.0;
    QD2_DroneStack_PID_2021a_DW.ms_time_prev_not_empty = true;
    QD2_DroneStack_PID_2021a_DW.sfEvent_l = QD2_DroneStack_PID_2_CALL_EVENT;

    /* SystemInitialize for MATLAB Function: '<S51>/MATLAB Function' */
    QD2_DroneStack_PID_2021a_DW.sfEvent_o = QD2_DroneStack_PID_2_CALL_EVENT;

    /* SystemInitialize for MATLAB Function: '<S51>/MATLAB Function1' */
    QD2_DroneStack_PID_2021a_DW.sfEvent_iv = QD2_DroneStack_PID_2_CALL_EVENT;

    /* SystemInitialize for MATLAB Function: '<S51>/MATLAB Function2' */
    QD2_DroneStack_PID_2021a_DW.sfEvent_id = QD2_DroneStack_PID_2_CALL_EVENT;

    /* SystemInitialize for MATLAB Function: '<S51>/MATLAB Function4' */
    QD2_DroneStack_PID_2021a_DW.sfEvent_i = QD2_DroneStack_PID_2_CALL_EVENT;

    /* SystemInitialize for MATLAB Function: '<S51>/Signmoid Type' */
    QD2_DroneStack_PID_2021a_DW.sfEvent_b = QD2_DroneStack_PID_2_CALL_EVENT;

    /* SystemInitialize for Enabled SubSystem: '<S51>/Use des height  when enabled' */
    Usedesiredheightwhenen_Init
      (&QD2_DroneStack_PID_2021a_B.Usedesheightwhenenabled,
       &QD2_DroneStack_PID_2021a_P.Usedesheightwhenenabled);

    /* End of SystemInitialize for SubSystem: '<S51>/Use des height  when enabled' */

    /* SystemInitialize for Enabled SubSystem: '<S51>/Use des yaw  when enabled' */
    Usedesiredheightwhenen_Init(&QD2_DroneStack_PID_2021a_B.Usedesyawwhenenabled,
      &QD2_DroneStack_PID_2021a_P.Usedesyawwhenenabled);

    /* End of SystemInitialize for SubSystem: '<S51>/Use des yaw  when enabled' */

    /* SystemInitialize for Enabled SubSystem: '<S51>/Use desired X  when enabled' */
    Usedesiredheightwhenen_Init
      (&QD2_DroneStack_PID_2021a_B.UsedesiredXwhenenabled,
       &QD2_DroneStack_PID_2021a_P.UsedesiredXwhenenabled);

    /* End of SystemInitialize for SubSystem: '<S51>/Use desired X  when enabled' */

    /* SystemInitialize for Enabled SubSystem: '<S51>/Use desired Y  when enabled' */
    Usedesiredheightwhenen_Init
      (&QD2_DroneStack_PID_2021a_B.UsedesiredYwhenenabled,
       &QD2_DroneStack_PID_2021a_P.UsedesiredYwhenenabled);

    /* End of SystemInitialize for SubSystem: '<S51>/Use desired Y  when enabled' */

    /* set "at time zero" to false */
    if (rtmIsFirstInitCond(QD2_DroneStack_PID_2021a_M)) {
      rtmSetFirstInitCond(QD2_DroneStack_PID_2021a_M, 0);
    }
  }
}

/* Model terminate function */
void QD2_DroneStack_PID_2021a_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S5>/HIL Initialize' */

  /* S-Function Block: QD2_DroneStack_PID_2021a/QDrone 2 DAQ/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(QD2_DroneStack_PID_2021a_DW.HILInitialize_Card);
    hil_monitor_stop_all(QD2_DroneStack_PID_2021a_DW.HILInitialize_Card);
    is_switching = false;

    /* S-Function Block: QD2_DroneStack_PID_2021a/STABILIZER - QDRONE 2/FLIGHT SAFETY/HIL Watchdog (hil_watchdog_block) */
    {
      hil_watchdog_stop(QD2_DroneStack_PID_2021a_DW.HILInitialize_Card);
    }

    if ((QD2_DroneStack_PID_2021a_P.HILInitialize_DOTerminate && !is_switching) ||
        (QD2_DroneStack_PID_2021a_P.HILInitialize_DOExit && is_switching)) {
      {
        int_T i1;
        boolean_T *dw_DOBits =
          &QD2_DroneStack_PID_2021a_DW.HILInitialize_DOBits[0];
        for (i1=0; i1 < 6; i1++) {
          dw_DOBits[i1] = QD2_DroneStack_PID_2021a_P.HILInitialize_DOFinal;
        }
      }

      num_final_digital_outputs = 6U;
    } else {
      num_final_digital_outputs = 0;
    }

    if ((QD2_DroneStack_PID_2021a_P.HILInitialize_POTerminate && !is_switching) ||
        (QD2_DroneStack_PID_2021a_P.HILInitialize_POExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues =
          &QD2_DroneStack_PID_2021a_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 6; i1++) {
          dw_POValues[i1] = QD2_DroneStack_PID_2021a_P.HILInitialize_POFinal;
        }
      }

      num_final_pwm_outputs = 6U;
    } else {
      num_final_pwm_outputs = 0;
    }

    if (0
        || num_final_pwm_outputs > 0
        || num_final_digital_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(QD2_DroneStack_PID_2021a_DW.HILInitialize_Card
                         , NULL, 0
                         , QD2_DroneStack_PID_2021a_P.HILInitialize_POChannels,
                         num_final_pwm_outputs
                         , QD2_DroneStack_PID_2021a_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , NULL, 0
                         , NULL
                         , &QD2_DroneStack_PID_2021a_DW.HILInitialize_POValues[0]
                         , (t_boolean *)
                         &QD2_DroneStack_PID_2021a_DW.HILInitialize_DOBits[0]
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm
            (QD2_DroneStack_PID_2021a_DW.HILInitialize_Card,
             QD2_DroneStack_PID_2021a_P.HILInitialize_POChannels,
             num_final_pwm_outputs,
             &QD2_DroneStack_PID_2021a_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital
            (QD2_DroneStack_PID_2021a_DW.HILInitialize_Card,
             QD2_DroneStack_PID_2021a_P.HILInitialize_DOChannels,
             num_final_digital_outputs, (t_boolean *)
             &QD2_DroneStack_PID_2021a_DW.HILInitialize_DOBits[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(QD2_DroneStack_PID_2021a_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(QD2_DroneStack_PID_2021a_DW.HILInitialize_Card);
    hil_monitor_delete_all(QD2_DroneStack_PID_2021a_DW.HILInitialize_Card);
    hil_close(QD2_DroneStack_PID_2021a_DW.HILInitialize_Card);
    QD2_DroneStack_PID_2021a_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (stream_client_block): '<S2>/Stream Client' incorporates:
   *  Constant: '<S2>/Constant'
   */

  /* S-Function Block: QD2_DroneStack_PID_2021a/Communication/Stream Client (stream_client_block) */
  {
    if (QD2_DroneStack_PID_2021a_DW.StreamClient_Stream != NULL) {
      pstream_close(QD2_DroneStack_PID_2021a_DW.StreamClient_Stream);
    }

    QD2_DroneStack_PID_2021a_DW.StreamClient_Stream = NULL;
  }

  QD2_DroneStack_P_emxFree_real_T(&QD2_DroneStack_PID_2021a_DW.buffer);

  /* Terminate for S-Function (stream_server_block): '<S5>/Stream Server' */

  /* S-Function Block: QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Stream Server (stream_server_block) */
  {
    if (QD2_DroneStack_PID_2021a_DW.StreamServer_Stream != NULL) {
      pstream_close(QD2_DroneStack_PID_2021a_DW.StreamServer_Stream);
    }

    QD2_DroneStack_PID_2021a_DW.StreamServer_Stream = NULL;
  }

  /* Terminate for S-Function (ranging_sensor_block): '<S5>/Ranging Sensor' */

  /* S-Function Block: QD2_DroneStack_PID_2021a/QDrone 2 DAQ/Ranging Sensor (ranging_sensor_block) */
  {
    vl53l1x_close(QD2_DroneStack_PID_2021a_DW.RangingSensor_Sensor);
    QD2_DroneStack_PID_2021a_DW.RangingSensor_Sensor = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  if (tid == 1)
    tid = 0;
  QD2_DroneStack_PID_2021a_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  QD2_DroneStack_PID_2021a_update(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  QD2_DroneStack_PID_2021a_initialize();
}

void MdlTerminate(void)
{
  QD2_DroneStack_PID_2021a_terminate();
}

/* Registration function */
RT_MODEL_QD2_DroneStack_PID_2_T *QD2_DroneStack_PID_2021a(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  QD2_DroneStack_PID_2021a_P.Constant1_Value_j = rtInf;

  /* initialize real-time model */
  (void) memset((void *)QD2_DroneStack_PID_2021a_M, 0,
                sizeof(RT_MODEL_QD2_DroneStack_PID_2_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&QD2_DroneStack_PID_2021a_M->solverInfo,
                          &QD2_DroneStack_PID_2021a_M->Timing.simTimeStep);
    rtsiSetTPtr(&QD2_DroneStack_PID_2021a_M->solverInfo, &rtmGetTPtr
                (QD2_DroneStack_PID_2021a_M));
    rtsiSetStepSizePtr(&QD2_DroneStack_PID_2021a_M->solverInfo,
                       &QD2_DroneStack_PID_2021a_M->Timing.stepSize0);
    rtsiSetdXPtr(&QD2_DroneStack_PID_2021a_M->solverInfo,
                 &QD2_DroneStack_PID_2021a_M->derivs);
    rtsiSetContStatesPtr(&QD2_DroneStack_PID_2021a_M->solverInfo, (real_T **)
                         &QD2_DroneStack_PID_2021a_M->contStates);
    rtsiSetNumContStatesPtr(&QD2_DroneStack_PID_2021a_M->solverInfo,
      &QD2_DroneStack_PID_2021a_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&QD2_DroneStack_PID_2021a_M->solverInfo,
      &QD2_DroneStack_PID_2021a_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&QD2_DroneStack_PID_2021a_M->solverInfo,
      &QD2_DroneStack_PID_2021a_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&QD2_DroneStack_PID_2021a_M->solverInfo,
      &QD2_DroneStack_PID_2021a_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&QD2_DroneStack_PID_2021a_M->solverInfo,
      (boolean_T**) &QD2_DroneStack_PID_2021a_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&QD2_DroneStack_PID_2021a_M->solverInfo,
                          (&rtmGetErrorStatus(QD2_DroneStack_PID_2021a_M)));
    rtsiSetRTModelPtr(&QD2_DroneStack_PID_2021a_M->solverInfo,
                      QD2_DroneStack_PID_2021a_M);
  }

  rtsiSetSimTimeStep(&QD2_DroneStack_PID_2021a_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&QD2_DroneStack_PID_2021a_M->solverInfo,
    false);
  rtsiSetIsContModeFrozen(&QD2_DroneStack_PID_2021a_M->solverInfo, false);
  QD2_DroneStack_PID_2021a_M->intgData.f[0] = QD2_DroneStack_PID_2021a_M->odeF[0];
  QD2_DroneStack_PID_2021a_M->contStates = ((real_T *)
    &QD2_DroneStack_PID_2021a_X);
  QD2_DroneStack_PID_2021a_M->contStateDisabled = ((boolean_T *)
    &QD2_DroneStack_PID_2021a_XDis);
  QD2_DroneStack_PID_2021a_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&QD2_DroneStack_PID_2021a_M->solverInfo, (void *)
                    &QD2_DroneStack_PID_2021a_M->intgData);
  rtsiSetSolverName(&QD2_DroneStack_PID_2021a_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = QD2_DroneStack_PID_2021a_M->Timing.sampleTimeTaskIDArray;
    int_T i;
    for (i = 0; i < 5; i++) {
      mdlTsMap[i] = i;
    }

    QD2_DroneStack_PID_2021a_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    QD2_DroneStack_PID_2021a_M->Timing.sampleTimes =
      (&QD2_DroneStack_PID_2021a_M->Timing.sampleTimesArray[0]);
    QD2_DroneStack_PID_2021a_M->Timing.offsetTimes =
      (&QD2_DroneStack_PID_2021a_M->Timing.offsetTimesArray[0]);

    /* task periods */
    QD2_DroneStack_PID_2021a_M->Timing.sampleTimes[0] = (0.0);
    QD2_DroneStack_PID_2021a_M->Timing.sampleTimes[1] = (0.001);
    QD2_DroneStack_PID_2021a_M->Timing.sampleTimes[2] = (0.002);
    QD2_DroneStack_PID_2021a_M->Timing.sampleTimes[3] = (0.01);
    QD2_DroneStack_PID_2021a_M->Timing.sampleTimes[4] = (0.04);

    /* task offsets */
    QD2_DroneStack_PID_2021a_M->Timing.offsetTimes[0] = (0.0);
    QD2_DroneStack_PID_2021a_M->Timing.offsetTimes[1] = (0.0);
    QD2_DroneStack_PID_2021a_M->Timing.offsetTimes[2] = (0.0);
    QD2_DroneStack_PID_2021a_M->Timing.offsetTimes[3] = (0.0);
    QD2_DroneStack_PID_2021a_M->Timing.offsetTimes[4] = (0.0);
  }

  rtmSetTPtr(QD2_DroneStack_PID_2021a_M,
             &QD2_DroneStack_PID_2021a_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = QD2_DroneStack_PID_2021a_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      QD2_DroneStack_PID_2021a_M->Timing.perTaskSampleHitsArray;
    QD2_DroneStack_PID_2021a_M->Timing.perTaskSampleHits =
      (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    QD2_DroneStack_PID_2021a_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(QD2_DroneStack_PID_2021a_M, -1);
  QD2_DroneStack_PID_2021a_M->Timing.stepSize0 = 0.001;
  QD2_DroneStack_PID_2021a_M->Timing.stepSize1 = 0.001;
  QD2_DroneStack_PID_2021a_M->Timing.stepSize2 = 0.002;
  QD2_DroneStack_PID_2021a_M->Timing.stepSize3 = 0.01;
  QD2_DroneStack_PID_2021a_M->Timing.stepSize4 = 0.04;
  rtmSetFirstInitCond(QD2_DroneStack_PID_2021a_M, 1);

  /* External mode info */
  QD2_DroneStack_PID_2021a_M->Sizes.checksums[0] = (1897080166U);
  QD2_DroneStack_PID_2021a_M->Sizes.checksums[1] = (1053647843U);
  QD2_DroneStack_PID_2021a_M->Sizes.checksums[2] = (1010425266U);
  QD2_DroneStack_PID_2021a_M->Sizes.checksums[3] = (2020173615U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[69];
    QD2_DroneStack_PID_2021a_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)&QD2_DroneStack_PID_2021a_DW.CoreSubsys[2].
      TriggeredSubsystem1_SubsysRanBC;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = (sysRanDType *)
      &QD2_DroneStack_PID_2021a_DW.TriggeredSubsystem_SubsysRanBC;
    systemRan[15] = (sysRanDType *)&QD2_DroneStack_PID_2021a_DW.CoreSubsys_p[8].
      TriggeredSubsystem_SubsysRanBC;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = &rtAlwaysEnabled;
    systemRan[18] = (sysRanDType *)
      &QD2_DroneStack_PID_2021a_DW.LatchEStop_SubsysRanBC;
    systemRan[19] = &rtAlwaysEnabled;
    systemRan[20] = &rtAlwaysEnabled;
    systemRan[21] = &rtAlwaysEnabled;
    systemRan[22] = &rtAlwaysEnabled;
    systemRan[23] = &rtAlwaysEnabled;
    systemRan[24] = (sysRanDType *)
      &QD2_DroneStack_PID_2021a_DW.Usedesiredheightwhenenabled_c.Usedesiredheightwhenenabled_Sub;
    systemRan[25] = &rtAlwaysEnabled;
    systemRan[26] = &rtAlwaysEnabled;
    systemRan[27] = &rtAlwaysEnabled;
    systemRan[28] = &rtAlwaysEnabled;
    systemRan[29] = &rtAlwaysEnabled;
    systemRan[30] = &rtAlwaysEnabled;
    systemRan[31] = (sysRanDType *)
      &QD2_DroneStack_PID_2021a_DW.Usedesheightwhenenabled.Usedesiredheightwhenenabled_Sub;
    systemRan[32] = (sysRanDType *)
      &QD2_DroneStack_PID_2021a_DW.Usedesyawwhenenabled.Usedesiredheightwhenenabled_Sub;
    systemRan[33] = (sysRanDType *)
      &QD2_DroneStack_PID_2021a_DW.UsedesiredXwhenenabled.Usedesiredheightwhenenabled_Sub;
    systemRan[34] = (sysRanDType *)
      &QD2_DroneStack_PID_2021a_DW.UsedesiredYwhenenabled.Usedesiredheightwhenenabled_Sub;
    systemRan[35] = &rtAlwaysEnabled;
    systemRan[36] = &rtAlwaysEnabled;
    systemRan[37] = &rtAlwaysEnabled;
    systemRan[38] = &rtAlwaysEnabled;
    systemRan[39] = &rtAlwaysEnabled;
    systemRan[40] = &rtAlwaysEnabled;
    systemRan[41] = &rtAlwaysEnabled;
    systemRan[42] = &rtAlwaysEnabled;
    systemRan[43] = &rtAlwaysEnabled;
    systemRan[44] = &rtAlwaysEnabled;
    systemRan[45] = &rtAlwaysEnabled;
    systemRan[46] = &rtAlwaysEnabled;
    systemRan[47] = &rtAlwaysEnabled;
    systemRan[48] = (sysRanDType *)
      &QD2_DroneStack_PID_2021a_DW.EnabledSubsystemWriteESCCommand;
    systemRan[49] = &rtAlwaysEnabled;
    systemRan[50] = &rtAlwaysEnabled;
    systemRan[51] = &rtAlwaysEnabled;
    systemRan[52] = &rtAlwaysEnabled;
    systemRan[53] = &rtAlwaysEnabled;
    systemRan[54] = &rtAlwaysEnabled;
    systemRan[55] = &rtAlwaysEnabled;
    systemRan[56] = &rtAlwaysEnabled;
    systemRan[57] = &rtAlwaysEnabled;
    systemRan[58] = &rtAlwaysEnabled;
    systemRan[59] = &rtAlwaysEnabled;
    systemRan[60] = &rtAlwaysEnabled;
    systemRan[61] = (sysRanDType *)
      &QD2_DroneStack_PID_2021a_DW.TriggeredSubsystemLatchingFlag_;
    systemRan[62] = &rtAlwaysEnabled;
    systemRan[63] = &rtAlwaysEnabled;
    systemRan[64] = &rtAlwaysEnabled;
    systemRan[65] = &rtAlwaysEnabled;
    systemRan[66] = &rtAlwaysEnabled;
    systemRan[67] = &rtAlwaysEnabled;
    systemRan[68] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(QD2_DroneStack_PID_2021a_M->extModeInfo,
      &QD2_DroneStack_PID_2021a_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(QD2_DroneStack_PID_2021a_M->extModeInfo,
                        QD2_DroneStack_PID_2021a_M->Sizes.checksums);
    rteiSetTPtr(QD2_DroneStack_PID_2021a_M->extModeInfo, rtmGetTPtr
                (QD2_DroneStack_PID_2021a_M));
  }

  QD2_DroneStack_PID_2021a_M->solverInfoPtr =
    (&QD2_DroneStack_PID_2021a_M->solverInfo);
  QD2_DroneStack_PID_2021a_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&QD2_DroneStack_PID_2021a_M->solverInfo, 0.001);
  rtsiSetSolverMode(&QD2_DroneStack_PID_2021a_M->solverInfo,
                    SOLVER_MODE_MULTITASKING);

  /* block I/O */
  QD2_DroneStack_PID_2021a_M->blockIO = ((void *) &QD2_DroneStack_PID_2021a_B);
  (void) memset(((void *) &QD2_DroneStack_PID_2021a_B), 0,
                sizeof(B_QD2_DroneStack_PID_2021a_T));

  /* parameters */
  QD2_DroneStack_PID_2021a_M->defaultParam = ((real_T *)
    &QD2_DroneStack_PID_2021a_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &QD2_DroneStack_PID_2021a_X;
    QD2_DroneStack_PID_2021a_M->contStates = (x);
    (void) memset((void *)&QD2_DroneStack_PID_2021a_X, 0,
                  sizeof(X_QD2_DroneStack_PID_2021a_T));
  }

  /* disabled states */
  {
    boolean_T *xdis = (boolean_T *) &QD2_DroneStack_PID_2021a_XDis;
    QD2_DroneStack_PID_2021a_M->contStateDisabled = (xdis);
    (void) memset((void *)&QD2_DroneStack_PID_2021a_XDis, 0,
                  sizeof(XDis_QD2_DroneStack_PID_2021a_T));
  }

  /* states (dwork) */
  QD2_DroneStack_PID_2021a_M->dwork = ((void *) &QD2_DroneStack_PID_2021a_DW);
  (void) memset((void *)&QD2_DroneStack_PID_2021a_DW, 0,
                sizeof(DW_QD2_DroneStack_PID_2021a_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    QD2_DroneStack_PID_2021a_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 35;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  QD2_DroneStack_PID_2021a_M->Sizes.numContStates = (56);/* Number of continuous states */
  QD2_DroneStack_PID_2021a_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  QD2_DroneStack_PID_2021a_M->Sizes.numY = (0);/* Number of model outputs */
  QD2_DroneStack_PID_2021a_M->Sizes.numU = (0);/* Number of model inputs */
  QD2_DroneStack_PID_2021a_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  QD2_DroneStack_PID_2021a_M->Sizes.numSampTimes = (5);/* Number of sample times */
  QD2_DroneStack_PID_2021a_M->Sizes.numBlocks = (724);/* Number of blocks */
  QD2_DroneStack_PID_2021a_M->Sizes.numBlockIO = (262);/* Number of block outputs */
  QD2_DroneStack_PID_2021a_M->Sizes.numBlockPrms = (2685);/* Sum of parameter "widths" */
  return QD2_DroneStack_PID_2021a_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
