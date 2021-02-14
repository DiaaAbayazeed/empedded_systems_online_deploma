/*
 * main.c
 *
 *  Created on: Feb 11, 2021
 *      Author: Diaa Abayazeed
 */
#include "CA.h"

int speed = 0;
int distance = 0;
int thershold = 50;
void (*CA_STATE)();
state_define(wating)
{
	//state name
	//CA_STATE_ID=CA_wating;
	//state action
	speed =0;
	printf("the distance is:%d \t and speed is: %d\n",distance,speed);

	//distance random to check
	distance=printRandoms(40,60,10);
	//state event
	(distance<thershold)?(CA_STATE=ST_wating):(CA_STATE=ST_driving);

}
state_define(driving)
{

	//state name
	//CA_STATE_ID=CA_driving;
	//state action
	speed =30;
	printf("the distance is:%d \t and speed is: %d\n",distance,speed);

	//distance random to check
	distance=printRandoms(40,60,10);
	//state event
	(distance>=thershold)?(CA_STATE=ST_driving):(CA_STATE=ST_wating);

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







