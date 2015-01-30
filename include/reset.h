#ifndef _RESET_H_
#define _RESET_H_


void __attribute__((noreturn)) reset(efi_reset_type_t type, efi_status_t status);


#endif
