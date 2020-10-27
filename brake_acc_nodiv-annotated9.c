/*
* Academic License - for use in teaching, academic research, and meeting
* course requirements at degree granting institutions only.  Not for
* government, commercial, or other organizational use.
*
* File: brake_acc_nodiv.c
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

#include "brake_acc_nodiv.h"
#define NumBitsPerChar                 8U

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

/* Block signals and states (default storage) */
DW rtDW;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
extern real_T rt_remd_snf(real_T u0, real_T u1);
extern real_T rt_roundd_snf(real_T u);
static void BINARYSEARCH_real_T(uint32_T *piLeft, uint32_T *piRght, real_T u,
const real_T *pData, uint32_T iHi);
static void LookUp_real_T_real_T(real_T *pY, const real_T *pYData, real_T u,
const real_T *pUData, uint32_T iHi);
static real_T look1_binlx(real_T u0, const real_T bp0[], const real_T table[],
uint32_T maxIndex);
static void ABS_RR_Wheel(real_T rtu_TRequestedTorqueNm, real_T
rtu_vVehicleVelocitykmh, real_T rtu_wwheelRotationrpm, real_T
*rty_M_absBrake_Torque);
static void Veh_Speed_Estimator(real_T rtu_RRWhl_rpm, real_T rtu_RLWhl_rpm,
real_T rtu_FRWhl_rpm, real_T rtu_FLWhl_rpm, real_T *rty_Veh_Spd_Est_kmh);
static void binary_search_ratio_Init(real_T *rty_slip_ratio);
static void binary_search_ratio(real_T rtu_abs_v_minus_wr, real_T rtu_max_v_wr,
real_T *rty_slip_ratio);
static void FL_Wheel_Init(void);
static void FL_Wheel(real_T rtu_M_abs_Nm, real_T rtu_v_mps, real_T
*rty_WheelFrictionN, real_T *rty_WheelSpeedrpm, DW_FL_Wheel
*localDW);
static void RR_Wheel_Init(void);
static void RR_Wheel(real_T rtu_M_abs_Nm, real_T rtu_v_mps, real_T
*rty_WheelFrictionN, real_T *rty_WheelSpeedrpm, DW_RR_Wheel
*localDW);
static void VehicleModel_Update(real_T rtu_FoceonRRWheel, real_T
rtu_ForceonRLWheel, real_T rtu_ForceonFRWheel, real_T rtu_ForceonFLWheel,
real_T *rty_VehicleSpeedms, DW_VehicleModel *localDW);
static void VehicleModel(real_T *rty_VehicleSpeedms, DW_VehicleModel *localDW);
static void Vehicle_Body_Wheels_Init(void);
static void Vehicle_Body_Wheels(real_T rtu_RearRightBrkTorq, real_T
rtu_RearLeftBrkTorq, real_T rtu_FrntRightBrkTorq, real_T rtu_FrntLeftBrkTorq,
real_T rtu_AccPedalPos, real_T *rty_Veh_Spd_Realkmh, real_T
*rty_RearRightWhl_rpm, real_T *rty_RearLeftWhl_rpm, real_T
*rty_FrntRightWhl_rpm, real_T *rty_FrntLeftWhl_rpm, DW_Vehicle_Body_Wheels
*localDW);
extern real_T rtGetNaN(void);
extern real32_T rtGetNaNF(void);
extern real_T rtInf;
extern real_T rtMinusInf;
extern real_T rtNaN;
extern real32_T rtInfF;
extern real32_T rtMinusInfF;
extern real32_T rtNaNF;
extern void rt_InitInfAndNaN(size_t realSize);
extern boolean_T rtIsInf(real_T value);
extern boolean_T rtIsInfF(real32_T value);
extern boolean_T rtIsNaN(real_T value);
extern boolean_T rtIsNaNF(real32_T value);
typedef struct {
struct {
uint32_T wordH;
uint32_T wordL;
} words;
} BigEndianIEEEDouble;

typedef struct {
struct {
uint32_T wordL;
uint32_T wordH;
} words;
} LittleEndianIEEEDouble;

typedef struct {
union {
real32_T wordLreal;
uint32_T wordLuint;
} wordL;
} IEEESingle;

real_T rtInf;
real_T rtMinusInf;
real_T rtNaN;
real32_T rtInfF;
real32_T rtMinusInfF;
real32_T rtNaNF;
extern real_T rtGetInf(void);
extern real32_T rtGetInfF(void);
extern real_T rtGetMinusInf(void);
extern real32_T rtGetMinusInfF(void);

/*
* Initialize rtNaN needed by the generated code.
* NaN is initialized as non-signaling. Assumes IEEE.
*/
real_T rtGetNaN(void)
{
size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
real_T nan = 0.0;
if (bitsPerReal == 32U) {
nan = rtGetNaNF();
} else {
union {
LittleEndianIEEEDouble bitVal;
real_T fltVal;
} tmpVal;

tmpVal.bitVal.words.wordH = 0xFFF80000U;
tmpVal.bitVal.words.wordL = 0x00000000U;
nan = tmpVal.fltVal;
}

return nan;
}

/*
* Initialize rtNaNF needed by the generated code.
* NaN is initialized as non-signaling. Assumes IEEE.
*/
real32_T rtGetNaNF(void)
{
IEEESingle nanF = { { 0 } };

nanF.wordL.wordLuint = 0xFFC00000U;
return nanF.wordL.wordLreal;
}

/*
* Initialize the rtInf, rtMinusInf, and rtNaN needed by the
* generated code. NaN is initialized as non-signaling. Assumes IEEE.
*/
void rt_InitInfAndNaN(size_t realSize)
{
(void) (realSize);
rtNaN = rtGetNaN();
rtNaNF = rtGetNaNF();
rtInf = rtGetInf();
rtInfF = rtGetInfF();
rtMinusInf = rtGetMinusInf();
rtMinusInfF = rtGetMinusInfF();
}

/* Test if value is infinite */
boolean_T rtIsInf(real_T value)
{
return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
}

/* Test if single-precision value is infinite */
boolean_T rtIsInfF(real32_T value)
{
return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
}

/* Test if value is not a number */
boolean_T rtIsNaN(real_T value)
{
boolean_T result = (boolean_T) 0;
size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
if (bitsPerReal == 32U) {
result = rtIsNaNF((real32_T)value);
} else {
union {
LittleEndianIEEEDouble bitVal;
real_T fltVal;
} tmpVal;

tmpVal.fltVal = value;
result = (boolean_T)((tmpVal.bitVal.words.wordH & 0x7FF00000) == 0x7FF00000 &&
( (tmpVal.bitVal.words.wordH & 0x000FFFFF) != 0 ||
(tmpVal.bitVal.words.wordL != 0) ));
}

return result;
}

