#include "memory.h"


void* memcpy(void* dest, void* src, uint32_t size){
    uint8_t* _dest = (uint8_t*)dest;
    uint8_t* _src = (uint8_t*)src;
    volatile uint32_t index = 0;
    while(index != size){
        *(_dest + index) = *(_src + index);
        index++;    
    }   
    return _dest;
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
    return _dest;
}

void* memset(void* dest,uint8_t val, uint32_t size){
    for(volatile uint32_t i = 0;i < size; i++) *(uint8_t*)(dest + i) = val;
    return dest;
}

bool strcmp(char* str1, char* str2){
    uint32_t i = 0;
    uint32_t len = strlen(str1);
    uint32_t len2 = strlen(str2);
    if(len != len2) return true;
    if(len <= 0) return true;
    while(i < len){
        if(*(str1+i) != *(str2+i)){
            return true;
        } else{
            i++;
        }
    }

    if(i == len) return false;
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
