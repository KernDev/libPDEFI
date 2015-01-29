#include <stdbool.h>
#include <output.h>
#include <global.h>
#include <efi_systab.h>
#include <efi_status.h>
#include <exception.h>
#include <cpu.h>


void reset_con(bool ext_verif)
{
	efi_status_t status = efi_systab->con_out->reset(efi_systab->con_out, ext_verif);
	if (status == EFI_DEVICE_ERROR)
		throw_exc(EXCEPTION_VIDEO_ERROR);
}

void clear_con()
{
	efi_status_t status = efi_systab->con_out->clear(efi_systab->con_out);
	if (status != EFI_SUCCESS)
	{
		if (status == EFI_DEVICE_ERROR)
			throw_exc(EXCEPTION_VIDEO_ERROR);
		else if (status == EFI_UNSUPPORTED)
			throw_exc(EXCEPTION_VIDEO_INVALID_MODE);
	}
}


efi_status_t query_tmode(tmode_n_t tmode_n, col_n_t *col_n, row_n_t *row_n)
{
	efi_status_t status = efi_systab->con_out->query_mode(efi_systab->con_out, tmode_n, col_n, row_n);
	if (status != EFI_SUCCESS)
	{
		if (status == EFI_UNSUPPORTED)
			throw_exc(EXCEPTION_VIDEO_UNSUPPORTED);
		else if (status == EFI_DEVICE_ERROR)
			throw_exc(EXCEPTION_VIDEO_ERROR);
	}
}

tmode_n_t find_tmode(col_n_t col_n, row_n_t row_n)
{
	for (tmode_n_t tmode_n = 0; tmode_n <= (unsigned) efi_systab->con_out->mode->max_mode; tmode_n++)
	{
		col_n_t c_col_n;
		row_n_t c_row_n;
		if (query_tmode(tmode_n, &c_col_n, &c_row_n) == EFI_SUCCESS)
			if (c_col_n == col_n && c_row_n == row_n)
				return tmode_n;
	}

	return 0;
}

void set_tmode(tmode_n_t tmode_n)
{
	col_n_t c_col_n;
	row_n_t c_row_n;
	efi_status_t status = query_tmode(tmode_n, &c_col_n, &c_row_n);
	if (status != EFI_SUCCESS)
	{
		if (status == EFI_UNSUPPORTED)
			throw_exc(EXCEPTION_VIDEO_UNSUPPORTED);
		else if (status == EFI_DEVICE_ERROR)
			throw_exc(EXCEPTION_VIDEO_ERROR);

		return;
	}

	status = efi_systab->con_out->set_mode(efi_systab->con_out, tmode_n);
	if (status != EFI_SUCCESS)
	{
		if (status == EFI_UNSUPPORTED)
			throw_exc(EXCEPTION_VIDEO_UNSUPPORTED);
		else if (status == EFI_DEVICE_ERROR)
			throw_exc(EXCEPTION_VIDEO_ERROR);
	}
}


void set_ch_attr(ch_attr_t attr)
{
	efi_status_t status = efi_systab->con_out->set_attr(efi_systab->con_out, attr);
	if (status == EFI_DEVICE_ERROR)
		throw_exc(EXCEPTION_VIDEO_ERROR);
}

ch_attr_t get_ch_attr()
{
	return (ch_attr_t) (efi_systab->con_out->mode->attr);
}


void puts(char16_t *str)
{
	efi_status_t status = efi_systab->con_out->puts(efi_systab->con_out, str);
	if (status != EFI_SUCCESS)
	{
		if (status == EFI_DEVICE_ERROR)
			throw_exc(EXCEPTION_VIDEO_ERROR);
		else if (status == EFI_UNSUPPORTED)
			throw_exc(EXCEPTION_VIDEO_INVALID_MODE);
		else if (status == EFI_WARN_UNKNOWN_GLYPH)
			throw_exc(EXCEPTION_VIDEO_BAD_CHR);
	}
}

void aputs(char16_t *str, ch_attr_t attr)
{
	ch_attr_t old_attr = get_ch_attr();

	set_ch_attr(attr);
	puts(str);

	set_ch_attr(old_attr);
}


void set_cur_pos(col_n_t col_n, row_n_t row_n)
{
	efi_status_t status = efi_systab->con_out->set_cur_pos(efi_systab->con_out, col_n, row_n);
	if (status != EFI_SUCCESS)
	{
		puts(L"Hmm...\n\r");
		if (status == EFI_DEVICE_ERROR)
			throw_exc(EXCEPTION_VIDEO_ERROR);
		else if (status == EFI_UNSUPPORTED)
			throw_exc(EXCEPTION_VIDEO_INVALID_MODE);
		else puts(L"WTF?!\n\r");
	}
}

void set_cur(bool cur)
{
	efi_status_t status = efi_systab->con_out->set_cur(efi_systab->con_out, cur);
	if (status != EFI_SUCCESS)
	{
		if (status == EFI_DEVICE_ERROR)
			throw_exc(EXCEPTION_VIDEO_ERROR);
		else if (status == EFI_UNSUPPORTED)
			throw_exc(EXCEPTION_VIDEO_UNSUPPORTED);
	}
}
