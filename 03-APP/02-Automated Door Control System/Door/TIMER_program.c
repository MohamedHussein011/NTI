/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: TIMER_program.c		            ************************/
/***************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER_interface.h"
#include "TIMER_private.h"
#include "TIMER_config.h"

/****************************			Global Variables				*************************/
/* variables indicating max freq. for each prescalers for TIMER0 PWM*/
#if TIMER0_MODE == TIMER_FAST_PWM
static u32 Timer0_MaxFreq = CPU_FREQ / 256UL;
static u32 Timer0_Pre8Freq = CPU_FREQ / (8 * 256UL);
static u32 Timer0_Pre64Freq = CPU_FREQ / (64 * 256UL);
static u32 Timer0_Pre256Freq = CPU_FREQ / (256 * 256UL);
static u32 Timer0_MinFreq = CPU_FREQ /(1024UL * 256UL);
#elif TIMER0_MODE == TIMER_PWM
static u32 Timer0_MaxFreq = CPU_FREQ / 510UL;
static u32 Timer0_Pre8Freq = CPU_FREQ / (8 * 510UL);
static u32 Timer0_Pre64Freq = CPU_FREQ / (64 * 510UL);
static u32 Timer0_Pre256Freq = CPU_FREQ / (256 * 510UL);
static u32 Timer0_MinFreq = CPU_FREQ /(1024UL * 510UL);
#endif

/* variables indicating max freq. for each prescalers for TIMER1 PWM*/
#if (TIMER1_MODE == TIMER1_FAST_PWM_8BIT)
static u32 Timer1_MaxFreq = CPU_FREQ / 256UL;
static u32 Timer1_Pre8Freq = CPU_FREQ / (8 * 256UL);
static u32 Timer1_Pre64Freq = CPU_FREQ / (64 * 256UL);
static u32 Timer1_Pre256Freq = CPU_FREQ / (256 * 256UL);
static u32 Timer1_MinFreq = CPU_FREQ /(1024UL * 256UL);

#elif (TIMER1_MODE == TIMER1_FAST_PWM_9BIT)
static u32 Timer1_MaxFreq = CPU_FREQ / 512UL;
static u32 Timer1_Pre8Freq = CPU_FREQ / (8 * 512UL);
static u32 Timer1_Pre64Freq = CPU_FREQ / (64 * 512UL);
static u32 Timer1_Pre256Freq = CPU_FREQ / (256 * 512UL);
static u32 Timer1_MinFreq = CPU_FREQ /(1024UL * 512UL);

#elif (TTIMER1_MODE == TIMER1_FAST_PWM_10BIT)
static u32 Timer1_MaxFreq = CPU_FREQ / 1024UL;
static u32 Timer1_Pre8Freq = CPU_FREQ / (8 * 1024UL);
static u32 Timer1_Pre64Freq = CPU_FREQ / (64 * 1024UL);
static u32 Timer1_Pre256Freq = CPU_FREQ / (256 * 1024UL);
static u32 Timer1_MinFreq = CPU_FREQ /(1024UL * 1024UL);

#elif (TIMER1_MODE == TIMER1_FAST_PWM_OCR1A || TIMER1_MODE == TIMER1_FAST_PWM_ICR1 || \
		TIMER1_MODE == TIMER1_PWM_OCR1A || TIMER1_MODE == TIMER1_PWM_ICR1 || \
		TIMER1_MODE == TIMER1_PWM_PFC_OCR1A || TIMER1_MODE == TIMER1_PWM_PFC_ICR1)
static u32 Timer1_MaxFreq = CPU_FREQ / 2;

#elif (TIMER1_MODE == TIMER1_PWM_8BIT)
static u32 Timer1_MaxFreq = CPU_FREQ / (256UL * 2);
static u32 Timer1_Pre8Freq = CPU_FREQ / (2 * 8 * 256UL);
static u32 Timer1_Pre64Freq = CPU_FREQ / (2 * 64 * 256UL);
static u32 Timer1_Pre256Freq = CPU_FREQ / (2 * 256 * 256UL);
static u32 Timer1_MinFreq = CPU_FREQ /(2 * 1024UL * 256UL);

#elif (TIMER1_MODE == TIMER1_PWM_9BIT)
static u32 Timer1_MaxFreq = CPU_FREQ / (2 * 512UL);
static u32 Timer1_Pre8Freq = CPU_FREQ / (2 * 8 * 512UL);
static u32 Timer1_Pre64Freq = CPU_FREQ / (2 * 64 * 512UL);
static u32 Timer1_Pre256Freq = CPU_FREQ / (2 * 256 * 512UL);
static u32 Timer1_MinFreq = CPU_FREQ /(2 * 1024UL * 512UL);

#elif (TTIMER1_MODE == TIMER1_PWM_10BIT)
static u32 Timer1_MaxFreq = CPU_FREQ / (2 * 1024UL);
static u32 Timer1_Pre8Freq = CPU_FREQ / (2 * 8 * 1024UL);
static u32 Timer1_Pre64Freq = CPU_FREQ / (2 * 64 * 1024UL);
static u32 Timer1_Pre256Freq = CPU_FREQ / (2 * 256 * 1024UL);
static u32 Timer1_MinFreq = CPU_FREQ /(2 * 1024UL * 1024UL);

#endif

/* Timer2 Delay Counter for the Delay function*/
static u16 Timer2_u16DelayCounter = 0;
/* Timer2 Counter for the Delay function*/
static u16 Timer2_u16Counter = 0;
/* Timer2 Flag for the Delay function indicating it's already working*/
static u8 Timer2_u8Flag = IDLE;

/*array of 2 pointers to functions for all interrupt sources for TIMER0*/
static pvFunction_t Timer_CallBack[8] = {NULL};


/********************************				Function Definitions				********************************/

/********************************				 TIMER0  						********************************/

