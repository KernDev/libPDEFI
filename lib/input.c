#include <wchar.h>
#include <global.h>
#include <exception.h>
#include <efi_status.h>
#include <output.h>


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

void getsn(char16_t *str, size_t len)
{
	set_cur(true);

	int32_t s_col = efi_systab->con_out->mode->cur_col;
	int32_t s_row = efi_systab->con_out->mode->cur_row;

	char16_t ch;
	size_t i = 0;
	while ((ch = getch()) != 0x0D)
	{
		if (ch == 0x08)
		{
			if (i > 0)
			{
				str[i] = 0x08;
				str[i + 1] = 0;
				i--;
				str[i] = ' ';
			}
		}
		else
		{
			str[i] = ch;
			if (i < len)
				i++;
			str[i] = 0;
		}

		set_cur_pos(s_col, s_row);
		puts(str);
	}

	puts(L"\n\r");

	set_cur(false);
}
