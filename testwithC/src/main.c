//
// Created by USER on 08-09-2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "../include/util.h"
#include "..\include\util.h"


int main(int argc,char** argv){
   
    if (argc <3){
        printf("more then 2 agruments are not allowed");
    }
    if (strcmp(argv[1],"run")==0){
        char* source = ReadAsciiFile(argv[2]);
        // printf("%c ,%d",source[1] ,strlen(source));
        for (int i = 0; i < strlen(source); i++)
        {
            printf("%c \n",source[i]);
        }
        
        free(source);
    }
    return 0;

};
