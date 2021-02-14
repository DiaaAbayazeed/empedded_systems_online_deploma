/*
 * CA.h
 *
 *  Created on: Feb 11, 2021
 *      Author: Diaa Abayazeed
 */

#ifndef CA_H_
#define CA_H_
#include "state.h"
#include <stdio.h>
#include <stdlib.h>
typedef enum
{
	CA_wating,
	CA_driving,
}CA_STATE_ID;

state_define(wating);
state_define(driving);

int printRandoms(int lower, int upper, int count);

extern void (*CA_STATE)();


#endif /* CA_H_ */
