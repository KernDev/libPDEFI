#ifndef _EFI_TXT_OUTPUT_H_
#define _EFI_TXT_OUTPUT_H_


#include <stdint.h>
#include <stdbool.h>
#include <wchar.h>
#include <efi_status.h>


#define CH_ATTR_BLACK 0x00
#define CH_ATTR_BLUE 0x01
#define CH_ATTR_GREEN 0x02
#define CH_ATTR_CYAN 0x03
#define CH_ATTR_RED 0x04
#define CH_ATTR_MAGENTA 0x05
#define CH_ATTR_BROWN 0x06
#define CH_ATTR_LGRAY 0x07
#define CH_ATTR_BRIGHT 0x08
#define CH_ATTR_DGRAY 0x08
#define CH_ATTR_LBLUE 0x09
#define CH_ATTR_LGREEN 0x0A
#define CH_ATTR_LCYAN 0x0B
#define CH_ATTR_LRED 0x0C
#define CH_ATTR_LMAGENTA 0x0D
#define CH_ATTR_YELLOW 0x0E
#define CH_ATTR_WHITE 0x0F
#define BG_ATTR_BLACK 0x00
#define BG_ATTR_BLUE 0x10
#define BG_ATTR_GREEN 0x20
#define BG_ATTR_CYAN 0x30
#define BG_ATTR_RED 0x40
#define BG_ATTR_MAGENTA 0x50
#define BG_ATTR_BROWN 0x60
#define BG_ATTR_LGRAY 0x70
#define CH_ATTR(fg, bg) ((fg) | ((bg) << 4))


typedef native_int_t vmode_n_t;

typedef native_int_t col_n_t;
typedef native_int_t row_n_t;


typedef native_int_t ch_attr_t;


typedef struct {
	int32_t max_mode;
	int32_t mode;

	int32_t attr;

	int32_t cur_col;
	int32_t cur_row;
	bool cur_visible;
} efi_txt_output_mode_t;


typedef struct {
	efi_status_t (*reset)(void*, bool);

	efi_status_t (*puts)(void*, char16_t*);
	efi_status_t (*strcheck)(void*, char16_t*);

	efi_status_t (*query_mode)(void*, vmode_n_t, col_n_t*, row_n_t*);
	efi_status_t (*set_mode)(void*, vmode_n_t);

	efi_status_t (*set_attr)(void*, ch_attr_t);

	efi_status_t (*clear)(void*);

	efi_status_t (*set_cur_pos)(void*, col_n_t, row_n_t);
	efi_status_t (*set_cur)(void*, bool);

	efi_txt_output_mode_t *mode;
} efi_txt_output_proto_t;


#endif
