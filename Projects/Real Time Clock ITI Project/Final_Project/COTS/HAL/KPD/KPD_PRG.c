

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_INT.h"
#include "KPD_INT.h"
#include <util/delay.h>

void HKPD_vInit(void){
	MDIO_vSetPortDirection(KPD_PORT,0b11110000);
	MDIO_vSetPortValue(KPD_PORT,0b11111111);
}
u8 HKPD_U8GetPressedKey(void){
	u8 local_u8Key= 50;
	for (u8 col = 0; col < 4; col++){
		MDIO_vSetPinValue(KPD_PORT,col+4,LOW);
		for (u8 row = 0; row < 4; ++row){
			u8 local_u8tmp = MDIO_U8GetPinValue(KPD_PORT,row);
			if (local_u8tmp == 0){
				local_u8Key = (row * 4) + col;
				while (MDIO_U8GetPinValue(KPD_PORT,row) == 0);
				_delay_ms(30);
			}
		}
		MDIO_vSetPinValue(KPD_PORT,col + 4,HIGH);
	}
	return local_u8Key;
}
