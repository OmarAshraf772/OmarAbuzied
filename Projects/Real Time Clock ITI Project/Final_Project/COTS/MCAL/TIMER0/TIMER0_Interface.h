/****************************************************/
/******** Author     : Shadi Bahaa   ****************/
/******** File name  : TIMER0_Interface.h  ****************/
/******** Date       : Aug 27, 2023       ****************/
/******** Version    : V1            ****************/
/******** Desc       : ...           ****************/
/****************************************************/
#ifndef COTS_MCAL_TIMER0_TIMER0_INTERFACE_H_
#define COTS_MCAL_TIMER0_TIMER0_INTERFACE_H_

void MTIMER0_vInit(void);
void MTIMER0_vSetCallBackOv(void (*ptr_to_fun)(void));
void MTIMER0_vSetPreloadValue(u8 A_u8Preload);
void MTIMER0_vSetCallBackCTC(void (*ptr_to_fun)(void));
void MTIMER0_vSetOCR0(u8 A_u8Value);

#endif /* COTS_MCAL_TIMER0_TIMER0_INTERFACE_H_ */
