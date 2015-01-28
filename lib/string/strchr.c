#include <string.h>

char *strchr(char *str, int chr) {
    size_t len = strlen(str);
    int i;
    for (i = 0; i < len; i++) if (str[i] == chr) break;
    return (char*)(str + i);
}

char *strchr(const char *str, int chr) {
    size_t len = strlen(str);
    int i;
    for (i = 0; i < len; i++) if (str[i] == chr) break;
    return (const char*)(str + i);
}