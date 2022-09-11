#include "hyeo.h"



uint32_t get_boot_seconds(void){
    set_args(SYS_BOOT_SECONDS,0,0,0);
    asm("int $110");
    return *(int*)0x10;
}

void crash(void){
    set_args(12,0,0,0);
    asm("int $110");
}