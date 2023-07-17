#include "IIC_Int.h"


ES_t IIC_MasterInit(void)
{
	ES_t Loc_ErrorState = NO_Error ; 
	TWBR=(unsigned char) (((F_CPU/IIC_CLKSPEED)-16)/(2*PRES));
	
	/*TWPS-PRESCALER*/
	if (PRES == PRES_1)
	{
		TWSR = 0 ;	
	}
	else  if (PRES == PRES_4)
	{
		TWSR = 1 ;
	}
	else if (PRES == PRES_16)
	{
		TWSR = 2 ;
	}
	else if (PRES == PRES_64)
	{
		TWSR = 3 ; 
	}
	
	/*Enable IIC*/
	SET_BIT(TWCR,TWEN);
	
	return Loc_ErrorState ; 
	
}

ES_t IIC_SlaveInit(uint8_t LOC_uint8_tSlaveAdress)
{
	ES_t Loc_ErrorState = NO_Error ;
	
	/*TWAR-SLAVE ADRESS*/
	TWAR = LOC_uint8_tSlaveAdress<<1  ;
	
	/*Enable IIC*/
	SET_BIT(TWCR,TWEN);
	
	return Loc_ErrorState ;

}

ES_t IIC_StartCondition(void)
{
	ES_t Loc_ErrorState = NO_Error ;
	/*CLEAR FLAG*/
	SET_BIT(TWCR,TWINT);
	/*START CONDITION */
	SET_BIT(TWCR,TWSTA);
	/*Enable IIC*/	
	SET_BIT(TWCR,TWEN);
	while ( (GET_BIT(TWCR,TWINT)) != 1); //WAITING FOR FLAG
	while( (TWSR&0xF8) != STARTCONDITION);

	return Loc_ErrorState ;
	
}

ES_t IIC_SendSlaveAdress(uint8_t LOC_uint8_tSlaveAdress , uint8_t operation)
{
	ES_t Loc_ErrorState = NO_Error ;
	
	TWDR=((LOC_uint8_tSlaveAdress<<1)|operation);
	/*CLEAR FLAG*/
	SET_BIT(TWCR,TWINT);
	/*Enable IIC*/
	SET_BIT(TWCR,TWEN);
	
	while ( (GET_BIT(TWCR,TWINT)) != 1); //WAITING FOR FLAG
	
	if (operation==0)
	{
		while((TWSR&0xF8) != SendSlaveAdressWithWrite ) ;
	}
	else if (operation==1)
	{
		while((TWSR&0xF8) != SendSlaveAdressWithRead );
	}
	
	return Loc_ErrorState ;
}

ES_t IIC_MasterSendData(uint8_t LOC_uint8_tData)
{
	ES_t Loc_ErrorState = NO_Error ;
	
	TWDR = LOC_uint8_tData;
	
	/*CLEAR FLAG*/
	SET_BIT(TWCR,TWINT);
	/*Enable IIC*/
	SET_BIT(TWCR,TWEN);
	
	while ( (GET_BIT(TWCR,TWINT)) != 1); //WAITING FOR FLAG
	
	while((TWSR&0xF8) != MasterSendData );

	return Loc_ErrorState;
	
}

ES_t IIC_SlaveReceieveData(uint8_t*ReceivedData)
{
	ES_t Loc_ErrorState = NO_Error ;
	/*CLEAR FLAG*/
	SET_BIT(TWCR,TWINT);
	// Enable Ack
	SET_BIT(TWCR,TWEA);
	/*CLEAR START CONDITION */
	SET_BIT(TWCR,TWEN);
	
	while ( (GET_BIT(TWCR,TWINT)) != 1); //WAITING FOR FLAG
	while((TWSR&0xF8) != SLAVERECIEVE );
	*ReceivedData = TWDR ; 
	return Loc_ErrorState;
}

ES_t IIC_StopCondition(void)
{
	ES_t Loc_ErrorState = NO_Error ;
	
	/*CLEAR FLAG*/
	SET_BIT(TWCR,TWINT);
	/*Enable IIC*/
	SET_BIT(TWCR,TWEN);
	/*STOP CONDITION */
	SET_BIT(TWCR,TWSTO);
	
	return Loc_ErrorState ;
	
}

