/*
 * stm32f103c6_gpio.c
 *
 *  Created on: Jul 30, 2021
 *      Author: Diaa Abayazeed
 */

#include "stm32f103c6_gpio.h"
#include "stm32f103x6.h"
#include "utils.h"


/**================================================================
 * @Fn			-MCAL_GPIO_INIT
 * @brief 		-nit all registers in the peripheral of GPIO
 * @param[in]	-Gpio_configuration_t :to know the speed, mode & the number of mode
 * @param[in]	-GPIO_TypeDef 		  :to know the GPIO port and access register
 * @retval		-none
 * Note			-none
 */
void MCAL_GPIO_INIT (Gpio_configuration_t* PinConfig, GPIO_TypeDef* GPIOx )
{
	uint8_t temp_config; //works as a temp
	temp_config = 0;
	// configuration of input mode
	if( PinConfig->Gpio_PinMode == Gpio_Mode_Analog || PinConfig->Gpio_PinMode == Gpio_Mode_Input_F )
	{
		if (PinConfig->Gpio_PinNumber <= 7)
		{
			/* Set CNF[1:0] MODE[1:0] */
			temp_config = ((PinConfig->Gpio_PinMode ));
			/* Write on CRL or CRH */
			GPIOx->CRL &=~ ( (0xf) << (PinConfig->Gpio_PinNumber *4) ); //the register when it reset the data on it is 0x44444444
																		// so we should set the CNF &  MODE to 0x00
			GPIOx->CRL |= ( (temp_config) << (PinConfig->Gpio_PinNumber *4) ); //set the 4bit in CRL

		}
		else
		{
			/* Set CNF[1:0] MODE[1:0] */
			temp_config = ((PinConfig->Gpio_PinMode ));
			/* Write on CRL or CRH */
			GPIOx->CRH &=~ ( (0xf) << ((PinConfig->Gpio_PinNumber - 8) *4) ); //the register when it reset the data on it is 0x44444444
																			// so we should set the CNF &  MODE to 0x00
			GPIOx->CRH |= ( (temp_config) << ((PinConfig->Gpio_PinNumber - 8) *4) ); //set the 4bit in CRH

		}
	}
	else if(PinConfig->Gpio_PinMode == Gpio_Mode_Input_PD || PinConfig->Gpio_PinMode == Gpio_Mode_Input_PU)
	{
		// configuration to set Gpio_Mode_Input_PU
		if(PinConfig->Gpio_PinMode == Gpio_Mode_Input_PU)
		{
			GPIOx->ODR |= (1<< PinConfig->Gpio_PinNumber);
		}
		else
		{
			GPIOx->ODR &=~ (1<< PinConfig->Gpio_PinNumber);
		}
		if (PinConfig->Gpio_PinNumber <= 7)
		{
			/* Set CNF[1:0] MODE[1:0] */
			temp_config = ((PinConfig->Gpio_PinMode ));
			/* Write on CRL or CRH */
			GPIOx->CRL &=~ ( (0xf) << (PinConfig->Gpio_PinNumber *4) ); //the register when it reset the data on it is 0x44444444
																		// so we should set the CNF &  MODE to 0x00
			GPIOx->CRL |= ( (temp_config) << (PinConfig->Gpio_PinNumber *4) ); //set the 4bit in CRL
		}
		else
		{
			/* Set CNF[1:0] MODE[1:0] */
			temp_config = ((PinConfig->Gpio_PinMode ));
			/* Write on CRL or CRH */
			GPIOx->CRH &=~ ( (0xf) << ((PinConfig->Gpio_PinNumber - 8) *4) ); //the register when it reset the data on it is 0x44444444
																			// so we should set the CNF &  MODE to 0x00
			GPIOx->CRH |= ( (temp_config) << ((PinConfig->Gpio_PinNumber - 8) *4) ); //set the 4bit in CRH


		}
	}
	else if( PinConfig->Gpio_PinMode == Gpio_Mode_Output_AF_OD || PinConfig->Gpio_PinMode == Gpio_Mode_Output_AF_PP ||PinConfig->Gpio_PinMode == Gpio_Mode_Output_OD ||PinConfig->Gpio_PinMode == Gpio_Mode_Output_PP)
	{
		if (PinConfig->Gpio_PinNumber <= 7)
		{


			/* Set CNF[1:0] MODE[1:0] */
			temp_config = ( (((PinConfig->Gpio_PinMode - 0xC)) | (PinConfig->Gpio_PinSpeed)) & 0x0f );
			/* Write on CRL or CRH */
			GPIOx->CRL &=~ ( (0xf) << (PinConfig->Gpio_PinNumber *4) ); //the register when it reset the data on it is 0x44444444
																		// so we should set the CNF &  MODE to 0x00
			GPIOx->CRL |= ( (temp_config) << (PinConfig->Gpio_PinNumber *4) ); //set the 4bit in CRL

		}
		else
		{

			/* Set CNF[1:0] MODE[1:0] */
			temp_config = ( (((PinConfig->Gpio_PinMode - 0xC)) | (PinConfig->Gpio_PinSpeed)) & 0x0f );
			/* Write on CRL or CRH */
			GPIOx->CRH &=~ ( (0xf) << ((PinConfig->Gpio_PinNumber - 8) *4) ); //the register when it reset the data on it is 0x44444444
																			  // so we should set the CNF &  MODE to 0x00
			GPIOx->CRH |= ( (temp_config) << ((PinConfig->Gpio_PinNumber - 8) *4) ); //set the 4bit in CRL

		}

	}
}

