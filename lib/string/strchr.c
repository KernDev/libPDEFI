#include <stdint.h>


char *strchr(const char *str, int chr)
{
	for (size_t i = 0; str[i] != 0; i++)
		if (str[i] == (char) chr)
			return (char*) str + i;

	return 0;
}
