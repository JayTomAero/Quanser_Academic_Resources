/*
 * QD2_MissionCtrl_Manual_2021a.c
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

#include "QD2_MissionCtrl_Manual_2021a.h"
#include "rtwtypes.h"
#include "QD2_MissionCtrl_Manual_2021a_private.h"
#include "zero_crossing_types.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "QD2_MissionCtrl_Manual_2021a_dt.h"

/* Named constants for MATLAB Function: '<S5>/MATLAB Function' */
#define QD2_MissionCtrl_Manu_CALL_EVENT (-1)

/* Block signals (default storage) */
B_QD2_MissionCtrl_Manual_2021_T QD2_MissionCtrl_Manual_2021a_B;

/* Block states (default storage) */
DW_QD2_MissionCtrl_Manual_202_T QD2_MissionCtrl_Manual_2021a_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_QD2_MissionCtrl_Manua_T QD2_MissionCtrl_Manual__PrevZCX;

/* Real-time model */
static RT_MODEL_QD2_MissionCtrl_Manu_T QD2_MissionCtrl_Manual_2021a_M_;
RT_MODEL_QD2_MissionCtrl_Manu_T *const QD2_MissionCtrl_Manual_2021a_M =
  &QD2_MissionCtrl_Manual_2021a_M_;

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
  /* S-Function Block: QD2_MissionCtrl_Manual_2021a/MISSION CONTROL QDRONE MANUAL FLIGHT/JOYSTICK_FRSKY/Host Game Controller (host_game_controller_block) */
  {
    if (QD2_MissionCtrl_Manual_2021a_P.HostGameController_Enabled) {

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
        QD2_MissionCtrl_Manual_2021a_P.HostGameController_BufferSize;
      game_controller_configuration.configuration.controller_number =
        QD2_MissionCtrl_Manual_2021a_P.HostGameController_Controller;
      game_controller_configuration.configuration.auto_center =
        QD2_MissionCtrl_Manual_2021a_P.HostGameController_AutoCenter;
      game_controller_configuration.configuration.debug_mode =
        QD2_MissionCtrl_Manual_2021a_P.HostGameController_DebugMode;
      result = host_send_extmode_packet(NULL, &game_controller_configuration,
        sizeof(game_controller_configuration));
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(QD2_MissionCtrl_Manual_2021a_M, _rt_error_message);
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
      /* S-Function Block: QD2_MissionCtrl_Manual_2021a/MISSION CONTROL QDRONE MANUAL FLIGHT/JOYSTICK_FRSKY/Host Game Controller (host_game_controller_block) */
      {
        t_game_controller_states * state = (t_game_controller_states *) (buffer);
        if (buffer_size >= sizeof(t_game_controller_states)) {
          t_error result = qthread_section_lock
            (&QD2_MissionCtrl_Manual_2021a_DW.HostGameController_Lock);
          if (result == 0) {
            memory_copy
              (&QD2_MissionCtrl_Manual_2021a_DW.HostGameController_ControllerSt,
               sizeof
               (*&QD2_MissionCtrl_Manual_2021a_DW.HostGameController_ControllerSt),
               state);
            QD2_MissionCtrl_Manual_2021a_DW.HostGameController_NewData = true;
            qthread_section_unlock
              (&QD2_MissionCtrl_Manual_2021a_DW.HostGameController_Lock);
          }
        } else {
          rtmSetErrorStatus(QD2_MissionCtrl_Manual_2021a_M,
                            "A Host Game Controller block has received an invalid packet from the host!");
        }
      }
      break;

     default:
      rtmSetErrorStatus(QD2_MissionCtrl_Manual_2021a_M,
                        "Invalid peripheral identifier received");
      break;
    }
  }

  return 0;
}

