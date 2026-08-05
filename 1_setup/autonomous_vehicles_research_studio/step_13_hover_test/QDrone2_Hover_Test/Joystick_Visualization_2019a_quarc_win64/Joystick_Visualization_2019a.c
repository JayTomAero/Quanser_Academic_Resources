/*
 * Joystick_Visualization_2019a.c
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

#include "Joystick_Visualization_2019a.h"
#include "rtwtypes.h"
#include "Joystick_Visualization_2019a_private.h"
#include <string.h>
#include <math.h>
#include "zero_crossing_types.h"
#include "rt_nonfinite.h"
#include "Joystick_Visualization_2019a_dt.h"

/* Named constants for MATLAB Function: '<S22>/MATLAB Function' */
#define Joystick_Visualizati_CALL_EVENT (-1)

/* Block signals (default storage) */
B_Joystick_Visualization_2019_T Joystick_Visualization_2019a_B;

/* Continuous states */
X_Joystick_Visualization_2019_T Joystick_Visualization_2019a_X;

/* Disabled State Vector */
XDis_Joystick_Visualization_2_T Joystick_Visualization_201_XDis;

/* Block states (default storage) */
DW_Joystick_Visualization_201_T Joystick_Visualization_2019a_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Joystick_Visualizatio_T Joystick_Visualization__PrevZCX;

/* Real-time model */
static RT_MODEL_Joystick_Visualizati_T Joystick_Visualization_2019a_M_;
RT_MODEL_Joystick_Visualizati_T *const Joystick_Visualization_2019a_M =
  &Joystick_Visualization_2019a_M_;

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
  /* S-Function Block: Joystick_Visualization_2019a/JOYSTICK_FRSKY/Host Game Controller (host_game_controller_block) */
  {
    if (Joystick_Visualization_2019a_P.HostGameController_Enabled) {

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
        Joystick_Visualization_2019a_P.HostGameController_BufferSize;
      game_controller_configuration.configuration.controller_number =
        Joystick_Visualization_2019a_P.HostGameController_Controller;
      game_controller_configuration.configuration.auto_center =
        Joystick_Visualization_2019a_P.HostGameController_AutoCenter;
      game_controller_configuration.configuration.debug_mode =
        Joystick_Visualization_2019a_P.HostGameController_DebugMode;
      result = host_send_extmode_packet(NULL, &game_controller_configuration,
        sizeof(game_controller_configuration));
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Joystick_Visualization_2019a_M, _rt_error_message);
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
      /* S-Function Block: Joystick_Visualization_2019a/JOYSTICK_FRSKY/Host Game Controller (host_game_controller_block) */
      {
        t_game_controller_states * state = (t_game_controller_states *) (buffer);
        if (buffer_size >= sizeof(t_game_controller_states)) {
          t_error result = qthread_section_lock
            (&Joystick_Visualization_2019a_DW.HostGameController_Lock);
          if (result == 0) {
            memory_copy
              (&Joystick_Visualization_2019a_DW.HostGameController_ControllerSt,
               sizeof
               (*&Joystick_Visualization_2019a_DW.HostGameController_ControllerSt),
               state);
            Joystick_Visualization_2019a_DW.HostGameController_NewData = true;
            qthread_section_unlock
              (&Joystick_Visualization_2019a_DW.HostGameController_Lock);
          }
        } else {
          rtmSetErrorStatus(Joystick_Visualization_2019a_M,
                            "A Host Game Controller block has received an invalid packet from the host!");
        }
      }
      break;

     default:
      rtmSetErrorStatus(Joystick_Visualization_2019a_M,
                        "Invalid peripheral identifier received");
      break;
    }
  }

  return 0;
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
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  Joystick_Visualization_2019a_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * System initialize for enable system:
 *    '<S22>/Use des height  when enabled'
 *    '<S22>/Use des yaw  when enabled'
 *    '<S22>/Use desired X  when enabled'
 *    '<S22>/Use desired Y  when enabled'
 */
void Jo_Usedesheightwhenenabled_Init(B_Usedesheightwhenenabled_Joy_T *localB,
  P_Usedesheightwhenenabled_Joy_T *localP)
{
  /* SystemInitialize for SignalConversion generated from: '<S28>/h_d (m) [1]' incorporates:
   *  Outport: '<S28>/Out1'
   */
  localB->h_dm1 = localP->Out1_Y0;
}

/*
 * Disable for enable system:
 *    '<S22>/Use des height  when enabled'
 *    '<S22>/Use des yaw  when enabled'
 *    '<S22>/Use desired X  when enabled'
 *    '<S22>/Use desired Y  when enabled'
 */
void Usedesheightwhenenabled_Disable(B_Usedesheightwhenenabled_Joy_T *localB,
  DW_Usedesheightwhenenabled_Jo_T *localDW, P_Usedesheightwhenenabled_Joy_T
  *localP)
{
  /* Disable for SignalConversion generated from: '<S28>/h_d (m) [1]' incorporates:
   *  Outport: '<S28>/Out1'
   */
  localB->h_dm1 = localP->Out1_Y0;
  localDW->Usedesheightwhenenabled_MODE = false;
}

/*
 * Start for enable system:
 *    '<S22>/Use des height  when enabled'
 *    '<S22>/Use des yaw  when enabled'
 *    '<S22>/Use desired X  when enabled'
 *    '<S22>/Use desired Y  when enabled'
 */
