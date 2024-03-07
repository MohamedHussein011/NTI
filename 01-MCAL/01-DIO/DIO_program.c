/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: DIO_program.c		            ************************/
/***************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

/*********************					 APIS PROTOTYPES 					************************/
/*		Init 	 */
void DIO_voidInit(void)
{
	/**********************				Direction					*************************/
	//DDRA
#if ((PORTA_PIN0_DIR == 0 || PORTA_PIN0_DIR == 1) && (PORTA_PIN1_DIR == 0 || PORTA_PIN1_DIR == 1) && \
	 (PORTA_PIN2_DIR == 0 || PORTA_PIN2_DIR == 1) && (PORTA_PIN3_DIR == 0 || PORTA_PIN3_DIR == 1) && \
	 (PORTA_PIN4_DIR == 0 || PORTA_PIN4_DIR == 1) && (PORTA_PIN5_DIR == 0 || PORTA_PIN5_DIR == 1) && \
	 (PORTA_PIN6_DIR == 0 || PORTA_PIN6_DIR == 1) && (PORTA_PIN7_DIR == 0 || PORTA_PIN7_DIR == 1))

	DDRA = PORTA_DIR;
#else
#error "Wrong input for PortA direction pins"
#endif

	//DDRB
#if    ((PORTB_PIN0_DIR == 0 || PORTB_PIN0_DIR == 1) && (PORTB_PIN1_DIR == 0 || PORTB_PIN1_DIR == 1) && \
		(PORTB_PIN2_DIR == 0 || PORTB_PIN2_DIR == 1) && (PORTB_PIN3_DIR == 0 || PORTB_PIN3_DIR == 1) && \
		(PORTB_PIN4_DIR == 0 || PORTB_PIN4_DIR == 1) && (PORTB_PIN5_DIR == 0 || PORTB_PIN5_DIR == 1) && \
		(PORTB_PIN6_DIR == 0 || PORTB_PIN6_DIR == 1) && (PORTB_PIN7_DIR == 0 || PORTB_PIN7_DIR == 1))

	DDRB = PORTB_DIR;
#else
#error "Wrong input for PortB direction pins"
#endif

	//DDRC
#if    ((PORTC_PIN0_DIR == 0 || PORTC_PIN0_DIR == 1) && (PORTC_PIN1_DIR == 0 || PORTC_PIN1_DIR == 1) && \
		(PORTC_PIN2_DIR == 0 || PORTC_PIN2_DIR == 1) && (PORTC_PIN3_DIR == 0 || PORTC_PIN3_DIR == 1) && \
		(PORTC_PIN4_DIR == 0 || PORTC_PIN4_DIR == 1) && (PORTC_PIN5_DIR == 0 || PORTC_PIN5_DIR == 1) && \
		(PORTC_PIN6_DIR == 0 || PORTC_PIN6_DIR == 1) && (PORTC_PIN7_DIR == 0 || PORTC_PIN7_DIR == 1))

	DDRC = PORTC_DIR;
#else
#error "Wrong input for PortC direction pins"
#endif

	//DDRD
#if    ((PORTD_PIN0_DIR == 0 || PORTD_PIN0_DIR == 1) && (PORTD_PIN1_DIR == 0 || PORTD_PIN1_DIR == 1) && \
		(PORTD_PIN2_DIR == 0 || PORTD_PIN2_DIR == 1) && (PORTD_PIN3_DIR == 0 || PORTD_PIN3_DIR == 1) && \
		(PORTD_PIN4_DIR == 0 || PORTD_PIN4_DIR == 1) && (PORTD_PIN5_DIR == 0 || PORTD_PIN5_DIR == 1) && \
		(PORTD_PIN6_DIR == 0 || PORTD_PIN6_DIR == 1) && (PORTD_PIN7_DIR == 0 || PORTD_PIN7_DIR == 1))

	DDRD = PORTD_DIR;
#else
#error "Wrong input for PortD direction pins"
#endif

	/**********************				Value					*************************/
	//PORTA
