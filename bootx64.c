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

	puts(L"Press any key to shutdown.");
	getch();

	reset(EFI_RESET_SHUTDOWN, EFI_SUCCESS);


	return 0;
}
