#include "idt.h"

#define LOW_16(address) (uint16_t)((address) & 0xFFFF)
#define HIGH_16(address) (uint16_t)((address) >> 16)


#define IDT_ENTRIES 256
idt_t idt[IDT_ENTRIES];
idtpr idt_reg;


void set_idt_gate(int n, uint32_t handler) {
    idt[n].low_offset = LOW_16(handler);
    idt[n].sel = KERNEL_CS;
    idt[n].always0 = 0;
    idt[n].flags = 0x8E; 
    idt[n].high_offset = HIGH_16(handler);
}

void set_idt(void) {
    idt_reg.base = (uint32_t) &idt;
    idt_reg.limit = IDT_ENTRIES * sizeof(idtpr) - 1;
    __asm__ __volatile__("lidt %0" : : "m" (idt_reg));
}