#include "inc/tty.h"
#include "idt/isr.h"
#include "mem/memory.h"
#include "timer/timer.h"
#include "keyboard/keyboard.h"
#include "utils/kernutils.hpp"
#include "syscall/syscall.h"


bool kernelStarted = false;
extern "C" char program[];

extern "C" int _kmain(){
    clear_screen();
    sti(); // enable interrupts
    _printf("hyeo v0.1f %s %s \n\n\n",__DATE__, __TIME__);
    printOK("Screen has been cleared.\n");
    isr_install();
    printOK("ISR's has been installed.\n");
    printOK("Enabled interrupts.\n");
    init_timer();
    init_keyboard();
    sys_call_init();
    printOK("Timer IRQ has been init.\n");
    Sleep(20);
    printOK("Keyboard IRQ has been init.\n");
    Sleep(200);
    _printf("Welcome to hyeoOS!\n");
    Sleep(100);
    kernelStarted = true;
    _printf("hyeo@user$- ");


    while (true)
    {
        Sleep(200);
    }
    


    return -1;
}