/*
 ============================================================================
 Name        : EX5_Write.c
 Author      : diaa abayazeed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char c;
	printf("enter a character :");
	fflush(stdout);  fflush(stdin);
	scanf(" %c",&c);
	printf("ASCII value of %c= %d",c,c);
	return 0;

}
