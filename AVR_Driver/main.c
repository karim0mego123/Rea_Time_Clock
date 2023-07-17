/*
 * GccApplication1.c
 *
 * Created: 4/19/2023 3:30:46 PM
 * Author : karim
 */ 
#include "EXTI.h"
#include "LCD.h"
#include "Keypad.h"
#include "Timer1_Interface.h"


static uint8_t Seconds = 0 ,  Minutes = 0 , Hours = 0 ;
char array[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};

void funa()
{		
	Seconds++ ; 
}
void Fun_Exti()
{
	Seconds = 0 ,  Minutes = 0 , Hours = 0 ;
}

int main()
{
	uint8_t key_scan = 0 , SBuffer = 0 , flag = 0 , MBuffer = 0 , HBuffer = 0 ; 
	DIO_Write_Port_Dir(PORT_C,OUT) ;
	DIO_Write_Port_Dir(PORT_D,OUT) ;
	DIO_Write_Pin_Dir(PORT_D,PIN3,IN);
	DIO_Write_Pin(PORT_D,PIN3,HIGH) ;
	LCD_Init();
	KeYPad_Init();
	Timer1_voidInit();
	EXTI_Enable(EX_INT1) ; 
	EXI_SetCallBack(EX_INT1,Fun_Exti) ;
	EXTI_TriggerEdge(EX_INT1,RISING_EDGE) ;  
	sei();
	Timer1_voidOCAEnableInterrupt();
	Timer1_voidOCASetCallBack(funa);
	Timer1_voidPreload(0);
	Timer1_voidSetCounterTOP(46875);
	LCD_Write_String((uint8_t*)"Set Time Enter 1",0,0);
	while(1)
	{
		key_scan = KeyPAd_Scan();
		if (key_scan!='+' && key_scan!='/' && key_scan!='-' && key_scan!='='&&key_scan != 'a')
		{
			break ;
		}
	}
	if (key_scan!='1')
	{
		Seconds = 0 ;
		Minutes = 0 ;
		Hours   = 0 ;
	}
	while(1)
	{
		if (key_scan=='1')
		{
			LCD_Clear_Screen();
			LCD_Write_String((uint8_t*)"Enter Seconds : ",0,0) ;
			while(1)
			{
				key_scan = KeyPAd_Scan();
				if (key_scan!='+' && key_scan!='/' && key_scan!='-' && key_scan!='='&&key_scan != 'a')
				{
					flag++ ;
					LCD_GO_TO_INDEX(1,flag-1);
					Lcd_Write_Char(key_scan);
				
					if (flag==1)
					{
						Seconds  = key_scan-48 ;
						Seconds*=10;					
					}
					SBuffer = (Seconds+(key_scan-48)) ;
					if (flag==2)
					{
						flag=0;
						break;	
					}
				}
			}
			LCD_Clear_Screen();
			LCD_Write_String((uint8_t*)"Enter Minutes : ",0,0) ;
			while(1)
			{
				key_scan = KeyPAd_Scan();
				if (key_scan!='+'&&key_scan!='/'&&key_scan!='-'&&key_scan!='='&&key_scan != 'a')
				{
					flag++ ;
					LCD_GO_TO_INDEX(1,flag-1);
					Lcd_Write_Char(key_scan);
			
					if (flag==1)
					{
						LCD_GO_TO_INDEX(1,flag-1);
						Minutes  = key_scan-48 ;
						Minutes*=10;
					}
					MBuffer = (Minutes+(key_scan-48)) ;
					if (flag==2)
					{
						flag=0;
						break;
					}
				}
			}
			LCD_Clear_Screen();
			LCD_Write_String((uint8_t*)"Enter Hours : ",0,0) ;
			while(1)
			{
				key_scan = KeyPAd_Scan();
				if (key_scan!='+'&&key_scan!='/'&&key_scan!='-'&&key_scan!='='&&key_scan != 'a')
				{
					flag++ ;
					LCD_GO_TO_INDEX(1,flag-1);
					Lcd_Write_Char(key_scan);
				
					if (flag==1)
					{
						Hours  = key_scan-48 ;
						Hours*=10;
					}
					HBuffer = (Hours+(key_scan-48)) ;
					if (flag==2)
					{
						flag=0;
						break;
					}
				}
			}
			LCD_Clear_Screen();
			LCD_Write_String((uint8_t*)"Time : ",0,0) ;
			key_scan = '0' ; 
			Seconds = SBuffer ;
			Minutes = MBuffer ;
			Hours   = HBuffer ;
			Timer1_voidPreload(0);		
		}
		SET_BIT(PORTD,1);
		SET_BIT(PORTD,2);
		SET_BIT(PORTD,4);
		SET_BIT(PORTD,6);
		SET_BIT(PORTD,7);
		CLEAR_BIT(PORTD,0);
		PORTC = ~array[(Seconds%10)] ;
		_delay_ms(5);
		SET_BIT(PORTD,0);
		SET_BIT(PORTD,2);
		SET_BIT(PORTD,4);
		SET_BIT(PORTD,6);
		SET_BIT(PORTD,7);
		CLEAR_BIT(PORTD,1);
		PORTC = ~array[(Seconds/10)] ;
		_delay_ms(5);
		SET_BIT(PORTD,1);
		SET_BIT(PORTD,0);
		SET_BIT(PORTD,4);
		SET_BIT(PORTD,6);
		SET_BIT(PORTD,7);
		CLEAR_BIT(PORTD,2);
		PORTC = ~array[(Minutes%10)] ;
		_delay_ms(5);
		SET_BIT(PORTD,1);
		SET_BIT(PORTD,2);
		SET_BIT(PORTD,0);
		SET_BIT(PORTD,6);
		SET_BIT(PORTD,7);
		CLEAR_BIT(PORTD,4);
		PORTC = ~array[(Minutes/10)] ;
		_delay_ms(5);
		SET_BIT(PORTD,1);
		SET_BIT(PORTD,2);
		SET_BIT(PORTD,4);
		SET_BIT(PORTD,0);
		SET_BIT(PORTD,7);
		CLEAR_BIT(PORTD,6);
		PORTC = ~array[(Hours%10)] ;
		_delay_ms(5);
		SET_BIT(PORTD,1);
		SET_BIT(PORTD,2);
		SET_BIT(PORTD,4);
		SET_BIT(PORTD,6);
		SET_BIT(PORTD,0);
		CLEAR_BIT(PORTD,7);
		PORTC = ~array[(Hours/10)] ;
		_delay_ms(5);
		if (Seconds==60)
		{
			Seconds=0;
			Minutes++;
		}
		if (Minutes==60)
		{
			Minutes=0;
			Hours++;
		}
		if (Hours==24)
		{
			Hours=0;
		}
	}	
	return 0 ; 
}