/* Test if single-precision value is not a number */
boolean_T rtIsNaNF(real32_T value)
{
IEEESingle tmp;
tmp.wordL.wordLreal = value;
return (boolean_T)( (tmp.wordL.wordLuint & 0x7F800000) == 0x7F800000 &&
(tmp.wordL.wordLuint & 0x007FFFFF) != 0 );
}

/*
* Initialize rtInf needed by the generated code.
* Inf is initialized as non-signaling. Assumes IEEE.
*/
real_T rtGetInf(void)
{
size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
real_T inf = 0.0;
if (bitsPerReal == 32U) {
inf = rtGetInfF();
} else {
union {
LittleEndianIEEEDouble bitVal;
real_T fltVal;
} tmpVal;

tmpVal.bitVal.words.wordH = 0x7FF00000U;
tmpVal.bitVal.words.wordL = 0x00000000U;
inf = tmpVal.fltVal;
}

return inf;
}

/*
* Initialize rtInfF needed by the generated code.
* Inf is initialized as non-signaling. Assumes IEEE.
*/
real32_T rtGetInfF(void)
{
IEEESingle infF;
infF.wordL.wordLuint = 0x7F800000U;
return infF.wordL.wordLreal;
}

/*
* Initialize rtMinusInf needed by the generated code.
* Inf is initialized as non-signaling. Assumes IEEE.
*/
real_T rtGetMinusInf(void)
{
size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
real_T minf = 0.0;
if (bitsPerReal == 32U) {
minf = rtGetMinusInfF();
} else {
union {
LittleEndianIEEEDouble bitVal;
real_T fltVal;
} tmpVal;

tmpVal.bitVal.words.wordH = 0xFFF00000U;
tmpVal.bitVal.words.wordL = 0x00000000U;
minf = tmpVal.fltVal;
}

return minf;
}

/*
* Initialize rtMinusInfF needed by the generated code.
* Inf is initialized as non-signaling. Assumes IEEE.
*/
real32_T rtGetMinusInfF(void)
{
IEEESingle minfF;
minfF.wordL.wordLuint = 0xFF800000U;
return minfF.wordL.wordLreal;
}

/* Lookup Binary Search Utility BINARYSEARCH_real_T */
static void BINARYSEARCH_real_T(uint32_T *piLeft, uint32_T *piRght, real_T u,
const real_T *pData, uint32_T iHi)
{
/* Find the location of current input value in the data table. */
*piLeft = 0U;
*piRght = iHi;
if (u <= pData[0] ) {
/* Less than or equal to the smallest point in the table. */
*piRght = 0U;
} else if (u >= pData[iHi] ) {
/* Greater than or equal to the largest point in the table. */
*piLeft = iHi;
} else {
uint32_T i;

/* Do a binary search. */
while (( *piRght - *piLeft ) > 1U ) {
/* Get the average of the left and right indices using to Floor rounding. */
i = (*piLeft + *piRght) >> 1;

/* Move either the right index or the left index so that */
/*  LeftDataPoint <= CurrentValue < RightDataPoint */
if (u < pData[i] ) {
*piRght = i;
} else {
*piLeft = i;
}
}
}
}

/* Lookup Utility LookUp_real_T_real_T */
static void LookUp_real_T_real_T(real_T *pY, const real_T *pYData, real_T u,
const real_T *pUData, uint32_T iHi)
{
uint32_T iLeft;
uint32_T iRght;
BINARYSEARCH_real_T( &(iLeft), &(iRght), u, pUData, iHi);

{
real_T lambda;
if (pUData[iRght] > pUData[iLeft] ) {
real_T num;
real_T den;
den = pUData[iRght];
den -= pUData[iLeft];
num = u;
num -= pUData[iLeft];
lambda = num / den;
} else {
lambda = 0.0;
}

{
real_T yLeftCast;
real_T yRghtCast;
yLeftCast = pYData[iLeft];
yRghtCast = pYData[iRght];
yLeftCast += lambda * ( yRghtCast - yLeftCast );
(*pY) = yLeftCast;
}
}
}

static real_T look1_binlx(real_T u0, const real_T bp0[], const real_T table[],
uint32_T maxIndex)
{
real_T frac;
uint32_T iRght;
uint32_T iLeft;
uint32_T bpIdx;

/* Column-major Lookup 1-D
Search method: 'binary'
Use previous index: 'off'
Interpolation method: 'Linear point-slope'
Extrapolation method: 'Linear'
Use last breakpoint for index at or above upper limit: 'off'
Remove protection against out-of-range input in generated code: 'off'
*/
/* Prelookup - Index and Fraction
Index Search method: 'binary'
Extrapolation method: 'Linear'
Use previous index: 'off'
Use last breakpoint for index at or above upper limit: 'off'
Remove protection against out-of-range input in generated code: 'off'
*/
if (u0 <= bp0[0U]) {
iLeft = 0U;
frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
} else if (u0 < bp0[maxIndex]) {
/* Binary Search */
bpIdx = maxIndex >> 1U;
iLeft = 0U;
iRght = maxIndex;
while (iRght - iLeft > 1U) {
if (u0 < bp0[bpIdx]) {
iRght = bpIdx;
} else {
iLeft = bpIdx;
}

bpIdx = (iRght + iLeft) >> 1U;
}

frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
} else {
iLeft = maxIndex - 1U;
frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
}

/* Column-major Interpolation 1-D
Interpolation method: 'Linear point-slope'
Use last breakpoint for index at or above upper limit: 'off'
Overflow mode: 'wrapping'
*/
return (table[iLeft + 1U] - table[iLeft]) * frac + table[iLeft];
}

