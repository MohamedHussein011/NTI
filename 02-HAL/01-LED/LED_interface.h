/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: LED_interface.h	            ************************/
/***************************************************************************************/

#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

                             /*************** ERRORS ***************/
#define LED_E_PARAM_INVALID_PIN_ID			0x0A
#define LED_E_PARAM_INVALID_PORT_ID			0x0B


/* NOTE:
 * 		Don't forget to configure the pins needed as output in DIO_config.h
 */

/********************************				Function Prototypes				********************************/
/* @brief		shall on the led required
* @paramin		copy_u8Port / PORT - copy_u8Pin / PIN
* @paramout		none
* @retval		Error of wrong paramin
*/
u8 LED_u8On (u8 copy_u8Port, u8 copy_u8Pin);

/* @brief		shall off the led required
* @paramin		copy_u8Port / PORT - copy_u8Pin / PIN
* @paramout		none
* @retval		Error of wrong paramin
*/
u8 LED_u8Off (u8 copy_u8Port, u8 copy_u8Pin);

/* @brief		shall toggle the led required
* @paramin		copy_u8Port / PORT - copy_u8Pin / PIN
* @paramout		none
* @retval		Error of wrong paramin
*/
u8 LED_u8Tog (u8 copy_u8Port, u8 copy_u8Pin);

#endif 
