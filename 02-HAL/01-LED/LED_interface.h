/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: LED_interface.h	            ************************/
/***************************************************************************************/

#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

                             /*************** ERRORS ***************/
#define LED_E_PARAM_INVALID_PIN_ID			0x0A
#define LED_E_PARAM_INVALID_PORT_ID			0x0B


u8 LED_u8ON (u8 copy_u8Port, u8 copy_u8Pin);
u8 LED_u8OFF (u8 copy_u8Port, u8 copy_u8Pin);
u8 LED_u8TOG (u8 copy_u8Port, u8 copy_u8Pin);

#endif 
