#########################################################################
# File Name: run_bochs.sh
# Author: 韩佩言
# mail: xiyouhanpeiyan@gmail.com
# Created Time: 2013年11月06日 星期三 18时34分48秒
# Class: 计科1107
#########################################################################
#!/bin/bash

sudo /sbin/losetp /dev/loop0 floppy.img
sudo bochs -f bochsrc.txt
sudo /sbin/losetup -d /dev/loop0
