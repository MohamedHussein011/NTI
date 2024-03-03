/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: SSEG_config.h	                ************************/
/***************************************************************************************/

#ifndef SSEG_CONFIG_H
#define SSEG_CONFIG_H


#define SSEG_USED_BITS					SSEG_8BITS

//ordinary 7 segment
#if SSEG_USED_BITS == SSEG_8BITS

#define SSEG_PORT_PIN0		DIO_PORTA
#define SSEG_PORT_PIN1		DIO_PORTA
#define SSEG_PORT_PIN2		DIO_PORTA
#define SSEG_PORT_PIN3		DIO_PORTA
#define SSEG_PORT_PIN4		DIO_PORTA
#define SSEG_PORT_PIN5		DIO_PORTA
#define SSEG_PORT_PIN6		DIO_PORTA

#if (SSEG_PORT_PIN0 < DIO_PORTA || SSEG_PORT_PIN0 > DIO_PORTD || \
	SSEG_PORT_PIN1 < DIO_PORTA || SSEG_PORT_PIN1 > DIO_PORTD || \
	SSEG_PORT_PIN2 < DIO_PORTA || SSEG_PORT_PIN2 > DIO_PORTD || \
	SSEG_PORT_PIN3 < DIO_PORTA || SSEG_PORT_PIN3 > DIO_PORTD || \
	SSEG_PORT_PIN4 < DIO_PORTA || SSEG_PORT_PIN4 > DIO_PORTD || \
	SSEG_PORT_PIN5 < DIO_PORTA || SSEG_PORT_PIN5 > DIO_PORTD || \
	SSEG_PORT_PIN6 < DIO_PORTA || SSEG_PORT_PIN6 > DIO_PORTD)
#error "Wrong seven segment port selection"
#endif



#define SSEG_PIN0		DIO_PIN0
#define SSEG_PIN1		DIO_PIN1
#define SSEG_PIN2		DIO_PIN2
#define SSEG_PIN3		DIO_PIN3
#define SSEG_PIN4		DIO_PIN4
#define SSEG_PIN5		DIO_PIN5
#define SSEG_PIN6		DIO_PIN6

#if (SSEG_PIN0 < DIO_PIN0 || SSEG_PIN0 > DIO_PIN7 || \
	SSEG_PIN1 < DIO_PIN0 || SSEG_PIN1 > DIO_PIN7 || \
	SSEG_PIN2 < DIO_PIN0 || SSEG_PIN2 > DIO_PIN7 || \
	SSEG_PIN3 < DIO_PIN0 || SSEG_PIN3 > DIO_PIN7 || \
	SSEG_PIN4 < DIO_PIN0 || SSEG_PIN4 > DIO_PIN7 || \
	SSEG_PIN5 < DIO_PIN0 || SSEG_PIN5 > DIO_PIN7 || \
	SSEG_PIN6 < DIO_PIN0 || SSEG_PIN6 > DIO_PIN7)
#error "Wrong seven segment pin selection"
#endif

#define SSEG_COM_PORT		DIO_PORTA
#define SSEG_COM_PIN		DIO_PIN7

#if (SSEG_COM_PORT < DIO_PORTA || SSEG_COM_PORT > DIO_PORTD || \
	SSEG_COM_PIN < DIO_PIN0 || SSEG_COM_PIN > DIO_PIN7)
#error "Wrong seven segment com port & pin selection"
#endif

#define SSEG_TYPE			CATHODE

#if (SSEG_TYPE < ANODE || SSEG_TYPE > CATHODE)
#error "Wrong seven segment type selection"
#endif

#elif SSEG_USED_BITS == SSEG_4BITS_BCD
//4 pins for BCD
#define BCD_SSEG_PORT_PINA		DIO_PORTB
#define BCD_SSEG_PORT_PINB		DIO_PORTB
#define BCD_SSEG_PORT_PINC		DIO_PORTB
#define BCD_SSEG_PORT_PIND		DIO_PORTB

#if (BCD_SSEG_PORT_PINA < DIO_PORTA || BCD_SSEG_PORT_PINA > DIO_PORTD || \
	BCD_SSEG_PORT_PINB < DIO_PORTA || BCD_SSEG_PORT_PINB > DIO_PORTD || \
	BCD_SSEG_PORT_PINC < DIO_PORTA || BCD_SSEG_PORT_PINC > DIO_PORTD || \
	BCD_SSEG_PORT_PIND < DIO_PORTA || BCD_SSEG_PORT_PIND > DIO_PORTD)
#error "Wrong seven segment port selection"
#endif

#define BCD_SSEG_PINA		DIO_PIN0
#define BCD_SSEG_PINB		DIO_PIN1
#define BCD_SSEG_PINC		DIO_PIN2
#define BCD_SSEG_PIND		DIO_PIN4

#if (BCD_SSEG_PINA < DIO_PIN0 || BCD_SSEG_PINA > DIO_PIN7 || \
	BCD_SSEG_PINB < DIO_PIN0 || BCD_SSEG_PINB > DIO_PIN7 || \
	BCD_SSEG_PINC < DIO_PIN0 || BCD_SSEG_PINC > DIO_PIN7 || \
	BCD_SSEG_PIND < DIO_PIN0 || BCD_SSEG_PIND > DIO_PIN7)
#error "Wrong seven segment pin selection"
#endif

#define SSEG_BCD_PORT_COM			DIO_PORTA

#define SSEG_BCD_PIN_COM			DIO_PIN3

#if (SSEG_BCD_PORT_COM < DIO_PORTA || SSEG_BCD_PORT_COM > DIO_PORTD || \
	SSEG_BCD_PIN_COM < DIO_PIN0 || SSEG_BCD_PIN_COM > DIO_PIN7)
#error "Wrong seven segment com port & pin selection"
#endif

#define SSEG_TYPE			CATHODE

#if (SSEG_TYPE < ANODE || SSEG_TYPE > CATHODE)
#error "Wrong seven segment type selection"
#endif

#else
#error "Wrong seven segment selection"
#endif

#endif
