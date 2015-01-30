#ifndef _STRING_H_
#define _STRING_H_


#include <stdint.h>


#define STRING_HELPER(val) #val
#define STRING(val) STRING_HELPER(val)


void *memset(void *ptr, int value, size_t size);
void *memcpy(void *dst, void *src, size_t size);
void *memchr(void *ptr, int value, size_t num);
void* memmove(void *dst, void *src, size_t size);
int memcmp(void *a, void *b, size_t size);

char *strcat(char *dst, char *src);
int strcmp(char *str1, char *str2);
char *strncat(char *dst, char *src, size_t num);
char *strchr(char *str, int chr);
char *strcpy(char *dst, char *src);
char *strncpy(char *dst, char *src, size_t len);
size_t strlen(char *str);
size_t strcspn(char *str1, char *str2);


#endif
