#include <avr/io.h>

#include "timer.h"

void timer_init() {

	//		  Non-invering mode, Fast PWN mode, 0xFF as top
	TCCR0A |= (1 << COM0A1) | (1 << WGM01) | (1 << WGM00);

	// 		  Set prescale to 64
	TCCR0B = (1 << CS00) | (1 << CS02);

	
	OCR0A = 255;

}




