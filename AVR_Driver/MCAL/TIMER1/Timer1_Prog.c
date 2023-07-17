/*
 * Timer1_Prog.c
 *
 * Created: 7/11/2023 4:58:35 PM
 *  Author: karim
 */ 
#include "Timer1_Interface.h"
#include "Timer1_Config.h"
/* Global Pointers to Functions for Calling Back */
void (*GLOB_VidTimer1OVFPtrCallBack)(void) = NULL;
void (*GLOB_VidTimer1OCAPtrCallBack)(void) = NULL;
void (*GLOB_VidTimer1OCBPtrCallBack)(void) = NULL;
void (*GLOB_VidTimer1CaptureEventPtrCallBack)(void) = NULL;

/************************************************************************************/
/*						PUBLIC FUNCTIONS IMPLEMENTATION								*/
/************************************************************************************/

void Timer1_voidInit(void)
{
		/* Mode of Operation Configuration */
		#if MODE == NORMAL
		CLEAR_BIT(TCCR1B , WGM13);
		CLEAR_BIT(TCCR1B , WGM12);
		CLEAR_BIT(TCCR1A , WGM11);
		CLEAR_BIT(TCCR1A , WGM10);

		#elif MODE == PHASE_CORRECT_8_BIT
		CLEAR_BIT(TCCR1B , WGM13);
		CLEAR_BIT(TCCR1B , WGM12);
		CLEAR_BIT(TCCR1A , WGM11);
		SET_BIT(TCCR1A , WGM10);

		#elif MODE == PHASE_CORRECT_9_BIT
		CLEAR_BIT(TCCR1B , WGM13);
		CLEAR_BIT(TCCR1B , WGM12);
		SET_BIT(TCCR1A , WGM11);
		CLEAR_BIT(TCCR1A , WGM10);

		#elif MODE == PHASE_CORRECT_10_BIT
		CLEAR_BIT(TCCR1B , WGM13);
		CLEAR_BIT(TCCR1B , WGM12);
		SET_BIT(TCCR1A , WGM11);
		SET_BIT(TCCR1A , WGM10);

		#elif MODE == CTC_OCR1A
		CLEAR_BIT(TCCR1B , WGM13);
		SET_BIT(TCCR1B , WGM12);
		CLEAR_BIT(TCCR1A , WGM11);
		CLEAR_BIT(TCCR1A , WGM10);

		#elif MODE == FAST_PWM_8_BIT
		CLEAR_BIT(TCCR1B , WGM13);
		SET_BIT(TCCR1B , WGM12);
		CLEAR_BIT(TCCR1A , WGM11);
		SET_BIT(TCCR1A , WGM10);

		#elif MODE == FAST_PWM_9_BIT
		CLEAR_BIT(TCCR1B , WGM13);
		SET_BIT(TCCR1B , WGM12);
		SET_BIT(TCCR1A , WGM11);
		CLEAR_BIT(TCCR1A , WGM10);

		#elif MODE == FAST_PWM_10_BIT
		CLEAR_BIT(TCCR1B , WGM13);
		SET_BIT(TCCR1B , WGM12);
		SET_BIT(TCCR1A , WGM11);
		SET_BIT(TCCR1A , WGM10);

		#elif MODE == PHASE_AND_FREQUENCY_CORRECT_ICR1
		SET_BIT(TCCR1B , WGM13);
		CLEAR_BIT(TCCR1B , WGM12);
		CLEAR_BIT(TCCR1A , WGM11);
		CLEAR_BIT(TCCR1A , WGM10);

		#elif MODE == PHASE_AND_FREQUENCY_CORRECT_OCR1A
		SET_BIT(TCCR1B , WGM13);
		CLEAR_BIT(TCCR1B , WGM12);
		CLEAR_BIT(TCCR1A , WGM11);
		SET_BIT(TCCR1A , WGM10);

		#elif MODE == PHASE_CORRECT_ICR1
		SET_BIT(TCCR1B , WGM13);
		CLEAR_BIT(TCCR1B , WGM12);
		SET_BIT(TCCR1A , WGM11);
		CLEAR_BIT(TCCR1A , WGM10);

		#elif MODE == PHASE_CORRECT_OCR1A
		SET_BIT(TCCR1B , WGM13);
		CLEAR_BIT(TCCR1B , WGM12);
		SET_BIT(TCCR1A , WGM11);
		SET_BIT(TCCR1A , WGM10);

		#elif MODE == CTC_ICR1
		SET_BIT(TCCR1B , WGM13);
		SET_BIT(TCCR1B , WGM12);
		CLEAR_BIT(TCCR1A , WGM11);
		CLEAR_BIT(TCCR1A , WGM10);

		#elif MODE == FAST_PWM_ICR1
		SET_BIT(TCCR1B , WGM13);
		SET_BIT(TCCR1B , WGM12);
		SET_BIT(TCCR1A , WGM11);
		CLEAR_BIT(TCCR1A , WGM10);

		#elif MODE == FAST_PWM_OCR1A
		SET_BIT(TCCR1B , WGM13);
		SET_BIT(TCCR1B , WGM12);
		SET_BIT(TCCR1A , WGM11);
		SET_BIT(TCCR1A , WGM10);

		#else
		#error "Invalid mode of operation for timer1"
		#endif

		/* Output Compare Pins Behavior */
		#if MODE == CTC_ICR1 || MODE == CTC_OCR1A || MODE == NORMAL
			#if OC1A_NON_PWM == DISCONNECT_OC1A
			CLEAR_BIT(TCCR1A , COM1A1);
			CLEAR_BIT(TCCR1A , COM1A0);
			#elif OC1A_NON_PWM == TOGGLE_OC1A
			CLEAR_BIT(TCCR1A , COM1A1);
			SET_BIT(TCCR1A , COM1A0);
			#elif OC1A_NON_PWM == CLEAR_OC1A
			SET_BIT(TCCR1A , COM1A1);
			CLEAR_BIT(TCCR1A , COM1A0);
			#elif OC1A_NON_PWM == SET_OC1A
			SET_BIT(TCCR1A , COM1A1);
			SET_BIT(TCCR1A , COM1A0);
			#else
			#error "Incorrect output compare pin (OC1A) behavior in case of non-PWM mode"
			#endif
			#if OC1B_NON_PWM == DISCONNECT_OC1B
			CLEAR_BIT(TCCR1A , COM1B1);
			CLEAR_BIT(TCCR1A , COM1B0);
			#elif OC1B_NON_PWM == TOGGLE_OC1B
			CLEAR_BIT(TCCR1A , COM1B1);
			SET_BIT(TCCR1A , COM1B0);
			#elif OC1B_NON_PWM == CLEAR_OC1B
			SET_BIT(TCCR1A , COM1B1);
			CLEAR_BIT(TCCR1A , COM1B0);
			#elif OC1B_NON_PWM == SET_OC1B
			SET_BIT(TCCR1A , COM1B1);
			SET_BIT(TCCR1A , COM1B0);
			#else
			#error "Incorrect output compare pin (OC1B) behavior in case of non-PWM mode"
			#endif
		#elif MODE == FAST_PWM_10_BIT || MODE == FAST_PWM_9_BIT || MODE == FAST_PWM_8_BIT \
		|| MODE == FAST_PWM_ICR1 || MODE == FAST_PWM_OCR1A
			#if OC1A_FAST_PWM == DISCONNECT_OC1A
			CLEAR_BIT(TCCR1A , COM1A1);
			CLEAR_BIT(TCCR1A , COM1A0);
			#elif OC1A_FAST_PWM == TOGGLE_OC1A
			CLEAR_BIT(TCCR1A , COM1A1);
			SET_BIT(TCCR1A , COM1A0);
			#elif OC1A_FAST_PWM == NON_INVERTED_OC1A
			SET_BIT(TCCR1A , COM1A1);
			CLEAR_BIT(TCCR1A , COM1A0);
			#elif OC1A_FAST_PWM == INVERTED_OC1A
			SET_BIT(TCCR1A , COM1A1);
			SET_BIT(TCCR1A , COM1A0);
			#else
			#error "Incorrect output compare pin (OC1A) behavior in case of fast PWM mode"
			#endif
			#if OC1B_FAST_PWM == DISCONNECT_OC1B
			CLEAR_BIT(TCCR1A , COM1B1);
			CLEAR_BIT(TCCR1A , COM1B0);
			#elif OC1B_FAST_PWM == TOGGLE_OC1B
			CLEAR_BIT(TCCR1A , COM1B1);
			SET_BIT(TCCR1A , COM1B0);
			#elif OC1B_FAST_PWM == NON_INVERTED_OC1B
			SET_BIT(TCCR1A , COM1B1);
			CLEAR_BIT(TCCR1A , COM1B0);
			#elif OC1B_FAST_PWM == INVERTED_OC1B
			SET_BIT(TCCR1A , COM1B1);
			SET_BIT(TCCR1A , COM1B0);
			#else
			#error "Incorrect output compare pin (OC1B) behavior in case of fast PWM mode"
			#endif
		#elif MODE == PHASE_AND_FREQUENCY_CORRECT_ICR1 || MODE == PHASE_CORRECT_10_BIT  || \
		MODE == PHASE_AND_FREQUENCY_CORRECT_OCR1A || MODE == PHASE_CORRECT_9_BIT || \
		MODE == PHASE_CORRECT_8_BIT || MODE == PHASE_CORRECT_ICR1 || MODE == \
		PHASE_CORRECT_OCR1A
			#if OC1A_PHASE == DISCONNECT_OC1A
			CLEAR_BIT(TCCR1A , COM1A1);
			CLEAR_BIT(TCCR1A , COM1A0);
			#elif OC1A_PHASE == TOGGLE_OC1A
			CLEAR_BIT(TCCR1A , COM1A1);
			SET_BIT(TCCR1A , COM1A0);
			#elif OC1A_PHASE == NON_INVERTED_OC1A
			SET_BIT(TCCR1A , COM1A1);
			CLEAR_BIT(TCCR1A , COM1A0);
			#elif OC1A_PHASE == INVERTED_OC1A
			SET_BIT(TCCR1A , COM1A1);
			SET_BIT(TCCR1A , COM1A0);
			#else
			#error "Incorrect output compare pin (OC1A) behavior in case of phase correct or phase and frequency correct PWM modes"
			#endif
			#if OC1B_PHASE == DISCONNECT_OC1B
			CLEAR_BIT(TCCR1A , COM1B1);
			CLEAR_BIT(TCCR1A , COM1B0);
			#elif OC1B_PHASE == NON_INVERTED_OC1B
			SET_BIT(TCCR1A , COM1B1);
			CLEAR_BIT(TCCR1A , COM1B0);
			#elif OC1B_PHASE == INVERTED_OC1B
			SET_BIT(TCCR1A , COM1B1);
			SET_BIT(TCCR1A , COM1B0);
			#else
			#error "Incorrect output compare pin (OC1B) behavior in case of phase correct or phase and frequency correct PWM modes"
			#endif
			#endif
		/* To ensure compatibility with future devices */
		CLEAR_BIT(TCCR1A , FOC1A);
		CLEAR_BIT(TCCR1A , FOC1B);
		CLEAR_BIT(TCCR1B , BIT5);
		#if CLOCK_SELECT == NO_CLOCK_SOURCE
		CLEAR_BIT(TCCR1B , CS12);
		CLEAR_BIT(TCCR1B , CS11);
		CLEAR_BIT(TCCR1B , CS10);
		#elif CLOCK_SELECT == NO_PRESCALER
		CLEAR_BIT(TCCR1B , CS12);
		CLEAR_BIT(TCCR1B , CS11);
		SET_BIT(TCCR1B , CS10);
		#elif CLOCK_SELECT == PRESCALER_8
		CLEAR_BIT(TCCR1B , CS12);
		SET_BIT(TCCR1B , CS11);
		CLEAR_BIT(TCCR1B , CS10);
		#elif CLOCK_SELECT == PRESCALER_64
		CLEAR_BIT(TCCR1B , CS12);
		SET_BIT(TCCR1B , CS11);
		SET_BIT(TCCR1B , CS10);
		#elif CLOCK_SELECT == PRESCALER_256
		SET_BIT(TCCR1B , CS12);
		CLEAR_BIT(TCCR1B , CS11);
		CLEAR_BIT(TCCR1B , CS10);
		#elif CLOCK_SELECT == PRESCALER_1024
		SET_BIT(TCCR1B , CS12);
		CLEAR_BIT(TCCR1B , CS11);
		SET_BIT(TCCR1B , CS10);
		#elif CLOCK_SELECT == EXTERNAL_T0_FALLING_EDGE
		SET_BIT(TCCR1B , CS12);
		SET_BIT(TCCR1B , CS11);
		CLEAR_BIT(TCCR1B , CS10);
		#elif CLOCK_SELECT == EXTERNAL_T0_RISING_EDGE
		SET_BIT(TCCR1B , CS12);
		SET_BIT(TCCR1B , CS11);
		SET_BIT(TCCR1B , CS10);
		#else
		#error "Incorrect clock selection"
		#endif	
}

