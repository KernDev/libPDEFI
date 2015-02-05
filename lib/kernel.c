#include <stdint.h>
#include <global.h>
#include <kernel.h>


void kernel_jump(native_int_t entry, native_int_t mmap_key)
{
	if (efi_systab->bsrv->exit_bsrv(efi_img_handle, mmap_key) != EFI_SUCCESS)
		return;

	void __attribute__((noreturn)) (*jump)() = (void*) entry;
	jump();

	halt();
}


void kernel_enter(native_int_t entry, native_int_t mmap_key, kernel_data_t *kdata)
{
	if (efi_systab->bsrv->exit_bsrv(efi_img_handle, mmap_key) != EFI_SUCCESS)
		return;

	void __attribute__((noreturn)) (*enter)(kernel_data_t*) = (void*) entry;
	enter(kdata);

	halt();
}
