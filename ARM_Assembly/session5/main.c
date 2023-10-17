/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Diaa
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "STM32F103x8.h"
#include "stm32f103x8_gpio_driver.h"
//#include "lcd.h"
//#include "keypad.h"
#include "stm32f103x8_EXTI_driver.h"
#include "stm32f103x8_USART_driver.h"
#include "stm32f103x8_SPI_driver.h"
#include "stm32f103x8_I2C_driver.h"
//#include "I2C_Slave_EEPROM.h"

#define  PSP_Start(s_PSP_TA)    		    __asm volatile("MSR PSP,%0" : : "r" (s_PSP_TA))
#define  MSP_to_PSP     			 		__asm volatile("MRS R0, CONTROL \n\t MOV R1, #2 \n\t ORR R0, R0, R1 \n\t  MSR CONTROL, R0")
#define  PSP_to_MSP						    __asm volatile("MRS R0, CONTROL \n\t MOV R1, #5 \n\t AND R0, R0, R1 \n\t  MSR CONTROL, R0")
#define  OS_generate_SW_interrupt     	    __asm volatile("SVC  #0x3")
#define  covert_to_unprivileged				__asm("MRS R0, control\n\t ORR R0, R0,#0x1 \n\t MSR CONTROL, R0 ")
#define  convert_to_privileged				__asm("MRS R0, control \n\t LSR R0, R0, #1 \n\t LSL R0, R0, #1  \n\t MSR CONTROL, R0 ")

//extern end of stack from linker script  _estack = ORIGIN(RAM) + LENGTH(RAM);
// end of "RAM" Ram type memory
extern unsigned int _estack;

unsigned int e_main_stack; // end of main stack

unsigned int s_process_stack_TA;  // start of process stack task A
unsigned int e_process_stack_TA;  // end of process stack task A

unsigned int s_process_stack_TB;  // start of process stack task B
unsigned int e_process_stack_TB;  // end of process stack task B


uint8_t IRQ_Flag = 0;
int Thread_val=11;
int Handler_val=10;

char Flag_Task_A ;
char Flag_Task_B ;


void SVC_Handler(void)
{
	convert_to_privileged;
}

char TASK_A(char a,char b ,char c)
{
	return a+b+c;

}

char TASK_B(char a,char b ,char c,char d)
{
	return a+b+c+d;

}
void EXTI9_CALLBACK(void)
{

	if(!IRQ_Flag)
	{
		Flag_Task_A=1;
		IRQ_Flag=1;
	}
	else
	{
		Flag_Task_B=1;
		IRQ_Flag=0;

	}
}

void OS_Scheduler ()
{

	unsigned int result=0;
	e_main_stack = &_estack - 512;

	//set word between MSP and PSP task A
	s_process_stack_TA = e_main_stack - 8;

	// store 64 byte to stack A into mem 100 -> 0x64
	e_process_stack_TA = s_process_stack_TA - 100 ;

	// set word between MSP and PSP task B
	s_process_stack_TB = e_process_stack_TA - 8;

	// store 64 byte to stack B into mem 100 -> 0x64
	e_process_stack_TB = s_process_stack_TB - 100 ;



	while(1)
	{

		if(Flag_Task_A)
		{
			// set PSP start address
			PSP_Start(s_process_stack_TA);
			//move SP from MSP to PSP
			MSP_to_PSP;
			//convert from privileged to unprivileged
			covert_to_unprivileged;

			result=TASK_A(1,2,3);
			// generate internal interrupt
			OS_generate_SW_interrupt;
			//move SP from PSP to MSP
			PSP_to_MSP;
			Flag_Task_A =0;
		}
		else if (Flag_Task_B)
		{
			// set PSP start address
			PSP_Start(s_process_stack_TB);
			//move SP from MSP to PSP
			MSP_to_PSP;
			//convert from privileged to unprivileged
			covert_to_unprivileged;

			result=TASK_B(1,2,3,4);
			// generate internal interrupt
			OS_generate_SW_interrupt;
			//move SP from PSP to MSP
			PSP_to_MSP;
			Flag_Task_B=0;

		}
	}

}


int main(void)
{
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();

	//Set EXTI Configuration
	EXTI_PinConfig_t EXTIConfig;
	EXTIConfig.EXTI_PIN = EXTI9PB9;
	EXTIConfig.Trigger_Case = EXTI_Trigger_RISING;
	EXTIConfig.P_IRQ_CallBack = EXTI9_CALLBACK;
	EXTIConfig.IRQ_EN = EXTI_IRQ_Enable;
	MCAL_EXTI_GPIO_Init(&EXTIConfig);

	//	switch_privilege_state(unprivileged);

	OS_Scheduler();



	IRQ_Flag = 1;

	while (1)
	{
		//		if(IRQ_Flag)
		//		{
		//			IRQ_Flag = 0;
		//		}
		//		else
		//		{
		//
		//			/* Misra */
		//
		//		}
	}


}
