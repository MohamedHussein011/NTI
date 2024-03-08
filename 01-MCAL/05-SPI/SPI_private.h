/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: SPI_private.h	                ************************/
/***************************************************************************************/

#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

			/****************			Registers					****************/
typedef struct
{
	volatile u8 SPCR;
	volatile u8 SPSR;
	volatile u8 SPDR;
}SPI_REG_st;

#define SPI				((volatile SPI_REG_st*) 0x2D)

//SPI registers bits
/******************************************************************************
 * !comment : SPI Control Register (SPCR) & Bits Definition.                     *
 ******************************************************************************/
#define SPIE    7          //SPI Interrupt Enable
#define SPE     6          //SPI Enable
#define DORD    5          //Data Order
#define MSTR    4          //Master/Slave Select
#define CPOL    3          //Clock Polarity
#define CPHA    2          //Clock Phase
#define SPR1    1          //SPI Clock Rate Select 1
#define SPR0    0          //SPI Clock Rate Select 0

/******************************************************************************
 * !comment : SPI Status Register (SPSR) & Bits Definition.                     *
 ******************************************************************************/
#define SPIF            7         //SPI Interrupt Flag
#define WCOL            6         //Write COLlision Flag
/* Bit 5 .. 1 reserved */
#define SPI2X           0         //Double SPI Speed Bit




#endif
