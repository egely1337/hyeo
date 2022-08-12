#pragma once
#include "../inc/typedefs.h"

void* memcpy(void* dest, void* src, uint32_t size);
void* memset(void* dest,uint8_t val, uint32_t size);
void* memcut(void* dest, void* src, uint32_t size);
uint32_t strlen(char* data);
