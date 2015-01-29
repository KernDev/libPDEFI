#include <stdint.h>


char *strncpy(char *dst, char *src, size_t len)
{
	for (size_t i = 0; (dst[i] = src[i]) && i < len; i++);

	return dst;
}
