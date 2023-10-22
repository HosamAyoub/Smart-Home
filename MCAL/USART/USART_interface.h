/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: MCAL					*********************************/
/********************			SWC: USART					*********************************/
/********************			Version: 1.00				*********************************/
/********************			Date: 19 Aug 2023			*********************************/
/********************************************************************************************/
/********************************************************************************************/
#ifndef MCAL_USART_USART_INTERFACE_H_
#define MCAL_USART_USART_INTERFACE_H_

void USART_voidInit (void);
void USART_voidTransmitWithBlocking (u16 Copy_u16Data);
void USART_voidTransmitWithoutBlocking (u16 Copy_u16Data);
tenumErrorStatus USART_tenumReceiveWithBlocking (u16 *pu16Data);

void USART_voidEnableTXC   (void);
void USART_voidDisableTXC  (void);
void USART_voidEnableRXC   (void);
void USART_voidDisableRXC  (void);
void USART_voidEnableUDRE  (void);
void USART_voidDisableUDRE (void);

#define USART_TRANSMITTER									1
#define USART_RECEIVER                                   	2
#define USART_TRANSCEIVER                                   3

#define USART_5_BIT											0
#define USART_6_BIT											1
#define USART_7_BIT											2
#define USART_8_BIT											3
#define USART_9_BIT											7

#define USART_ASYNCHRONOUS									0
#define USART_SYNCHRONOUS									1

#define USART_DISABLE_PARITY								0
#define USART_EVEN_PARITY									2
#define USART_ODD_PARITY									3

#define USART_1_STOP_BIT									0
#define USART_2_STOP_BIT									1

#define USART_FALLING_EDGE									0
#define USART_RISING_EDGE									1

#define USART_DOUBLE_SPEED_DISABLE							1
#define USART_DOUBLE_SPEED_ENABLE							0

#endif /* MCAL_USART_USART_INTERFACE_H_ */
