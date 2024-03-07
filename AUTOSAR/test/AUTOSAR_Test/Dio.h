/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: Dio.h		                    ************************/
/***************************************************************************************/

#ifndef DIO_H
#define DIO_H

#include "Std_Types.h"
#include "Dio_Cfg.h"
	
//Vendor ID (vendorId) according to the AUTOSAR vendor list.
#define DIO_VENDOR_ID							100U

//Module ID of this module
#define DIO_MODULE_ID							120U

/* Instance Id */
#define DIO_INSTANCE_ID               			0U

/*AUTOSAR Module version 4.4.0*/
#define DIO_AR_RELEASE_MAJOR_VERSION				4U
#define DIO_AR_RELEASE_MINOR_VERSION				4U
#define DIO_AR_RELEASE_REVISION_VERSION				0U

/*Module version 1.0.0*/
#define DIO_SW_MAJOR_VERSION						1U
#define DIO_SW_MINOR_VERSION						0U
#define DIO_SW_PATCH_VERSION						0U

/* AUTOSAR checking between Std Types and Dio Modules */
#if   ((DIO_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION) \
	|| (DIO_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION) \
	|| (DIO_AR_RELEASE_REVISION_VERSION != STD_TYPES_AR_RELEASE_REVISION_VERSION))

#error ("The AR Version of StdTypes.h doesn't match the expected version")
#endif

/* AUTOSAR checking between Dio_Cfg and Dio Modules */
#if   ((DIO_AR_RELEASE_MAJOR_VERSION    != DIO_CFG_AR_RELEASE_MAJOR_VERSION) \
	|| (DIO_AR_RELEASE_MINOR_VERSION    != DIO_CFG_AR_RELEASE_MINOR_VERSION) \
	|| (DIO_AR_RELEASE_REVISION_VERSION != DIO_CFG_AR_RELEASE_REVISION_VERSION))

#error ("The AR Version of Dio_Cfg.h doesn't match the expected version")
#endif

/**********************						APIs ID							**********************/
#define DIO_READ_CHANNEL					0x00
#define DIO_WRITE_CHANNEL					0x01
#define DIO_READ_PORT						0x02
#define DIO_WRITE_PORT						0x03
#define DIO_READ_CHANNEL_GROUP	     		0x04
#define DIO_WRITE_CHANNEL_GROUP				0x05
#define DIO_GET_VERSION_INFO				0x12
#define DIO_FLIP_CHANNEL					0x11
#define DIO_MASKED_WRITE_PORT				0x13


/*********************************		Error classification	******************************/
//Invalid channel requested
#define DIO_E_PARAM_INVALID_CHANNEL_ID					0x0A
//Invalid port requested
#define DIO_E_PARAM_INVALID_PORT_ID						0x14
//Invalid channel group requested
#define DIO_E_PARAM_INVALID_GROUP						0x1F
//API service called with a NULL pointer
#define DIO_E_PARAM_POINTER								0x20

//Numeric ID of a DIO channel.
typedef uint8 Dio_ChannelType;

//Numeric ID of a DIO port.
typedef uint8 Dio_PortType;

//Type for the definition of a channel group, which consists of several adjoining channels within a port.
typedef struct
{
	uint8 mask;			//This element mask which defines the positions of the channel group.
	uint8 offset;		//This element shall be the position of the Channel Group on the port, counted from the LSB.
	Dio_PortType port;	//This shall be the port on which the Channel group is defined.
}Dio_ChannelGroupType;

/*These are the possible levels a DIO channel can have (input or output)
 * range: STD_HIGH, STD_LOW can be found in Std_Types.h
 */
typedef uint8 Dio_LevelType;	

//If the μC owns ports of different port widths (e.g. 4, 8,16...Bit) Dio_PortLevelType inherits the size of the largest port.
typedef uint8 Dio_PortLevelType;

//Dio Ports
typedef enum
{
	DIO_PORT0 = 0,
	DIO_PORT1,
	DIO_PORT2,
	DIO_PORT3,
}DIO_PORTS_en;

//Dio Channels
typedef enum
{
	DIO_CHANNEL0 = 0,
	DIO_CHANNEL1,
	DIO_CHANNEL2,
	DIO_CHANNEL3,
	DIO_CHANNEL4,
	DIO_CHANNEL5,
	DIO_CHANNEL6,
	DIO_CHANNEL7,
	DIO_CHANNEL8,
	DIO_CHANNEL9,
	DIO_CHANNEL10,
	DIO_CHANNEL11,
	DIO_CHANNEL12,
	DIO_CHANNEL13,
	DIO_CHANNEL14,
	DIO_CHANNEL15,
	DIO_CHANNEL16,
	DIO_CHANNEL17,
	DIO_CHANNEL18,
	DIO_CHANNEL19,
	DIO_CHANNEL20,
	DIO_CHANNEL21,
	DIO_CHANNEL22,
	DIO_CHANNEL23,
	DIO_CHANNEL24,
	DIO_CHANNEL25,
	DIO_CHANNEL26,
	DIO_CHANNEL27,
	DIO_CHANNEL28,
	DIO_CHANNEL29,
	DIO_CHANNEL30,
	DIO_CHANNEL31
}DIO_CHANNELS_en;


