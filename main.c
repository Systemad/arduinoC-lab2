#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include <stdio.h>

#include "led.h"
#include "serial.h"
#include "timer.h"

int timer = 0;

void main (void) {
	uart_init();	// Initialize UART
	timer_init();	// Initialize timer
	LED_init();		// Initialize LED pin(s)

	while(1){
		if (TIFR0 & (1 << OCF0A)){	// If timer0 flag matched/reached, increment timer variable by one
			timer++;				
			TIFR0 = (1 << OCF0A); 	// then clear the OCF0A flag
		}
		
		if(timer == 10){ 			// If timer equals 10, reset it to reset loop and toggle LED
			timer = 0;
			PORTB ^= (1 << PB3);
		}
	}
}


/*
	while (1) {						
		if(TCNT0 >= compare_value){		// If timer(TCNTO) matches compare value
			timer++;					// Increment value by 1
			TCNT0 = 0;					// And reset timer
			if(timer == 10){			
				PORTB ^= (1 << PB3);	// Toggle LED and reset time variable if time goes above 10	
				timer = 0;
			}
		}
	}
}
*/