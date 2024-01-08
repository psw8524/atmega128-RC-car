/*
 * response.h
 *
 * Created: 2023-11-25 오전 3:53:54
 *  Author: USER
 */ 


#ifndef RESPONSE_H_
#define RESPONSE_H_

#include <avr/io.h>
#include "C:\Users\USER\Documents\Atmel Studio\7.0\first\first\button\button.h"
#include "C:\Users\USER\Documents\Atmel Studio\7.0\first\first\mfrc522\device\mfrc522.h"
#include "C:\Users\USER\Documents\Atmel Studio\7.0\first\first\timetick\timetick.h"
#include "C:\Users\USER\Documents\Atmel Studio\7.0\first\first\display\verifyState\verifyState.h"
#include "C:\Users\USER\Documents\Atmel Studio\7.0\first\first\display\add\add.h"
#include "C:\Users\USER\Documents\Atmel Studio\7.0\first\first\display\delete\delete.h"
#include "C:\Users\USER\Documents\Atmel Studio\7.0\first\first\display\verify\verify.h"
#include "C:\Users\USER\Documents\Atmel Studio\7.0\first\first\lcd\lcd.h"

enum {NONE, ALCOHOL, DRIVING};

void Response_init();
void Response_checkEvent();
void Response_checkButtonEvent();
void Response_checkRfidEvent();
void Control_checkButtonEvent();

#endif /* RESPONSE_H_ */