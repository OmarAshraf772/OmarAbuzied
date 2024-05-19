/****************************************************/
/******** Author     : Shadi Bahaa   ****************/
/******** File name  : WDT_Program.c  ****************/
/******** Date       : Aug 29, 2023       ****************/
/******** Version    : V1            ****************/
/******** Desc       : ...           ****************/
/****************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "WDT_Config.h"
#include "WDT_Private.h"
#include "WDT_Interface.h"

void MWDT_vEnable(void){
	SET_BIT(WDTCR,WDP2);
	SET_BIT(WDTCR,WDP1);
	SET_BIT(WDTCR,WDP0);
	SET_BIT(WDTCR,WDE);
}
void MWDT_vDisable(void){
	/* Write logical one to WDTOE and WDE */
	WDTCR = (1<<WDTOE) | (1<<WDE);
	/* Turn off WDT */
	WDTCR = 0x00;
}
