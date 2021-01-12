/*
 * fifo.h
 *
 *  Created on: Jan 8, 2021
 *      Author: Diaa Abayazeed
 */

#ifndef FIFO_H_
#define FIFO_H_
#include "stdint.h"
//user configuration
//use any typedef in stdint like (uint8_t ,uint16_t ,uint32_t ,......)
#define element_tybe uint8_t
//define the width of buffer
#define width 10
element_tybe buffer_array[width];


//structure of elment in buffer
typedef struct
{
	unsigned count;
	element_tybe *head ;
	element_tybe *base ;
	element_tybe *tail ;
	unsigned length;

}fifo_buff_t;

//fifo check
typedef enum
{
	fifo_no_error,
	fifo_full,
	fifo_empty,
	fifo_null,

}fifo_check_t;

//APIS
fifo_check_t init_fifo (fifo_buff_t *buff , element_tybe *buffer_array);
fifo_check_t enqueue_fifo (fifo_buff_t *buff,element_tybe element);
fifo_check_t dequeue_fifo (fifo_buff_t *buff,element_tybe *element);

#endif /* FIFO_H_ */
