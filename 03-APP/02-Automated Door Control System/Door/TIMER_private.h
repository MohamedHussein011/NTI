/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: TIMER_private.h	                ************************/
/***************************************************************************************/

#ifndef TIMER_PRIVATE_H
#define TIMER_PRIVATE_H

/***********************				Registers						************************/

/* Timer/Counter Interrupt Mask Register */
#define TIMSK    *((volatile u8*)0x59)
#define OCIE2    	 7                              //Timer/Counter2 Output Compare Match Interrupt Enable
#define TOIE2        6                              //Timer/Counter2 Overflow Interrupt Enable
#define TICIE1       5                    			//Timer/Counter1, Input Capture Interrupt Enable
#define OCIE1A       4                 			    //Timer/Counter1, Output Compare A Match Interrupt Enable
#define OCIE1B       3          			        //Timer/Counter1, Output Compare B Match Interrupt Enable
#define TOIE1        2			                    //Timer/Counter1, Overflow Interrupt Enable
#define OCIE0   	 1                              //Timer/Counter0 Output Compare Match Interrupt Enable
#define TOIE0    	 0                              //Timer/Counter0 Overflow Interrupt Enable

/* Timer/Counter Interrupt Flag Register */
#define TIFR     *((volatile u8*)0x58)
#define OCF2         7                              //Output Compare Flag 2
#define TOV2     	 6                              //Timer/Counter2 Overflow Flag
#define ICF1         5                    			//Timer/Counter1, Input Capture Flag
#define OCF1A        4                   			//Timer/Counter1, Output Compare A Match Flag
#define OCF1B        3               	    		//Timer/Counter1, Output Compare B Match Flag
#define TOV1         2                  		  	//Timer/Counter1, Overflow Flag
#define OCF0    	 1                              //Output Compare Flag 0
#define TOV0     	 0                              //Timer/Counter0 Overflow Flag


/******************************************************************************
 * !comment : TIMER0 Registers  		    	                 			   *
 ******************************************************************************/

/* Timer/Counter Control Register */
#define TCCR0    *((volatile u8*)0x53)
#define FOC0     7                              //Force Output Compare
#define WGM00    6                              //Waveform Generation Mode
#define COM01    5                              //Compare Match Output Mode
#define COM00    4                              //Compare Match Output Mode
#define WGM01    3                              //Waveform Generation Mode
#define CS02     2                              //Clock Select
#define CS01     1                              //Clock Select
#define CS00     0                              //Clock Select

/* Timer/Counter Register */
#define TCNT0    *((volatile u8*)0x52)

/* Output Compare Register */
#define OCR0     *((volatile u8*)0x5C)


/******************************************************************************
 * !comment : TIMER1 Registers  		    	                 			   *
 ******************************************************************************/

/* Timer/Counter1 Control Register A */
#define TCCR1A       *((volatile u8*)0x4F)
#define COM1A1       7                     //Compare Output Mode for Channel A
#define COM1A0       6                     //Compare Output Mode for Channel A
#define COM1B1       5                     //Compare Output Mode for Channel B
#define COM1B0       4                     //Compare Output Mode for Channel B
#define FOC1A        3                     //Force Output Compare for Channel A
#define FOC1B        2                     //Force Output Compare for Channel B
#define WGM11        1                     //Waveform Generation Mode
#define WGM10        0                     //Waveform Generation Mode

/* Timer/Counter1 Control Register B */
#define TCCR1B       *((volatile u8*)0x4E)
#define ICNC1        7                     //Input Capture Noise Canceler
#define ICES1        6                     //Input Capture Edge Select
/* Bit 5 reserved */
#define WGM13        4                     //Waveform Generation Mode
#define WGM12        3                     //Waveform Generation Mode
#define CS12         2                     //Clock Select
#define CS11         1                     //Clock Select
#define CS10         0                     //Clock Select

/* Timer/Counter1 Register */
#define TCNT1H       *((volatile u8*)0x4D)
#define TCNT1L       *((volatile u8*)0x4C)
#define TCNT1        *((volatile u16*)0x4C)

/* Output Compare Register 1 A */
#define OCR1AH       *((volatile u8*)0x4B)
#define OCR1AL       *((volatile u8*)0x4A)
#define OCR1A        *((volatile u16*)0x4A)

/* Output Compare Register 1 B */
#define OCR1BH       *((volatile u8*)0x49)
#define OCR1BL       *((volatile u8*)0x48)
#define OCR1B        *((volatile u16*)0x48)

/* Input Capture Register 1 */
#define ICR1H        *((volatile u8 *)0x47)
#define ICR1L        *((volatile u8 *)0x46)
#define ICR1         *((volatile u16 *)0x46)


/******************************************************************************
* !comment : TIMER2 Registers  		    	                 			   *
******************************************************************************/
/* Timer/Counter2 Control Register A */
#define TCCR2       *((volatile u8*)0x45)
#define FOC2        7                     //Force Output Compare
#define WGM20       6                     //Waveform Generation Mode
#define COM21       5                     //Compare Match Output Mode
#define COM20       4                     //Compare Match Output Mode
#define WGM21       3                     //Waveform Generation Mode
#define CS22        2                     //Clock Select
#define CS21        1                     //Clock Select
#define CS20        0                     //Clock Select

/* Timer/Counter Register */
#define TCNT2    *((volatile u8*)0x44)

/* Output Compare Register */
#define OCR2     *((volatile u8*)0x43)



#endif
