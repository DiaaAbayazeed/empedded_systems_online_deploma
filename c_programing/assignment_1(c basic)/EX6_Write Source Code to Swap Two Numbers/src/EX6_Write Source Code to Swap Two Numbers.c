/*
 ============================================================================
 Name        : EX6_Write.c
 Author      : diaa abayazeed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	float a,b;
	printf( "Enter value of a:");
	fflush(stdout);  fflush(stdin);
	scanf("%f",&a);
	printf( "Enter value of b:");
	fflush(stdout);  fflush(stdin);
	scanf("%f",&b);
	printf("After swapping, value of a = %f \n",b);
	printf("After swapping, value of b = %f",a);
	return 0;

}
