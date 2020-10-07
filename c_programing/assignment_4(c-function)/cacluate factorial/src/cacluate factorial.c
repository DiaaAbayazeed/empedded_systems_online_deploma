/*
 ============================================================================
 Name        : cacluate.c
 Author      : diaa abayazeed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//calculate factorial of number
int factorial (int x);
int main(void) {
	int i;
	printf("enter an positive integer: ");
	fflush(stdout);  fflush(stdin);
	scanf("%d",&i);
	printf("factorial of %d = %d",i,factorial(i));
	return 0;
}
//factorial function
int factorial (int x){
	static int y=1;
	y*=x;
	if(x>1){
		x--;
		factorial(x);
	}
return y;
}
