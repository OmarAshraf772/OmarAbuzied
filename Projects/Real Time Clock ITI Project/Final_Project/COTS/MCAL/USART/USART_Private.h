/****************************************************/
/******** Author     : Shadi Bahaa   ****************/
/******** File name  : USART_Private.h  ****************/
/******** Date       : Aug 30, 2023       ****************/
/******** Version    : V1            ****************/
/******** Desc       : ...           ****************/
/****************************************************/
#ifndef COTS_MCAL_USART_USART_PRIVATE_H_
#define COTS_MCAL_USART_USART_PRIVATE_H_

#define UDR     *((volatile u8 *)0x2C)
#define UCSRA   *((volatile u8 *)0x2B)
#define UCSRB   *((volatile u8 *)0x2A)
#define UCSRC   *((volatile u8 *)0x40)
#define UBRRL   *((volatile u8 *)0x29)
#define UBRRH   *((volatile u8 *)0x40)

#define RXEN    4
#define TXEN    3

#define UCSRC_CONFIG 0b10000110
#define U2X          1

#define RXC     7
#define UDRE    5

#endif /* COTS_MCAL_USART_USART_PRIVATE_H_ */
