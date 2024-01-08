/*
 * request.c
 *
 * Created: 2023-11-25 오전 4:44:30
 *  Author: USER
 */ 

#include "request.h"

char strBuff[30];
char blankBuff[] = "               ";


void Request_init()
{
	LCD_init();
}

void Request_excute()
{
	uint8_t modeState = VerifyStateModel_getState();
	
	switch (modeState)
	{
		case VERIFY:
		Request_setVerifyModeLCD();
		break;
		case ADD:
		Request_setAddModeLCD();
		break;
		case DELETE:
		Request_setDeleteModeLCD();
		break;
	}
}

void Request_setVerifyModeLCD()
{
	if (!strncmp(strBuff, "Verify Mode", 6)) return;
	
	strcpy(strBuff, "Verify Mode ");
	LCD_writeStringXY(0, 0, strBuff);
}

void Request_setAddModeLCD()
{
	if (!strncmp(strBuff, "Add Mode", 6)) return;
	
	strcpy(strBuff, "Add Mode    ");
	LCD_writeStringXY(0, 0, strBuff);
}

void Request_setDeleteModeLCD()
{
	if (!strncmp(strBuff, "Delete Mode", 6)) return;
	
	strcpy(strBuff, "Delete Mode ");
	LCD_writeStringXY(0, 0, strBuff);
}

void Request_setVerifyTrueLCD()
{
	if (!strncmp(strBuff, "Pass", 4)) return;
	
	strcpy(strBuff, "Pass         ");
	LCD_writeStringXY(1, 0, strBuff);
	
	_delay_ms(PRINT_DELAY);
	LCD_writeStringXY(1, 0, blankBuff);
}

void Request_setVerifyFalseLCD()
{
	if (!strncmp(strBuff, "Fail", 4)) return;
	
	strcpy(strBuff, "Fail         ");
	LCD_writeStringXY(1, 0, strBuff);
	
	_delay_ms(PRINT_DELAY);
	LCD_writeStringXY(1, 0, blankBuff);
}

void Request_setAddTrueLCD()
{
	if (!strncmp(strBuff, "Added", 5)) return;
	
	strcpy(strBuff, "Added         ");
	LCD_writeStringXY(1, 0, strBuff);
	
	_delay_ms(PRINT_DELAY);
	LCD_writeStringXY(1, 0, blankBuff);
}

void Request_setAddFalseLCD()
{
	if (!strncmp(strBuff, "Added Fail", 10)) return;
	
	strcpy(strBuff, "Added fail    ");
	LCD_writeStringXY(1, 0, strBuff);
	
	_delay_ms(PRINT_DELAY);
	LCD_writeStringXY(1, 0, blankBuff);
}

void Request_setDeleteTrueLCD()
{
	if (!strncmp(strBuff, "Deleted", 7)) return;
	
	strcpy(strBuff, "Deleted        ");
	LCD_writeStringXY(1, 0, strBuff);
	
	_delay_ms(PRINT_DELAY);
	LCD_writeStringXY(1, 0, blankBuff);
}

void Request_setDeleteFalseLCD()
{
	if (!strncmp(strBuff, "Deleted fail", 12)) return;
	
	strcpy(strBuff, "Deleted fail   ");
	LCD_writeStringXY(1, 0, strBuff);
	
	_delay_ms(PRINT_DELAY);
	LCD_writeStringXY(1, 0, blankBuff);
}