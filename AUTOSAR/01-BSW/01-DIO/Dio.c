/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: Dio.c  	                    ************************/
/***************************************************************************************/

#include "Dio.h"
#include "Dio_Regs.h"

//if development error detection is enabled, include Det.h
#if DIO_DEV_ERROR_DETECT == STD_ON
#include "Det.h"
/* AUTOSAR checking between Det and Dio Modules */
#if   ((DIO_AR_RELEASE_MAJOR_VERSION    != DET_AR_RELEASE_MAJOR_VERSION) \
		|| (DIO_AR_RELEASE_MINOR_VERSION    != DET_AR_RELEASE_MINOR_VERSION) \
		|| (DIO_AR_RELEASE_REVISION_VERSION != DET_AR_RELEASE_REVISION_VERSION))

#error ("The AR Version of Det.h doesn't match the expected version")
#endif
#endif

/* AUTOSAR checking between Dio_Regs and Dio Modules */
#if   ((DIO_AR_RELEASE_MAJOR_VERSION    != DIO_REGS_AR_RELEASE_MAJOR_VERSION) \
		|| (DIO_AR_RELEASE_MINOR_VERSION    != DIO_REGS_AR_RELEASE_MINOR_VERSION) \
		|| (DIO_AR_RELEASE_REVISION_VERSION != DIO_REGS_AR_RELEASE_REVISION_VERSION))

#error ("The AR Version of Dio_Regs.h doesn't match the expected version")
#endif


/********************************				Function Definitions				
 ********************************/

Dio_LevelType Dio_ReadChannel ( Dio_ChannelType ChannelId )
{
	Dio_LevelType ReturnValue;
#if DIO_DEV_ERROR_DETECT == STD_ON
	if(ChannelId > DIO_CHANNELS)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_READ_CHANNEL,
				DIO_E_PARAM_INVALID_CHANNEL_ID);
	}
	else
	{
		/*	No Error  */
	}
#endif

	if(ChannelId < 8)
	{
		//PORTA
		if((DIO_PORTA->PIN) >> ChannelId && 0x01)
		{
			ReturnValue = STD_HIGH;
		}
		else
			ReturnValue = STD_LOW;
	}
	else if(ChannelId < 16)
	{
		//PORTB
		if((DIO_PORTB->PIN) >> (ChannelId - 8) && 0x01)
		{
			ReturnValue = STD_HIGH;
		}
		else
			ReturnValue = STD_LOW;
	}
	else if(ChannelId < 24)
	{
		//PORTC
		if((DIO_PORTC->PIN) >> (ChannelId - 16) && 0x01)
		{
			ReturnValue = STD_HIGH;
		}
		else
			ReturnValue = STD_LOW;
	}
	else if(ChannelId < DIO_CHANNELS)
	{
		//PORTD
		if((DIO_PORTD->PIN) >> (ChannelId - 24) && 0x01)
		{
			ReturnValue = STD_HIGH;
		}
		else
			ReturnValue = STD_LOW;
	}


	return ReturnValue;

}


void Dio_WriteChannel ( Dio_ChannelType ChannelId, Dio_LevelType Level )
{
#if DIO_DEV_ERROR_DETECT == STD_ON
	if(ChannelId > DIO_CHANNELS)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_WRITE_CHANNEL,
				DIO_E_PARAM_INVALID_CHANNEL_ID);
	}
	else
	{
		/*	No Error  */
	}
#endif

	if(ChannelId < 8)
	{
		//PORTA
		if(Level == STD_HIGH)
		{
			DIO_PORTA->PORT |= (1 << ChannelId);
		}
		else if(Level == STD_LOW)
		{
			DIO_PORTA->PORT &= ~(1 << ChannelId);
		}
	}
	else if(ChannelId < 16)
	{
		//PORTB
		if(Level == STD_HIGH)
		{
			DIO_PORTB->PORT |= (1 << (ChannelId - 8));
		}
		else if(Level == STD_LOW)
		{
			DIO_PORTB->PORT &= ~(1 << (ChannelId - 8));
		}
	}
	else if(ChannelId < 24)
	{
		//PORTC
		if(Level == STD_HIGH)
		{
			DIO_PORTC->PORT |= (1 << (ChannelId - 16));
		}
		else if(Level == STD_LOW)
		{
			DIO_PORTC->PORT &= ~(1 << (ChannelId - 16));
		}
	}
	else if(ChannelId < DIO_CHANNELS)
	{
		//PORTD
		if(Level == STD_HIGH)
		{
			DIO_PORTD->PORT |= (1 << (ChannelId - 24));
		}
		else if(Level == STD_LOW)
		{
			DIO_PORTD->PORT &= ~(1 << (ChannelId - 24));
		}
	}
}