/* Model output function */
void QD2_MissionCtrl_Manual_2021a_output(void)
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
  int32_T rtb_StreamServer_o2;
  uint8_T rtb_StreamServer_o1;
  boolean_T rtb_HostGameController_o2[32];
  real_T rtb_TmpSignalConversionAtStream[11];
  real_T ManualSwitch1;
  real_T rtb_Time_k;
  int32_T i;
  boolean_T rtb_Relation;
  boolean_T rtb_RelationalOperator;
  boolean_T rtb_RelationalOperator_d;
  boolean_T tmp;
  ZCEventType zcEvent;

  /* Reset subsysRan breadcrumbs */
  srClearBC(QD2_MissionCtrl_Manual_2021a_DW.FrSKYMapping_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(QD2_MissionCtrl_Manual_2021a_DW.InitializationandConditioning_S);

  /* Reset subsysRan breadcrumbs */
  srClearBC(QD2_MissionCtrl_Manual_2021a_DW.pulsecount_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(QD2_MissionCtrl_Manual_2021a_DW.TriggeredSubsystem_SubsysRanBC);

  /* S-Function (host_initialize_block): '<S8>/Host Initialize' */

  /* S-Function Block: QD2_MissionCtrl_Manual_2021a/MISSION CONTROL QDRONE MANUAL FLIGHT/JOYSTICK_FRSKY/Host Initialize (host_initialize_block) */
  {
    QD2_MissionCtrl_Manual_2021a_B.HostInitialize_o1 =
      (rtExtModeQuarcIsConnected() ? HOST_STATE_CONNECTED :
       HOST_STATE_NOT_CONNECTED);
  }

  /* S-Function (host_game_controller_block): '<S8>/Host Game Controller' */

  /* S-Function Block: QD2_MissionCtrl_Manual_2021a/MISSION CONTROL QDRONE MANUAL FLIGHT/JOYSTICK_FRSKY/Host Game Controller (host_game_controller_block) */
  {
    if (QD2_MissionCtrl_Manual_2021a_P.HostGameController_Enabled) {
      t_error result = qthread_section_lock
        (&QD2_MissionCtrl_Manual_2021a_DW.HostGameController_Lock);
      if (result == 0) {
        {
          int_T i1;
          boolean_T *y1 = &rtb_HostGameController_o2[0];
          for (i1=0; i1 < 32; i1++) {
            y1[i1] =
              ((QD2_MissionCtrl_Manual_2021a_DW.HostGameController_ControllerSt.buttons
                & (1U << i1)) != 0);
          }
        }

        rtb_HostGameController_o3[0] =
          QD2_MissionCtrl_Manual_2021a_DW.HostGameController_ControllerSt.sliders
          [0];
        rtb_HostGameController_o3[1] =
          QD2_MissionCtrl_Manual_2021a_DW.HostGameController_ControllerSt.sliders
          [1];
        rtb_HostGameController_o4 =
          QD2_MissionCtrl_Manual_2021a_DW.HostGameController_ControllerSt.x;
        rtb_HostGameController_o5 =
          QD2_MissionCtrl_Manual_2021a_DW.HostGameController_ControllerSt.y;
        rtb_HostGameController_o6 =
          QD2_MissionCtrl_Manual_2021a_DW.HostGameController_ControllerSt.z;
        rtb_HostGameController_o7 =
          QD2_MissionCtrl_Manual_2021a_DW.HostGameController_ControllerSt.rx;
        rtb_Time_k =
          QD2_MissionCtrl_Manual_2021a_DW.HostGameController_ControllerSt.ry;
        rtb_HostGameController_o9 =
          QD2_MissionCtrl_Manual_2021a_DW.HostGameController_ControllerSt.rz;
        QD2_MissionCtrl_Manual_2021a_B.HostGameController_o1 =
          QD2_MissionCtrl_Manual_2021a_DW.HostGameController_NewData;
        QD2_MissionCtrl_Manual_2021a_DW.HostGameController_NewData = false;
        qthread_section_unlock
          (&QD2_MissionCtrl_Manual_2021a_DW.HostGameController_Lock);
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
        rtb_Time_k = 0;
        rtb_HostGameController_o9 = 0;
        QD2_MissionCtrl_Manual_2021a_B.HostGameController_o1 = false;
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
      rtb_Time_k = 0;
      rtb_HostGameController_o9 = 0;
      QD2_MissionCtrl_Manual_2021a_B.HostGameController_o1 = false;
    }
  }

  /* SignalConversion generated from: '<S8>/Compare' */
  rtb_TmpSignalConversionAtCompar[0] = rtb_HostGameController_o4;
  rtb_TmpSignalConversionAtCompar[1] = rtb_HostGameController_o5;
  rtb_TmpSignalConversionAtCompar[2] = rtb_HostGameController_o6;
  rtb_TmpSignalConversionAtCompar[3] = rtb_HostGameController_o7;
  rtb_TmpSignalConversionAtCompar[4] = rtb_Time_k;
  rtb_TmpSignalConversionAtCompar[5] = rtb_HostGameController_o9;

  /* Logic: '<S8>/AND' incorporates:
   *  Constant: '<S8>/Constant'
   *  S-Function (compare_block): '<S8>/Compare'
   *  SignalConversion generated from: '<S8>/Compare'
   */
  rtb_Relation = (rtb_TmpSignalConversionAtCompar[0] ==
                  QD2_MissionCtrl_Manual_2021a_P.Constant_Value_m[0]);
  for (i = 0; i < 5; i++) {
    rtb_Relation = (rtb_Relation && (rtb_TmpSignalConversionAtCompar[i + 1] ==
      QD2_MissionCtrl_Manual_2021a_P.Constant_Value_m[i + 1]));
  }

  /* RelationalOperator: '<S14>/Relation' incorporates:
   *  Constant: '<S14>/threshold'
   *  Logic: '<S8>/AND'
   */
  rtb_Relation = ((real_T)rtb_Relation >=
                  QD2_MissionCtrl_Manual_2021a_P.Threshold_threshold_h);

  /* Logic: '<S14>/Logical Operator' */
  QD2_MissionCtrl_Manual_2021a_B.LogicalOperator = !rtb_Relation;

  /* DiscreteIntegrator: '<S14>/Discrete-Time Integrator' */
  if (QD2_MissionCtrl_Manual_2021a_B.LogicalOperator ||
      (QD2_MissionCtrl_Manual_2021a_DW.DiscreteTimeIntegrator_PrevRese != 0)) {
    QD2_MissionCtrl_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE =
      QD2_MissionCtrl_Manual_2021a_P.DiscreteTimeIntegrator_IC_m;
  }

  /* RelationalOperator: '<S14>/Relational Operator' incorporates:
   *  Constant: '<S14>/duration'
   *  DiscreteIntegrator: '<S14>/Discrete-Time Integrator'
   */
  rtb_RelationalOperator =
    (QD2_MissionCtrl_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE >=
     QD2_MissionCtrl_Manual_2021a_P.Threshold_duration_d);

  /* Outputs for Enabled SubSystem: '<S8>/Initialization and Conditioning' incorporates:
   *  EnablePort: '<S12>/Enable'
   */
  /* Logic: '<S8>/NOT' incorporates:
   *  Logic: '<S12>/Logical Operator'
   */
  tmp = !rtb_RelationalOperator;

  /* End of Outputs for SubSystem: '<S8>/Initialization and Conditioning' */

  /* Outputs for Enabled SubSystem: '<S8>/FrSKYMapping' incorporates:
   *  EnablePort: '<S11>/Valid Signals Detected'
   */
  if (tmp) {
    QD2_MissionCtrl_Manual_2021a_DW.FrSKYMapping_MODE = true;
    for (i = 0; i < 32; i++) {
      /* SignalConversion generated from: '<S11>/Buttons' */
      QD2_MissionCtrl_Manual_2021a_B.Buttons[i] = rtb_HostGameController_o2[i];
    }

    /* RelationalOperator: '<S16>/Relation' incorporates:
     *  Constant: '<S16>/threshold'
     */
    rtb_RelationalOperator_d = ((real_T)QD2_MissionCtrl_Manual_2021a_B.Buttons[0]
      >= QD2_MissionCtrl_Manual_2021a_P.Threshold_threshold);

    /* DataTypeConversion: '<S16>/Data Type Conversion' */
    QD2_MissionCtrl_Manual_2021a_B.DataTypeConversion_k =
      rtb_RelationalOperator_d;

    /* Logic: '<S16>/Logical Operator' */
    QD2_MissionCtrl_Manual_2021a_B.LogicalOperator_n = !rtb_RelationalOperator_d;

    /* DiscreteIntegrator: '<S16>/Discrete-Time Integrator' */
    if (QD2_MissionCtrl_Manual_2021a_B.LogicalOperator_n ||
        (QD2_MissionCtrl_Manual_2021a_DW.DiscreteTimeIntegrator_PrevR_bf != 0))
    {
      QD2_MissionCtrl_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE_a =
        QD2_MissionCtrl_Manual_2021a_P.DiscreteTimeIntegrator_IC;
    }

    /* DiscreteIntegrator: '<S16>/Discrete-Time Integrator' */
    QD2_MissionCtrl_Manual_2021a_B.DiscreteTimeIntegrator =
      QD2_MissionCtrl_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE_a;

    /* RelationalOperator: '<S16>/Relational Operator' incorporates:
     *  Constant: '<S16>/duration'
     */
    QD2_MissionCtrl_Manual_2021a_B.RelationalOperator =
      (QD2_MissionCtrl_Manual_2021a_B.DiscreteTimeIntegrator >=
       QD2_MissionCtrl_Manual_2021a_P.Threshold_duration);

    /* Gain: '<S11>/Gain' */
    QD2_MissionCtrl_Manual_2021a_B.Gain =
      QD2_MissionCtrl_Manual_2021a_P.Gain_Gain * rtb_HostGameController_o7;

    /* Bias: '<S11>/Bias' incorporates:
     *  Gain: '<S11>/Gain1'
     */
    QD2_MissionCtrl_Manual_2021a_B.Bias =
      QD2_MissionCtrl_Manual_2021a_P.Gain1_Gain * rtb_HostGameController_o4 +
      QD2_MissionCtrl_Manual_2021a_P.Bias_Bias;

    /* SignalConversion generated from: '<S11>/y' */
    QD2_MissionCtrl_Manual_2021a_B.y = rtb_HostGameController_o5;

    /* SignalConversion generated from: '<S11>/z' */
    QD2_MissionCtrl_Manual_2021a_B.z = rtb_HostGameController_o6;

    /* RelationalOperator: '<S15>/Compare' incorporates:
     *  Constant: '<S15>/Constant'
     */
    QD2_MissionCtrl_Manual_2021a_B.Compare_h = (rtb_HostGameController_o9 >=
      QD2_MissionCtrl_Manual_2021a_P.CompareToConstant_const);
    srUpdateBC(QD2_MissionCtrl_Manual_2021a_DW.FrSKYMapping_SubsysRanBC);
  } else if (QD2_MissionCtrl_Manual_2021a_DW.FrSKYMapping_MODE) {
    /* Disable for DiscreteIntegrator: '<S16>/Discrete-Time Integrator' */
    QD2_MissionCtrl_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE_a =
      QD2_MissionCtrl_Manual_2021a_B.DiscreteTimeIntegrator;
    QD2_MissionCtrl_Manual_2021a_DW.FrSKYMapping_MODE = false;
  }

  /* End of Logic: '<S8>/NOT' */
  /* End of Outputs for SubSystem: '<S8>/FrSKYMapping' */

  /* Outputs for Atomic SubSystem: '<S8>/Pulse Check' */
  /* Outputs for Triggered SubSystem: '<S13>/pulse count ' incorporates:
   *  TriggerPort: '<S17>/Trigger'
   */
  if (QD2_MissionCtrl_Manual_2021a_B.HostGameController_o1 &&
      (QD2_MissionCtrl_Manual__PrevZCX.pulsecount_Trig_ZCE != POS_ZCSIG)) {
    /* Sum: '<S18>/FixPt Sum1' incorporates:
     *  Constant: '<S17>/Constant1'
     *  Constant: '<S18>/FixPt Constant'
     *  Sum: '<S17>/Sum'
     *  UnitDelay: '<S17>/Unit Delay'
     */
    QD2_MissionCtrl_Manual_2021a_B.FixPtSum1 =
      (QD2_MissionCtrl_Manual_2021a_P.Constant1_Value +
       QD2_MissionCtrl_Manual_2021a_DW.UnitDelay_DSTATE) +
      QD2_MissionCtrl_Manual_2021a_P.FixPtConstant_Value;

    /* Update for UnitDelay: '<S17>/Unit Delay' */
    QD2_MissionCtrl_Manual_2021a_DW.UnitDelay_DSTATE =
      QD2_MissionCtrl_Manual_2021a_B.FixPtSum1;
    QD2_MissionCtrl_Manual_2021a_DW.pulsecount_SubsysRanBC = 4;
  }

  QD2_MissionCtrl_Manual__PrevZCX.pulsecount_Trig_ZCE =
    QD2_MissionCtrl_Manual_2021a_B.HostGameController_o1;

  /* End of Outputs for SubSystem: '<S13>/pulse count ' */

  /* S-Function (compare_block): '<S13>/Compare' incorporates:
   *  Constant: '<S13>/Pulse Check'
   */
  {
    QD2_MissionCtrl_Manual_2021a_B.Compare_n =
      (QD2_MissionCtrl_Manual_2021a_B.FixPtSum1 >=
       QD2_MissionCtrl_Manual_2021a_P.PulseCheck_Value);
  }

  /* End of Outputs for SubSystem: '<S8>/Pulse Check' */

  /* Outputs for Enabled SubSystem: '<S8>/Initialization and Conditioning' incorporates:
   *  EnablePort: '<S12>/Enable'
   */
  if (QD2_MissionCtrl_Manual_2021a_B.Compare_n) {
    /* DataTypeConversion: '<S12>/Data Type Conversion2' */
    QD2_MissionCtrl_Manual_2021a_B.DataTypeConversion2 =
      QD2_MissionCtrl_Manual_2021a_B.RelationalOperator;

    /* DataTypeConversion: '<S12>/Data Type Conversion4' */
    QD2_MissionCtrl_Manual_2021a_B.DataTypeConversion4 = rtb_RelationalOperator;

    /* DataTypeConversion: '<S12>/Data Type Conversion6' */
    rtb_Time_k = tmp;

    /* SignalConversion generated from: '<S12>/Joystick Issue (0,1)' */
    QD2_MissionCtrl_Manual_2021a_B.OutportBufferForJoystickIssue01 =
      QD2_MissionCtrl_Manual_2021a_B.DataTypeConversion4;

    /* DeadZone: '<S12>/Dead Zone' */
    if (QD2_MissionCtrl_Manual_2021a_B.y >
        QD2_MissionCtrl_Manual_2021a_P.DeadZone_End) {
      ManualSwitch1 = QD2_MissionCtrl_Manual_2021a_B.y -
        QD2_MissionCtrl_Manual_2021a_P.DeadZone_End;
    } else if (QD2_MissionCtrl_Manual_2021a_B.y >=
               QD2_MissionCtrl_Manual_2021a_P.DeadZone_Start) {
      ManualSwitch1 = 0.0;
    } else {
      ManualSwitch1 = QD2_MissionCtrl_Manual_2021a_B.y -
        QD2_MissionCtrl_Manual_2021a_P.DeadZone_Start;
    }

    /* Product: '<S12>/Product' incorporates:
     *  DeadZone: '<S12>/Dead Zone'
     */
    QD2_MissionCtrl_Manual_2021a_B.Product_b[0] = rtb_Time_k * ManualSwitch1;

    /* DeadZone: '<S12>/Dead Zone' */
    if (QD2_MissionCtrl_Manual_2021a_B.z >
        QD2_MissionCtrl_Manual_2021a_P.DeadZone_End) {
      ManualSwitch1 = QD2_MissionCtrl_Manual_2021a_B.z -
        QD2_MissionCtrl_Manual_2021a_P.DeadZone_End;
    } else if (QD2_MissionCtrl_Manual_2021a_B.z >=
               QD2_MissionCtrl_Manual_2021a_P.DeadZone_Start) {
      ManualSwitch1 = 0.0;
    } else {
      ManualSwitch1 = QD2_MissionCtrl_Manual_2021a_B.z -
        QD2_MissionCtrl_Manual_2021a_P.DeadZone_Start;
    }

    /* Product: '<S12>/Product' incorporates:
     *  DeadZone: '<S12>/Dead Zone'
     */
    QD2_MissionCtrl_Manual_2021a_B.Product_b[1] = rtb_Time_k * ManualSwitch1;

    /* DeadZone: '<S12>/Dead Zone' */
    if (QD2_MissionCtrl_Manual_2021a_B.Gain >
        QD2_MissionCtrl_Manual_2021a_P.DeadZone_End) {
      ManualSwitch1 = QD2_MissionCtrl_Manual_2021a_B.Gain -
        QD2_MissionCtrl_Manual_2021a_P.DeadZone_End;
    } else if (QD2_MissionCtrl_Manual_2021a_B.Gain >=
               QD2_MissionCtrl_Manual_2021a_P.DeadZone_Start) {
      ManualSwitch1 = 0.0;
    } else {
      ManualSwitch1 = QD2_MissionCtrl_Manual_2021a_B.Gain -
        QD2_MissionCtrl_Manual_2021a_P.DeadZone_Start;
    }

    /* Product: '<S12>/Product' incorporates:
     *  DeadZone: '<S12>/Dead Zone'
     */
    QD2_MissionCtrl_Manual_2021a_B.Product_b[2] = rtb_Time_k * ManualSwitch1;

    /* Product: '<S12>/Product1' */
    QD2_MissionCtrl_Manual_2021a_B.Product1 = rtb_Time_k *
      QD2_MissionCtrl_Manual_2021a_B.Bias;

    /* Product: '<S12>/Product2' incorporates:
     *  DataTypeConversion: '<S12>/Data Type Conversion5'
     */
    QD2_MissionCtrl_Manual_2021a_B.Product2 = rtb_Time_k * (real_T)
      QD2_MissionCtrl_Manual_2021a_B.Buttons[1];

    /* Product: '<S12>/Product3' incorporates:
     *  DataTypeConversion: '<S12>/Data Type Conversion7'
     */
    QD2_MissionCtrl_Manual_2021a_B.Product3 = rtb_Time_k * (real_T)
      QD2_MissionCtrl_Manual_2021a_B.Compare_h;
    srUpdateBC(QD2_MissionCtrl_Manual_2021a_DW.InitializationandConditioning_S);
  }

  /* End of Outputs for SubSystem: '<S8>/Initialization and Conditioning' */

  /* DataTypeConversion: '<S14>/Data Type Conversion' */
  QD2_MissionCtrl_Manual_2021a_B.DataTypeConversion = rtb_Relation;

  /* S-Function (time_block): '<S5>/Time' */

  /* S-Function Block: QD2_MissionCtrl_Manual_2021a/Communication/Detect Communication loss/Time (time_block) */
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
      rtmSetErrorStatus(QD2_MissionCtrl_Manual_2021a_M, _rt_error_message);
      return;
    }
  }

  /* ManualSwitch: '<S2>/Manual Switch1' */
  if (QD2_MissionCtrl_Manual_2021a_P.ManualSwitch1_CurrentSetting == 1) {
    /* ManualSwitch: '<S2>/Manual Switch1' */
    QD2_MissionCtrl_Manual_2021a_B.ManualSwitch1[0] =
      QD2_MissionCtrl_Manual_2021a_B.Product2;
    QD2_MissionCtrl_Manual_2021a_B.ManualSwitch1[1] =
      QD2_MissionCtrl_Manual_2021a_B.Product3;
    QD2_MissionCtrl_Manual_2021a_B.ManualSwitch1[2] =
      QD2_MissionCtrl_Manual_2021a_B.DataTypeConversion2;
    QD2_MissionCtrl_Manual_2021a_B.ManualSwitch1[3] =
      QD2_MissionCtrl_Manual_2021a_B.DataTypeConversion4;
    QD2_MissionCtrl_Manual_2021a_B.ManualSwitch1[4] =
      QD2_MissionCtrl_Manual_2021a_B.OutportBufferForJoystickIssue01;
    QD2_MissionCtrl_Manual_2021a_B.ManualSwitch1[5] =
      QD2_MissionCtrl_Manual_2021a_B.Product1;
    ManualSwitch1 = QD2_MissionCtrl_Manual_2021a_B.Product_b[0];
  } else {
    /* ManualSwitch: '<S2>/Manual Switch1' */
    QD2_MissionCtrl_Manual_2021a_B.ManualSwitch1[0] = 0.0;
    QD2_MissionCtrl_Manual_2021a_B.ManualSwitch1[1] = 0.0;
    QD2_MissionCtrl_Manual_2021a_B.ManualSwitch1[2] = 0.0;
    QD2_MissionCtrl_Manual_2021a_B.ManualSwitch1[3] = 0.0;
    QD2_MissionCtrl_Manual_2021a_B.ManualSwitch1[4] = 0.0;
    QD2_MissionCtrl_Manual_2021a_B.ManualSwitch1[5] = 0.0;
    ManualSwitch1 = 0.0;
  }

  /* Gain: '<S9>/Max Thrust is 20.44 N' */
  QD2_MissionCtrl_Manual_2021a_B.MaxThrustis2044N =
    QD2_MissionCtrl_Manual_2021a_P.MaxThrustis2044N_Gain *
    QD2_MissionCtrl_Manual_2021a_B.ManualSwitch1[5];

  /* ManualSwitch: '<S2>/Manual Switch1' */
  QD2_MissionCtrl_Manual_2021a_B.ManualSwitch1[6] = ManualSwitch1;

  /* Gain: '<S9>/+//- 1.0915 Nm for Roll +//- 0.8984 Nm for Pitch +//- 0.0984 Nm for Yaw' */
  QD2_MissionCtrl_Manual_2021a_B.u0915NmforRoll08984NmforPitch00[0] =
    QD2_MissionCtrl_Manual_2021a_P.u0915NmforRoll08984NmforPitch00[0] *
    ManualSwitch1;

  /* Gain: '<S9>/+//- pi//4 rad for Roll//Pitch +//- pi//2 rad//s for Yaw Rate' */
  QD2_MissionCtrl_Manual_2021a_B.pi4radforRollPitchpi2radsforYaw[0] =
    QD2_MissionCtrl_Manual_2021a_P.pi4radforRollPitchpi2radsforYaw[0] *
    ManualSwitch1;

  /* ManualSwitch: '<S2>/Manual Switch1' */
  if (QD2_MissionCtrl_Manual_2021a_P.ManualSwitch1_CurrentSetting == 1) {
    /* ManualSwitch: '<S2>/Manual Switch1' */
    ManualSwitch1 = QD2_MissionCtrl_Manual_2021a_B.Product_b[1];
  } else {
    /* ManualSwitch: '<S2>/Manual Switch1' */
    ManualSwitch1 = 0.0;
  }

  /* ManualSwitch: '<S2>/Manual Switch1' */
  QD2_MissionCtrl_Manual_2021a_B.ManualSwitch1[7] = ManualSwitch1;

  /* Gain: '<S9>/+//- 1.0915 Nm for Roll +//- 0.8984 Nm for Pitch +//- 0.0984 Nm for Yaw' */
  QD2_MissionCtrl_Manual_2021a_B.u0915NmforRoll08984NmforPitch00[1] =
    QD2_MissionCtrl_Manual_2021a_P.u0915NmforRoll08984NmforPitch00[1] *
    ManualSwitch1;

  /* Gain: '<S9>/+//- pi//4 rad for Roll//Pitch +//- pi//2 rad//s for Yaw Rate' */
  QD2_MissionCtrl_Manual_2021a_B.pi4radforRollPitchpi2radsforYaw[1] =
    QD2_MissionCtrl_Manual_2021a_P.pi4radforRollPitchpi2radsforYaw[1] *
    ManualSwitch1;

  /* ManualSwitch: '<S2>/Manual Switch1' */
  if (QD2_MissionCtrl_Manual_2021a_P.ManualSwitch1_CurrentSetting == 1) {
    /* ManualSwitch: '<S2>/Manual Switch1' */
    ManualSwitch1 = QD2_MissionCtrl_Manual_2021a_B.Product_b[2];
  } else {
    /* ManualSwitch: '<S2>/Manual Switch1' */
    ManualSwitch1 = 0.0;
  }

  /* ManualSwitch: '<S2>/Manual Switch1' */
  QD2_MissionCtrl_Manual_2021a_B.ManualSwitch1[8] = ManualSwitch1;

  /* Gain: '<S9>/+//- 1.0915 Nm for Roll +//- 0.8984 Nm for Pitch +//- 0.0984 Nm for Yaw' */
  QD2_MissionCtrl_Manual_2021a_B.u0915NmforRoll08984NmforPitch00[2] =
    QD2_MissionCtrl_Manual_2021a_P.u0915NmforRoll08984NmforPitch00[2] *
    ManualSwitch1;

  /* Gain: '<S9>/+//- pi//4 rad for Roll//Pitch +//- pi//2 rad//s for Yaw Rate' */
  QD2_MissionCtrl_Manual_2021a_B.pi4radforRollPitchpi2radsforYaw[2] =
    QD2_MissionCtrl_Manual_2021a_P.pi4radforRollPitchpi2radsforYaw[2] *
    ManualSwitch1;

  /* S-Function (time_block): '<S2>/Time' */

  /* S-Function Block: QD2_MissionCtrl_Manual_2021a/MISSION CONTROL QDRONE MANUAL FLIGHT/Time (time_block) */
  {
    t_error result;
    t_timeout current_time;
    t_timeout time_difference;
    result = timeout_get_high_resolution_time(&current_time);
    if (result == 0) {
      result = timeout_subtract(&time_difference, &current_time,
        &_high_resolution_start_time);
      rtb_Time_k = time_difference.seconds + time_difference.nanoseconds * 1e-9;
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(QD2_MissionCtrl_Manual_2021a_M, _rt_error_message);
      return;
    }
  }

  /* SignalConversion generated from: '<S1>/Stream Server' incorporates:
   *  Constant: '<S2>/Manual Flight Mode 1 - Torque Mode,   0 - Angle Mode'
   */
  rtb_TmpSignalConversionAtStream[0] =
    QD2_MissionCtrl_Manual_2021a_P.ManualFlightMode1TorqueMode0Ang;
  rtb_TmpSignalConversionAtStream[1] =
    QD2_MissionCtrl_Manual_2021a_B.ManualSwitch1[2];
  rtb_TmpSignalConversionAtStream[2] =
    QD2_MissionCtrl_Manual_2021a_B.MaxThrustis2044N;
  rtb_TmpSignalConversionAtStream[3] =
    QD2_MissionCtrl_Manual_2021a_B.u0915NmforRoll08984NmforPitch00[0];
  rtb_TmpSignalConversionAtStream[6] =
    QD2_MissionCtrl_Manual_2021a_B.pi4radforRollPitchpi2radsforYaw[0];
  rtb_TmpSignalConversionAtStream[4] =
    QD2_MissionCtrl_Manual_2021a_B.u0915NmforRoll08984NmforPitch00[1];
  rtb_TmpSignalConversionAtStream[7] =
    QD2_MissionCtrl_Manual_2021a_B.pi4radforRollPitchpi2radsforYaw[1];
  rtb_TmpSignalConversionAtStream[5] =
    QD2_MissionCtrl_Manual_2021a_B.u0915NmforRoll08984NmforPitch00[2];
  rtb_TmpSignalConversionAtStream[8] =
    QD2_MissionCtrl_Manual_2021a_B.pi4radforRollPitchpi2radsforYaw[2];
  rtb_TmpSignalConversionAtStream[9] =
    QD2_MissionCtrl_Manual_2021a_B.ManualSwitch1[0];
  rtb_TmpSignalConversionAtStream[10] = rtb_Time_k;

  /* S-Function (stream_server_block): '<S1>/Stream Server' incorporates:
   *  Constant: '<S1>/Constant'
   */

  /* S-Function Block: QD2_MissionCtrl_Manual_2021a/Communication/Stream Server (stream_server_block) */
  {
    t_pstream_state state;
    t_error send_result;
    t_error receive_result;
    if (!QD2_MissionCtrl_Manual_2021a_DW.StreamServer_Listening) {
      t_pstream_options options;
      t_error result;
      qthread_attr_t send_thread_attributes;
      qthread_attr_t receive_thread_attributes;
      struct qsched_param scheduling_parameters;
      int min_priority = qsched_get_priority_min(QSCHED_FIFO);
      int max_priority = qsched_get_priority_max(QSCHED_FIFO);
      result = 0;
      options.size = sizeof(options);
      options.flags = QD2_MissionCtrl_Manual_2021a_P.StreamServer_Endian &
        PSTREAM_FLAG_ENDIAN_MASK;
      if (QD2_MissionCtrl_Manual_2021a_P.StreamServer_Implementation ==
          STREAM_SERVER_IMPLEMENTATION_THREAD) {
        options.flags |= PSTREAM_FLAG_MULTITHREADED;
      }

      if (QD2_MissionCtrl_Manual_2021a_P.StreamServer_Optimize ==
          STREAM_SERVER_OPTIMIZE_LATENCY) {
        options.flags |= PSTREAM_FLAG_MINIMIZE_LATENCY;
      }

      options.flags |= PSTREAM_FLAG_SEND_MOST_RECENT;
      options.flags |= PSTREAM_FLAG_RECEIVE_MOST_RECENT;
      options.send_unit_size = 8;
      options.num_send_units = 11;
      options.send_buffer_size =
        QD2_MissionCtrl_Manual_2021a_P.StreamServer_SndSize;
      options.send_fifo_size =
        QD2_MissionCtrl_Manual_2021a_P.StreamServer_SndFIFO;
      options.num_send_dimensions = 0;
      options.max_send_dimensions = NULL;
      if (QD2_MissionCtrl_Manual_2021a_P.StreamServer_SndPriority < min_priority)
      {
        scheduling_parameters.sched_priority = min_priority;
      } else if (QD2_MissionCtrl_Manual_2021a_P.StreamServer_SndPriority >
                 max_priority) {
        scheduling_parameters.sched_priority = max_priority;
      } else {
        scheduling_parameters.sched_priority =
          QD2_MissionCtrl_Manual_2021a_P.StreamServer_SndPriority;
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
            rtmSetErrorStatus(QD2_MissionCtrl_Manual_2021a_M,
                              "Unable to set scheduling inheritance for Stream Client sending thread");
          }
        } else {
          rtmSetErrorStatus(QD2_MissionCtrl_Manual_2021a_M,
                            "The specified thread priority for the Stream Client sending thread is not valid for this target");
        }
      } else {
        rtmSetErrorStatus(QD2_MissionCtrl_Manual_2021a_M,
                          "Unable to set scheduling policy for Stream Client sending thread");
      }

      options.send_thread_attributes = &send_thread_attributes;
      options.receive_unit_size = 8;
      options.num_receive_units = 2;
      options.receive_buffer_size =
        QD2_MissionCtrl_Manual_2021a_P.StreamServer_RcvSize;
      options.receive_fifo_size =
        QD2_MissionCtrl_Manual_2021a_P.StreamServer_RcvFIFO;
      options.num_receive_dimensions = 0;
      options.max_receive_dimensions = NULL;
      if (QD2_MissionCtrl_Manual_2021a_P.StreamServer_RcvPriority < min_priority)
      {
        scheduling_parameters.sched_priority = min_priority;
      } else if (QD2_MissionCtrl_Manual_2021a_P.StreamServer_RcvPriority >
                 max_priority) {
        scheduling_parameters.sched_priority = max_priority;
      } else {
        scheduling_parameters.sched_priority =
          QD2_MissionCtrl_Manual_2021a_P.StreamServer_RcvPriority;
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
              rtmSetErrorStatus(QD2_MissionCtrl_Manual_2021a_M,
                                "Unable to set scheduling inheritance for Stream Client receiving thread");
            }
          } else {
            rtmSetErrorStatus(QD2_MissionCtrl_Manual_2021a_M,
                              "The specified thread priority for the Stream Client receiving thread is not valid for this target");
          }
        } else {
          rtmSetErrorStatus(QD2_MissionCtrl_Manual_2021a_M,
                            "Unable to set scheduling policy for Stream Client receiving thread");
        }
      }

      options.receive_thread_attributes = &receive_thread_attributes;
      if (result == 0) {
        /* Make sure URI is null-terminated */
        if (string_length((char *)
                          &QD2_MissionCtrl_Manual_2021a_B.ModelArgument[0], 80) ==
            80) {
          rtmSetErrorStatus(QD2_MissionCtrl_Manual_2021a_M,
                            "URI passed to Stream Server block is not null-terminated!");
          result = -QERR_STRING_NOT_TERMINATED;
        } else {
          result = pstream_listen((char *)
            &QD2_MissionCtrl_Manual_2021a_B.ModelArgument[0], &options,
            &QD2_MissionCtrl_Manual_2021a_DW.StreamServer_Stream);
          if (result < 0 && result != -QERR_WOULD_BLOCK) {
            msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
              (_rt_error_message));
            rtmSetErrorStatus(QD2_MissionCtrl_Manual_2021a_M, _rt_error_message);
          }
        }
      }

      qthread_attr_destroy(&send_thread_attributes);
      qthread_attr_destroy(&receive_thread_attributes);
      QD2_MissionCtrl_Manual_2021a_DW.StreamServer_Listening = true;
    }

    if (QD2_MissionCtrl_Manual_2021a_P.Constant_Value_h) {
      send_result = pstream_send
        (QD2_MissionCtrl_Manual_2021a_DW.StreamServer_Stream,
         &rtb_TmpSignalConversionAtStream[0]);
    } else {
      send_result = 0;
    }

    receive_result = pstream_receive
      (QD2_MissionCtrl_Manual_2021a_DW.StreamServer_Stream,
       &QD2_MissionCtrl_Manual_2021a_B.StreamServer_o4[0]);
    rtb_StreamServer_o2 = 0;
    if (send_result < 0 && send_result != -QERR_WOULD_BLOCK) {
      rtb_StreamServer_o2 = send_result;
    } else if (receive_result < 0 && receive_result != -QERR_WOULD_BLOCK) {
      rtb_StreamServer_o2 = receive_result;
    }

    pstream_get_state(QD2_MissionCtrl_Manual_2021a_DW.StreamServer_Stream,
                      &state);
    rtb_StreamServer_o1 = state;
  }

  /* MATLAB Function: '<S5>/MATLAB Function' */
  QD2_MissionCtrl_Manual_2021a_DW.sfEvent = QD2_MissionCtrl_Manu_CALL_EVENT;

  /* MATLAB Function 'Communication/Detect Communication loss/MATLAB Function': '<S6>:1' */
  /* '<S6>:1:3' */
  i = 0;
  if ((rtb_Time > 1.0) && ((rtb_StreamServer_o1 != 2) || (rtb_StreamServer_o2 <
        0))) {
    /* '<S6>:1:4' */
    /* '<S6>:1:5' */
    /* '<S6>:1:7' */
    i = 1;
  } else {
    /* '<S6>:1:5' */
  }

  /* End of MATLAB Function: '<S5>/MATLAB Function' */

  /* RelationalOperator: '<S7>/Relation' incorporates:
   *  Constant: '<S7>/threshold'
   */
  rtb_Relation = (i >= QD2_MissionCtrl_Manual_2021a_P.Threshold_threshold_d);

  /* Logic: '<S7>/Logical Operator' */
  QD2_MissionCtrl_Manual_2021a_B.LogicalOperator_k = !rtb_Relation;

  /* DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
  if (QD2_MissionCtrl_Manual_2021a_B.LogicalOperator_k ||
      (QD2_MissionCtrl_Manual_2021a_DW.DiscreteTimeIntegrator_PrevRe_b != 0)) {
    QD2_MissionCtrl_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE_j =
      QD2_MissionCtrl_Manual_2021a_P.DiscreteTimeIntegrator_IC_c;
  }

  /* DataTypeConversion: '<S5>/Data Type Conversion' incorporates:
   *  Constant: '<S7>/duration'
   *  DiscreteIntegrator: '<S7>/Discrete-Time Integrator'
   *  RelationalOperator: '<S7>/Relational Operator'
   */
  QD2_MissionCtrl_Manual_2021a_B.DataTypeConversion_e =
    (QD2_MissionCtrl_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE_j >=
     QD2_MissionCtrl_Manual_2021a_P.Threshold_duration_b);

  /* Outputs for Triggered SubSystem: '<S2>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S10>/Trigger'
   */
  zcEvent = rt_ZCFcn(FALLING_ZERO_CROSSING,
                     &QD2_MissionCtrl_Manual__PrevZCX.TriggeredSubsystem_Trig_ZCE,
                     (QD2_MissionCtrl_Manual_2021a_B.DataTypeConversion_e));
  if (zcEvent != NO_ZCEVENT) {
    /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
     *  Constant: '<S10>/Constant'
     *  Memory: '<S10>/Memory'
     *  Sum: '<S10>/Add'
     */
    QD2_MissionCtrl_Manual_2021a_B.DataTypeConversion_o =
      QD2_MissionCtrl_Manual_2021a_P.Constant_Value +
      QD2_MissionCtrl_Manual_2021a_DW.Memory_PreviousInput;

    /* RelationalOperator: '<S19>/Compare' incorporates:
     *  Constant: '<S19>/Constant'
     */
    QD2_MissionCtrl_Manual_2021a_B.Compare =
      (QD2_MissionCtrl_Manual_2021a_B.DataTypeConversion_o >=
       QD2_MissionCtrl_Manual_2021a_P.CompareToConstant_const_f);

    /* Update for Memory: '<S10>/Memory' */
    QD2_MissionCtrl_Manual_2021a_DW.Memory_PreviousInput =
      QD2_MissionCtrl_Manual_2021a_B.DataTypeConversion_o;
    QD2_MissionCtrl_Manual_2021a_DW.TriggeredSubsystem_SubsysRanBC = 4;
  }

  /* End of Outputs for SubSystem: '<S2>/Triggered Subsystem' */

  /* Product: '<S2>/Product' */
  QD2_MissionCtrl_Manual_2021a_B.Product =
    QD2_MissionCtrl_Manual_2021a_B.DataTypeConversion_e * (real_T)
    QD2_MissionCtrl_Manual_2021a_B.Compare;

  /* Sum: '<S2>/Subtract' */
  QD2_MissionCtrl_Manual_2021a_B.Subtract[0] = rtb_Time_k -
    QD2_MissionCtrl_Manual_2021a_B.StreamServer_o4[0];
  QD2_MissionCtrl_Manual_2021a_B.Subtract[1] = rtb_Time_k -
    QD2_MissionCtrl_Manual_2021a_B.StreamServer_o4[1];

  /* SignalConversion generated from: '<S2>/To Host File' */
  QD2_MissionCtrl_Manual_2021a_B.TmpSignalConversionAtToHostFile[0] =
    QD2_MissionCtrl_Manual_2021a_B.ManualSwitch1[0];
  QD2_MissionCtrl_Manual_2021a_B.TmpSignalConversionAtToHostFile[1] =
    QD2_MissionCtrl_Manual_2021a_B.ManualSwitch1[1];
  QD2_MissionCtrl_Manual_2021a_B.TmpSignalConversionAtToHostFile[2] =
    QD2_MissionCtrl_Manual_2021a_B.ManualSwitch1[2];
  QD2_MissionCtrl_Manual_2021a_B.TmpSignalConversionAtToHostFile[3] =
    QD2_MissionCtrl_Manual_2021a_B.ManualSwitch1[3];
  QD2_MissionCtrl_Manual_2021a_B.TmpSignalConversionAtToHostFile[4] =
    QD2_MissionCtrl_Manual_2021a_B.MaxThrustis2044N;
  QD2_MissionCtrl_Manual_2021a_B.TmpSignalConversionAtToHostFile[5] =
    QD2_MissionCtrl_Manual_2021a_B.u0915NmforRoll08984NmforPitch00[0];
  QD2_MissionCtrl_Manual_2021a_B.TmpSignalConversionAtToHostFile[8] =
    QD2_MissionCtrl_Manual_2021a_B.pi4radforRollPitchpi2radsforYaw[0];
  QD2_MissionCtrl_Manual_2021a_B.TmpSignalConversionAtToHostFile[6] =
    QD2_MissionCtrl_Manual_2021a_B.u0915NmforRoll08984NmforPitch00[1];
  QD2_MissionCtrl_Manual_2021a_B.TmpSignalConversionAtToHostFile[9] =
    QD2_MissionCtrl_Manual_2021a_B.pi4radforRollPitchpi2radsforYaw[1];
  QD2_MissionCtrl_Manual_2021a_B.TmpSignalConversionAtToHostFile[7] =
    QD2_MissionCtrl_Manual_2021a_B.u0915NmforRoll08984NmforPitch00[2];
  QD2_MissionCtrl_Manual_2021a_B.TmpSignalConversionAtToHostFile[10] =
    QD2_MissionCtrl_Manual_2021a_B.pi4radforRollPitchpi2radsforYaw[2];
  QD2_MissionCtrl_Manual_2021a_B.TmpSignalConversionAtToHostFile[11] =
    QD2_MissionCtrl_Manual_2021a_B.Subtract[0];
  QD2_MissionCtrl_Manual_2021a_B.TmpSignalConversionAtToHostFile[12] =
    QD2_MissionCtrl_Manual_2021a_B.Subtract[1];
  QD2_MissionCtrl_Manual_2021a_B.TmpSignalConversionAtToHostFile[13] =
    QD2_MissionCtrl_Manual_2021a_B.Product;

  /* DataTypeConversion: '<S7>/Data Type Conversion' */
  QD2_MissionCtrl_Manual_2021a_B.DataTypeConversion_o = rtb_Relation;
}

