/*******************************************************************************************/
/*******************************************************************************************/
/***********************            Author  : Hosam Ayoub            ***********************/
/***********************            Layer   : MCAL                   ***********************/
/***********************            SWC     : SPI                    ***********************/
/***********************            Version : 1.5                    ***********************/
/***********************            Date    : 03 Sep 2023            ***********************/
/*******************************************************************************************/
/*******************************************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

void SPI_voidMasterInit (void)
{
	#if SPI_DATA_ORDER == SPI_MSB
		CLR_BIT_(SPCR, SPCR_DORD);
	#elif SPI_DATA_ORDER == SPI_LSB
		SET_BIT(SPCR, SPCR_DORD);
	#endif

	#if SPI_CLK_POLARITY == SPI_RISING_LEADING
		CLR_BIT(SPCR, SPCR_CPOL);
	#elif SPI_CLK_POLARITY == SPI_FALLING_LEADING
		SET_BIT(SPCR, SPCR_CPOL);
	#endif

	#if SPI_CLK_PHASE == SPI_SAMPLE_LEADING
		CLR_BIT(SPCR, SPCR_CPHA);
	#elif SPI_CLK_PHASE == SPI_SETUP_LEADING
		SET_BIT(SPCR, SPCR_CPHA);
	#endif

	#if SPI_PRESCLAER == SPI_PRESCALER_4
		CLR_BIT(SPCR, SPCR_SPR0);
		CLR_BIT(SPCR, SPCR_SPR1);
		CLR_BIT(SPSR, SPSR_SPI2X);
	#elif SPI_PRESCLAER == SPI_PRESCALER_16
		SET_BIT(SPCR, SPCR_SPR0);
		CLR_BIT(SPCR, SPCR_SPR1);
		CLR_BIT(SPSR, SPSR_SPI2X);
	#elif SPI_PRESCLAER == SPI_PRESCALER_64
		CLR_BIT(SPCR, SPCR_SPR0);
		SET_BIT(SPCR, SPCR_SPR1);
		CLR_BIT(SPSR, SPSR_SPI2X);
	#elif SPI_PRESCLAER == SPI_PRESCALER_128
		SET_BIT(SPCR, SPCR_SPR0);
		SET_BIT(SPCR, SPCR_SPR1);
		CLR_BIT(SPSR, SPSR_SPI2X);
	#elif SPI_PRESCLAER == SPI_PRESCALER_2
		CLR_BIT(SPCR, SPCR_SPR0);
		CLR_BIT(SPCR, SPCR_SPR1);
		SET_BIT(SPSR, SPSR_SPI2X);
	#elif SPI_PRESCLAER == SPI_PRESCALER_8
		SET_BIT(SPCR, SPCR_SPR0);
		CLR_BIT(SPCR, SPCR_SPR1);
		SET_BIT(SPSR, SPSR_SPI2X);
	#elif SPI_PRESCLAER == SPI_PRESCALER_32
		CLR_BIT(SPCR, SPCR_SPR0);
		SET_BIT(SPCR, SPCR_SPR1);
		SET_BIT(SPSR, SPSR_SPI2X);
	#endif
	SET_BIT(SPCR, SPCR_MSTR);
	SET_BIT(SPCR, SPCR_SPE);
}

void SPI_voidSlaveInit (void)
{
#if SPI_DATA_ORDER == SPI_MSB
		CLR_BIT_(SPCR, SPCR_DORD);
	#elif SPI_DATA_ORDER == SPI_LSB
		SET_BIT(SPCR, SPCR_DORD);
	#endif
	#if SPI_CLK_POLARITY == SPI_RISING_LEADING
			CLR_BIT(SPCR, SPCR_CPOL);
	#elif SPI_CLK_POLARITY == SPI_FALLING_LEADING
			SET_BIT(SPCR, SPCR_CPOL);
	#endif
	#if SPI_CLK_PHASE == SPI_SAMPLE_LEADING
			CLR_BIT(SPCR, SPCR_CPHA);
	#elif SPI_CLK_PHASE == SPI_SETUP_LEADING
			SET_BIT(SPCR, SPCR_CPHA);
	#endif
	CLR_BIT(SPCR, SPCR_MSTR);
	SET_BIT(SPCR, SPCR_SPE);
}

u8   SPI_u8Transceive (u8 Copy_u8Data)
{
	SPDR = Copy_u8Data;
	while (!GET_BIT(SPSR, SPSR_SPIF));
	return SPDR;
}

void   SPI_voidTransmite (u8 Copy_u8Data)
{
	SPDR = Copy_u8Data;
	while (!GET_BIT(SPSR, SPSR_SPIF));
}

u8   SPI_u8Receive (void)
{
	while (!GET_BIT(SPSR, SPSR_SPIF));
	return SPDR;
}

void SPI_voidEnableInterrupt (void)
{
	SET_BIT(SPCR, SPCR_SPIE);
}

void SPI_voidDisableInterrupt (void)
{
	CLR_BIT(SPCR, SPCR_SPIE);
}
