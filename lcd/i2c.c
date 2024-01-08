/*
 * i2c.c
 *
 * Created: 2023-11-24 오전 2:09:04
 *  Author: USER
 */ 
#include "I2C.h"


void I2C_init()
{
	I2C_DDR |= (1<<I2C_SCL) | (1<<I2C_SDA);
	//TWBR = 12; //400kHz SCL
	//TWBR = 32; //200kHz SCL
	//TWBR = 72; //100kHz SCL
	TWBR = 100;
	TWSR = 0;
}

void I2C_txByte(uint8_t SLA_W, uint8_t data)
{
	// Start 신호 송신
	I2C_start();
	// dev 주소 + Write bit 데이터 송신
	I2C_txDevAddr(SLA_W);
	// 데이터 송신
	I2C_txData(data);
	// Stop 신호 송신
	I2C_stop();
}

void I2C_start()
{
	//Send START condition
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	
	//Wait for TWINT flag set. This indicates that the START condition has been transmitted
	while (!(TWCR & (1<<TWINT)));
}

void I2C_txDevAddr(uint8_t SLA_W)
{
	//Load SLA_W into TWDR Register
	TWDR = SLA_W;   //값을 넣고
	
	//Clear TWINT bit in TWCR to start transmission of address
	TWCR = (1<<TWINT) | (1<<TWEN);  //전송시작
	
	//Wait for TWINT flag set.
	//This indicates that the SLA_W has been transmitted,
	//and ACK/NACK has been received.
	while (!(TWCR & (1<<TWINT)));  //전송이 완료될때까지
}

void I2C_txData(uint8_t data)
{
	//Load DATA into TWDR Register. Clear TWINT bit in TWCR to start transmission of data
	TWDR = data;
	TWCR = (1<<TWINT) | (1<<TWEN);
	
	//Wait for TWINT flag set.
	//This indicates that the DATA has been transmitted,
	//and ACK/NACK has been received.
	while (!(TWCR & (1<<TWINT)));
}

void I2C_stop()
{
	//Transmit STOP condition
	TWCR = (1<<TWINT)|(1<<TWEN)| (1<<TWSTO);
}