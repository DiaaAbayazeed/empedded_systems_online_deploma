/*
 * stm32f103x6.h
 *
 *  Created on: Jul 30, 2021
 *      Author: Diaa Abayazeed
 */

#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_

//-----------------------------
//Includes
//-----------------------------

#include "stdlib.h"
#include <stdint.h>

//============================================================================================

//-----------------------------
//Base addresses for Memories
//-----------------------------

#define	Flash_Memory_base			   0x08000000UL
#define CortexM3_Peripheral_base       0xE0000000UL


//==============================================================================================

//-----------------------------
//Base addresses for BUS Peripherals
//-----------------------------


//----AHB---
#define	Flash_memory_interface_base 	0x40022000UL
#define	RCC_base 						0x40021000UL


//---APB2---
#define	GPIOA_base 						0x40010800UL
#define	GPIOB_base 						0x40010C00UL
#define	GPIOC_base 						0x40011000UL
#define	GPIOD_base 						0x40011400UL
#define	GPIOE_base 						0x40011800UL
#define	AFIO_base 						0x40010000UL
#define	EXIT_base 						0x40010400UL

//---APB1---



//==============================================================================================

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:
//-*-*-*-*-*-*-*-*-*-*-*

//*******GPIO_TypeDef************

typedef struct{

	volatile uint32_t 		CRL;
	volatile uint32_t 		CRH;
	volatile uint32_t 		IDR;
	volatile uint32_t 		ODR;
	volatile uint32_t 		BSRR;
	volatile uint32_t 		BRR;
	volatile uint32_t 		LCKR;

}GPIO_TypeDef;

//*******************************

//*******AFIO_TypeDef************

typedef struct{

	volatile uint32_t 		EVCR;
	volatile uint32_t 		MAPR_density_devices;
	volatile uint32_t 		EXTICR1;
	volatile uint32_t 		EXTICR2;
	volatile uint32_t 		EXTICR3;
	volatile uint32_t 		EXTICR4;
	volatile uint32_t 		MAPR_2;

}AFIO_TypeDef;

//*******************************

//*******EXIT_TypeDef************

typedef struct{

	volatile uint32_t 		IMR;
	volatile uint32_t 		EMR;
	volatile uint32_t 		RTSR;
	volatile uint32_t 		FTSR;
	volatile uint32_t 		SWIER;
	volatile uint32_t 		PR;

}EXIT_TypeDef;

//*******************************

//*******RCC_TypeDef************

typedef struct{

	volatile uint32_t 		CR;
	volatile uint32_t 		CFGR;
	volatile uint32_t 		CIR;
	volatile uint32_t 		APB2RSTR;
	volatile uint32_t 		APB1RSTR;
	volatile uint32_t 		AHBENR;
	volatile uint32_t 		APB2ENR;
	volatile uint32_t 		APB1ENR;
	volatile uint32_t 		BDCR;
	volatile uint32_t 		CSR;
	volatile uint32_t 		AHBSTR;
	volatile uint32_t 		CFGR2;

}RCC_TypeDef;

//*******************************


//==============================================================================================

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*

#define GPIOA    			((GPIO_TypeDef *)GPIOA_base)
#define GPIOB    			((GPIO_TypeDef *)GPIOB_base)
#define GPIOC    			((GPIO_TypeDef *)GPIOC_base)
#define GPIOD    			((GPIO_TypeDef *)GPIOD_base)
#define GPIOE    			((GPIO_TypeDef *)GPIOE_base)

#define RCC					((RCC_TypeDef *)RCC_base)
#define EXIT				((EXIT_Type_Def *)EXIT_base)
#define AFIO				((AFIO_Type_Def *)AFIO_base)




//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#define RCC_GPIOA_CLK_EN   (RCC->APB2ENR |= 1<<2;)
#define RCC_GPIOB_CLK_EN   (RCC->APB2ENR |= 1<<3;)
#define RCC_GPIOC_CLK_EN   (RCC->APB2ENR |= 1<<4;)
#define RCC_GPIOD_CLK_EN   (RCC->APB2ENR |= 1<<5;)
#define RCC_GPIOE_CLK_EN   (RCC->APB2ENR |= 1<<6;)

#define RCC_AFIO_CLK_EN    (RCC->APB2ENR |= 1<<0;)



//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*


#endif /* INC_STM32F103X6_H_ */
