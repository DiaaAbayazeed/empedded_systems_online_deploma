/*
 ============================================================================
 Name        : StudentDataBase.c
 Author      : Diaa AbaYazeed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include "DataBase.h"

int main(void) {
	int x=0;
	char temp[10];
	init_data_base ();
	DPRINTF("Welcome to student management system \n ");
	while(1){
		DPRINTF("============================================\n ");
		DPRINTF("1. add student details by file\n ");
		DPRINTF("2. add student details manually\n ");
		DPRINTF("3. find student details by roll number\n ");
		DPRINTF("4. find student details by first name\n ");
		DPRINTF("5. find student details by student course id\n ");
		DPRINTF("6. find total number of student in system\n ");
		DPRINTF("7. delete student\n ");
		DPRINTF("8. update student data\n ");
		DPRINTF("=============================================\n ");
		gets(temp);
		switch(atoi(temp))
		{
		case 1:
			add_student_from_file(x);
			if(!data_null)
				break;
			++x;
			break;
		case 2:
			add_student_manually(x);
			++x;
			break;
		case 3:
			find_student_by_roll();
			break;
		case 4:
			find_student_by_fname();
			break;
		case 5:
			find_student_by_course_register();
			break;
		case 6:
			count_student();
			break;
		case 7:
			delete_student_by_roll_number();
			break;
		case 8:
			update_student_by_roll();
			break;
		default:
			DPRINTF("wrong number\n");
			break;

		}
	}
	return 0;
}
