#ifndef _OUTPUT_H_
#define _OUTPUT_H_


#include <stdbool.h>
#include <wchar.h>
#include <efi_txt_output.h>


void reset_con(bool ext_verif);
void clear_con();

efi_status_t query_tmode(tmode_n_t tmode_n, col_n_t *col_n, row_n_t *row_n);
tmode_n_t find_tmode(col_n_t col_n, row_n_t row_n_t);
void set_tmode(tmode_n_t tmode_n);

void puts(char16_t *str);
void aputs(char16_t *str, ch_attr_t attr);
void putc(char16_t ch);
void aputc(char16_t ch, ch_attr_t attr);

void set_ch_attr(ch_attr_t attr);
ch_attr_t get_ch_attr();

void set_cur_pos(col_n_t col_n, row_n_t row_n);
void set_cur(bool cur);


#endif
