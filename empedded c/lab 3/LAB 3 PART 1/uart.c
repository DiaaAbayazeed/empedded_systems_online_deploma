#include "uart.h"
#define UART0A *((volatile unsigned int*)((unsigned int*)0x101f1000 ))

void uart_send(unsigned char* string_buffer){
	while(*string_buffer != '\0'){
	UART0A=(unsigned int)(*string_buffer);
	string_buffer++;	
	}
}