#include <avr/io.h>
#include "led.h"

void LED_init() {
	DDRB |= (1 << PB3);

	// Pin 6 on Arduino to support OCR0A
	DDRD |= (1 << PORTD6);

}
