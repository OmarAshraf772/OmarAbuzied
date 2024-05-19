

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "TIMER0_Private.h"
#include "TIMER0_Interface.h"
#include "TIMER0_Config.h"

#define NULL 0

void (*TIMER0_OV)(void) = NULL;
void (*TIMER0_CTC)(void) = NULL;

void MTIMER0_vInit(void){
#if TIMER0_MODE == NORMAL_MODE
	/* Normal mode  */
	CLR_BIT(TCCR0,WGM01);
	CLR_BIT(TCCR0,WGM00);

	/* Prescalar : /8 */
	CLR_BIT(TCCR0,CS02);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS00);

	/* Turn on interrupt */
	SET_BIT(TIMSK,TOIE0);
#elif TIMER0_MODE == CTC_MODE
	/* CTC MODE */
	SET_BIT(TCCR0,WGM01);
	CLR_BIT(TCCR0,WGM00);
	/* Disconnect OC0 : Normal pin */
	CLR_BIT(TCCR0,COM01);
	CLR_BIT(TCCR0,COM00);
	/* Prescaler : /8 */
	CLR_BIT(TCCR0,CS02);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS00);
	/* Reset OCR0 */
	OCR0 = 0;
	/* Turn on interrupt */
	SET_BIT(TIMSK,OCIE0);
#elif TIMER0_MODE == FAST_PWM_MODE
	/* FAST PWM */
	SET_BIT(TCCR0,WGM01);
	SET_BIT(TCCR0,WGM00);
	/* Non inverting mode */
	SET_BIT(TCCR0,COM01);
	CLR_BIT(TCCR0,COM00);
	/* Pre-scaler : /8 */
	CLR_BIT(TCCR0,CS02);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS00);
	/* Reset OCR0 */
	OCR0 = 0;
	/* Disable interrupts */
	CLR_BIT(TIMSK,TOIE0);
	CLR_BIT(TIMSK,OCIE0);
#endif
}
void MTIMER0_vSetCallBackOv(void (*ptr_to_fun)(void)){
	TIMER0_OV = ptr_to_fun;
}
void MTIMER0_vSetCallBackCTC(void (*ptr_to_fun)(void)){
	TIMER0_CTC = ptr_to_fun;
}
void MTIMER0_vSetPreloadValue(u8 A_u8Preload){
	TCNT0 = A_u8Preload;
}
void MTIMER0_vSetOCR0(u8 A_u8Value){
	OCR0 = A_u8Value;
}

void __vector_11(){
	if (TIMER0_OV != NULL){
		TIMER0_OV();
	}
}
void __vector_10(){
	if (TIMER0_CTC != NULL){
		TIMER0_CTC();
	}
}
