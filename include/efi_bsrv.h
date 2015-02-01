#ifndef _EFI_BSRV_H_
#define _EFI_BSRV_H_


#include <stdint.h>
#include <efi_mem.h>


#define TPL_APPLICATION	4
#define TPL_CALLBACK	8
#define TPL_NOTIFY	16
#define TPL_HIGH_LEVEL	31


typedef native_int_t efi_tpl_t;


typedef enum {
	ALLOC_ANY_PAGES,
	ALLOC_MAX_ADDR,
	ALLOC_ADDR,
	MAX_ALLOC_TYPE
} efi_alloc_type_t;


typedef struct {
	efi_tab_hdr_t hdr;

	efi_tpl_t (*raise_tpl)(efi_tpl_t);
	void (*rstor_tpl)(efi_tpl_t);

	efi_status_t (*alloc_pages)(efi_alloc_type_t, efi_memory_type_t, native_int_t pages, native_int_t *memory);
	efi_status_t (*free_pages)(native_int_t, native_int_t);

	efi_status_t (*get_mmap)(native_int_t*, efi_mem_t*, native_int_t*, native_int_t*, uint32_t*);

	efi_status_t (*alloc_pool)(efi_memory_type_t, native_int_t, void**);
	efi_status_t (*free_pool)(void*);
} efi_bsrv_t;


#endif
