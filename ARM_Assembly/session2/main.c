/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
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


 uint8_t IRQ_Flag = 0;
 int Thread_val=11;
 int Handler_val=10;

void EXTI9_CALLBACK(void)
{
	IRQ_Flag = 1;
	__asm("nop \n\t nop \n\t nop");
 //store PRIMASK value into Handler_val in handler mode
	__asm("MRS %0,PRIMASK"
			: "=r"(Handler_val)
			);


	__asm("nop \n\t nop \n\t nop");
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


	__asm("nop \n\t nop \n\t nop");
 //store PRIMASK value into Thread_val in thread mode

	__asm("MRS %0,PRIMASK"
			: "=r"(Thread_val)
			);


	__asm("nop \n\t nop \n\t nop");



	IRQ_Flag = 1;

	while (1)
	{
		if(IRQ_Flag)
		{
			IRQ_Flag = 0;
		}
		else
		{

			/* Misra */

		}
	}


}
