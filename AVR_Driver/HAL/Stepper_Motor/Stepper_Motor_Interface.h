/*
 * Stepper_Motor_Interface.h
 *
 * Created: 7/17/2023 5:16:25 PM
 *  Author: karim
 */ 


#ifndef STEPPER_MOTOR_INTERFACE_H_
#define STEPPER_MOTOR_INTERFACE_H_

#include "Types.h"
#include "Regesters.h"
#include "DIO.h"
#include "Stepper_Motor_Priv.h"
#include "Stepper_Motor_Config.h"

void Stepper_Motor_Init() ;
void Stepper_Motor_GoForward() ; 
void Stepper_Motor_GoBackward() ;
void Stepper_Motor_TurnOff() ;

#endif /* STEPPER_MOTOR_INTERFACE_H_ */