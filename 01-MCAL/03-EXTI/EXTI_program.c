/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: EXTI_program.c		            ************************/
/***************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

/*array of 3 pointers to functions for all interrupt sources*/
static pvFunction_t EXIT_CallBackFunc[3] = {NULL};


void EXTI_voidINT0 (void)
{
#if EXTERNAL_INT0_SOURCE == LOW_LEVEL
	CLR_BIT(MCUCR,ISC00);		CLR_BIT(MCUCR,ISC01);
#elif EXTERNAL_INT0_SOURCE == ON_CHANGE
	SET_BIT(MCUCR,ISC00);		CLR_BIT(MCUCR,ISC01);
#elif EXTERNAL_INT0_SOURCE == FALLING_EDGE
	CLR_BIT(MCUCR,ISC00);		SET_BIT(MCUCR,ISC01);
#elif EXTERNAL_INT0_SOURCE == RISING_EDGE
	SET_BIT(MCUCR,ISC00);		SET_BIT(MCUCR,ISC01);
#else
#error "Wrong INT0 source selection"
#endif

#if EXTERNAL_INT0_EN == EXTI_ENABLE
	SET_BIT(GICR,INT0);
#elif EXTERNAL_INT0_EN == EXTI_DISABLE
	CLR_BIT(GICR,INT0);
#else
#error "Wrong INT0 enable selection"
#endif
}

void EXTI_voidINT1 (void)
{
#if EXTERNAL_INT1_SOURCE == LOW_LEVEL
	CLR_BIT(MCUCR,ISC10);		CLR_BIT(MCUCR,ISC11);
#elif EXTERNAL_INT1_SOURCE == ON_CHANGE
	SET_BIT(MCUCR,ISC10);		CLR_BIT(MCUCR,ISC11);
#elif EXTERNAL_INT1_SOURCE == FALLING_EDGE
	CLR_BIT(MCUCR,ISC10);		SET_BIT(MCUCR,ISC11);
#elif EXTERNAL_INT1_SOURCE == RISING_EDGE
	SET_BIT(MCUCR,ISC10);		SET_BIT(MCUCR,ISC11);
#else
#error "Wrong INT1 source selection"
#endif

#if EXTERNAL_INT1_EN == EXTI_ENABLE
	SET_BIT(GICR,INT1);
#elif EXTERNAL_INT1_EN == EXTI_DISABLE
	CLR_BIT(GICR,INT1);
#else
#error "Wrong INT1 enable selection"
#endif
}

void EXTI_voidINT2 (void)
{
	//disable first before changing ISC2 bit to ensure no interrupt is fired
	CLR_BIT(GICR,INT2);

#if EXTERNAL_INT2_SOURCE == FALLING_EDGE
	CLR_BIT(MCUCSR,ISC2);
#elif EXTERNAL_INT2_SOURCE == RISING_EDGE
	SET_BIT(MCUCSR,ISC2);
#else
#error "Wrong INT2 source selection"
#endif

#if EXTERNAL_INT2_EN == EXTI_ENABLE
	//clear flag first then enable
	SET_BIT(GIFR,INTF2);
	SET_BIT(GICR,INT2);
#elif EXTERNAL_INT2_EN == EXTI_DISABLE
	CLR_BIT(GICR,INT2);
#else
#error "Wrong INT2 enable selection"
#endif
}

