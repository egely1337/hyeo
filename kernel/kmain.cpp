#include "inc/tty.h"
#include "idt/isr.h"
#include "mem/memory.h"
#include "timer/timer.h"
#include "keyboard/keyboard.h"
#include "utils/kernutils.hpp"
#include "syscall/syscall.h"
#include "runtime/runtime.h"

extern "C" char shell[];

unsigned read_pit_count(void) {
	unsigned count = 0;
 
	// Disable interrupts
	cli();
 
	// al = channel in bits 6 and 7, remaining bits clear
	outb(0x43,0b0000000);
 
	count = inb(0x40);		// Low byte
	count |= inb(0x40)<<8;		// High byte
 
	return count;
}

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
    run_binary(shell,3209);
    clear_binary(3209);

    printf("\nRebooting.");
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
