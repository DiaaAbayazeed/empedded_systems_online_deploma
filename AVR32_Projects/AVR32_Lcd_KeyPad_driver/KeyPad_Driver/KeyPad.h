/*
 * KeyPad.h
 *
 * Created: 7/12/2021 12:30:59 AM
 *  Author: Diaa Abayazeed
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

#define KeyPad_Dir    DDRD
#define KeyPad_Data   PORTD
#define KeyPad_Input  PIND

#define R0      0
#define R1      1
#define R2      2
#define R3      3
#define C0      4
#define C1      5
#define C2      6
#define C3      7





void Init_KeyPad();
char Get_Data();






#endif /* KEYPAD_H_ */