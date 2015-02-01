#ifndef _EFI_MEM_H_
#define _EFI_MEM_H_


#define EFI_MEMORY_UC		0x0000000000000001
#define EFI_MEMORY_WC		0x0000000000000002
#define EFI_MEMORY_WT		0x0000000000000004
#define EFI_MEMORY_WB		0x0000000000000008
#define EFI_MEMORY_UCE		0x0000000000000010
#define EFI_MEMORY_WP		0x0000000000001000
#define EFI_MEMORY_RP		0x0000000000002000
#define EFI_MEMORY_XP		0x0000000000004000
#define EFI_MEMORY_RUNTIME	0x8000000000000000

#define EFI_MEM_DESC_VER 1

#define EFI_OSLDR_MEM(type) (0x80000000 | type)

typedef enum {
        EFI_RESERVED_MEM,
        EFI_LDR_CODE,
        EFI_LDR_DATA,
        EFI_BSRV_CODE,
        EFI_BSRV_DATA,
        EFI_RTSRV_CODE,
        EFI_RTSRV_DATA,
        EFI_CONVENTIONAL_MEM,
        EFI_UNUSABLE_MEM,
        EFI_ACPI_RECLAIM_MEM,
        EFI_ACPI_MEM_NVS,
        EFI_MMIO,
        EFI_MMIO_PORT_SPACE,
        EFI_PAL_CODE,
        EFI_MAX_MEM_TYPE
} efi_memory_type_t;


typedef struct {
	uint32_t type;
	native_int_t pstart;
	native_int_t vstart;
	uint64_t pnum;
	uint64_t attr;
} efi_mem_t;


#endif
