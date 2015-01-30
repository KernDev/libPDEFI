#include <wchar.h>
#include <global.h>
#include <exception.h>


efi_key_t getk()
{
	efi_key_t key;
	efi_status_t status;
	while ((status = efi_systab->con_in->getkey(efi_systab->con_in, &key)) != EFI_SUCCESS)
		if (status == EFI_DEVICE_ERROR)
			throw_exc(EXCEPTION_KBD_ERROR);

	return key;
}

char16_t getch()
{
	efi_key_t key = getk();
	/*efi_status_t status;
	while ((status = efi_systab->con_in->getkey(efi_systab->con_in, &key)) != EFI_SUCCESS)
		if (status == EFI_DEVICE_ERROR)
			throw_exc(EXCEPTION_KBD_ERROR);*/

	return key.uchar;
}
