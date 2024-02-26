/*
 * Button.c
 *
 * Created: 4/5/2023 4:18:47 AM
 *  Author: Mohamed Sayed 
 */ 
 
 #include "Button.h"

 Button_Status Button_Check(u8 Button)
 {
	 if(DIO_ReadPin(Button)==0)
	 {
		 while (!DIO_ReadPin(Button));
		 return Pressed;
	 }
	 else 
	 {
		 return NotPressed;
	 }
 }