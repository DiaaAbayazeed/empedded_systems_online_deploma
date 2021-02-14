/*
 * DataBase.h
 *
 *  Created on: Feb 7, 2021
 *      Author: Diaa Abayazeed
 */

#ifndef DATABASE_H_
#define DATABASE_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#define FSCANF(...)  {	fflush(stdin);\
		fflush(stdout);\
		fscanf(__VA_ARGS__);\
		fflush(stdin);\
		fflush(stdout);}
#define DPRINTF(...)  {	fflush(stdout);\
		fflush(stdin);\
		printf(__VA_ARGS__);\
		fflush(stdout);\
		fflush(stdin);}

//structure of element in buffer
typedef struct
{
	char fname[50];
	char lname[50];
	int roll;
	float GPA;
	int cid[10];
	int check;//if student check is equal to 0 the student is not found
}Data_info_t;

//fifo check
typedef enum
{
	data_no_error,
	data_full,
	data_empty,
	data_null,

}Data_check_t;

//APIS
Data_check_t init_data_base ();
Data_check_t add_student_from_file(int i);
Data_check_t print_student_data(Data_info_t *buff);
Data_check_t add_student_manually(int i);
Data_check_t find_student_by_roll();
Data_check_t find_student_by_fname();
Data_check_t find_student_by_course_register();
void count_student();
void delete_student_by_roll_number();
Data_check_t update_student_by_roll();


#endif /* DATABASE_H_ */
