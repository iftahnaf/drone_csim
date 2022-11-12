#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "interception_v15";

// For Block interception_v15/Missile Position
SimulinkSubscriber<geometry_msgs::PoseStamped, SL_Bus_interception_v15_geometry_msgs_PoseStamped> Sub_interception_v15_180;

// For Block interception_v15/Missile Velocity
SimulinkSubscriber<geometry_msgs::TwistStamped, SL_Bus_interception_v15_geometry_msgs_TwistStamped> Sub_interception_v15_179;

// For Block interception_v15/Publish
SimulinkPublisher<mavros_msgs::ParamValue, SL_Bus_interception_v15_mavros_msgs_ParamValue> Pub_interception_v15_350;

// For Block interception_v15/Publish1
SimulinkPublisher<geometry_msgs::PoseStamped, SL_Bus_interception_v15_geometry_msgs_PoseStamped> Pub_interception_v15_442;

// For Block interception_v15/Publish2
SimulinkPublisher<geometry_msgs::PoseStamped, SL_Bus_interception_v15_geometry_msgs_PoseStamped> Pub_interception_v15_446;

// For Block interception_v15/Publish3
SimulinkPublisher<mavros_msgs::AttitudeTarget, SL_Bus_interception_v15_mavros_msgs_AttitudeTarget> Pub_interception_v15_451;

// For Block interception_v15/Publish4
SimulinkPublisher<geometry_msgs::TwistStamped, SL_Bus_interception_v15_geometry_msgs_TwistStamped> Pub_interception_v15_469;

// For Block interception_v15/Sending position commands/Publish
SimulinkPublisher<geometry_msgs::PoseStamped, SL_Bus_interception_v15_geometry_msgs_PoseStamped> Pub_interception_v15_311;

// For Block interception_v15/Sending thrust commands/Publish
SimulinkPublisher<mavros_msgs::AttitudeTarget, SL_Bus_interception_v15_mavros_msgs_AttitudeTarget> Pub_interception_v15_178;

// For Block interception_v15/Get Parameter
SimulinkParameterGetter<real64_T, double> ParamGet_interception_v15_334;

// For Block interception_v15/Get Parameter1
SimulinkParameterGetter<real64_T, double> ParamGet_interception_v15_275;

// For Block interception_v15/Get Parameter10
SimulinkParameterGetter<real64_T, double> ParamGet_interception_v15_506;

// For Block interception_v15/Get Parameter11
SimulinkParameterGetter<real64_T, double> ParamGet_interception_v15_583;

// For Block interception_v15/Get Parameter13
SimulinkParameterGetter<real64_T, double> ParamGet_interception_v15_552;

// For Block interception_v15/Get Parameter14
SimulinkParameterGetter<real64_T, double> ParamGet_interception_v15_553;

// For Block interception_v15/Get Parameter2
SimulinkParameterGetter<real64_T, double> ParamGet_interception_v15_276;

// For Block interception_v15/Get Parameter4
SimulinkParameterGetter<real64_T, double> ParamGet_interception_v15_479;

// For Block interception_v15/Get Parameter5
SimulinkParameterGetter<real64_T, double> ParamGet_interception_v15_281;

// For Block interception_v15/Get Parameter6
SimulinkParameterGetter<real64_T, double> ParamGet_interception_v15_480;

// For Block interception_v15/Get Parameter7
SimulinkParameterGetter<real64_T, double> ParamGet_interception_v15_482;

// For Block interception_v15/Get Parameter8
SimulinkParameterGetter<real64_T, double> ParamGet_interception_v15_339;

// For Block interception_v15/Get Parameter9
SimulinkParameterGetter<real64_T, double> ParamGet_interception_v15_340;

// For Block interception_v15/Target Position/Get Parameter
SimulinkParameterGetter<real64_T, double> ParamGet_interception_v15_262;

// For Block interception_v15/Target Position/Get Parameter1
SimulinkParameterGetter<real64_T, double> ParamGet_interception_v15_263;

// For Block interception_v15/Target Position/Get Parameter2
SimulinkParameterGetter<real64_T, double> ParamGet_interception_v15_264;

// For Block interception_v15/Target Velocity/Get Parameter
SimulinkParameterGetter<real64_T, double> ParamGet_interception_v15_269;

// For Block interception_v15/Target Velocity/Get Parameter1
SimulinkParameterGetter<real64_T, double> ParamGet_interception_v15_270;

// For Block interception_v15/Target Velocity/Get Parameter2
SimulinkParameterGetter<real64_T, double> ParamGet_interception_v15_271;

// For Block interception_v15/Set Parameter
SimulinkParameterSetter<real64_T, double> ParamSet_interception_v15_573;

// For Block interception_v15/Set Parameter1
SimulinkParameterSetter<real64_T, double> ParamSet_interception_v15_576;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

