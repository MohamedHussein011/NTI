/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: SSEG_interface.h	            ************************/
/***************************************************************************************/

#ifndef SSEG_INTERFACE_H
#define SSEG_INTERFACE_H

			/********************		 ERRORS 	   **********************/
#define SSEG_E_PARAM_INVALID_NUMBER				0x0A
#define SSEG_E_PARAM_POINTER					0x0B
#define SSEG_E_PARAM_INVALID_PORT_PIN			0x0C
#define SSEG_E_PARAM_INVALID_TYPE				0x0D

//type of 7 segment
#define ANODE		0
#define CATHODE		1

//used 7 segment
#define	SSEG_8BITS			0		//ordinary 7 segment
#define SSEG_4BITS_BCD		1		//4 bits input to BCD

			/**********************			APIs		**********************/
void SSEG_voidInit();
u8 SSEG_u8WriteNumber (u8 copy_u8number);

//copy_pu8Ports is an array of 8 elements representing every port number of the seven segment or BCD
//copy_pu8Pins is an array of 8 elements representing every pin number of the seven segment or BCD
u8 SSEG_u8Init (u8* copy_pu8Ports, u8* copy_pu8Pins, u8 copy_u8SSEG);
u8 SSEG_u8WriteNumber8Bit (u8* copy_pu8Ports, u8* copy_pu8Pins, u8 copy_u8Type, u8 copy_u8number);


//copy_pu8Ports is an array of 8 elements representing every port number of the BCD connected to seven segment
//copy_pu8Pins is an array of 8 elements representing every pin number of the BCD connected to seven segment
u8 SSEG_u8WriteNumber4BitBCD (u8* copy_pu8Ports, u8* copy_pu8Pins, u8 copy_u8Type, u8 copy_u8number);

//pass COM port & pin number to turn it off
u8 SSEG_u8OFF (u8 copy_u8ComPort, u8 copy_u8ComPin, u8 copy_u8Type);

#endif 
