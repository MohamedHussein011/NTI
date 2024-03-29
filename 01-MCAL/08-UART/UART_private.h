/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: UART_private.h	                ************************/
/***************************************************************************************/

#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

/***********************				Registers						************************/
/* USART I/O Data Register */
#define UDR    *((volatile u8 *)0x2C)

/* USART Control and Status Register A */
#define UCSRA  *((volatile u8 *)0x2B)
#define RXC     7                     //USART Receive Complete
#define TXC		6                     //USART Transmit Complete
#define UDRE    5                     //USART Data Register Empty
#define FE      4                     //Frame Error
#define DOR     3                     //Data OverRun
#define PE      2                     //Parity Error
#define U2X     1                     //Double the USART Transmission Speed
#define MPCM    0                     //Multi-processor Communication Mode

/* USART Control and Status Register B */
#define UCSRB  *((volatile u8 *)0x2A)
#define RXCIE       7                     //RX Complete Interrupt Enable
#define TXCIE		6                     //TX Complete Interrupt Enable
#define UDRIE       5                     //USART Data Register Empty Interrupt Enable
#define RXEN        4                     //Receiver Enable
#define TXEN        3                     //Transmitter Enable
#define UCSZ2       2                     //Character Size
#define RXB8        1                     //Receive Data Bit 8
#define TXB8        0                     //Transmit Data Bit 8

/* USART Control and Status Register C */
#define UCSRC  *((volatile u8 *)0x40)
#define URSEL        7                     //Register Select
#define UMSEL		 6                     //USART Mode Select
#define UPM1         5                     //Parity Mode bit 1
#define UPM0         4                     //Parity Mode bit 0
#define USBS         3                     //Stop Bit Select
#define UCSZ1        2                     //Character Size bit 1
#define UCSZ0        1                     //Character Size bit 0
#define UCPOL        0                     //Clock Polarity

/* USART Baud Rate Registers */
#define UBRRL  *((volatile u8 *)0x29)
#define UBRRH  *((volatile u8 *)0x40)

#endif
