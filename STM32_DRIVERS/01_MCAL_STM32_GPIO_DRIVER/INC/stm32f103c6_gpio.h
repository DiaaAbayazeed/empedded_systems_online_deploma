/*
 * stm32f103c6_gpio.h
 *
 *  Created on: Jul 30, 2021
 *      Author: Diaa Abayazeed
 */

#ifndef INC_STM32F103C6_GPIO_H_
#define INC_STM32F103C6_GPIO_H_

//-----------------------------
//Includes
//-----------------------------

#include "stm32f103x6.h"

//===================================================================================================================


//-----------------------------
//User type definitions (structures)
//-----------------------------

typedef struct{

	uint16_t Gpio_PinNumber ;        // specifies the gpio pin number
	// this parameter can be avalue of @ref Gpio_pin_define

	uint8_t Gpio_PinMode ;   		// specifies the gpio pin mode
	// this parameter can be avalue of @ref Gpio_mode_define


	uint8_t Gpio_PinSpeed	 ;	    // specifies the gpio pin speed of output data
	// this parameter can be avalue of @ref Gpio_pin_speed_define
}Gpio_configuration_t;


//===================================================================================================================


//-----------------------------
//Macros Configuration References
//-----------------------------

// @ref Gpio_pin_define
//#define GPIO_PIN_0                ((uint16_t)0x0001)       /* Pin 0  is selected       */
//#define GPIO_PIN_1                ((uint16_t)0x0002)       /* Pin 1  is selected       */
//#define GPIO_PIN_2                ((uint16_t)0x0004)       /* Pin 2  is selected       */
//#define GPIO_PIN_3                ((uint16_t)0x0008)       /* Pin 3  is selected       */
//#define GPIO_PIN_4                ((uint16_t)0x0010)       /* Pin 4  is selected       */
//#define GPIO_PIN_5                ((uint16_t)0x0020)       /* Pin 5  is selected       */
//#define GPIO_PIN_6                ((uint16_t)0x0040)       /* Pin 6  is selected       */
//#define GPIO_PIN_7                ((uint16_t)0x0080)       /* Pin 7  is selected       */
//#define GPIO_PIN_8                ((uint16_t)0x0100)       /* Pin 8  is selected       */
//#define GPIO_PIN_9                ((uint16_t)0x0200)       /* Pin 9  is selected       */
//#define GPIO_PIN_10               ((uint16_t)0x0400)       /* Pin 10 is selected       */
//#define GPIO_PIN_11               ((uint16_t)0x0800)       /* Pin 11 is selected       */
//#define GPIO_PIN_12               ((uint16_t)0x1000)       /* Pin 12 is selected       */
//#define GPIO_PIN_13               ((uint16_t)0x2000)       /* Pin 13 is selected       */
//#define GPIO_PIN_14               ((uint16_t)0x4000)       /* Pin 14 is selected       */
//#define GPIO_PIN_15               ((uint16_t)0x8000)       /* Pin 15 is selected       */
//#define GPIO_PIN_ALL       		  ((uint16_t)0xFFFF)	   /* All pins are selected    */
//#define GPIO_PIN_MASK             0x0000FFFFu              /* Pin mask for assert test */

#define Gpio_Pin_Num_0       0
#define Gpio_Pin_Num_1       1
#define Gpio_Pin_Num_2       2
#define Gpio_Pin_Num_3       3
#define Gpio_Pin_Num_4       4
#define Gpio_Pin_Num_5       5
#define Gpio_Pin_Num_6       6
#define Gpio_Pin_Num_7       7
#define Gpio_Pin_Num_8       8
#define Gpio_Pin_Num_9       9
#define Gpio_Pin_Num_10       10
#define Gpio_Pin_Num_11       11
#define Gpio_Pin_Num_12       12
#define Gpio_Pin_Num_13       13
#define Gpio_Pin_Num_14       14
#define Gpio_Pin_Num_15       15


//@ref Gpio_mode_define
/*  Subject to the specific hardware characteristics of each I/O port listed in the datasheet, each
    port bit of the General Purpose IO (GPIO) Ports, can be individually configured by software
    in several modes:			*/

//1- Analog
//2- Input floating
//3- Input pull-up
//4- Input-pull-down
//5- Output push-pull
//6- Output open-drain
//7- Alternate function push-pull
//8- Alternate function open-drain

#define Gpio_Mode_Analog				0x00000000u
#define Gpio_Mode_Input_F				0x00000004u
#define Gpio_Mode_Input_PU				0x00000008u
#define Gpio_Mode_Input_PD				0x00000008u
#define Gpio_Mode_Output_PP				0x0000000Cu
#define Gpio_Mode_Output_OD				0x00000010u
#define Gpio_Mode_Output_AF_PP			0x00000014u
#define Gpio_Mode_Output_AF_OD			0x00000018u


//@ref Gpio_pin_speed_define
//These bits are written by software to configure the corresponding I/O port speed.
//Refer to Table 20: Port bit configuration table.
//00: Input mode (reset state)
//01: Output mode, max speed 10 MHz.
//10: Output mode, max speed 2 MHz.
//11: Output mode, max speed 50 MHz.

#define Gpio_Speed_10MHZ				0x00000001u
#define Gpio_Speed_2MHZ					0x00000002u
#define Gpio_Speed_50MHZ				0x00000003u

//===================================================================================================================

/* ===============================================
 * APIs Supported by "MCAL GPIO DRIVER"
 * ===============================================
 */

void MCAL_GPIO_INIT (Gpio_configuration_t* PinConfig, GPIO_TypeDef* GPIOx );
void MCAL_GPIO_DeINIT (GPIO_TypeDef* GPIOx );

//Read APIS
uint8_t  MCAL_GPIO_READ_PIN (Gpio_configuration_t* PinConfig, GPIO_TypeDef* GPIOx );
uint16_t MCAL_GPIO_READ_PORT (GPIO_TypeDef* GPIOx );

//Write APIS
void  MCAL_GPIO_WRITE_PIN  (Gpio_configuration_t* PinConfig, GPIO_TypeDef* GPIOx ,uint8_t value );
void  MCAL_GPIO_WRITE_PORT (GPIO_TypeDef* GPIOx ,uint8_t PortValue );

void  MCAL_GPIO_TOOGLE_PIN  (Gpio_configuration_t* PinConfig, GPIO_TypeDef* GPIOx );

void  MCAL_GPIO_LOCK_PIN  (Gpio_configuration_t* PinConfig, GPIO_TypeDef* GPIOx );


#endif /* INC_STM32F103C6_GPIO_H_ */
