#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_


#include <stdint.h>


#define EXCEPTION_VIDEO_UNSUPPORTED	1
#define EXCEPTION_VIDEO_ERROR		2
#define EXCEPTION_VIDEO_INVALID_MODE	3
#define EXCEPTION_VIDEO_BAD_CHR		4


void throw_exc(uint32_t code);


#endif
