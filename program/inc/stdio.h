#pragma once
#include "typedefs.h"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE -1


void set_args(char type, char arg1,char arg2, char arg3);
void clear(void);
void print_char(char b);
void printf(const char *fmt, ...);
char readChar(void);
uint32_t strlen(char* data);
void exit(uint32_t exit_code);