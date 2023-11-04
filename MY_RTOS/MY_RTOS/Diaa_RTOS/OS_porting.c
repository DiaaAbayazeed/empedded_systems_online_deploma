/**
 ******************************************************************************
 * @file           : OS_porting.c
 * @author         : Diaa Mohamed
 * @brief          :
 * @Date           :24/10/2023
 ******************************************************************************
 */

#include "OS_porting.h"
void NMI_Handler()
{
	while(1)
	{
		__asm("nop");
	}
}
void HardFault_Handler()
{
	while(1)
	{
		__asm("nop");
	}
}
void	MemManage_Handler()
{
	while(1)
	{
		__asm("nop");
	}
}
void	BusFault_Handler()
{
	while(1)
	{
		__asm("nop");
	}
}
void	UsageFault_Handler()
{
	while(1)
	{
		__asm("nop");
	}
}

void HW_init()
{
	// change priority of PendSV to be equal SYStick to avoid two interrupt cut each
	// and to avoid to go back to each other  for example
	// >> SYStick handler   call PendSV
	// PendSV high priority and cut SYSTick when it finish it get back to SYStick
	// for this reasons I use this fun __NVIC_SetPriority
	__NVIC_SetPriority(PendSV_IRQn, 15);


}
__attribute ((naked)) void SVC_Handler()
{
	__asm("TST     LR,#4 \n\t "
			"ITE     EQ  \n\t"
			"MRSEQ   R0,MSP \n\t"
			"MRSNE   R0,PSP  \n\t"
			"b       OS_SVC_Handle");

}


void trigger_OS_PendSV()
{


	SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk ;



}
void Start_Ticker()
{


	//Fcpu = 8MHZ
	//Tick time 1/8=125 nsec
	//generate irq every 1ms
	// required 8000 tick

	SysTick_Config(8000);


}

void SysTick_Handler()
{
	Task_wait_handle();
	// determine next task
	Decide_WhatNextTask();
	// switch context
	trigger_OS_PendSV();


}

