/*
 * main.c
 *
 *  Created on: Feb 11, 2021
 *      Author: Diaa Abayazeed
 */
#include "CA.h"
#include "CA_US.h"
#include "CA_DC.h"

void (*CA_STATE)();
state_define(wating)
{
	//stop state of motor
	//CA_STATE=st(DC_stop);
	//return to busy state of ultrasonic
	CA_STATE=st(US_busy);
}
state_define(driving)
{
	//run state of motor
	//CA_STATE=st(DC_run);
	//return to busy state of ultrasonic
	CA_STATE=st(US_busy);

}







