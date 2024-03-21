/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: TIMER_interface.h	            ************************/
/***************************************************************************************/


#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H


/*NOTE: CPU Freq. = 16 MHz
 * Non-Inverted mode  --> controls Ton (bigger compare value, bigger Ton)
 * Inverted mode  	  --> controls Toff (bigger compare value, bigger Toff)
 * */

/*********************************		Error classification	******************************/
//Invalid Timer interrupt ID requested
#define TIMER_E_PARAM_INVALID_INT_ID				0x0A
//APIs called with a Null Pointer
#define TIMER_E_PARAM_POINTER						0x0B
//APIs is busy
#define TIMER_E_BUSY								0x0C
//Invalid Timer duty cycle ID requested
#define TIMER_E_PARAM_INVALID_DUTY_ID				0x0E
//Invalid Timer freq ID requested
#define TIMER_E_PARAM_INVALID_FREQ_ID				0x0F
//Invalid Timer channel ID requested
#define TIMER_E_PARAM_INVALID_CHANNEL_ID			0x10
//Invalid Timer PWM configuration (timer mode not pwm mode or compare match mode)
#define TIMER_E_INVALID_PWM_CONFIG					0x11


/*********************************		MACROs	******************************/
/* Waveform Generation Mode for TIMER0 & TIMER2*/
#define TIMER_NORMAL						0
#define TIMER_PWM							1			//PWM, Phase Correct
#define TIMER_CTC							2
#define TIMER_FAST_PWM						3

/* Waveform Generation Mode for TIMER1 */
#define TIMER1_NORMAL						0
#define TIMER1_PWM_8BIT						1
#define TIMER1_PWM_9BIT						2
#define TIMER1_PWM_10BIT					3
#define TIMER1_CTC_OCR1A					4
#define TIMER1_FAST_PWM_8BIT				5
#define TIMER1_FAST_PWM_9BIT				6
#define TIMER1_FAST_PWM_10BIT				7
#define TIMER1_PWM_PFC_ICR1					8		//PWM, Phase and Frequency Correct
#define TIMER1_PWM_PFC_OCR1A				9		//PWM, Phase and Frequency Correct
#define TIMER1_PWM_ICR1						10
#define TIMER1_PWM_OCR1A					11
#define TIMER1_CTC_ICR1						12
#define TIMER1_FAST_PWM_ICR1				14
#define TIMER1_FAST_PWM_OCR1A				15

/* Compare Match Output Mode for TIMER0 & TIMER1 & TIMER2*/
//non-PWM Mode
#define TIMER_COMP_NORMAL			0		//Normal port operation, OCx disconnected
/*non-PWM Mode: Toggle OCx on compare match, Fast PWM Mode & Phase Correct PWM Mode reserved*/
#define TIMER_COMP_TOG_OCx			1
/*non-PWM Mode: Clear OCx on compare match, Fast PWM Mode: Clear OCx on compare match, set OCx at TOP (non-inverting),
* Phase Correct PWM Mode: Clear OCx on compare match when up-counting. Set OCx on compare match when downcounting (non-inverting).*/
#define TIMER_COMP_CLR_OCx			2
/*non-PWM Mode: Set OCx on compare match, Fast PWM Mode: Set OCx on compare match, clear OCx at TOP (inverting),
* Phase Correct PWM Mode: Set OCx on compare match when up-counting. Clear OCx on compare match when downcounting (inverting).*/
#define TIMER_COMP_SET_OCx			3


/* Clock Select / Prescaler for TIMER0 & TIMER1*/
#define TIMER_NO_CLOCK						0			//No clock source (Timer/Counter stopped).
#define TIMER_NO_PRESCALER					1			//clkI/O/(No prescaling)
#define TIMER_CLOCK_8						2
#define TIMER_CLOCK_64						3
#define TIMER_CLOCK_256						4
#define TIMER_CLOCK_1024					5
#define TIMER_EXT0_CLOCK					6		//External clock source on T0 pin. Clock on falling edge.
#define TIMER_EXT1_CLOCK					7		//External clock source on T0 pin. Clock on rising edge.

