/*
 * ADC_INT.h
 *
 * Created: 4/23/2023 3:27:30 PM
 *  Author: karim
 */ 

#include "ErrorState.h"
#include "Types.h"
#include "ADC_Privite.h"
#include "ADC_Config.h"

#ifndef ADC_INT_H_
#define ADC_INT_H_

typedef enum
{
	CHANNEL_0 ,
	CHANNEL_1 ,
	CHANNEL_2 ,
	CHANNEL_3,
	CHANNEL_4,
	CHANNEL_5,
	CHANNEL_6,
	CHANNEL_7	
} Channel_Id_e ;

ES_t ADC_INIT();
ES_t ADC_Start();
ES_t ADC_PollingSystem() ; 
ES_t ADC_ReadHighValue(uint16_t* copy_Value) ; 
ES_t ADC_Read(uint16_t* copy_value) ; 
ES_t ADC_CallBack(void(*Copy_PtrFun)(uint16_t*) , uint16_t* copy_AppParameter) ; 
ES_t ADC_Select_Channel( Channel_Id_e Id ) ; 
ES_t ADC_Enable_Triggring_Mode(uint8_t copy_TriggeringSource) ; 
ES_t ADC_Disable_Triggring_Mode() ;
ES_t ADC_EnableInterruptMode() ; 


#endif /* ADC_INT_H_ */