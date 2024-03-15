/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: KEYPAD_interface.h	            ************************/
/***************************************************************************************/

#ifndef KEYPAD_INTERFACE_H
#define KEYPAD_INTERFACE_H

/* NOTE:
 * 		Don't forget to configure the pins needed in DIO_config.h
 */

/********************************				MACROs				********************************/
#define COL_CONTROL				0
#define ROW_CONTROL				1

/********************************				Function Prototypes				********************************/
/* @brief		shall get the value of the key which is pressed one time in keypad
* @paramin		none
* @paramout		none
* @retval		the value of the key which is pressed
* @note			long pressing counts as one time pressing
*/
u8 KEYPAD_u8GetPressedKey (void);

#endif 
