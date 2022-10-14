#include "string.h"

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