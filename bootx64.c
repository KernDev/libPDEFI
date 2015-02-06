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
#include <gpt.h>

#ifdef ARCH_X86_64
#include <port.h>
#include <ata_pio.h>
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

	ata_sw_reset();

	gpt_header_t *gpt_hdr = ata_pio_read(1, 1, true, true);
	gpt_ent_t *pt = ata_pio_read(gpt_hdr->pt_lba, 1, true, true);
	puts(L"First partition offset: 0x");
	puts(ulltowcs(pt->st_lba, 0x10));
	puts(L"\n\r");

	puts(L"Finish.");

	halt();

	return EFI_SUCCESS;
}
