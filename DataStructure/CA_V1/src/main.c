/*
 ============================================================================
 Name        : CA_V1.c
 Author      : Diaa AbaYazeed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "CA.h"

void setup()
{
	// init all drivers
	// init IRQ
	// init hall US_driver MOTOR_driver
	// init block
	// set state pointer
	CA_STATE = ST_wating;


}

int main(void) {
// call setup
	setup();

	while(1)
	{
	CA_STATE();


	}




}
