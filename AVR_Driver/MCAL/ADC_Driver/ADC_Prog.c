/*
 * ADC.c
 *
 * Created: 4/23/2023 3:26:49 PM
 *  Author: karim
 */ 
#include "ADC_INT.h"
#include "DIO.h"
#include "Types.h"
#include "EXTI.h"

static void (*ADC_GptrFun)(uint16_t*) = NULL ; 
static uint16_t* ADCGptrParameter = NULL  ; 

/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : ADC_enuInit.                                          **/
/**	Return Type     : ERROR_STATES enum.                                    **/
/**	Arguments       : void.                                                 **/
/**	Functionality   : Setting prescaler , adjustment and reference voltage. **/
/*****************************************************************************/
/*****************************************************************************/
ES_t ADC_INIT()
{
	ES_t Local_ErrorState = NO_Error ;	
		
	#if ( ADC_PRES == PRES_2 )
	{
		PRESCALER_TWO ;
	}
	#elif ( ADC_PRES == PRES_4 )
	{
		PRESCALER_FOUR	;
	}
	#elif (ADC_PRES == PRES_8)
	{
		PRESCALER_EIGHT	;		
	}
	#elif (ADC_PRES == PRES_16)
	{
		PRESCALER_SIXTEEN ;		
	}
	#elif (ADC_PRES == PRES_32)
	{
		PRESCALER_THIRTY_TWO ;		
	}
	#elif (ADC_PRES == PRES_64)
	{
		PRESCALER_SIXTY_FOUR ;		
	}
	#elif (ADC_PRES == PRES_128)
	{
		PRESCALER_HUNDRED_TWENTY_EIGHT ;		
	}
	#else

#endif
	#if AD_REF_VOLT == AREF
	{
		AREF_VOLTAGE ; 
	} 
	#elif AD_REF_VOLT == INTERNAL
	{
		INTERNAL_VOLTAGE ;							
	}
	#elif AD_REF_VOLT == AVCC_REF
	{
		AVCC_VOLTAGE ;
	}
	#else
	{
	}
	#endif
	#if ADC_ADJ == RIGHT_ADJ
	{
		RIGHT_ADJUSTMENT	;						
	}
	#elif ADC_ADJ == LEFT_ADJ
	{
		LEFT_ADJUSTMENT		;						
	}
	#else
	{
	}
#endif

	ENABLE_ADC;

	return Local_ErrorState ; 
}

