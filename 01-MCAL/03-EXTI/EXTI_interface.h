/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: EXTI_interface.h	            ************************/
/***************************************************************************************/


#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

/* NOTE:
 * if you want to generate software interrupt using external interrupt
 * 1) configure INT0 or INT1 or INT2 as output pin
 * 2) set sense control for your external interrupt & enable it
 * 3) output high or low (depending on sense control) on INT0 or INT1 or INT2 pin
 */

/*********************************		Error classification	******************************/
//Invalid External Interrupt ID requested
#define EXTI_E_PARAM_INVALID_INT_ID						0x0A
//Invalid External Interrupt Sense Control ID requested
#define EXTI_E_PARAM_INVALID_INT_CONTROL_ID				0x0B
//Invalid External Interrupt Sense Control ID for INT2 requested
#define EXTI_E_PARAM_INVALID_INT2_CONTROL_ID			0x0C
//APIs called with a Null Pointer
#define EXTI_E_PARAM_POINTER							0x0D


/******************************************************************************
* !comment : Select Interrupt Sense Control option:  		 	               *
*           1: LOW_LEVEL                                                     *
*           2: ON_CHANGE                                                     *
            3: FALLING_EDGE                                                     *
            4: RISING_EDGE                                         			*
******************************************************************************/
#define LOW_LEVEL        0
#define ON_CHANGE        1
#define FALLING_EDGE     2
#define RISING_EDGE      3

/******************************************************************************
* !comment : Select External Interrupts sources option:  		 	               *
*           1: INT0                                                     *
*           2: INT1                                                     *
            3: INT2                                                     *
******************************************************************************/

#define EXT_INT0        0          /* Pin D2 */
#define EXT_INT1        1          /* Pin D3 */
#define EXT_INT2        2          /* Pin B2 */

//Enable or disable
#define EXTI_ENABLE					0
#define EXTI_DISABLE				1


/********************************				Function Prototypes				********************************/
/* @brief		shall initialize external interrupt 0
*				with the configuration set in EXTI_config.h
* @paramin		none
* @paramout		none
* @retval		none
*/
void EXTI_voidINT0 (void);

/* @brief		shall initialize external interrupt 1
*				with the configuration set in EXTI_config.h
* @paramin		none
* @paramout		none
* @retval		none
*/
void EXTI_voidINT1 (void);

/* @brief		shall initialize external interrupt 2
*				with the configuration set in EXTI_config.h
* @paramin		none
* @paramout		none
* @retval		none
*/
void EXTI_voidINT2 (void);

/* @brief		shall set external interrupt with specific sense control during runtime
* @paramin		copy_u8InterruptSource / Interrupt Source - copy_u8SenseControl / Interrupt Sense Control
* @paramout		none
* @retval		Error State of Wrong paramin
* @note			if INT2 is already enabled & you want to use this function,you must enable INT2
* 			    again after using this function by calling EXTI_u8EnableInterrupt
*/
u8 EXTI_u8SetSenseControl (u8 copy_u8InterruptSource, u8 copy_u8SenseControl);

/* @brief		shall enable external interrupt during runtime
* @paramin		copy_u8InterruptSource / Interrupt Source
* @paramout		none
* @retval		Error State of Wrong paramin
*/
u8 EXTI_u8EnableInterrupt (u8 copy_u8InterruptSource);

/* @brief		shall disable external interrupt during runtime
* @paramin		copy_u8InterruptSource / Interrupt Source
* @paramout		none
* @retval		Error State of Wrong paramin
*/
u8 EXTI_u8DisableInterrupt (u8 copy_u8InterruptSource);

/* @brief		shall initialize external interrupt ISR with function needed to be executed
 * 				when the external interrupt is fired during runtime
* @paramin		copy_u8InterruptSource / Interrupt Source - copy_pvFunc / pointer to a function that
*                takes nothing & returns nothing and being called when external interrupt happens
* @paramout		none
* @retval		Error State of Wrong paramin
*/
u8 EXTI_u8CallBack (u8 copy_u8InterruptSource, pvFunction_t copy_pvFunc);

#endif 
