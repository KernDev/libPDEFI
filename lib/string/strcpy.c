#include <string.h>

char *strcpy(char *dst, char *src) {
    size_t len = strlen(src);
    memcpy(dst, src, len);
    return dst;
}