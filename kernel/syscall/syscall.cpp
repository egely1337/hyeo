#include "syscall.h"



void sys_call_init(void){
    set_call_handler();
}
void set_call_handler(void){
    set_idt_gate(110,(uint32_t)call_handler);
}
void syscall(void){
    char* mem = 0x0;
    syscall_handler(mem[82],mem[83],mem[84],mem[85]);
}
void call_handler(void){
    asm("pusha");
    syscall();
    asm("popa");
    asm("leave");
    asm("iret");
}

void syscall_handler(char type, char argv1, char argv2, char argv3){
    char* mem = 0x0;
    switch (type)
    {
    case SYS_CLEAR_SCREEN:
        clear_screen();
        break;
    case SYS_PRINT_CHAR:
        print_char(argv1,VGA_WHITEGRAY);
        break;
    case SYS_NEW_LINE:
        printf("\n");
        break;
    case SYS_PRINT_INTEGER:
        _ttyPrintInteger(*((int*)mem));
        break;
    case SYS_PROCESS_EXIT:
        _printf("\nProcess Exited with %d", (int)argv1);
        break;
    case SYS_RANDOM:
        break;

    case SYS_READCHAR: {
        char* b = (char*)0x0;
        *b = readChar();
        break;
    }
    case SYS_DELETEONECHARACTER: {
        deleteOneCharacter();
        break;
    }
    default:
        break;
    }
}