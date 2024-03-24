/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: KEYPAD_program.c		            ************************/
/***************************************************************************************/
#include "STD_TYPES.h"

#include "DIO_interface.h"

#include "KEYPAD_interface.h"
#include "KEYPAD_config.h"


/********************************				Function Definitions				********************************/
u8 KEYPAD_u8GetPressedKey (void)
{
	u8 Local_u8PinState, Local_u8PressedKey = KEYPAD_NOT_PRESSED;
	/*static is used to save these arrays in .data/.bss rather than stack as its size is small
	 *as we call this function alot
	 */
	static u8 Local_u8ColPorts[4] = {KEYPAD_COL0_PORT, KEYPAD_COL1_PORT, KEYPAD_COL2_PORT, KEYPAD_COL3_PORT};
	static u8 Local_u8ColPins[4] = {KEYPAD_COL0_PIN, KEYPAD_COL1_PIN, KEYPAD_COL2_PIN, KEYPAD_COL3_PIN};
	static u8 Local_u8RowPorts[4] = {KEYPAD_ROW0_PORT, KEYPAD_ROW1_PORT, KEYPAD_ROW2_PORT, KEYPAD_ROW3_PORT};
	static u8 Local_u8RowPins[4] = {KEYPAD_ROW0_PIN, KEYPAD_ROW1_PIN, KEYPAD_ROW2_PIN, KEYPAD_ROW3_PIN};
	static u8 Local_u8Array[4][4] = KEYPAD_ARRAY;

#if KEYPAD_CONTROL == ROW_CONTROL

	for(u8 Local_u8Row = 0; Local_u8Row < 4; Local_u8Row++)
	{
		/*Activate current ROW*/
		DIO_u8SetPinValue(Local_u8RowPorts[Local_u8Row], Local_u8RowPins[Local_u8Row], DIO_PIN_LOW);

		for(u8 Local_u8Col = 0; Local_u8Col < 4; Local_u8Col++)
		{
			/*Read current Column*/
			DIO_u8GetPinValue(Local_u8ColPorts[Local_u8Col], Local_u8ColPins[Local_u8Col], &Local_u8PinState);
			/*check if the switch is pressed*/
			if(Local_u8PinState == DIO_PIN_LOW)
			{
				/*get the value*/
				Local_u8PressedKey = Local_u8Array[Local_u8Row][Local_u8Col];
				/*Polling to make sure it is pressed one time (single pressed)*/
				while(Local_u8PinState == DIO_PIN_LOW)
				{
					DIO_u8GetPinValue(Local_u8ColPorts[Local_u8Col], Local_u8ColPins[Local_u8Col], &Local_u8PinState);
				}

				return Local_u8PressedKey;
			}

		}

		/*Deactivate current ROW*/
		DIO_u8SetPinValue(Local_u8RowPorts[Local_u8Row], Local_u8RowPins[Local_u8Row], DIO_PIN_HIGH);
	}
#elif KEYPAD_CONTROL == COL_CONTROL

	for(u8 Local_u8Col = 0; Local_u8Col < 4; Local_u8Col++)
	{
		/*Activate current Column*/
		DIO_u8SetPinValue(Local_u8ColPorts[Local_u8Col], Local_u8ColPins[Local_u8Col], DIO_PIN_LOW);

		for(u8 Local_u8Row = 0; Local_u8Row < 4; Local_u8Row++)
		{
			/*Read current Row*/
			DIO_u8GetPinValue(Local_u8RowPorts[Local_u8Row], Local_u8RowPins[Local_u8Row], &Local_u8PinState);
			/*check if the switch is pressed*/
			if(Local_u8PinState == DIO_PIN_LOW)
			{
				/*get the value*/
				Local_u8PressedKey = Local_u8Array[Local_u8Row][Local_u8Col];
				/*Polling to make sure it is pressed one time (single pressed)*/
				while(Local_u8PinState == DIO_PIN_LOW)
				{
					DIO_u8GetPinValue(Local_u8RowPorts[Local_u8Row], Local_u8RowPins[Local_u8Row], &Local_u8PinState);
				}

				return Local_u8PressedKey;
			}

		}

		/*Deactivate current Column*/
		DIO_u8SetPinValue(Local_u8ColPorts[Local_u8Col], Local_u8ColPins[Local_u8Col], DIO_PIN_HIGH);
	}

#endif

	return Local_u8PressedKey;

}
