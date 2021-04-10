FROM dorowu/ubuntu-desktop-lxde-vnc:bionic

RUN apt update -q && \
    apt upgrade -yq && \
    apt install -yq wget curl git build-essential vim emacs sudo lsb-release locales bash-completion tzdata gosu && \
    rm -rf /var/lib/apt/lists/*
RUN useradd --create-home --home-dir /home/ubuntu --shell /bin/bash --user-group --groups adm,sudo ubuntu && \
    echo ubuntu:ubuntu | chpasswd && \
    echo "ubuntu ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers
COPY ./ros2-setup.sh /ros2-setup.sh
RUN mkdir -p /tmp/ros_setup_scripts_ubuntu && mv /ros2-setup.sh /tmp/ros_setup_scripts_ubuntu/ && \
    gosu ubuntu /tmp/ros_setup_scripts_ubuntu/ros2-setup.sh && \
    rm -rf /var/lib/apt/lists/*
ENV USER ubuntu