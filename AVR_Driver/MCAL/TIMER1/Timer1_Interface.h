/*
 * Timer1_Interface.h
 *
 * Created: 7/11/2023 4:59:09 PM
 *  Author: karim
 */ 


#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

#include "Types.h"
#include "utils.h"
#include "Timer1_Priv.h"
#include "Timer1_Config.h"

/***********************************************************************************/
/*         					INPUT CAPTURE EDGE SELECT      						   */
/***********************************************************************************/
#define TIMER1_FALLING_EDGE								0
#define TIMER1_RISING_EDGE								1


/************************************************************************************/
/*							 FUNCTIONS PROTOTYPES								    */
/************************************************************************************/

/************************************************************************************/
/* Description: initializes timer1's peripheral	  								    */
/* Inputs: nothing													 	 		    */
/* Output: void								  						    */
/************************************************************************************/
void Timer1_voidInit(void);
/************************************************************************************/

/************************************************************************************/
/* Description: sets a value to start counting from								    */
/* Inputs: value to count from													 	*/
/* Output: void								  						    */
/************************************************************************************/
void Timer1_voidPreload(uint16_t LOC_U16Value);
/************************************************************************************/

/************************************************************************************/
/* Description: sets a value to overflow at in non-normal modes. The minimum value	*/
/* allowed is 0x0003. 					    										*/
/* Inputs: TOP value												 	 		    */
/* Output: void								  						    */
/************************************************************************************/
void Timer1_voidSetCounterTOP(uint16_t LOC_U16Value);
/************************************************************************************/

/************************************************************************************/
/* Description: sets the value to be compared with for Output Compare unit A 		*/
/* Inputs: value to compare with									 	 		    */
/* Output: void								  						    */
/************************************************************************************/
void Timer1_voidSetOCACompareValue(uint16_t LOC_U16Value);
/************************************************************************************/

/************************************************************************************/
/* Description: sets the value to be compared with for Output Compare unit B 		*/
/* Inputs: value to compare with									 	 		    */
/* Output: void								  									    */
/************************************************************************************/
void Timer1_voidSetOCBCompareValue(uint16_t LOC_U16Value);
/************************************************************************************/

/************************************************************************************/
/* Description: sends a PWM signal with the received duty cycle (0% - 100%) on		*/
/* OC1A pin.																		*/
/* Inputs: Duty cycle - Counter top value (minimum 0x0003)			 	 		    */
/* Output: void								  									    */
/************************************************************************************/
void Timer1_voidOC1ASetDutyCycle(uint8_t LOC_U8DutyCycle, uint16_t LOC_U16Top);
/************************************************************************************/

/************************************************************************************/
/* Description: sends a PWM signal with the received duty cycle (0% - 100%) on		*/
/* OC1B pin.																		*/
/* Inputs: Duty cycle - Counter top value (minimum 0x0003)			 	 		    */
/* Output: void								  									    */
/************************************************************************************/
void Timer1_voidOC1BSetDutyCycle(uint8_t LOC_U8DutyCycle, uint16_t LOC_U16Top);
/************************************************************************************/

/************************************************************************************/
/* Description: returns the value in timer1's counter. Counts are in the range of   */
/* 0 - 65535.					    													*/
/* Inputs: pointer to a variable to receive the value in			 	 		    */
/* Output: void								  						    */
/************************************************************************************/
void Timer1_voidGetCounterValue(uint16_t* LOC_U16Value);
/************************************************************************************/

/************************************************************************************/
/* Description: activates the Input Capture Noise Canceler. When the Noise			*/
/* Canceler is activated, the input from the Input Capture Pin (ICP1) is filtered.	*/
/* Notice that The input capture is delayed by four Oscillator cycles when the 		*/
/* Noise Canceler is enabled														*/
/* Inputs: nothing			 	 		    										*/
/* Output: void								  						    */
/************************************************************************************/
void Timer1_voidEnableNoiseCanceler(void);
/************************************************************************************/

/************************************************************************************/
/* Description: deactivates the Input Capture Noise Canceler. 						*/
/* Inputs: nothing			 	 		    										*/
/* Output: void								  						    */
/************************************************************************************/
void Timer1_voidDisableNoiseCanceler(void);
/************************************************************************************/

/************************************************************************************/
/* Description: selects which edge on the Input Capture Pin (ICP1) that is used to	*/
/* trigger a capture event. 														*/
/* Inputs: nothing			 	 		    										*/
/* Output: void								  						    */
/************************************************************************************/
void Timer1_voidICEdgeSelect(uint8_t LOC_voidEdge);
/************************************************************************************/

/************************************************************************************/
/* Description: gets the value captured on the Input Capture Pin (ICP1). ICR1		*/
/* should not be used for defining TOP in this case in order to function correctly.	*/
/* Inputs: pointer to a variable to receive the value in							*/
/* Output: void								  						    */
/************************************************************************************/
void Timer1_voidGetCapturedValue(uint16_t* LOC_U16Value);
/************************************************************************************/

/************************************************************************************/
/* Description: enables overflow interrupt										    */
/* Inputs: nothing													 	 		    */
/* Output: void								  						    */
/************************************************************************************/
void Timer1_voidOVFEnableInterrupt(void);
/************************************************************************************/

