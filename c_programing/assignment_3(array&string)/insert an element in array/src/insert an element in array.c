/*
 ============================================================================
 Name        : insert.c
 Author      : diaa abayazeed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
//insert number in the array
int main(void) {
	int i,j,n,e;
	int a[100],b[100];
	printf("enter number of elements: ");
	fflush(stdout);  fflush(stdin);
	scanf("%d",&n);
	for(i=0;i<n;i++){
		a[i]=i+1;
		b[i]=i+1;
		printf("%d ",a[i]);
	}
	printf("\r\n enter location: ");
	fflush(stdout);  fflush(stdin);
	scanf("%d",&e);
	printf("\r\n enter the element to be insert: ");
	fflush(stdout);  fflush(stdin);
	scanf("%d",&j);
	//shift number in new array
	for (i=n-1;i>=e;i--){
		if(i==e-1)
			continue;
		b[i+1]=a[i];
	}
	//transpose number
	b[e]=j;
	for(i=0;i<n+1;i++){
		printf("%d ",b[i]);
	}
	return 0;
}
