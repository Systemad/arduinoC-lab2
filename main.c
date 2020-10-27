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

	while (1) {}
}
