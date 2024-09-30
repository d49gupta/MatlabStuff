/*
 * cart_trial_simple.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "cart_trial_simple".
 *
 * Model version              : 1.88
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Thu Sep 26 09:02:55 2024
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "cart_trial_simple.h"
#include "cart_trial_simple_private.h"
#include "cart_trial_simple_dt.h"

/* Block signals (default storage) */
B_cart_trial_simple_T cart_trial_simple_B;

/* Block states (default storage) */
DW_cart_trial_simple_T cart_trial_simple_DW;

/* Real-time model */
static RT_MODEL_cart_trial_simple_T cart_trial_simple_M_;
RT_MODEL_cart_trial_simple_T *const cart_trial_simple_M = &cart_trial_simple_M_;

/* Model output function */
void cart_trial_simple_output(void)
{
  /* local block i/o variables */
  real_T rtb_InverseModulus1;
  real_T rtb_Saturation;
  real_T rtb_Integrator;
  real_T rtb_AvoidDividebyZero;
  real_T temp;
  real_T *lastU;

  /* S-Function (hil_read_encoder_block): '<S2>/HIL Read Encoder1' */

  /* S-Function Block: cart_trial_simple/Quarc_Plant2/HIL Read Encoder1 (hil_read_encoder_block) */
  {
    t_error result = hil_read_encoder(cart_trial_simple_DW.HILInitialize_Card,
      &cart_trial_simple_P.HILReadEncoder1_channels, 1,
      &cart_trial_simple_DW.HILReadEncoder1_Buffer);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(cart_trial_simple_M, _rt_error_message);
    } else {
      rtb_Integrator = cart_trial_simple_DW.HILReadEncoder1_Buffer;
    }
  }

  /* Gain: '<S2>/mm//cn' */
  cart_trial_simple_B.mmcn = cart_trial_simple_P.mmcn_Gain * rtb_Integrator;

  /* S-Function (inverse_modulus_block): '<S2>/Inverse Modulus' */
  /* S-Function Block: cart_trial_simple/Quarc_Plant2/Inverse Modulus (inverse_modulus_block) */
  {
    static const real_T sampling_period = 0.001;
    real_T half_range = cart_trial_simple_P.InverseModulus_Modulus / 2.0;
    real_T du, dy;
    if (cart_trial_simple_DW.InverseModulus_FirstSample) {
      cart_trial_simple_DW.InverseModulus_FirstSample = false;
      cart_trial_simple_DW.InverseModulus_PreviousInput =
        cart_trial_simple_B.mmcn;
    }

    du = (real_T) cart_trial_simple_B.mmcn -
      cart_trial_simple_DW.InverseModulus_PreviousInput;
    if (du > half_range) {
      cart_trial_simple_DW.InverseModulus_Revolutions =
        cart_trial_simple_DW.InverseModulus_Revolutions - 1;
      dy = du - cart_trial_simple_P.InverseModulus_Modulus;
    } else if (du < -half_range) {
      cart_trial_simple_DW.InverseModulus_Revolutions =
        cart_trial_simple_DW.InverseModulus_Revolutions + 1;
      dy = du + cart_trial_simple_P.InverseModulus_Modulus;
    } else {
      dy = du;
    }

    cart_trial_simple_B.InverseModulus = cart_trial_simple_B.mmcn +
      cart_trial_simple_DW.InverseModulus_Revolutions *
      cart_trial_simple_P.InverseModulus_Modulus;
    cart_trial_simple_DW.InverseModulus_PreviousInput = cart_trial_simple_B.mmcn;
  }

  /* S-Function (hil_read_encoder_block): '<S2>/HIL Read Encoder 2' */

  /* S-Function Block: cart_trial_simple/Quarc_Plant2/HIL Read Encoder 2 (hil_read_encoder_block) */
  {
    t_error result = hil_read_encoder(cart_trial_simple_DW.HILInitialize_Card,
      &cart_trial_simple_P.HILReadEncoder2_channels, 1,
      &cart_trial_simple_DW.HILReadEncoder2_Buffer);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(cart_trial_simple_M, _rt_error_message);
    } else {
      rtb_Integrator = cart_trial_simple_DW.HILReadEncoder2_Buffer;
    }
  }

  /* Gain: '<S2>/mm//cn - 2' */
  cart_trial_simple_B.mmcn2 = cart_trial_simple_P.mmcn2_Gain * rtb_Integrator;

  /* S-Function (inverse_modulus_block): '<S2>/Inverse Modulus1' */
  /* S-Function Block: cart_trial_simple/Quarc_Plant2/Inverse Modulus1 (inverse_modulus_block) */
  {
    static const real_T sampling_period = 0.001;
    real_T half_range = cart_trial_simple_P.InverseModulus1_Modulus / 2.0;
    real_T du, dy;
    if (cart_trial_simple_DW.InverseModulus1_FirstSample) {
      cart_trial_simple_DW.InverseModulus1_FirstSample = false;
      cart_trial_simple_DW.InverseModulus1_PreviousInput =
        cart_trial_simple_B.mmcn2;
    }

    du = (real_T) cart_trial_simple_B.mmcn2 -
      cart_trial_simple_DW.InverseModulus1_PreviousInput;
    if (du > half_range) {
      cart_trial_simple_DW.InverseModulus1_Revolutions =
        cart_trial_simple_DW.InverseModulus1_Revolutions - 1;
      dy = du - cart_trial_simple_P.InverseModulus1_Modulus;
    } else if (du < -half_range) {
      cart_trial_simple_DW.InverseModulus1_Revolutions =
        cart_trial_simple_DW.InverseModulus1_Revolutions + 1;
      dy = du + cart_trial_simple_P.InverseModulus1_Modulus;
    } else {
      dy = du;
    }

    rtb_InverseModulus1 = cart_trial_simple_B.mmcn2 +
      cart_trial_simple_DW.InverseModulus1_Revolutions *
      cart_trial_simple_P.InverseModulus1_Modulus;
    cart_trial_simple_DW.InverseModulus1_PreviousInput =
      cart_trial_simple_B.mmcn2;
  }

  /* SignalGenerator: '<Root>/Signal Generator2' incorporates:
   *  Derivative: '<Root>/Derivative1'
   */
  rtb_AvoidDividebyZero = cart_trial_simple_M->Timing.t[0];
  temp = cart_trial_simple_P.SignalGenerator2_Frequency * rtb_AvoidDividebyZero;
  if (temp - floor(temp) >= 0.5) {
    /* SignalGenerator: '<Root>/Signal Generator2' */
    cart_trial_simple_B.SignalGenerator2 =
      cart_trial_simple_P.SignalGenerator2_Amplitude;
  } else {
    /* SignalGenerator: '<Root>/Signal Generator2' */
    cart_trial_simple_B.SignalGenerator2 =
      -cart_trial_simple_P.SignalGenerator2_Amplitude;
  }

  /* End of SignalGenerator: '<Root>/Signal Generator2' */

  /* Gain: '<S2>/Cable Gain' */
  cart_trial_simple_B.CableGain = cart_trial_simple_P.CableGain_Gain *
    cart_trial_simple_B.SignalGenerator2;

  /* S-Function (hil_write_analog_block): '<S2>/HIL Write Analog' */

  /* S-Function Block: cart_trial_simple/Quarc_Plant2/HIL Write Analog (hil_write_analog_block) */
  {
    t_error result;
    result = hil_write_analog(cart_trial_simple_DW.HILInitialize_Card,
      &cart_trial_simple_P.HILWriteAnalog_channels, 1,
      &cart_trial_simple_B.CableGain);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(cart_trial_simple_M, _rt_error_message);
    }
  }

  /* Derivative: '<Root>/Derivative1' */
  if ((cart_trial_simple_DW.TimeStampA >= rtb_AvoidDividebyZero) &&
      (cart_trial_simple_DW.TimeStampB >= rtb_AvoidDividebyZero)) {
    /* Derivative: '<Root>/Derivative1' */
    cart_trial_simple_B.Derivative1 = 0.0;
  } else {
    temp = cart_trial_simple_DW.TimeStampA;
    lastU = &cart_trial_simple_DW.LastUAtTimeA;
    if (cart_trial_simple_DW.TimeStampA < cart_trial_simple_DW.TimeStampB) {
      if (cart_trial_simple_DW.TimeStampB < rtb_AvoidDividebyZero) {
        temp = cart_trial_simple_DW.TimeStampB;
        lastU = &cart_trial_simple_DW.LastUAtTimeB;
      }
    } else if (cart_trial_simple_DW.TimeStampA >= rtb_AvoidDividebyZero) {
      temp = cart_trial_simple_DW.TimeStampB;
      lastU = &cart_trial_simple_DW.LastUAtTimeB;
    }

    /* Derivative: '<Root>/Derivative1' */
    cart_trial_simple_B.Derivative1 = (cart_trial_simple_B.InverseModulus -
      *lastU) / (rtb_AvoidDividebyZero - temp);
  }

  /* DiscreteIntegrator: '<S7>/Integrator' incorporates:
   *  Gain: '<S3>/Minimum sampling to time constant ratio'
   */
  rtb_Integrator = cart_trial_simple_P.FilteredDerivativeDiscreteorC_n *
    cart_trial_simple_B.Probe[0];

  /* MinMax: '<S3>/MinMax' incorporates:
   *  Constant: '<S3>/Time constant'
   */
  if ((!(rtb_Integrator >= cart_trial_simple_P.FilteredDerivativeDiscreteorC_e))
      && (!rtIsNaN(cart_trial_simple_P.FilteredDerivativeDiscreteorC_e))) {
    /* DiscreteIntegrator: '<S7>/Integrator' */
    rtb_Integrator = cart_trial_simple_P.FilteredDerivativeDiscreteorC_e;
  }

  /* End of MinMax: '<S3>/MinMax' */

  /* Fcn: '<S3>/Avoid Divide by Zero' */
  rtb_AvoidDividebyZero = (real_T)(rtb_Integrator == 0.0) *
    2.2204460492503131e-16 + rtb_Integrator;

  /* DiscreteIntegrator: '<S7>/Integrator' incorporates:
   *  Constant: '<S1>/Constant'
   */
  if (cart_trial_simple_DW.Integrator_IC_LOADING != 0) {
    cart_trial_simple_DW.Integrator_DSTATE = cart_trial_simple_B.InverseModulus;
    if (cart_trial_simple_DW.Integrator_DSTATE >=
        cart_trial_simple_P.Integrator_UpperSat) {
      cart_trial_simple_DW.Integrator_DSTATE =
        cart_trial_simple_P.Integrator_UpperSat;
    } else if (cart_trial_simple_DW.Integrator_DSTATE <=
               cart_trial_simple_P.Integrator_LowerSat) {
      cart_trial_simple_DW.Integrator_DSTATE =
        cart_trial_simple_P.Integrator_LowerSat;
    }
  }

  if ((cart_trial_simple_P.Constant_Value != 0.0) ||
      (cart_trial_simple_DW.Integrator_PrevResetState != 0)) {
    cart_trial_simple_DW.Integrator_DSTATE = cart_trial_simple_B.InverseModulus;
    if (cart_trial_simple_DW.Integrator_DSTATE >=
        cart_trial_simple_P.Integrator_UpperSat) {
      cart_trial_simple_DW.Integrator_DSTATE =
        cart_trial_simple_P.Integrator_UpperSat;
    } else if (cart_trial_simple_DW.Integrator_DSTATE <=
               cart_trial_simple_P.Integrator_LowerSat) {
      cart_trial_simple_DW.Integrator_DSTATE =
        cart_trial_simple_P.Integrator_LowerSat;
    }
  }

  if (cart_trial_simple_DW.Integrator_DSTATE >=
      cart_trial_simple_P.Integrator_UpperSat) {
    cart_trial_simple_DW.Integrator_DSTATE =
      cart_trial_simple_P.Integrator_UpperSat;
  } else if (cart_trial_simple_DW.Integrator_DSTATE <=
             cart_trial_simple_P.Integrator_LowerSat) {
    cart_trial_simple_DW.Integrator_DSTATE =
      cart_trial_simple_P.Integrator_LowerSat;
  }

  /* DiscreteIntegrator: '<S7>/Integrator' */
  rtb_Integrator = cart_trial_simple_DW.Integrator_DSTATE;

  /* Saturate: '<S7>/Saturation' */
  if (rtb_Integrator > cart_trial_simple_P.Saturation_UpperSat) {
    /* Saturate: '<S7>/Saturation' */
    rtb_Saturation = cart_trial_simple_P.Saturation_UpperSat;
  } else if (rtb_Integrator < cart_trial_simple_P.Saturation_LowerSat) {
    /* Saturate: '<S7>/Saturation' */
    rtb_Saturation = cart_trial_simple_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<S7>/Saturation' */
    rtb_Saturation = rtb_Integrator;
  }

  /* End of Saturate: '<S7>/Saturation' */

  /* Product: '<S1>/1//T' incorporates:
   *  Sum: '<S1>/Sum1'
   */
  cart_trial_simple_B.uT = 1.0 / rtb_AvoidDividebyZero *
    (cart_trial_simple_B.InverseModulus - rtb_Saturation);

  /* Gain: '<S1>/Gain' */
  rtb_AvoidDividebyZero = cart_trial_simple_P.FilteredDerivativeDiscreteorC_k *
    cart_trial_simple_B.uT;

  /* Saturate: '<S1>/[A,B]' */
  if (rtb_AvoidDividebyZero >
      cart_trial_simple_P.FilteredDerivativeDiscreteorC_d) {
    /* Saturate: '<S1>/[A,B]' */
    cart_trial_simple_B.AB = cart_trial_simple_P.FilteredDerivativeDiscreteorC_d;
  } else if (rtb_AvoidDividebyZero <
             cart_trial_simple_P.FilteredDerivativeDiscreteorCon) {
    /* Saturate: '<S1>/[A,B]' */
    cart_trial_simple_B.AB = cart_trial_simple_P.FilteredDerivativeDiscreteorCon;
  } else {
    /* Saturate: '<S1>/[A,B]' */
    cart_trial_simple_B.AB = rtb_AvoidDividebyZero;
  }

  /* End of Saturate: '<S1>/[A,B]' */
}