void TIMER0_voidInit(void)
{
	/* Waveform Generation Mode */
#if (TIMER0_MODE >= TIMER_NORMAL && TIMER0_MODE <= TIMER_FAST_PWM)
	/*			WGM00						WGM01				 */
	TCCR0 |= (((TIMER0_MODE&0x01) << 6) | ((TIMER0_MODE>>1 & 0x01) << 3));
#else
#error "Wrong Timer0 Waveform Generation Mode selection"
#endif

	/* Compare Match Output Mode */
#if (TIMER0_COMP_MODE >= TIMER_COMP_NORMAL && TIMER0_COMP_MODE <= TIMER_COMP_SET_OCx)
	/*			COM00						COM01				 */
	TCCR0 |= (((TIMER0_COMP_MODE&0x01) << 4) | ((TIMER0_COMP_MODE>>1 & 0x01) << 5));

#else
#error "Wrong Timer0 Compare Match Output Mode selection"
#endif

	/* Force Output Compare */
#if (TIMER0_MODE == TIMER_FAST_PWM || TIMER0_MODE == TIMER_PWM)
	/* CLEAR Force Output Compare pin*/
	CLR_BIT(TCCR0, FOC0);
#endif

	/* Preload value */
	TCNT0 = TIMER0_PRELOAD_VALUE;

	/* Compare value OCR0 */
	OCR0 = TIMER0_COMP_VALUE;

	/* Timer/Counter0 Overflow & Output Compare Match Interrupt Enable */
#if (TIMER0_OVF_INT <= TIMER_ENABLE && TIMER0_OVF_INT >= TIMER_DISABLE && \
		TIMER0_COMP_INT <= TIMER_ENABLE && TIMER0_COMP_INT >= TIMER_DISABLE)
	TIMSK |= (TIMER0_OVF_INT | (TIMER0_COMP_INT<<1));

#else
#error "Wrong Timer0 Interrupt Enable selection"
#endif

	/* Clock Select / Prescaler */
#if (TIMER0_CLOCK_SELECT >= TIMER_NO_CLOCK && TIMER0_CLOCK_SELECT <= TIMER_EXT1_CLOCK)
	TCCR0 &= 0xF8;
	TCCR0 |= TIMER0_CLOCK_SELECT;

#else
#error "Wrong Timer0 Clock selection"
#endif

}

void TIMER0_voidSetPreload(u8 copy_u8Preload)
{
	/* Preload value */
	TCNT0 = copy_u8Preload;
}

void TIMER0_voidSetCompMatchValue(u8 copy_u8CompValue)
{
	/* Compare value OCR0 */
	OCR0 = copy_u8CompValue;
}

u8 TIMER0_u8EnableInterrupt(u8 copy_u8IntSource)
{
	u8 Local_u8ErrorStatus = OK;

	if(copy_u8IntSource == TIMER0_OVF || copy_u8IntSource == TIMER0_COMP)
	{
		SET_BIT(TIMSK, copy_u8IntSource);
	}
	else
		Local_u8ErrorStatus = TIMER_E_PARAM_INVALID_INT_ID;

	return Local_u8ErrorStatus;
}

u8 TIMER0_u8DisableInterrupt(u8 copy_u8IntSource)
{
	u8 Local_u8ErrorStatus = OK;

	if(copy_u8IntSource == TIMER0_OVF || copy_u8IntSource == TIMER0_COMP)
	{
		CLR_BIT(TIMSK, copy_u8IntSource);
	}
	else
		Local_u8ErrorStatus = TIMER_E_PARAM_INVALID_INT_ID;

	return Local_u8ErrorStatus;
}

void TIMER0_voidForceOutputComp(void)
{
	SET_BIT(TCCR0, FOC0);
}

u8 TIMER0_u8GeneratePWM(u32 copy_u32Freq, u16 copy_u16Duty)
{
#if (TIMER0_MODE == TIMER_FAST_PWM || TIMER0_MODE == TIMER_PWM)
	u8 Local_u8ErrorStatus = OK;

	if(copy_u16Duty >= 0 && copy_u16Duty <= 1000)
	{
		if(copy_u32Freq >= 0 && copy_u32Freq <= Timer0_MaxFreq)
		{
			/* stop the timer first */
			TCCR0 &= 0xF8;
			TCCR0 |= TIMER_NO_CLOCK;

			/* Waveform Generation Mode */
			/*			WGM00						WGM01				 */
			TCCR0 |= (((TIMER0_MODE&0x01) << 6) | ((TIMER0_MODE>>1 & 0x01) << 3));

			/* Compare Match Output Mode */
			/*			COM00						COM01				 */
			TCCR0 |= (((TIMER0_COMP_MODE&0x01) << 4) | ((TIMER0_COMP_MODE>>1 & 0x01) << 5));

			/* Preload value */
			TCNT0 = 0;

			/* Compare value OCR0 */
#if (TIMER0_COMP_MODE == TIMER_COMP_CLR_OCx)		//non-inverting
			OCR0 = (255UL * (copy_u16Duty + 1)) / 1000UL;
#elif (TIMER0_COMP_MODE == TIMER_COMP_SET_OCx)		//inverting
			OCR0 = (256*1000UL - (copy_u16Duty + 1)*255UL) / 1000UL;
#else
			Local_u8ErrorStatus = TIMER_E_INVALID_PWM_CONFIG;
#endif

			/* Clock Select / Prescaler */
			TCCR0 &= 0xF8;
			if(copy_u32Freq < (Timer0_MinFreq + 1))
			{
				TCCR0 |= TIMER_CLOCK_1024;
			}
			else if(copy_u32Freq < (Timer0_Pre256Freq + 1))
			{
				TCCR0 |= TIMER_CLOCK_256;
			}
			else if(copy_u32Freq < (Timer0_Pre64Freq + 1))
			{
				TCCR0 |= TIMER_CLOCK_64;
			}
			else if(copy_u32Freq < (Timer0_Pre8Freq + 1))
			{
				TCCR0 |= TIMER_CLOCK_8;
			}
			else if(copy_u32Freq < Timer0_MaxFreq)
			{
				TCCR0 |= TIMER_NO_PRESCALER;
			}

		}
		else
			Local_u8ErrorStatus = TIMER_E_PARAM_INVALID_FREQ_ID;

	}
	else
		Local_u8ErrorStatus = TIMER_E_PARAM_INVALID_DUTY_ID;

#else
	Local_u8ErrorStatus = TIMER_E_INVALID_PWM_CONFIG;
#endif

	return Local_u8ErrorStatus;
}




