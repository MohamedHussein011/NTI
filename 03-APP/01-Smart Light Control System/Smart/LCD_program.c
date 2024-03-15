/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: LCD_program.c		            ************************/
/***************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "User_Functions.h"
#include "util/delay.h"

#include "DIO_interface.h"

#include "LCD_interface.h"
#include "LCD_config.h"
#include "LCD_private.h"


/********************************				Function Definitions				********************************/
void LCD_voidInit(void)
{

#if LCD_InitMode == EightBit_Init
	/*Wait for more than 30ms*/
	_delay_ms(40);
	/*Function Set: 1 or 2 Lines & 5x8 or 5x11 Dots*/
#if LCD_NumbersOfLines == One_Line
	//start of LCD_Font_Size
#if LCD_Font_Size == FiveEight_Size
	LCD_voidSendCommand(OneLine_5x8_8Bit);
#elif LCD_Font_Size == FiveEleven_Size
	LCD_voidSendCommand(OneLine_5x11_8Bit);
#else
#error "Wrong LCD font size"
#endif		//end of LCD_Font_Size

#elif LCD_NumbersOfLines == Two_Lines
	//start of LCD_Font_Size
#if LCD_Font_Size == FiveEight_Size
	LCD_voidSendCommand(TwoLine_5x8_8Bit);
#elif LCD_Font_Size == FiveEleven_Size
	LCD_voidSendCommand(TwoLine_5x11_8Bit);
#else
#error "Wrong LCD font size"
#endif		//end of LCD_Font_Size

#else
#error "Wrong LCD number of lines"
#endif		//end of LCD_NumbersOfLines

	/*Wait for more than 39us*/
	_delay_us(40);
	/*Display On/Off control*/
#if LCD_Display == Display_ON
#if LCD_Cursor == Cursor_ON
#if LCD_Blinking == Blinking_ON
	LCD_voidSendCommand(DisplayOn_CursorOn_BlinkingOn);
#elif LCD_Blinking == Blinking_OFF
	LCD_voidSendCommand(DisplayOn_CursorOn_BlinkingOff);
#else
#error "Wrong LCD blinking"
#endif /*Blinking*/

#elif LCD_Cursor == Cursor_OFF
#if LCD_Blinking == Blinking_ON
	LCD_voidSendCommand(DisplayOn_CursorOff_BlinkingOn);
#elif LCD_Blinking == Blinking_OFF
	LCD_voidSendCommand(DisplayOn_CursorOff_BlinkingOff);
#else
#error "Wrong LCD blinking"
#endif  /*Blinking*/
#else
#error "Wrong LCD cursor"
#endif  /*cursor*/

#elif LCD_Display == Display_OFF
#if LCD_Cursor == Cursor_ON
#if LCD_Blinking == Blinking_ON
	LCD_voidSendCommand(DisplayOff_CursorOn_BlinkingOn);
#elif LCD_Blinking == Blinking_OFF
	LCD_voidSendCommand(DisplayOff_CursorOn_BlinkingOff);
#else
#error "Wrong LCD blinking"
#endif   /*Blinking*/

#elif LCD_Cursor == Cursor_OFF
#if LCD_Blinking == Blinking_ON
	LCD_voidSendCommand(DisplayOff_CursorOff_BlinkingOn);
#elif LCD_Blinking == Blinking_OFF
	LCD_voidSendCommand(DisplayOff_CursorOff_BlinkingOff);
#else
#error "Wrong LCD blinking"
#endif  /*Blinking*/
#else
#error "Wrong LCD cursor"
#endif  /*cursor*/

#else
#error "Wrong LCD display"
#endif  /*Display*/

	/*Wait for more than 39us*/
	_delay_us(40);
	/*Display Clear*/
	LCD_voidSendCommand(CLEAR_DISPLAY);
	/*Wait for more than 1.53ms*/
	_delay_us(1600);
	/*Entry Mode Set*/
	LCD_voidSendCommand(ENTRY_MODE_SET);

#elif LCD_InitMode == FourBit_Init
	/*Wait for more than 30ms*/
	_delay_ms(40);

	LCD_voidSendCommand(0x02);
	LCD_voidSendCommand(0x02);


	/*Function Set: 1 or 2 Lines & 5x8 or 5x11 Dots*/
#if LCD_NumbersOfLines == One_Line
#if LCD_Font_Size == FiveEight_Size
	LCD_voidSendCommand(OneLine_5x8_4Bit);
#elif LCD_Font_Size == FiveEleven_Size
	LCD_voidSendCommand(OneLine_5x11_4Bit);
#else
#error "Wrong LCD font size"
#endif

#elif LCD_NumbersOfLines == Two_Lines
#if LCD_Font_Size == FiveEight_Size
	LCD_voidSendCommand(TwoLine_5x8_4Bit);
#elif LCD_Font_Size == FiveEleven_Size
	LCD_voidSendCommand(TwoLine_5x11_4Bit);
#else
#error "Wrong LCD font size"
#endif

#else
#error "Wrong LCD number of lines"
#endif
	/*Wait for more than 39us*/
	_delay_us(40);
	/*Display On/Off control*/
#if LCD_Display == Display_ON
#if LCD_Cursor == Cursor_ON
#if LCD_Blinking == Blinking_ON
	LCD_voidSendCommand(0x00);
	LCD_voidSendCommand(DisplayOn_CursorOn_BlinkingOn);
#elif LCD_Blinking == Blinking_OFF
	LCD_voidSendCommand(0x00);
	LCD_voidSendCommand(DisplayOn_CursorOn_BlinkingOff);
#else
#error "Wrong LCD blinking"
#endif /*Blinking*/
#elif LCD_Cursor == Cursor_OFF
#if LCD_Blinking == Blinking_ON
	LCD_voidSendCommand(0x00);
	LCD_voidSendCommand(DisplayOn_CursorOff_BlinkingOn);
#elif LCD_Blinking == Blinking_OFF
	LCD_voidSendCommand(0x00);
	LCD_voidSendCommand(DisplayOn_CursorOff_BlinkingOff);
#else
#error "Wrong LCD blinking"
#endif  /*Blinking*/
#else
#error "Wrong LCD cursor"
#endif  /*cursor*/
#elif LCD_Display == Display_OFF
#if LCD_Cursor == Cursor_ON
#if LCD_Blinking == Blinking_ON
	LCD_voidSendCommand(0x00);
	LCD_voidSendCommand(DisplayOff_CursorOn_BlinkingOn);
#elif LCD_Blinking == Blinking_OFF
	LCD_voidSendCommand(0x00);
	LCD_voidSendCommand(DisplayOff_CursorOn_BlinkingOff);
#else
#error "Wrong LCD blinking"
#endif   /*Blinking*/
#elif LCD_Cursor == Cursor_OFF
#if LCD_Blinking == Blinking_ON
	LCD_voidSendCommand(0x00);
	LCD_voidSendCommand(DisplayOff_CursorOff_BlinkingOn);
#elif LCD_Blinking == Blinking_OFF
	LCD_voidSendCommand(0x00);
	LCD_voidSendCommand(DisplayOff_CursorOff_BlinkingOff);
#else
#error "Wrong LCD blinking"
#endif  /*Blinking*/
#else
#error "Wrong LCD cursor"
#endif  /*cursor*/
#else
#error "Wrong LCD display"
#endif  /*Display*/

	/*Wait for more than 39us*/
	_delay_us(40);
	/*Display Clear*/
	LCD_voidSendCommand(0x00);
	LCD_voidSendCommand(CLEAR_DISPLAY);
	/*Wait for more than 1.53ms*/
	_delay_us(1600);
	/*Entry Mode Set*/
	LCD_voidSendCommand(0x00);
	LCD_voidSendCommand(ENTRY_MODE_SET);

#else
#error "Wrong LCD init mode"

#endif
}


