#include "../../stdio/stdio.h"
#include "../../stdio/string.h"
#include "../../stdio/hyeo.h"

extern "C" int _start(){
    char line[128];
    memset(&line[0],1,128);
    printf("Hi, what is your name?: ");readLine((char*)&line[0]);
    printf(
        " \n%s nice name, welcome hyeo. have fun!" \
        , line
    );
    exit(1);
}    
