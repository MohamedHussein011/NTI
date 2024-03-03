/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: EXTI_config.h	                ************************/
/***************************************************************************************/

#ifndef EXTI_CONFIG_H
#define EXTI_CONFIG_H

			/***************					INT0							******************/
#define EXTERNAL_INT0_SOURCE						LOW_LEVEL
#if (EXTERNAL_INT0_SOURCE < LOW_LEVEL || EXTERNAL_INT0_SOURCE > RISING_EDGE)
#error "Wrong INT0 source"
#endif

#define EXTERNAL_INT0_EN							EXTI_DISABLE
#if (EXTERNAL_INT0_EN < EXTI_ENABLE || EXTERNAL_INT0_EN > EXTI_DISABLE)
#error "Wrong INT0 source"
#endif

			/***************					INT1							******************/
#define EXTERNAL_INT1_SOURCE						LOW_LEVEL
#if (EXTERNAL_INT1_SOURCE < LOW_LEVEL || EXTERNAL_INT1_SOURCE > RISING_EDGE)
#error "Wrong INT1 source"
#endif

#define EXTERNAL_INT1_EN							EXTI_DISABLE
#if (EXTERNAL_INT1_EN < EXTI_ENABLE || EXTERNAL_INT1_EN > EXTI_DISABLE)
#error "Wrong INT1 source"
#endif

			/***************					INT2							******************/
#define EXTERNAL_INT2_SOURCE						FALLING_EDGE
#if (EXTERNAL_INT2_SOURCE < FALLING_EDGE || EXTERNAL_INT2_SOURCE > RISING_EDGE)
#error "Wrong INT1 source"
#endif

#define EXTERNAL_INT2_EN							EXTI_DISABLE
#if (EXTERNAL_INT2_EN < EXTI_ENABLE || EXTERNAL_INT2_EN > EXTI_DISABLE)
#error "Wrong INT2 source"
#endif

#endif
