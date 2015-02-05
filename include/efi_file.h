#ifndef _EFI_FILE_H_
#define _EFI_FILE_H_


#include <stdint.h>
#include <wchar.h>
#include <efi_status.h>
#include <efi_time.h>
#include <efi_guid.h>


#define EFI_SIMPLE_FILE_SYSTEM_PROTO_GUID {0x0964e5b22, 0x6459, 0x11d2, 0x8e, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b}
#define EFI_LOAD_FILE_PROTO_GUID {0x56EC3091, 0x954C, 0x11d2, {0x8E, 0x3F, 0x00, 0xA0, 0xC9, 0x69, 0x72, 0x3B}


#define EFI_SIMPLE_FILE SYSTEM_PROTO_REV 0x00010000
#define EFI_FILE_PROTO_REV 0x00010000


#define EFI_FILE_MODE_READ 0x0000000000000001
#define EFI_FILE_MODE_WRITE 0x0000000000000002
#define EFI_FILE_MODE_CREATE 0x8000000000000000


#define EFI_FILE_READ_ONLY 0x0000000000000001
#define EFI_FILE_HIDDEN 0x0000000000000002
#define EFI_FILE_SYSTEM 0x0000000000000004
#define EFI_FILE_RESERVED 0x0000000000000008
#define EFI_FILE_DIRECTORY 0x0000000000000010
#define EFI_FILE_ARCHIVE 0x0000000000000020
#define EFI_FILE_VALID_ATTR 0x0000000000000037


#define EFI_FILE_INFO_ID {0x09576e92, 0x6d3f, 0x11d2, 0x8e39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b}
#define EFI_FILE_SYSTEM_INFO_ID {0x09576e93, 0x6d3f, 0x11d2, 0x8e39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b}


typedef struct {
	uint64_t sz;
	uint64_t file_sz;
	uint64_t phys_file_sz;
	efi_time_t create_time;
	efi_time_t last_access_time;
	efi_time_t mod_time;
	uint64_t attr;
} efi_file_info_t;


typedef struct {
	uint64_t size;
	bool ro;
	uint64_t vol_sz;
	uint64_t free_spc;
	uint32_t blk_sz;
} efi_fs_info_t;


typedef struct _efi_file_proto_t {
	uint64_t rev;

	efi_status_t (*open)(void*, struct _efi_file_proto_t**, char16_t*, uint64_t, uint64_t);
	efi_status_t (*close)(void*);

	efi_status_t (*del)(void*);

	efi_status_t (*read)(void*, native_int_t*, void*);
	efi_status_t (*write)(void*, native_int_t*, void*);

	efi_status_t (*get_pos)(void*, uint64_t*);
	efi_status_t (*set_pos)(void*, uint64_t);

	efi_status_t (*get_info)(void*, efi_guid_t*, native_int_t*, void*);
	efi_status_t (*set_info)(void*, efi_guid_t*, native_int_t, void*);

	efi_status_t (*flush)(void*);
} efi_file_proto_t;


typedef struct {
	uint64_t rev;
	efi_status_t (*open_vol)(void*, efi_file_proto_t**);
} efi_fs_proto_t;


#endif
