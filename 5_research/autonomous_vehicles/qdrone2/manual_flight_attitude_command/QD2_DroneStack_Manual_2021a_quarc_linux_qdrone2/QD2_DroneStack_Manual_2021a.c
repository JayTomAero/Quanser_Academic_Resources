/*
 * QD2_DroneStack_Manual_2021a.c
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
#include "rtwtypes.h"
#include "QD2_DroneStack_Manual_2021a_types.h"
#include "QD2_DroneStack_Manual_2021a_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "zero_crossing_types.h"
#include "rt_defines.h"
#include "QD2_DroneStack_Manual_2021a_dt.h"

/* Named constants for MATLAB Function: '<S5>/MATLAB Function' */
#define QD2_DroneStack_Manua_CALL_EVENT (-1)

/* Block signals (default storage) */
B_QD2_DroneStack_Manual_2021a_T QD2_DroneStack_Manual_2021a_B;

/* Continuous states */
X_QD2_DroneStack_Manual_2021a_T QD2_DroneStack_Manual_2021a_X;

/* Disabled State Vector */
XDis_QD2_DroneStack_Manual_20_T QD2_DroneStack_Manual_2021_XDis;

/* Block states (default storage) */
DW_QD2_DroneStack_Manual_2021_T QD2_DroneStack_Manual_2021a_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_QD2_DroneStack_Manual_T QD2_DroneStack_Manual_2_PrevZCX;

/* Real-time model */
static RT_MODEL_QD2_DroneStack_Manua_T QD2_DroneStack_Manual_2021a_M_;
RT_MODEL_QD2_DroneStack_Manua_T *const QD2_DroneStack_Manual_2021a_M =
  &QD2_DroneStack_Manual_2021a_M_;

/* Forward declaration for local functions */
static void QD2_DroneStack_M_emxInit_real_T(emxArray_real_T_QD2_DroneStac_T
  **pEmxArray, int32_T numDimensions);
static void QD2_Dr_emxEnsureCapacity_real_T(emxArray_real_T_QD2_DroneStac_T
  *emxArray, int32_T oldNumel);
