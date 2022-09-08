#pragma once
#include "../inc/typedefs.h"
#include "../inc/io.h"
#include "../inc/tty.h"
#include "../idt/isr.h"
#include "../mem/memory.h"
#include "../timer/timer.h"

void keyboard_handler(Registers _regs);
void init_keyboard(void);
char readChar(void);