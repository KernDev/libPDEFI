#include <string.h>


size_t strcspn(const char *str1, const char *str2)
{
	char *span = 0;
	for (size_t i = 0; str2[i] != 0; i++)
	{
		char *nspan = strchr(str1, str2[i]);
		if (nspan > span)
			span = nspan;
	}

	return (size_t) (span - str1);
}
