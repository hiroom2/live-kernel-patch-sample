# live-kernel-patch-sample

$ KERNEL_DIR=/path/to/kernel make
$ sudo insmod patched/patched.ko 
$ sudo insmod patch/patch.ko 
$ cat /proc/patched 
Not patched yet.
$ sudo su -
# echo 1 > /sys/kernel/livepatch/patch/enabled 
# cat /proc/patched 
Patched.
