/*
 ============================================================================
 Name        : ex1_known.c
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
	printf("enter an integer number: ");
	scanf("%d  ",&a);
	if (a%2!=0 )
		printf("%d is odd: ",a);
	else
		printf("%d is even: ",a);
	return 0;

}