/* Clock Select / Prescaler for TIMER2*/
#define TIMER2_NO_CLOCK						0			//No clock source (Timer/Counter stopped).
#define TIMER2_NO_PRESCALER					1			//clkI/O/(No prescaling)
#define TIMER2_CLOCK_8						2
#define TIMER2_CLOCK_32						3
#define TIMER2_CLOCK_64						4
#define TIMER2_CLOCK_128					5
#define TIMER2_CLOCK_256					6
#define TIMER2_CLOCK_1024					7

/* TIMER1 Channels*/
#define TIMER1_CHANNEL_A					0
#define TIMER1_CHANNEL_B					1

/* Enable or Disable for TIMER0 & TIMER1 & TIMER2*/
#define TIMER_DISABLE					0
#define TIMER_ENABLE					1

/* interrupt sources for TIMER0 & TIMER1 & TIMER2 */
#define TIMER0_OVF						0
#define TIMER0_COMP						1
#define TIMER1_OVF						2
#define TIMER1_COMPB					3
#define TIMER1_COMPA					4
#define TIMER1_CAPT						5
#define TIMER2_OVF						6
#define TIMER2_COMP						7


/********************************				Function Prototypes				********************************/

/********************************				 TIMER0  						********************************/
/* @brief		shall initialize TIMER0 with the configuration set in TIMER_config.h
* @paramin		none
* @paramout		none
* @retval		none
*/
void TIMER0_voidInit(void);

/* @brief		shall initialize TIMER0 TCNT0 with preload value
* @paramin		copy_u8Preload / Timer0 preload value
* @paramout		none
* @retval		none
*/
void TIMER0_voidSetPreload(u8 copy_u8Preload);

/* @brief		shall initialize TIMER0 OCR0 with compare match value
* @paramin		copy_u8CompValue / Timer0 compare match value
* @paramout		none
* @retval		none
*/
void TIMER0_voidSetCompMatchValue(u8 copy_u8CompValue);

/* @brief		shall Force Output Compare for TIMER0
* @paramin		none
* @paramout		none
* @retval		none
*/
void TIMER0_voidForceOutputComp(void);

/* @brief		shall generate PWM using TIMER0
* @paramin		copy_u32Freq / frequency in Hz (min = CPU_FREQ/(1024UL * 256), max = CPU_FREQ / 256) -
* 				copy_u16Duty / duty cycle (range: 0 : 100, but first multiply it by 10)
* @paramout		none
* @retval		error of wrong paramin
* @note			note: 1000 = 100% , 500 = 50%, 20 = 2%
* @note 		due to few prescalers ranges, the output freq. will be nearly to the required
* @note			remember to configure TIMER0_MODE to be (TIMER_FAST_PWM or TIMER_PWM)
* 				& TIMER0_COMP_MODE to be (TIMER_COMP_CLR_OCx or TIMER_COMP_SET_OCx)
*/
u8 TIMER0_u8GeneratePWM(u32 copy_u32Freq, u16 copy_u16Duty);

/* @brief		shall stop TIMER0
* @paramin		none
* @paramout		none
* @retval		none
*/
void TIMER0_voidStop(void);

/********************************				 TIMER1  						********************************/
/* @brief		shall initialize TIMER1 with the configuration set in TIMER_config.h
* @paramin		none
* @paramout		none
* @retval		none
*/
void TIMER1_voidInit(void);

/* @brief		shall initialize TIMER1 TCNT1 with preload value
* @paramin		copy_u16Preload / Timer1 preload value
* @paramout		none
* @retval		none
*/
void TIMER1_voidSetPreload(u16 copy_u16Preload);

/* @brief		shall initialize TIMER1 channel A OCR1A with compare match value
* @paramin		copy_u16CompValue / Timer1 channel A compare match value
* @paramout		none
* @retval		none
*/
void TIMER1_voidSetCompMatchChannelAValue(u16 copy_u16CompValue);

/* @brief		shall initialize TIMER1 channel B OCR1B with compare match value
* @paramin		copy_u16CompValue / Timer1 channel B compare match value
* @paramout		none
* @retval		none
*/
void TIMER1_voidSetCompMatchChannelBValue(u16 copy_u16CompValue);

