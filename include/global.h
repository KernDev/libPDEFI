#ifndef _GLOBAL_H_
#define _GLOBAL_H_


#include <efi_systab.h>


void pde_init(void *nhandle, efi_systab_t *nsystab, tmode_n_t tmode);


extern void		*efi_img_handle;
extern efi_systab_t	*efi_systab;


#endif
