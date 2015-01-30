#include <arch.h>
#include <version.h>
#include <exception.h>
#include <stdint.h>
#include <stdbool.h>
#include <global.h>
#include <string.h>
#include <output.h>
#include <panic.h>
#include <cpu.h>
#include <efi.h>
#include <reset.h>
#include <input.h>

#ifdef ARCH_X86_64
#include <port.h>
#endif


void welcome()
{
	puts(L"TestBoot.\n\r");
	puts(L"Built with " PDE_NAME_STRING ".\n\r");
	puts(L"Released as public domain.\n\n\r");
}

efi_status_t efi_main(void *handle, efi_systab_t *systab)
{
	PDE_INIT_GLOBAL(handle, systab);
	efi_status_t status;


	set_tmode(systab->con_out->mode->max_mode);
	reset_con(true);
	clear_con();

	welcome();

	puts(L"Press R to reboot, S to shutdown, M to go to boot menu or H to halt.\n\r");
	while (true)
	{
		char16_t ch = getch();
		switch (ch)
		{
			case L'R':
			case L'r':
				reset(EFI_RESET_WARM, EFI_SUCCESS);
			case L'S':
			case L's':
				reset(EFI_RESET_SHUTDOWN, EFI_SUCCESS);
			case L'M':
			case L'm':
				return EFI_SUCCESS;
			case L'H':
			case L'h':
				puts(L"CPU halted.");
				halt();
		}
	}


	//return EFI_SUCCESS;
}
