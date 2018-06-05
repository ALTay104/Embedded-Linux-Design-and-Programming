# Download raspbian from the following site
# https://www.raspberrypi.org/downloads/raspbian/

# Burn raspbian OS to your SD card

# Add following file to your boot partition (FAT32) of your SD card
bcm2836-rpi-2-b.dtb
config.txt
initramfs-RPi.cpio.gz.uImage
u-boot-RPi3.bin
zImage

# Power up Raspberry Pi3 and you should be at uboot> prompt.

# Use following steps to transfer above images into RPi3 SDRAM

mmc dev 0

fatload mmc 0:1 ${kernel_addr_r} zImage

fatload mmc 0:1  ${fdt_addr_r} bcm2836-rpi-2-b.dtb

fatload mmc 0:1 ${ramdisk_addr_r} initramfs-5.cpio.gz.uImage 

setenv bootargs console=ttyAMA0,115200

bootz ${kernel_addr_r} ${ramdisk_addr_r} ${fdt_addr_r}

#echo ${fdt_addr_r} => to show which address that we are loading it
#ls mmc 0 => will show all the files in SD card


