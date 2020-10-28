#include <avr/io.h>
#include "led.h"

void LED_init() {
	DDRB |= (1 << PB3);

	// To use timer0 (OCR0A) we need to use pin 6 as output
	DDRD |= (1 << PORTD6);

}
