/****************************************************/
/******** Author     : Shadi Bahaa   ****************/
/******** File name  : TIMER1_Interface.h  ****************/
/******** Date       : Aug 28, 2023       ****************/
/******** Version    : V1            ****************/
/******** Desc       : ...           ****************/
/****************************************************/
#ifndef COTS_MCAL_TIMER1_TIMER1_INTERFACE_H_
#define COTS_MCAL_TIMER1_TIMER1_INTERFACE_H_

void MTIMER1_vInit(void);
void MTIMER1_vSetOCR1AValue(u16 A_u16Val);
void MTIMER1_vSetOCR1BValue(u16 A_u16Val);
void MTIMER1_vSetICR1Value(u16 A_u16Val);

#endif /* COTS_MCAL_TIMER1_TIMER1_INTERFACE_H_ */
