/****************************************************/
/******** Author     : Shadi Bahaa   ****************/
/******** File name  : EXTI_Interface.h  ****************/
/******** Date       : Aug 23, 2023       ****************/
/******** Version    : V1            ****************/
/******** Desc       : ...           ****************/
/****************************************************/
#ifndef COTS_MCAL_EXTI_EXTI_INTERFACE_H_
#define COTS_MCAL_EXTI_EXTI_INTERFACE_H_

void MEXTI_vInit();
void MEXTI_vSetCallBack(void (*ptr_to_fun)(void), u8 A_IntID);

#endif /* COTS_MCAL_EXTI_EXTI_INTERFACE_H_ */
