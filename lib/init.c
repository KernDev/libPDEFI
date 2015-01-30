#include <global.h>
#include <output.h>
#include <panic.h>


void pde_init(void *nhandle, efi_systab_t *nsystab, tmode_n_t tmode)
{
	// Init global variables.
	efi_img_handle = nhandle;
	efi_systab = nsystab;

	// Check the system table.
	if (efi_systab->header.signature != EFI_SYSTAB_SIGNATURE)
		panic(PANIC_BAD_EFI_SIG);

	if (efi_systab->rtsrv->header.signature != EFI_RTSRV_SIGNATURE)
		panic(PANIC_BAD_EFI_SIG);

	// Initialize the console.
	set_tmode(tmode);
	reset_con(true);
	set_ch_attr(CH_ATTR(CH_ATTR_LGRAY, BG_ATTR_BLACK));
	clear_con();

	// Initialize the input device.
	efi_systab->con_in->reset(efi_systab->con_in, true);
}
