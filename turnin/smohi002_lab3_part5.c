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
	DDRB = 0xF0; PORTB = 0x00; //Configure B's 8 pins as outputs, initialize to 0s
	DDRD = 0x00; PORTD = 0xFF; //Configure D's 8 pins as outputs, initialize to 0s
	unsigned char tmpB = 0x00;
	unsigned char tmpD = 0x00;
		
	unsigned short weight = 0x00;

    /* Insert your solution below */
    while (1) {
	//Read input	
	tmpD = PIND;	
	tmpB = PINB & 0x01;
	weight = (tmpD << 1) | tmpB;

	if (weight >= 0x45)
		tmpB = 0x02;
	else if (weight > 0x05 && weight < 0x45)
		tmpB = 0x04;
	else 
		tmpB = 0x00;

	PORTB = tmpB;	

    }
    return 1;
}
