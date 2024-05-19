
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_INT.h"
#include "../MCAL/USART/USART_Interface.h"
#include "../HAL/LCD/LCD_INT.h"
#include "../MCAL/GIE/GIE_Interface.h"
#include "../HAL/KPD/KPD_INT.h"
#include "../MCAL/TIMER0/TIMER0_Interface.h"
#include <util/delay.h>
#include "../MCAL/timer/timer.h"
#define BAUD_RATE 9600
#define F_CPU 8000000UL

#define ZERO 0b0000
#define ONE 0b0001
#define TWO 0b0010
#define THREE 0b0011
#define FOUR 0b0100
#define FIVE 0b0101
#define SIX 0b0110
#define SEVEN 0b0111
#define EIGHT 0b1000
#define NINE 0b1001
#define NOTPRESSED 50

volatile u8 seconds_counter=0;
u8 minutes_counter=0,hours_counter=0,A_hours_counter=24,A_minutes_counter=60;

u8 i=0;


u16 combine(u16 num1, u16 num2) {
    u16 t = num2;
    u16 multiplier = 1;

    if (t == 0) {
        multiplier = 10;
        t = 1;
    }

    while (t > 0) {
        num1 *= 10;
        t /= 10;
    }

    return num1 + num2 * multiplier;
}

