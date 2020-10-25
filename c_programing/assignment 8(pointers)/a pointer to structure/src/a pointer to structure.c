/*
 ============================================================================
 Name        : a.c
 Author      : diaa abayazeed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*Write a program in C to show a pointer to an array which contents
are pointer to structure.*/
#include <stdio.h>
#include <stdlib.h>
struct data {
	char name[10];
	int id;
};
int main(void) {
	struct data emploees[] ={
			{"diaa",1},{"mohamed",2},{"ahmed",3}
	};
	struct data* p;
	p=emploees;
	int i;
	for (i=0;i<=2;i++,++p){
	printf("name of the emploee:%s\n id of the emploee:%d\n",p->name,p->id);
	printf("########################################\n");
	}

	return 0;
}
