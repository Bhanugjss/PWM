/*
 * GccApplication3.c
 *
 * Created: 15-05-2019 11:33:22
 * Author : G J S S BHANU
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include<util/delay.h>
void PWM_init_()
{
	/*set fast PWM mode with non-inverted output*/
	TCCR0=(1<<WGM00) | (1<<WGM01) |(1<<COM01) |(1<<CS00);
	DDRB|=(1<<PB3);/*set 0C0 pin as output*/
}


int main(void)
{
	unsigned char duty;
	PWM_init_();
    /* Replace with your application code */
    while (1) 
    {
		for(duty=0;duty<255;duty++)
		{
			OCR0=duty;/*increase the LED light intensity*/
			_delay_ms(8);
		}
		for(duty=255;duty>1;duty--)
		{
			OCR0=duty;/*decrease the LED light intensity*/
			_delay_ms(8);
		}
    }
}

