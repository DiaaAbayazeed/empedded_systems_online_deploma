/*
 ============================================================================
 Name        : LIFO_BUFF.c
 Author      : Diaa Abayazeed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "stdint.h"
#include "LIFO.h"
void main(void) {
	LIFO_BUFF_t uart_send ;
	element_type j,i;
	element_type buffer[width];
	element_type L =6;
	init_buff (&uart_send ,&buffer,L);
	printf("\n===========================================================\n");
	printf("\n=========================add data==========================\n");
	for(j=0;j<=5;j++){

		add_buff (&uart_send,j);

	}
	printf("\n===========================================================\n");
	printf("\n=========================pop 3 data ========================\n");

	for(i=0;i<3;i++){

		pop_buff (&uart_send,&j);
	}
	printf("\n===========================================================\n");
	j=8;
	printf("\n=========================add j=8 ==========================\n");
	add_buff (&uart_send,j);
	printf("\n===========================================================\n");
	printf("\n=========================pop data==========================\n");
	pop_buff (&uart_send,&j);
	printf("\n===========================================================\n");
}
