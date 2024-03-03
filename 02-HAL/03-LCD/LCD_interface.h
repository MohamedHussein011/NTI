/***************************************************************************************/
/*************             Author: Mohamed Hussein              ************************/
/*************             File: LCD_interface.h	            ************************/
/***************************************************************************************/
// LCD 4*20
// LCD 2*16

#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

/* Modes of Initialization
   Options:
		1: EightBit_Init
		2: FourBit_Init
 */
#define EightBit_Init         0
#define FourBit_Init          1

/* Number of Lines
   Options:
		1: One_Line
		2: Two_Lines
 */
#define One_Line         0
#define Two_Lines        1

/* Font Size
   Options:
		1: FiveEight_Size
		2: FiveEleven_Size
 */
#define FiveEight_Size        0
#define FiveEleven_Size       1

/* Display On/Off
   Options:
		1: Display_ON
		2: Display_OFF
 */
#define Display_ON        0
#define Display_OFF       1

/* Cursor On/Off
   Options:
		1: Cursor_ON
		2: Cursor_OFF
 */
#define Cursor_ON       0
#define Cursor_OFF      1

/* Blinking On/Off
   Options:
		1: Blinking_ON
		2: Blinking_OFF
 */
#define Blinking_ON       0
#define Blinking_OFF      1

/*Control Instruction*/
#define CLEAR_DISPLAY       0x01
#define RETURN_HOME         0x02
#define ENTRY_MODE_SET      0x06
#define RESET               0x30
#define CURSOR_OFFEST       0x80
#define OneLine_5x8_8Bit    0x30
#define OneLine_5x8_4Bit    0x00
#define OneLine_5x11_8Bit   0x34
#define OneLine_5x11_4Bit   0x04
#define TwoLine_5x8_8Bit    0x38
#define TwoLine_5x8_4Bit    0x08
#define TwoLine_5x11_8Bit   0x3c
#define TwoLine_5x11_4Bit   0x0C
#define DisplayOn_CursorOn_BlinkingOn        0x0F
#define DisplayOn_CursorOn_BlinkingOff       0x0E
#define DisplayOn_CursorOff_BlinkingOn       0x0D
#define DisplayOn_CursorOff_BlinkingOff      0x0C
#define DisplayOff_CursorOn_BlinkingOn       0x0B
#define DisplayOff_CursorOn_BlinkingOff      0x0A
#define DisplayOff_CursorOff_BlinkingOn      0x09
#define DisplayOff_CursorOff_BlinkingOff     0x08


/*ROWs*/
#define LCD_ROW0            0
#define LCD_ROW1            1
#define LCD_ROW2            2
#define LCD_ROW3            3

/*Columns*/
#define LCD_COL0            0
#define LCD_COL1            1
#define LCD_COL2            2
#define LCD_COL3            3
#define LCD_COL4            4
#define LCD_COL5            5
#define LCD_COL6            6
#define LCD_COL7            7
#define LCD_COL8            8
#define LCD_COL9            9
#define LCD_COL10           10
#define LCD_COL11           11
#define LCD_COL12           12
#define LCD_COL13           13
#define LCD_COL14           14
#define LCD_COL15           15
#define LCD_COL16           16
#define LCD_COL17           17
#define LCD_COL18           18
#define LCD_COL19           19

void LCD_voidInit(void);

void LCD_voidSendCommand(u8 Copy_u8Command);
void LCD_voidClearDisplay(void);

void LCD_voidSendCharacter(u8 Copy_u8Character);
void LCD_voidSendString(const char* Copy_pchString);
void LCD_voidCreateCustomunCharacter(const u8 *Copy_pu8Pattern, u8 Copy_u8Location);
void LCD_voidSendCustomunCharacter(u8 Copy_u8Location, u8 Copy_u8Row, u8 Copy_u8Col);

void LCD_voidGoToRowCol (u8 Copy_u8Row, u8 Copy_u8Col);

void LCD_voidSendNumber(s32 Copy_s32Number);


#endif 
