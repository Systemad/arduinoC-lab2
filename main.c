#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include <stdio.h>

#include "led.h" // TODO: Add led function code
#include "serial.h"
#include "timer.h"

// Timer variable
volatile int time = 0;

void main (void) {
	uart_init();	// Initialize UARt
	timer_init();	// Initialize timer
	LED_init();		// Initialize LED pin(s)

	while (1) {						
		if(TCNT0 >= tl_compare){	// If timer(TCNTO) matches compare value
			time++;					// Increment value by 1
			TCNT0 = 0;				// And reset timer
			if(time > 10){			
				PORTB ^= (1 << PB3);	// Toggle LED and reset time variable if time goes above 10	
				time = 0;
			}
		}
	}
}
