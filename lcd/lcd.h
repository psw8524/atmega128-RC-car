/*
 * lcd.h
 *
 * Created: 2023-11-24 오전 12:57:33
 *  Author: USER
 */ 


#ifndef LCD_H_
#define LCD_H_

#define F_CPU	16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "I2C.h"

#define LCD_RS				0
#define LCD_RW				1
#define LCD_E				2
#define LCD_BACK_LIGHT		3
#define LCD_CONTROL_DDR		DDRC
#define LCD_CONTROL_PORT	PORTC
#define LCD_DATA_DDR		DDRC
#define LCD_DATA_PORT		PORTC

#define LCD__8BIT_FUNCTION_SET	0x38  // 2Line, 5*8 Font
#define LCD_4BIT_FUNCTION_SET	0x28
#define LCD_DISPLAY_OFF		0x08
#define LCD_DISPLAY_ON		0x0C
#define LCD_DISPLAY_CLEAR	0x01
#define LCD_ENTRY_MODE_SET	0x06

#define LCD_SLW				0x27
#define LCD_SLA_W			(LCD_SLW<<1)

void LCD_init();
void I2C_init();
void GpioInit();
void GpioWriteControl(uint8_t control);
void GpioWriteData(uint8_t data);
void LCD_cmdMode();
void LCD_dataMode();
void LCD_writeMode();
void LCD_enableHigh();
void LCD_enableLow();
void LCD_writeByte(uint8_t data);
void LCD_writeCmdData(uint8_t data);
void LCD_writeCharData(char data);
void LCD_displayClear();
void LCD_displayOff();
void LCD_displayOn();
void LCD_writeString(char *str);
void LCD_gotoXY(uint8_t row, uint8_t col);
void LCD_writeStringXY(uint8_t row, uint8_t col, char *str);
void LCD_writeNibble(uint8_t data);
void LCD_backLightOn();
void LCD_backLightOff();


#endif /* LCD_H_ */