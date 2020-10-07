/*
 ============================================================================
 Name        : find.c
 Author      : diaa abayazeed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
int i,j,r,c;
int a[100][100],b[100][100];
printf("enter the number of rows and columnsof matrix: ");
fflush(stdout);    fflush(stdin);
scanf("%d",&r);   scanf("%d",&c);
printf("enter the element of matrix");
for(i=0;i<r;i++)
{ for(j=0;j<c;j++){
	printf("enter element a%d%d: ",i+1,j+1);
	fflush(stdout);    fflush(stdin);
    scanf("%d",&a[i][j]);

}}
for(i=0;i<r;i++)
{ for(j=0;j<c;j++){
	printf("%d\t\t",a[i][j]);
}
printf("\r\n");
}
printf("the transpose matrix is:\r\n");
for(i=0;i<c;i++)
{ for(j=0;j<r;j++){
	b[i][j]=a[j][i];
	printf("%d\t\t",b[i][j]);
	}
printf("\r\n");
}


return 0;








}
