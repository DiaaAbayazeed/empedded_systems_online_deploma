/*
 ============================================================================
 Name        : alphabets.c
 Author      : diaa abayazeed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*Write a program in C to print all the alphabets using a pointer*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=65;
    int *pi=&i;
    do
    {
        printf("%c \t",*pi);
        *pi=*pi+1;
        if (*pi==80)
        printf("\n");
    }
    while(*pi<=90);
    return 0;
}
