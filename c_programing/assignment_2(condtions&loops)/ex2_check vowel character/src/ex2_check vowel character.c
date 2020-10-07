/*
 ============================================================================
 Name        : ex2_check.c
 Author      : diaa abayazeed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char ch;

	printf("enter the character : ");
	fflush(stdout);
	fflush(stdin);

	scanf("%c",&ch);

	if(ch='a'||ch=='e'||ch=='o'||ch=='i'||ch=='u'||ch=='A'||ch=='E'||ch=='O'||ch=='I'||ch=='U')
		printf("charercter is vowel ");
	else
		printf("charecter is constant ");
	return 0;
}
