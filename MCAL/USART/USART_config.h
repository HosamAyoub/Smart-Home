/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: HAL					*********************************/
/********************			SWC: USART					*********************************/
/********************			Version: 1.00				*********************************/
/********************			Date: 19 Aug 2023			*********************************/
/********************************************************************************************/
/********************************************************************************************/
#ifndef MCAL_USART_USART_CONFIG_H_
#define MCAL_USART_USART_CONFIG_H_

/*
 * 1- USART_RECEIVER
 * 2- USART_TRANSMITTER
 * 3- USART_TRANSCEIVER
 */
#define DEVICE_STATE							USART_TRANSCEIVER

/*
 * 1- USART_5_BIT
 * 2- USART_6_BIT
 * 3- USART_7_BIT
 * 4- USART_9_BIT
 * 5- USART_9_BIT
 */
#define DATA_SIZE								USART_8_BIT

/*
 * 1- USART_ASYNCHRONOUS
 * 2- USART_SYNCHRONOUS
 */
#define MODE									USART_ASYNCHRONOUS

/*
 * 1- USART_DISABLE_PARITY
 * 2- USART_EVEN_PARITY
 * 3- USART_ODD_PARITY
 */
#define PARITY									USART_DISABLE_PARITY

/*
 * 1- USART_1_STOP_BIT
 * 2- USART_2_STOP_BIT
 */
#define STOP_BITS								USART_1_STOP_BIT

/*
 * 1- USART_FALLING_EDGE
 * 2- USART_RISING_EDGE
 */
#define CLK_POLARITY							USART_FALLING_EDGE

/*
 * 1- USART_DOUBLE_SPEED_DISABLE
 * 2- USART_DOUBLE_SPEED_ENABLE
 */
#define DOUBLE_SPEED							USART_DOUBLE_SPEED_DISABLE

/* For 8 MHz Normal Speed:						For 8 MHz Double Speed:
 * from 123 to 0.5M								from 245 to 1M
 */
#define BAUD_RATE								9600

#endif /* MCAL_USART_USART_CONFIG_H_ */
