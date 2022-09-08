#include "inc/stdio.h"
#include "inc/string.h"
#include "inc/hyeo.h"
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
        if(!strcmp(line, "clear")) clear();
        if(!strcmp(line, "author")){printf(
            "\n\nAuthor: %s", "[https://github.com/hyper1923/hyeo]"
        );}
        if(!strcmp(line, "help")){
            printf("\n \nCommands:\n \nhelp: %s\nauthor: %s\nclear: %s\nexit: %s\n "
            , "will show this", "will show the author", "will clear the screen", "will reboot the screen");
        }
        /*
        if(!strcmp(line, "sleep")) Sleep(100);
        TODO: Fix the bug.
        */
        if(!strcmp(line, "exit")) break;

        /*End of Shell Area*/



        /*Reinit Area*/
        clearLineCache();
        printf("\n");
    }
    exit(EXIT_SUCCESS);
}   