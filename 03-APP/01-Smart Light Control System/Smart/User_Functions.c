/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: User_Functions.c	            ************************/
/***************************************************************************************/


#include "STD_TYPES.h"
#include "User_Functions.h"


s32 s32Map (s32 InputMin, s32 InputMax, s32 OutputMin, s32 OutputMax, s32 InputValue)
{
	/*y is output, x is input
	 * (y-y1)/(x-x1) = (y2-y1)/(x2-x1)
	 * */
	s32 s32Local_OutputDiference = OutputMax - OutputMin;
	s32 s32Local_InputDiference = InputMax - InputMin;
	s32 s32Local_InputCalculation = InputValue - InputMin;

	s32 s32Local_Output = (s32) ((s32Local_OutputDiference * s32Local_InputCalculation) / s32Local_InputDiference);
	s32Local_Output += OutputMin;

	if(s32Local_Output <= OutputMin)
		return OutputMin;
	else if(s32Local_Output >= OutputMax)
		return OutputMax;
	else
		return s32Local_Output;

}


void ConvertToString(char* Copy_String, s32 s32Copy_Number)
{
	s32 s32Local_Temp1 = 0, s32Local_Length = 0, s32Local_Remainder = 0, s32Local_Temp2 = 0;

	if(s32Copy_Number == 0)
	{
		Copy_String[0] = '0';
		s32Local_Length++;
		Copy_String[s32Local_Length] = '\0';
	}
	else
	{
		s32Local_Temp2 = s32Copy_Number;
		if(s32Local_Temp2<0)
		{
			s32Local_Length++;
			s32Copy_Number *= -1;
		}

		s32Local_Temp1 = s32Copy_Number;
		while(s32Local_Temp1 > 0)
		{
			s32Local_Temp1 /= 10;
			s32Local_Length++;
		}

		for(u8 i = 0; i<s32Local_Length; i++)
		{
			s32Local_Remainder = s32Copy_Number % 10;
			s32Copy_Number = s32Copy_Number / 10;
			Copy_String[s32Local_Length - (i+1)] = s32Local_Remainder + '0';
		}

		if(s32Local_Temp2 < 0)
			Copy_String[0] = '-';

		Copy_String[s32Local_Length] = '\0';
	}
}
s32 ConvertToint(const char* Copy_String, u8 copy_u8Len)
{
	s32 s32Local_Number = 0;
	s8 u8Local_sign = 1, u8Local_Iterator = 0;
	if(Copy_String[0] == '-')
	{
		u8Local_sign = -1;
		u8Local_Iterator = 1;
	}

	while(Copy_String[u8Local_Iterator] != '\0' && u8Local_Iterator < copy_u8Len)
	{
		if((Copy_String[u8Local_Iterator] - '0' < 0) || (Copy_String[u8Local_Iterator] - '0' > 9))
			break;
		s32Local_Number = (s32Local_Number*10) + (Copy_String[u8Local_Iterator] - '0');
		u8Local_Iterator++;
	}

	s32Local_Number *= u8Local_sign;
	return s32Local_Number;
}

u8 StringCompare(const char* pu8Copy_String1, const char* pu8Copy_String2)
{
	u8 u8Local_Flag = 0;

	while(*pu8Copy_String1 != '\0' || *pu8Copy_String2 != '\0')
	{
		if(*pu8Copy_String1 == *pu8Copy_String2)
		{
			pu8Copy_String1++;
			pu8Copy_String2++;
		}
		else if((*pu8Copy_String1 == '\0' && *pu8Copy_String2 != '\0') || (*pu8Copy_String1 != '\0' && *pu8Copy_String2 == '\0') || (*pu8Copy_String1 != *pu8Copy_String2))
		{
			u8Local_Flag=1;
			break;
		}

	}
	if(u8Local_Flag == 0)
		return 0;
	else
		return 1;
}

u8 StringLength(const char* pu8Copy_String)
{
	u16 u16LocalCounter = 0;
	while (*pu8Copy_String != 0 || *pu8Copy_String != '\0')
	{
		u16LocalCounter++;
		pu8Copy_String++;
	}

	return u16LocalCounter;
}

void StringReset(char* pu8Copy_String)
{
	u16 u16LocalCounter = 0;
	u16 u16LocalLength = 0;
	u16LocalLength = StringLength(pu8Copy_String);
	while(u16LocalCounter < u16LocalLength)
	{
		*(pu8Copy_String + u16LocalCounter) = 0;
		u16LocalCounter++;
	}
}