/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : ADC_Start.										    **/
/**	Return Type     : ES_t enum.								            **/
/**	Arguments       : void.                                                 **/
/**	Functionality   : Starting of ADC Conversion					        **/
/*****************************************************************************/
/*****************************************************************************/
 ES_t ADC_Start()
{
	ES_t Local_ErrorState = NO_Error ;
	
	START_CONVERSION	;						 
	
	return Local_ErrorState ;
}
/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : ADC_PollingSystem.                                    **/
/**	Return Type     : ES_t enum.				                            **/
/**	Arguments       : void.                                                 **/
/**	Functionality   : Polling on rising ADC flag, then clear it.            **/
/*****************************************************************************/
/*****************************************************************************/
ES_t ADC_PollingSystem() 
{
	ES_t Local_ErrorState = NO_Error ;
	
	while(((ADCSRA>>4)&1)==0);
	CLEAR_FLAG	;						
	
	return Local_ErrorState ;
}
/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : ADC_ReadHighValue.		                            **/
/**	Return Type     : ES_t enum.			                                **/
/**	Arguments       : Address of Variable which will Carry ADC Value.       **/
/**	Functionality   : Reading the highest 8 bit of ADC resolution register. **/
/*****************************************************************************/
/*****************************************************************************/
ES_t ADC_ReadHighValue(uint16_t* copy_Value) 
{
	ES_t Local_ErrorState = NO_Error ;
	
	#if ADC_ADJ == LEFT_ADJ
	{
		*copy_Value = ADCL>>6 ;
		*copy_Value |= ADCH<<2 ;
	}
	#elif ADC_ADJ == RIGHT_ADJ
	{
		*copy_Value = ADCL ;
		*copy_Value |= (ADCH<<8) ;
	}
	#else
	{
	}
	#endif
	
	return Local_ErrorState ;
}
/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : ADC_Read.						                        **/
/**	Return Type     : ES_t enum.				                            **/
/**	Arguments       : Address of Variable which will Carry ADC Value.       **/
/**	Functionality   : Reading All ADC resolution register.                  **/
/*****************************************************************************/
/*****************************************************************************/
ES_t ADC_Read(uint16_t* copy_value) 
{
	ES_t Local_ErrorState = NO_Error ;
	
	#if ADC_ADJ == LEFT_ADJ
	{
		*copy_value = ADCL ;
	}
	#elif ADC_ADJ == RIGHT_ADJ
	{
		*copy_value = ADCL ;
		*copy_value |= ((uint16_t)ADCH<<8) ;
	}
	#else
	{
	}
	#endif	
	
	return Local_ErrorState ;
}
/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : ADC_CallBack.					                        **/
/**	Return Type     : ES_t enum.		                                    **/
/**	Arguments       : ptr to a void func having generic ptr & this generic. **/
/**	Functionality   : Starting of ADC Conversion.                           **/
/*****************************************************************************/
/*****************************************************************************/
ES_t ADC_CallBack(void(*Copy_PtrFun)(uint16_t*),uint16_t* copy_AppParameter) 
{
	ES_t Local_ErrorState = NO_Error ;
	
	if (Copy_PtrFun != NULL)
	{
		ADC_GptrFun = Copy_PtrFun ;
		ADCGptrParameter = copy_AppParameter ;  
	}
	return Local_ErrorState ;
}
/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : ADC_Select_Channel.                                  **/
/**	Return Type     : ES_t enum.					                       **/
/**	Arguments       : Number of ADC Channel.                                **/
/**	Functionality   : Selecting of ADC Channel.                             **/
/*****************************************************************************/
/*****************************************************************************/
ES_t ADC_Select_Channel(Channel_Id_e Chacnnel_Id) 
{
	ES_t Local_ErrorState = NO_Error ;
	
	ADMUX &=~ 0x1F ; 
	
	ADMUX |= Chacnnel_Id ;
		
	return Local_ErrorState ;
}
/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : ADC_Enable_Triggring_Mode.                            **/
/**	Return Type     : ES_t enum.		                                    **/
/**	Arguments       : void.                                                 **/
/**	Functionality   : Enabling the ADC Trigger.                             **/
/*****************************************************************************/
/*****************************************************************************/
ES_t ADC_Enable_Triggring_Mode(uint8_t copy_TriggeringSource) 
{
	ES_t Local_ErrorState = NO_Error ;
	
	DISABLE_TRIGGER ;
	
	switch(copy_TriggeringSource)
	{
		case FREE_RUNNIG : 
			SFIOR &=~ (1<<5) ;
			SFIOR &=~ (1<<6) ;
			SFIOR &=~ (1<<7) ;
			break ;
		case EXTI0_TRIG : 
			SFIOR &=~ (1<<5) ;
			SFIOR |= (1<<6) ;
			SFIOR &=~ (1<<7) ;
			break ; 
			default:break ; 
	}
	
	ENABLE_TRIGGER	;							 
	
	return Local_ErrorState ;
}
/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : ADC_Disable_Triggring_Mode.                           **/
/**	Return Type     : ES_t enum.			                                **/
/**	Arguments       : void.                                                 **/
/**	Functionality   : Disabling the ADC Trigger.                            **/
/*****************************************************************************/
/*****************************************************************************/
ES_t ADC_Disable_Triggring_Mode() 
{
	ES_t Local_ErrorState = NO_Error ;
	
	DISABLE_TRIGGER; 
	
	return Local_ErrorState ;
}

/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : ADC_EnableInterruptMode.                               **/
/**	Return Type     : ES_t enum.											**/
/**	Arguments       : void.                                                 **/
/**	Functionality   : Enabling the ADC Interrupt.                           **/
/*****************************************************************************/
/*****************************************************************************/
ES_t ADC_EnableInterruptMode() 
{
	ES_t Local_ErrorState = NO_Error ;
	
	ENABLE_ADC_INTERRUPT ; 							 
	
	return Local_ErrorState ;
}
ISR(ADC_vect)
{
	if (ADC_GptrFun != NULL)
	{
		ADC_GptrFun(ADCGptrParameter) ; 
	}
}