/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: DCM_interface.h	            ************************/
/***************************************************************************************/

#ifndef DCM_INTERFACE_H
#define DCM_INTERFACE_H

/* NOTE:
 * 		Don't forget to configure the pins needed in DIO_config.h
 */

/*********************************		Error classification	******************************/
#define DCM_E_PARAM_INVALID_PORT_ID					0x0A
#define DCM_E_PARAM_INVALID_PIN_ID					0x0B

/********************************				Function Prototypes				********************************/
/* @brief		shall Rotate the DC Motor clockwise
* @paramin		copy_u8Port0, copy_u8Port1 / port number connected to DC motor -
*				copy_u8Pin0, copy_u8Pin1 / pin number connected to DC motor
* @paramout		none
* @retval		error of wrong paramin
*/
u8 DCM_u8RotateCW (u8 copy_u8Port0, u8 copy_u8Pin0, u8 copy_u8Port1, u8 copy_u8Pin1);

/* @brief		shall Rotate the DC Motor counter clockwise
* @paramin		copy_u8Port0, copy_u8Port1 / port number connected to DC motor -
*				copy_u8Pin0, copy_u8Pin1 / pin number connected to DC motor
* @paramout		none
* @retval		error of wrong paramin
*/
u8 DCM_u8RotateCCW (u8 copy_u8Port0, u8 copy_u8Pin0, u8 copy_u8Port1, u8 copy_u8Pin1);

#endif 
