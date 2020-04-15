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
    //DDRB = 0x00; PORTB = 0xFF;
    // Outputs
    DDRC = 0xFF; PORTC = 0x00;

    /* Insert your solution below */
    unsigned char level, ignition, seated, fastened;
    unsigned char levelLights, lowFuelLight, fastenSeatbeltLight;

    while (1) 
    {
        level    = PINA & 0x0F;
        ignition = PINA & 0x10;
        seated   = PINA & 0x20;
        fastened = PINA & 0x40;

        levelLights = 0;
        lowFuelLight = 0;
        fastenSeatbeltLight = 0;

        // set lowFuel light
        if (level <= 4)
        {
            lowFuelLight = 0x01 << 6;
        }

        // set fastenSeatbelt light
        if (ignition && seated && !fastened)
        {
            fastenSeatbeltLight = 0x01 << 7;
        }

        // set fuel level lights
        switch (level)
        {
        case 15 :
        case 14 :
        case 13 :
            levelLights = levelLights | 0x01;
        case 12 :
        case 11 :
        case 10 :
            levelLights = levelLights | 0x02;
        case 9  :
        case 8  :
        case 7  :
            levelLights = levelLights | 0x04;
        case 6  :
        case 5  :
            levelLights = levelLights | 0x08;
        case 4  :
        case 3  :
            levelLights = levelLights | 0x10;
        case 2  :
        case 1  :
            levelLights = levelLights | 0x20;
            break;
        default:
            break;
        }

        PORTC = levelLights | lowFuelLight | fastenSeatbeltLight;
    }
    return 1;
}
