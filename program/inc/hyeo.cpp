#include "hyeo.h"



uint32_t get_boot_seconds(void){
    set_args(9,0,0,0);
    asm("int $110");
    return *(int*)0x10;
}