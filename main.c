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
*
*
*
*
*
*/

int main (void)
{
	timer_init();
	LED_init();

    uint8_t brightness = 0;

    while (brightness <= 255 ){
        OCR0A = brightness;
        _delay_ms(50);
        brightness += 5;
    }

    while (brightness >= 0 ){
        OCR0A = brightness;
        _delay_ms(50);
        brightness -= 5;
    }
}


/*
	while(1)
    {
		
        for(brightness = 0; brightness < 255; brightness++)
        {
            OCR0A = brightness;
            _delay_ms(10);
        }

        for(brightness = 255; brightness > 0; brightness--)
        {
            OCR0A = brightness;
            _delay_ms(10);
        }
    }
*/