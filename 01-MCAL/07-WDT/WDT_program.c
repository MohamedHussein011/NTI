/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: WDT_program.c		            ************************/
/***************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "WDT_interface.h"
#include "WDT_private.h"




/********************************				Function Definitions				********************************/

u8 WDT_u8Enable(u8 copy_u8TimerReset)
{
	u8 Local_u8ErrorStatus = OK;

	if(copy_u8TimerReset >= WDT_TIME_16MS && copy_u8TimerReset <= WDT_TIME_2100MS)
	{
		/* Set time to reset */
		WDTCR |= copy_u8TimerReset;

		/* Enable Watchdog*/
		SET_BIT(WDTCR, WDE);
	}
	else
		Local_u8ErrorStatus = WDT_E_PARAM_INVALID_TIME_RESET_ID;

	return Local_u8ErrorStatus;
}

void WDT_voidDisable(void)
{
	/* Write logical one to WDTOE and WDE */
	WDTCR = (1<<WDTOE) | (1<<WDE);
	/* Turn off WDT */
	WDTCR = 0x00;
}
