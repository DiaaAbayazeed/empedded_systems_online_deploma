/*
 ============================================================================
 Name        : add.c
 Author      : diaa abayazeed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
//add two complex number using structure
struct Snum{
	float real;
	float imag;
};//read num by struct and return struct
struct Snum readnum(){
	struct Snum c;
	printf("enter real and imag in the order: ");
	fflush(stdout);fflush(stdin);
	scanf("%f  %f",&c.real,&c.imag);
	printf("real=%f\nimag=%f",c.real,c.imag);
	return c;
}//add num by struct
void addnum(struct Snum x,struct Snum y){
	float sum1=x.real+y.real;
	float sum2=(x.imag+y.imag);
	printf("\ntotal=%0.2f+(%0.2f)i",sum1,sum2);
}
int main(void) {
	struct Snum x,y;
	x=readnum();
	printf("\n");
	y=readnum();
	addnum(x,y);//print total
	return 0;
}
