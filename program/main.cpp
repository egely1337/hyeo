#include "inc/stdio.h"
extern "C" int _start(){
    printf("Hello World from hyeo-i386 program!\n");
    uint8_t* ptr = (uint8_t*)0xB8000;
    for(uint32_t i = 0; i < 0xFFFF; i++){
        *ptr = 'B';
        ++ptr;  
    }
    exit(EXIT_SUCCESS);
}   