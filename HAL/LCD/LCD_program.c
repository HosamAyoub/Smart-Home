/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: HAL					*********************************/
/********************			SWC: LCD					*********************************/
/********************			Version: 2.00				*********************************/
/********************			Date: 31 Aug 2023			*********************************/
/********************************************************************************************/
/********************************************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"
#include <util/delay.h>

extern tstrLCD LCDarray[NUMBER_OF_LCD];

void LCD_voidInit (void)
{
	u8 Local_u8Iterator, Local_u8Command;
	for (Local_u8Iterator = 0; Local_u8Iterator < NUMBER_OF_LCD; Local_u8Iterator++)
	{
		if (LCDarray[Local_u8Iterator].LCDConfig.u8Mode == LCD_8BIT_MODE)
		{
			_delay_ms(40);
			Local_u8Command = 0b00110000 | LCDarray[Local_u8Iterator].LCDConfig.u8Line << 3 | LCDarray[Local_u8Iterator].LCDConfig.u8Font << 2;
			LCD_voidSendCommand (Local_u8Iterator, Local_u8Command);
			Local_u8Command = 0b00001000 | LCDarray[Local_u8Iterator].LCDConfig.u8Display << 2 | LCDarray[Local_u8Iterator].LCDConfig.u8CursorState << 1 | LCDarray[Local_u8Iterator].LCDConfig.u8BlinkState << 0;
			LCD_voidSendCommand (Local_u8Iterator, Local_u8Command);
			Local_u8Command = 0b00000001;
			LCD_voidSendCommand (Local_u8Iterator, Local_u8Command);
			Local_u8Command = 0b00000100 | LCDarray[Local_u8Iterator].LCDConfig.u8CursorDirection << 1 | LCDarray[Local_u8Iterator].LCDConfig.u8Shift << 0;
			LCD_voidSendCommand (Local_u8Iterator, Local_u8Command);
		}
		else if (LCDarray[Local_u8Iterator].LCDConfig.u8Mode == LCD_4BIT_MODE)
		{
			_delay_ms(40);
			Local_u8Command = 0b00000010;
			LCD_voidSendCommand (Local_u8Iterator, Local_u8Command);
			Local_u8Command = 0b00100000 | LCDarray[Local_u8Iterator].LCDConfig.u8Line << 3 | LCDarray[Local_u8Iterator].LCDConfig.u8Font << 2;
			LCD_voidSendCommand (Local_u8Iterator, Local_u8Command);
			Local_u8Command = 0b00001000 | LCDarray[Local_u8Iterator].LCDConfig.u8Display << 2 | LCDarray[Local_u8Iterator].LCDConfig.u8CursorState << 1 | LCDarray[Local_u8Iterator].LCDConfig.u8BlinkState << 0;
			LCD_voidSendCommand (Local_u8Iterator, Local_u8Command);
			Local_u8Command = 0b00000001;
			LCD_voidSendCommand (Local_u8Iterator, Local_u8Command);
			Local_u8Command = 0b00000100 | LCDarray[Local_u8Iterator].LCDConfig.u8CursorDirection << 1 | LCDarray[Local_u8Iterator].LCDConfig.u8Shift << 0;
			LCD_voidSendCommand (Local_u8Iterator, Local_u8Command);
		}
	}
}

void LCD_voidSendCommand (u8 Copy_u8Index, u8 Copy_u8Command)
{
	u8 Local_u8Iterator;
	DIO_enumSetPinValue(LCDarray[Copy_u8Index].LCDConnections.u8RS_Pin, DIO_LOW);
	DIO_enumSetPinValue(LCDarray[Copy_u8Index].LCDConnections.u8RW_Pin, DIO_LOW);
	if (LCDarray[Copy_u8Index].LCDConfig.u8Mode == LCD_8BIT_MODE)
	{
		for (Local_u8Iterator = 0; Local_u8Iterator  < 8; Local_u8Iterator++)
		{
			DIO_enumSetPinValue(LCDarray[Copy_u8Index].LCDConnections.au8Pins[Local_u8Iterator], GET_BIT(Copy_u8Command, Local_u8Iterator));
		}

	}
	else if (LCDarray[Copy_u8Index].LCDConfig.u8Mode == LCD_4BIT_MODE)
	{
		for (Local_u8Iterator = 4; Local_u8Iterator  < 8; Local_u8Iterator++)
		{
			DIO_enumSetPinValue(LCDarray[Copy_u8Index].LCDConnections.au8Pins[Local_u8Iterator], GET_BIT(Copy_u8Command, Local_u8Iterator));
		}

		DIO_enumSetPinValue(LCDarray[Copy_u8Index].LCDConnections.u8EN_Pin, DIO_HIGH);
		_delay_ms(2);
		DIO_enumSetPinValue(LCDarray[Copy_u8Index].LCDConnections.u8EN_Pin, DIO_LOW);

		for (Local_u8Iterator = 0; Local_u8Iterator  < 4; Local_u8Iterator++)
		{
			DIO_enumSetPinValue(LCDarray[Copy_u8Index].LCDConnections.au8Pins[4 + Local_u8Iterator], GET_BIT(Copy_u8Command, Local_u8Iterator));
		}
	}
	DIO_enumSetPinValue(LCDarray[Copy_u8Index].LCDConnections.u8EN_Pin, DIO_HIGH);
	_delay_ms(2);
	DIO_enumSetPinValue(LCDarray[Copy_u8Index].LCDConnections.u8EN_Pin, DIO_LOW);
}

void LCD_voidSendData (u8 Copy_u8Index, u8 Copy_u8Data)
{
	u8 Local_u8Iterator;
	DIO_enumSetPinValue(LCDarray[Copy_u8Index].LCDConnections.u8RS_Pin, DIO_HIGH);
	DIO_enumSetPinValue(LCDarray[Copy_u8Index].LCDConnections.u8RW_Pin, DIO_LOW);
	if (LCDarray[Copy_u8Index].LCDConfig.u8Mode == LCD_8BIT_MODE)
	{
		for (Local_u8Iterator = 0; Local_u8Iterator  < 8; Local_u8Iterator++)
		{
			DIO_enumSetPinValue(LCDarray[Copy_u8Index].LCDConnections.au8Pins[Local_u8Iterator], GET_BIT(Copy_u8Data, Local_u8Iterator));
		}
	}
	else if (LCDarray[Copy_u8Index].LCDConfig.u8Mode == LCD_4BIT_MODE)
	{
		for (Local_u8Iterator = 4; Local_u8Iterator  < 8; Local_u8Iterator++)
		{
			DIO_enumSetPinValue(LCDarray[Copy_u8Index].LCDConnections.au8Pins[Local_u8Iterator], GET_BIT(Copy_u8Data, Local_u8Iterator));
		}

		DIO_enumSetPinValue(LCDarray[Copy_u8Index].LCDConnections.u8EN_Pin, DIO_HIGH);
		_delay_ms(2);
		DIO_enumSetPinValue(LCDarray[Copy_u8Index].LCDConnections.u8EN_Pin, DIO_LOW);

		for (Local_u8Iterator = 0; Local_u8Iterator  < 4; Local_u8Iterator++)
		{
			DIO_enumSetPinValue(LCDarray[Copy_u8Index].LCDConnections.au8Pins[4 + Local_u8Iterator], GET_BIT(Copy_u8Data, Local_u8Iterator));
		}
	}
	DIO_enumSetPinValue(LCDarray[Copy_u8Index].LCDConnections.u8EN_Pin, DIO_HIGH);
	_delay_ms(2);
	DIO_enumSetPinValue(LCDarray[Copy_u8Index].LCDConnections.u8EN_Pin, DIO_LOW);
}

void LCD_voidSendString (u8 Copy_u8Index, const u8 *pu8String)
{
	u8 Local_u8Iterator;
	for (Local_u8Iterator = 0; pu8String[Local_u8Iterator] != '\0'; Local_u8Iterator++)
	{
		LCD_voidSendData(Copy_u8Index, pu8String[Local_u8Iterator]);
	}
}

void LCD_voidClearScreen (u8 Copy_u8Index)
{
	LCD_voidSendCommand(Copy_u8Index, 0x01);
}

void LCD_voidSendNumber (u8 Copy_u8Index, u32 Copy_u32Number)
{
	u64 Local_u64Number = 1;
	if (Copy_u32Number == 0)
	{
		LCD_voidSendData(Copy_u8Index, '0');
	}
	else if (Copy_u32Number < 0)
	{
		LCD_voidSendData(Copy_u8Index, '-');
	}
	else
	{
		while (Copy_u32Number != 0)
		{
			Local_u64Number = (Local_u64Number * 10) + (Copy_u32Number%10);
			Copy_u32Number /= 10;
		}
		while (Local_u64Number != 1)
		{
			LCD_voidSendData(Copy_u8Index, Local_u64Number%10 + '0');
			Local_u64Number /= 10;
		}
	}
}



void LCD_voidGoTo (u8 Copy_u8Index, u8 Copy_u8Row, u8 Copy_u8Column)
{
	u8 Local_u8Address;
	Local_u8Address = (Copy_u8Row * 0x40) + Copy_u8Column;
	SET_BIT(Local_u8Address, 7);
	LCD_voidSendCommand(Copy_u8Index, Local_u8Address);
}

void LCD_voidDecimalToBinary (u8 Copy_u8Index, u8 Copy_u8Number)
{
	LCD_voidSendData(Copy_u8Index, '0');
	LCD_voidSendData(Copy_u8Index, 'b');
	for (u8 i = sizeof(u8) * 8; i > 0; i--)
	{
		LCD_voidSendData(Copy_u8Index, ((Copy_u8Number >> (i - 1)) & 1) + '0');
	}
}
