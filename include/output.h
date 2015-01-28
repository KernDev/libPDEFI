#ifndef _OUTPUT_H_
#define _OUTPUT_H_


#include <stdbool.h>
#include <wchar.h>
#include <efi_txt_output.h>


void reset_con(bool ext_verif);
void clear_con();

void puts(char16_t *str);
void aputs(char16_t *str, ch_attr_t attr);

void set_ch_attr(ch_attr_t attr);
ch_attr_t get_ch_attr();


#endif
