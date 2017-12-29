# ShiftReg
A library for AVR Microcontrollers to use a parallel-out shift register.
Has been tested on an ATTiny85 with the 74HC595 Shift Register,
However it should work with any AVR Microcontroller.

### Pins
Within *ShiftReg.h*, the defines for the data pin, clock pin and latch pin should be done to whatever you want your microcontroller outputs to be. The OE pin of the shift register should be connected to ground, while the MR pin of the shift register should be connected to VCC.

eg. To define the data pin if PB5 of the microcontroller was connected to it:
```
#define SHIFTREG_DS_PORT PORTB
#define SHIFTREG_DS_PIN 5
```

Make sure to also set `F_CPU` to your microcontroller's clock speed within *ShiftReg.h*
