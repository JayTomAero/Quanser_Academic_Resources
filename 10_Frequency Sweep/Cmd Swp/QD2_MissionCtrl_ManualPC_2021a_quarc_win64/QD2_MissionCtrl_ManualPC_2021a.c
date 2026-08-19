/*
 * QD2_MissionCtrl_ManualPC_2021a.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "QD2_MissionCtrl_ManualPC_2021a".
 *
 * Model version              : 3.0
 * Simulink Coder version : 26.1 (R2026a) 20-Nov-2025
 * C source code generated on : Fri Aug 14 16:58:26 2026
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "QD2_MissionCtrl_ManualPC_2021a.h"
#include "rtwtypes.h"
#include <math.h>
#include "rt_nonfinite.h"
#include <string.h>
#include "QD2_MissionCtrl_ManualPC_2021a_private.h"
#include "zero_crossing_types.h"
#include "QD2_MissionCtrl_ManualPC_2021a_dt.h"

/* Named constants for MATLAB Function: '<S5>/MATLAB Function' */
#define QD2_MissionCtrl_Manu_CALL_EVENT (-1)

/* Block signals (default storage) */
B_QD2_MissionCtrl_ManualPC_20_T QD2_MissionCtrl_ManualPC_2021_B;

/* Continuous states */
X_QD2_MissionCtrl_ManualPC_20_T QD2_MissionCtrl_ManualPC_2021_X;

/* Disabled State Vector */
XDis_QD2_MissionCtrl_ManualPC_T QD2_MissionCtrl_ManualPC_2_XDis;

/* Block states (default storage) */
DW_QD2_MissionCtrl_ManualPC_2_T QD2_MissionCtrl_ManualPC_202_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_QD2_MissionCtrl_Manua_T QD2_MissionCtrl_ManualP_PrevZCX;

/* Real-time model */
static RT_MODEL_QD2_MissionCtrl_Manu_T QD2_MissionCtrl_ManualPC_202_M_;
RT_MODEL_QD2_MissionCtrl_Manu_T *const QD2_MissionCtrl_ManualPC_202_M =
  &QD2_MissionCtrl_ManualPC_202_M_;
static void rate_monotonic_scheduler(void);

/*
 * Send data to the host peripheral (e.g. force feedback game controllers). The packet includes
 * the peripheral identifier so that the host knows to which peripheral to direct the data.
 */
t_error host_send_extmode_packet(void * context, const void * data, t_uint
  data_length)
{
  return extmode_svr_send_custom_action(EXT_MODE_ACTION_HOST_INTERFACE, data,
    data_length);
}

t_error host_extmode_svr_connected_callback(void * context)
{
  /* S-Function Block: QD2_MissionCtrl_ManualPC_2021a/MISSION CONTROL QDRONE MANUAL POSITION CONTROL/JOYSTICK_FRSKY/Host Game Controller (host_game_controller_block) */
  {
    if (QD2_MissionCtrl_ManualPC_2021_P.HostGameController_Enabled) {

#pragma pack(push, 1)

      struct tag_game_controller_configuration {
        t_host_command_header header;
        char driver[16];
        t_host_game_controller_configuration configuration;
      } game_controller_configuration = {
        { 0, HOST_COMMAND_LOAD },
        "game_controller",

        {
          0,                           /* max effects */
          12,                          /* buffer size */

          { 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff },/* deadzone */

          { 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff },/* saturation */
          10000,                       /* overall force feedback gain */
          0,                           /* controller number */
          false,                       /* auto-center */
          false
        }
      };

#pragma pack(pop)

      t_error result;
      game_controller_configuration.configuration.buffer_size =
        QD2_MissionCtrl_ManualPC_2021_P.HostGameController_BufferSize;
      game_controller_configuration.configuration.controller_number =
        QD2_MissionCtrl_ManualPC_2021_P.HostGameController_Controller;
      game_controller_configuration.configuration.auto_center =
        QD2_MissionCtrl_ManualPC_2021_P.HostGameController_AutoCenter;
      game_controller_configuration.configuration.debug_mode =
        QD2_MissionCtrl_ManualPC_2021_P.HostGameController_DebugMode;
      result = host_send_extmode_packet(NULL, &game_controller_configuration,
        sizeof(game_controller_configuration));
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QD2_MissionCtrl_ManualPC_202_M, _rt_error_message);
      }
    }
  }

  return 0;
}

t_error host_extmode_svr_disconnected_callback(void * context)
{
  return 0;
}

t_error host_extmode_svr_custom_action_callback(void * context, t_uint action,
  const void * data, t_uint data_length)
{
  if (action == EXT_MODE_ACTION_HOST_INTERFACE) {
    const t_uint32 * packet = (const t_uint32 *) data;
    t_uint32 peripheral_identifier = packet[0];
    t_uint32 buffer_size = packet[1];
    const void * buffer = &packet[2];
    switch (peripheral_identifier) {
     case 0:
      /* S-Function Block: QD2_MissionCtrl_ManualPC_2021a/MISSION CONTROL QDRONE MANUAL POSITION CONTROL/JOYSTICK_FRSKY/Host Game Controller (host_game_controller_block) */
      {
        t_game_controller_states * state = (t_game_controller_states *) (buffer);
        if (buffer_size >= sizeof(t_game_controller_states)) {
          t_error result = qthread_section_lock
            (&QD2_MissionCtrl_ManualPC_202_DW.HostGameController_Lock);
          if (result == 0) {
            memory_copy
              (&QD2_MissionCtrl_ManualPC_202_DW.HostGameController_ControllerSt,
               sizeof
               (*&QD2_MissionCtrl_ManualPC_202_DW.HostGameController_ControllerSt),
               state);
            QD2_MissionCtrl_ManualPC_202_DW.HostGameController_NewData = true;
            qthread_section_unlock
              (&QD2_MissionCtrl_ManualPC_202_DW.HostGameController_Lock);
          }
        } else {
          rtmSetErrorStatus(QD2_MissionCtrl_ManualPC_202_M,
                            "A Host Game Controller block has received an invalid packet from the host!");
        }
      }
      break;

     default:
      rtmSetErrorStatus(QD2_MissionCtrl_ManualPC_202_M,
                        "Invalid peripheral identifier received");
      break;
    }
  }

  return 0;
}

