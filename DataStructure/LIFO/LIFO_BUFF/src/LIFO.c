/*
 * LIFO.c
 *
 *  Created on: Jan 6, 2021
 *      Author: Diaa Abayazeed
 */
#include "stdint.h"
#include "LIFO.h"
#include <stdio.h>

//initiate the lifo buffer
void init_buff (LIFO_BUFF_t* buff_1,element_type *buffer ,element_type length)
{
	buff_1->count=0;
	buff_1->head=(element_type*)buffer;
	buff_1->base=(element_type*)buffer;
	buff_1->length=length;

}
//add data to the lifo buffer
LIFO_CHECK_t add_buff (LIFO_BUFF_t* buff_1, element_type element)
{

	//check if  buffer is full
	if(buff_1->count==buff_1->length)
		return buff_full;

	// add data to the lifo
	*(buff_1->head)=element;//put data in the head
	printf("\n===========================================================\n");
	printf("/t  %d /t ",*(buff_1->head));
	buff_1->head++;//increment head
	buff_1->count++;//increment count

	return no_error;
}
//pop data to the lifo buffer
LIFO_CHECK_t pop_buff (LIFO_BUFF_t* buff_1 ,element_type *element)
{


	//check if  buffer is empty
	if(buff_1->count==0)
		return empty;

	// decrement head
	buff_1->head--;
	buff_1->count--;//decrement count
	//pop data to the rest of buffer
	printf("\n===========================================================\n");
	*element =*(buff_1->head);//pop data
	printf("/t  %d /t ",*(element_type*)element);


	return no_error;

}
