/*
 * _7_SEG.c
 *
 * Created: 1/30/2023 1:23:46 AM
 *  Author: karim
 */ 
#include "7_SEG.h"
 
void _7_SEG_Init()
{
	DDRC = 0XFF ;
}
void _7_SEG_Start()
{
	uint8_t SEG[]={ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,ZERO};
	for ( uint8_t i =0 ; i < 11 ; i++ )
	{
		PORTC = SEG[i] ;
		_delay_ms(800);
	}	
}