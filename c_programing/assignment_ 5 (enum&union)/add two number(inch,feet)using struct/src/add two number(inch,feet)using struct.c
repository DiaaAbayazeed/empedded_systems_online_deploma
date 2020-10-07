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
//add two number in inch and feet using structure
struct Snum{
	float inch;
	float feet;
};//read num by struct and return struct
struct Snum readnum(){
	struct Snum c;
	printf("enter feet and inch in the order: ");
	fflush(stdout);fflush(stdin);
	scanf("%f  %f",&c.feet,&c.inch);
	printf("feet=%f\n inch=%f",c.feet,c.inch);
	return c;
}//add num by struct
float addnum(struct Snum x,struct Snum y){
	float sum1=x.feet+y.feet;
	float sum2=(x.inch+y.inch)/12;
	float total=sum1+sum2;
	return total;
}
int main(void) {
	struct Snum x,y;
	x=readnum();
	printf("\n");
	y=readnum();
	float z=addnum(x,y);//z is total
	printf("\r\n total = %f",z);
	return 0;
}
