/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: TWI_program.c		            ************************/
/***************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "User_Functions.h"

#include "TWI_interface.h"
#include "TWI_private.h"
#include "TWI_config.h"




/********************************				Function Definitions				********************************/
void TWI_voidInit (u8 copy_u8SlaveAddress)
{
	/* bit rate generator */
	u32 Local_u32PreBits = (u32)POW(4, TWI_PRESCALER);
	TWBR = (u8)(((CPU_FREQ / TWI_PRESCALER) - 16UL) / (2UL * Local_u32PreBits));

	if(TWBR < 10)
	{
		TWBR = 10;		//least value should be in the register so that TWI can operate in master mode
	}

	/* TWI Prescaler */
	TWSR &= 0xF8;			//mask the prescaler bits first
	TWSR |= TWI_PRESCALER;

	/* Store the slave address for master */
	TWAR = (copy_u8SlaveAddress << 1);

	/* Enable TWI & Enable Acknowledge Bit*/
	TWCR = (1 << TWEN) | (1 << TWEA);

}

u8 TWI_u8SendStartCondition (void)
{
	u8 Local_u8ErrorStatus = OK;

	/*send start condition & clear the interrupt flag to start the operation then enable TWI*/
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN) | (1 << TWEA);

	/* Wait for TWINT Flag set. This indicates
	 * that the START condition has been
	 * transmitted
	 */
	while(!(TWCR & (1 << TWINT)));

	/* Check if Start Condition is sent */
	if(TWI_MSTR_START != TWI_u8GetStatus())
	{
		Local_u8ErrorStatus = TWI_E_START_CONDITION;
	}

	return Local_u8ErrorStatus;
}

u8 TWI_u8SendRepeatedStartCondition (void)
{
	u8 Local_u8ErrorStatus = OK;

	/*send start condition & clear the interrupt flag to start the operation then enable TWI*/
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN) | (1 << TWEA);

	/* Wait for TWINT Flag set. This indicates
	 * that the Repeated START condition has been
	 * transmitted
	 */
	while(!(TWCR & (1 << TWINT)));

	/* Check if Repeated Start Condition is sent */
	if(TWI_MSTR_RS_START != TWI_u8GetStatus())
	{
		Local_u8ErrorStatus = TWI_E_RSTART_CONDITION;
	}

	return Local_u8ErrorStatus;
}


u8 TWI_u8SendSlaveAddressWrite (u8 copy_u8SlaveAddress)
{
	u8 Local_u8ErrorStatus = OK;

	/*Load SLA_W into TWDR Register. Clear
	 * TWINT bit in TWCR to start transmission
	 * of address*/
	TWDR = (copy_u8SlaveAddress << 1) | TWI_WRITE;
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);

	/* Wait for TWINT Flag set. This indicates
	 * that the SLA+W has been transmitted,
	 * and ACK/NACK has been received.
	 */
	while(!(TWCR & (1 << TWINT)));

	/*Check value of TWI Status Register.
	 * If status different from
	 * MT_SLA_ACK go to ERROR*/
	if(TWI_MSTR_SLA_W_ACK == TWI_u8GetStatus())
	{
		/* Do nothing */
	}
	else if(TWI_MSTR_SLA_W_NACK == TWI_u8GetStatus())
	{
		Local_u8ErrorStatus = TWI_E_SLA_W_NACK;
	}
	else if(TWI_MSTR_ARBT_LOST == TWI_u8GetStatus())
	{
		Local_u8ErrorStatus = TWI_E_ARBT_LOST;
	}
	else
	{
		Local_u8ErrorStatus = TWI_E_SLA_W;
	}

	return Local_u8ErrorStatus;
}

u8 TWI_u8SendSlaveAddressRead (u8 copy_u8SlaveAddress)
{
	u8 Local_u8ErrorStatus = OK;

	/* Load SLA_R into TWDR Register. Clear
	 * TWINT bit in TWCR to start transmission
	 * of address*/
	TWDR = (copy_u8SlaveAddress << 1) | TWI_READ;
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);

	/* Wait for TWINT Flag set. This indicates
	 * that the SLA+R has been transmitted,
	 * and ACK/NACK has been received.
	 */
	while(!(TWCR & (1 << TWINT)));

	/*Check value of TWI Status Register.
	 * If status different from
	 * MT_SLA_ACK go to ERROR*/
	if(TWI_MSTR_SLA_R_ACK == TWI_u8GetStatus())
	{
		/* Do nothing */
	}
	else if(TWI_MSTR_SLA_R_NACK == TWI_u8GetStatus())
	{
		Local_u8ErrorStatus = TWI_E_SLA_R_NACK;
	}
	else if(TWI_MSTR_ARBT_LOST == TWI_u8GetStatus())
	{
		Local_u8ErrorStatus = TWI_E_ARBT_LOST;
	}
	else
	{
		Local_u8ErrorStatus = TWI_E_SLA_R;
	}

	return Local_u8ErrorStatus;
}

u8 TWI_u8MasterSendData (u8 copy_u8Data)
{
	u8 Local_u8ErrorStatus = OK;

	/* Load DATA into TWDR Register. Clear
	 * TWINT bit in TWCR to start transmission
	 * of data */
	TWDR = copy_u8Data;
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);

	/* Wait for TWINT Flag set. This indicates
	 * that the DATA has been transmitted,
	 * and ACK/NACK has been received.
	 */
	while(!(TWCR & (1 << TWINT)));

	/*Check value of TWI Status Register.
	 * If status different from
	 * MT_DATA_ACK go to ERROR*/
	if(TWI_MSTR_DATA_T_ACK == TWI_u8GetStatus())
	{

	}
	else if(TWI_MSTR_DATA_T_NACK == TWI_u8GetStatus())
	{
		Local_u8ErrorStatus = TWI_E_DATA_T_NACK;
	}
	else if(TWI_MSTR_ARBT_LOST == TWI_u8GetStatus())
	{
		Local_u8ErrorStatus = TWI_E_ARBT_LOST;
	}
	else
	{
		Local_u8ErrorStatus = TWI_E_DATA;
	}

	return Local_u8ErrorStatus;


}

u8 TWI_u8MasterReceiveData (u8* copy_pu8Data)
{
	u8 Local_u8ErrorStatus = OK;

	/* Enable Acknowledge Bit. Clear
	 * TWINT bit in TWCR */
	TWCR = (1 << TWINT) | (1 << TWEA) | (1 << TWEN);

	/* Wait for TWINT Flag set. This indicates
	 * that the DATA, general call or device’s own slave address has been received,
	 * and ACK/NACK has been received.
	 */
	while(!(TWCR & (1 << TWINT)));

	/*Check value of TWI Status Register.
	 * If status different from
	 * MT_DATA_ACK go to ERROR*/
	if(TWI_MSTR_DATA_R_ACK == TWI_u8GetStatus())
	{
		*copy_pu8Data = TWDR;
	}
	else if(TWI_MSTR_DATA_R_NACK == TWI_u8GetStatus())
	{
		Local_u8ErrorStatus = TWI_E_DATA_R_NACK;
	}
	else
	{
		Local_u8ErrorStatus = TWI_E_DATA;
	}

	return Local_u8ErrorStatus;

}

void TWI_voidSendStopCondition (void)
{
	/* Send Stop Condition */
	TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);

	/*wait until stop condition is executed*/
	while (TWCR & (1 << TWSTO));
}


u8 TWI_u8GetStatus (void)
{
	return (TWSR & 0xF8);
}


/*****************************				ISR				********************************/
/* Two-wire Serial Interface */
void __vector_19 (void) __attribute__((signal));
void __vector_19 (void)
{

}
