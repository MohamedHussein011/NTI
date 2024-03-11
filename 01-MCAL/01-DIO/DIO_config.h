/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: DIO_config.h	                ************************/
/***************************************************************************************/

#ifndef DIO_CONFIG_H
#define DIO_CONFIG_H

/* if some pins aren't used, it's recommended to ensure that these pins have a defined value.
 * the simplest method is to enable the internal pull-up (DDR = 0, PORT = 1).
 */

/******************************************************************************
 * !comment : Select Direction for PORTA option:  		   	                  *
 *           1: 0                  -----> INPUT (default)                     *
 *           2: 1                  -----> OUTPUT                              *
 ******************************************************************************/
#define PORTA_PIN0_DIR                0
#define PORTA_PIN1_DIR                1
#define PORTA_PIN2_DIR                1
#define PORTA_PIN3_DIR                0
#define PORTA_PIN4_DIR                0
#define PORTA_PIN5_DIR                0
#define PORTA_PIN6_DIR                0
#define PORTA_PIN7_DIR                1

/******************************************************************************
 * !comment : Select Direction for PORTB option:  		    	              *
 *           1: 0                  -----> INPUT (default)                     *
 *           2: 1                  -----> OUTPUT                              *
 ******************************************************************************/
#define PORTB_PIN0_DIR                0
#define PORTB_PIN1_DIR                0
#define PORTB_PIN2_DIR                0             //INT2
#define PORTB_PIN3_DIR                0             //OC0
#define PORTB_PIN4_DIR                1             //SS  output for master & input for slave
#define PORTB_PIN5_DIR                1             //MOSI  output for master & input for slave
#define PORTB_PIN6_DIR                0             //MISO  output for slave & input for master
#define PORTB_PIN7_DIR                1             //SCK   output for master & input for slave

/******************************************************************************
 * !comment : Select Direction for PORTC option:                              *
 *           1: 0                  -----> INPUT (default)                     *
 *           2: 1                  -----> OUTPUT                              *
 ******************************************************************************/
#define PORTC_PIN0_DIR                0               //SCL
#define PORTC_PIN1_DIR                0               //SDA
#define PORTC_PIN2_DIR                0
#define PORTC_PIN3_DIR                0
#define PORTC_PIN4_DIR                0
#define PORTC_PIN5_DIR                0
#define PORTC_PIN6_DIR                0
#define PORTC_PIN7_DIR                0

/******************************************************************************
 * !comment : Select Direction for PORTD option:  		    	              *
 *           1: 0                  -----> INPUT (default)                     *
 *           2: 1                  -----> OUTPUT                              *
 ******************************************************************************/
#define PORTD_PIN0_DIR                0            //Rx USART
#define PORTD_PIN1_DIR                0            //Tx USART
#define PORTD_PIN2_DIR                0            //INT0
#define PORTD_PIN3_DIR                0            //INT1
#define PORTD_PIN4_DIR                0            //OC1B
#define PORTD_PIN5_DIR                0            //OC1A
#define PORTD_PIN6_DIR                0            //ICP1
#define PORTD_PIN7_DIR                0            //OC2

/******************************************************************************
 * !comment : Select Initial Value for every PIN for PORTA option:             *
 *           1: 0                  -----> LOW or Floating (input) (default)    *
 *           2: 1                  -----> HIGH or PULLED-UP (input)            *
 ******************************************************************************/
#define PORTA_PIN0_INITIAL_VALUE                0
#define PORTA_PIN1_INITIAL_VALUE                0
#define PORTA_PIN2_INITIAL_VALUE                0
#define PORTA_PIN3_INITIAL_VALUE                0
#define PORTA_PIN4_INITIAL_VALUE                1
#define PORTA_PIN5_INITIAL_VALUE                1
#define PORTA_PIN6_INITIAL_VALUE                1
#define PORTA_PIN7_INITIAL_VALUE                0

/******************************************************************************
 * !comment : Select Initial Value for every PIN for PORTB option:             *
 *           1: 0                  -----> LOW or Floating (input) (default)            *
 *           2: 1                  -----> HIGH or PULLED-UP (input)                    *
 ******************************************************************************/
#define PORTB_PIN0_INITIAL_VALUE                1
#define PORTB_PIN1_INITIAL_VALUE                1
#define PORTB_PIN2_INITIAL_VALUE                1       //INT2
#define PORTB_PIN3_INITIAL_VALUE                1       //OC0
#define PORTB_PIN4_INITIAL_VALUE                1       //SS  output for master & input for slave
#define PORTB_PIN5_INITIAL_VALUE                0       //MOSI  output for master & input for slave
#define PORTB_PIN6_INITIAL_VALUE                0       //MISO  output for slave & input for master
#define PORTB_PIN7_INITIAL_VALUE                0       //SCK   output for master & input for slave

/******************************************************************************
 * !comment : Select Initial Value for every PIN for PORTC option:             *
 *           1: 0                  -----> LOW or Floating (input) (default)            *
 *           2: 1                  -----> HIGH or PULLED-UP (input)                    *
 ******************************************************************************/
#define PORTC_PIN0_INITIAL_VALUE                1           //SCL
#define PORTC_PIN1_INITIAL_VALUE                1           //SDA
#define PORTC_PIN2_INITIAL_VALUE                1
#define PORTC_PIN3_INITIAL_VALUE                1
#define PORTC_PIN4_INITIAL_VALUE                1
#define PORTC_PIN5_INITIAL_VALUE                1
#define PORTC_PIN6_INITIAL_VALUE                1
#define PORTC_PIN7_INITIAL_VALUE                1

/******************************************************************************
 * !comment : Select Initial Value for every PIN for PORTD option:             *
 *           1: 0                  -----> LOW or Floating (input) (default)            *
 *           2: 1                  -----> HIGH or PULLED-UP (input)                    *
 ******************************************************************************/
#define PORTD_PIN0_INITIAL_VALUE                1             //Rx USART
#define PORTD_PIN1_INITIAL_VALUE                1             //Tx USART
#define PORTD_PIN2_INITIAL_VALUE                1             //INT0
#define PORTD_PIN3_INITIAL_VALUE                1             //INT1
#define PORTD_PIN4_INITIAL_VALUE                1             //OC1B
#define PORTD_PIN5_INITIAL_VALUE                1             //OC1A
#define PORTD_PIN6_INITIAL_VALUE                1             //ICP1
#define PORTD_PIN7_INITIAL_VALUE                1             //OC2


#endif
