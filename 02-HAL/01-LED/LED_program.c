/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: LED_program.c		            ************************/
/***************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "LED_interface.h"
#include "LED_config.h"


u8 LED_u8ON (u8 copy_u8Port, u8 copy_u8Pin)
{
	u8 Local_u8ErrorState = OK;

	if(copy_u8Port >= DIO_PORTA && copy_u8Port <= DIO_PORTD)
	{
		if(copy_u8Pin >= DIO_PIN0 && copy_u8Pin <= DIO_PIN7)
		{
			DIO_u8SetPinValue(copy_u8Port, copy_u8Pin, DIO_PIN_HIGH);
		}
		else
			Local_u8ErrorState = LED_E_PARAM_INVALID_PIN_ID;
	}
	else
		Local_u8ErrorState = LED_E_PARAM_INVALID_PORT_ID;

	return Local_u8ErrorState;
}

u8 LED_u8OFF (u8 copy_u8Port, u8 copy_u8Pin)
{
	u8 Local_u8ErrorState = OK;

	if(copy_u8Port >= DIO_PORTA && copy_u8Port <= DIO_PORTD)
	{
		if(copy_u8Pin >= DIO_PIN0 && copy_u8Pin <= DIO_PIN7)
		{
			DIO_u8SetPinValue(copy_u8Port, copy_u8Pin, DIO_PIN_LOW);
		}
		else
			Local_u8ErrorState = LED_E_PARAM_INVALID_PIN_ID;
	}
	else
		Local_u8ErrorState = LED_E_PARAM_INVALID_PORT_ID;

	return Local_u8ErrorState;
}

u8 LED_u8TOG (u8 copy_u8Port, u8 copy_u8Pin)
{
	u8 Local_u8ErrorState = OK;

	if(copy_u8Port >= DIO_PORTA && copy_u8Port <= DIO_PORTD)
	{
		if(copy_u8Pin >= DIO_PIN0 && copy_u8Pin <= DIO_PIN7)
		{
			DIO_u8TogglePinValue(copy_u8Port, copy_u8Pin);
		}
		else
			Local_u8ErrorState = LED_E_PARAM_INVALID_PIN_ID;
	}
	else
		Local_u8ErrorState = LED_E_PARAM_INVALID_PORT_ID;

	return Local_u8ErrorState;
}
