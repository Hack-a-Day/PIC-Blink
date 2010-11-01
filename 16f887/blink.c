//Simple program to get started programming
//PIC microcontrollers in Linux.
//Written by Devlin Thyne.
//Released to the public domain.

#include "pic/pic16f887.h"

//Use these configuration words:
//0x3ff4 0x3fff

//Set the configuration words:
unsigned int at _CONFIG1 configWord1 = 0x2FF4;
unsigned int at _CONFIG2 configWord2 = 0x3fff;

//To compile:
//sdcc -mpic14 -p16f887 blink.c

//To program the chip using picp:
//Assuming /dev/ttyUSB0 is the serial port.

//Erase the chip:
//picp /dev/ttyUSB0 16f887 -ef

//Write the program:
//picp /dev/ttyUSB0 16f887 -wp blink.hex

//Write the configuration words (optional):
//picp /dev/ttyUSB0 16f887 -wc 0x3ff4 0x3fff

//Doing it all at once: erasing, programming, and reading back config words:
//picp /dev/ttyUSB0 16f887 -ef -wp blink.hex -rc

//To program the chip using pk2cmd:
//pk2cmd -M -PPIC16f887 -Fblink.hex

//Setup variables
unsigned char ucharCount = 0;
unsigned int uintDelayCount = 0;

void main(void)
{
	//Set PORTC to all outputs
	TRISC = 0x00;

	ucharCount = 0;
	uintDelayCount = 0;

	//Loop forever
	while ( 1 )
	{
		//Delay Loop
		while ( uintDelayCount < 10000 )
		{
			//Increment the loop counter
			uintDelayCount++;
		}

		//Reset delay loop counter
		uintDelayCount = 0;

		//Increment the count
		ucharCount++;

		//Display the count on the PORTC pins
		PORTC = ucharCount;

	}

}
