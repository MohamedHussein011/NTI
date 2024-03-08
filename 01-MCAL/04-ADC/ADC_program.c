/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: ADC_program.c		            ************************/
/***************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"


/*Global flag to indicate for the ADC busy state*/
static u8 ADC_u8State = IDLE;
/*Global pointer to carry the conversion result in the asynchronous execution*/
static u16* ADC_pu16ConversionResult = NULL;
/*Global pointer to function to carry the notification function called by ISR*/
static pvFunction_t ADC_pvNotificationFunction = NULL;
/*Global variable to carry how many channels needed in group conversion*/
static u8 ADC_u8NumberOfChannels = 0;
/*Global pointer to carry the channels in group conversion*/
static u8* ADC_pu8GroupChannels = NULL;
/*Global flag to indicate for the group conversion is working*/
static u8 ADC_u8GroupConversionFlag = NOT_WORKING;
/*Global counter for Group conversion*/
static u8 ADC_u8GroupCounter = 0;


/********************************				Function Definitions				********************************/
void ADC_voidInit(void)
{
	/* Voltage Reference Selection */
#if ADC_REF_VOLT == ADC_AREF
	CLR_BIT(ADMUX,REFS0);			CLR_BIT(ADMUX,REFS1);
#elif ADC_REF_VOLT == ADC_AVCC
	SET_BIT(ADMUX,REFS0);			CLR_BIT(ADMUX,REFS1);
#elif ADC_REF_VOLT == ADC_INTERNAL
	SET_BIT(ADMUX,REFS0);			SET_BIT(ADMUX,REFS1);
#else
#error "Wrong ADC reference volt selection"
#endif

	/* ADC Left Adjust */
#if ADC_ADJUST == ADC_RIGHT
	CLR_BIT(ADMUX,ADLAR);
#elif ADC_ADJUST == ADC_LEFT
	SET_BIT(ADMUX,ADLAR);
#else
#error "Wrong ADC left adjust selection"
#endif

	/* ADC Auto Trigger Enable */
#if ADC_AUTO_TRIGGER == ADC_ENABLE
	SET_BIT(ADCSRA,ADATE);
#elif ADC_AUTO_TRIGGER == ADC_DISABLE
	CLR_BIT(ADCSRA,ADATE);
#else
#error "Wrong ADC Auto Trigger Enable selection"
#endif

	/* ADC Interrupt Enable */
#if ADC_INTERRUPT == ADC_ENABLE
	SET_BIT(ADCSRA,ADIE);
#elif ADC_INTERRUPT == ADC_DISABLE
	CLR_BIT(ADCSRA,ADIE);
#else
#error "Wrong ADC Interrupt Enable selection"
#endif

	/* ADC Prescaler */
	ADCSRA &= 0xF8;			//mask prescaler bits first
	ADCSRA |= ADC_PRESCALER;

	//enable ADC
	SET_BIT(ADCSRA, ADEN);
}

