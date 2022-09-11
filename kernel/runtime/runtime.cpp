#include "runtime.h"


void run_binary(void* program_block, uint32_t programSize){
    memcpy((void*)0x30000,program_block,programSize);
    asm volatile("call *%0"
							 :
							 : "r"(0x30000));
}

void clear_binary(uint32_t size){
    memset((void*)0x30000, 0,size);
}