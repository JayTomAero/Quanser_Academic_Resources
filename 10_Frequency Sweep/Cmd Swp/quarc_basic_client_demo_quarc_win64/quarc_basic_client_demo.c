/*
 * quarc_basic_client_demo.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "quarc_basic_client_demo".
 *
 * Model version              : 1.28
 * Simulink Coder version : 26.1 (R2026a) 20-Nov-2025
 * C source code generated on : Wed Aug 12 11:33:05 2026
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "quarc_basic_client_demo.h"
#include <math.h>
#include "rtwtypes.h"
#include "quarc_basic_client_demo_private.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "quarc_basic_client_demo_dt.h"

/* Block signals (default storage) */
B_quarc_basic_client_demo_T quarc_basic_client_demo_B;

/* Block states (default storage) */
DW_quarc_basic_client_demo_T quarc_basic_client_demo_DW;

/* Real-time model */
static RT_MODEL_quarc_basic_client_d_T quarc_basic_client_demo_M_;
RT_MODEL_quarc_basic_client_d_T *const quarc_basic_client_demo_M =
  &quarc_basic_client_demo_M_;

/* Model output function */
void quarc_basic_client_demo_output(void)
{
  real_T temp;

  /* SignalGenerator: '<Root>/Signal Generator' */
  temp = quarc_basic_client_demo_P.SignalGenerator_Frequency *
    quarc_basic_client_demo_M->Timing.t[0];

  /* SignalGenerator: '<Root>/Signal Generator' */
  quarc_basic_client_demo_B.SignalGenerator = (1.0 - (temp - floor(temp)) * 2.0)
    * quarc_basic_client_demo_P.SignalGenerator_Amplitude;

  /* S-Function (stream_client_block): '<Root>/Stream Client' incorporates:
   *  Constant: '<Root>/Constant'
   */

  /* S-Function Block: quarc_basic_client_demo/Stream Client (stream_client_block) */
  {
    t_pstream_state state;
    t_error send_result;
    t_error receive_result;
    if (quarc_basic_client_demo_P.Constant_Value) {
      send_result = pstream_send(quarc_basic_client_demo_DW.StreamClient_Stream,
        &quarc_basic_client_demo_B.SignalGenerator);
    } else {
      send_result = 0;
    }

    quarc_basic_client_demo_B.StreamClient_o3 = (send_result > 0);
    receive_result = pstream_receive
      (quarc_basic_client_demo_DW.StreamClient_Stream,
       &quarc_basic_client_demo_B.StreamClient_o4);
    quarc_basic_client_demo_B.StreamClient_o5 = (receive_result > 0);
    quarc_basic_client_demo_B.StreamClient_o2 = 0;
    if (send_result < 0 && send_result != -QERR_WOULD_BLOCK) {
      quarc_basic_client_demo_B.StreamClient_o2 = send_result;
    } else if (receive_result < 0 && receive_result != -QERR_WOULD_BLOCK) {
      quarc_basic_client_demo_B.StreamClient_o2 = receive_result;
    }

    pstream_get_state(quarc_basic_client_demo_DW.StreamClient_Stream, &state);
    quarc_basic_client_demo_B.StreamClient_o1 = state;
  }
}