void LCD_voidSendCommand(u8 Copy_u8Command)
{
	/*Set Rs to 0 to choose IR register to send command -----> 0 (Instruction Register), 1(Data Register)*/
	DIO_u8SetPinValue(LCD_RS_PORT, LCD_RS_PIN, DIO_PIN_LOW);

	/*Set R/W to 0 so i can write data ----> 0 (write), 1(read)*/
	DIO_u8SetPinValue(LCD_RW_PORT, LCD_RW_PIN, DIO_PIN_LOW);

	/*Send Command*/
#if LCD_InitMode == EightBit_Init
	DIO_u8SetPinValue(LCD_DATA_PORT_D0, LCD_DATA_PIN_D0, Copy_u8Command & 1);
	DIO_u8SetPinValue(LCD_DATA_PORT_D1, LCD_DATA_PIN_D1, (Copy_u8Command >> 1) & 1);
	DIO_u8SetPinValue(LCD_DATA_PORT_D2, LCD_DATA_PIN_D2, (Copy_u8Command >> 2) & 1);
	DIO_u8SetPinValue(LCD_DATA_PORT_D3, LCD_DATA_PIN_D3, (Copy_u8Command >> 3) & 1);
	DIO_u8SetPinValue(LCD_DATA_PORT_D4, LCD_DATA_PIN_D4, (Copy_u8Command >> 4) & 1);
	DIO_u8SetPinValue(LCD_DATA_PORT_D5, LCD_DATA_PIN_D5, (Copy_u8Command >> 5) & 1);
	DIO_u8SetPinValue(LCD_DATA_PORT_D6, LCD_DATA_PIN_D6, (Copy_u8Command >> 6) & 1);
	DIO_u8SetPinValue(LCD_DATA_PORT_D7, LCD_DATA_PIN_D7, (Copy_u8Command >> 7) & 1);
#elif LCD_InitMode == FourBit_Init
	DIO_u8SetPinValue(LCD_DATA_PORT_D4, LCD_DATA_PIN_D4, (Copy_u8Command) & 1);
	DIO_u8SetPinValue(LCD_DATA_PORT_D5, LCD_DATA_PIN_D5, (Copy_u8Command >> 1) & 1);
	DIO_u8SetPinValue(LCD_DATA_PORT_D6, LCD_DATA_PIN_D6, (Copy_u8Command >> 2) & 1);
	DIO_u8SetPinValue(LCD_DATA_PORT_D7, LCD_DATA_PIN_D7, (Copy_u8Command >> 3) & 1);
#else
#error "Wrong LCD init mode"
#endif
	/*Set enable pin from high to low with wide as 230ns*/
	DIO_u8SetPinValue(LCD_EN_PORT, LCD_EN_PIN, DIO_PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_EN_PORT, LCD_EN_PIN, DIO_PIN_LOW);

	/* Delay to let the LCD Display the character */
	_delay_ms(10);
}


