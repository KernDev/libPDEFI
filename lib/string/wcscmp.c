#include <stdint.h>
#include <wchar.h>


int wcscmp(const char16_t *str1, const char16_t *str2)
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
