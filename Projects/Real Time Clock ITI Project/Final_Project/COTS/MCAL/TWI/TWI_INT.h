/*
 * TWI_INT.h
 *
 *  Created on: Sep 2, 2023
 *      Author: Omar
 */

typedef enum{
	NO_ERROR=0,
	START_CONDITION_ERROR,
	REPEATED_START_CONDITION_ERROR,
	SLAVE_W_ACCESS_ERROR,
	SLAVE_R_ACCESS_ERROR,
	MASTER_W_BYTE_ERROR,
	MASTER_R_BYTE_ERROR,
}TWI_ERROR_e;

void MTWI_vInitMaster(u8 A_u8MasterAddress);
void MTWI_vInitSlave(u8 A_u8SlaveAddress);
TWI_ERROR_e MTWI_TwiErrorSendStartCondition(void);
TWI_ERROR_e MTWI_TwiErrorSendRepeatedStartCondition(void);
TWI_ERROR_e MTWI_TwiErrorSendSlaveAddresswithWrite(u8 A_u8SlaveAddress);
TWI_ERROR_e MTWI_TwiErrorSendSlaveAddresswithRead(u8 A_u8SlaveAddress);
TWI_ERROR_e MTWI_TwiErrorMasterWriteByte(u8 A_u8Data);
TWI_ERROR_e MTWI_TwiErrorMasterReadByte(u8* A_u8Data);
void MTWI_vSendStopCondition(void);
