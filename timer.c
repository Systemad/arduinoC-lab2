#include <avr/io.h>

#include "timer.h"

// TODO: Find right prescale value
const uint16_t tl_compare = 1562; // 15620 //.5; // Prescaler 1024

void timer_init() {

	// Set timer0 to CTC mode
	TCCR0A = (1 << WGM01) ;
	
	// Set prescaler to 1024
	TCCR0B = (1 << CS02); 

	OCR0A = tl_compare;
    TIMSK0 = (1 << OCIE1A);

}



