
#include "ShaftEncoder.h"
#include "PWM.h"
#include "Motor.h"
#include "Xbee.h"

//--------------------

//Function to configure INT4 (PORTE 4) pin as input for the left position encoder
//PE4
void left_encoder_pin_config (void)
{
	DDRE = DDRE & 0xEF; //Set the direction of the PORTE 4 pin as input
	PORTE = PORTE | 0x10; //Enable internal pull-up for PORTE 4 pin
}
//Function to configure INT5 (PORTE 5) pin as input for the right position encoder
//PE5
void right_encoder_pin_config (void)
{
	DDRE = DDRE & 0xDF; //Set the direction of the PORTE 4 pin as input
	PORTE = PORTE | 0x20; //Enable internal pull-up for PORTE 4 pin
}


//Function to configure INT4 (PORTE 4) pin as input for the left position encoder
//PE6 - C2
void leftFront_encoder_pin_config (void)
{
	DDRE = DDRE & 0xBF; //Set the direction of the PORTE 4 pin as input
	PORTE = PORTE | 0x40; //Enable internal pull-up for PORTE 4 pin
}
//Function to configure INT5 (PORTE 5) pin as input for the right position encoder
//PE7 - C1
void rightFront_encoder_pin_config (void)
{
	DDRE = DDRE & 0x7F; //Set the direction of the PORTE 4 pin as input
	PORTE = PORTE | 0x80; //Enable internal pull-up for PORTE 4 pin
}




void left_position_encoder_interrupt_init (void) //Interrupt 4 enable
{
	cli(); //Clears the global interrupt
	EICRB = EICRB | 0x02; // INT4 is set to trigger with falling edge
	EIMSK = EIMSK | 0x10; // Enable Interrupt INT4 for left position encoder
	sei(); // Enables the global interrupt
}
void right_position_encoder_interrupt_init (void) //Interrupt 5 enable
{
	cli(); //Clears the global interrupt
	EICRB = EICRB | 0x08; // INT5 is set to trigger with falling edge
	EIMSK = EIMSK | 0x20; // Enable Interrupt INT5 for right position encoder
	sei(); // Enables the global interrupt
}
//c2
void leftFront_position_encoder_interrupt_init (void) //Interrupt 6 enable
{
	cli(); //Clears the global interrupt
	EICRB = EICRB | 0x20; // INT6 is set to trigger with falling edge
	EIMSK = EIMSK | 0x40; // Enable Interrupt INT7 for left position encoder
	sei(); // Enables the global interrupt
}
//c1
void rightFront_position_encoder_interrupt_init (void) //Interrupt 7 enable
{
	cli(); //Clears the global interrupt
	EICRB = EICRB | 0x80; // INT7 is set to trigger with falling edge
	EIMSK = EIMSK | 0x80; // Enable Interrupt INT7 for right position encoder
	sei(); // Enables the global interrupt
}


//ISR for left position encoder
//HERE its RIGHT 
ISR(INT4_vect)
{
	cli();
		ShaftCountRight++; //increment left shaft position count
	sei();
}

//ISR for right position encoder
ISR(INT5_vect)
{
	cli();
		ShaftCountLeft++; //increment right shaft position count
	sei();
}


//ISR for Right
//c2
ISR(INT6_vect)
{
	cli();
		ShaftCountRightFront++; //increment left shaft position count
	sei();
}

//for Left
//c1
ISR(INT7_vect)
{
	cli();
		ShaftCountLeftFront++; //
	sei();
}



void linear_distance_mm(unsigned int DistanceInMM)
{
	float ReqdShaftCount = 0;
	unsigned long int ReqdShaftCountInt = 0;
	ReqdShaftCount = DistanceInMM / 1.2; // division by resolution to get shaft count
	ReqdShaftCountInt = (unsigned long int) ReqdShaftCount;

	ShaftCountRight = 0;
	ShaftCountLeft = 0;
	ShaftCountRightFront = 0;
	ShaftCountLeftFront = 0;
	while(1)
	{
		if(ShaftCountRight > ReqdShaftCountInt)
		{
			stopMotorBackRight();
			FLAG_BR = TRUE;	
		}
		if(ShaftCountLeft > ReqdShaftCountInt)
		{
			stopMotorBackLeft();
			FLAG_BL = TRUE;
		}
		if(ShaftCountRightFront > ReqdShaftCountInt)
		{
			stopMotorFrontRight();
			FLAG_FR = TRUE;
		}
		if(ShaftCountRightFront > ReqdShaftCountInt)
		//if(ShaftCountLeftFront > ReqdShaftCountInt)
		{
			stopMotorFrontLeft();
			FLAG_FL = TRUE;
		}
		if(FLAG_BR==TRUE && FLAG_BL==TRUE && FLAG_FR==TRUE && FLAG_FL==TRUE)
			break; 

	}


	

}

void forward_mm(unsigned int DistanceInMM)
{
	velocity(250,255,250,250);
	move_Forward();
	linear_distance_mm(DistanceInMM);
}
