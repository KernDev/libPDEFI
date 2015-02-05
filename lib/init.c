#include <global.h>
#include <output.h>
#include <panic.h>
#include <exception.h>


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

	// Set the watchdog timer.
	efi_systab->bsrv->set_watchdog_timer(180, 0x10000, sizeof(L"bootstrap timeout"), L"bootstrap timeout");

	// Initialize the console.
	set_tmode(tmode);
	reset_con(true);
	set_ch_attr(CH_ATTR(CH_ATTR_LGRAY, BG_ATTR_BLACK));
	clear_con();

	// Initialize the input device.
	efi_systab->con_in->reset(efi_systab->con_in, true);

	// Install graphics.
	efi_guid_t efi_graphics_proto_guid[] = EFI_GRAPHICS_PROTO_GUID;
	if (efi_systab->bsrv->locate_proto(efi_graphics_proto_guid, 0, (void**) &efi_graphics) != EFI_SUCCESS)
		throw_exc(EXCEPTION_NO_GRAPHICS_PROTO);
}
