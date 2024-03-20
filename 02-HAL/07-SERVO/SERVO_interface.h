/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: SERVO_interface.h	            ************************/
/***************************************************************************************/

#ifndef SERVO_INTERFACE_H
#define SERVO_INTERFACE_H

/* NOTE:
 * 		Don't forget to configure the pins needed in DIO_config.h
 */

/*********************************		Error classification	******************************/
#define SERVO_E_PARAM_ANGLE_ID					0x0A

/********************************				Function Prototypes				********************************/
/* @brief		shall Rotate the DC Motor clockwise
* @paramin		copy_u8Port0, copy_u8Port1 / port number connected to DC motor -
*				copy_u8Pin0, copy_u8Pin1 / pin number connected to DC motor
* @paramout		none
* @retval		error of wrong paramin
*/
u8 SERVO_u8SetAngle (u8 copy_u8Angle);

/* @brief		shall stop the PWM input to the servo
* @paramin		none
* @paramout		none
* @retval		none
*/
void SERVO_voidStop (void);

#endif 
