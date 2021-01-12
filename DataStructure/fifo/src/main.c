/*
 ============================================================================
 Name        : fifo.c
 Author      : Diaa AbaYazeed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "fifo.h"
int main(void) {
	fifo_buff_t buffer;
	element_tybe i;
	init_fifo (&buffer,(uint8_t*)buffer_array);
	printf("\n\n===================enqueue 5 element=======================\n\n");
	for(i=0;i<5;i++){
		if(!fifo_full || !fifo_null){
			printf("=========enqueue failed==========\n");
		}
		else{
			printf("=========enqueue done===========\n");
		}
		enqueue_fifo (&buffer,i);
	}
	printf("===========================================================\n");

	printf("\n\n=========dequeue 2 element===========\n\n");
	if(!fifo_empty || !fifo_null){
		printf("=========dequeue failed==========\n");
	}
	else{
		printf("=========dequeue done===========\n");
		dequeue_fifo (&buffer,&i);

	}
	if(!fifo_empty || !fifo_null){
		printf("=========dequeue failed=========\n");
	}
	else{
		printf("=========dequeue done===========\n");
		dequeue_fifo (&buffer,&i);

	}
	printf("===========================================================\n");

	printf("\n\n=========enqueue one element===========\n\n");
	if(!fifo_full || !fifo_null){
		printf("=========enqueue failed==========\n");
	}
	else{
		printf("=========enqueue done===========\n");
		i=9;
		enqueue_fifo (&buffer,i);
	}
	printf("===========================================================\n");
	printf("\n\n=========dequeue one element===========\n\n");

	if(!fifo_empty || !fifo_null){
		printf("=========dequeue failed=========\n");
	}
	else{
		printf("=========dequeue done===========\n");
		dequeue_fifo (&buffer,&i);

	}
	printf("===========================================================\n");
}
