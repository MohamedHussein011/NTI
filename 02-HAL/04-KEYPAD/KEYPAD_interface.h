/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: KEYPAD_interface.h	            ************************/
/***************************************************************************************/

#ifndef KEYPAD_INTERFACE_H
#define KEYPAD_INTERFACE_H

                             /*************** INPUT TYPE ***************/
#define KEYPAD_INPUT_PULLUP			0				//your keypad input pins is pull up by software
#define KEYPAD_INPUT_PU				1				//your keypad input pins is pull up by hardware
#define KEYPAD_INPUT_PD				2				//your keypad input pins is pull down by hardware

                             /*************** CONTROL ***************/
#define COL_CONTROL				0
#define ROW_CONTROL				1

                             /*************** APIs ***************/
void KEYPAD_voidInit (void);
u8 KEYPAD_u8GetPressedKey (void);

#endif 
