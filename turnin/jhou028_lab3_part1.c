/*	Author: houjiacheng
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab 3  Exercise 1
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
    DDRB = 0x00; PORTB = 0xFF;
    // Outputs
    DDRC = 0xFF; PORTC = 0x00;

    /* Insert your solution below */
    unsigned char tmpA, tmpB;
    unsigned char count;
    unsigned char i;

    while (1) 
    {
        tmpA = PINA;
        tmpB = PINB;

        count = 0;

        for (i = 0; i < 8; i++) 
        {
            if (tmpA & 0x01) count ++;
            if (tmpB & 0x01) count ++;

            tmpA = tmpA >> 1;
            tmpB = tmpB >> 1;            
        }

        PORTC = count;
    }
    return 1;
}