void Clock_Count(){
	static u16 counter = 0;
	counter++;
	if (counter == 3907){
		seconds_counter++;
		counter = 0;

		MTIMER0_vSetPreloadValue(192);
	}
}
void main(void){
	HLCD_vInit();
		HKPD_vInit();
		u8 key;
		u8 H_first_digit,H_second_digit,M_first_digit,M_second_digit,S_first_digit,S_second_digit,ALARM_H_first_digit,ALARM_H_second_digit,ALARM_M_first_digit,ALARM_M_second_digit;
		u8 numbers[10]={ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
		MUSART_vInit((F_CPU / (16UL * BAUD_RATE)) - 1);
		MDIO_vSetPinDirection(PORT_B,0,OUTPUT);
		MDIO_vSetPinDirection(PORT_B,1,OUTPUT);
		MDIO_vSetPinDirection(PORT_B,2,OUTPUT);
		MDIO_vSetPinDirection(PORT_B,3,OUTPUT);
		MDIO_vSetPinDirection(PORT_B,7,OUTPUT);
		MDIO_vSetPinDirection(PORT_D,2,OUTPUT);
		MDIO_vSetPinDirection(PORT_D,3,OUTPUT);
		MDIO_vSetPinDirection(PORT_D,4,OUTPUT);
		MDIO_vSetPinDirection(PORT_D,5,OUTPUT);
		MDIO_vSetPinDirection(PORT_D,6,OUTPUT);
		MDIO_vSetPinDirection(PORT_D,7,OUTPUT);
		HLCD_vSendString("1: Set Clock");
		HLCD_vMoveTo(1,0);
		HLCD_vSendString("2: Set Alarm");
	MTIMER0_vSetCallBackOv(Clock_Count);
	MTIMER0_vInit();
	MGIE_vEnableInterrupts();
	while (1){
		key=HKPD_U8GetPressedKey();
		if (key !=NOTPRESSED){

			if(key==1){
			HLCD_vDisplayClear();
			HLCD_vSendString("Hours: ");
			HLCD_vMoveTo(1,0);
			_delay_ms(500);
			do{
				H_first_digit=HKPD_U8GetPressedKey();

			  } while (H_first_digit == NOTPRESSED);
				HLCD_vSendNumber(H_first_digit);
				_delay_ms(300);
			do{
				H_second_digit=HKPD_U8GetPressedKey();
			} while (H_second_digit == NOTPRESSED);
			HLCD_vSendNumber(H_second_digit);
			hours_counter=combine(H_first_digit,H_second_digit);
			_delay_ms(300);

			HLCD_vDisplayClear();
			HLCD_vSendString("Minutes: ");
			HLCD_vMoveTo(1,0);
			_delay_ms(500);
			do{
				M_first_digit=HKPD_U8GetPressedKey();

			  } while (M_first_digit == NOTPRESSED);
				HLCD_vSendNumber(M_first_digit);
				_delay_ms(300);
			do{
				M_second_digit=HKPD_U8GetPressedKey();
			  } while (M_second_digit == NOTPRESSED);
				HLCD_vSendNumber(M_second_digit);
				minutes_counter=combine(M_first_digit,M_second_digit);
				_delay_ms(300);

			HLCD_vDisplayClear();
			HLCD_vSendString("Seconds: ");
			HLCD_vMoveTo(1,0);
			_delay_ms(500);
			do{
				S_first_digit=HKPD_U8GetPressedKey();

			  } while (S_first_digit == NOTPRESSED);
				HLCD_vSendNumber(S_first_digit);
				_delay_ms(300);
			do{
				S_second_digit=HKPD_U8GetPressedKey();
			  } while (S_second_digit == NOTPRESSED);
				HLCD_vSendNumber(S_second_digit);
				seconds_counter=combine(S_first_digit,S_second_digit);
				_delay_ms(300);
				HLCD_vDisplayClear();
				HLCD_vSendString("1: Set Clock");
				HLCD_vMoveTo(1,0);
				HLCD_vSendString("2: Set Alarm");
				MUSART_vTransmitData(99);
				_delay_ms(700);
				MUSART_vTransmitData(hours_counter);
				_delay_ms(700);
				MUSART_vTransmitData(minutes_counter);
				_delay_ms(700);
				MUSART_vTransmitData(seconds_counter);
				_delay_ms(700);

			}
			else if(key==2){
			HLCD_vDisplayClear();
			HLCD_vSendString("Hour: ");
			HLCD_vMoveTo(1,0);
			_delay_ms(500);
			do{
				ALARM_H_first_digit=HKPD_U8GetPressedKey();

			  } while (ALARM_H_first_digit == NOTPRESSED);
				HLCD_vSendNumber(ALARM_H_first_digit);
				_delay_ms(300);
			do{
				ALARM_H_second_digit=HKPD_U8GetPressedKey();
			} while (ALARM_H_second_digit == NOTPRESSED);
			HLCD_vSendNumber(ALARM_H_second_digit);
			A_hours_counter=combine(ALARM_H_first_digit,ALARM_H_second_digit);
			_delay_ms(300);

			HLCD_vDisplayClear();
			HLCD_vSendString("Minutes: ");
			HLCD_vMoveTo(1,0);
			_delay_ms(500);
			do{
				ALARM_M_first_digit=HKPD_U8GetPressedKey();

			  } while (ALARM_M_first_digit == NOTPRESSED);
				HLCD_vSendNumber(ALARM_M_first_digit);
				_delay_ms(300);
			do{
				ALARM_M_second_digit=HKPD_U8GetPressedKey();
			  } while (ALARM_M_second_digit == NOTPRESSED);
				HLCD_vSendNumber(ALARM_M_second_digit);
				A_minutes_counter=combine(ALARM_M_first_digit,ALARM_M_second_digit);
				_delay_ms(300);
				HLCD_vDisplayClear();
				HLCD_vSendString("1: Set Clock");
				HLCD_vMoveTo(1,0);
				HLCD_vSendString("2: Set Alarm");
				MUSART_vTransmitData(88);
				_delay_ms(500);
				MUSART_vTransmitData(A_hours_counter);
				_delay_ms(500);
				MUSART_vTransmitData(A_minutes_counter);
				_delay_ms(500);


			}
			else {
				HLCD_vDisplayClear();
				HLCD_vSendString("Invalid Choice ");
				_delay_ms(1000);
				HLCD_vDisplayClear();
				HLCD_vSendString("1: Set Clock");
				HLCD_vMoveTo(1,0);
				HLCD_vSendString("2: Set Alarm");
			}

			  }
		if(hours_counter==A_hours_counter && minutes_counter==A_minutes_counter && seconds_counter<3){
					MDIO_vSetPinValue(PORT_B,7,HIGH);
					MUSART_vTransmitData(77);
					_delay_ms(2000);

				}

			MDIO_vSetPinValue(PORT_D,2,HIGH);
			MDIO_vSetPinValue(PORT_D,3,HIGH);
			MDIO_vSetPinValue(PORT_D,4,HIGH);
			MDIO_vSetPinValue(PORT_D,5,HIGH);
			MDIO_vSetPinValue(PORT_D,6,HIGH);
			MDIO_vSetPinValue(PORT_D,7,LOW);
			MDIO_vSetPortValue(PORT_B,seconds_counter%10);
			_delay_ms(5);

			MDIO_vSetPinValue(PORT_D,2,HIGH);
			MDIO_vSetPinValue(PORT_D,3,HIGH);
			MDIO_vSetPinValue(PORT_D,4,HIGH);
			MDIO_vSetPinValue(PORT_D,5,HIGH);
			MDIO_vSetPinValue(PORT_D,6,LOW);
			MDIO_vSetPinValue(PORT_D,7,HIGH);
			MDIO_vSetPortValue(PORT_B,seconds_counter/10);
			_delay_ms(5);

			MDIO_vSetPinValue(PORT_D,2,HIGH);
			MDIO_vSetPinValue(PORT_D,3,HIGH);
			MDIO_vSetPinValue(PORT_D,4,HIGH);
			MDIO_vSetPinValue(PORT_D,5,LOW);
			MDIO_vSetPinValue(PORT_D,6,HIGH);
			MDIO_vSetPinValue(PORT_D,7,HIGH);
			MDIO_vSetPortValue(PORT_B,minutes_counter%10);
			_delay_ms(5);

			MDIO_vSetPinValue(PORT_D,2,HIGH);
			MDIO_vSetPinValue(PORT_D,3,HIGH);
			MDIO_vSetPinValue(PORT_D,4,LOW);
			MDIO_vSetPinValue(PORT_D,5,HIGH);
			MDIO_vSetPinValue(PORT_D,6,HIGH);
			MDIO_vSetPinValue(PORT_D,7,HIGH);
			MDIO_vSetPortValue(PORT_B,minutes_counter/10);
			_delay_ms(5);

			MDIO_vSetPinValue(PORT_D,2,HIGH);
			MDIO_vSetPinValue(PORT_D,3,LOW);
			MDIO_vSetPinValue(PORT_D,4,HIGH);
			MDIO_vSetPinValue(PORT_D,5,HIGH);
			MDIO_vSetPinValue(PORT_D,6,HIGH);
			MDIO_vSetPinValue(PORT_D,7,HIGH);
			MDIO_vSetPortValue(PORT_B,hours_counter%10);
			_delay_ms(5);

			MDIO_vSetPinValue(PORT_D,2,LOW);
			MDIO_vSetPinValue(PORT_D,3,HIGH);
			MDIO_vSetPinValue(PORT_D,4,HIGH);
			MDIO_vSetPinValue(PORT_D,5,HIGH);
			MDIO_vSetPinValue(PORT_D,6,HIGH);
			MDIO_vSetPinValue(PORT_D,7,HIGH);
			MDIO_vSetPortValue(PORT_B,hours_counter/10);
			_delay_ms(5);



			if (seconds_counter==60)
					{
						seconds_counter=0;
						minutes_counter++;
					}
					if (minutes_counter==60)
					{
						minutes_counter=0;
						hours_counter++;
					}
					if (hours_counter==24)
					{
						hours_counter=0;
					}

					if (seconds_counter>60 || minutes_counter>60 || hours_counter>24 ){
						HLCD_vDisplayClear();
						MUSART_vTransmitData(66);
						HLCD_vSendString("Invalid Time");
						_delay_ms(2000);
						seconds_counter=0;
						minutes_counter=0;
						hours_counter=0;
						HLCD_vDisplayClear();
						HLCD_vSendString("1: Set Clock");
						HLCD_vMoveTo(1,0);
						HLCD_vSendString("2: Set Alarm");
					}

					if (A_minutes_counter>60 || A_hours_counter>24 ){
						HLCD_vDisplayClear();
						HLCD_vSendString("Invalid Time");
						MUSART_vTransmitData(65);
						_delay_ms(2000);
						A_minutes_counter=60;
						A_hours_counter=24;
						HLCD_vDisplayClear();
						HLCD_vSendString("1: Set Clock");
						HLCD_vMoveTo(1,0);
						HLCD_vSendString("2: Set Alarm");
					}




				}
	}