void Timer1_voidPreload(uint16_t LOC_U16Value)
{
	TCNT1 = LOC_U16Value;
}
void Timer1_voidSetCounterTOP(uint16_t LOC_U16Value)
{
	if (LOC_U16Value >= MINIMUM_RESOLUTION)
	{
		#if MODE == CTC_OCR1A || MODE == FAST_PWM_OCR1A || MODE == PHASE_CORRECT_OCR1A \
		|| MODE == PHASE_AND_FREQUENCY_CORRECT_OCR1A
		OCR1A  = LOC_U16Value;
		#elif MODE == CTC_ICR1 || MODE == FAST_PWM_ICR1 || MODE == PHASE_CORRECT_ICR1 \
		|| MODE == PHASE_AND_FREQUENCY_CORRECT_ICR1
		ICR1  = LOC_U16Value;
		#elif MODE == NORMAL || MODE == PHASE_CORRECT_10_BIT || MODE == PHASE_CORRECT_8_BIT    \
		|| MODE == PHASE_CORRECT_9_BIT || MODE == FAST_PWM_10_BIT || MODE == FAST_PWM_9_BIT \
		|| MODE == FAST_PWM_8_BIT
		/* Trying to set TOP value while using a fixed-TOP mode. */
		#else
		#error "Invalid mode of operation for timer1"
		#endif
	}
}
void Timer1_voidSetOCACompareValue(uint16_t LOC_U16Value)
{
	#if MODE == CTC_OCR1A || MODE == PHASE_AND_FREQUENCY_CORRECT_OCR1A || MODE == \
	PHASE_CORRECT_OCR1A
	/* Trying to set the OCR1A value as a compare value while using OCR1A as a TOP */
	#else
	OCR1A  = LOC_U16Value;
	#endif
}

