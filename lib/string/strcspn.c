#include <string.h>

size_t strcspn ( const char * str1, const char * str2 ) {
    size_t span;
    size_t len = strlen(str2);
    for (int i = 0; i < len; i++) {
        span = strchr(str1, str2[i]);
    }
    return span;
}