/*
* Output and update for function-call system:
*    '<Root>/ABS_RR_Wheel'
*    '<Root>/ABS_RL_Wheel'
*    '<Root>/ABS_FR_Wheel'
*    '<Root>/ABS_FL_Wheel'
*/
//@ ensures (rtu_vVehicleVelocitykmh>10)?*rty_M_absBrake_Torque = (g_9>0)?*rty_M_absBrake_Torque = 0 : *rty_M_absBrake_Torque = rtu_TRequestedTorqueNm : *rty_M_absBrake_Torque = rtu_TRequestedTorqueNm
static void ABS_RR_Wheel(real_T rtu_TRequestedTorqueNm, real_T
rtu_vVehicleVelocitykmh, real_T rtu_wwheelRotationrpm, real_T
*rty_M_absBrake_Torque)
{
real_T rtb_vms;
real_T rtb_positive;

/* Switch: '<S4>/Threshold_10km//h' */
if (rtu_vVehicleVelocitykmh >= 10.0) {
/* Outputs for Atomic SubSystem: '<S4>/If v>=10 km//h' */
/* Gain: '<S34>/v (m//s)' */
//@ghost g_16 = 10/36 * rtu_vVehicleVelocitykmh 
rtb_vms = 0.27777777777777779 * rtu_vVehicleVelocitykmh;

/* Sum: '<S34>/Subtract' incorporates:
//@ghost g_5 = g_16 - g_13  
*  Gain: '<S34>/wheSpd (m//s)'
//@ghost g_13 = R*pi/30 * rtu_wwheelRotationrpm 
*/
rtb_positive = rtb_vms - 0.052359877559829883 * rtu_wwheelRotationrpm;

/* Saturate: '<S34>/positive' */
if (rtb_positive <= 0.0) {
rtb_positive = 0.0;
}

/* End of Saturate: '<S34>/positive' */
//@ghost g_1 = g_5 || 0  

/* Switch: '<S34>/LockDetect' incorporates:
*  Constant: '<S34>/ReleaseBrake'
*  Gain: '<S34>/times_10'
//@ghost g_6 = 10 * g_1 
*  RelationalOperator: '<S34>/Relational Operator'
//@ghost g_9 = g_6 > rtb_vms 
*/
if (10.0 * rtb_positive > rtb_vms) {
*rty_M_absBrake_Torque = 0.0;
} else {
*rty_M_absBrake_Torque = rtu_TRequestedTorqueNm;
}

/* End of Switch: '<S34>/LockDetect' */
//@ghost (g_9>0)?*rty_M_absBrake_Torque = 0 : *rty_M_absBrake_Torque = rtu_TRequestedTorqueNm 
/* End of Outputs for SubSystem: '<S4>/If v>=10 km//h' */
} else {
*rty_M_absBrake_Torque = rtu_TRequestedTorqueNm;
}

/* End of Switch: '<S4>/Threshold_10km//h' */
}

/* Output and update for function-call system: '<Root>/Veh_Speed_Estimator' */
//@ ensures g_8 = 3.6*R * g_6
static void Veh_Speed_Estimator(real_T rtu_RRWhl_rpm, real_T rtu_RLWhl_rpm,
real_T rtu_FRWhl_rpm, real_T rtu_FLWhl_rpm, real_T *rty_Veh_Spd_Est_kmh)
{
/* Gain: '<S29>/v (km//h)' incorporates:
*  Gain: '<S29>/average_rpm'
//@ghost g_7 = 1/4 * g_5 
*  Gain: '<S29>/u (grad//s)'
//@ghost g_6 = pi/30 * g_7 
*  Sum: '<S29>/Add'
//@ghost g_5 = RRWhl_rpm + RLWhl_rpm+FRWhl_rpm+FLWhl_rpm 
*/
*rty_Veh_Spd_Est_kmh = (((rtu_RRWhl_rpm + rtu_RLWhl_rpm) + rtu_FRWhl_rpm) +
rtu_FLWhl_rpm) * 0.25 * 0.10471975511965977 * 1.8;
}

/*
* System initialize for atomic system:
*    '<S40>/binary_search_ratio'
*    '<S42>/binary_search_ratio'
*    '<S44>/binary_search_ratio'
*    '<S46>/binary_search_ratio'
*/
static void binary_search_ratio_Init(real_T *rty_slip_ratio)
{
*rty_slip_ratio = 0.0;
}

/*
* Output and update for atomic system:
*    '<S40>/binary_search_ratio'
*    '<S42>/binary_search_ratio'
*    '<S44>/binary_search_ratio'
*    '<S46>/binary_search_ratio'
*/
static void binary_search_ratio(real_T rtu_abs_v_minus_wr, real_T rtu_max_v_wr,
real_T *rty_slip_ratio)
{
uint8_T idx_mid;
uint8_T idx_min;
uint8_T idx_max;
boolean_T guard1 = false;
int32_T exitg1;

/* Chart: '<S40>/binary_search_ratio' */
/*  check boundary conditions  */
if ((rtu_abs_v_minus_wr == 0.0) || (rtu_max_v_wr == 0.0)) {
*rty_slip_ratio = 0.0;

/*  terminate the flow  */
/*  terminate the flow  */
} else if (rtu_abs_v_minus_wr >= 100.0 * rtu_max_v_wr) {
*rty_slip_ratio = 100.0;

/*  terminate the flow  */
/*  terminate the flow  */
} else {
idx_min = 0U;
idx_max = 99U;

/*  start binary search  */
guard1 = false;
do {
exitg1 = 0;
if (idx_max == idx_min) {
/*  decide if idx_min is idx_max
or idx_max + 1  */
idx_mid = idx_max;
guard1 = true;
exitg1 = 1;
} else if (idx_max > idx_min) {
idx_mid = (uint8_T)((idx_min + idx_max) / 2);

/*  the middle index  */
if (rtu_abs_v_minus_wr < (real_T)idx_mid * rtu_max_v_wr) {
/*  if slip ratio is smaller than idx_mid  */
idx_max = (uint8_T)(idx_mid - 1);

/*  choose lower part  */
/*  go back for iterative search  */
guard1 = false;
} else if (rtu_abs_v_minus_wr > ((real_T)idx_mid + 1.0) * rtu_max_v_wr)
{
/*  if slip ratio is larger than idx_mid + 1  */
idx_min = (uint8_T)(idx_mid + 1);

/*  choose upper part  */
/*  go back for iterative search  */
guard1 = false;
} else {
guard1 = true;
exitg1 = 1;
}
} else {
*rty_slip_ratio = 20.0;

/*  if idx_max < idx_min, return 20%. The case should never happen  */
/*  terminate the flow  */
/*  terminate the flow  */
exitg1 = 1;
}
} while (exitg1 == 0);

if (guard1) {
if (rtu_abs_v_minus_wr - (real_T)idx_mid * rtu_max_v_wr <= ((real_T)
idx_mid + 1.0) * rtu_max_v_wr - rtu_abs_v_minus_wr) {
/*  if slip ratio is closer to idx_mid than idx_mid + 1  */
*rty_slip_ratio = idx_mid;

/*  terminate the flow  */
} else {
*rty_slip_ratio = (real_T)idx_mid + 1.0;
}
}
}

/* End of Chart: '<S40>/binary_search_ratio' */
}

