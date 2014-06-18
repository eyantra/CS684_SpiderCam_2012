#include "Motor.h"

//function name explains its behavior
//code is for 4 motors
//named as Front Left/Right
//         Back  Left/Right
//note: above naming is given by considering bot orientation as upside down i.e. wheel side is upper side

void startMotorFrontLeftWind(){

	CLEARBIT(PORTA,5);
	SETBIT(PORTA,4);
}
void startMotorFrontLeftUnwind(){

	CLEARBIT(PORTA,4);
	SETBIT(PORTA,5);
}

void startMotorFrontRightWind(){

	CLEARBIT(PORTA,7);
	SETBIT(PORTA,6);
}
void startMotorFrontRightUnwind(){

	CLEARBIT(PORTA,6);
	SETBIT(PORTA,7);
}

void startMotorBackRightWind(){

	CLEARBIT(PORTA,1);
	SETBIT(PORTA,0);
}
void startMotorBackRightUnwind(){

	CLEARBIT(PORTA,0);
	SETBIT(PORTA,1);
}

void startMotorBackLeftWind(){

	CLEARBIT(PORTA,2);
	SETBIT(PORTA,3);
}
void startMotorBackLeftUnwind(){

	CLEARBIT(PORTA,3);
	SETBIT(PORTA,2);
}

void stopMotorFrontLeft(){

	CLEARBIT(PORTA,4);
	CLEARBIT(PORTA,5);
	
}

void stopMotorFrontRight(){

	CLEARBIT(PORTA,6);
	CLEARBIT(PORTA,7);
	
}

void stopMotorBackLeft(){

	CLEARBIT(PORTA,3);
	CLEARBIT(PORTA,2);
	
}

void stopMotorBackRight(){

	CLEARBIT(PORTA,1);
	CLEARBIT(PORTA,0);
	
}

//***********************************************

void move_Up()
{
			
			startMotorBackLeftWind();
			startMotorBackRightWind();
			startMotorFrontLeftWind();
			startMotorFrontRightWind();
}
//***********************************************

void move_Down()
{
			startMotorBackLeftUnwind();
			startMotorBackRightUnwind();
			startMotorFrontLeftUnwind();
			startMotorFrontRightUnwind();
}




void move_Forward()
{
			startMotorBackLeftUnwind();
			startMotorBackRightUnwind();

			startMotorFrontLeftWind();
			startMotorFrontRightWind();
			

}

//***********************************************
void move_Backward()
{
			startMotorFrontLeftUnwind();
			startMotorFrontRightUnwind();
			startMotorBackLeftWind();
			startMotorBackRightWind();


}

//***********************************************
void move_Right()
{
//static long int i=0 ;
//i++;
{
			startMotorFrontLeftUnwind();
			startMotorBackLeftUnwind();}
{
			startMotorFrontRightWind();
			startMotorBackRightWind();}

}


//***********************************************
//***********************************************
void move_Left()
{
			startMotorFrontLeftWind();
			startMotorFrontRightUnwind();
			startMotorBackLeftWind();
			startMotorBackRightUnwind();

}

void stop_All(){
	stopMotorFrontLeft();
	stopMotorFrontRight();
	stopMotorBackLeft();
	stopMotorBackRight();
}

//***********************************************




void motorsPinInit()
{
	SETBIT(DDRA,0);
	SETBIT(DDRA,1);
	SETBIT(DDRA,2);
	SETBIT(DDRA,3);

	SETBIT(DDRL,3);
	SETBIT(DDRL,4);

	CLEARBIT(PORTA,0);
	CLEARBIT(PORTA,1);
	CLEARBIT(PORTA,2);
	CLEARBIT(PORTA,3);

	SETBIT(PORTL,3);
	SETBIT(PORTL,4);
	//PORTL = 0x18;
//********************************************
	SETBIT(DDRA,4);
	SETBIT(DDRA,5);
	SETBIT(DDRA,6);
	SETBIT(DDRA,7);

	SETBIT(DDRL,5);


	CLEARBIT(PORTA,4);
	CLEARBIT(PORTA,5);
	CLEARBIT(PORTA,6);
	CLEARBIT(PORTA,7);

	SETBIT(PORTL,5);


//***********************************************
}


void buzzer_pin_config (void)
{
 DDRC = DDRC | 0x08;		//Setting PORTC 3 as outpt
 PORTC = PORTC & 0xF7;		//Setting PORTC 3 logic low to turnoff buzzer
}

void motion_pin_config (void)
{
 DDRA = DDRA | 0x0F;
 PORTA = PORTA & 0xF0;
 DDRL = DDRL | 0x38;   //Setting PL3 and PL4 pins as output for PWM generation & PL5 //c1
 PORTL = PORTL | 0x38; //PL3 and PL4 pins are for velocity control using PWM.

 DDRE = DDRE | 0x08;   //Setting PL3 and PL4 pins as output for PWM generation & PL5 //c1
 PORTE = PORTE | 0x08; //PL3 and PL4 pins are for velocity control using PWM.

}



void buzzer_on (void)
{
 unsigned char port_restore = 0;
 port_restore = PINC;
 port_restore = port_restore | 0x08;
 PORTC = port_restore;
}

void buzzer_off (void)
{
 unsigned char port_restore = 0;
 port_restore = PINC;
 port_restore = port_restore & 0xF7;
 PORTC = port_restore;
}


