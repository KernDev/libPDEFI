#include <stdint.h>


int memcmp(void *a, void *b, size_t size)
{
	for (size_t i = 0; i < size; i++)
		if (((unsigned char*) a)[i] < ((unsigned char*) b)[i])
			return -1;
		else if (((unsigned char*) b)[i] < ((unsigned char*) a)[i])
			return 1;

	return 0;
}
