#include "runtime.h"
#define PROG_ADDRESS (void*)0x30000


void run_binary(void* program_block, uint32_t programSize){
    if(programSize == 0) return;
    memcpy(PROG_ADDRESS,program_block,programSize);
    asm volatile("call *%0"
							 :
							 : "r"(PROG_ADDRESS));
    clear_binary(programSize);
}

void clear_binary(uint32_t size){
    memset(PROG_ADDRESS, 0,size);
}

void run_executable(const char* fn){
    hfs_is_file_exists(fn);
    FILE_TABLE* fp = hfs_get_file_data(fn);
    run_binary(fp->data,fp->FILE_SIZE);
}