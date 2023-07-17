/*
 * LCD.c
 *
 * Created: 1/24/2023 2:11:56 PM
 *  Author: karim
 */ 
#include "LCD.h"
#ifdef FOUR_BIT_MODE
static uint8_t Init_Is_Finshed = 0 ;
#endif
/*******************************************************************************************************************
 * 			@Fn							-LCD_Clear_Screen															*
 * 			@brief 						-Function is used to clear screen											*
 * 			@param [in]					-NONE																		*
 * 			@retval						-NONE																		*
 * 			Note						-NONE																		*
 ********************************************************************************************************************/
void LCD_Clear_Screen ()
{
	LCD_Wirte_Cmd(LCD_CLEAR_SCREEN);
}

/*******************************************************************************************************************
 * 			@Fn							-LCD_Enable																	*
 * 			@brief 						-Function is used to read data or cmd from port after falling adge			*
 * 			@param [in]					-NONE																		*
 * 			@retval						-NONE																		*
 * 			Note						-NONE																		*
 ********************************************************************************************************************/
void LCD_Enable ()
{
	DIO_Write_Pin(PORT_LCD_A,EN_SWITCH,HIGH);
	_delay_ms(50);
	DIO_Write_Pin(PORT_LCD_A,EN_SWITCH,LOW);

}

/*******************************************************************************************************************
 * 			@Fn							-LCD_Init																	*
 * 			@brief 						-INIT LCD From DataSheet													*
 * 			@param [in]					-NONE																		*
 * 			@retval						-NONE																		*
 * 			Note						-NONE																		*
 ********************************************************************************************************************/
void LCD_Init()
{
	_delay_ms(20) ;
	
	SET_BIT(LCD_CTRL_DIR,RS_SWITCH);
	SET_BIT(LCD_CTRL_DIR,RW_SWITCH);
	SET_BIT(LCD_CTRL_DIR,EN_SWITCH);

	CLEAR_BIT(LCD_CTRL,RS_SWITCH);
	CLEAR_BIT(LCD_CTRL,RW_SWITCH);
	CLEAR_BIT(LCD_CTRL,EN_SWITCH);

#ifdef EIGHT_BIT_MODE
	SET_REG(LCD_DATA_DIR);
#endif 

#ifdef FOUR_BIT_MODE
	SET_BIT(LCD_DATA_DIR,4);
	SET_BIT(LCD_DATA_DIR,5);
	SET_BIT(LCD_DATA_DIR,6);
	SET_BIT(LCD_DATA_DIR,7);
#endif 
	_delay_ms(15);
	LCD_Clear_Screen();
	
	#ifdef EIGHT_BIT_MODE
	LCD_Wirte_Cmd(LCD_FUNCTION_8BIT_2LINES);
	#endif
	
#ifdef FOUR_BIT_MODE	

	LCD_Wirte_Cmd(0x20);
	LCD_Wirte_Cmd(0x20);
	LCD_Wirte_Cmd(0x80);
	_delay_ms(1);
	
	LCD_Wirte_Cmd(0x00);
	LCD_Wirte_Cmd(0xF0);
	_delay_ms(1);
	
	LCD_Wirte_Cmd(0x00);
	LCD_Wirte_Cmd(0x10);
	_delay_ms(2);
	
// 	LCD_Wirte_Cmd(0x00);	By Default
// 	LCD_Wirte_Cmd(0x60);	By Default

	Init_Is_Finshed = 1 ; // when we init LCD in case four bit we will send 0x2xxxx  , 0x2xxxx , 0x8xxxx
	// SO When we send 0x0010 0000 last four bit will be read from lcd and 0000 will not be read
	#endif
	LCD_Wirte_Cmd(LCD_ENTRY_MODE);
	LCD_Wirte_Cmd(LCD_BEGIN_AT_FIRST_ROW);
	LCD_Wirte_Cmd(LCD_DISP_ON_CURSOR_BLINK);	
}

/*******************************************************************************************************************
 * 			@Fn							-LCD_Wirte_Cmd																*
 * 			@brief 						-take cmd from user in case four bit mode we will write last four bit		*
 *										of cmd into LCD_PORT_DATA And then Write first four Bit into LCD_PORT_DATA	*									*
 *										And Between Sending four bit make 1ms Delay									*									*
 *										in case EIGHT_BIT_MODE	WE write 8 bit once in LCD_PORT_DATA				*									*
 *										after sending cmd make a 2ms Delay											*
 *										 To Read Data from LCD_PORT_DATA Make EN_SWITCH FALLing EDGE				*										*
 * 			@param [in]					-Cmd Command user will inter to preform specific operation					*
 * 			@retval						-NONE																		*
 * 			Note						-NONE																		*
 ********************************************************************************************************************/
void LCD_Wirte_Cmd (uint8_t Cmd)
{
	DIO_Write_Pin(PORT_LCD_A,RS_SWITCH,LOW);
	DIO_Write_Pin(PORT_LCD_A,RW_SWITCH,LOW);
	
	#ifdef FOUR_BIT_MODE
	

	LCD_DATA = (LCD_DATA&0x0F) | (Cmd&0xF0);  
	LCD_Enable ();
	_delay_ms(1);
	if (Init_Is_Finshed)
	{
		
		LCD_DATA = (((LCD_DATA&0x0F) | (Cmd&0x0F))<<4);
		LCD_Enable ();
	}
	#endif
	
	#ifdef EIGHT_BIT_MODE
	LCD_DATA = Cmd ;
	LCD_Enable();
	#endif
	_delay_ms(2);
}
/*******************************************************************************************************************
 * 			@Fn							-Lcd_Write_Char																*
 * 			@brief 						-function use to write char in Lcd											*
 * 			@param [in]					-char enter by user to display on Lcd										*
 * 			@retval						-NONE																		*
 * 			Note						-NONE																		*
 *******************************************************************************************************************/