time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(QD2_MissionCtrl_ManualPC_202_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(QD2_MissionCtrl_ManualPC_202_M, 2);
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

  /* tid 1 shares data with slower tid rate: 2 */
  if (QD2_MissionCtrl_ManualPC_202_M->Timing.TaskCounters.TID[1] == 0) {
    QD2_MissionCtrl_ManualPC_202_M->Timing.RateInteraction.TID1_2 =
      (QD2_MissionCtrl_ManualPC_202_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    QD2_MissionCtrl_ManualPC_202_M->Timing.perTaskSampleHits[5] =
      QD2_MissionCtrl_ManualPC_202_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (QD2_MissionCtrl_ManualPC_202_M->Timing.TaskCounters.TID[2])++;
  if ((QD2_MissionCtrl_ManualPC_202_M->Timing.TaskCounters.TID[2]) > 15) {/* Sample time: [0.016s, 0.0s] */
    QD2_MissionCtrl_ManualPC_202_M->Timing.TaskCounters.TID[2] = 0;
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
  int_T nXc = 3;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  QD2_MissionCtrl_ManualPC_2021a_derivatives();

  /* f1 = f(t + h, y + h*f0) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f0[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f1);
  QD2_MissionCtrl_ManualPC_2021a_output0();
  QD2_MissionCtrl_ManualPC_2021a_derivatives();

  /* tnew = t + h
     ynew = y + (h/2)*(f0 + f1) */
  temp = 0.5*h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + f1[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function for TID0 */
void QD2_MissionCtrl_ManualPC_2021a_output0(void) /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_HostGameController_o3[2];
  real_T rtb_HostGameController_o4;
  real_T rtb_HostGameController_o5;
  real_T rtb_HostGameController_o6;
  real_T rtb_HostGameController_o7;
  real_T rtb_HostGameController_o9;
  real_T rtb_TmpSignalConversionAtCompar[6];
  real_T rtb_Time;
  real_T rtb_ImpSel_InsertedFor_width_at;
  int32_T rtb_StreamServer_o2;
  uint8_T rtb_StreamServer_o1;
  boolean_T rtb_HostGameController_o2[32];
  boolean_T rtb_ImpSel_InsertedFor_Trigger_;

  /* local scratch DWork variables */
  int32_T ForEach_itr;
  real_T rtb_TmpSignalConversionAtStream[16];
  real_T rtb_EulerAnglestoRotationMatrix[9];
  real_T rtb_XVelocityScaling_0[3];
  real_T rtb_Gain2_idx_0;
  real_T rtb_Gain2_idx_2;
  real_T rtb_Gain2_idx_3;
  real_T rtb_Time_m;
  real_T rtb_XVelocityScaling;
  int32_T i;
  boolean_T rtb_Compare_p;
  boolean_T rtb_Relation;
  boolean_T rtb_RelationalOperator;
  boolean_T tmp;
  ZCEventType zcEvent;
  if (rtmIsMajorTimeStep(QD2_MissionCtrl_ManualPC_202_M)) {
    /* set solver stop time */
    if (!(QD2_MissionCtrl_ManualPC_202_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&QD2_MissionCtrl_ManualPC_202_M->solverInfo,
                            ((QD2_MissionCtrl_ManualPC_202_M->Timing.clockTickH0
        + 1) * QD2_MissionCtrl_ManualPC_202_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&QD2_MissionCtrl_ManualPC_202_M->solverInfo,
                            ((QD2_MissionCtrl_ManualPC_202_M->Timing.clockTick0
        + 1) * QD2_MissionCtrl_ManualPC_202_M->Timing.stepSize0 +
        QD2_MissionCtrl_ManualPC_202_M->Timing.clockTickH0 *
        QD2_MissionCtrl_ManualPC_202_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(QD2_MissionCtrl_ManualPC_202_M)) {
    QD2_MissionCtrl_ManualPC_202_M->Timing.t[0] = rtsiGetT
      (&QD2_MissionCtrl_ManualPC_202_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(QD2_MissionCtrl_ManualPC_202_DW.EnabledSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(QD2_MissionCtrl_ManualPC_202_DW.FrSKYMapping_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(QD2_MissionCtrl_ManualPC_202_DW.InitializationandConditioning_S);

  /* Reset subsysRan breadcrumbs */
  srClearBC(QD2_MissionCtrl_ManualPC_202_DW.pulsecount_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(QD2_MissionCtrl_ManualPC_202_DW.TriggeredSubsystem_SubsysRanBC);
  tmp = rtmIsMajorTimeStep(QD2_MissionCtrl_ManualPC_202_M);
  if (tmp) {
    /* S-Function (host_initialize_block): '<S9>/Host Initialize' */

    /* S-Function Block: QD2_MissionCtrl_ManualPC_2021a/MISSION CONTROL QDRONE MANUAL POSITION CONTROL/JOYSTICK_FRSKY/Host Initialize (host_initialize_block) */
    {
      QD2_MissionCtrl_ManualPC_2021_B.HostInitialize_o1 =
        (rtExtModeQuarcIsConnected() ? HOST_STATE_CONNECTED :
         HOST_STATE_NOT_CONNECTED);
    }

    /* SignalConversion generated from: '<S9>/Compare' incorporates:
     *  S-Function (host_game_controller_block): '<S9>/Host Game Controller'
     */

    /* S-Function Block: QD2_MissionCtrl_ManualPC_2021a/MISSION CONTROL QDRONE MANUAL POSITION CONTROL/JOYSTICK_FRSKY/Host Game Controller (host_game_controller_block) */
    {
      if (QD2_MissionCtrl_ManualPC_2021_P.HostGameController_Enabled) {
        t_error result = qthread_section_lock
          (&QD2_MissionCtrl_ManualPC_202_DW.HostGameController_Lock);
        if (result == 0) {
          {
            int_T i1;
            boolean_T *y1 = &rtb_HostGameController_o2[0];
            for (i1=0; i1 < 32; i1++) {
              y1[i1] =
                ((QD2_MissionCtrl_ManualPC_202_DW.HostGameController_ControllerSt.buttons
                  & (1U << i1)) != 0);
            }
          }

          rtb_HostGameController_o3[0] =
            QD2_MissionCtrl_ManualPC_202_DW.HostGameController_ControllerSt.sliders
            [0];
          rtb_HostGameController_o3[1] =
            QD2_MissionCtrl_ManualPC_202_DW.HostGameController_ControllerSt.sliders
            [1];
          rtb_HostGameController_o4 =
            QD2_MissionCtrl_ManualPC_202_DW.HostGameController_ControllerSt.x;
          rtb_HostGameController_o5 =
            QD2_MissionCtrl_ManualPC_202_DW.HostGameController_ControllerSt.y;
          rtb_HostGameController_o6 =
            QD2_MissionCtrl_ManualPC_202_DW.HostGameController_ControllerSt.z;
          rtb_HostGameController_o7 =
            QD2_MissionCtrl_ManualPC_202_DW.HostGameController_ControllerSt.rx;
          rtb_TmpSignalConversionAtCompar[4] =
            QD2_MissionCtrl_ManualPC_202_DW.HostGameController_ControllerSt.ry;
          rtb_HostGameController_o9 =
            QD2_MissionCtrl_ManualPC_202_DW.HostGameController_ControllerSt.rz;
          QD2_MissionCtrl_ManualPC_2021_B.HostGameController_o1 =
            QD2_MissionCtrl_ManualPC_202_DW.HostGameController_NewData;
          QD2_MissionCtrl_ManualPC_202_DW.HostGameController_NewData = false;
          qthread_section_unlock
            (&QD2_MissionCtrl_ManualPC_202_DW.HostGameController_Lock);
        } else {
          {
            int_T i1;
            boolean_T *y1 = &rtb_HostGameController_o2[0];
            for (i1=0; i1 < 32; i1++) {
              y1[i1] = false;
            }
          }

          rtb_HostGameController_o3[0] = 0;
          rtb_HostGameController_o3[1] = 0;
          rtb_HostGameController_o4 = 0;
          rtb_HostGameController_o5 = 0;
          rtb_HostGameController_o6 = 0;
          rtb_HostGameController_o7 = 0;
          rtb_TmpSignalConversionAtCompar[4] = 0;
          rtb_HostGameController_o9 = 0;
          QD2_MissionCtrl_ManualPC_2021_B.HostGameController_o1 = false;
        }
      } else {
        {
          int_T i1;
          boolean_T *y1 = &rtb_HostGameController_o2[0];
          for (i1=0; i1 < 32; i1++) {
            y1[i1] = false;
          }
        }

        rtb_HostGameController_o3[0] = 0;
        rtb_HostGameController_o3[1] = 0;
        rtb_HostGameController_o4 = 0;
        rtb_HostGameController_o5 = 0;
        rtb_HostGameController_o6 = 0;
        rtb_HostGameController_o7 = 0;
        rtb_TmpSignalConversionAtCompar[4] = 0;
        rtb_HostGameController_o9 = 0;
        QD2_MissionCtrl_ManualPC_2021_B.HostGameController_o1 = false;
      }
    }

    rtb_TmpSignalConversionAtCompar[0] = rtb_HostGameController_o4;
    rtb_TmpSignalConversionAtCompar[1] = rtb_HostGameController_o5;
    rtb_TmpSignalConversionAtCompar[2] = rtb_HostGameController_o6;
    rtb_TmpSignalConversionAtCompar[3] = rtb_HostGameController_o7;
    rtb_TmpSignalConversionAtCompar[5] = rtb_HostGameController_o9;

    /* Logic: '<S9>/AND' incorporates:
     *  Constant: '<S9>/Constant'
     *  S-Function (compare_block): '<S9>/Compare'
     *  SignalConversion generated from: '<S9>/Compare'
     */
    rtb_Relation = (rtb_TmpSignalConversionAtCompar[0] ==
                    QD2_MissionCtrl_ManualPC_2021_P.Constant_Value_k[0]);
    for (i = 0; i < 5; i++) {
      rtb_Relation = (rtb_Relation && (rtb_TmpSignalConversionAtCompar[i + 1] ==
        QD2_MissionCtrl_ManualPC_2021_P.Constant_Value_k[i + 1]));
    }

    /* RelationalOperator: '<S21>/Relation' incorporates:
     *  Constant: '<S21>/threshold'
     *  Logic: '<S9>/AND'
     */
    rtb_Relation = ((real_T)rtb_Relation >=
                    QD2_MissionCtrl_ManualPC_2021_P.Threshold_threshold_p);

    /* Logic: '<S21>/Logical Operator' */
    QD2_MissionCtrl_ManualPC_2021_B.LogicalOperator = !rtb_Relation;

    /* DiscreteIntegrator: '<S21>/Discrete-Time Integrator' */
    if (QD2_MissionCtrl_ManualPC_2021_B.LogicalOperator ||
        (QD2_MissionCtrl_ManualPC_202_DW.DiscreteTimeIntegrator_PrevRese != 0))
    {
      QD2_MissionCtrl_ManualPC_202_DW.DiscreteTimeIntegrator_DSTATE =
        QD2_MissionCtrl_ManualPC_2021_P.DiscreteTimeIntegrator_IC_j;
    }

    /* RelationalOperator: '<S21>/Relational Operator' incorporates:
     *  Constant: '<S21>/duration'
     *  DiscreteIntegrator: '<S21>/Discrete-Time Integrator'
     */
    rtb_RelationalOperator =
      (QD2_MissionCtrl_ManualPC_202_DW.DiscreteTimeIntegrator_DSTATE >=
       QD2_MissionCtrl_ManualPC_2021_P.Threshold_duration_l);

    /* Outputs for Enabled SubSystem: '<S9>/FrSKYMapping' incorporates:
     *  EnablePort: '<S18>/Valid Signals Detected'
     */
    if (rtsiIsModeUpdateTimeStep(&QD2_MissionCtrl_ManualPC_202_M->solverInfo)) {
      /* Logic: '<S9>/NOT' */
      if (!rtb_RelationalOperator) {
        QD2_MissionCtrl_ManualPC_202_DW.FrSKYMapping_MODE = true;
      } else if (QD2_MissionCtrl_ManualPC_202_DW.FrSKYMapping_MODE) {
        /* Disable for DiscreteIntegrator: '<S23>/Discrete-Time Integrator' */
        QD2_MissionCtrl_ManualPC_202_DW.DiscreteTimeIntegrator_DSTATE_h =
          QD2_MissionCtrl_ManualPC_2021_B.DiscreteTimeIntegrator;
        QD2_MissionCtrl_ManualPC_202_DW.FrSKYMapping_MODE = false;
      }

      /* End of Logic: '<S9>/NOT' */
    }

    if (QD2_MissionCtrl_ManualPC_202_DW.FrSKYMapping_MODE) {
      for (i = 0; i < 32; i++) {
        /* SignalConversion generated from: '<S18>/Buttons' */
        QD2_MissionCtrl_ManualPC_2021_B.Buttons[i] = rtb_HostGameController_o2[i];
      }

      /* RelationalOperator: '<S23>/Relation' incorporates:
       *  Constant: '<S23>/threshold'
       */
      rtb_Compare_p = ((real_T)QD2_MissionCtrl_ManualPC_2021_B.Buttons[0] >=
                       QD2_MissionCtrl_ManualPC_2021_P.Threshold_threshold);

      /* DataTypeConversion: '<S23>/Data Type Conversion' */
      QD2_MissionCtrl_ManualPC_2021_B.DataTypeConversion_g = rtb_Compare_p;

      /* Logic: '<S23>/Logical Operator' */
      QD2_MissionCtrl_ManualPC_2021_B.LogicalOperator_n = !rtb_Compare_p;

      /* DiscreteIntegrator: '<S23>/Discrete-Time Integrator' */
      if (QD2_MissionCtrl_ManualPC_2021_B.LogicalOperator_n ||
          (QD2_MissionCtrl_ManualPC_202_DW.DiscreteTimeIntegrator_PrevRe_i != 0))
      {
        QD2_MissionCtrl_ManualPC_202_DW.DiscreteTimeIntegrator_DSTATE_h =
          QD2_MissionCtrl_ManualPC_2021_P.DiscreteTimeIntegrator_IC;
      }

      /* DiscreteIntegrator: '<S23>/Discrete-Time Integrator' */
      QD2_MissionCtrl_ManualPC_2021_B.DiscreteTimeIntegrator =
        QD2_MissionCtrl_ManualPC_202_DW.DiscreteTimeIntegrator_DSTATE_h;

      /* RelationalOperator: '<S23>/Relational Operator' incorporates:
       *  Constant: '<S23>/duration'
       */
      QD2_MissionCtrl_ManualPC_2021_B.RelationalOperator =
        (QD2_MissionCtrl_ManualPC_2021_B.DiscreteTimeIntegrator >=
         QD2_MissionCtrl_ManualPC_2021_P.Threshold_duration);

      /* Gain: '<S18>/Gain' */
      QD2_MissionCtrl_ManualPC_2021_B.Gain_h =
        QD2_MissionCtrl_ManualPC_2021_P.Gain_Gain * rtb_HostGameController_o7;

      /* Bias: '<S18>/Bias' incorporates:
       *  Gain: '<S18>/Gain1'
       */
      QD2_MissionCtrl_ManualPC_2021_B.Bias =
        QD2_MissionCtrl_ManualPC_2021_P.Gain1_Gain * rtb_HostGameController_o4 +
        QD2_MissionCtrl_ManualPC_2021_P.Bias_Bias;

      /* SignalConversion generated from: '<S18>/y' */
      QD2_MissionCtrl_ManualPC_2021_B.y = rtb_HostGameController_o5;

      /* SignalConversion generated from: '<S18>/z' */
      QD2_MissionCtrl_ManualPC_2021_B.z = rtb_HostGameController_o6;

      /* RelationalOperator: '<S22>/Compare' incorporates:
       *  Constant: '<S22>/Constant'
       */
      QD2_MissionCtrl_ManualPC_2021_B.Compare_n = (rtb_HostGameController_o9 >=
        QD2_MissionCtrl_ManualPC_2021_P.CompareToConstant_const);
      if (rtsiIsModeUpdateTimeStep(&QD2_MissionCtrl_ManualPC_202_M->solverInfo))
      {
        srUpdateBC(QD2_MissionCtrl_ManualPC_202_DW.FrSKYMapping_SubsysRanBC);
      }
    }

    /* End of Outputs for SubSystem: '<S9>/FrSKYMapping' */

    /* Outputs for Atomic SubSystem: '<S9>/Pulse Check' */
    /* Outputs for Triggered SubSystem: '<S20>/pulse count ' incorporates:
     *  TriggerPort: '<S24>/Trigger'
     */
    if (QD2_MissionCtrl_ManualPC_2021_B.HostGameController_o1 &&
        (QD2_MissionCtrl_ManualP_PrevZCX.pulsecount_Trig_ZCE != POS_ZCSIG)) {
      /* Sum: '<S25>/FixPt Sum1' incorporates:
       *  Constant: '<S24>/Constant1'
       *  Constant: '<S25>/FixPt Constant'
       *  Sum: '<S24>/Sum'
       *  UnitDelay: '<S24>/Unit Delay'
       */
      QD2_MissionCtrl_ManualPC_2021_B.FixPtSum1 =
        (QD2_MissionCtrl_ManualPC_2021_P.Constant1_Value_p +
         QD2_MissionCtrl_ManualPC_202_DW.UnitDelay_DSTATE) +
        QD2_MissionCtrl_ManualPC_2021_P.FixPtConstant_Value;

      /* Update for UnitDelay: '<S24>/Unit Delay' */
      QD2_MissionCtrl_ManualPC_202_DW.UnitDelay_DSTATE =
        QD2_MissionCtrl_ManualPC_2021_B.FixPtSum1;
      QD2_MissionCtrl_ManualPC_202_DW.pulsecount_SubsysRanBC = 4;
    }

    QD2_MissionCtrl_ManualP_PrevZCX.pulsecount_Trig_ZCE =
      QD2_MissionCtrl_ManualPC_2021_B.HostGameController_o1;

    /* End of Outputs for SubSystem: '<S20>/pulse count ' */

    /* S-Function (compare_block): '<S20>/Compare' incorporates:
     *  Constant: '<S20>/Pulse Check'
     */
    {
      QD2_MissionCtrl_ManualPC_2021_B.Compare_g =
        (QD2_MissionCtrl_ManualPC_2021_B.FixPtSum1 >=
         QD2_MissionCtrl_ManualPC_2021_P.PulseCheck_Value);
    }

    /* End of Outputs for SubSystem: '<S9>/Pulse Check' */

    /* Outputs for Enabled SubSystem: '<S9>/Initialization and Conditioning' incorporates:
     *  EnablePort: '<S19>/Enable'
     */
    if (QD2_MissionCtrl_ManualPC_2021_B.Compare_g) {
      /* DataTypeConversion: '<S19>/Data Type Conversion2' */
      QD2_MissionCtrl_ManualPC_2021_B.DataTypeConversion2_i =
        QD2_MissionCtrl_ManualPC_2021_B.RelationalOperator;

      /* DataTypeConversion: '<S19>/Data Type Conversion4' */
      QD2_MissionCtrl_ManualPC_2021_B.DataTypeConversion4 =
        rtb_RelationalOperator;

      /* DataTypeConversion: '<S19>/Data Type Conversion5' */
      rtb_Time_m = QD2_MissionCtrl_ManualPC_2021_B.Buttons[1];

      /* Logic: '<S19>/Logical Operator' */
      rtb_Compare_p = !rtb_RelationalOperator;

      /* DataTypeConversion: '<S19>/Data Type Conversion7' */
      rtb_XVelocityScaling = QD2_MissionCtrl_ManualPC_2021_B.Compare_n;

      /* SignalConversion generated from: '<S19>/Joystick Issue (0,1)' */
      QD2_MissionCtrl_ManualPC_2021_B.OutportBufferForJoystickIssue01 =
        QD2_MissionCtrl_ManualPC_2021_B.DataTypeConversion4;

      /* DeadZone: '<S19>/Dead Zone' */
      if (QD2_MissionCtrl_ManualPC_2021_B.y >
          QD2_MissionCtrl_ManualPC_2021_P.DeadZone_End) {
        rtb_Gain2_idx_0 = QD2_MissionCtrl_ManualPC_2021_B.y -
          QD2_MissionCtrl_ManualPC_2021_P.DeadZone_End;
      } else if (QD2_MissionCtrl_ManualPC_2021_B.y >=
                 QD2_MissionCtrl_ManualPC_2021_P.DeadZone_Start) {
        rtb_Gain2_idx_0 = 0.0;
      } else {
        rtb_Gain2_idx_0 = QD2_MissionCtrl_ManualPC_2021_B.y -
          QD2_MissionCtrl_ManualPC_2021_P.DeadZone_Start;
      }

      /* Product: '<S19>/Product' incorporates:
       *  DataTypeConversion: '<S19>/Data Type Conversion6'
       *  DeadZone: '<S19>/Dead Zone'
       */
      QD2_MissionCtrl_ManualPC_2021_B.Product_n[0] = (real_T)rtb_Compare_p *
        rtb_Gain2_idx_0;

      /* DeadZone: '<S19>/Dead Zone' */
      if (QD2_MissionCtrl_ManualPC_2021_B.z >
          QD2_MissionCtrl_ManualPC_2021_P.DeadZone_End) {
        rtb_Gain2_idx_0 = QD2_MissionCtrl_ManualPC_2021_B.z -
          QD2_MissionCtrl_ManualPC_2021_P.DeadZone_End;
      } else if (QD2_MissionCtrl_ManualPC_2021_B.z >=
                 QD2_MissionCtrl_ManualPC_2021_P.DeadZone_Start) {
        rtb_Gain2_idx_0 = 0.0;
      } else {
        rtb_Gain2_idx_0 = QD2_MissionCtrl_ManualPC_2021_B.z -
          QD2_MissionCtrl_ManualPC_2021_P.DeadZone_Start;
      }

      /* Product: '<S19>/Product' incorporates:
       *  DataTypeConversion: '<S19>/Data Type Conversion6'
       *  DeadZone: '<S19>/Dead Zone'
       */
      QD2_MissionCtrl_ManualPC_2021_B.Product_n[1] = (real_T)rtb_Compare_p *
        rtb_Gain2_idx_0;

      /* DeadZone: '<S19>/Dead Zone' */
      if (QD2_MissionCtrl_ManualPC_2021_B.Gain_h >
          QD2_MissionCtrl_ManualPC_2021_P.DeadZone_End) {
        rtb_Gain2_idx_0 = QD2_MissionCtrl_ManualPC_2021_B.Gain_h -
          QD2_MissionCtrl_ManualPC_2021_P.DeadZone_End;
      } else if (QD2_MissionCtrl_ManualPC_2021_B.Gain_h >=
                 QD2_MissionCtrl_ManualPC_2021_P.DeadZone_Start) {
        rtb_Gain2_idx_0 = 0.0;
      } else {
        rtb_Gain2_idx_0 = QD2_MissionCtrl_ManualPC_2021_B.Gain_h -
          QD2_MissionCtrl_ManualPC_2021_P.DeadZone_Start;
      }

      /* Product: '<S19>/Product' incorporates:
       *  DataTypeConversion: '<S19>/Data Type Conversion6'
       *  DeadZone: '<S19>/Dead Zone'
       */
      QD2_MissionCtrl_ManualPC_2021_B.Product_n[2] = (real_T)rtb_Compare_p *
        rtb_Gain2_idx_0;

      /* Product: '<S19>/Product1' incorporates:
       *  DataTypeConversion: '<S19>/Data Type Conversion6'
       */
      QD2_MissionCtrl_ManualPC_2021_B.Product1 = (real_T)rtb_Compare_p *
        QD2_MissionCtrl_ManualPC_2021_B.Bias;

      /* Product: '<S19>/Product2' incorporates:
       *  DataTypeConversion: '<S19>/Data Type Conversion6'
       */
      QD2_MissionCtrl_ManualPC_2021_B.Product2 = (real_T)rtb_Compare_p *
        rtb_Time_m;

      /* Product: '<S19>/Product3' incorporates:
       *  DataTypeConversion: '<S19>/Data Type Conversion6'
       */
      QD2_MissionCtrl_ManualPC_2021_B.Product3 = (real_T)rtb_Compare_p *
        rtb_XVelocityScaling;
      if (rtsiIsModeUpdateTimeStep(&QD2_MissionCtrl_ManualPC_202_M->solverInfo))
      {
        srUpdateBC
          (QD2_MissionCtrl_ManualPC_202_DW.InitializationandConditioning_S);
      }
    }

    /* End of Outputs for SubSystem: '<S9>/Initialization and Conditioning' */

    /* DataTypeConversion: '<S21>/Data Type Conversion' */
    QD2_MissionCtrl_ManualPC_2021_B.DataTypeConversion = rtb_Relation;

    /* S-Function (time_block): '<S5>/Time' */

    /* S-Function Block: QD2_MissionCtrl_ManualPC_2021a/Communication/Detect Communication loss/Time (time_block) */
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
        rtmSetErrorStatus(QD2_MissionCtrl_ManualPC_202_M, _rt_error_message);
        return;
      }
    }

    /* ManualSwitch: '<S2>/Manual Switch1' */
    if (QD2_MissionCtrl_ManualPC_2021_P.ManualSwitch1_CurrentSetting == 1) {
      /* ManualSwitch: '<S2>/Manual Switch1' */
      QD2_MissionCtrl_ManualPC_2021_B.ManualSwitch1[0] =
        QD2_MissionCtrl_ManualPC_2021_B.Product2;
      QD2_MissionCtrl_ManualPC_2021_B.ManualSwitch1[1] =
        QD2_MissionCtrl_ManualPC_2021_B.Product3;
      QD2_MissionCtrl_ManualPC_2021_B.ManualSwitch1[2] =
        QD2_MissionCtrl_ManualPC_2021_B.DataTypeConversion2_i;
      QD2_MissionCtrl_ManualPC_2021_B.ManualSwitch1[3] =
        QD2_MissionCtrl_ManualPC_2021_B.DataTypeConversion4;
      QD2_MissionCtrl_ManualPC_2021_B.ManualSwitch1[4] =
        QD2_MissionCtrl_ManualPC_2021_B.OutportBufferForJoystickIssue01;
      QD2_MissionCtrl_ManualPC_2021_B.ManualSwitch1[5] =
        QD2_MissionCtrl_ManualPC_2021_B.Product1;
      QD2_MissionCtrl_ManualPC_2021_B.ManualSwitch1[6] =
        QD2_MissionCtrl_ManualPC_2021_B.Product_n[0];
      QD2_MissionCtrl_ManualPC_2021_B.ManualSwitch1[7] =
        QD2_MissionCtrl_ManualPC_2021_B.Product_n[1];
      QD2_MissionCtrl_ManualPC_2021_B.ManualSwitch1[8] =
        QD2_MissionCtrl_ManualPC_2021_B.Product_n[2];
    } else {
      /* ManualSwitch: '<S2>/Manual Switch1' */
      QD2_MissionCtrl_ManualPC_2021_B.ManualSwitch1[0] = 0.0;
      QD2_MissionCtrl_ManualPC_2021_B.ManualSwitch1[1] = 0.0;
      QD2_MissionCtrl_ManualPC_2021_B.ManualSwitch1[2] = 0.0;
      QD2_MissionCtrl_ManualPC_2021_B.ManualSwitch1[3] = 0.0;
      QD2_MissionCtrl_ManualPC_2021_B.ManualSwitch1[4] = 0.0;
      QD2_MissionCtrl_ManualPC_2021_B.ManualSwitch1[5] = 0.0;
      QD2_MissionCtrl_ManualPC_2021_B.ManualSwitch1[6] = 0.0;
      QD2_MissionCtrl_ManualPC_2021_B.ManualSwitch1[7] = 0.0;
      QD2_MissionCtrl_ManualPC_2021_B.ManualSwitch1[8] = 0.0;
    }

    /* End of ManualSwitch: '<S2>/Manual Switch1' */

    /* RateTransition: '<S10>/Rate Transition2' */
    if (QD2_MissionCtrl_ManualPC_202_M->Timing.RateInteraction.TID1_2) {
      /* RateTransition: '<S10>/Rate Transition2' */
      for (i = 0; i < 7; i++) {
        QD2_MissionCtrl_ManualPC_2021_B.RateTransition2[i] =
          QD2_MissionCtrl_ManualPC_202_DW.RateTransition2_Buffer0[i];
      }
    }

    /* End of RateTransition: '<S10>/Rate Transition2' */
    for (i = 0; i < 7; i++) {
      /* Reshape: '<S10>/Reshape1' incorporates:
       *  RateTransition: '<S10>/Rate Transition2'
       */
      QD2_MissionCtrl_ManualPC_2021_B.Reshape1[i] =
        QD2_MissionCtrl_ManualPC_2021_B.RateTransition2[i];
    }

    /* DataTypeConversion: '<S11>/Data Type Conversion2' */
    QD2_MissionCtrl_ManualPC_2021_B.DataTypeConversion2 =
      QD2_MissionCtrl_ManualPC_2021_B.Reshape1[6];

    /* Bias: '<S11>/Subtract Rigid Body Reference Offset  (Initial Height)  to get height above the ground' */
    rtb_Gain2_idx_0 = QD2_MissionCtrl_ManualPC_2021_B.Reshape1[0] +
      QD2_MissionCtrl_ManualPC_2021_P.SubtractRigidBodyReferenceOffse[0];

    /* Saturate: '<S11>/Saturation' */
    if (rtb_Gain2_idx_0 > QD2_MissionCtrl_ManualPC_2021_P.Saturation_UpperSat[0])
    {
      /* Saturate: '<S11>/Saturation' */
      QD2_MissionCtrl_ManualPC_2021_B.Saturation[0] =
        QD2_MissionCtrl_ManualPC_2021_P.Saturation_UpperSat[0];
    } else if (rtb_Gain2_idx_0 <
               QD2_MissionCtrl_ManualPC_2021_P.Saturation_LowerSat[0]) {
      /* Saturate: '<S11>/Saturation' */
      QD2_MissionCtrl_ManualPC_2021_B.Saturation[0] =
        QD2_MissionCtrl_ManualPC_2021_P.Saturation_LowerSat[0];
    } else {
      /* Saturate: '<S11>/Saturation' */
      QD2_MissionCtrl_ManualPC_2021_B.Saturation[0] = rtb_Gain2_idx_0;
    }

    /* DataTypeConversion: '<S11>/Data Type Conversion1' */
    QD2_MissionCtrl_ManualPC_2021_B.DataTypeConversion1[0] =
      QD2_MissionCtrl_ManualPC_2021_B.Reshape1[3];

    /* Bias: '<S11>/Subtract Rigid Body Reference Offset  (Initial Height)  to get height above the ground' */
    rtb_Gain2_idx_0 = QD2_MissionCtrl_ManualPC_2021_B.Reshape1[1] +
      QD2_MissionCtrl_ManualPC_2021_P.SubtractRigidBodyReferenceOffse[1];

    /* Saturate: '<S11>/Saturation' */
    if (rtb_Gain2_idx_0 > QD2_MissionCtrl_ManualPC_2021_P.Saturation_UpperSat[1])
    {
      /* Saturate: '<S11>/Saturation' */
      QD2_MissionCtrl_ManualPC_2021_B.Saturation[1] =
        QD2_MissionCtrl_ManualPC_2021_P.Saturation_UpperSat[1];
    } else if (rtb_Gain2_idx_0 <
               QD2_MissionCtrl_ManualPC_2021_P.Saturation_LowerSat[1]) {
      /* Saturate: '<S11>/Saturation' */
      QD2_MissionCtrl_ManualPC_2021_B.Saturation[1] =
        QD2_MissionCtrl_ManualPC_2021_P.Saturation_LowerSat[1];
    } else {
      /* Saturate: '<S11>/Saturation' */
      QD2_MissionCtrl_ManualPC_2021_B.Saturation[1] = rtb_Gain2_idx_0;
    }

    /* DataTypeConversion: '<S11>/Data Type Conversion1' */
    QD2_MissionCtrl_ManualPC_2021_B.DataTypeConversion1[1] =
      QD2_MissionCtrl_ManualPC_2021_B.Reshape1[4];

    /* Bias: '<S11>/Subtract Rigid Body Reference Offset  (Initial Height)  to get height above the ground' */
    rtb_Gain2_idx_0 = QD2_MissionCtrl_ManualPC_2021_B.Reshape1[2] +
      QD2_MissionCtrl_ManualPC_2021_P.SubtractRigidBodyReferenceOffse[2];

    /* Saturate: '<S11>/Saturation' */
    if (rtb_Gain2_idx_0 > QD2_MissionCtrl_ManualPC_2021_P.Saturation_UpperSat[2])
    {
      /* Saturate: '<S11>/Saturation' */
      QD2_MissionCtrl_ManualPC_2021_B.Saturation[2] =
        QD2_MissionCtrl_ManualPC_2021_P.Saturation_UpperSat[2];
    } else if (rtb_Gain2_idx_0 <
               QD2_MissionCtrl_ManualPC_2021_P.Saturation_LowerSat[2]) {
      /* Saturate: '<S11>/Saturation' */
      QD2_MissionCtrl_ManualPC_2021_B.Saturation[2] =
        QD2_MissionCtrl_ManualPC_2021_P.Saturation_LowerSat[2];
    } else {
      /* Saturate: '<S11>/Saturation' */
      QD2_MissionCtrl_ManualPC_2021_B.Saturation[2] = rtb_Gain2_idx_0;
    }

    /* DataTypeConversion: '<S11>/Data Type Conversion1' */
    QD2_MissionCtrl_ManualPC_2021_B.DataTypeConversion1[2] =
      QD2_MissionCtrl_ManualPC_2021_B.Reshape1[5];

    /* S-Function (inverse_modulus_block): '<S11>/Unwrap optitrack measurement' */
    /* S-Function Block: QD2_MissionCtrl_ManualPC_2021a/MISSION CONTROL QDRONE MANUAL POSITION CONTROL/Measurement Conditioning/Unwrap optitrack measurement (inverse_modulus_block) */
    {
      static const real_T sampling_period = 0.001;
      real_T half_range =
        QD2_MissionCtrl_ManualPC_2021_P.Unwrapoptitrackmeasurement_Modu / 2.0;
      real_T du, dy;
      if (QD2_MissionCtrl_ManualPC_202_DW.Unwrapoptitrackmeasurement_Firs) {
        QD2_MissionCtrl_ManualPC_202_DW.Unwrapoptitrackmeasurement_Firs = false;
        QD2_MissionCtrl_ManualPC_202_DW.Unwrapoptitrackmeasurement_Prev =
          QD2_MissionCtrl_ManualPC_2021_B.DataTypeConversion1[2];
      }

      du = (real_T) QD2_MissionCtrl_ManualPC_2021_B.DataTypeConversion1[2] -
        QD2_MissionCtrl_ManualPC_202_DW.Unwrapoptitrackmeasurement_Prev;
      if (du > half_range) {
        QD2_MissionCtrl_ManualPC_202_DW.Unwrapoptitrackmeasurement_Revo =
          QD2_MissionCtrl_ManualPC_202_DW.Unwrapoptitrackmeasurement_Revo - 1;
        dy = du -
          QD2_MissionCtrl_ManualPC_2021_P.Unwrapoptitrackmeasurement_Modu;
      } else if (du < -half_range) {
        QD2_MissionCtrl_ManualPC_202_DW.Unwrapoptitrackmeasurement_Revo =
          QD2_MissionCtrl_ManualPC_202_DW.Unwrapoptitrackmeasurement_Revo + 1;
        dy = du +
          QD2_MissionCtrl_ManualPC_2021_P.Unwrapoptitrackmeasurement_Modu;
      } else {
        dy = du;
      }

      QD2_MissionCtrl_ManualPC_2021_B.Unwrapoptitrackmeasurement =
        QD2_MissionCtrl_ManualPC_2021_B.DataTypeConversion1[2] +
        QD2_MissionCtrl_ManualPC_202_DW.Unwrapoptitrackmeasurement_Revo *
        QD2_MissionCtrl_ManualPC_2021_P.Unwrapoptitrackmeasurement_Modu;
      QD2_MissionCtrl_ManualPC_202_DW.Unwrapoptitrackmeasurement_Prev =
        QD2_MissionCtrl_ManualPC_2021_B.DataTypeConversion1[2];
    }
  }

  /* Integrator: '<S14>/Integrator' */
  if (rtsiIsModeUpdateTimeStep(&QD2_MissionCtrl_ManualPC_202_M->solverInfo)) {
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &QD2_MissionCtrl_ManualP_PrevZCX.Integrator_Reset_ZCE,
                       (QD2_MissionCtrl_ManualPC_2021_B.ManualSwitch1[1]));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      QD2_MissionCtrl_ManualPC_2021_X.Integrator_CSTATE[0] =
        QD2_MissionCtrl_ManualPC_2021_P.Integrator_IC;
      QD2_MissionCtrl_ManualPC_2021_X.Integrator_CSTATE[1] =
        QD2_MissionCtrl_ManualPC_2021_P.Integrator_IC;
    }
  }

  if (tmp) {
    /* Memory: '<S14>/Memory1' */
    rtb_XVelocityScaling = QD2_MissionCtrl_ManualPC_202_DW.Memory1_PreviousInput;

    /* S-Function (euler_angles_to_rotation_matrix_block): '<S14>/Euler Angles to Rotation Matrix' incorporates:
     *  Constant: '<S14>/Constant'
     */
    {
      t_double sin_phi = sin(rtb_XVelocityScaling);
      t_double cos_phi = cos(rtb_XVelocityScaling);
      t_double sin_theta = sin(QD2_MissionCtrl_ManualPC_2021_P.Constant_Value_iq);
      t_double cos_theta = cos(QD2_MissionCtrl_ManualPC_2021_P.Constant_Value_iq);
      t_double sin_psi = sin(QD2_MissionCtrl_ManualPC_2021_P.Constant_Value_iq);
      t_double cos_psi = cos(QD2_MissionCtrl_ManualPC_2021_P.Constant_Value_iq);
      rtb_EulerAnglestoRotationMatrix[0] = cos_phi * cos_psi - sin_phi *
        sin_theta * sin_psi;
      rtb_EulerAnglestoRotationMatrix[1] = sin_phi * cos_psi + cos_phi *
        sin_theta * sin_psi;
      rtb_EulerAnglestoRotationMatrix[2] = -cos_theta * sin_psi;
      rtb_EulerAnglestoRotationMatrix[3] = -sin_phi * cos_theta;
      rtb_EulerAnglestoRotationMatrix[4] = cos_phi * cos_theta;
      rtb_EulerAnglestoRotationMatrix[5] = sin_theta;
      rtb_EulerAnglestoRotationMatrix[6] = cos_phi * sin_psi + sin_phi *
        sin_theta * cos_psi;
      rtb_EulerAnglestoRotationMatrix[7] = sin_phi * sin_psi - cos_phi *
        sin_theta * cos_psi;
      rtb_EulerAnglestoRotationMatrix[8] = cos_theta * cos_psi;
    }

    /* SignalConversion generated from: '<S14>/Matrix Multiply' incorporates:
     *  Gain: '<S14>/X Velocity Scaling'
     */
    rtb_XVelocityScaling_0[0] =
      QD2_MissionCtrl_ManualPC_2021_P.XVelocityScaling_Gain *
      QD2_MissionCtrl_ManualPC_2021_B.ManualSwitch1[7];

    /* Gain: '<S14>/Height Velocity Scaling' */
    rtb_Time_m = QD2_MissionCtrl_ManualPC_2021_P.HeightVelocityScaling_Gain *
      QD2_MissionCtrl_ManualPC_2021_B.ManualSwitch1[5];

    /* SignalConversion generated from: '<S14>/Matrix Multiply' incorporates:
     *  Gain: '<S14>/Y Velocity Scaling'
     */
    rtb_XVelocityScaling_0[1] =
      QD2_MissionCtrl_ManualPC_2021_P.YVelocityScaling_Gain *
      QD2_MissionCtrl_ManualPC_2021_B.ManualSwitch1[6];
    rtb_XVelocityScaling_0[2] = rtb_Time_m;

    /* Product: '<S14>/Matrix Multiply' incorporates:
     *  S-Function (euler_angles_to_rotation_matrix_block): '<S14>/Euler Angles to Rotation Matrix'
     */
    rtb_XVelocityScaling = 0.0;
    rtb_Gain2_idx_2 = 0.0;
    rtb_Gain2_idx_3 = 0.0;
    for (i = 0; i < 3; i++) {
      rtb_Gain2_idx_0 = rtb_XVelocityScaling_0[i];
      rtb_XVelocityScaling += rtb_EulerAnglestoRotationMatrix[3 * i] *
        rtb_Gain2_idx_0;
      rtb_Gain2_idx_2 += rtb_EulerAnglestoRotationMatrix[3 * i + 1] *
        rtb_Gain2_idx_0;
      rtb_Gain2_idx_3 += rtb_EulerAnglestoRotationMatrix[3 * i + 2] *
        rtb_Gain2_idx_0;
    }

    QD2_MissionCtrl_ManualPC_2021_B.MatrixMultiply[2] = rtb_Gain2_idx_3;
    QD2_MissionCtrl_ManualPC_2021_B.MatrixMultiply[1] = rtb_Gain2_idx_2;
    QD2_MissionCtrl_ManualPC_2021_B.MatrixMultiply[0] = rtb_XVelocityScaling;

    /* End of Product: '<S14>/Matrix Multiply' */
  }

  /* Integrator: '<S14>/Integrator2' */
  if (rtsiIsModeUpdateTimeStep(&QD2_MissionCtrl_ManualPC_202_M->solverInfo)) {
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &QD2_MissionCtrl_ManualP_PrevZCX.Integrator2_Reset_ZCE,
                       (QD2_MissionCtrl_ManualPC_2021_B.ManualSwitch1[1]));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      QD2_MissionCtrl_ManualPC_2021_X.Integrator2_CSTATE =
        QD2_MissionCtrl_ManualPC_2021_P.Integrator2_IC;
    }
  }

  /* Integrator: '<S14>/Integrator2' */
  QD2_MissionCtrl_ManualPC_2021_B.Integrator2 =
    QD2_MissionCtrl_ManualPC_2021_X.Integrator2_CSTATE;
  if (tmp) {
    /* S-Function (one_shot_block): '<S17>/one_shot_block' incorporates:
     *  Constant: '<S17>/width'
     */
    if (QD2_MissionCtrl_ManualPC_2021_P.one_shot_block_trigger_type == 1.0 &&
        QD2_MissionCtrl_ManualPC_2021_B.ManualSwitch1[0] -
        QD2_MissionCtrl_ManualPC_202_DW.one_shot_block_DSTATE[2] > 0 ) {
      if (QD2_MissionCtrl_ManualPC_202_DW.one_shot_block_DSTATE[0] == 1.0 &&
          QD2_MissionCtrl_ManualPC_2021_P.one_shot_block_redun_pulse == 1.0 ) {
      } else if (QD2_MissionCtrl_ManualPC_202_DW.one_shot_block_DSTATE[0] == 1.0
                 && QD2_MissionCtrl_ManualPC_2021_P.one_shot_block_redun_pulse ==
                 2.0 ) {
        QD2_MissionCtrl_ManualPC_202_DW.one_shot_block_DSTATE[1] = 0.0;
      } else {
        QD2_MissionCtrl_ManualPC_202_DW.one_shot_block_DSTATE[0] = 1.0;
      }
    } else if (QD2_MissionCtrl_ManualPC_2021_P.one_shot_block_trigger_type ==
               2.0 && QD2_MissionCtrl_ManualPC_2021_B.ManualSwitch1[0] -
               QD2_MissionCtrl_ManualPC_202_DW.one_shot_block_DSTATE[2] < 0 ) {
      if (QD2_MissionCtrl_ManualPC_202_DW.one_shot_block_DSTATE[0] == 1.0 &&
          QD2_MissionCtrl_ManualPC_2021_P.one_shot_block_redun_pulse == 1.0 ) {
      } else if (QD2_MissionCtrl_ManualPC_202_DW.one_shot_block_DSTATE[0] == 1.0
                 && QD2_MissionCtrl_ManualPC_2021_P.one_shot_block_redun_pulse ==
                 2.0 ) {
        QD2_MissionCtrl_ManualPC_202_DW.one_shot_block_DSTATE[1] = 0.0;
      } else {
        QD2_MissionCtrl_ManualPC_202_DW.one_shot_block_DSTATE[0] = 1.0;
      }
    } else if ((QD2_MissionCtrl_ManualPC_2021_P.one_shot_block_trigger_type ==
                3.0 && QD2_MissionCtrl_ManualPC_2021_B.ManualSwitch1[0] -
                QD2_MissionCtrl_ManualPC_202_DW.one_shot_block_DSTATE[2] < 0 ) ||
               (QD2_MissionCtrl_ManualPC_2021_P.one_shot_block_trigger_type ==
                3.0 && QD2_MissionCtrl_ManualPC_2021_B.ManualSwitch1[0] -
                QD2_MissionCtrl_ManualPC_202_DW.one_shot_block_DSTATE[2] > 0 ) )
    {
      if (QD2_MissionCtrl_ManualPC_202_DW.one_shot_block_DSTATE[0] == 1.0 &&
          QD2_MissionCtrl_ManualPC_2021_P.one_shot_block_redun_pulse == 1.0 ) {
      } else if (QD2_MissionCtrl_ManualPC_202_DW.one_shot_block_DSTATE[0] == 1.0
                 && QD2_MissionCtrl_ManualPC_2021_P.one_shot_block_redun_pulse ==
                 2.0 ) {
        QD2_MissionCtrl_ManualPC_202_DW.one_shot_block_DSTATE[1] = 0.0;
      } else {
        QD2_MissionCtrl_ManualPC_202_DW.one_shot_block_DSTATE[0] = 1.0;
      }
    }

    QD2_MissionCtrl_ManualPC_202_DW.one_shot_block_DSTATE[2] =
      QD2_MissionCtrl_ManualPC_2021_B.ManualSwitch1[0] ;
    if (QD2_MissionCtrl_ManualPC_202_DW.one_shot_block_DSTATE[0] == 1.0 &&
        QD2_MissionCtrl_ManualPC_202_DW.one_shot_block_DSTATE[1] <
        QD2_MissionCtrl_ManualPC_2021_P.width_Value ) {
      QD2_MissionCtrl_ManualPC_202_DW.one_shot_block_DSTATE[1] += 1.0;
      QD2_MissionCtrl_ManualPC_2021_B.one_shot_block = 1.0;
    } else if (QD2_MissionCtrl_ManualPC_202_DW.one_shot_block_DSTATE[0] == 1.0 &&
               QD2_MissionCtrl_ManualPC_202_DW.one_shot_block_DSTATE[1] >=
               QD2_MissionCtrl_ManualPC_2021_P.width_Value ) {
      QD2_MissionCtrl_ManualPC_202_DW.one_shot_block_DSTATE[0] = 0.0;
      QD2_MissionCtrl_ManualPC_202_DW.one_shot_block_DSTATE[1] = 0.0;
      QD2_MissionCtrl_ManualPC_2021_B.one_shot_block = 0.0;
    } else if (QD2_MissionCtrl_ManualPC_202_DW.one_shot_block_DSTATE[0] == 0.0 )
    {
      QD2_MissionCtrl_ManualPC_202_DW.one_shot_block_DSTATE[1] = 0.0;
      QD2_MissionCtrl_ManualPC_2021_B.one_shot_block = 0.0;
    }

    /* Switch: '<S17>/Switch' */
    if (QD2_MissionCtrl_ManualPC_2021_B.one_shot_block >=
        QD2_MissionCtrl_ManualPC_2021_P.Switch_Threshold) {
      /* Switch: '<S17>/Switch' incorporates:
       *  Constant: '<S8>/Constant1'
       */
      QD2_MissionCtrl_ManualPC_2021_B.Switch =
        QD2_MissionCtrl_ManualPC_2021_P.Constant1_Value;
    } else {
      /* Switch: '<S17>/Switch' incorporates:
       *  Constant: '<S8>/Constant'
       */
      QD2_MissionCtrl_ManualPC_2021_B.Switch =
        QD2_MissionCtrl_ManualPC_2021_P.Constant_Value;
    }

    /* End of Switch: '<S17>/Switch' */
  }

  /* Logic: '<S8>/Logical Operator' incorporates:
   *  Clock: '<S8>/Clock'
   *  Constant: '<S15>/Constant'
   *  RelationalOperator: '<S15>/Compare'
   */
  QD2_MissionCtrl_ManualPC_2021_B.LogicalOperator_m =
    ((QD2_MissionCtrl_ManualPC_202_M->Timing.t[0] >
      QD2_MissionCtrl_ManualPC_2021_P.CompareToConstant_const_d) &&
     (QD2_MissionCtrl_ManualPC_2021_B.Switch != 0.0));
  if (tmp) {
    /* SignalConversion generated from: '<S16>/Enable' */
    QD2_MissionCtrl_ManualPC_2021_B.HiddenBuf_InsertedFor_EnabledSu =
      QD2_MissionCtrl_ManualPC_2021_B.LogicalOperator_m;

    /* Outputs for Enabled SubSystem: '<S8>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S16>/Enable'
     */
    if (rtsiIsModeUpdateTimeStep(&QD2_MissionCtrl_ManualPC_202_M->solverInfo)) {
      if (QD2_MissionCtrl_ManualPC_2021_B.HiddenBuf_InsertedFor_EnabledSu) {
        if (!QD2_MissionCtrl_ManualPC_202_DW.EnabledSubsystem_MODE) {
          QD2_MissionCtrl_ManualPC_202_DW.EnabledSubsystem_MODE = true;
        }
      } else if (QD2_MissionCtrl_ManualPC_202_DW.EnabledSubsystem_MODE) {
        QD2_MissionCtrl_ManualPC_202_DW.EnabledSubsystem_MODE = false;
      }
    }

    /* End of Outputs for SubSystem: '<S8>/Enabled Subsystem' */
  }

  /* Outputs for Enabled SubSystem: '<S8>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S16>/Enable'
   */
  if (QD2_MissionCtrl_ManualPC_202_DW.EnabledSubsystem_MODE) {
    /* SignalConversion generated from: '<S16>/Pose (m, rad ) [4] ' */
    QD2_MissionCtrl_ManualPC_2021_B.Posemrad4[0] =
      QD2_MissionCtrl_ManualPC_2021_B.Saturation[0];
    QD2_MissionCtrl_ManualPC_2021_B.Posemrad4[1] =
      QD2_MissionCtrl_ManualPC_2021_B.Saturation[1];
    QD2_MissionCtrl_ManualPC_2021_B.Posemrad4[2] =
      QD2_MissionCtrl_ManualPC_2021_B.Saturation[2];
    QD2_MissionCtrl_ManualPC_2021_B.Posemrad4[3] =
      QD2_MissionCtrl_ManualPC_2021_B.Unwrapoptitrackmeasurement;
    if (rtsiIsModeUpdateTimeStep(&QD2_MissionCtrl_ManualPC_202_M->solverInfo)) {
      srUpdateBC(QD2_MissionCtrl_ManualPC_202_DW.EnabledSubsystem_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S8>/Enabled Subsystem' */

  /* Sum: '<S8>/Sum' incorporates:
   *  Constant: '<S2>/Home height (m)'
   */
  rtb_XVelocityScaling = QD2_MissionCtrl_ManualPC_2021_B.Posemrad4[2] +
    QD2_MissionCtrl_ManualPC_2021_P.Homeheightm_Value;

  /* Sum: '<S14>/Sum' incorporates:
   *  Gain: '<S14>/Gain2'
   *  Integrator: '<S14>/Integrator'
   */
  QD2_MissionCtrl_ManualPC_2021_B.Sum[0] =
    QD2_MissionCtrl_ManualPC_2021_P.Gain2_Gain[0] *
    QD2_MissionCtrl_ManualPC_2021_B.Posemrad4[0] +
    QD2_MissionCtrl_ManualPC_2021_X.Integrator_CSTATE[0];
  QD2_MissionCtrl_ManualPC_2021_B.Sum[1] =
    QD2_MissionCtrl_ManualPC_2021_P.Gain2_Gain[1] *
    QD2_MissionCtrl_ManualPC_2021_B.Posemrad4[1] +
    QD2_MissionCtrl_ManualPC_2021_X.Integrator_CSTATE[1];
  QD2_MissionCtrl_ManualPC_2021_B.Sum[2] =
    QD2_MissionCtrl_ManualPC_2021_P.Gain2_Gain[2] * rtb_XVelocityScaling +
    QD2_MissionCtrl_ManualPC_2021_B.MatrixMultiply[2];
  QD2_MissionCtrl_ManualPC_2021_B.Sum[3] =
    QD2_MissionCtrl_ManualPC_2021_P.Gain2_Gain[3] *
    QD2_MissionCtrl_ManualPC_2021_B.Posemrad4[3] +
    QD2_MissionCtrl_ManualPC_2021_B.Integrator2;
  if (tmp) {
    /* Gain: '<S14>/Gain' incorporates:
     *  Constant: '<S2>/Cube Length (m)'
     */
    QD2_MissionCtrl_ManualPC_2021_B.Gain =
      QD2_MissionCtrl_ManualPC_2021_P.Gain_Gain_f *
      QD2_MissionCtrl_ManualPC_2021_P.CubeLengthm_Value;
  }

  /* Switch: '<S46>/Switch2' incorporates:
   *  Constant: '<S2>/Cube Length (m)'
   *  RelationalOperator: '<S46>/LowerRelop1'
   *  RelationalOperator: '<S46>/UpperRelop'
   *  Switch: '<S46>/Switch'
   */
  if (QD2_MissionCtrl_ManualPC_2021_B.Sum[0] >
      QD2_MissionCtrl_ManualPC_2021_P.CubeLengthm_Value) {
    /* Switch: '<S46>/Switch2' */
    QD2_MissionCtrl_ManualPC_2021_B.Switch2[0] =
      QD2_MissionCtrl_ManualPC_2021_P.CubeLengthm_Value;
  } else if (QD2_MissionCtrl_ManualPC_2021_B.Sum[0] <
             QD2_MissionCtrl_ManualPC_2021_B.Gain) {
    /* Switch: '<S46>/Switch' incorporates:
     *  Switch: '<S46>/Switch2'
     */
    QD2_MissionCtrl_ManualPC_2021_B.Switch2[0] =
      QD2_MissionCtrl_ManualPC_2021_B.Gain;
  } else {
    /* Switch: '<S46>/Switch2' incorporates:
     *  Switch: '<S46>/Switch'
     */
    QD2_MissionCtrl_ManualPC_2021_B.Switch2[0] =
      QD2_MissionCtrl_ManualPC_2021_B.Sum[0];
  }

  if (QD2_MissionCtrl_ManualPC_2021_B.Sum[1] >
      QD2_MissionCtrl_ManualPC_2021_P.CubeLengthm_Value) {
    /* Switch: '<S46>/Switch2' */
    QD2_MissionCtrl_ManualPC_2021_B.Switch2[1] =
      QD2_MissionCtrl_ManualPC_2021_P.CubeLengthm_Value;
  } else if (QD2_MissionCtrl_ManualPC_2021_B.Sum[1] <
             QD2_MissionCtrl_ManualPC_2021_B.Gain) {
    /* Switch: '<S46>/Switch' incorporates:
     *  Switch: '<S46>/Switch2'
     */
    QD2_MissionCtrl_ManualPC_2021_B.Switch2[1] =
      QD2_MissionCtrl_ManualPC_2021_B.Gain;
  } else {
    /* Switch: '<S46>/Switch2' incorporates:
     *  Switch: '<S46>/Switch'
     */
    QD2_MissionCtrl_ManualPC_2021_B.Switch2[1] =
      QD2_MissionCtrl_ManualPC_2021_B.Sum[1];
  }

  /* End of Switch: '<S46>/Switch2' */

  /* Switch: '<S45>/Switch2' incorporates:
   *  Constant: '<S14>/Minimum Flight Height'
   *  Constant: '<S2>/Cube Length (m)'
   *  RelationalOperator: '<S45>/LowerRelop1'
   *  RelationalOperator: '<S45>/UpperRelop'
   *  Switch: '<S45>/Switch'
   */
  if (QD2_MissionCtrl_ManualPC_2021_B.Sum[2] >
      QD2_MissionCtrl_ManualPC_2021_P.CubeLengthm_Value) {
    /* Switch: '<S45>/Switch2' */
    QD2_MissionCtrl_ManualPC_2021_B.Switch2_h =
      QD2_MissionCtrl_ManualPC_2021_P.CubeLengthm_Value;
  } else if (QD2_MissionCtrl_ManualPC_2021_B.Sum[2] <
             QD2_MissionCtrl_ManualPC_2021_P.MinimumFlightHeight_Value) {
    /* Switch: '<S45>/Switch' incorporates:
     *  Constant: '<S14>/Minimum Flight Height'
     *  Switch: '<S45>/Switch2'
     */
    QD2_MissionCtrl_ManualPC_2021_B.Switch2_h =
      QD2_MissionCtrl_ManualPC_2021_P.MinimumFlightHeight_Value;
  } else {
    /* Switch: '<S45>/Switch2' incorporates:
     *  Switch: '<S45>/Switch'
     */
    QD2_MissionCtrl_ManualPC_2021_B.Switch2_h =
      QD2_MissionCtrl_ManualPC_2021_B.Sum[2];
  }

  /* End of Switch: '<S45>/Switch2' */
  if (tmp) {
    /* ManualSwitch: '<S2>/Command Enable' */
    if (QD2_MissionCtrl_ManualPC_2021_P.CommandEnable_CurrentSetting == 1) {
      /* ManualSwitch: '<S2>/Command Enable' incorporates:
       *  Constant: '<S2>/Custom Mode'
       */
      QD2_MissionCtrl_ManualPC_2021_B.CommandEnable =
        QD2_MissionCtrl_ManualPC_2021_P.CustomMode_Value;
    } else {
      /* ManualSwitch: '<S2>/Command Enable' incorporates:
       *  Constant: '<S2>/Home Mode'
       */
      QD2_MissionCtrl_ManualPC_2021_B.CommandEnable =
        QD2_MissionCtrl_ManualPC_2021_P.HomeMode_Value;
    }

    /* End of ManualSwitch: '<S2>/Command Enable' */
  }

  /* Switch: '<S2>/Switch' */
  if (QD2_MissionCtrl_ManualPC_2021_B.CommandEnable >
      QD2_MissionCtrl_ManualPC_2021_P.Switch_Threshold_l) {
    /* Switch: '<S2>/Switch' */
    QD2_MissionCtrl_ManualPC_2021_B.DesiredPosemrad[0] =
      QD2_MissionCtrl_ManualPC_2021_B.Switch2[0];
    QD2_MissionCtrl_ManualPC_2021_B.DesiredPosemrad[1] =
      QD2_MissionCtrl_ManualPC_2021_B.Switch2[1];
    QD2_MissionCtrl_ManualPC_2021_B.DesiredPosemrad[2] =
      QD2_MissionCtrl_ManualPC_2021_B.Switch2_h;
    QD2_MissionCtrl_ManualPC_2021_B.DesiredPosemrad[3] =
      QD2_MissionCtrl_ManualPC_2021_B.Sum[3];
  } else {
    /* Switch: '<S2>/Switch' */
    QD2_MissionCtrl_ManualPC_2021_B.DesiredPosemrad[0] =
      QD2_MissionCtrl_ManualPC_2021_B.Posemrad4[0];
    QD2_MissionCtrl_ManualPC_2021_B.DesiredPosemrad[1] =
      QD2_MissionCtrl_ManualPC_2021_B.Posemrad4[1];
    QD2_MissionCtrl_ManualPC_2021_B.DesiredPosemrad[2] = rtb_XVelocityScaling;
    QD2_MissionCtrl_ManualPC_2021_B.DesiredPosemrad[3] =
      QD2_MissionCtrl_ManualPC_2021_B.Posemrad4[3];
  }

  /* End of Switch: '<S2>/Switch' */
  if (tmp) {
    /* S-Function (time_block): '<S2>/Time' */

    /* S-Function Block: QD2_MissionCtrl_ManualPC_2021a/MISSION CONTROL QDRONE MANUAL POSITION CONTROL/Time (time_block) */
    {
      t_error result;
      t_timeout current_time;
      t_timeout time_difference;
      result = timeout_get_high_resolution_time(&current_time);
      if (result == 0) {
        result = timeout_subtract(&time_difference, &current_time,
          &_high_resolution_start_time);
        rtb_Time_m = time_difference.seconds + time_difference.nanoseconds *
          1e-9;
      }

      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QD2_MissionCtrl_ManualPC_202_M, _rt_error_message);
        return;
      }
    }

    /* SignalConversion generated from: '<S1>/Stream Server' */
    rtb_TmpSignalConversionAtStream[0] =
      QD2_MissionCtrl_ManualPC_2021_B.ManualSwitch1[0];
    rtb_TmpSignalConversionAtStream[1] =
      QD2_MissionCtrl_ManualPC_2021_B.ManualSwitch1[1];
    rtb_TmpSignalConversionAtStream[2] =
      QD2_MissionCtrl_ManualPC_2021_B.ManualSwitch1[2];
    rtb_TmpSignalConversionAtStream[3] =
      QD2_MissionCtrl_ManualPC_2021_B.ManualSwitch1[3];
    rtb_TmpSignalConversionAtStream[4] =
      QD2_MissionCtrl_ManualPC_2021_B.DataTypeConversion2;
    rtb_TmpSignalConversionAtStream[5] =
      QD2_MissionCtrl_ManualPC_2021_B.Saturation[0];
    rtb_TmpSignalConversionAtStream[6] =
      QD2_MissionCtrl_ManualPC_2021_B.Saturation[1];
    rtb_TmpSignalConversionAtStream[7] =
      QD2_MissionCtrl_ManualPC_2021_B.Saturation[2];
    rtb_TmpSignalConversionAtStream[8] =
      QD2_MissionCtrl_ManualPC_2021_B.DataTypeConversion1[0];
    rtb_TmpSignalConversionAtStream[9] =
      QD2_MissionCtrl_ManualPC_2021_B.DataTypeConversion1[1];
    rtb_TmpSignalConversionAtStream[10] =
      QD2_MissionCtrl_ManualPC_2021_B.Unwrapoptitrackmeasurement;
    rtb_TmpSignalConversionAtStream[11] =
      QD2_MissionCtrl_ManualPC_2021_B.DesiredPosemrad[0];
    rtb_TmpSignalConversionAtStream[12] =
      QD2_MissionCtrl_ManualPC_2021_B.DesiredPosemrad[1];
    rtb_TmpSignalConversionAtStream[13] =
      QD2_MissionCtrl_ManualPC_2021_B.DesiredPosemrad[2];
    rtb_TmpSignalConversionAtStream[14] =
      QD2_MissionCtrl_ManualPC_2021_B.DesiredPosemrad[3];
    rtb_TmpSignalConversionAtStream[15] = rtb_Time_m;

    /* S-Function (stream_server_block): '<S1>/Stream Server' incorporates:
     *  Constant: '<S1>/Constant'
     */

    /* S-Function Block: QD2_MissionCtrl_ManualPC_2021a/Communication/Stream Server (stream_server_block) */
    {
      t_pstream_state state;
      t_error send_result;
      t_error receive_result;
      if (!QD2_MissionCtrl_ManualPC_202_DW.StreamServer_Listening) {
        t_pstream_options options;
        t_error result;
        qthread_attr_t send_thread_attributes;
        qthread_attr_t receive_thread_attributes;
        struct qsched_param scheduling_parameters;
        int min_priority = qsched_get_priority_min(QSCHED_FIFO);
        int max_priority = qsched_get_priority_max(QSCHED_FIFO);
        result = 0;
        options.size = sizeof(options);
        options.flags = QD2_MissionCtrl_ManualPC_2021_P.StreamServer_Endian &
          PSTREAM_FLAG_ENDIAN_MASK;
        if (QD2_MissionCtrl_ManualPC_2021_P.StreamServer_Implementation ==
            STREAM_SERVER_IMPLEMENTATION_THREAD) {
          options.flags |= PSTREAM_FLAG_MULTITHREADED;
        }

        if (QD2_MissionCtrl_ManualPC_2021_P.StreamServer_Optimize ==
            STREAM_SERVER_OPTIMIZE_LATENCY) {
          options.flags |= PSTREAM_FLAG_MINIMIZE_LATENCY;
        }

        options.flags |= PSTREAM_FLAG_SEND_MOST_RECENT;
        options.flags |= PSTREAM_FLAG_RECEIVE_MOST_RECENT;
        options.send_unit_size = 8;
        options.num_send_units = 16;
        options.send_buffer_size =
          QD2_MissionCtrl_ManualPC_2021_P.StreamServer_SndSize;
        options.send_fifo_size =
          QD2_MissionCtrl_ManualPC_2021_P.StreamServer_SndFIFO;
        options.num_send_dimensions = 0;
        options.max_send_dimensions = NULL;
        if (QD2_MissionCtrl_ManualPC_2021_P.StreamServer_SndPriority <
            min_priority) {
          scheduling_parameters.sched_priority = min_priority;
        } else if (QD2_MissionCtrl_ManualPC_2021_P.StreamServer_SndPriority >
                   max_priority) {
          scheduling_parameters.sched_priority = max_priority;
        } else {
          scheduling_parameters.sched_priority =
            QD2_MissionCtrl_ManualPC_2021_P.StreamServer_SndPriority;
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
              rtmSetErrorStatus(QD2_MissionCtrl_ManualPC_202_M,
                                "Unable to set scheduling inheritance for Stream Client sending thread");
            }
          } else {
            rtmSetErrorStatus(QD2_MissionCtrl_ManualPC_202_M,
                              "The specified thread priority for the Stream Client sending thread is not valid for this target");
          }
        } else {
          rtmSetErrorStatus(QD2_MissionCtrl_ManualPC_202_M,
                            "Unable to set scheduling policy for Stream Client sending thread");
        }

        options.send_thread_attributes = &send_thread_attributes;
        options.receive_unit_size = 8;
        options.num_receive_units = 1;
        options.receive_buffer_size =
          QD2_MissionCtrl_ManualPC_2021_P.StreamServer_RcvSize;
        options.receive_fifo_size =
          QD2_MissionCtrl_ManualPC_2021_P.StreamServer_RcvFIFO;
        options.num_receive_dimensions = 0;
        options.max_receive_dimensions = NULL;
        if (QD2_MissionCtrl_ManualPC_2021_P.StreamServer_RcvPriority <
            min_priority) {
          scheduling_parameters.sched_priority = min_priority;
        } else if (QD2_MissionCtrl_ManualPC_2021_P.StreamServer_RcvPriority >
                   max_priority) {
          scheduling_parameters.sched_priority = max_priority;
        } else {
          scheduling_parameters.sched_priority =
            QD2_MissionCtrl_ManualPC_2021_P.StreamServer_RcvPriority;
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
                rtmSetErrorStatus(QD2_MissionCtrl_ManualPC_202_M,
                                  "Unable to set scheduling inheritance for Stream Client receiving thread");
              }
            } else {
              rtmSetErrorStatus(QD2_MissionCtrl_ManualPC_202_M,
                                "The specified thread priority for the Stream Client receiving thread is not valid for this target");
            }
          } else {
            rtmSetErrorStatus(QD2_MissionCtrl_ManualPC_202_M,
                              "Unable to set scheduling policy for Stream Client receiving thread");
          }
        }

        options.receive_thread_attributes = &receive_thread_attributes;
        if (result == 0) {
          /* Make sure URI is null-terminated */
          if (string_length((char *)
                            &QD2_MissionCtrl_ManualPC_2021_B.ModelArgument[0],
                            80) == 80) {
            rtmSetErrorStatus(QD2_MissionCtrl_ManualPC_202_M,
                              "URI passed to Stream Server block is not null-terminated!");
            result = -QERR_STRING_NOT_TERMINATED;
          } else {
            result = pstream_listen((char *)
              &QD2_MissionCtrl_ManualPC_2021_B.ModelArgument[0], &options,
              &QD2_MissionCtrl_ManualPC_202_DW.StreamServer_Stream);
            if (result < 0 && result != -QERR_WOULD_BLOCK) {
              msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
                (_rt_error_message));
              rtmSetErrorStatus(QD2_MissionCtrl_ManualPC_202_M,
                                _rt_error_message);
            }
          }
        }

        qthread_attr_destroy(&send_thread_attributes);
        qthread_attr_destroy(&receive_thread_attributes);
        QD2_MissionCtrl_ManualPC_202_DW.StreamServer_Listening = true;
      }

      if (QD2_MissionCtrl_ManualPC_2021_P.Constant_Value_h) {
        send_result = pstream_send
          (QD2_MissionCtrl_ManualPC_202_DW.StreamServer_Stream,
           &rtb_TmpSignalConversionAtStream[0]);
      } else {
        send_result = 0;
      }

      receive_result = pstream_receive
        (QD2_MissionCtrl_ManualPC_202_DW.StreamServer_Stream,
         &QD2_MissionCtrl_ManualPC_2021_B.StreamServer_o4);
      rtb_StreamServer_o2 = 0;
      if (send_result < 0 && send_result != -QERR_WOULD_BLOCK) {
        rtb_StreamServer_o2 = send_result;
      } else if (receive_result < 0 && receive_result != -QERR_WOULD_BLOCK) {
        rtb_StreamServer_o2 = receive_result;
      }

      pstream_get_state(QD2_MissionCtrl_ManualPC_202_DW.StreamServer_Stream,
                        &state);
      rtb_StreamServer_o1 = state;
    }

    /* MATLAB Function: '<S5>/MATLAB Function' */
    QD2_MissionCtrl_ManualPC_202_DW.sfEvent_n = QD2_MissionCtrl_Manu_CALL_EVENT;

    /* MATLAB Function 'Communication/Detect Communication loss/MATLAB Function': '<S6>:1' */
    /* '<S6>:1:3' */
    rtb_XVelocityScaling = 0.0;
    if ((rtb_Time > 1.0) && ((rtb_StreamServer_o1 != 2) || (rtb_StreamServer_o2 <
          0))) {
      /* '<S6>:1:4' */
      /* '<S6>:1:5' */
      /* '<S6>:1:7' */
      rtb_XVelocityScaling = 1.0;
    } else {
      /* '<S6>:1:5' */
    }

    /* End of MATLAB Function: '<S5>/MATLAB Function' */

    /* RelationalOperator: '<S7>/Relation' incorporates:
     *  Constant: '<S7>/threshold'
     */
    rtb_Relation = (rtb_XVelocityScaling >=
                    QD2_MissionCtrl_ManualPC_2021_P.Threshold_threshold_d);

    /* Logic: '<S7>/Logical Operator' */
    QD2_MissionCtrl_ManualPC_2021_B.LogicalOperator_k = !rtb_Relation;

    /* DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
    if (QD2_MissionCtrl_ManualPC_2021_B.LogicalOperator_k ||
        (QD2_MissionCtrl_ManualPC_202_DW.DiscreteTimeIntegrator_PrevRe_b != 0))
    {
      QD2_MissionCtrl_ManualPC_202_DW.DiscreteTimeIntegrator_DSTATE_j =
        QD2_MissionCtrl_ManualPC_2021_P.DiscreteTimeIntegrator_IC_c;
    }

    /* DataTypeConversion: '<S5>/Data Type Conversion' incorporates:
     *  Constant: '<S7>/duration'
     *  DiscreteIntegrator: '<S7>/Discrete-Time Integrator'
     *  RelationalOperator: '<S7>/Relational Operator'
     */
    QD2_MissionCtrl_ManualPC_2021_B.DataTypeConversion_e =
      (QD2_MissionCtrl_ManualPC_202_DW.DiscreteTimeIntegrator_DSTATE_j >=
       QD2_MissionCtrl_ManualPC_2021_P.Threshold_duration_b);

    /* Outputs for Triggered SubSystem: '<S2>/Triggered Subsystem' incorporates:
     *  TriggerPort: '<S13>/Trigger'
     */
    if (rtsiIsModeUpdateTimeStep(&QD2_MissionCtrl_ManualPC_202_M->solverInfo)) {
      zcEvent = rt_ZCFcn(FALLING_ZERO_CROSSING,
                         &QD2_MissionCtrl_ManualP_PrevZCX.TriggeredSubsystem_Trig_ZCE,
                         (QD2_MissionCtrl_ManualPC_2021_B.DataTypeConversion_e));
      if (zcEvent != NO_ZCEVENT) {
        /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
         *  Constant: '<S13>/Constant'
         *  Memory: '<S13>/Memory'
         *  Sum: '<S13>/Add'
         */
        QD2_MissionCtrl_ManualPC_2021_B.DataTypeConversion_o =
          QD2_MissionCtrl_ManualPC_2021_P.Constant_Value_i +
          QD2_MissionCtrl_ManualPC_202_DW.Memory_PreviousInput;

        /* RelationalOperator: '<S43>/Compare' incorporates:
         *  Constant: '<S43>/Constant'
         */
        QD2_MissionCtrl_ManualPC_2021_B.Compare_f =
          (QD2_MissionCtrl_ManualPC_2021_B.DataTypeConversion_o >=
           QD2_MissionCtrl_ManualPC_2021_P.CompareToConstant_const_g);

        /* Update for Memory: '<S13>/Memory' */
        QD2_MissionCtrl_ManualPC_202_DW.Memory_PreviousInput =
          QD2_MissionCtrl_ManualPC_2021_B.DataTypeConversion_o;
        QD2_MissionCtrl_ManualPC_202_DW.TriggeredSubsystem_SubsysRanBC = 4;
      }
    }

    /* End of Outputs for SubSystem: '<S2>/Triggered Subsystem' */

    /* Product: '<S2>/Product' */
    QD2_MissionCtrl_ManualPC_2021_B.Product =
      QD2_MissionCtrl_ManualPC_2021_B.DataTypeConversion_e * (real_T)
      QD2_MissionCtrl_ManualPC_2021_B.Compare_f;

    /* Sum: '<S2>/Subtract' */
    QD2_MissionCtrl_ManualPC_2021_B.Subtract = rtb_Time_m -
      QD2_MissionCtrl_ManualPC_2021_B.StreamServer_o4;

    /* S-Function (time_block): '<S12>/Time' */

    /* S-Function Block: QD2_MissionCtrl_ManualPC_2021a/MISSION CONTROL QDRONE MANUAL POSITION CONTROL/Subsystem/Time (time_block) */
    {
      t_error result;
      t_timeout current_time;
      t_timeout time_difference;
      result = timeout_get_high_resolution_time(&current_time);
      if (result == 0) {
        result = timeout_subtract(&time_difference, &current_time,
          &_high_resolution_start_time);
        rtb_Time_m = time_difference.seconds + time_difference.nanoseconds *
          1e-9;
      }

      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QD2_MissionCtrl_ManualPC_202_M, _rt_error_message);
        return;
      }
    }

    /* RelationalOperator: '<S38>/Compare' incorporates:
     *  Constant: '<S38>/Constant'
     */
    rtb_Compare_p = (rtb_Time_m >=
                     QD2_MissionCtrl_ManualPC_2021_P.CompareToConstant_const_i);

    /* Product: '<S12>/Product' */
    rtb_Gain2_idx_0 = (real_T)rtb_Compare_p *
      QD2_MissionCtrl_ManualPC_2021_B.ManualSwitch1[0];
    rtb_XVelocityScaling = (real_T)rtb_Compare_p *
      QD2_MissionCtrl_ManualPC_2021_B.ManualSwitch1[1];
    rtb_Gain2_idx_2 = (real_T)rtb_Compare_p *
      QD2_MissionCtrl_ManualPC_2021_B.ManualSwitch1[2];
    rtb_Gain2_idx_3 = (real_T)rtb_Compare_p *
      QD2_MissionCtrl_ManualPC_2021_B.ManualSwitch1[3];

    /* MATLAB Function: '<S12>/MATLAB Function' */
    QD2_MissionCtrl_ManualPC_202_DW.sfEvent = QD2_MissionCtrl_Manu_CALL_EVENT;

    /* MATLAB Function 'MISSION CONTROL QDRONE MANUAL POSITION CONTROL/Subsystem/MATLAB Function': '<S40>:1' */
    /* '<S40>:1:13' */
    rtb_Time_m = 0.0;
    switch ((int32_T)QD2_MissionCtrl_ManualPC_202_DW.State) {
     case 0:
      if ((rtb_Gain2_idx_0 == 1.0) && (rtb_Gain2_idx_2 == 0.0) &&
          (rtb_Gain2_idx_3 == 0.0)) {
        /* '<S40>:1:20' */
        /* '<S40>:1:21' */
        QD2_MissionCtrl_ManualPC_202_DW.State = 1.0;
      } else if ((rtb_Gain2_idx_3 == 1.0) || (rtb_Gain2_idx_2 == 1.0) ||
                 (rtb_XVelocityScaling == 1.0) ||
                 (QD2_MissionCtrl_ManualPC_2021_B.Product == 1.0)) {
        /* '<S40>:1:22' */
        /* '<S40>:1:23' */
        QD2_MissionCtrl_ManualPC_202_DW.State = 9.0;
      }
      break;

     case 1:
      if ((rtb_Gain2_idx_2 == 0.0) && (rtb_Gain2_idx_3 == 0.0)) {
        /* '<S40>:1:27' */
        if (rtb_Gain2_idx_0 == 0.0) {
          /* '<S40>:1:28' */
          /* '<S40>:1:29' */
          QD2_MissionCtrl_ManualPC_202_DW.State = 0.0;
        } else if ((rtb_Gain2_idx_0 == 1.0) && (rtb_XVelocityScaling == 1.0)) {
          /* '<S40>:1:30' */
          /* '<S40>:1:31' */
          QD2_MissionCtrl_ManualPC_202_DW.State = 2.0;
        }
      } else if ((rtb_Gain2_idx_3 == 1.0) ||
                 (QD2_MissionCtrl_ManualPC_2021_B.Product == 1.0) ||
                 (rtb_Gain2_idx_2 == 1.0)) {
        /* '<S40>:1:33' */
        /* '<S40>:1:34' */
        QD2_MissionCtrl_ManualPC_202_DW.State = 9.0;
      }
      break;

     case 2:
      if ((rtb_Gain2_idx_2 == 0.0) && (rtb_Gain2_idx_3 == 0.0)) {
        /* '<S40>:1:38' */
        if (rtb_XVelocityScaling == 0.0) {
          /* '<S40>:1:39' */
          /* '<S40>:1:40' */
          QD2_MissionCtrl_ManualPC_202_DW.State = 3.0;
        } else if ((rtb_Gain2_idx_0 == 0.0) ||
                   (QD2_MissionCtrl_ManualPC_2021_B.Product == 1.0)) {
          /* '<S40>:1:41' */
          /* '<S40>:1:42' */
          QD2_MissionCtrl_ManualPC_202_DW.State = 9.0;
        }
      }
      break;

     case 3:
      if ((rtb_Gain2_idx_3 == 1.0) || (rtb_Gain2_idx_0 == 0.0) ||
          (QD2_MissionCtrl_ManualPC_2021_B.Product == 1.0)) {
        /* '<S40>:1:47' */
        /* '<S40>:1:48' */
        QD2_MissionCtrl_ManualPC_202_DW.State = 9.0;
      }
      break;

     case 9:
      /* '<S40>:1:52' */
      rtb_Time_m = 1.0;
      break;
    }

    /* '<S40>:1:56' */
    QD2_MissionCtrl_ManualPC_2021_B.Flight_State =
      QD2_MissionCtrl_ManualPC_202_DW.State;

    /* End of MATLAB Function: '<S12>/MATLAB Function' */

    /* SignalConversion generated from: '<S2>/To Host File' */
    QD2_MissionCtrl_ManualPC_2021_B.TmpSignalConversionAtToHostFile[0] =
      QD2_MissionCtrl_ManualPC_2021_B.DesiredPosemrad[0];
    QD2_MissionCtrl_ManualPC_2021_B.TmpSignalConversionAtToHostFile[1] =
      QD2_MissionCtrl_ManualPC_2021_B.DesiredPosemrad[1];
    QD2_MissionCtrl_ManualPC_2021_B.TmpSignalConversionAtToHostFile[2] =
      QD2_MissionCtrl_ManualPC_2021_B.DesiredPosemrad[2];
    QD2_MissionCtrl_ManualPC_2021_B.TmpSignalConversionAtToHostFile[3] =
      QD2_MissionCtrl_ManualPC_2021_B.DesiredPosemrad[3];
    QD2_MissionCtrl_ManualPC_2021_B.TmpSignalConversionAtToHostFile[4] =
      QD2_MissionCtrl_ManualPC_2021_B.Saturation[0];
    QD2_MissionCtrl_ManualPC_2021_B.TmpSignalConversionAtToHostFile[5] =
      QD2_MissionCtrl_ManualPC_2021_B.Saturation[1];
    QD2_MissionCtrl_ManualPC_2021_B.TmpSignalConversionAtToHostFile[6] =
      QD2_MissionCtrl_ManualPC_2021_B.Saturation[2];
    QD2_MissionCtrl_ManualPC_2021_B.TmpSignalConversionAtToHostFile[7] =
      QD2_MissionCtrl_ManualPC_2021_B.DataTypeConversion1[0];
    QD2_MissionCtrl_ManualPC_2021_B.TmpSignalConversionAtToHostFile[8] =
      QD2_MissionCtrl_ManualPC_2021_B.DataTypeConversion1[1];
    QD2_MissionCtrl_ManualPC_2021_B.TmpSignalConversionAtToHostFile[9] =
      QD2_MissionCtrl_ManualPC_2021_B.Unwrapoptitrackmeasurement;
    QD2_MissionCtrl_ManualPC_2021_B.TmpSignalConversionAtToHostFile[10] =
      QD2_MissionCtrl_ManualPC_2021_B.DataTypeConversion2;
    QD2_MissionCtrl_ManualPC_2021_B.TmpSignalConversionAtToHostFile[11] =
      QD2_MissionCtrl_ManualPC_2021_B.Subtract;
    QD2_MissionCtrl_ManualPC_2021_B.TmpSignalConversionAtToHostFile[12] =
      QD2_MissionCtrl_ManualPC_2021_B.Product;
    QD2_MissionCtrl_ManualPC_2021_B.TmpSignalConversionAtToHostFile[13] =
      QD2_MissionCtrl_ManualPC_2021_B.ManualSwitch1[0];
    QD2_MissionCtrl_ManualPC_2021_B.TmpSignalConversionAtToHostFile[14] =
      QD2_MissionCtrl_ManualPC_2021_B.ManualSwitch1[1];
    QD2_MissionCtrl_ManualPC_2021_B.TmpSignalConversionAtToHostFile[15] =
      QD2_MissionCtrl_ManualPC_2021_B.ManualSwitch1[2];
    QD2_MissionCtrl_ManualPC_2021_B.TmpSignalConversionAtToHostFile[16] =
      QD2_MissionCtrl_ManualPC_2021_B.ManualSwitch1[3];
    QD2_MissionCtrl_ManualPC_2021_B.TmpSignalConversionAtToHostFile[17] =
      QD2_MissionCtrl_ManualPC_2021_B.Flight_State;
    QD2_MissionCtrl_ManualPC_2021_B.TmpSignalConversionAtToHostFile[18] =
      QD2_MissionCtrl_ManualPC_2021_B.Product1;
    QD2_MissionCtrl_ManualPC_2021_B.TmpSignalConversionAtToHostFile[19] =
      QD2_MissionCtrl_ManualPC_2021_B.Product_n[0];
    QD2_MissionCtrl_ManualPC_2021_B.TmpSignalConversionAtToHostFile[20] =
      QD2_MissionCtrl_ManualPC_2021_B.Product_n[1];
    QD2_MissionCtrl_ManualPC_2021_B.TmpSignalConversionAtToHostFile[21] =
      QD2_MissionCtrl_ManualPC_2021_B.Product_n[2];

    /* RateTransition: '<S10>/Rate Transition6' incorporates:
     *  RateTransition: '<S10>/Rate Transition7'
     */
    if (QD2_MissionCtrl_ManualPC_202_M->Timing.RateInteraction.TID1_2) {
      /* RateTransition: '<S10>/Rate Transition6' */
      memcpy(&QD2_MissionCtrl_ManualPC_2021_B.RateTransition6[0],
             &QD2_MissionCtrl_ManualPC_202_DW.RateTransition6_Buffer0[0], 9U *
             sizeof(real_T));

      /* RateTransition: '<S10>/Rate Transition7' */
      memcpy(&QD2_MissionCtrl_ManualPC_2021_B.RateTransition7[0],
             &QD2_MissionCtrl_ManualPC_202_DW.RateTransition7_Buffer0[0], 9U *
             sizeof(real_T));
    }

    /* End of RateTransition: '<S10>/Rate Transition6' */

    /* Selector: '<S10>/Selector' incorporates:
     *  RateTransition: '<S10>/Rate Transition7'
     */
    memcpy(&QD2_MissionCtrl_ManualPC_2021_B.Selector[0],
           &QD2_MissionCtrl_ManualPC_2021_B.RateTransition7[0], 9U * sizeof
           (real_T));

    /* RateTransition: '<S10>/Rate Transition8' */
    if (QD2_MissionCtrl_ManualPC_202_M->Timing.RateInteraction.TID1_2) {
      /* RateTransition: '<S10>/Rate Transition8' */
      memcpy(&QD2_MissionCtrl_ManualPC_2021_B.RateTransition8[0],
             &QD2_MissionCtrl_ManualPC_202_DW.RateTransition8_Buffer0[0], 9U *
             sizeof(real_T));
    }

    /* End of RateTransition: '<S10>/Rate Transition8' */

    /* Selector: '<S10>/Selector1' incorporates:
     *  RateTransition: '<S10>/Rate Transition8'
     */
    memcpy(&QD2_MissionCtrl_ManualPC_2021_B.Selector1[0],
           &QD2_MissionCtrl_ManualPC_2021_B.RateTransition8[0], 9U * sizeof
           (real_T));

    /* Delay: '<S12>/Delay' */
    QD2_MissionCtrl_ManualPC_2021_B.Delay =
      QD2_MissionCtrl_ManualPC_202_DW.Delay_DSTATE[0];

    /* Stop: '<S41>/Stop Simulation' incorporates:
     *  Constant: '<S42>/Constant'
     *  RelationalOperator: '<S42>/Compare'
     */
    if (QD2_MissionCtrl_ManualPC_2021_B.Delay !=
        QD2_MissionCtrl_ManualPC_2021_P.Constant_Value_o) {
      rtmSetStopRequested(QD2_MissionCtrl_ManualPC_202_M, true);
    }

    /* End of Stop: '<S41>/Stop Simulation' */

    /* RelationalOperator: '<S39>/Compare' incorporates:
     *  Constant: '<S39>/Constant'
     */
    QD2_MissionCtrl_ManualPC_2021_B.Compare =
      (QD2_MissionCtrl_ManualPC_2021_B.Flight_State ==
       QD2_MissionCtrl_ManualPC_2021_P.CompareToConstant1_const);

    /* Logic: '<S12>/OR' incorporates:
     *  Delay: '<S12>/Delay1'
     */
    QD2_MissionCtrl_ManualPC_2021_B.OR =
      (QD2_MissionCtrl_ManualPC_202_DW.Delay1_DSTATE[0] || (rtb_Time_m != 0.0));
  }

  /* Abs: '<S14>/Abs' */
  QD2_MissionCtrl_ManualPC_2021_B.Abs[0] = fabs
    (QD2_MissionCtrl_ManualPC_2021_B.Switch2[0]);
  QD2_MissionCtrl_ManualPC_2021_B.Abs[1] = fabs
    (QD2_MissionCtrl_ManualPC_2021_B.Switch2[1]);
  if (tmp) {
    /* S-Function (compare_block): '<S14>/Compare' incorporates:
     *  Constant: '<S2>/Cube Length (m)'
     */
    {
      QD2_MissionCtrl_ManualPC_2021_B.Compare_d[0] =
        (QD2_MissionCtrl_ManualPC_2021_P.CubeLengthm_Value >
         QD2_MissionCtrl_ManualPC_2021_B.Abs[0]);
      QD2_MissionCtrl_ManualPC_2021_B.Compare_d[1] =
        (QD2_MissionCtrl_ManualPC_2021_P.CubeLengthm_Value >
         QD2_MissionCtrl_ManualPC_2021_B.Abs[1]);
    }

    /* Memory: '<S14>/Memory' */
    QD2_MissionCtrl_ManualPC_2021_B.Memory[0] =
      QD2_MissionCtrl_ManualPC_202_DW.Memory_PreviousInput_h[0];
    QD2_MissionCtrl_ManualPC_2021_B.Memory[1] =
      QD2_MissionCtrl_ManualPC_202_DW.Memory_PreviousInput_h[1];

    /* Outputs for Iterator SubSystem: '<S14>/For Each Subsystem' incorporates:
     *  ForEach: '<S44>/For Each'
     */
    for (ForEach_itr = 0; ForEach_itr < 2; ForEach_itr++) {
      /* ForEachSliceSelector generated from: '<S44>/Trigger' */
      rtb_ImpSel_InsertedFor_Trigger_ =
        QD2_MissionCtrl_ManualPC_2021_B.Memory[ForEach_itr];

      /* ForEachSliceSelector generated from: '<S44>/width' incorporates:
       *  Constant: '<S14>/Constant3'
       */
      rtb_ImpSel_InsertedFor_width_at =
        QD2_MissionCtrl_ManualPC_2021_P.Constant3_Value[ForEach_itr];

      /* S-Function (one_shot_block): '<S47>/one_shot_block' */
      if (QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys_p.one_shot_block_trigger_type
          == 1.0 && rtb_ImpSel_InsertedFor_Trigger_ -
          QD2_MissionCtrl_ManualPC_202_DW.CoreSubsys_p[ForEach_itr].
          one_shot_block_DSTATE[2] > 0 ) {
        if (QD2_MissionCtrl_ManualPC_202_DW.CoreSubsys_p[ForEach_itr].
            one_shot_block_DSTATE[0] == 1.0 &&
            QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys_p.one_shot_block_redun_pulse
            == 1.0 ) {
        } else if (QD2_MissionCtrl_ManualPC_202_DW.CoreSubsys_p[ForEach_itr].
                   one_shot_block_DSTATE[0] == 1.0 &&
                   QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys_p.one_shot_block_redun_pulse
                   == 2.0 ) {
          QD2_MissionCtrl_ManualPC_202_DW.CoreSubsys_p[ForEach_itr].
            one_shot_block_DSTATE[1] = 0.0;
        } else {
          QD2_MissionCtrl_ManualPC_202_DW.CoreSubsys_p[ForEach_itr].
            one_shot_block_DSTATE[0] = 1.0;
        }
      } else if
          (QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys_p.one_shot_block_trigger_type
           == 2.0 && rtb_ImpSel_InsertedFor_Trigger_ -
           QD2_MissionCtrl_ManualPC_202_DW.CoreSubsys_p[ForEach_itr].
           one_shot_block_DSTATE[2] < 0 ) {
        if (QD2_MissionCtrl_ManualPC_202_DW.CoreSubsys_p[ForEach_itr].
            one_shot_block_DSTATE[0] == 1.0 &&
            QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys_p.one_shot_block_redun_pulse
            == 1.0 ) {
        } else if (QD2_MissionCtrl_ManualPC_202_DW.CoreSubsys_p[ForEach_itr].
                   one_shot_block_DSTATE[0] == 1.0 &&
                   QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys_p.one_shot_block_redun_pulse
                   == 2.0 ) {
          QD2_MissionCtrl_ManualPC_202_DW.CoreSubsys_p[ForEach_itr].
            one_shot_block_DSTATE[1] = 0.0;
        } else {
          QD2_MissionCtrl_ManualPC_202_DW.CoreSubsys_p[ForEach_itr].
            one_shot_block_DSTATE[0] = 1.0;
        }
      } else if
          ((QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys_p.one_shot_block_trigger_type
            == 3.0 && rtb_ImpSel_InsertedFor_Trigger_ -
            QD2_MissionCtrl_ManualPC_202_DW.CoreSubsys_p[ForEach_itr].
            one_shot_block_DSTATE[2] < 0 ) ||
           (QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys_p.one_shot_block_trigger_type
            == 3.0 && rtb_ImpSel_InsertedFor_Trigger_ -
            QD2_MissionCtrl_ManualPC_202_DW.CoreSubsys_p[ForEach_itr].
            one_shot_block_DSTATE[2] > 0 ) ) {
        if (QD2_MissionCtrl_ManualPC_202_DW.CoreSubsys_p[ForEach_itr].
            one_shot_block_DSTATE[0] == 1.0 &&
            QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys_p.one_shot_block_redun_pulse
            == 1.0 ) {
        } else if (QD2_MissionCtrl_ManualPC_202_DW.CoreSubsys_p[ForEach_itr].
                   one_shot_block_DSTATE[0] == 1.0 &&
                   QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys_p.one_shot_block_redun_pulse
                   == 2.0 ) {
          QD2_MissionCtrl_ManualPC_202_DW.CoreSubsys_p[ForEach_itr].
            one_shot_block_DSTATE[1] = 0.0;
        } else {
          QD2_MissionCtrl_ManualPC_202_DW.CoreSubsys_p[ForEach_itr].
            one_shot_block_DSTATE[0] = 1.0;
        }
      }

      QD2_MissionCtrl_ManualPC_202_DW.CoreSubsys_p[ForEach_itr].
        one_shot_block_DSTATE[2] = rtb_ImpSel_InsertedFor_Trigger_ ;
      if (QD2_MissionCtrl_ManualPC_202_DW.CoreSubsys_p[ForEach_itr].
          one_shot_block_DSTATE[0] == 1.0 &&
          QD2_MissionCtrl_ManualPC_202_DW.CoreSubsys_p[ForEach_itr].
          one_shot_block_DSTATE[1] < rtb_ImpSel_InsertedFor_width_at ) {
        QD2_MissionCtrl_ManualPC_202_DW.CoreSubsys_p[ForEach_itr].
          one_shot_block_DSTATE[1] += 1.0;
        QD2_MissionCtrl_ManualPC_2021_B.CoreSubsys_p[ForEach_itr].one_shot_block
          = 1.0;
      } else if (QD2_MissionCtrl_ManualPC_202_DW.CoreSubsys_p[ForEach_itr].
                 one_shot_block_DSTATE[0] == 1.0 &&
                 QD2_MissionCtrl_ManualPC_202_DW.CoreSubsys_p[ForEach_itr].
                 one_shot_block_DSTATE[1] >= rtb_ImpSel_InsertedFor_width_at ) {
        QD2_MissionCtrl_ManualPC_202_DW.CoreSubsys_p[ForEach_itr].
          one_shot_block_DSTATE[0] = 0.0;
        QD2_MissionCtrl_ManualPC_202_DW.CoreSubsys_p[ForEach_itr].
          one_shot_block_DSTATE[1] = 0.0;
        QD2_MissionCtrl_ManualPC_2021_B.CoreSubsys_p[ForEach_itr].one_shot_block
          = 0.0;
      } else if (QD2_MissionCtrl_ManualPC_202_DW.CoreSubsys_p[ForEach_itr].
                 one_shot_block_DSTATE[0] == 0.0 ) {
        QD2_MissionCtrl_ManualPC_202_DW.CoreSubsys_p[ForEach_itr].
          one_shot_block_DSTATE[1] = 0.0;
        QD2_MissionCtrl_ManualPC_2021_B.CoreSubsys_p[ForEach_itr].one_shot_block
          = 0.0;
      }

      /* Switch: '<S47>/Switch' */
      if (QD2_MissionCtrl_ManualPC_2021_B.CoreSubsys_p[ForEach_itr].
          one_shot_block >=
          QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys_p.Switch_Threshold) {
        /* ForEachSliceAssignment generated from: '<S44>/Output Signal' incorporates:
         *  Constant: '<S14>/Constant2'
         *  ForEachSliceSelector generated from: '<S44>/Triggered Output'
         */
        QD2_MissionCtrl_ManualPC_2021_B.ImpAsg_InsertedFor_OutputSignal[ForEach_itr]
          = QD2_MissionCtrl_ManualPC_2021_P.Constant2_Value[ForEach_itr];
      } else {
        /* ForEachSliceAssignment generated from: '<S44>/Output Signal' incorporates:
         *  Constant: '<S14>/Constant1'
         *  ForEachSliceSelector generated from: '<S44>/Untriggered Output'
         */
        QD2_MissionCtrl_ManualPC_2021_B.ImpAsg_InsertedFor_OutputSignal[ForEach_itr]
          = QD2_MissionCtrl_ManualPC_2021_P.Constant1_Value_a[ForEach_itr];
      }

      /* End of Switch: '<S47>/Switch' */
    }

    /* End of Outputs for SubSystem: '<S14>/For Each Subsystem' */
  }

  /* Switch: '<S14>/Switch' */
  if (QD2_MissionCtrl_ManualPC_2021_B.ImpAsg_InsertedFor_OutputSignal[0] >
      QD2_MissionCtrl_ManualPC_2021_P.Switch_Threshold_k) {
    /* Signum: '<S14>/Sign1' */
    if (rtIsNaN(QD2_MissionCtrl_ManualPC_2021_B.Switch2[0])) {
      rtb_Gain2_idx_0 = (rtNaN);
    } else if (QD2_MissionCtrl_ManualPC_2021_B.Switch2[0] < 0.0) {
      rtb_Gain2_idx_0 = -1.0;
    } else {
      rtb_Gain2_idx_0 = (QD2_MissionCtrl_ManualPC_2021_B.Switch2[0] > 0.0);
    }

    /* Switch: '<S14>/Switch' incorporates:
     *  Gain: '<S14>/Gain3'
     *  Signum: '<S14>/Sign1'
     */
    QD2_MissionCtrl_ManualPC_2021_B.Switch_g[0] =
      QD2_MissionCtrl_ManualPC_2021_P.Gain3_Gain * rtb_Gain2_idx_0;
  } else {
    /* Switch: '<S14>/Switch' */
    QD2_MissionCtrl_ManualPC_2021_B.Switch_g[0] =
      QD2_MissionCtrl_ManualPC_2021_B.MatrixMultiply[0];
  }

  if (QD2_MissionCtrl_ManualPC_2021_B.ImpAsg_InsertedFor_OutputSignal[1] >
      QD2_MissionCtrl_ManualPC_2021_P.Switch_Threshold_k) {
    /* Signum: '<S14>/Sign1' */
    if (rtIsNaN(QD2_MissionCtrl_ManualPC_2021_B.Switch2[1])) {
      rtb_Gain2_idx_0 = (rtNaN);
    } else if (QD2_MissionCtrl_ManualPC_2021_B.Switch2[1] < 0.0) {
      rtb_Gain2_idx_0 = -1.0;
    } else {
      rtb_Gain2_idx_0 = (QD2_MissionCtrl_ManualPC_2021_B.Switch2[1] > 0.0);
    }

    /* Switch: '<S14>/Switch' incorporates:
     *  Gain: '<S14>/Gain3'
     *  Signum: '<S14>/Sign1'
     */
    QD2_MissionCtrl_ManualPC_2021_B.Switch_g[1] =
      QD2_MissionCtrl_ManualPC_2021_P.Gain3_Gain * rtb_Gain2_idx_0;
  } else {
    /* Switch: '<S14>/Switch' */
    QD2_MissionCtrl_ManualPC_2021_B.Switch_g[1] =
      QD2_MissionCtrl_ManualPC_2021_B.MatrixMultiply[1];
  }

  /* End of Switch: '<S14>/Switch' */
  if (tmp) {
    /* Gain: '<S14>/Yaw Velocity Scaling' */
    QD2_MissionCtrl_ManualPC_2021_B.YawVelocityScaling =
      QD2_MissionCtrl_ManualPC_2021_P.YawVelocityScaling_Gain *
      QD2_MissionCtrl_ManualPC_2021_B.ManualSwitch1[8];

    /* DataTypeConversion: '<S7>/Data Type Conversion' */
    QD2_MissionCtrl_ManualPC_2021_B.DataTypeConversion_o = rtb_Relation;
  }
}

