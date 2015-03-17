#include <stdint.h>
#include <port.h>
#include <ata_pio.h>
#include <mm.h>


void ata_sw_reset()
{
	outb(ATA_DEVICE_CONTROL_PORT, ATA_DCR_SW_RESET);	// Reset.
	outb(ATA_DEVICE_CONTROL_PORT, 0);			// Reset back to the normal operation mode.

	// 400ns delay.
	inb(ATA_DEVICE_CONTROL_PORT);
	inb(ATA_DEVICE_CONTROL_PORT);
	inb(ATA_DEVICE_CONTROL_PORT);
	inb(ATA_DEVICE_CONTROL_PORT);

	while (!(inb(ATA_DEVICE_CONTROL_PORT) & ATA_SB_RDY)); // Wait for BSY and RDY.
}


void *ata_pio_read(uint64_t lba, uint16_t sect_cnt, bool primary, bool master)
{
	uint16_t port_base;
	if (primary)
		port_base = ATA_PRIMARY_BUS_PORT_BASE;
	else
		port_base = ATA_SECONDARY_BUS_PORT_BASE;

	outb(port_base + ATA_DRIVE, 0x40 | (!master << 4));	// Select a drive.
	outb(port_base + ATA_SECTOR_CNT, sect_cnt >> 8);	// Send the high sector count byte.
	outb(port_base + ATA_LBA_LOW, (lba >> 24) & 0xFF);	// LBA + 3.
	outb(port_base + ATA_LBA_MID, (lba >> 32) & 0xFF);	// LBA + 4.
	outb(port_base + ATA_LBA_HIGH, (lba >> 40) & 0xFF);	// LBA + 5.
	outb(port_base + ATA_SECTOR_CNT, sect_cnt & 0xFF);	// Low sector count byte.
	outb(port_base + ATA_LBA_LOW, lba & 0xFF);		// LBA + 0.
	outb(port_base + ATA_LBA_MID, (lba >> 8) & 0xFF);	// LBA + 1.
	outb(port_base + ATA_LBA_HIGH, (lba >> 16) & 0xFF);	// LBA + 2.
	outb(port_base + ATA_COMMAND_STATUS, 0x24);		// Send the read command.

	for (uint8_t i = 0; i < 4; i++)
	{
		uint8_t sb = inb(ATA_COMMAND_STATUS);
		if (sb & ATA_SB_BSY)
			i++;
		else if (sb & ATA_SB_DRQ)
			break;
	}

	// Read.
	char *buffer = malloc(sect_cnt * 512);
	char *buffer_p = buffer;

	while (sect_cnt--)
	{
		uint8_t byte;
		while (inb(port_base + ATA_COMMAND_STATUS) & ATA_SB_BSY);
		if (byte & (ATA_SB_ERR | ATA_SB_DF))
			return 0;

		register uint64_t rdi asm("rdi") = (uint64_t) buffer_p;
		register uint64_t rcx asm("rcx") = 256;
		register uint16_t rdx asm("rdx") = port_base + ATA_DATA;
		asm("rep insw");

		// 400ns delay.
		inb(port_base + ATA_COMMAND_STATUS);
		inb(port_base + ATA_COMMAND_STATUS);
		inb(port_base + ATA_COMMAND_STATUS);
		inb(port_base + ATA_COMMAND_STATUS);

		buffer_p += 512;
	}

	if (inb(ATA_COMMAND_STATUS) & (ATA_SB_ERR | ATA_SB_DF))
	{
		free(buffer);
		return 0;
	}

	return buffer;
}
