/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
#include <stdint.h>

//RCC configuration
#define RCC_BASE 0x40021000
#define RCC_APB2ENR *(volatile uint32_t*)(RCC_BASE + 0x18)

//GPIO configuration
#define GPIOA_BASE 0x40010800
#define GPIOA_CRH  *(volatile uint32_t*)(GPIOA_BASE + 0x04)
#define GPIOA_ODR  *(volatile uint32_t*)(GPIOA_BASE + 0x0C)
#define GPIOA_CRL  *(volatile uint32_t*)(GPIOA_BASE + 0x00)
#define GPIOA_IDR  *(volatile uint32_t*)(GPIOA_BASE + 0x08)

#define GPIOB_BASE 0x40010C00
#define GPIOB_CRH  *(volatile uint32_t*)(GPIOB_BASE + 0x04)
#define GPIOB_ODR  *(volatile uint32_t*)(GPIOB_BASE + 0x0C)
#define GPIOB_CRL  *(volatile uint32_t*)(GPIOB_BASE + 0x00)
#define GPIOB_IDR  *(volatile uint32_t*)(GPIOB_BASE + 0x08)




void RCC_init(void)
{
	RCC_APB2ENR |= (1<<2) ;
	RCC_APB2ENR |= (1<<3) ;

}
void GPIO_init(void)
{

	GPIOA_CRL &= 0xfffffff0 ;
	GPIOA_CRL |= 0x00000002 ;
	GPIOA_CRH &= 0xff0fffff ;
	GPIOA_CRH |= 0x00200000 ;


	GPIOB_CRL &= 0xfffffff0 ;
	GPIOB_CRL |= 0x00000004 ;
	GPIOB_CRH &= 0xff0fffff ;
	GPIOB_CRH |= 0x00400000 ;

}


void LED_TOGGLE(void)
{
	if(((GPIOA_IDR & (1<<1))>>1) ==0)
	{
		GPIOB_ODR ^=(1<<1);
		while(((GPIOA_IDR & (1<<1))>>1) ==0);
	}

	if(((GPIOA_IDR & (1<<13))>>13) ==0)
	{
		GPIOB_ODR ^=(1<<13);
	}
}

void wait(int x){
	int y,z;
	for(y=0;y<z;y++)
		for(z=0;z<x;z++);

}


int main(void)
{
	/* Loop forever */
	RCC_init();
	GPIO_init();
	while(1){
		LED_TOGGLE();
		wait(100);
	}



}
