/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: Dio_Regs.h	                    ************************/
/***************************************************************************************/

#ifndef DIO_REGS_H
#define DIO_REGS_H

#include "Std_Types.h"

/*AUTOSAR Module version 4.4.0*/
#define DIO_REGS_AR_RELEASE_MAJOR_VERSION					4U
#define DIO_REGS_AR_RELEASE_MINOR_VERSION					4U
#define DIO_REGS_AR_RELEASE_REVISION_VERSION				0U

/*Module version 1.0.0*/
#define DIO_REGS_SW_MAJOR_VERSION						1U
#define DIO_REGS_SW_MINOR_VERSION						0U
#define DIO_REGS_SW_PATCH_VERSION						0U

/* AUTOSAR checking between Std Types and Dio Modules */
#if   ((DIO_REGS_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION) \
	|| (DIO_REGS_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION) \
	|| (DIO_REGS_AR_RELEASE_REVISION_VERSION != STD_TYPES_AR_RELEASE_REVISION_VERSION))

#error ("The AR Version of StdTypes.h doesn't match the expected version")
#endif


/***********************					registers								************************/
typedef struct
{
	const volatile uint8 PIN;
	volatile uint8 DDR;
	volatile uint8 PORT;
}REGS_st;

#define DIO_PORTA 				((volatile REGS_st*) 0x39)
#define DIO_PORTB 				((volatile REGS_st*) 0x36)
#define DIO_PORTC 				((volatile REGS_st*) 0x33)
#define DIO_PORTD 				((volatile REGS_st*) 0x30)


#endif
