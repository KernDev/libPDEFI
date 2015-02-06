#ifndef _ATA_PIO_H_
#define _ATA_PIO_H_


#include <stdint.h>
#include <stdbool.h>


// Ports.

#define ATA_DEVICE_CONTROL_PORT 0x3F6

#define ATA_PRIMARY_BUS_PORT_BASE 0x1F0
#define ATA_SECONDARY_BUS_PORT_BASE 0x170

enum {
	ATA_DATA,
	ATA_FTR_ERR,
	ATA_SECTOR_CNT,
	ATA_LBA_LOW,
	ATA_LBA_MID,
	ATA_LBA_HIGH,
	ATA_DRIVE,
	ATA_COMMAND_STATUS,
};


// ATA commands.

#define ATA_READ 0x24
#define ATA_WRITE 0x34


// Master / slave.

#define ATA_DRIVE_MASTER 0xE0
#define ATA_DRIVE_SLAVE 0xF0


// Status byte bits.

#define ATA_SB_ERR 1
#define ATA_SB_DRQ (1 << 3)
#define ATA_SB_SRV (1 << 4)
#define ATA_SB_DF  (1 << 5)
#define ATA_SB_RDY (1 << 6)
#define ATA_SB_BSY (1 << 7)


// Device control / alternate status bits.

#define ATA_DCR_NO_INT 2
#define ATA_DCR_SW_RESET (1 << 2)
#define ATA_DCR_HOB (1 << 7)


void ata_sw_reset();
void *ata_pio_read(uint64_t lba, uint16_t sect_cnt, bool primary, bool master);


#endif
