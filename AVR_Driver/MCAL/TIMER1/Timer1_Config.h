/*
 * Timer1_Config.h
 *
 * Created: 7/11/2023 4:59:24 PM
 *  Author: karim
 */ 


#ifndef TIMER1_CONFIG_H_
#define TIMER1_CONFIG_H_

/************************************************************************/
/* in case of using normal mode so top is FFFF and OVF will occur on FFFF
in case PHASE_CORRECT_8_BIT PHASE_CORRECT_9_BIT TOP PHASE_CORRECT_10_BIT
is Regester and Com will be in OCR1A  OC1A will be on mode inverting or non inverting
in case of ( CTC_OCR1A  - CTC_ICR1 ) mode using Timer1_voidSetCounterTOP to set OCR1A As top
in case of (FAST_PWM_8_BIT - FAST_PWM_9_BIT - FAST_PWM_10_BIT) use Timer1_voidSetOCACompareValue
to set Com to take action on Compare match .
in case mode PHASE_CORRECT_ICR1 Timer1_voidSetCounterTOP to set ICR1 as top and use Timer1_voidSetOCACompareValue to set Compare match /
in case of PHASE_CORRECT_OCR1A*/
/************************************************************************/

/*****************************************************************************/
/*      					 OPTIONS FOR TIMER MODE:			             */
/* NORMAL - PHASE_CORRECT_8_BIT - PHASE_CORRECT_9_BIT - PHASE_CORRECT_10_BIT */
/* CTC_OCR1A - CTC_ICR1 - FAST_PWM_8_BIT - FAST_PWM_9_BIT - FAST_PWM_10_BIT  */
/* PHASE_AND_FREQUENCY_CORRECT_ICR1 - PHASE_AND_FREQUENCY_CORRECT_OCR1A      */
/* PHASE_CORRECT_ICR1 - PHASE_CORRECT_OCR1A - FAST_PWM_ICR1 - FAST_PWM_OCR1A */
/*																			 */
/* Note that modes ending with ICR1 means that the TOP value is determined	 */
/* by the ICR1 register, while those ending with OCR1A means that the TOP	 */
/* value is determined by the OCR1A register. Using OCR1A for setting TOP	 */
/* value prevents it from being used for generating a PWM output.  			 */
/*****************************************************************************/
#define MODE										CTC_ICR1
	


/*****************************************************************************/
/*  OPTIONS FOR OUTPUT COMPARE PIN (OC1A) BEHAVIOUR IN CASE OF NON-PWM MODE: */
/*       	DISCONNECT_OC1A - TOGGLE_OC1A - CLEAR_OC1A - SET_OC1A		     */
/*****************************************************************************/
#define OC1A_NON_PWM				  			TOGGLE_OC1A


/*****************************************************************************/
/*  OPTIONS FOR OUTPUT COMPARE PIN (OC1B) BEHAVIOUR IN CASE OF NON-PWM MODE: */
/*       	DISCONNECT_OC1B - TOGGLE_OC1B - CLEAR_OC1B - SET_OC1B		     */
/*****************************************************************************/
#define OC1B_NON_PWM			  					DISCONNECT_OC1A


/*****************************************************************************/
/* OPTIONS FOR OUTPUT COMPARE PIN (OC1A) BEHAVIOUR IN CASE OF FAST PWM MODE: */
/* 			DISCONNECT_OC1A - NON_INVERTED_OC1A - INVERTED_OC1A	     	     */
/* TOGGLE_OC1A (FAST_PWM_OCR1A mode should be chosen. Otherwise, OC1A will	 */
/* be disconnected 															 */
/*****************************************************************************/
#define OC1A_FAST_PWM								NON_INVERTED_OC1A


/*****************************************************************************/
/*  OPTIONS FOR OUTPUT COMPARE PIN (OC1B) BEHAVIOUR IN CASE OF NON-PWM MODE: */
/*       		  DISCONNECT_OC1B - NON_INVERTED_OC1B - INVERTED_OC1B  	 	 */
/*****************************************************************************/
#define OC1B_FAST_PWM			  					NON_INVERTED_OC1B



/*****************************************************************************/
/* OPTIONS FOR OUTPUT COMPARE PIN (OC1A) BEHAVIOUR IN CASE OF PHASE CORRECT  */
/* 					   AND PHASE & FREQUENCY PWM MODES:  				     */
/* 				 DISCONNECT_OC1A - NON_INVERTED_OC1A - INVERTED_OC1A		 */
/* TOGGLE_OC1A (PHASE_AND_FREQUENCY_CORRECT_OCR1A or FAST_PWM_ICR1 mode		 */
/* should  be chosen. Otherwise, OC1A will be disconnected 					 */
/*****************************************************************************/
#define OC1A_PHASE									NON_INVERTED_OC1A


/*****************************************************************************/
/* OPTIONS FOR OUTPUT COMPARE PIN (OC1B) BEHAVIOUR IN CASE OF PHASE CORRECT  */
/* 					   AND PHASE & FREQUENCY PWM MODES:  				     */
/* 			DISCONNECT_OC1B - NON_INVERTED_OC1B - INVERTED_OC1B    			 */
/*****************************************************************************/
#define OC1B_PHASE									DISCONNECT_OC1B


/*****************************************************************************/
/* 							OPTIONS FOR CLOCK SELECT	 					 */
/*        NO_CLOCK_SOURCE - NO_PRESCALER - PRESCALER_8 - PRESCALER_64	     */
/*	       PRESCALER_256 - PRESCALER_1024 - EXTERNAL_T0_FALLING_EDGE		 */
/* 							EXTERNAL_T0_RISING_EDGE 						 */
/*****************************************************************************/
#define CLOCK_SELECT								PRESCALER_256


#define F_CPU										12000000UL

#endif /* TIMER1_CONFIG_H_ */