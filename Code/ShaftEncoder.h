
#ifndef _SHAFTENCODER_H
#define _SHAFTENCODER_H


int FLAG_FR ;
int FLAG_FL ;
int FLAG_BR ;
int FLAG_BL ;

#define FALSE 0
#define TRUE 1


void linear_distance_mm(unsigned int DistanceInMM);
void forward_mm(unsigned int DistanceInMM);

void left_encoder_pin_config();
void right_encoder_pin_config();
void leftFront_encoder_pin_config();
void rightFront_encoder_pin_config();

void left_position_encoder_interrupt_init (void);
void right_position_encoder_interrupt_init (void);
void rightFront_position_encoder_interrupt_init (void);
void leftFront_position_encoder_interrupt_init (void);

volatile int ShaftCountRight ,
			 ShaftCountLeft ,
			 ShaftCountRightFront ,
			 ShaftCountLeftFront ;

#endif
