#include "./hfs.h"
#include "../panic/panic.h"
#include "../mem/memory.h"

extern char vfs[];


#define DEBUG

void hfs_initialize(){
    HFS_INIT* hfs = (HFS_INIT*)vfs;
    if(strcmp((char*)hfs->HFS,"HFS")) panic("HFS error!");

    #ifdef DEBUG
        _printf("HYEO File System:\n\nChecksum: %s\nFile: %d\n", hfs->HFS,hfs->fileCount);


    FILE_TABLE* file_table = (FILE_TABLE*) (vfs+8);

    //_printf("File name: %s\n File size: %d", file_table->FILE_NAME, file_table->FILE_SIZE);
    unsigned int* b = (uint32_t*)vfs + 40;
    _printf("%d", *b);
    #endif    
}