#include <stdint.h>


int strcmp(const char *str1, const char *str2)
{
	for (size_t i = 0; str1[i] && str2[i]; i++)
	{
		if (str1[i] < str2[i])
			return -1;
		else if (str1[i] > str2[i])
			return 1;
	}

	return 0;
}
