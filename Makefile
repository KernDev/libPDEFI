ARCH = x86_64

CROSS_PREFIX = x86_64-w64-mingw32-

STDC_VERSION = gnu11

CC = $(CROSS_PREFIX)gcc
CFLAGS = -ffreestanding -c -nostdinc -Iinclude -Iinclude/arch/$(ARCH) -masm=intel -std=$(STDC_VERSION)

YASM = yasm
YASMFLAGS = -f win64

#LD = $(CROSS_PREFIX)-ld
LDFLAGS = -nostdlib -Wl,-dll -shared -Wl,--subsystem,10 -e efi_main

OBJS_NOARCH = $(patsubst %.c,%.o,$(shell find lib -path lib/arch/ -prune -o -type f -name '*.c'))
OBJS_ARCH = $(patsubst %.c,%.o,$(shell find lib/arch/$(ARCH) -type f -name '*.c'))
AOBJS = $(patsubst %.S,%.obj,$(shell find lib/arch/$(ARCH) -type f -name '*.S'))


all: build


build: BOOTX64.EFI


BOOTX64.EFI: bootx64.o $(OBJS_NOARCH) $(OBJS_ARCH) $(AOBJS) include/*
	$(CC) $(LDFLAGS) bootx64.o $(OBJS_NOARCH) $(OBJS_ARCH) $(AOBJS) -o BOOTX64.EFI

%.obj: %.S
	$(YASM) $(YASMFLAGS) $(patsubst %.obj,%.S,$@) -o $@


test: updatefat run

run:
	qemu-system-x86_64 -cpu Haswell -m 512 -monitor stdio -L OVMF -bios OVMF.fd -usbdevice disk::fat.img

updatefat: fat.img BOOTX64.EFI
	mcopy -i fat.img BOOTX64.EFI ::/EFI/BOOT

fat.img:
	dd if=/dev/zero of=fat.img bs=1k count=1440
	mformat -i fat.img -f 1440 ::
	mmd -i fat.img ::/EFI
	mmd -i fat.img ::/EFI/BOOT
