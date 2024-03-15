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

/* ADC Prescaler */
#define ADC_PRESCALER				ADC_DIV_BY_64

/* ADC conversion result */
#define ADC_RESULT					ADC_10BIT

/* ADC timeout */
#define ADC_TIMEOUT					5000UL

/*reference voltage (in mV) & resolution bits (value in decimal) used to calculate the analog value with respect to digital value*/
#define ADC_REFERENCE      		 	 5000UL
#define ADC_RESOLUTION_BITS          1024UL

#endif
