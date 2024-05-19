/*
 * TWI_PRG.c
 *
 *  Created on: Sep 2, 2023
 *      Author: Omar
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "TWI_CONFIG.h"
#include "TWI_INT.h"
#include "TWI_PRIV.h"

void MTWI_vInitMaster(u8 A_u8MasterAddress){
	SET_BIT(TWCR,TWEA);

	TWBR=SCL_TWBR_VAL;
	CLR_BIT(TWSR,TWPS0);
	CLR_BIT(TWSR,TWPS1);

	if(A_u8MasterAddress == 0){

	}else{
		TWAR=A_u8MasterAddress<<1;
	}
	SET_BIT(TWCR,TWEN);

}

void MTWI_vInitSlave(u8 A_u8SlaveAddress){
	TWAR= A_u8SlaveAddress<<1;
	SET_BIT(TWCR,TWEA);
	SET_BIT(TWCR,TWEN);
}

TWI_ERROR_e MTWI_TwiErrorSendStartCondition(void){
	TWI_ERROR_e local_TwiError= NO_ERROR;
	SET_BIT(TWCR,TWEN);
	SET_BIT(TWCR,TWSTA);
	SET_BIT(TWCR,TWINT);
	while (GET_BIT(TWCR,TWINT)==0);

	if ((TWSR & STATUS_MASK) != START_ACK){
		local_TwiError=START_CONDITION_ERROR;
	}
	return local_TwiError;
}

TWI_ERROR_e MTWI_TwiErrorSendRepeatedStartCondition(void){
	TWI_ERROR_e local_TwiError= NO_ERROR;
	SET_BIT(TWCR,TWEN);
	SET_BIT(TWCR,TWSTA);
	SET_BIT(TWCR,TWINT);
	while (GET_BIT(TWCR,TWINT)==0);

	if ((TWSR & STATUS_MASK) != REPEATED_START_ACK){
		local_TwiError=REPEATED_START_CONDITION_ERROR;
	}
	return local_TwiError;
}

TWI_ERROR_e MTWI_TwiErrorSendSlaveAddresswithWrite(u8 A_u8SlaveAddress){
	TWI_ERROR_e local_TwiError= NO_ERROR;

	TWDR=A_u8SlaveAddress<<1;
	SET_BIT(TWCR,TWEN);
	CLR_BIT(TWDR,TWD0);

	SET_BIT(TWCR,TWINT);
	while (GET_BIT(TWCR,TWINT)==0);

	if ((TWSR & STATUS_MASK) != SLAVE_W_ACK){
		local_TwiError=SLAVE_W_ACCESS_ERROR;
	}
	return local_TwiError;
}

TWI_ERROR_e MTWI_TwiErrorSendSlaveAddresswithRead(u8 A_u8SlaveAddress){
	TWI_ERROR_e local_TwiError= NO_ERROR;

	TWDR=A_u8SlaveAddress<<1;
	SET_BIT(TWCR,TWEN);

	SET_BIT(TWDR,TWD0);

	SET_BIT(TWCR,TWINT);
	while (GET_BIT(TWCR,TWINT)==0);

	if ((TWSR & STATUS_MASK) != SLAVE_R_ACK){
		local_TwiError=SLAVE_R_ACCESS_ERROR;
	}
	return local_TwiError;
}

TWI_ERROR_e MTWI_TwiErrorMasterWriteByte(u8 A_u8Data){
	TWI_ERROR_e local_TwiError= NO_ERROR;

	TWDR=A_u8Data;
	SET_BIT(TWCR,TWEN);

	SET_BIT(TWDR,TWD0);

	SET_BIT(TWCR,TWINT);
	while (GET_BIT(TWCR,TWINT)==0);

	if ((TWSR & STATUS_MASK) != MSTR_W_BYTE_ACK){
		local_TwiError=MASTER_W_BYTE_ERROR;
	}
	return local_TwiError;
}

TWI_ERROR_e MTWI_TwiErrorMasterReadByte(u8* A_u8Data){
	TWI_ERROR_e local_TwiError= NO_ERROR;


	SET_BIT(TWCR,TWEN);

	SET_BIT(TWDR,TWD0);

	SET_BIT(TWCR,TWINT);
	while (GET_BIT(TWCR,TWINT)==0);

	if ((TWSR & STATUS_MASK) != MSTR_R_BYTE_ACK){
		local_TwiError=MASTER_R_BYTE_ERROR;
	}else {
		*A_u8Data=TWDR;
	}
	return local_TwiError;
}

void MTWI_vSendStopCondition(void){
TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}
