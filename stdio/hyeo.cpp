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

HFS_INIT* get_hfs_data(void){
    set_args(13,0,0,0);
    asm("int $110");
    return (HFS_INIT*)(*(int*)0x0);
}

/* Temporary, will be deleted soon */

FILE_TABLE* get_first_table(void){
    return (FILE_TABLE*)((uint32_t)get_hfs_data() + 0x8);
}

FILE_TABLE* open(const char* fn){
    FILE_TABLE* fp = get_first_table();
    for(uint32_t i = 0; i < get_hfs_data()->fileCount; i++){
        if(!strcmp(fp[i].FILE_NAME,(char*)fn)) return &fp[i];
    }

    return nullptr;
}




/* End of Temporary */