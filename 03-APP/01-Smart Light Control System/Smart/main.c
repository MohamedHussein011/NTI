/*
 * main.c
 *
 *  Created on: Mar 15, 2024
 *      Author: Mohamed Hussein
 */

#include "STD_TYPES.h"
#include "User_Functions.h"
#include "util/delay.h"

#include "DIO_interface.h"
#include "ADC_interface.h"
#include "GI_interface.h"

#include "LCD_interface.h"
#include "KEYPAD_interface.h"
#include "LDR_interface.h"
#include "LED_interface.h"

#define NOT_PRESSED			0x00

u8 u8Percentage = 0;
u16 u16ADCdig = 0, u16ADCana = 0, u16Threshold = 0;
u32 u32LDR = 0;

void SetThreshold (void);
void Display (void);
void LDR_percentage(void);

void main()
{
	u8 Local_u8Key = NOT_PRESSED;

	DIO_voidInit();
	ADC_voidInit();
	GI_voidEnable();

	LCD_voidInit();

	LCD_u8GoToRowCol(LCD_ROW0, LCD_COL3);
	LCD_u8SendString("Welcome Back!!!");

	LCD_u8GoToRowCol(LCD_ROW2, LCD_COL0);
	LCD_u8SendString("Smart Light Control System");
	_delay_ms(1000);

	while(1)
	{
		LCD_voidClearDisplay();
		_delay_ms(200);
		LCD_u8GoToRowCol(LCD_ROW0, LCD_COL0);
		LCD_u8SendString("1)Display Percentage");

		LCD_u8GoToRowCol(LCD_ROW1, LCD_COL0);
		LCD_u8SendString("2) Set Threshold");

		do
		{
			Local_u8Key = KEYPAD_u8GetPressedKey();
		}while(Local_u8Key == NOT_PRESSED);

		switch(Local_u8Key)
		{
		case '1':		Display();			break;
		case '2':		SetThreshold();		break;

		default:	LCD_u8GoToRowCol(LCD_ROW3, LCD_COL0);
		LCD_u8SendString("Wrong Choice");
		_delay_ms(500);				break;
		}

	}

}

void SetThreshold (void)
{
	u8 Local_u8Key[3] = {NOT_PRESSED}, Local_u8Iterator = 0;
	LCD_voidClearDisplay();
	_delay_ms(200);

	LCD_u8GoToRowCol(LCD_ROW0, LCD_COL0);
	LCD_u8SendString("Enter Threshold:");
	LCD_u8GoToRowCol(LCD_ROW3, LCD_COL0);
	LCD_u8SendString("Press ON/C to enter");
	LCD_u8GoToRowCol(LCD_ROW1, LCD_COL0);

	while(Local_u8Iterator < 3)
	{
		do
		{
			Local_u8Key[Local_u8Iterator] = KEYPAD_u8GetPressedKey();
			if(Local_u8Key[Local_u8Iterator] == '/' || Local_u8Key[Local_u8Iterator] == '*' ||
					Local_u8Key[Local_u8Iterator] == '-' || Local_u8Key[Local_u8Iterator] == '+' ||
					Local_u8Key[Local_u8Iterator] == '=')
			{
				Local_u8Key[Local_u8Iterator] = NOT_PRESSED;
			}

		}while(Local_u8Key[Local_u8Iterator] == NOT_PRESSED);

		if(Local_u8Key[Local_u8Iterator] == '.')
			break;

		LCD_voidSendCharacter(Local_u8Key[Local_u8Iterator]);

		Local_u8Iterator++;

		if(Local_u8Iterator >= 3)
		{
			u16Threshold = (u16)ConvertToint((const char*)Local_u8Key, Local_u8Iterator);

			if(u16Threshold > 100)
			{
				LCD_u8GoToRowCol(LCD_ROW2, LCD_COL0);
				LCD_u8SendString("Wrong Per range");
				LCD_u8GoToRowCol(LCD_ROW1, LCD_COL0);
				LCD_u8SendString("   ");
				LCD_u8GoToRowCol(LCD_ROW1, LCD_COL0);
				StringReset((char*)Local_u8Key);
				Local_u8Iterator = 0;
				_delay_ms(400);
			}
		}

	}

	_delay_ms(400);
	u16Threshold = (u8)ConvertToint((const char*)Local_u8Key, Local_u8Iterator);

}

void Display (void)
{
	u8 Local_u8Key = NOT_PRESSED;

	LCD_voidClearDisplay();
	_delay_ms(200);
	LCD_u8GoToRowCol(LCD_ROW0, LCD_COL0);
	LCD_u8SendString("Percentage:");
	LCD_u8GoToRowCol(LCD_ROW3, LCD_COL0);
	LCD_u8SendString("Press ON/C to return");

	while(Local_u8Key != '.')
	{
		do
		{
			ADC_u8SingleConversionAsynch(ADC_CHANNEL0, &u16ADCdig, &LDR_percentage);
			Local_u8Key = KEYPAD_u8GetPressedKey();
		}while(Local_u8Key == NOT_PRESSED);

	}
}

void LDR_percentage(void)
{
	ADC_u8ConvertDigitalToAnalog(u16ADCdig, &u16ADCana);
	LDR_u8GetValue(&u32LDR, u16ADCana);

	u8Percentage = (u8)s32Map(400, 66000, 0, 100, u32LDR);

	LCD_u8GoToRowCol(LCD_ROW0, LCD_COL14);
	LCD_u8SendString("   ");
	LCD_u8GoToRowCol(LCD_ROW0, LCD_COL14);
	LCD_voidSendNumber(u8Percentage);

	if(u8Percentage > (u8)u16Threshold)
	{
		LED_u8On(DIO_PORTD, DIO_PIN0);
		LCD_u8GoToRowCol(LCD_ROW1, LCD_COL0);
		LCD_u8SendString("LED is ON ");
	}
	else
	{
		LED_u8Off(DIO_PORTD, DIO_PIN0);
		LCD_u8GoToRowCol(LCD_ROW1, LCD_COL0);
		LCD_u8SendString("LED is OFF");
	}
}
