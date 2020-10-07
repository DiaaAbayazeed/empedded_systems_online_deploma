/*
 ============================================================================
 Name        : ex8_simple.c
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
	char ob;
	printf("enter operator like + or * or / or -\n");
	fflush(stdout);
	fflush(stdin);
	scanf("%c",&ob);
	printf("enter two number\n");
	fflush(stdout);
	fflush(stdin);
	scanf("%f",&a);
	scanf("%f",&b);
	if (ob=='+'){
		c=a+b;
		printf("%.2f+%.2f=%.2f",a,b,c);
	}
	else if (ob=='-'){
		c=a-b;
		printf("%.2f-%.2f=%.2f",a,b,c);
	}
	if (ob=='*'){
		c=a*b;
		printf("%.2f*%.2f=%.2f",a,b,c);
	}
	else if (ob=='/'){
		c=a/b;
		printf("%.2f/%.2f=%.2f",a,b,c);
	}
	return 0;
}
