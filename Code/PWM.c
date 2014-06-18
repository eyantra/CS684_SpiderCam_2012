#include "PWM.h"

void PWM_timerT5Init()
{
	TCCR5B = 0x00; //Stop
	TCNT5H = 0xFF; //Counter higher 8-bit value to which OCR5xH value is compared with
	TCNT5L = 0x01; //Counter lower 8-bit value to which OCR5xH value is compared with

	OCR5AH = 0x00; //Output compare register high value for Front Left
	OCR5AL = 0xFF; //Output compare register low value for Front Left
	
	OCR5BH = 0x00; //Output compare register high value for Front Right
	OCR5BL = 0xFF; //Output compare register low value for Front Right
	
	OCR5CH = 0x00; //Output compare register high value for Back Right
	OCR5CL = 0xFF; //Output compare register low value for Back Right
	
	
	TCCR5A = 0xA9; //COM5A1=1, COM5A0=0; COM5B1=1, COM5B0=0; COM5C1=1
// COM5C0=0
//For Overriding normal port functionality to OCRnA outputs. WGM51=0, WGM50=1 Along With GM52 //in TCCR5B for Selecting FAST PWM 8-bit Mode
	TCCR5B = 0x0B; //WGM12=1; CS12=0, CS11=1, CS10=1 (Prescaler=64)
}

void PWM_timerT3Init()
{
	TCCR3B = 0x00; //Stop
	TCNT3H = 0xFF; //Counter higher 8-bit value to which OCR5xH value is compared with
	TCNT3L = 0x01; //Counter lower 8-bit value to which OCR5xH value is compared with

	OCR3AH = 0x00; //Output compare register high value for Back Left
	OCR3AL = 0xFF; //Output compare register low value for Back Left
	
	
	TCCR3A = 0xA9; //COM5A1=1, COM5A0=0; COM5B1=1, COM5B0=0; COM5C1=1
// COM5C0=0
//For Overriding normal port functionality to OCRnA outputs. WGM51=0, WGM50=1 Along With GM52 //in TCCR5B for Selecting FAST PWM 8-bit Mode
	TCCR3B = 0x0B; //WGM12=1; CS12=0, CS11=1, CS10=1 (Prescaler=64)
}


void velocity(unsigned char frontLeft,unsigned char frontRight,unsigned char backLeft,unsigned char backRight)
{/*
	OCR5AL = frontLeft;
	OCR5BL = frontRight;

	OCR3AL = backLeft;
	OCR5CL = backRight;
*/

OCR5AL = backLeft;
	OCR5BL = backRight;

	OCR3AL = frontLeft;
	OCR5CL = frontRight;

}

