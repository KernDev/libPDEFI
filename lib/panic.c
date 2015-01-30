#include <stdint.h>
#include <output.h>
#include <panic.h>
#include <cpu.h>


void panic(uint16_t code)
{
	puts(L"Bootloader panic: ");

	if (code == PANIC_UNFINISHED)
		puts(L"reached unfinished area.\n\r");
	else
		puts(L"undefined error.\n\r");

	puts(L"CPU halted.");
	halt();
}
