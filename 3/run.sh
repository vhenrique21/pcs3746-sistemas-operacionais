#!/bin/bash
docker kill pcs3746-container || true &&
docker run -ti --rm --name pcs3746-container -v "$PWD/../linux":/home/student/src/linux -v "$PWD/initramfs":/home/student/src/initramfs vhenrique21/pcs3746

