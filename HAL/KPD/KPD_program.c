/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: HAL					*********************************/
/********************			SWC: KPD					*********************************/
/********************			Version: 1.00				*********************************/
/********************			Date: 8 Aug 2023			*********************************/
/********************************************************************************************/
/********************************************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "KPD_interface.h"
#include "KPD_private.h"
#include "KPD_config.h"

void KPD_voidInit (void)
{
	u8 Local_u8ArrRows[KPD_ROWS_SIZE] = KPD_ROW_ARRAY;
	u8 Local_u8ArrColumns[KPD_COLUMNS_SIZE] = KPD_COLUMN_ARRAY;
	u8 Local_u8Iterator;
	for (Local_u8Iterator = 0; Local_u8Iterator < KPD_COLUMNS_SIZE; Local_u8Iterator++)
	{
		DIO_enumSetPinValue(Local_u8ArrColumns[Local_u8Iterator], DIO_HIGH);
	}
	for (Local_u8Iterator = 0; Local_u8Iterator < KPD_ROWS_SIZE; Local_u8Iterator++)
	{
		DIO_enumPullup(Local_u8ArrRows[Local_u8Iterator], DIO_ACTIVATE_PULLUP);
	}
}

u8 KPD_u8GetPressedKey (void)
{
	u8 Local_u8PressedKey = KPD_NOT_PRESSED, Local_u8Location[KPD_ROWS_SIZE][KPD_COLUMNS_SIZE] = KPD_ARRAY_VALUES, Local_u8ColumnIndex, Local_u8RowIndex, Local_u8Pressed = 1;
	u8 Local_u8ArrRows[KPD_ROWS_SIZE] = KPD_ROW_ARRAY;
	u8 Local_u8ArrColumns[KPD_COLUMNS_SIZE] = KPD_COLUMN_ARRAY;
	for (Local_u8ColumnIndex = 0; Local_u8ColumnIndex < KPD_COLUMNS_SIZE; Local_u8ColumnIndex++)
	{
		DIO_enumSetPinValue(Local_u8ArrColumns[Local_u8ColumnIndex], DIO_LOW);
		for (Local_u8RowIndex = 0; Local_u8RowIndex < KPD_ROWS_SIZE; Local_u8RowIndex++)
		{
			DIO_enumGetPinValue(Local_u8ArrRows[Local_u8RowIndex], &Local_u8Pressed);
			if (Local_u8Pressed == 0)
			{
				while (Local_u8Pressed == 0)
				{
					DIO_enumGetPinValue(Local_u8ArrRows[Local_u8RowIndex], &Local_u8Pressed);
				}
				Local_u8PressedKey = Local_u8Location[Local_u8RowIndex][Local_u8ColumnIndex];
			}
		}
		DIO_enumSetPinValue(Local_u8ArrColumns[Local_u8ColumnIndex], DIO_HIGH);
	}
	return Local_u8PressedKey;
}
