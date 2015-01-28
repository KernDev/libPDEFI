#ifndef _EFI_SYSTAB_H_
#define _EFI_SYSTAB_H_


#include <stdint.h>
#include <efi_txt_input.h>
#include <efi_txt_output.h>


#define EFI_SYSTAB_SIGNATURE 0x5453595320494249


#define EFI_2_20_SYSTAB_REV ((2<<16) | (20))
#define EFI_2_10_SYSTAB_REV ((2<<16) | (10))
#define EFI_2_00_SYSTAB_REV ((2<<16) | (00))
#define EFI_1_10_SYSTAB_REV ((1<<16) | (10))
#define EFI_1_02_SYSTAB_REV ((1<<16) | (02))

#define EFI_SYSTAB_REV EFI_2_20_SYSTAB_REV


typedef struct {
	uint64_t signature;
	uint32_t revision;
	uint32_t hdr_size;
	uint32_t crc32;
	uint32_t reserved;
} efi_systab_hdr_t;


typedef struct {
	efi_systab_hdr_t header;
	char16_t *vendor;
	uint32_t revision;

	void *con_in_handle;
	efi_txt_input_proto_t *con_in;

	void *con_out_handle;
	efi_txt_output_proto_t *con_out;
} efi_systab_t;


#endif