//Containers: Dio Config, Dio Port, Dio Channel
typedef struct
{
	Dio_ChannelType DioChannelId;
}Dio_Channel;

typedef struct
{
	Dio_PortType DioPortId;
	Dio_Channel DioChannel;
}Dio_Port;

typedef struct
{
	Dio_Port DioPort;
}Dio_Config;


/********************************				Function Prototypes				********************************/

/* @brief		Returns the value of the specified DIO channel.
* @service_id	0x00
* @Sync/Async 	Synchronous
* @Reentrancy   Reentrant
* @paramin		ChannelId / ID of DIO channel
* @paramout		none
* @retval		Dio_LevelType
*/
Dio_LevelType Dio_ReadChannel ( Dio_ChannelType ChannelId );

/* @brief		Service to set a level of an output channel & if input channel, has no influence on the physical output.
* @service_id	0x01
* @Sync/Async 	Synchronous
* @Reentrancy   Reentrant
* @paramin		ChannelId / ID of DIO channel - Level / Value to be written
* @paramout		none
* @retval		none
*/
void Dio_WriteChannel ( Dio_ChannelType ChannelId, Dio_LevelType Level );

/* @brief		Returns the level of all channels of that port.
* @service_id	0x02
* @Sync/Async 	Synchronous
* @Reentrancy   Reentrant
* @paramin		PortId / ID of DIO Port
* @paramout		none
* @retval		Dio_PortLevelType / Level of all channels of that port
*/
Dio_PortLevelType Dio_ReadPort ( Dio_PortType PortId );

/* @brief		Service to set a value of the port.
* @service_id	0x03
* @Sync/Async 	Synchronous
* @Reentrancy   Reentrant
* @paramin		PortId / ID of DIO Port - Level / Value to be written
* @paramout		none
* @retval		none
*/
void Dio_WritePort ( Dio_PortType PortId, Dio_PortLevelType Level );

/* @brief		This Service reads a subset of the adjoining bits of a port.
* @service_id	0x04
* @Sync/Async 	Synchronous
* @Reentrancy   Reentrant
* @paramin		ChannelGroupIdPtr / Pointer to ChannelGroup
* @paramout		none
* @retval		Dio_PortLevelType / Level of a subset of the adjoining bits of a port
*/
Dio_PortLevelType Dio_ReadChannelGroup ( const Dio_ChannelGroupType* ChannelGroupIdPtr );

/* @brief		Service to set a subset of the adjoining bits of a port to a specified level.
* @service_id	0x05
* @Sync/Async 	Synchronous
* @Reentrancy   Reentrant
* @paramin		ChannelGroupIdPtr / Pointer to ChannelGroup - Level / Value to be written
* @paramout		none
* @retval		none
*/
void Dio_WriteChannelGroup ( const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level );

/* @brief		Service to get the version information of this module.
* @service_id	0x12
* @Sync/Async 	Synchronous
* @Reentrancy   Reentrant
* @paramin		none
* @paramout		VersionInfo / Pointer to where to store the version information of this module.
* @retval		none
*/
#if DIO_VERSION_INFO_API == STD_ON
void Dio_GetVersionInfo ( Std_VersionInfoType* VersionInfo );
#endif

/* @brief		Service to flip (change from 1 to 0 or from 0 to 1) the level of a channel and return the level of the channel after flip.
* @service_id	0x11
* @Sync/Async 	Synchronous
* @Reentrancy   Reentrant
* @paramin		ChannelId / ID of DIO channel
* @paramout		none
* @retval		Dio_LevelType / the level of the channel after flip.
*/
#if DIO_FLIP_CHANNEL_API == STD_ON
Dio_LevelType Dio_FlipChannel ( Dio_ChannelType ChannelId );
#endif

/* @brief		Service to set the value of a given port with required mask.
* @service_id	0x13
* @Sync/Async 	Synchronous
* @Reentrancy   Reentrant
* @paramin		PortId / ID of DIO Port - Level / Value to be written - Mask / Channels to be masked in the port
* @paramout		none
* @retval		none
*/
#if DIO_MASKSED_WRITE_PORT_API == STD_ON
void Dio_MaskedWritePort ( Dio_PortType PortId, Dio_PortLevelType Level, Dio_PortLevelType Mask );
#endif




#endif
