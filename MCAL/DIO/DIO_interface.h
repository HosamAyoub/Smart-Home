/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: MCAL					*********************************/
/********************			SWC: DIO					*********************************/
/********************			Version: 1.00				*********************************/
/********************			Date: 2 Aug 2023			*********************************/
/********************************************************************************************/
/********************************************************************************************/
#ifndef MCAL_DIO_INTERFACE_H_
#define MCAL_DIO_INTERFACE_H_

//tenumErrorStatus DIO_enumSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction);
//tenumErrorStatus DIO_enumSetPortValue(u8 Copy_u8Port, u8 Copy_u8Value);

//tenumErrorStatus DIO_enumSetPinDirection(u8 Copy_u8Pin, u8 Copy_u8Direction);
void DIO_voidInit (void);
tenumErrorStatus DIO_enumSetPinValue (u8 Copy_u8Pin, u8 Copy_u8Value);
tenumErrorStatus DIO_enumGetPinValue (u8 Copy_u8Pin, u8 *Pu8PinValue);
tenumErrorStatus DIO_enumPullup (u8 Copy_u8Pin, u8 Copy_u8State);
tenumErrorStatus DIO_enumSetGroupValue (u8 *Pau8Pins, u8 *Pau8Values, u8 Copy_u8Size);
tenumErrorStatus DIO_enumSetPortValue (u8 Copy_u8Port, u8 Copy_u8Value);


#define DIO_INPUT	 0
#define DIO_OUTPUT	 1

#define DIO_LOW				    0
#define DIO_HIGH			    1

/* Pullup state */
#define DIO_DEACTIVATE_PULLUP   DIO_LOW
#define DIO_ACTIVATE_PULLUP     DIO_HIGH

/* PORT A */
#define DIO_PA0				    0
#define DIO_PA1                 1
#define DIO_PA2                 2
#define DIO_PA3                 3
#define DIO_PA4                 4
#define DIO_PA5                 5
#define DIO_PA6                 6
#define DIO_PA7                 7

/* PORT B */
#define DIO_PB0                 8
#define DIO_PB1                 9
#define DIO_PB2                 10
#define DIO_PB3                 11
#define DIO_PB4                 12
#define DIO_PB5                 13
#define DIO_PB6                 14
#define DIO_PB7                 15

/* PORT C */
#define DIO_PC0                 16
#define DIO_PC1                 17
#define DIO_PC2                 18
#define DIO_PC3                 19
#define DIO_PC4                 20
#define DIO_PC5                 21
#define DIO_PC6                 22
#define DIO_PC7                 23

/* PORT D */
#define DIO_PD0                 24
#define DIO_PD1                 25
#define DIO_PD2                 26
#define DIO_PD3                 27
#define DIO_PD4                 28
#define DIO_PD5                 29
#define DIO_PD6                 30
#define DIO_PD7                 31

/* PORTs */
#define DIO_PORTA				0
#define DIO_PORTB				1
#define DIO_PORTC               2
#define DIO_PORTD               3

#define DIO_PORT_HIGH			0xFF
#define DIO_PORT_LOW			0x00
#define DIO_PORT_LHIGH			0x0F
#define DIO_PORT_MHIGH			0xF0

#endif /* MCAL_DIO_INTERFACE_H_ */
