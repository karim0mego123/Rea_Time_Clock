/*
 * Timer0_Prog.c
 *
 * Created: 7/10/2023 11:53:20 PM
 *  Author: karim
 */ 
#include "Timer0_Interface.h"

/* Global Pointers to Functions for Calling Back */
void (*GLOB_VidTimer0OVFPtrCallBack) (void) = NULL;
void (*GLOB_VidTimer0OCMPtrCallBack) (void) = NULL;

/************************************************************************************/
/*						PUBLIC FUNCTIONS IMPLEMENTATION								*/

/************************************************************************************/
void Timer0_voidInit(void)
{
	#if MODE == NORMAL
	CLEAR_BIT(TCCR0 , WGM01);
	CLEAR_BIT(TCCR0 , WGM00);
	#elif MODE == PHASE_CORRECT
	CLEAR_BIT(TCCR0 , WGM01);
	SET_BIT(TCCR0 , WGM00);
	/* For ensuring compatibility with future devices */
	CLEAR_BIT(TCCR0 , FOC0);
		#if OC0_PHASE_CORRECT == DISCONNECT_OC0
		CLEAR_BIT(TCCR0 , COM01);
		CLEAR_BIT(TCCR0 , COM00);
		#elif OC0_PHASE_CORRECT == NON_INVERTING_OC0
		SET_BIT(TCCR0 , COM01);
		CLEAR_BIT(TCCR0 , COM00);
		#elif OC0_PHASE_CORRECT == INVERTING_OC0
		SET_BIT(TCCR0 , COM01);
		SET_BIT(TCCR0 , COM00);
		#else
		#error "Incorrect output compare pin (OC0) behavior in case of phase correct mode"
		#endif
	
	#elif MODE == CTC
	SET_BIT(TCCR0 , WGM01);
	CLEAR_BIT(TCCR0 , WGM00);
		#if OC0_NON_PWM == DISCONNECT_OC0
		CLEAR_BIT(TCCR0 , COM01);
		CLEAR_BIT(TCCR0 , COM00);
		#elif OC0_NON_PWM == TOGGLE_OC0
		CLEAR_BIT(TCCR0 , COM01);
		SET_BIT(TCCR0 , COM00);
		#elif OC0_NON_PWM == CLEAR_OC0
		SET_BIT(TCCR0 , COM01);
		CLEAR_BIT(TCCR0 , COM00);
		#elif OC0_NON_PWM == SET_OC0
		SET_BIT(TCCR0 , COM01);
		SET_BIT(TCCR0 , COM00);
		#else
		#error "Incorrect output compare pin (OC0) behaviour in case of non-PWM mode"
		#endif
	
	#elif MODE == FAST_PWM
	SET_BIT(TCCR0, WGM01);
	SET_BIT(TCCR0 , WGM00);
	/* For ensuring compatibility with future devices */
	CLEAR_BIT(TCCR0, FOC0);
		#if OC0_FAST_PWM == DISCONNECT_OC0
			CLEAR_BIT(TCCR0, COM01);
			CLEAR_BIT(TCCR0, COM00);
		#elif OC0_FAST_PWM == NON_INVERTING_OC0
			SET_BIT(TCCR0, COM01);
			CLEAR_BIT(TCCR0, COM00);
		#elif OC0_FAST_PWM == INVERTING_OC0
			SET_BIT(TCCR0, COM01);
			SET_BIT(TCCR0, COM00);
		#else
		#error "Incorrect output compare pin (OC0) behaviour in case of fast PWM mode"
		#endif
#else
#error "Incorrect timer0 mode"
#endif
	#if CLOCK_SELECT == NO_CLOCK_SOURCE
	CLEAR_BIT(TCCR0 , CS02);
	CLEAR_BIT(TCCR0 , CS01);
	CLEAR_BIT(TCCR0 , CS00);
	#elif CLOCK_SELECT == NO_PRESCALER
	CLEAR_BIT(TCCR0 , CS02);
	CLEAR_BIT(TCCR0 , CS01);
	SET_BIT(TCCR0 , CS00);
	#elif CLOCK_SELECT == PRESCALER_8
	CLEAR_BIT(TCCR0 , CS02);
	SET_BIT(TCCR0 , CS01);
	CLEAR_BIT(TCCR0 , CS00);
	#elif CLOCK_SELECT == PRESCALER_64
	CLEAR_BIT(TCCR0 , CS02);
	SET_BIT(TCCR0 , CS01);
	SET_BIT(TCCR0 , CS00);
	#elif CLOCK_SELECT == PRESCALER_256
	SET_BIT(TCCR0 , CS02);
	CLEAR_BIT(TCCR0 , CS01);
	CLEAR_BIT(TCCR0 , CS00);
	#elif CLOCK_SELECT == PRESCALER_1024
	SET_BIT(TCCR0 , CS02);
	CLEAR_BIT(TCCR0 , CS01);
	SET_BIT(TCCR0 , CS00);
	#elif CLOCK_SELECT == EXTERNAL_T0_FALLING_EDGE
	SET_BIT(TCCR0 , CS02);
	SET_BIT(TCCR0 , CS01);
	CLEAR_BIT(TCCR0 , CS00);
	#elif CLOCK_SELECT == EXTERNAL_T0_RISING_EDGE
	SET_BIT(TCCR0 , CS02);
	SET_BIT(TCCR0 , CS01);
	SET_BIT(TCCR0 , CS00);
	#else
	#error "Incorrect clock selection"
	#endif
}
void Timer0_voidPreload(uint8_t LOC_U8Value)
{
	TCNT0 = LOC_U8Value;
}
void Timer0_voidSetCTCValue(uint8_t LOC_U8Value)
{
	OCR0 = LOC_U8Value;
}
void Timer0_voidGetCounterValue(uint8_t* LOC_U8Value)
{

	*LOC_U8Value = TCNT0;
}
void Timer0_voidEnableOVFInterrupt(void)
{
	SET_BIT(TIMSK, TOIE0);
}
void Timer0_voidDisableOVFInterrupt(void)
{
	CLEAR_BIT(TIMSK, TOIE0) ;
}
void Timer0_voidEnableOCMInterrupt(void)
{
	SET_BIT(TIMSK, OCIE0);
}

