/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: brake_acc_nodiv.h
 *
 * Code generated for Simulink model 'brake_acc_nodiv'.
 *
 * Model version                  : 1.778
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Sep 29 17:33:04 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_brake_acc_nodiv_h_
#define RTW_HEADER_brake_acc_nodiv_h_
#include <stddef.h>
#include <float.h>
#include <math.h>
#ifndef brake_acc_nodiv_COMMON_INCLUDES_
# define brake_acc_nodiv_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* brake_acc_nodiv_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<S30>/FL_Wheel' */
typedef struct {
  real_T w_radps_DSTATE;               /* '<S35>/w_radps' */
} DW_FL_Wheel;

/* Block signals and states (default storage) for system '<S30>/RR_Wheel' */
typedef struct {
  real_T w_radps_DSTATE;               /* '<S38>/w_radps' */
} DW_RR_Wheel;

/* Block signals and states (default storage) for system '<S30>/Vehicle Model' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S39>/Unit Delay' */
} DW_VehicleModel;

/* Block signals and states (default storage) for system '<Root>/Vehicle_Body_Wheels' */
typedef struct {
  DW_VehicleModel VehicleModel_g;      /* '<S30>/Vehicle Model' */
  DW_RR_Wheel RR_Wheel_h;              /* '<S30>/RR_Wheel' */
  DW_FL_Wheel RL_Wheel;                /* '<S30>/RL_Wheel' */
  DW_FL_Wheel FR_Wheel;                /* '<S30>/FR_Wheel' */
  DW_FL_Wheel FL_Wheel_c;              /* '<S30>/FL_Wheel' */
} DW_Vehicle_Body_Wheels;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  DW_Vehicle_Body_Wheels Vehicle_Body_Wheels_d;/* '<Root>/Vehicle_Body_Wheels' */
  real_T Distribution[4];              /* '<S8>/Distribution' */
  real_T RT13;                         /* '<Root>/RT13' */
  real_T RT5;                          /* '<Root>/RT5' */
  real_T RT6;                          /* '<Root>/RT6' */
  real_T RT7;                          /* '<Root>/RT7' */
  real_T RT8;                          /* '<Root>/RT8' */
  real_T RT16;                         /* '<Root>/RT16' */
  real_T RT9;                          /* '<Root>/RT9' */
  real_T RT17;                         /* '<Root>/RT17' */
  real_T RT10;                         /* '<Root>/RT10' */
  real_T RT18;                         /* '<Root>/RT18' */
  real_T RT11;                         /* '<Root>/RT11' */
  real_T RT19;                         /* '<Root>/RT19' */
  real_T RT12;                         /* '<Root>/RT12' */
  real_T RT_h;                         /* '<Root>/RT' */
  real_T RT1;                          /* '<Root>/RT1' */
  real_T RT2;                          /* '<Root>/RT2' */
  real_T RT3;                          /* '<Root>/RT3' */
  real_T RT4;                          /* '<Root>/RT4' */
  real_T RT14;                         /* '<Root>/RT14' */
  real_T vkmh;                         /* '<S29>/v (km//h)' */
  real_T Threshold_10kmh;              /* '<S1>/Threshold_10km//h' */
  real_T Threshold_10kmh_o;            /* '<S2>/Threshold_10km//h' */
  real_T Threshold_10kmh_l;            /* '<S3>/Threshold_10km//h' */
  real_T Threshold_10kmh_e;            /* '<S4>/Threshold_10km//h' */
  real_T RT5_Buffer0;                  /* '<Root>/RT5' */
  real_T RT6_Buffer0;                  /* '<Root>/RT6' */
  real_T RT7_Buffer0;                  /* '<Root>/RT7' */
  real_T RT8_Buffer0;                  /* '<Root>/RT8' */
  real_T RT_Buffer0;                   /* '<Root>/RT' */
  real_T RT1_Buffer0;                  /* '<Root>/RT1' */
  real_T RT2_Buffer0;                  /* '<Root>/RT2' */
  real_T RT3_Buffer0;                  /* '<Root>/RT3' */
  real_T RT4_Buffer0;                  /* '<Root>/RT4' */
} DW;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: Fc_table_x)
   * Referenced by:
   *   '<S35>/friction_force_N'
   *   '<S36>/friction_force_N'
   *   '<S37>/friction_force_N'
   *   '<S38>/friction_force_N'
   */
  real_T pooled11[4];

  /* Pooled Parameter (Expression: Fc_table_y)
   * Referenced by:
   *   '<S35>/friction_force_N'
   *   '<S36>/friction_force_N'
   *   '<S37>/friction_force_N'
   *   '<S38>/friction_force_N'
   */
  real_T pooled12[4];

  /* Expression: rep_seq_y
   * Referenced by: '<S7>/Look-Up Table1'
   */
  real_T LookUpTable1_tableData[4];

  /* Expression: rep_seq_t - min(rep_seq_t)
   * Referenced by: '<S7>/Look-Up Table1'
   */
  real_T LookUpTable1_bp01Data[4];

  /* Expression: rep_seq_y
   * Referenced by: '<S6>/Look-Up Table1'
   */
  real_T LookUpTable1_tableData_o[5];

  /* Expression: rep_seq_t - min(rep_seq_t)
   * Referenced by: '<S6>/Look-Up Table1'
   */
  real_T LookUpTable1_bp01Data_a[5];
} ConstP;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    struct {
      uint8_T TID1_2;
      uint8_T TID1_3;
      uint8_T TID2_3;
    } RateInteraction;

    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[4];
  } Timing;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* Constant parameters (default storage) */
