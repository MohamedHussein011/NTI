/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: ADC_interface.h	            ************************/
/***************************************************************************************/


#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

/*********************************		Error classification	******************************/
//Invalid ADC channel ID requested
#define ADC_E_PARAM_INVALID_CHANNEL_ID			0x0A
//APIs called with a Null Pointer
#define ADC_E_PARAM_POINTER						0x0B
//ADC timeout
#define ADC_E_TIMEOUT							0x0C
//ADC is busy with conversion
#define ADC_E_BUSY								0x0D
//Invalid ADC Trigger Source ID requested
#define ADC_E_PARAM_INVALID_TRIGGER_ID			0x0E

/*********************************		MACROs	******************************/
/* Voltage Reference Selection */
#define ADC_AREF					0
#define ADC_AVCC					1
#define ADC_INTERNAL				2		//2.56v

/* ADC Left Adjust */
#define ADC_RIGHT					0
#define ADC_LEFT					1

/* ADC Auto Trigger Enable */
#define ADC_ENABLE					0
#define ADC_DISABLE					1

/* ADC conversion result */
#define ADC_10BIT					0
#define ADC_8BIT					1

/* ADC Prescaler */
typedef enum
{
	ADC_DIV_BY_2 = 1,
	ADC_DIV_BY_4,
	ADC_DIV_BY_8,
	ADC_DIV_BY_16,
	ADC_DIV_BY_32,
	ADC_DIV_BY_64,
	ADC_DIV_BY_128
}Adc_Prescaler_en;

/* ADC Trigger Source */
typedef enum
{
	ADC_FREE_RUNNING = 0,			//Free Running mode
	ADC_ANALOG_COM,					//Analog Comparator
	ADC_EXTI0,						//External Interrupt Request 0
	ADC_TIMER0_COM,					//Timer/Counter0 Compare Match
	ADC_TIMER0_OV,					//Timer/Counter0 Overflow
	ADC_TIMER1_COMB,				//Timer/Counter1 Compare Match B
	ADC_TIMER1_OV,					//Timer/Counter1 Overflow
	ADC_TIMER1_CE					//Timer/Counter1 Capture Event
}Adc_Trigger_en;

/* ADC channels */
typedef enum
{
	ADC_CHANNEL0 = 0,
	ADC_CHANNEL1,
	ADC_CHANNEL2,
	ADC_CHANNEL3,
	ADC_CHANNEL4,
	ADC_CHANNEL5,
	ADC_CHANNEL6,
	ADC_CHANNEL7
}Adc_Channels_en;

/* ADC group conversion Asynchronous */
typedef struct
{
	u8 NumOfConversions;
	u8* AdcChannels;
	u16* AdcResults;
	u8* AdcErrorStatus;
	pvFunction_t NotificationFunc;
}Adc_Group_Asynch_st;

/* ADC Trigger Conversion Asynchronous */
typedef struct
{
	u8 AdcTriggerSource;
	u8 AdcChannel;
	u16* AdcData;
	pvFunction_t NotificationFunc;
}Adc_Trigger_st;


/********************************				Function Prototypes				********************************/
/* @brief		shall initialize ADC with the configuration set in ADC_config.h
* @paramin		none
* @paramout		none
* @retval		none
*/
void ADC_voidInit(void);

/* @brief		shall start ADC single conversion synchronous
* @paramin		copy_u8AdcChannel / ADC channel to be converted
* @paramout		copy_u16AdcData / ADC result to be returned
* @retval		Error of wrong parameters
*/
u8 ADC_u8SingleConversionSynch(u8 copy_u8AdcChannel, u16* copy_pu16AdcData);

/* @brief		shall start ADC single conversion Asynchronous
* @paramin		copy_u8AdcChannel / ADC channel to be converted -
* 				copy_pvNotificationFunc / pointer to function that takes nothing and returns nothing
* 				& be executed when the conversion is complete
* @paramout		copy_u16AdcData / ADC result to be returned
* @retval		Error of wrong parameters
* @note			must enable interrupt
*/
u8 ADC_u8SingleConversionAsynch(u8 copy_u8AdcChannel, u16* copy_pu16AdcData, pvFunction_t copy_pvNotificationFunc);

/* @brief		shall start ADC group conversion synchronous
* @paramin		copy_u8NumOfConversions / number of ADC conversions needed -
* 				copy_pu8AdcChannels / array holding channels to be converted
* @paramout		copy_pu16AdcResults / ADC result to be returned
* @retval		Error of wrong parameters
*/
u8 ADC_u8GroupConversionSynch(u8 copy_u8NumOfConversions, u8* copy_pu8AdcChannels, u16* copy_pu16AdcResults);

/* @brief		shall start ADC group conversion Asynchronous
* @paramin		copy_stAdcGroupAsynch / a pointer to struct holding the next info. --> NumOfConversions / number of ADC conversions needed -
* 				AdcChannels / array holding channels to be converted -
* 				NotificationFunc / pointer to function that takes nothing and returns nothing
* 				& be executed when the conversion is complete
* @paramout		AdcResults / ADC result to be returned
* @retval		Error of wrong parameters
* @note			must enable interrupt
*/
u8 ADC_u8GroupConversionAsynch(Adc_Group_Asynch_st* copy_stAdcGroupAsynch);

/* @brief		shall start ADC conversion by a trigger source
* @paramin		copy_stAdcTrigger / a pointer to struct holding the next info. --> AdcTriggerSource / ADC trigger source that starts the conversion -
* 				AdcChannel / ADC channel to be converted -
* 				NotificationFunc / pointer to function that takes nothing and returns nothing
* 				& be executed when the conversion is complete
* @paramout		AdcData / ADC result to be returned
* @retval		Error of wrong parameters
* @note			must enable interrupt
* @note			it starts ADC conversion once there's a positive flag from the source & continuously doing so
* 				until you change the source or you disable it
* 				to disable it, use function ADC_voidDisableAutoTrigger
* 				to change trigger source, use function ADC_voidDisableAutoTrigger first then ADC_u8AutoTriggerConversion
*/
u8 ADC_u8AutoTriggerConversion(Adc_Trigger_st* copy_stAdcTrigger);

/* @brief		shall disable ADC conversion by a trigger source
* @paramin		none
* @paramout		none
* @retval		none
*/
void ADC_voidDisableAutoTrigger(void);

/* @brief		shall convert ADC digital value to analog value in mV
* @paramin		Copy_u16Value / ADC digital value
* @paramout		copy_u16Analog / analog value in mV
* @retval		Error of wrong parameters
* @note			configure first reference voltage & resolution bits in ADC_config.h
*/
u8 ADC_u8ConvertDigitalToAnalog (u16 Copy_u16Value, u16* copy_pu16Analog);


#endif 