#if    ((PORTA_PIN0_INITIAL_VALUE == 0 || PORTA_PIN0_INITIAL_VALUE == 1) && (PORTA_PIN1_INITIAL_VALUE == 0 || PORTA_PIN1_INITIAL_VALUE == 1) && \
		(PORTA_PIN2_INITIAL_VALUE == 0 || PORTA_PIN2_INITIAL_VALUE == 1) && (PORTA_PIN3_INITIAL_VALUE == 0 || PORTA_PIN3_INITIAL_VALUE == 1) && \
		(PORTA_PIN4_INITIAL_VALUE == 0 || PORTA_PIN4_INITIAL_VALUE == 1) && (PORTA_PIN5_INITIAL_VALUE == 0 || PORTA_PIN5_INITIAL_VALUE == 1) && \
		(PORTA_PIN6_INITIAL_VALUE == 0 || PORTA_PIN6_INITIAL_VALUE == 1) && (PORTA_PIN7_INITIAL_VALUE == 0 || PORTA_PIN7_INITIAL_VALUE == 1))

	PORTA = PORTA_INITIAL_VALUE;
#else
#error "Wrong input for PortA value pins"
#endif

	//PORTB
#if    ((PORTB_PIN0_INITIAL_VALUE == 0 || PORTB_PIN0_INITIAL_VALUE == 1) && (PORTB_PIN1_INITIAL_VALUE == 0 || PORTB_PIN1_INITIAL_VALUE == 1) && \
		(PORTB_PIN2_INITIAL_VALUE == 0 || PORTB_PIN2_INITIAL_VALUE == 1) && (PORTB_PIN3_INITIAL_VALUE == 0 || PORTB_PIN3_INITIAL_VALUE == 1) && \
		(PORTB_PIN4_INITIAL_VALUE == 0 || PORTB_PIN4_INITIAL_VALUE == 1) && (PORTB_PIN5_INITIAL_VALUE == 0 || PORTB_PIN5_INITIAL_VALUE == 1) && \
		(PORTB_PIN6_INITIAL_VALUE == 0 || PORTB_PIN6_INITIAL_VALUE == 1) && (PORTB_PIN7_INITIAL_VALUE == 0 || PORTB_PIN7_INITIAL_VALUE == 1))

	PORTB = PORTB_INITIAL_VALUE;
#else
#error "Wrong input for PortB value pins"
#endif

	//PORTC
#if    ((PORTC_PIN0_INITIAL_VALUE == 0 || PORTC_PIN0_INITIAL_VALUE == 1) && (PORTC_PIN1_INITIAL_VALUE == 0 || PORTC_PIN1_INITIAL_VALUE == 1) && \
		(PORTC_PIN2_INITIAL_VALUE == 0 || PORTC_PIN2_INITIAL_VALUE == 1) && (PORTC_PIN3_INITIAL_VALUE == 0 || PORTC_PIN3_INITIAL_VALUE == 1) && \
		(PORTC_PIN4_INITIAL_VALUE == 0 || PORTC_PIN4_INITIAL_VALUE == 1) && (PORTC_PIN5_INITIAL_VALUE == 0 || PORTC_PIN5_INITIAL_VALUE == 1) && \
		(PORTC_PIN6_INITIAL_VALUE == 0 || PORTC_PIN6_INITIAL_VALUE == 1) && (PORTC_PIN7_INITIAL_VALUE == 0 || PORTC_PIN7_INITIAL_VALUE == 1))

	PORTC = PORTC_INITIAL_VALUE;
#else
#error "Wrong input for PortC value pins"
#endif

	//PORTD
#if    ((PORTD_PIN0_INITIAL_VALUE == 0 || PORTD_PIN0_INITIAL_VALUE == 1) && (PORTD_PIN1_INITIAL_VALUE == 0 || PORTD_PIN1_INITIAL_VALUE == 1) && \
		(PORTD_PIN2_INITIAL_VALUE == 0 || PORTD_PIN2_INITIAL_VALUE == 1) && (PORTD_PIN3_INITIAL_VALUE == 0 || PORTD_PIN3_INITIAL_VALUE == 1) && \
		(PORTD_PIN4_INITIAL_VALUE == 0 || PORTD_PIN4_INITIAL_VALUE == 1) && (PORTD_PIN5_INITIAL_VALUE == 0 || PORTD_PIN5_INITIAL_VALUE == 1) && \
		(PORTD_PIN6_INITIAL_VALUE == 0 || PORTD_PIN6_INITIAL_VALUE == 1) && (PORTD_PIN7_INITIAL_VALUE == 0 || PORTD_PIN7_INITIAL_VALUE == 1))

	PORTD = PORTD_INITIAL_VALUE;
#else
#error "Wrong input for PortD value pins"
#endif

}

