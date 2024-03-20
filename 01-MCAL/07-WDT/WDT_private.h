/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: WDT_private.h	                ************************/
/***************************************************************************************/

#ifndef WDT_PRIVATE_H
#define WDT_PRIVATE_H

/***********************				Registers						************************/

/* Watchdog Timer Control Register – WDTCR */
#define WDTCR					(*(volatile u8*) 0x41)
#define WDTOE					4 			//Watchdog Turn-off Enable
#define WDE						3			//Watchdog Enable

#endif
