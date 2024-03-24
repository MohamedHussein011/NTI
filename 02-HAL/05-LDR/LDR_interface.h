/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: LDR_interface.h	            ************************/
/***************************************************************************************/

#ifndef LDR_INTERFACE_H
#define LDR_INTERFACE_H

/* NOTE:
 * 		Don't forget to configure the pins needed in DIO_config.h
 */

/*********************************		Error classification	******************************/
#define LDR_E_PARAM_POINTER					0x0A

/********************************				Function Prototypes				********************************/
/* @brief		shall get the value of the LDR
* @paramin		copy_u16AdcResult / ADC conversion result
* @paramout		copy_pu32Value / LDR value
* @retval		errro of wrong paramin & paramout
*/
u8 LDR_u8GetValue (u32* copy_pu32Value, u16 copy_u16AdcResult);

#endif 
