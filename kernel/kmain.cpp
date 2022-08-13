#include "inc/tty.h"
#include "idt/isr.h"
#include "mem/memory.h"
#include "timer/timer.h"
#include "keyboard/keyboard.h"
#include "utils/kernutils.hpp"

extern "C" int _kmain(){
    clear_screen();
    printOK("Screen has been cleared.\n");
    isr_install();
    printOK("ISR's has been installed.\n");
    sti(); // enable interrupts
    printOK("Enabled interrupts.\n");
    init_timer();
    printOK("Timer has been init.\n");
    Sleep(200);
    _printf("Welcome to hyeoOS!\n");
    Sleep(100);
    _printf("hyeo@user$- ");
    init_keyboard();
    while (true)
    {
        Sleep(10);
    }
    
    



    return -123;
}