/**================================================================
 * @Fn			-MCAL_GPIO_DeINIT
 * @brief 		-De initiate all registers in the peripheral of GPIO (rest GPIO)
 * @param[in]	-GPIO_TypeDef 		  :to know the GPIO port and access register
 * @retval		-none
 * Note			-none
 */
void MCAL_GPIO_DeINIT (GPIO_TypeDef* GPIOx )
{
	//IOPx RST: I/O port x reset
	//	Set and cleared by software.
	//	0: No effect
	//	1: Reset I/O port x

	if(GPIOx == GPIOA)
	{
		RCC->APB2RSTR |=(1<<2);
		RCC->APB2RSTR &=~(1<<2);

	}
	else if(GPIOx == GPIOB)
	{
		RCC->APB2RSTR |=(1<<3);
		RCC->APB2RSTR &=~(1<<3);
	}
	else if(GPIOx == GPIOC)
	{
		RCC->APB2RSTR |=(1<<4);
		RCC->APB2RSTR &=~(1<<4);
	}
	else if(GPIOx == GPIOD)
	{
		RCC->APB2RSTR |=(1<<5);
		RCC->APB2RSTR &=~(1<<5);
	}
	else if(GPIOx == GPIOE)
	{
		RCC->APB2RSTR |=(1<<6);
		RCC->APB2RSTR &=~(1<<6);
	}

}

/**================================================================
 * @Fn			-MCAL_GPIO_READ_PIN
 * @brief 		-read pin in GPIO port
 * @param[in]	-GPIO_TypeDef 		  :to know the GPIO port and access register
 * @param[in]	-Gpio_configuration_t :to know the speed, mode & the number of mode
 * @retval		-Input pin data from IDR register
 * Note			-none
 */
//Read APIS
uint8_t  MCAL_GPIO_READ_PIN (Gpio_configuration_t* PinConfig, GPIO_TypeDef* GPIOx )
{
	uint8_t  INPUT_DATA =0;
	// #define READBIT(reg,bit)    ((reg>>bit)&1)

	INPUT_DATA = READBIT(GPIOx->IDR,PinConfig->Gpio_PinNumber);

	return INPUT_DATA;
}

/**================================================================
 * @Fn			-MCAL_GPIO_READ_PORT
 * @brief 		-read pin in GPIO port
 * @param[in]	-GPIO_TypeDef 		  :to know the GPIO port and access register
 * @retval		-Input port data from IDR register
 * Note			-none
 */
uint16_t MCAL_GPIO_READ_PORT (GPIO_TypeDef* GPIOx )
{

	uint8_t  INPUT_DATA =0;

	INPUT_DATA = GPIOx->IDR ;

	return INPUT_DATA;
}


//***********Write APIS**************

/**================================================================
 * @Fn			-MCAL_GPIO_WRITE_PIN
 * @brief 		-Write value in GPIO pin
 * @param[in]	-GPIO_TypeDef 		  :to know the GPIO port and access register
 * @param[in]	-Gpio_configuration_t :to know the speed, mode & the number of mode
 * @param[in]	-Value                :pin value that will write in GPIO pin by ODR register
 * @retval		-none
 * Note			-none
 */
void  MCAL_GPIO_WRITE_PIN  (Gpio_configuration_t* PinConfig, GPIO_TypeDef* GPIOx ,uint8_t value )
{

	GPIOx->ODR |= (1<<PinConfig->Gpio_PinNumber);


}

/**================================================================
 * @Fn			-MCAL_GPIO_WRITE_PORT
 * @brief 		-Write value in GPIO port
 * @param[in]	-GPIO_TypeDef 		  :to know the GPIO port and access register
 * @param[in]	-PortValue            :port value that will write in GPIO port by ODR register
 * @retval		-none
 * Note			-none
 */
void  MCAL_GPIO_WRITE_PORT (GPIO_TypeDef* GPIOx ,uint8_t PortValue )
{

	GPIOx->ODR |= PortValue;
}

/**================================================================
 * @Fn			-MCAL_GPIO_TOOGLE_PIN
 * @brief 		-Toggle pin data in GPIO port
 * @param[in]	-GPIO_TypeDef 		  :to know the GPIO port and access register
 * @param[in]	-PortValue            :port value that will write in GPIO port by ODR register
 * @retval		-none
 * Note			-none
 */
void  MCAL_GPIO_TOOGLE_PIN  (Gpio_configuration_t* PinConfig, GPIO_TypeDef* GPIOx )
{
	// #define TOGGLEBIT(reg,bit)  (reg=reg ^(1<<bit))

	GPIOx->ODR ^=(1<<PinConfig->Gpio_PinNumber);


}

/**================================================================
 * @Fn			-MCAL_GPIO_LOCK_PIN
 * @brief 		-This register is used to lock the configuration of the port bits when a correct write sequence
 *				 is applied to bit 16 (LCKK). The value of bits [15:0] is used to lock the configuration of the
 *		       	GPIO. During the write sequence, the value of LCKR[15:0] must not change. When the
 *				LOCK sequence has been applied on a port bit it is no longer possible to modify the value of
 *				the port bit until the next reset.
 * @param[in]	-GPIO_TypeDef 		  :to know the GPIO port and access register
 * @param[in]	-PortValue            :port value that will write in GPIO port by ODR register
 * @retval		-none
 * Note			-LOCK key writing sequence:
 *					Write 1
 *					Write 0
 *					Write 1
 *					Read 0
 *					Read 1 (this read is optional but confirms that the lock is active)
 *				Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
 *				Any error in the lock sequence will abort the loc
 */
void  MCAL_GPIO_LOCK_PIN  (Gpio_configuration_t* PinConfig, GPIO_TypeDef* GPIOx )
{







}
