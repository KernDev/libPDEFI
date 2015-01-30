#include <stdint.h>


char *strcpy(char *dst, const char *src)
{
	for (size_t i = 0; (dst[i] = src[i]); i++);

	return dst;
}
