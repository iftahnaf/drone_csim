//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: interception_v15.h
//
// Code generated for Simulink model 'interception_v15'.
//
// Model version                  : 7.82
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Sat Oct 29 09:18:54 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_interception_v15_h_
#define RTW_HEADER_interception_v15_h_
#include "rtwtypes.h"
#include "slros_initialize.h"
#include "interception_v15_types.h"

extern "C"
{

#include "rtGetNaN.h"

}

extern "C"
{

#include "rt_nonfinite.h"

}

extern "C"
{

#include "rtGetInf.h"

}

#include <stddef.h>

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

// Block signals for system '<S19>/Current Time'
struct B_CurrentTime_interception_v1_T {
  SL_Bus_interception_v15_ros_time_Time CurrentTime;// '<S19>/Current Time'
};

// Block states (default storage) for system '<S19>/Current Time'
struct DW_CurrentTime_interception_v_T {
  ros_slros_internal_block_Curr_T obj; // '<S19>/Current Time'
  boolean_T objisempty;                // '<S19>/Current Time'
};

// Block signals (default storage)
struct B_interception_v15_T {
  creal_T V[16];
  creal_T At_data[16];
  creal_T b_A_data[16];
  creal_T At[16];
  SL_Bus_interception_v15_mavros_msgs_AttitudeTarget BusAssignment;// '<S20>/Bus Assignment' 
  SL_Bus_interception_v15_geometry_msgs_PoseStamped In1;// '<S28>/In1'
  SL_Bus_interception_v15_geometry_msgs_PoseStamped BusAssignment_h;// '<S19>/Bus Assignment' 
  SL_Bus_interception_v15_geometry_msgs_TwistStamped In1_m;// '<S29>/In1'
  SL_Bus_interception_v15_geometry_msgs_TwistStamped BusAssignment4;// '<Root>/Bus Assignment4' 
  real_T c_a_data[16];
  real_T T[16];
  real_T U[16];
  creal_T tgoroots_data[4];
  creal_T eiga_data[4];
  creal_T alpha1_data[4];
  creal_T vwork_data[4];
  creal_T e_x[4];
  creal_T work1[4];
  real_T c[5];
  real_T ctmp[5];
  char_T b_zeroDelimTopic[38];
  char_T b_zeroDelimName[35];
  char_T b_zeroDelimTopic_m[32];
  real_T y_data[4];
  real_T x_data[4];
  real_T quat[4];                      // '<S6>/MATLAB Function'
  real_T work[4];
  real_T rworka[4];
  real_T zr_data[4];
  real_T zi_data[4];
  real_T absx_data[4];
  char_T b_zeroDelimName_c[31];
  char_T b_zeroDelimTopic_k[30];
  char_T b_zeroDelimName_cx[29];
  char_T b_zeroDelimTopic_b[28];
  char_T b_zeroDelimName_p[27];
  char_T b_zeroDelimName_cv[26];
  char_T b_zeroDelimName_f[25];
  char_T b_zeroDelimName_g[24];
  real_T RateTransition[3];            // '<Root>/Rate Transition'
  real_T AddPose[3];                   // '<Root>/Add - Pose'
  real_T AddVelocity[3];               // '<Root>/Add - Velocity'
  real_T MathFunction_j[3];            // '<S18>/Math Function'
  real_T tau[3];
  real_T v[3];
  int32_T rscale[4];
  int32_T idx_data[4];
  int32_T iwork_data[4];
  int32_T b_iwork_data[4];
  SL_Bus_interception_v15_mavros_msgs_ParamValue BusAssignment_k;// '<Root>/Bus Assignment' 
  SL_Bus_interception_v15_ros_time_Time rtb_CurrentTime_d;
  creal_T eiga;
  creal_T atmp;
  creal_T ctemp;
  creal_T y;
  creal_T stemp;
  creal_T ascale;
  creal_T atmp_g;
  creal_T ctemp_m;
  creal_T y_n;
  creal_T stemp_p;
  creal_T ascale_l;
  creal_T work1_j;
  real_T state;                        // '<Root>/logic'
  real_T stop;                         // '<Root>/logic'
  real_T absx;
  real_T b_absx;
  real_T absxk;
  real_T t;
  real_T K14;
  real_T tgo4;                         // '<Root>/Numeric Calculation of Tgo'
  real_T Tan;                          // '<S6>/Tan'
  real_T rtb_Saturation_idx_2;
  real_T rtb_Saturation_idx_1;
  real_T rtb_Saturation_idx_0;
  real_T y_idx_2;
  real_T y_idx_1;
  real_T y_idx_0;
  real_T rtb_u_idx_2;
  real_T rtb_u_idx_1;
  real_T rtb_u_idx_0;
  real_T zb_des_idx_2;
  real_T yb_des_idx_1;
  real_T yb_des_idx_0;
  real_T c_tmp;
  real_T anrm;
  real_T absxk_g;
  real_T cfromc;
  real_T ctoc;
  real_T cfrom1;
  real_T cto1;
  real_T stemp_im_tmp;
  real_T anorm;
  real_T temp;
  real_T temp2;
  real_T scale;
  real_T ssq;
  real_T colscale;
  real_T absxk_l;
  real_T t_d;
  real_T x_re;
  real_T x_im;
  real_T eshift_re;
  real_T eshift_im;
  real_T stemp_im_tmp_d;
  real_T g2;
  real_T f2s;
  real_T di;
  real_T scale_l;
  real_T x;
  real_T fs_re;
  real_T fs_im;
  real_T gs_re;
  real_T gs_im;
  real_T a;
  real_T b;
  real_T anrm_o;
  real_T vtemp;
  real_T b_absxk;
  real_T cfromc_b;
  real_T ctoc_n;
  real_T cto1_b;
  real_T stemp_im_tmp_l;
  real_T anorm_h;
  real_T temp_b;
  real_T temp2_d;
  real_T scale_e;
  real_T ssq_b;
  real_T colscale_j;
  real_T absxk_f;
  real_T t_a;
  real_T x_im_j;
  real_T eshift_re_j;
  real_T eshift_im_o;
  real_T stemp_im_tmp_n;
  real_T g2_i;
  real_T d;
  real_T f2s_o;
  real_T scale_n;
  real_T x_m;
  real_T fs_re_c;
  real_T fs_im_m;
  real_T gs_re_m;
  real_T gs_im_j;
  real_T beta1;
  real_T A;
  real_T tst;
  real_T htmp1;
  real_T ab;
  real_T ba;
  real_T aa;
  real_T h12;
  real_T h21s;
  real_T a__4;
  real_T s_tmp;
  real_T temp_h;
  real_T p;
  real_T bcmax;
  real_T bcmis;
  real_T scale_c;
  real_T z;
  real_T anorm_c;
  real_T ascale_p;
  real_T temp_p;
  real_T acoeff;
  real_T scale_a;
  real_T dmin;
  real_T salpha_re;
  real_T salpha_im;
  real_T d_re;
  real_T work2_idx_3_re;
  real_T work2_idx_3_im;
  real_T absxk_e;
  real_T zr0;
  real_T absxk_tmp;
  real_T xnorm;
  real_T a_a;
  real_T scale_as;
  real_T absxk_i;
  real_T t_l;
  real_T g2_o;
  real_T f2s_o2;
  real_T di_i;
  real_T g2_f;
  real_T d_i;
  real_T absxr;
  real_T absxi;
  int32_T c_a_size[2];
  int32_T At_size[2];
  int8_T b_data[4];
  boolean_T bb_data[4];
  int32_T k1;
  int32_T k2;
  int32_T companDim;
  int32_T j;
  int32_T vstride;
  int32_T b_vstride;
  int32_T active;                      // '<Root>/MATLAB Function2'
  int32_T tgoroots_size;
  int32_T eiga_size;
  int32_T alpha1_size;
  int32_T vwork_size;
  int32_T bb_size;
  int32_T k;
  int32_T ii;
  int32_T nzcount;
  int32_T jj;
  int32_T c_n;
  int32_T jcol;
  int32_T loop_ub;
  int32_T atmp_tmp;
  int32_T n;
  int32_T j_f;
  int32_T b_k;
  int32_T ii_g;
  int32_T nzcount_c;
  int32_T jj_o;
  int32_T jrow;
  int32_T jcol_l;
  int32_T e_i;
  int32_T in;
  int32_T ia;
  int32_T f_i;
  int32_T ix0;
  int32_T knt;
  int32_T lastc;
  int32_T iac;
  int32_T l;
  int32_T b_ia;
  int32_T rowleft;
  int32_T c_ia;
  int32_T alpha1_tmp;
  int32_T work_tmp;
  int32_T n_m;
  int32_T nc;
  int32_T g_k;
  B_CurrentTime_interception_v1_T CurrentTime_pn;// '<S19>/Current Time'
  B_CurrentTime_interception_v1_T CurrentTime_p;// '<S19>/Current Time'
};