/*
* System initialize for atomic system:
*    '<S30>/FL_Wheel'
*    '<S30>/FR_Wheel'
*    '<S30>/RL_Wheel'
*/
static void FL_Wheel_Init(void)
{
/* local block i/o variables */
real_T rtb_slip_ratio;

/* SystemInitialize for Chart: '<S40>/binary_search_ratio' */
binary_search_ratio_Init(&rtb_slip_ratio);
}

/*
* Output and update for atomic system:
*    '<S30>/FL_Wheel'
*    '<S30>/FR_Wheel'
*    '<S30>/RL_Wheel'
*/
//@ ensures *rty_WheelSpeedrpm = 30/pi * g_21
static void FL_Wheel(real_T rtu_M_abs_Nm, real_T rtu_v_mps, real_T
*rty_WheelFrictionN, real_T *rty_WheelSpeedrpm, DW_FL_Wheel
*localDW)
{
/* local block i/o variables */
real_T rtb_friction_force_N;
real_T rtb_slip_ratio;
real_T rtb_Saturation;
real_T rtb_whlRadius;
real_T rtb_times100;

/* Saturate: '<S35>/Saturation' incorporates:
*  UnitDelay: '<S35>/w_radps'
*/
if (localDW->w_radps_DSTATE > 112.0) {
rtb_Saturation = 112.0;
} else if (localDW->w_radps_DSTATE < 0.0) {
rtb_Saturation = 0.0;
} else {
rtb_Saturation = localDW->w_radps_DSTATE;
}

/* End of Saturate: '<S35>/Saturation' */
//@ghost g_21 = g_42 || 0  

/* Gain: '<S35>/w (rpm)' */
*rty_WheelSpeedrpm = 9.5492965855137211 * rtb_Saturation;

/* Gain: '<S35>/whlRadius' */
//@ghost g_29 = R * g_21 
rtb_whlRadius = 0.5 * rtb_Saturation;

/* Gain: '<S35>/times100' incorporates:
//@ghost g_17 = 100 * g_31 
*  Sum: '<S35>/v_wr'
//@ghost g_31 = v_mps - g_29  
*/
rtb_times100 = (rtb_whlRadius - rtu_v_mps) * 100.0;

/* MinMax: '<S35>/max_v_wr' */
if ((rtu_v_mps > rtb_whlRadius) || rtIsNaN(rtb_whlRadius)) {
rtb_whlRadius = rtu_v_mps;
}

/* End of MinMax: '<S35>/max_v_wr' */

/* Chart: '<S40>/binary_search_ratio' incorporates:
*  Abs: '<S35>/Abs'
*/
binary_search_ratio(fabs(rtb_times100), rtb_whlRadius, &rtb_slip_ratio);

/* Switch: '<S40>/Switch1' */
//@ghost (g_2>0)?pout = g_4 : pout = g_1 
rtb_whlRadius = rtb_slip_ratio;

/* Lookup: '<S35>/friction_force_N' */
/*
* About '<S35>/friction_force_N':
* Input0  Data Type:  Floating Point real_T
* Output0 Data Type:  Floating Point real_T
* Lookup Method: Linear_Endpoint
*
* XData parameter uses the same data type and scaling as Input0
* YData parameter uses the same data type and scaling as Output0
*/
LookUp_real_T_real_T( &(rtb_friction_force_N), rtConstP.pooled12,
rtb_whlRadius, rtConstP.pooled11, 3U);

/* Signum: '<S35>/Sign' */
if (rtb_times100 < 0.0) {
rtb_times100 = -1.0;
} else if (rtb_times100 > 0.0) {
rtb_times100 = 1.0;
} else if (rtb_times100 == 0.0) {
rtb_times100 = 0.0;
} else {
rtb_times100 = (rtNaN);
}

/* End of Signum: '<S35>/Sign' */

/* Product: '<S35>/Product' incorporates:
*  Lookup: '<S35>/friction_force_N'
*/
*rty_WheelFrictionN = rtb_friction_force_N * rtb_times100;

/* Update for UnitDelay: '<S35>/w_radps' incorporates:
*  Gain: '<S35>/Radius'
//@ghost g_37 = R * g_34 
*  Gain: '<S35>/Ts_over_Inertia'
//@ghost g_41 = T_veh/I * g_40 
*  Sum: '<S35>/Subtract'
*  Sum: '<S35>/Sum'
//@ghost g_22 = g_41 + g_21  
*/
localDW->w_radps_DSTATE = (rtu_M_abs_Nm - 0.5 * *rty_WheelFrictionN) * 0.002 +
rtb_Saturation;
}

/* System initialize for atomic system: '<S30>/RR_Wheel' */
static void RR_Wheel_Init(void)
{
/* local block i/o variables */
real_T rtb_slip_ratio_g;

/* SystemInitialize for Chart: '<S46>/binary_search_ratio' */
binary_search_ratio_Init(&rtb_slip_ratio_g);
}

