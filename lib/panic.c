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
			puts(L"a fatal hardware error occured.");
			break;
		case PANIC_UNFINISHED:
			puts(L"reached unfinished area.");
			break;
		case PANIC_BAD_EFI_REV:
			puts(L"booted by an unsupported version of EFI.");
			break;
		case PANIC_BAD_EFI_SIG:
			puts(L"invalid signature.");
			break;
		case PANIC_ALLOC_FAILED:
			puts(L"memory allocation failed.");
			break;
		case PANIC_FREE_FAILED:
			puts(L"object free'd wasn't allocated, possible memory corruption.");
			break;
		case PANIC_NO_MMAP:
			puts(L"no memory map.");
			break;
		case PANIC_NO_FILESYSTEM:
			puts(L"no filesystem access.");
			break;
		default:
			puts(L"undefined error.");
	}

	puts(L"\n\rCPU halted.");
	halt();
}
