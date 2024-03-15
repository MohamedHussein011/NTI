/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: GI_program.c		            ************************/
/***************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GI_interface.h"
#include "GI_private.h"
#include "GI_config.h"

void GI_voidInit(void)
{
#if GI_EN == GI_ENABLE
	SET_BIT(SREG,GIE);
#elif GI_EN == GI_DISABLE
	CLR_BIT(SREG,GIE);
#else
#error "Wrong GIE selection"
#endif
}

void GI_voidEnable (void)
{
	SET_BIT(SREG,GIE);
}

void GI_voidDisable (void)
{
	CLR_BIT(SREG,GIE);
}
