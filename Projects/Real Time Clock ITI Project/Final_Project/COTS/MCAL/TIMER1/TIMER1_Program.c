/****************************************************/
/******** Author     : Shadi Bahaa   ****************/
/******** File name  : TIMER1_Program.c  ****************/
/******** Date       : Aug 28, 2023       ****************/
/******** Version    : V1            ****************/
/******** Desc       : ...           ****************/
/****************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "TIMER1_Config.h"
#include "TIMER1_Private.h"
#include "TIMER1_Interface.h"

void MTIMER1_vInit(void){
	/* Non inverting mode : OC1A, OC1B */
	SET_BIT(TCCR1A,COM1A1);
	SET_BIT(TCCR1A,COM1B1);
	CLR_BIT(TCCR1A,COM1A0);
	CLR_BIT(TCCR1A,COM1B0);
	/* FAST PWM MODE : TOP ICR1 */
	SET_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1B,WGM13);
	SET_BIT(TCCR1B,WGM12);
	/* prescaling : /8 */
	CLR_BIT(TCCR1B,CS12);
	SET_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS10);
	OCR1A = 0;
	OCR1B = 0;
}
void MTIMER1_vSetOCR1AValue(u16 A_u16Val){
	OCR1A = A_u16Val;
}
void MTIMER1_vSetOCR1BValue(u16 A_u16Val){
	OCR1B = A_u16Val;
}
void MTIMER1_vSetICR1Value(u16 A_u16Val){
	ICR1  = A_u16Val;
}

