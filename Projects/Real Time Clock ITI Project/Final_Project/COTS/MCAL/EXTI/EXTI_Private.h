/****************************************************/
/******** Author     : Shadi Bahaa   ****************/
/******** File name  : EXTI_Private.h  ****************/
/******** Date       : Aug 23, 2023       ****************/
/******** Version    : V1            ****************/
/******** Desc       : ...           ****************/
/****************************************************/
#ifndef COTS_MCAL_EXTI_EXTI_PRIVATE_H_
#define COTS_MCAL_EXTI_EXTI_PRIVATE_H_

#define MCUCR   *((volatile u8 *)0x55)
#define MCUCSR  *((volatile u8 *)0x54)
#define GICR    *((volatile u8 *)0x5B)
#define GIFR    *((volatile u8 *)0x5A)

#define ISC11   3
#define ISC10   2
#define INT2    5
#define INT1    7
#define INT0    6
#define ISC01   1
#define ISC00   0
#define ISC2    6

void __vector_1() __attribute__((signal));
void __vector_2() __attribute__((signal));
void __vector_3() __attribute__((signal));

#endif /* COTS_MCAL_EXTI_EXTI_PRIVATE_H_ */
