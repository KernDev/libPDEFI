#include <stdint.h>
#include <output.h>
#include <panic.h>
#include <cpu.h>


void panic(uint16_t code)
{
	puts(L"Bootloader panic: ");

	switch (code)
	{
		case PANIC_HW_FATAL:
			puts(L"a fatal hardware error occured.\n\r");
			break;
		case PANIC_UNFINISHED:
			puts(L"reached unfinished area.\n\r");
			break;
		case PANIC_BAD_EFI_REV:
			puts(L"booted by an unsupported version of EFI.\n\r");
			break;
		case PANIC_BAD_EFI_SIG:
			puts(L"invalid signature.\n\r");
			break;
		default:
			puts(L"undefined error.\n\r");
	}

	puts(L"CPU halted.");
	halt();
}
