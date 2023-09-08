//
// Created by USER on 08-09-2023.
//
#include "../include/util.h"
char* ReadAsciiFile(const char* path){
    FILE* file = fopen(path,"r");
    if(!file){
        printf("could not open file %s \n",path);
        return NULL;
    }
    fseek(file,0 ,SEEK_END);

    int size = ftell(file);
    fseek(file,0 ,SEEK_SET);
    char* buf= (char*) malloc(sizeof(char)* (size+1));
    fread(buf,1,size,file);
    buf[size]='\0';
    fclose(file);
    return buf;



};