/* Output and update for atomic system: '<S30>/RR_Wheel' */
//@ ensures Wheel Speed (rpm) = 30/pi * g_168
static void RR_Wheel(real_T rtu_M_abs_Nm, real_T rtu_v_mps, real_T
*rty_WheelFrictionN, real_T *rty_WheelSpeedrpm, DW_RR_Wheel
*localDW)
{
/* local block i/o variables */
real_T rtb_friction_force_N_m;
real_T rtb_slip_ratio_g;
real_T rtb_Saturation;
real_T rtb_whlRadius;
real_T rtb_times100;

/* Saturate: '<S38>/Saturation' incorporates:
//@ghost g_168 = g_189 || 0  
*  UnitDelay: '<S38>/w_radps'
*/
if (localDW->w_radps_DSTATE > 112.0) {
rtb_Saturation = 112.0;
} else if (localDW->w_radps_DSTATE < 0.0) {
rtb_Saturation = 0.0;
} else {
rtb_Saturation = localDW->w_radps_DSTATE;
}

/* End of Saturate: '<S38>/Saturation' */
//@ghost g_168 = g_189 || 0  

/* Gain: '<S38>/w (rpm)' */
*rty_WheelSpeedrpm = 9.5492965855137211 * rtb_Saturation;

/* Gain: '<S38>/whlRadius' */
//@ghost g_176 = R * g_168 
rtb_whlRadius = 0.5 * rtb_Saturation;

/* Gain: '<S38>/times100' incorporates:
//@ghost g_164 = 100 * g_178 
*  Sum: '<S38>/v_wr'
//@ghost g_178 = v_mps - g_176  
*/
rtb_times100 = (rtb_whlRadius - rtu_v_mps) * 100.0;

/* MinMax: '<S38>/max_v_wr' */
if ((rtu_v_mps > rtb_whlRadius) || rtIsNaN(rtb_whlRadius)) {
rtb_whlRadius = rtu_v_mps;
}

/* End of MinMax: '<S38>/max_v_wr' */

/* Chart: '<S46>/binary_search_ratio' incorporates:
*  Abs: '<S38>/Abs'
*/
binary_search_ratio(fabs(rtb_times100), rtb_whlRadius, &rtb_slip_ratio_g);

/* Switch: '<S46>/Switch1' */
//@ghost (g_149>0)?pout = g_151 : pout = g_148 
rtb_whlRadius = rtb_slip_ratio_g;

/* Lookup: '<S38>/friction_force_N' */
/*
* About '<S38>/friction_force_N':
* Input0  Data Type:  Floating Point real_T
* Output0 Data Type:  Floating Point real_T
* Lookup Method: Linear_Endpoint
*
* XData parameter uses the same data type and scaling as Input0
* YData parameter uses the same data type and scaling as Output0
*/
LookUp_real_T_real_T( &(rtb_friction_force_N_m), rtConstP.pooled12,
rtb_whlRadius, rtConstP.pooled11, 3U);

/* Signum: '<S38>/Sign' */
if (rtb_times100 < 0.0) {
rtb_times100 = -1.0;
} else if (rtb_times100 > 0.0) {
rtb_times100 = 1.0;
} else if (rtb_times100 == 0.0) {
rtb_times100 = 0.0;
} else {
rtb_times100 = (rtNaN);
}

/* End of Signum: '<S38>/Sign' */

/* Product: '<S38>/Product' incorporates:
*  Lookup: '<S38>/friction_force_N'
*/
*rty_WheelFrictionN = rtb_friction_force_N_m * rtb_times100;

/* Update for UnitDelay: '<S38>/w_radps' incorporates:
*  Gain: '<S38>/Radius'
//@ghost g_184 = R * g_181 
*  Gain: '<S38>/Ts_over_Inertia'
//@ghost g_188 = T_veh/I * g_187 
*  Sum: '<S38>/Subtract'
//@ghost g_187 = g_184 - M_abs_Nm  
*  Sum: '<S38>/Sum'
//@ghost g_169 = g_188 + g_168  
*/
localDW->w_radps_DSTATE = (rtu_M_abs_Nm - 0.5 * *rty_WheelFrictionN) * 0.002 +
rtb_Saturation;
}

/* Outputs for atomic system: '<S30>/Vehicle Model' */
//@ ensures *rty_VehicleSpeedms = g_198 || 0 
static void VehicleModel(real_T *rty_VehicleSpeedms, DW_VehicleModel *localDW)
{
real_T u0;

/* UnitDelay: '<S39>/Unit Delay' */
u0 = localDW->UnitDelay_DSTATE;

/* Saturate: '<S39>/Saturation' */
//@ghost g_201 = g_198 || 0  
if (u0 > 56.0) {
*rty_VehicleSpeedms = 56.0;
} else if (u0 < 0.0) {
*rty_VehicleSpeedms = 0.0;
} else {
*rty_VehicleSpeedms = u0;
}

/* End of Saturate: '<S39>/Saturation' */
//@ghost g_201 = g_198 || 0  
}

/* Update for atomic system: '<S30>/Vehicle Model' */
//@ ensures g_197 = g_207 + *rty_VehicleSpeedms 
static void VehicleModel_Update(real_T rtu_FoceonRRWheel, real_T
rtu_ForceonRLWheel, real_T rtu_ForceonFRWheel, real_T rtu_ForceonFLWheel,
real_T *rty_VehicleSpeedms, DW_VehicleModel *localDW)
{
/* Update for UnitDelay: '<S39>/Unit Delay' incorporates:
*  Gain: '<S39>/sample_time_over_mass'
//@ghost g_207 = T_veh/M * g_206 
*  Sum: '<S39>/Add'
//@ghost g_206 = Foce on RR Wheel + Force on RL Wheel  
*  Sum: '<S39>/Sum'
//@ghost g_197 = g_207 + g_201  
*/
localDW->UnitDelay_DSTATE = (((rtu_FoceonRRWheel + rtu_ForceonRLWheel) +
rtu_ForceonFRWheel) + rtu_ForceonFLWheel) * 2.5E-6 + *rty_VehicleSpeedms;
}

/* System initialize for function-call system: '<Root>/Vehicle_Body_Wheels' */
static void Vehicle_Body_Wheels_Init(void)
{
/* SystemInitialize for Atomic SubSystem: '<S30>/FL_Wheel' */
FL_Wheel_Init();

/* End of SystemInitialize for SubSystem: '<S30>/FL_Wheel' */

/* SystemInitialize for Atomic SubSystem: '<S30>/FR_Wheel' */
FL_Wheel_Init();

/* End of SystemInitialize for SubSystem: '<S30>/FR_Wheel' */

/* SystemInitialize for Atomic SubSystem: '<S30>/RL_Wheel' */
FL_Wheel_Init();

/* End of SystemInitialize for SubSystem: '<S30>/RL_Wheel' */

/* SystemInitialize for Atomic SubSystem: '<S30>/RR_Wheel' */
RR_Wheel_Init();

/* End of SystemInitialize for SubSystem: '<S30>/RR_Wheel' */
}

