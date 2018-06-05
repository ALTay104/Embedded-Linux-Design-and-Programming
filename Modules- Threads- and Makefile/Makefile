KVERSION:=linux-4.9.41
#KVERSION:=CHIP-linux
KDIR	:= ${PRJROOT}/KERNEL/${KVERSION}
#obj-m	:= modA.o modA.o
OBJ	:= modA modB
obj-m	:= $(OBJ:=.o)

default:
	make ARCH=arm CROSS_COMPILE=${TARGET}- -C ${KDIR} M=$(PWD) modules
	-file $(OBJ:=.ko)

clean:
	make -C $(KDIR) M=$(PWD) clean
