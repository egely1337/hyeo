#include "hyeo.h"



int get_boot_seconds(){
    set_args(9,0,0,0);
    asm("int $110");
    return *(int*)0x0;
}