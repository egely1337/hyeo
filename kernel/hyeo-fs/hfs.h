#pragma once
#include "../inc/typedefs.h"
#include "../inc/tty.h"
#include "../runtime/runtime.h"


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

void hfs_initialize(void* mod_st);
char* hfs_open(const char* fn);
FILE_TABLE* hfs_get_file_data(const char* fn);
uint8_t hfs_is_file_exists(const char* fn);
HFS_INIT* get_hfs_data(void);