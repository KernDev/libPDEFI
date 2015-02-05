#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_


#include <stdint.h>


enum {
	EXCEPTION_VIDEO_UNSUPPORTED,
	EXCEPTION_VIDEO_ERROR,
	EXCEPTION_VIDEO_INVALID_MODE,
	EXCEPTION_VIDEO_BAD_CHR,
	EXCEPTION_KBD_ERROR,
	EXCEPTION_NO_GRAPHICS_PROTO
};


void throw_exc(uint32_t code);


#endif
