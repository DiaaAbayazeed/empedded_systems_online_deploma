/*
 ============================================================================
 Name        : EX3Write.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int i ,j;
	printf("enter two number :");
	fflush(stdout);
	fflush(stdin);
	scanf("%d   %d",&i,&j);
	int sum=i+j;
	printf("the sum is =%d",sum);
	return 0;
}
