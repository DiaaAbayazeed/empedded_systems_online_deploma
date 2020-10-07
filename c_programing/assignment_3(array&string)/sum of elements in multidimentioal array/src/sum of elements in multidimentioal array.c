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
	/* write c code to find sum of two matrix of order 2*2
	 * using multidimensional arrays where element of matrix entered by user  */
	int i,j;
	float a[2][2];
	float b[2][2];
	float matrix [2][2];
	printf("enter the elements of 1st matrix\r\n");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("enter a%d%d: ",i,j);
			fflush(stdout);  fflush(stdin);
			scanf("%f",&a[i][j]);
		}
	}
	printf("enter the elements of 2st matrix\r\n");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("enter a%d%d: ",i,j);
			fflush(stdout);  fflush(stdin);
			scanf("%f",&b[i][j]);
		}
	}
	printf("\r\n");
	printf("sum of the matrix:\r\n");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			matrix[i][j]=a[i][j]+b[i][j];
		}
	}
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("%f\t\t",matrix[i][j]);
			fflush(stdout);
		}printf("\r\n");
	}
	return 0;
}
