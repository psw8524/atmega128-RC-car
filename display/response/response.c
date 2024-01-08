/*
 * response.c
 *
 * Created: 2023-11-25 오전 3:54:12
 *  Author: USER
 */ 

#include "response.h"

Button btnMode;
uint8_t ControlCarState = NONE;

void Response_init()
{
	Button_init(&btnMode, &DDRA, &PINA, 0);
	mfrc522_init();
}

void Response_checkEvent()
{
	Response_checkButtonEvent();
	Response_checkRfidEvent();
}

void Response_checkButtonEvent() // Rfid
{
	static uint32_t prevButtonTime;
	if (getTick() - prevButtonTime < 50) return;
	prevButtonTime = getTick();
	
	uint8_t VerifyState = VerifyStateModel_getState();
	
	switch (VerifyState)
	{
		case VERIFY :
		if (Button_getState(&btnMode) == ACT_RELEASE) {
			VerifyStateModel_setState(ADD);
		}
		break;
		case ADD:
		if (Button_getState(&btnMode) == ACT_RELEASE) {
			VerifyStateModel_setState(DELETE);
		}
		break;
		case DELETE:
		if (Button_getState(&btnMode) == ACT_RELEASE) {
			VerifyStateModel_setState(VERIFY);
		}
		break;
	}	
}

void Response_checkRfidEvent()
{
	static uint32_t prevRfidTime;
	if (getTick() - prevRfidTime < 1000) return;
	prevRfidTime = getTick();
	
	uint8_t cardSerialData[5];
	uint8_t byte = mfrc522_request(PICC_REQALL, cardSerialData);
	
	if (byte != CARD_FOUND) return;
	
	mfrc522_get_card_serial(cardSerialData);
	
	uint8_t VerifyState = VerifyStateModel_getState();
	
	switch (VerifyState)
	{
		case VERIFY :
		ResponseVerify_checkCardNumber(cardSerialData);
		break;
		case ADD:
		ResponseAdd_addCard(cardSerialData);
		break;
		case DELETE:
		ResponseDelete_deleteCard(cardSerialData);
		break;
	}
}

void Control_checkButtonEvent() // Alcohol, drive or parking
{
	static uint32_t prevButtonTime;
	if (getTick() - prevButtonTime < 50) return;
	prevButtonTime = getTick();
	
	switch (ControlCarState)
	{
		case NONE :
		if (Button_getState(&btnMode) == ACT_RELEASE) {
			ControlCarState = ALCOHOL;
		}
		break;
		case ALCOHOL :
		if (Button_getState(&btnMode) == ACT_RELEASE) {
			ControlCarState = DRIVING;
		}
		break;
	}
}