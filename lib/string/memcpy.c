#include <stdint.h>


void *memcpy(void *dst, void *src, size_t size)
{
	for (size_t i = 0; i < size; i++)
		((unsigned char*) dst)[i] = ((unsigned char*) src)[i];

	return dst;
}