/* Model update function */
void cart_trial_simple_update(void)
{
  real_T *lastU;

  /* Update for Derivative: '<Root>/Derivative1' */
  if (cart_trial_simple_DW.TimeStampA == (rtInf)) {
    cart_trial_simple_DW.TimeStampA = cart_trial_simple_M->Timing.t[0];
    lastU = &cart_trial_simple_DW.LastUAtTimeA;
  } else if (cart_trial_simple_DW.TimeStampB == (rtInf)) {
    cart_trial_simple_DW.TimeStampB = cart_trial_simple_M->Timing.t[0];
    lastU = &cart_trial_simple_DW.LastUAtTimeB;
  } else if (cart_trial_simple_DW.TimeStampA < cart_trial_simple_DW.TimeStampB)
  {
    cart_trial_simple_DW.TimeStampA = cart_trial_simple_M->Timing.t[0];
    lastU = &cart_trial_simple_DW.LastUAtTimeA;
  } else {
    cart_trial_simple_DW.TimeStampB = cart_trial_simple_M->Timing.t[0];
    lastU = &cart_trial_simple_DW.LastUAtTimeB;
  }

  *lastU = cart_trial_simple_B.InverseModulus;

  /* End of Update for Derivative: '<Root>/Derivative1' */

  /* Update for DiscreteIntegrator: '<S7>/Integrator' incorporates:
   *  Constant: '<S1>/Constant'
   */
  cart_trial_simple_DW.Integrator_IC_LOADING = 0U;
  if (cart_trial_simple_P.Constant_Value == 0.0) {
    cart_trial_simple_DW.Integrator_DSTATE +=
      cart_trial_simple_P.Integrator_gainval * cart_trial_simple_B.uT;
    if (cart_trial_simple_DW.Integrator_DSTATE >=
        cart_trial_simple_P.Integrator_UpperSat) {
      cart_trial_simple_DW.Integrator_DSTATE =
        cart_trial_simple_P.Integrator_UpperSat;
    } else if (cart_trial_simple_DW.Integrator_DSTATE <=
               cart_trial_simple_P.Integrator_LowerSat) {
      cart_trial_simple_DW.Integrator_DSTATE =
        cart_trial_simple_P.Integrator_LowerSat;
    }
  }

  if (cart_trial_simple_P.Constant_Value > 0.0) {
    cart_trial_simple_DW.Integrator_PrevResetState = 1;
  } else if (cart_trial_simple_P.Constant_Value < 0.0) {
    cart_trial_simple_DW.Integrator_PrevResetState = -1;
  } else if (cart_trial_simple_P.Constant_Value == 0.0) {
    cart_trial_simple_DW.Integrator_PrevResetState = 0;
  } else {
    cart_trial_simple_DW.Integrator_PrevResetState = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S7>/Integrator' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++cart_trial_simple_M->Timing.clockTick0)) {
    ++cart_trial_simple_M->Timing.clockTickH0;
  }

  cart_trial_simple_M->Timing.t[0] = cart_trial_simple_M->Timing.clockTick0 *
    cart_trial_simple_M->Timing.stepSize0 +
    cart_trial_simple_M->Timing.clockTickH0 *
    cart_trial_simple_M->Timing.stepSize0 * 4294967296.0;

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
    if (!(++cart_trial_simple_M->Timing.clockTick1)) {
      ++cart_trial_simple_M->Timing.clockTickH1;
    }

    cart_trial_simple_M->Timing.t[1] = cart_trial_simple_M->Timing.clockTick1 *
      cart_trial_simple_M->Timing.stepSize1 +
      cart_trial_simple_M->Timing.clockTickH1 *
      cart_trial_simple_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void cart_trial_simple_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<S2>/HIL Initialize' */

  /* S-Function Block: cart_trial_simple/Quarc_Plant2/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q2_usb", "0", &cart_trial_simple_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(cart_trial_simple_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (cart_trial_simple_DW.HILInitialize_Card,
       "d0=digital;d1=digital;led=auto;update_rate=normal;decimation=1", 63);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(cart_trial_simple_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(cart_trial_simple_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(cart_trial_simple_M, _rt_error_message);
      return;
    }

    if ((cart_trial_simple_P.HILInitialize_AIPStart && !is_switching) ||
        (cart_trial_simple_P.HILInitialize_AIPEnter && is_switching)) {
      cart_trial_simple_DW.HILInitialize_AIMinimums[0] =
        (cart_trial_simple_P.HILInitialize_AILow);
      cart_trial_simple_DW.HILInitialize_AIMinimums[1] =
        (cart_trial_simple_P.HILInitialize_AILow);
      cart_trial_simple_DW.HILInitialize_AIMaximums[0] =
        cart_trial_simple_P.HILInitialize_AIHigh;
      cart_trial_simple_DW.HILInitialize_AIMaximums[1] =
        cart_trial_simple_P.HILInitialize_AIHigh;
      result = hil_set_analog_input_ranges
        (cart_trial_simple_DW.HILInitialize_Card,
         cart_trial_simple_P.HILInitialize_AIChannels, 2U,
         &cart_trial_simple_DW.HILInitialize_AIMinimums[0],
         &cart_trial_simple_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(cart_trial_simple_M, _rt_error_message);
        return;
      }
    }

    if ((cart_trial_simple_P.HILInitialize_AOPStart && !is_switching) ||
        (cart_trial_simple_P.HILInitialize_AOPEnter && is_switching)) {
      cart_trial_simple_DW.HILInitialize_AOMinimums[0] =
        (cart_trial_simple_P.HILInitialize_AOLow);
      cart_trial_simple_DW.HILInitialize_AOMinimums[1] =
        (cart_trial_simple_P.HILInitialize_AOLow);
      cart_trial_simple_DW.HILInitialize_AOMaximums[0] =
        cart_trial_simple_P.HILInitialize_AOHigh;
      cart_trial_simple_DW.HILInitialize_AOMaximums[1] =
        cart_trial_simple_P.HILInitialize_AOHigh;
      result = hil_set_analog_output_ranges
        (cart_trial_simple_DW.HILInitialize_Card,
         cart_trial_simple_P.HILInitialize_AOChannels, 2U,
         &cart_trial_simple_DW.HILInitialize_AOMinimums[0],
         &cart_trial_simple_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(cart_trial_simple_M, _rt_error_message);
        return;
      }
    }

    if ((cart_trial_simple_P.HILInitialize_AOStart && !is_switching) ||
        (cart_trial_simple_P.HILInitialize_AOEnter && is_switching)) {
      cart_trial_simple_DW.HILInitialize_AOVoltages[0] =
        cart_trial_simple_P.HILInitialize_AOInitial;
      cart_trial_simple_DW.HILInitialize_AOVoltages[1] =
        cart_trial_simple_P.HILInitialize_AOInitial;
      result = hil_write_analog(cart_trial_simple_DW.HILInitialize_Card,
        cart_trial_simple_P.HILInitialize_AOChannels, 2U,
        &cart_trial_simple_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(cart_trial_simple_M, _rt_error_message);
        return;
      }
    }

    if (cart_trial_simple_P.HILInitialize_AOReset) {
      cart_trial_simple_DW.HILInitialize_AOVoltages[0] =
        cart_trial_simple_P.HILInitialize_AOWatchdog;
      cart_trial_simple_DW.HILInitialize_AOVoltages[1] =
        cart_trial_simple_P.HILInitialize_AOWatchdog;
      result = hil_watchdog_set_analog_expiration_state
        (cart_trial_simple_DW.HILInitialize_Card,
         cart_trial_simple_P.HILInitialize_AOChannels, 2U,
         &cart_trial_simple_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(cart_trial_simple_M, _rt_error_message);
        return;
      }
    }

    if ((cart_trial_simple_P.HILInitialize_EIPStart && !is_switching) ||
        (cart_trial_simple_P.HILInitialize_EIPEnter && is_switching)) {
      cart_trial_simple_DW.HILInitialize_QuadratureModes[0] =
        cart_trial_simple_P.HILInitialize_EIQuadrature;
      cart_trial_simple_DW.HILInitialize_QuadratureModes[1] =
        cart_trial_simple_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode
        (cart_trial_simple_DW.HILInitialize_Card,
         cart_trial_simple_P.HILInitialize_EIChannels, 2U,
         (t_encoder_quadrature_mode *)
         &cart_trial_simple_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(cart_trial_simple_M, _rt_error_message);
        return;
      }
    }

    if ((cart_trial_simple_P.HILInitialize_EIStart && !is_switching) ||
        (cart_trial_simple_P.HILInitialize_EIEnter && is_switching)) {
      cart_trial_simple_DW.HILInitialize_InitialEICounts[0] =
        cart_trial_simple_P.HILInitialize_EIInitial;
      cart_trial_simple_DW.HILInitialize_InitialEICounts[1] =
        cart_trial_simple_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(cart_trial_simple_DW.HILInitialize_Card,
        cart_trial_simple_P.HILInitialize_EIChannels, 2U,
        &cart_trial_simple_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(cart_trial_simple_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (inverse_modulus_block): '<S2>/Inverse Modulus' */

  /* S-Function Block: cart_trial_simple/Quarc_Plant2/Inverse Modulus (inverse_modulus_block) */
  {
    cart_trial_simple_DW.InverseModulus_FirstSample = true;
    cart_trial_simple_DW.InverseModulus_Revolutions = 0;
  }

  /* Start for S-Function (inverse_modulus_block): '<S2>/Inverse Modulus1' */

  /* S-Function Block: cart_trial_simple/Quarc_Plant2/Inverse Modulus1 (inverse_modulus_block) */
  {
    cart_trial_simple_DW.InverseModulus1_FirstSample = true;
    cart_trial_simple_DW.InverseModulus1_Revolutions = 0;
  }

  /* Start for Probe: '<S3>/Probe' */
  cart_trial_simple_B.Probe[0] = 0.001;
  cart_trial_simple_B.Probe[1] = 0.0;

  /* InitializeConditions for Derivative: '<Root>/Derivative1' */
  cart_trial_simple_DW.TimeStampA = (rtInf);
  cart_trial_simple_DW.TimeStampB = (rtInf);

  /* InitializeConditions for DiscreteIntegrator: '<S7>/Integrator' */
  cart_trial_simple_DW.Integrator_PrevResetState = 0;
  cart_trial_simple_DW.Integrator_IC_LOADING = 1U;
}

