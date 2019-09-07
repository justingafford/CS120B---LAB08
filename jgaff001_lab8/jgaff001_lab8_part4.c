/*	Partner 1's Name & E-mail: Justin Gafford jgaff001@ucr.edu
*  Partner 2's Name & E-mail: Wang Sitao 934415487@qq.com
*	Lab Section: 022
*	Assignment: Lab #8 Exercise #4
*
*	I acknowledge all content contained herein, excluding template or example
*	code, is my own original work.
*/

#include <avr/io.h>

void ADC_init() {
    ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
    // ADEN: setting this bit enables analog-to-digital conversion.
    // ADSC: setting this bit starts the first conversion.
    // ADATE: setting this bit enables auto-triggering. Since we are
    //        in Free Running Mode, a new conversion will trigger whenever
    //        the previous conversion completes.
}

int main(void)
{
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    DDRD = 0xFF; PORTD = 0x00;
    DDRC = 0xFF; PORTC = 0X00;
    
    unsigned short x = 0x0000;
    unsigned char my_char = 0x00;
    unsigned char my_char2 = 0x00;
    /* Replace with your application code */
    ADC_init();
    while (1) 
    {
        x = ADC;  // Value of ADC register now stored in variable x.
        if (x > 200)
        {
            my_char = 0x01;
        }
        if (x > 300)
        {
            my_char = 0x03;
        }
        if (x > 400)
        {
            my_char = 0x07;
        }
        if (x > 500)
        {
            my_char = 0x0F;
        }
        if (x > 600)
        {
            my_char = 31;
        }
        if (x > 700)
        {
            my_char = 63;
        }
        if (x > 800)
        {
            my_char = 127;
        }
        if (x > 900)
        {
            my_char = 255;
        }
        
        PORTB = ~my_char;
        PORTD = my_char2;
         if (x > 511)
         {
             PORTC = 0x00;
             
         }
         else
         {
             PORTC = 0x02;
             
         }
        
    }
}

