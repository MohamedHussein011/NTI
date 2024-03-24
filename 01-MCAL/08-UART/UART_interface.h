/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: UART_interface.h	            ************************/
/***************************************************************************************/


#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H


/*********************************		Error classification	******************************/
//Invalid Timer interrupt ID requested
#define UART_E_TIMEOUT							0x0A
//APIs called with null pointer
#define UART_E_PARAM_POINTER					0x0B
//UART is busy sending / receiving
#define UART_E_BUSY								0x0C


/*********************************		MACROs	******************************/
/* Character Size */
#define UART_5BITS						0
#define UART_6BITS						1
#define UART_7BITS						2
#define UART_8BITS						3

/* Parity Mode */
#define UART_EVEN						2
#define UART_ODD						3

/* Stop Bits */
#define UART_1STOP						0
#define UART_2STOP						1

/* Double the USART Transmission Speed in asynchronous mode*/
#define UART_NO_DOUBLE_SPEED						0
#define UART_DOUBLE_SPEED							1

/* UART Interrupt sources*/
#define UART_RXCIE								0
#define UART_TXCIE								1
#define UART_UDRIE								2

/* Enable UART transmitter & receiver*/
#define UART_DISABLE							0
#define UART_ENABLE								1


/********************************				Function Prototypes				********************************/

/********************************				 TIMER0  						********************************/
/* @brief		shall initialize UART with the configuration in UART_config.h
* @paramin		none
* @paramout		none
* @retval		none
*/
 void UART_voidInit (void);

/* @brief		shall transmit one byte synch
* @paramin		copy_u8Data / one byte data
* @paramout		none
* @retval		error of wrong paramin
*/
u8 UART_u8TransmitByte(u8 copy_u8Data);

/* @brief		shall receive one byte synch
* @paramin		none
* @paramout		copy_pu8Data / one byte data
* @retval		error of wrong paramin
*/
u8 UART_u8ReceiveByte(u8* copy_pu8Data);

/* @brief		shall transmit string synch
* @paramin		copy_pu8Data / pointer to an array holding more than one byte data
* @paramout		none
* @retval		error of wrong paramin
*/
u8 UART_u8TransmitStringSynch(u8* copy_pu8Data);

/* @brief		shall receive string synch
* @paramin		none
* @paramout		copy_pu8Data / pointer to an array holding more than one byte data
* @retval		error of wrong paramin
* @note			press [enter button] to enter the string
*/
u8 UART_u8ReceiveStringSynch(u8* copy_pu8Data);

/* @brief		shall transmit string Asynch
* @paramin		copy_pu8Data / pointer to an array holding more than one byte data -
* 				copy_pvFunc /  pointer to a function that takes nothing & returns nothing and being called
* 				after the string is transmitted
* @paramout		none
* @retval		error of wrong paramin
*/
u8 UART_u8TransmitStringAsynch(u8* copy_pu8Data, pvFunction_t copy_pvFunc);

/* @brief		shall receive string Asynch
* @paramin		copy_pvFunc /  pointer to a function that takes nothing & returns nothing and being called
* 				after the string is transmitted
* @paramout		copy_pu8Data / pointer to an array holding more than one byte data
* @retval		error of wrong paramin
* @note			press [enter button] to enter the string
*/
u8 UART_u8ReceiveStringAsynch(u8* copy_pu8Data, pvFunction_t copy_pvFunc);

/* @brief		shall transmit number
* @paramin		copy_s32Number / number to be sent
* @paramout		none
* @retval		none
*/
void UART_voidTransmitNumber(s32 copy_s32Number);

#endif 
