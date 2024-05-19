/****************************************************/
/******** Author     : Shadi Bahaa   ****************/
/******** File name  : SPI_Private.h  ****************/
/******** Date       : Aug 31, 2023       ****************/
/******** Version    : V1            ****************/
/******** Desc       : ...           ****************/
/****************************************************/
#ifndef COTS_MCAL_SPI_SPI_PRIVATE_H_
#define COTS_MCAL_SPI_SPI_PRIVATE_H_

#define SPCR   *((volatile u8*)0x2D)
#define SPSR   *((volatile u8*)0x2E)
#define SPDR   *((volatile u8*)0x2F)

#define SPE    6
#define MSTR   4
#define SPR0   0
#define SPIF   7

#endif /* COTS_MCAL_SPI_SPI_PRIVATE_H_ */
