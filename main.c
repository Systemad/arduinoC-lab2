#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include <stdio.h>

#include "led.h"
#include "serial.h"
#include "timer.h"

/*
* Fade using FastPWM Mode, with TOP 0xFF and non inverting mode
* Using two simple for loops to fade the led
* in order to demostrate we are able to put apply different duty cycles / brightness to OCR0A / LED
*	
*
* Brightness = duty cycle
*/

int main (void)
{
	timer_init();
	LED_init();
	
	while(1)
	{
		for (uint8_t brightness = 5; brightness <= 250; brightness += 5) {
			OCR0A = brightness;
			_delay_ms(50);
		}

		for (uint8_t brightness = 250; brightness >= 5; brightness -= 5) {
			OCR0A = brightness;
			_delay_ms(50);
		}
	}
}