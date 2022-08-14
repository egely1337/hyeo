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
    _printf("\nRebooting in 3 sec\n");
    wait_ticks(2000);
    _printf("Rebooting in 2 sec\n");
    wait_ticks(2000);
    _printf("Rebooting in 1 sec\n");
    wait_ticks(2000);
    _printf("NOW!\n");
    wait_ticks(1000);
    uint8_t good = 0x02;
    while(good & 0x02) good = inb(0x64);
    outb(0x64,0xFE);
    hlt(); 
}