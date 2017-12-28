/********************************************************************************
Title: Shift Register Output Library
Author: Eric Li 
Date: 12/28/2017
Usage: 	Meant for use with the 74HC595 serial out/parallel out shift register.
		Make sure OE is connected to GND and MR is connected to VCC.
********************************************************************************/
#include "ShiftReg.h"

//Error Checks
#if !defined(SHIFTREG_DS_PORT) || !defined(SHIFTREG_DS_PIN)
	#error Defines for SHIFTREG_DS_PORT or SHIFTREG_DS_PIN are not defined.
#endif
#if !defined(SHIFTREG_SH_CP_PORT) || !defined(SHIFTREG_SH_CP_PIN)
	#error Defines for SHIFTREG_SH_CP_PORT or SHIFTREG_SH_CP_PIN is not defined.
#endif
#if !defined(SHIFTREG_ST_CP_PORT) || !defined(SHIFTREG_ST_CP_PIN)
	#error Defines for SHIFTREG_SH_CP_PORT or SHIFTREG_SH_CP_PIN is not defined.
#endif

//Macros/Variable Defines
#define _BV(bit) (1 << (bit)) //Bit value
#define DDR(port) (*(&port - 1)) //Data direction register

#define Delay_us(__us) \
	__builtin_avr_delay_cycles((unsigned long) ( F_CPU/1000000.0 * __us))
#define Delay_ms(__ms) \
	__builtin_avr_delay_cycles((unsigned long) ( F_CPU/1000.0 * __ms))

static inline void clockPulse(){
	SHIFTREG_SH_CP_PORT |= _BV(SHIFTREG_SH_CP_PIN);
	SHIFTREG_SH_CP_PORT &= ~_BV(SHIFTREG_SH_CP_PIN);
}

static inline void latchPulse(){
	SHIFTREG_ST_CP_PORT |= _BV(SHIFTREG_ST_CP_PIN);
	SHIFTREG_ST_CP_PORT &= ~_BV(SHIFTREG_ST_CP_PIN);
}

void shiftReg_Init(){
	DDR(SHIFTREG_DS_PORT) |= _BV(SHIFTREG_DS_PIN);
	DDR(SHIFTREG_SH_CP_PORT) |= _BV(SHIFTREG_SH_CP_PIN);
	DDR(SHIFTREG_ST_CP_PORT) |= _BV(SHIFTREG_ST_CP_PIN);
}

void shiftReg_Write(uint8_t data){
	shiftReg_Send(data);
	latchPulse();
}

void shiftReg_Write_LSBFIRST(uint8_t data){
	shiftReg_Send_LSBFIRST(data);
	latchPulse();
}

void shiftReg_Send(uint8_t data){
	for(uint8_t i=0; i<8; i++){
		if(data & 0x01) SHIFTREG_DS_PORT |= _BV(SHIFTREG_DS_PIN);
		else SHIFTREG_DS_PORT &= ~_BV(SHIFTREG_DS_PIN);
		clockPulse();
		data >>= 1;
	}
}

void shiftReg_Send_LSBFIRST(uint8_t data){
	for(uint8_t i=0; i<8; i++){
		if(data & 0x01) SHIFTREG_DS_PORT |= _BV(SHIFTREG_DS_PIN);
		else SHIFTREG_DS_PORT &= ~_BV(SHIFTREG_DS_PIN);
		clockPulse();
		data >>= 1;
	}	
}

void shiftReg_Latch(uint8_t state){
	if(state==1) SHIFTREG_ST_CP_PORT |= _BV(SHIFTREG_ST_CP_PIN);
	else if(state==0) SHIFTREG_ST_CP_PORT &= ~_BV(SHIFTREG_ST_CP_PIN);
}