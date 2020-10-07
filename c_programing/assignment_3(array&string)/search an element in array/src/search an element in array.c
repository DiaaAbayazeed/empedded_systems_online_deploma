/*
 ============================================================================
 Name        : search.c
 Author      : diaa abayazeed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int i,n,s;
	int a[100];
	printf("enter number of elements: ");
	fflush(stdout);  fflush(stdin);
	scanf("%d",&n);
	for(i=0;i<n;i++){
		a[i]=i*11;
		printf("%d ",a[i]);
	}
	printf("enter the element to be searched: ");
	fflush(stdout);  fflush(stdin);
	scanf("%d",&s);

	for(i=0;i<n;i++)
	{
		if (a[i]==s)
		{
			printf("number found at the location :%d",i+1);
			break;
		}
		else
			continue;
	}
	return 0;
}