/************************************************************************************/
/* Description: disables overflow interrupt										    */
/* Inputs: nothing													 	 		    */
/* Output: void								  						    */
/************************************************************************************/
void Timer1_voidOVFDisableInterrupt(void);
/************************************************************************************/

/************************************************************************************/
/* Description: Output Compare A Match interrupt enable							    */
/* Inputs: nothing													 	 		    */
/* Output: void								  						    */
/************************************************************************************/
void Timer1_voidOCAEnableInterrupt(void);
/************************************************************************************/

/************************************************************************************/
/* Description: Output Compare A Match interrupt disable						    */
/* Inputs: nothing													 	 		    */
/* Output: void								  						    */
/************************************************************************************/
void Timer1_voidOCADisableInterrupt(void);
/************************************************************************************/

/************************************************************************************/
/* Description: Output Compare B Match interrupt enable							    */
/* Inputs: nothing													 	 		    */
/* Output: void								  						    */
/************************************************************************************/
void Timer1_voidOCBEnableInterrupt(void);
/************************************************************************************/

/************************************************************************************/
/* Description: Output Compare B Match interrupt disable						    */
/* Inputs: nothing													 	 		    */
/* Output: void								  						    */
/************************************************************************************/
void Timer1_voidOCBDisableInterrupt(void);
/************************************************************************************/

/************************************************************************************/
/* Description: Capture Event interrupt enable									    */
/* Inputs: nothing													 	 		    */
/* Output: void								  						    */
/************************************************************************************/
void Timer1_voidCaptureEventEnableInterrupt(void);
/************************************************************************************/

/************************************************************************************/
/* Description: Capture Event interrupt disable									    */
/* Inputs: nothing													 	 		    */
/* Output: void								  						    */
/************************************************************************************/
void Timer1_voidCaptureEventDisableInterrupt(void);
/************************************************************************************/

/***********************************************************************************/
/* Description: polls on timer1 overflow's flag						 			   */
/* Inputs: nothing					   											   */
/* Output: void								  						   */
/***********************************************************************************/
void Timer1_voidOVFPollingOnFlag(void);
/***********************************************************************************/

/***********************************************************************************/
/* Description: polls on timer1 Output Compare A Match flag			 			   */
/* Inputs: nothing					   											   */
/* Output: void								  						   */
/***********************************************************************************/
void Timer1_voidOCAPollingOnFlag(void);
/***********************************************************************************/

/***********************************************************************************/
/* Description: polls on timer1 Output Compare B Match flag			 			   */
/* Inputs: nothing					   											   */
/* Output: void								  						   */
/***********************************************************************************/
void Timer1_voidOCBPollingOnFlag(void);
/***********************************************************************************/

/***********************************************************************************/
/* Description: polls on timer1 Capture Event flag					 			   */
/* Inputs: nothing					   											   */
/* Output: void								  						   */
/***********************************************************************************/
void Timer1_voidCaptureEventPollingOnFlag(void);
/***********************************************************************************/

/***********************************************************************************/
/* Description: takes a pointer to a function that is to be executed on		  	   */
/* triggering the overflow interrupt.  								 			   */
/* Inputs: pointer to a function that takes no arguments and returns no value	   */
/* Output: void								  						   */
/***********************************************************************************/
void Timer1_voidOVFSetCallBack( void (*ptrToFun)(void) );
/***********************************************************************************/

/***********************************************************************************/
/* Description: takes a pointer to a function that is to be executed on		  	   */
/* triggering the Output Compare A Match flag						 			   */
/* Inputs: pointer to a function that takes no arguments and returns no value	   */
/* Output: void								  						   */
/***********************************************************************************/
void Timer1_voidOCASetCallBack( void (*ptrToFun)(void) );
/***********************************************************************************/

/***********************************************************************************/
/* Description: takes a pointer to a function that is to be executed on		  	   */
/* triggering the Output Compare B Match flag						 			   */
/* Inputs: pointer to a function that takes no arguments and returns no value	   */
/* Output: void								  									   */
/***********************************************************************************/
void Timer1_voidOCBSetCallBack( void (*ptrToFun)(void) );
/***********************************************************************************/

/***********************************************************************************/
/* Description: takes a pointer to a function that is to be executed on		  	   */
/* triggering the Capture Event flag								 			   */
/* Inputs: pointer to a function that takes no arguments and returns no value	   */
/* Output: void								  									   */
/***********************************************************************************/
void Timer1_voidCaptureEventSetCallBack( void (*ptrToFun)(void) );
/***********************************************************************************/

/***********************************************************************************/
/* Description: restarts timer1's prescaler. Note that this	affects both timer0	   */
/* and timer1						 			   			   					   */
/* Inputs: nothing					   											   */
/* Output: void								  									   */
/***********************************************************************************/
void Timer1_voidResetPrescaler(void);
/***********************************************************************************/
void Timer1_PWM_Init();
void Timer1_PWM_Freq_KHz(uint16_t Freq ) ;
void Timer1_PWM_Freq_Hz(uint16_t Freq );
void Timer1_PWM_Duty(uint8_t duty);
#endif /* TIMER1_INTERFACE_H_ */