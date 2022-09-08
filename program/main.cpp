#include "inc/stdio.h"
#include "inc/string.h"
char line[128];

void clearLineCache(void){
    for(uint32_t i = 0; i < 128; i++) line[i] = 1;
}

extern "C" int _start(){
    /*Shell Init Area*/
    printf("Welcome to hyeoShell!\n");
    clearLineCache();
    while(true){

        /*Shell Area*/
        printf("root-hyeo > "); readLine(&line[0]);
        if(!strcmp(line, "reboot")) printf("\nRebooting...");
        if(!strcmp(line, "clear")) clear();
        if(!strcmp(line, "exit")) break;

        /*End of Shell Area*/



        /*Reinit Area*/
        clearLineCache();
        printf("\n");
    }
    exit(EXIT_SUCCESS);
}   