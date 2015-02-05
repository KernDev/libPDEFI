#ifndef _KERNEL_H_
#define _KERNEL_H_


#include <stdint.h>
#include <efi_mem.h>


#define KERNEL_DATA_REV 1


enum {
	PIXEL_RED,
	PIXEL_GREEN,
	PIXEL_BLUE,
	PIXEL_RESERVED
};


typedef struct {
	uint8_t pix1;
	uint8_t pix2;
	uint8_t pix3;
	uint8_t pix4;
} __attribute__((packed)) pix_order_t;


typedef struct {
	uint8_t rev;

	efi_mem_t *mmap;
	native_int_t mmap_sz;
	native_int_t mmap_ent_sz;

	uint32_t video_mode;
	uint32_t res_horitzontal;
	uint32_t res_vertical;
	pix_order_t pix_order;

	char16_t *cmdline;
} __attribute__((packed)) kernel_data_t;


void kernel_jump(native_int_t entry, native_int_t mmap_key);
void kernel_enter(native_int_t entry, native_int_t mmap_key, kernel_data_t *kdata);


#endif
