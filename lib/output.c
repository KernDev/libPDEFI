#include <stdbool.h>
#include <output.h>
#include <global.h>
#include <efi_systab.h>
#include <cpu.h>


void reset_con(bool ext_verif)
{
	efi_systab->con_out->reset(efi_systab->con_out, ext_verif);
}

void clear_con()
{
	efi_systab->con_out->clear(efi_systab->con_out);
}


void set_ch_attr(ch_attr_t attr)
{
	efi_systab->con_out->set_attr(efi_systab->con_out, attr);
}

ch_attr_t get_ch_attr()
{
	return (ch_attr_t) (efi_systab->con_out->mode->attr);
}


void puts(char16_t *str)
{
	efi_systab->con_out->puts(efi_systab->con_out, str);
}

void aputs(char16_t *str, ch_attr_t attr)
{
	ch_attr_t old_attr = get_ch_attr();

	set_ch_attr(attr);
	puts(str);

	set_ch_attr(old_attr);
}
