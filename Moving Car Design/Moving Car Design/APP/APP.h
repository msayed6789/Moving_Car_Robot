/*
 * APP.h
 *
 * Created: 4/13/2023 12:08:38 PM
 *  Author: AIO
 */ 


#ifndef APP_H_
#define APP_H_

#include "DIO_Interface.h"
#include "Timers.h"
#include "EX_Interrupt.h"
#include "Button.h"
#include "LED.h"
#include "Motor.h"
void App_init(void);
void App_start(void);

void Timeout (void);
void Clear_Blocking (void);
void PWM_gen(void);
void PWM_duty(u8 duty);
void Stop_APP(void);




#endif /* APP_H_ */