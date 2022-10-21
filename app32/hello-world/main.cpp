#include "../../stdio/stdio.h"
#include "../../stdio/string.h"
#include "../../stdio/hyeo.h"

extern "C" int _start(){
    for(uint32_t i = 0; i < 300; i++){
        printf("Hello World!\n");
    }
    exit(1);
}    
