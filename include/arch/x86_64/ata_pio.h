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

enum {
	ATA_SB_ERR,
	ATA_SB_DRQ = 3,
	ATA_SB_SRV,
	ATA_SB_DF,
	ATA_SB_RDY,
	ATA_SB_BSY
};


// Device control / alternate status bits.

enum {
	ATA_DCR_NO_INT = 1,
	ATA_DCR_SW_RESET = 2,
	ATA_DCR_HOB = 7
};

#define ATA_DCR_SW_RESET_BYTE (1 << ATA_DCR_SW_RESET)


void ata_sw_reset();
void *ata_pio_read(uint64_t lba, uint16_t sect_cnt, bool primary, bool master);


#endif