void Timer1_voidSetOCBCompareValue(uint16_t LOC_U16Value)
{
	OCR1B  = LOC_U16Value;
}
void Timer1_voidOC1ASetDutyCycle(uint8_t LOC_voidDutyCycle,uint16_t LOC_U16Top)
{
	if (LOC_voidDutyCycle >= MINIMUM_DUTYCYCLE && LOC_voidDutyCycle <= MAXIMUM_DUTYCYCLE && LOC_U16Top >= MINIMUM_RESOLUTION)
	{
		Timer1_voidSetCounterTOP(LOC_U16Top);
		Timer1_voidSetOCACompareValue( ( LOC_voidDutyCycle / 100 ) * ( LOC_U16Top ) );
	}

}

void Timer1_voidOC1BSetDutyCycle(uint8_t LOC_voidDutyCycle, uint16_t LOC_U16Top)
{
	if (LOC_voidDutyCycle <= MAXIMUM_DUTYCYCLE && LOC_U16Top >= MINIMUM_RESOLUTION)
	{
		Timer1_voidSetCounterTOP(LOC_U16Top);
		Timer1_voidSetOCBCompareValue( ( LOC_voidDutyCycle / 100 ) * ( LOC_U16Top ) );
	}
}
void Timer1_voidGetCounterValue(uint16_t* LOC_U16Value)
{
	if (LOC_U16Value != NULL)
	{
		*LOC_U16Value = TCNT1;
	}
}