u8 ADC_u8SingleConversionSynch(u8 copy_u8AdcChannel, u16* copy_pu16AdcData)
{
	u8 Local_u8ErrorStatus = OK;
	u32 Local_u32Timeout = 0;

	if(copy_u8AdcChannel <= ADC_CHANNEL7)
	{
		if(copy_pu16AdcData != NULL)
		{
			if(ADC_u8State == IDLE)
			{
				/*ADC busy now*/
				ADC_u8State = BUSY;

				//select channel
				ADMUX &= 0xE0;		/* clear MUX bits in the ADMUX register */
				ADMUX |= copy_u8AdcChannel;	/* Set required channel into the MUX bits in ADMUX register */

				/* ADC Start Conversion */
				SET_BIT(ADCSRA, ADSC);

				/* Busy wait polling till conversion complete
				 * using also Timeout to make sure ADC conversion time not take too long or exit
				 * */
				while(GET_BIT(ADCSRA,ADIF) == 0 && (Local_u32Timeout != ADC_TIMEOUT))
				{
					Local_u32Timeout++;
				}

				//check if the loop was broken by timeout or conversion is complete
				if(Local_u32Timeout < ADC_TIMEOUT)
				{
					/* Clear the ADC complete conversion Flag */
					SET_BIT(ADCSRA, ADIF);

					/* Read the value of the ADC Registers */
#if ADC_RESULT == ADC_10BIT
					/* ADC Left Adjust */
#if ADC_ADJUST == ADC_RIGHT
					*copy_pu16AdcData = ADC_DATA;
#elif ADC_ADJUST == ADC_LEFT
					*copy_pu16AdcData = ADC_DATA >> 6;
#endif
#elif ADC_RESULT == ADC_8BIT
					/* ADC Left Adjust */
#if ADC_ADJUST == ADC_RIGHT
					*copy_pu16AdcData = ADC_DATA >> 2;
#elif ADC_ADJUST == ADC_LEFT
					*copy_pu16AdcData = ADCH;
#endif
#else
#error "Wrong ADC result selection"
#endif

					/*ADC is now IDLE*/
					ADC_u8State = IDLE;

				}
				else
					Local_u8ErrorStatus = ADC_E_TIMEOUT;
			}
			else
				Local_u8ErrorStatus = ADC_E_BUSY;

		}
		else
			Local_u8ErrorStatus = ADC_E_PARAM_POINTER;
	}
	else
		Local_u8ErrorStatus = ADC_E_PARAM_INVALID_CHANNEL_ID;

	return Local_u8ErrorStatus;
}

u8 ADC_u8SingleConversionAsynch(u8 copy_u8AdcChannel, u16* copy_pu16AdcData, pvFunction_t copy_pvNotificationFunc)
{
	u8 Local_u8ErrorStatus = OK;

	if(copy_u8AdcChannel <= ADC_CHANNEL7)
	{
		if(copy_pu16AdcData != NULL && copy_pvNotificationFunc != NULL)
		{
			if(ADC_u8State == IDLE)
			{
				/*ADC busy now*/
				ADC_u8State = BUSY;
				/*Initialize the global result pointer*/
				ADC_pu16ConversionResult = copy_pu16AdcData;
				/*Initialize the global notification function pointer*/
				ADC_pvNotificationFunction = copy_pvNotificationFunc;

				//select channel
				ADMUX &= 0xE0;		/* clear MUX bits in the ADMUX register */
				ADMUX |= copy_u8AdcChannel;	/* Set required channel into the MUX bits in ADMUX register */

				/* ADC Start Conversion */
				SET_BIT(ADCSRA, ADSC);
				/*Enable ADC Interrupt*/
				SET_BIT(ADCSRA,ADIE);

			}
			else
				Local_u8ErrorStatus = ADC_E_BUSY;

		}
		else
			Local_u8ErrorStatus = ADC_E_PARAM_POINTER;
	}
	else
		Local_u8ErrorStatus = ADC_E_PARAM_INVALID_CHANNEL_ID;

	return Local_u8ErrorStatus;
}

