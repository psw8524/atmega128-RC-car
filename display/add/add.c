/*
 * add.c
 *
 * Created: 2023-11-25 오전 4:27:19
 *  Author: USER
 */ 

#include "add.h"

void ResponseAdd_addCard(uint8_t *data)
{
	if(CardDB_addCard(data) == TRUE)
	Request_setAddTrueLCD();
	
	else
	Request_setAddFalseLCD();
}