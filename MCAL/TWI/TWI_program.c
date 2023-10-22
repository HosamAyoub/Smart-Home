/*******************************************************************************************/
/*******************************************************************************************/
/***********************            Author  : Hosam Ayoub            ***********************/
/***********************            Layer   : MCAL                   ***********************/
/***********************            SWC     : TWI                    ***********************/
/***********************            Version : 1.0                    ***********************/
/***********************            Date    : 08 Sep 2023            ***********************/
/*******************************************************************************************/
/*******************************************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "TWI_interface.h"
#include "TWI_private.h"
#include "TWI_config.h"

void TWI_voidMasterInit (u8 Copy_u8MasterAddress)
{
	/* Set the MCU address */
	if (Copy_u8MasterAddress != 0)
		TWAR = Copy_u8MasterAddress << 1;
	/* Set SCL speed to 400 kHz */
	// Set TWBR value
	TWBR = 2;
	// Clear TWPS bits
	CLR_BIT(TWSR, TWSR_TWPS0);
	CLR_BIT(TWSR, TWSR_TWPS1);
	/* Enable TWI */
	SET_BIT(TWCR, TWCR_TWEN);
}

void TWI_voidSlaveInit (u8 Copy_u8SlaveAddress)
{
	/* Set the MCU address */
	TWAR = (Copy_u8SlaveAddress << 1);
	/* Enable TWI */
	SET_BIT(TWCR, TWCR_TWEN);
}

tenumErrorStatus TWI_tenumSendStartCondition (void)
{
	tenumErrorStatus Local_tenumStatus = OK;
	/* Send Start Condition */
	SET_BIT(TWCR, TWCR_TWSTA);
	/* Clear Interrupt flag to start previous operation */
	SET_BIT(TWCR, TWCR_TWINT);
	/* waiting for the operation to finish */
	while (!GET_BIT(TWCR, TWCR_TWINT));
	/* checking if the operation is done successfully */
	if ((TWSR & TWSR_MASK) != START_ACK)
	{
		Local_tenumStatus = TWI_StartConditionError;
	}
	return Local_tenumStatus;
}

tenumErrorStatus TWI_tenumSendRepeatedStartCondition (void)
{
	tenumErrorStatus Local_tenumStatus = OK;
	/* Send Repeated Start Condition */
	SET_BIT(TWCR, TWCR_TWSTA);
	/* Clear Interrupt flag to start previous operation */
	SET_BIT(TWCR, TWCR_TWINT);
	/* Waiting for the operation to finish */
	while (!GET_BIT(TWCR, TWCR_TWINT));
	/* Checking if the operation is done successfully */
	if ((TWSR & TWSR_MASK) != REPEATED_START_ACK)
	{
		Local_tenumStatus = TWI_RepeatedStartConditionError;
	}
	return Local_tenumStatus;
}

tenumErrorStatus TWI_tenumSendSlaveAddressWithWrite (u8 Copy_u8SlaveAddress)
{
	tenumErrorStatus Local_tenumStatus = OK;
	/* Send Slave address with write signal */
	TWDR = Copy_u8SlaveAddress << 1 & 0xFE;
	/* Clear the start condition */
	CLR_BIT(TWCR, TWCR_TWSTA);
	/* Clear Interrupt flag to start previous operation */
	SET_BIT(TWCR, TWCR_TWINT);
	/* Waiting for the operation to finish */
	while (!GET_BIT(TWCR, TWCR_TWINT));
	/* Checking if the operation is done successfully */
	if ((TWSR & TWSR_MASK) != SLAVE_ADDRESS_WITH_WR_ACK)
	{
		Local_tenumStatus = TWI_SlaveAddressWithWriteAcknowledgmentError;
	}
	return Local_tenumStatus;
}

tenumErrorStatus TWI_tenumSendSlaveAddressWithRead (u8 Copy_u8SlaveAddress)
{
	tenumErrorStatus Local_tenumStatus = OK;
	/* Send Slave address with write signal */
	TWDR = Copy_u8SlaveAddress << 1 | 1;
	/* Clear the start condition */
	CLR_BIT(TWCR, TWCR_TWSTA);
	/* Clear Interrupt flag to start previous operation */
	SET_BIT(TWCR, TWCR_TWINT);
	/* Waiting for the operation to finish */
	while (!GET_BIT(TWCR, TWCR_TWINT));
	/* Checking if the operation is done successfully */
	if ((TWSR & TWSR_MASK) != SLAVE_ADDRESS_WITH_RD_ACK)
	{
		Local_tenumStatus = TWI_SlaveAddressWithReadAcknowledgmentError;
	}
	return Local_tenumStatus;
}

tenumErrorStatus TWI_tenumMasterWriteDataByte (u8 Copy_u8DataByte)
{
	tenumErrorStatus Local_tenumStatus = OK;
	/* Set Data */
	TWDR = Copy_u8DataByte;
	/* Clear Interrupt flag to start previous operation */
	SET_BIT(TWCR, TWCR_TWINT);
	/* Waiting for the operation to finish */
	while (!GET_BIT(TWCR, TWCR_TWINT));
	/* Checking if the operation is done successfully */
	if ((TWSR & TWSR_MASK) != MASTER_WRITE_BYTE_ACK)
	{
		Local_tenumStatus = TWI_MasterWriteByteWithAcknowledgmentError;
	}
	return Local_tenumStatus;
}

tenumErrorStatus TWI_tenumMasterReadDataByteWithACK (u8 *Copy_pu8DataByte)
{
	tenumErrorStatus Local_tenumStatus = OK;
	/* Enable Master Acknowledgment */
	SET_BIT(TWCR, TWCR_TWEA);
	/* Clear Interrupt flag to start receiving operation */
	SET_BIT(TWCR, TWCR_TWINT);
	/* Waiting for the operation to finish */
	while (!GET_BIT(TWCR, TWCR_TWINT));
	/* Checking if the operation is done successfully */
	if ((TWSR & TWSR_MASK) != MASTER_READ_BYTE_ACK)
	{
		Local_tenumStatus = TWI_MasterReadByteWithAcknowledgmentError;
	}
	else
	{
		/* Read Data from TWDR register */
		*Copy_pu8DataByte = TWDR;
	}
	return Local_tenumStatus;
}

tenumErrorStatus TWI_tenumMasterReadDataByteWithoutACK (u8 *Copy_pu8DataByte)
{
	tenumErrorStatus Local_tenumStatus = OK;
	/* Clear Interrupt flag to start receiving operation */
	SET_BIT(TWCR, TWCR_TWINT);
	/* Waiting for the operation to finish */
	while (!GET_BIT(TWCR, TWCR_TWINT));
	/* Checking if the operation is done successfully */
	if ((TWSR & TWSR_MASK) != MASTER_READ_BYTE_NACK)
	{
		Local_tenumStatus = TWI_MasterReadByteWithAcknowledgmentError;
	}
	else
	{
		/* Read Data from TWDR register */
		*Copy_pu8DataByte = TWDR;
	}
	return Local_tenumStatus;
}

void TWI_voidSendStopCondition (void)
{
	/* Send Stop condition */
	SET_BIT(TWCR, TWCR_TWSTO);
	/* Clear Interrupt flag to start previous operation */
	SET_BIT(TWCR, TWCR_TWINT);
}
