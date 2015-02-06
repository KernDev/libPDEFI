#ifndef _GPT_H_
#define _GPT_H_


#include <stdint.h>


#define GPT_SIGNATURE 0x5452415020494645
#define GPT_REV 0x10000


#define GPT_ATTR_SYS		1
#define GPT_ATTR_EFI_IGNORE	2
#define GPT_ATTR_LEGACY_BOOT	4


typedef struct {
	uint64_t signature;
	uint32_t rev;
	uint32_t hdr_size;
	uint32_t hdr_crc32;
	uint32_t reserved;
	uint64_t hdr_lba;
	uint64_t hdr_copy_lba;
	uint64_t part_st_lba;
	uint64_t part_end_lba;
	uint8_t disk_guid[16];
	uint64_t pt_lba;
	uint32_t pt_ent_n;
	uint32_t pt_ent_sz;
	uint32_t pt_crc32;
} __attribute__((__packed__)) gpt_header_t;


typedef struct {
	uint8_t type[16];
	uint8_t guid[16];
	uint64_t st_lba;
	uint64_t end_lba;
	uint64_t flags;
	char16_t name[];
} __attribute__((__packed__)) gpt_ent_t;


#endif