static void QD2_DroneStack_M_emxFree_real_T(emxArray_real_T_QD2_DroneStac_T
  **pEmxArray);
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(QD2_DroneStack_Manual_2021a_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(QD2_DroneStack_Manual_2021a_M, 2);
  rtmSampleHitPtr[3] = rtmStepTask(QD2_DroneStack_Manual_2021a_M, 3);
  rtmSampleHitPtr[4] = rtmStepTask(QD2_DroneStack_Manual_2021a_M, 4);
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
  if (QD2_DroneStack_Manual_2021a_M->Timing.TaskCounters.TID[1] == 0) {
    QD2_DroneStack_Manual_2021a_M->Timing.RateInteraction.TID1_2 =
      (QD2_DroneStack_Manual_2021a_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    QD2_DroneStack_Manual_2021a_M->Timing.perTaskSampleHits[7] =
      QD2_DroneStack_Manual_2021a_M->Timing.RateInteraction.TID1_2;
    QD2_DroneStack_Manual_2021a_M->Timing.RateInteraction.TID1_3 =
      (QD2_DroneStack_Manual_2021a_M->Timing.TaskCounters.TID[3] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    QD2_DroneStack_Manual_2021a_M->Timing.perTaskSampleHits[8] =
      QD2_DroneStack_Manual_2021a_M->Timing.RateInteraction.TID1_3;
    QD2_DroneStack_Manual_2021a_M->Timing.RateInteraction.TID1_4 =
      (QD2_DroneStack_Manual_2021a_M->Timing.TaskCounters.TID[4] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    QD2_DroneStack_Manual_2021a_M->Timing.perTaskSampleHits[9] =
      QD2_DroneStack_Manual_2021a_M->Timing.RateInteraction.TID1_4;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (QD2_DroneStack_Manual_2021a_M->Timing.TaskCounters.TID[2])++;
  if ((QD2_DroneStack_Manual_2021a_M->Timing.TaskCounters.TID[2]) > 1) {/* Sample time: [0.004s, 0.0s] */
    QD2_DroneStack_Manual_2021a_M->Timing.TaskCounters.TID[2] = 0;
  }

  (QD2_DroneStack_Manual_2021a_M->Timing.TaskCounters.TID[3])++;
  if ((QD2_DroneStack_Manual_2021a_M->Timing.TaskCounters.TID[3]) > 4) {/* Sample time: [0.01s, 0.0s] */
    QD2_DroneStack_Manual_2021a_M->Timing.TaskCounters.TID[3] = 0;
  }

  (QD2_DroneStack_Manual_2021a_M->Timing.TaskCounters.TID[4])++;
  if ((QD2_DroneStack_Manual_2021a_M->Timing.TaskCounters.TID[4]) > 19) {/* Sample time: [0.04s, 0.0s] */
    QD2_DroneStack_Manual_2021a_M->Timing.TaskCounters.TID[4] = 0;
  }
}

/*
 * This function updates continuous states using the ODE2 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE2_IntgData *id = (ODE2_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T temp;
  int_T i;
  int_T nXc = 34;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  QD2_DroneStack_Manual_2021a_derivatives();

  /* f1 = f(t + h, y + h*f0) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f0[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f1);
  QD2_DroneStack_Manual_2021a_output0();
  QD2_DroneStack_Manual_2021a_derivatives();

  /* tnew = t + h
     ynew = y + (h/2)*(f0 + f1) */
  temp = 0.5*h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + f1[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * Output and update for iterator system:
 *    '<S13>/For Each Subsystem -  Construct ESC Signal'
 *    '<S14>/For Each Subsystem -  Construct ESC Signal'
 *    '<S15>/For Each Subsystem -  Construct ESC Signal'
 */
void ForEachSubsystemConstructES(int32_T NumIters, const real_T rtu_ESCDataIn4[4],
  real_T rtu_ESCChannel, const real_T rtu_ESCPreviousData4[4], real_T
  rty_ESCDataOut4[4])
{
  /* local block i/o variables */
  int32_T rtb_ForEach;

  /* local scratch DWork variables */
  int32_T ForEach_itr;

  /* Outputs for Iterator SubSystem: '<S13>/For Each Subsystem -  Construct ESC Signal' incorporates:
   *  ForEach: '<S33>/For Each'
   */
  for (ForEach_itr = 0; ForEach_itr < NumIters; ForEach_itr++) {
    /* Outputs for Iterator SubSystem: '<S13>/For Each Subsystem -  Construct ESC Signal' incorporates:
     *  ForEach: '<S33>/For Each'
     */
    rtb_ForEach = ForEach_itr;

    /* Switch: '<S33>/Switch' incorporates:
     *  S-Function (compare_block): '<S33>/Compare'
     */
    if ((rtb_ForEach == rtu_ESCChannel)) {
      /* ForEachSliceAssignment generated from: '<S33>/ESC Data Out [4]' incorporates:
       *  ForEachSliceSelector generated from: '<S33>/ESC Data In [4]'
       */
      rty_ESCDataOut4[ForEach_itr] = rtu_ESCDataIn4[ForEach_itr];
    } else {
      /* ForEachSliceAssignment generated from: '<S33>/ESC Data Out [4]' incorporates:
       *  ForEachSliceSelector generated from: '<S33>/ESC Previous Data [4]'
       */
      rty_ESCDataOut4[ForEach_itr] = rtu_ESCPreviousData4[ForEach_itr];
    }

    /* End of Switch: '<S33>/Switch' */
  }

  /* End of Outputs for SubSystem: '<S13>/For Each Subsystem -  Construct ESC Signal' */
}

static void QD2_DroneStack_M_emxInit_real_T(emxArray_real_T_QD2_DroneStac_T
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

static void QD2_DroneStack_M_emxFree_real_T(emxArray_real_T_QD2_DroneStac_T
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
void QD2_DroneStack_Manual_2021a_output0(void) /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_Time;
  real_T rtb_ESCOutput[4];
  real_T rtb_Product[4];
  real_T rtb_Memory_g[4];
  real_T rtb_Product1[4];
  real_T rtb_Memory_f[4];
  real_T rtb_Product2[4];
  real_T rtb_Memory_l[4];
  real_T rtb_ImpSel_InsertedFor_ChannelR;
  real_T rtb_ImpSel_InsertedFor_Channe_e;
  int32_T rtb_StreamClient_o2;
  boolean_T rtb_Compare_c;

  /* local scratch DWork variables */
  int32_T ForEach_itr;
  int32_T ForEach_itr_b;
  real_T rtb_ImpAsg_InsertedFor_BFEstima[18];
  real_T rtb_EulerAnglestoRotationMatrix[9];
  real_T rtb_MultiportSwitch[6];
  real_T Duty_Cycle[4];
  real_T Duty_Cycle_0;
  real_T data_loss;
  real_T rtb_DataTypeConversion3;
  real_T rtb_Sum1_f_idx_0;
  real_T rtb_Sum1_f_idx_1;
  real_T rtb_Sum1_f_idx_2;
  real_T tmp;
  real_T tmp_0;
  real_T tmp_1;
  real_T tmp_2;
  real_T tmp_3;
  int32_T b_k;
  int32_T exitg1;
  int32_T firstBlockLength;
  int32_T hi;
  int32_T lastBlockLength;
  int32_T nblocks;
  int32_T xblockoffset;
  int32_T xoffset;
  uint16_T rtb_DataTypeConversion1[4];
  boolean_T rtb_ImpAsg_InsertedFor_mismatch[4];
  boolean_T rtb_Relation;
  boolean_T rtb_Relation_a;
  boolean_T rtb_Relation_h;
  if (rtmIsMajorTimeStep(QD2_DroneStack_Manual_2021a_M)) {
    /* set solver stop time */
    if (!(QD2_DroneStack_Manual_2021a_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&QD2_DroneStack_Manual_2021a_M->solverInfo,
                            ((QD2_DroneStack_Manual_2021a_M->Timing.clockTickH0
        + 1) * QD2_DroneStack_Manual_2021a_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&QD2_DroneStack_Manual_2021a_M->solverInfo,
                            ((QD2_DroneStack_Manual_2021a_M->Timing.clockTick0 +
        1) * QD2_DroneStack_Manual_2021a_M->Timing.stepSize0 +
        QD2_DroneStack_Manual_2021a_M->Timing.clockTickH0 *
        QD2_DroneStack_Manual_2021a_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(QD2_DroneStack_Manual_2021a_M)) {
    QD2_DroneStack_Manual_2021a_M->Timing.t[0] = rtsiGetT
      (&QD2_DroneStack_Manual_2021a_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(QD2_DroneStack_Manual_2021a_DW.EnabledSubsystemWriteESCCommand);

  /* Reset subsysRan breadcrumbs */
  srClearBC(QD2_DroneStack_Manual_2021a_DW.TriggeredSubsystemLatchingFlag_);

  /* RateTransition: '<S2>/Rate Transition6' */
  rtb_Relation = rtmIsMajorTimeStep(QD2_DroneStack_Manual_2021a_M);
  if (rtb_Relation) {
    /* S-Function (hil_read_block): '<S2>/HIL Read' */

    /* S-Function Block: QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/HIL Read (hil_read_block) */
    {
      t_error result = hil_read
        (QD2_DroneStack_Manual_2021a_DW.HILInitialize_Card,
         QD2_DroneStack_Manual_2021a_P.HILRead_analog_channels, 3U,
         NULL, 0U,
         NULL, 0U,
         QD2_DroneStack_Manual_2021a_P.HILRead_other_channels, 23U,
         &QD2_DroneStack_Manual_2021a_B.HILRead_o1[0],
         NULL,
         NULL,
         &QD2_DroneStack_Manual_2021a_B.HILRead_o2[0]
         );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QD2_DroneStack_Manual_2021a_M, _rt_error_message);
      }
    }

    /* S-Function (time_block): '<S2>/Time' */

    /* S-Function Block: QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Time (time_block) */
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
        rtmSetErrorStatus(QD2_DroneStack_Manual_2021a_M, _rt_error_message);
        return;
      }
    }

    /* Delay: '<S1>/Delay' */
    rtb_DataTypeConversion3 = QD2_DroneStack_Manual_2021a_DW.Delay_DSTATE;

    /* S-Function (stream_client_block): '<S1>/Stream Client' incorporates:
     *  Constant: '<S1>/Constant'
     */

    /* S-Function Block: QD2_DroneStack_Manual_2021a/Communication/Stream Client (stream_client_block) */
    {
      t_pstream_state state;
      t_error send_result;
      t_error receive_result;
      if (!QD2_DroneStack_Manual_2021a_DW.StreamClient_Connected) {
        qthread_attr_t send_thread_attributes;
        qthread_attr_t receive_thread_attributes;
        struct qsched_param scheduling_parameters;
        int min_priority = qsched_get_priority_min(QSCHED_FIFO);
        int max_priority = qsched_get_priority_max(QSCHED_FIFO);
        t_pstream_options options;
        t_error result;
        result = 0;
        options.size = sizeof(options);
        options.flags = QD2_DroneStack_Manual_2021a_P.StreamClient_Endian &
          PSTREAM_FLAG_ENDIAN_MASK;
        if (QD2_DroneStack_Manual_2021a_P.StreamClient_Implementation ==
            STREAM_CLIENT_IMPLEMENTATION_THREAD) {
          options.flags |= PSTREAM_FLAG_MULTITHREADED;
        }

        if (QD2_DroneStack_Manual_2021a_P.StreamClient_Optimize ==
            STREAM_CLIENT_OPTIMIZE_LATENCY) {
          options.flags |= PSTREAM_FLAG_MINIMIZE_LATENCY;
        }

        options.flags |= PSTREAM_FLAG_SEND_MOST_RECENT;
        options.flags |= PSTREAM_FLAG_RECEIVE_MOST_RECENT;
        options.send_unit_size = 8;
        options.num_send_units = 1;
        options.send_buffer_size =
          QD2_DroneStack_Manual_2021a_P.StreamClient_SndSize;
        options.send_fifo_size =
          QD2_DroneStack_Manual_2021a_P.StreamClient_SndFIFO;
        options.num_send_dimensions = 0;
        options.max_send_dimensions = NULL;
        if (QD2_DroneStack_Manual_2021a_P.StreamClient_SndPriority <
            min_priority) {
          scheduling_parameters.sched_priority = min_priority;
        } else if (QD2_DroneStack_Manual_2021a_P.StreamClient_SndPriority >
                   max_priority) {
          scheduling_parameters.sched_priority = max_priority;
        } else {
          scheduling_parameters.sched_priority =
            QD2_DroneStack_Manual_2021a_P.StreamClient_SndPriority;
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
              rtmSetErrorStatus(QD2_DroneStack_Manual_2021a_M,
                                "Unable to set scheduling inheritance for Stream Client sending thread");
            }
          } else {
            rtmSetErrorStatus(QD2_DroneStack_Manual_2021a_M,
                              "The specified thread priority for the Stream Client sending thread is not valid for this target");
          }
        } else {
          rtmSetErrorStatus(QD2_DroneStack_Manual_2021a_M,
                            "Unable to set scheduling policy for Stream Client sending thread");
        }

        options.send_thread_attributes = &send_thread_attributes;
        options.receive_unit_size = 8;
        options.num_receive_units = 11;
        options.receive_buffer_size =
          QD2_DroneStack_Manual_2021a_P.StreamClient_RcvSize;
        options.receive_fifo_size =
          QD2_DroneStack_Manual_2021a_P.StreamClient_RcvFIFO;
        options.num_receive_dimensions = 0;
        options.max_receive_dimensions = NULL;
        if (QD2_DroneStack_Manual_2021a_P.StreamClient_RcvPriority <
            min_priority) {
          scheduling_parameters.sched_priority = min_priority;
        } else if (QD2_DroneStack_Manual_2021a_P.StreamClient_RcvPriority >
                   max_priority) {
          scheduling_parameters.sched_priority = max_priority;
        } else {
          scheduling_parameters.sched_priority =
            QD2_DroneStack_Manual_2021a_P.StreamClient_RcvPriority;
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
                rtmSetErrorStatus(QD2_DroneStack_Manual_2021a_M,
                                  "Unable to set scheduling inheritance for Stream Client receiving thread");
              }
            } else {
              rtmSetErrorStatus(QD2_DroneStack_Manual_2021a_M,
                                "The specified thread priority for the Stream Client receiving thread is not valid for this target");
            }
          } else {
            rtmSetErrorStatus(QD2_DroneStack_Manual_2021a_M,
                              "Unable to set scheduling policy for Stream Client receiving thread");
          }
        }

        options.receive_thread_attributes = &receive_thread_attributes;
        if (result == 0) {
          /* Make sure URI is null-terminated */
          if (string_length((char *)
                            &QD2_DroneStack_Manual_2021a_B.IPAddressofSupervisoryModelMiss
                            [0], 80) == 80) {
            rtmSetErrorStatus(QD2_DroneStack_Manual_2021a_M,
                              "URI passed to Stream Client block is not null-terminated!");
            result = -QERR_STRING_NOT_TERMINATED;
          } else {
            result = pstream_connect((char *)
              &QD2_DroneStack_Manual_2021a_B.IPAddressofSupervisoryModelMiss[0],
              &options, &QD2_DroneStack_Manual_2021a_DW.StreamClient_Stream);
            if (result < 0 && result != -QERR_WOULD_BLOCK) {
              msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
                (_rt_error_message));
              rtmSetErrorStatus(QD2_DroneStack_Manual_2021a_M, _rt_error_message);
            }
          }
        }

        qthread_attr_destroy(&send_thread_attributes);
        qthread_attr_destroy(&receive_thread_attributes);
        QD2_DroneStack_Manual_2021a_DW.StreamClient_Connected = true;
      }

      if (QD2_DroneStack_Manual_2021a_P.Constant_Value_e) {
        send_result = pstream_send
          (QD2_DroneStack_Manual_2021a_DW.StreamClient_Stream,
           &rtb_DataTypeConversion3);
      } else {
        send_result = 0;
      }

      receive_result = pstream_receive
        (QD2_DroneStack_Manual_2021a_DW.StreamClient_Stream,
         &QD2_DroneStack_Manual_2021a_B.StreamClient_o4[0]);
      rtb_StreamClient_o2 = 0;
      if (send_result < 0 && send_result != -QERR_WOULD_BLOCK) {
        rtb_StreamClient_o2 = send_result;
      } else if (receive_result < 0 && receive_result != -QERR_WOULD_BLOCK) {
        rtb_StreamClient_o2 = receive_result;
      }

      pstream_get_state(QD2_DroneStack_Manual_2021a_DW.StreamClient_Stream,
                        &state);
      QD2_DroneStack_Manual_2021a_B.StreamClient_o1 = state;
    }

    /* MATLAB Function: '<S2>/MATLAB Function' incorporates:
     *  Memory: '<S2>/Memory'
     *  Memory: '<S2>/Memory1'
     */
    QD2_DroneStack_Manual_2021a_DW.sfEvent = QD2_DroneStack_Manua_CALL_EVENT;

    /* MATLAB Function 'QDrone 2 DAQ/MATLAB Function': '<S22>:1' */
    /* '<S22>:1:49' */
    /* '<S22>:1:241' */
    /* '<S22>:1:218' */
    /* '<S22>:1:206' */
    /* '<S22>:1:9' */
    rtb_DataTypeConversion3 = 0.0;

    /* '<S22>:1:10' */
    /* '<S22>:1:11' */
    /* '<S22>:1:12' */
    /* '<S22>:1:13' */
    /* '<S22>:1:14' */
    /* '<S22>:1:15' */
    /* '<S22>:1:16' */
    /* '<S22>:1:17' */
    /* '<S22>:1:21' */
    /* '<S22>:1:22' */
    /* '<S22>:1:23' */
    /* '<S22>:1:25' */
    /* '<S22>:1:27' */
    /* '<S22>:1:28' */
    /* '<S22>:1:29' */
    /* '<S22>:1:48' */
    /* '<S22>:1:49' */
    QD2_DroneStack_Manual_2021a_B.cmd[0] = 0.0;
    QD2_DroneStack_Manual_2021a_B.cmd[1] = 0.0;
    QD2_DroneStack_Manual_2021a_B.cmd[2] = 0.0;
    QD2_DroneStack_Manual_2021a_B.cmd[3] = 0.0;

    /* '<S22>:1:50' */
    QD2_DroneStack_Manual_2021a_B.tele_enable = 0.0;

    /* '<S22>:1:51' */
    QD2_DroneStack_Manual_2021a_B.cmd_enable = 0.0;

    /* '<S22>:1:52' */
    /* '<S22>:1:53' */
    QD2_DroneStack_Manual_2021a_B.esc_ready = 0.0;
    if (QD2_DroneStack_Manual_2021a_B.StreamClient_o4[1] != 0.0) {
      /* '<S22>:1:58' */
      rtb_DataTypeConversion3 = 99.0;
    } else {
      switch ((int32_T)QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput) {
       case 0:
        /* '<S22>:1:63' */
        QD2_DroneStack_Manual_2021a_DW.state_counter--;
        if (QD2_DroneStack_Manual_2021a_DW.state_counter <= 0.0) {
          /* '<S22>:1:64' */
          /* '<S22>:1:66' */
          rtb_DataTypeConversion3 = 1.0;

          /* '<S22>:1:67' */
          QD2_DroneStack_Manual_2021a_DW.state_counter = 10000.0;
        } else {
          /* '<S22>:1:70' */
          rtb_DataTypeConversion3 =
            QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput;
        }
        break;

       case 1:
        /* '<S22>:1:76' */
        QD2_DroneStack_Manual_2021a_DW.state_counter--;
        if (QD2_DroneStack_Manual_2021a_DW.state_counter <= 0.0) {
          /* '<S22>:1:77' */
          /* '<S22>:1:80' */
          rtb_DataTypeConversion3 = 99.0;

          /* '<S22>:1:81' */
          QD2_DroneStack_Manual_2021a_DW.esc_timeout_state = 1.0;
        } else if (QD2_DroneStack_Manual_2021a_DW.Memory1_PreviousInput) {
          /* '<S22>:1:85' */
          /* '<S22>:1:87' */
          rtb_DataTypeConversion3 =
            QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput;
        } else {
          /* '<S22>:1:90' */
          rtb_DataTypeConversion3 = 77.0;

          /* '<S22>:1:91' */
          QD2_DroneStack_Manual_2021a_DW.state_counter = 1000.0;

          /* '<S22>:1:92' */
          QD2_DroneStack_Manual_2021a_DW.next_state_after_pause = 3.0;

          /* '<S22>:1:93' */
          QD2_DroneStack_Manual_2021a_DW.state_counter_after_pause = 60.0;
        }
        break;

       case 3:
        /* '<S22>:1:99' */
        QD2_DroneStack_Manual_2021a_DW.state_counter--;
        if (QD2_DroneStack_Manual_2021a_DW.state_counter <= 0.0) {
          /* '<S22>:1:100' */
          /* '<S22>:1:102' */
          rtb_DataTypeConversion3 = 88.0;

          /* '<S22>:1:103' */
          QD2_DroneStack_Manual_2021a_DW.state_counter = 1000.0;

          /* '<S22>:1:104' */
          QD2_DroneStack_Manual_2021a_DW.next_state_after_pause = 4.0;

          /* '<S22>:1:105' */
          QD2_DroneStack_Manual_2021a_DW.state_counter_after_pause = 120.0;
        } else {
          /* '<S22>:1:111' */
          rtb_DataTypeConversion3 =
            QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput;
        }
        break;

       case 4:
        /* '<S22>:1:116' */
        QD2_DroneStack_Manual_2021a_DW.state_counter--;
        if (QD2_DroneStack_Manual_2021a_DW.state_counter <= 0.0) {
          /* '<S22>:1:117' */
          /* '<S22>:1:119' */
          rtb_DataTypeConversion3 = 88.0;

          /* '<S22>:1:120' */
          QD2_DroneStack_Manual_2021a_DW.state_counter = 500.0;

          /* '<S22>:1:121' */
          QD2_DroneStack_Manual_2021a_DW.next_state_after_pause = 2.0;

          /* '<S22>:1:122' */
          QD2_DroneStack_Manual_2021a_DW.state_counter_after_pause = 1000.0;
        } else {
          /* '<S22>:1:125' */
          rtb_DataTypeConversion3 =
            QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput;
        }
        break;

       case 2:
        if (QD2_DroneStack_Manual_2021a_B.StreamClient_o4[9] != 0.0) {
          /* '<S22>:1:132' */
          rtb_DataTypeConversion3 = 5.0;
        } else {
          /* '<S22>:1:135' */
          rtb_DataTypeConversion3 =
            QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput;
        }
        break;

       case 5:
        if (!(QD2_DroneStack_Manual_2021a_B.StreamClient_o4[9] != 0.0)) {
          /* '<S22>:1:142' */
          /* '<S22>:1:144' */
          rtb_DataTypeConversion3 = 2.0;
        } else {
          /* '<S22>:1:147' */
          rtb_DataTypeConversion3 =
            QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput;
        }
        break;

       case 88:
        /* '<S22>:1:157' */
        QD2_DroneStack_Manual_2021a_DW.state_counter--;
        if (QD2_DroneStack_Manual_2021a_DW.state_counter <= 0.0) {
          /* '<S22>:1:158' */
          /* '<S22>:1:160' */
          rtb_DataTypeConversion3 =
            QD2_DroneStack_Manual_2021a_DW.next_state_after_pause;

          /* '<S22>:1:161' */
          QD2_DroneStack_Manual_2021a_DW.state_counter =
            QD2_DroneStack_Manual_2021a_DW.state_counter_after_pause;
        } else {
          /* '<S22>:1:164' */
          rtb_DataTypeConversion3 =
            QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput;
        }
        break;

       case 77:
        /* '<S22>:1:169' */
        QD2_DroneStack_Manual_2021a_DW.state_counter--;
        if (QD2_DroneStack_Manual_2021a_DW.state_counter <= 0.0) {
          /* '<S22>:1:170' */
          /* '<S22>:1:172' */
          rtb_DataTypeConversion3 =
            QD2_DroneStack_Manual_2021a_DW.next_state_after_pause;

          /* '<S22>:1:173' */
          QD2_DroneStack_Manual_2021a_DW.state_counter =
            QD2_DroneStack_Manual_2021a_DW.state_counter_after_pause;
        } else {
          /* '<S22>:1:176' */
          rtb_DataTypeConversion3 =
            QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput;
        }
        break;

       case 99:
        /* '<S22>:1:182' */
        rtb_DataTypeConversion3 =
          QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput;
        break;
      }
    }

    switch ((int32_T)rtb_DataTypeConversion3) {
     case 0:
      /* '<S22>:1:190' */
      QD2_DroneStack_Manual_2021a_B.cmd[0] = 0.0;
      QD2_DroneStack_Manual_2021a_B.cmd[1] = 0.0;
      QD2_DroneStack_Manual_2021a_B.cmd[2] = 0.0;
      QD2_DroneStack_Manual_2021a_B.cmd[3] = 0.0;

      /* '<S22>:1:191' */
      QD2_DroneStack_Manual_2021a_B.tele_enable = 1.0;

      /* '<S22>:1:192' */
      QD2_DroneStack_Manual_2021a_B.cmd_enable = 1.0;

      /* '<S22>:1:193' */
      /* '<S22>:1:194' */
      break;

     case 1:
      /* '<S22>:1:198' */
      QD2_DroneStack_Manual_2021a_B.cmd[0] = 0.0;
      QD2_DroneStack_Manual_2021a_B.cmd[1] = 0.0;
      QD2_DroneStack_Manual_2021a_B.cmd[2] = 0.0;
      QD2_DroneStack_Manual_2021a_B.cmd[3] = 0.0;

      /* '<S22>:1:199' */
      QD2_DroneStack_Manual_2021a_B.tele_enable = 1.0;

      /* '<S22>:1:200' */
      QD2_DroneStack_Manual_2021a_B.cmd_enable = 1.0;

      /* '<S22>:1:201' */
      /* '<S22>:1:202' */
      break;

     case 3:
      /* '<S22>:1:206' */
      QD2_DroneStack_Manual_2021a_B.cmd[0] = 3.0;
      QD2_DroneStack_Manual_2021a_B.cmd[1] = 3.0;
      QD2_DroneStack_Manual_2021a_B.cmd[2] = 3.0;
      QD2_DroneStack_Manual_2021a_B.cmd[3] = 3.0;

      /* '<S22>:1:210' */
      QD2_DroneStack_Manual_2021a_B.tele_enable = 1.0;

      /* '<S22>:1:211' */
      QD2_DroneStack_Manual_2021a_B.cmd_enable = 1.0;

      /* '<S22>:1:212' */
      /* '<S22>:1:213' */
      break;

     case 4:
      /* '<S22>:1:218' */
      QD2_DroneStack_Manual_2021a_B.cmd[0] = 20.0;
      QD2_DroneStack_Manual_2021a_B.cmd[1] = 21.0;
      QD2_DroneStack_Manual_2021a_B.cmd[2] = 21.0;
      QD2_DroneStack_Manual_2021a_B.cmd[3] = 20.0;

      /* '<S22>:1:226' */
      QD2_DroneStack_Manual_2021a_B.tele_enable = 1.0;

      /* '<S22>:1:227' */
      QD2_DroneStack_Manual_2021a_B.cmd_enable = 1.0;

      /* '<S22>:1:228' */
      /* '<S22>:1:229' */
      break;

     case 2:
      /* '<S22>:1:233' */
      QD2_DroneStack_Manual_2021a_B.cmd[0] = 0.0;
      QD2_DroneStack_Manual_2021a_B.cmd[1] = 0.0;
      QD2_DroneStack_Manual_2021a_B.cmd[2] = 0.0;
      QD2_DroneStack_Manual_2021a_B.cmd[3] = 0.0;

      /* '<S22>:1:234' */
      /* '<S22>:1:235' */
      QD2_DroneStack_Manual_2021a_B.cmd_enable = 1.0;

      /* '<S22>:1:236' */
      /* '<S22>:1:237' */
      QD2_DroneStack_Manual_2021a_B.esc_ready = 1.0;
      break;

     case 5:
      /* '<S22>:1:241' */
      QD2_DroneStack_Manual_2021a_B.cmd[0] = 48.0;
      QD2_DroneStack_Manual_2021a_B.cmd[1] = 48.0;
      QD2_DroneStack_Manual_2021a_B.cmd[2] = 48.0;
      QD2_DroneStack_Manual_2021a_B.cmd[3] = 48.0;

      /* '<S22>:1:242' */
      QD2_DroneStack_Manual_2021a_B.tele_enable = 1.0;

      /* '<S22>:1:243' */
      QD2_DroneStack_Manual_2021a_B.cmd_enable = 1.0;

      /* '<S22>:1:244' */
      /* '<S22>:1:245' */
      QD2_DroneStack_Manual_2021a_B.esc_ready = 1.0;
      break;

     case 88:
      /* '<S22>:1:249' */
      QD2_DroneStack_Manual_2021a_B.cmd[0] = 0.0;
      QD2_DroneStack_Manual_2021a_B.cmd[1] = 0.0;
      QD2_DroneStack_Manual_2021a_B.cmd[2] = 0.0;
      QD2_DroneStack_Manual_2021a_B.cmd[3] = 0.0;

      /* '<S22>:1:250' */
      /* '<S22>:1:251' */
      /* '<S22>:1:252' */
      /* '<S22>:1:253' */
      break;

     case 77:
      /* '<S22>:1:257' */
      QD2_DroneStack_Manual_2021a_B.cmd[0] = 0.0;
      QD2_DroneStack_Manual_2021a_B.cmd[1] = 0.0;
      QD2_DroneStack_Manual_2021a_B.cmd[2] = 0.0;
      QD2_DroneStack_Manual_2021a_B.cmd[3] = 0.0;

      /* '<S22>:1:258' */
      QD2_DroneStack_Manual_2021a_B.tele_enable = 1.0;

      /* '<S22>:1:259' */
      QD2_DroneStack_Manual_2021a_B.cmd_enable = 1.0;

      /* '<S22>:1:260' */
      /* '<S22>:1:261' */
      break;

     case 99:
      /* '<S22>:1:265' */
      QD2_DroneStack_Manual_2021a_B.cmd[0] = 0.0;
      QD2_DroneStack_Manual_2021a_B.cmd[1] = 0.0;
      QD2_DroneStack_Manual_2021a_B.cmd[2] = 0.0;
      QD2_DroneStack_Manual_2021a_B.cmd[3] = 0.0;

      /* '<S22>:1:266' */
      /* '<S22>:1:267' */
      QD2_DroneStack_Manual_2021a_B.cmd_enable = 1.0;

      /* '<S22>:1:268' */
      /* '<S22>:1:269' */
      break;
    }

    /* '<S22>:1:273' */
    QD2_DroneStack_Manual_2021a_B.esc_timeout =
      QD2_DroneStack_Manual_2021a_DW.esc_timeout_state;
    QD2_DroneStack_Manual_2021a_B.state = rtb_DataTypeConversion3;

    /* End of MATLAB Function: '<S2>/MATLAB Function' */

    /* DataTypeConversion: '<S2>/Data Type Conversion' */
    tmp_3 = floor(QD2_DroneStack_Manual_2021a_B.state);
    if (rtIsNaN(tmp_3) || rtIsInf(tmp_3)) {
      tmp_3 = 0.0;
    } else {
      tmp_3 = fmod(tmp_3, 4.294967296E+9);
    }

    /* DataTypeConversion: '<S2>/Data Type Conversion' */
    QD2_DroneStack_Manual_2021a_B.DataTypeConversion_ko = tmp_3 < 0.0 ?
      (uint32_T)-(int32_T)(uint32_T)-tmp_3 : (uint32_T)tmp_3;

    /* Switch: '<S4>/Switch' */
    if (QD2_DroneStack_Manual_2021a_B.StreamClient_o4[0] >
        QD2_DroneStack_Manual_2021a_P.Switch_Threshold) {
      /* Switch: '<S4>/Switch' */
      QD2_DroneStack_Manual_2021a_B.AttitudeTorqueCommands[0] =
        QD2_DroneStack_Manual_2021a_B.StreamClient_o4[3];
    } else {
      /* Switch: '<S4>/Switch' incorporates:
       *  Constant: '<S4>/Zero Torque//Command'
       */
      QD2_DroneStack_Manual_2021a_B.AttitudeTorqueCommands[0] =
        QD2_DroneStack_Manual_2021a_P.ZeroTorqueCommand_Value[0];
    }

    /* Switch: '<S4>/Switch1' incorporates:
     *  Constant: '<S4>/Zero Torque//Command'
     *  Switch: '<S4>/Switch'
     */
    if (QD2_DroneStack_Manual_2021a_B.StreamClient_o4[0] >
        QD2_DroneStack_Manual_2021a_P.Switch1_Threshold) {
      rtb_DataTypeConversion3 =
        QD2_DroneStack_Manual_2021a_P.ZeroTorqueCommand_Value[0];
    } else {
      rtb_DataTypeConversion3 = QD2_DroneStack_Manual_2021a_B.StreamClient_o4[6];
    }

    /* Saturate: '<S4>/Saturate Stabilization Command' incorporates:
     *  Switch: '<S4>/Switch1'
     */
    if (rtb_DataTypeConversion3 >
        QD2_DroneStack_Manual_2021a_P.SaturateStabilizationCommand_Up[0]) {
      /* Saturate: '<S4>/Saturate Stabilization Command' */
      QD2_DroneStack_Manual_2021a_B.AttitudeAngleCommands[0] =
        QD2_DroneStack_Manual_2021a_P.SaturateStabilizationCommand_Up[0];
    } else if (rtb_DataTypeConversion3 <
               QD2_DroneStack_Manual_2021a_P.SaturateStabilizationCommand_Lo[0])
    {
      /* Saturate: '<S4>/Saturate Stabilization Command' */
      QD2_DroneStack_Manual_2021a_B.AttitudeAngleCommands[0] =
        QD2_DroneStack_Manual_2021a_P.SaturateStabilizationCommand_Lo[0];
    } else {
      /* Saturate: '<S4>/Saturate Stabilization Command' */
      QD2_DroneStack_Manual_2021a_B.AttitudeAngleCommands[0] =
        rtb_DataTypeConversion3;
    }

    /* Switch: '<S4>/Switch' */
    if (QD2_DroneStack_Manual_2021a_B.StreamClient_o4[0] >
        QD2_DroneStack_Manual_2021a_P.Switch_Threshold) {
      /* Switch: '<S4>/Switch' */
      QD2_DroneStack_Manual_2021a_B.AttitudeTorqueCommands[1] =
        QD2_DroneStack_Manual_2021a_B.StreamClient_o4[4];
    } else {
      /* Switch: '<S4>/Switch' incorporates:
       *  Constant: '<S4>/Zero Torque//Command'
       */
      QD2_DroneStack_Manual_2021a_B.AttitudeTorqueCommands[1] =
        QD2_DroneStack_Manual_2021a_P.ZeroTorqueCommand_Value[1];
    }

    /* Switch: '<S4>/Switch1' incorporates:
     *  Constant: '<S4>/Zero Torque//Command'
     *  Switch: '<S4>/Switch'
     */
    if (QD2_DroneStack_Manual_2021a_B.StreamClient_o4[0] >
        QD2_DroneStack_Manual_2021a_P.Switch1_Threshold) {
      rtb_DataTypeConversion3 =
        QD2_DroneStack_Manual_2021a_P.ZeroTorqueCommand_Value[1];
    } else {
      rtb_DataTypeConversion3 = QD2_DroneStack_Manual_2021a_B.StreamClient_o4[7];
    }

    /* Saturate: '<S4>/Saturate Stabilization Command' incorporates:
     *  Switch: '<S4>/Switch1'
     */
    if (rtb_DataTypeConversion3 >
        QD2_DroneStack_Manual_2021a_P.SaturateStabilizationCommand_Up[1]) {
      /* Saturate: '<S4>/Saturate Stabilization Command' */
      QD2_DroneStack_Manual_2021a_B.AttitudeAngleCommands[1] =
        QD2_DroneStack_Manual_2021a_P.SaturateStabilizationCommand_Up[1];
    } else if (rtb_DataTypeConversion3 <
               QD2_DroneStack_Manual_2021a_P.SaturateStabilizationCommand_Lo[1])
    {
      /* Saturate: '<S4>/Saturate Stabilization Command' */
      QD2_DroneStack_Manual_2021a_B.AttitudeAngleCommands[1] =
        QD2_DroneStack_Manual_2021a_P.SaturateStabilizationCommand_Lo[1];
    } else {
      /* Saturate: '<S4>/Saturate Stabilization Command' */
      QD2_DroneStack_Manual_2021a_B.AttitudeAngleCommands[1] =
        rtb_DataTypeConversion3;
    }

    /* Switch: '<S4>/Switch' */
    if (QD2_DroneStack_Manual_2021a_B.StreamClient_o4[0] >
        QD2_DroneStack_Manual_2021a_P.Switch_Threshold) {
      /* Switch: '<S4>/Switch' */
      QD2_DroneStack_Manual_2021a_B.AttitudeTorqueCommands[2] =
        QD2_DroneStack_Manual_2021a_B.StreamClient_o4[5];
    } else {
      /* Switch: '<S4>/Switch' incorporates:
       *  Constant: '<S4>/Zero Torque//Command'
       */
      QD2_DroneStack_Manual_2021a_B.AttitudeTorqueCommands[2] =
        QD2_DroneStack_Manual_2021a_P.ZeroTorqueCommand_Value[2];
    }

    /* Switch: '<S4>/Switch1' incorporates:
     *  Constant: '<S4>/Zero Torque//Command'
     *  Switch: '<S4>/Switch'
     */
    if (QD2_DroneStack_Manual_2021a_B.StreamClient_o4[0] >
        QD2_DroneStack_Manual_2021a_P.Switch1_Threshold) {
      rtb_DataTypeConversion3 =
        QD2_DroneStack_Manual_2021a_P.ZeroTorqueCommand_Value[2];
    } else {
      rtb_DataTypeConversion3 = QD2_DroneStack_Manual_2021a_B.StreamClient_o4[8];
    }

    /* Saturate: '<S4>/Saturate Stabilization Command' incorporates:
     *  Switch: '<S4>/Switch1'
     */
    if (rtb_DataTypeConversion3 >
        QD2_DroneStack_Manual_2021a_P.SaturateStabilizationCommand_Up[2]) {
      /* Saturate: '<S4>/Saturate Stabilization Command' */
      QD2_DroneStack_Manual_2021a_B.AttitudeAngleCommands[2] =
        QD2_DroneStack_Manual_2021a_P.SaturateStabilizationCommand_Up[2];
    } else if (rtb_DataTypeConversion3 <
               QD2_DroneStack_Manual_2021a_P.SaturateStabilizationCommand_Lo[2])
    {
      /* Saturate: '<S4>/Saturate Stabilization Command' */
      QD2_DroneStack_Manual_2021a_B.AttitudeAngleCommands[2] =
        QD2_DroneStack_Manual_2021a_P.SaturateStabilizationCommand_Lo[2];
    } else {
      /* Saturate: '<S4>/Saturate Stabilization Command' */
      QD2_DroneStack_Manual_2021a_B.AttitudeAngleCommands[2] =
        rtb_DataTypeConversion3;
    }
  }

  /* Outputs for Iterator SubSystem: '<S9>/For Each Subsystem - Iterate over IMU0 and IMU1' incorporates:
   *  ForEach: '<S28>/For Each'
   */
  for (ForEach_itr_b = 0; ForEach_itr_b < 2; ForEach_itr_b++) {
    /* ForEachSliceSelector generated from: '<S28>/IMU Data [6xn]' */
    for (firstBlockLength = 0; firstBlockLength < 6; firstBlockLength++) {
      rtb_MultiportSwitch[firstBlockLength] =
        (&QD2_DroneStack_Manual_2021a_B.HILRead_o2[0])[6 * ForEach_itr_b +
        firstBlockLength];
    }

    /* End of ForEachSliceSelector generated from: '<S28>/IMU Data [6xn]' */

    /* Integrator: '<S31>/Integrator1' */
    if (QD2_DroneStack_Manual_2021a_DW.CoreSubsys[ForEach_itr_b].
        Integrator1_DWORK1) {
      QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b]
        .Integrator1_CSTATE[0] = rtb_MultiportSwitch[3];
      QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b]
        .Integrator1_CSTATE[1] = rtb_MultiportSwitch[4];
      QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b]
        .Integrator1_CSTATE[2] = rtb_MultiportSwitch[5];
    }

    /* MATLAB Function: '<S28>/Roll and Pitch Approximation from Accelerometer data' incorporates:
     *  Integrator: '<S31>/Integrator1'
     */
    QD2_DroneStack_Manual_2021a_DW.CoreSubsys[ForEach_itr_b].sfEvent =
      QD2_DroneStack_Manua_CALL_EVENT;

    /* MATLAB Function 'QDrone 2 DAQ/Attitude Estimate from IMU Data/For Each Subsystem - Iterate over IMU0 and IMU1/Roll and Pitch Approximation from Accelerometer data': '<S29>:1' */
    /* '<S29>:1:7' */
    /* '<S29>:1:3' */
    data_loss = 3.312168642111238E-170;
    rtb_Sum1_f_idx_0 = fabs
      (QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].
       Integrator1_CSTATE[0]);
    if (rtb_Sum1_f_idx_0 > 3.312168642111238E-170) {
      rtb_DataTypeConversion3 = 1.0;
      data_loss = rtb_Sum1_f_idx_0;
    } else {
      rtb_Sum1_f_idx_1 = rtb_Sum1_f_idx_0 / 3.312168642111238E-170;
      rtb_DataTypeConversion3 = rtb_Sum1_f_idx_1 * rtb_Sum1_f_idx_1;
    }

    rtb_Sum1_f_idx_0 = fabs
      (QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].
       Integrator1_CSTATE[1]);
    if (rtb_Sum1_f_idx_0 > data_loss) {
      rtb_Sum1_f_idx_1 = data_loss / rtb_Sum1_f_idx_0;
      rtb_DataTypeConversion3 = rtb_DataTypeConversion3 * rtb_Sum1_f_idx_1 *
        rtb_Sum1_f_idx_1 + 1.0;
      data_loss = rtb_Sum1_f_idx_0;
    } else {
      rtb_Sum1_f_idx_1 = rtb_Sum1_f_idx_0 / data_loss;
      rtb_DataTypeConversion3 += rtb_Sum1_f_idx_1 * rtb_Sum1_f_idx_1;
    }

    rtb_Sum1_f_idx_0 = fabs
      (QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].
       Integrator1_CSTATE[2]);
    if (rtb_Sum1_f_idx_0 > data_loss) {
      rtb_Sum1_f_idx_1 = data_loss / rtb_Sum1_f_idx_0;
      rtb_DataTypeConversion3 = rtb_DataTypeConversion3 * rtb_Sum1_f_idx_1 *
        rtb_Sum1_f_idx_1 + 1.0;
      data_loss = rtb_Sum1_f_idx_0;
    } else {
      rtb_Sum1_f_idx_1 = rtb_Sum1_f_idx_0 / data_loss;
      rtb_DataTypeConversion3 += rtb_Sum1_f_idx_1 * rtb_Sum1_f_idx_1;
    }

    rtb_DataTypeConversion3 = data_loss * sqrt(rtb_DataTypeConversion3);
    if (rtIsNaN(rtb_DataTypeConversion3)) {
      b_k = 0;
      do {
        exitg1 = 0;
        if (b_k < 3) {
          if (rtIsNaN(QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].
                      Integrator1_CSTATE[b_k])) {
            exitg1 = 1;
          } else {
            b_k++;
          }
        } else {
          rtb_DataTypeConversion3 = (rtInf);
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }

    if (rtb_DataTypeConversion3 > 2.220446049250313E-16) {
      /* '<S29>:1:4' */
      /* '<S29>:1:5' */
      rtb_Sum1_f_idx_0 = QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b]
        .Integrator1_CSTATE[0] / rtb_DataTypeConversion3;
      rtb_Sum1_f_idx_1 = QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b]
        .Integrator1_CSTATE[1] / rtb_DataTypeConversion3;
      rtb_Sum1_f_idx_2 = QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b]
        .Integrator1_CSTATE[2] / rtb_DataTypeConversion3;
    } else {
      /* '<S29>:1:7' */
      rtb_Sum1_f_idx_0 = 0.0;
      rtb_Sum1_f_idx_1 = 0.0;
      rtb_Sum1_f_idx_2 = 1.0;
    }

    /* '<S29>:1:10' */
    rtb_DataTypeConversion3 = rt_atan2d_snf(rtb_Sum1_f_idx_1, rtb_Sum1_f_idx_2);

    /* Sum: '<S28>/Sum' incorporates:
     *  Integrator: '<S28>/Integrator1'
     *  MATLAB Function: '<S28>/Roll and Pitch Approximation from Accelerometer data'
     */
    /* '<S29>:1:11' */
    data_loss = QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].
      Integrator1_CSTATE_h[0] - rtb_DataTypeConversion3;
    rtb_DataTypeConversion3 =
      QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].
      Integrator1_CSTATE_h[1] - rt_atan2d_snf(-rtb_Sum1_f_idx_0,
      rtb_Sum1_f_idx_1 * sin(rtb_DataTypeConversion3) + rtb_Sum1_f_idx_2 * cos
      (rtb_DataTypeConversion3));

    /* Gain: '<S28>/Gain1' */
    QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Gain1[0] =
      QD2_DroneStack_Manual_2021a_P.CoreSubsys.Gain1_Gain[0] * data_loss;
    QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Gain1[1] =
      QD2_DroneStack_Manual_2021a_P.CoreSubsys.Gain1_Gain[1] *
      rtb_DataTypeConversion3;

    /* Integrator: '<S30>/Integrator1' */
    if (QD2_DroneStack_Manual_2021a_DW.CoreSubsys[ForEach_itr_b].
        Integrator1_DWORK1_b) {
      QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].
        Integrator1_CSTATE_h5[0] = rtb_MultiportSwitch[0];
      QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].
        Integrator1_CSTATE_h5[1] = rtb_MultiportSwitch[1];
      QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].
        Integrator1_CSTATE_h5[2] = rtb_MultiportSwitch[2];
    }

    /* Integrator: '<S30>/Integrator1' */
    QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Integrator1[0] =
      QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].
      Integrator1_CSTATE_h5[0];

    /* Product: '<S30>/Product1' incorporates:
     *  Constant: '<S28>/Gyro Filter Cutoff Frequency (rad//s)'
     *  Integrator: '<S30>/Integrator2'
     */
    QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Product1[0] =
      QD2_DroneStack_Manual_2021a_P.CoreSubsys.GyroFilterCutoffFrequencyrads_V *
      QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].
      Integrator2_CSTATE_k[0];

    /* Product: '<S30>/Product' incorporates:
     *  Constant: '<S28>/Gyro Filter Cutoff Frequency (rad//s)'
     *  Constant: '<S28>/Gyro Filter Damping Ratio'
     *  Constant: '<S30>/Constant'
     *  Integrator: '<S30>/Integrator1'
     *  Integrator: '<S30>/Integrator2'
     *  Product: '<S30>/Product2'
     *  Sum: '<S30>/Sum'
     *  Sum: '<S30>/Sum1'
     */
    QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Product[0] =
      ((rtb_MultiportSwitch[0] -
        QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].
        Integrator1_CSTATE_h5[0]) -
       QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].
       Integrator2_CSTATE_k[0] *
       QD2_DroneStack_Manual_2021a_P.CoreSubsys.Constant_Value *
       QD2_DroneStack_Manual_2021a_P.CoreSubsys.GyroFilterDampingRatio_Value) *
      QD2_DroneStack_Manual_2021a_P.CoreSubsys.GyroFilterCutoffFrequencyrads_V;

    /* Product: '<S31>/Product' incorporates:
     *  Constant: '<S28>/Accelerometer Filter Cutoff Frequency (rad//s)'
     *  Constant: '<S28>/Accelerometer Filter Damping Ratio'
     *  Constant: '<S31>/Constant'
     *  Integrator: '<S31>/Integrator1'
     *  Integrator: '<S31>/Integrator2'
     *  Product: '<S31>/Product2'
     *  Sum: '<S31>/Sum'
     *  Sum: '<S31>/Sum1'
     */
    QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Product_j[0] =
      ((rtb_MultiportSwitch[3] -
        QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].
        Integrator1_CSTATE[0]) -
       QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].
       Integrator2_CSTATE_e[0] *
       QD2_DroneStack_Manual_2021a_P.CoreSubsys.Constant_Value_m *
       QD2_DroneStack_Manual_2021a_P.CoreSubsys.AccelerometerFilterDampingRatio)
      * QD2_DroneStack_Manual_2021a_P.CoreSubsys.AccelerometerFilterCutoffFreque;

    /* Product: '<S31>/Product1' incorporates:
     *  Constant: '<S28>/Accelerometer Filter Cutoff Frequency (rad//s)'
     *  Integrator: '<S31>/Integrator2'
     */
    QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Product1_e[0] =
      QD2_DroneStack_Manual_2021a_P.CoreSubsys.AccelerometerFilterCutoffFreque *
      QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].
      Integrator2_CSTATE_e[0];

    /* Integrator: '<S30>/Integrator1' */
    QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Integrator1[1] =
      QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].
      Integrator1_CSTATE_h5[1];

    /* Product: '<S30>/Product1' incorporates:
     *  Constant: '<S28>/Gyro Filter Cutoff Frequency (rad//s)'
     *  Integrator: '<S30>/Integrator2'
     */
    QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Product1[1] =
      QD2_DroneStack_Manual_2021a_P.CoreSubsys.GyroFilterCutoffFrequencyrads_V *
      QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].
      Integrator2_CSTATE_k[1];

    /* Product: '<S30>/Product' incorporates:
     *  Constant: '<S28>/Gyro Filter Cutoff Frequency (rad//s)'
     *  Constant: '<S28>/Gyro Filter Damping Ratio'
     *  Constant: '<S30>/Constant'
     *  Integrator: '<S30>/Integrator1'
     *  Integrator: '<S30>/Integrator2'
     *  Product: '<S30>/Product2'
     *  Sum: '<S30>/Sum'
     *  Sum: '<S30>/Sum1'
     */
    QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Product[1] =
      ((rtb_MultiportSwitch[1] -
        QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].
        Integrator1_CSTATE_h5[1]) -
       QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].
       Integrator2_CSTATE_k[1] *
       QD2_DroneStack_Manual_2021a_P.CoreSubsys.Constant_Value *
       QD2_DroneStack_Manual_2021a_P.CoreSubsys.GyroFilterDampingRatio_Value) *
      QD2_DroneStack_Manual_2021a_P.CoreSubsys.GyroFilterCutoffFrequencyrads_V;

    /* Product: '<S31>/Product' incorporates:
     *  Constant: '<S28>/Accelerometer Filter Cutoff Frequency (rad//s)'
     *  Constant: '<S28>/Accelerometer Filter Damping Ratio'
     *  Constant: '<S31>/Constant'
     *  Integrator: '<S31>/Integrator1'
     *  Integrator: '<S31>/Integrator2'
     *  Product: '<S31>/Product2'
     *  Sum: '<S31>/Sum'
     *  Sum: '<S31>/Sum1'
     */
    QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Product_j[1] =
      ((rtb_MultiportSwitch[4] -
        QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].
        Integrator1_CSTATE[1]) -
       QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].
       Integrator2_CSTATE_e[1] *
       QD2_DroneStack_Manual_2021a_P.CoreSubsys.Constant_Value_m *
       QD2_DroneStack_Manual_2021a_P.CoreSubsys.AccelerometerFilterDampingRatio)
      * QD2_DroneStack_Manual_2021a_P.CoreSubsys.AccelerometerFilterCutoffFreque;

    /* Product: '<S31>/Product1' incorporates:
     *  Constant: '<S28>/Accelerometer Filter Cutoff Frequency (rad//s)'
     *  Integrator: '<S31>/Integrator2'
     */
    QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Product1_e[1] =
      QD2_DroneStack_Manual_2021a_P.CoreSubsys.AccelerometerFilterCutoffFreque *
      QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].
      Integrator2_CSTATE_e[1];

    /* Integrator: '<S30>/Integrator1' */
    QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Integrator1[2] =
      QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].
      Integrator1_CSTATE_h5[2];

    /* Product: '<S30>/Product1' incorporates:
     *  Constant: '<S28>/Gyro Filter Cutoff Frequency (rad//s)'
     *  Integrator: '<S30>/Integrator2'
     */
    QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Product1[2] =
      QD2_DroneStack_Manual_2021a_P.CoreSubsys.GyroFilterCutoffFrequencyrads_V *
      QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].
      Integrator2_CSTATE_k[2];

    /* Product: '<S30>/Product' incorporates:
     *  Constant: '<S28>/Gyro Filter Cutoff Frequency (rad//s)'
     *  Constant: '<S28>/Gyro Filter Damping Ratio'
     *  Constant: '<S30>/Constant'
     *  Integrator: '<S30>/Integrator1'
     *  Integrator: '<S30>/Integrator2'
     *  Product: '<S30>/Product2'
     *  Sum: '<S30>/Sum'
     *  Sum: '<S30>/Sum1'
     */
    QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Product[2] =
      ((rtb_MultiportSwitch[2] -
        QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].
        Integrator1_CSTATE_h5[2]) -
       QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].
       Integrator2_CSTATE_k[2] *
       QD2_DroneStack_Manual_2021a_P.CoreSubsys.Constant_Value *
       QD2_DroneStack_Manual_2021a_P.CoreSubsys.GyroFilterDampingRatio_Value) *
      QD2_DroneStack_Manual_2021a_P.CoreSubsys.GyroFilterCutoffFrequencyrads_V;

    /* Product: '<S31>/Product' incorporates:
     *  Constant: '<S28>/Accelerometer Filter Cutoff Frequency (rad//s)'
     *  Constant: '<S28>/Accelerometer Filter Damping Ratio'
     *  Constant: '<S31>/Constant'
     *  Integrator: '<S31>/Integrator1'
     *  Integrator: '<S31>/Integrator2'
     *  Product: '<S31>/Product2'
     *  Sum: '<S31>/Sum'
     *  Sum: '<S31>/Sum1'
     */
    QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Product_j[2] =
      ((rtb_MultiportSwitch[5] -
        QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].
        Integrator1_CSTATE[2]) -
       QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].
       Integrator2_CSTATE_e[2] *
       QD2_DroneStack_Manual_2021a_P.CoreSubsys.Constant_Value_m *
       QD2_DroneStack_Manual_2021a_P.CoreSubsys.AccelerometerFilterDampingRatio)
      * QD2_DroneStack_Manual_2021a_P.CoreSubsys.AccelerometerFilterCutoffFreque;

    /* Product: '<S31>/Product1' incorporates:
     *  Constant: '<S28>/Accelerometer Filter Cutoff Frequency (rad//s)'
     *  Integrator: '<S31>/Integrator2'
     */
    QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Product1_e[2] =
      QD2_DroneStack_Manual_2021a_P.CoreSubsys.AccelerometerFilterCutoffFreque *
      QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].
      Integrator2_CSTATE_e[2];

    /* Sum: '<S28>/Sum1' incorporates:
     *  Gain: '<S28>/Gain'
     *  Integrator: '<S28>/Integrator'
     */
    QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Sum1[0] =
      (QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Integrator1[0] -
       QD2_DroneStack_Manual_2021a_P.CoreSubsys.Gain_Gain[0] * data_loss) -
      QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].Integrator_CSTATE
      [0];

    /* ForEachSliceAssignment generated from: '<S28>/BF Estimated Attitude (rad, rad//s, rad//2^2) [9xn]' incorporates:
     *  Integrator: '<S28>/Integrator1'
     */
    rtb_ImpAsg_InsertedFor_BFEstima[9 * ForEach_itr_b] =
      QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].
      Integrator1_CSTATE_h[0];

    /* Sum: '<S28>/Sum1' incorporates:
     *  Gain: '<S28>/Gain'
     *  Integrator: '<S28>/Integrator'
     */
    QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Sum1[1] =
      (QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Integrator1[1] -
       QD2_DroneStack_Manual_2021a_P.CoreSubsys.Gain_Gain[1] *
       rtb_DataTypeConversion3) -
      QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].Integrator_CSTATE
      [1];

    /* ForEachSliceAssignment generated from: '<S28>/BF Estimated Attitude (rad, rad//s, rad//2^2) [9xn]' incorporates:
     *  Integrator: '<S28>/Integrator1'
     *  Integrator: '<S28>/Integrator2'
     *  SignalConversion generated from: '<S28>/BF Estimated Attitude (rad, rad//s, rad//2^2) [9xn]'
     */
    rtb_ImpAsg_InsertedFor_BFEstima[9 * ForEach_itr_b + 1] =
      QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].
      Integrator1_CSTATE_h[1];
    rtb_ImpAsg_InsertedFor_BFEstima[9 * ForEach_itr_b + 2] =
      QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].Integrator2_CSTATE;
    rtb_ImpAsg_InsertedFor_BFEstima[9 * ForEach_itr_b + 3] =
      QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Integrator1[0];
    rtb_ImpAsg_InsertedFor_BFEstima[9 * ForEach_itr_b + 6] =
      QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Product1[0];
    rtb_ImpAsg_InsertedFor_BFEstima[9 * ForEach_itr_b + 4] =
      QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Integrator1[1];
    rtb_ImpAsg_InsertedFor_BFEstima[9 * ForEach_itr_b + 7] =
      QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Product1[1];
    rtb_ImpAsg_InsertedFor_BFEstima[9 * ForEach_itr_b + 5] =
      QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Integrator1[2];
    rtb_ImpAsg_InsertedFor_BFEstima[9 * ForEach_itr_b + 8] =
      QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Product1[2];
  }

  /* End of Outputs for SubSystem: '<S9>/For Each Subsystem - Iterate over IMU0 and IMU1' */
  for (firstBlockLength = 0; firstBlockLength < 9; firstBlockLength++) {
    /* Selector: '<S9>/Select Data for IMU1' incorporates:
     *  ForEachSliceAssignment generated from: '<S28>/BF Estimated Attitude (rad, rad//s, rad//2^2) [9xn]'
     */
    rtb_DataTypeConversion3 = rtb_ImpAsg_InsertedFor_BFEstima[firstBlockLength +
      9];
    QD2_DroneStack_Manual_2021a_B.SelectDataforIMU1[firstBlockLength] =
      rtb_DataTypeConversion3;

    /* Selector: '<S9>/Select Data for IMU0' incorporates:
     *  ForEachSliceAssignment generated from: '<S28>/BF Estimated Attitude (rad, rad//s, rad//2^2) [9xn]'
     */
    rtb_Sum1_f_idx_0 = rtb_ImpAsg_InsertedFor_BFEstima[firstBlockLength];
    QD2_DroneStack_Manual_2021a_B.SelectDataforIMU0[firstBlockLength] =
      rtb_Sum1_f_idx_0;

    /* Product: '<S2>/Product3' incorporates:
     *  Constant: '<S2>/Constant1'
     *  Selector: '<S9>/Select Data for IMU0'
     *  Selector: '<S9>/Select Data for IMU1'
     *  Sum: '<S2>/Sum'
     */
    QD2_DroneStack_Manual_2021a_B.Product3[firstBlockLength] =
      (rtb_DataTypeConversion3 + rtb_Sum1_f_idx_0) /
      QD2_DroneStack_Manual_2021a_P.Constant1_Value;
  }

  /* Sum: '<S4>/Sum1' incorporates:
   *  Gain: '<S4>/Gain1'
   *  Gain: '<S4>/K_d_angle (rad//s // rad//s)'
   *  Gain: '<S4>/K_p_angle (rad//s // rad)'
   *  Gain: '<S4>/Scale'
   *  Gain: '<S4>/Scale1'
   *  Sum: '<S4>/Sum'
   */
  rtb_Sum1_f_idx_2 = (QD2_DroneStack_Manual_2021a_B.AttitudeAngleCommands[0] -
                      QD2_DroneStack_Manual_2021a_P.Gain1_Gain[0] *
                      QD2_DroneStack_Manual_2021a_B.Product3[0]) *
    QD2_DroneStack_Manual_2021a_P.K_p_angleradsrad_Gain[0] *
    QD2_DroneStack_Manual_2021a_P.Scale_Gain[0] -
    QD2_DroneStack_Manual_2021a_P.K_d_angleradsrads_Gain[0] *
    QD2_DroneStack_Manual_2021a_B.Product3[3] *
    QD2_DroneStack_Manual_2021a_P.Scale1_Gain[0];
  rtb_Sum1_f_idx_0 = rtb_Sum1_f_idx_2;

  /* Saturate: '<S4>/Saturation Max Rate  (rad//s)' */
  if (rtb_Sum1_f_idx_2 >
      QD2_DroneStack_Manual_2021a_P.SaturationMaxRaterads_UpperSat[0]) {
    rtb_Sum1_f_idx_2 =
      QD2_DroneStack_Manual_2021a_P.SaturationMaxRaterads_UpperSat[0];
  } else if (rtb_Sum1_f_idx_2 <
             QD2_DroneStack_Manual_2021a_P.SaturationMaxRaterads_LowerSat[0]) {
    rtb_Sum1_f_idx_2 =
      QD2_DroneStack_Manual_2021a_P.SaturationMaxRaterads_LowerSat[0];
  }

  /* Sum: '<S4>/Sum6' incorporates:
   *  Gain: '<S4>/K_d_angle (rad//s // rad//s)'
   *  Gain: '<S4>/K_d_speed (Nm // rad//s//s)1'
   *  Gain: '<S4>/K_p_speed (Nm // rad//s)'
   *  Gain: '<S4>/Scale4'
   *  Gain: '<S4>/Scale5'
   *  Saturate: '<S4>/Saturation Max Rate  (rad//s)'
   *  Sum: '<S4>/Sum5'
   */
  QD2_DroneStack_Manual_2021a_B.Sum6[0] = ((rtb_Sum1_f_idx_2 -
    QD2_DroneStack_Manual_2021a_B.Product3[3]) *
    QD2_DroneStack_Manual_2021a_P.K_p_speedNmrads_Gain[0] *
    QD2_DroneStack_Manual_2021a_P.Scale5_Gain[0] +
    QD2_DroneStack_Manual_2021a_B.AttitudeTorqueCommands[0]) -
    QD2_DroneStack_Manual_2021a_P.K_d_speedNmradss1_Gain[0] *
    QD2_DroneStack_Manual_2021a_B.Product3[6] *
    QD2_DroneStack_Manual_2021a_P.Scale4_Gain[0];

  /* Saturate: '<S4>/Saturation Command  Authority (Nm)1' */
  if (QD2_DroneStack_Manual_2021a_B.Sum6[0] >
      QD2_DroneStack_Manual_2021a_P.SaturationCommandAuthorityNm1_U[0]) {
    /* Saturate: '<S4>/Saturation Command  Authority (Nm)1' */
    QD2_DroneStack_Manual_2021a_B.SaturationCommandAuthorityNm1[0] =
      QD2_DroneStack_Manual_2021a_P.SaturationCommandAuthorityNm1_U[0];
  } else if (QD2_DroneStack_Manual_2021a_B.Sum6[0] <
             QD2_DroneStack_Manual_2021a_P.SaturationCommandAuthorityNm1_L[0]) {
    /* Saturate: '<S4>/Saturation Command  Authority (Nm)1' */
    QD2_DroneStack_Manual_2021a_B.SaturationCommandAuthorityNm1[0] =
      QD2_DroneStack_Manual_2021a_P.SaturationCommandAuthorityNm1_L[0];
  } else {
    /* Saturate: '<S4>/Saturation Command  Authority (Nm)1' */
    QD2_DroneStack_Manual_2021a_B.SaturationCommandAuthorityNm1[0] =
      QD2_DroneStack_Manual_2021a_B.Sum6[0];
  }

  /* Sum: '<S4>/Sum1' incorporates:
   *  Gain: '<S4>/Gain1'
   *  Gain: '<S4>/K_d_angle (rad//s // rad//s)'
   *  Gain: '<S4>/K_p_angle (rad//s // rad)'
   *  Gain: '<S4>/Scale'
   *  Gain: '<S4>/Scale1'
   *  Sum: '<S4>/Sum'
   */
  rtb_Sum1_f_idx_2 = (QD2_DroneStack_Manual_2021a_B.AttitudeAngleCommands[1] -
                      QD2_DroneStack_Manual_2021a_P.Gain1_Gain[1] *
                      QD2_DroneStack_Manual_2021a_B.Product3[1]) *
    QD2_DroneStack_Manual_2021a_P.K_p_angleradsrad_Gain[1] *
    QD2_DroneStack_Manual_2021a_P.Scale_Gain[1] -
    QD2_DroneStack_Manual_2021a_P.K_d_angleradsrads_Gain[1] *
    QD2_DroneStack_Manual_2021a_B.Product3[4] *
    QD2_DroneStack_Manual_2021a_P.Scale1_Gain[1];
  rtb_Sum1_f_idx_1 = rtb_Sum1_f_idx_2;

  /* Saturate: '<S4>/Saturation Max Rate  (rad//s)' */
  if (rtb_Sum1_f_idx_2 >
      QD2_DroneStack_Manual_2021a_P.SaturationMaxRaterads_UpperSat[1]) {
    rtb_Sum1_f_idx_2 =
      QD2_DroneStack_Manual_2021a_P.SaturationMaxRaterads_UpperSat[1];
  } else if (rtb_Sum1_f_idx_2 <
             QD2_DroneStack_Manual_2021a_P.SaturationMaxRaterads_LowerSat[1]) {
    rtb_Sum1_f_idx_2 =
      QD2_DroneStack_Manual_2021a_P.SaturationMaxRaterads_LowerSat[1];
  }

  /* Sum: '<S4>/Sum6' incorporates:
   *  Gain: '<S4>/K_d_angle (rad//s // rad//s)'
   *  Gain: '<S4>/K_d_speed (Nm // rad//s//s)1'
   *  Gain: '<S4>/K_p_speed (Nm // rad//s)'
   *  Gain: '<S4>/Scale4'
   *  Gain: '<S4>/Scale5'
   *  Saturate: '<S4>/Saturation Max Rate  (rad//s)'
   *  Sum: '<S4>/Sum5'
   */
  QD2_DroneStack_Manual_2021a_B.Sum6[1] = ((rtb_Sum1_f_idx_2 -
    QD2_DroneStack_Manual_2021a_B.Product3[4]) *
    QD2_DroneStack_Manual_2021a_P.K_p_speedNmrads_Gain[1] *
    QD2_DroneStack_Manual_2021a_P.Scale5_Gain[1] +
    QD2_DroneStack_Manual_2021a_B.AttitudeTorqueCommands[1]) -
    QD2_DroneStack_Manual_2021a_P.K_d_speedNmradss1_Gain[1] *
    QD2_DroneStack_Manual_2021a_B.Product3[7] *
    QD2_DroneStack_Manual_2021a_P.Scale4_Gain[1];

  /* Saturate: '<S4>/Saturation Command  Authority (Nm)1' */
  if (QD2_DroneStack_Manual_2021a_B.Sum6[1] >
      QD2_DroneStack_Manual_2021a_P.SaturationCommandAuthorityNm1_U[1]) {
    /* Saturate: '<S4>/Saturation Command  Authority (Nm)1' */
    QD2_DroneStack_Manual_2021a_B.SaturationCommandAuthorityNm1[1] =
      QD2_DroneStack_Manual_2021a_P.SaturationCommandAuthorityNm1_U[1];
  } else if (QD2_DroneStack_Manual_2021a_B.Sum6[1] <
             QD2_DroneStack_Manual_2021a_P.SaturationCommandAuthorityNm1_L[1]) {
    /* Saturate: '<S4>/Saturation Command  Authority (Nm)1' */
    QD2_DroneStack_Manual_2021a_B.SaturationCommandAuthorityNm1[1] =
      QD2_DroneStack_Manual_2021a_P.SaturationCommandAuthorityNm1_L[1];
  } else {
    /* Saturate: '<S4>/Saturation Command  Authority (Nm)1' */
    QD2_DroneStack_Manual_2021a_B.SaturationCommandAuthorityNm1[1] =
      QD2_DroneStack_Manual_2021a_B.Sum6[1];
  }

  /* Sum: '<S4>/Sum1' incorporates:
   *  Gain: '<S4>/Gain1'
   *  Gain: '<S4>/K_d_angle (rad//s // rad//s)'
   *  Gain: '<S4>/K_p_angle (rad//s // rad)'
   *  Gain: '<S4>/Scale'
   *  Gain: '<S4>/Scale1'
   *  Sum: '<S4>/Sum'
   */
  rtb_Sum1_f_idx_2 = (QD2_DroneStack_Manual_2021a_B.AttitudeAngleCommands[2] -
                      QD2_DroneStack_Manual_2021a_P.Gain1_Gain[2] *
                      QD2_DroneStack_Manual_2021a_B.Product3[2]) *
    QD2_DroneStack_Manual_2021a_P.K_p_angleradsrad_Gain[2] *
    QD2_DroneStack_Manual_2021a_P.Scale_Gain[2] -
    QD2_DroneStack_Manual_2021a_P.K_d_angleradsrads_Gain[2] *
    QD2_DroneStack_Manual_2021a_B.Product3[5] *
    QD2_DroneStack_Manual_2021a_P.Scale1_Gain[2];

  /* Saturate: '<S4>/Saturation Max Rate  (rad//s)' */
  if (rtb_Sum1_f_idx_2 >
      QD2_DroneStack_Manual_2021a_P.SaturationMaxRaterads_UpperSat[2]) {
    tmp_3 = QD2_DroneStack_Manual_2021a_P.SaturationMaxRaterads_UpperSat[2];
  } else if (rtb_Sum1_f_idx_2 <
             QD2_DroneStack_Manual_2021a_P.SaturationMaxRaterads_LowerSat[2]) {
    tmp_3 = QD2_DroneStack_Manual_2021a_P.SaturationMaxRaterads_LowerSat[2];
  } else {
    tmp_3 = rtb_Sum1_f_idx_2;
  }

  /* Sum: '<S4>/Sum6' incorporates:
   *  Gain: '<S4>/K_d_angle (rad//s // rad//s)'
   *  Gain: '<S4>/K_d_speed (Nm // rad//s//s)1'
   *  Gain: '<S4>/K_p_speed (Nm // rad//s)'
   *  Gain: '<S4>/Scale4'
   *  Gain: '<S4>/Scale5'
   *  Saturate: '<S4>/Saturation Max Rate  (rad//s)'
   *  Sum: '<S4>/Sum5'
   */
  QD2_DroneStack_Manual_2021a_B.Sum6[2] = ((tmp_3 -
    QD2_DroneStack_Manual_2021a_B.Product3[5]) *
    QD2_DroneStack_Manual_2021a_P.K_p_speedNmrads_Gain[2] *
    QD2_DroneStack_Manual_2021a_P.Scale5_Gain[2] +
    QD2_DroneStack_Manual_2021a_B.AttitudeTorqueCommands[2]) -
    QD2_DroneStack_Manual_2021a_P.K_d_speedNmradss1_Gain[2] *
    QD2_DroneStack_Manual_2021a_B.Product3[8] *
    QD2_DroneStack_Manual_2021a_P.Scale4_Gain[2];

  /* Saturate: '<S4>/Saturation Command  Authority (Nm)1' */
  if (QD2_DroneStack_Manual_2021a_B.Sum6[2] >
      QD2_DroneStack_Manual_2021a_P.SaturationCommandAuthorityNm1_U[2]) {
    /* Saturate: '<S4>/Saturation Command  Authority (Nm)1' */
    QD2_DroneStack_Manual_2021a_B.SaturationCommandAuthorityNm1[2] =
      QD2_DroneStack_Manual_2021a_P.SaturationCommandAuthorityNm1_U[2];
  } else if (QD2_DroneStack_Manual_2021a_B.Sum6[2] <
             QD2_DroneStack_Manual_2021a_P.SaturationCommandAuthorityNm1_L[2]) {
    /* Saturate: '<S4>/Saturation Command  Authority (Nm)1' */
    QD2_DroneStack_Manual_2021a_B.SaturationCommandAuthorityNm1[2] =
      QD2_DroneStack_Manual_2021a_P.SaturationCommandAuthorityNm1_L[2];
  } else {
    /* Saturate: '<S4>/Saturation Command  Authority (Nm)1' */
    QD2_DroneStack_Manual_2021a_B.SaturationCommandAuthorityNm1[2] =
      QD2_DroneStack_Manual_2021a_B.Sum6[2];
  }

  if (rtb_Relation) {
    /* Delay: '<S4>/Delay' */
    QD2_DroneStack_Manual_2021a_B.Delay =
      QD2_DroneStack_Manual_2021a_DW.Delay_DSTATE_l[0];
  }

  /* MATLAB Function: '<S2>/Force to percentage Mapping' incorporates:
   *  Constant: '<S2>/Constant3'
   */
  QD2_DroneStack_Manual_2021a_DW.sfEvent_e = QD2_DroneStack_Manua_CALL_EVENT;

  /* MATLAB Function 'QDrone 2 DAQ/Force to percentage Mapping': '<S20>:1' */
  /* '<S20>:1:3' */
  rtb_DataTypeConversion3 = QD2_DroneStack_Manual_2021a_P.KT[1] *
    QD2_DroneStack_Manual_2021a_P.KT[1];
  data_loss = 4.0 * QD2_DroneStack_Manual_2021a_P.KT[0];
  tmp_3 = QD2_DroneStack_Manual_2021a_P.KT[2];

  /* Product: '<S4>/Product' */
  tmp = QD2_DroneStack_Manual_2021a_B.StreamClient_o4[2] *
    QD2_DroneStack_Manual_2021a_B.Delay;
  tmp_0 = QD2_DroneStack_Manual_2021a_B.SaturationCommandAuthorityNm1[0] *
    QD2_DroneStack_Manual_2021a_B.Delay;
  tmp_1 = QD2_DroneStack_Manual_2021a_B.SaturationCommandAuthorityNm1[1] *
    QD2_DroneStack_Manual_2021a_B.Delay;
  tmp_2 = QD2_DroneStack_Manual_2021a_B.SaturationCommandAuthorityNm1[2] *
    QD2_DroneStack_Manual_2021a_B.Delay;

  /* MATLAB Function: '<S2>/Force to percentage Mapping' incorporates:
   *  Constant: '<S2>/Constant2'
   *  Product: '<S2>/Product5'
   */
  /* '<S20>:1:5' */
  /* '<S20>:1:6' */
  for (firstBlockLength = 0; firstBlockLength < 4; firstBlockLength++) {
    Duty_Cycle_0 = rtb_DataTypeConversion3 - (tmp_3 -
      (((QD2_DroneStack_Manual_2021a_P.Motor_Matrix[firstBlockLength + 4] *
         tmp_0 + QD2_DroneStack_Manual_2021a_P.Motor_Matrix[firstBlockLength] *
         tmp) + QD2_DroneStack_Manual_2021a_P.Motor_Matrix[firstBlockLength + 8]
        * tmp_1) + QD2_DroneStack_Manual_2021a_P.Motor_Matrix[firstBlockLength +
       12] * tmp_2)) * data_loss;
    Duty_Cycle[firstBlockLength] = Duty_Cycle_0;
    if (Duty_Cycle_0 < 0.0) {
      Duty_Cycle[firstBlockLength] = 0.0;
    }
  }

  /* ManualSwitch: '<S2>/Manual Switch -   Select Command Input' incorporates:
   *  Constant: '<Root>/Zero Reference Motor Commands'
   *  Constant: '<S2>/Constant3'
   *  MATLAB Function: '<S2>/Force to percentage Mapping'
   */
  /* '<S20>:1:9' */
  /* '<S20>:1:11' */
  if (QD2_DroneStack_Manual_2021a_P.ManualSwitchSelectCommandInput_ == 1) {
    rtb_DataTypeConversion3 = (-0.5 * QD2_DroneStack_Manual_2021a_P.KT[1] /
      QD2_DroneStack_Manual_2021a_P.KT[0] + sqrt(Duty_Cycle[0]) / (2.0 *
      QD2_DroneStack_Manual_2021a_P.KT[0])) /
      QD2_DroneStack_Manual_2021a_B.HILRead_o1[0];
  } else {
    rtb_DataTypeConversion3 =
      QD2_DroneStack_Manual_2021a_P.ZeroReferenceMotorCommands_Valu[0];
  }

  /* Saturate: '<S2>/Maximum  Command Authority ' incorporates:
   *  ManualSwitch: '<S2>/Manual Switch -   Select Command Input'
   */
  if (rtb_DataTypeConversion3 >
      QD2_DroneStack_Manual_2021a_P.MaximumCommandAuthority_UpperSa[0]) {
    /* Saturate: '<S2>/Maximum  Command Authority ' */
    QD2_DroneStack_Manual_2021a_B.MaximumCommandAuthority[0] =
      QD2_DroneStack_Manual_2021a_P.MaximumCommandAuthority_UpperSa[0];
  } else if (rtb_DataTypeConversion3 <
             QD2_DroneStack_Manual_2021a_P.MaximumCommandAuthority_LowerSa[0]) {
    /* Saturate: '<S2>/Maximum  Command Authority ' */
    QD2_DroneStack_Manual_2021a_B.MaximumCommandAuthority[0] =
      QD2_DroneStack_Manual_2021a_P.MaximumCommandAuthority_LowerSa[0];
  } else {
    /* Saturate: '<S2>/Maximum  Command Authority ' */
    QD2_DroneStack_Manual_2021a_B.MaximumCommandAuthority[0] =
      rtb_DataTypeConversion3;
  }

  /* ManualSwitch: '<S2>/Manual Switch -   Select Command Input' incorporates:
   *  Constant: '<Root>/Zero Reference Motor Commands'
   *  Constant: '<S2>/Constant3'
   *  MATLAB Function: '<S2>/Force to percentage Mapping'
   */
  if (QD2_DroneStack_Manual_2021a_P.ManualSwitchSelectCommandInput_ == 1) {
    rtb_DataTypeConversion3 = (-0.5 * QD2_DroneStack_Manual_2021a_P.KT[1] /
      QD2_DroneStack_Manual_2021a_P.KT[0] + sqrt(Duty_Cycle[1]) / (2.0 *
      QD2_DroneStack_Manual_2021a_P.KT[0])) /
      QD2_DroneStack_Manual_2021a_B.HILRead_o1[0];
  } else {
    rtb_DataTypeConversion3 =
      QD2_DroneStack_Manual_2021a_P.ZeroReferenceMotorCommands_Valu[1];
  }

  /* Saturate: '<S2>/Maximum  Command Authority ' incorporates:
   *  ManualSwitch: '<S2>/Manual Switch -   Select Command Input'
   */
  if (rtb_DataTypeConversion3 >
      QD2_DroneStack_Manual_2021a_P.MaximumCommandAuthority_UpperSa[1]) {
    /* Saturate: '<S2>/Maximum  Command Authority ' */
    QD2_DroneStack_Manual_2021a_B.MaximumCommandAuthority[1] =
      QD2_DroneStack_Manual_2021a_P.MaximumCommandAuthority_UpperSa[1];
  } else if (rtb_DataTypeConversion3 <
             QD2_DroneStack_Manual_2021a_P.MaximumCommandAuthority_LowerSa[1]) {
    /* Saturate: '<S2>/Maximum  Command Authority ' */
    QD2_DroneStack_Manual_2021a_B.MaximumCommandAuthority[1] =
      QD2_DroneStack_Manual_2021a_P.MaximumCommandAuthority_LowerSa[1];
  } else {
    /* Saturate: '<S2>/Maximum  Command Authority ' */
    QD2_DroneStack_Manual_2021a_B.MaximumCommandAuthority[1] =
      rtb_DataTypeConversion3;
  }

  /* ManualSwitch: '<S2>/Manual Switch -   Select Command Input' incorporates:
   *  Constant: '<Root>/Zero Reference Motor Commands'
   *  Constant: '<S2>/Constant3'
   *  MATLAB Function: '<S2>/Force to percentage Mapping'
   */
  if (QD2_DroneStack_Manual_2021a_P.ManualSwitchSelectCommandInput_ == 1) {
    rtb_DataTypeConversion3 = (-0.5 * QD2_DroneStack_Manual_2021a_P.KT[1] /
      QD2_DroneStack_Manual_2021a_P.KT[0] + sqrt(Duty_Cycle[2]) / (2.0 *
      QD2_DroneStack_Manual_2021a_P.KT[0])) /
      QD2_DroneStack_Manual_2021a_B.HILRead_o1[0];
  } else {
    rtb_DataTypeConversion3 =
      QD2_DroneStack_Manual_2021a_P.ZeroReferenceMotorCommands_Valu[2];
  }

  /* Saturate: '<S2>/Maximum  Command Authority ' incorporates:
   *  ManualSwitch: '<S2>/Manual Switch -   Select Command Input'
   */
  if (rtb_DataTypeConversion3 >
      QD2_DroneStack_Manual_2021a_P.MaximumCommandAuthority_UpperSa[2]) {
    /* Saturate: '<S2>/Maximum  Command Authority ' */
    QD2_DroneStack_Manual_2021a_B.MaximumCommandAuthority[2] =
      QD2_DroneStack_Manual_2021a_P.MaximumCommandAuthority_UpperSa[2];
  } else if (rtb_DataTypeConversion3 <
             QD2_DroneStack_Manual_2021a_P.MaximumCommandAuthority_LowerSa[2]) {
    /* Saturate: '<S2>/Maximum  Command Authority ' */
    QD2_DroneStack_Manual_2021a_B.MaximumCommandAuthority[2] =
      QD2_DroneStack_Manual_2021a_P.MaximumCommandAuthority_LowerSa[2];
  } else {
    /* Saturate: '<S2>/Maximum  Command Authority ' */
    QD2_DroneStack_Manual_2021a_B.MaximumCommandAuthority[2] =
      rtb_DataTypeConversion3;
  }

  /* ManualSwitch: '<S2>/Manual Switch -   Select Command Input' incorporates:
   *  Constant: '<Root>/Zero Reference Motor Commands'
   *  Constant: '<S2>/Constant3'
   *  MATLAB Function: '<S2>/Force to percentage Mapping'
   */
  if (QD2_DroneStack_Manual_2021a_P.ManualSwitchSelectCommandInput_ == 1) {
    rtb_DataTypeConversion3 = (-0.5 * QD2_DroneStack_Manual_2021a_P.KT[1] /
      QD2_DroneStack_Manual_2021a_P.KT[0] + sqrt(Duty_Cycle[3]) / (2.0 *
      QD2_DroneStack_Manual_2021a_P.KT[0])) /
      QD2_DroneStack_Manual_2021a_B.HILRead_o1[0];
  } else {
    rtb_DataTypeConversion3 =
      QD2_DroneStack_Manual_2021a_P.ZeroReferenceMotorCommands_Valu[3];
  }

  /* Saturate: '<S2>/Maximum  Command Authority ' incorporates:
   *  ManualSwitch: '<S2>/Manual Switch -   Select Command Input'
   */
  if (rtb_DataTypeConversion3 >
      QD2_DroneStack_Manual_2021a_P.MaximumCommandAuthority_UpperSa[3]) {
    /* Saturate: '<S2>/Maximum  Command Authority ' */
    QD2_DroneStack_Manual_2021a_B.MaximumCommandAuthority[3] =
      QD2_DroneStack_Manual_2021a_P.MaximumCommandAuthority_UpperSa[3];
  } else if (rtb_DataTypeConversion3 <
             QD2_DroneStack_Manual_2021a_P.MaximumCommandAuthority_LowerSa[3]) {
    /* Saturate: '<S2>/Maximum  Command Authority ' */
    QD2_DroneStack_Manual_2021a_B.MaximumCommandAuthority[3] =
      QD2_DroneStack_Manual_2021a_P.MaximumCommandAuthority_LowerSa[3];
  } else {
    /* Saturate: '<S2>/Maximum  Command Authority ' */
    QD2_DroneStack_Manual_2021a_B.MaximumCommandAuthority[3] =
      rtb_DataTypeConversion3;
  }

  if (rtb_Relation) {
    /* MATLAB Function: '<S10>/MATLAB Function' incorporates:
     *  Constant: '<S10>/Constant2'
     */
    QD2_DroneStack_Manual_2021a_DW.sfEvent_b = QD2_DroneStack_Manua_CALL_EVENT;

    /* MATLAB Function 'QDrone 2 DAQ/Choose Motor Telemetry/MATLAB Function': '<S32>:1' */
    /* '<S32>:1:11' */
    rtb_DataTypeConversion3 = QD2_DroneStack_Manual_2021a_DW.state;
    if (QD2_DroneStack_Manual_2021a_B.tele_enable != 0.0) {
      /* '<S32>:1:15' */
      QD2_DroneStack_Manual_2021a_DW.state++;
      if (QD2_DroneStack_Manual_2021a_DW.state >=
          QD2_DroneStack_Manual_2021a_P.Constant2_Value) {
        /* '<S32>:1:17' */
        /* '<S32>:1:18' */
        QD2_DroneStack_Manual_2021a_DW.state = 0.0;
      }
    } else {
      /* '<S32>:1:22' */
      QD2_DroneStack_Manual_2021a_DW.state = 0.0;

      /* '<S32>:1:23' */
      rtb_DataTypeConversion3 = 0.0;
    }

    /* End of MATLAB Function: '<S10>/MATLAB Function' */

    /* Selector: '<S10>/Selector' incorporates:
     *  Constant: '<S10>/Constant1'
     */
    QD2_DroneStack_Manual_2021a_B.Selector[0] =
      QD2_DroneStack_Manual_2021a_P.Constant1_Value_f[(int32_T)
      rtb_DataTypeConversion3];

    /* DataTypeConversion: '<S2>/Data Type Conversion1' */
    tmp_3 = floor(QD2_DroneStack_Manual_2021a_B.cmd[0]);
    if (rtIsNaN(tmp_3) || rtIsInf(tmp_3)) {
      tmp_3 = 0.0;
    } else {
      tmp_3 = fmod(tmp_3, 65536.0);
    }

    rtb_DataTypeConversion1[0] = (uint16_T)(tmp_3 < 0.0 ? (int32_T)(uint16_T)
      -(int16_T)(uint16_T)-tmp_3 : (int32_T)(uint16_T)tmp_3);

    /* Selector: '<S10>/Selector' incorporates:
     *  Constant: '<S10>/Constant1'
     */
    QD2_DroneStack_Manual_2021a_B.Selector[1] =
      QD2_DroneStack_Manual_2021a_P.Constant1_Value_f[(int32_T)
      rtb_DataTypeConversion3 + 8];

    /* DataTypeConversion: '<S2>/Data Type Conversion1' */
    tmp_3 = floor(QD2_DroneStack_Manual_2021a_B.cmd[1]);
    if (rtIsNaN(tmp_3) || rtIsInf(tmp_3)) {
      tmp_3 = 0.0;
    } else {
      tmp_3 = fmod(tmp_3, 65536.0);
    }

    rtb_DataTypeConversion1[1] = (uint16_T)(tmp_3 < 0.0 ? (int32_T)(uint16_T)
      -(int16_T)(uint16_T)-tmp_3 : (int32_T)(uint16_T)tmp_3);

    /* Selector: '<S10>/Selector' incorporates:
     *  Constant: '<S10>/Constant1'
     */
    QD2_DroneStack_Manual_2021a_B.Selector[2] =
      QD2_DroneStack_Manual_2021a_P.Constant1_Value_f[(int32_T)
      rtb_DataTypeConversion3 + 16];

    /* DataTypeConversion: '<S2>/Data Type Conversion1' */
    tmp_3 = floor(QD2_DroneStack_Manual_2021a_B.cmd[2]);
    if (rtIsNaN(tmp_3) || rtIsInf(tmp_3)) {
      tmp_3 = 0.0;
    } else {
      tmp_3 = fmod(tmp_3, 65536.0);
    }

    rtb_DataTypeConversion1[2] = (uint16_T)(tmp_3 < 0.0 ? (int32_T)(uint16_T)
      -(int16_T)(uint16_T)-tmp_3 : (int32_T)(uint16_T)tmp_3);

    /* Selector: '<S10>/Selector' incorporates:
     *  Constant: '<S10>/Constant1'
     */
    QD2_DroneStack_Manual_2021a_B.Selector[3] =
      QD2_DroneStack_Manual_2021a_P.Constant1_Value_f[(int32_T)
      rtb_DataTypeConversion3 + 24];

    /* DataTypeConversion: '<S2>/Data Type Conversion1' */
    tmp_3 = floor(QD2_DroneStack_Manual_2021a_B.cmd[3]);
    if (rtIsNaN(tmp_3) || rtIsInf(tmp_3)) {
      tmp_3 = 0.0;
    } else {
      tmp_3 = fmod(tmp_3, 65536.0);
    }

    rtb_DataTypeConversion1[3] = (uint16_T)(tmp_3 < 0.0 ? (int32_T)(uint16_T)
      -(int16_T)(uint16_T)-tmp_3 : (int32_T)(uint16_T)tmp_3);

    /* S-Function (esc_output_block): '<S2>/ESC Output' */

    /* S-Function Block: QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/ESC Output (esc_output_block) */
    {
      t_double saturated_input;
      t_uint16 throttle;
      t_uint16 checksum;
      saturated_input = QD2_DroneStack_Manual_2021a_B.MaximumCommandAuthority[0];
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

      throttle = (throttle << 1) | (QD2_DroneStack_Manual_2021a_B.Selector[0] !=
        0);
      checksum = throttle ^ (throttle >> 4) ^ (throttle >> 8);
      rtb_ESCOutput[0] = (throttle << 4) | (checksum & 0x0f);
      saturated_input = QD2_DroneStack_Manual_2021a_B.MaximumCommandAuthority[1];
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

      throttle = (throttle << 1) | (QD2_DroneStack_Manual_2021a_B.Selector[1] !=
        0);
      checksum = throttle ^ (throttle >> 4) ^ (throttle >> 8);
      rtb_ESCOutput[1] = (throttle << 4) | (checksum & 0x0f);
      saturated_input = QD2_DroneStack_Manual_2021a_B.MaximumCommandAuthority[2];
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

      throttle = (throttle << 1) | (QD2_DroneStack_Manual_2021a_B.Selector[2] !=
        0);
      checksum = throttle ^ (throttle >> 4) ^ (throttle >> 8);
      rtb_ESCOutput[2] = (throttle << 4) | (checksum & 0x0f);
      saturated_input = QD2_DroneStack_Manual_2021a_B.MaximumCommandAuthority[3];
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

      throttle = (throttle << 1) | (QD2_DroneStack_Manual_2021a_B.Selector[3] !=
        0);
      checksum = throttle ^ (throttle >> 4) ^ (throttle >> 8);
      rtb_ESCOutput[3] = (throttle << 4) | (checksum & 0x0f);
    }

    /* Outputs for Enabled SubSystem: '<S2>/Enabled Subsystem -  Write ESC Commands' incorporates:
     *  EnablePort: '<S19>/Enable'
     */
    if (QD2_DroneStack_Manual_2021a_B.cmd_enable > 0.0) {
      /* S-Function (hil_write_pwm_block): '<S19>/HIL Write PWM' */

      /* S-Function Block: QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Enabled Subsystem -  Write ESC Commands/HIL Write PWM (hil_write_pwm_block) */
      {
        t_error result;
        result = hil_write_pwm(QD2_DroneStack_Manual_2021a_DW.HILInitialize_Card,
          QD2_DroneStack_Manual_2021a_P.HILWritePWM_channels, 4, &rtb_ESCOutput
          [0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(QD2_DroneStack_Manual_2021a_M, _rt_error_message);
        }
      }

      if (rtsiIsModeUpdateTimeStep(&QD2_DroneStack_Manual_2021a_M->solverInfo))
      {
        srUpdateBC
          (QD2_DroneStack_Manual_2021a_DW.EnabledSubsystemWriteESCCommand);
      }
    }

    /* End of Outputs for SubSystem: '<S2>/Enabled Subsystem -  Write ESC Commands' */

    /* MultiPortSwitch: '<S21>/Multiport Switch' incorporates:
     *  Constant: '<S21>/Blue Blue'
     *  Constant: '<S21>/Green Green'
     *  Constant: '<S21>/LED OFF'
     *  Constant: '<S21>/Red Blue'
     *  Constant: '<S21>/Red Red'
     *  Constant: '<S21>/Red Yellow'
     *  Constant: '<S21>/Yellow Blue'
     *  Constant: '<S21>/Yellow Green'
     *  Constant: '<S21>/Yellow Red'
     *  Constant: '<S21>/Yellow Yellow'
     */
    for (firstBlockLength = 0; firstBlockLength < 6; firstBlockLength++) {
      switch (QD2_DroneStack_Manual_2021a_B.DataTypeConversion_ko) {
       case 0:
        rtb_MultiportSwitch[firstBlockLength] =
          QD2_DroneStack_Manual_2021a_P.YellowYellow_Value[firstBlockLength];
        break;

       case 1:
        rtb_MultiportSwitch[firstBlockLength] =
          QD2_DroneStack_Manual_2021a_P.YellowGreen_Value[firstBlockLength];
        break;

       case 2:
        rtb_MultiportSwitch[firstBlockLength] =
          QD2_DroneStack_Manual_2021a_P.BlueBlue_Value[firstBlockLength];
        break;

       case 3:
        rtb_MultiportSwitch[firstBlockLength] =
          QD2_DroneStack_Manual_2021a_P.YellowRed_Value[firstBlockLength];
        break;

       case 4:
        rtb_MultiportSwitch[firstBlockLength] =
          QD2_DroneStack_Manual_2021a_P.RedYellow_Value[firstBlockLength];
        break;

       case 5:
        rtb_MultiportSwitch[firstBlockLength] =
          QD2_DroneStack_Manual_2021a_P.GreenGreen_Value[firstBlockLength];
        break;

       case 77:
        rtb_MultiportSwitch[firstBlockLength] =
          QD2_DroneStack_Manual_2021a_P.YellowBlue_Value[firstBlockLength];
        break;

       case 88:
        rtb_MultiportSwitch[firstBlockLength] =
          QD2_DroneStack_Manual_2021a_P.RedBlue_Value[firstBlockLength];
        break;

       case 99:
        rtb_MultiportSwitch[firstBlockLength] =
          QD2_DroneStack_Manual_2021a_P.RedRed_Value[firstBlockLength];
        break;

       default:
        rtb_MultiportSwitch[firstBlockLength] =
          QD2_DroneStack_Manual_2021a_P.LEDOFF_Value[firstBlockLength];
        break;
      }
    }

    /* End of MultiPortSwitch: '<S21>/Multiport Switch' */

    /* S-Function (hil_write_digital_block): '<S2>/HIL Write Digital' */

    /* S-Function Block: QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/HIL Write Digital (hil_write_digital_block) */
    {
      t_error result;

      {
        int_T i1;
        const real_T *u0 = &rtb_MultiportSwitch[0];
        t_boolean *dw_Buffer =
          &QD2_DroneStack_Manual_2021a_DW.HILWriteDigital_Buffer[0];
        for (i1=0; i1 < 6; i1++) {
          dw_Buffer[i1] = (u0[i1] != 0);
        }
      }

      result = hil_write_digital
        (QD2_DroneStack_Manual_2021a_DW.HILInitialize_Card,
         QD2_DroneStack_Manual_2021a_P.HILWriteDigital_channels, 6,
         &QD2_DroneStack_Manual_2021a_DW.HILWriteDigital_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QD2_DroneStack_Manual_2021a_M, _rt_error_message);
      }
    }

    /* RateTransition: '<S2>/Rate Transition7' */
    if (QD2_DroneStack_Manual_2021a_M->Timing.RateInteraction.TID1_3) {
      /* RateTransition: '<S2>/Rate Transition7' */
      QD2_DroneStack_Manual_2021a_B.RateTransition7[0] =
        QD2_DroneStack_Manual_2021a_DW.RateTransition7_Buffer0[0];
      QD2_DroneStack_Manual_2021a_B.RateTransition7[1] =
        QD2_DroneStack_Manual_2021a_DW.RateTransition7_Buffer0[1];
    }

    /* End of RateTransition: '<S2>/Rate Transition7' */

    /* RateTransition: '<S2>/Rate Transition2' incorporates:
     *  RateTransition: '<S2>/Rate Transition1'
     */
    if (QD2_DroneStack_Manual_2021a_M->Timing.RateInteraction.TID1_4) {
      /* RateTransition: '<S2>/Rate Transition2' */
      QD2_DroneStack_Manual_2021a_B.RateTransition2 =
        QD2_DroneStack_Manual_2021a_DW.RateTransition2_Buffer0;

      /* RateTransition: '<S2>/Rate Transition1' */
      QD2_DroneStack_Manual_2021a_B.RateTransition1 =
        QD2_DroneStack_Manual_2021a_DW.RateTransition1_Buffer0;
    }

    /* End of RateTransition: '<S2>/Rate Transition2' */

    /* Gain: '<S2>/Divide by half of the number of poles in motor' */
    rtb_DataTypeConversion3 =
      QD2_DroneStack_Manual_2021a_P.Dividebyhalfofthenumberofpolesi *
      QD2_DroneStack_Manual_2021a_B.HILRead_o2[19];

    /* Gain: '<S2>/Multiple by resolution (supposed to be 100 RPM)' */
    rtb_DataTypeConversion3 *=
      QD2_DroneStack_Manual_2021a_P.Multiplebyresolutionsupposedtob;

    /* MultiPortSwitch: '<S2>/Extract ESC Channels' */
    switch ((int32_T)QD2_DroneStack_Manual_2021a_B.HILRead_o2[21]) {
     case 0:
      /* MultiPortSwitch: '<S2>/Extract ESC Channels' incorporates:
       *  Constant: '<S2>/Motor 0'
       */
      QD2_DroneStack_Manual_2021a_B.ExtractESCChannels[0] =
        QD2_DroneStack_Manual_2021a_P.Motor0_Value[0];
      QD2_DroneStack_Manual_2021a_B.ExtractESCChannels[1] =
        QD2_DroneStack_Manual_2021a_P.Motor0_Value[1];
      QD2_DroneStack_Manual_2021a_B.ExtractESCChannels[2] =
        QD2_DroneStack_Manual_2021a_P.Motor0_Value[2];
      QD2_DroneStack_Manual_2021a_B.ExtractESCChannels[3] =
        QD2_DroneStack_Manual_2021a_P.Motor0_Value[3];
      break;

     case 1:
      /* MultiPortSwitch: '<S2>/Extract ESC Channels' incorporates:
       *  Constant: '<S2>/Motor 1'
       */
      QD2_DroneStack_Manual_2021a_B.ExtractESCChannels[0] =
        QD2_DroneStack_Manual_2021a_P.Motor1_Value[0];
      QD2_DroneStack_Manual_2021a_B.ExtractESCChannels[1] =
        QD2_DroneStack_Manual_2021a_P.Motor1_Value[1];
      QD2_DroneStack_Manual_2021a_B.ExtractESCChannels[2] =
        QD2_DroneStack_Manual_2021a_P.Motor1_Value[2];
      QD2_DroneStack_Manual_2021a_B.ExtractESCChannels[3] =
        QD2_DroneStack_Manual_2021a_P.Motor1_Value[3];
      break;

     case 2:
      /* MultiPortSwitch: '<S2>/Extract ESC Channels' incorporates:
       *  Constant: '<S2>/Motor 2'
       */
      QD2_DroneStack_Manual_2021a_B.ExtractESCChannels[0] =
        QD2_DroneStack_Manual_2021a_P.Motor2_Value[0];
      QD2_DroneStack_Manual_2021a_B.ExtractESCChannels[1] =
        QD2_DroneStack_Manual_2021a_P.Motor2_Value[1];
      QD2_DroneStack_Manual_2021a_B.ExtractESCChannels[2] =
        QD2_DroneStack_Manual_2021a_P.Motor2_Value[2];
      QD2_DroneStack_Manual_2021a_B.ExtractESCChannels[3] =
        QD2_DroneStack_Manual_2021a_P.Motor2_Value[3];
      break;

     case 3:
      /* MultiPortSwitch: '<S2>/Extract ESC Channels' incorporates:
       *  Constant: '<S2>/Motor 3'
       */
      QD2_DroneStack_Manual_2021a_B.ExtractESCChannels[0] =
        QD2_DroneStack_Manual_2021a_P.Motor3_Value[0];
      QD2_DroneStack_Manual_2021a_B.ExtractESCChannels[1] =
        QD2_DroneStack_Manual_2021a_P.Motor3_Value[1];
      QD2_DroneStack_Manual_2021a_B.ExtractESCChannels[2] =
        QD2_DroneStack_Manual_2021a_P.Motor3_Value[2];
      QD2_DroneStack_Manual_2021a_B.ExtractESCChannels[3] =
        QD2_DroneStack_Manual_2021a_P.Motor3_Value[3];
      break;

     default:
      /* MultiPortSwitch: '<S2>/Extract ESC Channels' incorporates:
       *  Constant: '<S2>/No selection'
       */
      QD2_DroneStack_Manual_2021a_B.ExtractESCChannels[0] =
        QD2_DroneStack_Manual_2021a_P.Noselection_Value[0];
      QD2_DroneStack_Manual_2021a_B.ExtractESCChannels[1] =
        QD2_DroneStack_Manual_2021a_P.Noselection_Value[1];
      QD2_DroneStack_Manual_2021a_B.ExtractESCChannels[2] =
        QD2_DroneStack_Manual_2021a_P.Noselection_Value[2];
      QD2_DroneStack_Manual_2021a_B.ExtractESCChannels[3] =
        QD2_DroneStack_Manual_2021a_P.Noselection_Value[3];
      break;
    }

    /* End of MultiPortSwitch: '<S2>/Extract ESC Channels' */

    /* Product: '<S2>/Product' */
    rtb_Product[0] = rtb_DataTypeConversion3 *
      QD2_DroneStack_Manual_2021a_B.ExtractESCChannels[0];

    /* Memory: '<S13>/Memory' */
    rtb_Memory_g[0] = QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput_h[0];

    /* Product: '<S2>/Product' */
    rtb_Product[1] = rtb_DataTypeConversion3 *
      QD2_DroneStack_Manual_2021a_B.ExtractESCChannels[1];

    /* Memory: '<S13>/Memory' */
    rtb_Memory_g[1] = QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput_h[1];

    /* Product: '<S2>/Product' */
    rtb_Product[2] = rtb_DataTypeConversion3 *
      QD2_DroneStack_Manual_2021a_B.ExtractESCChannels[2];

    /* Memory: '<S13>/Memory' */
    rtb_Memory_g[2] = QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput_h[2];

    /* Product: '<S2>/Product' */
    rtb_Product[3] = rtb_DataTypeConversion3 *
      QD2_DroneStack_Manual_2021a_B.ExtractESCChannels[3];

    /* Memory: '<S13>/Memory' */
    rtb_Memory_g[3] = QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput_h[3];

    /* Outputs for Iterator SubSystem: '<S13>/For Each Subsystem -  Construct ESC Signal' */
    ForEachSubsystemConstructES(4, rtb_Product,
      QD2_DroneStack_Manual_2021a_B.HILRead_o2[21], rtb_Memory_g,
      QD2_DroneStack_Manual_2021a_B.ImpAsg_InsertedFor_ESCDataOu_kc);

    /* End of Outputs for SubSystem: '<S13>/For Each Subsystem -  Construct ESC Signal' */

    /* Saturate: '<S2>/Saturation' */
    if (QD2_DroneStack_Manual_2021a_B.HILRead_o2[20] >
        QD2_DroneStack_Manual_2021a_P.Saturation_UpperSat) {
      rtb_DataTypeConversion3 =
        QD2_DroneStack_Manual_2021a_P.Saturation_UpperSat;
    } else if (QD2_DroneStack_Manual_2021a_B.HILRead_o2[20] <
               QD2_DroneStack_Manual_2021a_P.Saturation_LowerSat) {
      rtb_DataTypeConversion3 =
        QD2_DroneStack_Manual_2021a_P.Saturation_LowerSat;
    } else {
      rtb_DataTypeConversion3 = QD2_DroneStack_Manual_2021a_B.HILRead_o2[20];
    }

    /* End of Saturate: '<S2>/Saturation' */

    /* Product: '<S2>/Product1' */
    rtb_Product1[0] = rtb_DataTypeConversion3 *
      QD2_DroneStack_Manual_2021a_B.ExtractESCChannels[0];

    /* Memory: '<S15>/Memory' */
    rtb_Memory_f[0] = QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput_k[0];

    /* Product: '<S2>/Product1' */
    rtb_Product1[1] = rtb_DataTypeConversion3 *
      QD2_DroneStack_Manual_2021a_B.ExtractESCChannels[1];

    /* Memory: '<S15>/Memory' */
    rtb_Memory_f[1] = QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput_k[1];

    /* Product: '<S2>/Product1' */
    rtb_Product1[2] = rtb_DataTypeConversion3 *
      QD2_DroneStack_Manual_2021a_B.ExtractESCChannels[2];

    /* Memory: '<S15>/Memory' */
    rtb_Memory_f[2] = QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput_k[2];

    /* Product: '<S2>/Product1' */
    rtb_Product1[3] = rtb_DataTypeConversion3 *
      QD2_DroneStack_Manual_2021a_B.ExtractESCChannels[3];

    /* Memory: '<S15>/Memory' */
    rtb_Memory_f[3] = QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput_k[3];

    /* Outputs for Iterator SubSystem: '<S15>/For Each Subsystem -  Construct ESC Signal' */
    ForEachSubsystemConstructES(4, rtb_Product1,
      QD2_DroneStack_Manual_2021a_B.HILRead_o2[21], rtb_Memory_f,
      QD2_DroneStack_Manual_2021a_B.ImpAsg_InsertedFor_ESCDataOut4_);

    /* End of Outputs for SubSystem: '<S15>/For Each Subsystem -  Construct ESC Signal' */

    /* S-Function (computation_time_block): '<S27>/Computation Time' */

    /* S-Function Block: QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Timing Monitors/Computation Time (computation_time_block) */
    {
      QD2_DroneStack_Manual_2021a_B.ComputationTime =
        QD2_DroneStack_Manual_2021a_DW.ComputationTime_ComputationTime.seconds +
        QD2_DroneStack_Manual_2021a_DW.ComputationTime_ComputationTime.nanoseconds
        * 1e-9;
    }

    /* S-Function (sample_time_block): '<S27>/Sample Time' */

    /* S-Function Block: QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Timing Monitors/Sample Time (sample_time_block) */
    {
      t_error result;
      t_timeout current_time;
      t_timeout time_difference;
      result = timeout_get_high_resolution_time(&current_time);
      if (result >= 0) {
        result = timeout_subtract(&time_difference, &current_time,
          &QD2_DroneStack_Manual_2021a_DW.SampleTime_PreviousTime);
        QD2_DroneStack_Manual_2021a_B.SampleTime = time_difference.seconds +
          time_difference.nanoseconds * 1e-9;
        memcpy(&QD2_DroneStack_Manual_2021a_DW.SampleTime_PreviousTime,
               &current_time, sizeof(t_timeout));
      }

      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QD2_DroneStack_Manual_2021a_M, _rt_error_message);
        return;
      }
    }

    /* RateTransition: '<S27>/Rate Transition' incorporates:
     *  RateTransition: '<S27>/Rate Transition1'
     */
    if (QD2_DroneStack_Manual_2021a_M->Timing.RateInteraction.TID1_3) {
      /* RateTransition: '<S27>/Rate Transition' */
      QD2_DroneStack_Manual_2021a_B.RateTransition =
        QD2_DroneStack_Manual_2021a_DW.RateTransition_Buffer0;

      /* RateTransition: '<S27>/Rate Transition1' */
      QD2_DroneStack_Manual_2021a_B.RateTransition1_d =
        QD2_DroneStack_Manual_2021a_DW.RateTransition1_Buffer0_l;
    }

    /* End of RateTransition: '<S27>/Rate Transition' */

    /* RateTransition: '<S27>/Rate Transition2' incorporates:
     *  RateTransition: '<S27>/Rate Transition3'
     */
    if (QD2_DroneStack_Manual_2021a_M->Timing.RateInteraction.TID1_4) {
      /* RateTransition: '<S27>/Rate Transition2' */
      QD2_DroneStack_Manual_2021a_B.RateTransition2_f =
        QD2_DroneStack_Manual_2021a_DW.RateTransition2_Buffer0_l;

      /* RateTransition: '<S27>/Rate Transition3' */
      QD2_DroneStack_Manual_2021a_B.RateTransition3 =
        QD2_DroneStack_Manual_2021a_DW.RateTransition3_Buffer0;
    }

    /* End of RateTransition: '<S27>/Rate Transition2' */

    /* RateTransition: '<S2>/Rate Transition6' */
    memcpy(&QD2_DroneStack_Manual_2021a_B.RateTransition6[0],
           &QD2_DroneStack_Manual_2021a_B.SelectDataforIMU0[0], 9U * sizeof
           (real_T));
    memcpy(&QD2_DroneStack_Manual_2021a_B.RateTransition6[9],
           &QD2_DroneStack_Manual_2021a_B.SelectDataforIMU1[0], 9U * sizeof
           (real_T));
    QD2_DroneStack_Manual_2021a_B.RateTransition6[18] =
      QD2_DroneStack_Manual_2021a_B.MaximumCommandAuthority[0];
    QD2_DroneStack_Manual_2021a_B.RateTransition6[19] =
      QD2_DroneStack_Manual_2021a_B.MaximumCommandAuthority[1];
    QD2_DroneStack_Manual_2021a_B.RateTransition6[20] =
      QD2_DroneStack_Manual_2021a_B.MaximumCommandAuthority[2];
    QD2_DroneStack_Manual_2021a_B.RateTransition6[21] =
      QD2_DroneStack_Manual_2021a_B.MaximumCommandAuthority[3];
    QD2_DroneStack_Manual_2021a_B.RateTransition6[22] =
      QD2_DroneStack_Manual_2021a_B.HILRead_o1[0];
    QD2_DroneStack_Manual_2021a_B.RateTransition6[23] =
      QD2_DroneStack_Manual_2021a_B.HILRead_o1[1];
    QD2_DroneStack_Manual_2021a_B.RateTransition6[24] =
      QD2_DroneStack_Manual_2021a_B.HILRead_o1[2];
    memcpy(&QD2_DroneStack_Manual_2021a_B.RateTransition6[25],
           &QD2_DroneStack_Manual_2021a_B.HILRead_o2[0], 12U * sizeof(real_T));
    QD2_DroneStack_Manual_2021a_B.RateTransition6[37] =
      QD2_DroneStack_Manual_2021a_B.RateTransition7[0];
    QD2_DroneStack_Manual_2021a_B.RateTransition6[38] =
      QD2_DroneStack_Manual_2021a_B.RateTransition7[1];
    for (firstBlockLength = 0; firstBlockLength < 7; firstBlockLength++) {
      QD2_DroneStack_Manual_2021a_B.RateTransition6[firstBlockLength + 39] =
        QD2_DroneStack_Manual_2021a_B.HILRead_o2[firstBlockLength + 12];
    }

    QD2_DroneStack_Manual_2021a_B.RateTransition6[46] =
      QD2_DroneStack_Manual_2021a_B.RateTransition2;
    QD2_DroneStack_Manual_2021a_B.RateTransition6[47] =
      QD2_DroneStack_Manual_2021a_B.RateTransition1;

    /* Product: '<S2>/Divide' incorporates:
     *  Gain: '<S2>/Convert to equivalent voltage (based on motor Kv rating)'
     */
    rtb_DataTypeConversion3 =
      QD2_DroneStack_Manual_2021a_P.Converttoequivalentvoltagebased *
      QD2_DroneStack_Manual_2021a_B.ImpAsg_InsertedFor_ESCDataOu_kc[0] /
      QD2_DroneStack_Manual_2021a_B.ImpAsg_InsertedFor_ESCDataOut4_[0];

    /* Saturate: '<S2>/Saturation1' */
    if (rtb_DataTypeConversion3 >
        QD2_DroneStack_Manual_2021a_P.Saturation1_UpperSat) {
      /* RateTransition: '<S2>/Rate Transition6' */
      QD2_DroneStack_Manual_2021a_B.RateTransition6[48] =
        QD2_DroneStack_Manual_2021a_P.Saturation1_UpperSat;
    } else if (rtb_DataTypeConversion3 <
               QD2_DroneStack_Manual_2021a_P.Saturation1_LowerSat) {
      /* RateTransition: '<S2>/Rate Transition6' */
      QD2_DroneStack_Manual_2021a_B.RateTransition6[48] =
        QD2_DroneStack_Manual_2021a_P.Saturation1_LowerSat;
    } else {
      /* RateTransition: '<S2>/Rate Transition6' */
      QD2_DroneStack_Manual_2021a_B.RateTransition6[48] =
        rtb_DataTypeConversion3;
    }

    /* Product: '<S2>/Divide' incorporates:
     *  Gain: '<S2>/Convert to equivalent voltage (based on motor Kv rating)'
     */
    rtb_DataTypeConversion3 =
      QD2_DroneStack_Manual_2021a_P.Converttoequivalentvoltagebased *
      QD2_DroneStack_Manual_2021a_B.ImpAsg_InsertedFor_ESCDataOu_kc[1] /
      QD2_DroneStack_Manual_2021a_B.ImpAsg_InsertedFor_ESCDataOut4_[1];

    /* Saturate: '<S2>/Saturation1' */
    if (rtb_DataTypeConversion3 >
        QD2_DroneStack_Manual_2021a_P.Saturation1_UpperSat) {
      /* RateTransition: '<S2>/Rate Transition6' */
      QD2_DroneStack_Manual_2021a_B.RateTransition6[49] =
        QD2_DroneStack_Manual_2021a_P.Saturation1_UpperSat;
    } else if (rtb_DataTypeConversion3 <
               QD2_DroneStack_Manual_2021a_P.Saturation1_LowerSat) {
      /* RateTransition: '<S2>/Rate Transition6' */
      QD2_DroneStack_Manual_2021a_B.RateTransition6[49] =
        QD2_DroneStack_Manual_2021a_P.Saturation1_LowerSat;
    } else {
      /* RateTransition: '<S2>/Rate Transition6' */
      QD2_DroneStack_Manual_2021a_B.RateTransition6[49] =
        rtb_DataTypeConversion3;
    }

    /* Product: '<S2>/Divide' incorporates:
     *  Gain: '<S2>/Convert to equivalent voltage (based on motor Kv rating)'
     */
    rtb_DataTypeConversion3 =
      QD2_DroneStack_Manual_2021a_P.Converttoequivalentvoltagebased *
      QD2_DroneStack_Manual_2021a_B.ImpAsg_InsertedFor_ESCDataOu_kc[2] /
      QD2_DroneStack_Manual_2021a_B.ImpAsg_InsertedFor_ESCDataOut4_[2];

    /* Saturate: '<S2>/Saturation1' */
    if (rtb_DataTypeConversion3 >
        QD2_DroneStack_Manual_2021a_P.Saturation1_UpperSat) {
      /* RateTransition: '<S2>/Rate Transition6' */
      QD2_DroneStack_Manual_2021a_B.RateTransition6[50] =
        QD2_DroneStack_Manual_2021a_P.Saturation1_UpperSat;
    } else if (rtb_DataTypeConversion3 <
               QD2_DroneStack_Manual_2021a_P.Saturation1_LowerSat) {
      /* RateTransition: '<S2>/Rate Transition6' */
      QD2_DroneStack_Manual_2021a_B.RateTransition6[50] =
        QD2_DroneStack_Manual_2021a_P.Saturation1_LowerSat;
    } else {
      /* RateTransition: '<S2>/Rate Transition6' */
      QD2_DroneStack_Manual_2021a_B.RateTransition6[50] =
        rtb_DataTypeConversion3;
    }

    /* Product: '<S2>/Divide' incorporates:
     *  Gain: '<S2>/Convert to equivalent voltage (based on motor Kv rating)'
     */
    rtb_DataTypeConversion3 =
      QD2_DroneStack_Manual_2021a_P.Converttoequivalentvoltagebased *
      QD2_DroneStack_Manual_2021a_B.ImpAsg_InsertedFor_ESCDataOu_kc[3] /
      QD2_DroneStack_Manual_2021a_B.ImpAsg_InsertedFor_ESCDataOut4_[3];

    /* Saturate: '<S2>/Saturation1' */
    if (rtb_DataTypeConversion3 >
        QD2_DroneStack_Manual_2021a_P.Saturation1_UpperSat) {
      /* RateTransition: '<S2>/Rate Transition6' */
      QD2_DroneStack_Manual_2021a_B.RateTransition6[51] =
        QD2_DroneStack_Manual_2021a_P.Saturation1_UpperSat;
    } else if (rtb_DataTypeConversion3 <
               QD2_DroneStack_Manual_2021a_P.Saturation1_LowerSat) {
      /* RateTransition: '<S2>/Rate Transition6' */
      QD2_DroneStack_Manual_2021a_B.RateTransition6[51] =
        QD2_DroneStack_Manual_2021a_P.Saturation1_LowerSat;
    } else {
      /* RateTransition: '<S2>/Rate Transition6' */
      QD2_DroneStack_Manual_2021a_B.RateTransition6[51] =
        rtb_DataTypeConversion3;
    }

    /* RateTransition: '<S2>/Rate Transition6' */
    QD2_DroneStack_Manual_2021a_B.RateTransition6[52] =
      QD2_DroneStack_Manual_2021a_B.ComputationTime;
    QD2_DroneStack_Manual_2021a_B.RateTransition6[53] =
      QD2_DroneStack_Manual_2021a_B.SampleTime;
    QD2_DroneStack_Manual_2021a_B.RateTransition6[54] =
      QD2_DroneStack_Manual_2021a_B.RateTransition;
    QD2_DroneStack_Manual_2021a_B.RateTransition6[55] =
      QD2_DroneStack_Manual_2021a_B.RateTransition1_d;
    QD2_DroneStack_Manual_2021a_B.RateTransition6[56] =
      QD2_DroneStack_Manual_2021a_B.RateTransition2_f;
    QD2_DroneStack_Manual_2021a_B.RateTransition6[57] =
      QD2_DroneStack_Manual_2021a_B.RateTransition3;
    QD2_DroneStack_Manual_2021a_B.RateTransition6[58] =
      QD2_DroneStack_Manual_2021a_B.esc_ready;
    QD2_DroneStack_Manual_2021a_B.RateTransition6[59] =
      QD2_DroneStack_Manual_2021a_B.esc_timeout;

    /* Bias: '<S10>/Bias1' incorporates:
     *  Gain: '<S10>/Gain'
     *  Selector: '<S10>/Selector'
     */
    QD2_DroneStack_Manual_2021a_B.Bias1[0] =
      QD2_DroneStack_Manual_2021a_P.Gain_Gain *
      QD2_DroneStack_Manual_2021a_B.Selector[0] +
      QD2_DroneStack_Manual_2021a_P.Bias1_Bias[0];
    QD2_DroneStack_Manual_2021a_B.Bias1[1] =
      QD2_DroneStack_Manual_2021a_P.Gain_Gain *
      QD2_DroneStack_Manual_2021a_B.Selector[1] +
      QD2_DroneStack_Manual_2021a_P.Bias1_Bias[1];
    QD2_DroneStack_Manual_2021a_B.Bias1[2] =
      QD2_DroneStack_Manual_2021a_P.Gain_Gain *
      QD2_DroneStack_Manual_2021a_B.Selector[2] +
      QD2_DroneStack_Manual_2021a_P.Bias1_Bias[2];
    QD2_DroneStack_Manual_2021a_B.Bias1[3] =
      QD2_DroneStack_Manual_2021a_P.Gain_Gain *
      QD2_DroneStack_Manual_2021a_B.Selector[3] +
      QD2_DroneStack_Manual_2021a_P.Bias1_Bias[3];

    /* Product: '<S2>/Product2' */
    rtb_Product2[0] = QD2_DroneStack_Manual_2021a_B.ExtractESCChannels[0] *
      QD2_DroneStack_Manual_2021a_B.HILRead_o2[22];

    /* Memory: '<S14>/Memory' */
    rtb_Memory_l[0] = QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput_a[0];

    /* Product: '<S2>/Product2' */
    rtb_Product2[1] = QD2_DroneStack_Manual_2021a_B.ExtractESCChannels[1] *
      QD2_DroneStack_Manual_2021a_B.HILRead_o2[22];

    /* Memory: '<S14>/Memory' */
    rtb_Memory_l[1] = QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput_a[1];

    /* Product: '<S2>/Product2' */
    rtb_Product2[2] = QD2_DroneStack_Manual_2021a_B.ExtractESCChannels[2] *
      QD2_DroneStack_Manual_2021a_B.HILRead_o2[22];

    /* Memory: '<S14>/Memory' */
    rtb_Memory_l[2] = QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput_a[2];

    /* Product: '<S2>/Product2' */
    rtb_Product2[3] = QD2_DroneStack_Manual_2021a_B.ExtractESCChannels[3] *
      QD2_DroneStack_Manual_2021a_B.HILRead_o2[22];

    /* Memory: '<S14>/Memory' */
    rtb_Memory_l[3] = QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput_a[3];

    /* Outputs for Iterator SubSystem: '<S14>/For Each Subsystem -  Construct ESC Signal' */
    ForEachSubsystemConstructES(4, rtb_Product2,
      QD2_DroneStack_Manual_2021a_B.HILRead_o2[21], rtb_Memory_l,
      QD2_DroneStack_Manual_2021a_B.ImpAsg_InsertedFor_ESCDataOut_k);

    /* End of Outputs for SubSystem: '<S14>/For Each Subsystem -  Construct ESC Signal' */

    /* Delay: '<S16>/Delay3' */
    QD2_DroneStack_Manual_2021a_B.Delay3 =
      QD2_DroneStack_Manual_2021a_DW.Delay3_DSTATE[0];

    /* Delay: '<S16>/Delay2' */
    QD2_DroneStack_Manual_2021a_B.Delay2 =
      QD2_DroneStack_Manual_2021a_DW.Delay2_DSTATE[0];

    /* Delay: '<S16>/Delay1' */
    QD2_DroneStack_Manual_2021a_B.Delay1 =
      QD2_DroneStack_Manual_2021a_DW.Delay1_DSTATE[0];

    /* Delay: '<S16>/Delay' */
    QD2_DroneStack_Manual_2021a_B.Delay_i =
      QD2_DroneStack_Manual_2021a_DW.Delay_DSTATE_ln[0];

    /* SignalConversion generated from: '<S16>/For Each Subsystem' */
    Duty_Cycle[0] = QD2_DroneStack_Manual_2021a_B.Delay3;
    Duty_Cycle[1] = QD2_DroneStack_Manual_2021a_B.Delay2;
    Duty_Cycle[2] = QD2_DroneStack_Manual_2021a_B.Delay1;
    Duty_Cycle[3] = QD2_DroneStack_Manual_2021a_B.Delay_i;

    /* Outputs for Iterator SubSystem: '<S16>/For Each Subsystem' incorporates:
     *  ForEach: '<S37>/For Each'
     */
    for (ForEach_itr = 0; ForEach_itr < 4; ForEach_itr++) {
      /* ForEachSliceSelector generated from: '<S37>/Channel Requested [4]' */
      rtb_ImpSel_InsertedFor_ChannelR = Duty_Cycle[ForEach_itr];

      /* ForEachSliceSelector generated from: '<S37>/Channel Reported [4]' */
      rtb_ImpSel_InsertedFor_Channe_e =
        QD2_DroneStack_Manual_2021a_B.ExtractESCChannels[ForEach_itr];

      /* ForEachSliceAssignment generated from: '<S37>/mismatched [4]' incorporates:
       *  Constant: '<S39>/Constant'
       *  ForEachSliceSelector generated from: '<S37>/Channel Reported [4]'
       *  ForEachSliceSelector generated from: '<S37>/Channel Requested [4]'
       *  Logic: '<S37>/AND'
       *  RelationalOperator: '<S39>/Compare'
       *  S-Function (compare_block): '<S37>/Compare'
       */
      rtb_ImpAsg_InsertedFor_mismatch[ForEach_itr] =
        ((rtb_ImpSel_InsertedFor_ChannelR >=
          QD2_DroneStack_Manual_2021a_P.CoreSubsys_p.CompareToConstant_const) &&
         (rtb_ImpSel_InsertedFor_ChannelR != rtb_ImpSel_InsertedFor_Channe_e));
    }

    /* End of Outputs for SubSystem: '<S16>/For Each Subsystem' */

    /* Logic: '<S16>/AND' */
    QD2_DroneStack_Manual_2021a_B.AND[0] = (rtb_ImpAsg_InsertedFor_mismatch[0] &&
      (QD2_DroneStack_Manual_2021a_B.tele_enable != 0.0));
    QD2_DroneStack_Manual_2021a_B.AND[1] = (rtb_ImpAsg_InsertedFor_mismatch[1] &&
      (QD2_DroneStack_Manual_2021a_B.tele_enable != 0.0));
    QD2_DroneStack_Manual_2021a_B.AND[2] = (rtb_ImpAsg_InsertedFor_mismatch[2] &&
      (QD2_DroneStack_Manual_2021a_B.tele_enable != 0.0));
    QD2_DroneStack_Manual_2021a_B.AND[3] = (rtb_ImpAsg_InsertedFor_mismatch[3] &&
      (QD2_DroneStack_Manual_2021a_B.tele_enable != 0.0));

    /* MATLAB Function: '<S16>/MATLAB Function' incorporates:
     *  Constant: '<S16>/Constant'
     */
    QD2_DroneStack_Manual_2021a_DW.sfEvent_d = QD2_DroneStack_Manua_CALL_EVENT;

    /* MATLAB Function 'QDrone 2 DAQ/Detect ESC Problems/MATLAB Function': '<S38>:1' */
    if (!QD2_DroneStack_Manual_2021a_DW.buffer_not_empty) {
      /* '<S38>:1:9' */
      /* '<S38>:1:10' */
      firstBlockLength = QD2_DroneStack_Manual_2021a_DW.buffer->size[0] *
        QD2_DroneStack_Manual_2021a_DW.buffer->size[1];
      QD2_DroneStack_Manual_2021a_DW.buffer->size[0] = 4;
      QD2_DroneStack_Manual_2021a_DW.buffer->size[1] = (int32_T)
        QD2_DroneStack_Manual_2021a_P.Constant_Value_o;
      QD2_Dr_emxEnsureCapacity_real_T(QD2_DroneStack_Manual_2021a_DW.buffer,
        firstBlockLength);
      nblocks = (int32_T)QD2_DroneStack_Manual_2021a_P.Constant_Value_o << 2;
      if (nblocks - 1 >= 0) {
        memset(&QD2_DroneStack_Manual_2021a_DW.buffer->data[0], 0, (uint32_T)
               nblocks * sizeof(real_T));
      }

      QD2_DroneStack_Manual_2021a_DW.buffer_not_empty =
        (QD2_DroneStack_Manual_2021a_DW.buffer->size[1] != 0);
    }

    /* '<S38>:1:17' */
    QD2_DroneStack_Manual_2021a_DW.buffer->data[((int32_T)
      QD2_DroneStack_Manual_2021a_DW.idx - 1) << 2] =
      QD2_DroneStack_Manual_2021a_B.AND[0];
    QD2_DroneStack_Manual_2021a_DW.buffer->data[(((int32_T)
      QD2_DroneStack_Manual_2021a_DW.idx - 1) << 2) + 1] =
      QD2_DroneStack_Manual_2021a_B.AND[1];
    QD2_DroneStack_Manual_2021a_DW.buffer->data[(((int32_T)
      QD2_DroneStack_Manual_2021a_DW.idx - 1) << 2) + 2] =
      QD2_DroneStack_Manual_2021a_B.AND[2];
    QD2_DroneStack_Manual_2021a_DW.buffer->data[(((int32_T)
      QD2_DroneStack_Manual_2021a_DW.idx - 1) << 2) + 3] =
      QD2_DroneStack_Manual_2021a_B.AND[3];

    /* '<S38>:1:19' */
    QD2_DroneStack_Manual_2021a_DW.idx++;
    if (QD2_DroneStack_Manual_2021a_DW.idx >
        QD2_DroneStack_Manual_2021a_P.Constant_Value_o) {
      /* '<S38>:1:20' */
      /* '<S38>:1:22' */
      QD2_DroneStack_Manual_2021a_DW.idx = 1.0;
    }

    /* '<S38>:1:26' */
    if (QD2_DroneStack_Manual_2021a_DW.buffer->size[1] == 0) {
      QD2_DroneStack_Manual_2021a_B.n[0] = 0.0;
      QD2_DroneStack_Manual_2021a_B.n[1] = 0.0;
      QD2_DroneStack_Manual_2021a_B.n[2] = 0.0;
      QD2_DroneStack_Manual_2021a_B.n[3] = 0.0;
    } else {
      if (QD2_DroneStack_Manual_2021a_DW.buffer->size[1] <= 1024) {
        firstBlockLength = QD2_DroneStack_Manual_2021a_DW.buffer->size[1];
        lastBlockLength = 0;
        nblocks = 1;
      } else {
        firstBlockLength = 1024;
        nblocks = (int32_T)((uint32_T)
                            QD2_DroneStack_Manual_2021a_DW.buffer->size[1] >> 10);
        lastBlockLength = QD2_DroneStack_Manual_2021a_DW.buffer->size[1] -
          (nblocks << 10);
        if (lastBlockLength > 0) {
          nblocks++;
        } else {
          lastBlockLength = 1024;
        }
      }

      QD2_DroneStack_Manual_2021a_B.n[0] =
        QD2_DroneStack_Manual_2021a_DW.buffer->data[0];
      QD2_DroneStack_Manual_2021a_B.n[1] =
        QD2_DroneStack_Manual_2021a_DW.buffer->data[1];
      QD2_DroneStack_Manual_2021a_B.n[2] =
        QD2_DroneStack_Manual_2021a_DW.buffer->data[2];
      QD2_DroneStack_Manual_2021a_B.n[3] =
        QD2_DroneStack_Manual_2021a_DW.buffer->data[3];
      for (xblockoffset = 2; xblockoffset <= firstBlockLength; xblockoffset++) {
        xoffset = (xblockoffset - 1) << 2;
        QD2_DroneStack_Manual_2021a_B.n[0] +=
          QD2_DroneStack_Manual_2021a_DW.buffer->data[xoffset];
        QD2_DroneStack_Manual_2021a_B.n[1] +=
          QD2_DroneStack_Manual_2021a_DW.buffer->data[xoffset + 1];
        QD2_DroneStack_Manual_2021a_B.n[2] +=
          QD2_DroneStack_Manual_2021a_DW.buffer->data[xoffset + 2];
        QD2_DroneStack_Manual_2021a_B.n[3] +=
          QD2_DroneStack_Manual_2021a_DW.buffer->data[xoffset + 3];
      }

      for (firstBlockLength = 2; firstBlockLength <= nblocks; firstBlockLength++)
      {
        xblockoffset = (firstBlockLength - 1) << 12;
        Duty_Cycle[0] = QD2_DroneStack_Manual_2021a_DW.buffer->data[xblockoffset];
        Duty_Cycle[1] = QD2_DroneStack_Manual_2021a_DW.buffer->data[xblockoffset
          + 1];
        Duty_Cycle[2] = QD2_DroneStack_Manual_2021a_DW.buffer->data[xblockoffset
          + 2];
        Duty_Cycle[3] = QD2_DroneStack_Manual_2021a_DW.buffer->data[xblockoffset
          + 3];
        if (firstBlockLength == nblocks) {
          hi = lastBlockLength;
        } else {
          hi = 1024;
        }

        for (b_k = 2; b_k <= hi; b_k++) {
          xoffset = ((b_k - 1) << 2) + xblockoffset;
          Duty_Cycle[0] += QD2_DroneStack_Manual_2021a_DW.buffer->data[xoffset];
          Duty_Cycle[1] += QD2_DroneStack_Manual_2021a_DW.buffer->data[xoffset +
            1];
          Duty_Cycle[2] += QD2_DroneStack_Manual_2021a_DW.buffer->data[xoffset +
            2];
          Duty_Cycle[3] += QD2_DroneStack_Manual_2021a_DW.buffer->data[xoffset +
            3];
        }

        QD2_DroneStack_Manual_2021a_B.n[0] += Duty_Cycle[0];
        QD2_DroneStack_Manual_2021a_B.n[1] += Duty_Cycle[1];
        QD2_DroneStack_Manual_2021a_B.n[2] += Duty_Cycle[2];
        QD2_DroneStack_Manual_2021a_B.n[3] += Duty_Cycle[3];
      }
    }

    /* End of MATLAB Function: '<S16>/MATLAB Function' */
    /* S-Function (euler_angles_to_rotation_matrix_block): '<S2>/Euler Angles to Rotation Matrix' incorporates:
     *  Constant: '<S2>/Zero Yaw'
     */
    {
      t_double sin_phi = sin(QD2_DroneStack_Manual_2021a_P.ZeroYaw_Value);
      t_double cos_phi = cos(QD2_DroneStack_Manual_2021a_P.ZeroYaw_Value);
      t_double sin_theta = sin(QD2_DroneStack_Manual_2021a_B.Product3[1]);
      t_double cos_theta = cos(QD2_DroneStack_Manual_2021a_B.Product3[1]);
      t_double sin_psi = sin(QD2_DroneStack_Manual_2021a_B.Product3[0]);
      t_double cos_psi = cos(QD2_DroneStack_Manual_2021a_B.Product3[0]);
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

    /* DataTypeConversion: '<S23>/Data Type Conversion' incorporates:
     *  Constant: '<S40>/Constant'
     *  Constant: '<S41>/Constant'
     *  Logic: '<S23>/AND'
     *  RelationalOperator: '<S40>/Compare'
     *  RelationalOperator: '<S41>/Compare'
     */
    rtb_DataTypeConversion3 = ((QD2_DroneStack_Manual_2021a_B.HILRead_o1[0] >
      QD2_DroneStack_Manual_2021a_P.Greaterthanminimumexpectedvolta) &&
      (QD2_DroneStack_Manual_2021a_B.HILRead_o1[0] <=
       QD2_DroneStack_Manual_2021a_P.Lessthanminimumthresholdvoltage));

    /* RelationalOperator: '<S42>/Relation' incorporates:
     *  Constant: '<S23>/Constant'
     */
    rtb_Relation_h = (rtb_DataTypeConversion3 >=
                      QD2_DroneStack_Manual_2021a_P.Constant_Value_j);

    /* DataTypeConversion: '<S42>/Data Type Conversion' */
    QD2_DroneStack_Manual_2021a_B.DataTypeConversion = rtb_Relation_h;

    /* Logic: '<S42>/Logical Operator' */
    QD2_DroneStack_Manual_2021a_B.LogicalOperator = !rtb_Relation_h;

    /* DiscreteIntegrator: '<S42>/Discrete-Time Integrator' */
    if (QD2_DroneStack_Manual_2021a_B.LogicalOperator ||
        (QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_PrevRese != 0)) {
      QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE =
        QD2_DroneStack_Manual_2021a_P.DiscreteTimeIntegrator_IC;
    }

    /* RelationalOperator: '<S42>/Relational Operator' incorporates:
     *  Constant: '<S23>/Battery Low Time Threshold (s)'
     *  DiscreteIntegrator: '<S42>/Discrete-Time Integrator'
     */
    rtb_Relation_h =
      (QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE >=
       QD2_DroneStack_Manual_2021a_P.BatteryLowTimeThresholds_Value);

    /* Outputs for Triggered SubSystem: '<S23>/Triggered Subsystem - Latching Flag' incorporates:
     *  TriggerPort: '<S43>/Trigger'
     */
    if (rtsiIsModeUpdateTimeStep(&QD2_DroneStack_Manual_2021a_M->solverInfo)) {
      if (rtb_Relation_h &&
          (QD2_DroneStack_Manual_2_PrevZCX.TriggeredSubsystemLatchingFlag_ !=
           POS_ZCSIG)) {
        /* SignalConversion generated from: '<S43>/Out1' incorporates:
         *  Constant: '<S43>/Constant'
         */
        QD2_DroneStack_Manual_2021a_B.OutportBufferForOut1 =
          QD2_DroneStack_Manual_2021a_P.Constant_Value;
        QD2_DroneStack_Manual_2021a_DW.TriggeredSubsystemLatchingFlag_ = 4;
      }

      QD2_DroneStack_Manual_2_PrevZCX.TriggeredSubsystemLatchingFlag_ =
        rtb_Relation_h;
    }

    /* End of Outputs for SubSystem: '<S23>/Triggered Subsystem - Latching Flag' */

    /* RateTransition: '<S2>/Rate Transition' */
    if (QD2_DroneStack_Manual_2021a_M->Timing.RateInteraction.TID1_3) {
      for (firstBlockLength = 0; firstBlockLength < 7; firstBlockLength++) {
        QD2_DroneStack_Manual_2021a_DW.RateTransition_Buffer[firstBlockLength] =
          QD2_DroneStack_Manual_2021a_B.HILRead_o2[firstBlockLength + 12];
      }
    }

    /* End of RateTransition: '<S2>/Rate Transition' */

    /* RateTransition: '<S2>/Rate Transition10' incorporates:
     *  Product: '<S2>/Product3'
     *  RateTransition: '<S2>/Rate Transition11'
     *  RateTransition: '<S2>/Rate Transition12'
     *  RateTransition: '<S2>/Rate Transition15'
     *  RateTransition: '<S2>/Rate Transition17'
     *  RateTransition: '<S2>/Rate Transition19'
     *  RateTransition: '<S2>/Rate Transition20'
     *  Selector: '<S9>/Select Data for IMU0'
     *  Selector: '<S9>/Select Data for IMU1'
     */
    if (QD2_DroneStack_Manual_2021a_M->Timing.RateInteraction.TID1_2) {
      QD2_DroneStack_Manual_2021a_DW.RateTransition10_Buffer[0] =
        QD2_DroneStack_Manual_2021a_B.MaximumCommandAuthority[0];
      QD2_DroneStack_Manual_2021a_DW.RateTransition10_Buffer[1] =
        QD2_DroneStack_Manual_2021a_B.MaximumCommandAuthority[1];
      QD2_DroneStack_Manual_2021a_DW.RateTransition10_Buffer[2] =
        QD2_DroneStack_Manual_2021a_B.MaximumCommandAuthority[2];
      QD2_DroneStack_Manual_2021a_DW.RateTransition10_Buffer[3] =
        QD2_DroneStack_Manual_2021a_B.MaximumCommandAuthority[3];
      QD2_DroneStack_Manual_2021a_DW.RateTransition11_Buffer =
        QD2_DroneStack_Manual_2021a_B.OutportBufferForOut1;
      QD2_DroneStack_Manual_2021a_DW.RateTransition12_Buffer =
        QD2_DroneStack_Manual_2021a_B.HILRead_o1[0];
      memcpy(&QD2_DroneStack_Manual_2021a_DW.RateTransition15_Buffer[0],
             &QD2_DroneStack_Manual_2021a_B.SelectDataforIMU0[0], 9U * sizeof
             (real_T));
      memcpy(&QD2_DroneStack_Manual_2021a_DW.RateTransition17_Buffer[0],
             &QD2_DroneStack_Manual_2021a_B.SelectDataforIMU1[0], 9U * sizeof
             (real_T));
      memcpy(&QD2_DroneStack_Manual_2021a_DW.RateTransition19_Buffer[0],
             &QD2_DroneStack_Manual_2021a_B.Product3[0], 9U * sizeof(real_T));
      QD2_DroneStack_Manual_2021a_DW.RateTransition20_Buffer =
        QD2_DroneStack_Manual_2021a_B.HILRead_o1[2];
    }

    /* End of RateTransition: '<S2>/Rate Transition10' */

    /* RateTransition: '<S2>/Rate Transition3' incorporates:
     *  S-Function (euler_angles_to_rotation_matrix_block): '<S2>/Euler Angles to Rotation Matrix'
     */
    if (QD2_DroneStack_Manual_2021a_M->Timing.RateInteraction.TID1_4) {
      memcpy(&QD2_DroneStack_Manual_2021a_DW.RateTransition3_Buffer[0],
             &rtb_EulerAnglestoRotationMatrix[0], 9U * sizeof(real_T));
    }

    /* End of RateTransition: '<S2>/Rate Transition3' */

    /* RateTransition: '<S2>/Rate Transition8' */
    if (QD2_DroneStack_Manual_2021a_M->Timing.RateInteraction.TID1_2) {
      memcpy(&QD2_DroneStack_Manual_2021a_DW.RateTransition8_Buffer[0],
             &QD2_DroneStack_Manual_2021a_B.HILRead_o2[0], 12U * sizeof(real_T));
    }

    /* End of RateTransition: '<S2>/Rate Transition8' */

    /* S-Function (compare_block): '<S25>/Compare' incorporates:
     *  Constant: '<S25>/Constant1'
     */
    {
      rtb_Compare_c = (rtb_Time >=
                       QD2_DroneStack_Manual_2021a_P.Constant1_Value_o);
    }

    /* RelationalOperator: '<S26>/Relation' incorporates:
     *  Constant: '<S26>/threshold'
     *  Constant: '<S36>/Constant'
     *  Logic: '<S2>/OR1'
     *  RelationalOperator: '<S36>/Compare'
     */
    rtb_Relation_a = (((QD2_DroneStack_Manual_2021a_B.n[0] >=
                        QD2_DroneStack_Manual_2021a_P.CompareToConstant_const) ||
                       (QD2_DroneStack_Manual_2021a_B.n[1] >=
                        QD2_DroneStack_Manual_2021a_P.CompareToConstant_const) ||
                       (QD2_DroneStack_Manual_2021a_B.n[2] >=
                        QD2_DroneStack_Manual_2021a_P.CompareToConstant_const) ||
                       (QD2_DroneStack_Manual_2021a_B.n[3] >=
                        QD2_DroneStack_Manual_2021a_P.CompareToConstant_const))
                      != QD2_DroneStack_Manual_2021a_P.Threshold_threshold);

    /* DataTypeConversion: '<S26>/Data Type Conversion' */
    QD2_DroneStack_Manual_2021a_B.DataTypeConversion_h = rtb_Relation_a;

    /* Logic: '<S26>/Logical Operator' */
    QD2_DroneStack_Manual_2021a_B.LogicalOperator_f = !rtb_Relation_a;

    /* DiscreteIntegrator: '<S26>/Discrete-Time Integrator' */
    if (QD2_DroneStack_Manual_2021a_B.LogicalOperator_f ||
        (QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_PrevRe_h != 0)) {
      QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE_j =
        QD2_DroneStack_Manual_2021a_P.DiscreteTimeIntegrator_IC_j;
    }

    /* RelationalOperator: '<S26>/Relational Operator' incorporates:
     *  Constant: '<S26>/duration'
     *  DiscreteIntegrator: '<S26>/Discrete-Time Integrator'
     */
    QD2_DroneStack_Manual_2021a_B.RelationalOperator =
      (QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE_j >=
       QD2_DroneStack_Manual_2021a_P.Threshold_duration);
  }

  /* Clock: '<S5>/Clock' */
  QD2_DroneStack_Manual_2021a_B.Clock = QD2_DroneStack_Manual_2021a_M->Timing.t
    [0];
  if (rtb_Relation) {
    /* MATLAB Function: '<S5>/MATLAB Function' */
    QD2_DroneStack_Manual_2021a_DW.sfEvent_a = QD2_DroneStack_Manua_CALL_EVENT;

    /* MATLAB Function 'Communication/Detect Communication loss/MATLAB Function': '<S6>:1' */
    /* '<S6>:1:10' */
    rtb_DataTypeConversion3 = 0.0;

    /* '<S6>:1:11' */
    data_loss = 0.0;
    if (QD2_DroneStack_Manual_2021a_B.Clock > 3.0) {
      /* '<S6>:1:12' */
      if ((QD2_DroneStack_Manual_2021a_B.StreamClient_o1 != 2) &&
          (rtb_StreamClient_o2 < 0)) {
        /* '<S6>:1:13' */
        /* '<S6>:1:15' */
        rtb_DataTypeConversion3 = 1.0;
      }

      if (QD2_DroneStack_Manual_2021a_B.StreamClient_o4[10] ==
          QD2_DroneStack_Manual_2021a_DW.ms_time_prev) {
        /* '<S6>:1:18' */
        /* '<S6>:1:20' */
        data_loss = 1.0;
      }
    }

    /* '<S6>:1:24' */
    QD2_DroneStack_Manual_2021a_DW.ms_time_prev =
      QD2_DroneStack_Manual_2021a_B.StreamClient_o4[10];

    /* End of MATLAB Function: '<S5>/MATLAB Function' */

    /* RelationalOperator: '<S7>/Relation' incorporates:
     *  Constant: '<S7>/threshold'
     */
    rtb_Relation_h = (rtb_DataTypeConversion3 >=
                      QD2_DroneStack_Manual_2021a_P.Threshold_threshold_h);

    /* Logic: '<S7>/Logical Operator' */
    QD2_DroneStack_Manual_2021a_B.LogicalOperator_p = !rtb_Relation_h;

    /* DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
    if (QD2_DroneStack_Manual_2021a_B.LogicalOperator_p ||
        (QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_PrevR_hs != 0)) {
      QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE_k =
        QD2_DroneStack_Manual_2021a_P.DiscreteTimeIntegrator_IC_c;
    }

    /* RelationalOperator: '<S8>/Relation' incorporates:
     *  Constant: '<S8>/threshold'
     */
    rtb_Relation_a = (data_loss >=
                      QD2_DroneStack_Manual_2021a_P.Threshold1_threshold);

    /* Logic: '<S8>/Logical Operator' */
    QD2_DroneStack_Manual_2021a_B.LogicalOperator_m = !rtb_Relation_a;

    /* DiscreteIntegrator: '<S8>/Discrete-Time Integrator' */
    if (QD2_DroneStack_Manual_2021a_B.LogicalOperator_m ||
        (QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_PrevRe_b != 0)) {
      QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE_e =
        QD2_DroneStack_Manual_2021a_P.DiscreteTimeIntegrator_IC_m;
    }

    /* DataTypeConversion: '<S5>/Data Type Conversion' incorporates:
     *  Constant: '<S7>/duration'
     *  Constant: '<S8>/duration'
     *  DiscreteIntegrator: '<S7>/Discrete-Time Integrator'
     *  DiscreteIntegrator: '<S8>/Discrete-Time Integrator'
     *  Logic: '<S5>/Logical Operator4'
     *  RelationalOperator: '<S7>/Relational Operator'
     *  RelationalOperator: '<S8>/Relational Operator'
     */
    QD2_DroneStack_Manual_2021a_B.DataTypeConversion_c =
      ((QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE_k >=
        QD2_DroneStack_Manual_2021a_P.Threshold_duration_d) ||
       (QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE_e >=
        QD2_DroneStack_Manual_2021a_P.Threshold1_duration));

    /* DataTypeConversion: '<S7>/Data Type Conversion' */
    QD2_DroneStack_Manual_2021a_B.DataTypeConversion_k = rtb_Relation_h;

    /* DataTypeConversion: '<S8>/Data Type Conversion' */
    QD2_DroneStack_Manual_2021a_B.DataTypeConversion_cz = rtb_Relation_a;
  }

  /* Gain: '<S57>/Gain' */
  QD2_DroneStack_Manual_2021a_B.Gain[0] =
    QD2_DroneStack_Manual_2021a_P.Gain_Gain_b *
    QD2_DroneStack_Manual_2021a_B.AttitudeAngleCommands[0];
  QD2_DroneStack_Manual_2021a_B.Gain[3] =
    QD2_DroneStack_Manual_2021a_P.Gain_Gain_b *
    QD2_DroneStack_Manual_2021a_B.Product3[0];
  QD2_DroneStack_Manual_2021a_B.Gain[1] =
    QD2_DroneStack_Manual_2021a_P.Gain_Gain_b *
    QD2_DroneStack_Manual_2021a_B.AttitudeAngleCommands[1];
  QD2_DroneStack_Manual_2021a_B.Gain[4] =
    QD2_DroneStack_Manual_2021a_P.Gain_Gain_b *
    QD2_DroneStack_Manual_2021a_B.Product3[1];
  QD2_DroneStack_Manual_2021a_B.Gain[2] =
    QD2_DroneStack_Manual_2021a_P.Gain_Gain_b *
    QD2_DroneStack_Manual_2021a_B.AttitudeAngleCommands[2];
  QD2_DroneStack_Manual_2021a_B.Gain[5] =
    QD2_DroneStack_Manual_2021a_P.Gain_Gain_b *
    QD2_DroneStack_Manual_2021a_B.Product3[2];
  if (rtb_Relation) {
  }

  /* Gain: '<S58>/Gain' incorporates:
   *  Sum: '<S4>/Sum1'
   */
  QD2_DroneStack_Manual_2021a_B.Gain_l[0] =
    QD2_DroneStack_Manual_2021a_P.Gain_Gain_k * rtb_Sum1_f_idx_0;
  QD2_DroneStack_Manual_2021a_B.Gain_l[3] =
    QD2_DroneStack_Manual_2021a_P.Gain_Gain_k *
    QD2_DroneStack_Manual_2021a_B.Product3[3];
  QD2_DroneStack_Manual_2021a_B.Gain_l[1] =
    QD2_DroneStack_Manual_2021a_P.Gain_Gain_k * rtb_Sum1_f_idx_1;
  QD2_DroneStack_Manual_2021a_B.Gain_l[4] =
    QD2_DroneStack_Manual_2021a_P.Gain_Gain_k *
    QD2_DroneStack_Manual_2021a_B.Product3[4];
  QD2_DroneStack_Manual_2021a_B.Gain_l[2] =
    QD2_DroneStack_Manual_2021a_P.Gain_Gain_k * rtb_Sum1_f_idx_2;
  QD2_DroneStack_Manual_2021a_B.Gain_l[5] =
    QD2_DroneStack_Manual_2021a_P.Gain_Gain_k *
    QD2_DroneStack_Manual_2021a_B.Product3[5];
  if (rtb_Relation) {
    /* S-Function (sample_time_block): '<S56>/Sample Time' */

    /* S-Function Block: QD2_DroneStack_Manual_2021a/STABILIZER - QDRONE 2/FLIGHT SAFETY/Sample Time (sample_time_block) */
    {
      t_error result;
      t_timeout current_time;
      t_timeout time_difference;
      result = timeout_get_high_resolution_time(&current_time);
      if (result >= 0) {
        result = timeout_subtract(&time_difference, &current_time,
          &QD2_DroneStack_Manual_2021a_DW.SampleTime_PreviousTime_j);
        QD2_DroneStack_Manual_2021a_B.SampleTime_h = time_difference.seconds +
          time_difference.nanoseconds * 1e-9;
        memcpy(&QD2_DroneStack_Manual_2021a_DW.SampleTime_PreviousTime_j,
               &current_time, sizeof(t_timeout));
      }

      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QD2_DroneStack_Manual_2021a_M, _rt_error_message);
        return;
      }
    }

    /* S-Function (computation_time_block): '<S56>/Computation Time' */

    /* S-Function Block: QD2_DroneStack_Manual_2021a/STABILIZER - QDRONE 2/FLIGHT SAFETY/Computation Time (computation_time_block) */
    {
      QD2_DroneStack_Manual_2021a_B.ComputationTime_a =
        QD2_DroneStack_Manual_2021a_DW.ComputationTime_ComputationTi_j.seconds +
        QD2_DroneStack_Manual_2021a_DW.ComputationTime_ComputationTi_j.nanoseconds
        * 1e-9;
    }

    /* RelationalOperator: '<S60>/Relation' incorporates:
     *  Constant: '<S60>/threshold'
     */
    rtb_Relation = (QD2_DroneStack_Manual_2021a_B.StreamClient_o4[1] >=
                    QD2_DroneStack_Manual_2021a_P.Stopmodel_threshold);

    /* Logic: '<S60>/Logical Operator' */
    QD2_DroneStack_Manual_2021a_B.LogicalOperator_a = !rtb_Relation;

    /* DiscreteIntegrator: '<S60>/Discrete-Time Integrator' */
    if (QD2_DroneStack_Manual_2021a_B.LogicalOperator_a ||
        (QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_PrevRe_j != 0)) {
      QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE_l =
        QD2_DroneStack_Manual_2021a_P.DiscreteTimeIntegrator_IC_a;
    }

    /* RelationalOperator: '<S60>/Relational Operator' incorporates:
     *  Constant: '<S60>/duration'
     *  DiscreteIntegrator: '<S60>/Discrete-Time Integrator'
     */
    QD2_DroneStack_Manual_2021a_B.RelationalOperator_g =
      (QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE_l >=
       QD2_DroneStack_Manual_2021a_P.Stopmodel_duration);

    /* DataTypeConversion: '<S56>/Data Type Conversion4' */
    QD2_DroneStack_Manual_2021a_B.DataTypeConversion4 =
      QD2_DroneStack_Manual_2021a_B.RelationalOperator_g;

    /* DataTypeConversion: '<S56>/Data Type Conversion3' incorporates:
     *  Logic: '<S56>/Logical Operator1'
     */
    rtb_DataTypeConversion3 =
      ((QD2_DroneStack_Manual_2021a_B.DataTypeConversion_c != 0.0) &&
       (QD2_DroneStack_Manual_2021a_B.StreamClient_o4[9] != 0.0));

    /* RelationalOperator: '<S59>/Relation' incorporates:
     *  Constant: '<S59>/threshold'
     */
    rtb_Relation_h = (rtb_DataTypeConversion3 >=
                      QD2_DroneStack_Manual_2021a_P.Communication_threshold);

    /* Logic: '<S59>/Logical Operator' */
    QD2_DroneStack_Manual_2021a_B.LogicalOperator_k = !rtb_Relation_h;

    /* DiscreteIntegrator: '<S59>/Discrete-Time Integrator' */
    if (QD2_DroneStack_Manual_2021a_B.LogicalOperator_k ||
        (QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_PrevRe_k != 0)) {
      QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_DSTAT_lx =
        QD2_DroneStack_Manual_2021a_P.DiscreteTimeIntegrator_IC_my;
    }

    /* RelationalOperator: '<S59>/Relational Operator' incorporates:
     *  Constant: '<S59>/duration'
     *  DiscreteIntegrator: '<S59>/Discrete-Time Integrator'
     */
    QD2_DroneStack_Manual_2021a_B.RelationalOperator_p =
      (QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_DSTAT_lx >=
       QD2_DroneStack_Manual_2021a_P.Communication_duration);

    /* DataTypeConversion: '<S56>/Data Type Conversion1' */
    QD2_DroneStack_Manual_2021a_B.DataTypeConversion1 =
      QD2_DroneStack_Manual_2021a_B.RelationalOperator_p;

    /* S-Function (hil_watchdog_block): '<S56>/HIL Watchdog' */

    /* S-Function Block: QD2_DroneStack_Manual_2021a/STABILIZER - QDRONE 2/FLIGHT SAFETY/HIL Watchdog (hil_watchdog_block) */
    {
      t_error result;
      if (QD2_DroneStack_Manual_2021a_DW.HILWatchdog_IsStarted) {
        result = hil_watchdog_reload
          (QD2_DroneStack_Manual_2021a_DW.HILInitialize_Card);
      } else {
        result = hil_watchdog_start
          (QD2_DroneStack_Manual_2021a_DW.HILInitialize_Card,
           QD2_DroneStack_Manual_2021a_P.HILWatchdog_Timeout);
        if (result == 0) {
          QD2_DroneStack_Manual_2021a_DW.HILWatchdog_IsStarted = true;
          result = 1;                  /* indicate watchdog has not expired */
        }
      }

      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QD2_DroneStack_Manual_2021a_M, _rt_error_message);
      }

      QD2_DroneStack_Manual_2021a_B.HILWatchdog = (result == 0);
    }

    /* DataTypeConversion: '<S56>/Data Type Conversion5' */
    QD2_DroneStack_Manual_2021a_B.DataTypeConversion5 =
      QD2_DroneStack_Manual_2021a_B.HILWatchdog;

    /* SignalConversion generated from: '<S4>/To Host File' */
    QD2_DroneStack_Manual_2021a_B.TmpSignalConversionAtToHostFile[0] =
      QD2_DroneStack_Manual_2021a_B.SampleTime_h;
    QD2_DroneStack_Manual_2021a_B.TmpSignalConversionAtToHostFile[1] =
      QD2_DroneStack_Manual_2021a_B.ComputationTime_a;
    QD2_DroneStack_Manual_2021a_B.TmpSignalConversionAtToHostFile[2] =
      QD2_DroneStack_Manual_2021a_B.DataTypeConversion4;
    QD2_DroneStack_Manual_2021a_B.TmpSignalConversionAtToHostFile[3] =
      QD2_DroneStack_Manual_2021a_B.DataTypeConversion1;
    QD2_DroneStack_Manual_2021a_B.TmpSignalConversionAtToHostFile[4] =
      QD2_DroneStack_Manual_2021a_B.DataTypeConversion5;
    QD2_DroneStack_Manual_2021a_B.TmpSignalConversionAtToHostFile[5] =
      QD2_DroneStack_Manual_2021a_B.StreamClient_o4[0];
    QD2_DroneStack_Manual_2021a_B.TmpSignalConversionAtToHostFile[6] =
      QD2_DroneStack_Manual_2021a_B.StreamClient_o4[2];
    QD2_DroneStack_Manual_2021a_B.TmpSignalConversionAtToHostFile[16] =
      QD2_DroneStack_Manual_2021a_B.StreamClient_o4[2];
    QD2_DroneStack_Manual_2021a_B.TmpSignalConversionAtToHostFile[7] =
      QD2_DroneStack_Manual_2021a_B.AttitudeAngleCommands[0];
    QD2_DroneStack_Manual_2021a_B.TmpSignalConversionAtToHostFile[10] =
      QD2_DroneStack_Manual_2021a_B.AttitudeTorqueCommands[0];
    QD2_DroneStack_Manual_2021a_B.TmpSignalConversionAtToHostFile[13] =
      QD2_DroneStack_Manual_2021a_B.Sum6[0];
    QD2_DroneStack_Manual_2021a_B.TmpSignalConversionAtToHostFile[17] =
      QD2_DroneStack_Manual_2021a_B.SaturationCommandAuthorityNm1[0];
    QD2_DroneStack_Manual_2021a_B.TmpSignalConversionAtToHostFile[8] =
      QD2_DroneStack_Manual_2021a_B.AttitudeAngleCommands[1];
    QD2_DroneStack_Manual_2021a_B.TmpSignalConversionAtToHostFile[11] =
      QD2_DroneStack_Manual_2021a_B.AttitudeTorqueCommands[1];
    QD2_DroneStack_Manual_2021a_B.TmpSignalConversionAtToHostFile[14] =
      QD2_DroneStack_Manual_2021a_B.Sum6[1];
    QD2_DroneStack_Manual_2021a_B.TmpSignalConversionAtToHostFile[18] =
      QD2_DroneStack_Manual_2021a_B.SaturationCommandAuthorityNm1[1];
    QD2_DroneStack_Manual_2021a_B.TmpSignalConversionAtToHostFile[9] =
      QD2_DroneStack_Manual_2021a_B.AttitudeAngleCommands[2];
    QD2_DroneStack_Manual_2021a_B.TmpSignalConversionAtToHostFile[12] =
      QD2_DroneStack_Manual_2021a_B.AttitudeTorqueCommands[2];
    QD2_DroneStack_Manual_2021a_B.TmpSignalConversionAtToHostFile[15] =
      QD2_DroneStack_Manual_2021a_B.Sum6[2];
    QD2_DroneStack_Manual_2021a_B.TmpSignalConversionAtToHostFile[19] =
      QD2_DroneStack_Manual_2021a_B.SaturationCommandAuthorityNm1[2];

    /* Stop: '<S61>/Stop Simulation' incorporates:
     *  Constant: '<S64>/Constant'
     *  RelationalOperator: '<S64>/Compare'
     */
    if (QD2_DroneStack_Manual_2021a_B.RelationalOperator_g !=
        QD2_DroneStack_Manual_2021a_P.Constant_Value_c) {
      rtmSetStopRequested(QD2_DroneStack_Manual_2021a_M, true);
    }

    /* End of Stop: '<S61>/Stop Simulation' */
    /* Stop: '<S62>/Stop Simulation' incorporates:
     *  Constant: '<S65>/Constant'
     *  RelationalOperator: '<S65>/Compare'
     */
    if (QD2_DroneStack_Manual_2021a_B.RelationalOperator_p !=
        QD2_DroneStack_Manual_2021a_P.Constant_Value_oc) {
      rtmSetStopRequested(QD2_DroneStack_Manual_2021a_M, true);
    }

    /* End of Stop: '<S62>/Stop Simulation' */
    /* Stop: '<S63>/Stop Simulation' incorporates:
     *  Constant: '<S66>/Constant'
     *  RelationalOperator: '<S66>/Compare'
     */
    if (QD2_DroneStack_Manual_2021a_B.HILWatchdog !=
        QD2_DroneStack_Manual_2021a_P.Constant_Value_a) {
      rtmSetStopRequested(QD2_DroneStack_Manual_2021a_M, true);
    }

    /* End of Stop: '<S63>/Stop Simulation' */

    /* DataTypeConversion: '<S59>/Data Type Conversion' */
    QD2_DroneStack_Manual_2021a_B.DataTypeConversion_p = rtb_Relation_h;

    /* DataTypeConversion: '<S60>/Data Type Conversion' */
    QD2_DroneStack_Manual_2021a_B.DataTypeConversion_a = rtb_Relation;
  }
}