void LCD_voidClearDisplay(void)
{
#if LCD_InitMode == EightBit_Init
	LCD_voidSendCommand(CLEAR_DISPLAY);
	LCD_voidSendCommand(CURSOR_OFFEST);
#elif LCD_InitMode == FourBit_Init
	LCD_voidSendCommand(CLEAR_DISPLAY >> 4);		//upper nibble
	LCD_voidSendCommand(CLEAR_DISPLAY);				//lower nibble

	LCD_voidSendCommand(CURSOR_OFFEST >> 4);        //upper nibble
	LCD_voidSendCommand(CURSOR_OFFEST);             //lower nibble
#endif
}


void LCD_voidSendCharacter(u8 Copy_u8Character)
{
	/*Set Rs to 0 to choose IR register to send command -----> 0 (Instruction Register), 1(Data Register)*/
	DIO_u8SetPinValue(LCD_RS_PORT, LCD_RS_PIN, DIO_PIN_HIGH);

	/*Set R/W to 0 so i can write data ----> 0 (write), 1(read)*/
	DIO_u8SetPinValue(LCD_RW_PORT, LCD_RW_PIN, DIO_PIN_LOW);

	/*Send Character*/
#if LCD_InitMode == EightBit_Init
	DIO_u8SetPinValue(LCD_DATA_PORT_D0, LCD_DATA_PIN_D0,  Copy_u8Character & 1);
	DIO_u8SetPinValue(LCD_DATA_PORT_D1, LCD_DATA_PIN_D1, (Copy_u8Character >> 1) & 1);
	DIO_u8SetPinValue(LCD_DATA_PORT_D2, LCD_DATA_PIN_D2, (Copy_u8Character >> 2) & 1);
	DIO_u8SetPinValue(LCD_DATA_PORT_D3, LCD_DATA_PIN_D3, (Copy_u8Character >> 3) & 1);
	DIO_u8SetPinValue(LCD_DATA_PORT_D4, LCD_DATA_PIN_D4, (Copy_u8Character >> 4) & 1);
	DIO_u8SetPinValue(LCD_DATA_PORT_D5, LCD_DATA_PIN_D5, (Copy_u8Character >> 5) & 1);
	DIO_u8SetPinValue(LCD_DATA_PORT_D6, LCD_DATA_PIN_D6, (Copy_u8Character >> 6) & 1);
	DIO_u8SetPinValue(LCD_DATA_PORT_D7, LCD_DATA_PIN_D7, (Copy_u8Character >> 7) & 1);

	/*Set enable pin from high to low with wide as 230ns*/
	DIO_u8SetPinValue(LCD_EN_PORT, LCD_EN_PIN, DIO_PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_EN_PORT, LCD_EN_PIN, DIO_PIN_LOW);

	/* Delay to let the LCD Display the character */
	_delay_ms(10);
#elif LCD_InitMode == FourBit_Init
	//send upper nibble first
	DIO_u8SetPinValue(LCD_DATA_PORT_D4, LCD_DATA_PIN_D4, (Copy_u8Character >> 4) & 1);
	DIO_u8SetPinValue(LCD_DATA_PORT_D5, LCD_DATA_PIN_D5, (Copy_u8Character >> 5) & 1);
	DIO_u8SetPinValue(LCD_DATA_PORT_D6, LCD_DATA_PIN_D6, (Copy_u8Character >> 6) & 1);
	DIO_u8SetPinValue(LCD_DATA_PORT_D7, LCD_DATA_PIN_D7, (Copy_u8Character >> 7) & 1);

	/*Set enable pin from high to low with wide as 230ns*/
	DIO_u8SetPinValue(LCD_EN_PORT, LCD_EN_PIN, DIO_PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_EN_PORT, LCD_EN_PIN, DIO_PIN_LOW);

	/* Delay to let the LCD Display the character */
	_delay_ms(2);

	//send lower nibble second
	DIO_u8SetPinValue(LCD_DATA_PORT_D4, LCD_DATA_PIN_D4, (Copy_u8Character) & 1);
	DIO_u8SetPinValue(LCD_DATA_PORT_D5, LCD_DATA_PIN_D5, (Copy_u8Character >> 1) & 1);
	DIO_u8SetPinValue(LCD_DATA_PORT_D6, LCD_DATA_PIN_D6, (Copy_u8Character >> 2) & 1);
	DIO_u8SetPinValue(LCD_DATA_PORT_D7, LCD_DATA_PIN_D7, (Copy_u8Character >> 3) & 1);

	/*Set enable pin from high to low with wide as 230ns*/
	DIO_u8SetPinValue(LCD_EN_PORT, LCD_EN_PIN, DIO_PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_EN_PORT, LCD_EN_PIN, DIO_PIN_LOW);

	/* Delay to let the LCD Display the character */
	_delay_ms(2);
#else
#error "Wrong LCD init mode"
#endif

}


