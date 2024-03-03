/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: EXTI_interface.h	            ************************/
/***************************************************************************************/


#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

                             /*************** ERRORS ***************/
#define EXTI_E_PARAM_INVALID_INT_ID						0x0A
#define EXTI_E_PARAM_INVALID_INT_CONTROL_ID				0x0B
#define EXTI_E_PARAM_INVALID_INT2_CONTROL_ID			0x0C

/******************************************************************************
* !comment : Select Interrupt Sense Control option:  		 	               *
*           1: LOW_LEVEL                                                     *
*           2: ON_CHANGE                                                     *
            3: FALLING_EDGE                                                     *
            4: RISING_EDGE                                         			*
******************************************************************************/
#define LOW_LEVEL        1
#define ON_CHANGE        2
#define FALLING_EDGE     3
#define RISING_EDGE      4

/******************************************************************************
* !comment : Select External Interrupts sources option:  		 	               *
*           1: INT0                                                     *
*           2: INT1                                                     *
            3: INT2                                                     *
******************************************************************************/

#define EXT_INT0        1
#define EXT_INT1        2
#define EXT_INT2        3

//Enable or disable
#define EXTI_ENABLE					0
#define EXTI_DISABLE				1


			/******************				APIs					*****************/
void EXTI_voidINT0 (void);
void EXTI_voidINT1 (void);
void EXTI_voidINT2 (void);

u8 EXTI_u8EnableInterrupt (u8 copy_u8InterruptSource, u8 copy_u8SenseControl);
u8 EXTI_u8DisableInterrupt (u8 copy_u8InterruptSource);

#endif 
