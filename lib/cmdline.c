#include <string.h>
#include <cmdline.h>
#include <input.h>
#include <output.h>
#include <global.h>


void start_cmdline(char16_t *prompt, uint32_t cmdc, cmd_t *cmds)
{
	col_n_t cols;
	row_n_t rows;
	efi_status_t status = query_tmode(efi_systab->con_out->mode->mode, &cols, &rows);
	if (status != EFI_SUCCESS)
		return;

	char16_t input[50];

	while (1)
	{
		puts(prompt);

		getsn(input, 49);

		uint32_t i;
		for (i = 0; i < cmdc; i++)
		{
			if (!wcscmp(input, cmds[i].name))
			{
				if (cmds[i].cb() != CMD_SUCCESS)
					puts(L"Error: unsuccessful command.\n\r");
				break;
			}
		}

		if (i == cmdc)
			puts(L"Error: unknown command.\n\r");
	}
}
