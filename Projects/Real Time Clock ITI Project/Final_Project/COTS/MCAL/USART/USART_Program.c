/****************************************************/
/******** Author     : Shadi Bahaa   ****************/
/******** File name  : USART_Program.c  ****************/
/******** Date       : Aug 30, 2023       ****************/
/******** Version    : V1            ****************/
/******** Desc       : ...           ****************/
/****************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "USART_Private.h"
#include "USART_Config.h"
#include "USART_Interface.h"

/*
 * Init : baud rate - enbale reciever and trans - frame format
 * transmit - recieve
 * */
void MUSART_vInit(u16 A_u16Baud){
	/* Enable of transmitter and receiver */
	SET_BIT(UCSRB,RXEN);
	SET_BIT(UCSRB,TXEN);
	/* Baud rate */
	UBRRH = (u8)(A_u16Baud>>8);
	UBRRL = (u8)A_u16Baud;
	/* Frame format configuration */
	UCSRC = UCSRC_CONFIG;
}
u8 MUSART_u8ReceiveData(void){
	while (GET_BIT(UCSRA,RXC)==0);
	return UDR;
}
void MUSART_vTransmitData(u8 A_u8Data){
	while (GET_BIT(UCSRA,UDRE)==0);
	UDR = A_u8Data;
}