u8 ADC_u8GroupConversionSynch(ADC_GROUP_st* copy_stAdcGroup)
{
	u8 Local_u8ErrorStatus = OK, Local_u8Iterator = 0;
	u32 Local_u32Timeout = 0;

	if((copy_stAdcGroup->NumberOfChannels) <= ADC_CHANNEL7)
	{
		if((copy_stAdcGroup != NULL) && (copy_stAdcGroup->AdcChannels != NULL) && (copy_stAdcGroup->AdcResults != NULL))
		{
			if(ADC_u8State == IDLE)
			{
				/*ADC busy now*/
				ADC_u8State = BUSY;

				//loop over group channels
				while(Local_u8Iterator < (copy_stAdcGroup->NumberOfChannels))
				{
					//select channel
					ADMUX &= 0xE0;		/* clear MUX bits in the ADMUX register */
					ADMUX |= (copy_stAdcGroup->AdcChannels[Local_u8Iterator]);	/* Set required channel into the MUX bits in ADMUX register */

					/* ADC Start Conversion */
					SET_BIT(ADCSRA, ADSC);

					/* Busy wait polling till conversion complete
					 * using also Timeout to make sure ADC conversion time not take too long or exit
					 * */
					while(GET_BIT(ADCSRA,ADIF) == 0 && (Local_u32Timeout != ADC_TIMEOUT))
					{
						Local_u32Timeout++;
					}

					//check if the loop was broken by timeout or conversion is complete
					if(Local_u32Timeout < ADC_TIMEOUT)
					{
						/* Clear the ADC complete conversion Flag */
						SET_BIT(ADCSRA, ADIF);

						/* Read the value of the ADC Registers */
#if ADC_RESULT == ADC_10BIT
						/* ADC Left Adjust */
#if ADC_ADJUST == ADC_RIGHT
						copy_stAdcGroup->AdcResults[Local_u8Iterator] = ADC_DATA;
#elif ADC_ADJUST == ADC_LEFT
						copy_stAdcGroup->AdcResults[Local_u8Iterator] = ADC_DATA >> 6;
#endif
#elif ADC_RESULT == ADC_8BIT
						/* ADC Left Adjust */
#if ADC_ADJUST == ADC_RIGHT
						copy_stAdcGroup->AdcResults[Local_u8Iterator] = ADC_DATA >> 2;
#elif ADC_ADJUST == ADC_LEFT
						copy_stAdcGroup->AdcResults[Local_u8Iterator] = ADCH;
#endif
#else
#error "Wrong ADC result selection"
#endif
					}
					else
					{
						Local_u8ErrorStatus = ADC_E_TIMEOUT;
						copy_stAdcGroup->AdcResults[Local_u8Iterator] = 0;
					}

					Local_u8Iterator++;
					Local_u32Timeout = 0;

				}//end of while loop

				/*ADC is now IDLE*/
				ADC_u8State = IDLE;
			}
			else
				Local_u8ErrorStatus = ADC_E_BUSY;

		}
		else
			Local_u8ErrorStatus = ADC_E_PARAM_POINTER;
	}
	else
		Local_u8ErrorStatus = ADC_E_PARAM_INVALID_CHANNEL_ID;

	return Local_u8ErrorStatus;
}

u8 ADC_u8GroupConversionAsynch(ADC_GROUP_st* copy_stAdcGroup, pvFunction_t copy_pvNotificationFunc)
{
	u8 Local_u8ErrorStatus = OK;

	if((copy_stAdcGroup->NumberOfChannels) <= ADC_CHANNEL7)
	{
		if((copy_stAdcGroup != NULL) && (copy_pvNotificationFunc != NULL)
				&& (copy_stAdcGroup->AdcChannels != NULL) && (copy_stAdcGroup->AdcResults != NULL))
		{

			if(ADC_u8State == IDLE)
			{
				/*ADC busy now*/
				ADC_u8State = BUSY;
				/*Group conversion now starts*/
				ADC_u8GroupConversionFlag = WORKING;
				/*Initialize the global Number Of Group Channels variable*/
				ADC_u8NumberOfChannels = copy_stAdcGroup->NumberOfChannels;
				/*Initialize the global Group Needed Channels pointer*/
				ADC_pu8GroupChannels = copy_stAdcGroup->AdcChannels;
				/*Initialize the global result pointer*/
				ADC_pu16ConversionResult = copy_stAdcGroup->AdcResults;
				/*Initialize the global notification function pointer*/
				ADC_pvNotificationFunction = copy_pvNotificationFunc;

				//select channel
				ADMUX &= 0xE0;		/* clear MUX bits in the ADMUX register */
				ADMUX |= copy_stAdcGroup->AdcChannels[ADC_u8GroupCounter];	/* Set required channel into the MUX bits in ADMUX register */

				/* ADC Start Conversion */
				SET_BIT(ADCSRA, ADSC);
				/*Enable ADC Interrupt*/
				SET_BIT(ADCSRA,ADIE);

			}
			else
				Local_u8ErrorStatus = ADC_E_BUSY;

		}
		else
			Local_u8ErrorStatus = ADC_E_PARAM_POINTER;
	}
	else
		Local_u8ErrorStatus = ADC_E_PARAM_INVALID_CHANNEL_ID;

	return Local_u8ErrorStatus;
}

