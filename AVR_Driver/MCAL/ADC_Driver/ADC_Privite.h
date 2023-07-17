/*
 * ADC_Privite.h
 *
 * Created: 4/23/2023 3:27:17 PM
 *  Author: karim
 */ 


#ifndef ADC_PRIVITE_H_
#define ADC_PRIVITE_H_

#include "Types.h"

/*****************************************************************************/
/*****************************************************************************/
/**                                                                         **/
/**                        Address of ADC registers                         **/
/**                                                                         **/
/*****************************************************************************/
/*****************************************************************************/
#define ADMUX	*((volatile uint8_t*) 0x27)
#define ADCSRA	*((volatile uint8_t*) 0x26)
#define ADCH	*((volatile uint8_t*) 0x25)
#define ADCL	*((volatile uint8_t*) 0x24)
#define SFIOR	*((volatile uint8_t*) 0x50)

/*****************************************************************************/
/*****************************************************************************/
/**                                                                         **/
/**                   Definitions of ADC configuration                      **/
/**                                                                         **/
/*****************************************************************************/
/*****************************************************************************/

/*****************************************************************************/
/**                Definitions of Prescaler configuration                   **/
/*****************************************************************************/

#define PRES_2			45
#define PRES_4			1
#define PRES_8			2
#define PRES_16			3
#define PRES_32			4
#define PRES_64			5
#define PRES_128		6

/*****************************************************************************/
/**                Definitions of Channel				                    **/
/*****************************************************************************/




/*****************************************************************************/
/**            Definitions of Reference Voltage configuration               **/
/*****************************************************************************/

#define AVCC_REF		34
#define AREF			32
#define INTERNAL		12

/*****************************************************************************/
/**               Definitions of Adjustment configuration                   **/
/*****************************************************************************/

#define RIGHT_ADJ		124
#define LEFT_ADJ		123

#define FREE_RUNNIG		21
#define EXTI0_TRIG		34


/*****************************************************************************/
/*****************************************************************************/
/**                                                                         **/
/**                   Definitions of BIT FIELD		                        **/
/**                                                                         **/
/*****************************************************************************/
/*****************************************************************************/

#define ENABLE_ADC									ADCSRA|=(1<<7)

#define DISABLE_ADC									ADCSRA&=~(1<<7)

#define PRESCALER_TWO								ADCSRA|=(1<<0)

#define PRESCALER_FOUR								ADCSRA|=(1<<1)

#define PRESCALER_EIGHT								ADCSRA|=(1<<0)|(1<<1)

#define PRESCALER_SIXTEEN							ADCSRA|=(1<<2)

#define PRESCALER_THIRTY_TWO						ADCSRA |= (1<<0)|(1<<2)

#define PRESCALER_SIXTY_FOUR						ADCSRA |= (1<<1)|(1<<2)

#define PRESCALER_HUNDRED_TWENTY_EIGHT				ADCSRA |= (1<<0)|(1<<1)|(1<<2)

#define AREF_VOLTAGE								ADMUX |= (0<<7)

#define AVCC_VOLTAGE								ADMUX |= (1<<6)

#define INTERNAL_VOLTAGE							ADMUX |= (1<<6)|(1<<7)

#define RIGHT_ADJUSTMENT							ADMUX &=~ (1<<5)

#define LEFT_ADJUSTMENT								ADMUX |=  (1<<5)

#define CLEAR_FLAG									ADCSRA |= (1<<4)

#define START_CONVERSION							ADCSRA|= (1<<6)

#define ENABLE_ADC_INTERRUPT						ADCSRA |= (1<<3)

#define ENABLE_TRIGGER								ADCSRA |= (1<<5)

#define DISABLE_TRIGGER								ADCSRA&=~(1<<5)

#define ADC_vect			   __vector_16

#endif /* ADC_PRIVITE_H_ */