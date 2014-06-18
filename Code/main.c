/*.....................................................
 * Project - Spider Cam
 * ....................................................
 * Course -  CS 684(Embedded System)
 * Group No - 10
 * Members -   Sandip Pawar
 * 			   Abhimanyu Khosla
 * 			   Atul Rokade
 * .....................................................
 * in the project Code different files are used to code the simillar set 
 * of things
 * moveMotors -> has only 2 functions & used for sending command to move
 *               (bot level Abstraction)
 * Motor -> all motor related initializations , configurations and each
 *          motor movement is coded here(motor level abstraction)
 
 * ShaftEncoder -> all the initializations , configurations related to 
 *            shaft encoder are handeled here, provides function through
 *            which you can control bot by specifying distance to move
 * 
 * PWM -> related to PWM..provides function through which you can control 
 *        the speed of bot
 * 
 * 
 * Xbee -> Xbee initialization ..
 *         it provides 2 functions one to get character fron communicating 
 *         Xbee module and other to send the character
 */		

#include "moveMotors.h"   //
#include "ShaftEncoder.h" //
#include "PWM.h"  //
#include "Motor.h" //
#include "Xbee.h" // 
#include <stdlib.h>

//port initialisation for motors,Xbee,shaftencoder,pwm and buzzer
//buzzer doesn't have specific use..just used in case if wrong input recieves at bot.. 
void port_init() 
{
	motorsPinInit();  //initialize motors Pin

	motion_pin_config(); //
	buzzer_pin_config(); //
//shaft encoder pin configuration
	left_encoder_pin_config(); //
	leftFront_encoder_pin_config(); //
	right_encoder_pin_config();
	rightFront_encoder_pin_config();
//PWM timers initialization
	PWM_timerT5Init();
	PWM_timerT3Init();
//Xbee uart initialization
	uart0_Xbee_init();
}

//----------------------
//Function To Initialize all The Devices
void init_devices()
{
 cli(); //Clears the global interrupts
 port_init();  //Initializes all the ports
 left_position_encoder_interrupt_init();
 leftFront_position_encoder_interrupt_init();
 right_position_encoder_interrupt_init();
 rightFront_position_encoder_interrupt_init();
 sei();   //Enables the global interrupts
}


#define NUM(ch) (ch-'0') //macro to get ascii value of character

#define AUTOMATE 2  //bot operates in 2 modes automated and command mode
#define COMMAND 1  // for more details refer README file

//for communication purpose (with Alex group project--where they send data remotly)
char fcall[5][5];
int i =0, j = 0;
int botId;

//data can be recieved in 2 forms
//1:for command mode ->  num$function_num$direction#
//2:for Automate mode ->  num$function_num$direction$distance$number_of_troughs#
//Ex. 1-> 10$1$f
//    2-> 10$2$b$200$3#

void function_caller()
{
	if(atoi(fcall[1]) == AUTOMATE ) //4 values 1st should be f 
		moveMotors1(fcall[2][0],atoi(fcall[3]),atoi(fcall[4]));
	else if(atoi(fcall[1]) == COMMAND )
		moveMotors(fcall[2][0]);
}


int main(void)
{
	init_devices();
	botId =  10;
	unsigned char data ;
// recieved data is copied in 2D array fcall..and after analysing particular action is taken
//here 1 row stores 1 function call ith its parameters
	while(1)
	{
		data = uart0_getchar();
		uart0_putchar(data);
		if(data == 0x23) // #  check for the end of function calling
		{
			if(atoi(fcall[0]) == botId) //check for correct botId 
			{
				if(j != 0) 
				{
					fcall[i][j] = 0;
					sei();
					function_caller();
					cli();
				}
			UDR0 = data; //data copied to udr port
			}
			i = 0;
			j = 0;
		}
		else if(data == 0x24) // $ //check for next parameter
		{
			fcall[i][j] = 0;
			i++;
			j = 0;
		}
		else
		{	
			fcall[i][j] = data; //next digit fo parameter
			j++;
		}
}


}
