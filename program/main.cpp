#include "inc/stdio.h"
#include "inc/string.h"
#include "inc/hyeo.h"
char line[128];

void clearLineCache(char* data, uint32_t size){
    for(uint32_t i = 0; i < size; i++) data[i] = 1;
}

void shell(){
    /*Shell Init Area*/
    printf("Welcome to hyeoShell!\n");
    clearLineCache(line,128);
    while(true){
        /*Shell Area*/
        printf("root-hyeo > "); readLine(&line[0]);
        if(!strcmp(line, "clear")) clear();
        if(!strcmp(line, "author")){printf(
            "\n \nAuthor: %s", "[https://github.com/hyper1923/hyeo]"
        );}
        if(!strcmp(line, "help")){
            printf("\n \nCommands:\n \nhelp: %s\nauthor: %s\nclear: %s\nexit: %s\n "
            , "will show this", "will show the author", "will clear the screen", "will reboot the screen");
        }
        if(!strcmp(line, "sleep")) Sleep(1000);
        if(!strcmp(line, "exit")) break;
        /*End of Shell Area*/


        if(!strcmp(line, "btime")){printf("\nSystem booted up for %d seconds", get_boot_seconds());}
        /*Reinit Area*/
        clearLineCache(line,128);
        printf("\n");
    }
}

void program(void){
    char name[32]; 
    char hobbies[128]; 
    clearLineCache(name,32);
    clearLineCache(hobbies,128);
    printf("Enter your name: "); readLine(&name[0]);printf("\n");
    printf("Hello, %s!\n", name);
    Sleep(1000);
    printf("Tell your hobbies: "); readLine(&hobbies[0]);printf("\n");
    printf("%s\n", hobbies);
    printf("Your hobbies really interesting things, bye!!\n");
}

extern "C" int _start(){
    shell();
    exit(1);
}   