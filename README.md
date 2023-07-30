# Linux_kernel_development
Linux_kernel_development

*************************cross tool-chain installation and settings for linux host******************

STEP 1 : Download arm cross toolchain for your Host machine

STEP 2 :  export  path of the cross compilation toolchain. 

export PATH=$PATH:/home/kiran/BBB_Workspace/Downloads/gcc-linaro-6.3.1-2017.02-x86_64_arm-linux-gnueabihf/bin


*************************U-boot Compilation ***************************************************


STEP 1: distclean : deletes all the previously compiled/generated object files. 

make CROSS_COMPILE=arm-linux-gnueabihf- distclean

STEP 2 : apply board default configuration for uboot

make CROSS_COMPILE=arm-linux-gnueabihf- am335x_boneblack_defconfig


STEP 3 : run menuconfig, if you want to do any settings other than default configuration . 

make CROSS_COMPILE=arm-linux-gnueabihf-  menuconfig


STEP 4 : compile 

make CROSS_COMPILE=arm-linux-gnueabihf- -j4  // -j4(4 core machine) will instructs the make tool to spawn 4 threads
make CROSS_COMPILE=arm-linux-gnueabihf- -j8  // -j8(8 core machine) will instructs the make tool to spawn 8 threads


************************* linux compilation ***************************************************
STEP 1:
 make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- distclean

STEP 2:
 make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- bb.org_defconfig (4.4)
for 4.11 use omap2plus_defconfig

STEP 3:
 make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- menuconfig

STEP 4:
 make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- uImage dtbs LOADADDR=0x80008000 -j4

STEP 5:
 make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -j4 modules

STEP 6:
 make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- INSTALL_MOD_PATH=<path of the RFS> modules_install


************************* Busy box compilation ***************************************************

STEP 1: download busybox 

STEP 2 : Apply default configuration
make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- defconfig

STEP 3 : change default settings if you want 
make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- menuconfig

STEP 4 : generate the busy box binary and minimal file system 
make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- CONFIG_PREFIX=<install_path> install



*********************************build-root compilation ***********************************
1) download the build root package from 

https://buildroot.org/

2) configure the build root 


*******************************Dropbear compilation*************************************

1) Download Dropbear 

2) Configure Dropbear

./configure --host=arm-linux-gnueabihf --disable-zlib --prefix=/home/kiran/BBB_Workspace/dropbear CC=arm-linux-gnueabihf-gcc

3) compile the Dropbear as static 

make PROGRAMS="dropbear dropbearkey dbclient scp" STATIC=1

4) install dropbear generated binaries 
make PROGRAMS="dropbear dropbearkey dbclient scp" install


5) generate RSA and DSS keys 
dropbearkey -t dss -f dropbear_dss_host_key
dropbearkey -t rsa -f dropbear_rsa_host_key

6) run the dropbear 
# dropbear

7) make a SSh connection from pc 
ssh -l root 192.168.7.2





# use this command to install a openssh server on your ubuntu host 
sudo apt-get install openssh-server
