/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: LDR_program.c		            ************************/
/***************************************************************************************/
#include "STD_TYPES.h"

#include "ADC_interface.h"

#include "LDR_interface.h"
#include "LDR_config.h"


/********************************				Function Definitions				********************************/
u8 LDR_u8GetValue (u32* copy_pu32Value, u16 copy_u16AdcResult)
{
	u8 Local_u8ErrorState = OK;
	u16 Local_u16Analog = 0;

	if(copy_pu32Value != NULL)
	{
		ADC_u8ConvertDigitalToAnalog(copy_u16AdcResult, &Local_u16Analog);
		*copy_pu32Value = (u32)((u32)((LDR_VIN - Local_u16Analog) * LDR_R) / Local_u16Analog);
	}
	else
		Local_u8ErrorState = LDR_E_PARAM_POINTER;

	return Local_u8ErrorState;
}
