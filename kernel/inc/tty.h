#pragma once
#include "io.h"
#include "typedefs.h"
#include "../utils/colors.hpp"

#define VGA_MEMORY (char*)0xB8000
#define VGA_WIDTH 80
#define MAX_ROWS 25


struct 
{
    uint16_t x = 0;
    uint16_t y = 0;
    uint16_t returnRawPosition(){
        return (y * 80) + x;
    }
} cursorPosition;


void SetCursorPosition(uint16_t position);
void deleteOneCharacter(void);
void clear_screen(void);
void print_char(char s, uint16_t color);
void printf(const char* _text);
void printInteger(int _data);
char* _ttyPrintInteger(int _integer);
void resetCursorPosition(void);
void _printf(const char* fmt, ...); 
void _printf__ok(const char* fmt, ...); 
void _printf__warn(const char* fmt, ...); 
void _printCurrentEntries(void);
void clear_col(int col);
void clear_screen_color(uint16_t backcolour, uint16_t forecolour);
void _setCursorPosition(uint16_t x, uint16_t y);
void _t(void);
void print_hex(uint32_t hex_nmbr);