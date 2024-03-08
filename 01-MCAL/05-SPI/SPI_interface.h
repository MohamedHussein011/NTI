/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: SPI_interface.h	            ************************/
/***************************************************************************************/


#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

/*********************************		Error classification	******************************/
//APIs called with a Null Pointer
#define SPI_E_PARAM_POINTER			0x0A

/*********************************		MACROs	******************************/
//SPI mode
#define SPI_MASTER					0
#define SPI_SLAVE 					1

/* SPI Interrupt Enable */
#define SPI_DISABLE			0
#define SPI_ENABLE			1

/* SPI Data Order */
#define SPI_LSB             0
#define SPI_MSB             1


/* SPI Clock Polarity Option (Leading_Trailing) Edge */
#define SPI_IDLE_HIGH         0
#define SPI_IDLE_LOW          1

/* SPI Clock Phase Option (Leading_Trailing) Edge */
#define SPI_Sample_Setup            0
#define SPI_Setup_Sample            1

/* SPI Clock Rate */
#define SPI_Normal_DivBy_4              0
#define SPI_Normal_DivBy_16             1
#define SPI_Normal_DivBy_64             2
#define SPI_Normal_DivBy_128            3
#define SPI_Double_DivBy_2              4
#define SPI_Double_DivBy_8              5
#define SPI_Double_DivBy_32             6
#define SPI_Double_DivBy_64             7


/********************************				Function Prototypes				********************************/
/* @brief		shall initialize SPI as a Master
*				with the configuration set in SPI_config.h
* @paramin		none
* @paramout		none
* @retval		none
*/
void SPI_voidMasterInit(void);

/* @brief		shall initialize SPI as a Slave
*				with the configuration set in SPI_config.h
* @paramin		none
* @paramout		none
* @retval		none
*/
void SPI_voidSlaveInit(void);

/* @brief		shall transmit & receive data synchronous
* @paramin		copy_u8TransData / 1 byte data to be transmitted
* @paramout		copy_u8ReceiveData / pointer to hold the received 1 byte data
* @retval		Error status of wrong paramin
*/
u8 SPI_u8TransReceiveDataSynch (u8 copy_u8TransData, u8* copy_u8ReceiveData);

/* @brief		shall transmit & receive data Asynchronous
* @paramin		copy_u8TransData / 1 byte data to be transmitted -
* 				copy_pvNotificationFunc / pointer to function that takes copy_u8Data which is the
* 				data received and returns nothing & be executed when the transmission is finished
* @paramout		none
* @retval		Error status of wrong paramin
*/
u8 SPI_u8TransReceiveDataAsynch (u8 copy_u8TransData, void (*copy_pvNotificationFunc)(u8 copy_u8Data));

/* @brief		shall enable SPI interrupt
*				with the configuration set in SPI_config.h
* @paramin		none
* @paramout		none
* @retval		none
*/
void SPI_voidEnableInterrupt(void);

/* @brief		shall disable SPI interrupt
*				with the configuration set in SPI_config.h
* @paramin		none
* @paramout		none
* @retval		none
*/
void SPI_voidDisableInterrupt(void);

/* @brief		shall initialize SPI ISR with function needed to be executed
 * 				when the transmission is finished during runtime
* @paramin		copy_pvFunc / pointer to function that takes copy_u8Data which is the
* 				data received and returns nothing & be executed when the transmission is finished
* @paramout		none
* @retval		Error State of Wrong paramin
*/
u8 SPI_u8SetCallback (void (*copy_pvFunc)(u8 copy_u8Data));

#endif 
