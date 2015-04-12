#include <stdint.h>
#include <global.h>
#include <timer.h>


static timer_t *set_timer_interval(uint64_t ns100, void (*cb)(void*, void*), void *ctx, uint64_t type)
{
	void *event;
	efi_status_t status = efi_systab->bsrv->create_evt(EFI_EVT_TIMER | EFI_EVT_NOTIFY_SIGNAL, TPL_CALLBACK, cb, ctx, &event);
	if (status != EFI_SUCCESS)
		return 0;

	status = efi_systab->bsrv->set_timer(event, type, ns100);
	if (status != EFI_SUCCESS)
	{
		efi_systab->bsrv->close_evt(event);
		return 0;
	}

	return event;
}

timer_t *set_timeout(uint64_t ns100, void (*cb)(void*, void*), void *ctx)
{
	return set_timer_interval(ns100, cb, ctx, TIMER_RELATIVE);
}

timer_t *set_interval(uint64_t ns100, void (*cb)(void*, void*), void *ctx)
{
	return set_timer_interval(ns100, cb, ctx, TIMER_PERIODIC);
}


void clear_timer(timer_t *timer)
{
	efi_systab->bsrv->set_timer(*timer, TIMER_CANCEL, 0);
	efi_systab->bsrv->close_evt(timer);
}


void sleep(native_int_t ms)
{
	efi_systab->bsrv->stall(ms);
}
