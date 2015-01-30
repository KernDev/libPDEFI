#include <stdint.h>
#include <string.h>


char *strcat(char *dst, const char *src)
{
	size_t len = strlen(dst);
	strcpy(dst + len, src);

	return dst;
}
