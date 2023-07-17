/*
 * Ultrasonic_Prog.c
 *
 * Created: 7/17/2023 2:19:03 AM
 *  Author: karim
 */ 
#include "Ultrasonic_Interface.h"

static volatile uint8_t c , c1 , c2 , flag ; 
static volatile uint16_t t1 , t2 ;

static void Fun_ICU ()
{
	if (flag == 0 )
	{
		c = 0 ;
		t1 = ICR1 ; 
		flag = 1 ; 
		Timer1_voidICEdgeSelect(_FALLING_EDGE) ; 
	}
	else if ( flag == 1 )
	{
		t2 = ICR1 ; 
		flag = 2 ; 
		Timer1_voidICEdgeSelect(_RISING_EDGE) ; 
		Timer1_voidOVFDisableInterrupt() ; 
		Timer1_voidCaptureEventDisableInterrupt();
	}
}
static void Fun_OVF()
{
	c++ ; 
}
void Ultrasonic_VoidInit() 
{
	DIO_Write_Pin_Dir(Ultrasonic_TR_PORT,Ultrasonic_TR_PIN,OUT);
	DIO_Write_Pin_Dir(Ultrasonic_ECHO_PORT,Ultrasonic_ECHO_PIN,OUT);	
	Timer1_voidCaptureEventSetCallBack(Fun_ICU) ; 
	Timer1_voidOVFSetCallBack(Fun_OVF) ;
}

void Ultrasonic_VoidReadDistance(uint8_t*Distance) 
{
	uint16_t Loc_Time = 0 ; 
	DIO_Write_Pin(Ultrasonic_TR_PORT,Ultrasonic_TR_PIN,HIGH) ; 
	_delay_us(10) ; 
	DIO_Write_Pin(Ultrasonic_TR_PORT,Ultrasonic_TR_PIN,LOW) ;
	Timer1_voidICEdgeSelect(_RISING_EDGE);
	c1 = c ;
	flag=0 ; 
	Timer1_voidOVFEnableInterrupt();
	Timer1_voidCaptureEventEnableInterrupt();
	while(flag<2);
	c2 = c ; 
	Loc_Time = t2 - t1 + (c2-c1)*65535UL ; 
	*Distance = Loc_Time / 58 ; 	
	Timer1_voidCaptureEventDisableInterrupt();
}