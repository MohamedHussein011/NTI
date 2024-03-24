/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: UART_program.c		            ************************/
/***************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "User_Functions.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"

/* array of 3 pointers to function holding address to a notification function*/
static pvFunction_t UART_CallBack[3] = {NULL};
/* array of 100 chars for string transmitted*/
static u8 UART_pu8TransmitString[100] = {0};
/* pointer to string received */
static u8* UART_pu8ReceiveString = NULL;
/* Counter for string*/
static u8 UART_u8counter = 0;
/* flag indicating UART is working or not */
static u8 UART_u8Flag = IDLE;


/********************************				Function Definitions				********************************/
void UART_voidInit (void)
{
	u16 Local_u16Baud = (CPU_FREQ / (UART_BAUD_RATE * (16 >> UART_ASYNCH_SEED_MODE))) - 1;

	/* Parity mode, character size, stop bits*/
	UCSRC = (1 << URSEL) | (UART_PARITY << UPM0) | (UART_STOP << USBS) | ((UART_CHAR_SIZE & 0x03) << UCSZ0);

	/* Double the USART Transmission Speed in asynchronous mode*/
	UCSRA |= (UART_ASYNCH_SEED_MODE << U2X);

	/* set baud rate*/
	UBRRH = (u8)((Local_u16Baud && ~(0x01 << 15)) >> 8);
	UBRRL = (u8)Local_u16Baud;

	/* Enable UART transmitter & receiver */
	UCSRB |= (UART_TX << TXEN) | (UART_RX << RXEN);

}

u8 UART_u8TransmitByte(u8 copy_u8Data)
{
	u8 Local_u8ErrorStatus = OK;
	u32 Local_u32Timeout = 0;

	if(UART_u8Flag == IDLE)
	{
		/* UART is now busy */
		UART_u8Flag = BUSY;

		/* Wait for empty transmit buffer */
		while(GET_BIT(UCSRA, UDRE) == 0 && Local_u32Timeout < UART_TIMEOUT)
		{
			Local_u32Timeout++;
		}

		/* check if loop is finished whether data register is empty or timeout happened */
		if(Local_u32Timeout < UART_TIMEOUT)
		{
			/* Put data into buffer, sends the data */
			UDR = copy_u8Data;

			/* UART is now idle */
			UART_u8Flag = IDLE;

		}
		else
			Local_u8ErrorStatus = UART_E_TIMEOUT;
	}
	else
		Local_u8ErrorStatus = UART_E_BUSY;


	return Local_u8ErrorStatus;
}

u8 UART_u8ReceiveByte(u8* copy_pu8Data)
{
	u8 Local_u8ErrorStatus = OK;
	u16 Local_u16Data = 0;
	u32 Local_u32Timeout = 0;

	if(UART_u8Flag == IDLE)
	{
		/* UART is now busy */
		UART_u8Flag = BUSY;

		if(copy_pu8Data != NULL)
		{
			/* Wait for data to be received */
			while(GET_BIT(UCSRA, RXC) == 0 && Local_u32Timeout < UART_TIMEOUT)
			{
				Local_u32Timeout++;
			}

			/* check if loop is finished whether data register is empty or timeout happened */
			if(Local_u32Timeout < UART_TIMEOUT)
			{
				/* Receive the data */
				*copy_pu8Data = UDR;

			}
			else
				Local_u8ErrorStatus = UART_E_TIMEOUT;
		}
		else
			Local_u8ErrorStatus = UART_E_PARAM_POINTER;

		/* UART is now idle */
		UART_u8Flag = IDLE;

	}
	else
		Local_u8ErrorStatus = UART_E_BUSY;

	return Local_u8ErrorStatus;
}

u8 UART_u8TransmitStringSynch(u8* copy_pu8Data)
{
	u8 Local_u8ErrorStatus = OK, Local_u8Iterator = 0;
	u32 Local_u32Timeout = 0;

	if(UART_u8Flag == IDLE)
	{
		/* UART is now busy */
		UART_u8Flag = BUSY;

		if(copy_pu8Data != NULL)
		{
			while(copy_pu8Data[Local_u8Iterator] != '\0')
			{
				/* Wait for empty transmit buffer */
				while(GET_BIT(UCSRA, UDRE) == 0 && Local_u32Timeout < UART_TIMEOUT)
				{
					Local_u32Timeout++;
				}

				/* check if loop is finished whether data register is empty or timeout happened */
				if(Local_u32Timeout < UART_TIMEOUT)
				{
					/* Put data into buffer, sends the data */
					UDR = (u8)copy_pu8Data[Local_u8Iterator];
					Local_u8Iterator++;
					Local_u32Timeout = 0;
				}
				else
				{
					Local_u8ErrorStatus = UART_E_TIMEOUT;
					break;
				}
			}

		}
		else
			Local_u8ErrorStatus = UART_E_PARAM_POINTER;

		/* UART is now idle */
		UART_u8Flag = IDLE;

	}
	else
		Local_u8ErrorStatus = UART_E_BUSY;

	return Local_u8ErrorStatus;
}

