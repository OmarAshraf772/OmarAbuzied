/****************************************************/
/******** Author     : Shadi Bahaa   ****************/
/******** File name  : SPI_Program.c  ****************/
/******** Date       : Aug 31, 2023       ****************/
/******** Version    : V1            ****************/
/******** Desc       : ...           ****************/
/****************************************************/

/*INIT: Master / slave - enable spi - clk
 * CPLOARITY - SETUP/SAMPLE - LSB/MSB
 * SlaveRecieve - MasterTransmit
 * */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "SPI_Config.h"
#include "SPI_Private.h"
#include "SPI_Interface.h"
void MSPI_vMasterInit(void)
{
	/* Set MOSI and SCK output, all others input */
	/* Enable SPI, Master, set clock rate fck/16 */
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}
void MSPI_vMasterTransmit(u8 A_u8Data)
{
	/* Start transmission */
	SPDR = A_u8Data;
	/* Wait for transmission complete */
	while(GET_BIT(SPSR,SPIF)==0);
}
void MSPI_vSlaveInit(void)
{
    /* Set MISO output, all others input */
	/* Enable SPI */
	SPCR = (1<<SPE);
}
u8 MSPI_u8SlaveReceive(void)
{
	/* Wait for reception complete */
	while(GET_BIT(SPSR,SPIF)==0);
	;
	/* Return data register */
	return SPDR;
}
