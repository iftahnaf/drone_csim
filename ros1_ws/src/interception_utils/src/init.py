#!/usr/bin/python3
import rospy

from mavros_msgs.msg import State
from mavros_msgs.srv import SetMode
from mavros_msgs.srv import CommandBool

import numpy as np
from numpy.linalg import norm as norm
from copy import deepcopy
from time import sleep

class DroneInitialize():
    def __init__(self):
        self.state_sub = rospy.Subscriber('/mavros/state', State, self.state_cb)

        self.change_mode = rospy.ServiceProxy('/mavros/set_mode', SetMode)
        self.arming = rospy.ServiceProxy('/mavros/cmd/arming', CommandBool)

        self.state = State()

        rospy.set_param('/mavros/interception/t_x', 50.0)
        rospy.set_param('/mavros/interception/t_y', 50.0)
        rospy.set_param('/mavros/interception/t_z', 50.0)
        
        rospy.set_param('/mavros/interception/t_vx', 0.0)
        rospy.set_param('/mavros/interception/t_vy', 0.0)
        rospy.set_param('/mavros/interception/t_vz', 0.0)

        rospy.set_param('/mavros/interception/m', 0.0)
        rospy.set_param('/mavros/interception/max_thrust', 1.0)
        rospy.set_param('/mavros/interception/min_tgo', 0.01)
        rospy.set_param('/mavros/interception/xf', 0.0)
        rospy.set_param('/mavros/interception/yf', 0.0)
        rospy.set_param('/mavros/interception/zf', 2.0)
        rospy.set_param('/mavros/interception/delta_rho', 10.0)
        rospy.set_param('/mavros/interception/rho_u', 70.0)
        rospy.set_param('/mavros/interception/g', 9.81)
        rospy.set_param('/mavros/interception/mass', 1.5)
        rospy.set_param('/mavros/interception/max_dist', 260.0)
        rospy.set_param('/mavros/interception/max_height', 100.0)
        rospy.set_param('/mavros/interception/k_gui', 0.07)

        self.tx = rospy.get_param('/mavros/interception/t_x')
        self.ty = rospy.get_param('/mavros/interception/t_y')
        self.tz = rospy.get_param('/mavros/interception/t_z')

        self.tvx = rospy.get_param('/mavros/interception/t_vx')
        self.tvy = rospy.get_param('/mavros/interception/t_vy')
        self.tvz = rospy.get_param('/mavros/interception/t_vz')

        self.rho_u = rospy.get_param('mavros/interception/rho_u')
        self.delta_rho = rospy.get_param('/mavros/interception/delta_rho')
        self.k_gui = rospy.get_param('/mavros/interception/k_gui')
        
        self.r_e = np.array([self.tx, self.ty, self.tz])

        rospy.loginfo_once("tx = {}, ty = {}, tz = {}".format(self.tx, self.ty, self.tz))
        rospy.loginfo_once("tvx = {}, tvy = {}, tvz = {}".format(self.tvx, self.tvy, self.tvz))
        rospy.loginfo_once("rho_u = {}, delta_rho = {}, k_gui = {}".format(self.rho_u, self.delta_rho, self.k_gui))

        sleep(5)

    def state_cb(self, msg):
        self.state = deepcopy(msg)
    
    def takeoff(self):
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
                rospy.loginfo("***** Changing to OFFBOARD Mode ******")
                self.change_mode(custom_mode='OFFBOARD')
            except rospy.ServiceException as e:
                print(e)

def main():
    rospy.init_node('start', anonymous=True, disable_signals=True)
    init = DroneInitialize()
    init.takeoff()

if __name__ == '__main__':
    try:
            main()
    except rospy.ROSInterruptException:
            pass
        


    
