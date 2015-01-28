#ifndef _GLOBAL_H_
#define _GLOBAL_H_


#include <efi_systab.h>


#define PDE_INIT_GLOBAL(nhandle, nsystab) (efi_img_handle = handle, efi_systab = nsystab)


extern void		*efi_img_handle;
extern efi_systab_t	*efi_systab;


#endif
