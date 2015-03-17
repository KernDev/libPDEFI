#ifndef _ELF_H_
#define _ELF_H_


#include <stdint.h>


#define ELF_MAGIC {0x7F, 'E', 'L', 'F'}

#define ELF_BITS_32 1
#define ELF_BITS_64 2

#define ELF_LITTLE_ENDIAN 1
#define ELF_BIG_ENDIAN 2

#define ELF_VERSION 1

#define ELF_ABI_SYSV	0x00
#define ELF_ABI_HPUX	0x01
#define ELF_ABI_NETBSD	0x02
#define ELF_ABI_LINUX	0x03
#define ELF_ABI_SOLARIS	0x06
#define ELF_ABI_AIX	0x07
#define ELF_ABI_IRIX	0x08
#define ELF_ABI_FREEBSD	0x09
#define ELF_ABI_OPENBSD	0x0C

#define ELF_TYPE_RELOCATABLE	1
#define ELF_TYPE_EXECUTABLE	2
#define ELF_TYPE_SHARED		3
#define ELF_TYPE_CORE		4

#define ELF_MACHINE_SPARC	0x02
#define ELF_MACHINE_X86		0x03
#define ELF_MACHINE_MIPS	0x08
#define ELF_MACHINE_PPC		0x14
#define ELF_MACHINE_ARM		0x28
#define ELF_MACHINE_SUPERH	0x2A
#define ELF_MACHINE_IA64	0x32
#define ELF_MACHINE_X86_64	0x3E
#define ELF_MACHINE_AARCH64	0xB7


typedef struct {
	uint8_t magic[4];
	uint8_t bits;
	uint8_t endianness;
	uint8_t version1;
	uint8_t abi;
	uint8_t abi_ver;
	uint8_t pad1[7];
	uint16_t type;
	uint16_t machine;
	uint32_t version2;
} __attribute__((__packed__)) elf_hdr1_t;


typedef struct {
	uint32_t flags;
	uint16_t size;
	uint16_t phdr_ent_sz;
	uint16_t phdr_ent_n;
	uint16_t shdr_ent_sz;
	uint16_t shdr_ent_n;
	uint16_t shdr_sn_index;
} __attribute__((__packed__)) elf_hdr3_t;


typedef struct {
	elf_hdr1_t indep1;
	uint64_t entry;
	uint64_t phdr_offset;
	uint64_t shdr_offset;
	elf_hdr3_t indep2;
} __attribute__((__packed__)) elf_hdr64_t;


#endif
