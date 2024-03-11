/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: SPI_program.c		            ************************/
/***************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

/* Global Pointer to function */
static void (*SPI_STCCallBack)(u8 copy_u8SPIData) = NULL;     //Serial Transfer Complete Interrupt

//global flag indicating that SPI (slave mode) is already initialized & waiting for data
static u8 SPI_FLAG = IDLE;

/********************************				Function Definitions				********************************/
void SPI_voidMasterInit(void)
{
	/* Data order to be transmitted */
#if SPI_Data_Order == SPI_MSB			// The MSB of the data word is transmitted first
	CLR_BIT(SPI->SPCR, DORD);
#elif SPI_Data_Order == SPI_LSB			// The LSB of the data word is transmitted first
	SET_BIT(SPI->SPCR, DORD);
#else
#error "Wrong SPI data order selection"
#endif

	/* SPI Clock Polarity Option */
#if SPI_Clock_polarity == SPI_IDLE_LOW		//leading Edge is Rising Edge & trailing Edge is Falling as IDLE state is LOW
	CLR_BIT(SPI->SPCR, CPOL);
#elif SPI_Clock_polarity == SPI_IDLE_HIGH		//leading Edge is Falling Edge & trailing Edge is Rising as IDLE state is HIGH
	SET_BIT(SPI->SPCR, CPOL);
#else
#error "Wrong SPI Clock Polarity selection"
#endif

	/* SPI Clock Phase */
#if SPI_Clock_Phase == SPI_Sample_Setup		 //leading Edge is Sample(receive) & trailing Edge is Setup(Send)
	CLR_BIT(SPI->SPCR, CPHA);
#elif SPI_Clock_Phase == SPI_Setup_Sample		//leading Edge is Setup(Send) & trailing Edge is Sample(receive)
	SET_BIT(SPI->SPCR, CPHA);
#else
#error "Wrong SPI Clock Phase selection"
#endif

	/* SPI Clock Rate */
	SPI->SPCR &= 0xFC;			//mask clock bits
	SPI->SPCR |= (SPI_Clock_Rate & 0x03);
	SPI->SPSR |= (SPI_Clock_Rate & 0x04);

	//Select Master
	SET_BIT(SPI->SPCR, MSTR);

	//Enable or Disable interrupt
#if SPI_INT_EN == SPI_ENABLE
	SET_BIT(SPI->SPCR, SPIE);
#elif SPI_INT_EN == SPI_DISABLE
	CLR_BIT(SPI->SPCR, SPIE);
#else
#error "Wrong SPI Enable or Disable interrupt selection"
#endif

	//Enable SPI
	SET_BIT(SPI->SPCR, SPE);
}

void SPI_voidSlaveInit(void)
{
	/* Data order to be transmitted */
#if SPI_Data_Order == SPI_MSB			// The MSB of the data word is transmitted first
	CLR_BIT(SPI->SPCR, DORD);
#elif SPI_Data_Order == SPI_LSB			// The LSB of the data word is transmitted first
	SET_BIT(SPI->SPCR, DORD);
#else
#error "Wrong SPI data order selection"
#endif

	/* SPI Clock Polarity Option */
#if SPI_Clock_polarity == SPI_IDLE_LOW		//leading Edge is Rising Edge & trailing Edge is Falling as IDLE state is LOW
	CLR_BIT(SPI->SPCR, CPOL);
#elif SPI_Clock_polarity == SPI_IDLE_HIGH		//leading Edge is Falling Edge & trailing Edge is Rising as IDLE state is HIGH
	SET_BIT(SPI->SPCR, CPOL);
#else
#error "Wrong SPI Clock Polarity selection"
#endif

	/* SPI Clock Phase */
#if SPI_Clock_Phase == SPI_Sample_Setup		 //leading Edge is Sample(receive) & trailing Edge is Setup(Send)
	CLR_BIT(SPI->SPCR, CPHA);
#elif SPI_Clock_Phase == SPI_Setup_Sample		//leading Edge is Setup(Send) & trailing Edge is Sample(receive)
	SET_BIT(SPI->SPCR, CPHA);
#else
#error "Wrong SPI Clock Phase selection"
#endif

	//Select Slave
	CLR_BIT(SPI->SPCR, MSTR);

	//Enable or Disable interrupt
#if SPI_INT_EN == SPI_ENABLE
	SET_BIT(SPI->SPCR, SPIE);
#elif SPI_INT_EN == SPI_DISABLE
	CLR_BIT(SPI->SPCR, SPIE);
#else
#error "Wrong SPI Enable or Disable interrupt selection"
#endif

	//Enable SPI
	SET_BIT(SPI->SPCR, SPE);
}

u8 SPI_u8TransReceiveDataSynch (u8 copy_u8TransData, u8* copy_pu8ReceiveData)
{
	u8 Local_u8ErrorState = OK;

	if(copy_pu8ReceiveData != NULL)
	{
		SPI->SPDR = copy_u8TransData;

		/* Busy Wait polling till sending operation complete */
		while (GET_BIT(SPI->SPSR, SPIF) != 1 );

		/* Clear interrput flag */
		SET_BIT(SPI->SPSR,SPIF);

		*copy_pu8ReceiveData = SPI->SPDR;
	}
	else
		Local_u8ErrorState = SPI_E_PARAM_POINTER;

	return Local_u8ErrorState;
}


u8 SPI_u8TransReceiveDataAsynch (u8 copy_u8TransData, void (*copy_pvNotificationFunc)(u8 copy_u8Data))
{
	u8 Local_u8ErrorStatus = OK;

	if(copy_pvNotificationFunc != NULL)
	{
		if(SPI_FLAG == IDLE)
		{
			SPI_STCCallBack = copy_pvNotificationFunc;
			SPI->SPDR = copy_u8TransData;
			//Enable interrupt
			SET_BIT(SPI->SPCR, SPIE);
			SPI_FLAG = BUSY;
		}
	}
	else
		Local_u8ErrorStatus = SPI_E_PARAM_POINTER;


	return Local_u8ErrorStatus;
}

void SPI_voidEnableInterrupt(void)
{
	SET_BIT(SPI->SPCR, SPIE);
}

void SPI_voidDisableInterrupt(void)
{
	CLR_BIT(SPI->SPCR, SPIE);
}

u8 SPI_u8SetCallback (void (*copy_pvFunc)(u8 copy_u8Data))
{
	u8 Local_u8ErrorState = OK;

	if(copy_pvFunc != NULL)
	{
		SPI_STCCallBack = copy_pvFunc;
	}
	else
		Local_u8ErrorState = SPI_E_PARAM_POINTER;

	return Local_u8ErrorState;
}
/******************************************************************************
 * !comment  :  ISR Function SPI.  							 			      *
 ******************************************************************************/
void __vector_12 (void) __attribute__((signal));
void __vector_12 (void)
{
	if(SPI_STCCallBack != NULL)
	{
		SPI_STCCallBack((u8)SPI->SPDR);
		//Disable interrupt
		CLR_BIT(SPI->SPCR, SPIE);

		//idle now
		SPI_FLAG = IDLE;
	}

	//check if SPI is in master mode or slave mode
#if SPI_MODE == SPI_MASTER
	//check if MSTR bit is cleared or not & if it's cleared, we must re-enable it.
	if(GET_BIT(SPI->SPCR, MSTR) == 0)
	{
		SET_BIT(SPI->SPCR, MSTR);
	}
#elif SPI_MODE == SPI_SLAVE

#else
#error "Wrong SPI mode selection"
#endif

}
