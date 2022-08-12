#pragma once
#include "../inc/typedefs.h"

void* memcpy(void* dest, void* src, uint32_t size);
void kmemcpy(char* source, char* dest, int nbytes);
uint32_t strlen(char* data);
