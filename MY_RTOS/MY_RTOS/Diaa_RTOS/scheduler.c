/*
 * 	Name      : Diaa Mohamed
 *  File name : scheduler.c
 *
 *  Date      :24/10/2023
 *
 */

#include "FIFO_stack.h"
#include "scheduler.h"
#include "string.h"

typedef struct {
	Task_ref* OSTasks[100]; //Sch. Table
	unsigned int _S_MSP_Task ;
	unsigned int _E_MSP_Task ;
	unsigned int PSP_Task_Locator ;
	unsigned int NoOfActiveTasks ;
	Task_ref* CurrentTask ;
	Task_ref* NextTask ;
	enum{
		OSsuspend,
		OsRunning
	}OSmodeID;
}OS_Control;

typedef enum {
	SVC_Activatetask,
	SVC_terminateTask,
	SVC_TaskWaitingTime,
	SVC_AquireMutex,
	SVC_ReleaseMutex
}SVC_ID;

OS_Control OS_Control_schaduler;
FIFO_Buf_t Ready_queue;
Task_ref* QUeue_buff[100];
Task_ref Idle_task;


void  OS_IdeleTask()
{
	while(1)
	{
		__asm("WFE");

	}


}
void MYRTOS_init_mainStack()
{
	/* locate the size of main stack in 3072 byte*/
	OS_Control_schaduler._S_MSP_Task=(unsigned int)&_estack;
	OS_Control_schaduler._E_MSP_Task=( OS_Control_schaduler._S_MSP_Task - MainStackSize); // Stack size is 3072

	/* locate first PSP task after word from end of MSP task*/
	OS_Control_schaduler.PSP_Task_Locator =(OS_Control_schaduler._E_MSP_Task -8);

}

void MyRTOS_Create_TaskStack(Task_ref* Task)
{
	/*Task Frame
	 * ======
	 * XPSR
	 * PC (Next Task Instruction which should be Run)
	 * LR (return register which is saved in CPU while TASk1 running before TaskSwitching)
	 * r12
	 * r4
	 * r3
	 * r2
	 * r1
	 * r0
	 *====
	 *r5, r6 , r7 ,r8 ,r9, r10,r11 (Saved/Restore)Manual
	 */
	Task->Current_PSP = (unsigned int*)Task->_S_PSP_Task ;

	Task->Current_PSP-- ;
	*(Task->Current_PSP) = 0x01000000;         //DUMMY_XPSR should T =1 to avoid BUS fault;//0x01000000

	Task->Current_PSP-- ;
	*(Task->Current_PSP) = (unsigned int)Task->p_TaskEntry ; //PC

	Task->Current_PSP-- ;
	*(Task->Current_PSP)  = 0xFFFFFFFD ; //LR = 0xFFFFFFFD (EXC_RETURN)Return to thread with PSP

	for (int  j=0 ; j< 13 ; j++ )
	{
		Task->Current_PSP-- ;
		*(Task->Current_PSP)  = 0 ;

	}
}

/* create task */
MYRTOS_errorID MYRTOS_CreateTask(Task_ref* Task)
{
	MYRTOS_errorID error =NoError;
	//Create Its OWN PSP stack
	//	-				-
	//	- _S_PSP_Task	-
	//	-	Task Stack	-
	//	- _E_PSP_Task	-
	//	-				-
	//	- _eheap		-
	//	-				-
	//
	Task->_S_PSP_Task= OS_Control_schaduler.PSP_Task_Locator;
	Task->_E_PSP_Task= (Task->_S_PSP_Task - Task->Stack_Size);

	//Check task stack size exceeded the PSP stack to heap
	if((Task->_E_PSP_Task) < (unsigned int)(&(_eheap)))
		error = Task_exceeded_StackSize;

	// put 8 byte between stack and next stack
	//Aligned 8 Bytes spaces between Task PSP and other
	OS_Control_schaduler.PSP_Task_Locator= (Task->_E_PSP_Task - 8);

	//update sch Table
	OS_Control_schaduler.OSTasks[OS_Control_schaduler.NoOfActiveTasks]= Task ;
	OS_Control_schaduler.NoOfActiveTasks++ ;

	// task state suspend at init
	Task->TaskState =Suspend;

	//Initialize PSP Task Stack
	MyRTOS_Create_TaskStack(Task);

	return error;
}

