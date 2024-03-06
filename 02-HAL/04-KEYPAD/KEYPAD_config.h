/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: KEYPAD_config.h	            ************************/
/***************************************************************************************/

#ifndef KEYPAD_CONFIG_H
#define KEYPAD_CONFIG_H

/*input type for input pins
 * KEYPAD_INPUT_PULLUP
 * or -> if your hardware is already connected pull down or up, choose KEYPAD_INPUT_PU or KEYPAD_INPUT_PD
 * */
#define KEYPAD_IN_TYPE			KEYPAD_INPUT_PU
#if (KEYPAD_IN_TYPE < KEYPAD_INPUT_PULLUP || KEYPAD_IN_TYPE > KEYPAD_INPUT_PD)
#error "Wrong keypad input selection"
#endif


/* CHOOSE what's input for control
 * COL_CONTROL -> col output / row input
 * ROW_CONTROL -> col input  / row output
 * */
#define KEYPAD_CONTROL				COL_CONTROL
#if (KEYPAD_CONTROL < COL_CONTROL || KEYPAD_CONTROL > ROW_CONTROL)
#error "Wrong keypad control selection"
#endif

//keypad ports
#define KEYPAD_COL0_PORT		DIO_PORTD
#define KEYPAD_COL1_PORT		DIO_PORTD
#define KEYPAD_COL2_PORT		DIO_PORTD
#define KEYPAD_COL3_PORT		DIO_PORTD
#define KEYPAD_ROW0_PORT		DIO_PORTC
#define KEYPAD_ROW1_PORT		DIO_PORTC
#define KEYPAD_ROW2_PORT		DIO_PORTC
#define KEYPAD_ROW3_PORT		DIO_PORTC

#if (KEYPAD_COL0_PORT < DIO_PORTA || KEYPAD_COL0_PORT > DIO_PORTD || \
     KEYPAD_COL1_PORT < DIO_PORTA || KEYPAD_COL1_PORT > DIO_PORTD || \
     KEYPAD_COL2_PORT < DIO_PORTA || KEYPAD_COL2_PORT > DIO_PORTD || \
     KEYPAD_COL3_PORT < DIO_PORTA || KEYPAD_COL3_PORT > DIO_PORTD || \
     KEYPAD_ROW0_PORT < DIO_PORTA || KEYPAD_ROW0_PORT > DIO_PORTD || \
     KEYPAD_ROW1_PORT < DIO_PORTA || KEYPAD_ROW1_PORT > DIO_PORTD || \
     KEYPAD_ROW2_PORT < DIO_PORTA || KEYPAD_ROW2_PORT > DIO_PORTD || \
     KEYPAD_ROW3_PORT < DIO_PORTA || KEYPAD_ROW3_PORT > DIO_PORTD)
#error "Wrong keypad port selection"
#endif

//keypad pins
#define KEYPAD_COL0_PIN		DIO_PIN7
#define KEYPAD_COL1_PIN		DIO_PIN6
#define KEYPAD_COL2_PIN		DIO_PIN5
#define KEYPAD_COL3_PIN		DIO_PIN3
#define KEYPAD_ROW0_PIN		DIO_PIN5
#define KEYPAD_ROW1_PIN		DIO_PIN4
#define KEYPAD_ROW2_PIN		DIO_PIN3
#define KEYPAD_ROW3_PIN		DIO_PIN2

#if (KEYPAD_COL0_PIN < DIO_PIN0 || KEYPAD_COL0_PIN > DIO_PIN7 || \
     KEYPAD_COL1_PIN < DIO_PIN0 || KEYPAD_COL1_PIN > DIO_PIN7 || \
     KEYPAD_COL2_PIN < DIO_PIN0 || KEYPAD_COL2_PIN > DIO_PIN7 || \
     KEYPAD_COL3_PIN < DIO_PIN0 || KEYPAD_COL3_PIN > DIO_PIN7 || \
     KEYPAD_ROW0_PIN < DIO_PIN0 || KEYPAD_ROW0_PIN > DIO_PIN7 || \
     KEYPAD_ROW1_PIN < DIO_PIN0 || KEYPAD_ROW1_PIN > DIO_PIN7 || \
     KEYPAD_ROW2_PIN < DIO_PIN0 || KEYPAD_ROW2_PIN > DIO_PIN7 || \
     KEYPAD_ROW3_PIN < DIO_PIN0 || KEYPAD_ROW3_PIN > DIO_PIN7)
#error "Wrong keypad pin selection"
#endif

//key is not pressed
#define KEYPAD_NOT_PRESSED			0X00

//keypad array
#define KEYPAD_ARRAY		{{'7','8','9','/'}, {'4','5','6','*'}, {'1','2','3','-'}, {'0','.','=','+'}}

#endif
