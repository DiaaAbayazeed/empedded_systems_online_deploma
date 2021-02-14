/*
 * DC.h
 *
 *  Created on: Feb 11, 2021
 *      Author: Diaa Abayazeed
 */

#ifndef DC_H_
#define DC_H_
#include "state.h"
#include <stdio.h>
#include <stdlib.h>
typedef enum
{
	stop,
	run,
}DC_STATE_ID;

state_define(DC_stop);
state_define(DC_run);

int printRandoms(int lower, int upper, int count);

extern void (*CA_STATE)();


#endif /* DC_H_ */
