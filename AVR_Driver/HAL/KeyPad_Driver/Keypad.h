/*
 * Keypad.h
 *
 * Created: 1/29/2023 12:08:10 AM
 *  Author: karim
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "DIO.h"

#define KeyPAd_PORT_Data	PORTB
#define Keypad_PORT_Dir		DDRB
#define KeyPad_Pin			PINB

#define R0	0
#define R1	1
#define R2	2
#define R3	3
#define C0	4
#define C1	5
#define C2	6
#define C3	7

void KeYPad_Init();
char KeyPAd_Scan();





#endif /* KEYPAD_H_ */