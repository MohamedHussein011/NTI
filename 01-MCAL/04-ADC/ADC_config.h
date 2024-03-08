/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: ADC_config.h	                ************************/
/***************************************************************************************/

#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H

/* Voltage Reference Selection */
#define ADC_REF_VOLT				ADC_AVCC

/* ADC Left Adjust */
#define ADC_ADJUST					ADC_RIGHT

/* ADC Auto Trigger Enable */
#define ADC_AUTO_TRIGGER			ADC_DISABLE

/* ADC Interrupt Enable */
#define ADC_INTERRUPT				ADC_ENABLE

/* ADC Prescaler */
#define ADC_PRESCALER				ADC_DIV_BY_64

/* ADC conversion result */
#define ADC_RESULT					ADC_10BIT

/* ADC timeout */
#define ADC_TIMEOUT					5000UL

#endif