void TIMER0_voidStop(void)
{
	/* Clock Select / Prescaler */
	TCCR0 &= 0xFC;
	TCCR0 |= TIMER_NO_CLOCK;
}


/********************************				 TIMER1  						********************************/
void TIMER1_voidInit(void)
{
	/* Waveform Generation Mode */
#if (TIMER1_MODE >= TIMER1_NORMAL && TIMER1_MODE <= TIMER1_FAST_PWM_OCR1A)
	/*			WGM10						WGM11				 */
	TCCR1A |= (((TIMER1_MODE&0x01)) | ((TIMER1_MODE>>1 & 0x01) << 1));

	/*			WGM12						WGM13				 */
	TCCR1B |= (((TIMER1_MODE>>2 &0x01) << 3) | ((TIMER1_MODE>>3 & 0x01) << 4));
#else
#error "Wrong Timer1 Waveform Generation Mode selection"
#endif

	/* Compare Match Output Mode Channel A */
#if (TIMER1_COMP_CHANEL_A_MODE >= TIMER_COMP_NORMAL && TIMER1_COMP_CHANEL_A_MODE <= TIMER_COMP_SET_OCx)
	/*			COM1A0									COM1A1				 */
	TCCR1A |= (((TIMER1_COMP_CHANEL_A_MODE&0x01) << 6) | ((TIMER1_COMP_CHANEL_A_MODE>>1 & 0x01) << 7));

#else
#error "Wrong Timer1 Compare Match Output Channel A Mode selection"
#endif

	/* Compare Match Output Mode Channel B */
#if (TIMER1_COMP_CHANEL_B_MODE >= TIMER_COMP_NORMAL && TIMER1_COMP_CHANEL_B_MODE <= TIMER_COMP_SET_OCx)
	/*			COM1B0										COM1B1				 */
	TCCR1A |= (((TIMER1_COMP_CHANEL_B_MODE&0x01) << 4) | ((TIMER1_COMP_CHANEL_B_MODE>>1 & 0x01) << 5));

#else
#error "Wrong Timer1 Compare Match Output Channel B Mode selection"
#endif

	/* Preload value */
	TCNT1 = TIMER1_PRELOAD_VALUE;

	/* Compare value OCR1A & OCR1B */
	OCR1A = TIMER1_COMP_A_VALUE;
	OCR1B = TIMER1_COMP_B_VALUE;

	/* Input Capture VALUE */
	ICR1 = TIMER1_IC_VALUE;

	/* Timer/Counter1 Overflow & Output Compare Match Interrupt Enable */
#if (TIMER1_OVF_INT <= TIMER_ENABLE && TIMER1_OVF_INT >= TIMER_DISABLE && \
		TIMER1_COMP_A_INT <= TIMER_ENABLE && TIMER1_COMP_A_INT >= TIMER_DISABLE && \
		TIMER1_COMP_B_INT <= TIMER_ENABLE && TIMER1_COMP_B_INT >= TIMER_DISABLE && \
		TIMER1_IC_INT <= TIMER_ENABLE && TIMER1_IC_INT >= TIMER_DISABLE)
	TIMSK |= ((TIMER1_OVF_INT << 2) | (TIMER1_COMP_B_INT<< 3) | (TIMER1_COMP_A_INT << 4) | (TIMER1_IC_INT << 5));

#else
#error "Wrong Timer1 Interrupt Enable selection"
#endif

	/* Clock Select / Prescaler */
#if (TIMER1_CLOCK_SELECT >= TIMER_NO_CLOCK && TIMER1_CLOCK_SELECT <= TIMER_EXT1_CLOCK)
	TCCR1B &= 0xF8;
	TCCR1B |= TIMER1_CLOCK_SELECT;

#else
#error "Wrong Timer1 Clock selection"
#endif

}

void TIMER1_voidSetPreload(u16 copy_u16Preload)
{
	/* Preload value */
	TCNT1 = copy_u16Preload;
}

void TIMER1_voidSetCompMatchChannelAValue(u16 copy_u16CompValue)
{
	/* Compare value OCR1A */
	OCR1A = copy_u16CompValue;
}

void TIMER1_voidSetCompMatchChannelBValue(u16 copy_u16CompValue)
{
	/* Compare value OCR1B */
	OCR1B = copy_u16CompValue;
}