// Block states (default storage) for system '<Root>'
struct DW_interception_v15_T {
  ros_slros_internal_block_Curr_T obj; // '<Root>/Current Time'
  ros_slros_internal_block_GetP_T obj_c;// '<S22>/Get Parameter2'
  ros_slros_internal_block_GetP_T obj_i;// '<S22>/Get Parameter1'
  ros_slros_internal_block_GetP_T obj_b;// '<S22>/Get Parameter'
  ros_slros_internal_block_GetP_T obj_g;// '<S21>/Get Parameter2'
  ros_slros_internal_block_GetP_T obj_h;// '<S21>/Get Parameter1'
  ros_slros_internal_block_GetP_T obj_a;// '<S21>/Get Parameter'
  ros_slros_internal_block_GetP_T obj_m;// '<Root>/Get Parameter9'
  ros_slros_internal_block_GetP_T obj_mn;// '<Root>/Get Parameter8'
  ros_slros_internal_block_GetP_T obj_p;// '<Root>/Get Parameter7'
  ros_slros_internal_block_GetP_T obj_av;// '<Root>/Get Parameter6'
  ros_slros_internal_block_GetP_T obj_o;// '<Root>/Get Parameter5'
  ros_slros_internal_block_GetP_T obj_l;// '<Root>/Get Parameter4'
  ros_slros_internal_block_GetP_T obj_bh;// '<Root>/Get Parameter2'
  ros_slros_internal_block_GetP_T obj_f;// '<Root>/Get Parameter14'
  ros_slros_internal_block_GetP_T obj_pt;// '<Root>/Get Parameter13'
  ros_slros_internal_block_GetP_T obj_ak;// '<Root>/Get Parameter11'
  ros_slros_internal_block_GetP_T obj_pb;// '<Root>/Get Parameter10'
  ros_slros_internal_block_GetP_T obj_a3;// '<Root>/Get Parameter1'
  ros_slros_internal_block_GetP_T obj_d;// '<Root>/Get Parameter'
  ros_slroscpp_internal_block_S_T obj_e;// '<S10>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_e0;// '<S9>/SourceBlock'
  ros_slroscpp_internal_block_P_T obj_gb;// '<S33>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_ap;// '<S31>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_go;// '<S16>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_mm;// '<S15>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_c5;// '<S14>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_ft;// '<S13>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_cs;// '<S12>/SinkBlock'
  ros_slros_internal_block_SetP_T obj_j;// '<Root>/Set Parameter1'
  ros_slros_internal_block_SetP_T obj_hv;// '<Root>/Set Parameter'
  real_T Delay_DSTATE[2];              // '<Root>/Delay'
  real_T Vel2Pos_DSTATE[3];            // '<Root>/Vel2Pos'
  real_T RateTransition_Buffer0[3];    // '<Root>/Rate Transition'
  real_T Memory_PreviousInput;         // '<S27>/Memory'
  real_T tmp_range;                    // '<Root>/logic'
  real_T done;                         // '<Root>/logic'
  real_T flag;                         // '<Root>/MATLAB Function2'
  uint8_T Vel2Pos_IC_LOADING;          // '<Root>/Vel2Pos'
  uint8_T is_c3_interception_v15;      // '<Root>/logic'
  uint8_T is_active_c3_interception_v15;// '<Root>/logic'
  uint8_T temporalCounter_i1;          // '<Root>/logic'
  DW_CurrentTime_interception_v_T CurrentTime_pn;// '<S19>/Current Time'
  DW_CurrentTime_interception_v_T CurrentTime_p;// '<S19>/Current Time'
};

