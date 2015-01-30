#ifndef _MBR_H_
#define _MBR_H_


#include <stdint.h>


enum {
	MBR_EMPTY,		// Empty.
	MBR_FAT12,		// FAT12.
	MBR_XENIX_ROOT,		// XENIX /root.
	MBR_XENIX_USR,		// XENIX /usr.
	MBR_FAT16_MAX32,	// FAT16 (up to 32MB).
	MBR_DOS_EXT,		// DOS 3.3+ extended partition.
	MBR_FAT16_OVR32,	// FAT16 (over 32MB).
	MBR_IFS,		// IFS - installable filesystem.
	MBR_NTFS = 7,		// Microsoft NTFS.
	MBR_EXFAT = 7,		// ExFAT.
	MBR_AUNIX = 7,		// Advanced Unix.
	MBR_QNX2 = 7,		// QNX 2.x pre-1988.
	MBR_OS2_1,		// OS/2 1.0-1.3.
	MBR_AIX_BOOT = 8,	// AIX boot.
	MBR_SPDRIVE = 8,	// SplitDrive.
	MBR_COMMODORE_DOS = 8,	// Commodore DOS.
	MBR_DELL_SPNDRV = 8,	// DELL partition spanning multiple drives.
	MBR_QNX_QNY = 8,	// QNX 1.x and 2.x.
	MBR_AIX_DATA,		// AIX data.
	MBR_COHERENT = 9,	// Coherent Unix.
	MBR_QNX_QNZ = 9,	// QNX 1.x and 2.x.
	MBR_OS2_BOOTMGR,	// OS/2 boot manager.
	MBR_COHERENT_SWP = 0x0A,// Coherent swap.
	MBR_OPUS = 0x0A,	// Open Parallel Unisys Server.
	MBR_WIN95_OSR2_FAT32,	// Windows 95 (non-LBA).
	MBR_WIN95_OSR2_FAT32L,	// Windows 95 (LBA).
	MBR_SILICON_SAFE,	// Silicon safe.
	MBR_WIN95_FAT16,	// Windows 95 FAT16 (LBA).
	MBR_WIN95_EXT,		// Windows 95 extended partition.
	MBR_MAYBE_OPUS,		// Open Parallel Unisys Server (maybe).
	MBR_FAT12_HIDDEN,	// Hidden FAT12.
	// TODO: add these obsolete filesystems: http://www.win.tue.nl/~aeb/partitions/partition_types-1.html.
	MBR_MIROS = 0x27,	// MirOS, a BSD flavor.
	MBR_WIN_RE = 0x27,	// Windows RE hidden partition.
	MBR_PLAN9 = 0x39,	// Plan 9 (from Bell Labs).
	MBR_OBERON_AOS = 0x4C,	// Oberon Aos.
	MBR_QNX4,		// QNX 4.x.
	MBR_QNX4_2,
	MBR_QNX4_3,
	MBR_OBERON_NAT = 0x4F,	// Oberon Nat.
	MBR_OBERON_NATIVE,	// Native Oberon.
	MBR_SYSV = 0x63,	// Unix System V (SCO, ISC Unix, UnixWare...), Mach, GNU Hurd.
	MBR_LINUX_SWP = 0x82,	// Linux swap.
	MBR_LINUX,		// Linux native.
	MBR_LINUX_EXT = 0x85,
	MBR_NTFS_VOLSET = 0x87,	// Legacy Fault Tolerant NTFS volume. HPFS Fault-Tolerant mirrored partition.
	MBR_LINUX_LVM = 0x8E,	// Linux Logical Volume Manager partition.
	MBR_LINUX_HDN = 0x93,	// Linux hidden partition.
	MBR_BSD = 0xA5,		// BSD/386, 386BSD, NetBSD, FreeBSD.
	MBR_OPENBSD,		// OpenBSD.
	MBR_MACOSX = 0xA8,	// Apple MacOS X.
	MBR_NETBSD,		// NetBSD.
	MBR_MACOSX_BOOT = 0xAB,	// Apple MacOS X boot.
	MBR_RISCOS_ADFS = 0xAD, // RISC OS ADFS.
	MBR_MACOSX_HFS = 0xAF,	// Apple MacOS X HFS or HFS+.
	MBR_LUKS = 0xE8,	// LUKS (Linux Unified Key Setup) partition.
	MBR_BEOS_BFS = 0xEB,	// BeOS BFS.
	MBR_IND_EFI = 0xEE	// Indication that this legacy MBR is followed by an EFI header.
};


#define MBR_SIG0 0x55
#define MBR_SIG1 0xAA

#define CHECK_MBR_SIGNATURE(sig) (sig[0] == MBR_SIG0 && sig[1] == MBR_SIG1)


typedef struct {
	uint8_t boot_flag;

	uint8_t st_head;
	uint8_t st_sect; // Only 6 bits. Bits 6-7 - the upper bits of st_cyl.
	uint8_t st_cyl;

	uint8_t sysid;

	uint8_t end_head;
	uint8_t end_sect; // Same layout as st_sect and st_cyl.
	uint8_t end_cyl;

	uint32_t st_lba;

	uint32_t sect_cnt;
} mbr_pt_ent_t;


typedef struct {
	char boot[436];
	char id[10];
	mbr_pt_ent_t pt[4];
	char signature[2];
} mbr_t;


#endif
