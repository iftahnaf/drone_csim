import rosbag
import glob, os
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np

class BagParser():
    def __init__(self, bagfile_path):

        self.bag_files = self._search_for_bags(bagfile_path)

        self.fig = plt.figure()

        self.read_bag(self.bag_files[0])
        self.plot_trajectory()


    def _search_for_bags(self, bagfile_path):
        os.chdir(bagfile_path)
        bag_files = []
        for bag in glob.glob("*.bag"):
            bag_files.append(bag)
        return bag_files

    def read_bag(self, bagfile):
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
        r = []
        axes = ['x', 'y', 'z']
        for i, axis in enumerate(axes):
            rp[axis] = [seq[i] for seq in self.rp]
            re[axis] = [seq[i] for seq in self.re]
        return rp, re, 

    def plot_trajectory(self):
        rp, re = self._create_data()

        ax1 = self.fig.add_subplot(311)
        ax2 = self.fig.add_subplot(312)
        ax3 = self.fig.add_subplot(313, projection = '3d')

        ax1.scatter(rp['x'], rp['z'], s=0.25)
        ax2.scatter(rp['y'], rp['z'], s=0.25)
        ax3.scatter(rp['x'], rp['y'], rp['z'], s=0.25)

        plt.show()


def main():
    bagfile_path = "/home/iftach/bagfiles/"
    bag_parser = BagParser(bagfile_path)

if __name__ == "__main__":
    try:
        main()
    except Exception as e:
        print(e)