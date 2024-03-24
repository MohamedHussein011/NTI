/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: TIMER_config.h	                ************************/
/***************************************************************************************/

#ifndef TIMER_CONFIG_H
#define TIMER_CONFIG_H


/********************************				 CPU FREQ  						********************************/
#define CPU_FREQ						16000000UL


/********************************				 TIMER0  						********************************/
/* Waveform Generation Mode */
#define TIMER0_MODE				TIMER_FAST_PWM

/* Compare Match Output Mode */
#define TIMER0_COMP_MODE					TIMER_COMP_CLR_OCx

/* Clock Select / Prescaler */
#define TIMER0_CLOCK_SELECT				TIMER_CLOCK_64

/* Preload value TCNT0 */
#define TIMER0_PRELOAD_VALUE					0

/* Compare value OCR0 */
#define TIMER0_COMP_VALUE					0

/* Timer/Counter0 Output Compare Match Interrupt Enable */
#define TIMER0_COMP_INT				TIMER_DISABLE

/* Timer/Counter0 Overflow Interrupt Enable */
#define TIMER0_OVF_INT					TIMER_DISABLE


/********************************				 TIMER1  						********************************/
/* Waveform Generation Mode */
#define TIMER1_MODE						TIMER1_NORMAL

/* Compare Match Output Mode */
#define TIMER1_COMP_CHANEL_A_MODE					TIMER_COMP_CLR_OCx	//Compare Output Mode for Channel A
#define TIMER1_COMP_CHANEL_B_MODE					TIMER_COMP_CLR_OCx	//Compare Output Mode for Channel B

/* Clock Select / Prescaler */
#define TIMER1_CLOCK_SELECT				TIMER_CLOCK_64

/* Preload value TCNT1 */
#define TIMER1_PRELOAD_VALUE					0

/* Compare value OCR1A & OCR1B */
#define TIMER1_COMP_A_VALUE					0
#define TIMER1_COMP_B_VALUE					0

/* Input Capture VALUE */
#define TIMER1_IC_VALUE						5000

/* Timer/Counter1 Output Compare Match Channel A & B Interrupt Enable */
#define TIMER1_COMP_A_INT				TIMER_DISABLE
#define TIMER1_COMP_B_INT				TIMER_DISABLE

/* Timer/Counter1 Overflow Interrupt Enable */
#define TIMER1_OVF_INT					TIMER_DISABLE

/* Timer/Counter1, Input Capture Interrupt Enable */
#define TIMER1_IC_INT					TIMER_DISABLE

/********************************				 TIMER2  						********************************/
/* Waveform Generation Mode */
#define TIMER2_MODE				TIMER_NORMAL

/* Compare Match Output Mode */
#define TIMER2_COMP_MODE					TIMER_COMP_SET_OCx

/* Clock Select / Prescaler */
#define TIMER2_CLOCK_SELECT				TIMER2_CLOCK_64

/* Preload value TCNT0 */
#define TIMER2_PRELOAD_VALUE					0

/* Compare value OCR0 */
#define TIMER2_COMP_VALUE					250

/* Timer/Counter0 Output Compare Match Interrupt Enable */
#define TIMER2_COMP_INT				TIMER_DISABLE

/* Timer/Counter0 Overflow Interrupt Enable */
#define TIMER2_OVF_INT					TIMER_DISABLE

#endif
