/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: TWI_interface.h	            ************************/
/***************************************************************************************/


#ifndef TWI_INTERFACE_H
#define TWI_INTERFACE_H


/*********************************		Error classification	******************************/
//failed to send start condition
#define TWI_E_START_CONDITION							0x0A
//failed to send repeated start condition
#define TWI_E_RSTART_CONDITION							0x0B
//slave address with W is sent & NACK is received
#define TWI_E_SLA_W_NACK								0x0C
//failed to send slave address with W
#define TWI_E_SLA_W										0x0D
//slave address with R is sent & NACK is received
#define TWI_E_SLA_R_NACK								0x0E
//failed to send slave address with R
#define TWI_E_SLA_R										0x0F
//Arbitration lost in SLA+W/R or data bytes
#define TWI_E_ARBT_LOST									0x10
//Data is sent & NACK is received
#define TWI_E_DATA_T_NACK								0x11
//Data is received & NACK is received
#define TWI_E_DATA_R_NACK								0x12
//failed to send or receive DATA
#define TWI_E_DATA										0x13


/*********************************		MACROs	******************************/
/* TWI Prescaler */
#define TWI_PRESCALER_1						0
#define TWI_PRESCALER_4						1
#define TWI_PRESCALER_16					2
#define TWI_PRESCALER_64					3


/********************************				Function Prototypes				********************************/

/* @brief		shall initialize TWI with the configuration in TWI_config.h
* @paramin		copy_u8SlaveAddress / 7 bit address for master in multi master system
* @paramout		none
* @retval		none
*/
void TWI_voidInit (u8 copy_u8SlaveAddress);

/* @brief		shall send start condition
* @paramin		none
* @paramout		none
* @retval		error status
*/
u8 TWI_u8SendStartCondition (void);

/* @brief		shall repeated send start condition
* @paramin		none
* @paramout		none
* @retval		error status
*/
u8 TWI_u8SendRepeatedStartCondition (void);

/* @brief		shall send slave address with write operation
* @paramin		copy_u8SlaveAddress / slave address
* @paramout		none
* @retval		error status
*/
u8 TWI_u8SendSlaveAddressWrite (u8 copy_u8SlaveAddress);

/* @brief		shall send slave address with read operation
* @paramin		copy_u8SlaveAddress / slave address
* @paramout		none
* @retval		error status
*/
u8 TWI_u8SendSlaveAddressRead (u8 copy_u8SlaveAddress);

/* @brief		shall send Data
* @paramin		copy_u8Data / data to be sent
* @paramout		none
* @retval		error status
*/
u8 TWI_u8MasterSendData (u8 copy_u8Data);

/* @brief		shall receive Data
* @paramin		none
* @paramout		copy_pu8Data / pointer to hold data to be received
* @retval		error status
*/
u8 TWI_u8MasterReceiveData (u8* copy_pu8Data);

/* @brief		shall return status value of last operation
* @paramin		none
* @paramout		none
* @retval		status value
*/
u8 TWI_u8GetStatus (void);

/* @brief		shall send stop condition
* @paramin		none
* @paramout		none
* @retval		none
*/
void TWI_voidSendStopCondition (void);


#endif 
