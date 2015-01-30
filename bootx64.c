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

#ifdef ARCH_X86_64
#include <port.h>
#endif


cmd_status_t cmdtest()
{
	puts(L"Hello, World!\n\r");

	return CMD_SUCCESS;
}


void welcome()
{
	puts(L"TestBoot.\n\r");
	puts(L"Built with " PDE_NAME_STRING ".\n\r");
	puts(L"Released as public domain.\n\n\r");
}

efi_status_t efi_main(void *handle, efi_systab_t *systab)
{
	pde_init(handle, systab);
	efi_status_t status;


	welcome();

	cmd_t cmds[1];
	cmds[0].name = L"test";
	cmds[0].cb = cmdtest;
	start_cmdline(L"boot: ", 1, cmds);

	UNFINISHED();


	//return EFI_SUCCESS;
}
