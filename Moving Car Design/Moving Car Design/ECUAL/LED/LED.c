/*
 * LED.c
 *
 * Created: 4/5/2023 2:00:41 AM
 *  Author: Mohamed Sayed
 */ 

#include "LED.h"


void LED_ON (u8 LED )
{
	DIO_WRitePin(LED,HIGH);
}
void LED_OFF (u8 LED )
{
		DIO_WRitePin(LED,LOW);
}



