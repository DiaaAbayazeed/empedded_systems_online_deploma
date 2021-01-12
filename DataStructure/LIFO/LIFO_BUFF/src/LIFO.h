/*
 * LIFO.h
 *
 *  Created on: Jan 6, 2021
 *      Author: Diaa Abayazeed
 */

#ifndef LIFO_H_
#define LIFO_H_
#include "stdint.h"
//choice the type of element like(uint8_t,uint16_t,uint32_t,.....)
#define element_type uint8_t
//define configuration
#define width  6


//define the main structure of lifo
typedef struct{
	unsigned int length;
	unsigned int count;
	element_type* base;
	element_type* head;

}LIFO_BUFF_t;
//to check lifo
typedef enum{
	no_error,
	buff_full,
	empty,
	null,
}LIFO_CHECK_t;

//APIS

void init_buff (LIFO_BUFF_t* buff_1, element_type *buffer,element_type length);//initiate the lifo buffer
LIFO_CHECK_t add_buff (LIFO_BUFF_t* buff_1, element_type element);//add data to the lifo buffer
LIFO_CHECK_t pop_buff (LIFO_BUFF_t* buff_1, element_type *element);//pop data to the lifo buffer



#endif /* LIFO_H_ */