u8 LCD_u8SendString(const char* Copy_pchString)
{
	u8 Local_u8Iterator=0, Local_u8ErrorStatus = OK;

	if(Copy_pchString != NULL)
	{
		while(Copy_pchString[Local_u8Iterator] != '\0')
		{
			LCD_voidSendCharacter(Copy_pchString[Local_u8Iterator]);
			Local_u8Iterator++;
		}
	}
	else
		Local_u8ErrorStatus = LCD_E_PARAM_POINTER;

	return Local_u8ErrorStatus;
}


u8 LCD_u8CreateCustomCharacter(const u8 *Copy_pu8Pattern, u8 Copy_u8Location)
{
	u8 Local_u8Iterator=0, Local_u8ErrorStatus = OK;

	if(Copy_pu8Pattern != NULL)
	{
		if(Copy_u8Location >= 0 && Copy_u8Location <= 7)
		{
			/*send location of CGRAM i want to write*/
#if LCD_InitMode == FourBit_Init
			LCD_voidSendCommand((0x40 + (Copy_u8Location*8))>> 4);
#endif

			LCD_voidSendCommand((0x40 + (Copy_u8Location*8)));

#if LCD_Font_Size == FiveEight_Size
			/*send Copy_pu8Pattern to save in CGRAM*/
			for(Local_u8Iterator = 0; Local_u8Iterator<8; Local_u8Iterator++)
			{
				LCD_voidSendCharacter(Copy_pu8Pattern[Local_u8Iterator]);
			}
#elif LCD_Font_Size == FiveEleven_Size
			/*send Copy_pu8Pattern to save in CGRAM*/
			for(Local_u8Iterator = 0; Local_u8Iterator<11; Local_u8Iterator++)
			{
				LCD_voidSendCharacter(Copy_pu8Pattern[Local_u8Iterator]);
			}
#else
#error "Wrong LCD font size"
#endif

		}
		else
			Local_u8ErrorStatus = LCD_E_PARAM_INVALID_LOCATION_ID;
	}
	else
		Local_u8ErrorStatus = LCD_E_PARAM_POINTER;

	return Local_u8ErrorStatus;
}


