/*
 * DIO.h
 *
 * Created: 12/13/2022 11:58:39 AM
 *  Author: karim
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "Regesters.h"
#include "util\delay.h"
#include "..\utilities\Types.h"
#include "..\utilities\utils.h"

// All Driver Macros
#define PORT_A	'A'
#define PORT_B	'B'
#define PORT_C	'C'
#define PORT_D	'D'

//** PORT states **//
#define LOW 0
#define HIGH 1

//** GPIO PINS **//

#define GPIO_PIN_0							0X01U
#define GPIO_PIN_1							0X02U
#define GPIO_PIN_2							0X04U
#define GPIO_PIN_3							0X08U
#define GPIO_PIN_4							0X10U
#define GPIO_PIN_5							0X20U
#define GPIO_PIN_6							0X40U
#define GPIO_PIN_7							0X80U
#define GPIO_PIN_AL							0XFFU

// Value_Defination
#define High	1
#define Low		0

//** PORT directions **//
#define IN 0
#define OUT 1

// DIO_PrortoTypes
void DIO_Write_Pin_Dir( uint8_t PortNumber , uint8_t PinNumber , uint8_t Direction ) ;
void DIO_Write_Port_Dir( uint8_t PortNumber , uint8_t Direction ) ;
void DIO_Write_Pin( uint8_t PortNumber , uint8_t PinNumber , uint8_t value  ) ;
void DIO_Write_Port( uint8_t PortNumber , uint8_t value  ) ;
void DIO_Read( uint8_t PortNumber , uint8_t PinNumber , uint8_t* value  );
void DIO_Toggle_Pin( uint8_t PortNumber , uint8_t PinNumber  );
void DIO_Toggle_Port( uint8_t PortNumber   );



#endif /* DIO_H_ */