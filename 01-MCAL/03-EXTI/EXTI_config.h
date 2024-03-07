/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: EXTI_config.h	                ************************/
/***************************************************************************************/

#ifndef EXTI_CONFIG_H
#define EXTI_CONFIG_H

			/***************					INT0							******************/
//external interrupt sense control
#define EXTERNAL_INT0_SOURCE						FALLING_EDGE
//enable or disable external interrupt
#define EXTERNAL_INT0_EN							EXTI_ENABLE

			/***************					INT1							******************/
//external interrupt sense control
#define EXTERNAL_INT1_SOURCE						LOW_LEVEL
//enable or disable external interrupt
#define EXTERNAL_INT1_EN							EXTI_DISABLE

			/***************					INT2							******************/
//external interrupt sense control
#define EXTERNAL_INT2_SOURCE						FALLING_EDGE
//enable or disable external interrupt
#define EXTERNAL_INT2_EN							EXTI_DISABLE

#endif
