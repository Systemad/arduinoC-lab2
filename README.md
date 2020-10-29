# arduinoC-lab2
Assignment 1: Blink a led using timer0, with CTC mode and prescaler 1024.

In order to calculate compare value we must use formula 'f_cpu clk / (prescale_value * rate)'
In this case, our cpu clk is 16Mhz, prescaler 1024 and our rate 10ms.

16Mhz / (1024 * 100) = 156.25 rounded 156 | (16Mhz = 16 000 000)

(Calculations above can also be found in timer.h)