void Lcd_Write_Char(uint8_t Char)
{
	
	DIO_Write_Pin(PORT_LCD_A,RS_SWITCH,HIGH);
	DIO_Write_Pin(PORT_LCD_A,RW_SWITCH,LOW);
#ifdef FOUR_BIT_MODE
	LCD_DATA = (LCD_DATA&0x0F) | (Char&0xF0);
	LCD_Enable ();
	_delay_ms(1);
	LCD_DATA = (((LCD_DATA&0x0F) | (Char&0x0F)<<4));
	LCD_Enable ();
#endif
	
#ifdef EIGHT_BIT_MODE
	_delay_ms(1);
	LCD_DATA = Char ;
	LCD_Enable();
#endif
}
/*******************************************************************************************************************
 * 			@Fn							-LCD_Write_String															*
 * 			@brief 						-take string from user and print it 										*
 * 			@param [in]					-STRING																		*
 *			@param [in]					-ROW																		*
 *			@param [in]					-COL																		*		
 * 			@retval						-NONE																		*
 * 			Note						-NONE																		*
 ********************************************************************************************************************/
void LCD_Write_String( uint8_t* STRING , uint8_t ROW , uint8_t COL)
{
	LCD_GO_TO_INDEX(ROW,COL);
	uint8_t index = 0 ;
	uint8_t Line = 0 ;
	while(STRING[index]!='\0' && ((ROW*16)+(index+COL))<=32 )  // Know if there are empty position in 2 * 16 LCD 
	{
		if (( (ROW*16)+(index+COL) )<16 ) // Write in First Row 
		{
			Lcd_Write_Char(STRING[index]);
			index++;
		}
		else if (( (ROW*16)+(index+COL) ) == 16 && Line == 0 ) // IF I REACH END OF ROW0 I WILL MOVE TO ROW1 
		{
			LCD_GO_TO_INDEX(1,0) ; 
			Line = 1 ; 
		}
		else if (( (ROW*16)+(index+COL) ) < 32 && Line==1  ) // i will start write in ROW1 till end of Row
		{
			Lcd_Write_Char(STRING[index]);
			index++ ;
		}		
	}
}
/*******************************************************************************************************************
 * 			@Fn							-LCD_GO_TO_INDEX															*
 * 			@brief 						-move Address counter to specific address									*
 *			@param [in]					-ROW																		*
 * 			@param [in]					-COL																	 	*
 * 			@retval						-NONE																		*
 * 			Note						-NONE																		*
 ********************************************************************************************************************/
void LCD_GO_TO_INDEX(uint8_t ROW , uint8_t COL)
{
	uint8_t Address ; 
	if (ROW<2 && COL <16){
		Address = ( ROW * Second_Row_Address ) + COL; // We multiply the row number by the starting address of the second row and add the column value
		SET_BIT(Address,7);	// To set DDRAM Address we must set bit7 in Address . Address here limit by 7bits becouse has 80 Location
		LCD_Wirte_Cmd(Address);
	}
}
/*******************************************************************************************************************
 * 			@Fn							-LCD_GO_TO_INDEX															*
 * 			@brief 						-move Address counter to specific address									*
 *			@param [in]					-pattern : data stored in spacific address 									*
 * 			@param [in]					-CGram_index : Ram can write in and part of CGram						 	*
 * 			@retval						-NONE																		*
 * 			Note						-NONE																		*
 ********************************************************************************************************************/
void LCD_Store_Customer_Char(uint8_t* pattern , uint8_t CGram_index )
{
	uint8_t Address ;
	uint8_t index ;  
	if (CGram_index<8)
	{
		Address = CGram_index*8 ;
		SET_BIT(Address,6);
		LCD_Wirte_Cmd(Address);
		for( index = 0 ; index < 8 ; index++ )
		{
			Lcd_Write_Char(pattern[index]);
		}
		LCD_Wirte_Cmd(0x02); 
	}
}
/*******************************************************************************************************************
 * 			@Fn							-LCD_Display_Customer_Char													*
 * 			@brief 						-display data stored in CGRAM												*
 * 			@param [in]					-CGram_index : Ram can write in and part of CGram						 	*
 *			@param [in]					-ROW																		*
 * 			@param [in]					-COL																	 	*
 * 			@retval						-NONE																		*
 * 			Note						-NONE																		*
 ********************************************************************************************************************/
void LCD_Display_Customer_Char(uint8_t CGRAM_Index , uint8_t ROW , uint8_t Col ) 
{
	LCD_GO_TO_INDEX(ROW,Col);
	Lcd_Write_Char(CGRAM_Index);
}
void LCD_Write_Number(uint32_t Number) 
{
	uint8_t Rem[5] = {0} , count = 0  ;
	if (Number<10)
	{
		Lcd_Write_Char(Number+48);
	}
	else
	{
		while(Number>0)
		{
			Rem[count++] = Number % 10 ;
			Number /= 10 ; 
		}
	}
	for (int i = count-1 ; i >= 0 ; i-- )
	{
		Lcd_Write_Char(Rem[i]+48);		
	}
}