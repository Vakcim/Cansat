/*
 * Geyger.c
 *
 * Created: 09.06.2021 19:53:19
 *  Author: 79776
 */ 

#ifndef F_CPU
	#define F_CPU 8000000
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
	TWI_WriteRegister(Geyger_Address, Geyger_Transform, 1);
	return 1;
}
extern uint8_t Geyger_Work_Counter(void){
	uint8_t Counter;
	TWI_ReadBytes(Geyger_Address, Geyger_Counter, 1, &Counter);
	return Counter;
}
extern uint32_t Geyger_Work_Intensive(void){
	uint32_t Intensive;
	TWI_ReadBytes(Geyger_Address, Geyger_Intensity, 1, &Intensive);
	return Intensive;
}