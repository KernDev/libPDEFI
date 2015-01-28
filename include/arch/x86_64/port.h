#ifndef _PORT_H_
#define _PORT_H_


#include <stdint.h>


typedef uint16_t x86_port_t;


uint8_t inb(x86_port_t port);
void outb(x86_port_t port, uint8_t val);


#endif
