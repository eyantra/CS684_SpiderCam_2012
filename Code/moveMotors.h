#ifndef _MOVEMOTORS_H
#define _MOVEMOTORS_H

#define TRUE 1
#define FALSE 0
void moveMotors(unsigned char data); 		// ISR for receive complete interrupt
void moveMotors1(unsigned char data, int DistanceInMM,int ); 		// ISR for receive complete interrupt
#endif
