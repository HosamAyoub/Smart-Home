/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: HAL					*********************************/
/********************			SWC: LCD					*********************************/
/********************			Version: 2.00				*********************************/
/********************			Date: 31 Aug 2023			*********************************/
/********************************************************************************************/
/********************************************************************************************/
#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_

void LCD_voidInit (void);
void LCD_voidSendData (u8 Copy_u8Index, u8 Copy_u8Data);
void LCD_voidSendCommand (u8 Copy_u8Index, u8 Copy_u8Command);
void LCD_voidSendString (u8 Copy_u8Index, const u8 *pu8String);
void LCD_voidClearScreen (u8 Copy_u8Index);
void LCD_voidSendNumber (u8 Copy_u8Index, u32 Copy_u32Number);
void LCD_voidGoTo (u8 Copy_u8Index, u8 Copy_u8Row, u8 Copy_u8Column);
void LCD_voidDecimalToBinary (u8 Copy_u8Index, u8 Copy_u8Number);

#define LCD_4BIT_MODE						1
#define LCD_8BIT_MODE						0

#define LCD_ONE_LINE						0
#define LCD_TWO_LINES						1

#define LCD_FONT_5x7						0
#define LCD_FONT_5x10						1

#define LCD_CURSOR_OFF						0
#define LCD_CURSOR_ON						1

#define LCD_CURSOR_BLINK_OFF				0
#define LCD_CURSOR_BLINK_ON					1

#define LCD_SHIFT_OFF						0
#define LCD_SHIFT_ON						1

#define LCD_DISPLAY_OFF						0
#define LCD_DISPLAY_ON						1

#define LCD_CURSOR_LEFT						0
#define LCD_CURSOR_RIGHT					1


#endif /* HAL_LCD_LCD_INTERFACE_H_ */
