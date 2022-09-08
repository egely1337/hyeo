#include "io.h"


void outb(uint16_t port, uint8_t data){
    asm volatile("outb %0, %1" : : "a"(data), "Nd"(port));
    return;
}

uint8_t inb(uint16_t port){
    uint8_t res;
    asm volatile("inb %1, %0" : "=a"(res) : "Nd"(port));
    return res;
}

void wait_ticks(uint32_t seconds){
    for(uint32_t i = 0; i < 100*seconds; i++){
        Nop();
    }
}

void Reboot(){
    uint8_t good = 0x02;
    while(good & 0x02) good = inb(0x64);
    outb(0x64,0xFE);
    hlt(); 
}