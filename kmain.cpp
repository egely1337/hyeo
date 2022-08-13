#include "inc/tty.h"
#include "idt/isr.h"
#include "mem/memory.h"
#include "timer/timer.h"
#include "keyboard/keyboard.h"
#include "utils/kernutils.hpp"


extern "C" bool kernelStarted = false;

extern "C" int _kmain(){
    clear_screen();
    _printf("hyeo v0.1f %s %s \n\n\n",__DATE__, __TIME__);
    printOK("Screen has been cleared.\n");
    isr_install();
    printOK("ISR's has been installed.\n");
    sti(); // enable interrupts
    printOK("Enabled interrupts.\n");
    init_timer();
    init_keyboard();
    printOK("Timer has been init.\n");
    Sleep(20);
    printOK("Keyboard IRQ has been init.\n");
    Sleep(200);
    _printf("Welcome to hyeoOS!\n");
    Sleep(100);
    kernelStarted = true;
    _printf("hyeo@user$- ");
    while (true)
    {
        Sleep(10);
    }
    
    



    return -123;
}