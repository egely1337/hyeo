#include "runtime.h"


void run_block(void* program_block, uint32_t programSize){
    memcpy((void*)0x12000,program_block,programSize);
    ((void (*)())0x12000)(); 
}

void clear_block(uint32_t size){
    memset((void*)0x12000, 1,size);
}