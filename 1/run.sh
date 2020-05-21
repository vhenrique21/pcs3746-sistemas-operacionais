#!/bin/bash
docker run -ti --rm --name linux_00 -v "$PWD/linux":/home/student/src/linux -v "$PWD/initramfs":/home/student/src/initramfs tiagoshibata/pcs3746
