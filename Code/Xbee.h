#ifndef _XBEE_H_
#define _XBEE_H_

#include "header.h"

#define F_CPU 11059200UL // or 
//#define F_CPU 14745600UL 
#define BAUD 9600

#include <util/setbaud.h>

void uart0_Xbee_init(void) ;
char uart0_getchar(void) ;
void uart0_putchar(char ); 

#endif