/* Pin Apis */
u8 DIO_u8SetPinDirection            (u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinDirection)
{
	u8 Local_u8ErrorState = OK;

	if(copy_u8PortId >= DIO_PORTA && copy_u8PortId <= DIO_PORTD)
	{
		if(copy_u8PinId >= DIO_PIN0 && copy_u8PinId <= DIO_PIN7)
		{
			switch(copy_u8PortId)
			{
			case DIO_PORTA: if(copy_u8PinDirection == DIO_PIN_OUTPUT)
			{
				SET_BIT(DDRA, copy_u8PinId);
			}
			else if(copy_u8PinDirection == DIO_PIN_INPUT)
			{
				CLR_BIT(DDRA, copy_u8PinId);
			}
			else
				Local_u8ErrorState = DIO_E_PARAM_INVALID_PIN_DIR;

			break;

			case DIO_PORTB: if(copy_u8PinDirection == DIO_PIN_OUTPUT)
			{
				SET_BIT(DDRB, copy_u8PinId);
			}
			else if(copy_u8PinDirection == DIO_PIN_INPUT)
			{
				CLR_BIT(DDRB, copy_u8PinId);
			}
			else
				Local_u8ErrorState = DIO_E_PARAM_INVALID_PIN_DIR;

			break;

			case DIO_PORTC: if(copy_u8PinDirection == DIO_PIN_OUTPUT)
			{
				SET_BIT(DDRC, copy_u8PinId);
			}
			else if(copy_u8PinDirection == DIO_PIN_INPUT)
			{
				CLR_BIT(DDRC, copy_u8PinId);
			}
			else
				Local_u8ErrorState = DIO_E_PARAM_INVALID_PIN_DIR;

			break;

			case DIO_PORTD: if(copy_u8PinDirection == DIO_PIN_OUTPUT)
			{
				SET_BIT(DDRD, copy_u8PinId);
			}
			else if(copy_u8PinDirection == DIO_PIN_INPUT)
			{
				CLR_BIT(DDRD, copy_u8PinId);
			}
			else
				Local_u8ErrorState = DIO_E_PARAM_INVALID_PIN_DIR;

			break;


			}
		}
		else
			Local_u8ErrorState = DIO_E_PARAM_INVALID_PIN_ID;
	}
	else
		Local_u8ErrorState = DIO_E_PARAM_INVALID_PORT_ID;

	return Local_u8ErrorState;

}

u8 DIO_u8SetPinValue                (u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinValue)
{
	u8 Local_u8ErrorState = OK;

	if(copy_u8PortId >= DIO_PORTA && copy_u8PortId <= DIO_PORTD)
	{
		if(copy_u8PinId >= DIO_PIN0 && copy_u8PinId <= DIO_PIN7)
		{
			switch(copy_u8PortId)
			{
			case DIO_PORTA: if(copy_u8PinValue == DIO_PIN_HIGH)
			{
				SET_BIT(PORTA, copy_u8PinId);
			}
			else if(copy_u8PinValue == DIO_PIN_LOW)
			{
				CLR_BIT(PORTA, copy_u8PinId);
			}
			else
				Local_u8ErrorState = DIO_E_PARAM_INVALID_PIN_VAL;

			break;

			case DIO_PORTB: if(copy_u8PinValue == DIO_PIN_HIGH)
			{
				SET_BIT(PORTB, copy_u8PinId);
			}
			else if(copy_u8PinValue == DIO_PIN_LOW)
			{
				CLR_BIT(PORTB, copy_u8PinId);
			}
			else
				Local_u8ErrorState = DIO_E_PARAM_INVALID_PIN_VAL;

			break;

			case DIO_PORTC: if(copy_u8PinValue == DIO_PIN_HIGH)
			{
				SET_BIT(PORTC, copy_u8PinId);
			}
			else if(copy_u8PinValue == DIO_PIN_LOW)
			{
				CLR_BIT(PORTC, copy_u8PinId);
			}
			else
				Local_u8ErrorState = DIO_E_PARAM_INVALID_PIN_VAL;

			break;

			case DIO_PORTD: if(copy_u8PinValue == DIO_PIN_HIGH)
			{
				SET_BIT(PORTD, copy_u8PinId);
			}
			else if(copy_u8PinValue == DIO_PIN_LOW)
			{
				CLR_BIT(PORTD, copy_u8PinId);
			}
			else
				Local_u8ErrorState = DIO_E_PARAM_INVALID_PIN_VAL;

			break;


			}
		}
		else
			Local_u8ErrorState = DIO_E_PARAM_INVALID_PIN_ID;
	}
	else
		Local_u8ErrorState = DIO_E_PARAM_INVALID_PORT_ID;

	return Local_u8ErrorState;
}
u8 DIO_u8GetPinValue                (u8 copy_u8PortId, u8 copy_u8PinId, u8* copy_pu8PinValue)
{
	u8 Local_u8ErrorState = OK;

	if(copy_u8PortId >= DIO_PORTA && copy_u8PortId <= DIO_PORTD)
	{
		if(copy_u8PinId >= DIO_PIN0 && copy_u8PinId <= DIO_PIN7)
		{
			if(copy_pu8PinValue != NULL)
			{
				switch(copy_u8PortId)
				{
				case DIO_PORTA: *copy_pu8PinValue = GET_BIT(PINA, copy_u8PinId);		break;

				case DIO_PORTB: *copy_pu8PinValue = GET_BIT(PINB, copy_u8PinId);		break;

				case DIO_PORTC: *copy_pu8PinValue = GET_BIT(PINC, copy_u8PinId);		break;

				case DIO_PORTD: *copy_pu8PinValue = GET_BIT(PIND, copy_u8PinId);		break;
				}
			}
			else
				Local_u8ErrorState = DIO_E_PARAM_POINTER;
		}
		else
			Local_u8ErrorState = DIO_E_PARAM_INVALID_PIN_ID;
	}
	else
		Local_u8ErrorState = DIO_E_PARAM_INVALID_PORT_ID;

	return Local_u8ErrorState;
}

