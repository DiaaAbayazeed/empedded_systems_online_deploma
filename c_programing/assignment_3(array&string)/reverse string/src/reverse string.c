/*
 ============================================================================
 Name        : reverse.c
 Author      : diaa abayazeed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int i=0,n=0,x=0;
	char text[100],reverse[100];
	printf("enter the string: ");
	fflush(stdout);  fflush(stdin);
	gets(text);
	fflush(stdin);
	x=strlen(text)-1;
	reverse[x+1]=0;
	for(i=x;i>=0;i--){
		reverse[n]=text[i];
		n+=1;
	}
	printf("the reverse is: %s",reverse);
	return 0;
}
