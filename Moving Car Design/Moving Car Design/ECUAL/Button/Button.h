/*
 * Button.h
 *
 * Created: 4/5/2023 4:19:28 AM
 *  Author: Mohamed Sayed
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "DIO_Interface.h"

/***************************Button Configuration********************************/
#define  Button1   PINA7
/*******************************************************************************/
typedef enum{
	Pressed,
	NotPressed	
}Button_Status;
Button_Status Button_Check(u8 Button);



#endif /* BUTTON_H_ */