#ifndef _EFI_TIME_H_
#define _EFI_TIME_H_


#include <stdint.h>
#include <stdbool.h>


typedef struct {
	uint16_t year;       // 1998_t – 20XX
	uint8_t  month;      // 1 – 12
	uint8_t  day;        // 1 – 31
	uint8_t  hour;       // 0 – 23
	uint8_t  minute;     // 0 – 59
	uint8_t  second;     // 0 – 59
	uint8_t  pad1;
	uint32_t nanosecond; // 0 – 999,999,999
	int16_t  timezone;   // -1440 to 1440 or 2047
	uint8_t  daylight;
	uint8_t  pad2;
} efi_time_t;


typedef struct {
	uint32_t resolution;
	uint32_t accuracy;
	bool     sets_zero;
} __attribute__((aligned(4))) efi_time_capab_t;


#endif
