#pragma once
#include "../mem/memory.h"
#include "../hyeo-fs/hfs.h"

void run_binary(void* program_block, uint32_t programSize);
void clear_binary(uint32_t size);
void run_executable(const char* fn);