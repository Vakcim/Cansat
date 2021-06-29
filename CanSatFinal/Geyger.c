/*
 * Geyger.c
 *
 * Created: 09.06.2021 19:53:19
 *  Author: 79776
 */ 

#ifndef F_CPU
	#define F_CPU 8000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>
#include "Geyger.h"
#include "MyTWI.h"

extern uint8_t Geyger_Begin(void) {
	uint8_t ReceivedValue;
	TWI_ReadBytes(Geyger_Address, Geyger_Register_ID, 1, &ReceivedValue);
	
	if (ReceivedValue != Geyger_ID) { return 0; }
	TWI_WriteRegister(Geyger_Address, Geyger_Transform, 1);
	TWI_WriteRegister(Geyger_Address, Geyger_Sensitiviti, 10);
	return 1;
}
extern uint8_t Geyger_Work_Counter(void){
	uint8_t Counter;
	TWI_ReadBytes(Geyger_Address, Geyger_Counter, 1, &Counter);
	return Counter;
}
// uint16_t BMP280_read16(uint8_t address) {
// 	uint8_t BMP280_buffer[2];
// 	TWI_ReadBytes(BMP280_dev_addr, address, 2, BMP280_buffer);
// 	return ((uint16_t) ((BMP280_buffer[0]<<8)|BMP280_buffer[1]));
// } uint16_t Geyger_Work_Intensive(void){
	uint8_t Intensive[2];
	TWI_ReadBytes(Geyger_Address, Geyger_Intensity, 2, Intensive);
	return (uint16_t) ((Intensive[0]<<8) | Intensive[1]);
}