/* @brief		shall generate PWM using TIMER1
* @paramin		copy_u8TimerChannel / Timer1 Channel (A or B) -
* 				copy_u32Freq / frequency in Hz (min = CPU_FREQ/(1024UL * (1+TOP)), max = CPU_FREQ / (1+TOP)) -
* 				copy_u16Duty / duty cycle (range: 0 : 100, but first multiply it by 10)
* @paramout		none
* @retval		error of wrong paramin
* @note			note: 1000 = 100% , 500 = 50%, 20 = 2%
* @note 		remember to configure TIMER1_MODE to be (TIMER1_FAST_PWM_OCR1A or TIMER1_FAST_PWM_ICR1 or TIMER1_PWM_OCR1A
* 				or TIMER1_PWM_ICR1 or TIMER1_PWM_8BIT or TIMER1_PWM_9BIT or TIMER1_PWM_10BIT or TIMER1_FAST_PWM_8BIT or
* 				TIMER1_FAST_PWM_9BIT or TIMER1_FAST_PWM_10BIT ....)
* 				& TIMER0_COMP_MODE to be (TIMER_COMP_CLR_OCx or TIMER_COMP_SET_OCx)
*/
u8 TIMER1_u8GeneratePWM(u8 copy_u8TimerChannel, u32 copy_u32Freq, u16 copy_u16Duty);

/* @brief		shall stop TIMER1
* @paramin		none
* @paramout		none
* @retval		none
*/
void TIMER1_voidStop(void);

/********************************				 TIMER2  						********************************/
/* @brief		shall initialize TIMER2 with the configuration set in TIMER_config.h
* @paramin		none
* @paramout		none
* @retval		none
*/
void TIMER2_voidInit(void);

/* @brief		shall initialize TIMER2 TCNT2 with preload value
* @paramin		copy_u8Preload / Timer2 preload value
* @paramout		none
* @retval		none
*/
void TIMER2_voidSetPreload(u8 copy_u8Preload);

/* @brief		shall initialize TIMER2 OCR2 with compare match value
* @paramin		copy_u8CompValue / Timer2 compare match value
* @paramout		none
* @retval		none
*/
void TIMER2_voidSetCompMatchValue(u8 copy_u8CompValue);

/* @brief		shall Force Output Compare for TIMER2
* @paramin		none
* @paramout		none
* @retval		none
*/
void TIMER2_voidForceOutputComp(void);

/* @brief		shall delay in ms using TIMER2
* @paramin		copy_u16Delayms / delay in ms -
* 				copy_pvFunc / pointer to a function that takes nothing & returns nothing and being called
* 				after the delay passes
* @paramout		none
* @retval		error of wrong paramin
* @note			least delay = 1 ms, must enable interrupt
*/
u8 TIMER2_u8Delayms(u16 copy_u16Delayms, pvFunction_t copy_pvFunc);

/* @brief		shall stop TIMER2
* @paramin		none
* @paramout		none
* @retval		none
*/
void TIMER2_voidStop(void);



/********************	 Timers interrupt functions		****************/
/* @brief		shall enable TIMER interrupt source
* @paramin		copy_u8IntSource / Timer interrupt source
* @paramout		none
* @retval		error of wrong paramin
*/
u8 TIMER_u8EnableInterrupt(u8 copy_u8IntSource);

/* @brief		shall disable TIMER interrupt source
* @paramin		copy_u8IntSource / Timer interrupt source
* @paramout		none
* @retval		error of wrong paramin
*/
u8 TIMER_u8DisableInterrupt(u8 copy_u8IntSource);

/* @brief		shall initialize TIMER0 or TIMER1 or TIMER2 call back functions for available interrupt sources
* @paramin		copy_pvFunc / pointer to function that takes none & returns none being called in ISR -
* 				copy_u8TimerSource / Timer interrupt source
* @paramout		none
* @retval		error of wrong paramin
*/
u8 TIMER_u8SetCallBack(u8 copy_u8TimerSource, pvFunction_t copy_pvFunc);


#endif 
