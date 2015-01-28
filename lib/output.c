#include <stdbool.h>
#include <output.h>
#include <global.h>
#include <efi_systab.h>


void reset_con(bool ext_verif)
{
	efi_systab->con_out->reset(efi_systab->con_out, ext_verif);
}

void clear_con()
{
	efi_systab->con_out->clear(efi_systab->con_out);
}


void puts(char16_t *str)
{
	efi_systab->con_out->puts(efi_systab->con_out, str);
}
