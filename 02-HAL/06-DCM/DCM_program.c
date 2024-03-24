/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: DCM_program.c		            ************************/
/***************************************************************************************/
#include "STD_TYPES.h"

#include "DIO_interface.h"

#include "DCM_interface.h"


/********************************				Function Definitions				********************************/

u8 DCM_u8RotateCW (u8 copy_u8Port0, u8 copy_u8Pin0, u8 copy_u8Port1, u8 copy_u8Pin1)
{
	u8 Local_u8ErrorState = OK;

	if(copy_u8Port0 >= DIO_PORTA && copy_u8Port0 <= DIO_PORTD &&
			copy_u8Port1 >= DIO_PORTA && copy_u8Port1 <= DIO_PORTD)
	{
		if(copy_u8Pin0 >= DIO_PIN0 && copy_u8Pin0 <= DIO_PIN7 &&
				copy_u8Pin1 >= DIO_PIN0 && copy_u8Pin1 <= DIO_PIN7)
		{
			DIO_u8SetPinValue(copy_u8Port0, copy_u8Pin0, DIO_PIN_HIGH);
			DIO_u8SetPinValue(copy_u8Port1, copy_u8Pin1, DIO_PIN_LOW);
		}
		else
			Local_u8ErrorState = DCM_E_PARAM_INVALID_PIN_ID;
	}
	else
		Local_u8ErrorState = DCM_E_PARAM_INVALID_PORT_ID;

	return Local_u8ErrorState;
}

u8 DCM_u8RotateCCW (u8 copy_u8Port0, u8 copy_u8Pin0, u8 copy_u8Port1, u8 copy_u8Pin1)
{
	u8 Local_u8ErrorState = OK;

	if(copy_u8Port0 >= DIO_PORTA && copy_u8Port0 <= DIO_PORTD &&
			copy_u8Port1 >= DIO_PORTA && copy_u8Port1 <= DIO_PORTD)
	{
		if(copy_u8Pin0 >= DIO_PIN0 && copy_u8Pin0 <= DIO_PIN7 &&
				copy_u8Pin1 >= DIO_PIN0 && copy_u8Pin1 <= DIO_PIN7)
		{
			DIO_u8SetPinValue(copy_u8Port0, copy_u8Pin0, DIO_PIN_LOW);
			DIO_u8SetPinValue(copy_u8Port1, copy_u8Pin1, DIO_PIN_HIGH);
		}
		else
			Local_u8ErrorState = DCM_E_PARAM_INVALID_PIN_ID;
	}
	else
		Local_u8ErrorState = DCM_E_PARAM_INVALID_PORT_ID;

	return Local_u8ErrorState;
}
