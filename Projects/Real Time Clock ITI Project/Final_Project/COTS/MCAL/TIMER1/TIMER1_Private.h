/****************************************************/
/******** Author     : Shadi Bahaa   ****************/
/******** File name  : TIMER1_Private.h  ****************/
/******** Date       : Aug 28, 2023       ****************/
/******** Version    : V1            ****************/
/******** Desc       : ...           ****************/
/****************************************************/
#ifndef COTS_MCAL_TIMER1_TIMER1_PRIVATE_H_
#define COTS_MCAL_TIMER1_TIMER1_PRIVATE_H_

#define TCCR1A  *((volatile u8 *)(0x4F))
#define TCCR1B  *((volatile u8 *)(0x4E))
/*#define TCNT1L
#define TCNT1H*/
#define TCNT1   *((volatile u16 *)(0x4C))
/*#define OCR1AL
#define OCR1AH*/
#define OCR1A   *((volatile u16 *)(0x4A))
/*#define OCR1BL
#define OCR1BH*/
#define OCR1B   *((volatile u16 *)(0x48))
/*#define ICR1L
#define ICR1H*/
#define ICR1    *((volatile u16 *)(0x46))
#define TIMSK   *((volatile u8 *)(0x59))
#define TIFR    *((volatile u8 *)(0x58))

#define COM1A1   7
#define COM1A0   6
#define COM1B1   5
#define COM1B0   4

#define WGM11    1
#define WGM10    0

#define WGM13    4
#define WGM12    3

#define CS12     2
#define CS11     1
#define CS10     0

#endif /* COTS_MCAL_TIMER1_TIMER1_PRIVATE_H_ */