/* Output and update for function-call system: '<Root>/Vehicle_Body_Wheels' */
//@ ensures g_213 = 3.6 * *rty_Veh_Spd_Realkmh = g_198 || 0
static void Vehicle_Body_Wheels(real_T rtu_RearRightBrkTorq, real_T rtu_RearLeftBrkTorq, real_T rtu_FrntRightBrkTorq, real_T rtu_FrntLeftBrkTorq,real_T rtu_AccPedalPos, real_T *rty_Veh_Spd_Realkmh, real_T*rty_RearRightWhl_rpm, real_T *rty_RearLeftWhl_rpm, real_T*rty_FrntRightWhl_rpm, real_T *rty_FrntLeftWhl_rpm, DW_Vehicle_Body_Wheels*localDW)
{
real_T Saturation;
real_T rtb_FL;
real_T rtb_FR;
real_T rtb_RL;
real_T Product_j;
real_T rtu_RearRightBrkTorq_0;

/* Switch: '<S30>/FL' incorporates:
//@ghost (FrntLeftBrkTorq>0)?g_230 = g_209 : g_230 = g_214 
*  Gain: '<S30>/half'
//@ghost g_218 = [5 5 5 5] * AccPedalPos 
*  Gain: '<S30>/negative3'
//@ghost g_209 = -1 * FrntLeftBrkTorq 
*/
if (rtu_FrntLeftBrkTorq > 0.0) {
rtb_FL = -rtu_FrntLeftBrkTorq;
} else {
rtb_FL = 5.0 * rtu_AccPedalPos;
}

/* End of Switch: '<S30>/FL' */
//@ghost (FrntLeftBrkTorq>0)?g_230 = g_209 : g_230 = g_214 

/* Outputs for Atomic SubSystem: '<S30>/Vehicle Model' */
VehicleModel(&Saturation, &localDW->VehicleModel_g);

/* End of Outputs for SubSystem: '<S30>/Vehicle Model' */

/* Outputs for Atomic SubSystem: '<S30>/FL_Wheel' */
FL_Wheel(rtb_FL, Saturation, &Product_j, rty_FrntLeftWhl_rpm,
&localDW->FL_Wheel_c);

/* End of Outputs for SubSystem: '<S30>/FL_Wheel' */

/* Switch: '<S30>/FR' incorporates:
//@ghost (FrntRightBrkTorq>0)?g_234 = g_210 : g_234 = g_215 
*  Gain: '<S30>/half'
//@ghost g_218 = [5 5 5 5] * AccPedalPos 
*  Gain: '<S30>/negative2'
//@ghost g_210 = -1 * FrntRightBrkTorq 
*/
if (rtu_FrntRightBrkTorq > 0.0) {
rtb_FR = -rtu_FrntRightBrkTorq;
} else {
rtb_FR = 5.0 * rtu_AccPedalPos;
}

/* End of Switch: '<S30>/FR' */
//@ghost (FrntRightBrkTorq>0)?g_234 = g_210 : g_234 = g_215 

/* Outputs for Atomic SubSystem: '<S30>/FR_Wheel' */
FL_Wheel(rtb_FR, Saturation, &rtb_FL, rty_FrntRightWhl_rpm, &localDW->FR_Wheel);

/* End of Outputs for SubSystem: '<S30>/FR_Wheel' */

/* Switch: '<S30>/RL' incorporates:
//@ghost (RearLeftBrkTorq>0)?g_222 = g_211 : g_222 = g_216 
*  Gain: '<S30>/half'
//@ghost g_218 = [5 5 5 5] * AccPedalPos 
*  Gain: '<S30>/negative1'
//@ghost g_211 = -1 * RearLeftBrkTorq 
*/
if (rtu_RearLeftBrkTorq > 0.0) {
rtb_RL = -rtu_RearLeftBrkTorq;
} else {
rtb_RL = 5.0 * rtu_AccPedalPos;
}

/* End of Switch: '<S30>/RL' */
//@ghost (RearLeftBrkTorq>0)?g_222 = g_211 : g_222 = g_216 

/* Outputs for Atomic SubSystem: '<S30>/RL_Wheel' */
FL_Wheel(rtb_RL, Saturation, &rtb_FR, rty_RearLeftWhl_rpm, &localDW->RL_Wheel);

/* End of Outputs for SubSystem: '<S30>/RL_Wheel' */

/* Switch: '<S30>/RR' incorporates:
//@ghost (RearRightBrkTorq>0)?g_226 = g_212 : g_226 = g_217 
*  Gain: '<S30>/half'
//@ghost g_218 = [5 5 5 5] * AccPedalPos 
*  Gain: '<S30>/negative'
//@ghost g_212 = -1 * RearRightBrkTorq 
*/
if (rtu_RearRightBrkTorq > 0.0) {
rtu_RearRightBrkTorq_0 = -rtu_RearRightBrkTorq;
} else {
rtu_RearRightBrkTorq_0 = 5.0 * rtu_AccPedalPos;
}

/* End of Switch: '<S30>/RR' */
//@ghost (RearRightBrkTorq>0)?g_226 = g_212 : g_226 = g_217 

/* Outputs for Atomic SubSystem: '<S30>/RR_Wheel' */
RR_Wheel(rtu_RearRightBrkTorq_0, Saturation, &rtb_RL, rty_RearRightWhl_rpm,
&localDW->RR_Wheel_h);

/* End of Outputs for SubSystem: '<S30>/RR_Wheel' */

/* Gain: '<S30>/v (km//h)' */
*rty_Veh_Spd_Realkmh = 3.6 * Saturation;

/* Update for Atomic SubSystem: '<S30>/Vehicle Model' */
VehicleModel_Update(rtb_RL, rtb_FR, rtb_FL, Product_j, &Saturation,
&localDW->VehicleModel_g);

/* End of Update for SubSystem: '<S30>/Vehicle Model' */
}

real_T rt_remd_snf(real_T u0, real_T u1)
{
real_T y;
real_T u1_0;
if (rtIsNaN(u0) || rtIsInf(u0) || (rtIsNaN(u1) || rtIsInf(u1))) {
y = (rtNaN);
} else {
if (u1 < 0.0) {
u1_0 = ceil(u1);
} else {
u1_0 = floor(u1);
}

if ((u1 != 0.0) && (u1 != u1_0)) {
u1_0 = fabs(u0 / u1);
if (fabs(u1_0 - floor(u1_0 + 0.5)) <= DBL_EPSILON * u1_0) {
y = 0.0 * u0;
} else {
y = fmod(u0, u1);
}
} else {
y = fmod(u0, u1);
}
}

return y;
}

real_T rt_roundd_snf(real_T u)
{
real_T y;
if (fabs(u) < 4.503599627370496E+15) {
if (u >= 0.5) {
y = floor(u + 0.5);
} else if (u > -0.5) {
y = u * 0.0;
} else {
y = ceil(u - 0.5);
}
} else {
y = u;
}

return y;
}

