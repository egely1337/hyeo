#include "../../stdio/stdio.h"
#include "../../stdio/string.h"
#include "../../stdio/hyeo.h"


#define PROGRAM_SPACE (void*)0x60000

const char* helloWorld = "H1e1l1l1o1 1W1o1r1l1d1!1";
char line[128];
void clearLineCache(char* data, uint32_t size){
    for(uint32_t i = 0; i < size; i++) data[i] = 1;
} 

  
void shell(){
    /*Shell Init Area*/
    clearLineCache(line,128);
    while(true){
        FILE_TABLE* fp = open("app32/program.bin");
        /*Shell Area*/
        printf("root-hyeo > "); readLine(&line[0]);
        if(!strcmp(line, "clear") || !strcmp(line,"cls")) clear();
        if(!strcmp(line, "author")){printf(
            "Author: %s\n", "[https://github.com/hyper1923/hyeo]"
        );}
        if(!strcmp(line, "help")){
            printf(" \nCommands:\n \nhelp: %s\nauthor: %s\nclear: %s\nexit: %s\nbtime: %s\nsleep: %s\nhfs status: %s\n \n"
            , "will show this", "will show the author", "will clear the screen", "will reboot the screen"
            , "will show boot time", "will sleep your OS for one second", "will show hyeo-fs status");
        }
        if(!strcmp(line, "sleep")) Sleep(1000);
        if(!strcmp(line, "exit")) break;
        if(!strcmp(line, "panic")) crash();
        if(!strcmp(line,"hfs status")) {
            printf(" \nTotal files on HFS: %d\n \n", get_hfs_data()->fileCount);
            for(uint32_t i = 0; i < get_hfs_data()->fileCount; i++){
                printf("File: %s | Size: %d\n", (char*)get_first_table()[i].FILE_NAME, get_first_table()[i].FILE_SIZE);
            }
            printf(" \n \n");
        }
        if(!strcmp(line, "btime")){printf("System booted up for %d seconds\n", get_boot_seconds());}
        if(!strcmp(line,"test")){FILE_TABLE* fp = open("sys/lorem_ipsum.txt"); printf("%s\n", fp->data);}
        if(!strcmp(line,"panik")){
            memset((void*)0x1000, 0, 0x8000);
        }
        /*End of Shell Area*/

        for(uint32_t i = 0; i < get_hfs_data()->fileCount; i++){
            if(!strcmp(get_first_table()[i].FILE_NAME,line)){
                    memcpy(PROGRAM_SPACE,get_first_table()[i].data,get_first_table()[i].FILE_SIZE);
                   asm volatile("call *%0" :: "r"(get_first_table()[i].data));
            }
        }
        
        /*Reinit Area*/
        clearLineCache(line,128);
    }
}

extern "C" int _start(){
    printf(" \nWelcome to hyeoOS!\n \n \n");  
    shell();
    exit(1);
}    
