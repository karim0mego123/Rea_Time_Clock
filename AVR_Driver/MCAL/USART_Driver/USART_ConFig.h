/*
 * USART_ConFig.h
 *
 * Created: 2/10/2023 5:01:27 PM
 *  Author: karim
 */ 


#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_

#define Synchronous         0
#define Asynchronous        1
#define UART_Clock          Asynchronous

#define Normal_Speed        1
#define Double_Speed        2
#define Speed_Mode          Normal_Speed 

#define TransMetter         0 
#define REciever            1
#define Transciever         2    
#define UART_MODE           Transciever

#define Five                5
#define Eight               8

#define NO_parity           0
#define Odd_Parity          1
#define Even_Parity         2

#define One_Bit             1
#define Two_Bits            2

#define Data_Len            Eight
#define Parity_State        NO_parity
#define STOP_State          One_Bit

#define FSOC	            8000000L // CLOCK SPEED
#define BAUD	            9600



#endif /* USART_CONFIG_H_ */