extern const ConstP rtConstP;

/* Model entry point functions */
extern void brake_acc_nodiv_initialize(void);
extern void brake_acc_nodiv_step0(void);
extern void brake_acc_nodiv_step2(void);
extern void brake_acc_nodiv_step3(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/ABSTorqFR' : Unused code path elimination
 * Block '<Root>/ABSTorqRR' : Unused code path elimination
 * Block '<S31>/slip_rate_large' : Unused code path elimination
 * Block '<S32>/slip_rate_large' : Unused code path elimination
 * Block '<S33>/slip_rate_large' : Unused code path elimination
 * Block '<S34>/slip_rate_large' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Scope1' : Unused code path elimination
 * Block '<Root>/Speed' : Unused code path elimination
 * Block '<S35>/Scope1' : Unused code path elimination
 * Block '<S35>/Slip Rate' : Unused code path elimination
 * Block '<S36>/Scope1' : Unused code path elimination
 * Block '<S36>/Slip Rate' : Unused code path elimination
 * Block '<S37>/Scope1' : Unused code path elimination
 * Block '<S37>/Slip Rate' : Unused code path elimination
 * Block '<S38>/Scope1' : Unused code path elimination
 * Block '<S38>/Slip Rate' : Unused code path elimination
 * Block '<S30>/Scope' : Unused code path elimination
 * Block '<S30>/Scope1' : Unused code path elimination
 * Block '<S31>/slip_abs_on_times_10' : Eliminated nontunable gain of 1
 * Block '<S32>/slip_abs_on_times_10' : Eliminated nontunable gain of 1
 * Block '<S33>/slip_abs_on_times_10' : Eliminated nontunable gain of 1
 * Block '<S34>/slip_abs_on_times_10' : Eliminated nontunable gain of 1
 * Block '<S6>/Output' : Eliminate redundant signal conversion block
 * Block '<S7>/Output' : Eliminate redundant signal conversion block
 * Block '<Root>/RT15' : Eliminated since input and output rates are identical
 * Block '<S40>/C_use_div' : Unused code path elimination
 * Block '<S40>/C_zero' : Unused code path elimination
 * Block '<S40>/Divide' : Unused code path elimination
 * Block '<S40>/Switch' : Unused code path elimination
 * Block '<S42>/C_use_div' : Unused code path elimination
 * Block '<S42>/C_zero' : Unused code path elimination
 * Block '<S42>/Divide' : Unused code path elimination
 * Block '<S42>/Switch' : Unused code path elimination
 * Block '<S44>/C_use_div' : Unused code path elimination
 * Block '<S44>/C_zero' : Unused code path elimination
 * Block '<S44>/Divide' : Unused code path elimination
 * Block '<S44>/Switch' : Unused code path elimination
 * Block '<S46>/C_use_div' : Unused code path elimination
 * Block '<S46>/C_zero' : Unused code path elimination
 * Block '<S46>/Divide' : Unused code path elimination
 * Block '<S46>/Switch' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'brake_acc_nodiv'
 * '<S1>'   : 'brake_acc_nodiv/ABS_FL_Wheel'
 * '<S2>'   : 'brake_acc_nodiv/ABS_FR_Wheel'
 * '<S3>'   : 'brake_acc_nodiv/ABS_RL_Wheel'
 * '<S4>'   : 'brake_acc_nodiv/ABS_RR_Wheel'
 * '<S5>'   : 'brake_acc_nodiv/Brake_Torq_Calculation'
 * '<S6>'   : 'brake_acc_nodiv/Driver_Accelerate'
 * '<S7>'   : 'brake_acc_nodiv/Driver_Brake'
 * '<S8>'   : 'brake_acc_nodiv/Global Brake Controller'
 * '<S9>'   : 'brake_acc_nodiv/HW_Accel_pedal'
 * '<S10>'  : 'brake_acc_nodiv/HW_BrakePedal'
 * '<S11>'  : 'brake_acc_nodiv/HW_FLBrake'
 * '<S12>'  : 'brake_acc_nodiv/HW_FLEncoder'
 * '<S13>'  : 'brake_acc_nodiv/HW_FRBrake'
 * '<S14>'  : 'brake_acc_nodiv/HW_FREncoder'
 * '<S15>'  : 'brake_acc_nodiv/HW_RLBrake'
 * '<S16>'  : 'brake_acc_nodiv/HW_RLEncoder'
 * '<S17>'  : 'brake_acc_nodiv/HW_RRBrake'
 * '<S18>'  : 'brake_acc_nodiv/HW_RREncoder'
 * '<S19>'  : 'brake_acc_nodiv/LDM_Accel_peddal'
 * '<S20>'  : 'brake_acc_nodiv/LDM_BrakePedal'
 * '<S21>'  : 'brake_acc_nodiv/LDM_FLBrake'
 * '<S22>'  : 'brake_acc_nodiv/LDM_FLSensor'
 * '<S23>'  : 'brake_acc_nodiv/LDM_FRBrake'
 * '<S24>'  : 'brake_acc_nodiv/LDM_FRSensor'
 * '<S25>'  : 'brake_acc_nodiv/LDM_RLBrake'
 * '<S26>'  : 'brake_acc_nodiv/LDM_RLSensor'
 * '<S27>'  : 'brake_acc_nodiv/LDM_RRBrake'
 * '<S28>'  : 'brake_acc_nodiv/LDM_RRSensor'
 * '<S29>'  : 'brake_acc_nodiv/Veh_Speed_Estimator'
 * '<S30>'  : 'brake_acc_nodiv/Vehicle_Body_Wheels'
 * '<S31>'  : 'brake_acc_nodiv/ABS_FL_Wheel/If v>=10 km//h'
 * '<S32>'  : 'brake_acc_nodiv/ABS_FR_Wheel/If v>=10 km//h'
 * '<S33>'  : 'brake_acc_nodiv/ABS_RL_Wheel/If v>=10 km//h'
 * '<S34>'  : 'brake_acc_nodiv/ABS_RR_Wheel/If v>=10 km//h'
 * '<S35>'  : 'brake_acc_nodiv/Vehicle_Body_Wheels/FL_Wheel'
 * '<S36>'  : 'brake_acc_nodiv/Vehicle_Body_Wheels/FR_Wheel'
 * '<S37>'  : 'brake_acc_nodiv/Vehicle_Body_Wheels/RL_Wheel'
 * '<S38>'  : 'brake_acc_nodiv/Vehicle_Body_Wheels/RR_Wheel'
 * '<S39>'  : 'brake_acc_nodiv/Vehicle_Body_Wheels/VehicleModel'
 * '<S40>'  : 'brake_acc_nodiv/Vehicle_Body_Wheels/FL_Wheel/slip_ratio_percentage'
 * '<S41>'  : 'brake_acc_nodiv/Vehicle_Body_Wheels/FL_Wheel/slip_ratio_percentage/binary_search_ratio'
 * '<S42>'  : 'brake_acc_nodiv/Vehicle_Body_Wheels/FR_Wheel/slip_ratio_percentage'
 * '<S43>'  : 'brake_acc_nodiv/Vehicle_Body_Wheels/FR_Wheel/slip_ratio_percentage/binary_search_ratio'
 * '<S44>'  : 'brake_acc_nodiv/Vehicle_Body_Wheels/RL_Wheel/slip_ratio_percentage'
 * '<S45>'  : 'brake_acc_nodiv/Vehicle_Body_Wheels/RL_Wheel/slip_ratio_percentage/binary_search_ratio'
 * '<S46>'  : 'brake_acc_nodiv/Vehicle_Body_Wheels/RR_Wheel/slip_ratio_percentage'
 * '<S47>'  : 'brake_acc_nodiv/Vehicle_Body_Wheels/RR_Wheel/slip_ratio_percentage/binary_search_ratio'
 */
#endif                                 /* RTW_HEADER_brake_acc_nodiv_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
