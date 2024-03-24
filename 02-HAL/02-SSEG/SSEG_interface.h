/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: SSEG_interface.h	            ************************/
/***************************************************************************************/

#ifndef SSEG_INTERFACE_H
#define SSEG_INTERFACE_H

/*********************************		Error classification	******************************/
#define SSEG_E_PARAM_INVALID_NUMBER				0x0A
#define SSEG_E_PARAM_POINTER					0x0B
#define SSEG_E_PARAM_INVALID_PORT_PIN			0x0C
#define SSEG_E_PARAM_INVALID_TYPE				0x0D

//type of 7 segment
#define ANODE		0
#define CATHODE		1

//used 7 segment
#define	SSEG_8BITS			0		//ordinary 7 pins segment
#define SSEG_4BITS_BCD		1		//4 bits input to BCD

/* NOTE:
 * 		Don't forget to configure the pins needed as output in DIO_config.h
 */

/********************************				Function Prototypes				********************************/
/* @brief		shall display the number needed in the seven segment
 * 				(ordinary 8 pins or 5 pins using BCD) with pins used in SSEG_config.h
* @paramin		copy_u8number / number needed in the seven segment
* @paramout		none
* @retval		Error of wrong paramin
*/
u8 SSEG_u8WriteNum (u8 copy_u8number);

//copy_pu8Ports is an array of 8 elements representing every port number of the seven segment or BCD
//copy_pu8Pins is an array of 8 elements representing every pin number of the seven segment or BCD
u8 SSEG_u8WriteNumber (u8* copy_pu8Ports, u8* copy_pu8Pins, u8 copy_u8Type, u8 copy_u8number);

//pass COM port & pin number to turn it off
u8 SSEG_u8OFF (u8 copy_u8ComPort, u8 copy_u8ComPin, u8 copy_u8Type);

#endif 