Dio_PortLevelType Dio_ReadPort ( Dio_PortType PortId )
{
	Dio_LevelType ReturnValue;
#if DIO_DEV_ERROR_DETECT == STD_ON
	if(PortId > DIO_PORTS)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_READ_PORT,
				DIO_E_PARAM_INVALID_PORT_ID);
	}
	else
	{
		/*	No Error  */
	}
#endif

	if(PortId == 0)
	{
		//PORTA
		ReturnValue = DIO_PORTA->PORT;
	}
	else if(PortId == 1)
	{
		//PORTB
		ReturnValue = DIO_PORTB->PORT;
	}
	else if(PortId == 2)
	{
		//PORTC
		ReturnValue = DIO_PORTC->PORT;
	}
	else if(PortId == 3)
	{
		//PORTD
		ReturnValue = DIO_PORTD->PORT;
	}


	return ReturnValue;
}


void Dio_WritePort ( Dio_PortType PortId, Dio_PortLevelType Level )
{
#if DIO_DEV_ERROR_DETECT == STD_ON
	if(PortId > DIO_PORTS)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_WRITE_PORT,
				DIO_E_PARAM_INVALID_PORT_ID);
	}
	else
	{
		/*	No Error  */
	}
#endif

	if(PortId == 0)
	{
		//PORTA
		DIO_PORTA->PORT = Level;
	}
	else if(PortId == 1)
	{
		//PORTB
		DIO_PORTB->PORT = Level;
	}
	else if(PortId == 2)
	{
		//PORTC
		DIO_PORTC->PORT = Level;
	}
	else if(PortId == 3)
	{
		//PORTD
		DIO_PORTD->PORT = Level;
	}
}


Dio_PortLevelType Dio_ReadChannelGroup ( const Dio_ChannelGroupType* ChannelGroupIdPtr )
{
	Dio_PortLevelType ReturnValue;

#if DIO_DEV_ERROR_DETECT == STD_ON
	if(ChannelGroupIdPtr == NULL_PTR)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_READ_CHANNEL_GROUP,
				DIO_E_PARAM_POINTER);
	}
	else
	{
		/*	No Error  */
	}

	if(ChannelGroupIdPtr->port > DIO_PORTS)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_READ_CHANNEL_GROUP,
				DIO_E_PARAM_INVALID_PORT_ID);
	}
	else
	{
		/*	No Error  */
	}
#endif

	if(ChannelGroupIdPtr->port == 0)
	{
		//PORTA
		ReturnValue = ((DIO_PORTA->PIN) >> ChannelGroupIdPtr->offset ) & (ChannelGroupIdPtr ->mask >> ChannelGroupIdPtr->offset);
	}
	else if(ChannelGroupIdPtr->port == 1)
	{
		//PORTB
		ReturnValue = ((DIO_PORTB->PIN) >> ChannelGroupIdPtr->offset ) & (ChannelGroupIdPtr ->mask >> ChannelGroupIdPtr->offset);
	}
	else if(ChannelGroupIdPtr->port == 2)
	{
		//PORTC
		ReturnValue = ((DIO_PORTC->PIN) >> ChannelGroupIdPtr->offset ) & (ChannelGroupIdPtr ->mask >> ChannelGroupIdPtr->offset);
	}
	else if(ChannelGroupIdPtr->port == 3)
	{
		//PORTD
		ReturnValue = ((DIO_PORTD->PIN) >> ChannelGroupIdPtr->offset ) & (ChannelGroupIdPtr ->mask >> ChannelGroupIdPtr->offset);
	}

	return ReturnValue;
}


void Dio_WriteChannelGroup ( const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level)
{
#if DIO_DEV_ERROR_DETECT == STD_ON
	if(ChannelGroupIdPtr == NULL_PTR)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_WRITE_CHANNEL_GROUP,
				DIO_E_PARAM_POINTER);
	}
	else
	{
		/*	No Error  */
	}

	if(ChannelGroupIdPtr->port > DIO_PORTS)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_WRITE_CHANNEL_GROUP,
				DIO_E_PARAM_INVALID_PORT_ID);
	}
	else
	{
		/*	No Error  */
	}