// Parameters (default storage)
struct P_interception_v15_T_ {
  real_T MinMaxRunningResettable_vinit;
                                // Mask Parameter: MinMaxRunningResettable_vinit
                                   //  Referenced by:
                                   //    '<S27>/Initial Condition'
                                   //    '<S27>/Memory'

  SL_Bus_interception_v15_mavros_msgs_AttitudeTarget Constant_Value;// Computed Parameter: Constant_Value
                                                                      //  Referenced by: '<S4>/Constant'

  SL_Bus_interception_v15_mavros_msgs_AttitudeTarget Constant_Value_h;// Computed Parameter: Constant_Value_h
                                                                      //  Referenced by: '<S32>/Constant'

  SL_Bus_interception_v15_geometry_msgs_PoseStamped Constant_Value_i;// Computed Parameter: Constant_Value_i
                                                                      //  Referenced by: '<S2>/Constant'

  SL_Bus_interception_v15_geometry_msgs_PoseStamped Constant_Value_a;// Computed Parameter: Constant_Value_a
                                                                      //  Referenced by: '<S3>/Constant'

  SL_Bus_interception_v15_geometry_msgs_PoseStamped Out1_Y0;// Computed Parameter: Out1_Y0
                                                               //  Referenced by: '<S28>/Out1'

  SL_Bus_interception_v15_geometry_msgs_PoseStamped Constant_Value_f;// Computed Parameter: Constant_Value_f
                                                                      //  Referenced by: '<S9>/Constant'

  SL_Bus_interception_v15_geometry_msgs_PoseStamped Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                                      //  Referenced by: '<S30>/Constant'

