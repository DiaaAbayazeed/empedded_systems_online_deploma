/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include "scheduler.h"
#include "string.h"
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


Task_ref Task1;
Task_ref Task2;
Task_ref Task3;

unsigned ToggleLedTask1;
unsigned ToggleLedTask2;
unsigned ToggleLedTask3;

void task1()
{
	while(1)
	{
		ToggleLedTask1 ^=1;
		__asm("nop");
	}


}
void task2()
{
	while(1)
	{
		ToggleLedTask2 ^=1;

		__asm("nop");
	}
}

void task3()
{
	while(1)
	{
		ToggleLedTask3 ^=1;
		MYRTOS_TaskWait(0xf, &Task3);
		__asm("nop");
	}
}
int main(void)
{
	HW_init();

	if( MYRTOS_init() != NoError )
	{
		while(1);
	}

	strcpy(Task1.TaskName ,"TASK A");
	Task1.Stack_Size=400;
	Task1.priority=5;
	Task1.p_TaskEntry=task1;


	strcpy(Task2.TaskName ,"TASK B");
	Task2.Stack_Size=400;
	Task2.priority=5;
	Task2.p_TaskEntry=task2;

	strcpy(Task3.TaskName ,"TASK C");
	Task3.Stack_Size=400;
	Task3.priority=3;
	Task3.p_TaskEntry=task3;

	if( MYRTOS_CreateTask(&Task1) != NoError )
	{
		while(1);
	}
	if( MYRTOS_CreateTask(&Task2) != NoError )
	{
		while(1);
	}
	if( MYRTOS_CreateTask(&Task3) != NoError )
	{
		while(1);
	}
	MYRTOS_ActivateTask (&Task1);
	MYRTOS_ActivateTask (&Task2);
	MYRTOS_ActivateTask (&Task3);

	MYRTOS_STARTOS();

	/* Loop forever */
	for(;;);
}