/* Model step function for TID0 */
void brake_acc_nodiv_step0(void)       /* Sample time: [0.0s, 0.0s] */
{
real_T wrpm;
real_T wrpm_h;
real_T wrpm_b;
real_T wrpm_n;
real_T rtb_vkmh;
real_T u0;

/* Update the flag to indicate when data transfers from
*  Sample time: [0.005s, 0.0s] to Sample time: [0.01s, 0.0s]  */
(rtM->Timing.RateInteraction.TID1_2)++;
if ((rtM->Timing.RateInteraction.TID1_2) > 1) {
rtM->Timing.RateInteraction.TID1_2 = 0;
}

/* Update the flag to indicate when data transfers from
*  Sample time: [0.005s, 0.0s] to Sample time: [0.02s, 0.0s]  */
(rtM->Timing.RateInteraction.TID1_3)++;
if ((rtM->Timing.RateInteraction.TID1_3) > 3) {
rtM->Timing.RateInteraction.TID1_3 = 0;
}

/* RateTransition: '<Root>/RT13' */
if (rtM->Timing.RateInteraction.TID1_2 == 1) {
/* Lookup_n-D: '<S7>/Look-Up Table1' incorporates:
*  Clock: '<S7>/Clock'
*  Constant: '<S7>/Constant'
*  Math: '<S7>/Math Function'
*  S-Function (sfun_tstart): '<S7>/startTime'
*  Sum: '<S7>/Sum'
*/
u0 = look1_binlx(rt_remd_snf(rtM->Timing.t[0] - (0.0), 100.0),
rtConstP.LookUpTable1_bp01Data,
rtConstP.LookUpTable1_tableData, 3U);

/* Saturate: '<S10>/Pedal_map' */
//@ghost elSignal = Position || 0  
if (u0 > 100.0) {
rtDW.RT13 = 100.0;
} else if (u0 < 0.0) {
rtDW.RT13 = 0.0;
} else {
rtDW.RT13 = u0;
}

/* End of Saturate: '<S10>/Pedal_map' */
//@ghost elSignal = Position || 0  
}

/* End of RateTransition: '<Root>/RT13' */
/* RateTransition: '<Root>/RT5' */
if (rtM->Timing.RateInteraction.TID1_2 == 1) {
rtDW.RT5 = rtDW.RT5_Buffer0;

/* RateTransition: '<Root>/RT6' */
rtDW.RT6 = rtDW.RT6_Buffer0;

/* RateTransition: '<Root>/RT7' */
rtDW.RT7 = rtDW.RT7_Buffer0;

/* RateTransition: '<Root>/RT8' */
rtDW.RT8 = rtDW.RT8_Buffer0;
}

/* End of RateTransition: '<Root>/RT5' */

/* Lookup_n-D: '<S6>/Look-Up Table1' incorporates:
*  Clock: '<S6>/Clock'
*  Constant: '<S6>/Constant'
*  Math: '<S6>/Math Function'
*  S-Function (sfun_tstart): '<S6>/startTime'
*  Sum: '<S6>/Sum'
*/
u0 = look1_binlx(rt_remd_snf(rtM->Timing.t[0] - (0.0), 100.0),
rtConstP.LookUpTable1_bp01Data_a,
rtConstP.LookUpTable1_tableData_o, 4U);

/* Saturate: '<S9>/Pedal_map' */
if (u0 > 100.0) {
u0 = 100.0;
} else {
if (u0 < 0.0) {
u0 = 0.0;
}
}

/* End of Saturate: '<S9>/Pedal_map' */

/* S-Function (fcncallgen): '<Root>/5ms' incorporates:
*  SubSystem: '<Root>/Vehicle_Body_Wheels'
*/
/* Rounding: '<S19>/to_int' */
Vehicle_Body_Wheels(rtDW.RT5, rtDW.RT6, rtDW.RT7, rtDW.RT8, rt_roundd_snf(u0),
&rtb_vkmh, &wrpm, &wrpm_h, &wrpm_b, &wrpm_n,
&rtDW.Vehicle_Body_Wheels_d);

/* End of Outputs for S-Function (fcncallgen): '<Root>/5ms' */

/* Rounding: '<S18>/to_int' */
rtb_vkmh = rt_roundd_snf(wrpm);

/* RateTransition: '<Root>/RT16' */
if (rtM->Timing.RateInteraction.TID1_2 == 1) {
rtDW.RT16 = rtb_vkmh;
}

/* End of RateTransition: '<Root>/RT16' */

/* RateTransition: '<Root>/RT9' */
if (rtM->Timing.RateInteraction.TID1_3 == 1) {
rtDW.RT9 = rtb_vkmh;
}

/* End of RateTransition: '<Root>/RT9' */

/* Rounding: '<S16>/to_int' */
wrpm_h = rt_roundd_snf(wrpm_h);

/* RateTransition: '<Root>/RT17' */
if (rtM->Timing.RateInteraction.TID1_2 == 1) {
rtDW.RT17 = wrpm_h;
}

/* End of RateTransition: '<Root>/RT17' */

/* RateTransition: '<Root>/RT10' */
if (rtM->Timing.RateInteraction.TID1_3 == 1) {
rtDW.RT10 = wrpm_h;
}

/* End of RateTransition: '<Root>/RT10' */

/* Rounding: '<S14>/to_int' */
wrpm_b = rt_roundd_snf(wrpm_b);

/* RateTransition: '<Root>/RT18' */
if (rtM->Timing.RateInteraction.TID1_2 == 1) {
rtDW.RT18 = wrpm_b;
}

/* End of RateTransition: '<Root>/RT18' */

/* RateTransition: '<Root>/RT11' */
if (rtM->Timing.RateInteraction.TID1_3 == 1) {
rtDW.RT11 = wrpm_b;
}

/* End of RateTransition: '<Root>/RT11' */

/* Rounding: '<S12>/to_int1' */
wrpm_n = rt_roundd_snf(wrpm_n);

/* RateTransition: '<Root>/RT19' */
if (rtM->Timing.RateInteraction.TID1_2 == 1) {
rtDW.RT19 = wrpm_n;
}

/* End of RateTransition: '<Root>/RT19' */

/* RateTransition: '<Root>/RT12' */
if (rtM->Timing.RateInteraction.TID1_3 == 1) {
rtDW.RT12 = wrpm_n;
}

/* End of RateTransition: '<Root>/RT12' */

/* Update absolute time */
/* The "clockTick0" counts the number of times the code of this task has
* been executed. The absolute time is the multiplication of "clockTick0"
* and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
* overflow during the application lifespan selected.
*/
rtM->Timing.t[0] =
(++rtM->Timing.clockTick0) * rtM->Timing.stepSize0;

/* Update absolute time */
/* The "clockTick1" counts the number of times the code of this task has
* been executed. The resolution of this integer timer is 0.005, which is the step size
* of the task. Size of "clockTick1" ensures timer will not overflow during the
* application lifespan selected.
*/
rtM->Timing.clockTick1++;
}

