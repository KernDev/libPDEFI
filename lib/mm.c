#include <stdint.h>
#include <global.h>
#include <panic.h>
#include <exception.h>
#include <string.h>


void *malloc(size_t size)
{
	void *buffer;
	efi_status_t status = efi_systab->bsrv->alloc_pool(EFI_OSLDR_MEM(EFI_CONVENTIONAL_MEM), size, &buffer);
	if (status != EFI_SUCCESS)
		panic(PANIC_ALLOC_FAILED);

	return buffer;
}


void free(void *blk)
{
	if (efi_systab->bsrv->free_pool(blk) != EFI_SUCCESS)
		panic(PANIC_FREE_FAILED);
}


void *realloc(void *blk, size_t size)
{
	void *nblk = malloc(size);
	memcpy(nblk, blk, size);
	free(blk);

	return nblk;
}


efi_mem_t *get_mmap(native_int_t *mmap_key, native_int_t *mmap_ent_n, native_int_t *mmap_ent_sz)
{
	*mmap_ent_n = 16;
	native_int_t mmap_sz = 16 * sizeof(efi_mem_t);
	efi_mem_t *mmap = malloc(mmap_sz);
	uint32_t mmap_ver;

	efi_status_t status;
	while (efi_systab->bsrv->get_mmap(&mmap_sz, mmap, mmap_key, mmap_ent_sz, &mmap_ver) != EFI_SUCCESS)
	{
		mmap_sz = (*mmap_ent_n *= 2) * sizeof(efi_mem_t);
		mmap = realloc(mmap, mmap_sz);
	}

	if (mmap_ver != EFI_MEM_DESC_VER)
		panic(PANIC_NO_MMAP);

	*mmap_ent_n = mmap_sz / *mmap_ent_sz;

	return mmap;
}
