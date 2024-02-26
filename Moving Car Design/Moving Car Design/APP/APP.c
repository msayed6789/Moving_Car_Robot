/*
 * APP.c
 *
 * Created: 4/13/2023 12:08:17 PM
 *  Author: AIO
 */ 
#include "APP.h"



#define PWM_F             400            //the frequency in Hz
#define PWM_Pin           PINA1
#define Forward_Long      LED1
#define Forward_Short     LED2
#define stop              LED3
#define rotate            LED4
volatile u32 PWM_count_ON=0;
volatile u32 PWM_count_OFF=0;
volatile u32 delay_1s=(((u32)(1000)*1000)/50000);
volatile u32 delay_3s=(((u32)(3000)*1000)/50000);
volatile u32 delay_2s=(((u32)(2000)*1000)/50000);
volatile u32 delay_5s=(((u32)(500)*1000)/50000);   //delay 0.5 s
volatile u32 Count_Flag=0;
u8 PWM_Count=0;
volatile u8 flag=0;


void App_init(void)
{
	sei();
	DIO_init();
	EXI_Enable(EX_INT0);
	EXI_Trigger(EX_INT0,RISING_EDGE);
	EXI_SetCallBack(EX_INT0, Stop_APP);
}

void App_start(void)
{
	if(Button_Check(Button1)==Pressed)
	{
		Timeout();
		while(Count_Flag!=delay_1s);
		flag=1;
	}
	while (flag==1)
	{
		//move forward for 3 sec with duty 50%
		PWM_duty(50);
		LED_OFF(stop);
		LED_ON(Forward_Long);
		Timeout();
		if (flag==0)
		{
			break;
		}
		while(Count_Flag!=delay_3s)
		{
			Clock_Wise(Motor_1);
			Clock_Wise(Motor_2);
		}
		 //stop motors for 0.5 sec
		Stop();
		LED_OFF(Forward_Long);
		LED_ON(stop);
		Timeout();
		if (flag==0)
		{
			break;
		}
		while(Count_Flag!=delay_5s);

		//rotate 90 degree (take 2 sec)
		DIO_WRitePin(PWM_Pin,HIGH);
		LED_OFF(stop);
		LED_ON(rotate);
		Timeout();
		if (flag==0)
		{
			break;
		}
		while(Count_Flag!=delay_2s)
		{
			AntiClock_Wise(Motor_1);
			Clock_Wise(Motor_2);
		}
		 //stop motors for 0.5 sec
		Stop();
		LED_OFF(rotate);
		LED_ON(stop);
		Timeout();
		if (flag==0)
		{
			break;
		}
		while(Count_Flag!=delay_5s);
		//move forward for 2 sec with duty 30%
		PWM_duty(30);
		LED_OFF(stop);
		LED_ON(Forward_Short);
		Timeout();
		if (flag==0)
		{
			break;
		}
		while(Count_Flag!=delay_2s)
		{
			Clock_Wise(Motor_1);
			Clock_Wise(Motor_2);
		}
		 //stop motors for 0.5 sec
		Stop();
		LED_OFF(Forward_Short);
		LED_ON(stop);
		Timeout();
		if (flag==0)
		{
			break;
		}
		while(Count_Flag<delay_5s);
		//rotate 90 degree (take 2 sec)
	    DIO_WRitePin(PWM_Pin,HIGH);
		LED_OFF(stop);
		LED_ON(rotate);
		Timeout();
		if (flag==0)
		{
			break;
		}
		while(Count_Flag!=delay_2s)
		{
			AntiClock_Wise(Motor_1);
			Clock_Wise(Motor_2);
		}
		 //stop motors for 0.5 sec
		Stop();
		LED_OFF(rotate);
		LED_ON(stop);
		Timeout();
		if (flag==0)
		{
			break;
		}
		while(Count_Flag<delay_5s);
	}
	
}

void PWM_duty(u8 duty)
{
	u32 temp=0;
	temp=((f32)1/PWM_F)*((f32)duty/100)*1000*1000;
	PWM_count_ON=temp/250;
	temp=((f32)1/PWM_F)*((f32)(100-duty)/100)*1000*1000;
	PWM_count_OFF=temp/250;
	PWM_Count=0;
	TIMER0_OV_SetCallBack(PWM_gen);
	TIMER0_OV_InterruptEnable();
	TCNT0=6;
	Timer0_init(TIMER0_NORMAL_MODE,TIMER0_SCALER_8);
}
void PWM_gen()
{
	PWM_Count++;
	if (PWM_Count==PWM_count_OFF)
	{
		DIO_WRitePin(PWM_Pin,HIGH);
	}
	else if (PWM_Count==(PWM_count_OFF+PWM_count_ON))
	{
		DIO_WRitePin(PWM_Pin,LOW);
		PWM_Count=0;
	}
	TCNT0=6;
}

void Timeout ()
{
	Timer1_Init(TIMER1_NORMAL_MODE,TIMER1_SCALER_8);
	Timer1_OCA_SetCallBack(Clear_Blocking);
	Timer1_OCA_InterruptEnable();
	TCNT1=15535;
	Count_Flag=0;
}
void Clear_Blocking ()
{
	Count_Flag++;
	TCNT1=15535;
}


void Stop_APP()
{
	flag=0;
	Stop();
	LED_OFF(Forward_Long);
	LED_OFF(Forward_Short);
	LED_OFF(rotate);
	LED_ON(stop);
	DIO_WRitePin(PWM_Pin,HIGH);
}

