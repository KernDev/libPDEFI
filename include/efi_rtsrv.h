#ifndef _EFI_RTSRV_H_
#define _EFI_RTSRV_H_


#include <stdint.h>
#include <stdbool.h>
#include <wchar.h>
#include <efi_status.h>
#include <efi_tab_hdr.h>
#include <efi_mem.h>
#include <efi_guid.h>
#include <efi_time.h>


#define EFI_RTSRV_SIGNATURE 0x56524553544e5552


#define EFI_OPTIONAL_PTR 0x00000001


#define CAPSULE_FLAGS_PERSIST_ACROSS_RESET	0x00010000
#define CAPSULE_FLAGS_POPULATE_SYSTEM_TABLE	0x00020000
#define CAPSULE_FLAGS_INITIATE_RESET		0x00040000


typedef enum {
	EFI_RESET_COLD,
	EFI_RESET_WARM,
	EFI_RESET_SHUTDOWN
} efi_reset_type_t;


typedef struct {
	efi_guid_t guid;
	uint32_t hdr_sz;
	uint32_t flags;
	uint32_t caps_sz;
} efi_caps_hdr_t;


typedef struct {
	native_int_t addr;
	uint32_t len;
	uint32_t *reserved;
} scatter_gather_elem_t;

typedef struct {
	uint32_t elem_n;
	uint32_t *reserved;
	scatter_gather_elem_t elems[];
} scatter_gather_list_t;


typedef struct {
	efi_tab_hdr_t header;

	efi_status_t (*get_time)(efi_time_t*, efi_time_capab_t*);
	efi_status_t (*set_time)(efi_time_t*);

	efi_status_t (*get_wakeup_time)(bool*, bool*, efi_time_t*);
	efi_status_t (*set_wakeup_time)(bool, efi_time_t*);

	efi_status_t (*set_vaddr_map)(native_int_t, native_int_t, uint32_t, efi_mem_t*);
	efi_status_t (*conv_ptr)(native_int_t, void**);

	efi_status_t (*get_var)(char16_t*, efi_guid_t*, uint32_t*, native_int_t*, void*);
	efi_status_t (*get_next_var_name)(native_int_t*, char16_t*, efi_guid_t*);
	efi_status_t (*set_var)(char16_t*, efi_guid_t*, uint32_t, native_int_t, void *data);

	efi_status_t (*get_next_high_monotonic_cnt)(uint32_t *cnt);

	void __attribute__((noreturn)) (*reset_sys)(efi_reset_type_t, efi_status_t, native_int_t, void*);

	efi_status_t (*update_caps)(efi_caps_hdr_t**, native_int_t, native_int_t, scatter_gather_list_t*);
	efi_status_t (*query_caps)(efi_caps_hdr_t**, native_int_t, uint64_t*, efi_reset_type_t*);
	efi_status_t (*query_var_info)(uint32_t attr, uint64_t*, uint64_t*, uint64_t*);
} efi_rtsrv_t;


#endif
