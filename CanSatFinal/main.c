/*
 * 
 *
 * Created: 04.06.2021 16:01:05
 * Author : Max
 */ 

#ifndef F_CPU
	#define F_CPU 8000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <inttypes.h>

#include "SPI.h"
#include "MyTWI.h"
#include "BMP.h"
#include "ADXL.h"
#include "ds18b20/ds18b20.h"
#include "nRF_24.h"
#include "MyTWI.h"
#include "Geyger.h"
#include "dht.h"

int main(void) {
	uint8_t datadht[4];
	int i = 0;
	DDRA = (1<<DDA5);
// 	PORTA |= (1<<DDA5);
// 	_delay_ms(1000);
// 	PORTA &= ~(1<<DDA5);
// 	_delay_ms(100);
PORTA |= (1<<DDA5);
_delay_ms(100);
PORTA &= ~(1<<DDA5);
_delay_ms(100);
	spi_init();
	PORTA |= (1<<DDA5);
	_delay_ms(100);
	PORTA &= ~(1<<DDA5);
	_delay_ms(100);
 	TWI_Init(F_CPU, 100000UL);
	 PORTA |= (1<<DDA5);
	 _delay_ms(100);
	 PORTA &= ~(1<<DDA5);
	 _delay_ms(100);
  	RF24_Begin(25);
	  PORTA |= (1<<DDA5);
	  _delay_ms(100);
	  PORTA &= ~(1<<DDA5);
	  _delay_ms(100);
	_delay_ms(500);
	RF24_Setup_Transmitter();
	uint8_t Package[RF24_PackageSize] = {  };
	int32_t BMtemperature, press, alt;
	int16_t Intensives, adxl_x, adxl_y, adxl_z, DStemperature;
	float pressure, altitude;
	
	while(1) {
		PORTA |= (1<<DDA5);
		_delay_ms(100);
		PORTA &= ~(1<<DDA5);
		_delay_ms(100);
		ds18b20convert( &PORTB, &DDRB, &PINB, ( 1 << PINB7 ), 0 );
		_delay_ms( 100 );
		if(ds18b20read( &PORTB, &DDRB, &PINB, ( 1 << PINB7 ), 0, &DStemperature ) == DS18B20_ERROR_OK) {
			DStemperature *= 6.25; DStemperature += 5500;
			
			Package[0] = ((DStemperature >> 8) & 0xFF);
			Package[1] = (DStemperature & 0xFF);
}
// 		if(BMP280_receiveData(&BMtemperature, &pressure, &altitude) == 1) {
// 			press = pressure * 100; alt = altitude * 10; BMtemperature += 5500;
// 			Package[2] = ((BMtemperature >> 8) & 0xFF);
// 			Package[3] = (BMtemperature & 0xFF);
// 			
// 			Package[4] = ((press >> 16) & 0xFF);
//  			Package[5] = ((press >> 8) & 0xFF);
//  			Package[6] = (press & 0xFF);
// 			
// 			Package[7] = ((alt >> 8) & 0xFF);
// 			Package[8] = (alt & 0xFF);
// }
// 		ADXL345_ReadXYZ(&adxl_x, &adxl_y, &adxl_z);
// 		adxl_x += 10000; adxl_y += 10000; adxl_z += 10000;
// 		
// 		Package[10] = ((adxl_x >> 8) & 0xFF);
// 		Package[11] = (adxl_x & 0xFF);
// 		
// 		Package[12] = ((adxl_y >> 8) & 0xFF);
// 		Package[13] = (adxl_y & 0xFF);
// 		
// 		Package[14] = ((adxl_z >> 8) & 0xFF);
// 		Package[15] = (adxl_z & 0xFF);	
// PORTA |= (1<<DDA5);
// _delay_ms(1000);
// PORTA &= ~(1<<DDA5);
// _delay_ms(100);
// 		if (i%50==0){Intensives = Geyger_Work_Intensive();
// 	 	Package[16] = ((Intensives >> 8) & 0xFF);
//   		Package[17] = (Intensives & 0xFF);
		if (i%11==0){
		dhtread(datadht);
		}
		Package[18] = datadht[1];
		RF24_Send(Package, RF24_PackageSize);
 		i+=1;
  		PORTA |= (1<<DDA5);
  		_delay_ms(100);
  		PORTA &= ~(1<<DDA5);
  		_delay_ms(100);
 }
	return 0;
}
	}