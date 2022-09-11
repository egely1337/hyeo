#include "panic.h"


void panic(const char* sys_message){
    _printf(" \n#--System Crashed! - not Syncing--#\n");
    _printf("\n%s\n", sys_message);
    _printf("\n#--end of kernel panic - not Syncing--#\n");
    asm("cli");
    for(;;)
        asm("hlt");
}