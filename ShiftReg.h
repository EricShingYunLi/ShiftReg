/********************************************************************************
Pin Defines:
	The connections to DS, SH_CP and ST_CP need to be defined.

	SHIFTREG_DS_PORT - Port of the pin to be connected to DS
	SHIFTREG_DS_PIN - Pin number of the pin to be connected to DS
			
	SHIFTREG_SH_CP_PORT - Port of the pin to be connected to SH_CP
	SHIFTREG_SH_CP_PIN - Pin number of the pin to be connected to SH_CP

	SHIFTREG_ST_CP_PORT - Port of the pin to be connected to ST_CP
	SHIFTREG_ST_CP_PIN - Pin number of the pin to be connected to ST_CP

	eg. If the latch pin was PB5, the defines would be:
		#define SHIFTREG_ST_CP_PORT PORTB
		#define SHIFTREG_ST_CP_PIN 5

Note: It is assumed OE is connected to GND and MR is connected to VCC.
********************************************************************************/

#ifndef SHIFTREG_H
#define SHIFTREG_H

#include "inttypes.h"

//PIN DEFINES
//Set these to your choice of configuration

//Clock frequency of microcontroller
#define F_CPU			1000000L

//Data pin
#define SHIFTREG_DS_PORT		PORTB
#define SHIFTREG_DS_PIN			0

//Clock pin
#define SHIFTREG_SH_CP_PORT		PORTB
#define SHIFTREG_SH_CP_PIN		1

//Latch pin
#define SHIFTREG_ST_CP_PORT		PORTB
#define SHIFTREG_ST_CP_PIN		2

//FUNCTIONS
//Functions available to the user

//Initiates pinouts
void shiftReg_Init();

//Sends data and updates shift register
void shiftReg_Write(uint8_t data);
void shiftReg_Write_LSBFIRST(uint8_t data);

//Sends data, but doesn't update until shiftReg_Latch() is called
//Optimal for daisy chaining
void shiftReg_Send(uint8_t data);
void shiftReg_Send_LSBFIRST(uint8_t data);

//only should be used with shiftReg_Send and shiftReg_Send_LSBFIRST
//Toggles latch pin between LOW and HIGH states at each call
void shiftReg_Latch_Toggle();

#endif