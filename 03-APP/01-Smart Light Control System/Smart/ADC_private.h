/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: ADC_private.h	                ************************/
/***************************************************************************************/

#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

/***********************				Registers						************************/
/******************************************************************************
 * !comment : ADC Multiplexer Selection Register (ADMUX) & Bits Definition.    *
 ******************************************************************************/
#define ADMUX  			*((volatile u8*)0x27)

#define REFS1           7         //Reference Selection Bits
#define REFS0           6         //Reference Selection Bits
#define ADLAR           5         //ADC Left Adjust Result
#define MUX4            4         //Analog Channel and Gain Selection Bits
#define MUX3            3         //Analog Channel and Gain Selection Bits
#define MUX2            2         //Analog Channel and Gain Selection Bits
#define MUX1            1         //Analog Channel and Gain Selection Bits
#define MUX0            0         //Analog Channel and Gain Selection Bits

/******************************************************************************
 * !comment : ADC Control and Status Register A (ADCSRA) & Bits Definition.    *
 ******************************************************************************/
#define ADCSRA 			*((volatile u8*)0x26)

#define ADEN            7         //ADC Enable
#define ADSC            6         //ADC Start Conversion
#define ADATE           5         //ADC Auto Trigger Enable
#define ADIF            4         //ADC Interrupt Flag
#define ADIE            3         //ADC Interrupt Enable
#define ADPS2           2         //ADC Prescaler Select Bits
#define ADPS1           1         //ADC Prescaler Select Bits
#define ADPS0           0         //ADC Prescaler Select Bits

/******************************************************************************
 * !comment : The ADC Data Register – (ADCH) & (ADCL)                          *
 ******************************************************************************/
#define ADCH   			*((const volatile u8*)0x25)
#define ADCL   			*((const volatile u8*)0x24)

/******************************************************************************
 * !comment : Register for data combined form ADCL & ADCH – (ADC_DATA)         *
 ******************************************************************************/
#define ADC_DATA        *((const volatile u16*)0x24)

/******************************************************************************
 * !comment : Special FunctionIO Register – (SFIOR)                            *
 ******************************************************************************/
#define SFIOR  			*((volatile u8*)0x50)

#define ADTS2           7         //ADC Auto Trigger Source
#define ADTS1           6         //ADC Auto Trigger Source
#define ADTS0           5         //ADC Auto Trigger Source


#endif
