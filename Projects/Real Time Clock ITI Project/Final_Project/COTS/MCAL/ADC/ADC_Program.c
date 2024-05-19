/****************************************************/
/******** Author     : Shadi Bahaa   ****************/
/******** File name  : ADC_Program.c  ****************/
/******** Date       : Aug 24, 2023       ****************/
/******** Version    : V1            ****************/
/******** Desc       : ...           ****************/
/****************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "ADC_Interface.h"
#include "ADC_Private.h"
#include "ADC_Config.h"

/*
 * Init (voltage source - prescalar - auto trigger - Data direction)
 * read (Enable ADC - Start conversion - wait for flag - return reading)
 * */

void MADC_vInit(void){
	/* voltage source */
	SET_BIT(ADMUX,REFS0);
	CLR_BIT(ADMUX,REFS1);
	/* Data direction : Right */
	CLR_BIT(ADMUX,ADLAR);
	/* no auto trigger */
	CLR_BIT(ADCSRA,ADATE);
	/* Prescalar ==> /8 */
	SET_BIT(ADCSRA,ADPS2);
	SET_BIT(ADCSRA,ADPS1);
	CLR_BIT(ADCSRA,ADPS0);
}
/* 00000 ====> 11111  0===>31 */
/* 00011111 */
u16 MADC_u8GetDigitalValue(u8 A_u8Channel){
	A_u8Channel &= CHANNEL_MASK; /* channel 5 bits */
	ADMUX &= ADMUX_MASK; /* save last 3 bits, clear right 5 bits */
	ADMUX |= A_u8Channel;
	/* ENALBE ADC */
	SET_BIT(ADCSRA,ADEN);
	/* Start conversion */
	SET_BIT(ADCSRA,ADSC);
	/* Pooling on flag */
	while (GET_BIT(ADCSRA,ADIF)==0);
	SET_BIT(ADCSRA,ADIF);
	/* Reading value */
	return ADC;
}
