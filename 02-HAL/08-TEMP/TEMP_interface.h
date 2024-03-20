/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: TEMP_interface.h	            ************************/
/***************************************************************************************/

#ifndef TEMP_INTERFACE_H
#define TEMP_INTERFACE_H

/* NOTE:
 * 		1)	LM35, temperautre sensor
 * 		2)	Don't forget to configure the pins needed in DIO_config.h
 */

/*********************************		Error classification	******************************/
//APIs called with NULL pointer
#define TEMP_E_PARAM_POINTER					0x0A

/********************************				Function Prototypes				********************************/
/* @brief		shall Rotate the DC Motor clockwise
* @paramin		copy_u16AdcResult / ADC conversion result -
* @paramout		copy_pu8Degree / temp degree related to the ADC conversion result
* @retval		error of wrong paramin
*/
u8 TEMP_u8GetTempDegree (u16 copy_u16AdcResult, u8* copy_pu8Degree);

#endif 
