#include <global.h>
#include <wchar.h>
#include <exception.h>
#include <output.h>


static void puts_noex(char16_t *str)
{
	efi_systab->con_out->puts(efi_systab->con_out, str);
}


void throw_exc(uint32_t code)
{
	switch (code)
	{
		case EXCEPTION_VIDEO_UNSUPPORTED:
			puts_noex(L"Warning: the video device doesn't support a preferable feature. Output can be incorrect.\n\r");
			break;
		case EXCEPTION_VIDEO_ERROR:
			puts_noex(L"Error: a critical video device error occured.\n\r"); //Maybe a user won't even see this.
			break;
		case EXCEPTION_VIDEO_INVALID_MODE:
			set_tmode(0); // Try the zero mode.
			puts_noex(L"Warning: using failsafe text mode.\n\r");
			break;
		case EXCEPTION_VIDEO_BAD_CHR:
			puts_noex(L"Warning: the firmware rejected some character(s). Output can be incorrect.\n\r");
			break;
		case EXCEPTION_KBD_ERROR:
			puts_noex(L"Error: couldn't get keyboard input.\n\r");
			break;
		default:
			puts_noex(L"Warning: an undefined exception was thrown.\n\r");
	}
}
