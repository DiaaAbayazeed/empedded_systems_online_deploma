/*
 ============================================================================
 Name        : the.c
 Author      : diaa abayazeed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char ch;
	printf("enter the character: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%c",&ch);
	if( ch>='a' && ch<='z' )
	{
		printf("the character is alphapet");
	}
	else if(ch>='A'&&ch<='Z')
	{
		printf("the character is alphapet");
		}
	else
	{
		printf("the character isn't alphapet");
	}
	return 0;

}
