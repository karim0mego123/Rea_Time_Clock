#ifndef  _TWI_CONFIG_H_
#define  _TWI_CONFIG_H_



/*TWI Control Register -TWCR*/
#define TWINT     7
#define TWEA      6
#define TWSTA     5
#define TWSTO     4
#define TWWC      3
#define TWEN      2
#define TWIE      0

/*TWBR RRES 1 4 16 64*/
//  PRES_1		
//  PRES_4		
//  PRES_16		
//  PRES_64	
#define PRES	PRES_1
 
// IIC_CLKSPEED_100K
// IIC_CLKSPEED_400K
#define IIC_CLKSPEED	IIC_CLKSPEED_100K
/*TWI Status Register -TWSR*/
#define TWS7      7
#define TWS6      6
#define TWS5      5
#define TWS4      4
#define TWS3      3
#define TWPS1     1
#define TWPS0     0

/*TWI Slave Adress Register -TWAR*/
#define TWGCE     0

/*TWI ERROR STATE*/
#define NOK    0
#define OK     1









#endif