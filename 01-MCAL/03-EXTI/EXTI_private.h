/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: EXTI_private.h	                ************************/
/***************************************************************************************/

#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

			/****************			Registers					****************/
//MCU Control Register
#define MCUCR				(*((volatile u8*)0x55))
#define ISC11       	   	 3            /* Interrupt Sense Control 1 Bit 1  */
#define ISC10      			 2            /* Interrupt Sense Control 1 Bit 0  */
#define ISC01      			 1            /* Interrupt Sense Control 0 Bit 1  */
#define ISC00      			 0            /* Interrupt Sense Control 0 Bit 0  */

//MCU Control and Status Register
#define MCUCSR				(*((volatile u8*)0x54))
#define ISC2        		6             /* Interrupt Sense Control 2  */

//General Interrupt Control Register
#define GICR				(*((volatile u8*)0x5B))
#define INT1            	7          /*External Interrupt Request 1 Enable*/
#define INT0             	6          /*External Interrupt Request 0 Enable*/
#define INT2             	5          /*External Interrupt Request 2 Enable*/

//General Interrupt Flag Register
#define GIFR				(*((volatile u8*)0x5A))
#define INTF1             	7          /*External Interrupt Flag 1 */
#define INTF0             	6          /*External Interrupt Flag 0 */
#define INTF2             	5          /*External Interrupt Flag 2 */

#endif
