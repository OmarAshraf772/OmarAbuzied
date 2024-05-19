/****************************************************/
/******** Author     : Shadi Bahaa   ****************/
/******** File name  : USART_Interface.h  ****************/
/******** Date       : Aug 30, 2023       ****************/
/******** Version    : V1            ****************/
/******** Desc       : ...           ****************/
/****************************************************/
#ifndef COTS_MCAL_USART_USART_INTERFACE_H_
#define COTS_MCAL_USART_USART_INTERFACE_H_

void MUSART_vInit(u16 A_u16Baud);
u8 MUSART_u8ReceiveData(void);
void MUSART_vTransmitData(u8 A_u8Data);

#endif /* COTS_MCAL_USART_USART_INTERFACE_H_ */