u8 TIMER1_u8GeneratePWM(u8 copy_u8TimerChannel, u32 copy_u32Freq, u16 copy_u16Duty)
{
	u8 Local_u8ErrorStatus = OK;
	u16 Local_u16Pre = 0;
	u32 Local_u32Temp = 0;

	if(copy_u8TimerChannel == TIMER1_CHANNEL_A || copy_u8TimerChannel == TIMER1_CHANNEL_B)
	{
		if(copy_u16Duty >= 0 && copy_u16Duty <= 1000)
		{
			/* stop the timer first */
			TCCR1B &= 0xF8;
			TCCR1B |= TIMER_NO_CLOCK;

			/* Waveform Generation Mode --> Fast PWM, ICR1 TOP*/
			/*			WGM10						WGM11				 */
			TCCR1A |= (((TIMER1_MODE&0x01)) | ((TIMER1_MODE>>1 & 0x01) << 1));

			/*			WGM12						WGM13				 */
			TCCR1B |= (((TIMER1_MODE>>2 &0x01) << 3) | ((TIMER1_MODE>>3 & 0x01) << 4));

			/* Compare Match Output Mode Channel A or B --> Clear OC1A/OC1B on compare match,
																   Set OC1A/OC1B at TOP	*/
			if(copy_u8TimerChannel == TIMER1_CHANNEL_A)
			{
				/*			COM1A0									COM1A1				 */
				TCCR1A |= (((TIMER1_COMP_CHANEL_A_MODE&0x01) << 6) | ((TIMER1_COMP_CHANEL_A_MODE>>1 & 0x01) << 7));
			}
			else if(copy_u8TimerChannel == TIMER1_CHANNEL_B)
			{
				/*			COM1B0										COM1B1				 */
				TCCR1A |= (((TIMER1_COMP_CHANEL_B_MODE&0x01) << 4) | ((TIMER1_COMP_CHANEL_B_MODE>>1 & 0x01) << 5));
			}

			/* load the freq required in ICR1 or OCR1A or not based on TIMER1 mode*/
#if (TIMER1_MODE == TIMER1_FAST_PWM_ICR1)
			if(copy_u32Freq <= Timer1_MaxFreq )
			{
				Local_u32Temp = ((CPU_FREQ / (1UL * copy_u32Freq)) - 1);
				if(Local_u32Temp > 65535)
				{
					Local_u32Temp = ((CPU_FREQ / (8UL * copy_u32Freq)) - 1);
					if(Local_u32Temp > 65535)
					{
						Local_u32Temp = ((CPU_FREQ / (64UL * copy_u32Freq)) - 1);
						if(Local_u32Temp > 65535)
						{
							Local_u32Temp = ((CPU_FREQ / (256UL * copy_u32Freq)) - 1);
							if(Local_u32Temp > 65535)
							{
								Local_u16Pre = 1024;
								ICR1 = ((CPU_FREQ / (1024UL * copy_u32Freq)) - 1);
							}
							else
							{
								Local_u16Pre = 256;
								ICR1 = Local_u32Temp;
							}
						}
						else
						{
							Local_u16Pre = 64;
							ICR1 = Local_u32Temp;
						}
					}
					else
					{
						Local_u16Pre = 8;
						ICR1 = Local_u32Temp;
					}
				}
				else
				{
					Local_u16Pre = 1;
					ICR1 = Local_u32Temp;
				}
			}
			else
			{
				Local_u8ErrorStatus = TIMER_E_PARAM_INVALID_FREQ_ID;
			}

#elif (TIMER1_MODE == TIMER1_FAST_PWM_OCR1A)
			if(copy_u32Freq < Timer1_MaxFreq )
			{
				Local_u32Temp = ((CPU_FREQ / (1UL * copy_u32Freq)) - 1);
				if(Local_u32Temp > 65535)
				{
					Local_u32Temp = ((CPU_FREQ / (8UL * copy_u32Freq)) - 1);
					if(Local_u32Temp > 65535)
					{
						Local_u32Temp = ((CPU_FREQ / (64UL * copy_u32Freq)) - 1);
						if(Local_u32Temp > 65535)
						{
							Local_u32Temp = ((CPU_FREQ / (256UL * copy_u32Freq)) - 1);
							if(Local_u32Temp > 65535)
							{
								Local_u16Pre = 1024;
								OCR1A = ((CPU_FREQ / (1024UL * copy_u32Freq)) - 1);
							}
							else
							{
								Local_u16Pre = 256;
								OCR1A = Local_u32Temp;
							}
						}
						else
						{
							Local_u16Pre = 64;
							OCR1A = Local_u32Temp;
						}
					}
					else
					{
						Local_u16Pre = 8;
						OCR1A = Local_u32Temp;
					}
				}
				else
				{
					Local_u16Pre = 1;
					OCR1A = Local_u32Temp;
				}
			}
			else
			{
				Local_u8ErrorStatus = TIMER_E_PARAM_INVALID_FREQ_ID;
			}

#elif (TIMER1_MODE == TIMER1_PWM_ICR1 || TIMER1_MODE == TIMER1_PWM_PFC_ICR1)
			if(copy_u32Freq < Timer1_MaxFreq )
			{
				Local_u32Temp = ((CPU_FREQ / (1UL * copy_u32Freq * 2)));
				if(Local_u32Temp > 65535)
				{
					Local_u32Temp = ((CPU_FREQ / (8UL * copy_u32Freq * 2)));
					if(Local_u32Temp > 65535)
					{
						Local_u32Temp = ((CPU_FREQ / (64UL * copy_u32Freq * 2)));
						if(Local_u32Temp > 65535)
						{
							Local_u32Temp = ((CPU_FREQ / (256UL * copy_u32Freq * 2)));
							if(Local_u32Temp > 65535)
							{
								Local_u16Pre = 1024;
								ICR1 = ((CPU_FREQ / (1024UL * copy_u32Freq * 2)));
							}
							else
							{
								Local_u16Pre = 256;
								ICR1 = Local_u32Temp;
							}
						}
						else
						{
							Local_u16Pre = 64;
							ICR1 = Local_u32Temp;
						}
					}
					else
					{
						Local_u16Pre = 8;
						ICR1 = Local_u32Temp;
					}
				}
				else
				{
					Local_u16Pre = 1;
					ICR1 = Local_u32Temp;
				}
			}
			else
			{
				Local_u8ErrorStatus = TIMER_E_PARAM_INVALID_FREQ_ID;
			}

#elif (TIMER1_MODE == TIMER1_PWM_OCR1A || TIMER1_MODE == TIMER1_PWM_PFC_OCR1A)

			if(copy_u32Freq < Timer1_MaxFreq )
			{
				Local_u32Temp = ((CPU_FREQ / (1UL * copy_u32Freq * 2)));
				if(Local_u32Temp > 65535)
				{
					Local_u32Temp = ((CPU_FREQ / (8UL * copy_u32Freq * 2)));
					if(Local_u32Temp > 65535)
					{
						Local_u32Temp = ((CPU_FREQ / (64UL * copy_u32Freq * 2)));
						if(Local_u32Temp > 65535)
						{
							Local_u32Temp = ((CPU_FREQ / (256UL * copy_u32Freq * 2)));
							if(Local_u32Temp > 65535)
							{
								Local_u16Pre = 1024;
								ICR1 = ((CPU_FREQ / (1024UL * copy_u32Freq * 2)));
							}
							else
							{
								Local_u16Pre = 256;
								ICR1 = Local_u32Temp;
							}
						}
						else
						{
							Local_u16Pre = 64;
							ICR1 = Local_u32Temp;
						}
					}
					else
					{
						Local_u16Pre = 8;
						ICR1 = Local_u32Temp;
					}
				}
				else
				{
					Local_u16Pre = 1;
					ICR1 = Local_u32Temp;
				}
			}
			else
			{
				Local_u8ErrorStatus = TIMER_E_PARAM_INVALID_FREQ_ID;
			}

#endif	//end of ICR1 or OCR1A pwm mode

			/* load the Duty required value in OCR1x */
			if(copy_u8TimerChannel == TIMER1_CHANNEL_A)
			{
#if (TIMER1_COMP_CHANEL_A_MODE == TIMER_COMP_CLR_OCx)		//non-inverting
#if (TIMER1_MODE == TIMER1_PWM_8BIT || TIMER1_MODE == TIMER1_FAST_PWM_8BIT)
				OCR1A = (255UL * (copy_u16Duty + 1)) / 1000UL;
#elif (TIMER1_MODE == TIMER1_PWM_9BIT || TIMER1_MODE == TIMER1_FAST_PWM_9BIT)
				OCR1A = (511UL * (copy_u16Duty + 1)) / 1000UL;
#elif (TIMER1_MODE == TIMER1_PWM_10BIT || TIMER1_MODE == TIMER1_FAST_PWM_10BIT)
				OCR1A = (1023UL * (copy_u16Duty + 1)) / 1000UL;
#elif (TIMER1_MODE == TIMER1_PWM_ICR1 || TIMER1_MODE == TIMER1_FAST_PWM_ICR1 || TIMER1_MODE == TIMER1_PWM_PFC_ICR1)
				OCR1A = (ICR1 * (u32)(copy_u16Duty)) / 1000UL;
#elif (TIMER1_MODE == TIMER1_PWM_OCR1A || TIMER1_MODE == TIMER1_FAST_PWM_OCR1A || TIMER1_MODE == TIMER1_PWM_PFC_OCR1A)
				OCR1A = (OCR1A * (u32)(copy_u16Duty + 1)) / 1000UL;
#else
				Local_u8ErrorStatus = TIMER_E_INVALID_PWM_CONFIG;
#endif

#elif (TIMER1_COMP_CHANEL_A_MODE == TIMER_COMP_SET_OCx)		//inverting
#if (TIMER1_MODE == TIMER1_PWM_8BIT || TIMER1_MODE == TIMER1_FAST_PWM_8BIT)
				OCR1A = (256*1000UL - (copy_u16Duty + 1)*255UL) / 1000UL;
#elif (TIMER1_MODE == TIMER1_PWM_9BIT || TIMER1_MODE == TIMER1_FAST_PWM_9BIT)
				OCR1A = (512*1000UL - (copy_u16Duty + 1)*511UL) / 1000UL;
#elif (TIMER1_MODE == TIMER1_PWM_10BIT || TIMER1_MODE == TIMER1_FAST_PWM_10BIT)
				OCR1A = (1024*1000UL - (copy_u16Duty + 1)*1023UL) / 1000UL;
#elif (TIMER1_MODE == TIMER1_PWM_ICR1 || TIMER1_MODE == TIMER1_FAST_PWM_ICR1 || TIMER1_MODE == TIMER1_PWM_PFC_ICR1)
				OCR1A = (ICR1*1000UL - (u32)(copy_u16Duty*ICR1)) / 1000UL;
#elif (TIMER1_MODE == TIMER1_PWM_OCR1A || TIMER1_MODE == TIMER1_FAST_PWM_OCR1A || TIMER1_MODE == TIMER1_PWM_PFC_OCR1A)
				OCR1A = (OCR1A*1000UL - (u32)(copy_u16Duty*ICR1)) / 1000UL;
#else
				Local_u8ErrorStatus = TIMER_E_INVALID_PWM_CONFIG;
#endif

#else
				Local_u8ErrorStatus = TIMER_E_INVALID_PWM_CONFIG;
#endif
			}
			else if(copy_u8TimerChannel == TIMER1_CHANNEL_B)
			{
#if (TIMER1_COMP_CHANEL_B_MODE == TIMER_COMP_CLR_OCx)		//non-inverting
#if (TIMER1_MODE == TIMER1_PWM_8BIT || TIMER1_MODE == TIMER1_FAST_PWM_8BIT)
				OCR1B = (255UL * (copy_u16Duty + 1)) / 1000UL;
#elif (TIMER1_MODE == TIMER1_PWM_9BIT || TIMER1_MODE == TIMER1_FAST_PWM_9BIT)
				OCR1B = (511UL * (copy_u16Duty + 1)) / 1000UL;
#elif (TIMER1_MODE == TIMER1_PWM_10BIT || TIMER1_MODE == TIMER1_FAST_PWM_10BIT)
				OCR1B = (1023UL * (copy_u16Duty + 1)) / 1000UL;
#elif (TIMER1_MODE == TIMER1_PWM_ICR1 || TIMER1_MODE == TIMER1_FAST_PWM_ICR1 || TIMER1_MODE == TIMER1_PWM_PFC_ICR1)
				OCR1B = (ICR1 * (u32)(copy_u16Duty)) / 1000UL;
#elif (TIMER1_MODE == TIMER1_PWM_OCR1A || TIMER1_MODE == TIMER1_FAST_PWM_OCR1A || TIMER1_MODE == TIMER1_PWM_PFC_OCR1A)
				OCR1B = (OCR1A * (u32)(copy_u16Duty + 1)) / 1000UL;
#else
				Local_u8ErrorStatus = TIMER_E_INVALID_PWM_CONFIG;
#endif

#elif (TIMER1_COMP_CHANEL_B_MODE == TIMER_COMP_SET_OCx)		//inverting
#if (TIMER1_MODE == TIMER1_PWM_8BIT || TIMER1_MODE == TIMER1_FAST_PWM_8BIT)
				OCR1B = (256*1000UL - (copy_u16Duty + 1)*255UL) / 1000UL;
#elif (TIMER1_MODE == TIMER1_PWM_9BIT || TIMER1_MODE == TIMER1_FAST_PWM_9BIT)
				OCR1B = (512*1000UL - (copy_u16Duty + 1)*511UL) / 1000UL;
#elif (TIMER1_MODE == TIMER1_PWM_10BIT || TIMER1_MODE == TIMER1_FAST_PWM_10BIT)
				OCR1B = (1024*1000UL - (copy_u16Duty + 1)*1023UL) / 1000UL;
#elif (TIMER1_MODE == TIMER1_PWM_ICR1 || TIMER1_MODE == TIMER1_FAST_PWM_ICR1 || TIMER1_MODE == TIMER1_PWM_PFC_ICR1)
				OCR1B = (ICR1*1000UL - (u32)(copy_u16Duty*ICR1)) / 1000UL;
#elif (TIMER1_MODE == TIMER1_PWM_OCR1A || TIMER1_MODE == TIMER1_FAST_PWM_OCR1A || TIMER1_MODE == TIMER1_PWM_PFC_OCR1A)
				OCR1B = (OCR1A*1000UL - (u32)(copy_u16Duty*ICR1)) / 1000UL;
#else
				Local_u8ErrorStatus = TIMER_E_INVALID_PWM_CONFIG;
#endif

#else
				Local_u8ErrorStatus = TIMER_E_INVALID_PWM_CONFIG;
#endif

			}

			/* start the timer with prescaler / 64 */
			TCCR1B &= 0xF8;
#if (TIMER1_MODE == TIMER1_FAST_PWM_ICR1 || TIMER1_MODE == TIMER1_FAST_PWM_OCR1A || \
			TIMER1_MODE == TIMER1_PWM_ICR1 || TIMER1_MODE == TIMER1_PWM_OCR1A || \
					TIMER1_MODE == TIMER1_PWM_PFC_ICR1 || TIMER1_MODE == TIMER1_PWM_PFC_OCR1A)
		if(Local_u16Pre == 1024)
		{
			TCCR1B |= TIMER_CLOCK_1024;
		}
		else if(Local_u16Pre == 256)
		{
			TCCR1B |= TIMER_CLOCK_256;
		}
		else if(Local_u16Pre == 64)
		{
			TCCR1B |= TIMER_CLOCK_64;
		}
		else if(Local_u16Pre == 8)
		{
			TCCR1B |= TIMER_CLOCK_8;
		}
		else if(Local_u16Pre == 1)
		{
			TCCR1B |= TIMER_NO_PRESCALER;
		}
#else
	if(copy_u32Freq < (Timer1_MinFreq + 1))
	{
		TCCR1B |= TIMER_CLOCK_1024;
	}
	else if(copy_u32Freq < (Timer1_Pre256Freq + 1))
	{
		TCCR1B |= TIMER_CLOCK_256;
	}
	else if(copy_u32Freq < (Timer1_Pre64Freq + 1))
	{
		TCCR1B |= TIMER_CLOCK_64;
	}
	else if(copy_u32Freq < (Timer1_Pre8Freq + 1))
	{
		TCCR1B |= TIMER_CLOCK_8;
	}
	else if(copy_u32Freq < Timer1_MaxFreq)
	{
		TCCR1B |= TIMER_NO_PRESCALER;
	}
#endif
		}
		else
			Local_u8ErrorStatus = TIMER_E_PARAM_INVALID_DUTY_ID;

	}
	else
		Local_u8ErrorStatus = TIMER_E_PARAM_INVALID_CHANNEL_ID;

	return Local_u8ErrorStatus;

}