/* Model update function */
void QD2_MissionCtrl_Manual_2021a_update(void)
{
  /* Update for DiscreteIntegrator: '<S14>/Discrete-Time Integrator' */
  QD2_MissionCtrl_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE +=
    QD2_MissionCtrl_Manual_2021a_P.DiscreteTimeIntegrator_gainva_b *
    QD2_MissionCtrl_Manual_2021a_B.DataTypeConversion;
  QD2_MissionCtrl_Manual_2021a_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
    QD2_MissionCtrl_Manual_2021a_B.LogicalOperator;

  /* Update for Enabled SubSystem: '<S8>/FrSKYMapping' incorporates:
   *  EnablePort: '<S11>/Valid Signals Detected'
   */
  if (QD2_MissionCtrl_Manual_2021a_DW.FrSKYMapping_MODE) {
    /* Update for DiscreteIntegrator: '<S16>/Discrete-Time Integrator' */
    QD2_MissionCtrl_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE_a +=
      QD2_MissionCtrl_Manual_2021a_P.DiscreteTimeIntegrator_gainval *
      QD2_MissionCtrl_Manual_2021a_B.DataTypeConversion_k;
    QD2_MissionCtrl_Manual_2021a_DW.DiscreteTimeIntegrator_PrevR_bf = (int8_T)
      QD2_MissionCtrl_Manual_2021a_B.LogicalOperator_n;
  }

  /* End of Update for SubSystem: '<S8>/FrSKYMapping' */

  /* Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
  QD2_MissionCtrl_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE_j +=
    QD2_MissionCtrl_Manual_2021a_P.DiscreteTimeIntegrator_gainva_n *
    QD2_MissionCtrl_Manual_2021a_B.DataTypeConversion_o;
  QD2_MissionCtrl_Manual_2021a_DW.DiscreteTimeIntegrator_PrevRe_b = (int8_T)
    QD2_MissionCtrl_Manual_2021a_B.LogicalOperator_k;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++QD2_MissionCtrl_Manual_2021a_M->Timing.clockTick0)) {
    ++QD2_MissionCtrl_Manual_2021a_M->Timing.clockTickH0;
  }

  QD2_MissionCtrl_Manual_2021a_M->Timing.t[0] =
    QD2_MissionCtrl_Manual_2021a_M->Timing.clockTick0 *
    QD2_MissionCtrl_Manual_2021a_M->Timing.stepSize0 +
    QD2_MissionCtrl_Manual_2021a_M->Timing.clockTickH0 *
    QD2_MissionCtrl_Manual_2021a_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void QD2_MissionCtrl_Manual_2021a_initialize(void)
{
  /* Start for S-Function (host_initialize_block): '<S8>/Host Initialize' */

  /* S-Function Block: QD2_MissionCtrl_Manual_2021a/MISSION CONTROL QDRONE MANUAL FLIGHT/JOYSTICK_FRSKY/Host Game Controller (host_game_controller_block) */
  {
    qthread_section_init
      (&QD2_MissionCtrl_Manual_2021a_DW.HostGameController_Lock, NULL);
  }

  /* S-Function Block: QD2_MissionCtrl_Manual_2021a/MISSION CONTROL QDRONE MANUAL FLIGHT/JOYSTICK_FRSKY/Host Initialize (host_initialize_block) */
  {
    t_error result;
    QD2_MissionCtrl_Manual_2021a_B.HostInitialize_o1 = HOST_STATE_NOT_LISTENING;
    result = extmode_svr_register_connected_callback
      (host_extmode_svr_connected_callback,
       host_extmode_svr_disconnected_callback, NULL,
       &QD2_MissionCtrl_Manual_2021a_DW.HostInitialize_ConnectedHandle);
    if (result == 0) {
      result = extmode_svr_register_custom_action(EXT_MODE_ACTION_HOST_INTERFACE,
        host_extmode_svr_custom_action_callback, NULL);
    }

    QD2_MissionCtrl_Manual_2021a_B.HostInitialize_o2 = result;
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(QD2_MissionCtrl_Manual_2021a_M, _rt_error_message);
    }

    if (rtExtModeQuarcIsConnected()) {
      /* Invoke connected callbacks explicitly since Simulink was already connected when MdlStart called */
      host_extmode_svr_connected_callback(NULL);
    }
  }

  /* Start for Enabled SubSystem: '<S8>/FrSKYMapping' */
  QD2_MissionCtrl_Manual_2021a_DW.FrSKYMapping_MODE = false;

  /* End of Start for SubSystem: '<S8>/FrSKYMapping' */
  /* Start for S-Function (stream_server_block): '<S1>/Stream Server' incorporates:
   *  Constant: '<S1>/Constant'
   */

  /* S-Function Block: QD2_MissionCtrl_Manual_2021a/Communication/Stream Server (stream_server_block) */
  {
    QD2_MissionCtrl_Manual_2021a_DW.StreamServer_Stream = NULL;
    QD2_MissionCtrl_Manual_2021a_B.StreamServer_o4[0] =
      QD2_MissionCtrl_Manual_2021a_P.StreamServer_default_value[0];
    QD2_MissionCtrl_Manual_2021a_B.StreamServer_o4[1] =
      QD2_MissionCtrl_Manual_2021a_P.StreamServer_default_value[1];
    QD2_MissionCtrl_Manual_2021a_DW.StreamServer_Listening = false;
  }

  /* user code (Start function Trailer) */

  /* S-Function Block: QD2_MissionCtrl_Manual_2021a/Communication/Detect Communication loss/Time (time_block) */
  {
    t_error result;
    result = timeout_get_high_resolution_time(&_high_resolution_start_time);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(QD2_MissionCtrl_Manual_2021a_M, _rt_error_message);
      return;
    }
  }

  QD2_MissionCtrl_Manual__PrevZCX.pulsecount_Trig_ZCE = POS_ZCSIG;
  QD2_MissionCtrl_Manual__PrevZCX.TriggeredSubsystem_Trig_ZCE =
    UNINITIALIZED_ZCSIG;

  /* InitializeConditions for DiscreteIntegrator: '<S14>/Discrete-Time Integrator' */
  QD2_MissionCtrl_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE =
    QD2_MissionCtrl_Manual_2021a_P.DiscreteTimeIntegrator_IC_m;
  QD2_MissionCtrl_Manual_2021a_DW.DiscreteTimeIntegrator_PrevRese = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
  QD2_MissionCtrl_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE_j =
    QD2_MissionCtrl_Manual_2021a_P.DiscreteTimeIntegrator_IC_c;
  QD2_MissionCtrl_Manual_2021a_DW.DiscreteTimeIntegrator_PrevRe_b = 0;

  /* SystemInitialize for Enabled SubSystem: '<S8>/FrSKYMapping' */
  /* InitializeConditions for DiscreteIntegrator: '<S16>/Discrete-Time Integrator' */
  QD2_MissionCtrl_Manual_2021a_DW.DiscreteTimeIntegrator_DSTATE_a =
    QD2_MissionCtrl_Manual_2021a_P.DiscreteTimeIntegrator_IC;
  QD2_MissionCtrl_Manual_2021a_DW.DiscreteTimeIntegrator_PrevR_bf = 0;

  /* SystemInitialize for RelationalOperator: '<S16>/Relational Operator' incorporates:
   *  Outport: '<S11>/Emergency Abort (bool)'
   */
  QD2_MissionCtrl_Manual_2021a_B.RelationalOperator =
    QD2_MissionCtrl_Manual_2021a_P.EmergencyAbortbool_Y0;

  /* SystemInitialize for Gain: '<S11>/Gain' incorporates:
   *  Outport: '<S11>/Yaw (%)'
   */
  QD2_MissionCtrl_Manual_2021a_B.Gain = QD2_MissionCtrl_Manual_2021a_P.Yaw_Y0;

  /* SystemInitialize for Bias: '<S11>/Bias' incorporates:
   *  Outport: '<S11>/Throttle (%)'
   */
  QD2_MissionCtrl_Manual_2021a_B.Bias =
    QD2_MissionCtrl_Manual_2021a_P.Throttle_Y0;

  /* SystemInitialize for SignalConversion generated from: '<S11>/y' incorporates:
   *  Outport: '<S11>/Roll (%)'
   */
  QD2_MissionCtrl_Manual_2021a_B.y = QD2_MissionCtrl_Manual_2021a_P.Roll_Y0;

  /* SystemInitialize for SignalConversion generated from: '<S11>/z' incorporates:
   *  Outport: '<S11>/Pitch (%)'
   */
  QD2_MissionCtrl_Manual_2021a_B.z = QD2_MissionCtrl_Manual_2021a_P.Pitch_Y0;

  /* SystemInitialize for Outport: '<S11>/Arm//Disarm (bool) ' incorporates:
   *  SignalConversion generated from: '<S11>/Buttons'
   */
  QD2_MissionCtrl_Manual_2021a_B.Buttons[1] =
    QD2_MissionCtrl_Manual_2021a_P.ArmDisarmbool_Y0;

  /* SystemInitialize for RelationalOperator: '<S15>/Compare' incorporates:
   *  Outport: '<S11>/Takeoff//Autoland (bool)'
   */
  QD2_MissionCtrl_Manual_2021a_B.Compare_h =
    QD2_MissionCtrl_Manual_2021a_P.TakeoffAutolandbool_Y0;

  /* End of SystemInitialize for SubSystem: '<S8>/FrSKYMapping' */

  /* SystemInitialize for Atomic SubSystem: '<S8>/Pulse Check' */
  /* SystemInitialize for Triggered SubSystem: '<S13>/pulse count ' */
  /* InitializeConditions for UnitDelay: '<S17>/Unit Delay' */
  QD2_MissionCtrl_Manual_2021a_DW.UnitDelay_DSTATE =
    QD2_MissionCtrl_Manual_2021a_P.UnitDelay_InitialCondition;

  /* SystemInitialize for Sum: '<S18>/FixPt Sum1' incorporates:
   *  Outport: '<S17>/Number of Pulses'
   */
  QD2_MissionCtrl_Manual_2021a_B.FixPtSum1 =
    QD2_MissionCtrl_Manual_2021a_P.NumberofPulses_Y0;

  /* End of SystemInitialize for SubSystem: '<S13>/pulse count ' */
  /* End of SystemInitialize for SubSystem: '<S8>/Pulse Check' */

  /* SystemInitialize for Enabled SubSystem: '<S8>/Initialization and Conditioning' */
  /* SystemInitialize for SignalConversion generated from: '<S12>/Joystick Issue (0,1)' incorporates:
   *  Outport: '<S12>/Joystick Issue (0,1)'
   */
  QD2_MissionCtrl_Manual_2021a_B.OutportBufferForJoystickIssue01 =
    QD2_MissionCtrl_Manual_2021a_P.JoystickIssue01_Y0;

  /* SystemInitialize for Product: '<S12>/Product2' incorporates:
   *  Outport: '<S12>/Triggers (0,1) [4]'
   */
  QD2_MissionCtrl_Manual_2021a_B.Product2 =
    QD2_MissionCtrl_Manual_2021a_P.Triggers014_Y0;

  /* SystemInitialize for Product: '<S12>/Product3' incorporates:
   *  Outport: '<S12>/Triggers (0,1) [4]'
   */
  QD2_MissionCtrl_Manual_2021a_B.Product3 =
    QD2_MissionCtrl_Manual_2021a_P.Triggers014_Y0;

  /* SystemInitialize for DataTypeConversion: '<S12>/Data Type Conversion2' incorporates:
   *  Outport: '<S12>/Triggers (0,1) [4]'
   */
  QD2_MissionCtrl_Manual_2021a_B.DataTypeConversion2 =
    QD2_MissionCtrl_Manual_2021a_P.Triggers014_Y0;

  /* SystemInitialize for DataTypeConversion: '<S12>/Data Type Conversion4' incorporates:
   *  Outport: '<S12>/Triggers (0,1) [4]'
   */
  QD2_MissionCtrl_Manual_2021a_B.DataTypeConversion4 =
    QD2_MissionCtrl_Manual_2021a_P.Triggers014_Y0;

  /* SystemInitialize for Product: '<S12>/Product1' incorporates:
   *  Outport: '<S12>/Commands (%) [4]'
   */
  QD2_MissionCtrl_Manual_2021a_B.Product1 =
    QD2_MissionCtrl_Manual_2021a_P.Commands4_Y0;

  /* SystemInitialize for Product: '<S12>/Product' incorporates:
   *  Outport: '<S12>/Commands (%) [4]'
   */
  QD2_MissionCtrl_Manual_2021a_B.Product_b[0] =
    QD2_MissionCtrl_Manual_2021a_P.Commands4_Y0;
  QD2_MissionCtrl_Manual_2021a_B.Product_b[1] =
    QD2_MissionCtrl_Manual_2021a_P.Commands4_Y0;
  QD2_MissionCtrl_Manual_2021a_B.Product_b[2] =
    QD2_MissionCtrl_Manual_2021a_P.Commands4_Y0;

  /* End of SystemInitialize for SubSystem: '<S8>/Initialization and Conditioning' */

  /* SystemInitialize for MATLAB Function: '<S5>/MATLAB Function' */
  QD2_MissionCtrl_Manual_2021a_DW.sfEvent = QD2_MissionCtrl_Manu_CALL_EVENT;

  /* SystemInitialize for Triggered SubSystem: '<S2>/Triggered Subsystem' */
  /* InitializeConditions for Memory: '<S10>/Memory' */
  QD2_MissionCtrl_Manual_2021a_DW.Memory_PreviousInput =
    QD2_MissionCtrl_Manual_2021a_P.Memory_InitialCondition;

  /* SystemInitialize for RelationalOperator: '<S19>/Compare' incorporates:
   *  Outport: '<S10>/Communication Issue (0,1)'
   */
  QD2_MissionCtrl_Manual_2021a_B.Compare =
    QD2_MissionCtrl_Manual_2021a_P.CommunicationIssue01_Y0;

  /* End of SystemInitialize for SubSystem: '<S2>/Triggered Subsystem' */
}

