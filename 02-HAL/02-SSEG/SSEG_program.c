/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: SSEG_program.c		            ************************/
/***************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "SSEG_interface.h"
#include "SSEG_config.h"

/* Numbers to be printed on ordinary SSD */
static u8 SEV_SEG[10] = { 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F };

void SSEG_voidInit(void)
{
#if SSEG_USED_BITS == SSEG_8BITS
	//initialize pins direction
	DIO_u8SetPinDirection(SSEG_PORT_PIN0,SSEG_PIN0,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(SSEG_PORT_PIN1,SSEG_PIN1,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(SSEG_PORT_PIN2,SSEG_PIN2,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(SSEG_PORT_PIN3,SSEG_PIN3,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(SSEG_PORT_PIN4,SSEG_PIN4,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(SSEG_PORT_PIN5,SSEG_PIN5,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(SSEG_PORT_PIN6,SSEG_PIN6,DIO_PIN_OUTPUT);

	//COM
	DIO_u8SetPinDirection(SSEG_COM_PORT,SSEG_COM_PIN,DIO_PIN_OUTPUT);

#elif SSEG_USED_BITS == SSEG_4BITS_BCD
	//BCD PINS
	DIO_u8SetPinDirection(BCD_SSEG_PORT_PINA,BCD_SSEG_PINA,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(BCD_SSEG_PORT_PINB,BCD_SSEG_PINB,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(BCD_SSEG_PORT_PINC,BCD_SSEG_PINC,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(BCD_SSEG_PORT_PIND,BCD_SSEG_PIND,DIO_PIN_OUTPUT);

	//COM PIN
	DIO_u8SetPinDirection(SSEG_BCD_PORT_COM,SSEG_BCD_PIN_COM,DIO_PIN_OUTPUT);

#else
#error "Wrong seven segment selection"

#endif
}

u8 SSEG_u8Init (u8* copy_pu8Ports, u8* copy_pu8Pins, u8 copy_u8SSEG)
{
	u8 Local_u8ErrorState = OK;
	u8 k=0;
	if(copy_u8SSEG == SSEG_8BITS)
		k = 8;
	else if(copy_u8SSEG == SSEG_4BITS_BCD)
		k = 5;

	if(copy_pu8Pins == NULL || copy_pu8Ports == NULL)
		Local_u8ErrorState = SSEG_E_PARAM_POINTER;
	else
	{
		for(u8 i=0; i< k; i++)
		{
			if((copy_pu8Ports[i] < DIO_PORTA || copy_pu8Ports[i] > DIO_PORTD) || (copy_pu8Pins[i] < DIO_PIN0 || copy_pu8Pins[i] > DIO_PIN7))
				Local_u8ErrorState = SSEG_E_PARAM_INVALID_PORT_PIN;
			else
			{
				DIO_u8SetPinDirection(copy_pu8Ports[i],copy_pu8Pins[i], DIO_PIN_OUTPUT);
			}
		}
	}

	return Local_u8ErrorState;
}

u8 SSEG_u8WriteNumber (u8 copy_u8number)
{
	u8 Local_u8ErrorState = OK;

	if(copy_u8number < 0 || copy_u8number > 9 || (copy_u8number != (u8)copy_u8number))
		Local_u8ErrorState = SSEG_E_PARAM_INVALID_NUMBER;
	else
	{
#if SSEG_USED_BITS == SSEG_8BITS
#if SSEG_TYPE == ANODE
		//COM
		DIO_u8SetPinValue(SSEG_COM_PORT,SSEG_COM_PIN,DIO_PIN_HIGH);

		DIO_u8SetPinValue(SSEG_PORT_PIN0,SSEG_PIN0,!(SEV_SEG[copy_u8number] & 1));
		DIO_u8SetPinValue(SSEG_PORT_PIN1,SSEG_PIN1,!((SEV_SEG[copy_u8number]>>1)&1));
		DIO_u8SetPinValue(SSEG_PORT_PIN2,SSEG_PIN2,!((SEV_SEG[copy_u8number]>>2)&1));
		DIO_u8SetPinValue(SSEG_PORT_PIN3,SSEG_PIN3,!((SEV_SEG[copy_u8number]>>3)&1));
		DIO_u8SetPinValue(SSEG_PORT_PIN4,SSEG_PIN4,!((SEV_SEG[copy_u8number]>>4)&1));
		DIO_u8SetPinValue(SSEG_PORT_PIN5,SSEG_PIN5,!((SEV_SEG[copy_u8number]>>5)&1));
		DIO_u8SetPinValue(SSEG_PORT_PIN6,SSEG_PIN6,!((SEV_SEG[copy_u8number]>>6)&1));

#elif SSEG_TYPE == CATHODE
		//COM
		DIO_u8SetPinValue(SSEG_COM_PORT,SSEG_COM_PIN,DIO_PIN_LOW);

		DIO_u8SetPinValue(SSEG_PORT_PIN0,SSEG_PIN0,SEV_SEG[copy_u8number] & 1);
		DIO_u8SetPinValue(SSEG_PORT_PIN1,SSEG_PIN1,(SEV_SEG[copy_u8number]>>1)&1);
		DIO_u8SetPinValue(SSEG_PORT_PIN2,SSEG_PIN2,(SEV_SEG[copy_u8number]>>2)&1);
		DIO_u8SetPinValue(SSEG_PORT_PIN3,SSEG_PIN3,(SEV_SEG[copy_u8number]>>3)&1);
		DIO_u8SetPinValue(SSEG_PORT_PIN4,SSEG_PIN4,(SEV_SEG[copy_u8number]>>4)&1);
		DIO_u8SetPinValue(SSEG_PORT_PIN5,SSEG_PIN5,(SEV_SEG[copy_u8number]>>5)&1);
		DIO_u8SetPinValue(SSEG_PORT_PIN6,SSEG_PIN6,(SEV_SEG[copy_u8number]>>6)&1);

#else
#error "Wrong seven segment type selection"
#endif

#elif SSEG_USED_BITS == SSEG_4BITS_BCD

#if SSEG_TYPE == ANODE
		//COM
		DIO_u8SetPinValue(SSEG_BCD_PORT_COM,SSEG_BCD_PIN_COM,DIO_PIN_HIGH);

		DIO_u8SetPinValue(BCD_SSEG_PORT_PINA,BCD_SSEG_PINA,!(copy_u8number & 1));
		DIO_u8SetPinValue(BCD_SSEG_PORT_PINB,BCD_SSEG_PINB,!((copy_u8number>>1)&1));
		DIO_u8SetPinValue(BCD_SSEG_PORT_PINC,BCD_SSEG_PINC,!((copy_u8number>>2)&1));
		DIO_u8SetPinValue(BCD_SSEG_PORT_PIND,BCD_SSEG_PIND,!((copy_u8number>>3)&1));
#elif SSEG_TYPE == CATHODE
		//COM
		DIO_u8SetPinValue(SSEG_BCD_PORT_COM,SSEG_BCD_PIN_COM,DIO_PIN_LOW);

		DIO_u8SetPinValue(BCD_SSEG_PORT_PINA,BCD_SSEG_PINA,copy_u8number & 1);
		DIO_u8SetPinValue(BCD_SSEG_PORT_PINB,BCD_SSEG_PINB,(copy_u8number>>1)&1);
		DIO_u8SetPinValue(BCD_SSEG_PORT_PINC,BCD_SSEG_PINC,(copy_u8number>>2)&1);
		DIO_u8SetPinValue(BCD_SSEG_PORT_PIND,BCD_SSEG_PIND,(copy_u8number>>3)&1);

#else
#error "Wrong seven segment type selection"
#endif

#else
#error "Wrong seven segment selection"
#endif
	}

	return Local_u8ErrorState;

	/*	for(int b=0; b<10; b++)
	{
		for(int a=0; a<10; a++)
		{
			for(int j=0; j<10; j++)
			{
				for(int k=0; k<10; k++)
				{
					for(int i=0; i<20; i++)
					{
						//1
						DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_LOW);
						DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_HIGH);
						DIO_u8SetPinValue(DIO_PORTB,DIO_PIN5,DIO_PIN_HIGH);
						DIO_u8SetPinValue(DIO_PORTB,DIO_PIN6,DIO_PIN_HIGH);

						DIO_u8SetPinValue(DIO_PORTB,DIO_PIN0,k & 1);
						DIO_u8SetPinValue(DIO_PORTB,DIO_PIN1,(k>>1)&1);
						DIO_u8SetPinValue(DIO_PORTB,DIO_PIN2,(k>>2)&1);
						DIO_u8SetPinValue(DIO_PORTB,DIO_PIN4,(k>>3)&1);

						_delay_ms(2);
						//2
						DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_HIGH);
						DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_LOW);
						DIO_u8SetPinValue(DIO_PORTB,DIO_PIN5,DIO_PIN_HIGH);
						DIO_u8SetPinValue(DIO_PORTB,DIO_PIN6,DIO_PIN_HIGH);

						DIO_u8SetPinValue(DIO_PORTB,DIO_PIN0,j & 1);
						DIO_u8SetPinValue(DIO_PORTB,DIO_PIN1,(j>>1)&1);
						DIO_u8SetPinValue(DIO_PORTB,DIO_PIN2,(j>>2)&1);
						DIO_u8SetPinValue(DIO_PORTB,DIO_PIN4,(j>>3)&1);
						_delay_ms(2);

						//3
						DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_HIGH);
						DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_HIGH);
						DIO_u8SetPinValue(DIO_PORTB,DIO_PIN5,DIO_PIN_LOW);
						DIO_u8SetPinValue(DIO_PORTB,DIO_PIN6,DIO_PIN_HIGH);

						DIO_u8SetPinValue(DIO_PORTB,DIO_PIN0,a & 1);
						DIO_u8SetPinValue(DIO_PORTB,DIO_PIN1,(a>>1)&1);
						DIO_u8SetPinValue(DIO_PORTB,DIO_PIN2,(a>>2)&1);
						DIO_u8SetPinValue(DIO_PORTB,DIO_PIN4,(a>>3)&1);
						_delay_ms(2);

						//4
						DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_HIGH);
						DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_HIGH);
						DIO_u8SetPinValue(DIO_PORTB,DIO_PIN5,DIO_PIN_HIGH);
						DIO_u8SetPinValue(DIO_PORTB,DIO_PIN6,DIO_PIN_LOW);

						DIO_u8SetPinValue(DIO_PORTB,DIO_PIN0,b & 1);
						DIO_u8SetPinValue(DIO_PORTB,DIO_PIN1,(b>>1)&1);
						DIO_u8SetPinValue(DIO_PORTB,DIO_PIN2,(b>>2)&1);
						DIO_u8SetPinValue(DIO_PORTB,DIO_PIN4,(b>>3)&1);
						_delay_ms(2);
					}
				}
			}
		}
	}*/
}

u8 SSEG_u8WriteNumber8Bit (u8* copy_pu8Ports, u8* copy_pu8Pins, u8 copy_u8Type, u8 copy_u8number)
{
	u8 Local_u8ErrorState = OK;

	if(copy_pu8Pins == NULL || copy_pu8Ports == NULL)
		Local_u8ErrorState = SSEG_E_PARAM_POINTER;
	else
	{
		if(copy_u8Type == ANODE)
		{
			DIO_u8SetPinValue(copy_pu8Ports[7],copy_pu8Pins[7], DIO_PIN_HIGH);
			for(u8 i=0; i< 8; i++)
			{
				if((copy_pu8Ports[i] < DIO_PORTA || copy_pu8Ports[i] > DIO_PORTD) || (copy_pu8Pins[i] < DIO_PIN0 || copy_pu8Pins[i] > DIO_PIN7))
					Local_u8ErrorState = SSEG_E_PARAM_INVALID_PORT_PIN;
				else
				{
					DIO_u8SetPinValue(copy_pu8Ports[i],copy_pu8Pins[i], !((SEV_SEG[copy_u8number]>>i)&1));
				}
			}
		}
		else if(copy_u8Type == CATHODE)
		{
			DIO_u8SetPinValue(copy_pu8Ports[7],copy_pu8Pins[7], DIO_PIN_LOW);
			for(u8 i=0; i< 8; i++)
			{
				if((copy_pu8Ports[i] < DIO_PORTA || copy_pu8Ports[i] > DIO_PORTD) || (copy_pu8Pins[i] < DIO_PIN0 || copy_pu8Pins[i] > DIO_PIN7))
					Local_u8ErrorState = SSEG_E_PARAM_INVALID_PORT_PIN;
				else
				{
					DIO_u8SetPinValue(copy_pu8Ports[i],copy_pu8Pins[i], ((SEV_SEG[copy_u8number]>>i)&1));
				}
			}
		}
		else
			Local_u8ErrorState = SSEG_E_PARAM_INVALID_TYPE;
	}

	return Local_u8ErrorState;
}

u8 SSEG_u8WriteNumber4BitBCD (u8* copy_pu8Ports, u8* copy_pu8Pins, u8 copy_u8Type, u8 copy_u8number)
{
	u8 Local_u8ErrorState = OK;

	if(copy_pu8Pins == NULL || copy_pu8Ports == NULL)
		Local_u8ErrorState = SSEG_E_PARAM_POINTER;
	else
	{
		if(copy_u8Type == ANODE)
		{
			DIO_u8SetPinValue(copy_pu8Ports[7],copy_pu8Pins[7], DIO_PIN_HIGH);
			for(u8 i=0; i< 5; i++)
			{
				if((copy_pu8Ports[i] < DIO_PORTA || copy_pu8Ports[i] > DIO_PORTD) || (copy_pu8Pins[i] < DIO_PIN0 || copy_pu8Pins[i] > DIO_PIN7))
					Local_u8ErrorState = SSEG_E_PARAM_INVALID_PORT_PIN;
				else
				{
					DIO_u8SetPinValue(copy_pu8Ports[i],copy_pu8Pins[i], !((copy_u8number>>i)&1));
				}
			}
		}
		else if(copy_u8Type == CATHODE)
		{
			DIO_u8SetPinValue(copy_pu8Ports[7],copy_pu8Pins[7], DIO_PIN_LOW);
			for(u8 i=0; i< 5; i++)
			{
				if((copy_pu8Ports[i] < DIO_PORTA || copy_pu8Ports[i] > DIO_PORTD) || (copy_pu8Pins[i] < DIO_PIN0 || copy_pu8Pins[i] > DIO_PIN7))
					Local_u8ErrorState = SSEG_E_PARAM_INVALID_PORT_PIN;
				else
				{
					DIO_u8SetPinValue(copy_pu8Ports[i],copy_pu8Pins[i], ((copy_u8number>>i)&1));
				}
			}
		}
		else
			Local_u8ErrorState = SSEG_E_PARAM_INVALID_TYPE;
	}

	return Local_u8ErrorState;
}

u8 SSEG_u8OFF (u8 copy_u8ComPort, u8 copy_u8ComPin, u8 copy_u8Type)
{
	u8 Local_u8ErrorState = OK;

	if(copy_u8ComPort < DIO_PORTA || copy_u8ComPort > DIO_PORTD || copy_u8ComPin < DIO_PIN0 || copy_u8ComPin > DIO_PIN7)
		Local_u8ErrorState = SSEG_E_PARAM_INVALID_PORT_PIN;
	else
	{
		if(copy_u8Type == ANODE)
		{
			DIO_u8SetPinValue(copy_u8ComPort,copy_u8ComPin, DIO_PIN_LOW);
		}
		else if(copy_u8Type == CATHODE)
		{
			DIO_u8SetPinValue(copy_u8ComPort,copy_u8ComPin, DIO_PIN_HIGH);
		}
		else
			Local_u8ErrorState = SSEG_E_PARAM_INVALID_TYPE;
	}

	return Local_u8ErrorState;
}