void TIMER1_voidStop(void)
{
	/* Clock Select / Prescaler */
	TCCR1B &= 0xF8;
	TCCR1B |= TIMER_NO_CLOCK;
}

/********************************				 TIMER2  						********************************/

void TIMER2_voidInit(void)
{
	/* Waveform Generation Mode */
#if (TIMER2_MODE >= TIMER_NORMAL && TIMER2_MODE <= TIMER_FAST_PWM)
	/*			WGM20						WGM21				 */
	TCCR2 |= (((TIMER2_MODE&0x01) << 6) | ((TIMER2_MODE>>1 & 0x01) << 3));
#else
#error "Wrong Timer2 Waveform Generation Mode selection"
#endif

	/* Compare Match Output Mode */
#if (TIMER2_COMP_MODE >= TIMER_COMP_NORMAL && TIMER2_COMP_MODE <= TIMER_COMP_SET_OCx)
	/*			COM20						COM21				 */
	TCCR2 |= (((TIMER2_COMP_MODE&0x01) << 4) | ((TIMER2_COMP_MODE>>1 & 0x01) << 5));

#else
#error "Wrong Timer2 Compare Match Output Mode selection"
#endif

	/* Force Output Compare */
#if (TIMER2_MODE == TIMER_FAST_PWM || TIMER2_MODE == TIMER_PWM)
	/* CLEAR Force Output Compare pin*/
	CLR_BIT(TCCR2, FOC2);
#endif

	/* Preload value */
	TCNT2 = TIMER2_PRELOAD_VALUE;

	/* Compare value OCR0 */
	OCR2 = TIMER2_COMP_VALUE;

	/* Timer/Counter2 Overflow & Output Compare Match Interrupt Enable */
#if (TIMER2_OVF_INT <= TIMER_ENABLE && TIMER2_OVF_INT >= TIMER_DISABLE && \
		TIMER2_COMP_INT <= TIMER_ENABLE && TIMER2_COMP_INT >= TIMER_DISABLE)
	TIMSK |= ((TIMER2_OVF_INT<<6) | (TIMER2_COMP_INT<<7));

