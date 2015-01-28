#include <string.h>

char *strchr(char *str, int chr) {
    size_t len = strlen(str);
    return (char*)memchr(str, chr, len);
}

const char *strchr(const char *str, int chr) {
    size_t len = strlen(str);
    return (const char*)memchr(str, chr, len);
}