/****************************************************/
/******** Author     : Shadi Bahaa   ****************/
/******** File name  : ADC_Private.h  ****************/
/******** Date       : Aug 24, 2023       ****************/
/******** Version    : V1            ****************/
/******** Desc       : ...           ****************/
/****************************************************/
#ifndef COTS_MCAL_ADC_ADC_PRIVATE_H_
#define COTS_MCAL_ADC_ADC_PRIVATE_H_

#define ADMUX   *((volatile u8 *)0x27)
#define ADCSRA  *((volatile u8 *)0x26)
#define ADC     *((volatile u16 *)0x24)
#define SFIOR   *((volatile u8 *)0x50)


#define REFS0 6
#define REFS1 7
#define ADLAR 5
#define ADATE 5

#define ADPS2 2
#define ADPS1 1
#define ADPS0 0

#define ADEN  7
#define ADSC  6
#define ADIF  4
#define CHANNEL_MASK 0b00011111
#define ADMUX_MASK   0b11100000
#endif /* COTS_MCAL_ADC_ADC_PRIVATE_H_ */
