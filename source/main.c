/*	Author: houjiacheng
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab 3  Exercise 4
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void)
{
    /* Insert DDR and PORT initializations */
    // Inputs
    DDRA = 0x00; PORTA = 0xFF;
    //DDRB = 0x00; PORTB = 0xFF;
    // Outputs
    DDRB = 0xFF; PORTB = 0x00;
    DDRC = 0xFF; PORTC = 0x00;

    /* Insert your solution below */
    unsigned char tmpA, tmpB, tmpC;

    while (1) 
    {
        tmpA = PINA;

        tmpB = ((tmpA & 0xF0) >> 4);
        tmpC = ((tmpA & 0x0F) << 4);

        PORTB = tmpB;
        PORTC = tmpC;
    }
    return 1;
}
