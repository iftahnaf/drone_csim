#!/usr/bin/python3
import rospy
from geometry_msgs.msg import PoseStamped
from geometry_msgs.msg import TwistStamped
import numpy as np
from numpy.linalg import norm as norm

class Reporter():
    def __init__(self):
        self.r_p_sub = rospy.Subscriber('/interception/r_p', PoseStamped, self.r_p_cb)
        self.r_e_sub = rospy.Subscriber('/interception/r_e', PoseStamped, self.r_e_cb)
        self.v_sub = rospy.Subscriber('/interception/v', TwistStamped, self.v_cb)
        self.r_p = np.array([0, 0, 0])
        self.r_e = np.array([130, 0, 50])
        self.range = 1000.0
        self.v = 0.0
        self.miss_distance = 1000000.0
        self.flag = True

    def r_p_cb(self, msg):
        self.r_p = np.array([msg.pose.position.x, msg.pose.position.y, msg.pose.position.z])
        
    def r_e_cb(self, msg):
        self.r_e = np.array([msg.pose.position.x, msg.pose.position.y, msg.pose.position.z])
    
    def v_cb(self, msg):
        v_tmp = [msg.twist.linear.x, msg.twist.linear.y, msg.twist.linear.z]
        self.v = norm(v_tmp)
    
    def calc_range(self):
        r = self.r_e - self.r_p
        self.range = norm(r)
    
    def calc_miss_distance(self):
        self.calc_range()
        self.tmp = self.range
        if self.v > 5.0 and self.flag:
            if self.range < self.miss_distance:
                self.miss_distance = self.range
            else:
                self.flag = False
                rospy.loginfo_once("Intercepred! Final Miss distance = {}".format(self.miss_distance))

def main():
    rospy.init_node('reporter', anonymous=True, disable_signals=True)
    reporter = Reporter()
    rate = rospy.Rate(10)
    while not rospy.is_shutdown():
        reporter.calc_miss_distance()
        rate.sleep()

if __name__ == '__main__':
    try:
            main()
    except rospy.ROSInterruptException:
            pass
        


    
