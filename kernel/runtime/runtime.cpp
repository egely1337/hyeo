#include "runtime.h"


void run_block(void* program_block){
    memcpy((void*)0x12000,program_block,4264);
    ((void (*)())0x12000)(); 
}