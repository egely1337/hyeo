#include "gdt.h"

Gdt_Entry gdt[5];
Gdt_Ptr gp;

void gdt_set_gate(int num, unsigned long base, unsigned long limit,
                  unsigned char access, unsigned char gran)
{
    gdt[num].base_low = (base & 0xFFFF);
    gdt[num].base_middle = (base >> 16) & 0xFF;
    gdt[num].base_high = (base >> 24) & 0xFF;

    gdt[num].limit_low = (limit & 0xFFFF);
    gdt[num].granularity = ((limit >> 16) & 0x0F);

    gdt[num].granularity |= (gran & 0xF0);
    gdt[num].access = access;
}

void gdt_install(void) {
    gp.limit = (sizeof(Gdt_Entry) * 3) - 1;
    gp.base = (int)&gdt;

    gdt_set_gate(0, 0, 0, 0, 0);                            // Null segment
    gdt_set_gate(1, 0, 0xFFFFFFFF, 0b10011010, 0b11001111); // Code segment
    gdt_set_gate(2, 0, 0xFFFFFFFF, 0b10010010, 0b11001111); // Data segment
    gdt_set_gate(3, 0, 0xFFFFFFFF, 0b11111010, 0b11001111); // User mode code segment
    gdt_set_gate(4, 0, 0xFFFFFFFF, 0b11110010, 0b11001111); // User mode data segment

    gdt_flush();
}