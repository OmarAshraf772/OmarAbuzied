/****************************************************/
/******** Author     : Shadi Bahaa   ****************/
/******** File name  : DIO_INT.h  ****************/
/******** Date       : Aug 17, 2023       ****************/
/******** Version    : V1            ****************/
/******** Desc       : ...           ****************/
/****************************************************/
#ifndef DIO_INT_H_
#define DIO_INT_H_

#define INPUT 0
#define OUTPUT 1
#define PORT_A 0
#define PORT_B 1
#define PORT_C 2
#define PORT_D 3
#define HIGH 1
#define LOW 0
/* Description: set pin direction
 * Arguments :
 * 	A_u8portNumber: 0 - 3 (PORTA - PORTB - PORTC - PORTD)
 *  A_u8pinNumber : 0 - 7 (PIN0 - PIN1 ---- PIN7)
 *  A_u8dir       : 0 - 1 (INPUT - OUTPUT)
 * Return type    : Nothing
 * */
void MDIO_vSetPinDirection(u8 A_u8portNumber, u8 A_u8pinNumber, u8 A_u8dir);
void MDIO_vSetPortDirection(u8 A_u8portNumber, u8 A_u8dir);
void MDIO_vSetPinValue(u8 A_u8portNumber, u8 A_u8pinNumber, u8 A_u8val);
void MDIO_vSetPortValue(u8 A_u8portNumber, u8 A_u8val);
void MDIO_vTogglePinValue(u8 A_u8portNumber, u8 A_u8pinNumber);
u8 MDIO_U8GetPinValue(u8 A_u8portNumber, u8 A_u8pinNumber);
#endif /* DIO_INT_H_ */
