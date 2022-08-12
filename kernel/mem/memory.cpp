#include "memory.h"


void* memcpy(void* dest, void* src, uint32_t size){
    uint8_t* _dest = (uint8_t*)dest;
    uint8_t* _src = (uint8_t*)src;
    uint32_t index = 0;
    while(index != size){
        *(_dest + index) = *(_src + index);
        index++;    
    }   
    return (_dest);
}

void* memcut(void* dest, void* src, uint32_t size){
    uint8_t* _dest = (uint8_t*)dest;
    uint8_t* _src = (uint8_t*)src;
    uint32_t index = 0;
    while(index != size){
        *(_dest + index) = *(_src + index);
        *(_src + index) = 0;
        index++;    
    }   
    return (_dest);
}

void* memset(void* dest,uint8_t val, uint32_t size){
    for(uint32_t i = 0; i < size; i++) *(uint8_t*)(dest + i) = val;
}

uint32_t strlen(char* data){
    char* _data = (char*)data;
    uint32_t size = 0;
    while(*_data != '\0') {
        size++;
        _data++;
    }
    return size;
}
