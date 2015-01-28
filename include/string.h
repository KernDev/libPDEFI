#ifndef _STRING_H_
#define _STRING_H_


#include <stdint.h>


#define STRING_HELPER(val) #val
#define STRING(val) STRING_HELPER(val)


void *memset(void *ptr, int value, size_t size);
void *memcpy(void *dst, void *src, size_t size);
void *memchr(void *ptr, int value, size_t num);
const void *memchr(const void *ptr, int value, size_t num);
void* memmove(void *dst, void *src, size_t size);
int memcmp(void *a, void *b, size_t size);

char *strcat(char *destination, char *source);
char *strchr(char *str, int chr);
const char *strchr(const char *str, int chr);
char *strcpy(char *dst, char *src);
size_t strlen(char *str);
size_t strcspn ( const char * str1, const char * str2 );


#endif