/* Model terminate function */
void cart_trial_simple_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S2>/HIL Initialize' */

  /* S-Function Block: cart_trial_simple/Quarc_Plant2/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    hil_task_stop_all(cart_trial_simple_DW.HILInitialize_Card);
    hil_monitor_stop_all(cart_trial_simple_DW.HILInitialize_Card);
    is_switching = false;
    if ((cart_trial_simple_P.HILInitialize_AOTerminate && !is_switching) ||
        (cart_trial_simple_P.HILInitialize_AOExit && is_switching)) {
      cart_trial_simple_DW.HILInitialize_AOVoltages[0] =
        cart_trial_simple_P.HILInitialize_AOFinal;
      cart_trial_simple_DW.HILInitialize_AOVoltages[1] =
        cart_trial_simple_P.HILInitialize_AOFinal;
      num_final_analog_outputs = 2U;
    } else {
      num_final_analog_outputs = 0;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog(cart_trial_simple_DW.HILInitialize_Card,
        cart_trial_simple_P.HILInitialize_AOChannels, num_final_analog_outputs,
        &cart_trial_simple_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(cart_trial_simple_M, _rt_error_message);
      }
    }

    hil_task_delete_all(cart_trial_simple_DW.HILInitialize_Card);
    hil_monitor_delete_all(cart_trial_simple_DW.HILInitialize_Card);
    hil_close(cart_trial_simple_DW.HILInitialize_Card);
    cart_trial_simple_DW.HILInitialize_Card = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  cart_trial_simple_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  cart_trial_simple_update();
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
  cart_trial_simple_initialize();
}

void MdlTerminate(void)
{
  cart_trial_simple_terminate();
}

/* Registration function */
RT_MODEL_cart_trial_simple_T *cart_trial_simple(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  cart_trial_simple_P.FilteredDerivativeDiscreteorCon = rtMinusInf;
  cart_trial_simple_P.FilteredDerivativeDiscreteorC_d = rtInf;
  cart_trial_simple_P.Integrator_UpperSat = rtInf;
  cart_trial_simple_P.Integrator_LowerSat = rtMinusInf;
  cart_trial_simple_P.Saturation_UpperSat = rtInf;
  cart_trial_simple_P.Saturation_LowerSat = rtMinusInf;

  /* initialize real-time model */
  (void) memset((void *)cart_trial_simple_M, 0,
                sizeof(RT_MODEL_cart_trial_simple_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&cart_trial_simple_M->solverInfo,
                          &cart_trial_simple_M->Timing.simTimeStep);
    rtsiSetTPtr(&cart_trial_simple_M->solverInfo, &rtmGetTPtr
                (cart_trial_simple_M));
    rtsiSetStepSizePtr(&cart_trial_simple_M->solverInfo,
                       &cart_trial_simple_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&cart_trial_simple_M->solverInfo, (&rtmGetErrorStatus
      (cart_trial_simple_M)));
    rtsiSetRTModelPtr(&cart_trial_simple_M->solverInfo, cart_trial_simple_M);
  }

  rtsiSetSimTimeStep(&cart_trial_simple_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&cart_trial_simple_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = cart_trial_simple_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "cart_trial_simple_M points to
       static memory which is guaranteed to be non-NULL" */
    cart_trial_simple_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    cart_trial_simple_M->Timing.sampleTimes =
      (&cart_trial_simple_M->Timing.sampleTimesArray[0]);
    cart_trial_simple_M->Timing.offsetTimes =
      (&cart_trial_simple_M->Timing.offsetTimesArray[0]);

    /* task periods */
    cart_trial_simple_M->Timing.sampleTimes[0] = (0.0);
    cart_trial_simple_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    cart_trial_simple_M->Timing.offsetTimes[0] = (0.0);
    cart_trial_simple_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(cart_trial_simple_M, &cart_trial_simple_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = cart_trial_simple_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    cart_trial_simple_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(cart_trial_simple_M, 8.0);
  cart_trial_simple_M->Timing.stepSize0 = 0.001;
  cart_trial_simple_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  cart_trial_simple_M->Sizes.checksums[0] = (196592455U);
  cart_trial_simple_M->Sizes.checksums[1] = (3168350042U);
  cart_trial_simple_M->Sizes.checksums[2] = (2932165913U);
  cart_trial_simple_M->Sizes.checksums[3] = (1110679257U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    cart_trial_simple_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(cart_trial_simple_M->extModeInfo,
      &cart_trial_simple_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(cart_trial_simple_M->extModeInfo,
                        cart_trial_simple_M->Sizes.checksums);
    rteiSetTPtr(cart_trial_simple_M->extModeInfo, rtmGetTPtr(cart_trial_simple_M));
  }

  cart_trial_simple_M->solverInfoPtr = (&cart_trial_simple_M->solverInfo);
  cart_trial_simple_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&cart_trial_simple_M->solverInfo, 0.001);
  rtsiSetSolverMode(&cart_trial_simple_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  cart_trial_simple_M->blockIO = ((void *) &cart_trial_simple_B);
  (void) memset(((void *) &cart_trial_simple_B), 0,
                sizeof(B_cart_trial_simple_T));

  /* parameters */
  cart_trial_simple_M->defaultParam = ((real_T *)&cart_trial_simple_P);

  /* states (dwork) */
  cart_trial_simple_M->dwork = ((void *) &cart_trial_simple_DW);
  (void) memset((void *)&cart_trial_simple_DW, 0,
                sizeof(DW_cart_trial_simple_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    cart_trial_simple_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 19;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  cart_trial_simple_M->Sizes.numContStates = (0);/* Number of continuous states */
  cart_trial_simple_M->Sizes.numY = (0);/* Number of model outputs */
  cart_trial_simple_M->Sizes.numU = (0);/* Number of model inputs */
  cart_trial_simple_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  cart_trial_simple_M->Sizes.numSampTimes = (2);/* Number of sample times */
  cart_trial_simple_M->Sizes.numBlocks = (26);/* Number of blocks */
  cart_trial_simple_M->Sizes.numBlockIO = (9);/* Number of block outputs */
  cart_trial_simple_M->Sizes.numBlockPrms = (85);/* Sum of parameter "widths" */
  return cart_trial_simple_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
