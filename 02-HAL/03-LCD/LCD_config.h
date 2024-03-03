/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: LCD_config.h	                ************************/
/***************************************************************************************/

#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

/* Modes of Initialization */
#define LCD_InitMode         FourBit_Init

#if (LCD_InitMode < EightBit_Init || LCD_InitMode > FourBit_Init)
#error "Wrong LCD init mode"
#endif

/* Number of Lines*/
#define LCD_NumbersOfLines         Two_Lines

#if (LCD_NumbersOfLines < One_Line || LCD_NumbersOfLines > Two_Lines)
#error "Wrong LCD number of lines"
#endif

/* Font Size*/
#define LCD_Font_Size        FiveEight_Size

#if (LCD_Font_Size < FiveEight_Size || LCD_Font_Size > FiveEleven_Size)
#error "Wrong LCD font size"
#endif

/* Display */
#define LCD_Display        Display_ON

#if (LCD_Display < Display_ON || LCD_Display > Display_OFF)
#error "Wrong LCD display"
#endif

/* Cursor On/Off*/
#define LCD_Cursor       Cursor_ON

#if (LCD_Cursor < Cursor_ON || LCD_Cursor > Cursor_OFF)
#error "Wrong LCD cursor"
#endif

/* Blinking On/Off*/
#define LCD_Blinking       Blinking_OFF

#if (LCD_Blinking < Blinking_ON || LCD_Blinking > Blinking_OFF)
#error "Wrong LCD blinking"
#endif

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
#define LCD_RW_PIN          DIO_PIN1
#define LCD_EN_PIN          DIO_PIN2

#if (LCD_RS_PIN < DIO_PIN0 || LCD_RS_PIN > DIO_PIN7 || \
	 LCD_RW_PIN < DIO_PIN0 || LCD_RW_PIN > DIO_PIN7 || \
	 LCD_EN_PIN < DIO_PIN0 || LCD_EN_PIN > DIO_PIN7)
#error "Wrong lcd pin selection"
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
#error "Wrong lcd port selection"
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
#error "Wrong lcd pin selection"
#endif

#endif
