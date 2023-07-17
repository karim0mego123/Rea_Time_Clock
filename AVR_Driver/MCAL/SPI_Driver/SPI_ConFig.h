/*
 * SPI_ConFig.h
 *
 * Created: 2/27/2023 4:06:55 PM
 *  Author: karim
 */ 


#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

#include "SPI_Private.h"

/*-------------------------DATA_ORDER-------------------------*/
// the LSB of the data word is transmitted first --> LSB_FIRST
// the MSB of the data word is transmitted first --> MSB_FIRST
#define DATA_ORDER      MSB_FIRST

/*-------------------------SPI_MODE-------------------------*/
/* 1.) 0 ----> Read on rising edge, write on falling edge    -->Leading = rising
 * 2.) 1 ----> Read on falling edge, write on rising edge    -->Leading = rising
 * 3.) 2 ----> Read on falling edge, write on falling edge	 -->Leading = falling
 * 4.) 3 ----> Read on rising edge, write on falling edge	 -->Leading = falling 
 */
#define SAMPLING_MODE    0

#define MASTER_MODE     0
#define SLAVE_MODE      1
#define SPI_MODE	MASTER_MODE

/*When this bit is written logic one the SPI speed (SCK Frequency) will be doubled when
  the SPI is in Master mode
*/
#define NORMAL_SPEED      0
#define DOUBLE_SPEED      1

#define SPEED_MODE      NORMAL_SPEED

#endif /* SPI_CONFIG_H_ */