
/*
 ============================================================================
 Name        : calc.c
 Author      : diaa abayazeed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//calc power of number using recursive
#include <stdio.h>
#include <stdlib.h>
int p,b;
int power();
int main(void) {

	printf("enter the base number: ");
	fflush(stdout);  fflush(stdin);
	scanf("%d",&b);
	printf("enter the power number: ");
	fflush(stdout);  fflush(stdin);
	scanf("%d",&p);
	printf("calculation = %d",power());
	return 0;

}
//power function
int power(){
static int c=1;
	if(p>=1){
		c*=b;
		p--;
		power();
	}

	return c;
}