MYRTOS_errorID MYRTOS_init()
{
	MYRTOS_errorID error = NoError;

	/* update os to suspend mode */
	OS_Control_schaduler.OSmodeID = OSsuspend;

	/* specify the main stack for OS */
	MYRTOS_init_mainStack();

	/* create OS Ready queue */
	if(FIFO_init(&Ready_queue, QUeue_buff, 100) != FIFO_NO_ERROR )
	{
		error =Ready_Queue_init_error;
	}

	/* Configure IDLE TASK  */
	strcpy(Idle_task.TaskName,"Idle task");
	Idle_task.priority =255;
	Idle_task.p_TaskEntry =&OS_IdeleTask;
	Idle_task.Stack_Size=400;
	Idle_task.TaskState= Suspend;

	MYRTOS_CreateTask(&Idle_task);

	return error;

}



/* OS generate interrupt with setting SVC handler*/
void OS_SVC_SET(SVC_ID ID)
{
	switch(ID)
	{
	case SVC_Activatetask:
		__asm("SVC  #0x00");
		break;
	case 	SVC_terminateTask:
		__asm("SVC  #0x01");
		break;
	case SVC_TaskWaitingTime:
		__asm("SVC  #0x02");
		break;
	case SVC_AquireMutex:
		__asm("SVC  #0x03");
		break;
	case SVC_ReleaseMutex:
		__asm("SVC  #0x04");
		break;
	default :
		__asm("SVC  #0x05");
		break;
	}

}


void BubbleSort()
{
	int i ,j,n;
	Task_ref* temp;
	n =OS_Control_schaduler.NoOfActiveTasks;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(OS_Control_schaduler.OSTasks[j]->priority > OS_Control_schaduler.OSTasks[j+1]->priority)
			{
				temp = OS_Control_schaduler.OSTasks[j+1];
				OS_Control_schaduler.OSTasks[j+1]=OS_Control_schaduler.OSTasks[j];
				OS_Control_schaduler.OSTasks[j]=temp;
			}
		}
	}
}

void MyRTOS_Update_Schadule_tables()
{
	Task_ref* item;
	Task_ref* PCurrentTask;
	Task_ref* PNextTask;
	int i=0;

	//1- bubble sort SchTable OS_Control-> OSTASKS[100] (priority high then low)
	BubbleSort();

	//2- free Ready Queue
	while(FIFO_dequeue(&Ready_queue, &item) != FIFO_EMPTY);


	//3- update ready queue
	while(OS_Control_schaduler.NoOfActiveTasks >= i)
	{
		PCurrentTask=OS_Control_schaduler.OSTasks[i];
		PNextTask=OS_Control_schaduler.OSTasks[i+1];
		// if we have only one task in the buffer and this task is on suspend state or new task in high priority
		if(PCurrentTask->TaskState != Suspend)
		{
			if(PNextTask->TaskState == Suspend)
			{
				PCurrentTask->TaskState =ready ;
				FIFO_enqueue(&Ready_queue, PCurrentTask);
				break;
			}

			// if we have only one highest priority task in waiting state
			if(PCurrentTask->priority < PNextTask->priority)
			{
				PCurrentTask->TaskState =ready ;
				FIFO_enqueue(&Ready_queue, PCurrentTask);
				break;
			}
			//if we have some tasks in the same priority in highest priority
			else if(PCurrentTask->priority == PNextTask->priority)
			{
				PCurrentTask->TaskState =ready ;
				FIFO_enqueue(&Ready_queue, PCurrentTask);
			}
		}
		i++;
	}

	//	while(i< OS_Control_schaduler.NoOfActiveTasks)
	//		{
	//
	//			PCurrentTask = OS_Control_schaduler.OSTasks[i] ;
	//			PNextTask = OS_Control_schaduler.OSTasks[i+1] ;
	//			if (PCurrentTask->TaskState != Suspend)
	//			{
	//				//in case we reached to the end of avaliable OSTASKS
	//				if (PNextTask->TaskState == Suspend)
	//				{
	//					FIFO_enqueue(&Ready_queue, PCurrentTask);
	//					PCurrentTask->TaskState = ready ;
	//					break ;
	//				}
	//				//	if the Ptask priority > nexttask then (lowest number is meaning higher priority)
	//				if (PCurrentTask->priority < PNextTask->priority )
	//				{
	//					FIFO_enqueue(&Ready_queue, PCurrentTask);
	//					PCurrentTask->TaskState = ready ;
	//					break ;
	//				}else if (PCurrentTask->priority == PNextTask->priority)
	//				{
	//					//	if the Ptask priority == nexttask then
	//					//		push Ptask to ready state
	//					//	And make the ptask = nexttask  and nexttask++
	//					FIFO_enqueue(&Ready_queue, PCurrentTask);
	//					PCurrentTask->TaskState = ready ;
	//				}else if (PCurrentTask->priority > PNextTask->priority)
	//				{
	//					//not allowed to happen as we already reordered it by bubble sort
	//					break ;
	//				}
	//			}
	//
	//
	//			i++ ;
	//		}

}




