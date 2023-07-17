/*
 * SPI.c
 *
 * Created: 2/27/2023 4:00:03 PM
 *  Author: karim
 */ 
#include "SPI.h"
#include "ErrorState.h"
#include "SPI_Private.h"
#include "SPI_ConFig.h"

ES_t MCAL_SPI_Init()
{

    ES_t Init_Status = NO_Error ; 
	
    #if SPI_MODE == MASTER_MODE
    {
		MCAL_SPI_Set_Pins_Master() ;
       SPCR |= (1<<MSTR) ; 
        // MAX BaudRate
        SPCR |= (1<<SPR0);
	    SPCR |= (1<<SPE) ; //  SPI Enable
		SET_BIT(PORTB,4);
       Init_Status = NO_Error ; 
    }
    #elif SPI_MODE == SLAVE_MODE
    {
	    SPCR |= (1<<SPE) ; //  SPI Enable
		MCAL_SPI_Set_Pins_SLAVE();
        Init_Status = NO_Error ; 
    }
    #else
    {
        Init_Status = Error ; 
    }
    #endif

    #if DATA_ORDER == MSB_FIRST
    {
        SPCR &=~ (1<<DORD);
        Init_Status = NO_Error ; 
    }    
    #elif DATA_ORDER == LSB_FIRST 
    {
        SPCR |= (1<<DORD);
        Init_Status = NO_Error ; 
    }
    #else
    {
        Init_Status = Error ; 
    }
    #endif

    #if SAMPLING_MODE == 0
    {
        SPCR &=~(1<<CPOL);
        SPCR &=~(1<<CPHA);
        Init_Status = NO_Error ; 
    }
    #elif SAMPLING_MODE == 1
    {
        SPCR &=~(1<<CPOL);
        SPCR |= (1<<CPHA);
        Init_Status = NO_Error ; 
    }
    #elif SAMPLING_MODE == 2
    {
        SPCR |= (1<<CPOL);
        SPCR &=~(1<<CPHA);
        Init_Status = NO_Error ; 
    }
    #elif SAMPLING_MODE == 3
    {
        SPCR |= (1<<CPOL);
        SPCR |= (1<<CPHA);
         Init_Status = NO_Error ; 
    }
    #else
    {
        Init_Status = Error ; 
    }
    #endif

    #if SPEED_MODE == NORMAL_SPEED
    {
	    SPCR &=~ (1<<SPI2X);
        Init_Status = NO_Error ; 
    }
    #elif  SPEED_MODE == DOUBLE_SPEED 
    {
	    SPSR |= (1<<SPI2X);
        Init_Status = NO_Error ; 
    }
    #else
    {
        Init_Status = Error ; 
    }
    #endif
	
    return Init_Status ;
}
uint8_t MCAL_SPI_MasterSend_Data(uint8_t DataSend  )
{
	CLEAR_BIT(PORTB,4);
	SPDR = DataSend ; 
	while( GET_BIT(SPSR,SPIF)==0);
	return SPDR ; 
}
uint8_t MCAL_SPI_SlaveRecieve_Data(uint8_t DataSend )
{
	SPDR = DataSend ;
	while( GET_BIT(SPSR,SPIF)==0);
	return SPDR ; 
}
ES_t MCAL_SPI_TX_RX(uint8_t DataSend , uint8_t* DataRecieve)
{
	 ES_t Init_Status = NO_Error ;
	SPDR = DataSend ;
	while( (SPSR&&(1<<SPIF) )==0);
	*DataRecieve = SPDR ;
	return Init_Status ;
}
void MCAL_SPI_Set_Pins_Master(void)
{
	DDRB |= 0xB0 ; 
}
void MCAL_SPI_Set_Pins_SLAVE(void)
{
	DDRB |= 0x40 ;
}