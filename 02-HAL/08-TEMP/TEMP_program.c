/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: TEMP_program.c		            ************************/
/***************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"

#include "TEMP_interface.h"


/********************************				Function Definitions				********************************/

u8 TEMP_u8GetTempDegree (u16 copy_u16AdcResult, u8* copy_pu8Degree)
{
	u8 Local_u8ErrorState = OK;
	u16 Local_u16Analog = 0;

	if(copy_pu8Degree != NULL)
	{
		ADC_u8ConvertDigitalToAnalog(copy_u16AdcResult, &Local_u16Analog);

		*copy_pu8Degree = (u8)(Local_u16Analog / 10);
	}
	else
		Local_u8ErrorState = TEMP_E_PARAM_POINTER;

	return Local_u8ErrorState;
}
