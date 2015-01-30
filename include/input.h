#ifndef _INPUT_H_
#define _INPUT_H_


#include <stdint.h>
#include <wchar.h>
#include <efi_txt_input.h>


efi_key_t getk();
char16_t getch();

void getsn(char16_t *str, size_t len);


#endif
