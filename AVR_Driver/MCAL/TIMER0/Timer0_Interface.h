/*
 * Timer0_Interface.h
 *
 * Created: 7/10/2023 11:53:03 PM
 *  Author: karim
 */ 


#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

#include "Types.h"
#include "utils.h"
#include "Timer0_Priv.h"
#include "Timer0_Config.h"

/************************************************************************************/
/*							 FUNCTIONS PROTOTYPES								    */
/************************************************************************************/

/************************************************************************************/
/* Description: initializes timer0's peripheral	  								    */
/* Inputs: nothing													 	 		    */
/* Output: NO Output								  						    */
/************************************************************************************/
extern void Timer0_voidInit(void);
/************************************************************************************/

/************************************************************************************/
/* Description: set a value to start counting from								    */
/* Inputs: value to count from													 	*/
/* Output: NO Output								  						    */
/************************************************************************************/
extern void Timer0_voidPreload(uint8_t LOC_voidValue);
/************************************************************************************/

/************************************************************************************/
/* Description: set a value to compare with in non-normal modes					    */
/* Inputs: value to compare with									 	 		    */
/* Output: NO Output								  						    */
/************************************************************************************/
void Timer0_voidSetCTCValue(uint8_t LOC_voidValue);
/************************************************************************************/

/************************************************************************************/
/* Description: returns the value in timer0's counter. Counts are in the range of   */
/* 0 - 255.					    													*/
/* Inputs: pointer to a variable to receive the value in			 	 		    */
/* Output: NO Output								  						    */
/************************************************************************************/
void Timer0_voidGetCounterValue(uint8_t* LOC_voidValue);
/************************************************************************************/

/************************************************************************************/
/* Description: enables overflow interrupt										    */
/* Inputs: nothing													 	 		    */
/* Output: NO Output								  						    */
/************************************************************************************/
void Timer0_voidEnableOVFInterrupt(void);
/************************************************************************************/

/************************************************************************************/
/* Description: disables overflow interrupt										    */
/* Inputs: nothing													 	 		    */
/* Output: NO Output								  						    */
/************************************************************************************/
void Timer0_voidDisableOVFInterrupt(void);
/************************************************************************************/

/************************************************************************************/
/* Description: enables On Compare Match interrupt								    */
/* Inputs: nothing													 	 		    */
/* Output: NO Output								  						    */
/************************************************************************************/
void Timer0_voidEnableOCMInterrupt(void);
/************************************************************************************/

/************************************************************************************/
/* Description: disables On Compare Match interrupt								    */
/* Inputs: nothing													 	 		    */
/* Output: NO Output								  						    */
/************************************************************************************/
void Timer0_voidDisableOCMInterrupt(void);
/************************************************************************************/

/************************************************************************************/
/* Description: takes a pointer to a function that is to be executed on		  	    */
/* triggering the overflow interrupt.  								 			    */
/* Inputs: pointer to a function that takes no arguments and returns no value	    */
/* Output: NO Output								  						    */
/************************************************************************************/
void Timer0_voidOVFSetCallBack( void (*ptrToFun)(void) );
/***********************************************************************************/

/***********************************************************************************/
/* Description: takes a pointer to a function that is to be executed on		  	   */
/* triggering the On Compare Match interrupt.						 			   */
/* Inputs: pointer to a function that takes no arguments and returns no value	   */
/* Output: NO Output								  						   */
/***********************************************************************************/
void Timer0_voidOCMSetCallBack( void (*ptrToFun)(void) );
/************************************************************************************/

/***********************************************************************************/
/* Description: polls on timer0 overflow's flag						 			   */
/* Inputs: nothing					   											   */
/* Output: NO Output								  						   */
/***********************************************************************************/
void Timer0_voidOVFPollingOnFlag(void);
/***********************************************************************************/

/***********************************************************************************/
/* Description: polls on timer0 on compare match's flag				 			   */
/* Inputs: nothing					   											   */
/* Output: NO Output								  						   */
/***********************************************************************************/
void Timer0_voidOCMPollingOnFlag(void);
/***********************************************************************************/


/***********************************************************************************/
/* Description: sends a PWM signal with the received duty cycle (0% - 100%) on OC0 */
/* pin. 	   																	   */
/* Inputs: analog voltage			   											   */
/* Output: NO Output								  						   */
/***********************************************************************************/
void Timer0_voidSetDutyCycle(uint8_t LOC_F32DutyCycle);
/***********************************************************************************/


/***********************************************************************************/
/* Description: restarts timer0's prescaler. Note that this	affects both timer0	   */
/* and timer1						 			   			   					   */
/* Inputs: nothing					   											   */
/* Output: NO Output								  						   */
/***********************************************************************************/
void Timer0_voidResetPrescaler(void);
/***********************************************************************************/




#endif /* TIMER0_INTERFACE_H_ */