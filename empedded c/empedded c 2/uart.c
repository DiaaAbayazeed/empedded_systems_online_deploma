#include"stdint.h"

#define UART0A *((volatile unsigned int*)((unsigned int*)0x101f10000 ))

void uart_send(unsigned char *arr){
	while(*arr!='\0'){
	UART0A=(unsigned int*)arr;
	arr++;	
	}
}