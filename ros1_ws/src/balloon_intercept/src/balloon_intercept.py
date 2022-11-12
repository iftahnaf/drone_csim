#!/usr/bin/python3
from tkinter import Y
from turtle import end_fill
import rospy
from cv_bridge import CvBridge
from geometry_msgs.msg import PoseStamped
from geometry_msgs.msg import TwistStamped
from geometry_msgs.msg import Vector3Stamped
from mavros_msgs.msg import State
from mavros_msgs.srv import SetMode
from mavros_msgs.srv import CommandBool
from mavros_msgs.srv import SetMavFrame
from geometry_msgs.msg import Point
from std_msgs.msg import Float32
from copy import deepcopy
from balloon_setpoints import Balloon
from utils import VectorGuidance as vg
import time
import numpy as np

class BalloonIntercepor():
    def __init__(self):
        self.rate = rospy.Rate(20)
        self.bridge = CvBridge()

        self.width = 320
        self.height = 240
        self.fov = 1.04719 #[rad]

        self.target_position = np.array([0.0, 0.0, 0.0])  #save target position in local (world) frame. init to origin

        self.r_m = 0.5  #balloon radius in [m]
        self.counter = 0
        self.rho_u = 18.0  
        self.rho_v = 9.81
        self.min_range_norm = 10000 #save minimal range norm - init to high value

        self.pose = PoseStamped()
        self.vel = TwistStamped()
        self.state = State()

        self.des_vel = TwistStamped()
        self.des_vel.twist.angular.x = 0
        self.des_vel.twist.angular.y = 0
        self.des_vel.twist.linear.y = 0

        self.pose_sub = rospy.Subscriber('/mavros/local_position/pose', PoseStamped, self.pose_cb)
        self.vel_sub = rospy.Subscriber('/mavros/local_position/velocity_local', TwistStamped, self.vel_cb)
        self.state_sub = rospy.Subscriber('/mavros/state', State, self.state_cb)

        self.vel_pub = rospy.Publisher('/mavros/setpoint_velocity/cmd_vel', TwistStamped, queue_size=10)
        self.pose_pub = rospy.Publisher('/mavros/setpoint_position/local', PoseStamped, queue_size=10)
        self.acc_pub = rospy.Publisher('/mavros/setpoint_accel/accel', Vector3Stamped, queue_size=10)
        self.acc_cmd = Vector3Stamped()

        self.balloon = Balloon()

        self.change_mode = rospy.ServiceProxy('/mavros/set_mode', SetMode)
        self.arming = rospy.ServiceProxy('/mavros/cmd/arming', CommandBool)
        self.vel_frame = rospy.ServiceProxy('/mavros/setpoint_velocity/mav_frame', SetMavFrame)

        self.center_sub = rospy.Subscriber('/balloon/center', Point, self.center_cb)
        self.radius_sub = rospy.Subscriber('/balloon/radius', Float32, self.radius_cb)
        self.center = []
        self.tmp_center = self.center

        self.balloon_in_frame = True

        self.real_balloon_pose = None 

    def center_cb(self, msg):
        self.center = [0, 0]
        self.center[0] = msg.x
        self.center[1] = msg.y
    
    def radius_cb(self, msg):
        self.radius = msg.data

    def pose_cb(self, msg):
        self.pose = deepcopy(msg)

    def vel_cb(self, msg):
        self.vel = deepcopy(msg)
    
    def state_cb(self, msg):
        self.state = deepcopy(msg)

    def takoff_seq(self, des_pose):
        if self.state.armed == 0:
            rospy.wait_for_service('/mavros/cmd/arming')
            try:
                self.arming(True)
                rospy.loginfo("***** Arming ******")
            except rospy.ServiceException as e:
                print(e)
        
        if self.state.mode not in 'OFFBOARD':
            rospy.wait_for_service('/mavros/set_mode')
            try:
                k = 0
                while k < 10:
                    self.pose_pub.publish(des_pose)
                    self.rate.sleep()
                    k += 1
                rospy.loginfo("***** Changing to OFFBOARD Mode ******")
                self.change_mode(custom_mode='OFFBOARD')
            except rospy.ServiceException as e:
                print(e)

        rospy.wait_for_service('/mavros/setpoint_velocity/mav_frame')
        try:
            self.vel_frame(mav_frame=8)
        except rospy.ServiceException as e:
            print(e)
        
    def initialPose(self):
        des_pose = PoseStamped()
        err = 0.5
        des_pose.pose.position.x = 0.0
        des_pose.pose.position.y = 0.0
        des_pose.pose.position.z = 5.0

        self.takoff_seq(des_pose)
        z = self.pose.pose.position.z
        
        while des_pose.pose.position.z - z > err:
            z = self.pose.pose.position.z
            self.pose_pub.publish(des_pose)
            self.rate.sleep()
        
    def scanning(self):
        self.initialPose()
        
        balloon_in_range = False
        x_in_range = False
        y_in_range = False
        
        while not balloon_in_range:
            if self.center and self.radius:
                if self.center[0] > (2*self.radius) and self.center[0] < (self.width - 2*self.radius):
                    x_in_range = True
                
                if self.center[1] > (2*self.radius) and self.center[1] < (self.height - 2*self.radius):
                    y_in_range = True

                if x_in_range and y_in_range:
                    balloon_in_range = True
        
            self.des_vel.twist.linear.x = 0.0
            self.des_vel.twist.linear.z = 0.0
            self.des_vel.twist.angular.z = 0.2
            self.vel_pub.publish(self.des_vel)
            rospy.loginfo_throttle(10, "***** Scanning for Balloon *****")
            self.rate.sleep()

        rospy.loginfo("***** Found Balloon! *****")
        self.balloon = deepcopy(self.pose)
        self.counter = 0
        rospy.loginfo("Balloon Center: ({},{})".format(self.center[0], self.center[1]))

    def hold(self, hold_time=2):
        hold_time_start = time.time()
        while time.time() < hold_time + hold_time_start:
            self.pose_pub.publish(self.balloon)
            self.rate.sleep()
    
    def create_rp(self):
        rp_x = self.pose.pose.position.x
        rp_y = self.pose.pose.position.y
        rp_z = self.pose.pose.position.z
        rp = np.array([rp_x, rp_y, rp_z])  #drone position (from GPS)
        return rp

    def create_v(self):
        vpx = self.vel.twist.linear.x  
        vpy = self.vel.twist.linear.y
        vpz = self.vel.twist.linear.z
        v = -np.array([vpx, vpy, vpz]) #balloon stationary, so relative vel = drone vel
        return v

    def run(self):
        self.initialPose()
        while not rospy.is_shutdown() and self.min_range_norm > 0.3:
            try:
                self.real_balloon_pose = Balloon.get_balloon_real_position()
                self.counter = 0
                self.center = None
                self.scanning()
                self.hold(hold_time=3)

                v = self.create_v()
                rp = self.create_rp()

                vg.bounded_interception(self, self.min_range_norm, self.tmp_center, self.center,\
                                        self.balloon_in_frame, v, rp, self.real_balloon_pose, self.acc_cmd,\
                                        self.acc_pub, self.rate, self.rho_u, self.rho_v)
            except KeyboardInterrupt:
                rospy.signal_shutdown("Done")
                break

def main():
    rospy.init_node('balloon_killer', anonymous=True, disable_signals=True)
    rospy.loginfo_once('***** Initiate Balloon Killer Node *****')
    drone = BalloonIntercepor()
    drone.run()

if __name__ == '__main__':
    try:
        main()
    except Exception as e:
        print(e)
        pass