/*
 ============================================================================
 Name        : reverse.c
 Author      : diaa abayazeed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//reverse sentence by recurseve
#include <stdio.h>
#include <stdlib.h>

void reverse(char names[],int i);
int main(void) {
	int i=0;
	char names[20];
	printf("enter sentense: ");
	fflush(stdout);  fflush(stdin);
	scanf("%s",names);
	i=strlen(names)-1;
	reverse(names,i);
	return 0;
}
//reverse function
void reverse(char names[],int i)
{
	int j=0;
	char lst[14];
	if (i>=0)
	{
		lst[j]=names[i];
		printf("%c",lst[j++]);
		reverse(names,--i);
	}
}
