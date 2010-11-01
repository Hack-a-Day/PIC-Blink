//Simple program to get started programming
//PIC microcontrollers in Linux.
//Written by Devlin Thyne.
//Released to the public domain.

#include "pic/pic16f688.h"

//Use this configuration word:
//0x3ff4

//Set the configuration word:
unsigned int at 0x2007 configWord = 0x3ff4;

//To compile:
//sdcc -mpic14 -p16f688 blink.c

//To program the chip using picp:
//Assuming /dev/ttyUSB0 is the serial port.

//Erase the chip:
//picp /dev/ttyUSB0 16f688 -ep

//Write the program:
//picp /dev/ttyUSB0 16f688 -wp blink.hex

//Write the configuration word (no longer needed):
//picp /dev/ttyUSB0 16f688 -wc 0x3ff4

//Doing it all at once: erasing, programming, and reading back config words:
//picp /dev/ttyUSB0 16f688 -ef -wp blink.hex -rc

//To program the chip using pk2cmd:
//pk2cmd -M -PPIC16f688 -Fblink.hex


//Setup variables
unsigned char ucharCount = 0;
unsigned int uintDelayCount = 0;

void main(void)
{
	//Set PORTC to all outputs
	TRISC = 0x00;

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
