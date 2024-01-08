/*
 * request.h
 *
 * Created: 2023-11-25 오전 4:44:07
 *  Author: USER
 */ 


#ifndef REQUEST_H_
#define REQUEST_H_

#include "C:\Users\USER\Documents\Atmel Studio\7.0\first\first\lcd\lcd.h"
#include "C:\Users\USER\Documents\Atmel Studio\7.0\first\first\display\verifyState\verifyState.h"
#include "C:\Users\USER\Documents\Atmel Studio\7.0\first\first\display\response\response.h"
#include "C:\Users\USER\Documents\Atmel Studio\7.0\first\first\display\cardDB\cardDB.h"

#define PRINT_DELAY 1500

void Request_init();
void Request_excute();
void Request_setVerifyModeLCD();
void Request_setAddModeLCD();
void Request_setDeleteModeLCD();
void Request_setVerifyTrueLCD();
void Request_setVerifyFalseLCD();
void Request_setAddTrueLCD();
void Request_setAddFalseLCD();
void Request_setDeleteTrueLCD();
void Request_setDeleteFalseLCD();

#endif /* REQUEST_H_ */