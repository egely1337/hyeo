#include "inc/stdio.h"
extern "C" int _start(){
    int i = 0;
    while (i < 100)
    {
        printf("i: %d\n", i);
        i++;
    }

    exit(EXIT_SUCCESS);
}   