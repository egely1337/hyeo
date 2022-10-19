#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <assert.h>



struct{
    char FILE_NAME[32];
    size_t FILE_SIZE;
    char* data;
} FILE_TABLE;

size_t get_file_size(const char *FP_NAME){
    size_t FS_SIZE;
    FILE* f = fopen(FP_NAME,"r");
    fseek(f,0,SEEK_END);
    FS_SIZE = ftell(f);
    fclose(f);
    return FS_SIZE;
}

char* get_file_data(const char *FP_NAME){
    unsigned FILE_SIZE = get_file_size(FP_NAME);
    char* fileData = (char*)malloc(FILE_SIZE);
    FILE* fp = fopen(FP_NAME, "r");
    fread(fileData, FILE_SIZE, 1, fp);
    fclose(fp);
    return fileData;
}

void add_file(unsigned int _argSize,...){
    va_list list;
    va_start(list,_argSize);
    FILE* fp = fopen("../iso_root/boot/hyeoFS.vfs", "w");
    fwrite("HFS",4,1,fp);
    unsigned int c = _argSize;
    fwrite(&c,4,1,fp);
    for(unsigned int i = 0; i < _argSize; i++){
        char* FILE_NAME = va_arg(list,char*);
        size_t FILE_SIZE = get_file_size(FILE_NAME);
        size_t calc = 24576/2 - FILE_SIZE;
        char* fs = (char*)malloc(calc);
        memset(fs,0,calc);
        char* data = get_file_data(FILE_NAME);
        printf("\nFILE NAME: %s\nFILE_SIZE: %d\n",FILE_NAME,FILE_SIZE);
        fwrite(FILE_NAME,32, 1,fp);
        fwrite(&FILE_SIZE,4,1,fp);
        fwrite(data,FILE_SIZE,1,fp);
        fwrite(fs,calc,1,fp);
    }
    va_end(list);
    fclose(fp);
}

int main(int argc, char** argv){
    assert(argc > 1); /* argc must be higher than 1 */
    if(argc == 2) add_file(1,argv[1]);
    if(argc == 3) add_file(2,argv[1],argv[2]);
    if(argc == 4) add_file(3,argv[1],argv[2],argv[3]);
    if(argc == 5) add_file(4,argv[1],argv[2],argv[3],argv[4],argv[5]);
    
}