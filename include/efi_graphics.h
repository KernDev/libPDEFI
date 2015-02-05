#ifndef _EFI_GRAPHICS_H_
#define _EFI_GRAPHICS_H_


#include <stdint.h>
#include <efi_status.h>
#include <efi_guid.h>


#define EFI_GRAPHICS_PROTO_GUID {0x9042a9de, 0x23dc, 0x4a38, 0x96, 0xfb, 0x7a, 0xde, 0xd0, 0x80, 0x51, 0x6a}


typedef enum {
	PIXEL_RGB_RESERVED_8BIT,
	PIXEL_BGR_RESERVED_8BIT,
	PIXEL_BITMASK,
	PIXEL_BLT_ONLY,
	PIXEL_FMT_MAX
} efi_graphics_pixel_format_t;


typedef struct {
	uint32_t red;
	uint32_t green;
	uint32_t blue;
	uint32_t reserved;
} efi_pixel_bitmask_t;

typedef struct {
	uint8_t blue;
	uint8_t green;
	uint8_t red;
	uint8_t reserved;
} efi_pixel_blt_t;


typedef enum {
	EFI_BLT_VIDEO_FILL,
	EFI_BLT_VIDEO_TO_BLT_BUFFER,
	EFI_BLT_BUFFER_TO_VIDEO,
	EFI_BLT_VIDEO_TO_VIDEO,
	EFI_BLT_OP_MAX
} efi_graphics_blt_op_t;


typedef struct {
	uint32_t ver;
	uint32_t res_horizontal;
	uint32_t res_vertical;
	efi_graphics_pixel_format_t pix_fmt;
	efi_pixel_bitmask_t pix_info;
	uint32_t pix_per_scan_line;
} efi_graphics_info_t;


typedef struct {
	uint32_t max_mode;
	uint32_t mode;
	efi_graphics_info_t *info;
	native_int_t info_sz;
	void *fb_base;
	native_int_t fb_sz;
} efi_graphics_mode_t;


typedef struct {
	efi_status_t (*query_mode)(void*, uint32_t, native_int_t*, efi_graphics_info_t**);
	efi_status_t (*set_mode)(void*, uint32_t);
	efi_status_t (*blt)(void*, efi_pixel_blt_t*, efi_graphics_blt_op_t, native_int_t, native_int_t, native_int_t, native_int_t, native_int_t, native_int_t, native_int_t);
	efi_graphics_mode_t *mode;
} efi_graphics_proto_t;


#endif