  SL_Bus_interception_v15_geometry_msgs_TwistStamped Constant_Value_e;// Computed Parameter: Constant_Value_e
                                                                      //  Referenced by: '<S5>/Constant'

  SL_Bus_interception_v15_geometry_msgs_TwistStamped Out1_Y0_f;// Computed Parameter: Out1_Y0_f
                                                                  //  Referenced by: '<S29>/Out1'

  SL_Bus_interception_v15_geometry_msgs_TwistStamped Constant_Value_j;// Computed Parameter: Constant_Value_j
                                                                      //  Referenced by: '<S10>/Constant'

  SL_Bus_interception_v15_mavros_msgs_ParamValue Constant_Value_g;// Computed Parameter: Constant_Value_g
                                                                     //  Referenced by: '<S1>/Constant'

  real_T RateTransition_InitialCondition;// Expression: 0
                                            //  Referenced by: '<Root>/Rate Transition'

  real_T Saturation_UpperSat[3];       // Expression: [260,260,120]
                                          //  Referenced by: '<Root>/Saturation'

  real_T Saturation_LowerSat[3];       // Expression: [-260,-260,5]
                                          //  Referenced by: '<Root>/Saturation'

  real_T Delay_InitialCondition;       // Expression: 0.0
                                          //  Referenced by: '<Root>/Delay'

  real_T Vel2Pos_gainval;              // Computed Parameter: Vel2Pos_gainval
                                          //  Referenced by: '<Root>/Vel2Pos'

};

// Real-time Model Data Structure
struct tag_RTM_interception_v15_T {
  const char_T * volatile errorStatus;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;

    boolean_T stopRequestedFlag;
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_interception_v15_T interception_v15_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_interception_v15_T interception_v15_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_interception_v15_T interception_v15_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void interception_v15_initialize(void);
  extern void interception_v15_step(void);
  extern void interception_v15_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_interception_v15_T *const interception_v15_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S8>/Data Type Duplicate' : Unused code path elimination
//  Block '<S27>/FixPt Data Type Duplicate2' : Unused code path elimination
//  Block '<Root>/Miss Distance' : Unused code path elimination
//  Block '<Root>/Range From Target ' : Unused code path elimination
//  Block '<Root>/Tgo' : Unused code path elimination
//  Block '<S6>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S6>/Data Type Conversion1' : Eliminate redundant data type conversion


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'interception_v15'
//  '<S1>'   : 'interception_v15/Blank Message'
//  '<S2>'   : 'interception_v15/Blank Message1'
//  '<S3>'   : 'interception_v15/Blank Message2'
//  '<S4>'   : 'interception_v15/Blank Message3'
//  '<S5>'   : 'interception_v15/Blank Message4'
//  '<S6>'   : 'interception_v15/Controller'
//  '<S7>'   : 'interception_v15/MATLAB Function2'
//  '<S8>'   : 'interception_v15/MinMax Running Resettable'
//  '<S9>'   : 'interception_v15/Missile Position'
//  '<S10>'  : 'interception_v15/Missile Velocity'
//  '<S11>'  : 'interception_v15/Numeric Calculation of Tgo'
//  '<S12>'  : 'interception_v15/Publish'
//  '<S13>'  : 'interception_v15/Publish1'
//  '<S14>'  : 'interception_v15/Publish2'
//  '<S15>'  : 'interception_v15/Publish3'
//  '<S16>'  : 'interception_v15/Publish4'
//  '<S17>'  : 'interception_v15/Range'
//  '<S18>'  : 'interception_v15/Range1'
//  '<S19>'  : 'interception_v15/Sending position commands'
//  '<S20>'  : 'interception_v15/Sending thrust commands'
//  '<S21>'  : 'interception_v15/Target Position'
//  '<S22>'  : 'interception_v15/Target Velocity'
//  '<S23>'  : 'interception_v15/logic'
//  '<S24>'  : 'interception_v15/Controller/Controller'
//  '<S25>'  : 'interception_v15/Controller/MATLAB Function'
//  '<S26>'  : 'interception_v15/Controller/Norm3'
//  '<S27>'  : 'interception_v15/MinMax Running Resettable/Subsystem'
//  '<S28>'  : 'interception_v15/Missile Position/Enabled Subsystem'
//  '<S29>'  : 'interception_v15/Missile Velocity/Enabled Subsystem'
//  '<S30>'  : 'interception_v15/Sending position commands/Blank Message'
//  '<S31>'  : 'interception_v15/Sending position commands/Publish'
//  '<S32>'  : 'interception_v15/Sending thrust commands/Blank Message'
//  '<S33>'  : 'interception_v15/Sending thrust commands/Publish'

#endif                                 // RTW_HEADER_interception_v15_h_

//
// File trailer for generated code.
//
// [EOF]
//
