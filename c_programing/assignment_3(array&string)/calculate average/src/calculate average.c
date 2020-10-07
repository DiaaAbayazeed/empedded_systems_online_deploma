/*
 ============================================================================
 Name        : sum.c
 Author      : diaa abayazeed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	/* the program takes n number of element and sum them */
	int n=0,i,sum=0;
	int a[100];
	printf("enter the number of data: ");
	fflush(stdout);  fflush(stdin);
	scanf("%d",&n);
	for (i=0;n<100;i++){
		printf("enter the number:");
		fflush(stdout);  fflush(stdin);
		scanf("%d",&a[i]);
		sum+=a[i];
		if(i+1==n)
			break;

	}printf("sum=%d",sum);

	return 0;
}
