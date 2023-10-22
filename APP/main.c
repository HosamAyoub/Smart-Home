/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Date: 15 Aug 2023			*********************************/
/********************************************************************************************/
/********************************************************************************************/
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/USART/USART_interface.h"
#include "../MCAL/TWI/TWI_interface.h"
#include "../MCAL/SPI/SPI_interface.h"
#include "../HAL/LCD/LCD_interface.h"
#include "../HAL/EEPROM/EEPROM_interface.h"
#include <util/delay.h>

void SendData (u8 *Pointer_u8Arr);
void ReceivedData (u8 *Pointer_u8Arr);
u8 arr[4] = {'0', '1', '2', '3'};
u8 Received[4];

void main (void)
{
	DIO_voidInit();
	LCD_voidInit();
	TWI_voidMasterInit(0);
	SendData(arr);
	ReceivedData(Received);
	for (u8 Local_u8Iterator = 0; Local_u8Iterator < 4; Local_u8Iterator++)
	{
		LCD_voidSendData(0, Received[Local_u8Iterator]);
	}
}

void SendData (u8 *Pointer_u8Arr)
{
	for (u8 Local_u8Iterator = 0; Local_u8Iterator < 4; Local_u8Iterator++)
	{
		EEPROM_voidSendDataByte(Local_u8Iterator, Pointer_u8Arr[Local_u8Iterator]);
		_delay_ms(1);
	}
}

void ReceivedData (u8 *Pointer_u8Arr)
{
	u8 Rec;
	for (u8 Local_u8Iterator = 0; Local_u8Iterator < 4; Local_u8Iterator++)
	{
		EEPROM_voidReadDataByte(Local_u8Iterator, &(Pointer_u8Arr[Local_u8Iterator]));
		_delay_ms(1);
	}
}
