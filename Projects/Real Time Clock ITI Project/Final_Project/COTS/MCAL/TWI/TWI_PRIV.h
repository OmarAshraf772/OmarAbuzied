/*
 * TWI_PRIV.h
 *
 *  Created on: Sep 2, 2023
 *      Author: Omar
 */

#define TWBR     *((volatile u8 *)0x20)
#define TWCR     *((volatile u8 *)0x56)
#define TWSR     *((volatile u8 *)0x21)
#define TWAR     *((volatile u8 *)0x22)
#define TWDR     *((volatile u8 *)0x23)

#define TWINT 7
#define TWEA  6
#define TWSTA 5
#define TWSTO 4
#define TWEN  2

#define TWPS1  1
#define TWPS0  0
#define TWD0   0

#define START_ACK 			0x08
#define REPEATED_START_ACK  0x10
#define SLAVE_W_ACK 		0x18
#define MSTR_W_BYTE_ACK 	0x28
#define SLAVE_R_ACK 		0x40
#define MSTR_R_BYTE_ACK 	0x50
#define STATUS_MASK 		0xF8



