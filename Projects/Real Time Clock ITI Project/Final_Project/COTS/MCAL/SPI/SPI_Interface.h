/****************************************************/
/******** Author     : Shadi Bahaa   ****************/
/******** File name  : SPI_Interface.h  ****************/
/******** Date       : Aug 31, 2023       ****************/
/******** Version    : V1            ****************/
/******** Desc       : ...           ****************/
/****************************************************/
#ifndef COTS_MCAL_SPI_SPI_INTERFACE_H_
#define COTS_MCAL_SPI_SPI_INTERFACE_H_

void MSPI_vMasterInit(void);
void MSPI_vMasterTransmit(u8 A_u8Data);
void MSPI_vSlaveInit(void);
u8 MSPI_u8SlaveReceive(void);

#endif /* COTS_MCAL_SPI_SPI_INTERFACE_H_ */