/* Model update function for TID0 */
void QD2_DroneStack_Manual_2021a_update0(void) /* Sample time: [0.0s, 0.0s] */
{
  /* local scratch DWork variables */
  int32_T ForEach_itr_b;
  int32_T idxDelay;
  boolean_T tmp;
  tmp = rtmIsMajorTimeStep(QD2_DroneStack_Manual_2021a_M);
  if (tmp) {
    /* Update for Delay: '<S1>/Delay' */
    QD2_DroneStack_Manual_2021a_DW.Delay_DSTATE =
      QD2_DroneStack_Manual_2021a_B.StreamClient_o4[10];

    /* Update for Memory: '<S2>/Memory1' */
    QD2_DroneStack_Manual_2021a_DW.Memory1_PreviousInput =
      QD2_DroneStack_Manual_2021a_B.RelationalOperator;

    /* Update for Memory: '<S2>/Memory' */
    QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput =
      QD2_DroneStack_Manual_2021a_B.state;
  }

  /* Update for Iterator SubSystem: '<S9>/For Each Subsystem - Iterate over IMU0 and IMU1' */
  for (ForEach_itr_b = 0; ForEach_itr_b < 2; ForEach_itr_b++) {
    /* Update for Integrator: '<S31>/Integrator1' */
    QD2_DroneStack_Manual_2021a_DW.CoreSubsys[ForEach_itr_b].Integrator1_DWORK1 =
      false;

    /* Update for Integrator: '<S30>/Integrator1' */
    QD2_DroneStack_Manual_2021a_DW.CoreSubsys[ForEach_itr_b].
      Integrator1_DWORK1_b = false;
  }

  /* End of Update for SubSystem: '<S9>/For Each Subsystem - Iterate over IMU0 and IMU1' */
  if (tmp) {
    /* Update for Delay: '<S4>/Delay' */
    for (idxDelay = 0; idxDelay < 49; idxDelay++) {
      QD2_DroneStack_Manual_2021a_DW.Delay_DSTATE_l[idxDelay] =
        QD2_DroneStack_Manual_2021a_DW.Delay_DSTATE_l[idxDelay + 1];
    }

    QD2_DroneStack_Manual_2021a_DW.Delay_DSTATE_l[49] =
      QD2_DroneStack_Manual_2021a_B.StreamClient_o4[9];

    /* End of Update for Delay: '<S4>/Delay' */

    /* Update for Memory: '<S13>/Memory' */
    QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput_h[0] =
      QD2_DroneStack_Manual_2021a_B.ImpAsg_InsertedFor_ESCDataOu_kc[0];

    /* Update for Memory: '<S15>/Memory' */
    QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput_k[0] =
      QD2_DroneStack_Manual_2021a_B.ImpAsg_InsertedFor_ESCDataOut4_[0];

    /* Update for Memory: '<S14>/Memory' */
    QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput_a[0] =
      QD2_DroneStack_Manual_2021a_B.ImpAsg_InsertedFor_ESCDataOut_k[0];

    /* Update for Memory: '<S13>/Memory' */
    QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput_h[1] =
      QD2_DroneStack_Manual_2021a_B.ImpAsg_InsertedFor_ESCDataOu_kc[1];

    /* Update for Memory: '<S15>/Memory' */
    QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput_k[1] =
      QD2_DroneStack_Manual_2021a_B.ImpAsg_InsertedFor_ESCDataOut4_[1];

    /* Update for Memory: '<S14>/Memory' */
    QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput_a[1] =
      QD2_DroneStack_Manual_2021a_B.ImpAsg_InsertedFor_ESCDataOut_k[1];

    /* Update for Memory: '<S13>/Memory' */
    QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput_h[2] =
      QD2_DroneStack_Manual_2021a_B.ImpAsg_InsertedFor_ESCDataOu_kc[2];

    /* Update for Memory: '<S15>/Memory' */
    QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput_k[2] =
      QD2_DroneStack_Manual_2021a_B.ImpAsg_InsertedFor_ESCDataOut4_[2];

    /* Update for Memory: '<S14>/Memory' */
    QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput_a[2] =
      QD2_DroneStack_Manual_2021a_B.ImpAsg_InsertedFor_ESCDataOut_k[2];

    /* Update for Memory: '<S13>/Memory' */
    QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput_h[3] =
      QD2_DroneStack_Manual_2021a_B.ImpAsg_InsertedFor_ESCDataOu_kc[3];

    /* Update for Memory: '<S15>/Memory' */
    QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput_k[3] =
      QD2_DroneStack_Manual_2021a_B.ImpAsg_InsertedFor_ESCDataOut4_[3];

    /* Update for Memory: '<S14>/Memory' */
    QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput_a[3] =
      QD2_DroneStack_Manual_2021a_B.ImpAsg_InsertedFor_ESCDataOut_k[3];

    /* Update for Delay: '<S16>/Delay3' */
    QD2_DroneStack_Manual_2021a_DW.Delay3_DSTATE[0] =
      QD2_DroneStack_Manual_2021a_DW.Delay3_DSTATE[1];
    QD2_DroneStack_Manual_2021a_DW.Delay3_DSTATE[1] =
      QD2_DroneStack_Manual_2021a_B.Selector[0];

    /* Update for Delay: '<S16>/Delay2' */
    QD2_DroneStack_Manual_2021a_DW.Delay2_DSTATE[0] =
      QD2_DroneStack_Manual_2021a_DW.Delay2_DSTATE[1];
    QD2_DroneStack_Manual_2021a_DW.Delay2_DSTATE[1] =
      QD2_DroneStack_Manual_2021a_B.Selector[1];

    /* Update for Delay: '<S16>/Delay1' */
    QD2_DroneStack_Manual_2021a_DW.Delay1_DSTATE[0] =
      QD2_DroneStack_Manual_2021a_DW.Delay1_DSTATE[1];
    QD2_DroneStack_Manual_2021a_DW.Delay1_DSTATE[1] =
      QD2_DroneStack_Manual_2021a_B.Selector[2];

    /* Update for Delay: '<S16>/Delay' */
    QD2_DroneStack_Manual_2021a_DW.Delay_DSTATE_ln[0] =
      QD2_DroneStack_Manual_2021a_DW.Delay_DSTATE_ln[1];
    QD2_DroneStack_Manual_2021a_DW.Delay_DSTATE_ln[1] =
      QD2_DroneStack_Manual_2021a_B.Selector[3];

    /* Update for DiscreteIntegrator: '<S42>/Discrete-Time Integrator' */
    QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE +=
      QD2_DroneStack_Manual_2021a_P.DiscreteTimeIntegrator_gainval *
      QD2_DroneStack_Manual_2021a_B.DataTypeConversion;
    QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
      QD2_DroneStack_Manual_2021a_B.LogicalOperator;

    /* Update for DiscreteIntegrator: '<S26>/Discrete-Time Integrator' */
    QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE_j +=
      QD2_DroneStack_Manual_2021a_P.DiscreteTimeIntegrator_gainva_b *
      QD2_DroneStack_Manual_2021a_B.DataTypeConversion_h;
    QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_PrevRe_h = (int8_T)
      QD2_DroneStack_Manual_2021a_B.LogicalOperator_f;

    /* Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
    QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE_k +=
      QD2_DroneStack_Manual_2021a_P.DiscreteTimeIntegrator_gainva_o *
      QD2_DroneStack_Manual_2021a_B.DataTypeConversion_k;
    QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_PrevR_hs = (int8_T)
      QD2_DroneStack_Manual_2021a_B.LogicalOperator_p;

    /* Update for DiscreteIntegrator: '<S8>/Discrete-Time Integrator' */
    QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE_e +=
      QD2_DroneStack_Manual_2021a_P.DiscreteTimeIntegrator_gainva_j *
      QD2_DroneStack_Manual_2021a_B.DataTypeConversion_cz;
    QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_PrevRe_b = (int8_T)
      QD2_DroneStack_Manual_2021a_B.LogicalOperator_m;

    /* Update for DiscreteIntegrator: '<S60>/Discrete-Time Integrator' */
    QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE_l +=
      QD2_DroneStack_Manual_2021a_P.DiscreteTimeIntegrator_gainv_bm *
      QD2_DroneStack_Manual_2021a_B.DataTypeConversion_a;
    QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_PrevRe_j = (int8_T)
      QD2_DroneStack_Manual_2021a_B.LogicalOperator_a;

    /* Update for DiscreteIntegrator: '<S59>/Discrete-Time Integrator' */
    QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_DSTAT_lx +=
      QD2_DroneStack_Manual_2021a_P.DiscreteTimeIntegrator_gainv_b1 *
      QD2_DroneStack_Manual_2021a_B.DataTypeConversion_p;
    QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_PrevRe_k = (int8_T)
      QD2_DroneStack_Manual_2021a_B.LogicalOperator_k;
  }

  if (rtmIsMajorTimeStep(QD2_DroneStack_Manual_2021a_M)) {
    rt_ertODEUpdateContinuousStates(&QD2_DroneStack_Manual_2021a_M->solverInfo);
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
  if (!(++QD2_DroneStack_Manual_2021a_M->Timing.clockTick0)) {
    ++QD2_DroneStack_Manual_2021a_M->Timing.clockTickH0;
  }

  QD2_DroneStack_Manual_2021a_M->Timing.t[0] = rtsiGetSolverStopTime
    (&QD2_DroneStack_Manual_2021a_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++QD2_DroneStack_Manual_2021a_M->Timing.clockTick1)) {
    ++QD2_DroneStack_Manual_2021a_M->Timing.clockTickH1;
  }

  QD2_DroneStack_Manual_2021a_M->Timing.t[1] =
    QD2_DroneStack_Manual_2021a_M->Timing.clockTick1 *
    QD2_DroneStack_Manual_2021a_M->Timing.stepSize1 +
    QD2_DroneStack_Manual_2021a_M->Timing.clockTickH1 *
    QD2_DroneStack_Manual_2021a_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void QD2_DroneStack_Manual_2021a_derivatives(void)
{
  /* local scratch DWork variables */
  int32_T ForEach_itr_b;
  XDot_QD2_DroneStack_Manual_20_T *_rtXdot;
  _rtXdot = ((XDot_QD2_DroneStack_Manual_20_T *)
             QD2_DroneStack_Manual_2021a_M->derivs);

  /* Derivatives for Iterator SubSystem: '<S9>/For Each Subsystem - Iterate over IMU0 and IMU1' */
  for (ForEach_itr_b = 0; ForEach_itr_b < 2; ForEach_itr_b++) {
    /* Derivatives for Integrator: '<S31>/Integrator1' incorporates:
     *  Product: '<S31>/Product1'
     */
    _rtXdot->CoreSubsys[ForEach_itr_b].Integrator1_CSTATE[0] =
      QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Product1_e[0];
    _rtXdot->CoreSubsys[ForEach_itr_b].Integrator1_CSTATE[1] =
      QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Product1_e[1];
    _rtXdot->CoreSubsys[ForEach_itr_b].Integrator1_CSTATE[2] =
      QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Product1_e[2];

    /* Derivatives for Integrator: '<S28>/Integrator1' */
    _rtXdot->CoreSubsys[ForEach_itr_b].Integrator1_CSTATE_h[0] =
      QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Sum1[0];
    _rtXdot->CoreSubsys[ForEach_itr_b].Integrator1_CSTATE_h[1] =
      QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Sum1[1];

    /* Derivatives for Integrator: '<S28>/Integrator2' */
    _rtXdot->CoreSubsys[ForEach_itr_b].Integrator2_CSTATE =
      QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Integrator1[2];

    /* Derivatives for Integrator: '<S30>/Integrator1' incorporates:
     *  Product: '<S30>/Product1'
     */
    _rtXdot->CoreSubsys[ForEach_itr_b].Integrator1_CSTATE_h5[0] =
      QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Product1[0];

    /* Derivatives for Integrator: '<S30>/Integrator2' incorporates:
     *  Product: '<S30>/Product'
     */
    _rtXdot->CoreSubsys[ForEach_itr_b].Integrator2_CSTATE_k[0] =
      QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Product[0];

    /* Derivatives for Integrator: '<S30>/Integrator1' incorporates:
     *  Product: '<S30>/Product1'
     */
    _rtXdot->CoreSubsys[ForEach_itr_b].Integrator1_CSTATE_h5[1] =
      QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Product1[1];

    /* Derivatives for Integrator: '<S30>/Integrator2' incorporates:
     *  Product: '<S30>/Product'
     */
    _rtXdot->CoreSubsys[ForEach_itr_b].Integrator2_CSTATE_k[1] =
      QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Product[1];

    /* Derivatives for Integrator: '<S30>/Integrator1' incorporates:
     *  Product: '<S30>/Product1'
     */
    _rtXdot->CoreSubsys[ForEach_itr_b].Integrator1_CSTATE_h5[2] =
      QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Product1[2];

    /* Derivatives for Integrator: '<S30>/Integrator2' incorporates:
     *  Product: '<S30>/Product'
     */
    _rtXdot->CoreSubsys[ForEach_itr_b].Integrator2_CSTATE_k[2] =
      QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Product[2];

    /* Derivatives for Integrator: '<S28>/Integrator' */
    _rtXdot->CoreSubsys[ForEach_itr_b].Integrator_CSTATE[0] =
      QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Gain1[0];
    _rtXdot->CoreSubsys[ForEach_itr_b].Integrator_CSTATE[1] =
      QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Gain1[1];

    /* Derivatives for Integrator: '<S31>/Integrator2' incorporates:
     *  Product: '<S31>/Product'
     */
    _rtXdot->CoreSubsys[ForEach_itr_b].Integrator2_CSTATE_e[0] =
      QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Product_j[0];
    _rtXdot->CoreSubsys[ForEach_itr_b].Integrator2_CSTATE_e[1] =
      QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Product_j[1];
    _rtXdot->CoreSubsys[ForEach_itr_b].Integrator2_CSTATE_e[2] =
      QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Product_j[2];
  }

  /* End of Derivatives for SubSystem: '<S9>/For Each Subsystem - Iterate over IMU0 and IMU1' */
}

/* Model output function for TID2 */
void QD2_DroneStack_Manual_2021a_output2(void) /* Sample time: [0.004s, 0.0s] */
{
  /* local block i/o variables */
  boolean_T rtb_StreamServer_o3;
  boolean_T rtb_StreamServer_o5;
  real_T rtb_TmpSignalConversionAtStream[47];
  boolean_T rtb_Memory3;

  /* SignalConversion generated from: '<S2>/Stream Server' incorporates:
   *  Memory: '<S2>/Memory2'
   *  RateTransition: '<S2>/Rate Transition10'
   *  RateTransition: '<S2>/Rate Transition11'
   *  RateTransition: '<S2>/Rate Transition12'
   *  RateTransition: '<S2>/Rate Transition15'
   *  RateTransition: '<S2>/Rate Transition17'
   *  RateTransition: '<S2>/Rate Transition19'
   *  RateTransition: '<S2>/Rate Transition20'
   *  RateTransition: '<S2>/Rate Transition8'
   */
  memcpy(&rtb_TmpSignalConversionAtStream[0],
         &QD2_DroneStack_Manual_2021a_DW.RateTransition8_Buffer[0], 12U * sizeof
         (real_T));
  memcpy(&rtb_TmpSignalConversionAtStream[12],
         &QD2_DroneStack_Manual_2021a_DW.RateTransition15_Buffer[0], 9U * sizeof
         (real_T));
  memcpy(&rtb_TmpSignalConversionAtStream[21],
         &QD2_DroneStack_Manual_2021a_DW.RateTransition17_Buffer[0], 9U * sizeof
         (real_T));
  memcpy(&rtb_TmpSignalConversionAtStream[30],
         &QD2_DroneStack_Manual_2021a_DW.RateTransition19_Buffer[0], 9U * sizeof
         (real_T));
  rtb_TmpSignalConversionAtStream[39] =
    QD2_DroneStack_Manual_2021a_DW.RateTransition20_Buffer;
  rtb_TmpSignalConversionAtStream[40] =
    QD2_DroneStack_Manual_2021a_DW.RateTransition10_Buffer[0];
  rtb_TmpSignalConversionAtStream[41] =
    QD2_DroneStack_Manual_2021a_DW.RateTransition10_Buffer[1];
  rtb_TmpSignalConversionAtStream[42] =
    QD2_DroneStack_Manual_2021a_DW.RateTransition10_Buffer[2];
  rtb_TmpSignalConversionAtStream[43] =
    QD2_DroneStack_Manual_2021a_DW.RateTransition10_Buffer[3];
  rtb_TmpSignalConversionAtStream[44] =
    QD2_DroneStack_Manual_2021a_DW.RateTransition12_Buffer;
  rtb_TmpSignalConversionAtStream[45] =
    QD2_DroneStack_Manual_2021a_DW.RateTransition11_Buffer;
  rtb_TmpSignalConversionAtStream[46] =
    QD2_DroneStack_Manual_2021a_DW.Memory2_PreviousInput;

  /* Memory: '<S2>/Memory3' */
  rtb_Memory3 = QD2_DroneStack_Manual_2021a_DW.Memory3_PreviousInput;

  /* RateTransition: '<S2>/Rate Transition14' incorporates:
   *  RateTransition: '<S2>/Rate Transition16'
   *  S-Function (stream_server_block): '<S2>/Stream Server'
   */

  /* S-Function Block: QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Stream Server (stream_server_block) */
  {
    t_pstream_state state;
    t_error send_result;
    t_error receive_result;
    if (rtb_Memory3) {
      send_result = pstream_send
        (QD2_DroneStack_Manual_2021a_DW.StreamServer_Stream,
         &rtb_TmpSignalConversionAtStream[0]);
    } else {
      send_result = 0;
    }

    rtb_StreamServer_o3 = (send_result > 0);
    receive_result = pstream_receive
      (QD2_DroneStack_Manual_2021a_DW.StreamServer_Stream,
       &QD2_DroneStack_Manual_2021a_B.StreamServer_o4);
    rtb_StreamServer_o5 = (receive_result > 0);
    QD2_DroneStack_Manual_2021a_B.RateTransition14 = 0;
    if (send_result < 0 && send_result != -QERR_WOULD_BLOCK) {
      QD2_DroneStack_Manual_2021a_B.RateTransition14 = send_result;
    } else if (receive_result < 0 && receive_result != -QERR_WOULD_BLOCK) {
      QD2_DroneStack_Manual_2021a_B.RateTransition14 = receive_result;
    }

    pstream_get_state(QD2_DroneStack_Manual_2021a_DW.StreamServer_Stream, &state);
    QD2_DroneStack_Manual_2021a_B.RateTransition16 = state;
  }

  /* Logic: '<S2>/AND' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S12>/Constant'
   *  RelationalOperator: '<S11>/Compare'
   *  RelationalOperator: '<S12>/Compare'
   */
  QD2_DroneStack_Manual_2021a_B.AND_g =
    ((QD2_DroneStack_Manual_2021a_B.RateTransition16 ==
      QD2_DroneStack_Manual_2021a_P.CompareToConstant_const_e) &&
     (QD2_DroneStack_Manual_2021a_B.RateTransition14 >=
      QD2_DroneStack_Manual_2021a_P.CompareToConstant1_const));
}

/* Model update function for TID2 */
void QD2_DroneStack_Manual_2021a_update2(void) /* Sample time: [0.004s, 0.0s] */
{
  /* Update for Memory: '<S2>/Memory2' */
  QD2_DroneStack_Manual_2021a_DW.Memory2_PreviousInput =
    QD2_DroneStack_Manual_2021a_B.StreamServer_o4;

  /* Update for Memory: '<S2>/Memory3' */
  QD2_DroneStack_Manual_2021a_DW.Memory3_PreviousInput =
    QD2_DroneStack_Manual_2021a_B.AND_g;

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++QD2_DroneStack_Manual_2021a_M->Timing.clockTick2)) {
    ++QD2_DroneStack_Manual_2021a_M->Timing.clockTickH2;
  }

  QD2_DroneStack_Manual_2021a_M->Timing.t[2] =
    QD2_DroneStack_Manual_2021a_M->Timing.clockTick2 *
    QD2_DroneStack_Manual_2021a_M->Timing.stepSize2 +
    QD2_DroneStack_Manual_2021a_M->Timing.clockTickH2 *
    QD2_DroneStack_Manual_2021a_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output function for TID3 */
