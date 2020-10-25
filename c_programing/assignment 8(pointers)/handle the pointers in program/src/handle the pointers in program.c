/*
 ============================================================================
 Name        : handle.c
 Author      : diaa abayazeed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*Write a program in C to demonstrate how to handle the pointers
in the program.*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int x=5,y=10,z=15;
    int* px =&x;
    int* py =&y;
    int* pz =&z;
    printf("Address of m: ox%x \n Value of m :%d\n",px,x);
    printf("#########################################\n");
    printf("Address of m: ox%x \n Value of m :%d\n",py,y);
    printf("#########################################\n");
    printf("Address of m: ox%x \n Value of m :%d",pz,z);
    return 0;
}
