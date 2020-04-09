/*	Author: smohi002
 *  Partner(s) Name: 
 *	Lab Section: 25
 *	Assignment: Lab #3  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF; //Configure A's 8 pins as inputs, initialize to 1s
//	DDRB = 0x00; PORTB = 0xFF; //Configure B's 8 pins as inputs, initialize to 1s 
	DDRC = 0xFF; PORTC = 0x00; //Configure C's 8 pins as outputs, initialize to 0s

	unsigned char tmpA = 0x00;
//	unsigned char tmpB = 0x00;
	unsigned char tmpC = 0x00;

    /* Insert your solution below */
    while (1) {
	//Read input	
	tmpA = PINA & 0x7F;
	
	if (((tmpA & 0x0F) == 0x01) || ((tmpA & 0x0F) == 0x02))
		tmpC = 0x20;
	else if (((tmpA & 0x0F) == 0x03) || ((tmpA & 0x0F) == 0x04))
                tmpC = 0x30;
	else if (((tmpA & 0x0F) == 0x05) || ((tmpA & 0x0F) == 0x06))
                tmpC = 0x38;
	else if (((tmpA & 0x0F) == 0x07) || ((tmpA & 0x0F) == 0x08) || ((tmpA & 0x0F) == 0x09))
                tmpC = 0x3C;
	else if (((tmpA & 0x0F) == 0x0A) || ((tmpA & 0x0F) == 0x0B) || ((tmpA & 0x0F)== 0x0C))
                tmpC = 0x3E;
	else if (((tmpA & 0x0F) == 0x0D) || ((tmpA & 0x0F) == 0x0E) || ((tmpA & 0x0F)== 0x0F))
                tmpC = 0x3F;

	if ((tmpA & 0x0F) <= 0x04) 
		tmpC = (tmpC & 0xBF) | 0x40;

//	if ((tmpA & 0x70) == 0x30)
//                tmpC = (tmpC & 0x7F) | 0x80;

	PORTC = tmpC;	

    }
    return 1;
}
