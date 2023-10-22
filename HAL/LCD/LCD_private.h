/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: HAL					*********************************/
/********************			SWC: LCD					*********************************/
/********************			Version: 2.00				*********************************/
/********************			Date: 31 Aug 2023			*********************************/
/********************************************************************************************/
/********************************************************************************************/
#ifndef HAL_LCD_LCD_PRIVATE_H_
#define HAL_LCD_LCD_PRIVATE_H_

typedef struct
{
	u8 u8Mode 			    : 1;
	u8 u8Line 			    : 1;
	u8 u8Font 			    : 1;
	u8 u8CursorState 	    : 1;
	u8 u8BlinkState 	    : 1;
	u8 u8Shift		 	    : 1;
	u8 u8Display 		    : 1;
	u8 u8CursorDirection	: 1;
}tstrLCDConfig;

typedef struct
{
	u8 u8RS_Pin;
	u8 u8RW_Pin;
	u8 u8EN_Pin;
	u8 au8Pins[8];
}tstrLCDConnections;

typedef struct
{
	tstrLCDConfig LCDConfig;
	tstrLCDConnections LCDConnections;
}tstrLCD;

#endif /* HAL_LCD_LCD_PRIVATE_H_ */
