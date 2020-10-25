/*
 ============================================================================
 Name        : print.c
 Author      : diaa abayazeed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
//Write a program in C to print a string in reverse using a pointer


int main(void) {

	char input[]="w3resource";
	char output[20];
	//char *pstr=input;
	char *prev=output;
	int size=sizeof(input)/sizeof(input[0]);
	size=size-2;
	for(int i=0;i<=size;i++){
		*prev=input[size-i];
		*prev++;
		if (i==9){
			*prev=*prev+1;
		    *prev=0;}
	}printf("the reverse sentence is: %s",output);

    return 0;
}
