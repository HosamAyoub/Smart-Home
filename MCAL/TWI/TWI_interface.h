/*******************************************************************************************/
/*******************************************************************************************/
/***********************            Author  : Hosam Ayoub            ***********************/
/***********************            Layer   : MCAL                   ***********************/
/***********************            SWC     : TWI                    ***********************/
/***********************            Version : 1.0                    ***********************/
/***********************            Date    : 08 Sep 2023            ***********************/
/*******************************************************************************************/
/*******************************************************************************************/
#ifndef TWI_INTERFACE_H
#define TWI_INTERFACE_H

void TWI_voidMasterInit (u8 Copy_u8MasterAddress);
void TWI_voidSlaveInit (u8 Copy_u8SlaveAddress);
tenumErrorStatus TWI_tenumSendStartCondition (void);
tenumErrorStatus TWI_tenumSendRepeatedStartCondition (void);
tenumErrorStatus TWI_tenumSendSlaveAddressWithWrite (u8 Copy_u8SlaveAddress);
tenumErrorStatus TWI_tenumSendSlaveAddressWithRead (u8 Copy_u8SlaveAddress);
tenumErrorStatus TWI_tenumMasterWriteDataByte (u8 Copy_u8DataByte);
tenumErrorStatus TWI_tenumMasterReadDataByte (u8 *Copy_pu8DataByte);
tenumErrorStatus TWI_tenumMasterReadDataByteWithoutACK (u8 *Copy_pu8DataByte);
void TWI_voidSendStopCondition (void);

#endif
