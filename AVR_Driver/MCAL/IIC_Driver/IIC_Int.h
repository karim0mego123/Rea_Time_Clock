#ifndef  _TWI_INT_H_
#define  _TWI_INT_H_

#include "utils.h"
#include "Types.h"
#include "ErrorState.h"
#include "IIC_Priv.h"
#include "IIC_Congig.h"
#define F_CPU		1000000UL

ES_t IIC_MasterInit(void);

ES_t IIC_SlaveInit(uint8_t LOC_uint8_tSlaveAdress);

ES_t IIC_StartCondition(void);

ES_t IIC_RepeatedStartCondition(void);

ES_t IIC_SendSlaveAdress(uint8_t LOC_uint8_tSlaveAdress , uint8_t operation) ;

ES_t IIC_MasterSendData(uint8_t LOC_uint8_tData);

ES_t IIC_SlaveReceieveData(uint8_t*ReceivedData) ;

ES_t IIC_StopCondition(void);











#endif