/*
 ============================================================================
 Name        : ex7_find.c
 Author      : diaa abayazeed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int factorial=1,i,n;
	printf("enter the number \n");
	fflush(stdout);
	fflush(stdin);
	scanf("%d",&n);
	if(n<0)
	{
		printf("erorr!!! factorial of negative number dosen't exsit");
	}
	else
	{
	for(i=n;n>0;n--)
	{
		factorial=factorial*n;

	}
	printf("factorial=%d",factorial);
	}

	return 0;

}
