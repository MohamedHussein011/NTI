/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: SPI_config.h	                ************************/
/***************************************************************************************/

#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

/******************************************************************************
 * !comment : Select SPI Interrupt Enable option:  			                     *
 *           1: SPI_MASTER                                                       *
 *           2: SPI_SLAVE                                                      *
 ******************************************************************************/
#define SPI_MODE			SPI_MASTER


/******************************************************************************
 * !comment : Select SPI Interrupt Enable option:  			                     *
 *           1: SPI_ENABLE                                                       *
 *           2: SPI_DISABLE                                                      *
 ******************************************************************************/
#define SPI_INT_EN			SPI_ENABLE


/******************************************************************************
 * !comment : Select SPI Data Order option:  			         	               *
 *           1: SPI_LSB                                                              *
 *           2: SPI_MSB                                                              *
 ******************************************************************************/
#define SPI_Data_Order             SPI_MSB


/******************************************************************************
 * !comment : Select SPI Clock Polarity Option (Leading_Trailing) Edge:  	      *
 *            1: SPI_IDLE_HIGH      (Falling_Rising)                            *
 *            2: SPI_IDLE_LOW       (Rising_Faling)                            *
 ******************************************************************************/
#define SPI_Clock_polarity        SPI_IDLE_HIGH


/******************************************************************************
 * !comment : Select SPI Clock Phase Option (Leading_Trailing) Edge:  	      *
 *            1: SPI_Sample_Setup 		-->receive then send                      *
 *            2: SPI_Setup_Sample 		-->send then receive                     *
 ******************************************************************************/
#define SPI_Clock_Phase            SPI_Setup_Sample


/******************************************************************************
 * !comment : Select SPI Clock Rate Option :  	      *
 *         1: SPI_Normal_DivBy_4                               *
 *         2: SPI_Normal_DivBy_16                              *
 *		   3: SPI_Normal_DivBy_64                              *
 *		   4: SPI_Normal_DivBy_128                             *
 *		   5: SPI_Double_DivBy_2                               *
 *		   6: SPI_Double_DivBy_8                               *
 *		   7: SPI_Double_DivBy_32                              *
 *		   8: SPI_Double_DivBy_64                              *
 ******************************************************************************/
#define SPI_Clock_Rate          SPI_Normal_DivBy_128


#endif
