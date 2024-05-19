/****************************************************/
/******** Author     : Shadi Bahaa   ****************/
/******** File name  : ICU_Program.c  ****************/
/******** Date       : Aug 29, 2023       ****************/
/******** Version    : V1            ****************/
/******** Desc       : ...           ****************/
/****************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "ICU_Config.h"
#include "ICU_Private.h"
#include "ICU_Interface.h"

/*
 * Init : Turn on normal mode
 * */
static u32 global_u32TOn = 0;
static u32 global_u32Ttotal = 0;
static u32 global_u32TOvCnt = 0;
static u32 global_u32Capture1 = 0;
static u32 global_u32Capture2 = 0;
static u32 global_u32Capture3 = 0;
static u8  global_u8Flag = 0;
void MICU_vInit(void){
	/* Normal / Overflow mode */
	CLR_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1A,WGM10);
	CLR_BIT(TCCR1B,WGM13);
	CLR_BIT(TCCR1B,WGM12);
	/* Trigger on rising edge */
	SET_BIT(TCCR1B,ICES1);
	/* Clock : /8 */
	CLR_BIT(TCCR1B,CS12);
	SET_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS10);
	/* ICU Interrupt enable */
	SET_BIT(TIMSK,TICIE1);
	/* Overflow Interrupt enable */
	SET_BIT(TIMSK,TOIE1);
}
/* Overflow ISR */
void __vector_9(){
	global_u32TOvCnt++;
}
void MICU_vSelectEdge(ICU_EDGE_e A_ICUEdge){
	switch(A_ICUEdge){
	case RISING:  SET_BIT(TCCR1B,ICES1);break;
	case FALLING: CLR_BIT(TCCR1B,ICES1);break;
	}
}
/* ICU ISR */
void __vector_6(){
	if (global_u8Flag == 0){
		global_u32Capture1 = ICR1;
		TCNT1 = 0;
		global_u32TOvCnt = 0;
		global_u8Flag = 1;
		CLR_BIT(TCCR1B,ICES1);
		global_u32TOn = 0;
		global_u32Ttotal = 0;
	}else if (global_u8Flag == 1){
		global_u32Capture2 = ICR1;
		global_u32TOn = global_u32Capture2 + global_u32TOvCnt*65536 -
				global_u32Capture1;
		global_u8Flag = 2;
		SET_BIT(TCCR1B,ICES1);
	}else if (global_u8Flag == 2){
		global_u32Capture3 = ICR1;
		global_u32Ttotal = global_u32Capture3 + global_u32TOvCnt*65536 -
						global_u32Capture1;
		global_u8Flag = 0;
	}
}
u32 MICU_u32GetTimeOn(){
	return global_u32TOn;
}
u32 MICU_u32GetTimeTotal(){
	return global_u32Ttotal;
}
