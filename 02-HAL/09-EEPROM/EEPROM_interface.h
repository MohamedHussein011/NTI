/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: EEPROM_interface.h	            ************************/
/***************************************************************************************/

#ifndef EEPROM_INTERFACE_H
#define EEPROM_INTERFACE_H

/* NOTE:
 * 		EEPROM - ATMEL AT24C01 / AT24C02 / AT24C04 / AT24C08 / AT24C16
 *			Addressed range for AT24C01: (128 Bytes) (8 EEPROMs on the Bus) (Device Address: 0->7, Data Address: 0 -> 127)
 *			Addressed range for AT24C02: (256 Bytes) (8 EEPROMs on the Bus) (Device Address: 0->7, Data Address: 0 -> 255)
 *			Addressed range for AT24C04: (512 Bytes) (4 EEPROMs on the Bus) (Device Address: 0->3, Data Address: 0 -> 511)
 *			Addressed range for AT24C08: (1024 Bytes) (2 EEPROMs on the Bus) (Device Address: 0->1, Data Address: 0 -> 1023)
 *			Addressed range for AT24C16: (2048 Bytes) (1 EEPROMs on the Bus) (Device Address: 0, Data Address: 0 -> 2047)
 */

/*********************************		Error classification	******************************/
//APIs called with NULL pointer
#define EEPROM_E_PARAM_POINTER					0x0A

/********************************				Function Prototypes				********************************/
/* @brief		shall send one byte up to 8 bytes to EEPROM
* @paramin		copy_u8DeviceAddress / device address for EEPROM -
*               copy_u16Address / address location of byte in EEPROM -
* 				copy_pu8Data / pointer holding the data to be sent -
* 				copy_u8Size / size of the data
* @paramout		none
* @retval		error of wrong paramin
*/
u8 EEPROM_u8SendData (u8 copy_u8DeviceAddress, u16 copy_u16DataAddress, u8* copy_pu8Data, u8 copy_u8Size);

/* @brief		shall receive one byte up to 8 bytes to EEPROM
* @paramin		copy_u8DeviceAddress / device address for EEPROM -
* 				copy_u16Address / address location of byte in EEPROM -
* 				copy_u8Size / size of the data
* @paramout		copy_pu8Data / pointer holding the data to be received
* @retval		error of wrong paramin
*/
u8 EEPROM_u8ReceiveData (u8 copy_u8DeviceAddress, u16 copy_u16DataAddress, u8* copy_pu8Data, u8 copy_u8Size);



#endif 
