/*
 ============================================================================
 Name        : print.c
 Author      : diaa abayazeed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
//Write a program in C to print the elements of an array in reverse order.
int main(void) {

	int input[15], i,count=0;
	int *prev; prev=input;
	printf("enter elements that you want to reverse (max=15) : \n");
	fflush(stdout);
	printf("if you finsh entering enter 0:\n ");
	fflush(stdout);
	for (i=0;i<15;i++){
		fflush(stdin);
		scanf("%d",prev);
		if(*prev==0){
			break;
		}
		prev++;count++;
	}

	printf("the reverse elements is: ");

	for( i=count;i>0;i--){
		printf(" %d\t",*--prev);
		fflush(stdout);
	}
	return 0;
}
