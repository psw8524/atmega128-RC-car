/*
 * verify.c
 *
 * Created: 2023-11-25 오전 4:39:37
 *  Author: USER
 */ 

#include "verify.h"

uint8_t rfidState = 0;

void ResponseVerify_checkCardNumber(uint8_t *data)
{
	if(CardDB_checkCardNumber(data) == TRUE){
		Request_setVerifyTrueLCD();
		rfidState = 1;
	}else{
		Request_setVerifyFalseLCD();
	}
}