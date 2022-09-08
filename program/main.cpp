#include "inc/stdio.h"
int cursor = 0;
extern "C" int _start(){
    printf("Welcome to hyeoShell!");
    while(true){
        printf("root-hyeoUser$- ");print_char(readChar());
    }
    exit(EXIT_SUCCESS);
}   