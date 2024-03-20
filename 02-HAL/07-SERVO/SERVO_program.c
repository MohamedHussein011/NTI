/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: SERVO_program.c		            ************************/
/***************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "User_Functions.h"

#include "TIMER_interface.h"

#include "SERVO_interface.h"


/********************************				Function Definitions				********************************/

u8 SERVO_u8SetAngle (u8 copy_u8Angle)
{
	u8 Local_u8ErrorState = OK;
	f32 Local_f32Duty = 0;

	if(copy_u8Angle <= 180)
	{
		Local_f32Duty = (f32) s32Map(0,180,50,100,copy_u8Angle);
		TIMER1_voidGeneratePWM(20,Local_f32Duty);
	}
	else
		Local_u8ErrorState = SERVO_E_PARAM_ANGLE_ID;

	return Local_u8ErrorState;
}

void SERVO_voidStop (void)
{
	TIMER1_voidStop();
}
