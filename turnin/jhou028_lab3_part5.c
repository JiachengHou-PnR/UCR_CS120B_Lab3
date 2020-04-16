/*	Author: houjiacheng
 *	Lab Section: 022
 *	Assignment: Lab 3  Exercise 5
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
    DDRB = 0xFE; PORTB = 0x01;
    DDRD = 0x00; PORTD = 0xFF;
    // Outputs
    DDRC = 0xFF; PORTC = 0x00;

    /* Insert your solution below */
    unsigned short weight;

    while (1) 
    {
        weight = (PIND << 1) | (PINB & 0x01);

        if (weight >= 70)
        {
            PORTB = 0x01 << 1;  // airbag on
        } 
        else if (weight > 5)
        {
            PORTB = 0x01 << 2;  // airbag icon
        }
        else
        {
            PORTB = 0x00;       // airbag off, no icon
        }
        
    }
    return 1;
}
