#ifndef _MM_H_
#define _MM_H_


#include <efi_mem.h>


void *malloc(size_t size);
void *realloc(void *blk, size_t size);
void free(void *blk);

efi_mem_t *get_mmap(native_int_t *mmap_key, native_int_t *mmap_ent_n, native_int_t *mmap_ent_sz);


#endif
