#include <global.h>
#include <efi_systab.h>


void __attribute__((noreturn)) reset(efi_reset_type_t type, efi_status_t status)
{
	efi_systab->rtsrv->reset_sys(type, status, 0, 0);
}
