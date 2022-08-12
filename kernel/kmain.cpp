#include "inc/tty.h"
#include "idt/isr.h"
#include "mem/memory.h"

extern "C" int _kmain(){
    isr_install();
    clear_screen();
    for(uint32_t i = 0; i < 90000; i++){
    }
    int i = (5 / 0);
    return -123;
}