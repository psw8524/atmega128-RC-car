/*
 * cardDB.c
 *
 * Created: 2023-11-25 오전 5:00:49
 *  Author: USER
 */ 

#include "cardDB.h"

cardDB VerifyCard = {0,};

uint8_t CardDB_addCard(uint8_t *cardNum)
{
	if (VerifyCard.cardCounter >= CARD_MAX) return FALSE;
	if (CardDB_checkCardNumber(cardNum)) return FALSE;
	
	memcpy(VerifyCard.regCard[VerifyCard.cardCounter], cardNum, 5);
	VerifyCard.cardCounter++;
	return TRUE;
}

uint8_t CardDB_checkCardNumber(uint8_t *cardNum)
{
	for (int i=0; i<VerifyCard.cardCounter; i++) {
		if (!memcmp(VerifyCard.regCard[i], cardNum, 5)) {
			return TRUE;
		}
	}
	return FALSE;
}

uint8_t CardDB_deleteCard(uint8_t *cardNum)
{
	for (int i=0; i<VerifyCard.cardCounter; i++) {
		if (!memcmp(VerifyCard.regCard[i], cardNum, 5)) {
			for (int j=i; ((j+1) < VerifyCard.cardCounter); j++) {
				memcpy(VerifyCard.regCard[j], VerifyCard.regCard[j+1], 5);
			}
			VerifyCard.cardCounter--;
			return TRUE;
		}
	}
	return FALSE;
}