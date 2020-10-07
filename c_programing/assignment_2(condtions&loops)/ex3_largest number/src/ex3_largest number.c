/*
 ============================================================================
 Name        : ex3_largest.c
 Author      : diaa abayazeed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float a,b,c;
	printf("enter three number: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%f \r\n %f \r\n %f",&a,&b,&c);

	if (a>b){
		if (a>c)
			printf("the biggest number is :%f",a);

	}
	if (b>a){
		if (b>c)
			printf("the biggest number is :%f",b);

	}
	if (c>b){
		if (c>a)
			printf("the biggest number is :%f",c);

	}
	return 0;


}
