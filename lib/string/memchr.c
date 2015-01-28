#include <string.h>

const void *memchr(const void *ptr, int value, size_t num) {
    int i;
    for (i = 0; i < num; i++) if (ptr[i] == value) break;
    return (const void*)(ptr + i);
}

void *memchr(void *ptr, int value, size_t num) {
    int i;
    for (i = 0; i < num; i++) if (ptr[i] == value) break;
    return (void*)(ptr + i);
}