#endif

	if(ChannelGroupIdPtr->port == 0)
	{
		//PORTA
		DIO_PORTA->PORT |= ((Level << ChannelGroupIdPtr->offset) & ChannelGroupIdPtr ->mask);
	}
	else if(ChannelGroupIdPtr->port == 1)
	{
		//PORTB
		DIO_PORTB->PORT |= ((Level << ChannelGroupIdPtr->offset) & ChannelGroupIdPtr ->mask);
	}
	else if(ChannelGroupIdPtr->port == 2)
	{
		//PORTC
		DIO_PORTC->PORT |= ((Level << ChannelGroupIdPtr->offset) & ChannelGroupIdPtr ->mask);
	}
	else if(ChannelGroupIdPtr->port == 3)
	{
		//PORTD
		DIO_PORTD->PORT |= ((Level << ChannelGroupIdPtr->offset) & ChannelGroupIdPtr ->mask);
	}

}

#if DIO_VERSION_INFO_API == STD_ON
void Dio_GetVersionInfo ( Std_VersionInfoType* VersionInfo )
{
#if DIO_DEV_ERROR_DETECT == STD_ON
	if(VersionInfo == NULL_PTR)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_GET_VERSION_INFO,
				DIO_E_PARAM_POINTER);
	}
	else
	{
		/*	No Error  */
	}
#endif
	VersionInfo->moduleID = DIO_MODULE_ID;
	VersionInfo->sw_major_version = DIO_SW_MAJOR_VERSION;
	VersionInfo->sw_minor_version = DIO_SW_MINOR_VERSION;
	VersionInfo->sw_patch_version = DIO_SW_PATCH_VERSION;
	VersionInfo->vendorID = DIO_VENDOR_ID;

}
#endif


#if DIO_FLIP_CHANNEL_API == STD_ON
Dio_LevelType Dio_FlipChannel ( Dio_ChannelType ChannelId )
{
	Dio_LevelType ReturnValue;
#if DIO_DEV_ERROR_DETECT == STD_ON
	if(ChannelId > DIO_CHANNELS)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_FLIP_CHANNEL,
				DIO_E_PARAM_INVALID_CHANNEL_ID);
	}
	else
	{
		/*	No Error  */
	}
#endif

	if(ChannelId < 8)
	{
		//PORTA
		DIO_PORTA->PORT ^= (1 << ChannelId);
	}
	else if(ChannelId < 16)
	{
		//PORTB
		DIO_PORTB->PORT ^= (1 << (ChannelId - 8));
	}
	else if(ChannelId < 24)
	{
		//PORTC
		DIO_PORTC->PORT ^= (1 << (ChannelId - 16));
	}
	else if(ChannelId < DIO_CHANNELS)
	{
		//PORTD
		DIO_PORTD->PORT ^= (1 << (ChannelId - 24));
	}

	ReturnValue = Dio_ReadChannel(ChannelId);

	return ReturnValue;
}
#endif


#if DIO_MASKSED_WRITE_PORT_API == STD_ON
void Dio_MaskedWritePort ( Dio_PortType PortId, Dio_PortLevelType Level, Dio_PortLevelType Mask )
{
	uint8 i=0;
#if DIO_DEV_ERROR_DETECT == STD_ON
	if(PortId > DIO_PORTS)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_MASKED_WRITE_PORT,
				DIO_E_PARAM_INVALID_PORT_ID);
	}
	else
	{
		/*	No Error  */
	}
#endif

	if(PortId == 0)
	{
		//PORTA
		while(i < 8 && (((Mask >> i) & 0x01) == 0))
		{
			i++;
		}

		if(i < 8)
		{
			DIO_PORTA->PORT |= ((Level << i) & Mask);
		}
		else
		{

		}

	}
	else if(PortId == 1)
	{
		//PORTB
		while(i < 8 && (((Mask >> i) & 0x01) == 0))
		{
			i++;
		}

		if(i < 8)
		{
			DIO_PORTB->PORT |= ((Level << i) & Mask);
		}
		else
		{

		}
	}
	else if(PortId == 2)
	{
		//PORTC
		while(i < 8 && (((Mask >> i) & 0x01) == 0))
		{
			i++;
		}

		if(i < 8)
		{
			DIO_PORTC->PORT |= ((Level << i) & Mask);
		}
		else
		{

		}
	}
	else if(PortId == 3)
	{
		//PORTD
		while(i < 8 && (((Mask >> i) & 0x01) == 0))
		{
			i++;
		}

		if(i < 8)
		{
			DIO_PORTD->PORT |= ((Level << i) & Mask);
		}
		else
		{

		}
	}
}
#endif




