#ifndef _PANIC_H_
#define _PANIC_H_


#include <stdint.h>


enum {
	PANIC_HW_FATAL,
	PANIC_UNFINISHED,
	PANIC_BAD_EFI_REV,
	PANIC_BAD_EFI_SIG
};


#define UNFINISHED() panic(PANIC_UNFINISHED)


void __attribute__((noreturn)) panic(uint16_t code);


#endif
