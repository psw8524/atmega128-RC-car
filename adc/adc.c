/*
 * adc.c
 *
 * Created: 2023-11-24 오전 9:43:16
 *  Author: USER
 */ 

#include "adc.h"

void adc_init(uint8_t channel){
	ADMUX = (1 << REFS0) | channel;
	ADCSRA |= (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}

uint16_t read_adc(){
	uint8_t adc_low, adc_high;
	uint16_t value;
	
	ADCSRA |= (1 << ADSC);
	
	while((ADCSRA & (1 << ADIF)) == (1 << ADIF));
	
	adc_low = ADCL;
	adc_high = ADCH;
	value = (adc_high << 8) | adc_low;
	
	return value;
}

void Adc_numDisplay(uint16_t value, char *str){
	str[0] = (value / 1000) + '0';
	str[1] = (value / 100) % 10 + '0';
	str[2] = (value / 10) % 10 + '0';
	str[3] = (value / 1) % 10 + '0';
	str[4] = '\0';
}