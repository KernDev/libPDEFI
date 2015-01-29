#include <string.h>

char *strncat(char *dst, char *src, size_t num) {
	if (num > (strlen(src)+1)) return strcat(dst, src);

	size_t len = strlen(dst);
	for (size_t i = 0; i < num; i++) dst[len+i] = src[i];
	dst[len+num] = 0;
	return dst;
}
