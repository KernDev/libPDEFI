#ifndef _OUTPUT_H_
#define _OUTPUT_H_


#include <stdbool.h>
#include <wchar.h>


void reset_con(bool ext_verif);
void clear_con();

void puts(char16_t *str);


#endif
