/*
 * Motor.c
 *
 * Created: 12/15/2022 8:51:29 AM
 *  Author: M.Sayed
 */ 
 #include "Motor.h"
 
 
 void Clock_Wise (Motor_type_en motor)
 {
	 switch (motor)
	 {
		 case Motor_1:
		 DIO_WRitePin(Motor_IN1,HIGH);
		 DIO_WRitePin(Motor_IN2,LOW);
		 break;
		 case Motor_2:
		 DIO_WRitePin(Motor_IN3,HIGH);
		 DIO_WRitePin(Motor_IN4,LOW);
		 break;
		 
	 }
	 
 }
 
void AntiClock_Wise (Motor_type_en motor)
 {
	 switch (motor)
	 {
		 case Motor_1:
		  DIO_WRitePin(Motor_IN1,LOW);
		  DIO_WRitePin(Motor_IN2,HIGH);
		 break;
		 case Motor_2:
		  DIO_WRitePin(Motor_IN3,LOW);
		  DIO_WRitePin(Motor_IN4,HIGH);
		 break;
		 
	 }
 }
 
 void Stop (void)
 {
	 DIO_WRitePin(Motor_IN1,LOW);
	 DIO_WRitePin(Motor_IN2,LOW);
	 DIO_WRitePin(Motor_IN3,LOW);
	 DIO_WRitePin(Motor_IN4,LOW);
 }
