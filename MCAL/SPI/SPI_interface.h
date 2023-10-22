/*******************************************************************************************/
/*******************************************************************************************/
/***********************            Author  : Hosam Ayoub            ***********************/
/***********************            Layer   : MCAL                   ***********************/
/***********************            SWC     : SPI                    ***********************/
/***********************            Version : 1.5                    ***********************/
/***********************            Date    : 03 Sep 2023            ***********************/
/*******************************************************************************************/
/*******************************************************************************************/
/*************************/
#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_voidMasterInit (void);
void SPI_voidSlaveInit (void);
u8   SPI_u8Transceive (u8 Copy_u8Data);
void SPI_voidEnableInterrupt (void);
void SPI_voidDisableInterrupt (void);
u8   SPI_u8Receive (void);
void   SPI_voidTransmite (u8 Copy_u8Data);
//u8   SPI_u8;
//void SPI_voidSendAsynchronous (u8 Copy_u8Data);


#define SPI_MASTER										0
#define SPI_SLAVE										1

#define SPI_LSB											0
#define SPI_MSB											1

#define SPI_RISING_LEADING								0
#define SPI_FALLING_LEADING								1

#define SPI_SAMPLE_LEADING								0
#define SPI_SETUP_LEADING								1

#define SPI_PRESCALER_4									0
#define SPI_PRESCALER_16                                1
#define SPI_PRESCALER_64                                2
#define SPI_PRESCALER_128                               3
#define SPI_PRESCALER_2                                 4
#define SPI_PRESCALER_8                                 5
#define SPI_PRESCALER_32                                6



#endif
