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
//API called with out of range angle
#define SERVO_E_PARAM_ANGLE_ID					0x0A

/********************************				Function Prototypes				********************************/
/* @brief		shall rotate the servo motor to a specified angle
* @paramin		copy_u8TimerChannel / TIMER1 channel A or B -
* 				copy_u8Angle / angle to be set to servo
* @paramout		none
* @retval		error of wrong paramin
*/
u8 SERVO_u8SetAngle (u8 copy_u8TimerChannel, u8 copy_u8Angle);

/* @brief		shall stop the PWM input to the servo
* @paramin		none
* @paramout		none
* @retval		none
*/
void SERVO_voidStop (void);

#endif 