void J_Usedesheightwhenenabled_Start(DW_Usedesheightwhenenabled_Jo_T *localDW)
{
  localDW->Usedesheightwhenenabled_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S22>/Use des height  when enabled'
 *    '<S22>/Use des yaw  when enabled'
 *    '<S22>/Use desired X  when enabled'
 *    '<S22>/Use desired Y  when enabled'
 */
void Joystic_Usedesheightwhenenabled(RT_MODEL_Joystick_Visualizati_T * const
  Joystick_Visualization_2019a_M, real_T rtu_Enable, real_T rtu_h_dm1,
  B_Usedesheightwhenenabled_Joy_T *localB, DW_Usedesheightwhenenabled_Jo_T
  *localDW, P_Usedesheightwhenenabled_Joy_T *localP)
{
  /* Outputs for Enabled SubSystem: '<S22>/Use des height  when enabled' incorporates:
   *  EnablePort: '<S28>/Enable'
   */
  if (rtmIsMajorTimeStep(Joystick_Visualization_2019a_M) &&
      rtsiIsModeUpdateTimeStep(&Joystick_Visualization_2019a_M->solverInfo)) {
    if (rtu_Enable > 0.0) {
      localDW->Usedesheightwhenenabled_MODE = true;
    } else if (localDW->Usedesheightwhenenabled_MODE) {
      Usedesheightwhenenabled_Disable(localB, localDW, localP);
    }
  }

  if (localDW->Usedesheightwhenenabled_MODE) {
    /* SignalConversion generated from: '<S28>/h_d (m) [1]' */
    localB->h_dm1 = rtu_h_dm1;
    if (rtsiIsModeUpdateTimeStep(&Joystick_Visualization_2019a_M->solverInfo)) {
      srUpdateBC(localDW->Usedesheightwhenenabled_SubsysR);
    }
  }

  /* End of Outputs for SubSystem: '<S22>/Use des height  when enabled' */
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T tmp;
  real_T tmp_0;
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Model output function */
void Joystick_Visualization_2019a_output(void)
{
  /* local block i/o variables */
  real_T rtb_HostGameController_o3[2];
  real_T rtb_HostGameController_o4;
  real_T rtb_HostGameController_o5;
  real_T rtb_HostGameController_o6;
  real_T rtb_HostGameController_o7;
  real_T rtb_HostGameController_o9;
  real_T rtb_TmpSignalConversionAtCompar[6];
  boolean_T rtb_HostGameController_o2[32];
  real_T rtb_Product_b[16];
  real_T rtb_Product_h[16];
  real_T rtb_Product_i[16];
  real_T rtb_Product_i_0[16];
  real_T MatrixConcatenate_f_tmp;
  real_T MatrixConcatenate_o_tmp;
  real_T rtb_Fcn1;
  real_T rtb_NormalizeDen;
  real_T rtb_Product_idx_0;
  real_T rtb_Product_idx_1;
  real_T rtb_Product_idx_3;
  real_T rtb_Product_j;
  real_T rtb_Product_j_0;
  real_T rtb_Product_j_1;
  int32_T i;
  int32_T i_0;
  int32_T rtb_Product_j_tmp;
  boolean_T rtb_LogicalOperator;
  boolean_T rtb_Relation;
  boolean_T rtb_RelationalOperator;
  boolean_T tmp;
  ZCEventType zcEvent;
  if (rtmIsMajorTimeStep(Joystick_Visualization_2019a_M)) {
    /* set solver stop time */
    if (!(Joystick_Visualization_2019a_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Joystick_Visualization_2019a_M->solverInfo,
                            ((Joystick_Visualization_2019a_M->Timing.clockTickH0
        + 1) * Joystick_Visualization_2019a_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Joystick_Visualization_2019a_M->solverInfo,
                            ((Joystick_Visualization_2019a_M->Timing.clockTick0
        + 1) * Joystick_Visualization_2019a_M->Timing.stepSize0 +
        Joystick_Visualization_2019a_M->Timing.clockTickH0 *
        Joystick_Visualization_2019a_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Joystick_Visualization_2019a_M)) {
    Joystick_Visualization_2019a_M->Timing.t[0] = rtsiGetT
      (&Joystick_Visualization_2019a_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(Joystick_Visualization_2019a_DW.FrSKYMapping_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Joystick_Visualization_2019a_DW.InitializationandConditioning_S);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Joystick_Visualization_2019a_DW.pulsecount_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC
    (Joystick_Visualization_2019a_DW.Usedesheightwhenenabled.Usedesheightwhenenabled_SubsysR);
  tmp = rtmIsMajorTimeStep(Joystick_Visualization_2019a_M);
  if (tmp) {
    /* Constant: '<S20>/Constant1' incorporates:
     *  Concatenate: '<S20>/Matrix Concatenate'
     */
    memcpy(&Joystick_Visualization_2019a_B.MatrixConcatenate[0],
           &Joystick_Visualization_2019a_P.Constant1_Value_l[0], 12U * sizeof
           (real_T));
  }

  /* S-Function (continuous_sigmoid_block): '<S22>/Continuous Sigmoid' */
  /* S-Function Block: Joystick_Visualization_2019a/Simple Drone  Visualization/Pose Conditioning/Command Conditioning via Sigmoids/Continuous Sigmoid (continuous_sigmoid_block) */
  {
    if (rtmIsMajorTimeStep(Joystick_Visualization_2019a_M)) {
      {
        real_T* params;

        /* Determine the correct step size for the output ports */
        params = &Joystick_Visualization_2019a_DW.ContinuousSigmoid_Sigmoid[0 *
          NUMBER_OF_SIGMOID_PARAMETERS];

        /*  Check if the target position has changed or if it is the first
           simulation step, in which case we need to compute the initial
           trajectory. */
        if (Joystick_Visualization_2019a_DW.ContinuousSigmoid_Flag == 1 ||
            Joystick_Visualization_2019a_DW.ContinuousSigmoid_Time == 0) {
          /*  Read the new position and reset the flag */
          params[SIGMOID_PARAMETER_XD] =
            Joystick_Visualization_2019a_DW.ContinuousSigmoid_Target;
          Joystick_Visualization_2019a_DW.ContinuousSigmoid_Flag = 0;

          /*  Calculate a single step using the new trajectory to account for the target
             change that occured at the previous sample (i.e., there is a one sample delay
             between the point where the target position changes and the trajectory changes
             based on the new target)    */
          if (Joystick_Visualization_2019a_DW.ContinuousSigmoid_Time == 0) {
            /*  Do not update the trajectory since we are at time 0 in simulation
               (leave t = 0)   */
          } else {
            /*  Set the relative time to one step size so that a single step
               is computed for the new trajectory  */

            /*  Set the default values in sigmoid_parameters to the trajectory
               state at the last time step.    */
            params[SIGMOID_PARAMETER_X0] =
              Joystick_Visualization_2019a_DW.ContinuousSigmoid_PPos;
            params[SIGMOID_PARAMETER_V0] =
              Joystick_Visualization_2019a_DW.ContinuousSigmoid_PVel;
            Joystick_Visualization_2019a_DW.ContinuousSigmoid_Time = 0.001;
          }

          /*  Calculate the new trajectory    */
          sigmoid_calculate_trajectory(params, 0, params[SIGMOID_PARAMETER_X0],
            params[SIGMOID_PARAMETER_V0],
            Joystick_Visualization_2019a_DW.ContinuousSigmoid_MAcc,
            Joystick_Visualization_2019a_DW.ContinuousSigmoid_MVel);
        }

        /* Mark the target as not reached */
        Joystick_Visualization_2019a_B.ContinuousSigmoid_o4 = 0;
        if (Joystick_Visualization_2019a_DW.ContinuousSigmoid_Time <
            params[SIGMOID_PARAMETER_T1]) {
          Joystick_Visualization_2019a_B.ContinuousSigmoid_o3 =
            params[SIGMOID_PARAMETER_AP];
          Joystick_Visualization_2019a_B.ContinuousSigmoid_o2 =
            params[SIGMOID_PARAMETER_V0] + params[SIGMOID_PARAMETER_AP] *
            Joystick_Visualization_2019a_DW.ContinuousSigmoid_Time;
          Joystick_Visualization_2019a_B.ContinuousSigmoid_o1 =
            params[SIGMOID_PARAMETER_X0] + (params[SIGMOID_PARAMETER_V0] + 0.5 *
            params[SIGMOID_PARAMETER_AP] *
            Joystick_Visualization_2019a_DW.ContinuousSigmoid_Time) *
            Joystick_Visualization_2019a_DW.ContinuousSigmoid_Time;
        } else if (Joystick_Visualization_2019a_DW.ContinuousSigmoid_Time <
                   params[SIGMOID_PARAMETER_T2]) {
          Joystick_Visualization_2019a_B.ContinuousSigmoid_o3 = 0;
          Joystick_Visualization_2019a_B.ContinuousSigmoid_o2 =
            params[SIGMOID_PARAMETER_VP];
          Joystick_Visualization_2019a_B.ContinuousSigmoid_o1 =
            params[SIGMOID_PARAMETER_X1] + params[SIGMOID_PARAMETER_VP] *
            (Joystick_Visualization_2019a_DW.ContinuousSigmoid_Time -
             params[SIGMOID_PARAMETER_T1]);
        } else if (Joystick_Visualization_2019a_DW.ContinuousSigmoid_Time <
                   params[SIGMOID_PARAMETER_T3]) {
          Joystick_Visualization_2019a_B.ContinuousSigmoid_o3 =
            -params[SIGMOID_PARAMETER_AP];
          Joystick_Visualization_2019a_B.ContinuousSigmoid_o2 =
            params[SIGMOID_PARAMETER_VP] - params[SIGMOID_PARAMETER_AP] *
            (Joystick_Visualization_2019a_DW.ContinuousSigmoid_Time -
             params[SIGMOID_PARAMETER_T2]);
          Joystick_Visualization_2019a_B.ContinuousSigmoid_o1 =
            params[SIGMOID_PARAMETER_X2] + (params[SIGMOID_PARAMETER_VP] - 0.5 *
            params[SIGMOID_PARAMETER_AP] *
            (Joystick_Visualization_2019a_DW.ContinuousSigmoid_Time -
             params[SIGMOID_PARAMETER_T2])) *
            (Joystick_Visualization_2019a_DW.ContinuousSigmoid_Time -
             params[SIGMOID_PARAMETER_T2]);
        } else {
          Joystick_Visualization_2019a_B.ContinuousSigmoid_o3 = 0;
          Joystick_Visualization_2019a_B.ContinuousSigmoid_o2 = 0;
          Joystick_Visualization_2019a_B.ContinuousSigmoid_o1 =
            params[SIGMOID_PARAMETER_XD];/* always attainable */

          /* Mark the target as reached after the hold-off period */
          if ((Joystick_Visualization_2019a_DW.ContinuousSigmoid_Time -
               params[SIGMOID_PARAMETER_T3]) >=
              params[SIGMOID_PARAMETER_HOLD_OFF])
            Joystick_Visualization_2019a_B.ContinuousSigmoid_o4 = 1;/* Assert Done signal */
        }

        /*  Save the current position/velocity to be used next time step (possibly) */
        Joystick_Visualization_2019a_DW.ContinuousSigmoid_PPos =
          Joystick_Visualization_2019a_B.ContinuousSigmoid_o1;
        Joystick_Visualization_2019a_DW.ContinuousSigmoid_PVel =
          Joystick_Visualization_2019a_B.ContinuousSigmoid_o2;

        /*  Increment the relative time RWork to the NEXT time step */
        Joystick_Visualization_2019a_DW.ContinuousSigmoid_Time += 0.001;
      }
    }
  }

  /* S-Function (continuous_sigmoid_block): '<S22>/Continuous Sigmoid1' */
  /* S-Function Block: Joystick_Visualization_2019a/Simple Drone  Visualization/Pose Conditioning/Command Conditioning via Sigmoids/Continuous Sigmoid1 (continuous_sigmoid_block) */
  {
    if (rtmIsMajorTimeStep(Joystick_Visualization_2019a_M)) {
      {
        real_T* params;

        /* Determine the correct step size for the output ports */
        params = &Joystick_Visualization_2019a_DW.ContinuousSigmoid1_Sigmoid[0 *
          NUMBER_OF_SIGMOID_PARAMETERS];

        /*  Check if the target position has changed or if it is the first
           simulation step, in which case we need to compute the initial
           trajectory. */
        if (Joystick_Visualization_2019a_DW.ContinuousSigmoid1_Flag == 1 ||
            Joystick_Visualization_2019a_DW.ContinuousSigmoid1_Time == 0) {
          /*  Read the new position and reset the flag */
          params[SIGMOID_PARAMETER_XD] =
            Joystick_Visualization_2019a_DW.ContinuousSigmoid1_Target;
          Joystick_Visualization_2019a_DW.ContinuousSigmoid1_Flag = 0;

          /*  Calculate a single step using the new trajectory to account for the target
             change that occured at the previous sample (i.e., there is a one sample delay
             between the point where the target position changes and the trajectory changes
             based on the new target)    */
          if (Joystick_Visualization_2019a_DW.ContinuousSigmoid1_Time == 0) {
            /*  Do not update the trajectory since we are at time 0 in simulation
               (leave t = 0)   */
          } else {
            /*  Set the relative time to one step size so that a single step
               is computed for the new trajectory  */

            /*  Set the default values in sigmoid_parameters to the trajectory
               state at the last time step.    */
            params[SIGMOID_PARAMETER_X0] =
              Joystick_Visualization_2019a_DW.ContinuousSigmoid1_PPos;
            params[SIGMOID_PARAMETER_V0] =
              Joystick_Visualization_2019a_DW.ContinuousSigmoid1_PVel;
            Joystick_Visualization_2019a_DW.ContinuousSigmoid1_Time = 0.001;
          }

          /*  Calculate the new trajectory    */
          sigmoid_calculate_trajectory(params, 0, params[SIGMOID_PARAMETER_X0],
            params[SIGMOID_PARAMETER_V0],
            Joystick_Visualization_2019a_DW.ContinuousSigmoid1_MAcc,
            Joystick_Visualization_2019a_DW.ContinuousSigmoid1_MVel);
        }

        /* Mark the target as not reached */
        Joystick_Visualization_2019a_B.ContinuousSigmoid1_o4 = 0;
        if (Joystick_Visualization_2019a_DW.ContinuousSigmoid1_Time <
            params[SIGMOID_PARAMETER_T1]) {
          Joystick_Visualization_2019a_B.ContinuousSigmoid1_o3 =
            params[SIGMOID_PARAMETER_AP];
          Joystick_Visualization_2019a_B.ContinuousSigmoid1_o2 =
            params[SIGMOID_PARAMETER_V0] + params[SIGMOID_PARAMETER_AP] *
            Joystick_Visualization_2019a_DW.ContinuousSigmoid1_Time;
          Joystick_Visualization_2019a_B.ContinuousSigmoid1_o1 =
            params[SIGMOID_PARAMETER_X0] + (params[SIGMOID_PARAMETER_V0] + 0.5 *
            params[SIGMOID_PARAMETER_AP] *
            Joystick_Visualization_2019a_DW.ContinuousSigmoid1_Time) *
            Joystick_Visualization_2019a_DW.ContinuousSigmoid1_Time;
        } else if (Joystick_Visualization_2019a_DW.ContinuousSigmoid1_Time <
                   params[SIGMOID_PARAMETER_T2]) {
          Joystick_Visualization_2019a_B.ContinuousSigmoid1_o3 = 0;
          Joystick_Visualization_2019a_B.ContinuousSigmoid1_o2 =
            params[SIGMOID_PARAMETER_VP];
          Joystick_Visualization_2019a_B.ContinuousSigmoid1_o1 =
            params[SIGMOID_PARAMETER_X1] + params[SIGMOID_PARAMETER_VP] *
            (Joystick_Visualization_2019a_DW.ContinuousSigmoid1_Time -
             params[SIGMOID_PARAMETER_T1]);
        } else if (Joystick_Visualization_2019a_DW.ContinuousSigmoid1_Time <
                   params[SIGMOID_PARAMETER_T3]) {
          Joystick_Visualization_2019a_B.ContinuousSigmoid1_o3 =
            -params[SIGMOID_PARAMETER_AP];
          Joystick_Visualization_2019a_B.ContinuousSigmoid1_o2 =
            params[SIGMOID_PARAMETER_VP] - params[SIGMOID_PARAMETER_AP] *
            (Joystick_Visualization_2019a_DW.ContinuousSigmoid1_Time -
             params[SIGMOID_PARAMETER_T2]);
          Joystick_Visualization_2019a_B.ContinuousSigmoid1_o1 =
            params[SIGMOID_PARAMETER_X2] + (params[SIGMOID_PARAMETER_VP] - 0.5 *
            params[SIGMOID_PARAMETER_AP] *
            (Joystick_Visualization_2019a_DW.ContinuousSigmoid1_Time -
             params[SIGMOID_PARAMETER_T2])) *
            (Joystick_Visualization_2019a_DW.ContinuousSigmoid1_Time -
             params[SIGMOID_PARAMETER_T2]);
        } else {
          Joystick_Visualization_2019a_B.ContinuousSigmoid1_o3 = 0;
          Joystick_Visualization_2019a_B.ContinuousSigmoid1_o2 = 0;
          Joystick_Visualization_2019a_B.ContinuousSigmoid1_o1 =
            params[SIGMOID_PARAMETER_XD];/* always attainable */

          /* Mark the target as reached after the hold-off period */
          if ((Joystick_Visualization_2019a_DW.ContinuousSigmoid1_Time -
               params[SIGMOID_PARAMETER_T3]) >=
              params[SIGMOID_PARAMETER_HOLD_OFF])
            Joystick_Visualization_2019a_B.ContinuousSigmoid1_o4 = 1;/* Assert Done signal */
        }

        /*  Save the current position/velocity to be used next time step (possibly) */
        Joystick_Visualization_2019a_DW.ContinuousSigmoid1_PPos =
          Joystick_Visualization_2019a_B.ContinuousSigmoid1_o1;
        Joystick_Visualization_2019a_DW.ContinuousSigmoid1_PVel =
          Joystick_Visualization_2019a_B.ContinuousSigmoid1_o2;

        /*  Increment the relative time RWork to the NEXT time step */
        Joystick_Visualization_2019a_DW.ContinuousSigmoid1_Time += 0.001;
      }
    }
  }

  /* S-Function (continuous_sigmoid_block): '<S22>/Continuous Sigmoid2' */
  /* S-Function Block: Joystick_Visualization_2019a/Simple Drone  Visualization/Pose Conditioning/Command Conditioning via Sigmoids/Continuous Sigmoid2 (continuous_sigmoid_block) */
  {
    if (rtmIsMajorTimeStep(Joystick_Visualization_2019a_M)) {
      {
        real_T* params;

        /* Determine the correct step size for the output ports */
        params = &Joystick_Visualization_2019a_DW.ContinuousSigmoid2_Sigmoid[0 *
          NUMBER_OF_SIGMOID_PARAMETERS];

        /*  Check if the target position has changed or if it is the first
           simulation step, in which case we need to compute the initial
           trajectory. */
        if (Joystick_Visualization_2019a_DW.ContinuousSigmoid2_Flag == 1 ||
            Joystick_Visualization_2019a_DW.ContinuousSigmoid2_Time == 0) {
          /*  Read the new position and reset the flag */
          params[SIGMOID_PARAMETER_XD] =
            Joystick_Visualization_2019a_DW.ContinuousSigmoid2_Target;
          Joystick_Visualization_2019a_DW.ContinuousSigmoid2_Flag = 0;

          /*  Calculate a single step using the new trajectory to account for the target
             change that occured at the previous sample (i.e., there is a one sample delay
             between the point where the target position changes and the trajectory changes
             based on the new target)    */
          if (Joystick_Visualization_2019a_DW.ContinuousSigmoid2_Time == 0) {
            /*  Do not update the trajectory since we are at time 0 in simulation
               (leave t = 0)   */
          } else {
            /*  Set the relative time to one step size so that a single step
               is computed for the new trajectory  */

            /*  Set the default values in sigmoid_parameters to the trajectory
               state at the last time step.    */
            params[SIGMOID_PARAMETER_X0] =
              Joystick_Visualization_2019a_DW.ContinuousSigmoid2_PPos;
            params[SIGMOID_PARAMETER_V0] =
              Joystick_Visualization_2019a_DW.ContinuousSigmoid2_PVel;
            Joystick_Visualization_2019a_DW.ContinuousSigmoid2_Time = 0.001;
          }

          /*  Calculate the new trajectory    */
          sigmoid_calculate_trajectory(params, 0, params[SIGMOID_PARAMETER_X0],
            params[SIGMOID_PARAMETER_V0],
            Joystick_Visualization_2019a_DW.ContinuousSigmoid2_MAcc,
            Joystick_Visualization_2019a_DW.ContinuousSigmoid2_MVel);
        }

        /* Mark the target as not reached */
        Joystick_Visualization_2019a_B.ContinuousSigmoid2_o4 = 0;
        if (Joystick_Visualization_2019a_DW.ContinuousSigmoid2_Time <
            params[SIGMOID_PARAMETER_T1]) {
          Joystick_Visualization_2019a_B.ContinuousSigmoid2_o3 =
            params[SIGMOID_PARAMETER_AP];
          Joystick_Visualization_2019a_B.ContinuousSigmoid2_o2 =
            params[SIGMOID_PARAMETER_V0] + params[SIGMOID_PARAMETER_AP] *
            Joystick_Visualization_2019a_DW.ContinuousSigmoid2_Time;
          Joystick_Visualization_2019a_B.ContinuousSigmoid2_o1 =
            params[SIGMOID_PARAMETER_X0] + (params[SIGMOID_PARAMETER_V0] + 0.5 *
            params[SIGMOID_PARAMETER_AP] *
            Joystick_Visualization_2019a_DW.ContinuousSigmoid2_Time) *
            Joystick_Visualization_2019a_DW.ContinuousSigmoid2_Time;
        } else if (Joystick_Visualization_2019a_DW.ContinuousSigmoid2_Time <
                   params[SIGMOID_PARAMETER_T2]) {
          Joystick_Visualization_2019a_B.ContinuousSigmoid2_o3 = 0;
          Joystick_Visualization_2019a_B.ContinuousSigmoid2_o2 =
            params[SIGMOID_PARAMETER_VP];
          Joystick_Visualization_2019a_B.ContinuousSigmoid2_o1 =
            params[SIGMOID_PARAMETER_X1] + params[SIGMOID_PARAMETER_VP] *
            (Joystick_Visualization_2019a_DW.ContinuousSigmoid2_Time -
             params[SIGMOID_PARAMETER_T1]);
        } else if (Joystick_Visualization_2019a_DW.ContinuousSigmoid2_Time <
                   params[SIGMOID_PARAMETER_T3]) {
          Joystick_Visualization_2019a_B.ContinuousSigmoid2_o3 =
            -params[SIGMOID_PARAMETER_AP];
          Joystick_Visualization_2019a_B.ContinuousSigmoid2_o2 =
            params[SIGMOID_PARAMETER_VP] - params[SIGMOID_PARAMETER_AP] *
            (Joystick_Visualization_2019a_DW.ContinuousSigmoid2_Time -
             params[SIGMOID_PARAMETER_T2]);
          Joystick_Visualization_2019a_B.ContinuousSigmoid2_o1 =
            params[SIGMOID_PARAMETER_X2] + (params[SIGMOID_PARAMETER_VP] - 0.5 *
            params[SIGMOID_PARAMETER_AP] *
            (Joystick_Visualization_2019a_DW.ContinuousSigmoid2_Time -
             params[SIGMOID_PARAMETER_T2])) *
            (Joystick_Visualization_2019a_DW.ContinuousSigmoid2_Time -
             params[SIGMOID_PARAMETER_T2]);
        } else {
          Joystick_Visualization_2019a_B.ContinuousSigmoid2_o3 = 0;
          Joystick_Visualization_2019a_B.ContinuousSigmoid2_o2 = 0;
          Joystick_Visualization_2019a_B.ContinuousSigmoid2_o1 =
            params[SIGMOID_PARAMETER_XD];/* always attainable */

          /* Mark the target as reached after the hold-off period */
          if ((Joystick_Visualization_2019a_DW.ContinuousSigmoid2_Time -
               params[SIGMOID_PARAMETER_T3]) >=
              params[SIGMOID_PARAMETER_HOLD_OFF])
            Joystick_Visualization_2019a_B.ContinuousSigmoid2_o4 = 1;/* Assert Done signal */
        }

        /*  Save the current position/velocity to be used next time step (possibly) */
        Joystick_Visualization_2019a_DW.ContinuousSigmoid2_PPos =
          Joystick_Visualization_2019a_B.ContinuousSigmoid2_o1;
        Joystick_Visualization_2019a_DW.ContinuousSigmoid2_PVel =
          Joystick_Visualization_2019a_B.ContinuousSigmoid2_o2;

        /*  Increment the relative time RWork to the NEXT time step */
        Joystick_Visualization_2019a_DW.ContinuousSigmoid2_Time += 0.001;
      }
    }
  }

  /* S-Function (continuous_sigmoid_block): '<S22>/Continuous Sigmoid3' */
  /* S-Function Block: Joystick_Visualization_2019a/Simple Drone  Visualization/Pose Conditioning/Command Conditioning via Sigmoids/Continuous Sigmoid3 (continuous_sigmoid_block) */
  {
    if (rtmIsMajorTimeStep(Joystick_Visualization_2019a_M)) {
      {
        real_T* params;

        /* Determine the correct step size for the output ports */
        params = &Joystick_Visualization_2019a_DW.ContinuousSigmoid3_Sigmoid[0 *
          NUMBER_OF_SIGMOID_PARAMETERS];

        /*  Check if the target position has changed or if it is the first
           simulation step, in which case we need to compute the initial
           trajectory. */
        if (Joystick_Visualization_2019a_DW.ContinuousSigmoid3_Flag == 1 ||
            Joystick_Visualization_2019a_DW.ContinuousSigmoid3_Time == 0) {
          /*  Read the new position and reset the flag */
          params[SIGMOID_PARAMETER_XD] =
            Joystick_Visualization_2019a_DW.ContinuousSigmoid3_Target;
          Joystick_Visualization_2019a_DW.ContinuousSigmoid3_Flag = 0;

          /*  Calculate a single step using the new trajectory to account for the target
             change that occured at the previous sample (i.e., there is a one sample delay
             between the point where the target position changes and the trajectory changes
             based on the new target)    */
          if (Joystick_Visualization_2019a_DW.ContinuousSigmoid3_Time == 0) {
            /*  Do not update the trajectory since we are at time 0 in simulation
               (leave t = 0)   */
          } else {
            /*  Set the relative time to one step size so that a single step
               is computed for the new trajectory  */

            /*  Set the default values in sigmoid_parameters to the trajectory
               state at the last time step.    */
            params[SIGMOID_PARAMETER_X0] =
              Joystick_Visualization_2019a_DW.ContinuousSigmoid3_PPos;
            params[SIGMOID_PARAMETER_V0] =
              Joystick_Visualization_2019a_DW.ContinuousSigmoid3_PVel;
            Joystick_Visualization_2019a_DW.ContinuousSigmoid3_Time = 0.001;
          }

          /*  Calculate the new trajectory    */
          sigmoid_calculate_trajectory(params, 0, params[SIGMOID_PARAMETER_X0],
            params[SIGMOID_PARAMETER_V0],
            Joystick_Visualization_2019a_DW.ContinuousSigmoid3_MAcc,
            Joystick_Visualization_2019a_DW.ContinuousSigmoid3_MVel);
        }

        /* Mark the target as not reached */
        Joystick_Visualization_2019a_B.ContinuousSigmoid3_o4 = 0;
        if (Joystick_Visualization_2019a_DW.ContinuousSigmoid3_Time <
            params[SIGMOID_PARAMETER_T1]) {
          Joystick_Visualization_2019a_B.ContinuousSigmoid3_o3 =
            params[SIGMOID_PARAMETER_AP];
          Joystick_Visualization_2019a_B.ContinuousSigmoid3_o2 =
            params[SIGMOID_PARAMETER_V0] + params[SIGMOID_PARAMETER_AP] *
            Joystick_Visualization_2019a_DW.ContinuousSigmoid3_Time;
          Joystick_Visualization_2019a_B.ContinuousSigmoid3_o1 =
            params[SIGMOID_PARAMETER_X0] + (params[SIGMOID_PARAMETER_V0] + 0.5 *
            params[SIGMOID_PARAMETER_AP] *
            Joystick_Visualization_2019a_DW.ContinuousSigmoid3_Time) *
            Joystick_Visualization_2019a_DW.ContinuousSigmoid3_Time;
        } else if (Joystick_Visualization_2019a_DW.ContinuousSigmoid3_Time <
                   params[SIGMOID_PARAMETER_T2]) {
          Joystick_Visualization_2019a_B.ContinuousSigmoid3_o3 = 0;
          Joystick_Visualization_2019a_B.ContinuousSigmoid3_o2 =
            params[SIGMOID_PARAMETER_VP];
          Joystick_Visualization_2019a_B.ContinuousSigmoid3_o1 =
            params[SIGMOID_PARAMETER_X1] + params[SIGMOID_PARAMETER_VP] *
            (Joystick_Visualization_2019a_DW.ContinuousSigmoid3_Time -
             params[SIGMOID_PARAMETER_T1]);
        } else if (Joystick_Visualization_2019a_DW.ContinuousSigmoid3_Time <
                   params[SIGMOID_PARAMETER_T3]) {
          Joystick_Visualization_2019a_B.ContinuousSigmoid3_o3 =
            -params[SIGMOID_PARAMETER_AP];
          Joystick_Visualization_2019a_B.ContinuousSigmoid3_o2 =
            params[SIGMOID_PARAMETER_VP] - params[SIGMOID_PARAMETER_AP] *
            (Joystick_Visualization_2019a_DW.ContinuousSigmoid3_Time -
             params[SIGMOID_PARAMETER_T2]);
          Joystick_Visualization_2019a_B.ContinuousSigmoid3_o1 =
            params[SIGMOID_PARAMETER_X2] + (params[SIGMOID_PARAMETER_VP] - 0.5 *
            params[SIGMOID_PARAMETER_AP] *
            (Joystick_Visualization_2019a_DW.ContinuousSigmoid3_Time -
             params[SIGMOID_PARAMETER_T2])) *
            (Joystick_Visualization_2019a_DW.ContinuousSigmoid3_Time -
             params[SIGMOID_PARAMETER_T2]);
        } else {
          Joystick_Visualization_2019a_B.ContinuousSigmoid3_o3 = 0;
          Joystick_Visualization_2019a_B.ContinuousSigmoid3_o2 = 0;
          Joystick_Visualization_2019a_B.ContinuousSigmoid3_o1 =
            params[SIGMOID_PARAMETER_XD];/* always attainable */

          /* Mark the target as reached after the hold-off period */
          if ((Joystick_Visualization_2019a_DW.ContinuousSigmoid3_Time -
               params[SIGMOID_PARAMETER_T3]) >=
              params[SIGMOID_PARAMETER_HOLD_OFF])
            Joystick_Visualization_2019a_B.ContinuousSigmoid3_o4 = 1;/* Assert Done signal */
        }

        /*  Save the current position/velocity to be used next time step (possibly) */
        Joystick_Visualization_2019a_DW.ContinuousSigmoid3_PPos =
          Joystick_Visualization_2019a_B.ContinuousSigmoid3_o1;
        Joystick_Visualization_2019a_DW.ContinuousSigmoid3_PVel =
          Joystick_Visualization_2019a_B.ContinuousSigmoid3_o2;

        /*  Increment the relative time RWork to the NEXT time step */
        Joystick_Visualization_2019a_DW.ContinuousSigmoid3_Time += 0.001;
      }
    }
  }

  if (tmp) {
    /* SignalConversion generated from: '<S1>/Compare' incorporates:
     *  S-Function (host_game_controller_block): '<S1>/Host Game Controller'
     */

    /* S-Function Block: Joystick_Visualization_2019a/JOYSTICK_FRSKY/Host Game Controller (host_game_controller_block) */
    {
      if (Joystick_Visualization_2019a_P.HostGameController_Enabled) {
        t_error result = qthread_section_lock
          (&Joystick_Visualization_2019a_DW.HostGameController_Lock);
        if (result == 0) {
          {
            int_T i1;
            boolean_T *y1 = &rtb_HostGameController_o2[0];
            for (i1=0; i1 < 32; i1++) {
              y1[i1] =
                ((Joystick_Visualization_2019a_DW.HostGameController_ControllerSt.buttons
                  & (1U << i1)) != 0);
            }
          }

          rtb_HostGameController_o3[0] =
            Joystick_Visualization_2019a_DW.HostGameController_ControllerSt.sliders
            [0];
          rtb_HostGameController_o3[1] =
            Joystick_Visualization_2019a_DW.HostGameController_ControllerSt.sliders
            [1];
          rtb_HostGameController_o4 =
            Joystick_Visualization_2019a_DW.HostGameController_ControllerSt.x;
          rtb_HostGameController_o5 =
            Joystick_Visualization_2019a_DW.HostGameController_ControllerSt.y;
          rtb_HostGameController_o6 =
            Joystick_Visualization_2019a_DW.HostGameController_ControllerSt.z;
          rtb_HostGameController_o7 =
            Joystick_Visualization_2019a_DW.HostGameController_ControllerSt.rx;
          rtb_TmpSignalConversionAtCompar[4] =
            Joystick_Visualization_2019a_DW.HostGameController_ControllerSt.ry;
          rtb_HostGameController_o9 =
            Joystick_Visualization_2019a_DW.HostGameController_ControllerSt.rz;
          Joystick_Visualization_2019a_B.HostGameController_o1 =
            Joystick_Visualization_2019a_DW.HostGameController_NewData;
          Joystick_Visualization_2019a_DW.HostGameController_NewData = false;
          qthread_section_unlock
            (&Joystick_Visualization_2019a_DW.HostGameController_Lock);
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
          Joystick_Visualization_2019a_B.HostGameController_o1 = false;
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
        Joystick_Visualization_2019a_B.HostGameController_o1 = false;
      }
    }

    rtb_TmpSignalConversionAtCompar[0] = rtb_HostGameController_o4;
    rtb_TmpSignalConversionAtCompar[1] = rtb_HostGameController_o5;
    rtb_TmpSignalConversionAtCompar[2] = rtb_HostGameController_o6;
    rtb_TmpSignalConversionAtCompar[3] = rtb_HostGameController_o7;
    rtb_TmpSignalConversionAtCompar[5] = rtb_HostGameController_o9;

    /* Logic: '<S1>/AND' incorporates:
     *  Constant: '<S1>/Constant'
     *  S-Function (compare_block): '<S1>/Compare'
     *  SignalConversion generated from: '<S1>/Compare'
     */
    rtb_Relation = (rtb_TmpSignalConversionAtCompar[0] ==
                    Joystick_Visualization_2019a_P.Constant_Value_a[0]);
    for (i = 0; i < 5; i++) {
      rtb_Relation = (rtb_Relation && (rtb_TmpSignalConversionAtCompar[i + 1] ==
        Joystick_Visualization_2019a_P.Constant_Value_a[i + 1]));
    }

    /* RelationalOperator: '<S7>/Relation' incorporates:
     *  Constant: '<S7>/threshold'
     *  Logic: '<S1>/AND'
     */
    rtb_Relation = ((real_T)rtb_Relation >=
                    Joystick_Visualization_2019a_P.Threshold_threshold_d);

    /* Logic: '<S7>/Logical Operator' */
    Joystick_Visualization_2019a_B.LogicalOperator = !rtb_Relation;

    /* DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
    if (Joystick_Visualization_2019a_B.LogicalOperator ||
        (Joystick_Visualization_2019a_DW.DiscreteTimeIntegrator_PrevRese != 0))
    {
      Joystick_Visualization_2019a_DW.DiscreteTimeIntegrator_DSTATE =
        Joystick_Visualization_2019a_P.DiscreteTimeIntegrator_IC_e;
    }

    /* RelationalOperator: '<S7>/Relational Operator' incorporates:
     *  Constant: '<S7>/duration'
     *  DiscreteIntegrator: '<S7>/Discrete-Time Integrator'
     */
    rtb_RelationalOperator =
      (Joystick_Visualization_2019a_DW.DiscreteTimeIntegrator_DSTATE >=
       Joystick_Visualization_2019a_P.Threshold_duration_h);

    /* Outputs for Enabled SubSystem: '<S1>/FrSKYMapping' incorporates:
     *  EnablePort: '<S4>/Valid Signals Detected'
     */
    if (rtsiIsModeUpdateTimeStep(&Joystick_Visualization_2019a_M->solverInfo)) {
      /* Logic: '<S1>/NOT' */
      if (!rtb_RelationalOperator) {
        Joystick_Visualization_2019a_DW.FrSKYMapping_MODE = true;
      } else if (Joystick_Visualization_2019a_DW.FrSKYMapping_MODE) {
        /* Disable for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
        Joystick_Visualization_2019a_DW.DiscreteTimeIntegrator_DSTATE_c =
          Joystick_Visualization_2019a_B.DiscreteTimeIntegrator;
        Joystick_Visualization_2019a_DW.FrSKYMapping_MODE = false;
      }

      /* End of Logic: '<S1>/NOT' */
    }

    if (Joystick_Visualization_2019a_DW.FrSKYMapping_MODE) {
      for (i = 0; i < 32; i++) {
        /* SignalConversion generated from: '<S4>/Buttons' */
        Joystick_Visualization_2019a_B.Buttons[i] = rtb_HostGameController_o2[i];
      }

      /* RelationalOperator: '<S9>/Relation' incorporates:
       *  Constant: '<S9>/threshold'
       */
      rtb_LogicalOperator = ((real_T)Joystick_Visualization_2019a_B.Buttons[0] >=
        Joystick_Visualization_2019a_P.Threshold_threshold);

      /* DataTypeConversion: '<S9>/Data Type Conversion' */
      Joystick_Visualization_2019a_B.DataTypeConversion_j = rtb_LogicalOperator;

      /* Logic: '<S9>/Logical Operator' */
      Joystick_Visualization_2019a_B.LogicalOperator_j = !rtb_LogicalOperator;

      /* DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
      if (Joystick_Visualization_2019a_B.LogicalOperator_j ||
          (Joystick_Visualization_2019a_DW.DiscreteTimeIntegrator_PrevRe_j != 0))
      {
        Joystick_Visualization_2019a_DW.DiscreteTimeIntegrator_DSTATE_c =
          Joystick_Visualization_2019a_P.DiscreteTimeIntegrator_IC;
      }

      /* DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
      Joystick_Visualization_2019a_B.DiscreteTimeIntegrator =
        Joystick_Visualization_2019a_DW.DiscreteTimeIntegrator_DSTATE_c;

      /* RelationalOperator: '<S9>/Relational Operator' incorporates:
       *  Constant: '<S9>/duration'
       */
      Joystick_Visualization_2019a_B.RelationalOperator =
        (Joystick_Visualization_2019a_B.DiscreteTimeIntegrator >=
         Joystick_Visualization_2019a_P.Threshold_duration);

      /* Gain: '<S4>/Gain' */
      Joystick_Visualization_2019a_B.Gain =
        Joystick_Visualization_2019a_P.Gain_Gain * rtb_HostGameController_o7;

      /* Bias: '<S4>/Bias' incorporates:
       *  Gain: '<S4>/Gain1'
       */
      Joystick_Visualization_2019a_B.Bias =
        Joystick_Visualization_2019a_P.Gain1_Gain * rtb_HostGameController_o4 +
        Joystick_Visualization_2019a_P.Bias_Bias;

      /* SignalConversion generated from: '<S4>/y' */
      Joystick_Visualization_2019a_B.y = rtb_HostGameController_o5;

      /* SignalConversion generated from: '<S4>/z' */
      Joystick_Visualization_2019a_B.z = rtb_HostGameController_o6;

      /* RelationalOperator: '<S8>/Compare' incorporates:
       *  Constant: '<S8>/Constant'
       */
      Joystick_Visualization_2019a_B.Compare_j = (rtb_HostGameController_o9 >=
        Joystick_Visualization_2019a_P.CompareToConstant_const);
      if (rtsiIsModeUpdateTimeStep(&Joystick_Visualization_2019a_M->solverInfo))
      {
        srUpdateBC(Joystick_Visualization_2019a_DW.FrSKYMapping_SubsysRanBC);
      }
    }

    /* End of Outputs for SubSystem: '<S1>/FrSKYMapping' */

    /* Outputs for Atomic SubSystem: '<S1>/Pulse Check' */
    /* Outputs for Triggered SubSystem: '<S6>/pulse count ' incorporates:
     *  TriggerPort: '<S10>/Trigger'
     */
    if (((Joystick_Visualization__PrevZCX.pulsecount_Trig_ZCE == POS_ZCSIG) !=
         (int32_T)Joystick_Visualization_2019a_B.HostGameController_o1) &&
        (Joystick_Visualization__PrevZCX.pulsecount_Trig_ZCE !=
         UNINITIALIZED_ZCSIG)) {
      /* Sum: '<S11>/FixPt Sum1' incorporates:
       *  Constant: '<S10>/Constant1'
       *  Constant: '<S11>/FixPt Constant'
       *  Sum: '<S10>/Sum'
       *  UnitDelay: '<S10>/Unit Delay'
       */
      Joystick_Visualization_2019a_B.FixPtSum1 =
        (Joystick_Visualization_2019a_P.Constant1_Value +
         Joystick_Visualization_2019a_DW.UnitDelay_DSTATE) +
        Joystick_Visualization_2019a_P.FixPtConstant_Value;

      /* Update for UnitDelay: '<S10>/Unit Delay' */
      Joystick_Visualization_2019a_DW.UnitDelay_DSTATE =
        Joystick_Visualization_2019a_B.FixPtSum1;
      Joystick_Visualization_2019a_DW.pulsecount_SubsysRanBC = 4;
    }

    Joystick_Visualization__PrevZCX.pulsecount_Trig_ZCE =
      Joystick_Visualization_2019a_B.HostGameController_o1;

    /* End of Outputs for SubSystem: '<S6>/pulse count ' */

    /* S-Function (compare_block): '<S6>/Compare' incorporates:
     *  Constant: '<S6>/Pulse Check'
     */
    {
      Joystick_Visualization_2019a_B.Compare =
        (Joystick_Visualization_2019a_B.FixPtSum1 >=
         Joystick_Visualization_2019a_P.PulseCheck_Value);
    }

    /* End of Outputs for SubSystem: '<S1>/Pulse Check' */

    /* Outputs for Enabled SubSystem: '<S1>/Initialization and Conditioning' incorporates:
     *  EnablePort: '<S5>/Enable'
     */
    if (Joystick_Visualization_2019a_B.Compare) {
      /* DataTypeConversion: '<S5>/Data Type Conversion2' */
      Joystick_Visualization_2019a_B.DataTypeConversion2 =
        Joystick_Visualization_2019a_B.RelationalOperator;

      /* DataTypeConversion: '<S5>/Data Type Conversion4' */
      Joystick_Visualization_2019a_B.DataTypeConversion4 =
        rtb_RelationalOperator;

      /* Logic: '<S5>/Logical Operator' */
      rtb_LogicalOperator = !rtb_RelationalOperator;

      /* DeadZone: '<S5>/Dead Zone' */
      if (Joystick_Visualization_2019a_B.y >
          Joystick_Visualization_2019a_P.DeadZone_End) {
        rtb_NormalizeDen = Joystick_Visualization_2019a_B.y -
          Joystick_Visualization_2019a_P.DeadZone_End;
      } else if (Joystick_Visualization_2019a_B.y >=
                 Joystick_Visualization_2019a_P.DeadZone_Start) {
        rtb_NormalizeDen = 0.0;
      } else {
        rtb_NormalizeDen = Joystick_Visualization_2019a_B.y -
          Joystick_Visualization_2019a_P.DeadZone_Start;
      }

      /* Product: '<S5>/Product' incorporates:
       *  DataTypeConversion: '<S5>/Data Type Conversion6'
       *  DeadZone: '<S5>/Dead Zone'
       */
      Joystick_Visualization_2019a_B.Product[0] = (real_T)rtb_LogicalOperator *
        rtb_NormalizeDen;

      /* DeadZone: '<S5>/Dead Zone' */
      if (Joystick_Visualization_2019a_B.z >
          Joystick_Visualization_2019a_P.DeadZone_End) {
        rtb_NormalizeDen = Joystick_Visualization_2019a_B.z -
          Joystick_Visualization_2019a_P.DeadZone_End;
      } else if (Joystick_Visualization_2019a_B.z >=
                 Joystick_Visualization_2019a_P.DeadZone_Start) {
        rtb_NormalizeDen = 0.0;
      } else {
        rtb_NormalizeDen = Joystick_Visualization_2019a_B.z -
          Joystick_Visualization_2019a_P.DeadZone_Start;
      }

      /* Product: '<S5>/Product' incorporates:
       *  DataTypeConversion: '<S5>/Data Type Conversion6'
       *  DeadZone: '<S5>/Dead Zone'
       */
      Joystick_Visualization_2019a_B.Product[1] = (real_T)rtb_LogicalOperator *
        rtb_NormalizeDen;

      /* DeadZone: '<S5>/Dead Zone' */
      if (Joystick_Visualization_2019a_B.Gain >
          Joystick_Visualization_2019a_P.DeadZone_End) {
        rtb_NormalizeDen = Joystick_Visualization_2019a_B.Gain -
          Joystick_Visualization_2019a_P.DeadZone_End;
      } else if (Joystick_Visualization_2019a_B.Gain >=
                 Joystick_Visualization_2019a_P.DeadZone_Start) {
        rtb_NormalizeDen = 0.0;
      } else {
        rtb_NormalizeDen = Joystick_Visualization_2019a_B.Gain -
          Joystick_Visualization_2019a_P.DeadZone_Start;
      }

      /* Product: '<S5>/Product' incorporates:
       *  DataTypeConversion: '<S5>/Data Type Conversion6'
       *  DeadZone: '<S5>/Dead Zone'
       */
      Joystick_Visualization_2019a_B.Product[2] = (real_T)rtb_LogicalOperator *
        rtb_NormalizeDen;

      /* Product: '<S5>/Product1' incorporates:
       *  DataTypeConversion: '<S5>/Data Type Conversion6'
       */
      Joystick_Visualization_2019a_B.Product1_e = (real_T)rtb_LogicalOperator *
        Joystick_Visualization_2019a_B.Bias;

      /* Product: '<S5>/Product2' incorporates:
       *  DataTypeConversion: '<S5>/Data Type Conversion5'
       *  DataTypeConversion: '<S5>/Data Type Conversion6'
       */
      Joystick_Visualization_2019a_B.Product2 = (real_T)rtb_LogicalOperator *
        (real_T)Joystick_Visualization_2019a_B.Buttons[1];

      /* Product: '<S5>/Product3' incorporates:
       *  DataTypeConversion: '<S5>/Data Type Conversion6'
       *  DataTypeConversion: '<S5>/Data Type Conversion7'
       */
      Joystick_Visualization_2019a_B.Product3 = (real_T)rtb_LogicalOperator *
        (real_T)Joystick_Visualization_2019a_B.Compare_j;
      if (rtsiIsModeUpdateTimeStep(&Joystick_Visualization_2019a_M->solverInfo))
      {
        srUpdateBC
          (Joystick_Visualization_2019a_DW.InitializationandConditioning_S);
      }
    }

    /* End of Outputs for SubSystem: '<S1>/Initialization and Conditioning' */

    /* Gain: '<S1>/  m//%  ' */
    Joystick_Visualization_2019a_B.m = Joystick_Visualization_2019a_P.m_Gain *
      Joystick_Visualization_2019a_B.Product[1];

    /* Gain: '<S1>/ m//% ' */
    Joystick_Visualization_2019a_B.m_h = Joystick_Visualization_2019a_P.m_Gain_o
      * Joystick_Visualization_2019a_B.Product[0];

    /* Gain: '<S1>/m//%' */
    Joystick_Visualization_2019a_B.m_m = Joystick_Visualization_2019a_P.m_Gain_n
      * Joystick_Visualization_2019a_B.Product1_e;
  }

  /* Integrator: '<S1>/Integrator' */
  if (rtsiIsModeUpdateTimeStep(&Joystick_Visualization_2019a_M->solverInfo)) {
    zcEvent = rt_ZCFcn(FALLING_ZERO_CROSSING,
                       &Joystick_Visualization__PrevZCX.Integrator_Reset_ZCE,
                       (Joystick_Visualization_2019a_B.Product3));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      Joystick_Visualization_2019a_X.Integrator_CSTATE =
        Joystick_Visualization_2019a_P.Integrator_IC;
    }
  }

  /* ManualSwitch: '<Root>/Manual Switch1' */
  if (Joystick_Visualization_2019a_P.ManualSwitch1_CurrentSetting == 1) {
    /* ManualSwitch: '<Root>/Manual Switch1' incorporates:
     *  Integrator: '<S1>/Integrator'
     */
    Joystick_Visualization_2019a_B.ManualSwitch1[0] =
      Joystick_Visualization_2019a_B.DataTypeConversion4;
    Joystick_Visualization_2019a_B.ManualSwitch1[1] =
      Joystick_Visualization_2019a_B.m;
    Joystick_Visualization_2019a_B.ManualSwitch1[2] =
      Joystick_Visualization_2019a_B.m_h;
    Joystick_Visualization_2019a_B.ManualSwitch1[3] =
      Joystick_Visualization_2019a_B.m_m;
    Joystick_Visualization_2019a_B.ManualSwitch1[4] =
      Joystick_Visualization_2019a_X.Integrator_CSTATE;
    Joystick_Visualization_2019a_B.ManualSwitch1[5] =
      Joystick_Visualization_2019a_B.Product2;
    Joystick_Visualization_2019a_B.ManualSwitch1[6] =
      Joystick_Visualization_2019a_B.Product3;
    Joystick_Visualization_2019a_B.ManualSwitch1[7] =
      Joystick_Visualization_2019a_B.DataTypeConversion2;
  } else {
    /* ManualSwitch: '<Root>/Manual Switch1' */
    Joystick_Visualization_2019a_B.ManualSwitch1[0] = 0.0;
    Joystick_Visualization_2019a_B.ManualSwitch1[1] = 0.0;
    Joystick_Visualization_2019a_B.ManualSwitch1[2] = 0.0;
    Joystick_Visualization_2019a_B.ManualSwitch1[3] = 0.0;
    Joystick_Visualization_2019a_B.ManualSwitch1[4] = 0.0;
    Joystick_Visualization_2019a_B.ManualSwitch1[5] = 0.0;
    Joystick_Visualization_2019a_B.ManualSwitch1[6] = 0.0;
    Joystick_Visualization_2019a_B.ManualSwitch1[7] = 0.0;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch1' */

  /* Product: '<S14>/Product' */
  rtb_Product_idx_0 = Joystick_Visualization_2019a_B.ContinuousSigmoid_o1 *
    Joystick_Visualization_2019a_B.ManualSwitch1[5];
  rtb_Product_idx_1 = Joystick_Visualization_2019a_B.ContinuousSigmoid1_o1 *
    Joystick_Visualization_2019a_B.ManualSwitch1[5];
  rtb_Product_idx_3 = Joystick_Visualization_2019a_B.ContinuousSigmoid3_o1 *
    Joystick_Visualization_2019a_B.ManualSwitch1[5];

  /* SignalConversion generated from: '<S20>/Matrix Concatenate' incorporates:
   *  Concatenate: '<S20>/Matrix Concatenate'
   *  Constant: '<S20>/Constant'
   *  Product: '<S14>/Product'
   */
  Joystick_Visualization_2019a_B.MatrixConcatenate[12] = rtb_Product_idx_0;
  Joystick_Visualization_2019a_B.MatrixConcatenate[13] = rtb_Product_idx_1;
  Joystick_Visualization_2019a_B.MatrixConcatenate[14] =
    Joystick_Visualization_2019a_B.ContinuousSigmoid2_o1 *
    Joystick_Visualization_2019a_B.ManualSwitch1[5];
  Joystick_Visualization_2019a_B.MatrixConcatenate[15] =
    Joystick_Visualization_2019a_P.Constant_Value_f;

  /* Product: '<S20>/Product' incorporates:
   *  Concatenate: '<S20>/Matrix Concatenate'
   *  Constant: '<S19>/Constant'
   */
  for (i = 0; i < 4; i++) {
    rtb_Fcn1 = 0.0;
    rtb_Product_j = 0.0;
    rtb_Product_j_0 = 0.0;
    rtb_Product_j_1 = 0.0;
    for (i_0 = 0; i_0 < 4; i_0++) {
      rtb_NormalizeDen = Joystick_Visualization_2019a_B.MatrixConcatenate[(i <<
        2) + i_0];
      rtb_Product_j_tmp = i_0 << 2;
      rtb_Fcn1 +=
        Joystick_Visualization_2019a_P.Constant_Value[rtb_Product_j_tmp] *
        rtb_NormalizeDen;
      rtb_Product_j +=
        Joystick_Visualization_2019a_P.Constant_Value[rtb_Product_j_tmp + 1] *
        rtb_NormalizeDen;
      rtb_Product_j_0 +=
        Joystick_Visualization_2019a_P.Constant_Value[rtb_Product_j_tmp + 2] *
        rtb_NormalizeDen;
      rtb_Product_j_1 +=
        Joystick_Visualization_2019a_P.Constant_Value[rtb_Product_j_tmp + 3] *
        rtb_NormalizeDen;
    }

    rtb_Product_j_tmp = i << 2;
    rtb_Product_h[rtb_Product_j_tmp + 3] = rtb_Product_j_1;
    rtb_Product_h[rtb_Product_j_tmp + 2] = rtb_Product_j_0;
    rtb_Product_h[rtb_Product_j_tmp + 1] = rtb_Product_j;
    rtb_Product_h[rtb_Product_j_tmp] = rtb_Fcn1;
  }

  /* End of Product: '<S20>/Product' */
  if (tmp) {
    /* Constant: '<S21>/Constant1' incorporates:
     *  Concatenate: '<S21>/Matrix Concatenate'
     */
    memcpy(&Joystick_Visualization_2019a_B.MatrixConcatenate_j[0],
           &Joystick_Visualization_2019a_P.Constant1_Value_h[0], 12U * sizeof
           (real_T));
  }

  /* SignalConversion generated from: '<S21>/Matrix Concatenate' incorporates:
   *  Concatenate: '<S21>/Matrix Concatenate'
   *  Constant: '<S13>/Constant'
   *  Constant: '<S21>/Constant'
   */
  Joystick_Visualization_2019a_B.MatrixConcatenate_j[12] = rtb_Product_idx_0;
  Joystick_Visualization_2019a_B.MatrixConcatenate_j[13] = rtb_Product_idx_1;
  Joystick_Visualization_2019a_B.MatrixConcatenate_j[14] =
    Joystick_Visualization_2019a_P.Constant_Value_j;
  Joystick_Visualization_2019a_B.MatrixConcatenate_j[15] =
    Joystick_Visualization_2019a_P.Constant_Value_k;

  /* Product: '<S21>/Product' incorporates:
   *  Concatenate: '<S21>/Matrix Concatenate'
   *  Constant: '<S19>/Constant'
   */
  for (i = 0; i < 4; i++) {
    rtb_Product_idx_0 = 0.0;
    rtb_Product_idx_1 = 0.0;
    rtb_Fcn1 = 0.0;
    rtb_Product_j = 0.0;
    for (i_0 = 0; i_0 < 4; i_0++) {
      rtb_NormalizeDen = Joystick_Visualization_2019a_B.MatrixConcatenate_j[(i <<
        2) + i_0];
      rtb_Product_j_tmp = i_0 << 2;
      rtb_Product_idx_0 +=
        Joystick_Visualization_2019a_P.Constant_Value[rtb_Product_j_tmp] *
        rtb_NormalizeDen;
      rtb_Product_idx_1 +=
        Joystick_Visualization_2019a_P.Constant_Value[rtb_Product_j_tmp + 1] *
        rtb_NormalizeDen;
      rtb_Fcn1 +=
        Joystick_Visualization_2019a_P.Constant_Value[rtb_Product_j_tmp + 2] *
        rtb_NormalizeDen;
      rtb_Product_j +=
        Joystick_Visualization_2019a_P.Constant_Value[rtb_Product_j_tmp + 3] *
        rtb_NormalizeDen;
    }

    rtb_Product_j_tmp = i << 2;
    rtb_Product_b[rtb_Product_j_tmp + 3] = rtb_Product_j;
    rtb_Product_b[rtb_Product_j_tmp + 2] = rtb_Fcn1;
    rtb_Product_b[rtb_Product_j_tmp + 1] = rtb_Product_idx_1;
    rtb_Product_b[rtb_Product_j_tmp] = rtb_Product_idx_0;
  }

  /* End of Product: '<S21>/Product' */

  /* Fcn: '<S18>/Fcn' */
  rtb_Product_idx_1 = sin(rtb_Product_idx_3);

  /* Fcn: '<S18>/Fcn1' */
  rtb_Fcn1 = cos(rtb_Product_idx_3);
  if (tmp) {
    /* Fcn: '<S18>/Normalize Den' incorporates:
     *  Constant: '<S12>/Constant'
     */
    rtb_NormalizeDen = 1.0 / rt_powd_snf((rt_powd_snf
      (Joystick_Visualization_2019a_P.Constant_Value_m[0], 2.0) + rt_powd_snf
      (Joystick_Visualization_2019a_P.Constant_Value_m[1], 2.0)) + rt_powd_snf
      (Joystick_Visualization_2019a_P.Constant_Value_m[2], 2.0), 0.5);

    /* Product: '<S18>/Product1' incorporates:
     *  Constant: '<S12>/Constant'
     */
    Joystick_Visualization_2019a_B.Product1[0] =
      Joystick_Visualization_2019a_P.Constant_Value_m[0] * rtb_NormalizeDen;
    Joystick_Visualization_2019a_B.Product1[1] =
      Joystick_Visualization_2019a_P.Constant_Value_m[1] * rtb_NormalizeDen;
    Joystick_Visualization_2019a_B.Product1[2] =
      Joystick_Visualization_2019a_P.Constant_Value_m[2] * rtb_NormalizeDen;
  }

  /* SignalConversion generated from: '<S18>/Matrix Concatenate' incorporates:
   *  Concatenate: '<S18>/Matrix Concatenate'
   *  Constant: '<S18>/Constant9'
   *  Fcn: '<S18>/mat11'
   *  Fcn: '<S18>/mat21'
   *  Fcn: '<S18>/mat31'
   */
  Joystick_Visualization_2019a_B.MatrixConcatenate_i[0] = (1.0 - rtb_Fcn1) *
    rt_powd_snf(Joystick_Visualization_2019a_B.Product1[0], 2.0) + rtb_Fcn1;
  Joystick_Visualization_2019a_B.MatrixConcatenate_i[1] =
    Joystick_Visualization_2019a_B.Product1[0] *
    Joystick_Visualization_2019a_B.Product1[1] * (1.0 - rtb_Fcn1) +
    Joystick_Visualization_2019a_B.Product1[2] * rtb_Product_idx_1;
  Joystick_Visualization_2019a_B.MatrixConcatenate_i[2] =
    Joystick_Visualization_2019a_B.Product1[0] *
    Joystick_Visualization_2019a_B.Product1[2] * (1.0 - rtb_Fcn1) -
    Joystick_Visualization_2019a_B.Product1[1] * rtb_Product_idx_1;
  Joystick_Visualization_2019a_B.MatrixConcatenate_i[3] =
    Joystick_Visualization_2019a_P.Constant9_Value;

  /* SignalConversion generated from: '<S18>/Matrix Concatenate' incorporates:
   *  Concatenate: '<S18>/Matrix Concatenate'
   *  Constant: '<S18>/Constant8'
   *  Fcn: '<S18>/mat12'
   *  Fcn: '<S18>/mat22'
   *  Fcn: '<S18>/mat32'
   */
  Joystick_Visualization_2019a_B.MatrixConcatenate_i[4] =
    Joystick_Visualization_2019a_B.Product1[0] *
    Joystick_Visualization_2019a_B.Product1[1] * (1.0 - rtb_Fcn1) -
    Joystick_Visualization_2019a_B.Product1[2] * rtb_Product_idx_1;
  Joystick_Visualization_2019a_B.MatrixConcatenate_i[5] = (1.0 - rtb_Fcn1) *
    rt_powd_snf(Joystick_Visualization_2019a_B.Product1[1], 2.0) + rtb_Fcn1;
  Joystick_Visualization_2019a_B.MatrixConcatenate_i[6] =
    Joystick_Visualization_2019a_B.Product1[1] *
    Joystick_Visualization_2019a_B.Product1[2] * (1.0 - rtb_Fcn1) +
    Joystick_Visualization_2019a_B.Product1[0] * rtb_Product_idx_1;
  Joystick_Visualization_2019a_B.MatrixConcatenate_i[7] =
    Joystick_Visualization_2019a_P.Constant8_Value;

  /* SignalConversion generated from: '<S18>/Matrix Concatenate' incorporates:
   *  Concatenate: '<S18>/Matrix Concatenate'
   *  Constant: '<S18>/Constant7'
   *  Fcn: '<S18>/mat13'
   *  Fcn: '<S18>/mat23'
   *  Fcn: '<S18>/mat33'
   */
  Joystick_Visualization_2019a_B.MatrixConcatenate_i[8] =
    Joystick_Visualization_2019a_B.Product1[0] *
    Joystick_Visualization_2019a_B.Product1[2] * (1.0 - rtb_Fcn1) +
    Joystick_Visualization_2019a_B.Product1[1] * rtb_Product_idx_1;
  Joystick_Visualization_2019a_B.MatrixConcatenate_i[9] =
    Joystick_Visualization_2019a_B.Product1[1] *
    Joystick_Visualization_2019a_B.Product1[2] * (1.0 - rtb_Fcn1) -
    Joystick_Visualization_2019a_B.Product1[0] * rtb_Product_idx_1;
  Joystick_Visualization_2019a_B.MatrixConcatenate_i[10] = (1.0 - rtb_Fcn1) *
    rt_powd_snf(Joystick_Visualization_2019a_B.Product1[2], 2.0) + rtb_Fcn1;
  Joystick_Visualization_2019a_B.MatrixConcatenate_i[11] =
    Joystick_Visualization_2019a_P.Constant7_Value;
  if (tmp) {
    /* Constant: '<S18>/Constant5' incorporates:
     *  Concatenate: '<S18>/Matrix Concatenate'
     */
    Joystick_Visualization_2019a_B.MatrixConcatenate_i[12] =
      Joystick_Visualization_2019a_P.Constant5_Value[0];
    Joystick_Visualization_2019a_B.MatrixConcatenate_i[13] =
      Joystick_Visualization_2019a_P.Constant5_Value[1];
    Joystick_Visualization_2019a_B.MatrixConcatenate_i[14] =
      Joystick_Visualization_2019a_P.Constant5_Value[2];
    Joystick_Visualization_2019a_B.MatrixConcatenate_i[15] =
      Joystick_Visualization_2019a_P.Constant5_Value[3];
  }

  /* Product: '<S18>/Product' incorporates:
   *  Concatenate: '<S18>/Matrix Concatenate'
   *  Constant: '<S15>/Constant'
   *  Product: '<S17>/Product'
   */
  for (i = 0; i < 4; i++) {
    rtb_Product_idx_3 = 0.0;
    rtb_Product_idx_0 = 0.0;
    rtb_Product_idx_1 = 0.0;
    rtb_Fcn1 = 0.0;
    for (i_0 = 0; i_0 < 4; i_0++) {
      rtb_NormalizeDen = Joystick_Visualization_2019a_B.MatrixConcatenate_i[(i <<
        2) + i_0];
      rtb_Product_j_tmp = i_0 << 2;
      rtb_Product_idx_3 +=
        Joystick_Visualization_2019a_P.Constant_Value_g[rtb_Product_j_tmp] *
        rtb_NormalizeDen;
      rtb_Product_idx_0 +=
        Joystick_Visualization_2019a_P.Constant_Value_g[rtb_Product_j_tmp + 1] *
        rtb_NormalizeDen;
      rtb_Product_idx_1 +=
        Joystick_Visualization_2019a_P.Constant_Value_g[rtb_Product_j_tmp + 2] *
        rtb_NormalizeDen;
      rtb_Fcn1 +=
        Joystick_Visualization_2019a_P.Constant_Value_g[rtb_Product_j_tmp + 3] *
        rtb_NormalizeDen;
    }

    rtb_Product_j_tmp = i << 2;
    rtb_Product_i[rtb_Product_j_tmp + 3] = rtb_Fcn1;
    rtb_Product_i[rtb_Product_j_tmp + 2] = rtb_Product_idx_1;
    rtb_Product_i[rtb_Product_j_tmp + 1] = rtb_Product_idx_0;
    rtb_Product_i[rtb_Product_j_tmp] = rtb_Product_idx_3;
  }

  /* End of Product: '<S18>/Product' */
  if (tmp) {
    /* Fcn: '<S16>/Fcn' incorporates:
     *  Constant: '<S3>/Constant'
     */
    rtb_Product_idx_1 = sin(Joystick_Visualization_2019a_P.Constant_Value_fm);

    /* Fcn: '<S16>/Fcn1' incorporates:
     *  Constant: '<S3>/Constant'
     */
    rtb_Fcn1 = cos(Joystick_Visualization_2019a_P.Constant_Value_fm);

    /* Fcn: '<S16>/Normalize Den' incorporates:
     *  Constant: '<S12>/Constant1'
     */
    rtb_Product_idx_0 = 1.0 / rt_powd_snf((rt_powd_snf
      (Joystick_Visualization_2019a_P.Constant1_Value_c[0], 2.0) + rt_powd_snf
      (Joystick_Visualization_2019a_P.Constant1_Value_c[1], 2.0)) + rt_powd_snf
      (Joystick_Visualization_2019a_P.Constant1_Value_c[2], 2.0), 0.5);

    /* Product: '<S16>/Product1' incorporates:
     *  Constant: '<S12>/Constant1'
     */
    rtb_Product_idx_3 = Joystick_Visualization_2019a_P.Constant1_Value_c[0] *
      rtb_Product_idx_0;
    rtb_NormalizeDen = Joystick_Visualization_2019a_P.Constant1_Value_c[1] *
      rtb_Product_idx_0;
    rtb_Product_idx_0 *= Joystick_Visualization_2019a_P.Constant1_Value_c[2];

    /* SignalConversion generated from: '<S16>/Matrix Concatenate' incorporates:
     *  Concatenate: '<S16>/Matrix Concatenate'
     *  Fcn: '<S16>/mat11'
     */
    Joystick_Visualization_2019a_B.MatrixConcatenate_f[0] = (1.0 - rtb_Fcn1) *
      rt_powd_snf(rtb_Product_idx_3, 2.0) + rtb_Fcn1;

    /* Fcn: '<S16>/mat21' incorporates:
     *  Fcn: '<S16>/mat12'
     */
    rtb_Product_j = rtb_Product_idx_3 * rtb_NormalizeDen * (1.0 - rtb_Fcn1);
    rtb_Product_j_0 = rtb_Product_idx_0 * rtb_Product_idx_1;

    /* SignalConversion generated from: '<S16>/Matrix Concatenate' incorporates:
     *  Concatenate: '<S16>/Matrix Concatenate'
     *  Fcn: '<S16>/mat21'
     */
    Joystick_Visualization_2019a_B.MatrixConcatenate_f[1] = rtb_Product_j +
      rtb_Product_j_0;

    /* Fcn: '<S16>/mat31' incorporates:
     *  Fcn: '<S16>/mat13'
     */
    rtb_Product_j_1 = rtb_Product_idx_3 * rtb_Product_idx_0 * (1.0 - rtb_Fcn1);
    MatrixConcatenate_f_tmp = rtb_NormalizeDen * rtb_Product_idx_1;

    /* SignalConversion generated from: '<S16>/Matrix Concatenate' incorporates:
     *  Concatenate: '<S16>/Matrix Concatenate'
     *  Constant: '<S16>/Constant9'
     *  Fcn: '<S16>/mat31'
     */
    Joystick_Visualization_2019a_B.MatrixConcatenate_f[2] = rtb_Product_j_1 -
      MatrixConcatenate_f_tmp;
    Joystick_Visualization_2019a_B.MatrixConcatenate_f[3] =
      Joystick_Visualization_2019a_P.Constant9_Value_f;

    /* SignalConversion generated from: '<S16>/Matrix Concatenate' incorporates:
     *  Concatenate: '<S16>/Matrix Concatenate'
     *  Fcn: '<S16>/mat12'
     *  Fcn: '<S16>/mat22'
     */
    Joystick_Visualization_2019a_B.MatrixConcatenate_f[4] = rtb_Product_j -
      rtb_Product_j_0;
    Joystick_Visualization_2019a_B.MatrixConcatenate_f[5] = (1.0 - rtb_Fcn1) *
      rt_powd_snf(rtb_NormalizeDen, 2.0) + rtb_Fcn1;

    /* Fcn: '<S16>/mat32' incorporates:
     *  Fcn: '<S16>/mat23'
     */
    rtb_Product_j = rtb_NormalizeDen * rtb_Product_idx_0 * (1.0 - rtb_Fcn1);
    rtb_Product_j_0 = rtb_Product_idx_3 * rtb_Product_idx_1;

    /* SignalConversion generated from: '<S16>/Matrix Concatenate' incorporates:
     *  Concatenate: '<S16>/Matrix Concatenate'
     *  Constant: '<S16>/Constant8'
     *  Fcn: '<S16>/mat32'
     */
    Joystick_Visualization_2019a_B.MatrixConcatenate_f[6] = rtb_Product_j +
      rtb_Product_j_0;
    Joystick_Visualization_2019a_B.MatrixConcatenate_f[7] =
      Joystick_Visualization_2019a_P.Constant8_Value_d;

    /* Concatenate: '<S16>/Matrix Concatenate' incorporates:
     *  Fcn: '<S16>/mat13'
     *  Fcn: '<S16>/mat23'
     *  Fcn: '<S16>/mat33'
     *  SignalConversion generated from: '<S16>/Matrix Concatenate'
     */
    Joystick_Visualization_2019a_B.MatrixConcatenate_f[8] = rtb_Product_j_1 +
      MatrixConcatenate_f_tmp;
    Joystick_Visualization_2019a_B.MatrixConcatenate_f[9] = rtb_Product_j -
      rtb_Product_j_0;
    Joystick_Visualization_2019a_B.MatrixConcatenate_f[10] = (1.0 - rtb_Fcn1) *
      rt_powd_snf(rtb_Product_idx_0, 2.0) + rtb_Fcn1;

    /* SignalConversion generated from: '<S16>/Matrix Concatenate' incorporates:
     *  Concatenate: '<S16>/Matrix Concatenate'
     *  Constant: '<S16>/Constant7'
     */
    Joystick_Visualization_2019a_B.MatrixConcatenate_f[11] =
      Joystick_Visualization_2019a_P.Constant7_Value_e;

    /* Constant: '<S16>/Constant5' incorporates:
     *  Concatenate: '<S16>/Matrix Concatenate'
     */
    Joystick_Visualization_2019a_B.MatrixConcatenate_f[12] =
      Joystick_Visualization_2019a_P.Constant5_Value_p[0];
    Joystick_Visualization_2019a_B.MatrixConcatenate_f[13] =
      Joystick_Visualization_2019a_P.Constant5_Value_p[1];
    Joystick_Visualization_2019a_B.MatrixConcatenate_f[14] =
      Joystick_Visualization_2019a_P.Constant5_Value_p[2];
    Joystick_Visualization_2019a_B.MatrixConcatenate_f[15] =
      Joystick_Visualization_2019a_P.Constant5_Value_p[3];

    /* Fcn: '<S17>/Fcn' incorporates:
     *  Constant: '<S3>/Constant'
     */
    rtb_Fcn1 = sin(Joystick_Visualization_2019a_P.Constant_Value_fm);

    /* Fcn: '<S17>/Fcn1' incorporates:
     *  Constant: '<S3>/Constant'
     */
    rtb_Product_idx_1 = cos(Joystick_Visualization_2019a_P.Constant_Value_fm);

    /* Fcn: '<S17>/Normalize Den' incorporates:
     *  Constant: '<S12>/Constant2'
     */
    rtb_Product_idx_0 = 1.0 / rt_powd_snf((rt_powd_snf
      (Joystick_Visualization_2019a_P.Constant2_Value[0], 2.0) + rt_powd_snf
      (Joystick_Visualization_2019a_P.Constant2_Value[1], 2.0)) + rt_powd_snf
      (Joystick_Visualization_2019a_P.Constant2_Value[2], 2.0), 0.5);

    /* Product: '<S17>/Product1' incorporates:
     *  Constant: '<S12>/Constant2'
     */
    rtb_Product_idx_3 = Joystick_Visualization_2019a_P.Constant2_Value[0] *
      rtb_Product_idx_0;
    rtb_NormalizeDen = Joystick_Visualization_2019a_P.Constant2_Value[1] *
      rtb_Product_idx_0;
    rtb_Product_idx_0 *= Joystick_Visualization_2019a_P.Constant2_Value[2];

    /* Fcn: '<S17>/mat31' incorporates:
     *  Fcn: '<S17>/mat13'
     */
    rtb_Product_j = rtb_Product_idx_3 * rtb_Product_idx_0 * (1.0 -
      rtb_Product_idx_1);
    rtb_Product_j_0 = rtb_NormalizeDen * rtb_Fcn1;

    /* Concatenate: '<S17>/Matrix Concatenate' incorporates:
     *  Fcn: '<S17>/mat31'
     *  SignalConversion generated from: '<S17>/Matrix Concatenate'
     */
    Joystick_Visualization_2019a_B.MatrixConcatenate_o[2] = rtb_Product_j -
      rtb_Product_j_0;

    /* SignalConversion generated from: '<S17>/Matrix Concatenate' incorporates:
     *  Concatenate: '<S17>/Matrix Concatenate'
     *  Fcn: '<S17>/mat11'
     */
    Joystick_Visualization_2019a_B.MatrixConcatenate_o[0] = (1.0 -
      rtb_Product_idx_1) * rt_powd_snf(rtb_Product_idx_3, 2.0) +
      rtb_Product_idx_1;

    /* Fcn: '<S17>/mat21' incorporates:
     *  Fcn: '<S17>/mat12'
     */
    rtb_Product_j_1 = rtb_Product_idx_3 * rtb_NormalizeDen * (1.0 -
      rtb_Product_idx_1);
    MatrixConcatenate_f_tmp = rtb_Product_idx_0 * rtb_Fcn1;

    /* SignalConversion generated from: '<S17>/Matrix Concatenate' incorporates:
     *  Concatenate: '<S17>/Matrix Concatenate'
     *  Constant: '<S17>/Constant9'
     *  Fcn: '<S17>/mat21'
     */
    Joystick_Visualization_2019a_B.MatrixConcatenate_o[1] = rtb_Product_j_1 +
      MatrixConcatenate_f_tmp;
    Joystick_Visualization_2019a_B.MatrixConcatenate_o[3] =
      Joystick_Visualization_2019a_P.Constant9_Value_j;

    /* Fcn: '<S17>/mat32' incorporates:
     *  Fcn: '<S17>/mat23'
     */
    MatrixConcatenate_o_tmp = rtb_NormalizeDen * rtb_Product_idx_0 * (1.0 -
      rtb_Product_idx_1);
    rtb_Product_idx_3 *= rtb_Fcn1;

    /* Concatenate: '<S17>/Matrix Concatenate' incorporates:
     *  Fcn: '<S17>/mat32'
     *  SignalConversion generated from: '<S17>/Matrix Concatenate'
     */
    Joystick_Visualization_2019a_B.MatrixConcatenate_o[6] =
      MatrixConcatenate_o_tmp + rtb_Product_idx_3;

    /* SignalConversion generated from: '<S17>/Matrix Concatenate' incorporates:
     *  Concatenate: '<S17>/Matrix Concatenate'
     *  Constant: '<S17>/Constant8'
     *  Fcn: '<S17>/mat12'
     *  Fcn: '<S17>/mat22'
     */
    Joystick_Visualization_2019a_B.MatrixConcatenate_o[4] = rtb_Product_j_1 -
      MatrixConcatenate_f_tmp;
    Joystick_Visualization_2019a_B.MatrixConcatenate_o[5] = (1.0 -
      rtb_Product_idx_1) * rt_powd_snf(rtb_NormalizeDen, 2.0) +
      rtb_Product_idx_1;
    Joystick_Visualization_2019a_B.MatrixConcatenate_o[7] =
      Joystick_Visualization_2019a_P.Constant8_Value_g;

    /* SignalConversion generated from: '<S17>/Matrix Concatenate' incorporates:
     *  Concatenate: '<S17>/Matrix Concatenate'
     *  Constant: '<S17>/Constant7'
     *  Fcn: '<S17>/mat13'
     *  Fcn: '<S17>/mat23'
     *  Fcn: '<S17>/mat33'
     */
    Joystick_Visualization_2019a_B.MatrixConcatenate_o[8] = rtb_Product_j +
      rtb_Product_j_0;
    Joystick_Visualization_2019a_B.MatrixConcatenate_o[9] =
      MatrixConcatenate_o_tmp - rtb_Product_idx_3;
    Joystick_Visualization_2019a_B.MatrixConcatenate_o[10] = (1.0 -
      rtb_Product_idx_1) * rt_powd_snf(rtb_Product_idx_0, 2.0) +
      rtb_Product_idx_1;
    Joystick_Visualization_2019a_B.MatrixConcatenate_o[11] =
      Joystick_Visualization_2019a_P.Constant7_Value_g;

    /* Constant: '<S17>/Constant5' incorporates:
     *  Concatenate: '<S17>/Matrix Concatenate'
     */
    Joystick_Visualization_2019a_B.MatrixConcatenate_o[12] =
      Joystick_Visualization_2019a_P.Constant5_Value_m[0];
    Joystick_Visualization_2019a_B.MatrixConcatenate_o[13] =
      Joystick_Visualization_2019a_P.Constant5_Value_m[1];
    Joystick_Visualization_2019a_B.MatrixConcatenate_o[14] =
      Joystick_Visualization_2019a_P.Constant5_Value_m[2];
    Joystick_Visualization_2019a_B.MatrixConcatenate_o[15] =
      Joystick_Visualization_2019a_P.Constant5_Value_m[3];
  }

  /* Product: '<S16>/Product' incorporates:
   *  Concatenate: '<S16>/Matrix Concatenate'
   *  Product: '<S17>/Product'
   */
  for (i = 0; i < 4; i++) {
    rtb_Product_idx_3 = 0.0;
    rtb_Product_idx_0 = 0.0;
    rtb_Product_idx_1 = 0.0;
    rtb_Fcn1 = 0.0;
    for (i_0 = 0; i_0 < 4; i_0++) {
      rtb_NormalizeDen = Joystick_Visualization_2019a_B.MatrixConcatenate_f[(i <<
        2) + i_0];
      rtb_Product_j_tmp = i_0 << 2;
      rtb_Product_idx_3 += rtb_Product_i[rtb_Product_j_tmp] * rtb_NormalizeDen;
      rtb_Product_idx_0 += rtb_Product_i[rtb_Product_j_tmp + 1] *
        rtb_NormalizeDen;
      rtb_Product_idx_1 += rtb_Product_i[rtb_Product_j_tmp + 2] *
        rtb_NormalizeDen;
      rtb_Fcn1 += rtb_Product_i[rtb_Product_j_tmp + 3] * rtb_NormalizeDen;
    }

    rtb_Product_j_tmp = i << 2;
    rtb_Product_i_0[rtb_Product_j_tmp + 3] = rtb_Fcn1;
    rtb_Product_i_0[rtb_Product_j_tmp + 2] = rtb_Product_idx_1;
    rtb_Product_i_0[rtb_Product_j_tmp + 1] = rtb_Product_idx_0;
    rtb_Product_i_0[rtb_Product_j_tmp] = rtb_Product_idx_3;
  }

  /* End of Product: '<S16>/Product' */

  /* Product: '<S17>/Product' incorporates:
   *  Concatenate: '<S17>/Matrix Concatenate'
   */
  for (i = 0; i < 4; i++) {
    rtb_Product_idx_3 = 0.0;
    rtb_Product_idx_0 = 0.0;
    rtb_Product_idx_1 = 0.0;
    rtb_Fcn1 = 0.0;
    for (i_0 = 0; i_0 < 4; i_0++) {
      rtb_NormalizeDen = Joystick_Visualization_2019a_B.MatrixConcatenate_o[(i <<
        2) + i_0];
      rtb_Product_j_tmp = i_0 << 2;
      rtb_Product_idx_3 += rtb_Product_i_0[rtb_Product_j_tmp] * rtb_NormalizeDen;
      rtb_Product_idx_0 += rtb_Product_i_0[rtb_Product_j_tmp + 1] *
        rtb_NormalizeDen;
      rtb_Product_idx_1 += rtb_Product_i_0[rtb_Product_j_tmp + 2] *
        rtb_NormalizeDen;
      rtb_Fcn1 += rtb_Product_i_0[rtb_Product_j_tmp + 3] * rtb_NormalizeDen;
    }

    rtb_Product_j_tmp = i << 2;
    rtb_Product_i[rtb_Product_j_tmp + 3] = rtb_Fcn1;
    rtb_Product_i[rtb_Product_j_tmp + 2] = rtb_Product_idx_1;
    rtb_Product_i[rtb_Product_j_tmp + 1] = rtb_Product_idx_0;
    rtb_Product_i[rtb_Product_j_tmp] = rtb_Product_idx_3;
  }

  /* End of Product: '<S17>/Product' */

  /* S-Function (visualization_set_variables_block): '<S3>/Visualization Set Variables' */

  /* S-Function Block: Joystick_Visualization_2019a/Simple Drone  Visualization/Visualization Set Variables (visualization_set_variables_block) */
  {
    t_error result;
    t_uint32 memory_size;
    t_single * memory_data;
    t_double current_time;
    if (rtmIsMajorTimeStep(Joystick_Visualization_2019a_M)) {
      current_time = Joystick_Visualization_2019a_M->Timing.t[0];
      result = visualization_get_memory
        (Joystick_Visualization_2019a_DW.VisualizationInitialize_Visuali,
         &memory_data, &memory_size);
      if (result == 0 && memory_data != NULL) {
        t_single * data;
        if (16 > memory_size) {
          rtmSetErrorStatus(Joystick_Visualization_2019a_M,
                            "Variable offset + length exceeds size of visualization memory!");
          return;
        }

        data = &memory_data[0];

        {
          int_T i1;
          const real_T *u0 = &rtb_Product_h[0];
          for (i1=0; i1 < 16; i1++) {
            data[i1] = (t_single) u0[i1];
          }
        }

        if (48 > memory_size) {
          rtmSetErrorStatus(Joystick_Visualization_2019a_M,
                            "Variable offset + length exceeds size of visualization memory!");
          return;
        }

        data = &memory_data[32];

        {
          int_T i1;
          const real_T *u1 = &rtb_Product_b[0];
          for (i1=0; i1 < 16; i1++) {
            data[i1] = (t_single) u1[i1];
          }
        }

        if (32 > memory_size) {
          rtmSetErrorStatus(Joystick_Visualization_2019a_M,
                            "Variable offset + length exceeds size of visualization memory!");
          return;
        }

        data = &memory_data[16];

        {
          int_T i1;
          const real_T *u2 = &rtb_Product_i[0];
          for (i1=0; i1 < 16; i1++) {
            data[i1] = (t_single) u2[i1];
          }
        }

        result = visualization_release_memory
          (Joystick_Visualization_2019a_DW.VisualizationInitialize_Visuali);
        if (result == 0) {
          if (current_time -
              Joystick_Visualization_2019a_DW.VisualizationSetVariables_PrevT >=
              0.033) {
            Joystick_Visualization_2019a_DW.VisualizationSetVariables_PrevT =
              current_time;
            result = visualization_flush
              (Joystick_Visualization_2019a_DW.VisualizationInitialize_Visuali);
          }
        }
      }

      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Joystick_Visualization_2019a_M, _rt_error_message);
        return;
      }
    }
  }

  /* S-Function (stop_with_error_block): '<S14>/Stop with Error' */

  /* S-Function Block: Joystick_Visualization_2019a/Simple Drone  Visualization/Pose Conditioning/Stop with Error (stop_with_error_block) */
  {
    if (Joystick_Visualization_2019a_B.ManualSwitch1[7]) {
      rtmSetErrorStatus(Joystick_Visualization_2019a_M, "E-Stop Toggled!");
      return;
    }
  }

  if (tmp) {
    /* MATLAB Function: '<S22>/Signmoid Type' incorporates:
     *  Constant: '<S22>/Constant'
     */
    Joystick_Visualization_2019a_DW.sfEvent = Joystick_Visualizati_CALL_EVENT;

    /* MATLAB Function 'Simple Drone  Visualization/Pose Conditioning/Command Conditioning via Sigmoids/Signmoid Type': '<S27>:1' */
    /* '<S27>:1:18' */
    Joystick_Visualization_2019a_B.sigmoid_type = 0.0;
    switch ((int32_T)Joystick_Visualization_2019a_P.Constant_Value_ab) {
     case 1:
      /* '<S27>:1:22' */
      Joystick_Visualization_2019a_B.sigmoid_type = 1.0;
      break;

     case 2:
      /* '<S27>:1:24' */
      Joystick_Visualization_2019a_B.sigmoid_type = 1.0;
      break;

     case 3:
      /* '<S27>:1:26' */
      Joystick_Visualization_2019a_B.sigmoid_type = 2.0;
      break;

     case 4:
      /* '<S27>:1:28' */
      Joystick_Visualization_2019a_B.sigmoid_type = 4.0;
      break;

     case 5:
      /* '<S27>:1:30' */
      Joystick_Visualization_2019a_B.sigmoid_type = 3.0;
      break;

     case 6:
      /* '<S27>:1:32' */
      Joystick_Visualization_2019a_B.sigmoid_type = 5.0;
      break;

     case 7:
      /* '<S27>:1:34' */
      Joystick_Visualization_2019a_B.sigmoid_type = 1.0;
      break;

     case 8:
      /* '<S27>:1:36' */
      Joystick_Visualization_2019a_B.sigmoid_type = 1.0;
      break;

     case 9:
      /* '<S27>:1:38' */
      Joystick_Visualization_2019a_B.sigmoid_type = 1.0;
      break;
    }

    /* End of MATLAB Function: '<S22>/Signmoid Type' */
  }

  /* Switch: '<S14>/Switch' */
  if (Joystick_Visualization_2019a_B.ManualSwitch1[6] >
      Joystick_Visualization_2019a_P.Switch_Threshold) {
    /* Switch: '<S14>/Switch' incorporates:
     *  Gain: '<S14>/Gain'
     */
    Joystick_Visualization_2019a_B.Switch[0] =
      Joystick_Visualization_2019a_P.Gain_Gain_f[0] *
      Joystick_Visualization_2019a_B.ManualSwitch1[1];
    Joystick_Visualization_2019a_B.Switch[1] =
      Joystick_Visualization_2019a_P.Gain_Gain_f[1] *
      Joystick_Visualization_2019a_B.ManualSwitch1[2];
    Joystick_Visualization_2019a_B.Switch[2] =
      Joystick_Visualization_2019a_P.Gain_Gain_f[2] *
      Joystick_Visualization_2019a_B.ManualSwitch1[3];
    Joystick_Visualization_2019a_B.Switch[3] =
      Joystick_Visualization_2019a_P.Gain_Gain_f[3] *
      Joystick_Visualization_2019a_B.ManualSwitch1[4];
  } else {
    /* Switch: '<S14>/Switch' incorporates:
     *  Constant: '<S14>/Default input '
     */
    Joystick_Visualization_2019a_B.Switch[0] =
      Joystick_Visualization_2019a_P.Defaultinput_Value[0];
    Joystick_Visualization_2019a_B.Switch[1] =
      Joystick_Visualization_2019a_P.Defaultinput_Value[1];
    Joystick_Visualization_2019a_B.Switch[2] =
      Joystick_Visualization_2019a_P.Defaultinput_Value[2];
    Joystick_Visualization_2019a_B.Switch[3] =
      Joystick_Visualization_2019a_P.Defaultinput_Value[3];
  }

  /* End of Switch: '<S14>/Switch' */

  /* MATLAB Function: '<S22>/MATLAB Function2' incorporates:
   *  Constant: '<S22>/Constant2'
   *  Constant: '<S22>/Constant3'
   */
  Joystick_Visualization_2019a_DW.sfEvent_g = Joystick_Visualizati_CALL_EVENT;

  /* MATLAB Function 'Simple Drone  Visualization/Pose Conditioning/Command Conditioning via Sigmoids/MATLAB Function2': '<S25>:1' */
  /* '<S25>:1:4' */
  Joystick_Visualization_2019a_B.enable_f = 0.0;

  /* '<S25>:1:5' */
  Joystick_Visualization_2019a_B.height_ref = 0.0;

  /* '<S25>:1:6' */
  Joystick_Visualization_2019a_B.max_height_vel = 0.0;

  /* '<S25>:1:7' */
  Joystick_Visualization_2019a_B.max_height_accel = 0.0;
  switch ((int32_T)Joystick_Visualization_2019a_B.sigmoid_type) {
   case 1:
    /* '<S25>:1:11' */
    /* '<S25>:1:12' */
    /* '<S25>:1:13' */
    Joystick_Visualization_2019a_B.max_height_vel = 0.0;

    /* '<S25>:1:14' */
    Joystick_Visualization_2019a_B.max_height_accel = 0.0;
    break;

   case 2:
    /* '<S25>:1:17' */
    /* '<S25>:1:18' */
    /* '<S25>:1:19' */
    Joystick_Visualization_2019a_B.max_height_vel = 0.0;

    /* '<S25>:1:20' */
    Joystick_Visualization_2019a_B.max_height_accel = 0.0;
    break;

   case 3:
    /* '<S25>:1:23' */
    Joystick_Visualization_2019a_B.enable_f = 1.0;

    /* '<S25>:1:24' */
    Joystick_Visualization_2019a_B.height_ref =
      Joystick_Visualization_2019a_B.Switch[2];

    /* '<S25>:1:25' */
    Joystick_Visualization_2019a_B.max_height_vel =
      Joystick_Visualization_2019a_P.Constant2_Value_d[0];

    /* '<S25>:1:26' */
    Joystick_Visualization_2019a_B.max_height_accel =
      Joystick_Visualization_2019a_P.Constant2_Value_d[1];
    break;

   case 4:
    /* '<S25>:1:29' */
    Joystick_Visualization_2019a_B.enable_f = 1.0;

    /* '<S25>:1:30' */
    Joystick_Visualization_2019a_B.height_ref =
      Joystick_Visualization_2019a_B.Switch[2];
    if ((Joystick_Visualization_2019a_B.ContinuousSigmoid2_o2 < 0.0) || (fabs
         (Joystick_Visualization_2019a_B.ContinuousSigmoid2_o1 -
          Joystick_Visualization_2019a_B.Switch[2]) <= 0.1) ||
        (Joystick_Visualization_2019a_B.Switch[2] <=
         Joystick_Visualization_2019a_B.ContinuousSigmoid2_o1)) {
      /* '<S25>:1:31' */
      /* '<S25>:1:32' */
      Joystick_Visualization_2019a_B.max_height_vel =
        Joystick_Visualization_2019a_P.Constant2_Value_d[0];

      /* '<S25>:1:33' */
      Joystick_Visualization_2019a_B.max_height_accel =
        Joystick_Visualization_2019a_P.Constant2_Value_d[1];
    } else {
      /* '<S25>:1:35' */
      Joystick_Visualization_2019a_B.max_height_vel =
        Joystick_Visualization_2019a_P.Constant3_Value[0];

      /* '<S25>:1:36' */
      Joystick_Visualization_2019a_B.max_height_accel =
        Joystick_Visualization_2019a_P.Constant3_Value[1];
    }
    break;

   case 5:
    /* '<S25>:1:39' */
    Joystick_Visualization_2019a_B.enable_f = 1.0;

    /* '<S25>:1:40' */
    if (Joystick_Visualization_2019a_B.ContinuousSigmoid2_o2 >= 0.0) {
      /* '<S25>:1:41' */
      /* '<S25>:1:42' */
      Joystick_Visualization_2019a_B.max_height_vel =
        Joystick_Visualization_2019a_P.Constant2_Value_d[0];

      /* '<S25>:1:43' */
      Joystick_Visualization_2019a_B.max_height_accel =
        Joystick_Visualization_2019a_P.Constant2_Value_d[1];
    } else {
      /* '<S25>:1:45' */
      Joystick_Visualization_2019a_B.max_height_vel =
        Joystick_Visualization_2019a_P.Constant3_Value[0];

      /* '<S25>:1:46' */
      Joystick_Visualization_2019a_B.max_height_accel =
        Joystick_Visualization_2019a_P.Constant3_Value[1];
    }
    break;
  }

  /* End of MATLAB Function: '<S22>/MATLAB Function2' */
  if (tmp) {
    /* SignalConversion generated from: '<S28>/Enable' */
    Joystick_Visualization_2019a_B.HiddenBuf_InsertedFor_Usedeshei =
      Joystick_Visualization_2019a_B.enable_f;
  }

  /* MATLAB Function: '<S22>/MATLAB Function4' incorporates:
   *  Constant: '<S22>/Constant5'
   *  Constant: '<S22>/Constant6'
   */
  Joystick_Visualization_2019a_DW.sfEvent_d = Joystick_Visualizati_CALL_EVENT;

  /* MATLAB Function 'Simple Drone  Visualization/Pose Conditioning/Command Conditioning via Sigmoids/MATLAB Function4': '<S26>:1' */
  /* '<S26>:1:4' */
  Joystick_Visualization_2019a_B.enable = 0.0;

  /* '<S26>:1:5' */
  Joystick_Visualization_2019a_B.yaw_ref = 0.0;

  /* '<S26>:1:6' */
  Joystick_Visualization_2019a_B.max_yaw_vel = 0.0;

  /* '<S26>:1:7' */
  Joystick_Visualization_2019a_B.max_yaw_accel = 0.0;
  switch ((int32_T)Joystick_Visualization_2019a_B.sigmoid_type) {
   case 1:
    /* '<S26>:1:11' */
    /* '<S26>:1:12' */
    /* '<S26>:1:13' */
    Joystick_Visualization_2019a_B.max_yaw_vel = 0.0;

    /* '<S26>:1:14' */
    Joystick_Visualization_2019a_B.max_yaw_accel = 0.0;
    break;

   case 2:
    /* '<S26>:1:16' */
    Joystick_Visualization_2019a_B.enable = 1.0;

    /* '<S26>:1:17' */
    Joystick_Visualization_2019a_B.yaw_ref =
      Joystick_Visualization_2019a_B.Switch[3];

    /* '<S26>:1:18' */
    Joystick_Visualization_2019a_B.max_yaw_vel =
      Joystick_Visualization_2019a_P.Constant5_Value_py[0];

    /* '<S26>:1:19' */
    Joystick_Visualization_2019a_B.max_yaw_accel =
      Joystick_Visualization_2019a_P.Constant5_Value_py[1];
    break;

   case 3:
    /* '<S26>:1:21' */
    Joystick_Visualization_2019a_B.enable = 1.0;

    /* '<S26>:1:22' */
    Joystick_Visualization_2019a_B.yaw_ref =
      Joystick_Visualization_2019a_B.Switch[3];

    /* '<S26>:1:23' */
    Joystick_Visualization_2019a_B.max_yaw_vel =
      Joystick_Visualization_2019a_P.Constant6_Value_b[0];

    /* '<S26>:1:24' */
    Joystick_Visualization_2019a_B.max_yaw_accel =
      Joystick_Visualization_2019a_P.Constant6_Value_b[1];
    break;

   case 4:
    /* '<S26>:1:26' */
    Joystick_Visualization_2019a_B.enable = 1.0;

    /* '<S26>:1:27' */
    Joystick_Visualization_2019a_B.yaw_ref =
      Joystick_Visualization_2019a_B.Switch[3];
    if ((Joystick_Visualization_2019a_B.ContinuousSigmoid3_o2 < 0.0) ||
        (Joystick_Visualization_2019a_B.Switch[3] <
         Joystick_Visualization_2019a_B.ContinuousSigmoid3_o1) || (fabs
         (Joystick_Visualization_2019a_B.ContinuousSigmoid3_o1 -
          Joystick_Visualization_2019a_B.Switch[3]) <= 0.2)) {
      /* '<S26>:1:28' */
      /* '<S26>:1:29' */
      Joystick_Visualization_2019a_B.max_yaw_vel =
        Joystick_Visualization_2019a_P.Constant6_Value_b[0];

      /* '<S26>:1:30' */
      Joystick_Visualization_2019a_B.max_yaw_accel =
        Joystick_Visualization_2019a_P.Constant6_Value_b[1];
    } else {
      /* '<S26>:1:32' */
      Joystick_Visualization_2019a_B.max_yaw_vel =
        Joystick_Visualization_2019a_P.Constant5_Value_py[0];

      /* '<S26>:1:33' */
      Joystick_Visualization_2019a_B.max_yaw_accel =
        Joystick_Visualization_2019a_P.Constant5_Value_py[1];
    }
    break;

   case 5:
    /* '<S26>:1:36' */
    Joystick_Visualization_2019a_B.enable = 1.0;

    /* '<S26>:1:37' */
    Joystick_Visualization_2019a_B.yaw_ref =
      Joystick_Visualization_2019a_B.Switch[3];
    if (Joystick_Visualization_2019a_B.ContinuousSigmoid3_o2 >= 0.0) {
      /* '<S26>:1:38' */
      /* '<S26>:1:39' */
      Joystick_Visualization_2019a_B.max_yaw_vel =
        Joystick_Visualization_2019a_P.Constant6_Value_b[0];

      /* '<S26>:1:40' */
      Joystick_Visualization_2019a_B.max_yaw_accel =
        Joystick_Visualization_2019a_P.Constant6_Value_b[1];
    } else {
      /* '<S26>:1:42' */
      Joystick_Visualization_2019a_B.max_yaw_vel =
        Joystick_Visualization_2019a_P.Constant5_Value_py[0];

      /* '<S26>:1:43' */
      Joystick_Visualization_2019a_B.max_yaw_accel =
        Joystick_Visualization_2019a_P.Constant5_Value_py[1];
    }
    break;
  }

  /* End of MATLAB Function: '<S22>/MATLAB Function4' */
  if (tmp) {
    /* SignalConversion generated from: '<S29>/Enable' */
    Joystick_Visualization_2019a_B.HiddenBuf_InsertedFor_Usedesyaw =
      Joystick_Visualization_2019a_B.enable;

    /* Memory: '<S22>/Memory' */
    Joystick_Visualization_2019a_B.Memory[0] =
      Joystick_Visualization_2019a_DW.Memory_PreviousInput[0];
    Joystick_Visualization_2019a_B.Memory[1] =
      Joystick_Visualization_2019a_DW.Memory_PreviousInput[1];
    Joystick_Visualization_2019a_B.Memory[2] =
      Joystick_Visualization_2019a_DW.Memory_PreviousInput[2];
    Joystick_Visualization_2019a_B.Memory[3] =
      Joystick_Visualization_2019a_DW.Memory_PreviousInput[3];
  }

  /* MATLAB Function: '<S22>/MATLAB Function' incorporates:
   *  Constant: '<S22>/Constant8'
   *  Constant: '<S22>/Constant9'
   */
  Joystick_Visualization_2019a_DW.sfEvent_n = Joystick_Visualizati_CALL_EVENT;

  /* MATLAB Function 'Simple Drone  Visualization/Pose Conditioning/Command Conditioning via Sigmoids/MATLAB Function': '<S23>:1' */
  /* '<S23>:1:4' */
  Joystick_Visualization_2019a_B.enable_m = 0.0;

  /* '<S23>:1:5' */
  Joystick_Visualization_2019a_B.x_ref = 0.0;

  /* '<S23>:1:6' */
  Joystick_Visualization_2019a_B.max_x_vel = 0.0;

  /* '<S23>:1:7' */
  Joystick_Visualization_2019a_B.max_x_accel = 0.0;
  switch ((int32_T)Joystick_Visualization_2019a_B.sigmoid_type) {
   case 1:
    /* '<S23>:1:11' */
    Joystick_Visualization_2019a_B.enable_m = 1.0;

    /* '<S23>:1:12' */
    Joystick_Visualization_2019a_B.x_ref =
      Joystick_Visualization_2019a_B.Memory[0];

    /* '<S23>:1:13' */
    Joystick_Visualization_2019a_B.max_x_vel =
      Joystick_Visualization_2019a_P.Constant9_Value_b[0];

    /* '<S23>:1:14' */
    Joystick_Visualization_2019a_B.max_x_accel =
      Joystick_Visualization_2019a_P.Constant9_Value_b[1];
    break;

   case 2:
    /* '<S23>:1:17' */
    Joystick_Visualization_2019a_B.enable_m = 1.0;

    /* '<S23>:1:18' */
    Joystick_Visualization_2019a_B.x_ref =
      Joystick_Visualization_2019a_B.Memory[0];

    /* '<S23>:1:19' */
    Joystick_Visualization_2019a_B.max_x_vel =
      Joystick_Visualization_2019a_P.Constant9_Value_b[0];

    /* '<S23>:1:20' */
    Joystick_Visualization_2019a_B.max_x_accel =
      Joystick_Visualization_2019a_P.Constant9_Value_b[1];
    break;

   case 3:
    /* '<S23>:1:23' */
    Joystick_Visualization_2019a_B.enable_m = 1.0;

    /* '<S23>:1:24' */
    Joystick_Visualization_2019a_B.x_ref =
      Joystick_Visualization_2019a_B.Switch[0];

    /* '<S23>:1:25' */
    Joystick_Visualization_2019a_B.max_x_vel =
      Joystick_Visualization_2019a_P.Constant8_Value_k[0];

    /* '<S23>:1:26' */
    Joystick_Visualization_2019a_B.max_x_accel =
      Joystick_Visualization_2019a_P.Constant8_Value_k[1];
    break;

   case 4:
    /* '<S23>:1:29' */
    Joystick_Visualization_2019a_B.enable_m = 1.0;

    /* '<S23>:1:30' */
    Joystick_Visualization_2019a_B.x_ref =
      Joystick_Visualization_2019a_B.Switch[0];
    if (fabs(Joystick_Visualization_2019a_B.ContinuousSigmoid_o1 -
             Joystick_Visualization_2019a_B.Switch[0]) <= 0.02) {
      /* '<S23>:1:31' */
      /* '<S23>:1:32' */
      Joystick_Visualization_2019a_B.max_x_vel =
        Joystick_Visualization_2019a_P.Constant8_Value_k[0];

      /* '<S23>:1:33' */
      Joystick_Visualization_2019a_B.max_x_accel =
        Joystick_Visualization_2019a_P.Constant8_Value_k[1];
    } else {
      /* '<S23>:1:35' */
      Joystick_Visualization_2019a_B.max_x_vel =
        Joystick_Visualization_2019a_P.Constant9_Value_b[0];

      /* '<S23>:1:36' */
      Joystick_Visualization_2019a_B.max_x_accel =
        Joystick_Visualization_2019a_P.Constant9_Value_b[1];
    }
    break;

   case 5:
    /* '<S23>:1:39' */
    Joystick_Visualization_2019a_B.enable_m = 1.0;

    /* '<S23>:1:40' */
    Joystick_Visualization_2019a_B.x_ref =
      Joystick_Visualization_2019a_B.Switch[0];
    if (fabs(Joystick_Visualization_2019a_B.ContinuousSigmoid_o1 -
             Joystick_Visualization_2019a_B.Switch[0]) <= 0.02) {
      /* '<S23>:1:41' */
      /* '<S23>:1:42' */
      Joystick_Visualization_2019a_B.max_x_vel =
        Joystick_Visualization_2019a_P.Constant8_Value_k[0];

      /* '<S23>:1:43' */
      Joystick_Visualization_2019a_B.max_x_accel =
        Joystick_Visualization_2019a_P.Constant8_Value_k[1];
    } else {
      /* '<S23>:1:45' */
      Joystick_Visualization_2019a_B.max_x_vel =
        Joystick_Visualization_2019a_P.Constant9_Value_b[0];

      /* '<S23>:1:46' */
      Joystick_Visualization_2019a_B.max_x_accel =
        Joystick_Visualization_2019a_P.Constant9_Value_b[1];
    }
    break;
  }

  /* End of MATLAB Function: '<S22>/MATLAB Function' */
  if (tmp) {
    /* SignalConversion generated from: '<S30>/Enable' */
    Joystick_Visualization_2019a_B.HiddenBuf_InsertedFor_Usedesire =
      Joystick_Visualization_2019a_B.enable_m;
  }

  /* MATLAB Function: '<S22>/MATLAB Function1' incorporates:
   *  Constant: '<S22>/Constant1'
   *  Constant: '<S22>/Constant4'
   */
  Joystick_Visualization_2019a_DW.sfEvent_i = Joystick_Visualizati_CALL_EVENT;

  /* MATLAB Function 'Simple Drone  Visualization/Pose Conditioning/Command Conditioning via Sigmoids/MATLAB Function1': '<S24>:1' */
  /* '<S24>:1:4' */
  Joystick_Visualization_2019a_B.enable_j = 0.0;

  /* '<S24>:1:5' */
  Joystick_Visualization_2019a_B.y_ref = 0.0;

  /* '<S24>:1:6' */
  Joystick_Visualization_2019a_B.max_y_vel = 0.0;

  /* '<S24>:1:7' */
  Joystick_Visualization_2019a_B.max_y_accel = 0.0;
  switch ((int32_T)Joystick_Visualization_2019a_B.sigmoid_type) {
   case 1:
    /* '<S24>:1:11' */
    Joystick_Visualization_2019a_B.enable_j = 1.0;

    /* '<S24>:1:12' */
    Joystick_Visualization_2019a_B.y_ref =
      Joystick_Visualization_2019a_B.Memory[1];

    /* '<S24>:1:13' */
    Joystick_Visualization_2019a_B.max_y_vel =
      Joystick_Visualization_2019a_P.Constant1_Value_p[0];

    /* '<S24>:1:14' */
    Joystick_Visualization_2019a_B.max_y_accel =
      Joystick_Visualization_2019a_P.Constant1_Value_p[1];
    break;

   case 2:
    /* '<S24>:1:17' */
    Joystick_Visualization_2019a_B.enable_j = 1.0;

    /* '<S24>:1:18' */
    Joystick_Visualization_2019a_B.y_ref =
      Joystick_Visualization_2019a_B.Memory[1];

    /* '<S24>:1:19' */
    Joystick_Visualization_2019a_B.max_y_vel =
      Joystick_Visualization_2019a_P.Constant1_Value_p[0];

    /* '<S24>:1:20' */
    Joystick_Visualization_2019a_B.max_y_accel =
      Joystick_Visualization_2019a_P.Constant1_Value_p[1];
    break;

   case 3:
    /* '<S24>:1:23' */
    Joystick_Visualization_2019a_B.enable_j = 1.0;

    /* '<S24>:1:24' */
    Joystick_Visualization_2019a_B.y_ref =
      Joystick_Visualization_2019a_B.Switch[1];

    /* '<S24>:1:25' */
    Joystick_Visualization_2019a_B.max_y_vel =
      Joystick_Visualization_2019a_P.Constant4_Value[0];

    /* '<S24>:1:26' */
    Joystick_Visualization_2019a_B.max_y_accel =
      Joystick_Visualization_2019a_P.Constant4_Value[1];
    break;

   case 4:
    /* '<S24>:1:29' */
    Joystick_Visualization_2019a_B.enable_j = 1.0;

    /* '<S24>:1:30' */
    Joystick_Visualization_2019a_B.y_ref =
      Joystick_Visualization_2019a_B.Switch[1];
    if (fabs(Joystick_Visualization_2019a_B.ContinuousSigmoid1_o1 -
             Joystick_Visualization_2019a_B.Switch[1]) <= 0.02) {
      /* '<S24>:1:31' */
      /* '<S24>:1:32' */
      Joystick_Visualization_2019a_B.max_y_vel =
        Joystick_Visualization_2019a_P.Constant4_Value[0];

      /* '<S24>:1:33' */
      Joystick_Visualization_2019a_B.max_y_accel =
        Joystick_Visualization_2019a_P.Constant4_Value[1];
    } else {
      /* '<S24>:1:35' */
      Joystick_Visualization_2019a_B.max_y_vel =
        Joystick_Visualization_2019a_P.Constant1_Value_p[0];

      /* '<S24>:1:36' */
      Joystick_Visualization_2019a_B.max_y_accel =
        Joystick_Visualization_2019a_P.Constant1_Value_p[1];
    }
    break;

   case 5:
    /* '<S24>:1:39' */
    Joystick_Visualization_2019a_B.enable_j = 1.0;

    /* '<S24>:1:40' */
    Joystick_Visualization_2019a_B.y_ref =
      Joystick_Visualization_2019a_B.Switch[1];
    if (fabs(Joystick_Visualization_2019a_B.ContinuousSigmoid1_o1 -
             Joystick_Visualization_2019a_B.Switch[1]) <= 0.02) {
      /* '<S24>:1:41' */
      /* '<S24>:1:42' */
      Joystick_Visualization_2019a_B.max_y_vel =
        Joystick_Visualization_2019a_P.Constant4_Value[0];

      /* '<S24>:1:43' */
      Joystick_Visualization_2019a_B.max_y_accel =
        Joystick_Visualization_2019a_P.Constant4_Value[1];
    } else {
      /* '<S24>:1:45' */
      Joystick_Visualization_2019a_B.max_y_vel =
        Joystick_Visualization_2019a_P.Constant1_Value_p[0];

      /* '<S24>:1:46' */
      Joystick_Visualization_2019a_B.max_y_accel =
        Joystick_Visualization_2019a_P.Constant1_Value_p[1];
    }
    break;
  }

  /* End of MATLAB Function: '<S22>/MATLAB Function1' */
  if (tmp) {
    /* SignalConversion generated from: '<S31>/Enable' */
    Joystick_Visualization_2019a_B.HiddenBuf_InsertedFor_Usedesi_i =
      Joystick_Visualization_2019a_B.enable_j;
  }

  /* Outputs for Enabled SubSystem: '<S22>/Use des height  when enabled' */
  Joystic_Usedesheightwhenenabled(Joystick_Visualization_2019a_M,
    Joystick_Visualization_2019a_B.HiddenBuf_InsertedFor_Usedeshei,
    Joystick_Visualization_2019a_B.height_ref,
    &Joystick_Visualization_2019a_B.Usedesheightwhenenabled,
    &Joystick_Visualization_2019a_DW.Usedesheightwhenenabled,
    &Joystick_Visualization_2019a_P.Usedesheightwhenenabled);

  /* End of Outputs for SubSystem: '<S22>/Use des height  when enabled' */

  /* Outputs for Enabled SubSystem: '<S22>/Use des yaw  when enabled' */
  Joystic_Usedesheightwhenenabled(Joystick_Visualization_2019a_M,
    Joystick_Visualization_2019a_B.HiddenBuf_InsertedFor_Usedesyaw,
    Joystick_Visualization_2019a_B.yaw_ref,
    &Joystick_Visualization_2019a_B.Usedesyawwhenenabled,
    &Joystick_Visualization_2019a_DW.Usedesyawwhenenabled,
    &Joystick_Visualization_2019a_P.Usedesyawwhenenabled);

  /* End of Outputs for SubSystem: '<S22>/Use des yaw  when enabled' */

  /* Outputs for Enabled SubSystem: '<S22>/Use desired X  when enabled' */
  Joystic_Usedesheightwhenenabled(Joystick_Visualization_2019a_M,
    Joystick_Visualization_2019a_B.HiddenBuf_InsertedFor_Usedesire,
    Joystick_Visualization_2019a_B.x_ref,
    &Joystick_Visualization_2019a_B.UsedesiredXwhenenabled,
    &Joystick_Visualization_2019a_DW.UsedesiredXwhenenabled,
    &Joystick_Visualization_2019a_P.UsedesiredXwhenenabled);

  /* End of Outputs for SubSystem: '<S22>/Use desired X  when enabled' */

  /* Outputs for Enabled SubSystem: '<S22>/Use desired Y  when enabled' */
  Joystic_Usedesheightwhenenabled(Joystick_Visualization_2019a_M,
    Joystick_Visualization_2019a_B.HiddenBuf_InsertedFor_Usedesi_i,
    Joystick_Visualization_2019a_B.y_ref,
    &Joystick_Visualization_2019a_B.UsedesiredYwhenenabled,
    &Joystick_Visualization_2019a_DW.UsedesiredYwhenenabled,
    &Joystick_Visualization_2019a_P.UsedesiredYwhenenabled);

  /* End of Outputs for SubSystem: '<S22>/Use desired Y  when enabled' */
  if (tmp) {
    /* S-Function (host_initialize_block): '<S1>/Host Initialize' */

    /* S-Function Block: Joystick_Visualization_2019a/JOYSTICK_FRSKY/Host Initialize (host_initialize_block) */
    {
      Joystick_Visualization_2019a_B.HostInitialize_o1 =
        (rtExtModeQuarcIsConnected() ? HOST_STATE_CONNECTED :
         HOST_STATE_NOT_CONNECTED);
    }

    /* Gain: '<S1>/ rad//s//%' */
    Joystick_Visualization_2019a_B.rads =
      Joystick_Visualization_2019a_P.rads_Gain *
      Joystick_Visualization_2019a_B.Product[2];

    /* DataTypeConversion: '<S7>/Data Type Conversion' */
    Joystick_Visualization_2019a_B.DataTypeConversion = rtb_Relation;
  }
}

/* Model update function */
void Joystick_Visualization_2019a_update(void)
{
  /* Update for S-Function (continuous_sigmoid_block): '<S22>/Continuous Sigmoid' */
  if (1) {
    {
      if (Joystick_Visualization_2019a_DW.ContinuousSigmoid_Target !=
          Joystick_Visualization_2019a_B.UsedesiredXwhenenabled.h_dm1) {
        Joystick_Visualization_2019a_DW.ContinuousSigmoid_Target =
          Joystick_Visualization_2019a_B.UsedesiredXwhenenabled.h_dm1;
        Joystick_Visualization_2019a_DW.ContinuousSigmoid_Flag = 1;
      }

      if (Joystick_Visualization_2019a_B.max_x_vel !=
          Joystick_Visualization_2019a_DW.ContinuousSigmoid_MVel) {
        Joystick_Visualization_2019a_DW.ContinuousSigmoid_MVel =
          Joystick_Visualization_2019a_B.max_x_vel;
        Joystick_Visualization_2019a_DW.ContinuousSigmoid_Flag = 1;
      }

      if (Joystick_Visualization_2019a_B.max_x_accel !=
          Joystick_Visualization_2019a_DW.ContinuousSigmoid_MAcc) {
        Joystick_Visualization_2019a_DW.ContinuousSigmoid_MAcc =
          Joystick_Visualization_2019a_B.max_x_accel;
        Joystick_Visualization_2019a_DW.ContinuousSigmoid_Flag = 1;
      }
    }
  }

  /* Update for S-Function (continuous_sigmoid_block): '<S22>/Continuous Sigmoid1' */
  if (1) {
    {
      if (Joystick_Visualization_2019a_DW.ContinuousSigmoid1_Target !=
          Joystick_Visualization_2019a_B.UsedesiredYwhenenabled.h_dm1) {
        Joystick_Visualization_2019a_DW.ContinuousSigmoid1_Target =
          Joystick_Visualization_2019a_B.UsedesiredYwhenenabled.h_dm1;
        Joystick_Visualization_2019a_DW.ContinuousSigmoid1_Flag = 1;
      }

      if (Joystick_Visualization_2019a_B.max_y_vel !=
          Joystick_Visualization_2019a_DW.ContinuousSigmoid1_MVel) {
        Joystick_Visualization_2019a_DW.ContinuousSigmoid1_MVel =
          Joystick_Visualization_2019a_B.max_y_vel;
        Joystick_Visualization_2019a_DW.ContinuousSigmoid1_Flag = 1;
      }

      if (Joystick_Visualization_2019a_B.max_y_accel !=
          Joystick_Visualization_2019a_DW.ContinuousSigmoid1_MAcc) {
        Joystick_Visualization_2019a_DW.ContinuousSigmoid1_MAcc =
          Joystick_Visualization_2019a_B.max_y_accel;
        Joystick_Visualization_2019a_DW.ContinuousSigmoid1_Flag = 1;
      }
    }
  }

  /* Update for S-Function (continuous_sigmoid_block): '<S22>/Continuous Sigmoid2' */
  if (1) {
    {
      if (Joystick_Visualization_2019a_DW.ContinuousSigmoid2_Target !=
          Joystick_Visualization_2019a_B.Usedesheightwhenenabled.h_dm1) {
        Joystick_Visualization_2019a_DW.ContinuousSigmoid2_Target =
          Joystick_Visualization_2019a_B.Usedesheightwhenenabled.h_dm1;
        Joystick_Visualization_2019a_DW.ContinuousSigmoid2_Flag = 1;
      }

      if (Joystick_Visualization_2019a_B.max_height_vel !=
          Joystick_Visualization_2019a_DW.ContinuousSigmoid2_MVel) {
        Joystick_Visualization_2019a_DW.ContinuousSigmoid2_MVel =
          Joystick_Visualization_2019a_B.max_height_vel;
        Joystick_Visualization_2019a_DW.ContinuousSigmoid2_Flag = 1;
      }

      if (Joystick_Visualization_2019a_B.max_height_accel !=
          Joystick_Visualization_2019a_DW.ContinuousSigmoid2_MAcc) {
        Joystick_Visualization_2019a_DW.ContinuousSigmoid2_MAcc =
          Joystick_Visualization_2019a_B.max_height_accel;
        Joystick_Visualization_2019a_DW.ContinuousSigmoid2_Flag = 1;
      }
    }
  }

  /* Update for S-Function (continuous_sigmoid_block): '<S22>/Continuous Sigmoid3' */
  if (1) {
    {
      if (Joystick_Visualization_2019a_DW.ContinuousSigmoid3_Target !=
          Joystick_Visualization_2019a_B.Usedesyawwhenenabled.h_dm1) {
        Joystick_Visualization_2019a_DW.ContinuousSigmoid3_Target =
          Joystick_Visualization_2019a_B.Usedesyawwhenenabled.h_dm1;
        Joystick_Visualization_2019a_DW.ContinuousSigmoid3_Flag = 1;
      }

      if (Joystick_Visualization_2019a_B.max_yaw_vel !=
          Joystick_Visualization_2019a_DW.ContinuousSigmoid3_MVel) {
        Joystick_Visualization_2019a_DW.ContinuousSigmoid3_MVel =
          Joystick_Visualization_2019a_B.max_yaw_vel;
        Joystick_Visualization_2019a_DW.ContinuousSigmoid3_Flag = 1;
      }

      if (Joystick_Visualization_2019a_B.max_yaw_accel !=
          Joystick_Visualization_2019a_DW.ContinuousSigmoid3_MAcc) {
        Joystick_Visualization_2019a_DW.ContinuousSigmoid3_MAcc =
          Joystick_Visualization_2019a_B.max_yaw_accel;
        Joystick_Visualization_2019a_DW.ContinuousSigmoid3_Flag = 1;
      }
    }
  }

  if (rtmIsMajorTimeStep(Joystick_Visualization_2019a_M)) {
    /* Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
    Joystick_Visualization_2019a_DW.DiscreteTimeIntegrator_DSTATE +=
      Joystick_Visualization_2019a_P.DiscreteTimeIntegrator_gainva_k *
      Joystick_Visualization_2019a_B.DataTypeConversion;
    Joystick_Visualization_2019a_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
      Joystick_Visualization_2019a_B.LogicalOperator;

    /* Update for Enabled SubSystem: '<S1>/FrSKYMapping' incorporates:
     *  EnablePort: '<S4>/Valid Signals Detected'
     */
    if (Joystick_Visualization_2019a_DW.FrSKYMapping_MODE) {
      /* Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
      Joystick_Visualization_2019a_DW.DiscreteTimeIntegrator_DSTATE_c +=
        Joystick_Visualization_2019a_P.DiscreteTimeIntegrator_gainval *
        Joystick_Visualization_2019a_B.DataTypeConversion_j;
      Joystick_Visualization_2019a_DW.DiscreteTimeIntegrator_PrevRe_j = (int8_T)
        Joystick_Visualization_2019a_B.LogicalOperator_j;
    }

    /* End of Update for SubSystem: '<S1>/FrSKYMapping' */

    /* Update for Memory: '<S22>/Memory' */
    Joystick_Visualization_2019a_DW.Memory_PreviousInput[0] =
      Joystick_Visualization_2019a_B.Switch[0];
    Joystick_Visualization_2019a_DW.Memory_PreviousInput[1] =
      Joystick_Visualization_2019a_B.Switch[1];
    Joystick_Visualization_2019a_DW.Memory_PreviousInput[2] =
      Joystick_Visualization_2019a_B.Switch[2];
    Joystick_Visualization_2019a_DW.Memory_PreviousInput[3] =
      Joystick_Visualization_2019a_B.Switch[3];
  }

  if (rtmIsMajorTimeStep(Joystick_Visualization_2019a_M)) {
    rt_ertODEUpdateContinuousStates(&Joystick_Visualization_2019a_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Joystick_Visualization_2019a_M->Timing.clockTick0)) {
    ++Joystick_Visualization_2019a_M->Timing.clockTickH0;
  }

  Joystick_Visualization_2019a_M->Timing.t[0] = rtsiGetSolverStopTime
    (&Joystick_Visualization_2019a_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Joystick_Visualization_2019a_M->Timing.clockTick1)) {
      ++Joystick_Visualization_2019a_M->Timing.clockTickH1;
    }

    Joystick_Visualization_2019a_M->Timing.t[1] =
      Joystick_Visualization_2019a_M->Timing.clockTick1 *
      Joystick_Visualization_2019a_M->Timing.stepSize1 +
      Joystick_Visualization_2019a_M->Timing.clockTickH1 *
      Joystick_Visualization_2019a_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void Joystick_Visualization_2019a_derivatives(void)
{
  XDot_Joystick_Visualization_2_T *_rtXdot;
  _rtXdot = ((XDot_Joystick_Visualization_2_T *)
             Joystick_Visualization_2019a_M->derivs);

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE = Joystick_Visualization_2019a_B.rads;
}

/* Model initialize function */
void Joystick_Visualization_2019a_initialize(void)
{
  /* Start for S-Function (visualization_initialize_block): '<S3>/Visualization Initialize' */

  /* S-Function Block: Joystick_Visualization_2019a/Simple Drone  Visualization/Visualization Initialize (visualization_initialize_block) */
  {
    t_error result;
    result = visualization_open("shmem://Joystick_Visualization_2019a:2", "", 0,
      Joystick_Visualization_2019a_P.VisualizationInitialize_variabl, 3,
      Joystick_Visualization_2019a_P.VisualizationInitialize_initial, 48,
      Joystick_Visualization_2019a_P.VisualizationInitialize_serve_o,
      Joystick_Visualization_2019a_P.VisualizationInitialize_server_,
      &Joystick_Visualization_2019a_DW.VisualizationInitialize_Visuali);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Joystick_Visualization_2019a_M, _rt_error_message);
      return;
    }
  }

  /* Start for S-Function (continuous_sigmoid_block): '<S22>/Continuous Sigmoid' */

  /* S-Function Block: Joystick_Visualization_2019a/Simple Drone  Visualization/Pose Conditioning/Command Conditioning via Sigmoids/Continuous Sigmoid (continuous_sigmoid_block) */
  {
    real_T* params;
    params = &Joystick_Visualization_2019a_DW.ContinuousSigmoid_Sigmoid[0 *
      NUMBER_OF_SIGMOID_PARAMETERS];
    params[SIGMOID_PARAMETER_T1] = 0;
    params[SIGMOID_PARAMETER_T2] = 0;
    params[SIGMOID_PARAMETER_T3] = 0;
    params[SIGMOID_PARAMETER_X0] =
      Joystick_Visualization_2019a_P.ContinuousSigmoid_XI;
    params[SIGMOID_PARAMETER_X1] =
      Joystick_Visualization_2019a_P.ContinuousSigmoid_XI;
    params[SIGMOID_PARAMETER_X2] =
      Joystick_Visualization_2019a_P.ContinuousSigmoid_XI;
    params[SIGMOID_PARAMETER_XD] =
      Joystick_Visualization_2019a_P.ContinuousSigmoid_XI;
    params[SIGMOID_PARAMETER_V0] =
      Joystick_Visualization_2019a_P.ContinuousSigmoid_VI;
    params[SIGMOID_PARAMETER_VP] = 0;
    params[SIGMOID_PARAMETER_AP] = 0;
    params[SIGMOID_PARAMETER_HOLD_OFF] =
      Joystick_Visualization_2019a_P.ContinuousSigmoid_Hold;
    Joystick_Visualization_2019a_DW.ContinuousSigmoid_Time = 0;
    Joystick_Visualization_2019a_DW.ContinuousSigmoid_Target =
      Joystick_Visualization_2019a_P.ContinuousSigmoid_XI;
    Joystick_Visualization_2019a_DW.ContinuousSigmoid_PPos =
      Joystick_Visualization_2019a_P.ContinuousSigmoid_XI;
    Joystick_Visualization_2019a_DW.ContinuousSigmoid_PVel =
      Joystick_Visualization_2019a_P.ContinuousSigmoid_VI;
    Joystick_Visualization_2019a_DW.ContinuousSigmoid_Flag = 0;
    Joystick_Visualization_2019a_DW.ContinuousSigmoid_MVel = 0;
    Joystick_Visualization_2019a_DW.ContinuousSigmoid_MAcc = 0;
  }

  /* Start for S-Function (continuous_sigmoid_block): '<S22>/Continuous Sigmoid1' */

  /* S-Function Block: Joystick_Visualization_2019a/Simple Drone  Visualization/Pose Conditioning/Command Conditioning via Sigmoids/Continuous Sigmoid1 (continuous_sigmoid_block) */
  {
    real_T* params;
    params = &Joystick_Visualization_2019a_DW.ContinuousSigmoid1_Sigmoid[0 *
      NUMBER_OF_SIGMOID_PARAMETERS];
    params[SIGMOID_PARAMETER_T1] = 0;
    params[SIGMOID_PARAMETER_T2] = 0;
    params[SIGMOID_PARAMETER_T3] = 0;
    params[SIGMOID_PARAMETER_X0] =
      Joystick_Visualization_2019a_P.ContinuousSigmoid1_XI;
    params[SIGMOID_PARAMETER_X1] =
      Joystick_Visualization_2019a_P.ContinuousSigmoid1_XI;
    params[SIGMOID_PARAMETER_X2] =
      Joystick_Visualization_2019a_P.ContinuousSigmoid1_XI;
    params[SIGMOID_PARAMETER_XD] =
      Joystick_Visualization_2019a_P.ContinuousSigmoid1_XI;
    params[SIGMOID_PARAMETER_V0] =
      Joystick_Visualization_2019a_P.ContinuousSigmoid1_VI;
    params[SIGMOID_PARAMETER_VP] = 0;
    params[SIGMOID_PARAMETER_AP] = 0;
    params[SIGMOID_PARAMETER_HOLD_OFF] =
      Joystick_Visualization_2019a_P.ContinuousSigmoid1_Hold;
    Joystick_Visualization_2019a_DW.ContinuousSigmoid1_Time = 0;
    Joystick_Visualization_2019a_DW.ContinuousSigmoid1_Target =
      Joystick_Visualization_2019a_P.ContinuousSigmoid1_XI;
    Joystick_Visualization_2019a_DW.ContinuousSigmoid1_PPos =
      Joystick_Visualization_2019a_P.ContinuousSigmoid1_XI;
    Joystick_Visualization_2019a_DW.ContinuousSigmoid1_PVel =
      Joystick_Visualization_2019a_P.ContinuousSigmoid1_VI;
    Joystick_Visualization_2019a_DW.ContinuousSigmoid1_Flag = 0;
    Joystick_Visualization_2019a_DW.ContinuousSigmoid1_MVel = 0;
    Joystick_Visualization_2019a_DW.ContinuousSigmoid1_MAcc = 0;
  }

  /* Start for S-Function (continuous_sigmoid_block): '<S22>/Continuous Sigmoid2' */

  /* S-Function Block: Joystick_Visualization_2019a/Simple Drone  Visualization/Pose Conditioning/Command Conditioning via Sigmoids/Continuous Sigmoid2 (continuous_sigmoid_block) */
  {
    real_T* params;
    params = &Joystick_Visualization_2019a_DW.ContinuousSigmoid2_Sigmoid[0 *
      NUMBER_OF_SIGMOID_PARAMETERS];
    params[SIGMOID_PARAMETER_T1] = 0;
    params[SIGMOID_PARAMETER_T2] = 0;
    params[SIGMOID_PARAMETER_T3] = 0;
    params[SIGMOID_PARAMETER_X0] =
      Joystick_Visualization_2019a_P.ContinuousSigmoid2_XI;
    params[SIGMOID_PARAMETER_X1] =
      Joystick_Visualization_2019a_P.ContinuousSigmoid2_XI;
    params[SIGMOID_PARAMETER_X2] =
      Joystick_Visualization_2019a_P.ContinuousSigmoid2_XI;
    params[SIGMOID_PARAMETER_XD] =
      Joystick_Visualization_2019a_P.ContinuousSigmoid2_XI;
    params[SIGMOID_PARAMETER_V0] =
      Joystick_Visualization_2019a_P.ContinuousSigmoid2_VI;
    params[SIGMOID_PARAMETER_VP] = 0;
    params[SIGMOID_PARAMETER_AP] = 0;
    params[SIGMOID_PARAMETER_HOLD_OFF] =
      Joystick_Visualization_2019a_P.ContinuousSigmoid2_Hold;
    Joystick_Visualization_2019a_DW.ContinuousSigmoid2_Time = 0;
    Joystick_Visualization_2019a_DW.ContinuousSigmoid2_Target =
      Joystick_Visualization_2019a_P.ContinuousSigmoid2_XI;
    Joystick_Visualization_2019a_DW.ContinuousSigmoid2_PPos =
      Joystick_Visualization_2019a_P.ContinuousSigmoid2_XI;
    Joystick_Visualization_2019a_DW.ContinuousSigmoid2_PVel =
      Joystick_Visualization_2019a_P.ContinuousSigmoid2_VI;
    Joystick_Visualization_2019a_DW.ContinuousSigmoid2_Flag = 0;
    Joystick_Visualization_2019a_DW.ContinuousSigmoid2_MVel = 0;
    Joystick_Visualization_2019a_DW.ContinuousSigmoid2_MAcc = 0;
  }

  /* Start for S-Function (continuous_sigmoid_block): '<S22>/Continuous Sigmoid3' */

  /* S-Function Block: Joystick_Visualization_2019a/Simple Drone  Visualization/Pose Conditioning/Command Conditioning via Sigmoids/Continuous Sigmoid3 (continuous_sigmoid_block) */
  {
    real_T* params;
    params = &Joystick_Visualization_2019a_DW.ContinuousSigmoid3_Sigmoid[0 *
      NUMBER_OF_SIGMOID_PARAMETERS];
    params[SIGMOID_PARAMETER_T1] = 0;
    params[SIGMOID_PARAMETER_T2] = 0;
    params[SIGMOID_PARAMETER_T3] = 0;
    params[SIGMOID_PARAMETER_X0] =
      Joystick_Visualization_2019a_P.ContinuousSigmoid3_XI;
    params[SIGMOID_PARAMETER_X1] =
      Joystick_Visualization_2019a_P.ContinuousSigmoid3_XI;
    params[SIGMOID_PARAMETER_X2] =
      Joystick_Visualization_2019a_P.ContinuousSigmoid3_XI;
    params[SIGMOID_PARAMETER_XD] =
      Joystick_Visualization_2019a_P.ContinuousSigmoid3_XI;
    params[SIGMOID_PARAMETER_V0] =
      Joystick_Visualization_2019a_P.ContinuousSigmoid3_VI;
    params[SIGMOID_PARAMETER_VP] = 0;
    params[SIGMOID_PARAMETER_AP] = 0;
    params[SIGMOID_PARAMETER_HOLD_OFF] =
      Joystick_Visualization_2019a_P.ContinuousSigmoid3_Hold;
    Joystick_Visualization_2019a_DW.ContinuousSigmoid3_Time = 0;
    Joystick_Visualization_2019a_DW.ContinuousSigmoid3_Target =
      Joystick_Visualization_2019a_P.ContinuousSigmoid3_XI;
    Joystick_Visualization_2019a_DW.ContinuousSigmoid3_PPos =
      Joystick_Visualization_2019a_P.ContinuousSigmoid3_XI;
    Joystick_Visualization_2019a_DW.ContinuousSigmoid3_PVel =
      Joystick_Visualization_2019a_P.ContinuousSigmoid3_VI;
    Joystick_Visualization_2019a_DW.ContinuousSigmoid3_Flag = 0;
    Joystick_Visualization_2019a_DW.ContinuousSigmoid3_MVel = 0;
    Joystick_Visualization_2019a_DW.ContinuousSigmoid3_MAcc = 0;
  }

  /* Start for Enabled SubSystem: '<S1>/FrSKYMapping' */
  Joystick_Visualization_2019a_DW.FrSKYMapping_MODE = false;

  /* End of Start for SubSystem: '<S1>/FrSKYMapping' */

  /* Start for Enabled SubSystem: '<S22>/Use des height  when enabled' */
  J_Usedesheightwhenenabled_Start
    (&Joystick_Visualization_2019a_DW.Usedesheightwhenenabled);

  /* End of Start for SubSystem: '<S22>/Use des height  when enabled' */

  /* Start for Enabled SubSystem: '<S22>/Use des yaw  when enabled' */
  J_Usedesheightwhenenabled_Start
    (&Joystick_Visualization_2019a_DW.Usedesyawwhenenabled);

  /* End of Start for SubSystem: '<S22>/Use des yaw  when enabled' */

  /* Start for Enabled SubSystem: '<S22>/Use desired X  when enabled' */
  J_Usedesheightwhenenabled_Start
    (&Joystick_Visualization_2019a_DW.UsedesiredXwhenenabled);

  /* End of Start for SubSystem: '<S22>/Use desired X  when enabled' */

  /* Start for Enabled SubSystem: '<S22>/Use desired Y  when enabled' */
  J_Usedesheightwhenenabled_Start
    (&Joystick_Visualization_2019a_DW.UsedesiredYwhenenabled);

  /* End of Start for SubSystem: '<S22>/Use desired Y  when enabled' */

  /* Start for S-Function (host_initialize_block): '<S1>/Host Initialize' */

  /* S-Function Block: Joystick_Visualization_2019a/JOYSTICK_FRSKY/Host Game Controller (host_game_controller_block) */
  {
    qthread_section_init
      (&Joystick_Visualization_2019a_DW.HostGameController_Lock, NULL);
  }

  /* S-Function Block: Joystick_Visualization_2019a/JOYSTICK_FRSKY/Host Initialize (host_initialize_block) */
  {
    t_error result;
    Joystick_Visualization_2019a_B.HostInitialize_o1 = HOST_STATE_NOT_LISTENING;
    result = extmode_svr_register_connected_callback
      (host_extmode_svr_connected_callback,
       host_extmode_svr_disconnected_callback, NULL,
       &Joystick_Visualization_2019a_DW.HostInitialize_ConnectedHandle);
    if (result == 0) {
      result = extmode_svr_register_custom_action(EXT_MODE_ACTION_HOST_INTERFACE,
        host_extmode_svr_custom_action_callback, NULL);
    }

    Joystick_Visualization_2019a_B.HostInitialize_o2 = result;
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Joystick_Visualization_2019a_M, _rt_error_message);
    }

    if (rtExtModeQuarcIsConnected()) {
      /* Invoke connected callbacks explicitly since Simulink was already connected when MdlStart called */
      host_extmode_svr_connected_callback(NULL);
    }
  }

  Joystick_Visualization__PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;
  Joystick_Visualization__PrevZCX.pulsecount_Trig_ZCE = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
  Joystick_Visualization_2019a_DW.DiscreteTimeIntegrator_DSTATE =
    Joystick_Visualization_2019a_P.DiscreteTimeIntegrator_IC_e;
  Joystick_Visualization_2019a_DW.DiscreteTimeIntegrator_PrevRese = 0;

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  Joystick_Visualization_2019a_X.Integrator_CSTATE =
    Joystick_Visualization_2019a_P.Integrator_IC;

  /* InitializeConditions for Memory: '<S22>/Memory' */
  Joystick_Visualization_2019a_DW.Memory_PreviousInput[0] =
    Joystick_Visualization_2019a_P.Memory_InitialCondition;
  Joystick_Visualization_2019a_DW.Memory_PreviousInput[1] =
    Joystick_Visualization_2019a_P.Memory_InitialCondition;
  Joystick_Visualization_2019a_DW.Memory_PreviousInput[2] =
    Joystick_Visualization_2019a_P.Memory_InitialCondition;
  Joystick_Visualization_2019a_DW.Memory_PreviousInput[3] =
    Joystick_Visualization_2019a_P.Memory_InitialCondition;

  /* SystemInitialize for Enabled SubSystem: '<S1>/FrSKYMapping' */
  /* InitializeConditions for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
  Joystick_Visualization_2019a_DW.DiscreteTimeIntegrator_DSTATE_c =
    Joystick_Visualization_2019a_P.DiscreteTimeIntegrator_IC;
  Joystick_Visualization_2019a_DW.DiscreteTimeIntegrator_PrevRe_j = 0;

  /* SystemInitialize for RelationalOperator: '<S9>/Relational Operator' incorporates:
   *  Outport: '<S4>/Emergency Abort (bool)'
   */
  Joystick_Visualization_2019a_B.RelationalOperator =
    Joystick_Visualization_2019a_P.EmergencyAbortbool_Y0;

  /* SystemInitialize for Gain: '<S4>/Gain' incorporates:
   *  Outport: '<S4>/Yaw (%)'
   */
  Joystick_Visualization_2019a_B.Gain = Joystick_Visualization_2019a_P.Yaw_Y0;

  /* SystemInitialize for Bias: '<S4>/Bias' incorporates:
   *  Outport: '<S4>/Throttle (%)'
   */
  Joystick_Visualization_2019a_B.Bias =
    Joystick_Visualization_2019a_P.Throttle_Y0;

  /* SystemInitialize for SignalConversion generated from: '<S4>/y' incorporates:
   *  Outport: '<S4>/Roll (%)'
   */
  Joystick_Visualization_2019a_B.y = Joystick_Visualization_2019a_P.Roll_Y0;

  /* SystemInitialize for SignalConversion generated from: '<S4>/z' incorporates:
   *  Outport: '<S4>/Pitch (%)'
   */
  Joystick_Visualization_2019a_B.z = Joystick_Visualization_2019a_P.Pitch_Y0;

  /* SystemInitialize for Outport: '<S4>/Arm//Disarm (bool) ' incorporates:
   *  SignalConversion generated from: '<S4>/Buttons'
   */
  Joystick_Visualization_2019a_B.Buttons[1] =
    Joystick_Visualization_2019a_P.ArmDisarmbool_Y0;

  /* SystemInitialize for RelationalOperator: '<S8>/Compare' incorporates:
   *  Outport: '<S4>/Takeoff//Autoland (bool)'
   */
  Joystick_Visualization_2019a_B.Compare_j =
    Joystick_Visualization_2019a_P.TakeoffAutolandbool_Y0;

  /* End of SystemInitialize for SubSystem: '<S1>/FrSKYMapping' */

  /* SystemInitialize for Atomic SubSystem: '<S1>/Pulse Check' */
  /* SystemInitialize for Triggered SubSystem: '<S6>/pulse count ' */
  /* InitializeConditions for UnitDelay: '<S10>/Unit Delay' */
  Joystick_Visualization_2019a_DW.UnitDelay_DSTATE =
    Joystick_Visualization_2019a_P.UnitDelay_InitialCondition;

  /* SystemInitialize for Sum: '<S11>/FixPt Sum1' incorporates:
   *  Outport: '<S10>/Number of Pulses'
   */
  Joystick_Visualization_2019a_B.FixPtSum1 =
    Joystick_Visualization_2019a_P.NumberofPulses_Y0;

  /* End of SystemInitialize for SubSystem: '<S6>/pulse count ' */
  /* End of SystemInitialize for SubSystem: '<S1>/Pulse Check' */

  /* SystemInitialize for Enabled SubSystem: '<S1>/Initialization and Conditioning' */
  /* SystemInitialize for Product: '<S5>/Product2' incorporates:
   *  Outport: '<S5>/Triggers (0,1) [4]'
   */
  Joystick_Visualization_2019a_B.Product2 =
    Joystick_Visualization_2019a_P.Triggers014_Y0;

  /* SystemInitialize for Product: '<S5>/Product3' incorporates:
   *  Outport: '<S5>/Triggers (0,1) [4]'
   */
  Joystick_Visualization_2019a_B.Product3 =
    Joystick_Visualization_2019a_P.Triggers014_Y0;

  /* SystemInitialize for DataTypeConversion: '<S5>/Data Type Conversion2' incorporates:
   *  Outport: '<S5>/Triggers (0,1) [4]'
   */
  Joystick_Visualization_2019a_B.DataTypeConversion2 =
    Joystick_Visualization_2019a_P.Triggers014_Y0;

  /* SystemInitialize for DataTypeConversion: '<S5>/Data Type Conversion4' incorporates:
   *  Outport: '<S5>/Triggers (0,1) [4]'
   */
  Joystick_Visualization_2019a_B.DataTypeConversion4 =
    Joystick_Visualization_2019a_P.Triggers014_Y0;

  /* SystemInitialize for Product: '<S5>/Product1' incorporates:
   *  Outport: '<S5>/Commands (%) [4]'
   */
  Joystick_Visualization_2019a_B.Product1_e =
    Joystick_Visualization_2019a_P.Commands4_Y0;

  /* SystemInitialize for Product: '<S5>/Product' incorporates:
   *  Outport: '<S5>/Commands (%) [4]'
   */
  Joystick_Visualization_2019a_B.Product[0] =
    Joystick_Visualization_2019a_P.Commands4_Y0;
  Joystick_Visualization_2019a_B.Product[1] =
    Joystick_Visualization_2019a_P.Commands4_Y0;
  Joystick_Visualization_2019a_B.Product[2] =
    Joystick_Visualization_2019a_P.Commands4_Y0;

  /* End of SystemInitialize for SubSystem: '<S1>/Initialization and Conditioning' */

  /* SystemInitialize for MATLAB Function: '<S22>/Signmoid Type' */
  Joystick_Visualization_2019a_DW.sfEvent = Joystick_Visualizati_CALL_EVENT;

  /* SystemInitialize for MATLAB Function: '<S22>/MATLAB Function2' */
  Joystick_Visualization_2019a_DW.sfEvent_g = Joystick_Visualizati_CALL_EVENT;

  /* SystemInitialize for MATLAB Function: '<S22>/MATLAB Function4' */
  Joystick_Visualization_2019a_DW.sfEvent_d = Joystick_Visualizati_CALL_EVENT;

  /* SystemInitialize for MATLAB Function: '<S22>/MATLAB Function' */
  Joystick_Visualization_2019a_DW.sfEvent_n = Joystick_Visualizati_CALL_EVENT;

  /* SystemInitialize for MATLAB Function: '<S22>/MATLAB Function1' */
  Joystick_Visualization_2019a_DW.sfEvent_i = Joystick_Visualizati_CALL_EVENT;

  /* SystemInitialize for Enabled SubSystem: '<S22>/Use des height  when enabled' */
  Jo_Usedesheightwhenenabled_Init
    (&Joystick_Visualization_2019a_B.Usedesheightwhenenabled,
     &Joystick_Visualization_2019a_P.Usedesheightwhenenabled);

  /* End of SystemInitialize for SubSystem: '<S22>/Use des height  when enabled' */

  /* SystemInitialize for Enabled SubSystem: '<S22>/Use des yaw  when enabled' */
  Jo_Usedesheightwhenenabled_Init
    (&Joystick_Visualization_2019a_B.Usedesyawwhenenabled,
     &Joystick_Visualization_2019a_P.Usedesyawwhenenabled);

  /* End of SystemInitialize for SubSystem: '<S22>/Use des yaw  when enabled' */

  /* SystemInitialize for Enabled SubSystem: '<S22>/Use desired X  when enabled' */
  Jo_Usedesheightwhenenabled_Init
    (&Joystick_Visualization_2019a_B.UsedesiredXwhenenabled,
     &Joystick_Visualization_2019a_P.UsedesiredXwhenenabled);

  /* End of SystemInitialize for SubSystem: '<S22>/Use desired X  when enabled' */

  /* SystemInitialize for Enabled SubSystem: '<S22>/Use desired Y  when enabled' */
  Jo_Usedesheightwhenenabled_Init
    (&Joystick_Visualization_2019a_B.UsedesiredYwhenenabled,
     &Joystick_Visualization_2019a_P.UsedesiredYwhenenabled);

  /* End of SystemInitialize for SubSystem: '<S22>/Use desired Y  when enabled' */
}

/* Model terminate function */
void Joystick_Visualization_2019a_terminate(void)
{
  /* Terminate for S-Function (visualization_initialize_block): '<S3>/Visualization Initialize' */

  /* S-Function Block: Joystick_Visualization_2019a/Simple Drone  Visualization/Visualization Initialize (visualization_initialize_block) */
  {
    if (Joystick_Visualization_2019a_DW.VisualizationInitialize_Visuali != NULL)
    {
      visualization_close
        (Joystick_Visualization_2019a_DW.VisualizationInitialize_Visuali);
      Joystick_Visualization_2019a_DW.VisualizationInitialize_Visuali = NULL;
    }
  }

  /* Terminate for S-Function (host_game_controller_block): '<S1>/Host Game Controller' */

  /* S-Function Block: Joystick_Visualization_2019a/JOYSTICK_FRSKY/Host Game Controller (host_game_controller_block) */
  {
    qthread_section_destroy
      (&Joystick_Visualization_2019a_DW.HostGameController_Lock);
  }

  /* Terminate for S-Function (host_initialize_block): '<S1>/Host Initialize' */

  /* S-Function Block: Joystick_Visualization_2019a/JOYSTICK_FRSKY/Host Initialize (host_initialize_block) */
  {
    extmode_svr_unregister_custom_action(EXT_MODE_ACTION_HOST_INTERFACE);
    extmode_svr_unregister_connected_callback
      (Joystick_Visualization_2019a_DW.HostInitialize_ConnectedHandle);
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
  Joystick_Visualization_2019a_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Joystick_Visualization_2019a_update();
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
  Joystick_Visualization_2019a_initialize();
}

void MdlTerminate(void)
{
  Joystick_Visualization_2019a_terminate();
}

/* Registration function */
RT_MODEL_Joystick_Visualizati_T *Joystick_Visualization_2019a(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Joystick_Visualization_2019a_M, 0,
                sizeof(RT_MODEL_Joystick_Visualizati_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Joystick_Visualization_2019a_M->solverInfo,
                          &Joystick_Visualization_2019a_M->Timing.simTimeStep);
    rtsiSetTPtr(&Joystick_Visualization_2019a_M->solverInfo, &rtmGetTPtr
                (Joystick_Visualization_2019a_M));
    rtsiSetStepSizePtr(&Joystick_Visualization_2019a_M->solverInfo,
                       &Joystick_Visualization_2019a_M->Timing.stepSize0);
    rtsiSetdXPtr(&Joystick_Visualization_2019a_M->solverInfo,
                 &Joystick_Visualization_2019a_M->derivs);
    rtsiSetContStatesPtr(&Joystick_Visualization_2019a_M->solverInfo, (real_T **)
                         &Joystick_Visualization_2019a_M->contStates);
    rtsiSetNumContStatesPtr(&Joystick_Visualization_2019a_M->solverInfo,
      &Joystick_Visualization_2019a_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Joystick_Visualization_2019a_M->solverInfo,
      &Joystick_Visualization_2019a_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr
      (&Joystick_Visualization_2019a_M->solverInfo,
       &Joystick_Visualization_2019a_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr
      (&Joystick_Visualization_2019a_M->solverInfo,
       &Joystick_Visualization_2019a_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&Joystick_Visualization_2019a_M->solverInfo,
      (boolean_T**) &Joystick_Visualization_2019a_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&Joystick_Visualization_2019a_M->solverInfo,
                          (&rtmGetErrorStatus(Joystick_Visualization_2019a_M)));
    rtsiSetRTModelPtr(&Joystick_Visualization_2019a_M->solverInfo,
                      Joystick_Visualization_2019a_M);
  }

  rtsiSetSimTimeStep(&Joystick_Visualization_2019a_M->solverInfo,
                     MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange
    (&Joystick_Visualization_2019a_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&Joystick_Visualization_2019a_M->solverInfo, false);
  Joystick_Visualization_2019a_M->intgData.f[0] =
    Joystick_Visualization_2019a_M->odeF[0];
  Joystick_Visualization_2019a_M->contStates = ((real_T *)
    &Joystick_Visualization_2019a_X);
  Joystick_Visualization_2019a_M->contStateDisabled = ((boolean_T *)
    &Joystick_Visualization_201_XDis);
  Joystick_Visualization_2019a_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&Joystick_Visualization_2019a_M->solverInfo, (void *)
                    &Joystick_Visualization_2019a_M->intgData);
  rtsiSetSolverName(&Joystick_Visualization_2019a_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      Joystick_Visualization_2019a_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    Joystick_Visualization_2019a_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Joystick_Visualization_2019a_M->Timing.sampleTimes =
      (&Joystick_Visualization_2019a_M->Timing.sampleTimesArray[0]);
    Joystick_Visualization_2019a_M->Timing.offsetTimes =
      (&Joystick_Visualization_2019a_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Joystick_Visualization_2019a_M->Timing.sampleTimes[0] = (0.0);
    Joystick_Visualization_2019a_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    Joystick_Visualization_2019a_M->Timing.offsetTimes[0] = (0.0);
    Joystick_Visualization_2019a_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Joystick_Visualization_2019a_M,
             &Joystick_Visualization_2019a_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Joystick_Visualization_2019a_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Joystick_Visualization_2019a_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Joystick_Visualization_2019a_M, -1);
  Joystick_Visualization_2019a_M->Timing.stepSize0 = 0.001;
  Joystick_Visualization_2019a_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  Joystick_Visualization_2019a_M->Sizes.checksums[0] = (1582488308U);
  Joystick_Visualization_2019a_M->Sizes.checksums[1] = (609985076U);
  Joystick_Visualization_2019a_M->Sizes.checksums[2] = (1662047858U);
  Joystick_Visualization_2019a_M->Sizes.checksums[3] = (1640916765U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[15];
    Joystick_Visualization_2019a_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &Joystick_Visualization_2019a_DW.FrSKYMapping_SubsysRanBC;
    systemRan[2] = (sysRanDType *)
      &Joystick_Visualization_2019a_DW.InitializationandConditioning_S;
    systemRan[3] = (sysRanDType *)
      &Joystick_Visualization_2019a_DW.pulsecount_SubsysRanBC;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = (sysRanDType *)
      &Joystick_Visualization_2019a_DW.Usedesheightwhenenabled.Usedesheightwhenenabled_SubsysR;
    systemRan[11] = (sysRanDType *)
      &Joystick_Visualization_2019a_DW.Usedesyawwhenenabled.Usedesheightwhenenabled_SubsysR;
    systemRan[12] = (sysRanDType *)
      &Joystick_Visualization_2019a_DW.UsedesiredXwhenenabled.Usedesheightwhenenabled_SubsysR;
    systemRan[13] = (sysRanDType *)
      &Joystick_Visualization_2019a_DW.UsedesiredYwhenenabled.Usedesheightwhenenabled_SubsysR;
    systemRan[14] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Joystick_Visualization_2019a_M->extModeInfo,
      &Joystick_Visualization_2019a_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Joystick_Visualization_2019a_M->extModeInfo,
                        Joystick_Visualization_2019a_M->Sizes.checksums);
    rteiSetTPtr(Joystick_Visualization_2019a_M->extModeInfo, rtmGetTPtr
                (Joystick_Visualization_2019a_M));
  }

  Joystick_Visualization_2019a_M->solverInfoPtr =
    (&Joystick_Visualization_2019a_M->solverInfo);
  Joystick_Visualization_2019a_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&Joystick_Visualization_2019a_M->solverInfo, 0.001);
  rtsiSetSolverMode(&Joystick_Visualization_2019a_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Joystick_Visualization_2019a_M->blockIO = ((void *)
    &Joystick_Visualization_2019a_B);
  (void) memset(((void *) &Joystick_Visualization_2019a_B), 0,
                sizeof(B_Joystick_Visualization_2019_T));

  /* parameters */
  Joystick_Visualization_2019a_M->defaultParam = ((real_T *)
    &Joystick_Visualization_2019a_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Joystick_Visualization_2019a_X;
    Joystick_Visualization_2019a_M->contStates = (x);
    (void) memset((void *)&Joystick_Visualization_2019a_X, 0,
                  sizeof(X_Joystick_Visualization_2019_T));
  }

  /* disabled states */
  {
    boolean_T *xdis = (boolean_T *) &Joystick_Visualization_201_XDis;
    Joystick_Visualization_2019a_M->contStateDisabled = (xdis);
    (void) memset((void *)&Joystick_Visualization_201_XDis, 0,
                  sizeof(XDis_Joystick_Visualization_2_T));
  }

  /* states (dwork) */
  Joystick_Visualization_2019a_M->dwork = ((void *)
    &Joystick_Visualization_2019a_DW);
  (void) memset((void *)&Joystick_Visualization_2019a_DW, 0,
                sizeof(DW_Joystick_Visualization_201_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Joystick_Visualization_2019a_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 23;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  Joystick_Visualization_2019a_M->Sizes.numContStates = (1);/* Number of continuous states */
  Joystick_Visualization_2019a_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  Joystick_Visualization_2019a_M->Sizes.numY = (0);/* Number of model outputs */
  Joystick_Visualization_2019a_M->Sizes.numU = (0);/* Number of model inputs */
  Joystick_Visualization_2019a_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Joystick_Visualization_2019a_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Joystick_Visualization_2019a_M->Sizes.numBlocks = (188);/* Number of blocks */
  Joystick_Visualization_2019a_M->Sizes.numBlockIO = (78);/* Number of block outputs */
  Joystick_Visualization_2019a_M->Sizes.numBlockPrms = (246);/* Sum of parameter "widths" */
  return Joystick_Visualization_2019a_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
