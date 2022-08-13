#include "timer.h"



uint32_t _timerTicks = 0;
static void timer_handler(Registers _regs){
    _timerTicks++;
    if(_timerTicks == 0xFFFFFFFF){
        _timerTicks = 0;
    }
}

void Sleep(uint32_t mill){
    uint32_t loc = _timerTicks + mill;
    while (_timerTicks < loc) hlt();
}

void init_timer(void){
    register_interrupt_handler(IRQ0,timer_handler);
    uint16_t divisior = INPUT_CLOCK_FREQUENCY / 100;
    uint8_t low  = (uint8_t)(divisior & 0xFF);
    uint8_t high = (uint8_t)( (divisior >> 8) & 0xFF);
    outb(0x43, 0x36);
    outb(0x40, low);
    outb(0x40, high);
}   