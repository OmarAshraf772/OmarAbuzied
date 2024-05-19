/****************************************************/
/******** Author     : Shadi Bahaa   ****************/
/******** File name  : TIMER0_Private.h  ****************/
/******** Date       : Aug 27, 2023       ****************/
/******** Version    : V1            ****************/
/******** Desc       : ...           ****************/
/****************************************************/
#ifndef COTS_MCAL_TIMER0_TIMER0_PRIVATE_H_
#define COTS_MCAL_TIMER0_TIMER0_PRIVATE_H_

#define TCCR0   *((volatile u8 *)0x53)
#define TCNT0   *((volatile u8 *)0x52)
#define OCR0    *((volatile u8 *)0x5C)
#define TIMSK   *((volatile u8 *)0x59)
#define TIFR    *((volatile u8 *)0x58)

#define WGM01   6
#define WGM00   3

#define CS02   2
#define CS01   1
#define CS00   0

#define TOIE0  0

#define COM01  5
#define COM00  4

#define OCIE0  1

void __vector_11() __attribute__((signal));
void __vector_10() __attribute__((signal));

#endif /* COTS_MCAL_TIMER0_TIMER0_PRIVATE_H_ */