u8 LCD_u8SendCustomCharacter(u8 Copy_u8Location, u8 Copy_u8Row, u8 Copy_u8Col)
{
	u8 Local_u8ErrorStatus = OK;

	if(Copy_u8Location >= 0 && Copy_u8Location <= 7)
	{
		if(Copy_u8Row >= LCD_ROW0 && Copy_u8Row <= LCD_ROW3)
		{
			if(Copy_u8Col >= LCD_COL0 && Copy_u8Col <= LCD_COL19)
			{
				/*Go to ROW & COL i want to display on screen*/
				LCD_u8GoToRowCol(Copy_u8Row, Copy_u8Col);

				/*send location to DDRAM to output the character on the screen*/
				LCD_voidSendCharacter(Copy_u8Location);
			}
			else
				Local_u8ErrorStatus = LCD_E_PARAM_INVALID_COL_ID;
		}
		else
			Local_u8ErrorStatus = LCD_E_PARAM_INVALID_ROW_ID;

	}
	else
		Local_u8ErrorStatus = LCD_E_PARAM_INVALID_LOCATION_ID;


	return Local_u8ErrorStatus;
}


u8 LCD_u8GoToRowCol (u8 Copy_u8Row, u8 Copy_u8Col)
{
	u8 Local_u8Location = 0, Local_u8Var = 0, Local_u8ErrorStatus = OK;

	if(Copy_u8Row >= LCD_ROW0 && Copy_u8Row <= LCD_ROW3)
	{
		if(Copy_u8Col >= LCD_COL0 && Copy_u8Col <= LCD_COL19)
		{
			if(Copy_u8Row == LCD_ROW0)  /*Location is at first line*/
			{
				Local_u8Location = 0x00 + Copy_u8Col;
			}
			else if(Copy_u8Row == LCD_ROW1)   /*Location is at second line*/
			{
				Local_u8Location = 0x40 + Copy_u8Col;
			}
			else if(Copy_u8Row == LCD_ROW2)   /*Location is at third line*/
			{
				Local_u8Location = 0x14 + Copy_u8Col;
			}
			else if(Copy_u8Row == LCD_ROW3)   /*Location is at fourth line*/
			{
				Local_u8Location = 0x54 + Copy_u8Col;
			}

#if LCD_InitMode == EightBit_Init
			/*send address of the ROW & COL*/
			LCD_voidSendCommand(CURSOR_OFFEST | Local_u8Location);
#elif LCD_InitMode == FourBit_Init
			Local_u8Var = CURSOR_OFFEST | Local_u8Location;
			LCD_voidSendCommand(Local_u8Var >> 4); 		//send upper nibble first
			LCD_voidSendCommand(Local_u8Var); 			//send lower nibble
#endif
		}
		else
			Local_u8ErrorStatus = LCD_E_PARAM_INVALID_COL_ID;

	}
	else
		Local_u8ErrorStatus = LCD_E_PARAM_INVALID_ROW_ID;


	return Local_u8ErrorStatus;

}


void LCD_voidSendNumber(s32 Copy_s32Number)
{
	u8 Local_u8String[10] = {'\0'};

	/* convert Copy_s32Number to a string*/
	ConvertToString((char*)Local_u8String, Copy_s32Number);

	/* send ConvertToString */
	LCD_u8SendString((char*)Local_u8String);
}
