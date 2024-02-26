/*
 * LED.h
 *
 * Created: 4/5/2023 2:01:12 AM
 *  Author: AIO
 */ 


#ifndef LED_H_
#define LED_H_
#include "DIO_Interface.h"
/***************************LED Configuration******************************************************/
#define  LED1      PINB0
#define  LED2      PINB1
#define  LED3      PINB2
#define  LED4      PINB3
#define  LED5      PINA4
#define  LED6      PINA5

#define LED_Num     4
/*************************************************************************************************/


void LED_ON (u8 LED );
void LED_OFF (u8 LED );


#endif /* LED_H_ */