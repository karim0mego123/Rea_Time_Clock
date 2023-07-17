/*
 * DC_Motor.c
 *
 * Created: 7/16/2023 10:59:22 PM
 *  Author: karim
 */ 
#include "DC_Motor_Interface.h"
#include "DIO.h"

void DC_Motor_Init() 
{
	DIO_Write_Pin_Dir(DC_IN1_PORT,DC_IN1_PIN,OUT);	
	DIO_Write_Pin_Dir(DC_IN2_PORT,DC_IN2_PIN,OUT);
	DIO_Write_Pin_Dir(DC_EN_PORT,DC_EN_PIN,IN);
}
void DC_Motor_Move_Right() 
{
	DIO_Write_Pin(DC_IN1_PORT,DC_IN1_PIN,HIGH);
	DIO_Write_Pin(DC_IN2_PORT,DC_IN2_PIN,LOW);
}
void DC_Motor_Move_Left() 
{
	DIO_Write_Pin(DC_IN1_PORT,DC_IN1_PIN,LOW);
	DIO_Write_Pin(DC_IN2_PORT,DC_IN2_PIN,HIGH);
}
void DC_Motor_Stop()
{
	DIO_Write_Pin(DC_IN1_PORT,DC_IN1_PIN,LOW);
	DIO_Write_Pin(DC_IN2_PORT,DC_IN2_PIN,LOW);
}