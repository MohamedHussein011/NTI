/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: Det.h		                    ************************/
/***************************************************************************************/

#ifndef DET_H
#define DET_H

#include "Std_Types.h"

//Vendor ID (vendorId) according to the AUTOSAR vendor list.
#define DET_VENDOR_ID							100U

//Module ID of this module
#define DET_MODULE_ID							15U

/*AUTOSAR Module version 4.4.0*/
#define DET_AR_RELEASE_MAJOR_VERSION				4U
#define DET_AR_RELEASE_MINOR_VERSION				4U
#define DET_AR_RELEASE_REVISION_VERSION			    0U

/*Module version 1.0.0*/
#define DET_SW_MAJOR_VERSION						1U
#define DET_SW_MINOR_VERSION						0U
#define DET_SW_PATCH_VERSION						0U

/* AUTOSAR checking between Std Types and Det Modules */
#if   ((DET_AR_RELEASE_MAJOR_VERSION    != STD_TYPES_AR_RELEASE_MAJOR_VERSION) \
	|| (DET_AR_RELEASE_MINOR_VERSION    != STD_TYPES_AR_RELEASE_MINOR_VERSION) \
	|| (DET_AR_RELEASE_REVISION_VERSION != STD_TYPES_AR_RELEASE_REVISION_VERSION))

#error ("The AR Version of StdTypes.h doesn't match the expected version")
#endif

/* @brief		Service to report development errors.
* @service_id	0x01
* @Sync/Async 	Synchronous
* @Reentrancy   Reentrant
* @paramin		ModuleId / Module ID of calling module - InstanceId / The identifier of the index based instance of a module, starting
*				from 0, If the module is a single instance module it shall pass 0 as the InstanceId - 
*				ApiId / ID of API service in which error is detected (defined in SWS of calling module) - 
*				ErrorId / ID of detected development error (defined in SWS of calling module)
* @paramout		none
* @retval		Std_ReturnType / never returns a value, but has a return type for compatibility with
*				services and hooks
*/
Std_ReturnType Det_ReportError (uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId);


#endif
