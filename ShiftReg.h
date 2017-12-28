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

//PIN DEFINES
//Set these to your configuration

//Clock Frequency of Microcontroller
#define F_CPU					1000000L

//Data Pin
#define SHIFTREG_DS_PORT		PORTB
#define SHIFTREG_DS_PIN			0

//Clock Pin
#define SHIFTREG_SH_CP_PORT		PORTB
#define SHIFTREG_SH_CP_PIN		1

//Latch Pin
#define SHIFTREG_ST_CP_PORT		PORTB
#define SHIFTREG_ST_CP_PIN		2

//FUNCTIONS
//Functions available to the user
void shiftReg_Init();
void shiftReg_Write(uint8_t data);
void shiftReg_Send(uint8_t data);
void shiftReg_Latch(uint8_t state);

#endif