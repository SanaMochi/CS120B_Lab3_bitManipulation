/*	Author: smohi002
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
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
	DDRB = 0x00; PORTB = 0xFF; //Configure B's 8 pins as inputs, initialize to 1s 
	DDRC = 0xFF; PORTC = 0x00; //Configure C's 8 pins as outputs, initialize to 0s

	unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00;
	unsigned char tmpC = 0x00;

	unsigned char cntA = 0x00;
	unsigned char cntB = 0x00;
    /* Insert your solution below */
    while (1) {
	//Read input	
	tmpA = PINA;
	tmpB = PINB;
	cntA = 0x00;
	cntB = 0x00;

	cntA = ((tmpA & 0x80) >> 7) + ((tmpA & 0x40) >> 6) + ((tmpA & 0x20) >> 5) + ((tmpA & 0x10) >> 4) + ((tmpA & 0x08) >> 3) + ((tmpA & 0x04) >> 2) + ((tmpA & 0x02) >> 1) + (tmpA & 0x01);

	cntB = ((tmpB & 0x80) >> 7) + ((tmpB & 0x40) >> 6) + ((tmpB & 0x20) >> 5) + ((tmpB & 0x10) >> 4) + ((tmpB & 0x08) >> 3) + ((tmpB & 0x04) >> 2) + ((tmpB & 0x02) >> 1) + (tmpB & 0x01);

	tmpC = cntA + cntB;

	PORTC = tmpC;	

    }
    return 1;
}
