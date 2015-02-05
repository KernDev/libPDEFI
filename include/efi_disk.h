#ifndef _EFI_DISK_H_
#define _EFI_DISK_H_


#include <stdint.h>
#include <efi_status.h>
#include <efi_dev_path.h>


#define EFI_DISK_IO_PROTO_GUID {0xCE345171, 0xBA0B, 0x11d2, 0x8e, 0x4F, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b}
#define EFI_BLK_IO_PROTO_GUID {0x964e5b21, 0x6459, 0x11d2, 0x8e, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b}


#define EFI_DISK_IO_PROTO_REV 0x00010000
#define EFI_BLK_IO_PROTO_REV 0x00010000


enum {
	PT_TYPE_MBR = 1,
	PT_TYPE_GPT
};


enum {
	SIG_TYPE_NO,
	SIG_TYPE_MBR,
	SIG_TYPE_GPT
};


typedef struct {
	uint32_t part_n;
	uint64_t part_st;
	uint64_t part_sz;
	uint8_t sig[16];
	uint8_t pt_type;
	uint8_t sig_type;
} efi_harddrive_dev_path_t;


typedef struct {
	efi_dev_path_proto_t header;
	uint32_t media_id;
	bool rem_media;
	bool media_pres;
	bool logical_part;
	bool ro;
	bool write_caching;
	uint32_t blk_sz;
	uint32_t io_align;
	uint64_t last_blk;
} efi_blk_io_media_t;


typedef struct {
	uint64_t rev;
	efi_blk_io_media_t media;
	efi_status_t (*reset)(void*, bool);
	efi_status_t (*read_blk)(void*, uint32_t, uint64_t, native_int_t, void*);
	efi_status_t (*write_blk)(void*, uint32_t, uint64_t, native_int_t, void*);
	efi_status_t (*flush_blk)(void*);
} efi_blk_io_proto_t;


typedef struct {
	uint64_t rev;
	efi_status_t (*read_disk)(void*, uint32_t, uint64_t, native_int_t, void*);
	efi_status_t (*write_disk)(void*, uint32_t, uint64_t, native_int_t, void*);
} efi_disk_io_proto_t;


#endif
