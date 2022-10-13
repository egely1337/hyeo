#include "inc/tty.h"
#include "idt/isr.h"
#include "mem/memory.h"
#include "timer/timer.h"
#include "keyboard/keyboard.h"
#include "utils/kernutils.hpp"
#include "syscall/syscall.h"
#include "runtime/runtime.h"
#include "hyeo-fs/hfs.h"


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
    hfs_initialize();
    printOK("File system init.\n");
    _printf("\nWelcome to hyeoOS!\n\n\n");  
    FILE_TABLE* fp = hfs_get_file_data("app32/program.bin");
    run_binary(fp->data,fp->FILE_SIZE);

    
    /*Sleep(250);
    print_char('.',VGA_WHITEGRAY);
    Sleep(250);
    print_char('.',VGA_WHITEGRAY);
    Sleep(250);
    print_char('.',VGA_WHITEGRAY);
    Sleep(250);
    print_char('.',VGA_WHITEGRAY);
    Reboot();*/
    return -1;
}
