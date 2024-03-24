/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: SSEG_config.h	                ************************/
/***************************************************************************************/

#ifndef SSEG_CONFIG_H
#define SSEG_CONFIG_H


#define SSEG_USED_BITS					SSEG_4BITS_BCD
#define SSEG_TYPE						CATHODE

//ordinary 7 segment
#if SSEG_USED_BITS == SSEG_8BITS

#define SSEG_PORT_PIN0		DIO_PORTC
#define SSEG_PORT_PIN1		DIO_PORTC
#define SSEG_PORT_PIN2		DIO_PORTC
#define SSEG_PORT_PIN3		DIO_PORTC
#define SSEG_PORT_PIN4		DIO_PORTC
#define SSEG_PORT_PIN5		DIO_PORTC
#define SSEG_PORT_PIN6		DIO_PORTC

#define SSEG_PIN0		DIO_PIN0
#define SSEG_PIN1		DIO_PIN1
#define SSEG_PIN2		DIO_PIN2
#define SSEG_PIN3		DIO_PIN3
#define SSEG_PIN4		DIO_PIN4
#define SSEG_PIN5		DIO_PIN5
#define SSEG_PIN6		DIO_PIN6

#define SSEG_COM_PORT		DIO_PORTC
#define SSEG_COM_PIN		DIO_PIN7

#elif SSEG_USED_BITS == SSEG_4BITS_BCD
//4 pins for BCD
#define BCD_SSEG_PORT_PINA		DIO_PORTC
#define BCD_SSEG_PORT_PINB		DIO_PORTC
#define BCD_SSEG_PORT_PINC		DIO_PORTC
#define BCD_SSEG_PORT_PIND		DIO_PORTC

#define BCD_SSEG_PINA		DIO_PIN0
#define BCD_SSEG_PINB		DIO_PIN1
#define BCD_SSEG_PINC		DIO_PIN2
#define BCD_SSEG_PIND		DIO_PIN3

#define SSEG_BCD_PORT_COM			DIO_PORTC
#define SSEG_BCD_PIN_COM			DIO_PIN7

#else
#error "Wrong seven segment selection"
#endif

#endif
