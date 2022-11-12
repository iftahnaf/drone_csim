import numpy as np
import rospy
from scipy.spatial.transform import Rotation as R
class VectorGuidance():
    def __init__(self):
        pass

    def tgo_bounded(self, r, v, rho_u, rho_v, m=0.0, min_tgo=0.001):
        #define the variables of the polynom
        drho = rho_u - rho_v
        rr = np.dot(r,r)
        rv = np.dot(r,v)
        vv = np.dot(r,v)
        #define the polynom
        a0 = -rr+m**2
        a1 = -2.0*rv
        a2 = -vv +m*drho
        a3 = 0.0
        a4 = 0.25*drho**2
        P = np.poly1d([a4, a3, a2, a1, a0])
        # calculate Tgo
        sol = np.roots(P)
        real_sol = np.real(sol)[abs(np.imag(sol)) < 1e-5]
        real_sol = np.real(real_sol)[np.real(real_sol) > 0]
        if len(real_sol) > 1:
            Tgo = min(real_sol)
        elif len(real_sol) == 0:
            Tgo = min_tgo
        else:
            Tgo = real_sol
        return Tgo + min_tgo

    def cont_bounded(self, Tgo, r, v, max_thrust=1):

        ux_unb = ((r[0] + Tgo*v[0])/np.linalg.norm(r + Tgo*v))
        uy_unb = ((r[1] + Tgo*v[1])/np.linalg.norm(r + Tgo*v))
        uz_unb = ((r[2] + Tgo*v[2])/np.linalg.norm(r + Tgo*v))
        
        u = np.array([ux_unb, uy_unb, uz_unb]) * max_thrust

        return u

    def cam_2_local(self, vec, qx, qy, qz, qw):
        ##rotate vector from cam to local (gazebo world) system
        
        cam_2_drone_rot_mat = np.eye(3)  #rotation matrix from camera to drone system
        
        local_2_drone_rot_mat = R.from_quat([qx, qy, qz, qw]) #rotation matrix from local to drone system
        local_2_drone_rot_mat=local_2_drone_rot_mat.as_dcm()
        
        drone_2_local_rot_mat = np.linalg.inv(local_2_drone_rot_mat) #rotation matrix from drone to local system
        
        tmp_mat = cam_2_drone_rot_mat*drone_2_local_rot_mat*np.transpose(vec)
        
        rot_vec=np.array([tmp_mat[0][0], tmp_mat[1][1], tmp_mat[2][2]])

        return rot_vec

    def range_est(self):
     
        ##range in drone ENU system 
        x_range_cam = (self.width*self.r_m)/(2*self.radius*np.tan((self.fov)/2))  
        y_range_cam = -(self.center[0] - (self.width / 2.0))*self.r_m/self.radius
        z_range_cam = -(self.center[1] - (self.height / 2.0))*self.r_m/self.radius

        #multiply by correction factors
        x_range_cam = x_range_cam*1.12

        range_cam = np.array([x_range_cam, y_range_cam, z_range_cam])
        
        return range_cam

    def create_r(self, balloon_in_frame, rp, real_balloon_pose):

        if  balloon_in_frame:
            print("balloon in frame")
            range_cam = self.range_est()
            local_range =  self.cam_2_local(range_cam)

            target_position = rp + local_range #while balloon in frame, update it's location in local frame
            print("cam_range = {}".format(range_cam))
            print("range = {}".format(local_range))
            print("target position = {}".format(target_position))
            r = local_range

        else:   #if baloon is out of frame, use drone GPS position and last known baloon position
            print("balloon out of frame")
            r = target_position - rp  
            
            print("range = {}".format(r))
            print("target position = {}".format(target_position))
        
        range_norm = np.linalg.norm(r)
        self.min_range_norm = min(self.min_range_norm, range_norm) #save the smallest norm
        rospy.loginfo("Min range norm = {}".format(self.min_range_norm))
        
        norm_to_real_balloon_pose = np.linalg.norm(real_balloon_pose-rp)  ##calculate eal miss distance
        rospy.loginfo("Norm to real baloon position = {}".format(norm_to_real_balloon_pose))

        return r

    def bounded_interception(self, min_range_norm, tmp_center, center, balloon_in_frame, v, rp, real_balloon_pose, acc_cmd, acc_pub, rate, rho_u, rho_v):
        while not rospy.is_shutdown() and min_range_norm > 0.3:
            if tmp_center == center:
                balloon_in_frame = False

            r = self.create_r(self, balloon_in_frame , rp, real_balloon_pose) #get relativerange and velocity in local frame
            
            tgo = self.tgo_bounded(r, v, rho_u, rho_v, m=0.0, min_tgo=0.001) # calc tgo
            u = self.cont_bounded(tgo, r, v, max_thrust=0.7) # calc accelaration command fro VG bounded

            acc_cmd.vector.x = u[0]   #construct accelaration msg
            acc_cmd.vector.y = u[1]
            acc_cmd.vector.z = u[2] + 0.3

            acc_pub.publish(acc_cmd)  #publish accelaration msg
            tmp_center = center

            rate.sleep()
