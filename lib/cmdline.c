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
				cmd_status_t cmd_status = cmds[i].cb();
				switch (cmd_status)
				{
					case CMD_SUCCESS:
						break;
					case CMD_FAILURE:
						puts(L"Error: the command executed unsuccessfully.\n\r");
						break;
					case CMD_EXIT:
						puts(L"Bye!\n\r");
						return;
					default:
						puts(L"Warning: the command returned an undefined status code.\n\r");
				}

				break;
			}
		}

		if (i == cmdc)
			puts(L"Error: unknown command.\n\r");
	}
}
