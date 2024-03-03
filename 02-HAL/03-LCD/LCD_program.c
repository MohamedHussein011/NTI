/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: LCD_program.c		            ************************/
/***************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"

#include "DIO_interface.h"

#include "LCD_interface.h"
#include "LCD_config.h"

void LCD_voidInit(void)
{
	/* 1. LCD Pin Directions */
	/* Control Pins Directions */
	DIO_u8SetPinDirection(LCD_RS_PORT, LCD_RS_PIN, DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(LCD_RW_PORT, LCD_RW_PIN, DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(LCD_EN_PORT, LCD_EN_PIN, DIO_PIN_OUTPUT);

#if LCD_InitMode == EightBit_Init
	/* Data Pins Directions */
	DIO_u8SetPinDirection(LCD_DATA_PORT_D0, LCD_DATA_PIN_D0, DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(LCD_DATA_PORT_D1, LCD_DATA_PIN_D1, DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(LCD_DATA_PORT_D2, LCD_DATA_PIN_D2, DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(LCD_DATA_PORT_D3, LCD_DATA_PIN_D3, DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(LCD_DATA_PORT_D4, LCD_DATA_PIN_D4, DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(LCD_DATA_PORT_D5, LCD_DATA_PIN_D5, DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(LCD_DATA_PORT_D6, LCD_DATA_PIN_D6, DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(LCD_DATA_PORT_D7, LCD_DATA_PIN_D7, DIO_PIN_OUTPUT);

	/*Wait for more than 30ms*/
	_delay_ms(40);
	/*Function Set: 1 or 2 Lines & 5x8 or 5x11 Dots*/
#if LCD_NumbersOfLines == One_Line
#if LCD_Font_Size == FiveEight_Size
	LCD_voidSendCommand(OneLine_5x8_8Bit);
#elif LCD_Font_Size == FiveEleven_Size
	LCD_voidSendCommand(OneLine_5x11_8Bit);
#endif
#elif LCD_NumbersOfLines == Two_Lines
#if LCD_Font_Size == FiveEight_Size
	LCD_voidSendCommand(TwoLine_5x8_8Bit);
#elif LCD_Font_Size == FiveEleven_Size
	LCD_voidSendCommand(TwoLine_5x11_8Bit);
#endif
#endif
	/*Wait for more than 39us*/
	_delay_us(40);
	/*Display On/Off control*/
#if LCD_Display == Display_ON
#if LCD_Cursor == Cursor_ON
#if LCD_Blinking == Blinking_ON
	LCD_voidSendCommand(DisplayOn_CursorOn_BlinkingOn);
#elif LCD_Blinking == Blinking_OFF
	LCD_voidSendCommand(DisplayOn_CursorOn_BlinkingOff);
#endif /*Blinking*/
#elif LCD_Cursor == Cursor_OFF
#if LCD_Blinking == Blinking_ON
	LCD_voidSendCommand(DisplayOn_CursorOff_BlinkingOn);
#elif LCD_Blinking == Blinking_OFF
	LCD_voidSendCommand(DisplayOn_CursorOff_BlinkingOff);
#endif  /*Blinking*/
#endif  /*cursor*/
#elif LCD_Display == Display_OFF
#if LCD_Cursor == Cursor_ON
#if LCD_Blinking == Blinking_ON
	LCD_voidSendCommand(DisplayOff_CursorOn_BlinkingOn);
#elif LCD_Blinking == Blinking_OFF
	LCD_voidSendCommand(DisplayOff_CursorOn_BlinkingOff);
#endif   /*Blinking*/
#elif LCD_Cursor == Cursor_OFF
#if LCD_Blinking == Blinking_ON
	LCD_voidSendCommand(DisplayOff_CursorOff_BlinkingOn);
#elif LCD_Blinking == Blinking_OFF
	LCD_voidSendCommand(DisplayOff_CursorOff_BlinkingOff);
#endif  /*Blinking*/
#endif  /*cursor*/
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
	/* Data Pins Directions */
	DIO_u8SetPinDirection(LCD_DATA_PORT_D4, LCD_DATA_PIN_D4, DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(LCD_DATA_PORT_D5, LCD_DATA_PIN_D5, DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(LCD_DATA_PORT_D6, LCD_DATA_PIN_D6, DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(LCD_DATA_PORT_D7, LCD_DATA_PIN_D7, DIO_PIN_OUTPUT);

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
#endif
#elif LCD_NumbersOfLines == Two_Lines
#if LCD_Font_Size == FiveEight_Size
	LCD_voidSendCommand(TwoLine_5x8_4Bit);
#elif LCD_Font_Size == FiveEleven_Size
	LCD_voidSendCommand(TwoLine_5x11_4Bit);
#endif
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
#endif /*Blinking*/
#elif LCD_Cursor == Cursor_OFF
#if LCD_Blinking == Blinking_ON
	LCD_voidSendCommand(0x00);
	LCD_voidSendCommand(DisplayOn_CursorOff_BlinkingOn);
#elif LCD_Blinking == Blinking_OFF
	LCD_voidSendCommand(0x00);
	LCD_voidSendCommand(DisplayOn_CursorOff_BlinkingOff);
#endif  /*Blinking*/
#endif  /*cursor*/
#elif LCD_Display == Display_OFF
#if LCD_Cursor == Cursor_ON
#if LCD_Blinking == Blinking_ON
	LCD_voidSendCommand(0x00);
	LCD_voidSendCommand(DisplayOff_CursorOn_BlinkingOn);
#elif LCD_Blinking == Blinking_OFF
	LCD_voidSendCommand(0x00);
	LCD_voidSendCommand(DisplayOff_CursorOn_BlinkingOff);
#endif   /*Blinking*/
#elif LCD_Cursor == Cursor_OFF
#if LCD_Blinking == Blinking_ON
	LCD_voidSendCommand(0x00);
	LCD_voidSendCommand(DisplayOff_CursorOff_BlinkingOn);
#elif LCD_Blinking == Blinking_OFF
	LCD_voidSendCommand(0x00);
	LCD_voidSendCommand(DisplayOff_CursorOff_BlinkingOff);
#endif  /*Blinking*/
#endif  /*cursor*/
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
#error "Wrong init mode selection"
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
	LCD_voidSendCommand(CLEAR_DISPLAY >> 4);
	LCD_voidSendCommand(CLEAR_DISPLAY);

	LCD_voidSendCommand(CURSOR_OFFEST >> 4);
	LCD_voidSendCommand(CURSOR_OFFEST);
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
#error "Wrong init mode selection"
#endif

}
void LCD_voidSendString(const char* Copy_pchString)
{
	u8 Local_u8Iterator = 0;
	while(Copy_pchString[Local_u8Iterator] != '\0')
	{
		LCD_voidSendCharacter(Copy_pchString[Local_u8Iterator]);
		Local_u8Iterator++;
	}
}
void LCD_voidCreateCustomunCharacter(const u8 *Copy_pu8Pattern, u8 Copy_u8Location)
{
	u8 Local_u8Iterator=0;

	/* CGRAM addresses ranges from 0x40 to 0x7f
	 * it allows you to create 8 different custom characters at 8 different locations at CGRAM (from 0 to 7)
	 * every new character is 8 bit, so every location is 8bit
	 * Copy_pchPattern is an array of bits for all 5x7 or 5x10 dots, 5 columns 7 rows or 10 rows
	 * so every element represents a row which is 5 bit long ---> every row contains 5 pixels
	 */

	/*send location of CGRAM i want to write*/
#if LCD_InitMode == FourBit_Init
	LCD_voidSendCommand((0x40 + (Copy_u8Location*8))>> 4);
#endif
	LCD_voidSendCommand((0x40 + (Copy_u8Location*8)));

	for(Local_u8Iterator = 0; Local_u8Iterator<8; Local_u8Iterator++)
	{
		LCD_voidSendCharacter(Copy_pu8Pattern[Local_u8Iterator]);
	}
}

void LCD_voidSendCustomunCharacter(u8 Copy_u8Location, u8 Copy_u8Row, u8 Copy_u8Col)
{
	/*Go to ROW & COL i want to display on screen*/
	LCD_voidGoToRowCol(Copy_u8Row, Copy_u8Col);

	/*send location to DDRAM to output the character on the screen*/
	LCD_voidSendCharacter(Copy_u8Location);
}

void LCD_voidGoToRowCol (u8 Copy_u8Row, u8 Copy_u8Col)
{
	u8 Local_u8Location = 0, Local_u8Var = 0;

	if(Copy_u8Row == 0)  /*Location is at first line*/
	{
		Local_u8Location = 0x00 + Copy_u8Col;
	}
	else if(Copy_u8Row == 1)   /*Location is at second line*/
	{
		Local_u8Location = 0x40 + Copy_u8Col;
	}
	else if(Copy_u8Row == 2)   /*Location is at third line*/
	{
		Local_u8Location = 0x14 + Copy_u8Col;
	}
	else if(Copy_u8Row == 3)   /*Location is at fourth line*/
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

void LCD_voidSendNumber(s32 Copy_s32Number)
{
	s32 Local_s32Temp1 = 0, Local_s32Length = 0, Local_s32Remainder = 0, Local_s32Temp2 = 0;
	u8 Local_u8String[10] = {'\0'};

	if(Copy_s32Number == 0)
	{
		Local_u8String[0] = '0';
		Local_s32Length++;
		Local_u8String[Local_s32Length] = '\0';
	}
	else
	{
		Local_s32Temp2 = Copy_s32Number;
		if(Local_s32Temp2<0)
		{
			Local_s32Length++;
			Copy_s32Number *= -1;
		}

		Local_s32Temp1 = Copy_s32Number;

		while(Local_s32Temp1 > 0)
		{
			Local_s32Temp1 /= 10;
			Local_s32Length++;
		}

		for(s32 i = 0; i<Local_s32Length; i++)
		{
			Local_s32Remainder = Copy_s32Number % 10;
			Copy_s32Number = Copy_s32Number / 10;
			Local_u8String[Local_s32Length - (i+1)] = Local_s32Remainder + '0';
		}

		if(Local_s32Temp2 < 0)
			Local_u8String[0] = '-';

		Local_u8String[Local_s32Length] = '\0';
	}

	LCD_voidSendString(Local_u8String);
}
