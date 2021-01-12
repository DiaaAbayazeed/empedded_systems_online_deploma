/*
 * linked_list.c
 *
 *  Created on: Jan 9, 2021
 *      Author: Diaa Abayazeed
 */

#include "linked_list.h"
struct sStudent* gpFirstStduent=NULL;

void add_stduent()
{
	struct sStudent* pNewStduent;
	struct sStudent* pLastStduent;


	if(gpFirstStduent==NULL)//when add first student data
	{
		pNewStduent=(struct sStudent*)malloc(sizeof(struct sStudent));
		gpFirstStduent=pNewStduent;
	}
	else
	{
		pLastStduent=gpFirstStduent;//start pointer of last student from first
		while(pLastStduent->pNextStduent)//navigate to the last student
			pLastStduent=pLastStduent->pNextStduent;

		pNewStduent=(struct sStudent*)malloc(sizeof(struct sStudent));//create new student
		pLastStduent->pNextStduent=pNewStduent;//point to new student//;//

	}

	char temp[40];
	DPRINTF("==========enter the student id===========\n");
	gets(temp);
	pNewStduent->student.ID=atoi(temp);

	DPRINTF("===============enter the student name============\n");
	gets (pNewStduent->student.name);

	DPRINTF("=================enter the student hight==========\n");
	gets(temp);
	pNewStduent->student.hight=atof(temp);

	pNewStduent->pNextStduent=NULL;//
}

void delete_stduent()
{
	char temp[20];
	DPRINTF("===============enter the id that you want to delete=================\n");
	gets(temp);
	struct sStudent* pDeleteStduent;
	struct sStudent* pPreviusStduent;
	pDeleteStduent=gpFirstStduent;
	pPreviusStduent=gpFirstStduent;
	while(pDeleteStduent)
	{
		if(pDeleteStduent->student.ID==atoi(temp))//check if the first ID is the deleted student
		{
			gpFirstStduent=pDeleteStduent->pNextStduent;//make the next student first
			free(pDeleteStduent);//delete student
		}
		else
		{		pPreviusStduent=pDeleteStduent;
				pDeleteStduent=pDeleteStduent->pNextStduent;//navigate delete student

			if(pDeleteStduent->student.ID==atoi(temp))
			{
				pPreviusStduent->pNextStduent=pDeleteStduent->pNextStduent;
				free(pDeleteStduent);
				break;
			}
		}

	}


}


void view_stduent()
{
	struct sStudent* pStduent;
	pStduent=gpFirstStduent;
	if(pStduent==NULL)
		DPRINTF("====empty list====\n");

	while(pStduent){
		DPRINTF("===============students============\n ");
		DPRINTF("=====student id: %d========\n ",pStduent->student.ID);
		DPRINTF("=====student name: %s========\n ",pStduent->student.name);
		DPRINTF("=====student hight: %f========\n ",pStduent->student.hight);
		pStduent=pStduent->pNextStduent;

	}
}

void delete_all_stduent()
{
	struct sStudent* pStduent=gpFirstStduent;
	if(gpFirstStduent==NULL)
		DPRINTF("====empty list====\n");

	while(pStduent->pNextStduent)
	{
		struct sStudent* pCurrentStduent=pStduent;
		pStduent=pStduent->pNextStduent;
		free(pCurrentStduent);
	}
	gpFirstStduent=NULL;
}

int lenght_list()//find the number of student
{
	struct sStudent* pLenghtList=gpFirstStduent;
	unsigned int count=0;
	while(pLenghtList->pNextStduent)//navigate to find length of list
	{
		pLenghtList=pLenghtList->pNextStduent;
		count++;
	}
	DPRINTF("=========== the number of student is: %d\n============",count+1);
	return count++;
}

void element_from_end()//find  student from end by two pointer(fast method)
{
	struct sStudent* pPreviusStudent=gpFirstStduent;
	struct sStudent* pStudent=gpFirstStduent;
	char temp[20];unsigned int i=0;
	DPRINTF("\n=====enter the number of element from end ======\n");//ask user to enter the number of student from end
	gets(temp);//get the number

	while(i<=atoi(temp))//pointer step number of elements from end times
	{
		pStudent=pStudent->pNextStduent;
		i++;
	}
	while(pStudent->pNextStduent)//navigate till end
	{
		pStudent=pStudent->pNextStduent;
		pPreviusStudent=pPreviusStudent->pNextStduent;
		if(pPreviusStudent==NULL)
			DPRINTF("====error: can't find student====\n");
	}//print the student data
	DPRINTF("===============student from end============\n ");
	DPRINTF("=====student id: %d========\n ",pPreviusStudent->student.ID);
	DPRINTF("=====student name: %s========\n ",pPreviusStudent->student.name);
	DPRINTF("=====student hieght: %f========\n ",pPreviusStudent->student.hight);
}

void middle_LinkedList()//find the middle of the list
{
	struct sStudent* pFast=gpFirstStduent;
	struct sStudent* pSlow=gpFirstStduent;
	while(pFast->pNextStduent)//tow pointer one step twice than another
	{

		pFast=pFast->pNextStduent;
		if(pFast->pNextStduent)
		{
			pSlow=pSlow->pNextStduent;
			pFast=pFast->pNextStduent;
		}
	}//print student data
	DPRINTF("===============student in the middle============\n ");
	DPRINTF("=====student id: %d========\n ",pSlow->student.ID);
	DPRINTF("=====student name: %s========\n ",pSlow->student.name);
	DPRINTF("=====student hieght: %f========\n ",pSlow->student.hight);

}
