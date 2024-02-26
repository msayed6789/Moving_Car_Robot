/*
 * Motor.h
 *
 * Created: 12/15/2022 8:52:05 AM
 *  Author: M.Sayed
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_
#include "DIO_Interface.h"


/**************************Pin_config**************************/
#define Motor_IN1  PINC0
#define Motor_IN2  PINC1
#define Motor_IN3  PINC3
#define Motor_IN4  PINC4

typedef enum
{
	Motor_1,
	Motor_2
}Motor_type_en;




void Clock_Wise (Motor_type_en motor);
void AntiClock_Wise (Motor_type_en motor);
void Stop (void);


#endif /* MOTOR_H_ */