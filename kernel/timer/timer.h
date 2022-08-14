#pragma once
#include "../inc/typedefs.h"
#include "../inc/tty.h"
#include "../idt/isr.h"
#include "../inc/io.h"
#define INPUT_CLOCK_FREQUENCY 1193180

static void timer_handler(Registers _regs);
void init_timer(void);
void Sleep(uint32_t seconds);
uint32_t getTicks(void);
uint32_t getSeconds(void);