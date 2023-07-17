/*
 * utils.h
 *
 * Created: 12/13/2022 11:55:59 AM
 *  Author: karim
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#define SET_REG(Reg) Reg=0xFF
#define CLEAR_REG(Reg) Reg=0x00
#define TOOGLE_REG(Reg) Reg^=0xFF
#define ASSIGN_REG(Reg,Value) Reg=Value
#define SET_BITS_REG(Reg,Mask) Reg|=(Mask)
#define CLEAR_BITS_REG(Reg,Mask) Reg=(Reg&(~Mask))
#define SET_BIT(Reg,bit) Reg|=(1<<bit)
#define CLEAR_BIT(Reg,bit) Reg=(Reg&(~(1<<bit)))
#define TOOGLE_BIT(Reg,bit) Reg^=(1<<bit)
#define GET_BIT(Reg,bit) (( (Reg)>>(bit) )& 1)






#endif /* UTILS_H_ */