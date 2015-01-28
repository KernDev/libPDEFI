#include <stdint.h>


void* memmove(void *dst, void *src, size_t size)
{
	if (dst < src)
		for (size_t i = 0; i < size; i++)
			((unsigned char*) dst)[i] = ((unsigned char*) src)[i];
	else
		for (size_t i = size; i != 0; i--)
			((unsigned char*) dst)[i-1] = ((unsigned char*) src)[i-1];

	return dst;
}
