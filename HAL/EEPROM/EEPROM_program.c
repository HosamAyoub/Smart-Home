/*******************************************************************************************/
/*******************************************************************************************/
/***********************            Author  : Hosam Ayoub            ***********************/
/***********************            Layer   : HAL                    ***********************/
/***********************            SWC     : EEPROM                 ***********************/
/***********************            Version : 1.0                    ***********************/
/***********************            Date    : 08 Sep 2023            ***********************/
/*******************************************************************************************/
/*******************************************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/TWI/TWI_interface.h"
#include "EEPROM_interface.h"
#include "EEPROM_private.h"
#include "EEPROM_config.h"


void EEPROM_voidSendDataByte(u8 Copy_u8Address, u8 Copy_u8DataByte)
{
    /* Send start condition */
    TWI_tenumSendStartCondition();
    /* Send slave address with write request */
    TWI_tenumSendSlaveAddressWithWrite(0b01010000);
    /* Send data byte address */
    TWI_tenumMasterWriteDataByte(Copy_u8Address);
    /* Send data */
    TWI_tenumMasterWriteDataByte(Copy_u8DataByte);
    /* Send stop condition */
    TWI_voidSendStopCondition();
}


void EEPROM_voidReadDataByte(u8 Copy_u8Address, u8 *Copy_pu8ReceivedData)
{
	/* Send start condition */
    TWI_tenumSendStartCondition();
    /* Send slave address with write request */
    TWI_tenumSendSlaveAddressWithWrite(0b01010000);
    /* Send data byte address */
    TWI_tenumMasterWriteDataByte(Copy_u8Address);
    /* Send repeated start condition */
    TWI_tenumSendRepeatedStartCondition();
    /* Send slave address with read request */
    TWI_tenumSendSlaveAddressWithRead(0b01010000);
    /* Read data */
//    TWI_tenumMasterReadDataByte(Copy_pu8ReceivedData);
    TWI_tenumMasterReadDataByteWithoutACK(Copy_pu8ReceivedData);
    /* Send stop condition */
    TWI_voidSendStopCondition();
}
