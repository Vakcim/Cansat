#include "radSens1v2.h"
#include "MyTWI.h"

void beginGeyger(){
	uint8_t a;
	TWI_ReadBytes(0x66, 0x00, 1, &a);
	
}
