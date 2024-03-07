/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: Dio_Cfg.h	                    ************************/
/***************************************************************************************/

#ifndef DIO_CFG_H
#define DIO_CFG_H

#include "Std_Types.h"

/*AUTOSAR Module version 4.4.0*/
#define DIO_CFG_AR_RELEASE_MAJOR_VERSION				4U
#define DIO_CFG_AR_RELEASE_MINOR_VERSION				4U
#define DIO_CFG_AR_RELEASE_REVISION_VERSION				0U

/*Module version 1.0.0*/
#define DIO_CFG_SW_MAJOR_VERSION						1U
#define DIO_CFG_SW_MINOR_VERSION						0U
#define DIO_CFG_SW_PATCH_VERSION						0U

/* AUTOSAR checking between Std Types and Dio Modules */
#if   ((DIO_CFG_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION) \
	|| (DIO_CFG_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION) \
	|| (DIO_CFG_AR_RELEASE_REVISION_VERSION != STD_TYPES_AR_RELEASE_REVISION_VERSION))

#error ("The AR Version of StdTypes.h doesn't match the expected version")
#endif

//Pre-compile time configuration parameter for enabling development error detection
#define DIO_DEV_ERROR_DETECT							STD_ON

//Pre-compile time configuration parameter for enabling Dio Flip Channel Api
#define DIO_FLIP_CHANNEL_API							STD_ON

//Pre-compile time configuration parameter for enabling Dio Masked Write Port Api
#define DIO_MASKSED_WRITE_PORT_API							STD_ON

//Pre-compile time configuration parameter for enabling Dio Version Info Api
#define DIO_VERSION_INFO_API							STD_ON

//Numbers of Ports in our uC
#define DIO_PORTS						4

//Numbers of Channels in our uC
#define DIO_CHANNELS					32 



#endif