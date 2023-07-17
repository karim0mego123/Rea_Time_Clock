/*
 * USART.c
 *
 * Created: 2/10/2023 5:01:04 PM
 *  Author: karim
 */ 
#include "USART.h"



ES_t USART_Init()
{
	ES_t Loc_Init_Status = NO_Error ;

	#if Speed_Mode == Normal_Speed
	UCSRA |=(1<<U2X) ; 
	#endif

	#if	UART_MODE == Transciever
	 SET_BIT(UCSRB,TXEN);
	 SET_BIT(UCSRB,RXEN);
	#endif
	
	uint8_t Loc_u8UCSRC = 0 ; // UCSRC can not use bit access so i made variable to bit access intreed of register
	
	#if UART_Clock == Asynchronous
	Loc_u8UCSRC &=~ (1<<6) ; 
	#endif

	#if Data_Len == Eight
	Loc_u8UCSRC |= (3<<1);
	#endif

	#if Parity_State == NO_parity 
	Loc_u8UCSRC &=~ (3<<4);
	#endif
	
	#if STOP_State == One_Bit
	Loc_u8UCSRC &=~ (1<<3);
	#endif

	Loc_u8UCSRC |= (1<<7) ;  	// Select Regester UCsrc by write one in bit 7 or UBRRH 0 
	UCSRC = Loc_u8UCSRC ; 
	
 	uint16_t Loc_u16UBRR = MYUBRR(BAUD);
 	Loc_u16UBRR &=~ (1<<15);	// Select Regester UCsrc by write one in bit 7 or UBRRH 0 
 	UBRRL = (uint8_t) Loc_u16UBRR ;
 	UBRRH |= (uint8_t) (Loc_u16UBRR>>8) ;
	 
	return Loc_Init_Status ; 
}

ES_t USART_Send_Char(uint8_t Data )
{
	ES_t Loc_TX_Status = NO_Error ;
		while(!(UCSRA&(1<<UDRE)) );
		UDR = Data ; 
	return Loc_TX_Status ; 
}
ES_t USART_Recieve_Char( uint8_t* Data )
{
	ES_t Loc_RX_Status = NO_Error ;
	if(Data==NULL)
	{
		Loc_RX_Status = Error ; 
	}
	else
	{
		while(!( (UCSRA>>RXC) & 1) );
		*Data = UDR ; 
	}
	return Loc_RX_Status ; 
}
ES_t USAERT_Send_STRING(uint8_t* String)
{
	ES_t Loc_TX_String_Status = NO_Error ;
	if(String==NULL)
	{
		Loc_TX_String_Status = Error ; 
	}
	else
	{
		while (*String != '\0')
		{
			USART_Send_Char(*String);
			String++ ;
		}
	}
	return Loc_TX_String_Status ; 
}
ES_t USAERT_Recieve_STRING(uint8_t* String)
{
	ES_t Loc_RX_STRING_Status = NO_Error ;
	if(String==NULL)
	{
		Loc_RX_STRING_Status = Error ; 
	}
	while (1)
	{
		USART_Recieve_Char(String);
		if(*String == '\r' || *String == '\n')
		{
			*String = '\0' ; 
			break;
		}
		String++;
	}
	return Loc_RX_STRING_Status ; 
}






























