/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: EEPROM_program.c		            ************************/
/***************************************************************************************/
#include "STD_TYPES.h"

#include "TWI_interface.h"

#include "EEPROM_interface.h"


/********************************				Function Definitions				********************************/
u8 EEPROM_u8SendData (u8 copy_u8DeviceAddress, u16 copy_u16DataAddress, u8* copy_pu8Data, u8 copy_u8Size)
{
	u8 Local_u8ErrorStatus = OK, Local_u8Counter = 0;

	if(copy_pu8Data != NULL)
	{
		Local_u8ErrorStatus = TWI_u8SendStartCondition();

		Local_u8ErrorStatus = TWI_u8SendSlaveAddressWrite(0x50 | ((copy_u8DeviceAddress | (copy_u16DataAddress>>8)) & 0x07));

		Local_u8ErrorStatus = TWI_u8MasterSendData((u8)copy_u16DataAddress);

		while(Local_u8Counter < copy_u8Size)
		{
			Local_u8ErrorStatus = TWI_u8MasterSendData(copy_pu8Data[Local_u8Counter]);
			Local_u8Counter++;
		}

		TWI_voidSendStopCondition();
	}
	else
		Local_u8ErrorStatus = EEPROM_E_PARAM_POINTER;

	return Local_u8ErrorStatus;
}

u8 EEPROM_u8ReceiveData (u8 copy_u8DeviceAddress, u16 copy_u16DataAddress, u8* copy_pu8Data, u8 copy_u8Size)
{
	u8 Local_u8ErrorStatus = OK, Local_u8Counter = 0;

	if(copy_pu8Data != NULL)
	{
		Local_u8ErrorStatus = TWI_u8SendStartCondition();

		Local_u8ErrorStatus = TWI_u8SendSlaveAddressWrite(0x50 | ((copy_u8DeviceAddress | (copy_u16DataAddress>>8)) & 0x07));

		Local_u8ErrorStatus = TWI_u8MasterSendData((u8)copy_u16DataAddress);

		Local_u8ErrorStatus = TWI_u8SendRepeatedStartCondition();

		Local_u8ErrorStatus = TWI_u8SendSlaveAddressRead(0x50 | ((copy_u8DeviceAddress | (copy_u16DataAddress>>8)) & 0x07));

		while(Local_u8Counter < copy_u8Size)
		{
			Local_u8ErrorStatus = TWI_u8MasterReceiveData(&copy_pu8Data[Local_u8Counter]);
			Local_u8Counter++;
		}

		TWI_voidSendStopCondition();
	}
	else
		Local_u8ErrorStatus = EEPROM_E_PARAM_POINTER;

	return Local_u8ErrorStatus;
}
