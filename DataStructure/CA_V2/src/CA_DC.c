/*
 * main.c
 *
 *  Created on: Feb 11, 2021
 *      Author: Diaa Abayazeed
 */
#include "CA.h"

int speed;

state_define(DC_stop)
{
	//state name
	//CA_STATE_ID=CA_wating;
	//state action
	speed =0;
	printf("..Waiting state.....speed=%d....\n",speed);
	CA_STATE=st(wating);

}
state_define(DC_run)
{

	//state name
	//CA_STATE_ID=CA_driving;
	//state action
	speed =30;
	printf("..driving state.....speed=%d....\n",speed);
	CA_STATE=st(driving);


}