/* Model update function for TID0 */
void QD2_MissionCtrl_ManualPC_2021a_update0(void) /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_ImpSel_InsertedFor_width_at;
  boolean_T rtb_ImpSel_InsertedFor_Trigger_;

  /* local scratch DWork variables */
  int32_T ForEach_itr;
  int32_T idxDelay;
  if (rtmIsMajorTimeStep(QD2_MissionCtrl_ManualPC_202_M)) {
    /* Update for DiscreteIntegrator: '<S21>/Discrete-Time Integrator' */
    QD2_MissionCtrl_ManualPC_202_DW.DiscreteTimeIntegrator_DSTATE +=
      QD2_MissionCtrl_ManualPC_2021_P.DiscreteTimeIntegrator_gainva_j *
      QD2_MissionCtrl_ManualPC_2021_B.DataTypeConversion;
    QD2_MissionCtrl_ManualPC_202_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
      QD2_MissionCtrl_ManualPC_2021_B.LogicalOperator;

    /* Update for Enabled SubSystem: '<S9>/FrSKYMapping' incorporates:
     *  EnablePort: '<S18>/Valid Signals Detected'
     */
    if (QD2_MissionCtrl_ManualPC_202_DW.FrSKYMapping_MODE) {
      /* Update for DiscreteIntegrator: '<S23>/Discrete-Time Integrator' */
      QD2_MissionCtrl_ManualPC_202_DW.DiscreteTimeIntegrator_DSTATE_h +=
        QD2_MissionCtrl_ManualPC_2021_P.DiscreteTimeIntegrator_gainval *
        QD2_MissionCtrl_ManualPC_2021_B.DataTypeConversion_g;
      QD2_MissionCtrl_ManualPC_202_DW.DiscreteTimeIntegrator_PrevRe_i = (int8_T)
        QD2_MissionCtrl_ManualPC_2021_B.LogicalOperator_n;
    }

    /* End of Update for SubSystem: '<S9>/FrSKYMapping' */

    /* Update for Memory: '<S14>/Memory1' */
    QD2_MissionCtrl_ManualPC_202_DW.Memory1_PreviousInput =
      QD2_MissionCtrl_ManualPC_2021_B.Integrator2;

    /* Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
    QD2_MissionCtrl_ManualPC_202_DW.DiscreteTimeIntegrator_DSTATE_j +=
      QD2_MissionCtrl_ManualPC_2021_P.DiscreteTimeIntegrator_gainva_n *
      QD2_MissionCtrl_ManualPC_2021_B.DataTypeConversion_o;
    QD2_MissionCtrl_ManualPC_202_DW.DiscreteTimeIntegrator_PrevRe_b = (int8_T)
      QD2_MissionCtrl_ManualPC_2021_B.LogicalOperator_k;

    /* Update for Delay: '<S12>/Delay' */
    for (idxDelay = 0; idxDelay < 5999; idxDelay++) {
      QD2_MissionCtrl_ManualPC_202_DW.Delay_DSTATE[idxDelay] =
        QD2_MissionCtrl_ManualPC_202_DW.Delay_DSTATE[idxDelay + 1];
    }

    QD2_MissionCtrl_ManualPC_202_DW.Delay_DSTATE[5999] =
      QD2_MissionCtrl_ManualPC_2021_B.OR;

    /* End of Update for Delay: '<S12>/Delay' */

    /* Update for Delay: '<S12>/Delay1' */
    for (idxDelay = 0; idxDelay < 1999; idxDelay++) {
      QD2_MissionCtrl_ManualPC_202_DW.Delay1_DSTATE[idxDelay] =
        QD2_MissionCtrl_ManualPC_202_DW.Delay1_DSTATE[idxDelay + 1];
    }

    QD2_MissionCtrl_ManualPC_202_DW.Delay1_DSTATE[1999] =
      QD2_MissionCtrl_ManualPC_2021_B.Compare;

    /* End of Update for Delay: '<S12>/Delay1' */

    /* Update for Memory: '<S14>/Memory' */
    QD2_MissionCtrl_ManualPC_202_DW.Memory_PreviousInput_h[0] =
      QD2_MissionCtrl_ManualPC_2021_B.Compare_d[0];
    QD2_MissionCtrl_ManualPC_202_DW.Memory_PreviousInput_h[1] =
      QD2_MissionCtrl_ManualPC_2021_B.Compare_d[1];

    /* Update for Iterator SubSystem: '<S14>/For Each Subsystem' */
    for (ForEach_itr = 0; ForEach_itr < 2; ForEach_itr++) {
      /* Update for ForEachSliceSelector generated from: '<S44>/Trigger' */
      rtb_ImpSel_InsertedFor_Trigger_ =
        QD2_MissionCtrl_ManualPC_2021_B.Memory[ForEach_itr];

      /* Update for ForEachSliceSelector generated from: '<S44>/width' incorporates:
       *  Constant: '<S14>/Constant3'
       */
      rtb_ImpSel_InsertedFor_width_at =
        QD2_MissionCtrl_ManualPC_2021_P.Constant3_Value[ForEach_itr];
    }

    /* End of Update for SubSystem: '<S14>/For Each Subsystem' */
  }

  if (rtmIsMajorTimeStep(QD2_MissionCtrl_ManualPC_202_M)) {
    rt_ertODEUpdateContinuousStates(&QD2_MissionCtrl_ManualPC_202_M->solverInfo);
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
  if (!(++QD2_MissionCtrl_ManualPC_202_M->Timing.clockTick0)) {
    ++QD2_MissionCtrl_ManualPC_202_M->Timing.clockTickH0;
  }

  QD2_MissionCtrl_ManualPC_202_M->Timing.t[0] = rtsiGetSolverStopTime
    (&QD2_MissionCtrl_ManualPC_202_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++QD2_MissionCtrl_ManualPC_202_M->Timing.clockTick1)) {
    ++QD2_MissionCtrl_ManualPC_202_M->Timing.clockTickH1;
  }

  QD2_MissionCtrl_ManualPC_202_M->Timing.t[1] =
    QD2_MissionCtrl_ManualPC_202_M->Timing.clockTick1 *
    QD2_MissionCtrl_ManualPC_202_M->Timing.stepSize1 +
    QD2_MissionCtrl_ManualPC_202_M->Timing.clockTickH1 *
    QD2_MissionCtrl_ManualPC_202_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void QD2_MissionCtrl_ManualPC_2021a_derivatives(void)
{
  XDot_QD2_MissionCtrl_ManualPC_T *_rtXdot;
  _rtXdot = ((XDot_QD2_MissionCtrl_ManualPC_T *)
             QD2_MissionCtrl_ManualPC_202_M->derivs);

  /* Derivatives for Integrator: '<S14>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = QD2_MissionCtrl_ManualPC_2021_B.Switch_g[0];
  _rtXdot->Integrator_CSTATE[1] = QD2_MissionCtrl_ManualPC_2021_B.Switch_g[1];

  /* Derivatives for Integrator: '<S14>/Integrator2' */
  _rtXdot->Integrator2_CSTATE =
    QD2_MissionCtrl_ManualPC_2021_B.YawVelocityScaling;
}

