#pragma once
#define Nop() asm("nop")
#define hlt() asm("hlt")
#include "typedefs.h"

void outb(uint16_t port, uint8_t data);
uint8_t inb(uint16_t port);
void wait_ticks(uint32_t seconds);