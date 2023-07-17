/*
 * USART.h
 *
 * Created: 2/10/2023 5:01:42 PM
 *  Author: karim
 */ 


#ifndef USART_H_
#define USART_H_

#include "utils.h"
#include "ErrorState.h"
#include "Types.h"
#include "Regesters.h"
#include "USART_ConFig.h"



ES_t USART_Init();
ES_t USART_Send_Char(uint8_t Data );
ES_t USART_Recieve_Char( uint8_t* Data );
ES_t USAERT_Send_STRING(uint8_t* String);
ES_t USAERT_Recieve_STRING(uint8_t* Data);




#endif /* USART_H_ */