#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>

#include "dht.h"
#define _DHT22  /* Модель подключенного датчика. _DHT11 или _DHT22. */
#define _PORT_DHT  PORTA
#define _DDR_DHT   DDRA
#define _PIN_DHT   PINA
#define _PINNUM_DHT   7 /* Нумерация пинов с 0 */

int main(void)
{
	int datadht[4];
	DDRA = (1<<PA6);
	while(1){
		PORTA |= (1<<PA6);
		_delay_ms(1000);
		PORTA &= ~(1<<PA6);
		_delay_ms(1000);
}
}