void QD2_DroneStack_Manual_2021a_output3(void) /* Sample time: [0.01s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_ComputationTime1;
  real_T rtb_SampleTime1;
  int32_T i;
  for (i = 0; i < 7; i++) {
    /* RateTransition: '<S2>/Rate Transition' */
    QD2_DroneStack_Manual_2021a_B.RateTransition_g[i] =
      QD2_DroneStack_Manual_2021a_DW.RateTransition_Buffer[i];
  }

  /* Constant: '<S18>/x0' */
  QD2_DroneStack_Manual_2021a_B.x0 = QD2_DroneStack_Manual_2021a_P.x0_Value;

  /* Product: '<S18>/Product' incorporates:
   *  Constant: '<S18>/Constant'
   *  Constant: '<S18>/bandwidth'
   *  Constant: '<S18>/zeta'
   *  DiscreteIntegrator: '<S18>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S18>/Discrete-Time Integrator1'
   *  Product: '<S18>/Product2'
   *  Sum: '<S18>/Sum'
   *  Sum: '<S18>/Sum1'
   */
  QD2_DroneStack_Manual_2021a_B.Product[0] =
    ((QD2_DroneStack_Manual_2021a_B.RateTransition_g[0] -
      QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator1_DSTATE[0]) -
     QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE_o[0] *
     QD2_DroneStack_Manual_2021a_P.Constant_Value_l *
     QD2_DroneStack_Manual_2021a_P.DiscreteSecondOrderLowPassFil_p) *
    QD2_DroneStack_Manual_2021a_P.DiscreteSecondOrderLowPassFilte;

  /* Product: '<S18>/Product1' incorporates:
   *  Constant: '<S18>/bandwidth'
   *  DiscreteIntegrator: '<S18>/Discrete-Time Integrator'
   */
  QD2_DroneStack_Manual_2021a_B.Product1[0] =
    QD2_DroneStack_Manual_2021a_P.DiscreteSecondOrderLowPassFilte *
    QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE_o[0];

  /* RateTransition: '<S2>/Rate Transition7' incorporates:
   *  DiscreteIntegrator: '<S18>/Discrete-Time Integrator1'
   */
  QD2_DroneStack_Manual_2021a_DW.RateTransition7_Buffer0[0] =
    QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator1_DSTATE[0];

  /* Product: '<S18>/Product' incorporates:
   *  Constant: '<S18>/Constant'
   *  Constant: '<S18>/bandwidth'
   *  Constant: '<S18>/zeta'
   *  DiscreteIntegrator: '<S18>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S18>/Discrete-Time Integrator1'
   *  Product: '<S18>/Product2'
   *  Sum: '<S18>/Sum'
   *  Sum: '<S18>/Sum1'
   */
  QD2_DroneStack_Manual_2021a_B.Product[1] =
    ((QD2_DroneStack_Manual_2021a_B.RateTransition_g[1] -
      QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator1_DSTATE[1]) -
     QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE_o[1] *
     QD2_DroneStack_Manual_2021a_P.Constant_Value_l *
     QD2_DroneStack_Manual_2021a_P.DiscreteSecondOrderLowPassFil_p) *
    QD2_DroneStack_Manual_2021a_P.DiscreteSecondOrderLowPassFilte;

  /* Product: '<S18>/Product1' incorporates:
   *  Constant: '<S18>/bandwidth'
   *  DiscreteIntegrator: '<S18>/Discrete-Time Integrator'
   */
  QD2_DroneStack_Manual_2021a_B.Product1[1] =
    QD2_DroneStack_Manual_2021a_P.DiscreteSecondOrderLowPassFilte *
    QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE_o[1];

  /* RateTransition: '<S2>/Rate Transition7' incorporates:
   *  DiscreteIntegrator: '<S18>/Discrete-Time Integrator1'
   */
  QD2_DroneStack_Manual_2021a_DW.RateTransition7_Buffer0[1] =
    QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator1_DSTATE[1];

  /* S-Function (computation_time_block): '<S27>/Computation Time1' */

  /* S-Function Block: QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Timing Monitors/Computation Time1 (computation_time_block) */
  {
    rtb_ComputationTime1 =
      QD2_DroneStack_Manual_2021a_DW.ComputationTime1_ComputationTim.seconds +
      QD2_DroneStack_Manual_2021a_DW.ComputationTime1_ComputationTim.nanoseconds
      * 1e-9;
  }

  /* RateTransition: '<S27>/Rate Transition' */
  QD2_DroneStack_Manual_2021a_DW.RateTransition_Buffer0 = rtb_ComputationTime1;

  /* S-Function (sample_time_block): '<S27>/Sample Time1' */

  /* S-Function Block: QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Timing Monitors/Sample Time1 (sample_time_block) */
  {
    t_error result;
    t_timeout current_time;
    t_timeout time_difference;
    result = timeout_get_high_resolution_time(&current_time);
    if (result >= 0) {
      result = timeout_subtract(&time_difference, &current_time,
        &QD2_DroneStack_Manual_2021a_DW.SampleTime1_PreviousTime);
      rtb_SampleTime1 = time_difference.seconds + time_difference.nanoseconds *
        1e-9;
      memcpy(&QD2_DroneStack_Manual_2021a_DW.SampleTime1_PreviousTime,
             &current_time, sizeof(t_timeout));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(QD2_DroneStack_Manual_2021a_M, _rt_error_message);
      return;
    }
  }

  /* RateTransition: '<S27>/Rate Transition1' */
  QD2_DroneStack_Manual_2021a_DW.RateTransition1_Buffer0_l = rtb_SampleTime1;
}

