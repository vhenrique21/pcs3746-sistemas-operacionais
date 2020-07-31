#!/bin/bash

# make clean
# make clean ../initramfs_base/Makefile

docker run -ti --rm --name pcs3746-container \
    -v "$PWD/../linux":/home/student/src/linux \
    -v "$PWD":/home/student/src/initramfs \
    -v "$PWD/../initramfs_base":/home/student/src/initramfs_base \
    -v "$PWD/docker_cmd.sh":/default_cmd.sh \
    vhenrique21/pcs3746
