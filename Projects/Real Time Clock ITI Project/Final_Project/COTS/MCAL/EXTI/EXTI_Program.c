/****************************************************/
/******** Author     : Shadi Bahaa   ****************/
/******** File name  : EXTI_Program.c  ****************/
/******** Date       : Aug 23, 2023       ****************/
/******** Version    : V1            ****************/
/******** Desc       : ...           ****************/
/****************************************************/

/* sense control:falling edge - rising edge
 * enable interrupt
 * */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "EXTI_Interface.h"
#include "EXTI_Private.h"
#include "EXTI_Config.h"
#define  NULL  0
/* int0 / int2 */

/* 1- App ==> App
 * 2- Code size >>>>
 * */
/* 1,0,2 */

void (*Ptr_To_Int0)(void) = NULL;
void (*Ptr_To_Int1)(void) = NULL;
void (*Ptr_To_Int2)(void) = NULL;

void MEXTI_vInit(){
#if (INT1_ENABLED == ENABLE)
	/* SET INTERRUPT 1 TO FALLING EDGE */
	SET_BIT(MCUCR,ISC11);
	CLR_BIT(MCUCR,ISC10);
	/* Enable INT1 */
	SET_BIT(GICR,INT1);
#endif
#if (INT0_ENABLED == ENABLE)
	/* SET INTERRUPT 0 TO falling EDGE */
	SET_BIT(MCUCR,ISC01);
	CLR_BIT(MCUCR,ISC00);
	/* Enable INT0 */
	SET_BIT(GICR,INT0);
#endif
#if (INT2_ENABLED == ENABLE)
	/* SET INTERRUPT 2 TO RISING EDGE */
	SET_BIT(MCUCSR,ISC2);
	/* Enable INT0 */
	SET_BIT(GICR,INT2);
#endif
}
void MEXTI_vSetCallBack(void (*ptr_to_fun)(void), u8 A_IntID){
	if (A_IntID == 0){
		Ptr_To_Int0 = ptr_to_fun;
	}else if (A_IntID == 1){
		Ptr_To_Int1 = ptr_to_fun;
	}else if (A_IntID == 2){
		Ptr_To_Int2 = ptr_to_fun;
	}
}
// INT 0
void __vector_1(){
	if (Ptr_To_Int0 != NULL){
		Ptr_To_Int0();
	}
}
// INT 1
void __vector_2(){
	if (Ptr_To_Int1 != NULL){
		Ptr_To_Int1();
	}
}
// INT 2
void __vector_3(){
	if (Ptr_To_Int2 != NULL){
		Ptr_To_Int2();
	}
}
