/*
 * Regesters.h
 *
 * Created: 1/31/2023 12:54:31 AM
 *  Author: karim
 */ 


#ifndef REGESTERS_H_
#define REGESTERS_H_


/************************************************************************/
/*						MCU_Regester                                    */
/************************************************************************/

/************************************************************************/
/*							DIO_Regesters                               */
/************************************************************************/

// PORTA

#define PORTA	*(volatile uint8_t *)(0x3B)
#define DDRA	*(volatile uint8_t *)(0x3A)
#define PINA	*(volatile uint8_t *)(0x39)

// PORTB
#define PORTB	*(volatile uint8_t *)(0x38)
#define DDRB	*(volatile uint8_t *)(0x37)
#define PINB	*(volatile uint8_t *)(0x36)

// PORTC
#define PORTC	*(volatile uint8_t *)(0x35)
#define DDRC	*(volatile uint8_t *)(0x34)
#define PINC	*(volatile uint8_t *)(0x33)

// PORTD
#define PORTD	*(volatile uint8_t *)(0x32)
#define DDRD	*(volatile uint8_t *)(0x31)
#define PIND	*(volatile uint8_t *)(0x30)


#define PIN0  0 
#define	PIN1  1
#define	PIN2  2
#define	PIN3  3 
#define	PIN4  4 
#define	PIN5  5 
#define	PIN6  6
#define	PIN7  7


/************************************************************************/
/*							Timer_Regesters                             */
/************************************************************************/
/* Timer 0*/


#define TCCR0_BASE	*(volatile uint8_t *)(0x53)
#define CS00	0
#define	CS01	1
#define	CS02	2
#define WGM01	3
#define COM00	4
#define COM01	5
#define WGM00	6
#define FOC0	7

#define TCNT0_BASE	*(volatile uint8_t *)(0x52)
#define OCR0_BASE	*(volatile uint8_t *)(0x5C)

#define TIMSK_BASE	*(volatile uint8_t *)(0x59)
#define TOIE0	0
#define OCIE0	1
#define TOIE1	2
#define OCIE1B	3
#define OCIE1A	4
#define TICIE1	5
#define TOIE2	6
#define OCIE2	7

#define TIFR_BASE	*(volatile uint8_t *)(0x58)
#define TOV0	0
#define	OCF0	1
#define	TOV1	2
#define	OCF1B	3
#define	OCF1A	4
#define ICF1	5
#define	TOV2	6
#define	OCF2	7

// INTERRUPT
#define	MCUCR	*(volatile uint8_t *)(0x55)
#define ISC00	0
#define ISC01	1
#define ISC10	2
#define ISC11	3


#define	MCUCSR	*(volatile uint8_t *)(0x54)
#define ISC2	6

#define	GICR	*(volatile uint8_t *)(0x5B)
#define INT1	7
#define INT0	6
#define INT2	5

#define	GIFR	*(volatile uint8_t *)(0x5A)
#define INTF1	7
#define INTF0	6
#define INTF2	5

#define	SREG	*(volatile uint8_t *)(0x5F)



#define INT0_vect		__vector_1
#define INT1_vect		__vector_2
#define INT2_vect		__vector_3



/************************************************************************/
/*								USART		                             */
/************************************************************************/
#define UDR		*(volatile uint8_t *)(0x2C)

#define UCSRA	*(volatile uint8_t *)(0x2B)
#define MPCM    0
#define U2X     1
#define UPE     2
#define DOR     3
#define FE      4
#define UDRE    5
#define TXC     6
#define RXC     7

#define UCSRB	*(volatile uint8_t *)(0x2A)
#define TXB8    0
#define RXB8    1
#define UCSZ2   2
#define TXEN    3
#define RXEN    4
#define UDRIE   5
#define TXCIE   6
#define RXCIE   7

#define UCSRC	*(volatile uint8_t *)(0x40)
#define UCPOL   0
#define UCSZ0   1
#define UCSZ1   2
#define USBS    3
#define UPM0    4
#define UPM1    5
#define UMSEL   6
#define URSEL   7

#define UBRRL	*(volatile uint8_t *)(0x29)
#define UBRRH	*(volatile uint8_t *)(0x40)

#define MYUBRR(BAUD)	            ((unsigned int)((FSOC/Speed_Mode)/(16UL*BAUD)-1))

/************************************************************************/
/*							EXTI_Interrupt                              */
/***********************************************************************/

#define MCUCSR	*(volatile uint8_t *)(0x54)
#define ISC2   6	// MCUCSR � MCU Control and Status Register

// ISC11 ISC10 Description
// 0 0 The low level of INT1 generates an interrupt request.
// 0 1 Any logical change on INT1 generates an interrupt request.
// 1 0 The falling edge of INT1 generates an interrupt request.
// 1 1 The rising edge of INT1 generates an interrupt request.

#define MCUCR	*(volatile uint8_t *)(0x55)
#define ISC00   0
#define ISC01	1
#define ISC10	2
#define ISC11	3

#define GICR	*(volatile uint8_t *)(0x5B)
#define INT0   6
#define INT1   7
#define INT2   5

#define GIFR	*(volatile uint8_t *)(0x5A)
#define INTF2   5
#define INTF0   6
#define INTF1   7





/* Interrupt vectors */

/* External Interrupt Request 0 */
#define INT0_vect			__vector_1
/* External Interrupt Request 1 */
#define INT1_vect			__vector_2
/* External Interrupt Request 2 */
#define INT2_vect			__vector_3
/* Timer/Counter2 Compare Match */
#define TIMER2_COMP_vect		__vector_4
/* Timer/Counter2 Overflow */
#define TIMER2_OVF_vect			__vector_5
/* Timer/Counter1 Capture Event */
#define TIMER1_CAPT_vect		__vector_6
/* Timer/Counter1 Compare Match A */
#define TIMER1_COMPA_vect		__vector_7
/* Timer/Counter1 Compare Match B */
#define TIMER1_COMPB_vect		__vector_8
/* Timer/Counter1 Overflow */
#define TIMER1_OVF_vect			__vector_9
/* Timer/Counter0 Compare Match */
#define TIMER0_COMP_vect		__vector_10
/* Timer/Counter0 Overflow */
#define TIMER0_OVF_vect			__vector_11
/* Serial Transfer Complete */
#define SPI_STC_vect			__vector_12
/* USART, Rx Complete */
#define USART_RXC_vect			__vector_13
/* USART Data Register Empty */
#define USART_UDRE_vect			__vector_14
/* USART, Tx Complete */
#define USART_TXC_vect			__vector_15
/* ADC Conversion Complete */
#define ADC_vect			   __vector_16
/* EEPROM Ready */
#define EE_RDY_vect			   __vector_17
/* Analog Comparator */
#define ANA_COMP_vect			__vector_18
/* 2-wire Serial Interface */
#define TWI_vect			    __vector_19
/* Store Program Memory Ready */
#define SPM_RDY_vect			__vector_20



/*interrupt functions*/

# define sei()  __asm__ __volatile__ ("sei" ::)
# define cli()  __asm__ __volatile__ ("cli" ::)
# define reti()  __asm__ __volatile__ ("reti" ::)


#  define ISR_NOBLOCK    __attribute__((interrupt))// open global interrupt before switch context 
#  define ISR_NAKED      __attribute__((naked))


#  define ISR(vector)            \
void vector (void) __attribute__ ((signal)) ; \
void vector (void)
















#endif /* REGESTERS_H_ */