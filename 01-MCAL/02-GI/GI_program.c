/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: GI_program.c		            ************************/
/***************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GI_interface.h"
#include "GI_private.h"


/********************************				Function Definitions				********************************/

void GI_voidEnable (void)
{
	SET_BIT(SREG,GIE);
}

void GI_voidDisable (void)
{
	CLR_BIT(SREG,GIE);
}

u8 GI_u8GetFlag (void)
{
	u8 Local_u8Flag = GET_BIT(SREG,GIE);

	return Local_u8Flag;
}
