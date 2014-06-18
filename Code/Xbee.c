#include "Xbee.h"

void uart0_Xbee_init(void) {
cli();
    UBRR0H = UBRRH_VALUE;
    UBRR0L = UBRRL_VALUE;

#if USE_2X
    UCSR0A |= _BV(U2X0);
#else
    UCSR0A &= ~(_BV(U2X0));
#endif

    UCSR0C = _BV(UCSZ01) | _BV(UCSZ00); /* 8-bit data */ 
    UCSR0B = _BV(RXEN0) | _BV(TXEN0);   /* Enable RX and TX */
sei();
}


char uart0_getchar(void) {

	unsigned char data1;
    //loop_until_bit_is_set(UCSR0A, RXC0); /* Wait until data exists. */
	while(!(UCSR0A&(1<<RXC0))){}
	
	data1 = UDR0;

    return data1;
}

void uart0_putchar(char c) {
    UDR0 = c;

   loop_until_bit_is_set(UCSR0A, TXC0); /* Wait until transmission ready. */  //both statements work i.e. loop_until... and while..
// 	while(!(UCSR0A&(1<<TXC0))){}

}






































/*
void uart0_init(void)
{
 UCSR0B = 0x00; //disable while setting baud rate
 UCSR0A = 0x00;
 UCSR0C = 0x06;
 UBRR0L = 0x47; //11059200 Hz
// UBRR0L = 0x5F; // 14745600 Hzset baud rate lo
 UBRR0H = 0x00; //set baud rate hi
 UCSR0B = 0x98;
}


SIGNAL(SIG_USART0_RECV) 		// ISR for receive complete interrupt
{
	data = UDR0; 				//making copy of data from UDR0 in 'data' variable 

	UDR0 = data; 				//echo data back to PC

	//stop_All();
	switch(data)
	{
		case 'u':
		case 'U':
					move_Up();
					break;
		case 'd':
		case 'D':
					move_Down();
					break;
		
		case 'f':
		case 'F':
					velocity(250,255,250,250);
		//		motorsForward();
					move_Forward();
//					ShaftCountLeft = ShaftCountRight = 0;
				//	controlVar = 'f';	
			//		UCSR0B = 0x00; //disable while setting baud rate
 			//		UCSR0A = 0x00;
					return;
				//	forward_mm(100);
					break;
		case 'b':
		case 'B':
		velocity(50,55,50,50);
					move_Backward();
					break;
		case 'r':
		case 'R':
		velocity(250,255,50,50);
					move_Right();
					break;
		case 'l':
		case 'L':
					move_Left();
					break;
		case 's':
		case 'S':
					stop_All();
					break;
		case 'o':
		case 'O':
					buzzer_off()	;
					break;
		case '[':
					startMotorFrontLeftWind();
					startMotorBackLeftWind();
					break;

		case '{':
					startMotorFrontLeftUnwind();
					startMotorBackLeftUnwind();
					break;
		case ']':
					startMotorFrontRightWind();
					startMotorBackRightWind();
					break;

		case '}':
					startMotorFrontRightUnwind();
					startMotorBackRightUnwind();
					break;			
		case 'i':
					startMotorFrontLeftWind();
					startMotorFrontRightWind();
					break;

		case 'k':
					startMotorBackRightWind();
					startMotorBackLeftWind();
					break;
		case 'I':
					startMotorFrontLeftUnwind();
					startMotorFrontRightUnwind();
					break;

		case 'K':
					startMotorBackRightUnwind();
					startMotorBackLeftUnwind();
					break;
		

		case '1':
					velocity(50,0,0,0);
					//startMotorFrontLeftWind();
					move_Forward();
					break;
		case '2':
					velocity(0,50,0,0);
					//startMotorFrontRightWind();
					move_Forward();
					break;
		case '3':
					velocity(0,0,50,0);
					startMotorBackLeftWind();
					break;
		case '4':
					velocity(0,0,0,50);
					startMotorBackRightWind();
					break;
		case '!':	
					velocity(250,0,0,0);
					startMotorFrontLeftUnwind();
					break;
		case '@':
					velocity(0,250,0,0);
					startMotorFrontRightUnwind();
					break;
		case '#':
					velocity(0,0,250,0);
					startMotorBackLeftUnwind();
					break;
		case '$':
					velocity(0,0,0,250);
					startMotorBackRightUnwind();
					break;
		default :
					buzzer_on();
					break;
	}
	

}

*/
