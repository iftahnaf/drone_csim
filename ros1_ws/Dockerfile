FROM ros:noetic

LABEL maintainer="iftahnaf@gmail.com"
LABEL version="1.0"
LABEL description="This is custom Docker Image for \
autonomous drone development."

ENV ROS_DISTRO noetic

RUN apt update && apt-get install -y python2 ros-noetic-mavros ros-noetic-mavros-extras
RUN wget https://raw.githubusercontent.com/mavlink/mavros/master/mavros/scripts/install_geographiclib_datasets.sh
RUN bash ./install_geographiclib_datasets.sh 
RUN rm install_geographiclib_datasets.sh 

WORKDIR /workspace

COPY src/interception_utils src/interception_utils
COPY src/interception_v15 src/interception_v15
RUN /bin/bash -c '. /opt/ros/noetic/setup.bash; catkin_make'

RUN mkdir -p /bags

COPY ros_entrypoint.sh .
ENTRYPOINT ["/workspace/ros_entrypoint.sh"]

CMD ["bash"]