/* Model update function for TID3 */
void QD2_DroneStack_Manual_2021a_update3(void) /* Sample time: [0.01s, 0.0s] */
{
  /* Update for DiscreteIntegrator: '<S18>/Discrete-Time Integrator' */
  QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE_o[0] +=
    QD2_DroneStack_Manual_2021a_P.DiscreteTimeIntegrator_gainva_f *
    QD2_DroneStack_Manual_2021a_B.Product[0];

  /* Update for DiscreteIntegrator: '<S18>/Discrete-Time Integrator1' */
  QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator1_DSTATE[0] +=
    QD2_DroneStack_Manual_2021a_P.DiscreteTimeIntegrator1_gainval *
    QD2_DroneStack_Manual_2021a_B.Product1[0];

  /* Update for DiscreteIntegrator: '<S18>/Discrete-Time Integrator' */
  QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE_o[1] +=
    QD2_DroneStack_Manual_2021a_P.DiscreteTimeIntegrator_gainva_f *
    QD2_DroneStack_Manual_2021a_B.Product[1];

  /* Update for DiscreteIntegrator: '<S18>/Discrete-Time Integrator1' */
  QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator1_DSTATE[1] +=
    QD2_DroneStack_Manual_2021a_P.DiscreteTimeIntegrator1_gainval *
    QD2_DroneStack_Manual_2021a_B.Product1[1];

  /* Update absolute time */
  /* The "clockTick3" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick3"
   * and "Timing.stepSize3". Size of "clockTick3" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick3 and the high bits
   * Timing.clockTickH3. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++QD2_DroneStack_Manual_2021a_M->Timing.clockTick3)) {
    ++QD2_DroneStack_Manual_2021a_M->Timing.clockTickH3;
  }

  QD2_DroneStack_Manual_2021a_M->Timing.t[3] =
    QD2_DroneStack_Manual_2021a_M->Timing.clockTick3 *
    QD2_DroneStack_Manual_2021a_M->Timing.stepSize3 +
    QD2_DroneStack_Manual_2021a_M->Timing.clockTickH3 *
    QD2_DroneStack_Manual_2021a_M->Timing.stepSize3 * 4294967296.0;
}

/* Model output function for TID4 */
void QD2_DroneStack_Manual_2021a_output4(void) /* Sample time: [0.04s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_ComputationTime2;
  real_T rtb_SampleTime2;
  real_T rtb_MatrixMultiply[3];
  real_T rtb_DiscreteTimeIntegrator1_h;
  real_T rtb_MatrixMultiply_0;
  int32_T i;

  /* Constant: '<S2>/ToF Filter Initial Condition (m)' */
  QD2_DroneStack_Manual_2021a_B.ToFFilterInitialConditionm =
    QD2_DroneStack_Manual_2021a_P.ToFFilterInitialConditionm_Valu;

  /* DiscreteIntegrator: '<S17>/Discrete-Time Integrator1' */
  rtb_DiscreteTimeIntegrator1_h =
    QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator1_DSTAT_d;

  /* S-Function (ranging_sensor_block): '<S2>/Ranging Sensor' */

  /* S-Function Block: QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Ranging Sensor (ranging_sensor_block) */
  {
    t_error result;
    result = vl53l1x_read(QD2_DroneStack_Manual_2021a_DW.RangingSensor_Sensor,
                          &QD2_DroneStack_Manual_2021a_DW.RangingSensor_Measurements);
    if (result >= 0) {
      QD2_DroneStack_Manual_2021a_B.RangingSensor_o1 =
        QD2_DroneStack_Manual_2021a_DW.RangingSensor_Measurements.distance;
    } else {
      if (result != -QERR_WOULD_BLOCK) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QD2_DroneStack_Manual_2021a_M, _rt_error_message);
      }
    }
  }

  /* Product: '<S17>/Product' incorporates:
   *  Constant: '<S17>/Constant'
   *  Constant: '<S2>/ToF Filter Cutoff Frequency (rad)'
   *  Constant: '<S2>/ToF Filter Damping Ratio'
   *  DiscreteIntegrator: '<S17>/Discrete-Time Integrator'
   *  Product: '<S17>/Product2'
   *  Sum: '<S17>/Sum'
   *  Sum: '<S17>/Sum1'
   */
  QD2_DroneStack_Manual_2021a_B.Product_k =
    ((QD2_DroneStack_Manual_2021a_B.RangingSensor_o1 -
      rtb_DiscreteTimeIntegrator1_h) -
     QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE_a *
     QD2_DroneStack_Manual_2021a_P.Constant_Value_n *
     QD2_DroneStack_Manual_2021a_P.ToFFilterDampingRatio_Value) *
    QD2_DroneStack_Manual_2021a_P.ToFFilterCutoffFrequencyrad_Val;

  /* Product: '<S17>/Product1' incorporates:
   *  Constant: '<S2>/ToF Filter Cutoff Frequency (rad)'
   *  DiscreteIntegrator: '<S17>/Discrete-Time Integrator'
   */
  QD2_DroneStack_Manual_2021a_B.Product1_p =
    QD2_DroneStack_Manual_2021a_P.ToFFilterCutoffFrequencyrad_Val *
    QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE_a;

  /* SignalConversion generated from: '<S2>/Matrix Multiply' incorporates:
   *  Constant: '<S2>/ToF Sensor XY Offsets (m)'
   */
  rtb_MatrixMultiply[0] =
    QD2_DroneStack_Manual_2021a_P.ToFSensorXYOffsetsm_Value[0];
  rtb_MatrixMultiply[1] =
    QD2_DroneStack_Manual_2021a_P.ToFSensorXYOffsetsm_Value[1];
  rtb_MatrixMultiply[2] = rtb_DiscreteTimeIntegrator1_h;

  /* Product: '<S2>/Matrix Multiply' incorporates:
   *  RateTransition: '<S2>/Rate Transition3'
   */
  rtb_MatrixMultiply_0 = 0.0;
  for (i = 0; i < 3; i++) {
    rtb_MatrixMultiply_0 +=
      QD2_DroneStack_Manual_2021a_DW.RateTransition3_Buffer[3 * i + 2] *
      rtb_MatrixMultiply[i];
  }

  rtb_MatrixMultiply[2] = rtb_MatrixMultiply_0;

  /* End of Product: '<S2>/Matrix Multiply' */

  /* RateTransition: '<S2>/Rate Transition1' */
  QD2_DroneStack_Manual_2021a_DW.RateTransition1_Buffer0 = rtb_MatrixMultiply[2];

  /* RateTransition: '<S2>/Rate Transition2' */
  QD2_DroneStack_Manual_2021a_DW.RateTransition2_Buffer0 =
    rtb_DiscreteTimeIntegrator1_h;

  /* S-Function (computation_time_block): '<S27>/Computation Time2' */

  /* S-Function Block: QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Timing Monitors/Computation Time2 (computation_time_block) */
  {
    rtb_ComputationTime2 =
      QD2_DroneStack_Manual_2021a_DW.ComputationTime2_ComputationTim.seconds +
      QD2_DroneStack_Manual_2021a_DW.ComputationTime2_ComputationTim.nanoseconds
      * 1e-9;
  }

  /* RateTransition: '<S27>/Rate Transition2' */
  QD2_DroneStack_Manual_2021a_DW.RateTransition2_Buffer0_l =
    rtb_ComputationTime2;

  /* S-Function (sample_time_block): '<S27>/Sample Time2' */

  /* S-Function Block: QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Timing Monitors/Sample Time2 (sample_time_block) */
  {
    t_error result;
    t_timeout current_time;
    t_timeout time_difference;
    result = timeout_get_high_resolution_time(&current_time);
    if (result >= 0) {
      result = timeout_subtract(&time_difference, &current_time,
        &QD2_DroneStack_Manual_2021a_DW.SampleTime2_PreviousTime);
      rtb_SampleTime2 = time_difference.seconds + time_difference.nanoseconds *
        1e-9;
      memcpy(&QD2_DroneStack_Manual_2021a_DW.SampleTime2_PreviousTime,
             &current_time, sizeof(t_timeout));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(QD2_DroneStack_Manual_2021a_M, _rt_error_message);
      return;
    }
  }

  /* RateTransition: '<S27>/Rate Transition3' */
  QD2_DroneStack_Manual_2021a_DW.RateTransition3_Buffer0 = rtb_SampleTime2;
}

