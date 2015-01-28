#include <stdint.h>


void *memset(void *ptr, int val, size_t size)
{
	for (size_t i = 0; i < size; i++)
		((unsigned char*) ptr)[i] = (unsigned char) val;

	return ptr;
}
