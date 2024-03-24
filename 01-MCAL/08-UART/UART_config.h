/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: UART_config.h	                ************************/
/***************************************************************************************/

#ifndef UART_CONFIG_H
#define UART_CONFIG_H


/* CPU Freq. */
#define CPU_FREQ				16000000UL

/* Baud rate Select*/
#define UART_BAUD_RATE					9600UL

/* Character Size */
#define UART_CHAR_SIZE					UART_8BITS

/* Parity Mode */
#define UART_PARITY						UART_DISABLE

/* Stop Bits */
#define UART_STOP						UART_1STOP

/* Double the USART Transmission Speed in asynchronous mode*/
#define UART_ASYNCH_SEED_MODE				UART_NO_DOUBLE_SPEED

/* Enable UART transmitter & receiver*/
#define UART_TX							UART_ENABLE
#define UART_RX							UART_ENABLE

/* Timeout indicating whether Data empty register is ready or not & not to stuck on the function */
#define UART_TIMEOUT			5000000UL

#endif
