/****************************************************/
/******** Author     : Shadi Bahaa   ****************/
/******** File name  : ICU_Interface.h  ****************/
/******** Date       : Aug 29, 2023       ****************/
/******** Version    : V1            ****************/
/******** Desc       : ...           ****************/
/****************************************************/
#ifndef COTS_MCAL_ICU_ICU_INTERFACE_H_
#define COTS_MCAL_ICU_ICU_INTERFACE_H_

typedef enum{
	FALLING = 0,
	RISING
}ICU_EDGE_e;

void MICU_vInit(void);
void MICU_vSelectEdge(ICU_EDGE_e A_ICUEdge);
u32 MICU_u32GetTimeOn();
u32 MICU_u32GetTimeTotal();
#endif /* COTS_MCAL_ICU_ICU_INTERFACE_H_ */