/* Model update function */
void quarc_basic_client_demo_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++quarc_basic_client_demo_M->Timing.clockTick0)) {
    ++quarc_basic_client_demo_M->Timing.clockTickH0;
  }

  quarc_basic_client_demo_M->Timing.t[0] =
    quarc_basic_client_demo_M->Timing.clockTick0 *
    quarc_basic_client_demo_M->Timing.stepSize0 +
    quarc_basic_client_demo_M->Timing.clockTickH0 *
    quarc_basic_client_demo_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++quarc_basic_client_demo_M->Timing.clockTick1)) {
      ++quarc_basic_client_demo_M->Timing.clockTickH1;
    }

    quarc_basic_client_demo_M->Timing.t[1] =
      quarc_basic_client_demo_M->Timing.clockTick1 *
      quarc_basic_client_demo_M->Timing.stepSize1 +
      quarc_basic_client_demo_M->Timing.clockTickH1 *
      quarc_basic_client_demo_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void quarc_basic_client_demo_initialize(void)
{
  /* Start for S-Function (stream_client_block): '<Root>/Stream Client' incorporates:
   *  Constant: '<Root>/Constant'
   */

  /* S-Function Block: quarc_basic_client_demo/Stream Client (stream_client_block) */
  {
    qthread_attr_t send_thread_attributes;
    qthread_attr_t receive_thread_attributes;
    struct qsched_param scheduling_parameters;
    int min_priority = qsched_get_priority_min(QSCHED_FIFO);
    int max_priority = qsched_get_priority_max(QSCHED_FIFO);
    t_pstream_options options;
    t_error result;
    quarc_basic_client_demo_DW.StreamClient_Stream = NULL;
    quarc_basic_client_demo_B.StreamClient_o4 =
      quarc_basic_client_demo_P.StreamClient_default_value;
    result = 0;
    options.size = sizeof(options);
    options.flags = quarc_basic_client_demo_P.StreamClient_Endian &
      PSTREAM_FLAG_ENDIAN_MASK;
    if (quarc_basic_client_demo_P.StreamClient_Implementation ==
        STREAM_CLIENT_IMPLEMENTATION_THREAD) {
      options.flags |= PSTREAM_FLAG_MULTITHREADED;
    }

    if (quarc_basic_client_demo_P.StreamClient_Optimize ==
        STREAM_CLIENT_OPTIMIZE_LATENCY) {
      options.flags |= PSTREAM_FLAG_MINIMIZE_LATENCY;
    }

    options.flags |= PSTREAM_FLAG_SEND_MOST_RECENT;
    options.flags |= PSTREAM_FLAG_RECEIVE_MOST_RECENT;
    options.send_unit_size = 8;
    options.num_send_units = 1;
    options.send_buffer_size = quarc_basic_client_demo_P.StreamClient_SndSize;
    options.send_fifo_size = quarc_basic_client_demo_P.StreamClient_SndFIFO;
    options.num_send_dimensions = 0;
    options.max_send_dimensions = NULL;
    if (quarc_basic_client_demo_P.StreamClient_SndPriority < min_priority) {
      scheduling_parameters.sched_priority = min_priority;
    } else if (quarc_basic_client_demo_P.StreamClient_SndPriority > max_priority)
    {
      scheduling_parameters.sched_priority = max_priority;
    } else {
      scheduling_parameters.sched_priority =
        quarc_basic_client_demo_P.StreamClient_SndPriority;
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
          rtmSetErrorStatus(quarc_basic_client_demo_M,
                            "Unable to set scheduling inheritance for Stream Client sending thread");
        }
      } else {
        rtmSetErrorStatus(quarc_basic_client_demo_M,
                          "The specified thread priority for the Stream Client sending thread is not valid for this target");
      }
    } else {
      rtmSetErrorStatus(quarc_basic_client_demo_M,
                        "Unable to set scheduling policy for Stream Client sending thread");
    }

    options.send_thread_attributes = &send_thread_attributes;
    options.receive_unit_size = 8;
    options.num_receive_units = 1;
    options.receive_buffer_size = quarc_basic_client_demo_P.StreamClient_RcvSize;
    options.receive_fifo_size = quarc_basic_client_demo_P.StreamClient_RcvFIFO;
    options.num_receive_dimensions = 0;
    options.max_receive_dimensions = NULL;
    if (quarc_basic_client_demo_P.StreamClient_RcvPriority < min_priority) {
      scheduling_parameters.sched_priority = min_priority;
    } else if (quarc_basic_client_demo_P.StreamClient_RcvPriority > max_priority)
    {
      scheduling_parameters.sched_priority = max_priority;
    } else {
      scheduling_parameters.sched_priority =
        quarc_basic_client_demo_P.StreamClient_RcvPriority;
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
            rtmSetErrorStatus(quarc_basic_client_demo_M,
                              "Unable to set scheduling inheritance for Stream Client receiving thread");
          }
        } else {
          rtmSetErrorStatus(quarc_basic_client_demo_M,
                            "The specified thread priority for the Stream Client receiving thread is not valid for this target");
        }
      } else {
        rtmSetErrorStatus(quarc_basic_client_demo_M,
                          "Unable to set scheduling policy for Stream Client receiving thread");
      }
    }

    options.receive_thread_attributes = &receive_thread_attributes;
    if (result == 0) {
      result = pstream_connect((const char *)
        quarc_basic_client_demo_P.StreamClient_URI, &options,
        &quarc_basic_client_demo_DW.StreamClient_Stream);
      if (result < 0 && result != -QERR_WOULD_BLOCK) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(quarc_basic_client_demo_M, _rt_error_message);
      }
    }

    qthread_attr_destroy(&send_thread_attributes);
    qthread_attr_destroy(&receive_thread_attributes);
  }
}

