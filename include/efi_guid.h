#ifndef _EFI_GUID_H_
#define _EFI_GUID_H_


#include <stdint.h>


typedef struct {
	uint32_t data1;
	uint16_t data2;
	uint16_t data3;
	uint8_t data4[8];
} efi_guid_t;


#endif
