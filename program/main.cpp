#include "inc/stdio.h"
#include "inc/string.h"
char line[128];

void clearLineCache(void){
    for(uint32_t i = 0; i < 128; i++) line[i] = 1;
}

extern "C" int _start(){
    printf("\n\nWelcome to hyeoShell!\n");
    clearLineCache();
    while(true){
        printf("\nroot-hyeo > "); readLine(&line[0]);
        if(!strcmp(line, "reboot")) printf("\nRebooting...");
        if(!strcmp(line, "clear")) clear();
        clearLineCache();
    }
    exit(EXIT_SUCCESS);
}   