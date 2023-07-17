/*
 * Private.h
 *
 * Created: 2/27/2023 4:06:11 PM
 *  Author: karim
 */ 


#ifndef PRIVATE_H_
#define PRIVATE_H_

#include "Types.h"
#include "DIO.h"

#define	SS		GPIO_PIN_4
#define MOSI	GPIO_PIN_5
#define MISO	GPIO_PIN_6
#define SCK		GPIO_PIN_7

#define SPDR	*(volatile uint8_t*)(0x2F)
#define LSB        0 
#define MSB        7 

#define SPSR	*(volatile uint8_t*)(0x2E)
#define SPI2X        0 
#define WCOL         6 
#define SPIF         7

#define SPCR	*(volatile uint8_t*)(0x2D)
#define SPR0        0 
#define SPR1        1 
#define CPHA        2 
#define CPOL        3 
#define MSTR        4 
#define DORD        5 
#define SPE         6 
#define SPIE        7 

#define MSB_FIRST   1
#define LSB_FIRST   2

#define MASTER_MODE 0
#define SLAVE_MODE  1

#define Enable      1
#define Disable     0

#endif /* PRIVATE_H_ */