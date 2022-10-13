#pragma once
#include "stdio.h"
#include "string.h"




#define HFS_INITALIZE 0
#define HFS_ERROR 1

#define MAX_PROGRAM_SIZE 24576/2
struct HFS_INIT {
    uint8_t HFS[2];
    uint8_t reserved;
    uint32_t fileCount;
};



struct FILE_TABLE{
    char FILE_NAME[32];
    uint32_t FILE_SIZE;
    char data[MAX_PROGRAM_SIZE];
};


uint32_t get_boot_seconds(void);
void crash(void);
HFS_INIT* get_hfs_data(void);