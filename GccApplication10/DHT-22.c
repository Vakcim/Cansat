#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>     /* ��� delay */

unsigned int delay_counter=0;


#define DHT_PORT        PORTA // ����
#define DHT_DDR         DDRA
#define DHT_PIN         PINA
#define DHT_BIT         7 // ��� �����

int dhtread (int *datadht) // ���� � ��������� ������� ����������,�� �� ��������� �� �������� ����� ������� �������
{

	uint8_t  j = 0, i = 0;
	
	datadht[0] = datadht[1] = datadht[2] = datadht[3] = datadht[4] = 0;
	
	DHT_DDR|=(1<<DHT_BIT); //pin as output
	DHT_PORT&=~(1<<DHT_BIT);
	_delay_ms(18);


	DHT_PORT|=(1<<DHT_BIT);
	DHT_DDR&=~(1<<DHT_BIT);
	_delay_us(50); // +1 ��� attiny(��������� ��� ������)
	if (DHT_PIN&(1<<DHT_BIT)) return 0;
	_delay_us(80); // +1 ��� attiny(��������� ��� ������)
	if (!(DHT_PIN&(1<<DHT_BIT))) return 0;
	while (DHT_PIN&(1<<DHT_BIT));
	for (j=0; j<5; j++)
	{
		datadht[j]=0;
		for(i=0; i<8; i++)
		{
			while (!(DHT_PIN&(1<<DHT_BIT)));
			_delay_us (30);
			if (DHT_PIN&(1<<DHT_BIT))
			datadht[j]|=1<<(7-i);
			while (DHT_PIN&(1<<DHT_BIT));
		}
	}
	

	return 1;
}

// int __attribute__((noreturn)) main(void)
// {
// // ��� ��������� ��������� ���������
//
//
//     for(;;){                /* ���� ��������� */
//
//
//
//
// 	_delay_ms(1000);
//
// 	if (delay_counter==0) {
//
// 	  delay_counter=10; // ��������� ������ 10 ������
//
//
//
// 	   dhtread (); //��� ���� ����� ��������� �� ������: ���������� 0 ��������� �� ������..
//
// 		   int f,h;
// 	   if (datadht[0]==0 && datadht[1]==0 && datadht[2]==0 && datadht[3]==0) {
// //��������� ������:�� ��������� ������ !!
// 
// 	  } else if (datadht[0] + datadht[1] + datadht[2] + datadht[3] == datadht[4]) {
//
//
//
// 	  if (datadht[1]==0 && datadht[3]==0) { //���� ��� ���������� ������� ��� ����� ����,�� ��� dht11
// 
// 	    f=datadht[2]*10;
// 	    h=datadht[0]*10;
// 
// 	  }else  { // dht22
// 
// 	h = datadht[0] * 256 + datadht[1];
// 
//        f = (datadht[2] & 0x7F)* 256 + datadht[3];
// 
//        if (datadht[2] & 0x80)  f *= -1;
// 
// 	}
//
//
//
// 	} else {
// //��������� ������: CHECKSUM !!
//
// 	}
//
// // ��� ���������� int f - �����������*10 � h - ���������*10
// // ����� ���������� � float ���������� ,�������������� ������� ����..
//
// 	}
// 		delay_counter--;
//     }
//
// }