void Timer1_voidEnableNoiseCanceler(void)
{
	SET_BIT(TCCR1B, ICNC1);
}

void Timer1_voidDisableNoiseCanceler(void)
{
	CLEAR_BIT(TCCR1B, ICNC1);
	
}

void Timer1_voidICEdgeSelect(uint8_t LOC_voidEdge)

{
	switch (LOC_voidEdge)
	{
		case _FALLING_EDGE:
			CLEAR_BIT(TCCR1B, ICES1);
			break;
		case _RISING_EDGE:
			SET_BIT(TCCR1B , ICES1);
			break;
		default:break;
	}
}

void Timer1_voidGetCapturedValue(uint16_t* LOC_U16Value)
{
	if (LOC_U16Value != NULL)
	{

		*LOC_U16Value = ICR1 ;
	}
}

void Timer1_PWM_Freq_KHz(uint16_t Freq ) 
{
	if (Freq==0);
	else
	{
		uint16_t Ttotal = F_CPU/1000/Freq ; 
		if (Ttotal>=1)
		{
			ICR1 = Ttotal-1 ; 
		}
		else ICR1 = 0 ; 
	}
}
void Timer1_PWM_Freq_Hz(uint16_t Freq )
{
	if (Freq==0);
	else
	{
		uint16_t Ttotal = F_CPU/Freq ;
		if (Ttotal>=1)
		{
			ICR1 = Ttotal-1 ;
		}
		else ICR1 = 0 ;
	}
}
void Timer1_PWM_Duty(uint8_t duty)
{
	if (duty<=100)
	{
		uint16_t Ton = ((uint32_t)duty*(ICR1+1))/100 ; 
		if (Ton>1)
		{
			OCR1A = Ton - 1; 
		}
		else
		OCR1A=0 ; 
	}
}
void Timer1_voidOVFEnableInterrupt(void)
{
	SET_BIT(TIMSK , TOIE1);
}

