#include <stdint.h>
#include <wchar.h>


size_t wcslen(const char16_t* wcs)
{
	size_t i;
	while (wcs[i])
		i++;

	return i;
}
