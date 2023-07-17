/*
 * Ultrasonic_Interface.h
 *
 * Created: 7/17/2023 2:18:02 AM
 *  Author: karim
 */ 


#ifndef ULTRASONIC_INTERFACE_H_
#define ULTRASONIC_INTERFACE_H_

#include "Timer1_Interface.h"
#include "Ultrasonic_Config.h"
#include "Ultrasonic_Priv.h"

void Ultrasonic_VoidInit() ;

void Ultrasonic_VoidReadDistance(uint8_t*Distance) ;


#endif /* ULTRASONIC_INTERFACE_H_ */