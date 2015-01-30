#ifndef _EFI_TIME_H_
#define _EFI_TIME_H_


typedef struct {
	uint16_t Year;       // 1998_t – 20XX
	uint8_t  Month;      // 1 – 12
	uint8_t  Day;        // 1 – 31
	uint8_t  Hour;       // 0 – 23
	uint8_t  Minute;     // 0 – 59
	uint8_t  Second;     // 0 – 59
	uint8_t  Pad1;
	uint32_t Nanosecond; // 0 – 999,999,999
	int16_t  TimeZone;   // -1440 to 1440 or 2047
	uint8_t  Daylight;
	uint8_t  Pad2;
} efi_time_t;


typedef struct {
	uint32_t resolution;
	uint32_t accuracy;
	bool     sets_zero;
} __attribute__((aligned(4))) efi_time_capab_t;


#endif
