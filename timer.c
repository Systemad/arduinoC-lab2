#include <avr/io.h>

#include "timer.h"

void timer_init() {

	// Fast PWN Mode
	TCCR0A |= (1 << WGM01) | (1 << WGM00);
	
	// Set prescaler to 1024
	TCCR0B |= (1 << CS02 ) | ( 1 << CS00);

	// Reset timer
	TCNT0 = 0;

	// Set compate value
	OCR0A = tl_compare;

}



