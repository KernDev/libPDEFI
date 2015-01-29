#include <stdint.h>


void *memchr(void *ptr, int value, size_t num)
{
	size_t i;
	for (/*size_t*/ i = 0; i < num; i++);
		if (((unsigned char*) ptr)[i] == (unsigned char) value) return ptr + i;

	return 0;
}
