/*
 ******************************************************************************
 * @file           : FIFO_satck.h
 * @author         : Diaa Mohamed
 * @brief          :
 * @Date           :24/10/2023
 ******************************************************************************
 */

#ifndef 	FIFO_STACK_H
#define 	FIFO_STACK_H

#include "stdio.h"
#include "stdint.h"
#include "scheduler.h"

/*customer can select element type */
#define element_type Task_ref*
typedef struct{
	unsigned int counter;
	element_type* head;
	element_type* tail;
	element_type* base;
	unsigned int  length;
}FIFO_Buf_t;


typedef enum{
	FIFO_NO_ERROR,
	FIFO_FULL,
	FIFO_EMPTY,
	FIFO_NULL,

}Buffer_status;


/**************APIs**************/
Buffer_status FIFO_init (FIFO_Buf_t* fifo,element_type* buff , unsigned int length);
Buffer_status FIFO_enqueue (FIFO_Buf_t* fifo,element_type item);
Buffer_status FIFO_dequeue (FIFO_Buf_t* fifo,element_type* item);
Buffer_status FIFO_is_full (FIFO_Buf_t* fifo);
void FIFO_print (FIFO_Buf_t* fifo);


#endif  /* FIFO_STACK_H */