u8 UART_u8ReceiveStringSynch(u8* copy_pu8Data)
{
	u8 Local_u8ErrorStatus = OK, Local_u8Iterator = 0;
	u32 Local_u32Timeout = 0;

	if(UART_u8Flag == IDLE)
	{
		/* UART is now busy */
		UART_u8Flag = BUSY;

		if(copy_pu8Data != NULL)
		{
			while(1)
			{
				/* Wait for data to be received */
				while(GET_BIT(UCSRA, RXC) == 0 && Local_u32Timeout < UART_TIMEOUT)
				{
					Local_u32Timeout++;
				}

				/* check if loop is finished whether data register is empty or timeout happened */
				if(Local_u32Timeout < UART_TIMEOUT)
				{
					/* Receive the data */
					copy_pu8Data[Local_u8Iterator] = UDR;

					/* check if it's [enter button] */
					if(copy_pu8Data[Local_u8Iterator] == '\r')
					{
						copy_pu8Data[Local_u8Iterator] = '\0';
						break;
					}

					Local_u8Iterator++;

					Local_u32Timeout = 0;
				}
				else
					Local_u8ErrorStatus = UART_E_TIMEOUT;

			}


		}
		else
			Local_u8ErrorStatus = UART_E_PARAM_POINTER;

		/* UART is now idle */
		UART_u8Flag = IDLE;

	}
	else
		Local_u8ErrorStatus = UART_E_BUSY;

	return Local_u8ErrorStatus;
}

u8 UART_u8TransmitStringAsynch(u8* copy_pu8Data, pvFunction_t copy_pvFunc)
{
	u8 Local_u8ErrorStatus = OK, Local_u8Iterator = 0;

	if(UART_u8Flag == IDLE)
	{
		/* UART is now busy */
		UART_u8Flag = BUSY;

		if(copy_pu8Data != NULL && copy_pvFunc != NULL)
		{
			/* store the function */
			UART_CallBack[UART_TXCIE] = copy_pvFunc;

			/*reset the string array first*/
			StringReset(UART_pu8TransmitString, 100);

			/* store the data in string*/
			while(copy_pu8Data[Local_u8Iterator] != '\0')
			{
				UART_pu8TransmitString[Local_u8Iterator] = copy_pu8Data[Local_u8Iterator];
				Local_u8Iterator++;
			}

			/* enable USART Data Register Empty Interrupt*/
			SET_BIT(UCSRB, UDRIE);

			/* enable TX Complete Interrupt Enable*/
			SET_BIT(UCSRB, TXCIE);

		}
		else
			Local_u8ErrorStatus = UART_E_PARAM_POINTER;

	}
	else
		Local_u8ErrorStatus = UART_E_BUSY;

	return Local_u8ErrorStatus;
}

u8 UART_u8ReceiveStringAsynch(u8* copy_pu8Data, pvFunction_t copy_pvFunc)
{
	u8 Local_u8ErrorStatus = OK;

	if(UART_u8Flag == IDLE)
	{
		/* UART is now busy */
		UART_u8Flag = BUSY;


		if(copy_pu8Data != NULL && copy_pvFunc != NULL)
		{
			/* store the function */
			UART_CallBack[UART_RXCIE] = copy_pvFunc;

			/* store the pointer to string*/
			UART_pu8ReceiveString = copy_pu8Data;

			/* enable RX Complete Interrupt*/
			SET_BIT(UCSRB, RXCIE);

		}
		else
			Local_u8ErrorStatus = UART_E_PARAM_POINTER;

	}
	else
		Local_u8ErrorStatus = UART_E_BUSY;

	return Local_u8ErrorStatus;
}

void UART_voidTransmitNumber(s32 copy_s32Number)
{
	u8 Local_u8String[10];

	ConvertToString((char*)Local_u8String, copy_s32Number);
	UART_u8TransmitStringSynch(Local_u8String);

}

/******************************************************************************
 * !comment  :  ISR Function TIMER. 						 			      *
 ******************************************************************************/
/* USART, Rx Complete */
void __vector_13 (void) __attribute__((signal));
void __vector_13 (void)
{
	/* Receive the data */
	UART_pu8ReceiveString[UART_u8counter] = UDR;

	/* check if it's [enter button] */
	if(UART_pu8ReceiveString[UART_u8counter] == '\r')
	{
		UART_pu8ReceiveString[UART_u8counter] = '\0';

		/* reset the counter */
		UART_u8counter = 0;

		/* UART is now idle */
		UART_u8Flag = IDLE;

		/* disable USART Data Register Empty Interrupt */
		CLR_BIT(UCSRB, RXCIE);

		/* Call the notification function */
		if(UART_CallBack[UART_RXCIE] != NULL)
		{
			UART_CallBack[UART_RXCIE]();
		}
	}

	/* Increment the counter */
	UART_u8counter++;

}

/* USART Data Register Empty */
void __vector_14 (void) __attribute__((signal));
void __vector_14 (void)
{
	/* Put data into buffer, sends the data */
	UDR = (u8)UART_pu8TransmitString[UART_u8counter];

	/* Increment the counter */
	UART_u8counter++;

	/* disable USART Data Register Empty Interrupt */
	CLR_BIT(UCSRB, UDRIE);

}

/* USART, Tx Complete */
void __vector_15 (void) __attribute__((signal));
void __vector_15 (void)
{
	/* Put data into buffer, sends the data */
	UDR = (u8)UART_pu8TransmitString[UART_u8counter];

	/* Increment the counter */
	UART_u8counter++;

	/*check if it reached the last element in the string array*/
	if(UART_pu8TransmitString[UART_u8counter] == '\0')
	{
		/* reset the counter */
		UART_u8counter = 0;

		/* UART is now idle */
		UART_u8Flag = IDLE;

		/* disable TX Complete Interrupt */
		CLR_BIT(UCSRB, TXCIE);

		/* Call the notification function */
		if(UART_CallBack[UART_TXCIE] != NULL)
		{
			UART_CallBack[UART_TXCIE]();
		}
	}
}
