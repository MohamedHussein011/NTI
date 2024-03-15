/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: LDR_program.c		            ************************/
/***************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "LDR_interface.h"
#include "LDR_config.h"


/********************************				Function Definitions				********************************/
u8 LDR_u8GetValue (u32* copy_pu32Value, u16 copy_u16Analog)
{
	u8 Local_u8ErrorState = OK;

	if(copy_u16Analog != NULL)
	{
		*copy_pu32Value = (u32)((u32)((LDR_VIN - copy_u16Analog) * LDR_R) / copy_u16Analog);
	}
	else
		Local_u8ErrorState = LDR_E_PARAM_POINTER;

	return Local_u8ErrorState;
}
