#ifndef _EFI_BSRV_H_
#define _EFI_BSRV_H_


#include <stdint.h>
#include <stdbool.h>
#include <wchar.h>
#include <efi_mem.h>
#include <efi_event.h>
#include <efi_dev_path.h>


#define EFI_OPEN_PROTOCOL_BY_HANDLE_PROTOCOL	0x00000001
#define EFI_OPEN_PROTOCOL_GET_PROTOCOL		0x00000002
#define EFI_OPEN_PROTOCOL_TEST_PROTOCOL		0x00000004
#define EFI_OPEN_PROTOCOL_BY_CHILD_CONTROLLER	0x00000008
#define EFI_OPEN_PROTOCOL_BY_DRIVER		0x00000010
#define EFI_OPEN_PROTOCOL_EXCLUSIVE		0x00000020


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


typedef enum {
	TIMER_CANCEL,
	TIMER_PERIODIC,
	TIMER_RELATIVE
} efi_timer_delay_t;


typedef enum {
	EFI_NATIVE_INTERFACE
} efi_interface_t;


typedef enum {
  ALL_HANDLES,
  BY_REGISTER_NOTIFY,
  BY_PROTOCOL
} efi_locate_search_t;


typedef void (*efi_evt_notify_t)(void*, void*);


typedef struct {
	void *agent_handle;
	void *controller_handle;
	uint32_t attr;
	uint32_t cnt;
} efi_proto_info_ent_t;


typedef struct {
	efi_tab_hdr_t hdr;

	efi_tpl_t (*raise_tpl)(efi_tpl_t);
	void (*rstor_tpl)(efi_tpl_t);

	efi_status_t (*alloc_pages)(efi_alloc_type_t, efi_memory_type_t, native_int_t pages, native_int_t *memory);
	efi_status_t (*free_pages)(native_int_t, native_int_t);

	efi_status_t (*get_mmap)(native_int_t*, efi_mem_t*, native_int_t*, native_int_t*, uint32_t*);

	efi_status_t (*alloc_pool)(efi_memory_type_t, native_int_t, void**);
	efi_status_t (*free_pool)(void*);

	efi_status_t (*create_evt)(uint32_t, efi_tpl_t, efi_evt_notify_t, void*, void**);
	efi_status_t (*set_timer)(void*, efi_timer_delay_t, uint64_t);
	efi_status_t (*wait_evt)(native_int_t, void**, native_int_t*);
	efi_status_t (*sig_evt)(void*);
	efi_status_t (*close_evt)(void*);
	efi_status_t (*check_evt)(void*);

	efi_status_t (*install_proto)(void**, efi_guid_t*, efi_interface_t, void*);
	efi_status_t (*reinstall_proto)(void*, efi_guid_t*, void*, void*);
	efi_status_t (*uninstall_proto)(void*, efi_guid_t*, void*);
	efi_status_t (*handle_proto)(void*, efi_guid_t*, void**);

	void *reserved;

	efi_status_t (*reg_proto_notify)(efi_guid_t*, void*, void**);

	efi_status_t (*locate_handle)(efi_locate_search_t, efi_guid_t*, void*, native_int_t*, void**);
	efi_status_t (*locate_dev_path)(efi_guid_t*, efi_dev_path_proto_t**, void**);
	efi_status_t (*install_cfg_tab)(efi_guid_t*, void*);

	efi_status_t (*load_img)(bool, void*, efi_dev_path_proto_t*, void*, native_int_t, void**);
	efi_status_t (*start_img)(void*, native_int_t*, char16_t**);

	efi_status_t (*exit)(void*, efi_status_t, native_int_t, char16_t*);

	efi_status_t (*unload_img)(void*);

	efi_status_t (*exit_bsrv)(void*, native_int_t);

	efi_status_t (*get_next_monotonic_cnt)(uint64_t*);

	efi_status_t (*stall)(native_int_t);

	efi_status_t (*set_watchdog_timer)(native_int_t, uint64_t, native_int_t, char16_t*);

	efi_status_t (*connect_controller)(void*, void**, efi_dev_path_proto_t*, bool);
	efi_status_t (*disconnect_controller)(void*, void*, void*);

	efi_status_t (*open_proto)(void*, efi_guid_t*, void**, void*, void*, uint32_t);
	efi_status_t (*close_proto)(void*, efi_guid_t*, void*, void*);
	efi_status_t (*open_proto_info)(void*, efi_guid_t*, efi_proto_info_ent_t**, native_int_t*);
	efi_status_t (*proto_per_handle)(void*, efi_guid_t***, native_int_t*);

    efi_status_t (*locate_handle_buffer)(native_int_t, efi_guid_t*, void*, native_int_t*, void***);
	efi_status_t (*locate_proto)(efi_guid_t*, void*, void**);

	efi_status_t (*install_multiple_proto_interfaces)(void**, ...);
	efi_status_t (*uninstall_multiple_proto_interfaces)(void*, ...);
    
    efi_status_t (*calc_crc32)(void*, native_int_t, uint32_t*);
    
    void (*copy_mem)(void*, void*, native_int_t);
    void (*set_mem)(void*, native_int_t, uint8_t);
    
    efi_status_t (*create_evt_ex)(uint32_t, efi_tpl_t, efi_evt_notify_t, void*, const efi_guid_t*, void**);
} efi_bsrv_t;


#endif