u8 EXTI_u8SetSenseControl (u8 copy_u8InterruptSource, u8 copy_u8SenseControl)
{
	u8 Local_u8ErrorState = OK;

	if(copy_u8InterruptSource >= EXT_INT0 && copy_u8InterruptSource <= EXT_INT2)
	{
		if(copy_u8SenseControl >= LOW_LEVEL && copy_u8SenseControl <= RISING_EDGE)
		{
			switch(copy_u8InterruptSource)
			{
			case EXT_INT0:
				switch(copy_u8SenseControl)
				{
				case LOW_LEVEL:		CLR_BIT(MCUCR,ISC00);		CLR_BIT(MCUCR,ISC01);	break;
				case ON_CHANGE:		SET_BIT(MCUCR,ISC00);		CLR_BIT(MCUCR,ISC01);	break;
				case FALLING_EDGE:	CLR_BIT(MCUCR,ISC00);		SET_BIT(MCUCR,ISC01);	break;
				case RISING_EDGE:	SET_BIT(MCUCR,ISC00);		SET_BIT(MCUCR,ISC01);	break;
				}

				break;

				case EXT_INT1:
					switch(copy_u8SenseControl)
					{
					case LOW_LEVEL:		CLR_BIT(MCUCR,ISC10);		CLR_BIT(MCUCR,ISC11);	break;
					case ON_CHANGE:		SET_BIT(MCUCR,ISC10);		CLR_BIT(MCUCR,ISC11);	break;
					case FALLING_EDGE:	CLR_BIT(MCUCR,ISC10);		SET_BIT(MCUCR,ISC11);	break;
					case RISING_EDGE:	SET_BIT(MCUCR,ISC10);		SET_BIT(MCUCR,ISC11);	break;
					}

					break;

					case EXT_INT2:
						if(copy_u8SenseControl == RISING_EDGE || copy_u8SenseControl == FALLING_EDGE)
						{
							//disable first before changing ISC2 bit to ensure no interrupt is fired
							CLR_BIT(GICR,INT2);
							switch(copy_u8SenseControl)
							{
							case FALLING_EDGE:	CLR_BIT(MCUCSR,ISC2);	break;
							case RISING_EDGE:	SET_BIT(MCUCSR,ISC2);	break;
							}
						}
						else
							Local_u8ErrorState = EXTI_E_PARAM_INVALID_INT2_CONTROL_ID;

						break;
			}
		}
		else
			Local_u8ErrorState = EXTI_E_PARAM_INVALID_INT_CONTROL_ID;
	}
	else
		Local_u8ErrorState = EXTI_E_PARAM_INVALID_INT_ID;

	return Local_u8ErrorState;
}


u8 EXTI_u8EnableInterrupt (u8 copy_u8InterruptSource)
{
	u8 Local_u8ErrorState = OK;

	if(copy_u8InterruptSource >= EXT_INT0 && copy_u8InterruptSource <= EXT_INT2)
	{
		switch(copy_u8InterruptSource)
		{
		case EXT_INT0:		SET_BIT(GICR,INT0);		break;

		case EXT_INT1:		SET_BIT(GICR,INT1);		break;

		case EXT_INT2:
			//clear flag first then enable
			SET_BIT(GIFR,INTF2);
			SET_BIT(GICR,INT2);

			break;
		}
	}
	else
		Local_u8ErrorState = EXTI_E_PARAM_INVALID_INT_ID;

	return Local_u8ErrorState;
}

u8 EXTI_u8DisableInterrupt (u8 copy_u8InterruptSource)
{
	u8 Local_u8ErrorState = OK;

	if(copy_u8InterruptSource >= EXT_INT0 && copy_u8InterruptSource <= EXT_INT2)
	{
		switch(copy_u8InterruptSource)
		{
		case EXT_INT0:		CLR_BIT(GICR,INT0);

		break;
		case EXT_INT1:		CLR_BIT(GICR,INT1);

		break;
		case EXT_INT2:		CLR_BIT(GICR,INT2);

		break;
		}
	}
	else
		Local_u8ErrorState = EXTI_E_PARAM_INVALID_INT_ID;

	return Local_u8ErrorState;
}

u8 EXTI_u8CallBack (u8 copy_u8InterruptSource, pvFunction_t copy_pvFunc)
{
	u8 Local_u8ErrorState = OK;

	if(copy_u8InterruptSource >= EXT_INT0 && copy_u8InterruptSource <= EXT_INT2)
	{
		if(copy_pvFunc != NULL)
		{
			EXIT_CallBackFunc[copy_u8InterruptSource] = copy_pvFunc;
		}
		else
			Local_u8ErrorState = EXTI_E_PARAM_POINTER;
	}
	else
		Local_u8ErrorState = EXTI_E_PARAM_INVALID_INT_ID;

	return Local_u8ErrorState;
}

/******************************************************************************
 * !comment  :  ISR Function EXI.  							 			      *
 ******************************************************************************/
//INT0
void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	if(EXIT_CallBackFunc[EXT_INT0] != NULL)
	{
		//clear flag
		SET_BIT(GIFR,INTF0);
		//invoke the function
		EXIT_CallBackFunc[EXT_INT0]();
	}
}

//INT1
void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{
	if(EXIT_CallBackFunc[EXT_INT1] != NULL)
	{
		//clear flag
		SET_BIT(GIFR,INTF1);
		//invoke the function
		EXIT_CallBackFunc[EXT_INT1]();
	}
}

//INT2
void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
	if(EXIT_CallBackFunc[EXT_INT2] != NULL)
	{
		//clear flag
		SET_BIT(GIFR,INTF2);
		//invoke the function
		EXIT_CallBackFunc[EXT_INT2]();
	}
}
