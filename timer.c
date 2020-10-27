#include <avr/io.h>

#include "timer.h"

void timer_init() {

	// Fast PWN Mode
	TCCR0A |= (1 << WGM01) | (1 << WGM00);

	// set non-inverting mode
	TCCR0A |= (1 << COM0A1);
	
	// Set prescaler to 1024
	//TCCR0B |= (1 << CS02 ) | ( 1 << CS00);

	// Reset timer
	TCNT0 = 0;

	
	OCR0A = 128;

}