/* Model update function for TID4 */
void QD2_DroneStack_Manual_2021a_update4(void) /* Sample time: [0.04s, 0.0s] */
{
  /* Update for DiscreteIntegrator: '<S17>/Discrete-Time Integrator' */
  QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE_a +=
    QD2_DroneStack_Manual_2021a_P.DiscreteTimeIntegrator_gainv_o5 *
    QD2_DroneStack_Manual_2021a_B.Product_k;

  /* Update for DiscreteIntegrator: '<S17>/Discrete-Time Integrator1' */
  QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator1_DSTAT_d +=
    QD2_DroneStack_Manual_2021a_P.DiscreteTimeIntegrator1_gainv_i *
    QD2_DroneStack_Manual_2021a_B.Product1_p;

  /* Update absolute time */
  /* The "clockTick4" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick4"
   * and "Timing.stepSize4". Size of "clockTick4" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick4 and the high bits
   * Timing.clockTickH4. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++QD2_DroneStack_Manual_2021a_M->Timing.clockTick4)) {
    ++QD2_DroneStack_Manual_2021a_M->Timing.clockTickH4;
  }

  QD2_DroneStack_Manual_2021a_M->Timing.t[4] =
    QD2_DroneStack_Manual_2021a_M->Timing.clockTick4 *
    QD2_DroneStack_Manual_2021a_M->Timing.stepSize4 +
    QD2_DroneStack_Manual_2021a_M->Timing.clockTickH4 *
    QD2_DroneStack_Manual_2021a_M->Timing.stepSize4 * 4294967296.0;
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void QD2_DroneStack_Manual_2021a_output(int_T tid)
{
  switch (tid) {
   case 0 :
    QD2_DroneStack_Manual_2021a_output0();
    break;

   case 2 :
    QD2_DroneStack_Manual_2021a_output2();
    break;

   case 3 :
    QD2_DroneStack_Manual_2021a_output3();
    break;

   case 4 :
    QD2_DroneStack_Manual_2021a_output4();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void QD2_DroneStack_Manual_2021a_update(int_T tid)
{
  switch (tid) {
   case 0 :
    QD2_DroneStack_Manual_2021a_update0();
    break;

   case 2 :
    QD2_DroneStack_Manual_2021a_update2();
    break;

   case 3 :
    QD2_DroneStack_Manual_2021a_update3();
    break;

   case 4 :
    QD2_DroneStack_Manual_2021a_update4();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void QD2_DroneStack_Manual_2021a_initialize(void)
{
  {
    /* local scratch DWork variables */
    int32_T ForEach_itr_b;

    /* Start for S-Function (hil_initialize_block): '<S2>/HIL Initialize' */

    /* S-Function Block: QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/HIL Initialize (hil_initialize_block) */
    {
      t_int result;
      t_boolean is_switching;
      result = hil_open("qdrone2", "0",
                        &QD2_DroneStack_Manual_2021a_DW.HILInitialize_Card);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QD2_DroneStack_Manual_2021a_M, _rt_error_message);
        return;
      }

      is_switching = false;
      result = hil_set_card_specific_options
        (QD2_DroneStack_Manual_2021a_DW.HILInitialize_Card,
         "gyro0_fs=250;gyro0_rate=500;gyro0_bw=125;gyro0_ord=3;accel0_fs=16;accel0_rate=1000;accel0_bw=250;accel0_ord=3;temp0_bw=4000;gyro1_fs=250;gyro1_rate=500;gyro1_bw=125;gyro1_ord=3;accel1_fs=16;accel1_rate=1000;accel1_bw=400;accel1_ord=3;temp1_bw=4000;enc0_dir=0;enc1_dir=0;pwm03_dshot=1;opt_rate=121;",
         298);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QD2_DroneStack_Manual_2021a_M, _rt_error_message);
        return;
      }

      result = hil_watchdog_clear
        (QD2_DroneStack_Manual_2021a_DW.HILInitialize_Card);
      if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QD2_DroneStack_Manual_2021a_M, _rt_error_message);
        return;
      }

      if ((QD2_DroneStack_Manual_2021a_P.HILInitialize_AIPStart && !is_switching)
          || (QD2_DroneStack_Manual_2021a_P.HILInitialize_AIPEnter &&
              is_switching)) {
        QD2_DroneStack_Manual_2021a_DW.HILInitialize_AIMinimums[0] =
          QD2_DroneStack_Manual_2021a_P.HILInitialize_AILow;
        QD2_DroneStack_Manual_2021a_DW.HILInitialize_AIMinimums[1] =
          QD2_DroneStack_Manual_2021a_P.HILInitialize_AILow;
        QD2_DroneStack_Manual_2021a_DW.HILInitialize_AIMinimums[2] =
          QD2_DroneStack_Manual_2021a_P.HILInitialize_AILow;
        QD2_DroneStack_Manual_2021a_DW.HILInitialize_AIMinimums[3] =
          QD2_DroneStack_Manual_2021a_P.HILInitialize_AILow;
        QD2_DroneStack_Manual_2021a_DW.HILInitialize_AIMaximums[0] =
          QD2_DroneStack_Manual_2021a_P.HILInitialize_AIHigh;
        QD2_DroneStack_Manual_2021a_DW.HILInitialize_AIMaximums[1] =
          QD2_DroneStack_Manual_2021a_P.HILInitialize_AIHigh;
        QD2_DroneStack_Manual_2021a_DW.HILInitialize_AIMaximums[2] =
          QD2_DroneStack_Manual_2021a_P.HILInitialize_AIHigh;
        QD2_DroneStack_Manual_2021a_DW.HILInitialize_AIMaximums[3] =
          QD2_DroneStack_Manual_2021a_P.HILInitialize_AIHigh;
        result = hil_set_analog_input_ranges
          (QD2_DroneStack_Manual_2021a_DW.HILInitialize_Card,
           QD2_DroneStack_Manual_2021a_P.HILInitialize_AIChannels, 4U,
           &QD2_DroneStack_Manual_2021a_DW.HILInitialize_AIMinimums[0],
           &QD2_DroneStack_Manual_2021a_DW.HILInitialize_AIMaximums[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(QD2_DroneStack_Manual_2021a_M, _rt_error_message);
          return;
        }
      }

      result = hil_set_digital_directions
        (QD2_DroneStack_Manual_2021a_DW.HILInitialize_Card,
         QD2_DroneStack_Manual_2021a_P.HILInitialize_DIChannels, 6U,
         QD2_DroneStack_Manual_2021a_P.HILInitialize_DOChannels, 6U);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QD2_DroneStack_Manual_2021a_M, _rt_error_message);
        return;
      }

      if ((QD2_DroneStack_Manual_2021a_P.HILInitialize_DOStart && !is_switching)
          || (QD2_DroneStack_Manual_2021a_P.HILInitialize_DOEnter &&
              is_switching)) {
        {
          int_T i1;
          boolean_T *dw_DOBits =
            &QD2_DroneStack_Manual_2021a_DW.HILInitialize_DOBits[0];
          for (i1=0; i1 < 6; i1++) {
            dw_DOBits[i1] =
              QD2_DroneStack_Manual_2021a_P.HILInitialize_DOInitial;
          }
        }

        result = hil_write_digital
          (QD2_DroneStack_Manual_2021a_DW.HILInitialize_Card,
           QD2_DroneStack_Manual_2021a_P.HILInitialize_DOChannels, 6U,
           (t_boolean *) &QD2_DroneStack_Manual_2021a_DW.HILInitialize_DOBits[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(QD2_DroneStack_Manual_2021a_M, _rt_error_message);
          return;
        }
      }

      if (QD2_DroneStack_Manual_2021a_P.HILInitialize_DOReset) {
        result = hil_watchdog_set_digital_expiration_state
          (QD2_DroneStack_Manual_2021a_DW.HILInitialize_Card,
           QD2_DroneStack_Manual_2021a_P.HILInitialize_DOChannels, 6U, (const
            t_digital_state *)
           QD2_DroneStack_Manual_2021a_P.HILInitialize_DOWatchdog);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(QD2_DroneStack_Manual_2021a_M, _rt_error_message);
          return;
        }
      }

      if ((QD2_DroneStack_Manual_2021a_P.HILInitialize_EIPStart && !is_switching)
          || (QD2_DroneStack_Manual_2021a_P.HILInitialize_EIPEnter &&
              is_switching)) {
        QD2_DroneStack_Manual_2021a_DW.HILInitialize_QuadratureModes[0] =
          QD2_DroneStack_Manual_2021a_P.HILInitialize_EIQuadrature;
        QD2_DroneStack_Manual_2021a_DW.HILInitialize_QuadratureModes[1] =
          QD2_DroneStack_Manual_2021a_P.HILInitialize_EIQuadrature;
        result = hil_set_encoder_quadrature_mode
          (QD2_DroneStack_Manual_2021a_DW.HILInitialize_Card,
           QD2_DroneStack_Manual_2021a_P.HILInitialize_EIChannels, 2U,
           (t_encoder_quadrature_mode *)
           &QD2_DroneStack_Manual_2021a_DW.HILInitialize_QuadratureModes[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(QD2_DroneStack_Manual_2021a_M, _rt_error_message);
          return;
        }

        QD2_DroneStack_Manual_2021a_DW.HILInitialize_FilterFrequency[0] =
          QD2_DroneStack_Manual_2021a_P.HILInitialize_EIFrequency;
        QD2_DroneStack_Manual_2021a_DW.HILInitialize_FilterFrequency[1] =
          QD2_DroneStack_Manual_2021a_P.HILInitialize_EIFrequency;
        result = hil_set_encoder_filter_frequency
          (QD2_DroneStack_Manual_2021a_DW.HILInitialize_Card,
           QD2_DroneStack_Manual_2021a_P.HILInitialize_EIChannels, 2U,
           &QD2_DroneStack_Manual_2021a_DW.HILInitialize_FilterFrequency[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(QD2_DroneStack_Manual_2021a_M, _rt_error_message);
          return;
        }
      }

      if ((QD2_DroneStack_Manual_2021a_P.HILInitialize_EIStart && !is_switching)
          || (QD2_DroneStack_Manual_2021a_P.HILInitialize_EIEnter &&
              is_switching)) {
        QD2_DroneStack_Manual_2021a_DW.HILInitialize_InitialEICounts[0] =
          QD2_DroneStack_Manual_2021a_P.HILInitialize_EIInitial;
        QD2_DroneStack_Manual_2021a_DW.HILInitialize_InitialEICounts[1] =
          QD2_DroneStack_Manual_2021a_P.HILInitialize_EIInitial;
        result = hil_set_encoder_counts
          (QD2_DroneStack_Manual_2021a_DW.HILInitialize_Card,
           QD2_DroneStack_Manual_2021a_P.HILInitialize_EIChannels, 2U,
           &QD2_DroneStack_Manual_2021a_DW.HILInitialize_InitialEICounts[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(QD2_DroneStack_Manual_2021a_M, _rt_error_message);
          return;
        }
      }

      if ((QD2_DroneStack_Manual_2021a_P.HILInitialize_POPStart && !is_switching)
          || (QD2_DroneStack_Manual_2021a_P.HILInitialize_POPEnter &&
              is_switching)) {
        uint32_T num_duty_cycle_modes = 0;
        uint32_T num_frequency_modes = 0;
        QD2_DroneStack_Manual_2021a_DW.HILInitialize_POModeValues[0] =
          (QD2_DroneStack_Manual_2021a_P.HILInitialize_POModes[0]);
        QD2_DroneStack_Manual_2021a_DW.HILInitialize_POModeValues[1] =
          (QD2_DroneStack_Manual_2021a_P.HILInitialize_POModes[1]);
        QD2_DroneStack_Manual_2021a_DW.HILInitialize_POModeValues[2] =
          (QD2_DroneStack_Manual_2021a_P.HILInitialize_POModes[2]);
        QD2_DroneStack_Manual_2021a_DW.HILInitialize_POModeValues[3] =
          (QD2_DroneStack_Manual_2021a_P.HILInitialize_POModes[3]);
        QD2_DroneStack_Manual_2021a_DW.HILInitialize_POModeValues[4] =
          (QD2_DroneStack_Manual_2021a_P.HILInitialize_POModes[4]);
        QD2_DroneStack_Manual_2021a_DW.HILInitialize_POModeValues[5] =
          (QD2_DroneStack_Manual_2021a_P.HILInitialize_POModes[4]);
        result = hil_set_pwm_mode
          (QD2_DroneStack_Manual_2021a_DW.HILInitialize_Card,
           QD2_DroneStack_Manual_2021a_P.HILInitialize_POChannels, 6U,
           (t_pwm_mode *)
           &QD2_DroneStack_Manual_2021a_DW.HILInitialize_POModeValues[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(QD2_DroneStack_Manual_2021a_M, _rt_error_message);
          return;
        }

        {
          int_T i1;
          const uint32_T *p_HILInitialize_POChannels =
            QD2_DroneStack_Manual_2021a_P.HILInitialize_POChannels;
          int32_T *dw_POModeValues =
            &QD2_DroneStack_Manual_2021a_DW.HILInitialize_POModeValues[0];
          for (i1=0; i1 < 6; i1++) {
            if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1]
                == PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE ||
                dw_POModeValues[i1] == PWM_RAW_MODE) {
              QD2_DroneStack_Manual_2021a_DW.HILInitialize_POSortedChans[num_duty_cycle_modes]
                = (p_HILInitialize_POChannels[i1]);
              QD2_DroneStack_Manual_2021a_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]
                = QD2_DroneStack_Manual_2021a_P.HILInitialize_POFrequency;
              num_duty_cycle_modes++;
            } else {
              QD2_DroneStack_Manual_2021a_DW.HILInitialize_POSortedChans[5U -
                num_frequency_modes] = (p_HILInitialize_POChannels[i1]);
              QD2_DroneStack_Manual_2021a_DW.HILInitialize_POSortedFreqs[5U -
                num_frequency_modes] =
                QD2_DroneStack_Manual_2021a_P.HILInitialize_POFrequency;
              num_frequency_modes++;
            }
          }
        }

        if (num_duty_cycle_modes > 0) {
          result = hil_set_pwm_frequency
            (QD2_DroneStack_Manual_2021a_DW.HILInitialize_Card,
             &QD2_DroneStack_Manual_2021a_DW.HILInitialize_POSortedChans[0],
             num_duty_cycle_modes,
             &QD2_DroneStack_Manual_2021a_DW.HILInitialize_POSortedFreqs[0]);
          if (result < 0) {
            msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
              (_rt_error_message));
            rtmSetErrorStatus(QD2_DroneStack_Manual_2021a_M, _rt_error_message);
            return;
          }
        }

        if (num_frequency_modes > 0) {
          result = hil_set_pwm_duty_cycle
            (QD2_DroneStack_Manual_2021a_DW.HILInitialize_Card,
             &QD2_DroneStack_Manual_2021a_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
             num_frequency_modes,
             &QD2_DroneStack_Manual_2021a_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
          if (result < 0) {
            msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
              (_rt_error_message));
            rtmSetErrorStatus(QD2_DroneStack_Manual_2021a_M, _rt_error_message);
            return;
          }
        }

        {
          int_T i1;
          int32_T *dw_POModeValues =
            &QD2_DroneStack_Manual_2021a_DW.HILInitialize_POModeValues[0];
          for (i1=0; i1 < 6; i1++) {
            dw_POModeValues[i1] =
              QD2_DroneStack_Manual_2021a_P.HILInitialize_POConfiguration;
          }
        }

        {
          int_T i1;
          int32_T *dw_POAlignValues =
            &QD2_DroneStack_Manual_2021a_DW.HILInitialize_POAlignValues[0];
          for (i1=0; i1 < 6; i1++) {
            dw_POAlignValues[i1] =
              QD2_DroneStack_Manual_2021a_P.HILInitialize_POAlignment;
          }
        }

        {
          int_T i1;
          int32_T *dw_POPolarityVals =
            &QD2_DroneStack_Manual_2021a_DW.HILInitialize_POPolarityVals[0];
          for (i1=0; i1 < 6; i1++) {
            dw_POPolarityVals[i1] =
              QD2_DroneStack_Manual_2021a_P.HILInitialize_POPolarity;
          }
        }

        result = hil_set_pwm_configuration
          (QD2_DroneStack_Manual_2021a_DW.HILInitialize_Card,
           QD2_DroneStack_Manual_2021a_P.HILInitialize_POChannels, 6U,
           (t_pwm_configuration *)
           &QD2_DroneStack_Manual_2021a_DW.HILInitialize_POModeValues[0],
           (t_pwm_alignment *)
           &QD2_DroneStack_Manual_2021a_DW.HILInitialize_POAlignValues[0],
           (t_pwm_polarity *)
           &QD2_DroneStack_Manual_2021a_DW.HILInitialize_POPolarityVals[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(QD2_DroneStack_Manual_2021a_M, _rt_error_message);
          return;
        }
      }

      if ((QD2_DroneStack_Manual_2021a_P.HILInitialize_POStart && !is_switching)
          || (QD2_DroneStack_Manual_2021a_P.HILInitialize_POEnter &&
              is_switching)) {
        {
          int_T i1;
          real_T *dw_POValues =
            &QD2_DroneStack_Manual_2021a_DW.HILInitialize_POValues[0];
          for (i1=0; i1 < 6; i1++) {
            dw_POValues[i1] =
              QD2_DroneStack_Manual_2021a_P.HILInitialize_POInitial;
          }
        }

        result = hil_write_pwm(QD2_DroneStack_Manual_2021a_DW.HILInitialize_Card,
          QD2_DroneStack_Manual_2021a_P.HILInitialize_POChannels, 6U,
          &QD2_DroneStack_Manual_2021a_DW.HILInitialize_POValues[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(QD2_DroneStack_Manual_2021a_M, _rt_error_message);
          return;
        }
      }

      if (QD2_DroneStack_Manual_2021a_P.HILInitialize_POReset) {
        {
          int_T i1;
          real_T *dw_POValues =
            &QD2_DroneStack_Manual_2021a_DW.HILInitialize_POValues[0];
          for (i1=0; i1 < 6; i1++) {
            dw_POValues[i1] =
              QD2_DroneStack_Manual_2021a_P.HILInitialize_POWatchdog;
          }
        }

        result = hil_watchdog_set_pwm_expiration_state
          (QD2_DroneStack_Manual_2021a_DW.HILInitialize_Card,
           QD2_DroneStack_Manual_2021a_P.HILInitialize_POChannels, 6U,
           &QD2_DroneStack_Manual_2021a_DW.HILInitialize_POValues[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(QD2_DroneStack_Manual_2021a_M, _rt_error_message);
          return;
        }
      }
    }

    /* Start for S-Function (stream_client_block): '<S1>/Stream Client' incorporates:
     *  Constant: '<S1>/Constant'
     */

    /* S-Function Block: QD2_DroneStack_Manual_2021a/Communication/Stream Client (stream_client_block) */
    {
      QD2_DroneStack_Manual_2021a_DW.StreamClient_Stream = NULL;

      {
        int_T i1;
        real_T *y3 = &QD2_DroneStack_Manual_2021a_B.StreamClient_o4[0];
        const real_T *p_StreamClient_default_value =
          QD2_DroneStack_Manual_2021a_P.StreamClient_default_value;
        for (i1=0; i1 < 11; i1++) {
          y3[i1] = p_StreamClient_default_value[i1];
        }
      }

      QD2_DroneStack_Manual_2021a_DW.StreamClient_Connected = false;
    }

    /* Start for Iterator SubSystem: '<S9>/For Each Subsystem - Iterate over IMU0 and IMU1' */
    for (ForEach_itr_b = 0; ForEach_itr_b < 2; ForEach_itr_b++) {
      /* Start for Gain: '<S28>/Gain1' */
      QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Gain1[0] = 0.0;
      QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Gain1[1] = 0.0;

      /* Start for Integrator: '<S30>/Integrator1' */
      QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Integrator1[0] =
        0.0;

      /* Start for Product: '<S30>/Product1' */
      QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Product1[0] = 0.0;

      /* Start for Product: '<S30>/Product' */
      QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Product[0] = 0.0;

      /* Start for Product: '<S31>/Product' */
      QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Product_j[0] = 0.0;

      /* Start for Product: '<S31>/Product1' */
      QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Product1_e[0] =
        0.0;

      /* Start for Integrator: '<S30>/Integrator1' */
      QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Integrator1[1] =
        0.0;

      /* Start for Product: '<S30>/Product1' */
      QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Product1[1] = 0.0;

      /* Start for Product: '<S30>/Product' */
      QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Product[1] = 0.0;

      /* Start for Product: '<S31>/Product' */
      QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Product_j[1] = 0.0;

      /* Start for Product: '<S31>/Product1' */
      QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Product1_e[1] =
        0.0;

      /* Start for Integrator: '<S30>/Integrator1' */
      QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Integrator1[2] =
        0.0;

      /* Start for Product: '<S30>/Product1' */
      QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Product1[2] = 0.0;

      /* Start for Product: '<S30>/Product' */
      QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Product[2] = 0.0;

      /* Start for Product: '<S31>/Product' */
      QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Product_j[2] = 0.0;

      /* Start for Product: '<S31>/Product1' */
      QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Product1_e[2] =
        0.0;

      /* Start for Sum: '<S28>/Sum1' */
      QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Sum1[0] = 0.0;
      QD2_DroneStack_Manual_2021a_B.CoreSubsys[ForEach_itr_b].Sum1[1] = 0.0;
    }

    /* End of Start for SubSystem: '<S9>/For Each Subsystem - Iterate over IMU0 and IMU1' */

    /* Start for RateTransition: '<S2>/Rate Transition7' */
    QD2_DroneStack_Manual_2021a_B.RateTransition7[0] =
      QD2_DroneStack_Manual_2021a_P.RateTransition7_InitialConditio;
    QD2_DroneStack_Manual_2021a_B.RateTransition7[1] =
      QD2_DroneStack_Manual_2021a_P.RateTransition7_InitialConditio;

    /* Start for RateTransition: '<S2>/Rate Transition2' */
    QD2_DroneStack_Manual_2021a_B.RateTransition2 =
      QD2_DroneStack_Manual_2021a_P.RateTransition2_InitialConditio;

    /* Start for RateTransition: '<S2>/Rate Transition1' */
    QD2_DroneStack_Manual_2021a_B.RateTransition1 =
      QD2_DroneStack_Manual_2021a_P.RateTransition1_InitialConditio;

    /* Start for S-Function (sample_time_block): '<S27>/Sample Time' */

    /* S-Function Block: QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Timing Monitors/Sample Time (sample_time_block) */
    {
      t_error result;
      result = timeout_get_high_resolution_time
        (&QD2_DroneStack_Manual_2021a_DW.SampleTime_PreviousTime);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QD2_DroneStack_Manual_2021a_M, _rt_error_message);
        return;
      }
    }

    /* Start for RateTransition: '<S27>/Rate Transition' */
    QD2_DroneStack_Manual_2021a_B.RateTransition =
      QD2_DroneStack_Manual_2021a_P.RateTransition_InitialCondition;

    /* Start for RateTransition: '<S27>/Rate Transition1' */
    QD2_DroneStack_Manual_2021a_B.RateTransition1_d =
      QD2_DroneStack_Manual_2021a_P.RateTransition1_InitialCondit_m;

    /* Start for RateTransition: '<S27>/Rate Transition2' */
    QD2_DroneStack_Manual_2021a_B.RateTransition2_f =
      QD2_DroneStack_Manual_2021a_P.RateTransition2_InitialCondit_o;

    /* Start for RateTransition: '<S27>/Rate Transition3' */
    QD2_DroneStack_Manual_2021a_B.RateTransition3 =
      QD2_DroneStack_Manual_2021a_P.RateTransition3_InitialConditio;
    QD2_DroneStack_M_emxInit_real_T(&QD2_DroneStack_Manual_2021a_DW.buffer, 2);

    /* Start for S-Function (sample_time_block): '<S56>/Sample Time' */

    /* S-Function Block: QD2_DroneStack_Manual_2021a/STABILIZER - QDRONE 2/FLIGHT SAFETY/Sample Time (sample_time_block) */
    {
      t_error result;
      result = timeout_get_high_resolution_time
        (&QD2_DroneStack_Manual_2021a_DW.SampleTime_PreviousTime_j);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QD2_DroneStack_Manual_2021a_M, _rt_error_message);
        return;
      }
    }

    /* Start for S-Function (hil_watchdog_block): '<S56>/HIL Watchdog' */

    /* S-Function Block: QD2_DroneStack_Manual_2021a/STABILIZER - QDRONE 2/FLIGHT SAFETY/HIL Watchdog (hil_watchdog_block) */
    {
      QD2_DroneStack_Manual_2021a_DW.HILWatchdog_IsStarted = false;
    }

    /* Start for S-Function (stream_server_block): '<S2>/Stream Server' */

    /* S-Function Block: QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Stream Server (stream_server_block) */
    {
      qthread_attr_t send_thread_attributes;
      qthread_attr_t receive_thread_attributes;
      struct qsched_param scheduling_parameters;
      int min_priority = qsched_get_priority_min(QSCHED_FIFO);
      int max_priority = qsched_get_priority_max(QSCHED_FIFO);
      t_pstream_options options;
      t_error result;
      QD2_DroneStack_Manual_2021a_DW.StreamServer_Stream = NULL;
      QD2_DroneStack_Manual_2021a_B.StreamServer_o4 =
        QD2_DroneStack_Manual_2021a_P.StreamServer_default_value;
      result = 0;
      options.size = sizeof(options);
      options.flags = QD2_DroneStack_Manual_2021a_P.StreamServer_Endian &
        PSTREAM_FLAG_ENDIAN_MASK;
      if (QD2_DroneStack_Manual_2021a_P.StreamServer_Implementation ==
          STREAM_SERVER_IMPLEMENTATION_THREAD) {
        options.flags |= PSTREAM_FLAG_MULTITHREADED;
      }

      if (QD2_DroneStack_Manual_2021a_P.StreamServer_Optimize ==
          STREAM_SERVER_OPTIMIZE_LATENCY) {
        options.flags |= PSTREAM_FLAG_MINIMIZE_LATENCY;
      }

      options.flags |= PSTREAM_FLAG_SEND_MOST_RECENT;
      options.flags |= PSTREAM_FLAG_RECEIVE_MOST_RECENT;
      options.send_unit_size = 8;
      options.num_send_units = 47;
      options.send_buffer_size =
        QD2_DroneStack_Manual_2021a_P.StreamServer_SndSize;
      options.send_fifo_size =
        QD2_DroneStack_Manual_2021a_P.StreamServer_SndFIFO;
      options.num_send_dimensions = 0;
      options.max_send_dimensions = NULL;
      if (QD2_DroneStack_Manual_2021a_P.StreamServer_SndPriority < min_priority)
      {
        scheduling_parameters.sched_priority = min_priority;
      } else if (QD2_DroneStack_Manual_2021a_P.StreamServer_SndPriority >
                 max_priority) {
        scheduling_parameters.sched_priority = max_priority;
      } else {
        scheduling_parameters.sched_priority =
          QD2_DroneStack_Manual_2021a_P.StreamServer_SndPriority;
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
            rtmSetErrorStatus(QD2_DroneStack_Manual_2021a_M,
                              "Unable to set scheduling inheritance for Stream Client sending thread");
          }
        } else {
          rtmSetErrorStatus(QD2_DroneStack_Manual_2021a_M,
                            "The specified thread priority for the Stream Client sending thread is not valid for this target");
        }
      } else {
        rtmSetErrorStatus(QD2_DroneStack_Manual_2021a_M,
                          "Unable to set scheduling policy for Stream Client sending thread");
      }

      options.send_thread_attributes = &send_thread_attributes;
      options.receive_unit_size = 8;
      options.num_receive_units = 1;
      options.receive_buffer_size =
        QD2_DroneStack_Manual_2021a_P.StreamServer_RcvSize;
      options.receive_fifo_size =
        QD2_DroneStack_Manual_2021a_P.StreamServer_RcvFIFO;
      options.num_receive_dimensions = 0;
      options.max_receive_dimensions = NULL;
      if (QD2_DroneStack_Manual_2021a_P.StreamServer_RcvPriority < min_priority)
      {
        scheduling_parameters.sched_priority = min_priority;
      } else if (QD2_DroneStack_Manual_2021a_P.StreamServer_RcvPriority >
                 max_priority) {
        scheduling_parameters.sched_priority = max_priority;
      } else {
        scheduling_parameters.sched_priority =
          QD2_DroneStack_Manual_2021a_P.StreamServer_RcvPriority;
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
              rtmSetErrorStatus(QD2_DroneStack_Manual_2021a_M,
                                "Unable to set scheduling inheritance for Stream Client receiving thread");
            }
          } else {
            rtmSetErrorStatus(QD2_DroneStack_Manual_2021a_M,
                              "The specified thread priority for the Stream Client receiving thread is not valid for this target");
          }
        } else {
          rtmSetErrorStatus(QD2_DroneStack_Manual_2021a_M,
                            "Unable to set scheduling policy for Stream Client receiving thread");
        }
      }

      options.receive_thread_attributes = &receive_thread_attributes;
      if (result == 0) {
        result = pstream_listen((const char *)
          QD2_DroneStack_Manual_2021a_P.StreamServer_URI, &options,
          &QD2_DroneStack_Manual_2021a_DW.StreamServer_Stream);
        if (result < 0 && result != -QERR_WOULD_BLOCK) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(QD2_DroneStack_Manual_2021a_M, _rt_error_message);
        }
      }

      qthread_attr_destroy(&send_thread_attributes);
      qthread_attr_destroy(&receive_thread_attributes);
    }

    /* Start for Constant: '<S18>/x0' */
    QD2_DroneStack_Manual_2021a_B.x0 = QD2_DroneStack_Manual_2021a_P.x0_Value;

    /* Start for S-Function (sample_time_block): '<S27>/Sample Time1' */

    /* S-Function Block: QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Timing Monitors/Sample Time1 (sample_time_block) */
    {
      t_error result;
      result = timeout_get_high_resolution_time
        (&QD2_DroneStack_Manual_2021a_DW.SampleTime1_PreviousTime);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QD2_DroneStack_Manual_2021a_M, _rt_error_message);
        return;
      }
    }

    /* Start for Constant: '<S2>/ToF Filter Initial Condition (m)' */
    QD2_DroneStack_Manual_2021a_B.ToFFilterInitialConditionm =
      QD2_DroneStack_Manual_2021a_P.ToFFilterInitialConditionm_Valu;

    /* Start for S-Function (ranging_sensor_block): '<S2>/Ranging Sensor' */

    /* S-Function Block: QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Ranging Sensor (ranging_sensor_block) */
    {
      t_error result;
      result = vl53l1x_open("i2c-cpu://localhost:0?address='0x29',baud='400000',memsize='512'",
                            (t_ranging_distance)
                            (QD2_DroneStack_Manual_2021a_P.RangingSensor_Range -
        1), QD2_DroneStack_Manual_2021a_P.RangingSensor_Budget,
                            QD2_DroneStack_Manual_2021a_P.RangingSensor_Period,
                            &QD2_DroneStack_Manual_2021a_DW.RangingSensor_Sensor);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QD2_DroneStack_Manual_2021a_M, _rt_error_message);
      }
    }

    /* Start for S-Function (sample_time_block): '<S27>/Sample Time2' */

    /* S-Function Block: QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Timing Monitors/Sample Time2 (sample_time_block) */
    {
      t_error result;
      result = timeout_get_high_resolution_time
        (&QD2_DroneStack_Manual_2021a_DW.SampleTime2_PreviousTime);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QD2_DroneStack_Manual_2021a_M, _rt_error_message);
        return;
      }
    }

    /* user code (Start function Trailer) */

    /* S-Function Block: QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Time (time_block) */
    {
      t_error result;
      result = timeout_get_high_resolution_time(&_high_resolution_start_time);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QD2_DroneStack_Manual_2021a_M, _rt_error_message);
        return;
      }
    }
  }

  QD2_DroneStack_Manual_2_PrevZCX.TriggeredSubsystemLatchingFlag_ = POS_ZCSIG;

  {
    /* local scratch DWork variables */
    int32_T ForEach_itr_b;
    int32_T i;

    /* InitializeConditions for Delay: '<S1>/Delay' */
    QD2_DroneStack_Manual_2021a_DW.Delay_DSTATE =
      QD2_DroneStack_Manual_2021a_P.Delay_InitialCondition;

    /* InitializeConditions for Memory: '<S2>/Memory1' */
    QD2_DroneStack_Manual_2021a_DW.Memory1_PreviousInput =
      QD2_DroneStack_Manual_2021a_P.Memory1_InitialCondition;

    /* InitializeConditions for Memory: '<S2>/Memory' */
    QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput =
      QD2_DroneStack_Manual_2021a_P.Memory_InitialCondition;

    /* InitializeConditions for Delay: '<S4>/Delay' */
    for (i = 0; i < 50; i++) {
      QD2_DroneStack_Manual_2021a_DW.Delay_DSTATE_l[i] =
        QD2_DroneStack_Manual_2021a_P.Delay_InitialCondition_i;
    }

    /* End of InitializeConditions for Delay: '<S4>/Delay' */

    /* InitializeConditions for RateTransition: '<S2>/Rate Transition7' */
    QD2_DroneStack_Manual_2021a_DW.RateTransition7_Buffer0[0] =
      QD2_DroneStack_Manual_2021a_P.RateTransition7_InitialConditio;
    QD2_DroneStack_Manual_2021a_DW.RateTransition7_Buffer0[1] =
      QD2_DroneStack_Manual_2021a_P.RateTransition7_InitialConditio;

    /* InitializeConditions for RateTransition: '<S2>/Rate Transition2' */
    QD2_DroneStack_Manual_2021a_DW.RateTransition2_Buffer0 =
      QD2_DroneStack_Manual_2021a_P.RateTransition2_InitialConditio;

    /* InitializeConditions for RateTransition: '<S2>/Rate Transition1' */
    QD2_DroneStack_Manual_2021a_DW.RateTransition1_Buffer0 =
      QD2_DroneStack_Manual_2021a_P.RateTransition1_InitialConditio;

    /* InitializeConditions for RateTransition: '<S27>/Rate Transition' */
    QD2_DroneStack_Manual_2021a_DW.RateTransition_Buffer0 =
      QD2_DroneStack_Manual_2021a_P.RateTransition_InitialCondition;

    /* InitializeConditions for RateTransition: '<S27>/Rate Transition1' */
    QD2_DroneStack_Manual_2021a_DW.RateTransition1_Buffer0_l =
      QD2_DroneStack_Manual_2021a_P.RateTransition1_InitialCondit_m;

    /* InitializeConditions for RateTransition: '<S27>/Rate Transition2' */
    QD2_DroneStack_Manual_2021a_DW.RateTransition2_Buffer0_l =
      QD2_DroneStack_Manual_2021a_P.RateTransition2_InitialCondit_o;

    /* InitializeConditions for RateTransition: '<S27>/Rate Transition3' */
    QD2_DroneStack_Manual_2021a_DW.RateTransition3_Buffer0 =
      QD2_DroneStack_Manual_2021a_P.RateTransition3_InitialConditio;

    /* InitializeConditions for Memory: '<S13>/Memory' */
    QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput_h[0] =
      QD2_DroneStack_Manual_2021a_P.Memory_InitialCondition_k[0];

    /* InitializeConditions for Memory: '<S15>/Memory' */
    QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput_k[0] =
      QD2_DroneStack_Manual_2021a_P.Memory_InitialCondition_b[0];

    /* InitializeConditions for Memory: '<S14>/Memory' */
    QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput_a[0] =
      QD2_DroneStack_Manual_2021a_P.Memory_InitialCondition_bp[0];

    /* InitializeConditions for Memory: '<S13>/Memory' */
    QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput_h[1] =
      QD2_DroneStack_Manual_2021a_P.Memory_InitialCondition_k[1];

    /* InitializeConditions for Memory: '<S15>/Memory' */
    QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput_k[1] =
      QD2_DroneStack_Manual_2021a_P.Memory_InitialCondition_b[1];

    /* InitializeConditions for Memory: '<S14>/Memory' */
    QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput_a[1] =
      QD2_DroneStack_Manual_2021a_P.Memory_InitialCondition_bp[1];

    /* InitializeConditions for Memory: '<S13>/Memory' */
    QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput_h[2] =
      QD2_DroneStack_Manual_2021a_P.Memory_InitialCondition_k[2];

    /* InitializeConditions for Memory: '<S15>/Memory' */
    QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput_k[2] =
      QD2_DroneStack_Manual_2021a_P.Memory_InitialCondition_b[2];

    /* InitializeConditions for Memory: '<S14>/Memory' */
    QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput_a[2] =
      QD2_DroneStack_Manual_2021a_P.Memory_InitialCondition_bp[2];

    /* InitializeConditions for Memory: '<S13>/Memory' */
    QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput_h[3] =
      QD2_DroneStack_Manual_2021a_P.Memory_InitialCondition_k[3];

    /* InitializeConditions for Memory: '<S15>/Memory' */
    QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput_k[3] =
      QD2_DroneStack_Manual_2021a_P.Memory_InitialCondition_b[3];

    /* InitializeConditions for Memory: '<S14>/Memory' */
    QD2_DroneStack_Manual_2021a_DW.Memory_PreviousInput_a[3] =
      QD2_DroneStack_Manual_2021a_P.Memory_InitialCondition_bp[3];

    /* InitializeConditions for DiscreteIntegrator: '<S42>/Discrete-Time Integrator' */
    QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE =
      QD2_DroneStack_Manual_2021a_P.DiscreteTimeIntegrator_IC;
    QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_PrevRese = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S26>/Discrete-Time Integrator' */
    QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE_j =
      QD2_DroneStack_Manual_2021a_P.DiscreteTimeIntegrator_IC_j;
    QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_PrevRe_h = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
    QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE_k =
      QD2_DroneStack_Manual_2021a_P.DiscreteTimeIntegrator_IC_c;
    QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_PrevR_hs = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S8>/Discrete-Time Integrator' */
    QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE_e =
      QD2_DroneStack_Manual_2021a_P.DiscreteTimeIntegrator_IC_m;
    QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_PrevRe_b = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S60>/Discrete-Time Integrator' */
    QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE_l =
      QD2_DroneStack_Manual_2021a_P.DiscreteTimeIntegrator_IC_a;
    QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_PrevRe_j = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S59>/Discrete-Time Integrator' */
    QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_DSTAT_lx =
      QD2_DroneStack_Manual_2021a_P.DiscreteTimeIntegrator_IC_my;
    QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_PrevRe_k = 0;

    /* InitializeConditions for Memory: '<S2>/Memory2' */
    QD2_DroneStack_Manual_2021a_DW.Memory2_PreviousInput =
      QD2_DroneStack_Manual_2021a_P.Memory2_InitialCondition;

    /* InitializeConditions for Memory: '<S2>/Memory3' */
    QD2_DroneStack_Manual_2021a_DW.Memory3_PreviousInput =
      QD2_DroneStack_Manual_2021a_P.Memory3_InitialCondition;

    /* InitializeConditions for Delay: '<S16>/Delay3' */
    QD2_DroneStack_Manual_2021a_DW.Delay3_DSTATE[0] =
      QD2_DroneStack_Manual_2021a_P.Delay3_InitialCondition;

    /* InitializeConditions for Delay: '<S16>/Delay2' */
    QD2_DroneStack_Manual_2021a_DW.Delay2_DSTATE[0] =
      QD2_DroneStack_Manual_2021a_P.Delay2_InitialCondition;

    /* InitializeConditions for Delay: '<S16>/Delay1' */
    QD2_DroneStack_Manual_2021a_DW.Delay1_DSTATE[0] =
      QD2_DroneStack_Manual_2021a_P.Delay1_InitialCondition;

    /* InitializeConditions for Delay: '<S16>/Delay' */
    QD2_DroneStack_Manual_2021a_DW.Delay_DSTATE_ln[0] =
      QD2_DroneStack_Manual_2021a_P.Delay_InitialCondition_m;

    /* InitializeConditions for DiscreteIntegrator: '<S18>/Discrete-Time Integrator' */
    QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE_o[0] =
      QD2_DroneStack_Manual_2021a_P.DiscreteTimeIntegrator_IC_n;

    /* InitializeConditions for DiscreteIntegrator: '<S18>/Discrete-Time Integrator1' */
    QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator1_DSTATE[0] =
      QD2_DroneStack_Manual_2021a_B.x0;

    /* InitializeConditions for Delay: '<S16>/Delay3' */
    QD2_DroneStack_Manual_2021a_DW.Delay3_DSTATE[1] =
      QD2_DroneStack_Manual_2021a_P.Delay3_InitialCondition;

    /* InitializeConditions for Delay: '<S16>/Delay2' */
    QD2_DroneStack_Manual_2021a_DW.Delay2_DSTATE[1] =
      QD2_DroneStack_Manual_2021a_P.Delay2_InitialCondition;

    /* InitializeConditions for Delay: '<S16>/Delay1' */
    QD2_DroneStack_Manual_2021a_DW.Delay1_DSTATE[1] =
      QD2_DroneStack_Manual_2021a_P.Delay1_InitialCondition;

    /* InitializeConditions for Delay: '<S16>/Delay' */
    QD2_DroneStack_Manual_2021a_DW.Delay_DSTATE_ln[1] =
      QD2_DroneStack_Manual_2021a_P.Delay_InitialCondition_m;

    /* InitializeConditions for DiscreteIntegrator: '<S18>/Discrete-Time Integrator' */
    QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE_o[1] =
      QD2_DroneStack_Manual_2021a_P.DiscreteTimeIntegrator_IC_n;

    /* InitializeConditions for DiscreteIntegrator: '<S18>/Discrete-Time Integrator1' */
    QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator1_DSTATE[1] =
      QD2_DroneStack_Manual_2021a_B.x0;

    /* InitializeConditions for DiscreteIntegrator: '<S17>/Discrete-Time Integrator' */
    QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE_a =
      QD2_DroneStack_Manual_2021a_P.DiscreteTimeIntegrator_IC_ac;

    /* InitializeConditions for DiscreteIntegrator: '<S17>/Discrete-Time Integrator1' */
    QD2_DroneStack_Manual_2021a_DW.DiscreteTimeIntegrator1_DSTAT_d =
      QD2_DroneStack_Manual_2021a_B.ToFFilterInitialConditionm;

    /* SystemInitialize for Iterator SubSystem: '<S9>/For Each Subsystem - Iterate over IMU0 and IMU1' */
    for (ForEach_itr_b = 0; ForEach_itr_b < 2; ForEach_itr_b++) {
      /* InitializeConditions for Integrator: '<S31>/Integrator1' incorporates:
       *  Integrator: '<S30>/Integrator1'
       */
      if (rtmIsFirstInitCond(QD2_DroneStack_Manual_2021a_M)) {
        QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].
          Integrator1_CSTATE[0] = 0.0;
        QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].
          Integrator1_CSTATE[1] = 0.0;
        QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].
          Integrator1_CSTATE[2] = 0.0;
        QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].
          Integrator1_CSTATE_h5[0] = 0.0;
        QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].
          Integrator1_CSTATE_h5[1] = 0.0;
        QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].
          Integrator1_CSTATE_h5[2] = 0.0;
      }

      QD2_DroneStack_Manual_2021a_DW.CoreSubsys[ForEach_itr_b].
        Integrator1_DWORK1 = true;

      /* End of InitializeConditions for Integrator: '<S31>/Integrator1' */

      /* InitializeConditions for Integrator: '<S28>/Integrator1' */
      QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].
        Integrator1_CSTATE_h[0] =
        QD2_DroneStack_Manual_2021a_P.CoreSubsys.Integrator1_IC;
      QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].
        Integrator1_CSTATE_h[1] =
        QD2_DroneStack_Manual_2021a_P.CoreSubsys.Integrator1_IC;

      /* InitializeConditions for Integrator: '<S28>/Integrator2' */
      QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].Integrator2_CSTATE
        = QD2_DroneStack_Manual_2021a_P.CoreSubsys.Integrator2_IC;

      /* InitializeConditions for Integrator: '<S30>/Integrator1' */
      QD2_DroneStack_Manual_2021a_DW.CoreSubsys[ForEach_itr_b].
        Integrator1_DWORK1_b = true;

      /* InitializeConditions for Integrator: '<S30>/Integrator2' */
      QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].
        Integrator2_CSTATE_k[0] =
        QD2_DroneStack_Manual_2021a_P.CoreSubsys.Integrator2_IC_j;
      QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].
        Integrator2_CSTATE_k[1] =
        QD2_DroneStack_Manual_2021a_P.CoreSubsys.Integrator2_IC_j;
      QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].
        Integrator2_CSTATE_k[2] =
        QD2_DroneStack_Manual_2021a_P.CoreSubsys.Integrator2_IC_j;

      /* InitializeConditions for Integrator: '<S28>/Integrator' */
      QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].Integrator_CSTATE
        [0] = QD2_DroneStack_Manual_2021a_P.CoreSubsys.Integrator_IC;
      QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].Integrator_CSTATE
        [1] = QD2_DroneStack_Manual_2021a_P.CoreSubsys.Integrator_IC;

      /* InitializeConditions for Integrator: '<S31>/Integrator2' */
      QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].
        Integrator2_CSTATE_e[0] =
        QD2_DroneStack_Manual_2021a_P.CoreSubsys.Integrator2_IC_g;
      QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].
        Integrator2_CSTATE_e[1] =
        QD2_DroneStack_Manual_2021a_P.CoreSubsys.Integrator2_IC_g;
      QD2_DroneStack_Manual_2021a_X.CoreSubsys[ForEach_itr_b].
        Integrator2_CSTATE_e[2] =
        QD2_DroneStack_Manual_2021a_P.CoreSubsys.Integrator2_IC_g;

      /* SystemInitialize for MATLAB Function: '<S28>/Roll and Pitch Approximation from Accelerometer data' */
      QD2_DroneStack_Manual_2021a_DW.CoreSubsys[ForEach_itr_b].sfEvent =
        QD2_DroneStack_Manua_CALL_EVENT;
    }

    /* End of SystemInitialize for SubSystem: '<S9>/For Each Subsystem - Iterate over IMU0 and IMU1' */

    /* SystemInitialize for MATLAB Function: '<S10>/MATLAB Function' */
    QD2_DroneStack_Manual_2021a_DW.state = 0.0;
    QD2_DroneStack_Manual_2021a_DW.state_not_empty = true;
    QD2_DroneStack_Manual_2021a_DW.sfEvent_b = QD2_DroneStack_Manua_CALL_EVENT;

    /* SystemInitialize for MATLAB Function: '<S16>/MATLAB Function' */
    QD2_DroneStack_Manual_2021a_DW.buffer_not_empty = false;
    QD2_DroneStack_Manual_2021a_DW.idx = 1.0;
    QD2_DroneStack_Manual_2021a_DW.idx_not_empty = true;
    QD2_DroneStack_Manual_2021a_DW.sfEvent_d = QD2_DroneStack_Manua_CALL_EVENT;

    /* SystemInitialize for MATLAB Function: '<S2>/Force to percentage Mapping' */
    QD2_DroneStack_Manual_2021a_DW.sfEvent_e = QD2_DroneStack_Manua_CALL_EVENT;

    /* SystemInitialize for MATLAB Function: '<S2>/MATLAB Function' */
    QD2_DroneStack_Manual_2021a_DW.next_state_after_pause = 99.0;
    QD2_DroneStack_Manual_2021a_DW.next_state_after_pause_not_empt = true;
    QD2_DroneStack_Manual_2021a_DW.state_counter = 1000.0;
    QD2_DroneStack_Manual_2021a_DW.state_counter_not_empty = true;
    QD2_DroneStack_Manual_2021a_DW.state_counter_after_pause = 1000.0;
    QD2_DroneStack_Manual_2021a_DW.state_counter_after_pause_not_e = true;
    QD2_DroneStack_Manual_2021a_DW.esc_timeout_state = 0.0;
    QD2_DroneStack_Manual_2021a_DW.esc_timeout_state_not_empty = true;
    QD2_DroneStack_Manual_2021a_DW.sfEvent = QD2_DroneStack_Manua_CALL_EVENT;

    /* SystemInitialize for Triggered SubSystem: '<S23>/Triggered Subsystem - Latching Flag' */
    /* SystemInitialize for SignalConversion generated from: '<S43>/Out1' incorporates:
     *  Outport: '<S43>/Out1'
     */
    QD2_DroneStack_Manual_2021a_B.OutportBufferForOut1 =
      QD2_DroneStack_Manual_2021a_P.Out1_Y0;

    /* End of SystemInitialize for SubSystem: '<S23>/Triggered Subsystem - Latching Flag' */

    /* SystemInitialize for MATLAB Function: '<S5>/MATLAB Function' */
    QD2_DroneStack_Manual_2021a_DW.ms_time_prev = 0.0;
    QD2_DroneStack_Manual_2021a_DW.ms_time_prev_not_empty = true;
    QD2_DroneStack_Manual_2021a_DW.sfEvent_a = QD2_DroneStack_Manua_CALL_EVENT;

    /* set "at time zero" to false */
    if (rtmIsFirstInitCond(QD2_DroneStack_Manual_2021a_M)) {
      rtmSetFirstInitCond(QD2_DroneStack_Manual_2021a_M, 0);
    }
  }
}

