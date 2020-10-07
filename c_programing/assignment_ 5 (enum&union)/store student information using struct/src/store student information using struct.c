/*
 ============================================================================
 Name        : store.c
 Author      : diaa abayazeed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
struct Sstudent{
	int m_roll;
	char m_name[10];
	float m_mark;
};
void readInformation(struct Sstudent student[],int i){
	static int n=1;
	printf("enter name & mark in the order:");
	fflush(stdout);fflush(stdin);
	scanf("%s\n%f",&student[i].m_name,&student[i].m_mark);
	student[i].m_roll=n++;
	printf("\nroll= %d\nname= %s\nmark= %.2f",student[i].m_roll,&student[i].m_name,student[i].m_mark);
}
void displayInformation(struct Sstudent student[],int j)
{
static int n=1;
	student[j].m_roll=n++;
	printf("\nroll= %d\nname= %s\nmark= %.2f",student[j].m_roll,&student[j].m_name,student[j].m_mark);
}
int main(void) {
	int i,j;
	struct Sstudent student[3];
	for(i=0;i<3;i++){
		readInformation(student,i);
	}
	printf("\r\n");
	for(j=0;j<3;j++){
		displayInformation(student,j);
	}
	return 0;
}