#else
#error "Wrong Timer2 Interrupt Enable selection"
#endif

	/* Clock Select / Prescaler */
#if (TIMER2_CLOCK_SELECT >= TIMER2_NO_CLOCK && TIMER2_CLOCK_SELECT <= TIMER2_CLOCK_1024)
	TCCR2 &= 0xF8;
	TCCR2 |= TIMER2_CLOCK_SELECT;

#else
#error "Wrong Timer2 Clock selection"
#endif

}

void TIMER2_voidSetPreload(u8 copy_u8Preload)
{
	/* Preload value */
	TCNT2 = copy_u8Preload;
}

void TIMER2_voidSetCompMatchValue(u8 copy_u8CompValue)
{
	/* Compare value OCR2 */
	OCR2 = copy_u8CompValue;
}

void TIMER2_voidForceOutputComp(void)
{
	SET_BIT(TCCR2, FOC2);
}

u8 TIMER2_u8Delayms(u16 copy_u16Delayms, pvFunction_t copy_pvFunc)
{
	u8 Local_u8ErrorStatus = OK;
	u32 Local_u32Value = 0;

	if(copy_pvFunc != NULL)
	{
		if(Timer2_u8Flag == IDLE)
		{
			/* Busy */
			Timer2_u8Flag = BUSY;

			/* stop the timer */
			TCCR2 &= 0xF8;
			TCCR2 |= TIMER2_NO_CLOCK;

			/* store the function to be called*/
			Timer_CallBack[TIMER2_COMP] = copy_pvFunc;

			/* Waveform Generation Mode --> CTC mode */
			/*			WGM20						WGM21				 */
			TCCR2 |= (((TIMER_CTC&0x01) << 6) | ((TIMER_CTC>>1 & 0x01) << 3));

			/* Compare Match Output Mode --> Normal */
			/*			COM20						COM21				 */
			TCCR2 |= (((TIMER_COMP_NORMAL&0x01) << 4) | ((TIMER_COMP_NORMAL>>1 & 0x01) << 5));

			/* Preload value = 0, to start from the beginning */
			TCNT2 = 0;

			/* store the delay*/
			Timer2_u16Counter = copy_u16Delayms;

			//mask prescaler bits first
			TCCR2 &= 0xF8;

			if(CPU_FREQ <= 1000000UL)
			{
				/* compare value = 250, every 1 ms interrupt happens */
				Local_u32Value = 1000UL / (1000000UL / CPU_FREQ);
				if(Local_u32Value > 255)
				{
					while(Local_u32Value > 255)
					{
						Local_u32Value /= 255;
					}
					Timer2_u16Counter *= (Local_u32Value + 1);
					OCR2 = 255;
				}
				else
					OCR2 = Local_u32Value;
				/* Timer/Counter2 Output Compare Match Interrupt Enable */
				TIMSK |= (TIMER_ENABLE<<7);

				/* start the timer by prescaler /64 ... tick time = 4 us*/
				TCCR2 |= TIMER2_NO_PRESCALER;
			}
			else if(CPU_FREQ <= 8000000UL)
			{
				/* compare value = 250, every 1 ms interrupt happens */
				Local_u32Value = 1000UL / (8000000UL / CPU_FREQ);
				if(Local_u32Value > 255)
				{
					while(Local_u32Value > 255)
					{
						Local_u32Value /= 255;
					}
					Timer2_u16Counter *= (Local_u32Value + 1);
					OCR2 = 255;
				}
				else
					OCR2 = Local_u32Value;
				/* Timer/Counter2 Output Compare Match Interrupt Enable */
				TIMSK |= (TIMER_ENABLE<<7);

				/* start the timer by prescaler /64 ... tick time = 4 us*/
				TCCR2 |= TIMER2_CLOCK_8;
			}
			else if(CPU_FREQ <= 32000000UL)
			{
				/* compare value = 250, every 1 ms interrupt happens */
				Local_u32Value = 1000UL / (32000000UL / CPU_FREQ);
				if(Local_u32Value > 255)
				{
					while(Local_u32Value > 255)
					{
						Local_u32Value /= 255;
					}
					Timer2_u16Counter *= (Local_u32Value + 1);
					OCR2 = 255;
				}
				else
					OCR2 = Local_u32Value;
				/* Timer/Counter2 Output Compare Match Interrupt Enable */
				TIMSK |= (TIMER_ENABLE<<7);

				/* start the timer by prescaler /64 ... tick time = 4 us*/
				TCCR2 |= TIMER2_CLOCK_32;
			}
			else if(CPU_FREQ <= 64000000UL)
			{
				/* compare value = 250, every 1 ms interrupt happens */
				Local_u32Value = 1000UL / (64000000UL / CPU_FREQ);
				if(Local_u32Value > 255)
				{
					while(Local_u32Value > 255)
					{
						Local_u32Value /= 255;
					}
					Timer2_u16Counter *= (Local_u32Value + 1);
					OCR2 = 255;
				}
				else
					OCR2 = Local_u32Value;
				/* Timer/Counter2 Output Compare Match Interrupt Enable */
				TIMSK |= (TIMER_ENABLE<<7);

				/* start the timer by prescaler /64 ... tick time = 4 us*/
				TCCR2 |= TIMER2_CLOCK_64;
			}
			else if(CPU_FREQ <= 128000000UL)
			{
				/* compare value = 250, every 1 ms interrupt happens */
				Local_u32Value = 1000UL / (128000000UL / CPU_FREQ);
				if(Local_u32Value > 255)
				{
					while(Local_u32Value > 255)
					{
						Local_u32Value /= 255;
					}
					Timer2_u16Counter *= (Local_u32Value + 1);
					OCR2 = 255;
				}
				else
					OCR2 = Local_u32Value;


				/* Timer/Counter2 Output Compare Match Interrupt Enable */
				TIMSK |= (TIMER_ENABLE<<7);

				/* start the timer by prescaler /64 ... tick time = 4 us*/
				TCCR2 |= TIMER2_CLOCK_128;
			}
			else if(CPU_FREQ <= 256000000UL)
			{
				/* compare value = 250, every 1 ms interrupt happens */
				Local_u32Value = 1000UL / (256000000UL / CPU_FREQ);
				if(Local_u32Value > 255)
				{
					while(Local_u32Value > 255)
					{
						Local_u32Value /= 255;
					}
					Timer2_u16Counter *= (Local_u32Value + 1);
					OCR2 = 255;
				}
				else
					OCR2 = Local_u32Value;
				/* Timer/Counter2 Output Compare Match Interrupt Enable */
				TIMSK |= (TIMER_ENABLE<<7);

				/* start the timer by prescaler /64 ... tick time = 4 us*/
				TCCR2 |= TIMER2_CLOCK_256;
			}
			else if(CPU_FREQ <= 1024000000UL)
			{
				/* compare value = 250, every 1 ms interrupt happens */
				Local_u32Value = 1000UL / (1024000000UL / CPU_FREQ);
				if(Local_u32Value > 255)
				{
					while(Local_u32Value > 255)
					{
						Local_u32Value /= 255;
					}
					Timer2_u16Counter *= (Local_u32Value + 1);
					OCR2 = 255;
				}
				else
					OCR2 = Local_u32Value;
				/* Timer/Counter2 Output Compare Match Interrupt Enable */
				TIMSK |= (TIMER_ENABLE<<7);

				/* start the timer by prescaler /64 ... tick time = 4 us*/
				TCCR2 |= TIMER2_CLOCK_1024;
			}

		}
		else
			Local_u8ErrorStatus = TIMER_E_BUSY;

	}
	else
		Local_u8ErrorStatus = TIMER_E_PARAM_POINTER;

	return Local_u8ErrorStatus;
}

