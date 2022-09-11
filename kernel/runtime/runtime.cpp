#include "runtime.h"
#define PROG_ADDRESS (void*)0x30000


void run_binary(void* program_block, uint32_t programSize){
    memcpy(PROG_ADDRESS,program_block,programSize);
    asm volatile("call *%0"
							 :
							 : "r"(PROG_ADDRESS));
}

void clear_binary(uint32_t size){
    memset(PROG_ADDRESS, 0,size);
}