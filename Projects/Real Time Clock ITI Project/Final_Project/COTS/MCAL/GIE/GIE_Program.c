/****************************************************/
/******** Author     : Shadi Bahaa   ****************/
/******** File name  : GIE_Program.c  ****************/
/******** Date       : Aug 23, 2023       ****************/
/******** Version    : V1            ****************/
/******** Desc       : ...           ****************/
/****************************************************/

/*
 * enable GIE
 * disable GIE
 * */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "GIE_Interface.h"
#include "GIE_Private.h"

void MGIE_vEnableInterrupts(void){
	SET_BIT(SREG,GIE_PIN);
}

void MGIE_vDisableInterrupts(void){
	CLR_BIT(SREG,GIE_PIN);
}
