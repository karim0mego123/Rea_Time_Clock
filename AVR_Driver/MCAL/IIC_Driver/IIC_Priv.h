#ifndef  _TWI_PRIV_H_
#define  _TWI_PRIV_H_



#define  TWBR        *((volatile uint8_t*)  0x20)
#define  TWSR        *((volatile uint8_t*)  0x21)
#define  TWAR        *((volatile uint8_t*)  0x22)
#define  TWCR        *((volatile uint8_t*)  0x56)
#define  TWDR        *((volatile uint8_t*)  0x23)

/************************************************************************/
/*     PRES To Set TWBR                                                                 */
/**********************************************Æ**************************/
#define PRES_1		1
#define PRES_4		2
#define PRES_16		16
#define PRES_64		64

/************************************************************************/
/*           IIC_CLKSPEED 100K : 400K                                                           */
/************************************************************************/
#define IIC_CLKSPEED_100K	100000UL
#define IIC_CLKSPEED_400K	400000UL

/*STATUS OF TWSR REGISTER */
#define STARTCONDITION            0x08

#define SendSlaveAdressWithWrite  0x18

#define SendSlaveAdressWithRead   0x40

#define MasterSendData            0x28

#define ReceieveDataWih_NACK      0x58

#define REPEATEDSTARTCONDITION    0x10


#define SLAVERECIEVE			  0x80

#define BITRATE	(((F_CPU/IIC_CLKSPEED)-16)/(2*PRES))

#endif