void Timer1_voidOVFDisableInterrupt(void)
{
	CLEAR_BIT(TIMSK , TOIE1);
}

void Timer1_voidOCAEnableInterrupt(void)
{
	SET_BIT(TIMSK , OCIE1A);
}

void Timer1_voidOCADisableInterrupt(void)
{
	CLEAR_BIT(TIMSK , OCIE1A);
}

void Timer1_voidOCBEnableInterrupt(void)
{
	SET_BIT(TIMSK , OCIE1B);
}

void Timer1_voidOCBDisableInterrupt(void)
{
	CLEAR_BIT(TIMSK , OCIE1B);
}

void Timer1_voidCaptureEventEnableInterrupt(void)
{
	SET_BIT(TIMSK , TICIE1);
}

void Timer1_voidCaptureEventDisableInterrupt(void)
{
	CLEAR_BIT(TIMSK , TICIE1);
}

void Timer1_voidOVFPollingOnFlag(void)
{
	/* Wait until flag is fired */
	while ( !GET_BIT(TIFR , TOV1) );
	/* Clear flag */
	SET_BIT(TIFR , TOV1);
}

void Timer1_voidOCAPollingOnFlag(void)
{
	/* Wait until flag is fired */
	while ( !GET_BIT(TIFR , OCF1A) );
	/* Clear flag */
	SET_BIT(TIFR , OCF1A);
}

void Timer1_voidOCBPollingOnFlag(void)
{
	/* Wait until flag is fired */
	while ( !GET_BIT(TIFR , OCF1B) );
	/* Clear flag */
	SET_BIT(TIFR , OCF1B);
}

void Timer1_voidCaptureEventPollingOnFlag(void)
{
	/* Wait until flag is fired */
	while ( !GET_BIT(TIFR , ICF1) );
	/* Clear flag */
	SET_BIT(TIFR , ICF1);
}

void Timer1_voidOVFSetCallBack( void (*ptrToFun)(void) )
{
	if (ptrToFun != NULL)
	{
		GLOB_VidTimer1OVFPtrCallBack = ptrToFun;
	 
	}
}
void Timer1_voidOCASetCallBack( void (*ptrToFun)(void) )
{
	if (ptrToFun != NULL)
	{
		GLOB_VidTimer1OCAPtrCallBack = ptrToFun;
	}
}

void Timer1_voidOCBSetCallBack( void (*ptrToFun)(void) )
{
	if (ptrToFun != NULL)
	{
		GLOB_VidTimer1OCBPtrCallBack = ptrToFun;
		
	}
}

void Timer1_voidCaptureEventSetCallBack( void (*ptrToFun)(void) )
{
	if (ptrToFun != NULL)
	{
		GLOB_VidTimer1CaptureEventPtrCallBack = ptrToFun;
		
	}
}

void Timer1_voidResetPrescaler(void)
{
	SET_BIT(SFIOR, PSR10);	
}

/************************************************************************************/
/*						PRIVATE FUNCTIONS IMPLEMENTATION							*/
/************************************************************************************/

void __vector_9(void)
{
	if (GLOB_VidTimer1OVFPtrCallBack != NULL)
	{
		(*GLOB_VidTimer1OVFPtrCallBack)();
	}
}

void __vector_8(void)
{
	if (GLOB_VidTimer1OCBPtrCallBack != NULL)
	{
		(*GLOB_VidTimer1OCBPtrCallBack)();
	}
}

void __vector_7(void)
{
	if (GLOB_VidTimer1OCAPtrCallBack != NULL)
	{
		(*GLOB_VidTimer1OCAPtrCallBack)();
	}
}

void __vector_6(void)
{
	if (GLOB_VidTimer1CaptureEventPtrCallBack != NULL)
	{
		(*GLOB_VidTimer1CaptureEventPtrCallBack)();
	}
}