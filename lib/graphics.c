#include <stdint.h>
#include <efi_graphics.h>
#include <efi_status.h>


efi_graphics_proto_t *efi_graphics;


efi_status_t set_max_gmode()
{
	if (efi_graphics == 0)
		return EFI_UNSUPPORTED;

	efi_status_t status;

	efi_graphics_info_t *g_info;
	native_int_t g_info_sz;
	uint32_t mode_n;
	for (mode_n = (unsigned) -1; (status = efi_graphics->query_mode(efi_graphics, mode_n + 1, &g_info_sz, &g_info)) == EFI_SUCCESS; mode_n++);
	if (mode_n == (unsigned) -1)
		return status;

	status = efi_graphics->set_mode(efi_graphics, mode_n);
	if (status != EFI_SUCCESS)
		return status;

	return status;
}
