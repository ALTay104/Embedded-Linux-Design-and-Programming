KVERSION:=linux-4.9.41
#KVERSION:=CHIP-linux
KDIR	:= ${PRJROOT}/KERNEL/${KVERSION}
obj-m	:= proc-version.o

default:
	make ARCH=arm CROSS_COMPILE=${TARGET}- -C ${KDIR} M=$(PWD) modules

clean:
	make -C $(KDIR) M=$(PWD) clean