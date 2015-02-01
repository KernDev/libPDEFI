#include <wchar.h>
#include <global.h>
#include <exception.h>
#include <efi_status.h>
#include <output.h>
#include <mm.h>


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

char16_t *dgets()
{
	set_cur(true);

	char16_t *str = malloc(1);
	char16_t ch;
	size_t i = 0;
	while ((ch = getch()) != 0x0D)
	{
		if (ch == 0x08)
		{
			if (i > 0)
			{
				puts(L"\b \b");
			}
		}
		else
		{
			putc(ch);
			str[i] = ch;
			i++;

			str = realloc(str, (i + 2) * sizeof(char16_t));
		}
	}

	str[i] = 0;
	puts(L"\n\r");

	set_cur(false);

	return str;
}
