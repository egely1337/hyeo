#include "inc/tty.h"
#include "idt/isr.h"
#include "mem/memory.h"
#include "timer/timer.h"

extern "C" int _kmain(){
    clear_screen();
    isr_install();
    sti(); // enable interrupts
    init_timer();
    _printf("Sleep start\n");
    Sleep(10);
    _printf("Sleep finish\n");
    Sleep(5);
    _printf("Sleep 5 sec");
    for(int i = 0; i < 500000; i++){
        
    }
    Sleep(10);



    return -123;
}