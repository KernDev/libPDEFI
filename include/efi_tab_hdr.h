#ifndef _EFI_TAB_HDR_H_
#define _EFI_TAB_HDR_H_


typedef struct {
	uint64_t signature;
	uint32_t revision;
	uint32_t hdr_size;
	uint32_t crc32;
	uint32_t reserved;
} efi_tab_hdr_t;


#endif
