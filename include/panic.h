#ifndef _PANIC_H_
#define _PANIC_H_


#include <stdint.h>


#define PANIC_UNFINISHED 1


#define UNFINISHED() panic(PANIC_UNFINISHED)


void __attribute__((noreturn)) panic(uint16_t code);


#endif
