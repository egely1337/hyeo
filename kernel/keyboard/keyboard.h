#pragma once
#include "../inc/typedefs.h"
#include "../inc/io.h"
#include "../inc/tty.h"
#include "../idt/isr.h"
#include "../timer/timer.h"
#include "../mem/memory.h"

void keyboard_handler(Registers _regs);
void init_keyboard(void);