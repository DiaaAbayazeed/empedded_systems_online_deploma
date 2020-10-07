/*
 ============================================================================
 Name        : ex4_number.c
 Author      : diaa abayazeed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int a;
	printf("enter number:\n ");
	fflush(stdout);
	fflush(stdin);
	scanf("%d ",&a);

	if (a>0)
	{
		printf("%d is positive \n",a);
	}
	else if (a<0)
	{
		printf("%d is negative \n",a);
	}
	else
	{
		printf("number is zero \n");
	}

	return 0;



}
