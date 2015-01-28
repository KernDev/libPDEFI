#ifndef _EFI_TXT_INPUT_H_
#define _EFI_TXT_INPUT_H_


#include <stdbool.h>
#include <stdint.h>
#include <wchar.h>
#include <efi_status.h>
#include <efi_event.h>


typedef struct {
	uint16_t scan_code;
	char16_t uchar;
} efi_key_t;


typedef struct {
	efi_status_t (*reset)(void*, bool);
	efi_status_t (*getkey)(void*, efi_key_t*);
	void *waitkey;
} efi_txt_input_proto_t;


#endif
