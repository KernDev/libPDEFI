#ifndef _STRING_H_
#define _STRING_H_


#include <stdint.h>


#define STRING_HELPER(val) #val
#define STRING(val) STRING_HELPER(val)


void *memset(void *ptr, int value, size_t size);


#endif
