#ifndef _CMDLINE_H_
#define _CMDLINE_H_


#include <wchar.h>
#include <stdint.h>


enum {
	CMD_SUCCESS,
	CMD_FAILURE,
	CMD_EXIT
};


typedef uint32_t cmd_status_t;


typedef struct {
	char16_t *name;
	cmd_status_t (*cb)();
} cmd_t;


void start_cmdline(char16_t *prompt, uint32_t cmdc, cmd_t *cmds);


#endif
