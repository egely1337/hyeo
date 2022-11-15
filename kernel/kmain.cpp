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
#include "gdt/gdt.h"
#include "./multiboot.h"
#include "cpuid/cpuid.h"

extern "C" void _kmain(){
    register int *mboot_addr asm ("ebx"); // gets multiboot info address
    multiboot_t* mboot_struct = (multiboot_t*)mboot_addr; // gets grub 2 multiboot info
    mod_t* hfs_mod = (mod_t*)mboot_struct->mods_addr; // gets initrd
    clear_screen();
    _printf("hyeo v0.1f %s %s : %s() \n\n\n",__DATE__, __TIME__,__FUNCTION__);

    gdt_install();
    gdt_flush();  
    _printf__ok("GDT has been installed.\n");  
    isr_install();
    _printf__ok("IDT has been installed.\n");
    init_cpuid();
    sti();
    init_keyboard();
    sys_call_init();
    init_timer();
    _printf__ok("Timer driver has been init.\n");
    Sleep(250);
    _printf__ok("Keyboard driver has been init.\n"); 
    if((uint32_t)(mboot_struct->mem_upper / 1024) < 32) panic("Not enough memory to run RamFS."); 
    if(mboot_struct->mods_count < 1) panic("Initrd not found in system.");
    hfs_initialize((void*)hfs_mod->mod_start);
    _printf__ok("File system init.\n");
    _printf__warn("Total size of Physical Memory: %d MiB\n", (mboot_struct->mem_lower | mboot_struct->mem_upper) / 1024);
    _printf__warn("Total size of HFS: %d KiB\n", (uint32_t)(hfs_mod->mod_end-hfs_mod->mod_start) / 1024);
    _printf__warn("CPU Vendor: %s\n", get_cpu_info().vendor);
    HFS_INIT* hfs = get_hfs_data();
    FILE_TABLE* fp = hfs_get_file_data("app32/program.bin");
    run_executable("sys/shell.bin");

    
    _printf("Kernel couldnt find task to run. System halted!");
    hlt();
}
