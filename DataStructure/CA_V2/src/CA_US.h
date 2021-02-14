/*
 * US.h
 *
 *  Created on: Feb 11, 2021
 *      Author: Diaa Abayazeed
 */

#ifndef US_H_
#define US_H_
#include "state.h"
#include <stdio.h>
#include <stdlib.h>
typedef enum
{
	init,
	busy,
}US_STATE_ID;

state_define(US_init);
state_define(US_busy);

int printRandoms(int lower, int upper, int count);

extern void (*CA_STATE)();


#endif /* US_H_ */