void Timer0_voidDisableOCMInterrupt(void)
{
	CLEAR_BIT(TIMSK, OCIE0);
}
void Timer0_voidOVFSetCallBack( void (*ptrToFun)(void) )
{
	if (ptrToFun != NULL)
	{
		GLOB_VidTimer0OVFPtrCallBack = ptrToFun;
	}
}
void Timer0_voidOCMSetCallBack( void (*ptrToFun)(void) )
{
	if (ptrToFun != NULL)
	{
		GLOB_VidTimer0OCMPtrCallBack = ptrToFun;
	}
}
void Timer0_voidOVFPollingOnFlag(void)
{
	/* Wait until flag is fired */
	while ( !GET_BIT(TIFR, TOV0) );
	/* Clear flag */
	SET_BIT(TIFR, TOV0);
}
void Timer0_voidOCMPollingOnFlag(void)
{
	/* Wait until flag is fired */
	while ( !GET_BIT(TIFR, OCF0) );
	/* Clear flag */
	SET_BIT(TIFR, OCF0);

}
void Timer0_voidSetDutyCycle(uint8_t LOC_F32DutyCycle)
{
	if (LOC_F32DutyCycle >= MINIMUM_DUTYCYCLE && LOC_F32DutyCycle <= MAXIMUM_DUTYCYCLE)
	{
		Timer0_voidSetCTCValue( ( LOC_F32DutyCycle / 100 ) * ( RESOLUTION - 1 ) );
	}
}

/************************************************************************************/
/*						PRIVATE FUNCTIONS IMPLEMENTATION							*/
/************************************************************************************/

void __vector_10(void)
{
	if (GLOB_VidTimer0OCMPtrCallBack != NULL)
	{
		(*GLOB_VidTimer0OCMPtrCallBack)();
	}
}

void __vector_11(void)
{
	if (GLOB_VidTimer0OVFPtrCallBack != NULL)
	{
		(*GLOB_VidTimer0OVFPtrCallBack)();
	}
}
