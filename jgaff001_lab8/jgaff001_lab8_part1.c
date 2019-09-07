/*	Partner 1's Name & E-mail: Justin Gafford jgaff001@ucr.edu
*  Partner 2's Name & E-mail: Wang Sitao 934415487@qq.com
*	Lab Section: 022
*	Assignment: Lab #8 Exercise #1
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
        my_char = (char)x; // my_char = 0xCD
        my_char2 = (char)(x >> 8); // my_char = 0xBC
        
        PORTB = my_char;
        PORTD = my_char2;
        
    }
}

