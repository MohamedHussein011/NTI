/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: KEYPAD_program.c		            ************************/
/***************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "KEYPAD_interface.h"
#include "KEYPAD_config.h"



void KEYPAD_voidInit (void)
{
	u8 Local_u8ColPorts[4] = {KEYPAD_COL0_PORT, KEYPAD_COL1_PORT, KEYPAD_COL2_PORT, KEYPAD_COL3_PORT};
	u8 Local_u8ColPins[4] = {KEYPAD_COL0_PIN, KEYPAD_COL1_PIN, KEYPAD_COL2_PIN, KEYPAD_COL3_PIN};
	u8 Local_u8RowPorts[4] = {KEYPAD_ROW0_PORT, KEYPAD_ROW1_PORT, KEYPAD_ROW2_PORT, KEYPAD_ROW3_PORT};
	u8 Local_u8RowPins[4] = {KEYPAD_ROW0_PIN, KEYPAD_ROW1_PIN, KEYPAD_ROW2_PIN, KEYPAD_ROW3_PIN};

#if KEYPAD_IN_TYPE == KEYPAD_INPUT_PULLUP
#if KEYPAD_CONTROL == ROW_CONTROL
	for(u8 i=0; i<4; i++)
	{
		DIO_u8ActivePinInPullUpResistance(Local_u8ColPorts[i], Local_u8ColPins[i]);
		DIO_u8SetPinDirection(Local_u8RowPorts[i], Local_u8RowPins[i], DIO_PIN_OUTPUT);
		DIO_u8SetPinValue(Local_u8RowPorts[i], Local_u8RowPins[i], DIO_PIN_HIGH);
	}
#elif KEYPAD_CONTROL == COL_CONTROL
	for(u8 i=0; i<4; i++)
	{
		DIO_u8SetPinDirection(Local_u8ColPorts[i], Local_u8ColPins[i], DIO_PIN_OUTPUT);
		DIO_u8SetPinValue(Local_u8ColPorts[i], Local_u8ColPins[i], DIO_PIN_HIGH);
		DIO_u8ActivePinInPullUpResistance(Local_u8RowPorts[i], Local_u8RowPorts[i]);
	}
#endif

#elif (KEYPAD_IN_TYPE == KEYPAD_INPUT_PU || KEYPAD_IN_TYPE == KEYPAD_INPUT_PD)
#if KEYPAD_CONTROL == ROW_CONTROL
	for(u8 i=0; i<4; i++)
	{
		DIO_u8SetPinDirection(Local_u8ColPorts[i], Local_u8ColPins[i], DIO_PIN_INPUT);
		DIO_u8SetPinDirection(Local_u8RowPorts[i], Local_u8RowPins[i], DIO_PIN_OUTPUT);
	}
#elif KEYPAD_CONTROL == COL_CONTROL
	for(u8 i=0; i<4; i++)
	{
		DIO_u8SetPinDirection(Local_u8ColPorts[i], Local_u8ColPins[i], DIO_PIN_OUTPUT);
		DIO_u8SetPinDirection(Local_u8RowPorts[i], Local_u8RowPins[i], DIO_PIN_INPUT);
	}
#endif

#endif


}
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

	for(u8 Local_u8Col = 0; Local_u8Col < 4; Local_u8Col++)
	{
#if (KEYPAD_IN_TYPE == KEYPAD_INPUT_PULLUP || KEYPAD_IN_TYPE == KEYPAD_INPUT_PU)
#if KEYPAD_CONTROL == ROW_CONTROL
		/*Activate current ROW*/
		DIO_u8SetPinValue(Local_u8RowPorts[Local_u8Col], Local_u8RowPins[Local_u8Col], DIO_PIN_LOW);
#elif KEYPAD_CONTROL == COL_CONTROL
		/*Activate current Column*/
		DIO_u8SetPinValue(Local_u8ColPorts[Local_u8Col], Local_u8ColPins[Local_u8Col], DIO_PIN_LOW);
#endif

#elif (KEYPAD_IN_TYPE == KEYPAD_INPUT_PD)
#if KEYPAD_CONTROL == ROW_CONTROL
		/*Activate current ROW*/
		DIO_u8SetPinValue(Local_u8RowPorts[Local_u8Col], Local_u8RowPins[Local_u8Col], DIO_PIN_HIGH);
#elif KEYPAD_CONTROL == COL_CONTROL
		/*Activate current Column*/
		DIO_u8SetPinValue(Local_u8ColPorts[Local_u8Col], Local_u8ColPins[Local_u8Col], DIO_PIN_HIGH);
