/*
 * Geyger_Debug.c
 *
 * Created: 09.06.2021 19:50:59
 * Author : 79776
 */ 

#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <inttypes.h>
#include "MyTWI.h"
#include "Geyger.h"


int main(void) {
	uint8_t Counter;
	uint16_t Intensive;
	DDRA = (1 << PA7);
	TWI_Init(F_CPU, 1000000UL);
	while (1){
		if (Geyger_Begin()) { 
			PORTA |= (1<<PA7); 
			_delay_ms(1000);
			PORTA &= ~(1<<PA7);
			_delay_ms(1000);/* Датчик определился */ }
	else { 
			PORTA |= (1<<PA7);
			_delay_ms(10000);
			PORTA &= ~(1<<PA7);
			_delay_ms(1000);/* Датчик не определился */ }
		Counter = Geyger_Work_Counter();
		Intensive = Geyger_Work_Intensive();
		
	}
}
