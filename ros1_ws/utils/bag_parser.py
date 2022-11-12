import rosbag
import glob, os
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np

class BagParser():
    def __init__(self, bagfile_path):
        self.bag_files = self._search_for_bags(bagfile_path)
        self.fig = plt.figure(figsize=(8,8))
        self.get_data()
        
    def _search_for_bags(self, bagfile_path):
        os.chdir(bagfile_path)
        bag_files = []
        for bag in glob.glob("*.bag"):
            bag_files.append(bag)
        return bag_files

    def _read_bag(self, bagfile):
        bag = rosbag.Bag(bagfile)
        self.rp = []
        self.re = []
        for topic, msg, t in bag.read_messages(topics=['/interception/r_p']):
                self.rp.append([msg.pose.position.x, msg.pose.position.y, msg.pose.position.z])
        for topic, msg, t in bag.read_messages(topics=['/interception/r_e']):
                self.re.append([msg.pose.position.x, msg.pose.position.y, msg.pose.position.z])
        bag.close()
    
    def _create_data(self):
        rp = {}
        re = {}
        axes = ['x', 'y', 'z']
        for i, axis in enumerate(axes):
            rp[axis] = [seq[i] for seq in self.rp]
            re[axis] = [seq[i] for seq in self.re]
        return rp, re

    def _calc_miss_distance(self):
        r = np.array([[re[0] - rp[0], re[1] - rp[1], re[2] - rp[2]] for re,rp in zip(self.re, self.rp)])
        _range = [np.linalg.norm(relative_position) for relative_position in r]
        miss_distance = np.min(_range)
        idx = np.argmin(_range)
        return miss_distance, idx

    def _plot_trajectory(self, rp, re, miss_distance, idx, runs):
        ax1 = self.fig.add_subplot(311)
        ax2 = self.fig.add_subplot(312)
        ax3 = self.fig.add_subplot(313, projection = '3d')

        ax1.scatter(rp['x'][0:idx], rp['z'][0:idx], s=0.25)
        ax1.scatter(re['x'][0:idx], re['z'][0:idx], s=0.25, c='red')
        ax1.set_title("X vs Z")

        ax2.scatter(rp['y'][0:idx], rp['z'][0:idx], s=0.25)
        ax2.scatter(re['y'][0:idx], re['z'][0:idx], s=0.25, c='red')
        ax2.set_title("Y vs Z")

        ax3.scatter(rp['x'][0:idx], rp['y'][0:idx], rp['z'][0:idx], s=0.25)
        ax3.scatter(re['x'][0:idx], re['y'][0:idx], re['z'][0:idx], s=0.25, c='red')
        ax3.set_title("Trajectories")
    
    def get_data(self):
        miss_distance = []
        runs = 0
        for bag in self.bag_files:
            runs += 1
            self._read_bag(bag)
            rp, re = self._create_data()
            md, idx = self._calc_miss_distance()
            miss_distance.append(md)
            mean_miss_distance = np.mean(miss_distance)
            self._plot_trajectory(rp, re, mean_miss_distance, idx, runs)
        plt.suptitle(f"Number of runs = {runs}\nMean Miss Distance = {mean_miss_distance:.3} [m]")
        plt.show()

def main():
    bagfile_path = "/home/iftach/bagfiles/"
    bag_parser = BagParser(bagfile_path)

if __name__ == "__main__":
    main()
