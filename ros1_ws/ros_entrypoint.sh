#!/bin/bash
set -e

source /opt/ros/noetic/setup.bash
source /workspace/devel/setup.bash
sleep 10

roslaunch interception_utils simulation.launch
