#ifndef _STRING_H_
#define _STRING_H_


#include <stdint.h>
#include <wchar.h>


#define STRING_HELPER(val) #val
#define STRING(val) STRING_HELPER(val)


void *memset(void *ptr, int value, size_t size);
void *memcpy(void *dst, void *src, size_t size);
void *memchr(void *ptr, int value, size_t num);
void* memmove(void *dst, void *src, size_t size);
int memcmp(void *a, void *b, size_t size);

char *strcat(char *dst, const char *src);
int strcmp(const char *str1, const char *str2);
char *strncat(char *dst, const char *src, size_t num);
char *strchr(const char *str, int chr);
char *strcpy(char *dst, const char *src);
char *strncpy(char *dst, const char *src, size_t len);
size_t strlen(char *str);
size_t strcspn(const char *str1, const char *str2);

int wcscmp(const char16_t *str1, const char16_t *str2);
size_t wcslen(const char16_t *wcs);

char16_t *ulltowcs(uint64_t val, uint8_t base);


#endif
