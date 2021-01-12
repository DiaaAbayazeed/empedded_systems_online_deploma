/*
 * linked_list.h
 *
 *  Created on: Jan 9, 2021
 *      Author: Diaa Abayazeed
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_
#include <stdio.h>
#include <stdlib.h>
#include "stdint.h"
#include "string.h"
#include "conio.h"

#define DPRINTF(...)  {	fflush(stdout);\
	                    fflush(stdin);\
	                    printf(__VA_ARGS__);\
	                    fflush(stdout);\
	                    fflush(stdin);}

//main structure
typedef struct{
	unsigned int ID;
	unsigned char name[45];
	float hight ;
}sdata;

struct sStudent{

	 sdata student;
	 struct sStudent* pNextStduent;

};


//APIS

void add_stduent();
void delete_stduent();
void view_stduent();
void delete_all_stduent();
int lenght_list();
void element_from_end();
void middle_LinkedList();

#endif /* LINKED_LIST_H_ */
