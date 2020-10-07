/*
 ============================================================================
 Name        : ex4_Write.c
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
	float i ,j;
	printf("enter two number :");
	fflush(stdout);
	fflush(stdin);
	scanf("%f   %f",&i,&j);
	float sum=i+j;
	printf("the sum is =%d",sum);
	return 0;
}
