/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: User_Functions.h	            ************************/
/***************************************************************************************/

#ifndef _USER_FUNCTIONS_H
#define _USER_FUNCTIONS_H

s32 s32Map (s32 InputMin, s32 InputMax, s32 OutputMin, s32 OutputMax, s32 InputValue);

void ConvertToString(char* Copy_String, s32 s32Copy_Number);
s32 ConvertToint(const char* Copy_String, u8 copy_u8Len);

u8 StringCompare(const char* pu8Copy_String1, const char* pu8Copy_String2);
u8 StringLength(const char* pu8Copy_String);
void StringReset(char* pu8Copy_String);

#endif
