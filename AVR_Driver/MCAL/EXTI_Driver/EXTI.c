/*
 * EXTI.c
 *
 * Created: 1/31/2023 5:40:27 PM
 *  Author: karim
 */ 
#include "EXTI.h"


/****************************Pointer to functions to be assigned to ISR*********************************/

static void (*INT0_Fptr) (void)=NULL;
static void (*INT1_Fptr) (void)=NULL;
static void (*INT2_Fptr) (void)=NULL;

/************************************Call back functions*********************************************/
void EXI_SetCallBack(EXTI_Interrupt_t Interrupt,void(*LocalPtr)(void))
{
	switch(Interrupt){
		case EX_INT0:
		INT0_Fptr=LocalPtr;
		break;
		case EX_INT1:
		INT1_Fptr=LocalPtr;
		break;
		case EX_INT2:
		INT2_Fptr=LocalPtr;
		break;
	}
}
void EXTI_Enable(EXTI_Interrupt_t interrupt)
{
	switch(interrupt)
	{
		case EX_INT0 :
			SET_BIT(GICR,INT0);
			break;
		case EX_INT1 :
			SET_BIT(GICR,INT1);
			break;
		case EX_INT2 :
			SET_BIT(GICR,INT2);
			break;
	}
}
void EXTI_Disable(EXTI_Interrupt_t interrupt)
{
	switch(interrupt)
	{
		case EX_INT0 :
		CLEAR_BIT(GICR,INT0);
		break;
		case EX_INT1 :
		CLEAR_BIT(GICR,INT1);
		break;
		case EX_INT2 :
		CLEAR_BIT(GICR,INT2);
		break;
	}
	
}
void EXTI_TriggerEdge(EXTI_Interrupt_t interrupt , Trigger_Edge_t Edge)
{
	switch(interrupt)
	{
		case EX_INT0 :
			switch(Edge)
			{
				case LOW_LEVEL :
				CLEAR_BIT(MCUCR,ISC00);
				CLEAR_BIT(MCUCR,ISC01);
				break;
				case ANY_LOGIC_CHANGE :
				SET_BIT(MCUCR,ISC00);
				CLEAR_BIT(MCUCR,ISC01);
				break;
				case FALLING_EDGE :
				CLEAR_BIT(MCUCR,ISC00);
				SET_BIT(MCUCR,ISC01);
				break;
				case RISING_EDGE :
				SET_BIT(MCUCR,ISC00);
				SET_BIT(MCUCR,ISC01);
				break;
			}
			break;
		case EX_INT1 :
			switch(Edge)
			{
				case LOW_LEVEL :
				CLEAR_BIT(MCUCR,ISC10);
				CLEAR_BIT(MCUCR,ISC11);
				break;
				case ANY_LOGIC_CHANGE :
				SET_BIT(MCUCR,ISC10);
				CLEAR_BIT(MCUCR,ISC11);
				break;
				case FALLING_EDGE :
				CLEAR_BIT(MCUCR,ISC10);
				SET_BIT(MCUCR,ISC11);
				break;
				case RISING_EDGE :
				SET_BIT(MCUCR,ISC10);
				SET_BIT(MCUCR,ISC11);
				break;
			}
			break;
		case EX_INT2 :
			switch(Edge)
			{
				case FALLING_EDGE :
					CLEAR_BIT(MCUCSR,ISC2);
					break;
				case RISING_EDGE :
					SET_BIT(MCUCSR,ISC2);
					break;
				default:
					CLEAR_BIT(MCUCSR,ISC2);
					break;
			}
			break;
	}
}
/*******************************ISR********************************/
ISR(INT0_vect)
{
	if (INT0_Fptr!=NULL)
	{
		INT0_Fptr();
	}
}
ISR(INT1_vect)
{
	if (INT1_Fptr!=NULL)
	{
		INT1_Fptr();
	}
}
ISR(INT2_vect)
{
	if (INT2_Fptr!=NULL)
	{
		INT2_Fptr();
	}
}