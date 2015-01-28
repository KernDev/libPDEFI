#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_


#include <stdint.h>


#define EXCEPTION_FEATURE_UNSUPPORTED		1
#define EXCEPTION_HARDWARE_ERROR		2
#define EXCEPTION_TYPE_OUT_OF_RESOURCES		4
#define EXCEPTION_WRONG_CALL			8


//void throw_exc(uint32_t exc_code, native_int_t spec);


#endif
