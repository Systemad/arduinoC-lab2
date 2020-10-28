#include <avr/io.h>

#include "timer.h"

void timer_init() {

	// Non-invering mode, Fast PWN mode, 0xFF as TOP
	TCCR0A |= (1 << COM0A1) | (1 << WGM01) | (1 << WGM00);

	// Set prescale to 64
	TCCR0B = (1 << CS00) | (1 << CS01);
	
	/*
	*  	Us formula f_clk / (N * 256), where N is prescale divider, to calculate output PWM frequency
	*	16 000 000 / (64 * 256) = 976,5625, rounded up to 977
	*/

	//OCR0A = 255;
}




