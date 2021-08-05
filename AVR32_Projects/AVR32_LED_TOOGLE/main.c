/*
 * LED_TOOGLE.c
 *
 * Created: 4/28/2021 1:00:38 AM
 * Author : Diaa Abayazeed
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include "util/delay.h"

int main(void)
{
	int i;
	DDRA =0xff;
    /* Replace with your application code */
    while (1) 
    {
		for(i=0;i<=7;i++)
		{
		PORTA |=(1<<i);
		_delay_ms(500);
		}
		for(i=7;i>=0;i--)
			{
			PORTA ^=(1<<i);
			_delay_ms(500);
		    }
	}
}

