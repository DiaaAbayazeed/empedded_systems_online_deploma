/*
 * AlarmMonitor.c
 *
 *  Created on: Feb 13, 2021
 *      Author: Diaa Abayazeed
 */
#include "AlarmMonitor.h"

void High_Pressure_Val(){
	Set_Alarm_actuator(0);
	Delay(600000);
	Alarm_OFF();
}

void Alarm_OFF(){

	Set_Alarm_actuator(1);
	
	}
