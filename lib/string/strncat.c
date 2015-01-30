#include <string.h>


char *strncat(char *dst, const char *src, size_t len)
{
	size_t dst_len = strlen(dst);
	strncpy(dst + dst_len, src, len);

	return dst;
}
