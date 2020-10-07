/*
 ============================================================================
 Name        : frequance.c
 Author      : diaa abayazeed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
int i,n=0; char c;
char text[100];
printf("enter the string: \r\n");
fflush(stdout);  fflush(stdin);
gets(text);
printf("enter the character: ");
fflush(stdout);  fflush(stdin);
scanf("%c",&c);
//count the frequancy
for(i=0;i<100;i++){
	if(text[i]==c)
		n+=1;
}
printf("the frequancy of character is %d",n);
return 0;
}
