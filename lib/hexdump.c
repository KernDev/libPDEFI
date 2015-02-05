#include <string.h>
#include <stdint.h>
#include <output.h>
#include <mm.h>


void hexdump(void *data, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		char16_t *str = ulltowcs(((uint8_t*) data)[i], 0x10);
		puts(str);
		free(str);

		puts(L" ");
	}
}