/******************************************************************************
 * !comment  :  ISR Function ADC.  							 			      *
 ******************************************************************************/

void __vector_16 (void) __attribute__((signal));
void __vector_16 (void)
{
	if(ADC_u8GroupConversionFlag == NOT_WORKING)
	{
		/* Clear the ADC complete conversion Flag */
		SET_BIT(ADCSRA, ADIF);

		/* Read the value of the ADC Registers */
#if ADC_RESULT == ADC_10BIT
		/* ADC Left Adjust */
#if ADC_ADJUST == ADC_RIGHT
		*ADC_pu16ConversionResult = ADC_DATA;
#elif ADC_ADJUST == ADC_LEFT
		*ADC_pu16ConversionResult = ADC_DATA >> 6;
#endif
#elif ADC_RESULT == ADC_8BIT
		/* ADC Left Adjust */
#if ADC_ADJUST == ADC_RIGHT
		*ADC_pu16ConversionResult = ADC_DATA >> 2;
#elif ADC_ADJUST == ADC_LEFT
		*ADC_pu16ConversionResult = ADCH;
#endif
#else
#error "Wrong ADC result selection"
#endif

		/*Disable ADC Interrupt*/
		CLR_BIT(ADCSRA,ADIE);

		/*Invoke the callback notification function*/
		ADC_pvNotificationFunction();

		/*ADC is now IDLE*/
		ADC_u8State = IDLE;
	}
	else if(ADC_u8GroupConversionFlag == WORKING)
	{
		/* Clear the ADC complete conversion Flag */
		SET_BIT(ADCSRA, ADIF);
		/* Read the value of the ADC Registers */
#if ADC_RESULT == ADC_10BIT
		/* ADC Left Adjust */
#if ADC_ADJUST == ADC_RIGHT
		ADC_pu16ConversionResult[ADC_u8GroupCounter] = ADC_DATA;
#elif ADC_ADJUST == ADC_LEFT
		ADC_pu16ConversionResult[ADC_u8GroupCounter] = ADC_DATA >> 6;
#endif
#elif ADC_RESULT == ADC_8BIT
		/* ADC Left Adjust */
#if ADC_ADJUST == ADC_RIGHT
		ADC_pu16ConversionResult[ADC_u8GroupCounter] = ADC_DATA >> 2;
#elif ADC_ADJUST == ADC_LEFT
		ADC_pu16ConversionResult[ADC_u8GroupCounter] = ADCH;
#endif
#else
#error "Wrong ADC result selection"
#endif

		ADC_u8GroupCounter++;

		if(ADC_u8GroupCounter >= ADC_u8NumberOfChannels)
		{
			/*Disable ADC Interrupt*/
			CLR_BIT(ADCSRA,ADIE);

			/* Reset the Group Counter*/
			ADC_u8GroupCounter = 0;

			/*Invoke the callback notification function*/
			ADC_pvNotificationFunction();

			/*Group conversion is now not working*/
			ADC_u8GroupConversionFlag = NOT_WORKING;

			/*ADC is now IDLE*/
			ADC_u8State = IDLE;
		}
		else
		{
			//select channel
			ADMUX &= 0xE0;		/* clear MUX bits in the ADMUX register */
			ADMUX |= ADC_pu8GroupChannels[ADC_u8GroupCounter];	/* Set required channel into the MUX bits in ADMUX register */

			/* ADC Start Conversion */
			SET_BIT(ADCSRA, ADSC);
		}
	}
}
