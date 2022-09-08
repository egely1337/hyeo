#include "inc/tty.h"
#include "idt/isr.h"
#include "mem/memory.h"
#include "timer/timer.h"
#include "keyboard/keyboard.h"
#include "utils/kernutils.hpp"
#include "syscall/syscall.h"


extern "C" char shell[];


extern "C" int _kmain(){
    clear_screen();
    sti(); // enable interrupts
    _printf("hyeo v0.1f %s %s \n\n\n",__DATE__, __TIME__);
    _printf("Hello World from Linux Build!\n");
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
    _printf("Welcome to hyeoOS!\n");
    /*copy the shell to 0x12000 and jump it*/
    memcpy((void*)0x12000,shell,4264);
    ((void (*)())0x12000)(); 
    return -1;
}