/*******************************************************************************************/
/*******************************************************************************************/
/***********************            Author  : Hosam Ayoub            ***********************/
/***********************            Layer   : MCAL                   ***********************/
/***********************            SWC     : TWI                    ***********************/
/***********************            Version : 1.0                    ***********************/
/***********************            Date    : 08 Sep 2023            ***********************/
/*******************************************************************************************/
/*******************************************************************************************/
#ifndef TWI_PRIVATE_H
#define TWI_PRIVATE_H


#define TWCR							(*((volatile u8*)0x56))			// TWI Control register
#define TWCR_TWIE						0								// TWI Interrupt enable bit
#define TWCR_TWEN						2								// TWI Enable bit
#define TWCR_TWWC						3								// TWI Write collision flag bit
#define TWCR_TWSTO						4								// TWI Stop condition bit
#define TWCR_TWSTA						5								// TWI Start condition bit
#define TWCR_TWEA						6								// TWI Enable acknowledge bit
#define TWCR_TWINT						7								// TWI Interrupt flag bit


#define TWDR							(*((volatile u8*)0x23))			// TWI Data register
#define TWDR_TWD0						0


#define TWAR							(*((volatile u8*)0x22))			// TWI (slave) Address register
#define TWAR_TWGCE						0								// TWI General call Recognition bit

#define TWSR							(*((volatile u8*)0x21))			// TWI Bit status register
#define TWSR_TWPS0						0								// TWI Prescaler bit 0
#define TWSR_TWPS1						1								// TWI Prescaler bit 1

#define TWBR							(*((volatile u8*)0x20))			// TWI Bit rate register


#define START_ACK                                       0x08	// Start has been sent
#define REPEATED_START_ACK                              0x10	// Repeated start has been sent
#define SLAVE_ADDRESS_WITH_WR_ACK                       0x18    // Master transmitted (slave address + write) with acknowledgment
#define SLAVE_ADDRESS_WITH_RD_ACK                       0x40    // Master transmitted (slave address + read) with acknowledgment
#define MASTER_WRITE_BYTE_ACK                           0x28    // Master write data with acknowledgment
#define MASTER_READ_BYTE_ACK                            0x50    // Master read data with acknowledgment
#define MASTER_READ_BYTE_NACK                           0x58    // Master read data with negative acknowledgment
#define SLAVE_ADD_RECEIVED_RD_REQ                       0xA8    // Slave received its address with read request
#define SLAVE_ADD_RECEIVED_WR_REQ                       0x60    // Slave received its address with write request
#define SLAVE_DATA_RECEIVED			                    0x80    // Slave has received a byte and transmitted acknowledgment
#define SLAVE_BYTE_TRANSMITTED							0xB8    // Slave has transmitted a byte

#define TWSR_MASK										0xF8

#endif
