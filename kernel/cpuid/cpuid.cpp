#include "cpuid.h"


static cpu_t cpu_info;
static inline void _cpuid(unsigned int *eax, unsigned int *ebx,unsigned int *ecx, unsigned int *edx)
{
        asm volatile("cpuid"
            : "=a" (*eax),
              "=b" (*ebx),
              "=c" (*ecx),
              "=d" (*edx)
            : "0" (*eax), "2" (*ecx));
}


void getCpuVendor(void){
    uint8_t vendor[13];
    uint32_t get_vendor = 0;
    _cpuid(&get_vendor,(uint32_t*)(vendor + 0), (uint32_t*)(vendor + 8), (uint32_t*)(vendor + 4));
    vendor[12] = '\0';
    memcpy(&cpu_info.vendor[0],&vendor[0],13);
}

cpu_t& get_cpu_info(void){
    return cpu_info;
}

void init_cpuid(void){
    getCpuVendor();
}
