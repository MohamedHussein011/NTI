/*
 * main.c
 *
 *  Created on: Mar 7, 2024
 *      Author: Mohamed Hussein
 */

#include "Std_Types.h"
#include "util/delay.h"
#include "Dio.h"


void main(void)
{
	*((uint8*) 0x31) = 0xff;	//DDRD
	*((uint8*) 0x34) = 0xff;	//DDRC
	*((uint8*) 0x37) = 0xff;	//DDRB
	*((uint8*) 0x3A) = 0xff;	//DDRA

	Dio_WriteChannel(DIO_CHANNEL0, STD_HIGH);		//A0    HIGH
	Dio_WriteChannel(DIO_CHANNEL1, STD_HIGH);		//A1    HIGH
	Dio_WriteChannel(DIO_CHANNEL2, STD_HIGH);		//A2    HIGH
	Dio_WriteChannel(DIO_CHANNEL3, STD_HIGH);		//A3    HIGH
	Dio_WriteChannel(DIO_CHANNEL4, STD_HIGH);		//A4    HIGH
	Dio_WriteChannel(DIO_CHANNEL5, STD_LOW);        //A5    LOW
	Dio_WriteChannel(DIO_CHANNEL6, STD_LOW);        //A6    LOW
	Dio_WriteChannel(DIO_CHANNEL7, STD_LOW);        //A7    LOW

	Dio_WritePort(DIO_PORT1,0xff);				//PORTB 	HIGH
	Dio_WritePort(DIO_PORT2,0x00);				//PORTC		LOW

	Dio_ChannelGroupType dio_group = {0x1E, 1, DIO_PORT3};		//group (D1 -> D4), D1 & D2 high, D3 & D4 low
	Dio_WriteChannelGroup(&dio_group, 0x03);

	_delay_ms(3000);

	Dio_FlipChannel(DIO_CHANNEL10);				//B2 was high, now low
	Dio_FlipChannel(DIO_CHANNEL14);             //B6 was high, now low

	Dio_FlipChannel(DIO_CHANNEL17);             //C1 was low, now high
	Dio_FlipChannel(DIO_CHANNEL20);             //c4 was low, now high

	_delay_ms(3000);
	Dio_MaskedWritePort(DIO_PORT2, 0x07, 0xE0);		//C5 -> C6 is high now



	while(1)
	{

	}
}

