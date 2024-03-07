/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: Std_Types.h                    ************************/
/***************************************************************************************/

#ifndef STD_TYPES_H
#define STD_TYPES_H

#include "Platform_Types.h"
#include "Compiler.h"

//Vendor ID (vendorId) according to the AUTOSAR vendor list.
#define STD_TYPES_VENDOR_ID							100U

//Module ID of this module
#define STD_TYPES_MODULE_ID							197U

/*AUTOSAR Module version 4.4.0*/
#define STD_TYPES_AR_RELEASE_MAJOR_VERSION				4U
#define STD_TYPES_AR_RELEASE_MINOR_VERSION				4U
#define STD_TYPES_AR_RELEASE_REVISION_VERSION			0U

/*Module version 1.0.0*/
#define STD_TYPES_SW_MAJOR_VERSION						1U
#define STD_TYPES_SW_MINOR_VERSION						0U
#define STD_TYPES_SW_PATCH_VERSION						0U

/* AUTOSAR checking between Std Types and Platform Types Modules */
#if   ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PLATFORM_AR_RELEASE_MAJOR_VERSION) \
	|| (STD_TYPES_AR_RELEASE_MINOR_VERSION != PLATFORM_AR_RELEASE_MINOR_VERSION) \
	|| (STD_TYPES_AR_RELEASE_REVISION_VERSION != PLATFORM_AR_RELEASE_REVISION_VERSION))

#error ("The AR Version of PlatformTypes.h doesn't match the expected version")
#endif

/* AUTOSAR checking between Std Types and Compiler Modules */
#if   ((STD_TYPES_AR_RELEASE_MAJOR_VERSION    != COMPILER_AR_RELEASE_MAJOR_VERSION) \
	|| (STD_TYPES_AR_RELEASE_MINOR_VERSION    != COMPILER_AR_RELEASE_MINOR_VERSION) \
	|| (STD_TYPES_AR_RELEASE_REVISION_VERSION != COMPILER_AR_RELEASE_REVISION_VERSION))

#error ("The AR Version of Compiler.h doesn't match the expected version")
#endif

/*This type can be used as standard API return type which is shared between the RTE and the BSW
 * modules.
 */
typedef uint8 Std_ReturnType;

/* shall be used to request the version of a BSW module using the
 * <Module name>_GetVersionInfo() function
 */
typedef struct
{
	uint16 vendorID;
	uint16 moduleID;
	uint8 sw_major_version;
	uint8 sw_minor_version;
	uint8 sw_patch_version;
}Std_VersionInfoType;

/* Because E_OK is already defined within OSEK, the symbol E_OK has to be shared. To avoid
 *name clashes and redefinition problems, the symbols have to be defined in the following way
 */
 
#ifndef STATUSTYPEDEFINED
#define STATUSTYPEDEFINED

#define E_OK					((Std_ReturnType)0x00U)				/*Success*/

typedef uint8 StatusType; 					/* OSEK compliance */
#endif

#define E_NOT_OK				((Std_ReturnType)0x01U)				/*Failure*/

#define STD_LOW						0x00u				/* Physical state 0V */
#define STD_HIGH					0x01u				/* Physical state 5V or 3.3V */

#define STD_IDLE					0x00u				/* Logical state idle*/
#define STD_ACTIVE					0x01u				/* Logical state active*/

#define STD_OFF					0x00u				/*Standard Off*/
#define STD_ON					0x01u				/*Standard On*/

#define NULL_PTR				((VoidPtr) 0)

#endif
