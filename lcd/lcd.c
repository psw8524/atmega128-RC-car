/*
 * lcd.c
 *
 * Created: 2023-11-24 오전 12:58:27
 *  Author: USER
 */ 

#include "lcd.h"

uint8_t lcdData = 0;

void LCD_init()
{
	I2C_init();
	LCD_backLightOn();
	
	_delay_ms(15);
	LCD_cmdMode();
	LCD_writeMode();
	LCD_writeNibble(0x30);
	_delay_ms(5);
	LCD_writeNibble(0x30);
	_delay_ms(1);
	LCD_writeNibble(0x30);
	LCD_writeNibble(0x20);
	LCD_writeByte(LCD_4BIT_FUNCTION_SET);
	LCD_writeByte(LCD_DISPLAY_OFF);
	LCD_writeByte(LCD_DISPLAY_CLEAR);
	LCD_writeByte(LCD_ENTRY_MODE_SET);
	LCD_writeByte(LCD_DISPLAY_ON);
	

}

void LCD_sendToI2C(uint8_t sla_w, uint8_t data)
{
	I2C_txByte(sla_w, data);
}

void LCD_cmdMode()
{
	lcdData &= ~(1<<LCD_RS);
	LCD_sendToI2C(LCD_SLA_W, lcdData);
}

void LCD_dataMode()
{
	lcdData |= (1<<LCD_RS);
	LCD_sendToI2C(LCD_SLA_W, lcdData);
}

void LCD_writeMode()
{
	lcdData &= ~(1<<LCD_RW);
	LCD_sendToI2C(LCD_SLA_W, lcdData);
}

void LCD_enableHigh()
{
	lcdData |= (1<<LCD_E);
	LCD_sendToI2C(LCD_SLA_W, lcdData);
	_delay_ms(1);
}

void LCD_enableLow()
{
	lcdData &= ~(1<<LCD_E);
	LCD_sendToI2C(LCD_SLA_W, lcdData);
	_delay_ms(1);
}

void LCD_writeByte(uint8_t data)
{
	//GpioWriteData(data);
	LCD_writeNibble(data);	// data의 상위 4비트 전송
	data = data << 4; // data <<= 4
	LCD_writeNibble(data);	// data의 하위 4비트 전송
}

void LCD_writeNibble(uint8_t data)  // 상위 4 bit nibble data만 전송
{
	LCD_enableHigh();
	lcdData = (lcdData & 0x0f) | (data & 0xf0); // 상위 4 bit  0 으로 만들어줌
	LCD_sendToI2C(LCD_SLA_W, lcdData);
	LCD_enableLow();
	
}

void LCD_writeCmdData(uint8_t data)
{
	LCD_cmdMode();
	LCD_writeMode();
	//LCD_enableHigh();
	LCD_writeByte(data);
	//LCD_enableLow();
}

void LCD_writeCharData(char data)
{
	LCD_dataMode();
	LCD_writeMode();
	//LCD_enableHigh();
	LCD_writeByte(data);
	//	LCD_enableLow();
}

void LCD_displayClear()
{
	LCD_writeCmdData(LCD_DISPLAY_CLEAR);
}

void LCD_displayOff()
{
	LCD_writeCmdData(LCD_DISPLAY_OFF);
}

void LCD_displayOn()
{
	LCD_writeCmdData(LCD_DISPLAY_ON);
}

void LCD_writeString(char *str)
{
	for (int i=0; str[i]; i++) {
		LCD_writeCharData(str[i]);
	}
}

void LCD_gotoXY(uint8_t row, uint8_t col)
{
	col %= 16;
	row %= 2;
	
	uint8_t lcdRegisterAddress = (0x40 * row) + col;
	uint8_t command = 0x80 + lcdRegisterAddress;
	LCD_writeCmdData(command);
}

void LCD_writeStringXY(uint8_t row, uint8_t col, char *str)
{
	LCD_gotoXY(row, col);
	LCD_writeString(str);
}

void LCD_backLightOn()
{
	lcdData |= (1<<LCD_BACK_LIGHT);
	LCD_sendToI2C(LCD_SLA_W, lcdData);
}

void LCD_backLightOff()
{
	lcdData &= ~(1<<LCD_BACK_LIGHT);
	LCD_sendToI2C(LCD_SLA_W, lcdData);
}