/* Model terminate function */
void QD2_MissionCtrl_Manual_2021a_terminate(void)
{
  /* Terminate for S-Function (host_initialize_block): '<S8>/Host Initialize' */

  /* S-Function Block: QD2_MissionCtrl_Manual_2021a/MISSION CONTROL QDRONE MANUAL FLIGHT/JOYSTICK_FRSKY/Host Initialize (host_initialize_block) */
  {
    extmode_svr_unregister_custom_action(EXT_MODE_ACTION_HOST_INTERFACE);
    extmode_svr_unregister_connected_callback
      (QD2_MissionCtrl_Manual_2021a_DW.HostInitialize_ConnectedHandle);
  }

  /* Terminate for S-Function (host_game_controller_block): '<S8>/Host Game Controller' */

  /* S-Function Block: QD2_MissionCtrl_Manual_2021a/MISSION CONTROL QDRONE MANUAL FLIGHT/JOYSTICK_FRSKY/Host Game Controller (host_game_controller_block) */
  {
    qthread_section_destroy
      (&QD2_MissionCtrl_Manual_2021a_DW.HostGameController_Lock);
  }

  /* Terminate for S-Function (stream_server_block): '<S1>/Stream Server' incorporates:
   *  Constant: '<S1>/Constant'
   */

  /* S-Function Block: QD2_MissionCtrl_Manual_2021a/Communication/Stream Server (stream_server_block) */
  {
    if (QD2_MissionCtrl_Manual_2021a_DW.StreamServer_Stream != NULL) {
      pstream_close(QD2_MissionCtrl_Manual_2021a_DW.StreamServer_Stream);
    }

    QD2_MissionCtrl_Manual_2021a_DW.StreamServer_Stream = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  QD2_MissionCtrl_Manual_2021a_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  QD2_MissionCtrl_Manual_2021a_update();
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
  QD2_MissionCtrl_Manual_2021a_initialize();
}

void MdlTerminate(void)
{
  QD2_MissionCtrl_Manual_2021a_terminate();
}

/* Registration function */
RT_MODEL_QD2_MissionCtrl_Manu_T *QD2_MissionCtrl_Manual_2021a(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)QD2_MissionCtrl_Manual_2021a_M, 0,
                sizeof(RT_MODEL_QD2_MissionCtrl_Manu_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      QD2_MissionCtrl_Manual_2021a_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    QD2_MissionCtrl_Manual_2021a_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    QD2_MissionCtrl_Manual_2021a_M->Timing.sampleTimes =
      (&QD2_MissionCtrl_Manual_2021a_M->Timing.sampleTimesArray[0]);
    QD2_MissionCtrl_Manual_2021a_M->Timing.offsetTimes =
      (&QD2_MissionCtrl_Manual_2021a_M->Timing.offsetTimesArray[0]);

    /* task periods */
    QD2_MissionCtrl_Manual_2021a_M->Timing.sampleTimes[0] = (0.001);

    /* task offsets */
    QD2_MissionCtrl_Manual_2021a_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(QD2_MissionCtrl_Manual_2021a_M,
             &QD2_MissionCtrl_Manual_2021a_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = QD2_MissionCtrl_Manual_2021a_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    QD2_MissionCtrl_Manual_2021a_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(QD2_MissionCtrl_Manual_2021a_M, -1);
  QD2_MissionCtrl_Manual_2021a_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  QD2_MissionCtrl_Manual_2021a_M->Sizes.checksums[0] = (909136845U);
  QD2_MissionCtrl_Manual_2021a_M->Sizes.checksums[1] = (1981442374U);
  QD2_MissionCtrl_Manual_2021a_M->Sizes.checksums[2] = (465213708U);
  QD2_MissionCtrl_Manual_2021a_M->Sizes.checksums[3] = (3933833137U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    QD2_MissionCtrl_Manual_2021a_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)
      &QD2_MissionCtrl_Manual_2021a_DW.FrSKYMapping_SubsysRanBC;
    systemRan[3] = (sysRanDType *)
      &QD2_MissionCtrl_Manual_2021a_DW.InitializationandConditioning_S;
    systemRan[4] = (sysRanDType *)
      &QD2_MissionCtrl_Manual_2021a_DW.pulsecount_SubsysRanBC;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = (sysRanDType *)
      &QD2_MissionCtrl_Manual_2021a_DW.TriggeredSubsystem_SubsysRanBC;
    rteiSetModelMappingInfoPtr(QD2_MissionCtrl_Manual_2021a_M->extModeInfo,
      &QD2_MissionCtrl_Manual_2021a_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(QD2_MissionCtrl_Manual_2021a_M->extModeInfo,
                        QD2_MissionCtrl_Manual_2021a_M->Sizes.checksums);
    rteiSetTPtr(QD2_MissionCtrl_Manual_2021a_M->extModeInfo, rtmGetTPtr
                (QD2_MissionCtrl_Manual_2021a_M));
  }

  QD2_MissionCtrl_Manual_2021a_M->solverInfoPtr =
    (&QD2_MissionCtrl_Manual_2021a_M->solverInfo);
  QD2_MissionCtrl_Manual_2021a_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&QD2_MissionCtrl_Manual_2021a_M->solverInfo, 0.001);
  rtsiSetSolverMode(&QD2_MissionCtrl_Manual_2021a_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  QD2_MissionCtrl_Manual_2021a_M->blockIO = ((void *)
    &QD2_MissionCtrl_Manual_2021a_B);
  (void) memset(((void *) &QD2_MissionCtrl_Manual_2021a_B), 0,
                sizeof(B_QD2_MissionCtrl_Manual_2021_T));

  /* parameters */
  QD2_MissionCtrl_Manual_2021a_M->defaultParam = ((real_T *)
    &QD2_MissionCtrl_Manual_2021a_P);

  /* states (dwork) */
  QD2_MissionCtrl_Manual_2021a_M->dwork = ((void *)
    &QD2_MissionCtrl_Manual_2021a_DW);
  (void) memset((void *)&QD2_MissionCtrl_Manual_2021a_DW, 0,
                sizeof(DW_QD2_MissionCtrl_Manual_202_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    QD2_MissionCtrl_Manual_2021a_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 25;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  QD2_MissionCtrl_Manual_2021a_M->Sizes.numContStates = (0);/* Number of continuous states */
  QD2_MissionCtrl_Manual_2021a_M->Sizes.numY = (0);/* Number of model outputs */
  QD2_MissionCtrl_Manual_2021a_M->Sizes.numU = (0);/* Number of model inputs */
  QD2_MissionCtrl_Manual_2021a_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  QD2_MissionCtrl_Manual_2021a_M->Sizes.numSampTimes = (1);/* Number of sample times */
  QD2_MissionCtrl_Manual_2021a_M->Sizes.numBlocks = (92);/* Number of blocks */
  QD2_MissionCtrl_Manual_2021a_M->Sizes.numBlockIO = (39);/* Number of block outputs */
  QD2_MissionCtrl_Manual_2021a_M->Sizes.numBlockPrms = (186);/* Sum of parameter "widths" */
  return QD2_MissionCtrl_Manual_2021a_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
