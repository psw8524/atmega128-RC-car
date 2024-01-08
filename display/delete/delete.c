/*
 * delete.c
 *
 * Created: 2023-11-25 오전 4:34:59
 *  Author: USER
 */ 

#include "delete.h"

void ResponseDelete_deleteCard(uint8_t * data)
{
	if(CardDB_deleteCard(data) == TRUE)
	Request_setDeleteTrueLCD();
	
	else
	Request_setDeleteFalseLCD();
}