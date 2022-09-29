#include "inc/tty.h"
#include "idt/isr.h"
#include "mem/memory.h"
#include "timer/timer.h"
#include "keyboard/keyboard.h"
#include "utils/kernutils.hpp"
#include "syscall/syscall.h"
#include "runtime/runtime.h"
#include "hyeo-fs/hfs.h"


extern char vfs[];

extern "C" int _kmain(){
    clear_screen();
    _printf("hyeo v0.1f %s %s \n\n\n",__DATE__, __TIME__);
    printOK("Screen has been cleared.\n");
    isr_install();
    printOK("ISR's has been installed.\n");
    printOK("Enabled interrupts.\n");    
    init_keyboard();
    sys_call_init();
    init_timer();
    sti();
    printOK("Timer IRQ has been init.\n");
    Sleep(250);
    printOK("Keyboard IRQ has been init.\n");
    _printf("Welcome to hyeoOS!\n\n\n");   
    run_binary(vfs,7364);
    clear_binary(7364);    

    Sleep(250);
    print_char('.',VGA_WHITEGRAY);
    Sleep(250);
    print_char('.',VGA_WHITEGRAY);
    Sleep(250);
    print_char('.',VGA_WHITEGRAY);
    Sleep(250);
    print_char('.',VGA_WHITEGRAY);
    Reboot();
    return -1;
}
