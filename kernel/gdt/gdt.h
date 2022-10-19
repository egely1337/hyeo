#pragma once

typedef struct Gdt_Entry {
    unsigned short limit_low;
    unsigned short base_low;
    unsigned char base_middle;
    unsigned char access;
    unsigned char granularity;
    unsigned char base_high;
} __attribute__((packed)) Gdt_Entry;

typedef struct Gdt_Ptr {
    unsigned short limit;
    unsigned int base;
} __attribute__((packed)) Gdt_Ptr;

extern "C" void gdt_flush(void);
void gdt_install(void);