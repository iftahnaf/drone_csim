#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "slros_time.h"
#include "interception_v15_types.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block interception_v15/Missile Position
extern SimulinkSubscriber<geometry_msgs::PoseStamped, SL_Bus_interception_v15_geometry_msgs_PoseStamped> Sub_interception_v15_180;

// For Block interception_v15/Missile Velocity
extern SimulinkSubscriber<geometry_msgs::TwistStamped, SL_Bus_interception_v15_geometry_msgs_TwistStamped> Sub_interception_v15_179;

// For Block interception_v15/Publish
extern SimulinkPublisher<mavros_msgs::ParamValue, SL_Bus_interception_v15_mavros_msgs_ParamValue> Pub_interception_v15_350;

// For Block interception_v15/Publish1
extern SimulinkPublisher<geometry_msgs::PoseStamped, SL_Bus_interception_v15_geometry_msgs_PoseStamped> Pub_interception_v15_442;

// For Block interception_v15/Publish2
extern SimulinkPublisher<geometry_msgs::PoseStamped, SL_Bus_interception_v15_geometry_msgs_PoseStamped> Pub_interception_v15_446;

// For Block interception_v15/Publish3
extern SimulinkPublisher<mavros_msgs::AttitudeTarget, SL_Bus_interception_v15_mavros_msgs_AttitudeTarget> Pub_interception_v15_451;

// For Block interception_v15/Publish4
extern SimulinkPublisher<geometry_msgs::TwistStamped, SL_Bus_interception_v15_geometry_msgs_TwistStamped> Pub_interception_v15_469;

// For Block interception_v15/Sending position commands/Publish
extern SimulinkPublisher<geometry_msgs::PoseStamped, SL_Bus_interception_v15_geometry_msgs_PoseStamped> Pub_interception_v15_311;

// For Block interception_v15/Sending thrust commands/Publish
extern SimulinkPublisher<mavros_msgs::AttitudeTarget, SL_Bus_interception_v15_mavros_msgs_AttitudeTarget> Pub_interception_v15_178;

// For Block interception_v15/Get Parameter
extern SimulinkParameterGetter<real64_T, double> ParamGet_interception_v15_334;

// For Block interception_v15/Get Parameter1
extern SimulinkParameterGetter<real64_T, double> ParamGet_interception_v15_275;

// For Block interception_v15/Get Parameter10
extern SimulinkParameterGetter<real64_T, double> ParamGet_interception_v15_506;

// For Block interception_v15/Get Parameter11
extern SimulinkParameterGetter<real64_T, double> ParamGet_interception_v15_583;

// For Block interception_v15/Get Parameter13
extern SimulinkParameterGetter<real64_T, double> ParamGet_interception_v15_552;

// For Block interception_v15/Get Parameter14
extern SimulinkParameterGetter<real64_T, double> ParamGet_interception_v15_553;

// For Block interception_v15/Get Parameter2
extern SimulinkParameterGetter<real64_T, double> ParamGet_interception_v15_276;

// For Block interception_v15/Get Parameter4
extern SimulinkParameterGetter<real64_T, double> ParamGet_interception_v15_479;

// For Block interception_v15/Get Parameter5
extern SimulinkParameterGetter<real64_T, double> ParamGet_interception_v15_281;

// For Block interception_v15/Get Parameter6
extern SimulinkParameterGetter<real64_T, double> ParamGet_interception_v15_480;

// For Block interception_v15/Get Parameter7
extern SimulinkParameterGetter<real64_T, double> ParamGet_interception_v15_482;

// For Block interception_v15/Get Parameter8
extern SimulinkParameterGetter<real64_T, double> ParamGet_interception_v15_339;

// For Block interception_v15/Get Parameter9
extern SimulinkParameterGetter<real64_T, double> ParamGet_interception_v15_340;

// For Block interception_v15/Target Position/Get Parameter
extern SimulinkParameterGetter<real64_T, double> ParamGet_interception_v15_262;

// For Block interception_v15/Target Position/Get Parameter1
extern SimulinkParameterGetter<real64_T, double> ParamGet_interception_v15_263;

// For Block interception_v15/Target Position/Get Parameter2
extern SimulinkParameterGetter<real64_T, double> ParamGet_interception_v15_264;

// For Block interception_v15/Target Velocity/Get Parameter
extern SimulinkParameterGetter<real64_T, double> ParamGet_interception_v15_269;

// For Block interception_v15/Target Velocity/Get Parameter1
extern SimulinkParameterGetter<real64_T, double> ParamGet_interception_v15_270;

// For Block interception_v15/Target Velocity/Get Parameter2
extern SimulinkParameterGetter<real64_T, double> ParamGet_interception_v15_271;

// For Block interception_v15/Set Parameter
extern SimulinkParameterSetter<real64_T, double> ParamSet_interception_v15_573;

// For Block interception_v15/Set Parameter1
extern SimulinkParameterSetter<real64_T, double> ParamSet_interception_v15_576;

void slros_node_init(int argc, char** argv);

#endif
