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
    syscall();
}

void syscall_handler(char type, char argv1, char argv2, char argv3){
    char* mem = 0x0;
    switch (type)
    {
    case SYS_CLEAR_SCREEN:
        sti();
        clear_screen();
        break;
    case SYS_PRINT_CHAR:
        sti();
        print_char(argv1,VGA_WHITEGRAY);
        break;
    case SYS_NEW_LINE:
        sti();
        printf("\n");
        break;
    case SYS_PRINT_INTEGER:
        _ttyPrintInteger(*((int*)mem));
        sti();
        break;
    case SYS_PROCESS_EXIT:
        sti();
        _printf("\n\nProcess Exited with %d", *(int*)0x0);
        break;
    case SYS_RANDOM:
        break;

    case SYS_READCHAR: {
        sti();
        char* b = (char*)0x0;
        *b = readChar();
        break;
    }
    case SYS_DELETEONECHARACTER: {
        sti();
        deleteOneCharacter();
        break;
    }
    case SYS_SLEEP:{
        sti();
        Sleep(*(int*)0x0);
        break;
    }
    case SYS_BOOT_SECONDS:{
        sti();
        uint32_t* b = (uint32_t*)0x10;
        *b = getSeconds();
        break;
    }
    default:
        break;
    }
}