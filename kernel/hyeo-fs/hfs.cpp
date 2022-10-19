#include "./hfs.h"
#include "../panic/panic.h"
#include "../mem/memory.h"

uint8_t init;
HFS_INIT* hfs;
void hfs_initialize(void* mod_s){
    hfs = (HFS_INIT*)mod_s;
    if(strcmp((char*)hfs->HFS,"HFS")) panic("HFS error!");

    #ifdef DEBUG 1

        FILE_TABLE *file_table = (FILE_TABLE*)((uint32_t)hfs + 0x8);
        _printf("hyeoFS: /dev/vfs/\n");
        for(uint32_t i = 0; i < hfs->fileCount; i++){
            _printf("file name: %s | file size: %d\n", 
            (uint8_t*)file_table[i].FILE_NAME, file_table[i].FILE_SIZE);
        }

    #endif    
    init = HFS_INITALIZE;
}

char* hfs_open(const char* fn){
    if(init != HFS_INITALIZE) panic("File system hasnt inited yet.");
    FILE_TABLE *file_table = (FILE_TABLE*)((uint32_t)hfs + 0x8);
    for(uint32_t i = 0; i < hfs->fileCount; i++){
        if(!strcmp(file_table[i].FILE_NAME,(char*)fn)) return file_table[i].data;
    }
}

FILE_TABLE* hfs_get_file_data(const char* fn){
    if(init != HFS_INITALIZE) panic("File system isn't inited yet.");
    FILE_TABLE *file_table = (FILE_TABLE*)((uint32_t)hfs + 0x8);
    for(uint32_t i = 0; i < hfs->fileCount; i++){
        if(!strcmp(file_table[i].FILE_NAME,(char*)fn)) return &file_table[i];
    }
}

uint8_t hfs_is_file_exists(const char* fn){
    if(init != HFS_INITALIZE) panic("File system isn't inited yet.");
    FILE_TABLE *file_table = (FILE_TABLE*)((uint32_t)hfs + 0x8);
    for(uint32_t i = 0; i < hfs->fileCount; i++){
        if(!strcmp(file_table[i].FILE_NAME,(char*)fn)) return true;
    }

    panic("File couldnt found in hfs.");
}

HFS_INIT* get_hfs_data(void){
    if(init != HFS_INITALIZE) panic("File system isn't inited yet.");
    return hfs;
}