void TIMER2_voidStop(void)
{
	/* Clock Select / Prescaler */
	TCCR2 &= 0xFC;
	TCCR2 |= TIMER2_NO_CLOCK;
}


/********************	 Timers interrupt functions		****************/
u8 TIMER_u8EnableInterrupt(u8 copy_u8IntSource)
{
	u8 Local_u8ErrorStatus = OK;

	if(copy_u8IntSource >= TIMER0_OVF || copy_u8IntSource <= TIMER2_COMP)
	{
		SET_BIT(TIMSK, copy_u8IntSource);
	}
	else
		Local_u8ErrorStatus = TIMER_E_PARAM_INVALID_INT_ID;

	return Local_u8ErrorStatus;
}

u8 TIMER_u8DisableInterrupt(u8 copy_u8IntSource)
{
	u8 Local_u8ErrorStatus = OK;

	if(copy_u8IntSource >= TIMER0_OVF || copy_u8IntSource <= TIMER2_COMP)
	{
		CLR_BIT(TIMSK, copy_u8IntSource);
	}
	else
		Local_u8ErrorStatus = TIMER_E_PARAM_INVALID_INT_ID;

	return Local_u8ErrorStatus;
}

u8 TIMER_u8SetCallBack(u8 copy_u8TimerSource, pvFunction_t copy_pvFunc)
{
	u8 Local_u8ErrorStatus = OK;

	if(copy_u8TimerSource >= TIMER0_OVF && copy_u8TimerSource <= TIMER2_COMP)
	{
		if(copy_pvFunc != NULL)
		{
			Timer_CallBack[copy_u8TimerSource] = copy_pvFunc;
		}
		else
			Local_u8ErrorStatus = TIMER_E_PARAM_POINTER;
	}
	else
		Local_u8ErrorStatus = TIMER_E_PARAM_INVALID_INT_ID;

	return Local_u8ErrorStatus;
}

