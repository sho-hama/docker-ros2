#!/usr/bin/env bash
set -eu

CHOOSE_ROS_DISTRO=dashing
INSTALL_PACKAGE=desktop

sudo apt-get update
sudo apt-get install -y curl gnupg2 lsb-release
curl -Ls https://raw.githubusercontent.com/ros/rosdistro/master/ros.key | sudo apt-key add -
sudo sh -c 'echo "deb http://packages.ros.org/ros2/ubuntu $(lsb_release -cs) main" > /etc/apt/sources.list.d/ros2-latest.list'
sudo apt-get update
sudo apt-get install -y ros-${CHOOSE_ROS_DISTRO}-${INSTALL_PACKAGE}
sudo apt-get install -y python3-argcomplete
sudo apt-get install -y python3-colcon-common-extensions
sudo apt-get install -y python-rosdep python3-vcstool 
sudo rosdep init
rosdep update
sudo apt-get install -y ros-${CHOOSE_ROS_DISTRO}-gazebo-ros-pkgs
grep -F "source /opt/ros/${CHOOSE_ROS_DISTRO}/setup.bash" ~/.bashrc ||
echo "source /opt/ros/${CHOOSE_ROS_DISTRO}/setup.bash" >> ~/.bashrc

set +u

source /opt/ros/${CHOOSE_ROS_DISTRO}/setup.bash
