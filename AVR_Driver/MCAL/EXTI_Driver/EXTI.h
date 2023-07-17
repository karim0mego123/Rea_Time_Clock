/*
 * EXTI.h
 *
 * Created: 1/31/2023 5:40:41 PM
 *  Author: karim
 */ 


#ifndef EXTI_H_
#define EXTI_H_

#include "DIO.h"

// enable Interrupt 

typedef enum{
	EX_INT0 = 0 ,
	EX_INT1 ,
	EX_INT2 
} EXTI_Interrupt_t ;

typedef enum{
	LOW_LEVEL=0,
	ANY_LOGIC_CHANGE,
	FALLING_EDGE,
	RISING_EDGE
} Trigger_Edge_t ;

void EXTI_Enable(EXTI_Interrupt_t interrupt);
void EXTI_Disable(EXTI_Interrupt_t interrupt);
void EXI_SetCallBack(EXTI_Interrupt_t Interrupt,void(*LocalPtr)(void));
void EXTI_TriggerEdge(EXTI_Interrupt_t interrupt , Trigger_Edge_t Edge);

#endif /* EXTI_H_ */