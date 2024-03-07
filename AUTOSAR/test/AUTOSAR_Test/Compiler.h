/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: Compiler.h                    ************************/
/***************************************************************************************/

#ifndef COMPILER_H
#define COMPILER_H

//Vendor ID (vendorId) according to the AUTOSAR vendor list.
#define COMPILER_VENDOR_ID							100U

//Module ID of this module
#define COMPILER_MODULE_ID							198U

/*AUTOSAR Module version 4.4.0*/
#define COMPILER_AR_RELEASE_MAJOR_VERSION				4U
#define COMPILER_AR_RELEASE_MINOR_VERSION				4U
#define COMPILER_AR_RELEASE_REVISION_VERSION			0U

/*Module version 1.0.0*/
#define COMPILER_SW_MAJOR_VERSION						1U
#define COMPILER_SW_MINOR_VERSION						0U
#define COMPILER_SW_PATCH_VERSION						0U


//The memory class AUTOMATIC shall be provided as empty definition, used for the declaration of local pointers.
#define AUTOMATIC

/*The memory class TYPEDEF shall be provided as empty definition. This memory class shall be used within type definitions
 *, where no memory qualifier can be specified.
 */
#define TYPEDEF

//The compiler abstraction shall provide the NULL_PTR define with a void pointer to zero definition.
#define NULL_PTR 		((void*) 0)

//The compiler abstraction shall provide the INLINE define for abstraction of the keyword inline.
#define INLINE			inline

//The compiler abstraction shall provide the LOCAL_INLINE define for abstraction of the keyword inline in functions with “static” scope.
#define LOCAL_INLINE				static inline

#endif
