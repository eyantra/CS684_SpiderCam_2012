#ifndef _MOTOR_H
#define _MOTOR_H

#include "header.h"

#define SETBIT(x,b) x|=(1<<b)     //b'th bit of variable x is set
#define CLEARBIT(x,b) x&=(~(1<<b)) //b'th bot of variable x is cleared


void startMotorFrontLeftWind();
void startMotorFrontLeftUnwind();
void startMotorFrontRightWind();
void startMotorFrontRightUnwind();

void startMotorBackLeftWind();
void startMotorBackLeftUnwind();
void startMotorBackRightWind();
void startMotorBackRightUnwind();

void stopMotorFrontLeft();
void stopMotorFrontRight();
void stopMotorBackLeft();
void stopMotorBackRight();

void move_Up();
void move_Down();
void move_Forward();
void move_Backward();
void move_Right();
void move_Left();

void stop_All();

void motorsPinInit();

void buzzer_off (void);
void buzzer_on (void);

void motion_pin_config (void);
void buzzer_pin_config (void);


#endif
