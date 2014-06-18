#include "moveMotors.h"
#include "Motor.h"
#include "PWM.h"
#include "ShaftEncoder.h"


//motors operates on input character..
void moveMotors(unsigned char data)
{
	stop_All();
	velocity(250,255,250,250);
	switch(data)
	{
		case 'u': //UP
		case 'U':  velocity(250,255,250,250);
					move_Up();
					break;
		case 'd': //Down
		case 'D':   velocity(250,255,250,250);
					move_Down();
					break;
		case 'f'://Forward
		case 'F':	velocity(250,250,150,150);
					move_Forward();
					break;
		case 'b'://Backward
		case 'B':	velocity(150,155,250,250);
					move_Backward();
					break;
		case 'r'://Right
		case 'R'://velocity(250,100,250,100);
					move_Right();
					break;
		case 'l'://Left
		case 'L'://velocity(100,250,100,250);
					move_Left();
					break;
		case 's'://Stop
		case 'S':   velocity(0,0,0,0);
					stop_All();
					break;
		case 'o'://BuzzerOff
		case 'O':	buzzer_off()	;
					break;
		case '[':  //Wind both left side motors
		            velocity(250,250,250,250);
					startMotorFrontLeftWind();
					startMotorBackLeftWind();
					break;

		case '{'://UnWind both left side motors
		            //velocity(250,0,250,0);
					velocity(250,250,250,250);
					startMotorFrontLeftUnwind();
					startMotorBackLeftUnwind();
					break;
		case ']'://Wind both Right side motors
		           //velocity(0,250,0,250);
					velocity(250,250,250,250);
					startMotorFrontRightWind();
					startMotorBackRightWind();
					break;

		case '}':  //UnWind both Right side motors
		            //velocity(0,250,0,250);
					velocity(250,250,250,250);
					startMotorFrontRightUnwind();
					startMotorBackRightUnwind();
					break;			
		case 'i'://Wind both front motors
		            //velocity(250,250,0,0);
					velocity(250,250,250,250);
					startMotorFrontLeftWind();
					startMotorFrontRightWind();
					break;

		case 'k'://Wind both rear motors
					velocity(250,250,250,250);
					startMotorBackRightWind();
					startMotorBackLeftWind();
					break;
		case 'I':  //UnWind both front motors
		            velocity(250,250,0,0);
					startMotorFrontLeftUnwind();
					startMotorFrontRightUnwind();
					break;

		case 'K':  //UnWind both rear motors
		            velocity(0,0,250,250);
					startMotorBackRightUnwind();
					startMotorBackLeftUnwind();
					break;
		case '1': velocity(250,250,250,250); 
					//velocity(250,0,0,0);
					startMotorFrontLeftWind();
					//move_Forward();
					break;
		case '2':velocity(250,250,250,250);
					//velocity(0,250,0,0);
					startMotorFrontRightWind();
					//move_Forward();
					break;
		case '3':velocity(250,250,250,250);
					//velocity(0,0,250,0);
					startMotorBackLeftWind();
					break;
		case '4':velocity(250,250,250,250);
					//velocity(0,0,0,250);
					startMotorBackRightWind();
					break;
		case '!':	velocity(250,250,250,250);  //SHIFT and 1,2,3,4 to unwind
					//velocity(250,0,0,0);
					startMotorFrontLeftUnwind();
					break;
		case '@':velocity(250,250,250,250);
					//velocity(0,250,0,0);
					startMotorFrontRightUnwind();
					break;
		case '#':velocity(250,250,250,250);
					//velocity(0,0,250,0);
					startMotorBackLeftUnwind();
					break;
		case '$':velocity(250,250,250,250);
					//velocity(0,0,0,250);
					startMotorBackRightUnwind();
					break;
		default :
					buzzer_on();
					break;
	}
	

}

#define TROUGH_COUNT 3
void moveMotors1(unsigned char data, int DistanceInMM, int noofTrough) 		// ISR for receive complete interrupt
{

	//int noofTrough = TROUGH_COUNT ;
	int gapTrough = DistanceInMM/noofTrough;

	move_Up();
	_delay_ms(2000);

	velocity(100,100,250,250);
	
	move_Backward();
	_delay_ms(3000);

for(int i=0;i<noofTrough-1;i++)
{
	move_Up();
	_delay_ms(7000);

	move_Down();
	_delay_ms(1000);

	velocity(250,250,100,100);
	move_Forward();
	linear_distance_mm(gapTrough);
	_delay_ms(2000);
}

stop_All();

}






