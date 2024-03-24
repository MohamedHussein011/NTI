/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: LCD_config.h	                ************************/
/***************************************************************************************/

#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

/* Modes of Initialization */
#define LCD_InitMode         FourBit_Init

/* Number of Lines*/
#define LCD_NumbersOfLines         Two_Lines
/*NOTE:
 * 	One_Line 		--->	ROW0 & ROW2
 * 	Two_Lines 		--->	all rows
 * */

/* Font Size*/
#define LCD_Font_Size        FiveEight_Size

/* Display */
#define LCD_Display        Display_ON

/* Cursor On/Off*/
#define LCD_Cursor       Cursor_ON

/* Blinking On/Off*/
#define LCD_Blinking       Blinking_OFF

/*Control Port*/
#define LCD_RS_PORT          DIO_PORTA
#define LCD_RW_PORT          DIO_PORTA
#define LCD_EN_PORT          DIO_PORTA

#if (LCD_RS_PORT < DIO_PORTA || LCD_RS_PORT > DIO_PORTD || \
	 LCD_RW_PORT < DIO_PORTA || LCD_RW_PORT > DIO_PORTD || \
	 LCD_EN_PORT < DIO_PORTA || LCD_EN_PORT > DIO_PORTD)
#error "Wrong lcd control ports"
#endif


/*Control Pins*/
#define LCD_RS_PIN          DIO_PIN3
#define LCD_RW_PIN          DIO_PIN6
#define LCD_EN_PIN          DIO_PIN2

#if (LCD_RS_PIN < DIO_PIN0 || LCD_RS_PIN > DIO_PIN7 || \
	 LCD_RW_PIN < DIO_PIN0 || LCD_RW_PIN > DIO_PIN7 || \
	 LCD_EN_PIN < DIO_PIN0 || LCD_EN_PIN > DIO_PIN7)
#error "Wrong lcd Control pin selection"
#endif

/*Data Port*/
#define LCD_DATA_PORT_D0			DIO_PORTB
#define LCD_DATA_PORT_D1			DIO_PORTB
#define LCD_DATA_PORT_D2			DIO_PORTB
#define LCD_DATA_PORT_D3			DIO_PORTB
#define LCD_DATA_PORT_D4			DIO_PORTB
#define LCD_DATA_PORT_D5			DIO_PORTB
#define LCD_DATA_PORT_D6			DIO_PORTB
#define LCD_DATA_PORT_D7			DIO_PORTB

#if (LCD_DATA_PORT_D0 < DIO_PORTA || LCD_DATA_PORT_D0 > DIO_PORTD || \
	 LCD_DATA_PORT_D1 < DIO_PORTA || LCD_DATA_PORT_D1 > DIO_PORTD || \
	 LCD_DATA_PORT_D2 < DIO_PORTA || LCD_DATA_PORT_D2 > DIO_PORTD || \
	 LCD_DATA_PORT_D3 < DIO_PORTA || LCD_DATA_PORT_D3 > DIO_PORTD || \
	 LCD_DATA_PORT_D4 < DIO_PORTA || LCD_DATA_PORT_D4 > DIO_PORTD || \
	 LCD_DATA_PORT_D5 < DIO_PORTA || LCD_DATA_PORT_D5 > DIO_PORTD || \
	 LCD_DATA_PORT_D6 < DIO_PORTA || LCD_DATA_PORT_D6 > DIO_PORTD || \
	 LCD_DATA_PORT_D7 < DIO_PORTA || LCD_DATA_PORT_D7 > DIO_PORTD)
#error "Wrong lcd Data port selection"
#endif


/*Data pins */
#define LCD_DATA_PIN_D0			DIO_PIN0
#define LCD_DATA_PIN_D1			DIO_PIN1
#define LCD_DATA_PIN_D2			DIO_PIN2
#define LCD_DATA_PIN_D3			DIO_PIN3
#define LCD_DATA_PIN_D4			DIO_PIN0
#define LCD_DATA_PIN_D5			DIO_PIN1
#define LCD_DATA_PIN_D6			DIO_PIN2
#define LCD_DATA_PIN_D7			DIO_PIN4

#if (LCD_DATA_PIN_D0 < DIO_PIN0 || LCD_DATA_PIN_D0 > DIO_PIN7 || \
	 LCD_DATA_PIN_D1 < DIO_PIN0 || LCD_DATA_PIN_D1 > DIO_PIN7 || \
	 LCD_DATA_PIN_D2 < DIO_PIN0 || LCD_DATA_PIN_D2 > DIO_PIN7 || \
	 LCD_DATA_PIN_D3 < DIO_PIN0 || LCD_DATA_PIN_D3 > DIO_PIN7 || \
	 LCD_DATA_PIN_D4 < DIO_PIN0 || LCD_DATA_PIN_D4 > DIO_PIN7 || \
	 LCD_DATA_PIN_D5 < DIO_PIN0 || LCD_DATA_PIN_D5 > DIO_PIN7 || \
	 LCD_DATA_PIN_D6 < DIO_PIN0 || LCD_DATA_PIN_D6 > DIO_PIN7 || \
	 LCD_DATA_PIN_D7 < DIO_PIN0 || LCD_DATA_PIN_D7 > DIO_PIN7)
#error "Wrong lcd Data pin selection"
#endif

#endif
