#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include <stdio.h>

#include "led.h" // TODO: Add led function code
#include "serial.h"
#include "timer.h"

uint16_t time = 0;

void main (void) {
	uart_init();
	timer_init();
	DDRB |= (1<<PB3);

	// 
	TCCR0A = 0;

	sei();
	while (1) {};

}


ISR(TIMER0_COMPA_vect){
	time++;
	// TODO: Wrong value?
	if (time > 100) {
        PORTB ^= (1<<PB3);
        time = 0;       
    }
}