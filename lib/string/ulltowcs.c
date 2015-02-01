#include <stdint.h>
#include <wchar.h>
#include <mm.h>


char16_t *ulltowcs(uint64_t val, uint8_t base)
{
	size_t len;
	uint64_t val1 = val;
	if (val1 > 0)
		for (len = 1; val1 /= base; len++);
	else
		len = 1;

	char16_t *str = malloc((len + 1) * sizeof(char16_t));
	str[len] = 0;
	while (len)
	{
		uint8_t rem = val % base;
		if (rem < 10)
			str[len-- - 1] = 0x30 + rem;
		else
			str[len-- - 1] = 0x37 + rem;

		val /= base;
	}

	return str;
}
