/*
 * Stepper_Motor_Config.h
 *
 * Created: 7/17/2023 5:17:10 PM
 *  Author: karim
 */ 


#ifndef STEPPER_MOTOR_CONFIG_H_
#define STEPPER_MOTOR_CONFIG_H_

#include "Regesters.h"

#define STEPPER_MOTOR_FULL_STEP		1
#define STEPPER_MOTOR_HALF_STEP		0

#define STEPPER_MOTOR_MODE			STEPPER_MOTOR_FULL_STEP

#define STEPPER_MOTOR_PIN0			PIN0
#define STEPPER_MOTOR_PORT0			PORT_C

#define STEPPER_MOTOR_PIN1			PIN1
#define STEPPER_MOTOR_PORT1         PORT_C

#define STEPPER_MOTOR_PIN2          PIN2
#define STEPPER_MOTOR_PORT2         PORT_C

#define STEPPER_MOTOR_PIN3          PIN3
#define STEPPER_MOTOR_PORT3         PORT_C




#endif /* STEPPER_MOTOR_CONFIG_H_ */