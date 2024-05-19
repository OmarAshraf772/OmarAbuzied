/*
 * AT24C08_PRG.c
 *
 *  Created on: Sep 2, 2023
 *      Author: Omar
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/TWI/TWI_INT.h"
#include "AT24C08_CONFIG.h"
#include "AT24C08_INT.h"
#include "AT24C08_PRIV.h"

void HAT24C08_vSendData(u16 A_u16Location ,u8 A_u8Data){
	u8 local_u8SlaveAddress=(FIXED_ADDRESS)|(CHIP_EN_CONFIG<<2) |(A_u16Location>>8);
	MTWI_TwiErrorSendStartCondition();
	MTWI_TwiErrorSendSlaveAddresswithWrite(local_u8SlaveAddress);
	MTWI_TwiErrorMasterWriteByte((u8)A_u16Location);
	MTWI_TwiErrorMasterWriteByte(A_u8Data);
	MTWI_vSendStopCondition();

}

u8 HAT24C08_vReadData(u16 A_u16Location){
	u8 local_u8SlaveAddress=(FIXED_ADDRESS)|(CHIP_EN_CONFIG<<2) |(A_u16Location>>8);
	MTWI_TwiErrorSendStartCondition();
	MTWI_TwiErrorSendSlaveAddresswithWrite(local_u8SlaveAddress);
	MTWI_TwiErrorMasterWriteByte((u8)A_u16Location);
	MTWI_TwiErrorSendRepeatedStartCondition();
	MTWI_TwiErrorSendSlaveAddresswithRead(local_u8SlaveAddress);
	u8 local_u8Data;
	MTWI_TwiErrorMasterReadByte(&local_u8Data);
	MTWI_vSendStopCondition();
	return local_u8Data;

}
