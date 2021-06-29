/*
 * Geyger.h
 *
 * Created: 09.06.2021 19:53:47
 *  Author: 79776
 */ 


#ifndef GEYGER_H_
	#define GEYGER_H_
	
	#define Geyger_ID			0x7D
	#define Geyger_Address		0x66
	
	#define Geyger_Register_ID	0x00
	#define Geyger_Intensity	0x03
	#define	Geyger_Counter		0x09
	#define	Geyger_Transform	0x11
	#define	Geyger_Sensitiviti	0x12
	extern uint8_t Geyger_Begin(void);
	extern uint8_t Geyger_Work_Counter(void);
	extern uint32_t Geyger_Work_Intensive(void);
#endif /* GEYGER_H_ */