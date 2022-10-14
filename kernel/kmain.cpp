#include "inc/tty.h"
#include "idt/isr.h"
#include "mem/memory.h"
#include "timer/timer.h"
#include "keyboard/keyboard.h"
#include "utils/kernutils.hpp"
#include "syscall/syscall.h"
#include "runtime/runtime.h"
#include "hyeo-fs/hfs.h"
#include "mem/memmap.h"


uint32_t total_mem(){
    unsigned short total;
    unsigned char lowmem, highmem;
 
    outb(0x70, 0x30);
    lowmem = inb(0x71);
    outb(0x70, 0x31);
    highmem = inb(0x71);
 
    total = lowmem | highmem << 8;
    return total;
}

extern "C" int _kmain(){
    clear_screen();
    _printf("hyeo v0.1f %s %s \n\n\n",__DATE__, __TIME__);
    _printf__ok("Screen has been cleared.\n");
    isr_install();
    _printf__ok("ISR's has been installed.\n");
    _printf__ok("Enabled interrupts.\n");    
    init_keyboard();
    sys_call_init();
    init_timer();
    sti();
    _printf__ok("Timer IRQ has been init.\n");
    Sleep(250);
    _printf__ok("Keyboard IRQ has been init.\n"); 
    hfs_initialize();
    _printf__ok("File system init.\n");
    _printf__warn("%d MiB Memory Available\n", total_mem() /1024);
    _printf("\nWelcome to hyeoOS!\n\n\n");  
    HFS_INIT* hfs = get_hfs_data();
    FILE_TABLE* fp = hfs_get_file_data("app32/program.bin");
    run_executable("app32/program.bin");

    
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
