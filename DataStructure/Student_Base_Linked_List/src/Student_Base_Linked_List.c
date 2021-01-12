/*
 ============================================================================
 Name        : Student_Base_Linked_List.c
 Author      : Diaa AbaYazeed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"


void main(void) {
	char x[10];
	while(1)
	{
		DPRINTF("*****************************************\n");
		DPRINTF("========enter the number of options======\n");
		DPRINTF("========1- add student===================\n");
		DPRINTF("========2- delete student================\n");
		DPRINTF("========3- view student==================\n");
		DPRINTF("========4- delete all student============\n");
		DPRINTF("========5- number of all student=========\n");
		DPRINTF("========6- student from the end==========\n");
		DPRINTF("========7- the middle student in the list\n");
		DPRINTF("*****************************************\n");
		gets(x);

		switch(atoi(x))
		{
		case 1:
			add_stduent();
			break;
		case 2:
			delete_stduent();
			break;
		case 3:
			view_stduent();
			break;
		case 4:
			delete_all_stduent();
			break;
		case 5:
			lenght_list();
			break;
		case 6:
			element_from_end();
			break;
		case 7:
			middle_LinkedList();
			break;
		default:
			DPRINTF("\n============wrong choice==========\n");
			break;
		}
	}

}
