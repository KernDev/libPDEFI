#ifndef _INPUT_H_
#define _INPUT_H_


#include <stdint.h>
#include <wchar.h>
#include <efi_txt_input.h>


efi_key_t getk();
char16_t getch();

char16_t *dgets();


#endif
