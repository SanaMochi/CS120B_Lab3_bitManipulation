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
	DDRB = 0x00; PORTB = 0xFF; //Configure B's 8 pins as inputs, initialize to 1s 
//	DDRC = 0xFF; PORTC = 0x00; //Configure C's 8 pins as outputs, initialize to 0s

	unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00;
//	unsigned char tmpC = 0x00;

    /* Insert your solution below */
    while (1) {
	//Read input	
	tmpA = PINA;
	
	tmpB = ((tmpA & 0xF0) >> 4) | ((tmpA & 0x0F) << 4);

	PORTB = tmpB;	

    }
    return 1;
}
