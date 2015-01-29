#include <stdint.h>


char *strchr(char *str, int chr)
{
	for (size_t i = 0; str[i] != 0; i++)
		if (str[i] == (char) chr) return str + i;

	return 0;
}
