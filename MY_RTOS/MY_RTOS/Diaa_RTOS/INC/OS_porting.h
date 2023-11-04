/**************************************************************************//**
 * @file     : OS_porting.h
 * @name     : Diaa MOhamed
 * @brief    :
 * @date     : 24/10/2023
 ******************************************************************************/

#ifndef 	OS_PORTING_H
#define 	OS_PORTING_H

#include "core_cm3.h"

extern int _estack ;
extern int _eheap  ;
extern int _ebss;
#define MainStackSize 	3072

#define OS_SET_PSP(add)    		 	__asm volatile("MOV  r0, %0  \n\t MSR  PSP, R0" ::"r"(add))
#define OS_GET_PSP(add) 			__asm volatile("MRS  r0,PSP  \n\t MOV  %0, R0"  : "=r"(add))

#define OS_SWITCH_MSP_to_PSP     	__asm volatile("MRS R0, CONTROL \n\t MOV R1, #2 \n\t ORR R0, R0, R1 \n\t  MSR CONTROL, R0")
#define OS_SWITCH_PSP_to_MSP		__asm volatile("MRS R0, CONTROL \n\t MOV R1, #5 \n\t AND R0, R0, R1 \n\t  MSR CONTROL, R0")

#define OS_CONVERT_to_unprivileged		__asm volatile("MRS R0, control\n\t ORR R0, R0,#0x1 \n\t MSR CONTROL, R0 ")
#define OS_CONVERT_to_privileged		__asm volatile("MRS R0, control \n\t LSR R0, R0, #1 \n\t LSL R0, R0, #1  \n\t MSR CONTROL, R0 ")


void trigger_OS_PendSV();
void Start_Ticker();

#endif  /* OS_PORTING_H */

