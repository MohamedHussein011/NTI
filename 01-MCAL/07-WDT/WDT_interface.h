/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: WDT_interface.h	            ************************/
/***************************************************************************************/


#ifndef WDT_INTERFACE_H
#define WDT_INTERFACE_H

/* NOTE: clocked from a separate On-chip Oscillator which runs at 1MHz.
 * */


/*********************************		Error classification	******************************/
//Invalid Timer interrupt ID requested
#define WDT_E_PARAM_INVALID_TIME_RESET_ID				0x0A


/*********************************		MACROs	******************************/
/* Watchdog Timer Prescaler 2, 1, and 0 */
#define WDT_TIME_16MS					0		//VCC=5v -> 16.3 ms , VCC=3v -> 17.1 ms
#define WDT_TIME_32MS					1		//VCC=5v -> 32.5 ms , VCC=3v -> 34.3 ms
#define WDT_TIME_65MS					2		//VCC=5v -> 65 ms , VCC=3v -> 68.5 ms
#define WDT_TIME_130MS					3		//VCC=5v -> 0.13 s , VCC=3v -> 0.14 s
#define WDT_TIME_260MS					4		//VCC=5v -> 0.26 s , VCC=3v -> 0.27 s
#define WDT_TIME_520MS					5		//VCC=5v -> 0.52 s , VCC=3v -> 0.55 s
#define WDT_TIME_1000MS					6		//VCC=5v -> 1 s , VCC=3v -> 1.1 s
#define WDT_TIME_2100MS					7		//VCC=5v -> 2.1 s , VCC=3v -> 2.2 s


/********************************				Function Prototypes				********************************/

/********************************				 TIMER0  						********************************/
/* @brief		shall enable Watchdog with time to reset
* @paramin		copy_u8TimerReset / timeout to reset the uc
* @paramout		none
* @retval		error of wrong paramin
*/
u8 WDT_u8Enable(u8 copy_u8TimerReset);

/* @brief		shall disable watchdog
* @paramin		none
* @paramout		none
* @retval		none
*/
void WDT_voidDisable(void);


#endif 
