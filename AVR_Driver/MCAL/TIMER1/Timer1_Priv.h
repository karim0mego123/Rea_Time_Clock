/*
 * Timer1_Priv.h
 *
 * Created: 7/11/2023 4:58:51 PM
 *  Author: karim
 */ 


#ifndef TIMER1_PRIV_H_
#define TIMER1_PRIV_H_

/***********************************************************************************/
/*  								REGISTERS ADDRESSES							   */
/***********************************************************************************/
#define TCCR1A 							*((volatile uint8_t*)0x4F)
#define TCCR1B  						*((volatile uint8_t*)0x4E)
#define TCNT1 							*((volatile uint16_t*)0x4C)
#define OCR1A 							*((volatile uint16_t*)0x4A)
#define OCR1B 							*((volatile uint16_t*)0x48)
#define ICR1 							*((volatile uint16_t*)0x46)
#define TIMSK 							*((volatile uint8_t*)0x59)
#define TIFR 							*((volatile uint8_t*)0x58)
#define SFIOR 							*((volatile uint8_t*)0x50)

/***********************************************************************************/
/* 					               TCCR1A REGISTER BITS							   */
/***********************************************************************************/
#define COM1A1									7
#define COM1A0									6
#define COM1B1									5
#define COM1B0									4
#define FOC1A									3
#define FOC1B									2
#define WGM11									1
#define WGM10									0

/***********************************************************************************/
/* 					               TCCR1B REGISTER BITS							   */
/***********************************************************************************/
#define ICNC1									7
#define ICES1									6
#define BIT5									5
#define WGM13									4
#define WGM12									3
#define CS12									2
#define CS11									1
#define CS10									0

/***********************************************************************************/
/* 					               TIMSK REGISTER BITS							   */
/***********************************************************************************/
#define TICIE1									5
#define OCIE1A									4
#define OCIE1B									3
#define TOIE1									2

/***********************************************************************************/
/* 					               TIFR REGISTER BITS							   */
/***********************************************************************************/
#define ICF1									5
#define OCF1A									4
#define OCF1B									3
#define TOV1									2

/***********************************************************************************/
/* 					                SFIOR REGISTER BITS							   */
/***********************************************************************************/
#define PSR10									0

/***********************************************************************************/
/* 					                TIMER MODES							   		   */
/***********************************************************************************/
#define NORMAL									0
#define PHASE_CORRECT_8_BIT						1
#define PHASE_CORRECT_9_BIT						2
#define PHASE_CORRECT_10_BIT					3
#define CTC_OCR1A								4
#define CTC_ICR1								5
#define FAST_PWM_8_BIT							6
#define FAST_PWM_9_BIT							7
#define FAST_PWM_10_BIT							8
#define PHASE_AND_FREQUENCY_CORRECT_ICR1		9
#define PHASE_AND_FREQUENCY_CORRECT_OCR1A		10
#define PHASE_CORRECT_ICR1						11
#define PHASE_CORRECT_OCR1A						12
#define FAST_PWM_ICR1							13
#define FAST_PWM_OCR1A							14

/***********************************************************************************/
/*             			OUTPUT COMPARE PIN (OC1A) BEHAVIOUR				           */
/***********************************************************************************/
#define DISCONNECT_OC1A							0
#define TOGGLE_OC1A								1
#define CLEAR_OC1A								2
#define SET_OC1A								3
#define NON_INVERTED_OC1A						4
#define INVERTED_OC1A							5

/***********************************************************************************/
/*             			OUTPUT COMPARE PIN (OC1B) BEHAVIOUR				           */
/***********************************************************************************/
#define DISCONNECT_OC1B							0
#define TOGGLE_OC1B								1
#define CLEAR_OC1B								2
#define SET_OC1B								3
#define NON_INVERTED_OC1B						4
#define INVERTED_OC1B							5

/***********************************************************************************/
/*         						 CLOCK SELECTION        						   */
/***********************************************************************************/
#define NO_CLOCK_SOURCE							0
#define NO_PRESCALER							1
#define PRESCALER_8								2
#define PRESCALER_64							3
#define PRESCALER_256							4
#define PRESCALER_1024							5
#define EXTERNAL_T0_FALLING_EDGE				6
#define EXTERNAL_T0_RISING_EDGE					7


/***********************************************************************************/
/*         					INPUT CAPTURE EDGE SELECT      						   */
/***********************************************************************************/

#define _FALLING_EDGE							0
#define _RISING_EDGE								1

/***********************************************************************************/
/*         						 RESOLUTION RANGE        						   */
/***********************************************************************************/
#define MINIMUM_RESOLUTION						0x0003

/***********************************************************************************/
/*         						 DUTYCYCLE RANGE        						   */
/***********************************************************************************/
#define MAXIMUM_DUTYCYCLE						100
#define MINIMUM_DUTYCYCLE						0

/***********************************************************************************/
/*						  PRIVATE FUNCTIONS PROTOTYPES							   */
/***********************************************************************************/
void __vector_9(void) 							__attribute__((signal));
void __vector_8(void) 							__attribute__((signal));
void __vector_7(void) 							__attribute__((signal));
void __vector_6(void) 							__attribute__((signal));

#endif /* TIMER1_PRIV_H_ */