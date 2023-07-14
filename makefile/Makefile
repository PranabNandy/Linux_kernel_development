obj-m := hello.o
PWD=$(shell pwd)
KERNEL_SOURCE := /lib/modules/$(shell uname -r)/build
KERNEL_SOURCE2 := /usr/src/linux-headers-5.15.0-76-generic/
all:
	make -C $(KERNEL_SOURCE) M=$(PWD)
clean:
	make -C $(KERNEL_SOURCE2) M=$(PWD) clean
