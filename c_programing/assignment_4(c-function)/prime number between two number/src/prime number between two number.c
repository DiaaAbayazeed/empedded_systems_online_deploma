/*
 ============================================================================
 Name        : prime.c
 Author      : diaa abayazeed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
//prime number between two intervals by making user-defined function
int y,z;
int prime(int x);
int main(void) {
	int i=0;
	printf("enter two number: ");
	fflush(stdout);  fflush(stdin);
	scanf("%d\r\n",&y);
	scanf("%d",&z);
	printf("prime number between %d and %d is : ",y,z);
	for(i=y;i<z;i++){
		prime(i);
	}
	return 0;
}
int prime(int x){
	int j=x;
	for(--j;j>1;j--){

		if(x%j==0){
			break;}
		else if(j==2){
			printf("%d\n",x);}
		else{
			continue;
	}}
	return 0;
}