/* Model terminate function */
void QD2_DroneStack_Manual_2021a_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S2>/HIL Initialize' */

  /* S-Function Block: QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(QD2_DroneStack_Manual_2021a_DW.HILInitialize_Card);
    hil_monitor_stop_all(QD2_DroneStack_Manual_2021a_DW.HILInitialize_Card);
    is_switching = false;

    /* S-Function Block: QD2_DroneStack_Manual_2021a/STABILIZER - QDRONE 2/FLIGHT SAFETY/HIL Watchdog (hil_watchdog_block) */
    {
      hil_watchdog_stop(QD2_DroneStack_Manual_2021a_DW.HILInitialize_Card);
    }

    if ((QD2_DroneStack_Manual_2021a_P.HILInitialize_DOTerminate &&
         !is_switching) || (QD2_DroneStack_Manual_2021a_P.HILInitialize_DOExit &&
         is_switching)) {
      {
        int_T i1;
        boolean_T *dw_DOBits =
          &QD2_DroneStack_Manual_2021a_DW.HILInitialize_DOBits[0];
        for (i1=0; i1 < 6; i1++) {
          dw_DOBits[i1] = QD2_DroneStack_Manual_2021a_P.HILInitialize_DOFinal;
        }
      }

      num_final_digital_outputs = 6U;
    } else {
      num_final_digital_outputs = 0;
    }

    if ((QD2_DroneStack_Manual_2021a_P.HILInitialize_POTerminate &&
         !is_switching) || (QD2_DroneStack_Manual_2021a_P.HILInitialize_POExit &&
         is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues =
          &QD2_DroneStack_Manual_2021a_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 6; i1++) {
          dw_POValues[i1] = QD2_DroneStack_Manual_2021a_P.HILInitialize_POFinal;
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
      result = hil_write(QD2_DroneStack_Manual_2021a_DW.HILInitialize_Card
                         , NULL, 0
                         ,
                         QD2_DroneStack_Manual_2021a_P.HILInitialize_POChannels,
                         num_final_pwm_outputs
                         ,
                         QD2_DroneStack_Manual_2021a_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , NULL, 0
                         , NULL
                         ,
                         &QD2_DroneStack_Manual_2021a_DW.HILInitialize_POValues
                         [0]
                         , (t_boolean *)
                         &QD2_DroneStack_Manual_2021a_DW.HILInitialize_DOBits[0]
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm
            (QD2_DroneStack_Manual_2021a_DW.HILInitialize_Card,
             QD2_DroneStack_Manual_2021a_P.HILInitialize_POChannels,
             num_final_pwm_outputs,
             &QD2_DroneStack_Manual_2021a_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital
            (QD2_DroneStack_Manual_2021a_DW.HILInitialize_Card,
             QD2_DroneStack_Manual_2021a_P.HILInitialize_DOChannels,
             num_final_digital_outputs, (t_boolean *)
             &QD2_DroneStack_Manual_2021a_DW.HILInitialize_DOBits[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(QD2_DroneStack_Manual_2021a_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(QD2_DroneStack_Manual_2021a_DW.HILInitialize_Card);
    hil_monitor_delete_all(QD2_DroneStack_Manual_2021a_DW.HILInitialize_Card);
    hil_close(QD2_DroneStack_Manual_2021a_DW.HILInitialize_Card);
    QD2_DroneStack_Manual_2021a_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (stream_client_block): '<S1>/Stream Client' incorporates:
   *  Constant: '<S1>/Constant'
   */

  /* S-Function Block: QD2_DroneStack_Manual_2021a/Communication/Stream Client (stream_client_block) */
  {
    if (QD2_DroneStack_Manual_2021a_DW.StreamClient_Stream != NULL) {
      pstream_close(QD2_DroneStack_Manual_2021a_DW.StreamClient_Stream);
    }

    QD2_DroneStack_Manual_2021a_DW.StreamClient_Stream = NULL;
  }

  QD2_DroneStack_M_emxFree_real_T(&QD2_DroneStack_Manual_2021a_DW.buffer);

  /* Terminate for S-Function (stream_server_block): '<S2>/Stream Server' */

  /* S-Function Block: QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Stream Server (stream_server_block) */
  {
    if (QD2_DroneStack_Manual_2021a_DW.StreamServer_Stream != NULL) {
      pstream_close(QD2_DroneStack_Manual_2021a_DW.StreamServer_Stream);
    }

    QD2_DroneStack_Manual_2021a_DW.StreamServer_Stream = NULL;
  }

  /* Terminate for S-Function (ranging_sensor_block): '<S2>/Ranging Sensor' */

  /* S-Function Block: QD2_DroneStack_Manual_2021a/QDrone 2 DAQ/Ranging Sensor (ranging_sensor_block) */
  {
    vl53l1x_close(QD2_DroneStack_Manual_2021a_DW.RangingSensor_Sensor);
    QD2_DroneStack_Manual_2021a_DW.RangingSensor_Sensor = NULL;
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
  QD2_DroneStack_Manual_2021a_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  QD2_DroneStack_Manual_2021a_update(tid);
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
  QD2_DroneStack_Manual_2021a_initialize();
}

void MdlTerminate(void)
{
  QD2_DroneStack_Manual_2021a_terminate();
}

/* Registration function */
RT_MODEL_QD2_DroneStack_Manua_T *QD2_DroneStack_Manual_2021a(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)QD2_DroneStack_Manual_2021a_M, 0,
                sizeof(RT_MODEL_QD2_DroneStack_Manua_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&QD2_DroneStack_Manual_2021a_M->solverInfo,
                          &QD2_DroneStack_Manual_2021a_M->Timing.simTimeStep);
    rtsiSetTPtr(&QD2_DroneStack_Manual_2021a_M->solverInfo, &rtmGetTPtr
                (QD2_DroneStack_Manual_2021a_M));
    rtsiSetStepSizePtr(&QD2_DroneStack_Manual_2021a_M->solverInfo,
                       &QD2_DroneStack_Manual_2021a_M->Timing.stepSize0);
    rtsiSetdXPtr(&QD2_DroneStack_Manual_2021a_M->solverInfo,
                 &QD2_DroneStack_Manual_2021a_M->derivs);
    rtsiSetContStatesPtr(&QD2_DroneStack_Manual_2021a_M->solverInfo, (real_T **)
                         &QD2_DroneStack_Manual_2021a_M->contStates);
    rtsiSetNumContStatesPtr(&QD2_DroneStack_Manual_2021a_M->solverInfo,
      &QD2_DroneStack_Manual_2021a_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&QD2_DroneStack_Manual_2021a_M->solverInfo,
      &QD2_DroneStack_Manual_2021a_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr
      (&QD2_DroneStack_Manual_2021a_M->solverInfo,
       &QD2_DroneStack_Manual_2021a_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&QD2_DroneStack_Manual_2021a_M->solverInfo,
      &QD2_DroneStack_Manual_2021a_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&QD2_DroneStack_Manual_2021a_M->solverInfo,
      (boolean_T**) &QD2_DroneStack_Manual_2021a_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&QD2_DroneStack_Manual_2021a_M->solverInfo,
                          (&rtmGetErrorStatus(QD2_DroneStack_Manual_2021a_M)));
    rtsiSetRTModelPtr(&QD2_DroneStack_Manual_2021a_M->solverInfo,
                      QD2_DroneStack_Manual_2021a_M);
  }

  rtsiSetSimTimeStep(&QD2_DroneStack_Manual_2021a_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange
    (&QD2_DroneStack_Manual_2021a_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&QD2_DroneStack_Manual_2021a_M->solverInfo, false);
  QD2_DroneStack_Manual_2021a_M->intgData.y =
    QD2_DroneStack_Manual_2021a_M->odeY;
  QD2_DroneStack_Manual_2021a_M->intgData.f[0] =
    QD2_DroneStack_Manual_2021a_M->odeF[0];
  QD2_DroneStack_Manual_2021a_M->intgData.f[1] =
    QD2_DroneStack_Manual_2021a_M->odeF[1];
  QD2_DroneStack_Manual_2021a_M->contStates = ((real_T *)
    &QD2_DroneStack_Manual_2021a_X);
  QD2_DroneStack_Manual_2021a_M->contStateDisabled = ((boolean_T *)
    &QD2_DroneStack_Manual_2021_XDis);
  QD2_DroneStack_Manual_2021a_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&QD2_DroneStack_Manual_2021a_M->solverInfo, (void *)
                    &QD2_DroneStack_Manual_2021a_M->intgData);
  rtsiSetSolverName(&QD2_DroneStack_Manual_2021a_M->solverInfo,"ode2");

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      QD2_DroneStack_Manual_2021a_M->Timing.sampleTimeTaskIDArray;
    int_T i;
    for (i = 0; i < 5; i++) {
      mdlTsMap[i] = i;
    }

    QD2_DroneStack_Manual_2021a_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    QD2_DroneStack_Manual_2021a_M->Timing.sampleTimes =
      (&QD2_DroneStack_Manual_2021a_M->Timing.sampleTimesArray[0]);
    QD2_DroneStack_Manual_2021a_M->Timing.offsetTimes =
      (&QD2_DroneStack_Manual_2021a_M->Timing.offsetTimesArray[0]);

    /* task periods */
    QD2_DroneStack_Manual_2021a_M->Timing.sampleTimes[0] = (0.0);
    QD2_DroneStack_Manual_2021a_M->Timing.sampleTimes[1] = (0.002);
    QD2_DroneStack_Manual_2021a_M->Timing.sampleTimes[2] = (0.004);
    QD2_DroneStack_Manual_2021a_M->Timing.sampleTimes[3] = (0.01);
    QD2_DroneStack_Manual_2021a_M->Timing.sampleTimes[4] = (0.04);

    /* task offsets */
    QD2_DroneStack_Manual_2021a_M->Timing.offsetTimes[0] = (0.0);
    QD2_DroneStack_Manual_2021a_M->Timing.offsetTimes[1] = (0.0);
    QD2_DroneStack_Manual_2021a_M->Timing.offsetTimes[2] = (0.0);
    QD2_DroneStack_Manual_2021a_M->Timing.offsetTimes[3] = (0.0);
    QD2_DroneStack_Manual_2021a_M->Timing.offsetTimes[4] = (0.0);
  }

  rtmSetTPtr(QD2_DroneStack_Manual_2021a_M,
             &QD2_DroneStack_Manual_2021a_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = QD2_DroneStack_Manual_2021a_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      QD2_DroneStack_Manual_2021a_M->Timing.perTaskSampleHitsArray;
    QD2_DroneStack_Manual_2021a_M->Timing.perTaskSampleHits =
      (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    QD2_DroneStack_Manual_2021a_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(QD2_DroneStack_Manual_2021a_M, -1);
  QD2_DroneStack_Manual_2021a_M->Timing.stepSize0 = 0.002;
  QD2_DroneStack_Manual_2021a_M->Timing.stepSize1 = 0.002;
  QD2_DroneStack_Manual_2021a_M->Timing.stepSize2 = 0.004;
  QD2_DroneStack_Manual_2021a_M->Timing.stepSize3 = 0.01;
  QD2_DroneStack_Manual_2021a_M->Timing.stepSize4 = 0.04;
  rtmSetFirstInitCond(QD2_DroneStack_Manual_2021a_M, 1);

  /* External mode info */
  QD2_DroneStack_Manual_2021a_M->Sizes.checksums[0] = (1429712378U);
  QD2_DroneStack_Manual_2021a_M->Sizes.checksums[1] = (3322906005U);
  QD2_DroneStack_Manual_2021a_M->Sizes.checksums[2] = (3877968020U);
  QD2_DroneStack_Manual_2021a_M->Sizes.checksums[3] = (2383775020U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[34];
    QD2_DroneStack_Manual_2021a_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
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
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = (sysRanDType *)
      &QD2_DroneStack_Manual_2021a_DW.EnabledSubsystemWriteESCCommand;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = &rtAlwaysEnabled;
    systemRan[18] = &rtAlwaysEnabled;
    systemRan[19] = &rtAlwaysEnabled;
    systemRan[20] = &rtAlwaysEnabled;
    systemRan[21] = &rtAlwaysEnabled;
    systemRan[22] = &rtAlwaysEnabled;
    systemRan[23] = &rtAlwaysEnabled;
    systemRan[24] = &rtAlwaysEnabled;
    systemRan[25] = &rtAlwaysEnabled;
    systemRan[26] = &rtAlwaysEnabled;
    systemRan[27] = &rtAlwaysEnabled;
    systemRan[28] = (sysRanDType *)
      &QD2_DroneStack_Manual_2021a_DW.TriggeredSubsystemLatchingFlag_;
    systemRan[29] = &rtAlwaysEnabled;
    systemRan[30] = &rtAlwaysEnabled;
    systemRan[31] = &rtAlwaysEnabled;
    systemRan[32] = &rtAlwaysEnabled;
    systemRan[33] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(QD2_DroneStack_Manual_2021a_M->extModeInfo,
      &QD2_DroneStack_Manual_2021a_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(QD2_DroneStack_Manual_2021a_M->extModeInfo,
                        QD2_DroneStack_Manual_2021a_M->Sizes.checksums);
    rteiSetTPtr(QD2_DroneStack_Manual_2021a_M->extModeInfo, rtmGetTPtr
                (QD2_DroneStack_Manual_2021a_M));
  }

  QD2_DroneStack_Manual_2021a_M->solverInfoPtr =
    (&QD2_DroneStack_Manual_2021a_M->solverInfo);
  QD2_DroneStack_Manual_2021a_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&QD2_DroneStack_Manual_2021a_M->solverInfo, 0.002);
  rtsiSetSolverMode(&QD2_DroneStack_Manual_2021a_M->solverInfo,
                    SOLVER_MODE_MULTITASKING);

  /* block I/O */
  QD2_DroneStack_Manual_2021a_M->blockIO = ((void *)
    &QD2_DroneStack_Manual_2021a_B);
  (void) memset(((void *) &QD2_DroneStack_Manual_2021a_B), 0,
                sizeof(B_QD2_DroneStack_Manual_2021a_T));

  /* parameters */
  QD2_DroneStack_Manual_2021a_M->defaultParam = ((real_T *)
    &QD2_DroneStack_Manual_2021a_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &QD2_DroneStack_Manual_2021a_X;
    QD2_DroneStack_Manual_2021a_M->contStates = (x);
    (void) memset((void *)&QD2_DroneStack_Manual_2021a_X, 0,
                  sizeof(X_QD2_DroneStack_Manual_2021a_T));
  }

  /* disabled states */
  {
    boolean_T *xdis = (boolean_T *) &QD2_DroneStack_Manual_2021_XDis;
    QD2_DroneStack_Manual_2021a_M->contStateDisabled = (xdis);
    (void) memset((void *)&QD2_DroneStack_Manual_2021_XDis, 0,
                  sizeof(XDis_QD2_DroneStack_Manual_20_T));
  }

  /* states (dwork) */
  QD2_DroneStack_Manual_2021a_M->dwork = ((void *)
    &QD2_DroneStack_Manual_2021a_DW);
  (void) memset((void *)&QD2_DroneStack_Manual_2021a_DW, 0,
                sizeof(DW_QD2_DroneStack_Manual_2021_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    QD2_DroneStack_Manual_2021a_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 30;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  QD2_DroneStack_Manual_2021a_M->Sizes.numContStates = (34);/* Number of continuous states */
  QD2_DroneStack_Manual_2021a_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  QD2_DroneStack_Manual_2021a_M->Sizes.numY = (0);/* Number of model outputs */
  QD2_DroneStack_Manual_2021a_M->Sizes.numU = (0);/* Number of model inputs */
  QD2_DroneStack_Manual_2021a_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  QD2_DroneStack_Manual_2021a_M->Sizes.numSampTimes = (5);/* Number of sample times */
  QD2_DroneStack_Manual_2021a_M->Sizes.numBlocks = (337);/* Number of blocks */
  QD2_DroneStack_Manual_2021a_M->Sizes.numBlockIO = (99);/* Number of block outputs */
  QD2_DroneStack_Manual_2021a_M->Sizes.numBlockPrms = (698);/* Sum of parameter "widths" */
  return QD2_DroneStack_Manual_2021a_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