/******************************************************************************
 * !comment  :  ISR Function TIMER. 						 			      *
 ******************************************************************************/
/* Timer/Counter0 Overflow */
void __vector_11 (void) __attribute__((signal));
void __vector_11 (void)
{
	if(Timer_CallBack[TIMER0_OVF] != NULL)
	{
		Timer_CallBack[TIMER0_OVF]();
	}
}

/* Timer/Counter0 Compare Match */
void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	if(Timer_CallBack[TIMER0_COMP] != NULL)
	{
		Timer_CallBack[TIMER0_COMP]();
	}
}

/* Timer/Counter1 Overflow */
void __vector_9 (void) __attribute__((signal));
void __vector_9 (void)
{
	if(Timer_CallBack[TIMER1_OVF] != NULL)
	{
		Timer_CallBack[TIMER1_OVF]();
	}
}

/* Timer/Counter1 Compare Match B */
void __vector_8 (void) __attribute__((signal));
void __vector_8 (void)
{
	if(Timer_CallBack[TIMER1_COMPB] != NULL)
	{
		Timer_CallBack[TIMER1_COMPB]();
	}
}

/* Timer/Counter1 Compare Match A */
void __vector_7 (void) __attribute__((signal));
void __vector_7 (void)
{
	if(Timer_CallBack[TIMER1_COMPA] != NULL)
	{
		Timer_CallBack[TIMER1_COMPA]();
	}
}

/* Timer/Counter1 Capture Event */
void __vector_6 (void) __attribute__((signal));
void __vector_6 (void)
{
	if(Timer_CallBack[TIMER1_CAPT] != NULL)
	{
		Timer_CallBack[TIMER1_CAPT]();
	}
}

/* Timer/Counter2 Overflow */
void __vector_5 (void) __attribute__((signal));
void __vector_5 (void)
{
	if(Timer_CallBack[TIMER2_OVF] != NULL)
	{
		Timer_CallBack[TIMER2_OVF]();
	}
}

/* Timer/Counter2 Compare Match */
void __vector_4 (void) __attribute__((signal));
void __vector_4 (void)
{
	Timer2_u16DelayCounter++;

	if(Timer2_u16DelayCounter == Timer2_u16Counter)
	{
		if(Timer_CallBack[TIMER2_COMP] != NULL)
		{
			Timer_CallBack[TIMER2_COMP]();
		}

		Timer2_u16DelayCounter = 0;
		Timer2_u8Flag = IDLE;

		/* Timer/Counter2 Output Compare Match Interrupt Disable */
		CLR_BIT(TIMSK, TIMER2_COMP);

		/* stop the timer */
		TCCR2 &= 0xFC;
		TCCR2 |= TIMER2_NO_CLOCK;
	}


}
