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
#include <cmdline.h>
#include <mm.h>
#include <timer.h>
#include <hexdump.h>
#include <graphics.h>

#ifdef ARCH_X86_64
#include <port.h>
#endif


void welcome()
{
	puts(L"TestBoot.\n\r");
	puts(L"Built with " PDE_NAME_STRING ".\n\r");
	puts(L"Released as public domain.\n\n\r");
}

efi_status_t efi_main(void *img_handle, efi_systab_t *systab)
{
	pde_init(img_handle, systab, systab->con_out->mode->max_mode);
	efi_status_t status;

	welcome();

	// Insert your test code here.

	halt();

	return EFI_SUCCESS;
}
