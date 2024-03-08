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
#define ADC_E_BUSY							0x0D

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

/* ADC channels */
typedef enum
{
	ADC_DIV_BY_2 = 1,
	ADC_DIV_BY_4,
	ADC_DIV_BY_8,
	ADC_DIV_BY_16,
	ADC_DIV_BY_32,
	ADC_DIV_BY_64,
	ADC_DIV_BY_128
}ADC_PRESCALER_en;

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
	ADC_CHANNEL7,
}ADC_CHANNELS_en;

/* ADC Group Synchronous*/
typedef struct
{
	u8 NumberOfChannels;
	u8* AdcChannels;
	u16* AdcResults;
}ADC_GROUP_st;


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
*/
u8 ADC_u8SingleConversionAsynch(u8 copy_u8AdcChannel, u16* copy_pu16AdcData, pvFunction_t copy_pvNotificationFunc);

/* @brief		shall start ADC group conversion synchronous
* @paramin		copy_stAdcGroup / ADC channels to be converted
* @paramout		copy_stAdcGroup / ADC result to be returned
* @retval		Error of wrong parameters
*/
u8 ADC_u8GroupConversionSynch(ADC_GROUP_st* copy_stAdcGroup);

/* @brief		shall start ADC group conversion Asynchronous
* @paramin		copy_stAdcGroup / ADC channels to be converted -
* 				copy_pvNotificationFunc / pointer to function that takes nothing and returns nothing
* 				& be executed when the conversion is complete
* @paramout		copy_stAdcGroup / ADC result to be returned
* @retval		Error of wrong parameters
*/
u8 ADC_u8GroupConversionAsynch(ADC_GROUP_st* copy_stAdcGroup, pvFunction_t copy_pvNotificationFunc);


#endif 
