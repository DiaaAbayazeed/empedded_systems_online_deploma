/*
 ============================================================================
 Name        : ex5_summing.c
 Author      : diaa abayazeed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int sum=0,i=0,n=0;
	printf("enter the number \n");
	fflush(stdout);
	fflush(stdin);
	scanf("%d",&n);
	for(i=n;n>=0;n--)
	{
		sum+=n;

	}
	printf("sum=%d",sum);
	return 0;

}
