#include <stdint.h>


int strcmp(char *str1, char *str2)
{
	for (size_t i = 0; str1[i] && str2[i]; i++)
	{
		if (str1[i] < str2[i])
			return -1;
		else if (str1[i] < str2[i])
			return 1;
	}

	return 0;
}