/* Model output function for TID2 */
void QD2_MissionCtrl_ManualPC_2021a_output2(void) /* Sample time: [0.016s, 0.0s] */
{
  /* local scratch DWork variables */
  int32_T ForEach_itr_p;
  real_T rtb_ImpAsg_InsertedFor_R_RSF3nx[9];
  real_T rtb_ImpAsg_InsertedFor_R_Tool3n[9];
  real_T rtb_ImpAsg_InsertedFor_R_VRPN3n[9];
  real_T rtb_MatrixMultiply2[9];
  real_T rtb_MatrixMultiply3[9];
  real_T rtb_R_Tool_Transpose[9];
  real_T rtb_VF_R_RSF[9];
  real_T rtb_ImpAsg_InsertedFor_data_RSF[7];
  real_T rtb_ImpAsg_InsertedFor_rot_RSFr[3];
  const real_T *rtb_R_Tool_0;
  const real_T *rtb_R_VRPN_0;
  real_T rtb_EulerAnglesfromRotationMa_h;
  real_T rtb_EulerAnglesfromRotationMatr;
  real_T rtb_MathFunction1;
  real_T rtb_MathFunction2;
  real_T rtb_MathFunction3;
  real_T rtb_q0q1;
  real_T rtb_q2q3;
  real_T rtb_r33;
  int32_T i;
  int32_T i_0;
  int32_T rtb_MatrixMultiply2_tmp;
  int32_T rtb_MatrixMultiply2_tmp_0;
  int32_T rtb_MatrixMultiply3_tmp;

  /* S-Function (vrpn_client_block): '<S10>/VRPN Client' */

  /* S-Function Block: QD2_MissionCtrl_ManualPC_2021a/MISSION CONTROL QDRONE MANUAL POSITION CONTROL/Localization Data Server (VRPN) /VRPN Client (vrpn_client_block) */
  {
    t_error result = 0;
    result = result = vrpn_client_read
      (QD2_MissionCtrl_ManualPC_202_DW.VRPNClient_VRPNClient,
       NULL, 0,
       NULL, 0,
       NULL, 0,
       &QD2_MissionCtrl_ManualPC_202_DW.VRPNClient_TrackerData, 1,
       QD2_MissionCtrl_ManualPC_2021_P.VRPNClient_trackers_jpl);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(QD2_MissionCtrl_ManualPC_202_M, _rt_error_message);
    }

    QD2_MissionCtrl_ManualPC_2021_B.VRPNClient_o1[0] =
      QD2_MissionCtrl_ManualPC_202_DW.VRPNClient_TrackerData.pos[0];
    QD2_MissionCtrl_ManualPC_2021_B.VRPNClient_o1[1] =
      QD2_MissionCtrl_ManualPC_202_DW.VRPNClient_TrackerData.pos[1];
    QD2_MissionCtrl_ManualPC_2021_B.VRPNClient_o1[2] =
      QD2_MissionCtrl_ManualPC_202_DW.VRPNClient_TrackerData.pos[2];
    QD2_MissionCtrl_ManualPC_2021_B.VRPNClient_o2[0] =
      QD2_MissionCtrl_ManualPC_202_DW.VRPNClient_TrackerData.quat[0];
    QD2_MissionCtrl_ManualPC_2021_B.VRPNClient_o2[1] =
      QD2_MissionCtrl_ManualPC_202_DW.VRPNClient_TrackerData.quat[1];
    QD2_MissionCtrl_ManualPC_2021_B.VRPNClient_o2[2] =
      QD2_MissionCtrl_ManualPC_202_DW.VRPNClient_TrackerData.quat[2];
    QD2_MissionCtrl_ManualPC_2021_B.VRPNClient_o2[3] =
      QD2_MissionCtrl_ManualPC_202_DW.VRPNClient_TrackerData.quat[3];
    QD2_MissionCtrl_ManualPC_2021_B.VRPNClient_o9 =
      QD2_MissionCtrl_ManualPC_202_DW.VRPNClient_TrackerData.new_data;
  }

  /* Outputs for Iterator SubSystem: '<S10>/For Each Subsystem (Convention Correction:  Motive Frame to Research Studio Frame)1' incorporates:
   *  ForEach: '<S26>/For Each'
   */
  for (ForEach_itr_p = 0; ForEach_itr_p < 1; ForEach_itr_p++) {
    /* MultiPortSwitch: '<S26>/Multiport Switch' incorporates:
     *  Constant: '<S26>/Generic Rotate Matrix R_Tool (column vectors are basis vectors) of TNF w.r.t. RSF'
     *  Constant: '<S26>/OptiTrack Rotate Matrix R_Tool (column vectors are basis vectors) of TNF w.r.t. RSF'
     *  Constant: '<S26>/Phase Space Rotate Matrix R_Tool (column vectors are basis vectors) of TNF w.r.t. RSF'
     *  Constant: '<S2>/Constant'
     */
    switch ((int32_T)QD2_MissionCtrl_ManualPC_2021_P.Constant_Value_a) {
     case 0:
      rtb_R_Tool_0 =
        &QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.GenericRotateMatrixR_Toolcolumn
        [0];

      /* MultiPortSwitch: '<S26>/Multiport Switch1' incorporates:
       *  Constant: '<S26>/ Generic Rotate Matrix R_VPRN (column vectors are basis vectors) of VF w.r.t. TNF1'
       *  Constant: '<S26>/Generic Rotate Matrix R_Tool (column vectors are basis vectors) of TNF w.r.t. RSF'
       *  MultiPortSwitch: '<S26>/Multiport Switch'
       */
      rtb_R_VRPN_0 =
        &QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.GenericRotateMatrixR_VPRNcolumn
        [0];
      break;

     case 1:
      rtb_R_Tool_0 =
        &QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.OptiTrackRotateMatrixR_Toolcolu
        [0];

      /* MultiPortSwitch: '<S26>/Multiport Switch1' incorporates:
       *  Constant: '<S26>/ Generic Rotate Matrix R_VPRN (column vectors are basis vectors) of VF w.r.t. TNF1'
       *  Constant: '<S26>/OptiTrack Rotate Matrix R_Tool (column vectors are basis vectors) of TNF w.r.t. RSF'
       *  MultiPortSwitch: '<S26>/Multiport Switch'
       */
      rtb_R_VRPN_0 =
        &QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.GenericRotateMatrixR_VPRNcolumn
        [0];
      break;

     case 2:
      rtb_R_Tool_0 =
        &QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.GenericRotateMatrixR_Toolcolumn
        [0];

      /* MultiPortSwitch: '<S26>/Multiport Switch1' incorporates:
       *  Constant: '<S26>/ Generic Rotate Matrix R_VPRN (column vectors are basis vectors) of VF w.r.t. TNF1'
       *  Constant: '<S26>/Generic Rotate Matrix R_Tool (column vectors are basis vectors) of TNF w.r.t. RSF'
       *  MultiPortSwitch: '<S26>/Multiport Switch'
       */
      rtb_R_VRPN_0 =
        &QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.GenericRotateMatrixR_VPRNcolumn
        [0];
      break;

     case 3:
      rtb_R_Tool_0 =
        &QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.GenericRotateMatrixR_Toolcolumn
        [0];

      /* MultiPortSwitch: '<S26>/Multiport Switch1' incorporates:
       *  Constant: '<S26>/ Qualisys Rotate Matrix R_VPRN (column vectors are basis vectors) of VF w.r.t. TNF'
       *  Constant: '<S26>/Generic Rotate Matrix R_Tool (column vectors are basis vectors) of TNF w.r.t. RSF'
       *  MultiPortSwitch: '<S26>/Multiport Switch'
       */
      rtb_R_VRPN_0 =
        &QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.QualisysRotateMatrixR_VPRNcolum
        [0];
      break;

     case 4:
      rtb_R_Tool_0 =
        &QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.PhaseSpaceRotateMatrixR_Toolcol
        [0];

      /* MultiPortSwitch: '<S26>/Multiport Switch1' incorporates:
       *  Constant: '<S26>/ Generic Rotate Matrix R_VPRN (column vectors are basis vectors) of VF w.r.t. TNF1'
       *  Constant: '<S26>/Phase Space Rotate Matrix R_Tool (column vectors are basis vectors) of TNF w.r.t. RSF'
       *  MultiPortSwitch: '<S26>/Multiport Switch'
       */
      rtb_R_VRPN_0 =
        &QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.GenericRotateMatrixR_VPRNcolumn
        [0];
      break;

     default:
      rtb_R_Tool_0 =
        &QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.GenericRotateMatrixR_Toolcolumn
        [0];

      /* MultiPortSwitch: '<S26>/Multiport Switch1' incorporates:
       *  Constant: '<S26>/ Generic Rotate Matrix R_VPRN (column vectors are basis vectors) of VF w.r.t. TNF1'
       *  Constant: '<S26>/Generic Rotate Matrix R_Tool (column vectors are basis vectors) of TNF w.r.t. RSF'
       *  MultiPortSwitch: '<S26>/Multiport Switch'
       */
      rtb_R_VRPN_0 =
        &QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.GenericRotateMatrixR_VPRNcolumn
        [0];
      break;
    }

    /* End of MultiPortSwitch: '<S26>/Multiport Switch' */

    /* Math: '<S29>/Math Function' incorporates:
     *  ForEachSliceSelector generated from: '<S26>/q_VF [4xn]'
     *  S-Function (vrpn_client_block): '<S10>/VRPN Client'
     */
    rtb_r33 = QD2_MissionCtrl_ManualPC_2021_B.VRPNClient_o2[0] *
      QD2_MissionCtrl_ManualPC_2021_B.VRPNClient_o2[0];

    /* Math: '<S29>/Math Function1' incorporates:
     *  ForEachSliceSelector generated from: '<S26>/q_VF [4xn]'
     *  S-Function (vrpn_client_block): '<S10>/VRPN Client'
     */
    rtb_MathFunction1 = QD2_MissionCtrl_ManualPC_2021_B.VRPNClient_o2[1] *
      QD2_MissionCtrl_ManualPC_2021_B.VRPNClient_o2[1];

    /* Math: '<S29>/Math Function2' incorporates:
     *  ForEachSliceSelector generated from: '<S26>/q_VF [4xn]'
     *  S-Function (vrpn_client_block): '<S10>/VRPN Client'
     */
    rtb_MathFunction2 = QD2_MissionCtrl_ManualPC_2021_B.VRPNClient_o2[2] *
      QD2_MissionCtrl_ManualPC_2021_B.VRPNClient_o2[2];

    /* Math: '<S29>/Math Function3' incorporates:
     *  ForEachSliceSelector generated from: '<S26>/q_VF [4xn]'
     *  S-Function (vrpn_client_block): '<S10>/VRPN Client'
     */
    rtb_MathFunction3 = QD2_MissionCtrl_ManualPC_2021_B.VRPNClient_o2[3] *
      QD2_MissionCtrl_ManualPC_2021_B.VRPNClient_o2[3];

    /* Product: '<S29>/Product2' incorporates:
     *  ForEachSliceSelector generated from: '<S26>/q_VF [4xn]'
     *  S-Function (vrpn_client_block): '<S10>/VRPN Client'
     */
    rtb_q0q1 = QD2_MissionCtrl_ManualPC_2021_B.VRPNClient_o2[1] *
      QD2_MissionCtrl_ManualPC_2021_B.VRPNClient_o2[2];

    /* Product: '<S29>/Product3' incorporates:
     *  ForEachSliceSelector generated from: '<S26>/q_VF [4xn]'
     *  S-Function (vrpn_client_block): '<S10>/VRPN Client'
     */
    rtb_q2q3 = QD2_MissionCtrl_ManualPC_2021_B.VRPNClient_o2[0] *
      QD2_MissionCtrl_ManualPC_2021_B.VRPNClient_o2[3];

    /* Product: '<S29>/Product6' incorporates:
     *  ForEachSliceSelector generated from: '<S26>/q_VF [4xn]'
     *  S-Function (vrpn_client_block): '<S10>/VRPN Client'
     */
    rtb_EulerAnglesfromRotationMatr =
      QD2_MissionCtrl_ManualPC_2021_B.VRPNClient_o2[1] *
      QD2_MissionCtrl_ManualPC_2021_B.VRPNClient_o2[3];

    /* Product: '<S29>/Product7' incorporates:
     *  ForEachSliceSelector generated from: '<S26>/q_VF [4xn]'
     *  S-Function (vrpn_client_block): '<S10>/VRPN Client'
     */
    rtb_EulerAnglesfromRotationMa_h =
      QD2_MissionCtrl_ManualPC_2021_B.VRPNClient_o2[0] *
      QD2_MissionCtrl_ManualPC_2021_B.VRPNClient_o2[2];

    /* SignalConversion generated from: '<S29>/Vector Concatenate' incorporates:
     *  Gain: '<S29>/Gain1'
     *  Gain: '<S29>/Gain6'
     *  Sum: '<S29>/Sum'
     *  Sum: '<S29>/Sum4'
     *  Sum: '<S29>/Sum9'
     */
    rtb_R_Tool_Transpose[2] = (rtb_EulerAnglesfromRotationMatr -
      rtb_EulerAnglesfromRotationMa_h) *
      QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Gain1_Gain;
    rtb_R_Tool_Transpose[0] = ((rtb_r33 + rtb_MathFunction1) - rtb_MathFunction2)
      - rtb_MathFunction3;
    rtb_R_Tool_Transpose[1] = (rtb_q0q1 + rtb_q2q3) *
      QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Gain6_Gain;

    /* SignalConversion generated from: '<S29>/Vector Concatenate' incorporates:
     *  Gain: '<S29>/Gain'
     *  Sum: '<S29>/Sum3'
     */
    rtb_R_Tool_Transpose[3] = (rtb_q0q1 - rtb_q2q3) *
      QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Gain_Gain;

    /* Product: '<S29>/Product1' incorporates:
     *  ForEachSliceSelector generated from: '<S26>/q_VF [4xn]'
     *  S-Function (vrpn_client_block): '<S10>/VRPN Client'
     */
    rtb_q2q3 = QD2_MissionCtrl_ManualPC_2021_B.VRPNClient_o2[2] *
      QD2_MissionCtrl_ManualPC_2021_B.VRPNClient_o2[3];

    /* Product: '<S29>/Product' incorporates:
     *  ForEachSliceSelector generated from: '<S26>/q_VF [4xn]'
     *  S-Function (vrpn_client_block): '<S10>/VRPN Client'
     */
    rtb_q0q1 = QD2_MissionCtrl_ManualPC_2021_B.VRPNClient_o2[0] *
      QD2_MissionCtrl_ManualPC_2021_B.VRPNClient_o2[1];

    /* Sum: '<S29>/Sum1' incorporates:
     *  Sum: '<S29>/Sum2'
     */
    rtb_r33 -= rtb_MathFunction1;

    /* SignalConversion generated from: '<S29>/Vector Concatenate' incorporates:
     *  Gain: '<S29>/Gain3'
     *  Sum: '<S29>/Sum1'
     *  Sum: '<S29>/Sum6'
     */
    rtb_R_Tool_Transpose[4] = (rtb_r33 + rtb_MathFunction2) - rtb_MathFunction3;
    rtb_R_Tool_Transpose[5] = (rtb_q2q3 + rtb_q0q1) *
      QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Gain3_Gain;

    /* Gain: '<S29>/Gain5' incorporates:
     *  Sum: '<S29>/Sum8'
     */
    rtb_MathFunction1 = (rtb_EulerAnglesfromRotationMatr +
                         rtb_EulerAnglesfromRotationMa_h) *
      QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Gain5_Gain;

    /* Gain: '<S29>/Gain2' incorporates:
     *  Sum: '<S29>/Sum5'
     */
    rtb_EulerAnglesfromRotationMa_h = (rtb_q2q3 - rtb_q0q1) *
      QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Gain2_Gain;

    /* SignalConversion generated from: '<S29>/Vector Concatenate' incorporates:
     *  Sum: '<S29>/Sum2'
     */
    rtb_R_Tool_Transpose[6] = rtb_MathFunction1;
    rtb_R_Tool_Transpose[7] = rtb_EulerAnglesfromRotationMa_h;
    rtb_R_Tool_Transpose[8] = (rtb_r33 - rtb_MathFunction2) + rtb_MathFunction3;
    for (i = 0; i < 3; i++) {
      /* Product: '<S26>/Matrix Multiply1' incorporates:
       *  MultiPortSwitch: '<S26>/Multiport Switch'
       *  MultiPortSwitch: '<S26>/Multiport Switch1'
       */
      rtb_MathFunction3 = 0.0;
      rtb_q0q1 = 0.0;
      rtb_q2q3 = 0.0;
      for (i_0 = 0; i_0 < 3; i_0++) {
        /* Product: '<S26>/Matrix Multiply2' */
        rtb_MatrixMultiply3_tmp = 3 * i + i_0;
        rtb_MathFunction2 = rtb_R_VRPN_0[rtb_MatrixMultiply3_tmp];
        rtb_MathFunction3 += rtb_R_Tool_0[3 * i_0] * rtb_MathFunction2;
        rtb_q0q1 += rtb_R_Tool_0[3 * i_0 + 1] * rtb_MathFunction2;
        rtb_q2q3 += rtb_R_Tool_0[3 * i_0 + 2] * rtb_MathFunction2;

        /* Product: '<S26>/Matrix Multiply2' incorporates:
         *  MultiPortSwitch: '<S26>/Multiport Switch'
         *  MultiPortSwitch: '<S26>/Multiport Switch1'
         */
        rtb_MatrixMultiply2[rtb_MatrixMultiply3_tmp] = 0.0;
      }

      rtb_VF_R_RSF[3 * i + 2] = rtb_q2q3;
      rtb_VF_R_RSF[3 * i + 1] = rtb_q0q1;
      rtb_VF_R_RSF[3 * i] = rtb_MathFunction3;

      /* End of Product: '<S26>/Matrix Multiply1' */
    }

    for (i = 0; i < 3; i++) {
      /* Product: '<S26>/Matrix Multiply2' incorporates:
       *  Math: '<S26>/Transpose'
       *  Product: '<S26>/Matrix Multiply1'
       */
      rtb_MathFunction3 = rtb_MatrixMultiply2[3 * i];
      rtb_MatrixMultiply2_tmp_0 = 3 * i + 1;
      rtb_q0q1 = rtb_MatrixMultiply2[rtb_MatrixMultiply2_tmp_0];
      rtb_MatrixMultiply2_tmp = 3 * i + 2;
      rtb_q2q3 = rtb_MatrixMultiply2[rtb_MatrixMultiply2_tmp];
      for (i_0 = 0; i_0 < 3; i_0++) {
        /* Math: '<S26>/Transpose' incorporates:
         *  Product: '<S26>/Matrix Multiply3'
         */
        rtb_MatrixMultiply3_tmp = 3 * i + i_0;
        rtb_MathFunction2 = rtb_R_Tool_Transpose[rtb_MatrixMultiply3_tmp];
        rtb_MathFunction3 += rtb_VF_R_RSF[3 * i_0] * rtb_MathFunction2;
        rtb_q0q1 += rtb_VF_R_RSF[3 * i_0 + 1] * rtb_MathFunction2;
        rtb_q2q3 += rtb_VF_R_RSF[3 * i_0 + 2] * rtb_MathFunction2;

        /* Math: '<S26>/Transpose' incorporates:
         *  MultiPortSwitch: '<S26>/Multiport Switch'
         *  Product: '<S26>/Matrix Multiply1'
         */
        rtb_R_Tool_Transpose[rtb_MatrixMultiply3_tmp] = rtb_R_Tool_0[3 * i_0 + i];

        /* Product: '<S26>/Matrix Multiply3' */
        rtb_MatrixMultiply3[rtb_MatrixMultiply3_tmp] = 0.0;
      }

      rtb_MatrixMultiply2[rtb_MatrixMultiply2_tmp] = rtb_q2q3;
      rtb_MatrixMultiply2[rtb_MatrixMultiply2_tmp_0] = rtb_q0q1;
      rtb_MatrixMultiply2[3 * i] = rtb_MathFunction3;
    }

    /* Product: '<S26>/Matrix Multiply3' incorporates:
     *  Math: '<S26>/Transpose'
     *  Product: '<S26>/Matrix Multiply2'
     */
    for (i = 0; i < 3; i++) {
      rtb_MathFunction3 = rtb_MatrixMultiply3[3 * i];
      rtb_MatrixMultiply3_tmp = 3 * i + 1;
      rtb_q0q1 = rtb_MatrixMultiply3[rtb_MatrixMultiply3_tmp];
      rtb_MatrixMultiply2_tmp_0 = 3 * i + 2;
      rtb_q2q3 = rtb_MatrixMultiply3[rtb_MatrixMultiply2_tmp_0];
      for (i_0 = 0; i_0 < 3; i_0++) {
        rtb_MathFunction2 = rtb_R_Tool_Transpose[3 * i + i_0];
        rtb_MathFunction3 += rtb_MatrixMultiply2[3 * i_0] * rtb_MathFunction2;
        rtb_q0q1 += rtb_MatrixMultiply2[3 * i_0 + 1] * rtb_MathFunction2;
        rtb_q2q3 += rtb_MatrixMultiply2[3 * i_0 + 2] * rtb_MathFunction2;
      }

      rtb_MatrixMultiply3[rtb_MatrixMultiply2_tmp_0] = rtb_q2q3;
      rtb_MatrixMultiply3[rtb_MatrixMultiply3_tmp] = rtb_q0q1;
      rtb_MatrixMultiply3[3 * i] = rtb_MathFunction3;
    }

    /* S-Function (euler_angles_from_rotation_matrix_block): '<S26>/Euler Angles from Rotation Matrix (Relative ZYX)' */
    {
      if (fabs(rtb_MatrixMultiply3[0]) > DBL_EPSILON || fabs
          (rtb_MatrixMultiply3[1]) > DBL_EPSILON) {
        rtb_MathFunction1 = atan2(rtb_MatrixMultiply3[1], rtb_MatrixMultiply3[0]);
        rtb_EulerAnglesfromRotationMatr = atan2(rtb_MatrixMultiply3[5],
          rtb_MatrixMultiply3[8]);
      } else {
        rtb_MathFunction1 = -PI_2;
        rtb_EulerAnglesfromRotationMatr = atan2(-rtb_MatrixMultiply3[3],
          rtb_MatrixMultiply3[4]);
      }

      rtb_EulerAnglesfromRotationMa_h = asin(-rtb_MatrixMultiply3[2]);
    }

    /* Product: '<S26>/Matrix Multiply' incorporates:
     *  ForEachSliceSelector generated from: '<S26>/xyz_VF (m) [3xn]'
     *  Product: '<S26>/Matrix Multiply1'
     *  S-Function (vrpn_client_block): '<S10>/VRPN Client'
     */
    rtb_MathFunction3 = 0.0;
    rtb_q0q1 = 0.0;
    rtb_q2q3 = 0.0;
    for (i = 0; i < 3; i++) {
      rtb_MathFunction2 = QD2_MissionCtrl_ManualPC_2021_B.VRPNClient_o1[i];
      rtb_MathFunction3 += rtb_VF_R_RSF[3 * i] * rtb_MathFunction2;
      rtb_q0q1 += rtb_VF_R_RSF[3 * i + 1] * rtb_MathFunction2;
      rtb_q2q3 += rtb_VF_R_RSF[3 * i + 2] * rtb_MathFunction2;
    }

    /* ForEachSliceAssignment generated from: '<S26>/data_RSF (m, rad, bool) [7n]' incorporates:
     *  DataTypeConversion: '<S26>/Data Type Conversion'
     *  ForEachSliceSelector generated from: '<S26>/isTracking [1xn]'
     *  Product: '<S26>/Matrix Multiply'
     *  SignalConversion generated from: '<S26>/data_RSF (m, rad, bool) [7n]'
     */
    i = ForEach_itr_p * 7;
    rtb_ImpAsg_InsertedFor_data_RSF[i] = rtb_MathFunction3;
    rtb_ImpAsg_InsertedFor_data_RSF[i + 1] = rtb_q0q1;
    rtb_ImpAsg_InsertedFor_data_RSF[i + 2] = rtb_q2q3;
    rtb_ImpAsg_InsertedFor_data_RSF[i + 3] = rtb_EulerAnglesfromRotationMatr;
    rtb_ImpAsg_InsertedFor_data_RSF[i + 4] = rtb_EulerAnglesfromRotationMa_h;
    rtb_ImpAsg_InsertedFor_data_RSF[i + 5] = rtb_MathFunction1;
    rtb_ImpAsg_InsertedFor_data_RSF[i + 6] =
      QD2_MissionCtrl_ManualPC_2021_B.VRPNClient_o9;

    /* ForEachSliceAssignment generated from: '<S26>/rot_RSF (rad) [3n]' incorporates:
     *  SignalConversion generated from: '<S26>/rot_RSF (rad) [3n]'
     */
    rtb_ImpAsg_InsertedFor_rot_RSFr[ForEach_itr_p * 3] =
      rtb_EulerAnglesfromRotationMatr;
    rtb_ImpAsg_InsertedFor_rot_RSFr[ForEach_itr_p * 3 + 1] =
      rtb_EulerAnglesfromRotationMa_h;
    rtb_ImpAsg_InsertedFor_rot_RSFr[ForEach_itr_p * 3 + 2] = rtb_MathFunction1;

    /* Sum: '<S28>/Sum' incorporates:
     *  Constant: '<S28>/Constant'
     */
    rtb_MathFunction1 = ((rtb_MatrixMultiply3[0] + rtb_MatrixMultiply3[4]) +
                         rtb_MatrixMultiply3[8]) +
      QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Constant_Value_i;

    /* Saturate: '<S28>/Saturation' */
    if (rtb_MathFunction1 >
        QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Saturation_UpperSat) {
      rtb_MathFunction1 =
        QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Saturation_UpperSat;
    } else if (rtb_MathFunction1 <
               QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Saturation_LowerSat) {
      rtb_MathFunction1 =
        QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Saturation_LowerSat;
    }

    /* End of Saturate: '<S28>/Saturation' */

    /* Sqrt: '<S28>/Sqrt' */
    rtb_MathFunction1 = sqrt(rtb_MathFunction1);

    /* Gain: '<S28>/Gain' */
    rtb_r33 = QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Gain_Gain_c *
      rtb_MathFunction1;

    /* Sum: '<S28>/Sum1' incorporates:
     *  Constant: '<S28>/Constant'
     */
    rtb_MathFunction1 = ((rtb_MatrixMultiply3[0] - rtb_MatrixMultiply3[4]) -
                         rtb_MatrixMultiply3[8]) +
      QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Constant_Value_i;

    /* Saturate: '<S28>/Saturation1' */
    if (rtb_MathFunction1 >
        QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Saturation1_UpperSat) {
      rtb_MathFunction1 =
        QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Saturation1_UpperSat;
    } else if (rtb_MathFunction1 <
               QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Saturation1_LowerSat)
    {
      rtb_MathFunction1 =
        QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Saturation1_LowerSat;
    }

    /* End of Saturate: '<S28>/Saturation1' */

    /* Sqrt: '<S28>/Sqrt1' */
    rtb_MathFunction1 = sqrt(rtb_MathFunction1);

    /* If: '<S30>/If1' incorporates:
     *  Gain: '<S28>/Gain1'
     *  If: '<S32>/If'
     */
    if (rtb_r33 > 1.0E-8) {
      /* Update for IfAction SubSystem: '<S30>/q0 > 0' incorporates:
       *  ActionPort: '<S31>/Action Port'
       */
      /* Update for If: '<S30>/If1' */
      srUpdateBC(QD2_MissionCtrl_ManualPC_202_DW.CoreSubsys[ForEach_itr_p].
                 q00_SubsysRanBC_f);

      /* End of Update for SubSystem: '<S30>/q0 > 0' */
    } else {
      /* Outputs for IfAction SubSystem: '<S30>/q0 ~ 0' incorporates:
       *  ActionPort: '<S32>/Action Port'
       */
      if (QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Gain1_Gain_n *
          rtb_MathFunction1 > 1.0E-8) {
        /* Update for IfAction SubSystem: '<S32>/q1 > 0' incorporates:
         *  ActionPort: '<S33>/Action Port'
         */
        /* Update for If: '<S32>/If' */
        srUpdateBC(QD2_MissionCtrl_ManualPC_202_DW.CoreSubsys[ForEach_itr_p].
                   q10_SubsysRanBC_h);

        /* End of Update for SubSystem: '<S32>/q1 > 0' */
      } else {
        /* Update for IfAction SubSystem: '<S32>/q1 ~ 0' incorporates:
         *  ActionPort: '<S34>/Action Port'
         */
        /* Update for If: '<S32>/If' */
        srUpdateBC(QD2_MissionCtrl_ManualPC_202_DW.CoreSubsys[ForEach_itr_p].
                   q10_SubsysRanBC);

        /* End of Update for SubSystem: '<S32>/q1 ~ 0' */
      }

      /* End of Outputs for SubSystem: '<S30>/q0 ~ 0' */

      /* Update for IfAction SubSystem: '<S30>/q0 ~ 0' incorporates:
       *  ActionPort: '<S32>/Action Port'
       */
      /* Update for If: '<S30>/If1' */
      srUpdateBC(QD2_MissionCtrl_ManualPC_202_DW.CoreSubsys[ForEach_itr_p].
                 q00_SubsysRanBC);

      /* End of Update for SubSystem: '<S30>/q0 ~ 0' */
    }

    /* End of If: '<S30>/If1' */

    /* ForEachSliceAssignment generated from: '<S26>/R_VRPN [3nx3]' incorporates:
     *  MultiPortSwitch: '<S26>/Multiport Switch1'
     */
    i = ForEach_itr_p * 3;
    for (i_0 = 0; i_0 < 3; i_0++) {
      /* ForEachSliceAssignment generated from: '<S26>/R_Tool [3nx3]' incorporates:
       *  ForEachSliceAssignment generated from: '<S26>/R_RSF [3n x 3]'
       */
      rtb_MatrixMultiply3_tmp = 3 * i_0 + i;
      rtb_ImpAsg_InsertedFor_R_VRPN3n[rtb_MatrixMultiply3_tmp] = rtb_R_VRPN_0[3 *
        i_0];

      /* ForEachSliceAssignment generated from: '<S26>/R_Tool [3nx3]' incorporates:
       *  ForEachSliceAssignment generated from: '<S26>/R_VRPN [3nx3]'
       *  MultiPortSwitch: '<S26>/Multiport Switch'
       *  MultiPortSwitch: '<S26>/Multiport Switch1'
       */
      rtb_ImpAsg_InsertedFor_R_Tool3n[rtb_MatrixMultiply3_tmp] = rtb_R_Tool_0[3 *
        i_0];

      /* ForEachSliceAssignment generated from: '<S26>/R_RSF [3n x 3]' incorporates:
       *  Product: '<S26>/Matrix Multiply3'
       */
      rtb_ImpAsg_InsertedFor_R_RSF3nx[rtb_MatrixMultiply3_tmp] =
        rtb_MatrixMultiply3[3 * i_0];

      /* ForEachSliceAssignment generated from: '<S26>/R_Tool [3nx3]' incorporates:
       *  ForEachSliceAssignment generated from: '<S26>/R_RSF [3n x 3]'
       */
      rtb_MatrixMultiply2_tmp_0 = 3 * i_0 + 1;
      rtb_ImpAsg_InsertedFor_R_VRPN3n[rtb_MatrixMultiply3_tmp + 1] =
        rtb_R_VRPN_0[rtb_MatrixMultiply2_tmp_0];

      /* ForEachSliceAssignment generated from: '<S26>/R_Tool [3nx3]' incorporates:
       *  ForEachSliceAssignment generated from: '<S26>/R_VRPN [3nx3]'
       *  MultiPortSwitch: '<S26>/Multiport Switch'
       *  MultiPortSwitch: '<S26>/Multiport Switch1'
       */
      rtb_ImpAsg_InsertedFor_R_Tool3n[rtb_MatrixMultiply3_tmp + 1] =
        rtb_R_Tool_0[rtb_MatrixMultiply2_tmp_0];

      /* ForEachSliceAssignment generated from: '<S26>/R_RSF [3n x 3]' incorporates:
       *  Product: '<S26>/Matrix Multiply3'
       */
      rtb_ImpAsg_InsertedFor_R_RSF3nx[rtb_MatrixMultiply3_tmp + 1] =
        rtb_MatrixMultiply3[rtb_MatrixMultiply2_tmp_0];

      /* ForEachSliceAssignment generated from: '<S26>/R_Tool [3nx3]' incorporates:
       *  ForEachSliceAssignment generated from: '<S26>/R_RSF [3n x 3]'
       */
      rtb_MatrixMultiply2_tmp_0 = 3 * i_0 + 2;
      rtb_ImpAsg_InsertedFor_R_VRPN3n[rtb_MatrixMultiply3_tmp + 2] =
        rtb_R_VRPN_0[rtb_MatrixMultiply2_tmp_0];

      /* ForEachSliceAssignment generated from: '<S26>/R_Tool [3nx3]' incorporates:
       *  ForEachSliceAssignment generated from: '<S26>/R_VRPN [3nx3]'
       *  MultiPortSwitch: '<S26>/Multiport Switch'
       *  MultiPortSwitch: '<S26>/Multiport Switch1'
       */
      rtb_ImpAsg_InsertedFor_R_Tool3n[rtb_MatrixMultiply3_tmp + 2] =
        rtb_R_Tool_0[rtb_MatrixMultiply2_tmp_0];

      /* ForEachSliceAssignment generated from: '<S26>/R_RSF [3n x 3]' incorporates:
       *  Product: '<S26>/Matrix Multiply3'
       */
      rtb_ImpAsg_InsertedFor_R_RSF3nx[rtb_MatrixMultiply3_tmp + 2] =
        rtb_MatrixMultiply3[rtb_MatrixMultiply2_tmp_0];
    }

    /* End of ForEachSliceAssignment generated from: '<S26>/R_VRPN [3nx3]' */
  }

  /* End of Outputs for SubSystem: '<S10>/For Each Subsystem (Convention Correction:  Motive Frame to Research Studio Frame)1' */

  /* Gain: '<S27>/Gain' */
  QD2_MissionCtrl_ManualPC_2021_B.Gain_i[0] =
    QD2_MissionCtrl_ManualPC_2021_P.Gain_Gain_b *
    rtb_ImpAsg_InsertedFor_rot_RSFr[0];
  QD2_MissionCtrl_ManualPC_2021_B.Gain_i[1] =
    QD2_MissionCtrl_ManualPC_2021_P.Gain_Gain_b *
    rtb_ImpAsg_InsertedFor_rot_RSFr[1];
  QD2_MissionCtrl_ManualPC_2021_B.Gain_i[2] =
    QD2_MissionCtrl_ManualPC_2021_P.Gain_Gain_b *
    rtb_ImpAsg_InsertedFor_rot_RSFr[2];

  /* RateTransition: '<S10>/Rate Transition2' incorporates:
   *  ForEachSliceAssignment generated from: '<S26>/data_RSF (m, rad, bool) [7n]'
   */
  for (i = 0; i < 7; i++) {
    QD2_MissionCtrl_ManualPC_202_DW.RateTransition2_Buffer0[i] =
      rtb_ImpAsg_InsertedFor_data_RSF[i];
  }

  /* End of RateTransition: '<S10>/Rate Transition2' */

  /* RateTransition: '<S10>/Rate Transition6' incorporates:
   *  ForEachSliceAssignment generated from: '<S26>/R_RSF [3n x 3]'
   */
  memcpy(&QD2_MissionCtrl_ManualPC_202_DW.RateTransition6_Buffer0[0],
         &rtb_ImpAsg_InsertedFor_R_RSF3nx[0], 9U * sizeof(real_T));

  /* RateTransition: '<S10>/Rate Transition7' incorporates:
   *  ForEachSliceAssignment generated from: '<S26>/R_Tool [3nx3]'
   */
  memcpy(&QD2_MissionCtrl_ManualPC_202_DW.RateTransition7_Buffer0[0],
         &rtb_ImpAsg_InsertedFor_R_Tool3n[0], 9U * sizeof(real_T));

  /* RateTransition: '<S10>/Rate Transition8' incorporates:
   *  ForEachSliceAssignment generated from: '<S26>/R_VRPN [3nx3]'
   */
  memcpy(&QD2_MissionCtrl_ManualPC_202_DW.RateTransition8_Buffer0[0],
         &rtb_ImpAsg_InsertedFor_R_VRPN3n[0], 9U * sizeof(real_T));
}

