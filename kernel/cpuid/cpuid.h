#pragma once
#include "../inc/typedefs.h"
#include "../inc/tty.h"
#include "../mem/memory.h"


typedef struct{
    uint8_t vendor[13];
    uint8_t processorName[48];
} cpu_t;

static inline void _cpuid(unsigned int *eax, unsigned int *ebx,unsigned int *ecx, unsigned int *edx);
void getCpuVendor(void);
cpu_t& get_cpu_info(void);
void init_cpuid(void);