u8 DIO_u8TogglePinValue             (u8 copy_u8PortId, u8 copy_u8PinId)
{
	u8 Local_u8ErrorState = OK;

	if(copy_u8PortId >= DIO_PORTA && copy_u8PortId <= DIO_PORTD)
	{
		if(copy_u8PinId >= DIO_PIN0 && copy_u8PinId <= DIO_PIN7)
		{
			switch(copy_u8PortId)
			{
			case DIO_PORTA: TOG_BIT(PORTA, copy_u8PinId);		break;

			case DIO_PORTB: TOG_BIT(PORTB, copy_u8PinId);		break;

			case DIO_PORTC: TOG_BIT(PORTC, copy_u8PinId);		break;

			case DIO_PORTD: TOG_BIT(PORTD, copy_u8PinId);		break;
			}
		}
		else
			Local_u8ErrorState = DIO_E_PARAM_INVALID_PIN_ID;
	}
	else
		Local_u8ErrorState = DIO_E_PARAM_INVALID_PORT_ID;

	return Local_u8ErrorState;
}
u8 DIO_u8ActivePinInPullUpResistance(u8 copy_u8PortId, u8 copy_u8PinId)
{
	u8 Local_u8ErrorState = OK;

	if(copy_u8PortId >= DIO_PORTA && copy_u8PortId <= DIO_PORTD)
	{
		if(copy_u8PinId >= DIO_PIN0 && copy_u8PinId <= DIO_PIN7)
		{
			switch(copy_u8PortId)
			{
			case DIO_PORTA: CLR_BIT(DDRA, copy_u8PinId);		SET_BIT(PORTA,copy_u8PinId);		break;

			case DIO_PORTB: CLR_BIT(DDRB, copy_u8PinId);		SET_BIT(PORTB,copy_u8PinId);		break;

			case DIO_PORTC: CLR_BIT(DDRC, copy_u8PinId);		SET_BIT(PORTC,copy_u8PinId);		break;

			case DIO_PORTD: CLR_BIT(DDRD, copy_u8PinId);		SET_BIT(PORTD,copy_u8PinId);		break;
			}
		}
		else
			Local_u8ErrorState = DIO_E_PARAM_INVALID_PIN_ID;
	}
	else
		Local_u8ErrorState = DIO_E_PARAM_INVALID_PORT_ID;

	return Local_u8ErrorState;
}


