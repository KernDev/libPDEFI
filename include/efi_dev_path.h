#ifndef _EFI_DEV_PATH_H_
#define _EFI_DEV_PATH_H_


#include <stdint.h>


#define EFI_DEV_PATH_PROTO_GUID {0x09576e91, 0x6d3f, 0x11d2, 0x8e, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b}
#define EFI_DEV_PATH_UTILITIES_PROTO_GUID {0x379be4e, 0xd706, 0x437d, 0xb0, 0x37, 0xed, 0xb8, 0x2f, 0xb7, 0x72, 0xa4}


#define HARDWARE_DEVICE_PATH	0x01 
#define ACPI_DEVICE_PATH	0x02 
#define MESSAGING_DEVICE_PATH	0x03
#define MEDIA_DEVICE_PATH	0x04
#define BBS_DEVICE_PATH		0x05
#define END_DEVICE_PATH_TYPE	0x7F

#define HW_PCI_DP		0x01
#define HW_PCCARD_DP		0x02
#define HW_MEMMAP_DP		0x03
#define HW_VENDOR_DP		0x04
#define HW_CONTROLLER_DP	0x05

#define ACPI_DP			0x01 
#define ACPI_EXTENDED_DP	0x02
#define ACPI_ADR_DP		0x03

#define MSG_ATAPI_DP		0x01
#define MSG_SCSI_DP		0x02
#define MSG_FIBRECHANNEL_DP	0x03
#define MSG_1394_DP		0x04
#define MSG_USB_DP		0x05
#define MSG_I2O_DP		0x06
#define MSG_INFINIBAND_DP	0x09
#define MSG_VENDOR_DP		0x0A
#define MSG_MAC_ADDR_DP		0x0B
#define MSG_IPV4_DP		0x0C
#define MSG_IPV6_DP		0x0D
#define MSG_UART_DP		0x0E
#define MSG_USB_CLASS_DP	0x0F
#define MSG_USB_WWID_DP		0x10
#define MSG_DEV_LOGICAL_UNIT_DP	0x11
#define MSG_SATA_DP		0x12
#define MSG_ISCSI_DP		0x13

#define MEDIA_HARDDRIVE_DP	0x01
#define MEDIA_CDROM_DP		0x02
#define MEDIA_VENDOR_DP		0x03
#define MEDIA_FILEPATH_DP	0x04
#define MEDIA_PROTOCOL_DP	0x05

#define BBS_BBS_DP		0x01

#define END_ENTIRE_DEVICE_PATH_SUBTYPE		0xFF
#define END_INSTANCE_DEVICE_PATH_SUBTYPE	0x01


typedef struct {
	uint8_t type;
	uint8_t subtype;
	uint16_t length;
} efi_dev_path_proto_t;


typedef struct {
	native_int_t (*get_dev_path_size)(const efi_dev_path_proto_t*);
	efi_dev_path_proto_t *(*dup_dev_path)(const efi_dev_path_proto_t*);
	efi_dev_path_proto_t *(*append_dev_path)(const efi_dev_path_proto_t*, const efi_dev_path_proto_t*);
	efi_dev_path_proto_t *(*append_dev_node)(const efi_dev_path_proto_t*, const efi_dev_path_proto_t*);
	efi_dev_path_proto_t *(*append_dev_path_inst)(const efi_dev_path_proto_t*, const efi_dev_path_proto_t*);
	efi_dev_path_proto_t *(*get_next_dev_path_inst)(efi_dev_path_proto_t**, native_int_t*);
	bool *(*is_dev_path_multi_inst)(const efi_dev_path_proto_t*);
	efi_dev_path_proto_t *(*create_dev_node)(uint8_t, uint8_t, uint16_t);
} efi_dev_path_utils_proto_t;


#endif