void MYRTOS_ActivateTask (Task_ref* Task)
{
	Task->TaskState = Waiting ;
	OS_SVC_SET(SVC_Activatetask);
}
void MYRTOS_TerminateTask (Task_ref* Task)
{

	Task->TaskState = Suspend ;
	OS_SVC_SET(SVC_terminateTask);


}
__attribute ((naked)) void PendSV_Handler()
{

	//====================================
	//Save the Context of the Current Task
	//====================================
	//Get the Current Task "Current PSP from CPU register" as CPU Push XPSR,.....,R0
	OS_GET_PSP(OS_Control_schaduler.CurrentTask->Current_PSP);

	//using this Current_PSP (Pointer) tp store (R4 to R11)
	OS_Control_schaduler.CurrentTask->Current_PSP--;
	__asm volatile("MOV %0,R4" : "=r"(*(OS_Control_schaduler.CurrentTask->Current_PSP)));
	OS_Control_schaduler.CurrentTask->Current_PSP--;
	__asm volatile("MOV %0,R5" : "=r"(*(OS_Control_schaduler.CurrentTask->Current_PSP)));
	OS_Control_schaduler.CurrentTask->Current_PSP--;
	__asm volatile("MOV %0,R6" : "=r"(*(OS_Control_schaduler.CurrentTask->Current_PSP)));
	OS_Control_schaduler.CurrentTask->Current_PSP--;
	__asm volatile("MOV %0,R7" : "=r"(*(OS_Control_schaduler.CurrentTask->Current_PSP)));
	OS_Control_schaduler.CurrentTask->Current_PSP--;
	__asm volatile("MOV %0,R8" : "=r"(*(OS_Control_schaduler.CurrentTask->Current_PSP)));
	OS_Control_schaduler.CurrentTask->Current_PSP--;
	__asm volatile("MOV %0,R9" : "=r"(*(OS_Control_schaduler.CurrentTask->Current_PSP)));
	OS_Control_schaduler.CurrentTask->Current_PSP--;
	__asm volatile("MOV %0,R10" : "=r"(*(OS_Control_schaduler.CurrentTask->Current_PSP)));
	OS_Control_schaduler.CurrentTask->Current_PSP--;
	__asm volatile("MOV %0,R11" : "=r"(*(OS_Control_schaduler.CurrentTask->Current_PSP)) );



	//save the current Value of PSP
	//already saved in Current_PSP



	//====================================
	//Restore the Context of the Next Task
	//====================================

	if (OS_Control_schaduler.NextTask != NULL)
	{
		OS_Control_schaduler.CurrentTask = OS_Control_schaduler.NextTask ;
		OS_Control_schaduler.NextTask = NULL ;
	}

	__asm volatile("mov r11,%0 " : : "r" (*(OS_Control_schaduler.CurrentTask->Current_PSP))  );
	OS_Control_schaduler.CurrentTask->Current_PSP++ ;
	__asm volatile("mov r10,%0 " : : "r" (*(OS_Control_schaduler.CurrentTask->Current_PSP))  );
	OS_Control_schaduler.CurrentTask->Current_PSP++ ;
	__asm volatile("mov r9,%0 " : : "r" (*(OS_Control_schaduler.CurrentTask->Current_PSP))  );
	OS_Control_schaduler.CurrentTask->Current_PSP++ ;
	__asm volatile("mov r8,%0 " : : "r" (*(OS_Control_schaduler.CurrentTask->Current_PSP))  );
	OS_Control_schaduler.CurrentTask->Current_PSP++ ;
	__asm volatile("mov r7,%0 " : : "r" (*(OS_Control_schaduler.CurrentTask->Current_PSP))  );
	OS_Control_schaduler.CurrentTask->Current_PSP++ ;
	__asm volatile("mov r6,%0 " : : "r" (*(OS_Control_schaduler.CurrentTask->Current_PSP))  );
	OS_Control_schaduler.CurrentTask->Current_PSP++ ;
	__asm volatile("mov r5,%0 " : : "r" (*(OS_Control_schaduler.CurrentTask->Current_PSP))  );
	OS_Control_schaduler.CurrentTask->Current_PSP++ ;
	__asm volatile("mov r4,%0 " : : "r" (*(OS_Control_schaduler.CurrentTask->Current_PSP))  );
	OS_Control_schaduler.CurrentTask->Current_PSP++ ;

	//update PSP and exit
	OS_SET_PSP(OS_Control_schaduler.CurrentTask->Current_PSP);
	__asm volatile("BX LR");

}

