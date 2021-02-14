/*
 * DataBase.c
 *
 *  Created on: Feb 7, 2021
 *      Author: Diaa Abayazeed
 */

#include "DataBase.h"

Data_info_t buff[100];
Data_check_t init_data_base ()//Initiate data
{
	int i;
	buff[0].roll=0;//Initiate roll number
	buff[0].GPA=0.0;//Initiate GPA
	for(i=0;i<100;i++)//Initiate all check of student to zero
		buff[i].check=0;

	return data_no_error;
}
Data_check_t add_student_from_file(int i){

	char fn[10],ln[10];//fn=first name  ln=last name
	//r=roll number  n=number to loop in cid  ci=course id   g=GPA
	int r,n,ci[10];float g;
	FILE *fptr;//make pointer to file address
	fptr = fopen("student.txt", "r");//open file
	if (fptr != NULL)//check if File created successfully
	{
		printf("File created successfully!\n");
	}
	else//check if file Failed to create
	{
		printf("Failed to create the file.\n");
		// exit status for OS that an error occured
		return data_null;
	}

	FSCANF(fptr,"%s",&fn);//scan data from the file
	strcpy(buff[i].fname,fn);//copy fname in data base
	FSCANF(fptr,"%s",&ln);
	strcpy(buff[i].lname,ln);//copy lname in data base
	FSCANF(fptr,"%d",&r);
	for(n=0;n<100;n++)//to make roll number unique
	{

		if(buff[n].roll==r)//if roll number found
		{
			DPRINTF("the roll number is exist \n");
			DPRINTF("the roll number is equal to 0 till you change it manually \n");
			r=0;
			break;
		}

	}
	buff[i].roll=r;
	FSCANF(fptr,"%f",&g);
	buff[i].GPA=g;

	for(n=0;n<10;n++){
		FSCANF(fptr,"%d",&ci[n]);
		buff[i].cid[n]=ci[n];
	}
	buff[i].check=1;
	fclose(fptr);
	printf("student added successfully!\n");

	return data_no_error;
}
Data_check_t add_student_manually(int i)//add student in array
{
	char temp[50],x;
	int z=0,y;
	DPRINTF("enter the first name :");
	gets (buff[i].fname);//get first name
	DPRINTF("enter the last name :");
	gets (buff[i].lname);//get last name
	DPRINTF("enter the roll number :");
	gets (temp);//get roll number
	for(y=0;y<100;y++)//to make roll number unique
	{
		if(buff[y].roll==atoi(temp))//if roll number found
		{
			DPRINTF("the roll number is exist \n");
			DPRINTF("enter the roll number :");
			gets (temp);//get roll number
			y=0;//to start from first roll number in list
		}

	}
	buff[i].roll=atoi(temp);//
	DPRINTF("enter the GPA :");
	gets (temp);//get GPA
	buff[i].GPA=atof(temp);
	DPRINTF("enter the course id :");
	gets (temp);//get course id
	buff[i].cid[z]=atoi(temp);
	buff[i].check=1;
	DPRINTF("if you want to enter new course enter 'y' else enter 'x' \n");//ask for add new course id
	scanf("%c",&x);//get new course id to add
	while(x =='y')
	{
		++z;
		DPRINTF("enter the course id :");
		gets (temp);//get course id
		buff[i].cid[z]=atoi(temp);DPRINTF("\n");
		DPRINTF("if you want to enter new course enter 'y' else enter 'x' \n");//ask again for add course id
		scanf("%c",&x);
		if (i>10)//check if array full
			return data_full;
	}

	return data_no_error;
}
Data_check_t print_student_data(Data_info_t *buff)// print data of student
{
	if(buff->check==0)
	{
		DPRINTF("the student not found \n");
		return data_null;
	}
	int i;
	DPRINTF("the first name is: %s\n",buff->fname);//print first name
	DPRINTF("the last name is: %s\n",buff->lname);//print last name
	DPRINTF("the roll number is: %d\n",buff->roll);//print roll number
	DPRINTF("the GPA is: %f\n",buff->GPA);//print GPA
	DPRINTF("the course id is: ");
	//loop for print all courses id that student joined
	for(i=0;i<10;i++){

		DPRINTF("%d\t",buff->cid[i]);
		/*if(buff->cid[i]==0)//if array element is free
			break;//terminate loop
		 */}
	DPRINTF("\n");

	return data_no_error;
}
Data_check_t find_student_by_roll()//find student by roll number
{
	DPRINTF("enter the roll number of student \n");
	int i=0;
	char temp[10];
	gets(temp);//get roll number
	while(i<100)//loop to find roll number
	{
		if(buff[i].roll==atoi(temp))//check roll number
		{
			print_student_data(&buff[i]);
			break;
		}
		++i;
		DPRINTF("student not found \n");

	}

	return data_no_error;

}

Data_check_t find_student_by_fname()
{
	DPRINTF("enter the first name of student \n");
	int i=0;
	char temp[10];
	gets(temp);
	while(i<100){

		if(strcmp(buff[i].fname,temp)==0)
		{
			print_student_data(&buff[i]);
			break;
		}
		++i;
	}

	return data_no_error;

}

Data_check_t find_student_by_course_register()
{
	DPRINTF("enter the course number \n");
	int i=0,x;
	char temp[10];
	gets(temp);
	while(i<100){
		x=0;
		if(buff[i].cid[x]==atoi(temp))
		{
			print_student_data(&buff[i]);
		}
		else
		{
			while(x<10)
			{
				if(buff[i].cid[x]==atoi(temp))
				{
					print_student_data(&buff[i]);
					break;
				}
				++x;
			}
		}
		++i;
	}

	return data_no_error;

}

void count_student(){

	int i=0,x=0;
	while(i<100)//loop to find number of student
	{
		if(buff[i].check==1)//check roll number
		{
			++x;
		}
		++i;

	}

	DPRINTF("the number of student in list is :%d \n",x);


}
void delete_student_by_roll_number(){

	int i=0,x=0;
	char temp[10];
	DPRINTF("enter the roll number of student that you want to deleted \n");
	gets(temp);
	while(i<100)//loop to find roll number
	{
		if(buff[i].roll==atoi(temp))//check roll number
		{
			buff[i].check=0;
			buff[i].roll=0;
			buff[i].GPA=0;
			while(x<10)
			{
				buff[i].cid[x]=0;
				x++;
			}
			break;
		}
		++i;
	}
	DPRINTF(".........the student is deleted.........\n");


}
Data_check_t update_student_by_roll()//update student by roll number
{
	DPRINTF("enter the roll number of student \n");
	int i=0;
	char temp[10];
	gets(temp);//get roll number
	while(i<100)//loop to find roll number
	{
		if(buff[i].roll==atoi(temp))//check roll number
		{
			DPRINTF(" 1-first name\n 2-last name\n 3-roll number\n 4-GPA\n");
			gets(temp);
			switch(atoi(temp))
			{
			case 1:
				DPRINTF("enter the new name:\t");
				gets(temp);
				strcpy(buff[i].fname,temp);
				break;
			case 2:
				DPRINTF("enter the new name:\t");
				gets(temp);
				strcpy(buff[i].lname,temp);
				break;
			case 3:
				DPRINTF("enter the new roll:\t");
				gets(temp);
				buff[i].roll=atoi(temp);
				break;
			case 4:
				DPRINTF("enter the new GPA:\t");
				gets(temp);
				buff[i].GPA=atof(temp);
				break;
			default:
				DPRINTF("wrong number\n");
				break;
			}
			print_student_data(&buff[i]);
			break;
		}
		++i;
	}

	return data_no_error;

}
