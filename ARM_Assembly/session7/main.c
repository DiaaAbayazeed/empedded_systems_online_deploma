/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Diaa Mohamed
 * @brief          : Main program body
 ******************************************************************************
 */

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "core_cm3.h"
#include "STM32F103x8.h"
#include "stm32f103x8_gpio_driver.h"
#include "stm32f103x8_EXTI_driver.h"
#include "stm32f103x8_USART_driver.h"
#include "stm32f103x8_SPI_driver.h"
#include "stm32f103x8_I2C_driver.h"

// Declare a global variable to store the result of arithmetic operations
int result;

// Define a function to perform arithmetic operations based on the SVC number
void SVC_num_find(int *Stack_frame)
{
    // Extract values from the stack frame
    unsigned int R0_val = Stack_frame[0];
    unsigned int R1_val = Stack_frame[1];

    // Get the SVC number from the stack frame
    unsigned char SVC_val_num = *((unsigned char*)((Stack_frame[6]) - 2));

    // Perform the corresponding arithmetic operation based on SVC number
    switch (SVC_val_num)
    {
    case 1: // Add
        result = R0_val + R1_val;
        break;
    case 2: // Subtract
        result = R0_val - R1_val;
        break;
    case 3: // Multiply
        result = R0_val * R1_val;
        break;
    }
}

// Define an SVC handler function (assembly language)
// This function checks the stack used (MSP or PSP) and then calls SVC_num_find
__attribute ((naked)) void SVC_Handler()
{
    __asm("TST     LR, #4 \n\t "
          "ITE     EQ  \n\t"
          "MRSEQ   R0, MSP \n\t"
          "MRSNE   R0, PSP  \n\t"
          "B       SVC_num_find");
}

// Function to invoke an SVC call with provided operands and an SVC_ID
int OS_SVC_SET(int a, int b, int SVC_ID)
{
    int SVC_ID_result = 0;

    switch (SVC_ID)
    {
    case 1: // Add
        __asm("SVC  #0x1"); // Generate a software interrupt for addition
        break;
    case 2: // Subtract
        __asm("SVC  #0x2"); // Generate a software interrupt for subtraction
        break;
    case 3: // Multiply
        __asm("SVC  #0x3"); // Generate a software interrupt for multiplication
        break;
    }

    return SVC_ID_result;
}

int main(void)
{
    // Invoke OS_SVC_SET to perform addition (SVC_ID = 1), subtraction (SVC_ID = 2), and multiplication (SVC_ID = 3)
    OS_SVC_SET(4, 4, 1); // Add 4 + 4
    OS_SVC_SET(4, 4, 2); // Subtract 4 - 4
    OS_SVC_SET(4, 4, 3); // Multiply 4 * 4

    while (1)
    {
        __asm("nop"); // Infinite loop to keep the program running
    }
}
