#pragma once
#include "../inc/tty.h"


void printOK(const char* txt){
    _printf("[");
    print_char('O', VGA_GREEN);
    print_char('K', VGA_GREEN);
    _printf("]");
    _printf(" ");
    _printf("%s",txt);
}