/* Port Apis */
u8 DIO_u8SetPortDirection            (u8 copy_u8PortId, u8 copy_u8PortDirection)
{
	u8 Local_u8ErrorState = OK;

	if(copy_u8PortId >= DIO_PORTA && copy_u8PortId <= DIO_PORTD)
	{
		if(copy_u8PortDirection == DIO_PORT_INPUT || copy_u8PortDirection == DIO_PORT_OUTPUT)
		{
			switch(copy_u8PortId)
			{
			case DIO_PORTA: DDRA = copy_u8PortDirection;		break;

			case DIO_PORTB: DDRB = copy_u8PortDirection;		break;

			case DIO_PORTC: DDRC = copy_u8PortDirection;		break;

			case DIO_PORTD: DDRD = copy_u8PortDirection;		break;
			}
		}
		else
			Local_u8ErrorState = DIO_E_PARAM_INVALID_PORT_DIR;
	}
	else
		Local_u8ErrorState = DIO_E_PARAM_INVALID_PORT_ID;

	return Local_u8ErrorState;
}

u8 DIO_u8SetPortValue                (u8 copy_u8PortId, u8 copy_u8PortValue)
{
	u8 Local_u8ErrorState = OK;

	if(copy_u8PortId >= DIO_PORTA && copy_u8PortId <= DIO_PORTD)
	{
		if(copy_u8PortValue >= DIO_PORT_LOW && copy_u8PortValue <= DIO_PORT_HIGH)
		{
			switch(copy_u8PortId)
			{
			case DIO_PORTA: PORTA = copy_u8PortValue;		break;

			case DIO_PORTB: PORTB = copy_u8PortValue;		break;

			case DIO_PORTC: PORTC = copy_u8PortValue;		break;

			case DIO_PORTD: PORTD = copy_u8PortValue;		break;
			}
		}
		else
			Local_u8ErrorState = DIO_E_PARAM_INVALID_PORT_DIR;
	}
	else
		Local_u8ErrorState = DIO_E_PARAM_INVALID_PORT_ID;

	return Local_u8ErrorState;
}

u8 DIO_u8GetPortValue                (u8 copy_u8PortId, u8* copy_pu8PortValue)
{
	u8 Local_u8ErrorState = OK;

	if(copy_u8PortId >= DIO_PORTA && copy_u8PortId <= DIO_PORTD)
	{
		if(copy_pu8PortValue != NULL)
		{
			switch(copy_u8PortId)
			{
			case DIO_PORTA: *copy_pu8PortValue = PINA;		break;

			case DIO_PORTB: *copy_pu8PortValue = PINB;		break;

			case DIO_PORTC: *copy_pu8PortValue = PINC;		break;

			case DIO_PORTD: *copy_pu8PortValue = PIND;		break;
			}
		}
		else
			Local_u8ErrorState = DIO_E_PARAM_POINTER;
	}
	else
		Local_u8ErrorState = DIO_E_PARAM_INVALID_PORT_ID;

	return Local_u8ErrorState;
}

u8 DIO_u8TogglePortValue             (u8 copy_u8PortId)
{
	u8 Local_u8ErrorState = OK;

	if(copy_u8PortId >= DIO_PORTA && copy_u8PortId <= DIO_PORTD)
	{
		switch(copy_u8PortId)
		{
		case DIO_PORTA: PORTA ^= 0xFF;		break;

		case DIO_PORTB: PORTB ^= 0xFF;		break;

		case DIO_PORTC: PORTC ^= 0xFF;		break;

		case DIO_PORTD: PORTD ^= 0xFF;		break;
		}
	}
	else
		Local_u8ErrorState = DIO_E_PARAM_INVALID_PORT_ID;

	return Local_u8ErrorState;
}

u8 DIO_u8ActivePortInPullUpResistance(u8 copy_u8PortId)
{
	u8 Local_u8ErrorState = OK;

	if(copy_u8PortId >= DIO_PORTA && copy_u8PortId <= DIO_PORTD)
	{
		switch(copy_u8PortId)
		{
		case DIO_PORTA: DDRA = DIO_PORT_LOW;		PORTA = DIO_PORT_HIGH;		break;

		case DIO_PORTB: DDRB = DIO_PORT_LOW;		PORTB = DIO_PORT_HIGH;		break;

		case DIO_PORTC: DDRC = DIO_PORT_LOW;		PORTC = DIO_PORT_HIGH;		break;

		case DIO_PORTD: DDRD = DIO_PORT_LOW;		PORTD = DIO_PORT_HIGH;		break;
		}
	}
	else
		Local_u8ErrorState = DIO_E_PARAM_INVALID_PORT_ID;

	return Local_u8ErrorState;
}
