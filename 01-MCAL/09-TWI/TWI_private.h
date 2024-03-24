/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: TWI_private.h	                ************************/
/***************************************************************************************/

#ifndef TWI_PRIVATE_H
#define TWI_PRIVATE_H

/***********************				Registers						************************/
/******************************************************************************
 * !comment : TWI Bit Rate Register (TWBR) & Bits Definition.                     *
 ******************************************************************************/
#define TWBR    *((volatile u8*)0x20)

/******************************************************************************
 * !comment : TWI Control Register (TWCR) & Bits Definition.                     *
 ******************************************************************************/
#define TWCR    *((volatile u8*)0x56)
#define TWINT    7          //TWI Interrupt Flag
#define TWEA     6          //TWI Enable Acknowledge Bit
#define TWSTA    5          //TWI START Condition Bit
#define TWSTO    4          //TWI STOP Condition Bit
#define TWWC     3          //TWI Write Collision Flag
#define TWEN     2          //TWI Enable Bit
/* Bit 1 - Reserved for future use */
#define TWIE     0          //TWI Interrupt Enable

/******************************************************************************
 * !comment : TWI Status Register (TWSR) & Bits Definition.                     *
 ******************************************************************************/
#define TWSR    *((volatile u8*)0x21)
#define TWS7    7          //TWI Status
#define TWS6    6          //TWI Status
#define TWS5    5          //TWI Status
#define TWS4    4          //TWI Status
#define TWS3    3          //TWI Status
/* Bit 2 - Reserved for future use */
#define TWPS1   1          //TWI Prescaler Bits
#define TWPS0   0          //TWI Prescaler Bits

/******************************************************************************
 * !comment : TWI Data Register (TWDR) Definition.                     *
 ******************************************************************************/
#define TWDR    *((volatile u8*)0x23)

/******************************************************************************
 * !comment : TWI (Slave) Address Register (TWAR) Definition.                     *
 ******************************************************************************/
#define TWAR    *((volatile u8*)0x22)
#define TWGCE   0    //TWI General Call Recognition Enable Bit



/****************************			Status Codes				*****************************/
/* Status Codes for Master Transmitter Mode */
#define TWI_MSTR_START					0x08		//A START condition has been transmitted
#define TWI_MSTR_RS_START				0x10		//A repeated START condition has been transmitted
#define TWI_MSTR_SLA_W_ACK				0x18		//SLA+W has been transmitted; ACK has been received
#define TWI_MSTR_SLA_W_NACK				0x20		//SLA+W has been transmitted; NOT ACK has been received
#define TWI_MSTR_DATA_T_ACK				0x28		//Data byte has been transmitted; ACK has been received
#define TWI_MSTR_DATA_T_NACK			0x30		//Data byte has been transmitted; NOT ACK has been received
#define TWI_MSTR_ARBT_LOST				0x38		//Arbitration lost in SLA+W or data bytes / Arbitration lost in SLA+R or NOT ACK bit
#define TWI_MSTR_SLA_R_ACK				0x40		//SLA+W has been transmitted; ACK has been received
#define TWI_MSTR_SLA_R_NACK				0x48		//SLA+W has been transmitted; NOT ACK has been received
#define TWI_MSTR_DATA_R_ACK				0x50		//Data byte has been received; ACK has been returned
#define TWI_MSTR_DATA_R_NACK			0x58		//Data byte has been received; NOT ACK has been returned


/* TWI W/R */
#define TWI_WRITE					0x00
#define TWI_READ					0x01



#endif