#endif

#endif

		for(u8 Local_u8Row = 0; Local_u8Row < 4; Local_u8Row++)
		{
#if (KEYPAD_IN_TYPE == KEYPAD_INPUT_PULLUP || KEYPAD_IN_TYPE == KEYPAD_INPUT_PU)
#if KEYPAD_CONTROL == ROW_CONTROL
			/*Read current Column*/
			DIO_u8GetPinValue(Local_u8ColPorts[Local_u8Row], Local_u8ColPins[Local_u8Row], &Local_u8PinState);
			/*check if the switch is pressed*/
			if(Local_u8PinState == DIO_PIN_LOW)
			{
				/*get the value*/
				Local_u8PressedKey = Local_u8Array[Local_u8Row][Local_u8Col];
				/*Polling to make sure it is pressed one time (single pressed)*/
				while(Local_u8PinState == DIO_PIN_LOW)
				{
					DIO_u8GetPinValue(Local_u8ColPorts[Local_u8Row], Local_u8ColPins[Local_u8Row], &Local_u8PinState);
				}

				return Local_u8PressedKey;
			}
#elif KEYPAD_CONTROL == COL_CONTROL
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
#endif

#elif (KEYPAD_IN_TYPE == KEYPAD_INPUT_PD)
#if KEYPAD_CONTROL == ROW_CONTROL
			/*Read current Column*/
			DIO_u8GetPinValue(Local_u8ColPorts[Local_u8Row], Local_u8ColPins[Local_u8Row], &Local_u8PinState);
			/*check if the switch is pressed*/
			if(Local_u8PinState == DIO_PIN_HIGH)
			{
				/*get the value*/
				Local_u8PressedKey = Local_u8Array[Local_u8Row][Local_u8Col];
				/*Polling to make sure it is pressed one time (single pressed)*/
				while(Local_u8PinState == DIO_PIN_HIGH)
				{
					DIO_u8GetPinValue(Local_u8ColPorts[Local_u8Row], Local_u8ColPins[Local_u8Row], &Local_u8PinState);
				}

				return Local_u8PressedKey;
			}
#elif KEYPAD_CONTROL == COL_CONTROL
			/*Read current Row*/
			DIO_u8GetPinValue(Local_u8RowPorts[Local_u8Row], Local_u8RowPins[Local_u8Row], &Local_u8PinState);
			/*check if the switch is pressed*/
			if(Local_u8PinState == DIO_PIN_HIGH)
			{
				/*get the value*/
				Local_u8PressedKey = Local_u8Array[Local_u8Row][Local_u8Col];
				/*Polling to make sure it is pressed one time (single pressed)*/
				while(Local_u8PinState == DIO_PIN_HIGH)
				{
					DIO_u8GetPinValue(Local_u8RowPorts[Local_u8Row], Local_u8RowPins[Local_u8Row], &Local_u8PinState);
				}

				return Local_u8PressedKey;
			}
#endif

#endif

		}

#if (KEYPAD_IN_TYPE == KEYPAD_INPUT_PULLUP || KEYPAD_IN_TYPE == KEYPAD_INPUT_PU)
#if KEYPAD_CONTROL == ROW_CONTROL
		/*Deactivate current ROW*/
		DIO_u8SetPinValue(Local_u8RowPorts[Local_u8Col], Local_u8RowPins[Local_u8Col], DIO_PIN_HIGH);
#elif KEYPAD_CONTROL == COL_CONTROL
		/*Deactivate current Column*/
		DIO_u8SetPinValue(Local_u8ColPorts[Local_u8Col], Local_u8ColPins[Local_u8Col], DIO_PIN_HIGH);
#endif

#elif (KEYPAD_IN_TYPE == KEYPAD_INPUT_PD)
#if KEYPAD_CONTROL == ROW_CONTROL
		/*Deactivate current ROW*/
		DIO_u8SetPinValue(Local_u8RowPorts[Local_u8Col], Local_u8RowPins[Local_u8Col], DIO_PIN_LOW);
#elif KEYPAD_CONTROL == COL_CONTROL
		/*Deactivate current Column*/
		DIO_u8SetPinValue(Local_u8ColPorts[Local_u8Col], Local_u8ColPins[Local_u8Col], DIO_PIN_LOW);
#endif

#endif

	}

	return Local_u8PressedKey;

}
