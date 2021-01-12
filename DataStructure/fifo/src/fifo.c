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



//APIS
fifo_check_t init_fifo (fifo_buff_t *buff,element_tybe *buffer_array ){

	buff->count=0;
	buff->head=(uint8_t*)buffer_array;
	buff->base=(uint8_t*)buffer_array;
	buff->tail=(uint8_t*)buffer_array;
	buff->length=width;

	return fifo_no_error;
}

fifo_check_t enqueue_fifo (fifo_buff_t *buff,element_tybe element)
{
	if(!buff->base || !buff->head ||!buff->tail )
	{
		return fifo_null;
	}
	*(buff->head)=element;
	printf("\t the enqueue element is: %x \n",element);
	buff->count++;
	//fifo circular
	if(buff->head==(buff->base + (buff->length * sizeof(element_tybe))))
	{
		buff->head=buff->base;
		return fifo_full;
	}
	else
		buff->head++;

	return fifo_no_error;
}
fifo_check_t dequeue_fifo (fifo_buff_t *buff,element_tybe *element)
{
	if(!buff->base || !buff->head ||!buff->tail )
	{
		return fifo_null;
	}
	if(buff->count==0)
		return fifo_empty;
	*element=*(buff->tail);
	printf("\t the dequeue element is: %x \n",*element);
	buff->count--;
	//fifo circular
	if(buff->tail==(buff->base + (buff->length * sizeof(element_tybe))))
	{
		buff->tail=buff->base;
		return fifo_full;
	}
	else
		buff->tail++;

	return fifo_no_error;
}

