/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: MCAL					*********************************/
/********************			SWC: USART					*********************************/
/********************			Version: 1.00				*********************************/
/********************			Date: 19 Aug 2023			*********************************/
/********************************************************************************************/
/********************************************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"

pf USART_pfCallBack = NULL;
u16 Global_u16TransmittedData, Global_u16ReceivedData;

void USART_voidInit (void)
{
	/* The configurations values is choose based on data sheet to set the UCSRC register */
	UCSRC = (1 << UCSRC_URSEL) | (MODE << UCSRC_UMSEL) | (PARITY << UCSRC_UPM0) | (STOP_BITS << UCSRC_USBS) | ((DATA_SIZE & 3) << UCSRC_UCSZ0) | (CLK_POLARITY << UCSRC_UCPOL);
	/* Set The state of device and data size */
	UCSRB |= (DEVICE_STATE << UCSRB_TXEN) | ((GET_BIT(DATA_SIZE, 2)) << UCSRB_UCSZ2);
	/* UBRRValue equation */
	u16 Local_u16UBRRValue = ((F_CPU) / ((16/ (2 - DOUBLE_SPEED)) * (u32)BAUD_RATE)) - 1;
	UBRRH = (0 << UCSRC_URSEL) | (0x0F & (Local_u16UBRRValue >> 8));
	UBRRL = (u8) Local_u16UBRRValue;
}

void USART_voidTransmitWithBlocking (u16 Copy_u16Data)
{
	while (!GET_BIT(UCSRA, UCSRA_UDRE));
	#if DATA_SIZE == USART_9_BIT
		if (GET_BIT(Copy_u16Data, 8))
			SET_BIT(UCSRB, UCSRB_TXB8);
		else
			CLR_BIT(UCSRB, UCSRB_TXB8);
	#endif
	UDR = Copy_u16Data;
}

void USART_voidTransmitWithoutBlocking (u16 Copy_u16Data)
{
	Global_u16TransmittedData = Copy_u16Data;
}

tenumErrorStatus USART_tenumReceiveWithBlocking (u16 *pu16Data)
{
	tenumErrorStatus State = OK;
	while (!GET_BIT(UCSRA, UCSRA_RXC));
	if (UCSRA & ERROR_MASK)
	{
		State = ERROR;
	}
	else
	{
		#if DATA_SIZE == USART_9_BIT
			if (GET_BIT(UCSRB, UCSRB_RXB8))
				*pu16Data = (GET_BIT(UCSRB, UCSRB_RXB8) << 8) | UDR;
		#else
			*pu16Data = UDR;
		#endif
	}
	return State;
}

tenumErrorStatus USART_tenumReceiveWithoutBlocking (u16 *pu16Data)
{
	tenumErrorStatus State = OK;
	if (GET_BIT(Global_u16ReceivedData, 14))
	{
		State = ERROR;
	}
	else
	{
		*pu16Data = Global_u16ReceivedData;
	}
	return State;
}

void USART_voidEnableTXC (void)
{
	SET_BIT(UCSRB, UCSRB_TXCIE);
}


void USART_voidDisableTXC (void)
{
	CLR_BIT(UCSRB, UCSRB_TXCIE);
}

void USART_voidEnableRXC (void)
{
	SET_BIT(UCSRB, UCSRB_RXCIE);
}

void USART_voidDisableRXC (void)
{
	CLR_BIT(UCSRB, UCSRB_RXCIE);
}

void USART_voidEnableUDRE (void)
{
	SET_BIT(UCSRB, UCSRB_UDRIE);
}

void USART_voidDisableUDRE (void)
{
	CLR_BIT(UCSRB, UCSRB_UDRIE);
}

void USART_voidSetCallBack (pf pfCallBack)
{
	USART_pfCallBack = pfCallBack;
}

/* TXC */
void __vector_15 (void) __attribute__ ((signal, used));
void __vector_15 (void)
{

	USART_pfCallBack();
}

/* UDRE */
void __vector_14 (void) __attribute__ ((signal, used));
void __vector_14 (void)
{
	#if DATA_SIZE == USART_9_BIT
		if (GET_BIT(Global_u16TransmittedData, 8))
			SET_BIT(UCSRB, UCSRB_TXB8);
		else
			CLR_BIT(UCSRB, UCSRB_TXB8);
	#endif
	UDR = Global_u16TransmittedData;
}

/* RXC */
void __vector_13 (void) __attribute__ ((signal, used));
void __vector_13 (void)
{
	if (UCSRA & ERROR_MASK)
	{
		SET_BIT(Global_u16ReceivedData, 14);
	}
	else
	{
		#if DATA_SIZE == USART_9_BIT
				if (GET_BIT(UCSRB, UCSRB_RXB8))
					Global_u16ReceivedData = (GET_BIT(UCSRB, UCSRB_RXB8) << 8) | UDR;
		#else
				Global_u16ReceivedData = UDR;
		#endif
	}
}
