#pragma once
#include "../inc/typedefs.h"

struct MemoryMapEntry{
    uint32_t base_addr;
    uint32_t reg_lenght;
    uint32_t reg_type;
    uint32_t extended_attr;
};

extern uint8_t memreg;
