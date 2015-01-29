#ifndef _EFI_RTSRV_H_
#define _EFI_RTSRV_H_


#include <efi_status.h>
#include <efi_tab_hdr.h>


typedef struct {
	efi_tab_hdr_t header;

	efi_status_t (*get_time)(efi_time_t*, efi_time_capab_t*);
} efi_rtsrv_t;


#endif
