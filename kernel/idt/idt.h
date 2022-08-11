/*
    Lots of thanks to tixvage [https://github.com/tixvage]
*/
#pragma once
#include "../inc/typedefs.h"

#define KERNEL_CS 0x08

typedef struct idt_t {
    uint16_t low_offset;
    uint16_t sel;
    uint8_t always0;
    uint8_t flags; 
    uint16_t high_offset;
} __attribute__((packed)) idt_t;

typedef struct idtpr {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed)) idtpr;


void set_idt_gate(int n, uint32_t handler);
void set_idt(void);
