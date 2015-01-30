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


cmd_status_t cmd_reset()
{
	reset(EFI_RESET_WARM, EFI_SUCCESS);

	return CMD_FAILURE;
}

cmd_status_t cmd_shutdown()
{
	reset(EFI_RESET_SHUTDOWN, EFI_SUCCESS);

	return CMD_FAILURE;
}

cmd_status_t cmd_halt()
{
	puts(L"CPU halted.\n\r");
	halt();

	return CMD_FAILURE;
}

cmd_status_t cmd_exit()
{
	return CMD_EXIT;
}

cmd_status_t cmd_help()
{
	puts(L"reset/reboot   reset the system.\n\r");
	puts(L"shutdown       shutdown the system.\n\r");
	puts(L"halt           halt the CPU.\n\r");
	puts(L"exit/menu      exit to the boot menu.\n\r");
	puts(L"help           print this help text.\n\r");

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
	pde_init(handle, systab, systab->con_out->mode->max_mode);
	set_tmode(0);
	efi_status_t status;


	welcome();

	cmd_t cmds[7];

	cmds[0].name = L"reset";
	cmds[0].cb = cmd_reset;

	cmds[1].name = L"reboot";
	cmds[1].cb = cmd_reset;

	cmds[2].name = L"shutdown";
	cmds[2].cb = cmd_shutdown;

	cmds[3].name = L"halt";
	cmds[3].cb = cmd_halt;

	cmds[4].name = L"exit";
	cmds[4].cb = cmd_exit;

	cmds[5].name = L"menu";
	cmds[5].cb = cmd_exit;

	cmds[6].name = L"help";
	cmds[6].cb = cmd_help;

	start_cmdline(L"boot: ", 7, cmds);


	return EFI_SUCCESS;
}
