/**************************************************************************//**
 * @file     : scheduler.h
 * @name     : Diaa MOhamed
 * @brief    :
 * @date     : 24/10/2023
 ******************************************************************************/

#ifndef		SCHEDULER_H
#define 	SCHEDULER_H

#include "OS_porting.h"

typedef enum{
	NoError,
	Ready_Queue_init_error,
	Task_exceeded_StackSize,
	MutexisReacedToMaxNumberOfUsers

}MYRTOS_errorID;


typedef struct{
	unsigned int Stack_Size;
	unsigned char priority;
	void (*p_TaskEntry)(void); //pointer to Tack C Function
	unsigned char AutoStart ;
	unsigned int _S_PSP_Task ;//Not Entered by the user
	unsigned int _E_PSP_Task ;//Not Entered by the user
	unsigned int* Current_PSP ;//Not Entered by the user
	char TaskName[30] ;
	enum{
		Suspend,
		Running,
		Waiting,
		ready
	}TaskState	;//Not Entered by the user
	struct{
		enum{
			Enable,
			Disable
		}Blocking;
		unsigned int Ticks_Count ;
	}TimingWaiting;
}Task_ref;

typedef struct {
	unsigned char* Ppayload;
	unsigned int   PayloadSize ;
	Task_ref* 	   CurrentTUser ;
	Task_ref* 	   NextTUser ;
	char 		   MutexName[30]  ;
} Mutex_ref;

#define element_type Task_ref*


//APIs
MYRTOS_errorID MYRTOS_init();
MYRTOS_errorID MYRTOS_CreateTask(Task_ref* Task);
void MYRTOS_ActivateTask (Task_ref* Tref);
void MYRTOS_TerminateTask (Task_ref* Tref);
void MYRTOS_STARTOS() ;
void MYRTOS_TaskWait(unsigned int NoTICKS,Task_ref* SelfTref);

#endif  /* SCHEDULER_H */
