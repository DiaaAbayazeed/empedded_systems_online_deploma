#include "uart.h"

unsigned char arr[100]="LEARN_IN_DEPTH:<DIAA>";
void main (void){
	uart_send(arr);
		
}