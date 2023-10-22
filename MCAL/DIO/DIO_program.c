/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: MCAL					*********************************/
/********************			SWC: DIO					*********************************/
/********************			Version: 1.00				*********************************/
/********************			Date: 2 Aug 2023			*********************************/
/********************************************************************************************/
/********************************************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

void DIO_voidInit (void)
{
	DDRA = PORTA_DIR;
	DDRB = PORTB_DIR;
	DDRC = PORTC_DIR;
	DDRD = PORTD_DIR;
}

tenumErrorStatus DIO_enumSetPinValue (u8 Copy_u8Pin, u8 Copy_u8Value)
{
	tenumErrorStatus Local_tenumStatus = OK;
//	if (Copy_u8Value == DIO_HIGH)
//	{
//		switch (Copy_u8Pin)
//		{
//		case DIO_PA0 ... DIO_PA7:
//			SET_BIT(PORTA, Copy_u8Pin);
//			break;
//		case DIO_PB0 ... DIO_PB7:
//			SET_BIT(PORTB, Copy_u8Pin % 8);
//			break;
//		case DIO_PC0 ... DIO_PC7:
//			SET_BIT(PORTC, Copy_u8Pin % 8);
//			break;
//		case DIO_PD0 ... DIO_PD7:
//			SET_BIT(PORTD, Copy_u8Pin % 8);
//			break;
//		default:
//			Local_tenumStatus = PARAMETER_OUT_RANGE;
//			break;
//		}
//	}
//	else if (Copy_u8Value == DIO_LOW)
//	{
//		switch (Copy_u8Pin)
//		{
//		case DIO_PA0 ... DIO_PA7:
//			CLR_BIT(PORTA, Copy_u8Pin);
//			break;
//		case DIO_PB0 ... DIO_PB7:
//			CLR_BIT(PORTB, Copy_u8Pin % 8);
//			break;
//		case DIO_PC0 ... DIO_PC7:
//			CLR_BIT(PORTC, Copy_u8Pin % 8);
//			break;
//		case DIO_PD0 ... DIO_PD7:
//			CLR_BIT(PORTD, Copy_u8Pin % 8);
//			break;
//		default:
//			Local_tenumStatus = PARAMETER_OUT_RANGE;
//			break;
//		}
//	}
//	else
//	{
//		Local_tenumStatus = ERROR;
//	}

	if (DIO_PA0 <= Copy_u8Pin && Copy_u8Pin <= DIO_PA7)
	{
		switch (Copy_u8Value)
		{
		case DIO_LOW:
			CLR_BIT(PORTA, Copy_u8Pin);
			break;
		case DIO_HIGH:
			SET_BIT(PORTA, Copy_u8Pin);
			break;
		default:
			Local_tenumStatus = PARAMETER_OUT_RANGE;
			break;
		}
	}
	else if (DIO_PB0 <= Copy_u8Pin && Copy_u8Pin <= DIO_PB7)
	{
		switch (Copy_u8Value)
		{
		case DIO_LOW:
			CLR_BIT(PORTB, Copy_u8Pin%REG_SIZE);
			break;
		case DIO_HIGH:
			SET_BIT(PORTB, Copy_u8Pin%REG_SIZE);
			break;
		default:
			Local_tenumStatus = PARAMETER_OUT_RANGE;
			break;
		}
	}
	else if (DIO_PC0 <= Copy_u8Pin && Copy_u8Pin <= DIO_PC7)
	{
		switch (Copy_u8Value)
		{
		case DIO_LOW:
			CLR_BIT(PORTC, Copy_u8Pin%REG_SIZE);
			break;
		case DIO_HIGH:
			SET_BIT(PORTC, Copy_u8Pin%REG_SIZE);
			break;
		default:
			Local_tenumStatus = PARAMETER_OUT_RANGE;
			break;
		}
	}
	else if (DIO_PD0 <= Copy_u8Pin && Copy_u8Pin <= DIO_PD7)
	{
		switch (Copy_u8Value)
		{
		case DIO_LOW:
			CLR_BIT(PORTD, Copy_u8Pin%REG_SIZE);
			break;
		case DIO_HIGH:
			SET_BIT(PORTD, Copy_u8Pin%REG_SIZE);
			break;
		default:
			Local_tenumStatus = PARAMETER_OUT_RANGE;
			break;
		}
	}
	else
	{
		Local_tenumStatus = PARAMETER_OUT_RANGE;
	}
	return Local_tenumStatus;
}

tenumErrorStatus DIO_enumGetPinValue (u8 Copy_u8Pin, u8 *Pu8PinValue)
{
	tenumErrorStatus Local_tenumStatus = OK;
		if (DIO_PA0 <= Copy_u8Pin && Copy_u8Pin <= DIO_PA7)
		{
			*Pu8PinValue = GET_BIT(PINA, Copy_u8Pin);
		}
		else if (DIO_PB0 <= Copy_u8Pin && Copy_u8Pin <= DIO_PB7)
		{
			*Pu8PinValue = GET_BIT(PINB, Copy_u8Pin % 8);
		}
		else if (DIO_PC0 <= Copy_u8Pin && Copy_u8Pin <= DIO_PC7)
		{
			*Pu8PinValue = GET_BIT(PINC, Copy_u8Pin % 8);
		}
		else if (DIO_PD0 <= Copy_u8Pin && Copy_u8Pin <= DIO_PD7)
		{
			*Pu8PinValue = GET_BIT(PIND, Copy_u8Pin % 8);
		}
		else
		{
			Local_tenumStatus = PARAMETER_OUT_RANGE;
		}

//	if (Pu8PinValue != NULL)
//	{
//		switch (Copy_u8Pin)
//		{
//		case DIO_PA0 ... DIO_PA7:
//			*Pu8PinValue = GET_BIT(PINA, Copy_u8Pin);
//			break;
//		case DIO_PB0 ... DIO_PB7:
//			*Pu8PinValue = GET_BIT(PINB, Copy_u8Pin % 8);
//			break;
//		case DIO_PC0 ... DIO_PC7:
//			*Pu8PinValue = GET_BIT(PINC, Copy_u8Pin % 8);
//			break;
//		case DIO_PD0 ... DIO_PD7:
//			*Pu8PinValue = GET_BIT(PIND, Copy_u8Pin % 8);
//			break;
//		default:
//			Local_tenumStatus = PARAMETER_OUT_RANGE;
//			break;
//		}
//	}
//	else
//	{
//		Local_tenumStatus = POINTER_OUT_OF_RANGE;
//	}
	return Local_tenumStatus;
}

tenumErrorStatus DIO_enumPullup (u8 Copy_u8Pin, u8 Copy_u8State)
{
	return DIO_enumSetPinValue(Copy_u8Pin, Copy_u8State);
}

tenumErrorStatus DIO_enumSetGroupValue (u8 *Pau8Pins, u8 *Pau8Values, u8 Copy_u8Size)
{
	tenumErrorStatus Local_tenumStatus = OK;
	u8 Local_u8Counter;
	for (Local_u8Counter = 0; Local_u8Counter < Copy_u8Size; Local_u8Counter++)
	{
		Local_tenumStatus = DIO_enumSetPinValue(Pau8Pins[Local_u8Counter], Pau8Values[Local_u8Counter]);
		if (Local_tenumStatus)
		{
			break;
		}
	}
	return Local_tenumStatus;
}

tenumErrorStatus DIO_enumSetPortValue (u8 Copy_u8Port, u8 Copy_u8Value)
{
	tenumErrorStatus Local_tenumStatus = OK;
	switch (Copy_u8Port)
	{
	case DIO_PORTA: PORTA = Copy_u8Value; break;
	case DIO_PORTB: PORTB = Copy_u8Value; break;
	case DIO_PORTC: PORTC = Copy_u8Value; break;
	case DIO_PORTD: PORTD = Copy_u8Value; break;
	default: Local_tenumStatus = PARAMETER_OUT_RANGE; break;
	}
	return Local_tenumStatus;
}