/* Model terminate function */
void quarc_basic_client_demo_terminate(void)
{
  /* Terminate for S-Function (stream_client_block): '<Root>/Stream Client' incorporates:
   *  Constant: '<Root>/Constant'
   */

  /* S-Function Block: quarc_basic_client_demo/Stream Client (stream_client_block) */
  {
    if (quarc_basic_client_demo_DW.StreamClient_Stream != NULL) {
      pstream_close(quarc_basic_client_demo_DW.StreamClient_Stream);
    }

    quarc_basic_client_demo_DW.StreamClient_Stream = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  quarc_basic_client_demo_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  quarc_basic_client_demo_update();
  UNUSED_PARAMETER(tid);
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
  quarc_basic_client_demo_initialize();
}

void MdlTerminate(void)
{
  quarc_basic_client_demo_terminate();
}

/* Registration function */
RT_MODEL_quarc_basic_client_d_T *quarc_basic_client_demo(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)quarc_basic_client_demo_M, 0,
                sizeof(RT_MODEL_quarc_basic_client_d_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&quarc_basic_client_demo_M->solverInfo,
                          &quarc_basic_client_demo_M->Timing.simTimeStep);
    rtsiSetTPtr(&quarc_basic_client_demo_M->solverInfo, &rtmGetTPtr
                (quarc_basic_client_demo_M));
    rtsiSetStepSizePtr(&quarc_basic_client_demo_M->solverInfo,
                       &quarc_basic_client_demo_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&quarc_basic_client_demo_M->solverInfo,
                          (&rtmGetErrorStatus(quarc_basic_client_demo_M)));
    rtsiSetRTModelPtr(&quarc_basic_client_demo_M->solverInfo,
                      quarc_basic_client_demo_M);
  }

  rtsiSetSimTimeStep(&quarc_basic_client_demo_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&quarc_basic_client_demo_M->solverInfo,
    false);
  rtsiSetIsContModeFrozen(&quarc_basic_client_demo_M->solverInfo, false);
  rtsiSetSolverName(&quarc_basic_client_demo_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = quarc_basic_client_demo_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    quarc_basic_client_demo_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    quarc_basic_client_demo_M->Timing.sampleTimes =
      (&quarc_basic_client_demo_M->Timing.sampleTimesArray[0]);
    quarc_basic_client_demo_M->Timing.offsetTimes =
      (&quarc_basic_client_demo_M->Timing.offsetTimesArray[0]);

    /* task periods */
    quarc_basic_client_demo_M->Timing.sampleTimes[0] = (0.0);
    quarc_basic_client_demo_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    quarc_basic_client_demo_M->Timing.offsetTimes[0] = (0.0);
    quarc_basic_client_demo_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(quarc_basic_client_demo_M,
             &quarc_basic_client_demo_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = quarc_basic_client_demo_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    quarc_basic_client_demo_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(quarc_basic_client_demo_M, -1);
  quarc_basic_client_demo_M->Timing.stepSize0 = 0.01;
  quarc_basic_client_demo_M->Timing.stepSize1 = 0.01;

  /* External mode info */
  quarc_basic_client_demo_M->Sizes.checksums[0] = (31952660U);
  quarc_basic_client_demo_M->Sizes.checksums[1] = (1375546491U);
  quarc_basic_client_demo_M->Sizes.checksums[2] = (708201160U);
  quarc_basic_client_demo_M->Sizes.checksums[3] = (796035681U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    quarc_basic_client_demo_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(quarc_basic_client_demo_M->extModeInfo,
      &quarc_basic_client_demo_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(quarc_basic_client_demo_M->extModeInfo,
                        quarc_basic_client_demo_M->Sizes.checksums);
    rteiSetTPtr(quarc_basic_client_demo_M->extModeInfo, rtmGetTPtr
                (quarc_basic_client_demo_M));
  }

  quarc_basic_client_demo_M->solverInfoPtr =
    (&quarc_basic_client_demo_M->solverInfo);
  quarc_basic_client_demo_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&quarc_basic_client_demo_M->solverInfo, 0.01);
  rtsiSetSolverMode(&quarc_basic_client_demo_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  quarc_basic_client_demo_M->blockIO = ((void *) &quarc_basic_client_demo_B);
  (void) memset(((void *) &quarc_basic_client_demo_B), 0,
                sizeof(B_quarc_basic_client_demo_T));

  {
    quarc_basic_client_demo_B.SignalGenerator = 0.0;
    quarc_basic_client_demo_B.StreamClient_o4 = 0.0;
  }

  /* parameters */
  quarc_basic_client_demo_M->defaultParam = ((real_T *)
    &quarc_basic_client_demo_P);

  /* states (dwork) */
  quarc_basic_client_demo_M->dwork = ((void *) &quarc_basic_client_demo_DW);
  (void) memset((void *)&quarc_basic_client_demo_DW, 0,
                sizeof(DW_quarc_basic_client_demo_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    quarc_basic_client_demo_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 20;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  quarc_basic_client_demo_M->Sizes.numContStates = (0);/* Number of continuous states */
  quarc_basic_client_demo_M->Sizes.numY = (0);/* Number of model outputs */
  quarc_basic_client_demo_M->Sizes.numU = (0);/* Number of model inputs */
  quarc_basic_client_demo_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  quarc_basic_client_demo_M->Sizes.numSampTimes = (2);/* Number of sample times */
  quarc_basic_client_demo_M->Sizes.numBlocks = (9);/* Number of blocks */
  quarc_basic_client_demo_M->Sizes.numBlockIO = (6);/* Number of block outputs */
  quarc_basic_client_demo_M->Sizes.numBlockPrms = (42);/* Sum of parameter "widths" */
  return quarc_basic_client_demo_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
