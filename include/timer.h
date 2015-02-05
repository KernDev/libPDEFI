#ifndef _TIMER_H_
#define _TIMER_H_


#include <stdint.h>


typedef void* timer_t;


timer_t *set_timeout(uint64_t ns100, void (*cb)(void*, void*), void *ctx);
timer_t *set_interval(uint64_t ns100, void (*cb)(void*, void*), void *ctx);
void clear_timer(timer_t *timer);
void sleep(native_int_t ms);


#endif
