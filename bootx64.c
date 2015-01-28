#include <arch.h>
#include <version.h>
#include <stdint.h>
#include <stdbool.h>
#include <global.h>
#include <output.h>
#include <panic.h>
#include <cpu.h>
#include <efi.h>

#ifdef ARCH_X86_64
#include <port.h>
#endif


void welcome()
{
	puts(L"TestBoot.\n\r");
	puts(L"Built with " PDE_NAME_STRING ".\n\r");
	puts(L"Released as public domain.\n\r");
}

efi_status_t efi_main(void *handle, efi_systab_t *systab)
{
	PDE_INIT_GLOBAL(handle, systab);
	efi_status_t status;


	reset_con(true);
	clear_con();

	welcome();


	UNFINISHED();


	return 0;
}
