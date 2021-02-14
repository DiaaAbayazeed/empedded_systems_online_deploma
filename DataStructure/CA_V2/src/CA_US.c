/*
 * main.c
 *
 *  Created on: Feb 11, 2021
 *      Author: Diaa Abayazeed
 */
#include "CA_US.h"
#include "CA_DC.h"
int distance = 0;
int thershold = 50;
state_define(US_busy)
{
	//state name
	//US_STATE_ID=US_wating;
	//state action


	//distance random to check
	distance=printRandoms(40,60,10);
	//state event
	(distance<thershold)?(CA_STATE=st(DC_stop)):(CA_STATE=st(DC_run));
	printf("the distance is:%d \t",distance);


}


int printRandoms(int lower, int upper, int count)
{
	int i;
	for (i = 0; i < count; i++)
	{
		int num = (rand()%(upper - lower + 1)) + lower;
		return num;
	}
return 0;
}







