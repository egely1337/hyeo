#include "inc/tty.h"
#include "idt/isr.h"
extern "C" int _kmain(){
    isr_install();
    printf("Hello World from hyeo-i386!\n");
    //int b = (10 / 0);
    return -123;
}