void Decide_WhatNextTask()
{


	//if Ready Queue is empty && OS_Control->currentTask != suspend
	//	if (Ready_queue.counter == 0 && OS_Control_schaduler.CurrentTask->TaskState != Suspend) //FIFO_EMPTY
	//	{
	//		// enqueue the current task to fifo
	//		FIFO_enqueue(&Ready_queue,OS_Control_schaduler.CurrentTask );
	//		OS_Control_schaduler.CurrentTask->TaskState=ready;
	//	}
	//
	//		// if we have only one task in the ready queue
	//		// dequeue task and send to running state
	//		FIFO_dequeue(&Ready_queue,&OS_Control_schaduler.CurrentTask);
	//		OS_Control_schaduler.CurrentTask->TaskState=Running;
	//
	//		if( (OS_Control_schaduler.CurrentTask->priority == OS_Control_schaduler.NextTask->priority) && (OS_Control_schaduler.CurrentTask->TaskState != Suspend) )
	//		{
	//			FIFO_enqueue(&Ready_queue,OS_Control_schaduler.CurrentTask);
	//			OS_Control_schaduler.CurrentTask->TaskState=Running;
	//
	//		}
	//if Ready Queue is empty && OS_Control->currentTask != suspend
	if (Ready_queue.counter == 0 && OS_Control_schaduler.CurrentTask->TaskState != Suspend) //FIFO_EMPTY
	{
		OS_Control_schaduler.CurrentTask->TaskState = Running ;
		//add the current task again(round robin)
		FIFO_enqueue(&Ready_queue, OS_Control_schaduler.CurrentTask);
		OS_Control_schaduler.NextTask = OS_Control_schaduler.CurrentTask ;
	}else
	{
		FIFO_dequeue(&Ready_queue, &OS_Control_schaduler.NextTask);
		OS_Control_schaduler.NextTask->TaskState = Running ;
		//update Ready queue (to keep round robin Algo. happen)
		if ((OS_Control_schaduler.CurrentTask->priority == OS_Control_schaduler.NextTask->priority )&&(OS_Control_schaduler.CurrentTask->TaskState != Suspend))
		{
			FIFO_enqueue(&Ready_queue, OS_Control_schaduler.CurrentTask);
			OS_Control_schaduler.CurrentTask->TaskState = ready ;
		}
	}
}


void  OS_SVC_Handle(int *Stack_frame)
{

	unsigned char SVC_val_num=*((unsigned char*)((Stack_frame[6])-2));
	switch(SVC_val_num)
	{
	case SVC_Activatetask:
	case SVC_terminateTask:
		//Update Sch Table, Ready Queue
		MyRTOS_Update_Schadule_tables();
		//OS is in Running State
		if (OS_Control_schaduler.OSmodeID == OsRunning)
		{
			if (strcmp(OS_Control_schaduler.CurrentTask->TaskName,"Idle task") != 0)
			{
				//Decide what Next
				Decide_WhatNextTask();

				//trigger OS_pendSV (Switch Context/Restore)
				trigger_OS_PendSV();
			}
		}
		break;
	case SVC_TaskWaitingTime:
		MyRTOS_Update_Schadule_tables();
		break;
	case SVC_AquireMutex:
		break;
	case SVC_ReleaseMutex:
		break;
	default :
		break;
	}

}


void MYRTOS_STARTOS()
{
	OS_Control_schaduler.OSmodeID = OsRunning ;
	//Set Default "Current Task =Idle Task"
	OS_Control_schaduler.CurrentTask = &Idle_task ;
	//Activate IDLE Task
	MYRTOS_ActivateTask(&Idle_task);
	//Start Ticker
	Start_Ticker(); // 1ms

	OS_SET_PSP(OS_Control_schaduler.CurrentTask->Current_PSP);
	//Switch Thread Mode SP from MSP to PSP
	OS_SWITCH_MSP_to_PSP;
	OS_CONVERT_to_unprivileged;
	Idle_task.p_TaskEntry();
}



void Task_wait_handle()
{

	int n=OS_Control_schaduler.NoOfActiveTasks;
	while(n--)
	{
		if(OS_Control_schaduler.OSTasks[n]->TaskState == Suspend)
		{
			if(OS_Control_schaduler.OSTasks[n]->TimingWaiting.Blocking == Enable)
			{
				if(--(OS_Control_schaduler.OSTasks[n]->TimingWaiting.Ticks_Count) == 0)
				{
					OS_Control_schaduler.OSTasks[n]->TimingWaiting.Blocking =Disable;
					OS_Control_schaduler.OSTasks[n]->TaskState =Waiting;
					OS_SVC_SET(SVC_TaskWaitingTime);
				}
			}
		}
	}

}


void MYRTOS_TaskWait(unsigned int NoTICKS,Task_ref* SelfTref)
{

	SelfTref->TimingWaiting.Blocking =Enable;
	SelfTref->TimingWaiting.Ticks_Count = NoTICKS;
	MYRTOS_TerminateTask(SelfTref);


}






