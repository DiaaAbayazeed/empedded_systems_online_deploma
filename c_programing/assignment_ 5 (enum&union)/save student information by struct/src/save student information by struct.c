/*
 ============================================================================
 Name        : save.c
 Author      : diaa abayazeed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
//get and display student information using struct
struct student {
	char name[50];
	float roll;
	float mark;
};
int main(void) {
struct student x;
printf("enter information of student\n");
printf(" enter name: ");
fflush(stdout);fflush(stdin);
scanf("%s",&x.name);
printf(" enter the roll: ");
fflush(stdout);fflush(stdin);
scanf("%f",&x.roll);
printf(" enter the mark: ");
fflush(stdout);fflush(stdin);
scanf("%f",&x.mark);
printf("displaying information\n");
printf(" name: %s\n",x.name);
printf(" roll: %.2f\n",x.roll);
printf(" mark: %.2f",x.mark);
return 0;
}
