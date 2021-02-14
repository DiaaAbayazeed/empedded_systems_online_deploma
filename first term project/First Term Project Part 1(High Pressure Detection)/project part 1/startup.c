/*
 ============================================================================
 Name        : startup.c
 Author      : Diaa Mohamed Ahmed
 Version     : v1
 ============================================================================
 */

#include<stdint.h>

void Reset_Handler();
void NMI_Handler();
void H_fault_Handler();
void MM_Fault_Handler();
void Bus_Fault();
void Usage_Fault_Handler();


uint32_t vectors[] __attribute__((section(".vectors"))) = {
	
	(uint32_t) 0x20001000,
	(uint32_t) &Reset_Handler,
    (uint32_t) &NMI_Handler,
	(uint32_t) &H_fault_Handler,
	(uint32_t) &MM_Fault_Handler,
	(uint32_t) &Bus_Fault,
	(uint32_t) &Usage_Fault_Handler
};



void Reset_Handler(){
	
	main();
}
void NMI_Handler(){
	Reset_Handler();
}
void H_fault_Handler(){
	Reset_Handler();
}
void MM_Fault_Handler(){
	Reset_Handler();
}
void Bus_Fault(){
	Reset_Handler();
}
void Usage_Fault_Handler(){
	Reset_Handler();
}