/* Model update function for TID2 */
void QD2_MissionCtrl_ManualPC_2021a_update2(void) /* Sample time: [0.016s, 0.0s] */
{
  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++QD2_MissionCtrl_ManualPC_202_M->Timing.clockTick2)) {
    ++QD2_MissionCtrl_ManualPC_202_M->Timing.clockTickH2;
  }

  QD2_MissionCtrl_ManualPC_202_M->Timing.t[2] =
    QD2_MissionCtrl_ManualPC_202_M->Timing.clockTick2 *
    QD2_MissionCtrl_ManualPC_202_M->Timing.stepSize2 +
    QD2_MissionCtrl_ManualPC_202_M->Timing.clockTickH2 *
    QD2_MissionCtrl_ManualPC_202_M->Timing.stepSize2 * 4294967296.0;
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void QD2_MissionCtrl_ManualPC_2021a_output(int_T tid)
{
  switch (tid) {
   case 0 :
    QD2_MissionCtrl_ManualPC_2021a_output0();
    break;

   case 2 :
    QD2_MissionCtrl_ManualPC_2021a_output2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void QD2_MissionCtrl_ManualPC_2021a_update(int_T tid)
{
  switch (tid) {
   case 0 :
    QD2_MissionCtrl_ManualPC_2021a_update0();
    break;

   case 2 :
    QD2_MissionCtrl_ManualPC_2021a_update2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void QD2_MissionCtrl_ManualPC_2021a_initialize(void)
{
  {
    /* local scratch DWork variables */
    int32_T ForEach_itr;
    int32_T i;

    /* Start for S-Function (host_initialize_block): '<S9>/Host Initialize' */

    /* S-Function Block: QD2_MissionCtrl_ManualPC_2021a/MISSION CONTROL QDRONE MANUAL POSITION CONTROL/JOYSTICK_FRSKY/Host Game Controller (host_game_controller_block) */
    {
      qthread_section_init
        (&QD2_MissionCtrl_ManualPC_202_DW.HostGameController_Lock, NULL);
    }

    /* S-Function Block: QD2_MissionCtrl_ManualPC_2021a/MISSION CONTROL QDRONE MANUAL POSITION CONTROL/JOYSTICK_FRSKY/Host Initialize (host_initialize_block) */
    {
      t_error result;
      QD2_MissionCtrl_ManualPC_2021_B.HostInitialize_o1 =
        HOST_STATE_NOT_LISTENING;
      result = extmode_svr_register_connected_callback
        (host_extmode_svr_connected_callback,
         host_extmode_svr_disconnected_callback, NULL,
         &QD2_MissionCtrl_ManualPC_202_DW.HostInitialize_ConnectedHandle);
      if (result == 0) {
        result = extmode_svr_register_custom_action
          (EXT_MODE_ACTION_HOST_INTERFACE,
           host_extmode_svr_custom_action_callback, NULL);
      }

      QD2_MissionCtrl_ManualPC_2021_B.HostInitialize_o2 = result;
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QD2_MissionCtrl_ManualPC_202_M, _rt_error_message);
      }

      if (rtExtModeQuarcIsConnected()) {
        /* Invoke connected callbacks explicitly since Simulink was already connected when MdlStart called */
        host_extmode_svr_connected_callback(NULL);
      }
    }

    /* Start for Enabled SubSystem: '<S9>/FrSKYMapping' */
    QD2_MissionCtrl_ManualPC_202_DW.FrSKYMapping_MODE = false;

    /* End of Start for SubSystem: '<S9>/FrSKYMapping' */
    for (i = 0; i < 7; i++) {
      /* Start for RateTransition: '<S10>/Rate Transition2' */
      QD2_MissionCtrl_ManualPC_2021_B.RateTransition2[i] =
        QD2_MissionCtrl_ManualPC_2021_P.RateTransition2_InitialConditio;
    }

    /* Start for S-Function (inverse_modulus_block): '<S11>/Unwrap optitrack measurement' */

    /* S-Function Block: QD2_MissionCtrl_ManualPC_2021a/MISSION CONTROL QDRONE MANUAL POSITION CONTROL/Measurement Conditioning/Unwrap optitrack measurement (inverse_modulus_block) */
    {
      QD2_MissionCtrl_ManualPC_202_DW.Unwrapoptitrackmeasurement_Firs = true;
      QD2_MissionCtrl_ManualPC_202_DW.Unwrapoptitrackmeasurement_Revo = 0;
    }

    /* Start for Enabled SubSystem: '<S8>/Enabled Subsystem' */
    QD2_MissionCtrl_ManualPC_202_DW.EnabledSubsystem_MODE = false;

    /* End of Start for SubSystem: '<S8>/Enabled Subsystem' */
    /* Start for S-Function (stream_server_block): '<S1>/Stream Server' incorporates:
     *  Constant: '<S1>/Constant'
     */

    /* S-Function Block: QD2_MissionCtrl_ManualPC_2021a/Communication/Stream Server (stream_server_block) */
    {
      QD2_MissionCtrl_ManualPC_202_DW.StreamServer_Stream = NULL;
      QD2_MissionCtrl_ManualPC_2021_B.StreamServer_o4 =
        QD2_MissionCtrl_ManualPC_2021_P.StreamServer_default_value;
      QD2_MissionCtrl_ManualPC_202_DW.StreamServer_Listening = false;
    }

    for (i = 0; i < 9; i++) {
      /* Start for RateTransition: '<S10>/Rate Transition6' */
      QD2_MissionCtrl_ManualPC_2021_B.RateTransition6[i] =
        QD2_MissionCtrl_ManualPC_2021_P.RateTransition6_InitialConditio;

      /* Start for RateTransition: '<S10>/Rate Transition7' */
      QD2_MissionCtrl_ManualPC_2021_B.RateTransition7[i] =
        QD2_MissionCtrl_ManualPC_2021_P.RateTransition7_InitialConditio;

      /* Start for RateTransition: '<S10>/Rate Transition8' */
      QD2_MissionCtrl_ManualPC_2021_B.RateTransition8[i] =
        QD2_MissionCtrl_ManualPC_2021_P.RateTransition8_InitialConditio;
    }

    /* Start for Iterator SubSystem: '<S14>/For Each Subsystem' */
    for (ForEach_itr = 0; ForEach_itr < 2; ForEach_itr++) {
    }

    /* End of Start for SubSystem: '<S14>/For Each Subsystem' */

    /* Start for S-Function (vrpn_client_block): '<S10>/VRPN Client' */

    /* S-Function Block: QD2_MissionCtrl_ManualPC_2021a/MISSION CONTROL QDRONE MANUAL POSITION CONTROL/Localization Data Server (VRPN) /VRPN Client (vrpn_client_block) */
    {
      t_error result;
      const char* tracker_device_names[128];
      t_int index;
      const char* device_list;
      const char* ep;
      const char* cp;
      const char* wp;
      device_list = (const char*)
        QD2_MissionCtrl_ManualPC_ConstP.VRPNClient_TraStringList;
      ep = device_list + 11 - 1;
      wp = device_list;
      index = 0;
      for (cp = device_list; cp <= ep; cp++) {
        if (*cp == '\0') {
          tracker_device_names[index] = wp;
          index++;
          wp = (char *)cp + 1;
        }
      }

      result = vrpn_client_open
        (&QD2_MissionCtrl_ManualPC_202_DW.VRPNClient_VRPNClient,
         "192.168.2.5:3883",
         NULL, NULL, 0,
         NULL, NULL, 0,
         NULL, NULL, 0,
         tracker_device_names,
         &QD2_MissionCtrl_ManualPC_2021_P.VRPNClient_TraNumSensors, 1);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QD2_MissionCtrl_ManualPC_202_M, _rt_error_message);
      }

      result = vrpn_client_initialize
        (QD2_MissionCtrl_ManualPC_202_DW.VRPNClient_VRPNClient,
         NULL, NULL, 0,
         NULL, NULL, 0,
         NULL, NULL, 0,
         (t_int *)QD2_MissionCtrl_ManualPC_2021_P.VRPNClient_TraReadSensors,
         (t_int *)&QD2_MissionCtrl_ManualPC_2021_P.VRPNClient_TraReadSensors[1],
         1);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QD2_MissionCtrl_ManualPC_202_M, _rt_error_message);
      }
    }

    /* user code (Start function Trailer) */

    /* S-Function Block: QD2_MissionCtrl_ManualPC_2021a/Communication/Detect Communication loss/Time (time_block) */
    {
      t_error result;
      result = timeout_get_high_resolution_time(&_high_resolution_start_time);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QD2_MissionCtrl_ManualPC_202_M, _rt_error_message);
        return;
      }
    }
  }

  QD2_MissionCtrl_ManualP_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;
  QD2_MissionCtrl_ManualP_PrevZCX.Integrator2_Reset_ZCE = UNINITIALIZED_ZCSIG;
  QD2_MissionCtrl_ManualP_PrevZCX.pulsecount_Trig_ZCE = POS_ZCSIG;
  QD2_MissionCtrl_ManualP_PrevZCX.TriggeredSubsystem_Trig_ZCE =
    UNINITIALIZED_ZCSIG;

  {
    /* local scratch DWork variables */
    int32_T ForEach_itr;
    int32_T i;

    /* InitializeConditions for DiscreteIntegrator: '<S21>/Discrete-Time Integrator' */
    QD2_MissionCtrl_ManualPC_202_DW.DiscreteTimeIntegrator_DSTATE =
      QD2_MissionCtrl_ManualPC_2021_P.DiscreteTimeIntegrator_IC_j;
    QD2_MissionCtrl_ManualPC_202_DW.DiscreteTimeIntegrator_PrevRese = 0;

    /* InitializeConditions for RateTransition: '<S10>/Rate Transition2' */
    for (i = 0; i < 7; i++) {
      QD2_MissionCtrl_ManualPC_202_DW.RateTransition2_Buffer0[i] =
        QD2_MissionCtrl_ManualPC_2021_P.RateTransition2_InitialConditio;
    }

    /* End of InitializeConditions for RateTransition: '<S10>/Rate Transition2' */

    /* InitializeConditions for Integrator: '<S14>/Integrator' */
    QD2_MissionCtrl_ManualPC_2021_X.Integrator_CSTATE[0] =
      QD2_MissionCtrl_ManualPC_2021_P.Integrator_IC;
    QD2_MissionCtrl_ManualPC_2021_X.Integrator_CSTATE[1] =
      QD2_MissionCtrl_ManualPC_2021_P.Integrator_IC;

    /* InitializeConditions for Memory: '<S14>/Memory1' */
    QD2_MissionCtrl_ManualPC_202_DW.Memory1_PreviousInput =
      QD2_MissionCtrl_ManualPC_2021_P.Memory1_InitialCondition;

    /* InitializeConditions for Integrator: '<S14>/Integrator2' */
    QD2_MissionCtrl_ManualPC_2021_X.Integrator2_CSTATE =
      QD2_MissionCtrl_ManualPC_2021_P.Integrator2_IC;

    /* InitializeConditions for S-Function (one_shot_block): '<S17>/one_shot_block' incorporates:
     *  Constant: '<S17>/width'
     */
    {
      QD2_MissionCtrl_ManualPC_202_DW.one_shot_block_DSTATE[0] = 0.0;
      QD2_MissionCtrl_ManualPC_202_DW.one_shot_block_DSTATE[1] = 0.0;
      QD2_MissionCtrl_ManualPC_202_DW.one_shot_block_DSTATE[2] = 0.0;
    }

    /* InitializeConditions for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
    QD2_MissionCtrl_ManualPC_202_DW.DiscreteTimeIntegrator_DSTATE_j =
      QD2_MissionCtrl_ManualPC_2021_P.DiscreteTimeIntegrator_IC_c;
    QD2_MissionCtrl_ManualPC_202_DW.DiscreteTimeIntegrator_PrevRe_b = 0;
    for (i = 0; i < 9; i++) {
      /* InitializeConditions for RateTransition: '<S10>/Rate Transition6' */
      QD2_MissionCtrl_ManualPC_202_DW.RateTransition6_Buffer0[i] =
        QD2_MissionCtrl_ManualPC_2021_P.RateTransition6_InitialConditio;

      /* InitializeConditions for RateTransition: '<S10>/Rate Transition7' */
      QD2_MissionCtrl_ManualPC_202_DW.RateTransition7_Buffer0[i] =
        QD2_MissionCtrl_ManualPC_2021_P.RateTransition7_InitialConditio;

      /* InitializeConditions for RateTransition: '<S10>/Rate Transition8' */
      QD2_MissionCtrl_ManualPC_202_DW.RateTransition8_Buffer0[i] =
        QD2_MissionCtrl_ManualPC_2021_P.RateTransition8_InitialConditio;
    }

    /* InitializeConditions for Delay: '<S12>/Delay' */
    for (i = 0; i < 6000; i++) {
      QD2_MissionCtrl_ManualPC_202_DW.Delay_DSTATE[i] =
        QD2_MissionCtrl_ManualPC_2021_P.Delay_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<S12>/Delay' */

    /* InitializeConditions for Delay: '<S12>/Delay1' */
    for (i = 0; i < 2000; i++) {
      QD2_MissionCtrl_ManualPC_202_DW.Delay1_DSTATE[i] =
        QD2_MissionCtrl_ManualPC_2021_P.Delay1_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<S12>/Delay1' */

    /* InitializeConditions for Memory: '<S14>/Memory' */
    QD2_MissionCtrl_ManualPC_202_DW.Memory_PreviousInput_h[0] =
      QD2_MissionCtrl_ManualPC_2021_P.Memory_InitialCondition_m[0];
    QD2_MissionCtrl_ManualPC_202_DW.Memory_PreviousInput_h[1] =
      QD2_MissionCtrl_ManualPC_2021_P.Memory_InitialCondition_m[1];

    /* SystemInitialize for Enabled SubSystem: '<S9>/FrSKYMapping' */
    /* InitializeConditions for DiscreteIntegrator: '<S23>/Discrete-Time Integrator' */
    QD2_MissionCtrl_ManualPC_202_DW.DiscreteTimeIntegrator_DSTATE_h =
      QD2_MissionCtrl_ManualPC_2021_P.DiscreteTimeIntegrator_IC;
    QD2_MissionCtrl_ManualPC_202_DW.DiscreteTimeIntegrator_PrevRe_i = 0;

    /* SystemInitialize for RelationalOperator: '<S23>/Relational Operator' incorporates:
     *  Outport: '<S18>/Emergency Abort (bool)'
     */
    QD2_MissionCtrl_ManualPC_2021_B.RelationalOperator =
      QD2_MissionCtrl_ManualPC_2021_P.EmergencyAbortbool_Y0;

    /* SystemInitialize for Gain: '<S18>/Gain' incorporates:
     *  Outport: '<S18>/Yaw (%)'
     */
    QD2_MissionCtrl_ManualPC_2021_B.Gain_h =
      QD2_MissionCtrl_ManualPC_2021_P.Yaw_Y0;

    /* SystemInitialize for Bias: '<S18>/Bias' incorporates:
     *  Outport: '<S18>/Throttle (%)'
     */
    QD2_MissionCtrl_ManualPC_2021_B.Bias =
      QD2_MissionCtrl_ManualPC_2021_P.Throttle_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S18>/y' incorporates:
     *  Outport: '<S18>/Roll (%)'
     */
    QD2_MissionCtrl_ManualPC_2021_B.y = QD2_MissionCtrl_ManualPC_2021_P.Roll_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S18>/z' incorporates:
     *  Outport: '<S18>/Pitch (%)'
     */
    QD2_MissionCtrl_ManualPC_2021_B.z = QD2_MissionCtrl_ManualPC_2021_P.Pitch_Y0;

    /* SystemInitialize for Outport: '<S18>/Arm//Disarm (bool) ' incorporates:
     *  SignalConversion generated from: '<S18>/Buttons'
     */
    QD2_MissionCtrl_ManualPC_2021_B.Buttons[1] =
      QD2_MissionCtrl_ManualPC_2021_P.ArmDisarmbool_Y0;

    /* SystemInitialize for RelationalOperator: '<S22>/Compare' incorporates:
     *  Outport: '<S18>/Takeoff//Autoland (bool)'
     */
    QD2_MissionCtrl_ManualPC_2021_B.Compare_n =
      QD2_MissionCtrl_ManualPC_2021_P.TakeoffAutolandbool_Y0;

    /* End of SystemInitialize for SubSystem: '<S9>/FrSKYMapping' */

    /* SystemInitialize for Enabled SubSystem: '<S9>/Initialization and Conditioning' */
    /* SystemInitialize for SignalConversion generated from: '<S19>/Joystick Issue (0,1)' incorporates:
     *  Outport: '<S19>/Joystick Issue (0,1)'
     */
    QD2_MissionCtrl_ManualPC_2021_B.OutportBufferForJoystickIssue01 =
      QD2_MissionCtrl_ManualPC_2021_P.JoystickIssue01_Y0;

    /* SystemInitialize for Product: '<S19>/Product2' incorporates:
     *  Outport: '<S19>/Triggers (0,1) [4]'
     */
    QD2_MissionCtrl_ManualPC_2021_B.Product2 =
      QD2_MissionCtrl_ManualPC_2021_P.Triggers014_Y0;

    /* SystemInitialize for Product: '<S19>/Product3' incorporates:
     *  Outport: '<S19>/Triggers (0,1) [4]'
     */
    QD2_MissionCtrl_ManualPC_2021_B.Product3 =
      QD2_MissionCtrl_ManualPC_2021_P.Triggers014_Y0;

    /* SystemInitialize for DataTypeConversion: '<S19>/Data Type Conversion2' incorporates:
     *  Outport: '<S19>/Triggers (0,1) [4]'
     */
    QD2_MissionCtrl_ManualPC_2021_B.DataTypeConversion2_i =
      QD2_MissionCtrl_ManualPC_2021_P.Triggers014_Y0;

    /* SystemInitialize for DataTypeConversion: '<S19>/Data Type Conversion4' incorporates:
     *  Outport: '<S19>/Triggers (0,1) [4]'
     */
    QD2_MissionCtrl_ManualPC_2021_B.DataTypeConversion4 =
      QD2_MissionCtrl_ManualPC_2021_P.Triggers014_Y0;

    /* SystemInitialize for Product: '<S19>/Product1' incorporates:
     *  Outport: '<S19>/Commands (%) [4]'
     */
    QD2_MissionCtrl_ManualPC_2021_B.Product1 =
      QD2_MissionCtrl_ManualPC_2021_P.Commands4_Y0;

    /* SystemInitialize for Product: '<S19>/Product' incorporates:
     *  Outport: '<S19>/Commands (%) [4]'
     */
    QD2_MissionCtrl_ManualPC_2021_B.Product_n[0] =
      QD2_MissionCtrl_ManualPC_2021_P.Commands4_Y0;
    QD2_MissionCtrl_ManualPC_2021_B.Product_n[1] =
      QD2_MissionCtrl_ManualPC_2021_P.Commands4_Y0;
    QD2_MissionCtrl_ManualPC_2021_B.Product_n[2] =
      QD2_MissionCtrl_ManualPC_2021_P.Commands4_Y0;

    /* End of SystemInitialize for SubSystem: '<S9>/Initialization and Conditioning' */

    /* SystemInitialize for Atomic SubSystem: '<S9>/Pulse Check' */
    /* SystemInitialize for Triggered SubSystem: '<S20>/pulse count ' */
    /* InitializeConditions for UnitDelay: '<S24>/Unit Delay' */
    QD2_MissionCtrl_ManualPC_202_DW.UnitDelay_DSTATE =
      QD2_MissionCtrl_ManualPC_2021_P.UnitDelay_InitialCondition;

    /* SystemInitialize for Sum: '<S25>/FixPt Sum1' incorporates:
     *  Outport: '<S24>/Number of Pulses'
     */
    QD2_MissionCtrl_ManualPC_2021_B.FixPtSum1 =
      QD2_MissionCtrl_ManualPC_2021_P.NumberofPulses_Y0;

    /* End of SystemInitialize for SubSystem: '<S20>/pulse count ' */
    /* End of SystemInitialize for SubSystem: '<S9>/Pulse Check' */

    /* SystemInitialize for Enabled SubSystem: '<S8>/Enabled Subsystem' */
    /* SystemInitialize for SignalConversion generated from: '<S16>/Pose (m, rad ) [4] ' incorporates:
     *  Outport: '<S16>/Home Pose (m, rad ) [4]'
     */
    QD2_MissionCtrl_ManualPC_2021_B.Posemrad4[0] =
      QD2_MissionCtrl_ManualPC_2021_P.HomePosemrad4_Y0;
    QD2_MissionCtrl_ManualPC_2021_B.Posemrad4[1] =
      QD2_MissionCtrl_ManualPC_2021_P.HomePosemrad4_Y0;
    QD2_MissionCtrl_ManualPC_2021_B.Posemrad4[2] =
      QD2_MissionCtrl_ManualPC_2021_P.HomePosemrad4_Y0;
    QD2_MissionCtrl_ManualPC_2021_B.Posemrad4[3] =
      QD2_MissionCtrl_ManualPC_2021_P.HomePosemrad4_Y0;

    /* End of SystemInitialize for SubSystem: '<S8>/Enabled Subsystem' */

    /* SystemInitialize for MATLAB Function: '<S12>/MATLAB Function' */
    QD2_MissionCtrl_ManualPC_202_DW.State = 0.0;
    QD2_MissionCtrl_ManualPC_202_DW.State_not_empty = true;
    QD2_MissionCtrl_ManualPC_202_DW.sfEvent = QD2_MissionCtrl_Manu_CALL_EVENT;

    /* SystemInitialize for Triggered SubSystem: '<S2>/Triggered Subsystem' */
    /* InitializeConditions for Memory: '<S13>/Memory' */
    QD2_MissionCtrl_ManualPC_202_DW.Memory_PreviousInput =
      QD2_MissionCtrl_ManualPC_2021_P.Memory_InitialCondition;

    /* SystemInitialize for RelationalOperator: '<S43>/Compare' incorporates:
     *  Outport: '<S13>/Communication Issue (0,1)'
     */
    QD2_MissionCtrl_ManualPC_2021_B.Compare_f =
      QD2_MissionCtrl_ManualPC_2021_P.CommunicationIssue01_Y0;

    /* End of SystemInitialize for SubSystem: '<S2>/Triggered Subsystem' */
    /* SystemInitialize for Iterator SubSystem: '<S14>/For Each Subsystem' */
    for (ForEach_itr = 0; ForEach_itr < 2; ForEach_itr++) {
      /* SystemInitialize for Iterator SubSystem: '<S14>/For Each Subsystem' */
      /* InitializeConditions for S-Function (one_shot_block): '<S47>/one_shot_block' */
      {
        QD2_MissionCtrl_ManualPC_202_DW.CoreSubsys_p[ForEach_itr].
          one_shot_block_DSTATE[0] = 0.0;
        QD2_MissionCtrl_ManualPC_202_DW.CoreSubsys_p[ForEach_itr].
          one_shot_block_DSTATE[1] = 0.0;
        QD2_MissionCtrl_ManualPC_202_DW.CoreSubsys_p[ForEach_itr].
          one_shot_block_DSTATE[2] = 0.0;
      }

      /* End of SystemInitialize for SubSystem: '<S14>/For Each Subsystem' */
    }

    /* End of SystemInitialize for SubSystem: '<S14>/For Each Subsystem' */
    /* SystemInitialize for MATLAB Function: '<S5>/MATLAB Function' */
    QD2_MissionCtrl_ManualPC_202_DW.sfEvent_n = QD2_MissionCtrl_Manu_CALL_EVENT;
  }
}