/* Model step function for TID2 */
void brake_acc_nodiv_step2(void)       /* Sample time: [0.01s, 0.0s] */
{
/* Update the flag to indicate when data transfers from
*  Sample time: [0.01s, 0.0s] to Sample time: [0.02s, 0.0s]  */
(rtM->Timing.RateInteraction.TID2_3)++;
if ((rtM->Timing.RateInteraction.TID2_3) > 1) {
rtM->Timing.RateInteraction.TID2_3 = 0;
}

/* RateTransition: '<Root>/RT' */
if (rtM->Timing.RateInteraction.TID2_3 == 1) {
rtDW.RT_h = rtDW.RT_Buffer0;

/* RateTransition: '<Root>/RT1' */
rtDW.RT1 = rtDW.RT1_Buffer0;

/* RateTransition: '<Root>/RT2' */
rtDW.RT2 = rtDW.RT2_Buffer0;

/* RateTransition: '<Root>/RT3' */
rtDW.RT3 = rtDW.RT3_Buffer0;

/* RateTransition: '<Root>/RT4' */
rtDW.RT4 = rtDW.RT4_Buffer0;
}

/* End of RateTransition: '<Root>/RT' */

/* S-Function (fcncallgen): '<Root>/10ms_1' incorporates:
*  SubSystem: '<Root>/ABS_RR_Wheel'
*/
ABS_RR_Wheel(rtDW.RT_h, rtDW.RT4, rtDW.RT16, &rtDW.Threshold_10kmh_e);

/* End of Outputs for S-Function (fcncallgen): '<Root>/10ms_1' */

/* S-Function (fcncallgen): '<Root>/10ms_2' incorporates:
*  SubSystem: '<Root>/ABS_RL_Wheel'
*/
ABS_RR_Wheel(rtDW.RT1, rtDW.RT4, rtDW.RT17, &rtDW.Threshold_10kmh_l);

/* End of Outputs for S-Function (fcncallgen): '<Root>/10ms_2' */

/* S-Function (fcncallgen): '<Root>/10ms_3' incorporates:
*  SubSystem: '<Root>/ABS_FR_Wheel'
*/
ABS_RR_Wheel(rtDW.RT2, rtDW.RT4, rtDW.RT18, &rtDW.Threshold_10kmh_o);

/* End of Outputs for S-Function (fcncallgen): '<Root>/10ms_3' */

/* S-Function (fcncallgen): '<Root>/10ms_4' incorporates:
*  SubSystem: '<Root>/ABS_FL_Wheel'
*/
ABS_RR_Wheel(rtDW.RT3, rtDW.RT4, rtDW.RT19, &rtDW.Threshold_10kmh);

/* End of Outputs for S-Function (fcncallgen): '<Root>/10ms_4' */

/* RateTransition: '<Root>/RT14' incorporates:
*  Gain: '<S5>/Gain1'
*  Rounding: '<S20>/round_to_int'
*/
if (rtM->Timing.RateInteraction.TID2_3 == 1) {
/* S-Function (fcncallgen): '<Root>/10ms' incorporates:
*  SubSystem: '<Root>/Brake_Torq_Calculation'
*/
rtDW.RT14 = 30.0 * rt_roundd_snf(rtDW.RT13);

/* End of Outputs for S-Function (fcncallgen): '<Root>/10ms' */
}

/* End of RateTransition: '<Root>/RT14' */

/* Update for RateTransition: '<Root>/RT5' */
rtDW.RT5_Buffer0 = rtDW.Threshold_10kmh_e;

/* Update for RateTransition: '<Root>/RT6' */
rtDW.RT6_Buffer0 = rtDW.Threshold_10kmh_l;

/* Update for RateTransition: '<Root>/RT7' */
rtDW.RT7_Buffer0 = rtDW.Threshold_10kmh_o;

/* Update for RateTransition: '<Root>/RT8' */
rtDW.RT8_Buffer0 = rtDW.Threshold_10kmh;
}

/* Model step function for TID3 */
void brake_acc_nodiv_step3(void)       /* Sample time: [0.02s, 0.0s] */
{
/* S-Function (fcncallgen): '<Root>/20ms' incorporates:
*  SubSystem: '<Root>/Global Brake Controller'
*/
/* Gain: '<S8>/Distribution' */
rtDW.Distribution[0] = 0.31 * rtDW.RT14;
rtDW.Distribution[1] = 0.29 * rtDW.RT14;
rtDW.Distribution[2] = 0.21 * rtDW.RT14;
rtDW.Distribution[3] = 0.19 * rtDW.RT14;

/* End of Outputs for S-Function (fcncallgen): '<Root>/20ms' */

/* S-Function (fcncallgen): '<Root>/20ms1' incorporates:
*  SubSystem: '<Root>/Veh_Speed_Estimator'
*/
Veh_Speed_Estimator(rtDW.RT9, rtDW.RT10, rtDW.RT11, rtDW.RT12, &rtDW.vkmh);

/* End of Outputs for S-Function (fcncallgen): '<Root>/20ms1' */

/* Update for RateTransition: '<Root>/RT' */
rtDW.RT_Buffer0 = rtDW.Distribution[0];

/* Update for RateTransition: '<Root>/RT1' */
rtDW.RT1_Buffer0 = rtDW.Distribution[1];

/* Update for RateTransition: '<Root>/RT2' */
rtDW.RT2_Buffer0 = rtDW.Distribution[2];

/* Update for RateTransition: '<Root>/RT3' */
rtDW.RT3_Buffer0 = rtDW.Distribution[3];

/* Update for RateTransition: '<Root>/RT4' */
rtDW.RT4_Buffer0 = rtDW.vkmh;
}

/* Model initialize function */
void brake_acc_nodiv_initialize(void)
{
/* Registration code */

/* initialize non-finites */
rt_InitInfAndNaN(sizeof(real_T));

{
/* Setup solver object */
rtsiSetSimTimeStepPtr(&rtM->solverInfo, &rtM->Timing.simTimeStep);
rtsiSetTPtr(&rtM->solverInfo, &rtmGetTPtr(rtM));
rtsiSetStepSizePtr(&rtM->solverInfo, &rtM->Timing.stepSize0);
rtsiSetErrorStatusPtr(&rtM->solverInfo, ((const char_T **)
(&rtmGetErrorStatus(rtM))));
rtsiSetRTModelPtr(&rtM->solverInfo, rtM);
}

rtsiSetSimTimeStep(&rtM->solverInfo, MAJOR_TIME_STEP);
rtsiSetSolverName(&rtM->solverInfo,"FixedStepDiscrete");
rtmSetTPtr(rtM, &rtM->Timing.tArray[0]);
rtM->Timing.stepSize0 = 0.005;

/* SystemInitialize for S-Function (fcncallgen): '<Root>/5ms' incorporates:
*  SubSystem: '<Root>/Vehicle_Body_Wheels'
*/
Vehicle_Body_Wheels_Init();

/* End of SystemInitialize for S-Function (fcncallgen): '<Root>/5ms' */
}

/*
* File trailer for generated code.
*
* [EOF]
*/
