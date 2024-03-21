/*
 * main.c
 *
 *  Created on: Mar 20, 2024
 *      Author: Mohamed Hussein
 */

#include "STD_TYPES.h"
#include "User_Functions.h"
#include "util/delay.h"

#include "DIO_interface.h"
#include "TIMER_interface.h"

#include "LCD_interface.h"
#include "KEYPAD_interface.h"
#include "SERVO_interface.h"
#include "LED_interface.h"

#define NOT_PRESSED			0x00


void main()
{
	u8 Local_u8Trials = 0, Local_u8Iterator = 0;
	u8 Local_u8Pass[4] = "123", Local_u8Password[20] = {NOT_PRESSED};

	DIO_voidInit();
	LCD_voidInit();


	LCD_u8GoToRowCol(LCD_ROW0, LCD_COL2);
	LCD_u8SendString("Welcome to Smart");
	LCD_u8GoToRowCol(LCD_ROW1, LCD_COL4);
	LCD_u8SendString("Door System");
	_delay_ms(1000);

	LCD_voidClearDisplay();
	LCD_u8GoToRowCol(LCD_ROW0, LCD_COL0);
	LCD_u8SendString("Enter Password:");
	LCD_u8GoToRowCol(LCD_ROW3, LCD_COL0);
	LCD_u8SendString("Enter ON/C to enter");


	while(1)
	{
		while(Local_u8Trials < 3)
		{
			LCD_u8GoToRowCol(LCD_ROW1, LCD_COL0);
			while(Local_u8Iterator < 20)
			{
				do
				{
					Local_u8Password[Local_u8Iterator] = KEYPAD_u8GetPressedKey();

					if(Local_u8Password[Local_u8Iterator] == '/' || Local_u8Password[Local_u8Iterator] == '*' ||
							Local_u8Password[Local_u8Iterator] == '-' || Local_u8Password[Local_u8Iterator] == '+' ||
							Local_u8Password[Local_u8Iterator] == '=')
						Local_u8Password[Local_u8Iterator] = 0x00;

				}while(Local_u8Password[Local_u8Iterator] == 0x00);

				if(Local_u8Password[Local_u8Iterator] == '.')
				{
					Local_u8Password[Local_u8Iterator] = NOT_PRESSED;
					break;
				}

				LCD_voidSendCharacter(Local_u8Password[Local_u8Iterator]);
				Local_u8Iterator++;
			}

			if(0 == StringCompare((const char*) Local_u8Pass, (const char*) Local_u8Password))
			{
				LCD_voidClearDisplay();
				LCD_u8GoToRowCol(LCD_ROW0, LCD_COL0);
				LCD_u8SendString("Welcome Home!");
				SERVO_u8SetAngle(TIMER1_CHANNEL_B, 90);
				LED_u8On(DIO_PORTD, DIO_PIN2);
				Local_u8Trials = 4;
				break;
			}
			else
			{
				Local_u8Iterator = 0;
				StringReset((char*) Local_u8Password, 20);
				LCD_u8GoToRowCol(LCD_ROW1, LCD_COL0);
				LCD_u8SendString("                    ");
				LCD_u8GoToRowCol(LCD_ROW2, LCD_COL0);
				LCD_u8SendString("Wrong Password");
			}

			Local_u8Trials++;

		}

		if(Local_u8Trials == 3)
		{
			Local_u8Trials++;

			LCD_voidClearDisplay();
			LCD_u8GoToRowCol(LCD_ROW0, LCD_COL0);
			LCD_u8SendString("Thieeeeeef!!!");
			LCD_u8GoToRowCol(LCD_ROW1, LCD_COL0);
			LCD_u8SendString("Calling 911 !!");
			LED_u8On(DIO_PORTD, DIO_PIN0);
			LED_u8On(DIO_PORTD, DIO_PIN1);
		}

	}
}