/* Model terminate function */
void QD2_MissionCtrl_ManualPC_2021a_terminate(void)
{
  /* Terminate for S-Function (host_initialize_block): '<S9>/Host Initialize' */

  /* S-Function Block: QD2_MissionCtrl_ManualPC_2021a/MISSION CONTROL QDRONE MANUAL POSITION CONTROL/JOYSTICK_FRSKY/Host Initialize (host_initialize_block) */
  {
    extmode_svr_unregister_custom_action(EXT_MODE_ACTION_HOST_INTERFACE);
    extmode_svr_unregister_connected_callback
      (QD2_MissionCtrl_ManualPC_202_DW.HostInitialize_ConnectedHandle);
  }

  /* Terminate for S-Function (host_game_controller_block): '<S9>/Host Game Controller' */

  /* S-Function Block: QD2_MissionCtrl_ManualPC_2021a/MISSION CONTROL QDRONE MANUAL POSITION CONTROL/JOYSTICK_FRSKY/Host Game Controller (host_game_controller_block) */
  {
    qthread_section_destroy
      (&QD2_MissionCtrl_ManualPC_202_DW.HostGameController_Lock);
  }

  /* Terminate for S-Function (stream_server_block): '<S1>/Stream Server' incorporates:
   *  Constant: '<S1>/Constant'
   */

  /* S-Function Block: QD2_MissionCtrl_ManualPC_2021a/Communication/Stream Server (stream_server_block) */
  {
    if (QD2_MissionCtrl_ManualPC_202_DW.StreamServer_Stream != NULL) {
      pstream_close(QD2_MissionCtrl_ManualPC_202_DW.StreamServer_Stream);
    }

    QD2_MissionCtrl_ManualPC_202_DW.StreamServer_Stream = NULL;
  }

  /* Terminate for S-Function (vrpn_client_block): '<S10>/VRPN Client' */

  /* S-Function Block: QD2_MissionCtrl_ManualPC_2021a/MISSION CONTROL QDRONE MANUAL POSITION CONTROL/Localization Data Server (VRPN) /VRPN Client (vrpn_client_block) */
  {
    t_error result;
    if ((result = vrpn_client_close
         (QD2_MissionCtrl_ManualPC_202_DW.VRPNClient_VRPNClient)) < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(QD2_MissionCtrl_ManualPC_202_M, _rt_error_message);
    }

    QD2_MissionCtrl_ManualPC_202_DW.VRPNClient_VRPNClient = NULL;
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
  QD2_MissionCtrl_ManualPC_2021a_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  QD2_MissionCtrl_ManualPC_2021a_update(tid);
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
  QD2_MissionCtrl_ManualPC_2021a_initialize();
}

void MdlTerminate(void)
{
  QD2_MissionCtrl_ManualPC_2021a_terminate();
}

/* Registration function */
RT_MODEL_QD2_MissionCtrl_Manu_T *QD2_MissionCtrl_ManualPC_2021a(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Saturation_UpperSat = rtInf;
  QD2_MissionCtrl_ManualPC_2021_P.CoreSubsys.Saturation1_UpperSat = rtInf;

  /* initialize real-time model */
  (void) memset((void *)QD2_MissionCtrl_ManualPC_202_M, 0,
                sizeof(RT_MODEL_QD2_MissionCtrl_Manu_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&QD2_MissionCtrl_ManualPC_202_M->solverInfo,
                          &QD2_MissionCtrl_ManualPC_202_M->Timing.simTimeStep);
    rtsiSetTPtr(&QD2_MissionCtrl_ManualPC_202_M->solverInfo, &rtmGetTPtr
                (QD2_MissionCtrl_ManualPC_202_M));
    rtsiSetStepSizePtr(&QD2_MissionCtrl_ManualPC_202_M->solverInfo,
                       &QD2_MissionCtrl_ManualPC_202_M->Timing.stepSize0);
    rtsiSetdXPtr(&QD2_MissionCtrl_ManualPC_202_M->solverInfo,
                 &QD2_MissionCtrl_ManualPC_202_M->derivs);
    rtsiSetContStatesPtr(&QD2_MissionCtrl_ManualPC_202_M->solverInfo, (real_T **)
                         &QD2_MissionCtrl_ManualPC_202_M->contStates);
    rtsiSetNumContStatesPtr(&QD2_MissionCtrl_ManualPC_202_M->solverInfo,
      &QD2_MissionCtrl_ManualPC_202_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&QD2_MissionCtrl_ManualPC_202_M->solverInfo,
      &QD2_MissionCtrl_ManualPC_202_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr
      (&QD2_MissionCtrl_ManualPC_202_M->solverInfo,
       &QD2_MissionCtrl_ManualPC_202_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr
      (&QD2_MissionCtrl_ManualPC_202_M->solverInfo,
       &QD2_MissionCtrl_ManualPC_202_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&QD2_MissionCtrl_ManualPC_202_M->solverInfo,
      (boolean_T**) &QD2_MissionCtrl_ManualPC_202_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&QD2_MissionCtrl_ManualPC_202_M->solverInfo,
                          (&rtmGetErrorStatus(QD2_MissionCtrl_ManualPC_202_M)));
    rtsiSetRTModelPtr(&QD2_MissionCtrl_ManualPC_202_M->solverInfo,
                      QD2_MissionCtrl_ManualPC_202_M);
  }

  rtsiSetSimTimeStep(&QD2_MissionCtrl_ManualPC_202_M->solverInfo,
                     MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange
    (&QD2_MissionCtrl_ManualPC_202_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&QD2_MissionCtrl_ManualPC_202_M->solverInfo, false);
  QD2_MissionCtrl_ManualPC_202_M->intgData.y =
    QD2_MissionCtrl_ManualPC_202_M->odeY;
  QD2_MissionCtrl_ManualPC_202_M->intgData.f[0] =
    QD2_MissionCtrl_ManualPC_202_M->odeF[0];
  QD2_MissionCtrl_ManualPC_202_M->intgData.f[1] =
    QD2_MissionCtrl_ManualPC_202_M->odeF[1];
  QD2_MissionCtrl_ManualPC_202_M->contStates = ((real_T *)
    &QD2_MissionCtrl_ManualPC_2021_X);
  QD2_MissionCtrl_ManualPC_202_M->contStateDisabled = ((boolean_T *)
    &QD2_MissionCtrl_ManualPC_2_XDis);
  QD2_MissionCtrl_ManualPC_202_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&QD2_MissionCtrl_ManualPC_202_M->solverInfo, (void *)
                    &QD2_MissionCtrl_ManualPC_202_M->intgData);
  rtsiSetSolverName(&QD2_MissionCtrl_ManualPC_202_M->solverInfo,"ode2");

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      QD2_MissionCtrl_ManualPC_202_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    QD2_MissionCtrl_ManualPC_202_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    QD2_MissionCtrl_ManualPC_202_M->Timing.sampleTimes =
      (&QD2_MissionCtrl_ManualPC_202_M->Timing.sampleTimesArray[0]);
    QD2_MissionCtrl_ManualPC_202_M->Timing.offsetTimes =
      (&QD2_MissionCtrl_ManualPC_202_M->Timing.offsetTimesArray[0]);

    /* task periods */
    QD2_MissionCtrl_ManualPC_202_M->Timing.sampleTimes[0] = (0.0);
    QD2_MissionCtrl_ManualPC_202_M->Timing.sampleTimes[1] = (0.001);
    QD2_MissionCtrl_ManualPC_202_M->Timing.sampleTimes[2] = (0.016);

    /* task offsets */
    QD2_MissionCtrl_ManualPC_202_M->Timing.offsetTimes[0] = (0.0);
    QD2_MissionCtrl_ManualPC_202_M->Timing.offsetTimes[1] = (0.0);
    QD2_MissionCtrl_ManualPC_202_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(QD2_MissionCtrl_ManualPC_202_M,
             &QD2_MissionCtrl_ManualPC_202_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = QD2_MissionCtrl_ManualPC_202_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      QD2_MissionCtrl_ManualPC_202_M->Timing.perTaskSampleHitsArray;
    QD2_MissionCtrl_ManualPC_202_M->Timing.perTaskSampleHits =
      (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    QD2_MissionCtrl_ManualPC_202_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(QD2_MissionCtrl_ManualPC_202_M, -1);
  QD2_MissionCtrl_ManualPC_202_M->Timing.stepSize0 = 0.001;
  QD2_MissionCtrl_ManualPC_202_M->Timing.stepSize1 = 0.001;
  QD2_MissionCtrl_ManualPC_202_M->Timing.stepSize2 = 0.016;

  /* External mode info */
  QD2_MissionCtrl_ManualPC_202_M->Sizes.checksums[0] = (4134201443U);
  QD2_MissionCtrl_ManualPC_202_M->Sizes.checksums[1] = (566813720U);
  QD2_MissionCtrl_ManualPC_202_M->Sizes.checksums[2] = (2096342655U);
  QD2_MissionCtrl_ManualPC_202_M->Sizes.checksums[3] = (764929163U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[25];
    QD2_MissionCtrl_ManualPC_202_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)
      &QD2_MissionCtrl_ManualPC_202_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = (sysRanDType *)
      &QD2_MissionCtrl_ManualPC_202_DW.FrSKYMapping_SubsysRanBC;
    systemRan[6] = (sysRanDType *)
      &QD2_MissionCtrl_ManualPC_202_DW.InitializationandConditioning_S;
    systemRan[7] = (sysRanDType *)
      &QD2_MissionCtrl_ManualPC_202_DW.pulsecount_SubsysRanBC;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = (sysRanDType *)&QD2_MissionCtrl_ManualPC_202_DW.CoreSubsys[0]
      .q10_SubsysRanBC_h;
    systemRan[10] = (sysRanDType *)&QD2_MissionCtrl_ManualPC_202_DW.CoreSubsys[0]
      .q10_SubsysRanBC;
    systemRan[11] = (sysRanDType *)&QD2_MissionCtrl_ManualPC_202_DW.CoreSubsys[0]
      .q00_SubsysRanBC;
    systemRan[12] = (sysRanDType *)&QD2_MissionCtrl_ManualPC_202_DW.CoreSubsys[0]
      .q00_SubsysRanBC_f;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = &rtAlwaysEnabled;
    systemRan[18] = &rtAlwaysEnabled;
    systemRan[19] = &rtAlwaysEnabled;
    systemRan[20] = &rtAlwaysEnabled;
    systemRan[21] = (sysRanDType *)
      &QD2_MissionCtrl_ManualPC_202_DW.TriggeredSubsystem_SubsysRanBC;
    systemRan[22] = &rtAlwaysEnabled;
    systemRan[23] = &rtAlwaysEnabled;
    systemRan[24] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(QD2_MissionCtrl_ManualPC_202_M->extModeInfo,
      &QD2_MissionCtrl_ManualPC_202_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(QD2_MissionCtrl_ManualPC_202_M->extModeInfo,
                        QD2_MissionCtrl_ManualPC_202_M->Sizes.checksums);
    rteiSetTPtr(QD2_MissionCtrl_ManualPC_202_M->extModeInfo, rtmGetTPtr
                (QD2_MissionCtrl_ManualPC_202_M));
  }

  QD2_MissionCtrl_ManualPC_202_M->solverInfoPtr =
    (&QD2_MissionCtrl_ManualPC_202_M->solverInfo);
  QD2_MissionCtrl_ManualPC_202_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&QD2_MissionCtrl_ManualPC_202_M->solverInfo, 0.001);
  rtsiSetSolverMode(&QD2_MissionCtrl_ManualPC_202_M->solverInfo,
                    SOLVER_MODE_MULTITASKING);

  /* block I/O */
  QD2_MissionCtrl_ManualPC_202_M->blockIO = ((void *)
    &QD2_MissionCtrl_ManualPC_2021_B);
  (void) memset(((void *) &QD2_MissionCtrl_ManualPC_2021_B), 0,
                sizeof(B_QD2_MissionCtrl_ManualPC_20_T));

  /* parameters */
  QD2_MissionCtrl_ManualPC_202_M->defaultParam = ((real_T *)
    &QD2_MissionCtrl_ManualPC_2021_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &QD2_MissionCtrl_ManualPC_2021_X;
    QD2_MissionCtrl_ManualPC_202_M->contStates = (x);
    (void) memset((void *)&QD2_MissionCtrl_ManualPC_2021_X, 0,
                  sizeof(X_QD2_MissionCtrl_ManualPC_20_T));
  }

  /* disabled states */
  {
    boolean_T *xdis = (boolean_T *) &QD2_MissionCtrl_ManualPC_2_XDis;
    QD2_MissionCtrl_ManualPC_202_M->contStateDisabled = (xdis);
    (void) memset((void *)&QD2_MissionCtrl_ManualPC_2_XDis, 0,
                  sizeof(XDis_QD2_MissionCtrl_ManualPC_T));
  }

  /* states (dwork) */
  QD2_MissionCtrl_ManualPC_202_M->dwork = ((void *)
    &QD2_MissionCtrl_ManualPC_202_DW);
  (void) memset((void *)&QD2_MissionCtrl_ManualPC_202_DW, 0,
                sizeof(DW_QD2_MissionCtrl_ManualPC_2_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    QD2_MissionCtrl_ManualPC_202_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 28;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  QD2_MissionCtrl_ManualPC_202_M->Sizes.numContStates = (3);/* Number of continuous states */
  QD2_MissionCtrl_ManualPC_202_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  QD2_MissionCtrl_ManualPC_202_M->Sizes.numY = (0);/* Number of model outputs */
  QD2_MissionCtrl_ManualPC_202_M->Sizes.numU = (0);/* Number of model inputs */
  QD2_MissionCtrl_ManualPC_202_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  QD2_MissionCtrl_ManualPC_202_M->Sizes.numSampTimes = (3);/* Number of sample times */
  QD2_MissionCtrl_ManualPC_202_M->Sizes.numBlocks = (308);/* Number of blocks */
  QD2_MissionCtrl_ManualPC_202_M->Sizes.numBlockIO = (82);/* Number of block outputs */
  QD2_MissionCtrl_ManualPC_202_M->Sizes.numBlockPrms = (325);/* Sum of parameter "widths" */
  return QD2_MissionCtrl_ManualPC_202_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
