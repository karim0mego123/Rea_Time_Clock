/*
 * SPI.h
 *
 * Created: 2/27/2023 4:00:13 PM
 *  Author: karim
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "SPI_Private.h"
#include "Types.h"
#include "utils.h"
#include "ErrorState.h"




ES_t MCAL_SPI_Init();
uint8_t MCAL_SPI_MasterSend_Data(uint8_t DataSend  );
uint8_t MCAL_SPI_SlaveRecieve_Data(uint8_t DataSend );
ES_t MCAL_SPI_TX_RX(uint8_t Buffer , uint8_t* Buffer1);
void MCAL_SPI_Set_Pins_Master(void);
void MCAL_SPI_Set_Pins_SLAVE(void);

#endif /* SPI_H_ */