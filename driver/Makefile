obj-m := linux_sentinel_driver.o

KERNEL_SOURCE := $(HOME)/WSL2-Linux-Kernel

all:
	$(MAKE) -C $(KERNEL_SOURCE) M=$(CURDIR) modules

clean:
	$(MAKE) -C $(KERNEL_SOURCE) M=$(CURDIR) clean
