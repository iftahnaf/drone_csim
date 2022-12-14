//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: interception_v15_types.h
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
#ifndef RTW_HEADER_interception_v15_types_h_
#define RTW_HEADER_interception_v15_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_interception_v15_mavros_msgs_ParamValue_
#define DEFINED_TYPEDEF_FOR_SL_Bus_interception_v15_mavros_msgs_ParamValue_

// MsgType=mavros_msgs/ParamValue
struct SL_Bus_interception_v15_mavros_msgs_ParamValue
{
  // Int64Type=int64
  real_T Integer;
  real_T Real;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_interception_v15_ros_time_Time_
#define DEFINED_TYPEDEF_FOR_SL_Bus_interception_v15_ros_time_Time_

// MsgType=ros_time/Time
struct SL_Bus_interception_v15_ros_time_Time
{
  real_T Sec;
  real_T Nsec;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_

struct SL_Bus_ROSVariableLengthArrayInfo
{
  uint32_T CurrentLength;
  uint32_T ReceivedLength;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_interception_v15_std_msgs_Header_
#define DEFINED_TYPEDEF_FOR_SL_Bus_interception_v15_std_msgs_Header_

// MsgType=std_msgs/Header
struct SL_Bus_interception_v15_std_msgs_Header
{
  uint32_T Seq;

  // MsgType=ros_time/Time
  SL_Bus_interception_v15_ros_time_Time Stamp;

  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=FrameId_SL_Info:TruncateAction=warn 
  uint8_T FrameId[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=FrameId
  SL_Bus_ROSVariableLengthArrayInfo FrameId_SL_Info;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_interception_v15_geometry_msgs_Point_
#define DEFINED_TYPEDEF_FOR_SL_Bus_interception_v15_geometry_msgs_Point_

// MsgType=geometry_msgs/Point
struct SL_Bus_interception_v15_geometry_msgs_Point
{
  real_T X;
  real_T Y;
  real_T Z;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_interception_v15_geometry_msgs_Quaternion_
#define DEFINED_TYPEDEF_FOR_SL_Bus_interception_v15_geometry_msgs_Quaternion_

// MsgType=geometry_msgs/Quaternion
struct SL_Bus_interception_v15_geometry_msgs_Quaternion
{
  real_T X;
  real_T Y;
  real_T Z;
  real_T W;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_interception_v15_geometry_msgs_Pose_
#define DEFINED_TYPEDEF_FOR_SL_Bus_interception_v15_geometry_msgs_Pose_

// MsgType=geometry_msgs/Pose
struct SL_Bus_interception_v15_geometry_msgs_Pose
{
  // MsgType=geometry_msgs/Point
  SL_Bus_interception_v15_geometry_msgs_Point Position;

  // MsgType=geometry_msgs/Quaternion
  SL_Bus_interception_v15_geometry_msgs_Quaternion Orientation;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_interception_v15_geometry_msgs_PoseStamped_
#define DEFINED_TYPEDEF_FOR_SL_Bus_interception_v15_geometry_msgs_PoseStamped_

// MsgType=geometry_msgs/PoseStamped
struct SL_Bus_interception_v15_geometry_msgs_PoseStamped
{
  // MsgType=std_msgs/Header
  SL_Bus_interception_v15_std_msgs_Header Header;

  // MsgType=geometry_msgs/Pose
  SL_Bus_interception_v15_geometry_msgs_Pose Pose;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_interception_v15_geometry_msgs_Vector3_
#define DEFINED_TYPEDEF_FOR_SL_Bus_interception_v15_geometry_msgs_Vector3_

// MsgType=geometry_msgs/Vector3
struct SL_Bus_interception_v15_geometry_msgs_Vector3
{
  real_T X;
  real_T Y;
  real_T Z;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_interception_v15_mavros_msgs_AttitudeTarget_
#define DEFINED_TYPEDEF_FOR_SL_Bus_interception_v15_mavros_msgs_AttitudeTarget_

// MsgType=mavros_msgs/AttitudeTarget
struct SL_Bus_interception_v15_mavros_msgs_AttitudeTarget
{
  // MsgType=std_msgs/Header
  SL_Bus_interception_v15_std_msgs_Header Header;
  uint8_T TypeMask;

  // MsgType=geometry_msgs/Quaternion
  SL_Bus_interception_v15_geometry_msgs_Quaternion Orientation;

  // MsgType=geometry_msgs/Vector3
  SL_Bus_interception_v15_geometry_msgs_Vector3 BodyRate;
  real32_T Thrust;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_interception_v15_geometry_msgs_Twist_
#define DEFINED_TYPEDEF_FOR_SL_Bus_interception_v15_geometry_msgs_Twist_

// MsgType=geometry_msgs/Twist
struct SL_Bus_interception_v15_geometry_msgs_Twist
{
  // MsgType=geometry_msgs/Vector3
  SL_Bus_interception_v15_geometry_msgs_Vector3 Linear;

  // MsgType=geometry_msgs/Vector3
  SL_Bus_interception_v15_geometry_msgs_Vector3 Angular;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_interception_v15_geometry_msgs_TwistStamped_
#define DEFINED_TYPEDEF_FOR_SL_Bus_interception_v15_geometry_msgs_TwistStamped_

// MsgType=geometry_msgs/TwistStamped
struct SL_Bus_interception_v15_geometry_msgs_TwistStamped
{
  // MsgType=std_msgs/Header
  SL_Bus_interception_v15_std_msgs_Header Header;

  // MsgType=geometry_msgs/Twist
  SL_Bus_interception_v15_geometry_msgs_Twist Twist;
};

#endif

#ifndef struct_f_robotics_slcore_internal_bl_T
#define struct_f_robotics_slcore_internal_bl_T

struct f_robotics_slcore_internal_bl_T
{
  int32_T __dummy;
};

#endif                                // struct_f_robotics_slcore_internal_bl_T

#ifndef struct_ros_slros_internal_block_Curr_T
#define struct_ros_slros_internal_block_Curr_T

struct ros_slros_internal_block_Curr_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  f_robotics_slcore_internal_bl_T SampleTimeHandler;
};

#endif                                // struct_ros_slros_internal_block_Curr_T

#ifndef struct_ros_slroscpp_internal_block_S_T
#define struct_ros_slroscpp_internal_block_S_T

struct ros_slroscpp_internal_block_S_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                // struct_ros_slroscpp_internal_block_S_T

#ifndef struct_ros_slroscpp_internal_block_P_T
#define struct_ros_slroscpp_internal_block_P_T

struct ros_slroscpp_internal_block_P_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                // struct_ros_slroscpp_internal_block_P_T

#ifndef struct_ros_slros_internal_block_SetP_T
#define struct_ros_slros_internal_block_SetP_T

struct ros_slros_internal_block_SetP_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                // struct_ros_slros_internal_block_SetP_T

#ifndef struct_ros_slros_internal_block_GetP_T
#define struct_ros_slros_internal_block_GetP_T

struct ros_slros_internal_block_GetP_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  f_robotics_slcore_internal_bl_T SampleTimeHandler;
};

#endif                                // struct_ros_slros_internal_block_GetP_T

// Parameters (default storage)
typedef struct P_interception_v15_T_ P_interception_v15_T;

// Forward declaration for rtModel
typedef struct tag_RTM_interception_v15_T RT_MODEL_interception_v15_T;

#endif                                 // RTW_HEADER_interception_v15_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
