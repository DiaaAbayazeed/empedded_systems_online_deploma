/*
 ============================================================================
 Name        : main.c
 Author      : Diaa Mohamed Ahmed
 Version     : v1
 ============================================================================
 */

#include <stdint.h>
#include <stdio.h>

//#include "driver/driver.h"
#include "AlarmMonitor.h"

int main ()
{
	GPIO_INITIALIZATION();
	int thershold =20;
	int Pval;
	while (1)
	{
		//Implement your Design 

		Pval=getPressureVal();

		if(Pval>=thershold)
		{
			High_Pressure_Val();
			
		}
		else
		{
			Alarm_OFF();
			Delay(10000);

		}

	}
	return 0;
}

