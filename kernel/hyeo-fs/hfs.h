#pragma once
#include "../inc/typedefs.h"
#include "../inc/tty.h"

struct HFS_INIT {
    uint8_t HFS[3];
    uint8_t reserved;
    uint32_t fileCount;
};


struct FILE_TABLE{
    char FILE_NAME[32];
    uint32_t FILE_SIZE;
    char* data;
};


void hfs_initialize(void);